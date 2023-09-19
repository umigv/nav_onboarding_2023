# Navigation Onboarding 2023

This is the official repository for UMARV Navigation subteams onboarding documents for 2023.

## Project Overview
You are a bank robber living in the digital age. All people and banks use ROS 1 noetic. In this tutorial, you will learn how to use ROS publishers and subscribers to receive the secret message that contains the vault key code. Once you have received and cracked the code, send it via a ROS client to a ROS service to get the money from the vault.

**Topic Overview:**
- Publishers & Subscribers
- Services & Clients
- Custom Message Types
- ROS Command Line Tools
- Much More!

<br>

# DO NOT LOOK AT ANY OF THE OTHER FILES IN THIS REPOSITORY
### Prerequisites to Starting
- Follow this guide to download
docker:
[Docker Tutorial](https://docs.google.com/document/d/1BoBzBi_zj4UksIr_JSo8NRH-JYdkBk_sFzb5_qUIuQs/edit?usp=drive_link)
- Open your docker container in VNC viewer (You can also view the container in your browser)
- Open a terminal window

<br><br>
<h1> Navigation Onboarding Tutorial </h1>

<h2>Setup the Workspace</h2>

Before getting started, we first need to download the code onto your computer. Follow the steps below in your terminal window. Make sure you are in the correct folder/directory when running the commands! There will be explanations of each command you run below it.

```shell
cd ~
```
- The `cd` (current directory) command changes which folder you are currently in.
- The `~` directory is known as the "home" directory, and is where a terminal is opened to by default. Running this will make sure everyone starts in the same location.


```shell
mkdir ros_tutorial_ws
```
- The `mkdir` command creates a folder in the directory you are currently in. In this case, we create a folder called "ros_tutorial_ws", which will hold all the code we write/download for this onboarding tutorial.


```shell
cd ros_tutorial_ws
catkin init
mkdir src
cd src
```
- We move into the just-created "ros_tutorial_ws" folder, and create a "src" folder within it. We then move into the src folder. This means our current path would be `~/ros_tutorial_ws/src`.
- catkin init is used to initialize the workspace, this allows ROS to recognize `~/ros_tutorial_ws` as the root directory for the workspace.


```shell
git clone https://github.com/umigv/nav_onboarding_2023.git .
```
- This command will make a copy of the code on this github page, and place it in your current directory (which we moved into above). By running the `ls` command, you should now see two folders and this README.md file in the folder.

```shell
cd ~/ros_tutorial_ws
```
- We now move back out to the "ros_tutorial_ws" folder we created originally, so we can build and run the code we've just copied.

Note that this portion of copying the code only needs to be done once!

<br>
<h2>Run the Starting Files</h2>

You will need to have a terminal window open. If you are continuing from the previous section, you can use the same terminal window!

```shell
cd ~/ros_tutorial_ws
```
- By default a terminal will open to the home (`~`) directory, but we want to be in the tutorial folder.


```shell
catkin build
```
- Running the `catkin build` command will compile all projects within the "ros_tutorial_ws" directory into executable files that your computer can run. (Don't worry, you don't need to understand how this works!)


```shell
source devel/setup.bash
```
- Whenever you run `catkin build`, the executables created are put in a different folder, and named different things. 
- We run the `source devel/setup.bash` command in order to tell the computer where the files are located, and what they are called.
- Note: you should run the `source devel/setup.bash` command every time you run the `catkin build` command, otherwise the computer may not be able to find the files!


```shell
roscore
```
- The `roscore` command starts running a ROS server on your computer.
- This server is where all the different ROS nodes can communicate with one another! Whenever you are working on ROS-related code, you will usually want to always have `roscore` running in the background!

### Run the secret message node

- **Open a new terminal for the next step**
    - Use the "file" tab and press *new window* or *new tab* to do this.
    - You wan to keep the `roscore` command running in the other terminal in the background!


```shell
cd ~/ros_tutorial_ws
source devel/setup.bash
roslaunch secret_msg secret_msg.launch
```
- First we navigate to the tutorial folder, and tell the computer where your executable files are (as explained before).
- The `roslaunch` command is used to run the secret_msg node we created for the tutorial. This will happen in your current terminal window, so you will need to open another terminal window/tab to continue.
    - For more details about the `roslaunch` command, feel free to read this information below (optional):
    - `roslaunch` specifically looks for a *.launch file (the second parameter) in the folder (first parameter). The launch file defines which specific parts of the node(s) need to be run, and can include parameters to allow for customization. You can also run multiple different nodes (in different folders) from the same launch file!

<br>

**Open a new terminal tab** and navigate to the "ros_tutorial_ws" folder.
- Make sure to leave the `roscore` and `roslaunch` terminals running in the background

You can now run the following command in the new terminal:
```shell
rosnode list
```
- The output of the `rosnode list` command will display all the current running nodes in your ROS server (running on your computer from the `roscore` command).
- You should see a few nodes running, a few of which may be helpful for you to get into the bank vault.
- ROS Nodes can do many things, but most will be publishers, subscribers, or services.
    - Publisher nodes will continually update and push data to "topics", and anyone can subscribe to their "topics" to read the most up-to-date data from them.
    - Subscribers will subscribe to specific "topics" they are interested in, and will read the data available on there. They are usually configured to do some action whenever new data is pushed to the topic.
    - Services are kind of like functions that are called from many different nodes. They wait until their service function is called (usually with some data passed in, called a message), and execute an action accordingly. Services will usually return some data to the caller when the processing is finished.
    - **Hint**: feel free to play with the `rosnode` functions further to learn more about the nodes you can see: [Rosnode Documentation](http://wiki.ros.org/rosnode)

<br>

<h2>Creating Your Custom Package</h2>

- Working together on this part can definitely be helpful, so feel free to find someone around you, or ask us and we can try to help you find a partner!

<br>

You are now fully set, and it's time for you to code your own nodes!
- Hopefully, you have learned a bit about the structure of ROS at this point as well.
- Feel free to ask anyone in Nav questions if you are confused about anything or want to learn more about a specific topic!

In order to continue forward and get into the bank vault, there are two main steps you will need to take:
- You need to create a custom ROS package to subscribe to data from the secret_msg node 
- You need to use that data to call a service in the vault_key pad node.

You are a bank robber and your goal is to, as one may say, "Get dat bread".

In order to do this, you will use ROS Wiki tutorials to guide you. This is definitely not an easy task, so please do not hesitate to ask us for help!


**Open a new terminal** and run the following commands:
```shell
cd ~/ros_tutorial_ws
source devel/setup.bash
cd ~/ros_tutorial_ws/src
catkin_create_pkg <package_name> roscpp rospy std_msgs std_srvs message_generation
```
- The `catkin_create_pkg` will create a ros package (folder) with the main files you will be writing your code in. 
- These files will be found in the `~/ros_tutorial_ws/src` directory, under a folder called <package_name> (which you specified when running the command).
- `roscpp` `rospy` `std_msgs` etc, these are all ROS dependencies. These are just the ones needed for this tutorial, there are many other possible dependencies, and we will look into this as we develop more complex projects.

```shell
cd ~/ros_tutorial_ws
catkin build
rospack list | grep <package_name>
```
- Calling `catkin build` before you have any code is a good way to check if the package was created correctly.
- When calling `rospack list | grep <package_name>` you should see your package appear.

<br>
Use the links below to learn how to create the subscriber node, and then call the service!

- Hint: use `rosnode list` and `rosnode info <node_name>` to find what topic to subscribe to.

<br>

### [Publisher Tutorial](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29)
- Go to the link above for a ros publisher, and subscriber tutorial.
- Note you created a package called <package_name> (from before) while the tutorial references a package they created called "beginner_tutorials".
- It is important to note: Copying the subscriber directly will not work. It is an example for how a basic subscriber will look, work together to change the example into one that works with the `secret_msg` and `vault_keypad` nodes. 
- **Hint: section 2 of this site will be most useful to you, and use `rosservice list`**

### [Service Client Tutorial](http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29)
- Go to the link above for a ros service and client tutorial. 
- Call the service you found using `rosservice list`.
- If you are struggling you can send “HELP” to the service and it will return a helpful message.
- **Hint: section 2 of this site will be most useful to you**

## Remember, we are here to help you! Make sure to ask us questions about anything you are confused about!
- You can also always send a message in the discord to another Nav member, the #navigation channel, or to the leads if you need any help!
