# docker_hiwin_ros2
Docker environment for hiwin robotics arm control.
Main fucntion is to use realsense to tell where the billard balls are and hit the ball accurately.

## Acknowledgment
The Hiwin_libmodbus submodule package is from [Hiwin_libmodbus](https://github.com/tku-iarc/Hiwin_libmodbus.git).\
The libumodbus submodule package is from [libmodus](https://github.com/stephane/libmodbus.git).

## Requirements
This package requires operating system ubuntu and setup with docker.\
[Docker install method](https://docs.docker.com/engine/install/ubuntu/)\
running docker without sudo\
[**Run docker without sudo**](https://docs.docker.com/engine/install/linux-postinstall/)
```bash
sudo chmod 666 /var/run/docker.sock
```
## building 
```bash
clone docker repo with libmodbus submodule within Hiwin_libmodbus submodule to your pc
git clone --recurse-submodules https://github.com/zhekai-w/docker_hiwin_ros2_ws.git

# go to the environment
cd .../docker

# build docker image
./build.sh
```
#### Quick start
```bash
# run docker
./run.sh
