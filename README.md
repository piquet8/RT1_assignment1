# Research Track 1 - first assignment
The assignment requires controlling a holonomix robot in a 2d space with a simple 2d simulator, Stage. The simulator can be launched by executing the command:
## Expected Behaviour
1. The robot asks for a ranom target, with both coordinates in the interval (-6.0, 6.0)
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
1. Firstly, in your workspace, open the terminal and run:
```
git clone https://github.com/piquet8/assignment_1.git/
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
rosrun assignment_1 rand_targ.cpp
```
5. To launch the main node, open another shell tab and digit:
```
rosrun assignment_1 robot_control.cpp
```
The robot should appear in the simulation environment and once it reaches a target, it should move toward another direction, looking for the next one.





