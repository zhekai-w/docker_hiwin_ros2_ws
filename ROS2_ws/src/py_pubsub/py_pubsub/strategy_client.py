import time
import rclpy
from enum import Enum
from threading import Thread
from rclpy.node import Node
from rclpy.task import Future
from typing import NamedTuple
from geometry_msgs.msg import Twist

from hiwin_interfaces.srv import RobotCommand
from yolo_strategy_interfaces.srv import YoloStrategy
import cv2
import pyrealsense2 as rs
import numpy as np 
import math

MY_BASE = 12
CUE_TOOL = 12
CAM_TOOL = 11

DEFAULT_VELOCITY = 25
DEFAULT_ACCELERATION = 25

LIGHT_PIN = 6
HITSOFT_PIN = 4
HITMID_PIN = 5
HITHEAVY_PIN = 1
HEAVY_PIN = 2

tablewidth = 1920
tableheight = 932
tablewidth_mm = 627
tableheight_mm = 304

class States(Enum):
    INIT = 0
    FINISH = 1
    MOVE_TO_PHOTO_POSE = 2
    TAKE_PHOTO = 3
    YOLO_DETECT = 4
    BF_HITBALL_POSE = 5
    HITBALL_POSE = 6
    HITBALL = 7
    AF_HITBALL_POSE = 8
    CHECK_POSE = 9
    CLOSE_ROBOT = 10
    WAITING = 11
    SEC_IO =  12
    SECOND_PHOTO = 13
    RECALCULATE = 14

fix_abs_cam = [305.998, 186.186, -453.931, 0.0, 2.729, -89.182]
# fix_abs_cam = [306.098, 173.154, -454.970, 0.0, 0.0, -88.904]
# fix_abs_cam = [3.274, 181.514, -408.926, 0.0, 0.0, -89.163]

def take_pics(first_or_second):
    # Create a context object. This object owns the handles to all connected realsense devices
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.color, 1920, 1080, rs.format.bgr8, 30)
    a = 0
    # Start streaming
    pipeline.start(config)

    # Instructions for user
    print('Press m to take pictures\n')
    print('Press q to quit camera\n')
    while True:

        # Wait for a coherent pair of frames: depth and color
        frames = pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()
        # if not color_frame:
        #     continue

        # Convert images to numpy arrays
        color_image = np.asanyarray(color_frame.get_data())

        # Resize color image 
        # resized_color_image = cv2.resize(table_outline, dsize=(1280,720), interpolation=cv2.INTER_AREA)    

        # Show images
        cv2.namedWindow('RealSense', cv2.WINDOW_AUTOSIZE)
        cv2.imshow('RealSense', color_image)
        key=cv2.waitKey(1)
        if key&0xFF==ord('m'):
            a=a+1
            print("picture taken")
            if first_or_second == 1:
                cv2.imwrite('/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/testpics/detect_ball.jpg',color_image)
            else:
                cv2.imwrite('/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/testpics/detect_second_ball.jpg',color_image)
        if key&0xFF==ord('q'):
            cv2.destroyAllWindows()
            break
    # Stop streaming
    pipeline.stop() 

def mm_to_pixels(mmx, mmy):
    px = tablewidth*mmx/tablewidth_mm
    py = tableheight*mmy/tableheight_mm
    return px, py

class ArmsDealer(Node):
    def __init__(self):
        super().__init__('arms_dealer')
        self.strategy_client = self.create_client(YoloStrategy, 'yolo_strategy')
        # while not self.strategy_client.wait_for_service(timeout_sec=2.0):
        #     self.get_logger().info('YOLO service not available, waiting agian...')
        self.yolo_req = YoloStrategy.Request()

        # Hiwin client
        self.hiwin_client = self.create_client(RobotCommand, 'hiwinmodbus_service')
        self.cue_hitpoint = []
        self.yolo_state = 0
        self.fix_campoint = Twist()

    def strategy_state(self, state:States) -> States:
        if state == States.INIT:
            self.get_logger().info('Moving to calculated camera point')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = fix_abs_cam[0:3]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.PTP,
                tool = CAM_TOOL,
                pose = pose
                )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.SEC_IO
            else:
                nest_state = None

        elif state == States.SEC_IO:
            self.get_logger().info('Turning second IO on for heavy hit\n')
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                digital_output_pin = HEAVY_PIN
            )
            self.call_hiwin(req)
            nest_state = States.TAKE_PHOTO

        elif state == States.TAKE_PHOTO:
            self.get_logger().info('Taking photo\n')
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                digital_output_pin = LIGHT_PIN
            )
            self.call_hiwin(req)
            take_pics(1)
            time.sleep(1.0)
            self.get_logger().info('Taking photo\n')
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_OFF,
                digital_output_pin = LIGHT_PIN
            )
            res = self.call_hiwin(req)
            self.yolo_state = 1
            nest_state = States.WAITING

        elif state == States.WAITING:
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.YOLO_DETECT
            else:
                nest_state = None

        elif state == States.YOLO_DETECT:
            if self.yolo_state == 1:
                self.cue_hitpoint = []
                self.get_logger().info('Detecting all hitpoint location\n')
                self.yolo_req.send_position = 1
                self.yolo_req.update_position = [fix_abs_cam[2]]
                yolo_res = self.call_yolo(self.yolo_req) # request 1 for cueball hitpoint and vector
                self.cue_hitpoint = yolo_res.current_position
                print('cue_hitpoint:',self.cue_hitpoint)
                nest_state = States.BF_HITBALL_POSE
        
        elif state == States.BF_HITBALL_POSE:
            self.get_logger().info('Before hitting cueball\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = [self.cue_hitpoint[0], self.cue_hitpoint[1], -70.0]
            # pose.angular.x = self.cue_hitpoint[2]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.PTP,
                pose = pose
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.HITBALL_POSE
            else:
                nest_state = None

        elif state == States.HITBALL_POSE:
            self.get_logger().info('Going to hit cueball\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = [self.cue_hitpoint[0], self.cue_hitpoint[1], -25.0]
            [pose.angular.x, pose.angular.y] = fix_abs_cam[3:5]
            pose.angular.z = fix_abs_cam[5]+self.cue_hitpoint[2]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.LINE,
                pose = pose
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.HITBALL
            else:
                nest_state = None
        
        elif state == States.HITBALL:
            self.get_logger().info('Hitting cueball\n')
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
            )
            res = self.call_hiwin(req)
            if self.cue_hitpoint[-1] >= 5500:
                hit_pin = HITSOFT_PIN
            else: #5500 > self.cue_hitpoint[-1] >= 2000:
                hit_pin = HITMID_PIN
            # else:
            #     hit_pin = HITHEAVY_PIN
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                digital_output_pin = hit_pin
            )
            self.call_hiwin(req)
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_OFF,
                digital_output_pin = hit_pin
            )
            res = self.call_hiwin(req)
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.AF_HITBALL_POSE
            else:
                nest_state = None
        
        elif state == States.AF_HITBALL_POSE:
            self.get_logger().info('Moving back to photo pose\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = [self.cue_hitpoint[0], self.cue_hitpoint[1], -70.0]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.LINE,
                pose = pose,
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.MOVE_TO_PHOTO_POSE
            else:
                nest_state = None

        elif state == States.MOVE_TO_PHOTO_POSE:
            self.cue_hitpoint = [] # clear array for next use
            self.get_logger().info('Moving to photo pose\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = fix_abs_cam[0:3]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.PTP,
                tool = CAM_TOOL,
                pose = pose
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.TAKE_PHOTO
            else:
                nest_state = None

        else:
            nest_state = None
            self.get_logger().info('input state not supported!\n')

        return nest_state
    
    def _main_loop(self):
        state = States.INIT
        while state != States.FINISH:
            state = self.strategy_state(state)
            if state == None:
                break
        self.destroy_node()

    def generate_robot_request(
            self, 
            holding=True,
            cmd_mode=RobotCommand.Request.PTP,
            cmd_type=RobotCommand.Request.POSE_CMD,
            velocity=DEFAULT_VELOCITY,
            acceleration=DEFAULT_ACCELERATION,
            tool=CUE_TOOL,
            base=MY_BASE,
            digital_output_pin=0,
            digital_output_cmd=RobotCommand.Request.DIGITAL_OFF,
            pose=Twist(),
            joints=[float('inf')]*6,
            circ_s=[],
            circ_end=[],
            jog_joint=6,
            jog_dir=0
            ):
        request = RobotCommand.Request()
        request.digital_output_pin = digital_output_pin
        request.digital_output_cmd = digital_output_cmd
        request.acceleration = acceleration
        request.jog_joint = jog_joint
        request.velocity = velocity
        request.tool = tool
        request.base = base
        request.cmd_mode = cmd_mode
        request.cmd_type = cmd_type
        request.circ_end = circ_end
        request.jog_dir = jog_dir
        request.holding = holding
        request.joints = joints
        request.circ_s = circ_s
        request.pose = pose
        return request
    
    def call_hiwin(self, req):
        while not self.hiwin_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting again...')
        future = self.hiwin_client.call_async(req)
        if self._wait_for_future_done(future):
            res = future.result()
        else:
            res = None
        return res

    def call_yolo(self, req):
        while not self.strategy_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('YOLO service not available, waiting again...')
        future = self.strategy_client.call_async(req)
        if self._wait_for_future_done(future):
            res = future.result()
        else:
            res = None
        return res
    
    def _wait_for_future_done(self, future: Future, timeout=-1):
        time_start = time.time()
        while not future.done():
            time.sleep(0.01)
            if timeout > 0 and time.time() - time_start > timeout:
                self.get_logger().error('Wait for service timeout!')
                return False
        return True
    
    def start_main_loop_thread(self):
        self.main_loop_thread = Thread(target=self._main_loop)
        self.main_loop_thread.daemon = True
        self.main_loop_thread.start()

    def test_request(self):
        key = input('Enter 1 or 0 to send ball location:\n')
        if key == '1':
            oi = 3
        else:
            oi = 0
        self.yolo_req.send_position = oi
        future = self.strategy_client.call_async(self.yolo_req)
        rclpy.spin_until_future_complete(self, future)
        # if self._wait_for_future_done(future):
        #     res = future.result()
        # else:
        #     res = None
       
        return future.result()
    
class ArmsDealer_2(Node):
    def __init__(self):
        super().__init__('arms_dealer_2')
        self.strategy_client = self.create_client(YoloStrategy, 'yolo_strategy')
        # while not self.strategy_client.wait_for_service(timeout_sec=2.0):
        #     self.get_logger().info('YOLO service not available, waiting agian...')
        self.yolo_req = YoloStrategy.Request()

        # Hiwin client
        self.hiwin_client = self.create_client(RobotCommand, 'hiwinmodbus_service')
        self.cue_hitpoint = []
        self.ball_in_route = []
        self.Nballinroute = 0
        self.yolo_state = 0
        self.ball_position_pixels = []

    def strategy_state(self, state:States) -> States:
        if state == States.INIT:
            self.get_logger().info('Moving to calculated camera point')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = fix_abs_cam[0:3]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.PTP,
                tool = CAM_TOOL,
                pose = pose
                )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.SEC_IO
            else:
                nest_state = None

        elif state == States.SEC_IO:
            self.get_logger().info('Turning second IO on for heavy hit\n')
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                digital_output_pin = HEAVY_PIN
            )
            self.call_hiwin(req)
            nest_state = States.TAKE_PHOTO

        elif state == States.TAKE_PHOTO:
            self.get_logger().info('Taking photo\n')
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                digital_output_pin = LIGHT_PIN
            )
            self.call_hiwin(req)
            take_pics(1)
            time.sleep(1.0)
            self.get_logger().info('Taking photo\n')
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_OFF,
                digital_output_pin = LIGHT_PIN
            )
            res = self.call_hiwin(req)
            self.yolo_state = 1
            nest_state = States.WAITING

        elif state == States.WAITING:
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.YOLO_DETECT
            else:
                nest_state = None

        elif state == States.YOLO_DETECT:
            if self.yolo_state == 1:
                self.ball_in_route = []
                self.get_logger().info('Detecting all hitpoint location\n')
                # flat array. First two indexis are for cueballx and y
                self.yolo_req.send_position = 3 
                yolo_res_ballinroute = self.call_yolo(self.yolo_req) # request 3 for ball in route
                self.ball_in_route = yolo_res_ballinroute.current_position
                self.Nballinroute = len(self.ball_in_route)
                print('cue_hitpoint:',self.ball_in_route)
                # nest_state = States.BF_HITBALL_POSE
                nest_state = States.SECOND_PHOTO
            elif self.yolo_state == 2:
                # self.cue_hitpoint = []
                # self.get_logger().info('Detecting specific hitpoint location\n')
                # self.yolo_req.send_position = 1
                # yolo_res = self.call_yolo(self.yolo_req) # request 1 for cueball hitpoint and vector
                # self.cue_hitpoint = yolo_res.current_position
                # print('cue_hitpoint:',self.cue_hitpoint)
                nest_state = States.BF_HITBALL_POSE
            else:
                nest_state = None
            
        elif state == States.SECOND_PHOTO:
            real_ball_position = []
            for i in range(0, self.Nballinroute, 2):
                self.get_logger().info('Moving to second photo pose %d\n'%i)
                pose = Twist()
                print(self.ball_in_route[i])
                print(self.ball_in_route[i+1])
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.ball_in_route[i], self.ball_in_route[i+1], -200.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
                req = self.generate_robot_request(
                    cmd_mode = RobotCommand.Request.PTP,
                    holding = True,
                    tool = CAM_TOOL,
                    pose = pose
                )
                self.call_hiwin(req)

                req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
                )
                res = self.call_hiwin(req)

                self.get_logger().info('Taking second photo to correct ball position\n')
                req = self.generate_robot_request(
                    cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                    digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                    digital_output_pin = LIGHT_PIN
                )
                self.call_hiwin(req)
                take_pics(2)
                time.sleep(1.0)
                self.get_logger().info('Photo taken\n')
                req = self.generate_robot_request(
                    cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                    digital_output_cmd = RobotCommand.Request.DIGITAL_OFF,
                    digital_output_pin = LIGHT_PIN
                )
                res = self.call_hiwin(req)
                # call yolo to see ball position
                self.yolo_req.send_position = 2
                yolo_second_res = self.call_yolo(self.yolo_req)
                # return whole list, first half of list for x-axis and second half for y-axis
                obj = yolo_second_res.current_position
                l = len(obj)/2
                l = int(l)
                objx = obj[0:l]
                objy = obj[l:l*2]
                print('close objx:\n', objx)
                print('close objy:\n',objy)
                # calculate closest ball relative to pixel mid point (1920/2, 932/2)
                # we only need the middle ball position here
                dis = []
                missx = []
                missy = []
                for j in range(0,l):
                    disx = objx[j]- tablewidth/2  # not actual tablewidth and height, but in pixels 1920*1080 
                    disy = objy[j] - 1080/2
                    temp_dis = math.sqrt((disx)**2+(disy)**2)
                    dis.append(temp_dis)
                    missx.append(disx)
                    missy.append(disy)
                midball_index = dis.index(min(dis))
                devx = missx[midball_index]
                devy = missy[midball_index]
                
                devmmx = devx*(tablewidth_mm*200)/(tablewidth*(-fix_abs_cam[2]))
                devmmy = devy*(tableheight_mm*200)/(tableheight*(-fix_abs_cam[2]))
                print('pixel deviation x:\n', devx)
                print('pixel deviation y:\n', devy)
                print('actual deviation x:\n', devmmx)
                print('actual deviation y:\n', devmmy)

                self.get_logger().info('Reading current arm pose\n')
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.CHECK_POSE,
                    tool = CAM_TOOL
                    )
                res = self.call_hiwin(req)
                current_pose = res.current_position
                # flat array. First two indexis are for cueballx and y
                real_ball_position.append(current_pose[0])
                real_ball_position.append(current_pose[1]+devmmy)
                print('cam tool x:\n', current_pose[0])
                print('cam tool y:\n', current_pose[1])
                print('actual ball position x:\n', current_pose[0])
                print('actual ball position y:\n', current_pose[1]+devmmy)
                # if devx <= tablewidth/2:
                #     if devy <= tableheight/2:
                #         real_ball_position.append(current_pose[0]-devmmx)
                #         real_ball_position.append(current_pose[0]-devmmy)
                #     else:
                #         real_ball_position.append(current_pose[0]-devmmx)
                #         real_ball_position.append(current_pose[0]+devmmy)
                # else:
                #     if devy <= tableheight/2:
                #         real_ball_position.append(current_pose[0]+devmmx)
                #         real_ball_position.append(current_pose[0]-devmmy)
                #     else:
                #         real_ball_position.append(current_pose[0]+devmmx)
                #         real_ball_position.append(current_pose[0]+devmmy)

            # convert real_ball_position from mm to pixels for strategy
            self.ball_position_pixels = []
            for j in range(0, len(real_ball_position), 2):
                tempx, tempy = mm_to_pixels(real_ball_position[j], real_ball_position[j+1])
                self.ball_position_pixels.append(tempx)
                self.ball_position_pixels.append(tempy)
            
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.RECALCULATE
            else:
                nest_state = None

        elif state == States.RECALCULATE:
            self.cue_hitpoint = []
            print('updated position:\n',self.ball_position_pixels)
            self.yolo_req.update_position = self.ball_position_pixels
            self.yolo_req.send_position = 4 # request 4 to update cueball hitpoint and vector
            re_yolo_res = self.call_yolo(self.yolo_req)
            self.get_logger().info('Reculculating hit ball location\n')
            self.cue_hitpoint = re_yolo_res.current_position
            print('cue_hitpoint:',self.cue_hitpoint)
            nest_state = States.BF_HITBALL_POSE


        elif state == States.BF_HITBALL_POSE:
            self.get_logger().info('Before hitting cueball\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = [self.cue_hitpoint[0], self.cue_hitpoint[1], -70.0]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.PTP,
                pose = pose
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.HITBALL_POSE
            else:
                nest_state = None

        elif state == States.HITBALL_POSE:
            self.get_logger().info('Going to hit cueball\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = [self.cue_hitpoint[0], self.cue_hitpoint[1], -20.0]
            [pose.angular.x, pose.angular.y] = fix_abs_cam[3:5]
            pose.angular.z = fix_abs_cam[5]+self.cue_hitpoint[2]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.LINE,
                pose = pose
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.HITBALL
            else:
                nest_state = None
        
        elif state == States.HITBALL:
            self.get_logger().info('Hitting cueball\n')
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
            )
            res = self.call_hiwin(req)
            # how hard it hits. Decided by the score of the route
            if self.cue_hitpoint[-1] >= 5000:
                hit_pin = HITSOFT_PIN
            else: # 5000 > self.cue_hitpoint[-1] >= 2000:
                hit_pin = HITMID_PIN
            # else:
            #     hit_pin = HITHEAVY_PIN

            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_ON,
                digital_output_pin = hit_pin
            )
            self.call_hiwin(req)
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.DIGITAL_OUTPUT,
                digital_output_cmd = RobotCommand.Request.DIGITAL_OFF,
                digital_output_pin = hit_pin
            )
            res = self.call_hiwin(req)
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.WAITING
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.AF_HITBALL_POSE
            else:
                nest_state = None
        
        elif state == States.AF_HITBALL_POSE:
            self.get_logger().info('Moving back to photo pose\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = [self.cue_hitpoint[0], self.cue_hitpoint[1], -70.0]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.LINE,
                pose = pose,
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.MOVE_TO_PHOTO_POSE
            else:
                nest_state = None

        elif state == States.MOVE_TO_PHOTO_POSE:
            self.cue_hitpoint = [] # clear array for next use
            self.get_logger().info('Moving to photo pose\n')
            pose = Twist()
            [pose.linear.x, pose.linear.y, pose.linear.z] = fix_abs_cam[0:3]
            [pose.angular.x, pose.angular.y, pose.angular.z] = fix_abs_cam[3:6]
            req = self.generate_robot_request(
                cmd_mode = RobotCommand.Request.PTP,
                tool = CAM_TOOL,
                pose = pose
            )
            res = self.call_hiwin(req)
            if res.arm_state == RobotCommand.Response.IDLE:
                nest_state = States.TAKE_PHOTO
            else:
                nest_state = None

        else:
            nest_state = None
            self.get_logger().info('input state not supported!\n')

        return nest_state

    def _main_loop(self):
        state = States.INIT
        while state != States.FINISH:
            state = self.strategy_state(state)
            if state == None:
                break
        self.destroy_node()

    def generate_robot_request(
            self, 
            holding=True,
            cmd_mode=RobotCommand.Request.PTP,
            cmd_type=RobotCommand.Request.POSE_CMD,
            velocity=DEFAULT_VELOCITY,
            acceleration=DEFAULT_ACCELERATION,
            tool=CUE_TOOL,
            base=MY_BASE,
            digital_output_pin=0,
            digital_output_cmd=RobotCommand.Request.DIGITAL_OFF,
            pose=Twist(),
            joints=[float('inf')]*6,
            circ_s=[],
            circ_end=[],
            jog_joint=6,
            jog_dir=0
            ):
        request = RobotCommand.Request()
        request.digital_output_pin = digital_output_pin
        request.digital_output_cmd = digital_output_cmd
        request.acceleration = acceleration
        request.jog_joint = jog_joint
        request.velocity = velocity
        request.tool = tool
        request.base = base
        request.cmd_mode = cmd_mode
        request.cmd_type = cmd_type
        request.circ_end = circ_end
        request.jog_dir = jog_dir
        request.holding = holding
        request.joints = joints
        request.circ_s = circ_s
        request.pose = pose
        return request
    
    def call_hiwin(self, req):
        while not self.hiwin_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting again...')
        future = self.hiwin_client.call_async(req)
        if self._wait_for_future_done(future):
            res = future.result()
        else:
            res = None
        return res

    def call_yolo(self, req):
        while not self.strategy_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('YOLO service not available, waiting again...')
        future = self.strategy_client.call_async(req)
        if self._wait_for_future_done(future):
            res = future.result()
        else:
            res = None
        return res
    
    def _wait_for_future_done(self, future: Future, timeout=-1):
        time_start = time.time()
        while not future.done():
            time.sleep(0.01)
            if timeout > 0 and time.time() - time_start > timeout:
                self.get_logger().error('Wait for service timeout!')
                return False
        return True
    
    def start_main_loop_thread(self):
        self.main_loop_thread = Thread(target=self._main_loop)
        self.main_loop_thread.daemon = True
        self.main_loop_thread.start()

    def test_request(self):
        key = input('Enter 1 or 0 to send ball location:\n')
        if key == '1':
            oi = 1
        else:
            oi = 0
        self.yolo_req.send_position = oi
        future = self.strategy_client.call_async(self.yolo_req)
        rclpy.spin_until_future_complete(self, future)
        # if self._wait_for_future_done(future):
        #     res = future.result()
        # else:
        #     res = None
       
        return future.result()
    

def main(args=None):
    rclpy.init(args=args)

    strategy = ArmsDealer_2()
    # # test yolo_service
    # response = strategy.test_request()
    # strategy.get_logger().info('ball location:{}\n'.format(response.current_position))

    #actual strategy client
    strategy.start_main_loop_thread()
    rclpy.spin(strategy)
    # strategy.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()