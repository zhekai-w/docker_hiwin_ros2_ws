#!/usr/bin/env python3
import time
import rclpy
from enum import Enum
from threading import Thread
from rclpy.node import Node
from rclpy.task import Future
from typing import NamedTuple
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32MultiArray

from hiwin_interfaces.srv import RobotCommand
# from YoloDetector import YoloDetectorActionClient

DEFAULT_VELOCITY = 30
DEFAULT_ACCELERATION = 30

VACUUM_PIN = 3

PHOTO_POSE = [0.00, 0.00, 0.00, 0.00, -90.00, 0.00]
# OBJECT_POSE = [20.00, 0.00, 0.00, 0.00, -90.00, 0.00]
OBJECT_POSE = [-67.517, 361.753, 293.500, 180.00, 0.00, 100.572]
PLACE_POSE = [-20.00, 0.00, 0.00, 0.00, -90.00, 0.00]

upperpoint = [0.0, -75.0] 
midpoint = [0.0, 0.0]
lowerpoint = [0.0, 75.0]
leftpoint = [117.0, 0.0]
rightpoint = [-117.0, 0.0]


NUM_OBJECTS = 5


class States(Enum):
    INIT = 0
    FINISH = 1
    KK = 99
    MOVE_TO_PHOTO_POSE = 2
    YOLO_DETECT = 3
    MOVE_TO_OPJxECT_TOP = 4
    PICK_OBJECT = 5
    MOVE_TO_PLACE_POSE = 6
    CHECK_POSE = 7
    CLOSE_ROBOT = 8

    MOVE_TO_TOP = 9
    MOVE_TO_MID = 10
    MOVE_TO_BOT = 11
    MOVE_TO_LEFT = 12
    MOVE_TO_RIGHT = 13
    MOVE_TO_LOWER = 14

class ManualCalibration(Node):
    def __init__(self):
        super().__init__('manual_calibration')
        self.hiwin_client = self.create_client(RobotCommand, 'hiwinmodbus_service')
        self.fix_campoint = Twist()
        self.basepoint_offset = [-32, 137, 380, 0, 0, 0]

    def calibration_state(self, state: States) -> States:
        if state == States.INIT:
            self.get_logger().info('Reading arm current position')
            req = self.generate_robot_request(
                cmd_mode=RobotCommand.Request.CHECK_POSE)
            res = self.call_hiwin(req)
            self.fix_campoint = res.current_position
            print(res.current_position)
            

            print('len of this shit:\n',len(res.current_position))
            nest_state = States.MOVE_TO_LOWER
        
        elif state == States.MOVE_TO_LOWER:
            self.get_logger().info('moving to lower point z')
            key = input('enter y to continue:\n')
            if key == 'y':
                pose = Twist()
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.fix_campoint[0],self.fix_campoint[1],85.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.MOVE_TO_TOP
                else:
                    nest_state = None

        elif state == States.MOVE_TO_TOP:
            self.get_logger().info('moving to top point')
            key = input('enter y to continue:\n')
            if key == 'y':
                pose = Twist()
                totaloffsetx = upperpoint[0]
                totaloffsety = upperpoint[1]
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.fix_campoint[0]+totaloffsetx,self.fix_campoint[1]+totaloffsety, 85.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.MOVE_TO_MID
                else:
                    nest_state = None
        
        elif state == States.MOVE_TO_MID:
            self.get_logger().info('moving to mid point')
            key = input('enter y to continue\n')
            if key == 'y':
                pose = Twist()
                totaloffsetx = midpoint[0]
                totaloffsety = midpoint[1]
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.fix_campoint[0]+totaloffsetx,self.fix_campoint[1]+totaloffsety, 85.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.MOVE_TO_BOT
                else:
                    nest_state = None

        elif state == States.MOVE_TO_BOT:
            self.get_logger().info('moving to lower point')
            key = input('enter y to continue\n')
            if key == 'y':
                pose = Twist()
                totaloffsetx = lowerpoint[0]
                totaloffsety = lowerpoint[1]
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.fix_campoint[0]+totaloffsetx,self.fix_campoint[1]+totaloffsety, 85.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.MOVE_TO_LEFT
                else:
                    nest_state = None

        elif state == States.MOVE_TO_LEFT:
            self.get_logger().info('moving to left point')
            key = input('enter y to continue\n')
            if key == 'y':
                pose = Twist()
                totaloffsetx = leftpoint[0]
                totaloffsety = leftpoint[1]
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.fix_campoint[0]+totaloffsetx,self.fix_campoint[1]+totaloffsety, 85.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.MOVE_TO_RIGHT
                else:
                    nest_state = None

        elif state == States.MOVE_TO_RIGHT:
            self.get_logger().info('moving to mid point')
            key = input('enter y to continue\n')
            if key == 'y':
                pose = Twist()
                totaloffsetx = rightpoint[0]
                totaloffsety = rightpoint[1]
                [pose.linear.x, pose.linear.y, pose.linear.z] = [self.fix_campoint[0]+totaloffsetx,self.fix_campoint[1]+totaloffsety, 85.0]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.MOVE_TO_PHOTO_POSE
                else:
                    nest_state = None
        
        elif state == States.MOVE_TO_PHOTO_POSE:
            self.get_logger().info('going back to fix camera point')
            key = input('enter y to continue\n')
            if key == 'y':
                pose = Twist()
                [pose.linear.x, pose.linear.y, pose.linear.z] = self.fix_campoint[0:3]
                [pose.angular.x, pose.angular.y, pose.angular.z] = self.fix_campoint[3:6]
                req = self.generate_robot_request(
                    cmd_mode=RobotCommand.Request.PTP,
                    pose=pose)
                res = self.call_hiwin(req)
                if res.arm_state == RobotCommand.Response.IDLE:
                    nest_state = States.FINISH

        else:
            nest_state = None
            self.get_logger().info('input state not supported')

        return nest_state
    
        

    def _main_loop(self):
        state = States.INIT
        while state != States.FINISH:
            state = self.calibration_state(state)
            if state == None:
                break
        self.destroy_node()

    def _wait_for_future_done(self, future: Future, timeout=-1):
        time_start = time.time()
        while not future.done():
            time.sleep(0.01)
            if timeout > 0 and time.time() - time_start > timeout:
                self.get_logger().error('Wait for service timeout!')
                return False
        return True
    
    def generate_robot_request(
            self, 
            holding=True,
            cmd_mode=RobotCommand.Request.PTP,
            cmd_type=RobotCommand.Request.POSE_CMD,
            velocity=DEFAULT_VELOCITY,
            acceleration=DEFAULT_ACCELERATION,
            tool=1,
            base=0,
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
        print("Start call Hiwin")
        while not self.hiwin_client.wait_for_service(timeout_sec=2.0):
            self.get_logger().info('service not available, waiting again...')
        future = self.hiwin_client.call_async(req)
        
        if self._wait_for_future_done(future):
            res = future.result()
        else:
            res = None
        print(res)    
        return res

    def call_yolo(self):
        class YoloResponse(NamedTuple):
            has_object: bool
            object_pose: list
        has_object = True if self.object_cnt < 5 else False
        object_pose = OBJECT_POSE
        res = YoloResponse(has_object,object_pose)
        # res.has_object = True if self.object_cnt < 5 else False
        # res.object_pose = OBJECT_POSE
        self.object_cnt += 1
        return res

    def start_main_loop_thread(self):
        self.main_loop_thread = Thread(target=self._main_loop)
        self.main_loop_thread.daemon = True
        self.main_loop_thread.start()


def main(args=None):
    rclpy.init(args=args)

    calibration = ManualCalibration()
    calibration.start_main_loop_thread()
    # manual_cali = ManualCalibration()

    rclpy.spin(calibration)
    rclpy.shutdown()

if __name__ == "__main__":
    main()