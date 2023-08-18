import rclpy
from rclpy.node import Node
from yolo_strategy_interfaces.srv import YoloStrategy

import math
import cv2
import py_pubsub.darknet as darknet
import py_pubsub.pool_strategy as ps
import pyrealsense2 as rs

"""
神經網路檔案位置_檢測全部拼圖
"""
ALL_cfg_path ="/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/cfg/yolov4-obj.cfg"      #'./cfg/yolov4-obj.cfg'
ALL_weights_path = '/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/cfg/weights/ALL/yolov4-obj_best.weights'
ALL_data_path = '/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/cfg/hiwin_C_WDA_v4.data'


"""
載入神經網路
"""
ALL_network, ALL_class_names, ALL_class_colors = darknet.load_network(
        ALL_cfg_path,
        ALL_data_path,
        ALL_weights_path,
        batch_size=1
)



"""
影像檢測
    輸入:(影像位置,神經網路,物件名稱集,信心值閥值(0.0~1.0))
    輸出:(檢測後影像,檢測結果)
    註記:
"""
def image_detection(image, network, class_names, class_colors, thresh):
    # Darknet doesn't accept numpy images.
    # Create one with image we reuse for each detect
    width = darknet.network_width(network)
    height = darknet.network_height(network)
    darknet_image = darknet.make_image(width, height, 3)

    
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    image_resized = cv2.resize(image_rgb, (width, height),
                               interpolation=cv2.INTER_LINEAR)

    darknet.copy_image_from_bytes(darknet_image, image_resized.tobytes())
    detections = darknet.detect_image(network, class_names, darknet_image, thresh=thresh)
    darknet.free_image(darknet_image)
    image = darknet.draw_boxes(detections, image_resized, class_colors)
    return cv2.cvtColor(image, cv2.COLOR_BGR2RGB), detections



"""
座標轉換
    輸入:(YOLO座標,原圖寬度,原圖高度)
    輸出:(框的左上座標,框的右下座標)
    註記:
"""
def bbox2points(bbox,W,H):
    """
    From bounding box yolo format
    to corner points cv2 rectangle
    """ 
    width = darknet.network_width(ALL_network)      # YOLO壓縮圖片大小(寬)
    height = darknet.network_height(ALL_network)    # YOLO壓縮圖片大小(高)

    x, y, w, h = bbox                           # (座標中心x,座標中心y,寬度比值,高度比值)
    x = x*W/width
    y = y*H/height
    w = w*W/width
    h = h*H/height
    # 輸出框座標_YOLO格式
    # print("     (left_x: {:.0f}   top_y:  {:.0f}   width:   {:.0f}   height:  {:.0f})".format(x, y, w, h))
    xmin = int(round(x - (w / 2)))
    xmax = int(round(x + (w / 2)))
    ymin = int(round(y - (h / 2)))
    ymax = int(round(y + (h / 2)))
    
    return xmin, ymin, xmax, ymax



"""
原圖繪製檢測框線
    輸入:(檢測結果,原圖位置,框線顏色集)
    輸出:(影像結果)
    註記:
"""
def draw_boxes(detections, image, colors):
    ball_imformation = [[-999 for i in range(4)] for j in range(20)]
    i = 0

    H,W,_ = image.shape                      # 獲得原圖長寬

    # cv2.line(image,(640,0),(640,720),(0,0,255),5)

    for label, confidence, bbox in detections:
        xmin, ymin, xmax, ymax = bbox2points(bbox,W,H)

        cv2.rectangle(image, (xmin, ymin), (xmax, ymax), colors[label], 1)
        cv2.putText(image, "{} [{:.2f}]".format(label, float(confidence)),
                    (xmin, ymin - 5), cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                    colors[label], 2)
        # 輸出框座標_加工格式座標(左上點座標,右上點座標)
        #print("\t{}\t: {:3.2f}%    (x1: {:4.0f}   y1: {:4.0f}   x2: {:4.0f}   y2: {:4.0f})".format(label, float(confidence), xmin, ymin, xmax, ymax))
        
        mx = float(xmax + xmin)/2
        my = float(ymax + ymin)/2

        # cv2.circle(image, (int(mx),int(my)), 33, (0,0,255), 3)
        if label == 'C':
            ball_imformation[i] = [0.0, float(confidence), mx, my]
        elif label == 'M':
            ball_imformation[i] = [1.0, float(confidence), mx, my]
        i+=1
        
    return image, ball_imformation

def detect_ALL(img,thresh=0.8):
    out,detections = image_detection(img,ALL_network, ALL_class_names, ALL_class_colors,thresh)
    out2, ball_imformation= draw_boxes(detections, img, ALL_class_colors)
    # cv2.imshow('out2', out2)
    # cv2.waitKey()
    # cv2.destroyAllWindows()
    return out2, ball_imformation

def yaw_angle(vectorx, vectory):
    org_vector = [0,1]
    vectorlength = math.sqrt((vectorx**2)+(vectory**2))
    rad = math.acos((-1*vectory)/(vectorlength*1))
    theta = rad*180/math.pi
    if vectorx >= 0:
        return theta, rad
    elif vectorx < 0:
        return -theta, -rad
    
def pixel_mm_convert(pixel):
    actuallengh = 626
    pixellengh = 1920
    mm = actuallengh/pixellengh*pixel
    return mm

def realsense_intrinsics(x, y):
    width = 1920
    height = 1080
    fps = 30
    depth = 1
    
    calibrated_intrinsics_f = [1362.38, 1360.45]
    calibrated_intrinsics_pp = [938.315, 552.935]

    dis_coeffs = [0.0693826933, 0.445315521, 0.00291064076, -0.000845071017, -1.99098719]

    _intrinsics = rs.intrinsics()
    _intrinsics.width = width
    _intrinsics.height = height
    _intrinsics.ppx = calibrated_intrinsics_pp[0]
    _intrinsics.ppy = calibrated_intrinsics_pp[1]
    _intrinsics.fx = calibrated_intrinsics_f[0]
    _intrinsics.fy = calibrated_intrinsics_f[1]
    #_intrinsics.model = cameraInfo.distortion_model
    _intrinsics.model  = rs.distortion.none
    _intrinsics.coeffs = dis_coeffs

    # pipeline = rs.pipeline()
    # config = rs.config()
    # config.enable_stream(rs.stream.color, width, height, rs.format.bgr8, fps)
    # config.enable_stream(rs.stream.depth, width, height, rs.format.z16, fps)

    # ストリーミング開始

    # profile = pipeline.start(config)
    # depth_intrinsics = rs.video_stream_profile(profile.get_stream(rs.stream.depth)).get_intrinsics()
    # color_intrinsics = rs.video_stream_profile(profile.get_stream(rs.stream.color)).get_intrinsics()

    pixel = [x, y]
    ca_point = rs.rs2_deproject_pixel_to_point(_intrinsics, pixel, depth)
    # print('calibrated point:',ca_point)

    x_ = int(ca_point[0] * calibrated_intrinsics_f[0] + calibrated_intrinsics_pp[0])
    y_ = int(ca_point[1] * calibrated_intrinsics_f[1] + calibrated_intrinsics_pp[1])
    # print('calibrated intrinsics x:',x_)
    # print('calibrated intrinsics y:',y_)

    # pipeline.stop()
    return x_, y_

def cam_angle_correction(camseex, camseey):
    width = 1920
    height = 1080
    midx = abs(width/2-camseex)
    midy = abs(height/2-camseey)
    devx = 16/455.417*midx 
    devy = 16/455.417*midy
    if camseex <= width/2:
        if camseey <= height/2:
            actx = camseex-devx
            acty = camseey-devy
        else:
            actx = camseex-devx
            acty = camseey+devy
    
    else:
        if camseey <= height/2:
            actx = camseex+devx
            acty = camseey-devy
        else:
            actx = camseex+devx
            acty = camseey+devy

    return  actx, acty

class YOLOService(Node):
    def __init__(self):
        super().__init__('yolo_service')
        self.yolo_service = self.create_service(YoloStrategy, 'yolo_strategy', self.service_callback)
        self.n = 2201
        # self.objectballx = []
        # self.objectbally = []
        # self.confidence = []
        # self.objx = []
        # self.objy = []

    def service_callback(self, request, response):
        # detect image
        # clear array
        flat_list = []
        self.objectballx = []
        self.objectbally = []
        self.confidence = []
        self.intrin_objx = []
        self.intrin_objy = []
        self.corrected_objx = []
        self.corrected_objy = []

        if request.send_position == 1:
            self.get_logger().info('request for current ball location\n')
            img = cv2.imread('/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/testpics/detect_ball.jpg')

            out2, ballinfo = detect_ALL(img)
            # check for non float value in ballinfo since flat_list does not accept data other than float
            cnt = 0
            for i in range(len(ballinfo)):
                if ballinfo[i][1] != -999:
                    cnt += 1
                else:
                    break
            #flatten list of 2darray to 1darray
            flat_list = []
            for i in range(0,cnt):
                flat_list.extend(ballinfo[i])

            # response.current_position = flat_list
            # self.get_logger().info('current ball location sent !\n')
            # self.n += 1

            # convert flat array to usable array 
            # in this case objectballx(y)[], with cuex(y) in objectballx(y)[-1] and confidence[]
            self.get_logger().info('culculating best route\n')
            for i in range(0,len(flat_list),4):
                if flat_list[i] == 0:
                    self.confidence.append(flat_list[i+1])
                    self.objectballx.append(flat_list[i+2])
                    self.objectbally.append(flat_list[i+3])
                else:
                    cueindex = i
            self.confidence.append(flat_list[cueindex+1])
            self.objectballx.append(flat_list[cueindex+2])
            self.objectbally.append(flat_list[cueindex+3])

            print("input objectball x:\n",self.objectballx)
            print("input objectball y:\n",self.objectbally)
            n = len(self.objectballx)

            for i in range(0,n):
                # realsense intrinsics calibration
                intrinx, intriny = realsense_intrinsics(self.objectballx[i], self.objectbally[i])
                self.intrin_objx.append(intrinx)
                self.intrin_objy.append(intriny)
                # cam angle correction
                realx, realy = cam_angle_correction(intrinx, intriny)
                self.corrected_objx.append(realx)
                self.corrected_objy.append(realy)
            print('intrinsics objectball x:\n', self.intrin_objx)
            print('intrinsics objectball y:\n', self.intrin_objy)
            print('real objectball x:\n',self.corrected_objx)
            print('real objectball y:\n',self.corrected_objy)


            ValidRoute, bestrouteindex = ps.main(self.corrected_objx[-1],self.corrected_objy[-1], 
                                                self.corrected_objx[0:n], self.corrected_objy[0:n],n-1)
            print('All valid route:\n',ValidRoute)
            print('Best route index:',bestrouteindex)
            print('Best Route:\n',ValidRoute[bestrouteindex])
            print('Score of best route:\n',ValidRoute[bestrouteindex][0])

            hitpointx, hitpointy = ps.findhitpoint(self.corrected_objx[-1],self.corrected_objy[-1],
                                                ValidRoute[bestrouteindex][3][0],ValidRoute[bestrouteindex][3][1])
            yaw, rad = yaw_angle(ValidRoute[bestrouteindex][3][0],ValidRoute[bestrouteindex][3][1])
            hitpointmmx = pixel_mm_convert(hitpointx)
            hitpointmmy = pixel_mm_convert(hitpointy)
            score = ValidRoute[bestrouteindex][0]

            # print('mmx:',hitpointmmx)
            # print('mmy:',hitpointmmy)
            # print('rad:',rad)
            # print('pixelx:',hitpointx)
            # print('pixely:',hitpointy)
            print('degree:',yaw)
            # print('best route index:',bestrouteindex)
            # print('vectorx:',ValidRoute[bestrouteindex][3][0])
            # print('vectory:',ValidRoute[bestrouteindex][3][1])
            # print('all route:',ValidRoute)

            response.current_position = [hitpointmmx, hitpointmmy, yaw, score]
            
        elif request.send_position == 2: # detect second photo 
            self.get_logger().info('detecting second photo ! \n')
            img2 = cv2.imread('/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/testpics/detect_second_ball.jpg')
            out2, ballinfo = detect_ALL(img2)
            # check for non float value in ballinfo since flat_list does not accept data other than float
            cnt = 0
            for i in range(len(ballinfo)):
                if ballinfo[i][1] != -999:
                    cnt += 1
                else:
                    break
            #flatten list of 2darray to 1darray
            flat_list = []
            for i in range(0,cnt):
                flat_list.extend(ballinfo[i])

            # convert flat array to usable array 
            # in this case objectballx(y)[], with cuex(y) in objectballx(y)[-1] and confidence[]
            self.get_logger().info('culculating best route\n')
            for i in range(0,len(flat_list),4):
                if flat_list[i] == 0:
                    self.confidence.append(flat_list[i+1])
                    self.objectballx.append(flat_list[i+2])
                    self.objectbally.append(flat_list[i+3])
                else:
                    cueindex = i
            self.confidence.append(flat_list[cueindex+1])
            self.objectballx.append(flat_list[cueindex+2])
            self.objectbally.append(flat_list[cueindex+3])

            print("input objectball x:\n",self.objectballx)
            print("input objectball y:\n",self.objectbally)
            n = len(self.objectballx)

            # DO CAMERA CALIBRATION HERE

            # return whole list, first half of list for x-axis and second half for y-axis
            wholelist = self.objectballx + self.objectbally
            print('1D ball position:\n', wholelist)
            response.current_position = wholelist

        elif request.send_position == 3: # send all ball in route
            self.get_logger().info('request for current ball location\n')
            img = cv2.imread('/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/testpics/detect_ball.jpg')

            out2, ballinfo = detect_ALL(img)
            # check for non float value in ballinfo since flat_list does not accept data other than float
            cnt = 0
            for i in range(len(ballinfo)):
                if ballinfo[i][1] != -999:
                    cnt += 1
                else:
                    break
            #flatten list of 2darray to 1darray
            flat_list = []
            for i in range(0,cnt):
                flat_list.extend(ballinfo[i])

            # response.current_position = flat_list
            # self.get_logger().info('current ball location sent !\n')
            # self.n += 1

            # convert flat array to usable array 
            # in this case objectballx(y)[], with cuex(y) in objectballx(y)[-1] and confidence[]
            self.get_logger().info('culculating best route\n')
            for i in range(0,len(flat_list),4):
                if flat_list[i] == 0:
                    self.confidence.append(flat_list[i+1])
                    self.objectballx.append(flat_list[i+2])
                    self.objectbally.append(flat_list[i+3])
                else:
                    cueindex = i
            self.confidence.append(flat_list[cueindex+1])
            self.objectballx.append(flat_list[cueindex+2])
            self.objectbally.append(flat_list[cueindex+3])

            print("input objectball x:\n",self.objectballx)
            print("input objectball y:\n",self.objectbally)
            n = len(self.objectballx)

            for i in range(0,n):
                # realsense intrinsics calibration
                intrinx, intriny = realsense_intrinsics(self.objectballx[i], self.objectbally[i])
                self.intrin_objx.append(intrinx)
                self.intrin_objy.append(intriny)
                # cam angle correction
                realx, realy = cam_angle_correction(intrinx, intriny)
                self.corrected_objx.append(realx)
                self.corrected_objy.append(realy)
            print('intrinsics objectball x:\n', self.intrin_objx)
            print('intrinsics objectball y:\n', self.intrin_objy)
            print('real objectball x:\n',self.corrected_objx)
            print('real objectball y:\n',self.corrected_objy)


            ValidRoute, bestrouteindex = ps.main(self.corrected_objx[-1],self.corrected_objy[-1], 
                                                self.corrected_objx[0:n], self.corrected_objy[0:n],n-1)
            # route() return this
            # score,cuefinalvector,cue,cuetoivector, objectballi, itok2vector, objectballk2 ,k2tok1vector, objectballk1, toholevector,n
            self.get_logger().info('sending best route ! \n')
            NBallInRoute = ValidRoute[bestrouteindex][-1] + 2 
            if ValidRoute[bestrouteindex][0] == -6000: #lcuky ball
                temp_flat = []
                temp_flat.append(float(ValidRoute[bestrouteindex][2][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][2][1]))
                response.current_position = temp_flat
            elif NBallInRoute == 2:
                temp_flat = []
                temp_flat.append(float(ValidRoute[bestrouteindex][2][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][2][1]))
                temp_flat.append(float(ValidRoute[bestrouteindex][4][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][4][1]))
                response.current_position = temp_flat
            elif NBallInRoute == 3:
                temp_flat = []
                temp_flat.append(float(ValidRoute[bestrouteindex][2][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][2][1]))
                temp_flat.append(float(ValidRoute[bestrouteindex][4][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][4][1]))
                temp_flat.append(float(ValidRoute[bestrouteindex][6][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][6][1]))
                response.current_position = temp_flat
            else:
                temp_flat = []
                temp_flat.append(float(ValidRoute[bestrouteindex][2][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][2][1]))
                temp_flat.append(float(ValidRoute[bestrouteindex][4][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][4][1]))
                temp_flat.append(float(ValidRoute[bestrouteindex][6][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][6][1]))
                temp_flat.append(float(ValidRoute[bestrouteindex][8][0]))
                temp_flat.append(float(ValidRoute[bestrouteindex][8][1]))
                # first index is cueball and the rest follow(s)
                temp_flat_mm = []
                for i in range(len(temp_flat)):
                    temp = pixel_mm_convert(temp_flat)
                    temp_flat_mm.append(temp)

                response.current_position = temp_flat_mm
                print(temp_flat_mm)

        elif request.send_position == 4:
            re_position = request.update_position
            cuex = re_position[0]
            cuey = re_position[1]
            objx = []
            objy = []
            l = len(re_position)
            for i in range(2,len(re_position)):
                objx.append(re_position[i])
                objy.append(re_position[i+1])

            re_Route, re_bestindex = ps.main(cuex, cuey, objx, objy, l/2-1) 

            new_hitpointx, new_hitpointy = ps.findhitpoint(objx[-1], objy[-1],
                                                re_Route[re_bestindex][3][0],re_Route[re_bestindex][3][1])
            new_yaw, rad = yaw_angle(re_Route[re_bestindex][3][0],re_Route[re_bestindex][3][1])
            new_hitpointmmx = pixel_mm_convert(new_hitpointx)
            new_hitpointmmy = pixel_mm_convert(new_hitpointy)
            score = ValidRoute[bestrouteindex][0]

            response.current_position = [new_hitpointmmx, new_hitpointmmy, new_yaw, score]

        else:
            self.get_logger().info('waiting for proper request...')
            response.current_position = [-3.0]
            
        return response
    
def main(args=None):
    rclpy.init(args=args)

    yolo_strategy = YOLOService()

    rclpy.spin(yolo_strategy)

    rclpy.shutdown()

if __name__=='__main__':
    main()