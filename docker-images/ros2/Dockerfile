FROM ubuntu:20.04

RUN echo 'Etc/UTC' > /etc/timezone && \
    ln -s /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    apt-get update && apt-get install -q -y tzdata && rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt install -y software-properties-common
RUN add-apt-repository universe
RUN apt-get update && apt install -y curl gnupg lsb-release && rm -rf /var/lib/apt/lists/*
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o /usr/share/keyrings/ros-archive-keyring.gpg

RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" |  tee /etc/apt/sources.list.d/ros2.list > /dev/null

RUN apt-get update &&  apt-get install -y \
  build-essential \
  cmake \
  git \
  python3-flake8 \
  python3-pip \
  python3-pytest-cov \
  python3-rosdep \
  python3-setuptools \
  wget && rm -rf /var/lib/apt/lists/*
 
RUN python3 -m pip install -U \
  colcon-common-extensions \
  vcstool \
  flake8-blind-except \
  flake8-builtins \
  flake8-class-newline \
  flake8-comprehensions \
  flake8-deprecated \
  flake8-docstrings \
  flake8-import-order \
  flake8-quotes \
  pytest-repeat \
  pytest-rerunfailures \
  pytest \
  setuptools
  
RUN  mkdir -p ~/ros2_galactic/src && cd ~/ros2_galactic && wget https://raw.githubusercontent.com/ros2/ros2/galactic/ros2.repos && vcs import src < ros2.repos


RUN rosdep init
RUN rosdep update
RUN apt-get update && cd ~/ros2_galactic && rosdep install --from-paths src --ignore-src --rosdistro galactic -y --skip-keys "console_bridge fastcdr fastrtps rti-connext-dds-5.3.1 urdfdom_headers"

RUN cd ~/ros2_galactic/ && colcon build --symlink-install
RUN apt-get update  &&  apt-get install iputils-ping && rm -rf /var/lib/apt/lists/*

CMD ["/sbin/init"]
