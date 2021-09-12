# Research Track 1 - first assignment
The assignment requires controlling a holonomix robot in a 2d space with a simple 2d simulator, Stage. The simulator can be launched by executing the command:
## Expected Behaviour
1. The robot asks for a random target, with both coordinates in the interval (-6.0, 6.0)
2. The robot reaches the target
3. Go to the step 1
# Project structure
I have created a new ROS package in which I have developed **two nodes** which we find in the src folder and **one service file** which we find in the srv folder. The nodes are implemented using the **C++ programming language**  
## First node
The first node is: [robot_control.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/robot_control.cpp). This node implements:
* A ROS publisher
* A ROS subscriber
* A ROS client
## Second node
The second node is the service node: [rand_targ.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/rand_targ.cpp). This node implements a random generator of two numbers between -6.0 and 6.0
## Service file
The service file is: [Rand_targ.srv](https://github.com/piquet8/RT1_assignment1/blob/main/srv/Rand_targ.srv). It is composed by a void request and response with two float x and y
## Rqt-graph
By running the following command:
```
rosrun rqt_graph rqt_graph
```
we can see a dynamic graph that shows what’s going on in the system:

![Rqt-graph](https://github.com/piquet8/RT1_assignment1/blob/main/rqt_graph.png)
# How to launch
1. Firstly, open the terminal, go to your workspace and in the src folder run:
```
git clone https://github.com/piquet8/assignment_1.git
```
2. Now, start the master by running:
```
roscore &
```
3. Then to launch the simulation environment open a new shell tab and run the command
```
rosrun stage_ros stageros $(rospack find assignment_1)/world/exercise.world
```
4. Now we start the service node that will produce the new random coordinates, open another shell tab and digit:
```
rosrun assignment_1 rand_targ
```
5. To launch the main node, open another shell tab and digit:
```
rosrun assignment_1 robot_control
```
# Report of the assignment
## Robot behaviors
The behaviour of the robot is very simple and minimal, it is located inside a square 'arena' of side 12 (-6,6) and every time it reaches the target position it communicates it to the user and then immediately leaves to reach the new target position chosen randomly inside the square
## Software architecture and the architectural choices made
The architecture of this project is very simple and is mainly based on communication via service between the main node [robot_control.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/robot_control.cpp) and the server node [rand_targ.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/rand_targ.cpp). The main node uses a **publisher** to modify its speed through the message `geometry_msgs/Twist` and a **subscriber** through which it receives the current position of the robot through the message `nav_msgs/Odometry`, which it uses to verify the distance to the target position. Finally it uses a **service** to obtain the target position, the service file [Rand_targ.srv](https://github.com/piquet8/RT1_assignment1/blob/main/srv/Rand_targ.srv) has an empty field for the request and two float fields for the x and y values as response, these fields are filled by the relative server [rand_targ.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/rand_targ.cpp). This node has two simple functions: a function `rand` which computes the random number and a function `myrandom` which is the actual service callback that sends the values to the service file [Rand_targ.srv](https://github.com/piquet8/RT1_assignment1/blob/main/srv/Rand_targ.srv) which allows the request/reply interaction




