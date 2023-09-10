# Navigation Onboarding 2023

This is the official repository for UMARV Navigation subteams onboarding documents for 2023.

**Project Overview**\
You are a bank robber living in the digital age. All people and banks use ROS 1 noetic. In this tutorial, you will learn how to use ROS publishers and subscribers to receive the secret message that contains the vault key code. Once you have received and cracked the code, send it via a ROS client to a ROS service to get the money from the vault.\
_Topic Overview:_\
Publishers & Subscribers\
Services & Clients\
Custom Message Types\
ROS Command Line Tools\
Much More!


**DO NOT LOOK AT ANY OF THE FILES IN THIS REPOSITORY**

**PREREQUISITES TO STARTING**\
Follow this guide to download
docker:
[Docker Tutorial](https://docs.google.com/document/d/1BoBzBi_zj4UksIr_JSo8NRH-JYdkBk_sFzb5_qUIuQs/edit?usp=drive_link)

**HOW TO COMPLETE THE NAV ONBOARDING** \
Open your docker container in VNC viewer \
Open terminal\

```shell
cd ~\
mkdir ros_tutorial_ws\
cd ros_tutorial_ws\
mkdir src\
cd src\
git clone https://github.com/umigv/nav_onboarding_2023.git .\
cd ..\
catkin build\
source devel/setup.bash\
roscore\
```

Open a new terminal (CTRL-t) NOTE: If you're using the online view, you can't control t without opening a new browser
tab. So just go into the file tab in your terminal and open a new tab that way.

```shell
source devel/setup.bash\
roslaunch secret_msg secret_msg.launch\
```

Open a new tab (Reminder: you should still be in ~/ros_tutorial_ws)\

```shell
rosnode list
```

**Hint play with the rosnode functions and see what you can learn.**\
[Rosnode Documentation](http://wiki.ros.org/rosnode)

**CREATING YOUR CUSTOM PACKAGE**\
You are now set up for the tutorial. Hopefully, you have learned a bit about the structure of ROS at this point as well.
Now you need to create a custom ROS package to subscribe to data from the secret_msg node and use that data to call a
service in the vault_key pad node. You are a bank robber and your goal is to, as one may say, "Get dat bread". Use the
ROS WIKI tutorials to help guide you. This is not an easy task and by no means is this tutorial exhaustive so please do
not hesitate to ask for help!\
Open a new terminal.

```commandline
cd ~/ros_tutorial_ws\
source devel/setup.bash\
catkin create pkg <package_name> roscpp rospy std_msgs std_srvs message_generation\
```

Hint: use `rosnode list` and `rosnode info <node_name>` to find what topic to subscribe to.\
[Publisher Tutorial](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29)\
Go to the link above for a ros publisher, and subscriber tutorial.\
Hint: use -> rosservice list\
[Service Client Tutorial](http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29) \
Go to the link above for a ros service and client tutorial. \
Call the service you found using rosservice list.\
If you are struggling you can send “HELP” to the service and it will return a helpful message.\
