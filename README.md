# docker_hiwin_ros2
Docker environment for hiwin robotics arm control.
Main fucntion is to use realsense to tell where the billard balls are and hit the ball accurately.

## Requirements
[**Run docker without sudo**](https://docs.docker.com/engine/install/linux-postinstall/)
```bash
sudo chmod 666 /var/run/docker.sock
```

## building 
```bash
# go to the environmet
.../docker

# build docker image
./build.sh
```

#### Quick start

```bash
# run docker
./run.sh
