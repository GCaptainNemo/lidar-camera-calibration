# 激光雷达和相机标定
## 一、依赖库
PCL + OpenCV

## 二、硬件
Livox Horizon 激光雷达 + Hikvision 相机

## 三、介绍
激光雷达和相机之间标定需要标定相机的内参、畸变系数，和相机相对于激光雷达的位姿。具体步骤如下所示：

1. 相机内参和畸变系数用张正友标定法，通过Matlab或者Opencv等标定工具得到。
    
    ![相机内参和畸变系数标定](./resources/intrinsic.jpg)

2. 点云不含纹理信息，因此没法用标定板格子的角点进行外参标定，这里选择简单的一块铁板在较开阔的地区进行标定。

    ![外参标定板](./resources/2_1.bmp)

3. 使用livox-viewer录制点云流数据(.lvx文件)和用OpenCV抓图。

4. 使用lvx_parser文件夹下的pylvx.py脚本将lvx文件转成pcd文件。

5. 将多帧点云合成一帧(read_pcds_xyz函数)，然后分别进行点云特征点(interact_visualize函数)和图像对应特征点(Matlab)的提取。

    ![标定](./resources/calibration.jpg)

6. 然后用OpenCV的SolvePnp函数(cal_calib函数)进行外参求解。

## 四、资源及参考资料

[1] [内参标定板](](./resources/chess_board.png))

[2] [livox-官方标定方法](https://github.com/Livox-SDK/livox_camera_lidar_calibration)