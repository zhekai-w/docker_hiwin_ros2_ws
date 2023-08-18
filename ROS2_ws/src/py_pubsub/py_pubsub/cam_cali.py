import pyrealsense2 as rs
import numpy as np
import cv2


# import rclpy
# from rclpy.node import Node

# from std_msgs.msg import Float32MultiArray




def YOLO_manual_calibration():
    # Create a context object. This object owns the handles to all connected realsense devices
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.color, 1920, 1080, rs.format.bgr8, 30)
    a = 0
    # Start streaming
    pipeline.start(config)

    # Instructions for user
    print('Press m to take pictures')
    print('Press q to quit camera\n')
    while True:

        # Wait for a coherent pair of frames: depth and color
        frames = pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()
        # if not color_frame:
        #     continue

        # Convert images to numpy arrays
        color_image = np.asanyarray(color_frame.get_data())
        # Draw pool table outline
        startoutline = (0,932)
        endoutline = (1920,932)
        table_outline = cv2.line(color_image,startoutline,endoutline,color=(0,0,0),thickness=1)
        startmidline = (960,0)
        endmidline = (960,932)
        middle_line = cv2.line(table_outline,startmidline,endmidline,color=(0,0,0),thickness=1)
        # Draw calibration board outline
        midboxupS = (899,396)
        midboxupE = (1021,518)
        midbox_img = cv2.rectangle(middle_line, midboxupS, midboxupE, color=(0,0,0), thickness=1)
        uppermidS = (899,167)
        uppermidE = (1021,289)
        uppermid_img = cv2.rectangle(midbox_img,uppermidS, uppermidE, color=(0,0,0), thickness=1)
        lowermidS = (899,625)
        lowermidE = (1021,747)
        lowermid_img = cv2.rectangle(uppermid_img,lowermidS, lowermidE, color=(0,0,0), thickness=1)
        leftS = (542,396)
        leftE = (664,518)
        left_img = cv2.rectangle(lowermid_img,leftS, leftE, color=(0,0,0), thickness=1)
        rightS = (1256,396)
        rightE = (1378,518)
        done_img = cv2.rectangle(left_img,rightS, rightE, color=(0,0,0), thickness=1)

        # YOLO detect
        # detected_img = detect_ALL(done_img)[0]

        # Resize color image 
        resized_color_image = cv2.resize(done_img, dsize=(1280,720), interpolation=cv2.INTER_AREA)    

        # Show images
        cv2.namedWindow('RealSense', cv2.WINDOW_AUTOSIZE)
        cv2.imshow('RealSense', done_img)
        key=cv2.waitKey(1)
        if key&0xFF==ord('m'):
            a=a+1
            print("picture take")
            cv2.imwrite('/home/zack/work/ROS2_ws/src/py_pubsub/py_pubsub/testpics/PoolBall_%d.jpg'% (a),done_img)
        if key&0xFF==ord('q'):
            break

    # Stop streaming
    pipeline.stop()


        


def main():
    # camera to do manual calibration press
    YOLO_manual_calibration()


if __name__ == '__main__':
    main()

        



