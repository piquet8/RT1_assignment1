# Research Track 1 - first assignment
The assignment requires controlling a holonomix robot in a 2d space with a simple 2d simulator, Stage. The simulator can be launched by executing the command:
```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world
```
## Expected Behaviour
1. The robot asks for a ranom target, with both coordinates in the interval (-6.0, 6.0)
2. The robot reaches the target
3. Go to the step 1
# Project structure
I have created a new ROS package in which I have developed **two nodes** which we find in the src folder and **one service files** which we find in the srv folder. The nodes were implemented using the **C++ programming language**  
## First node
The first node is: [robot_control.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/robot_control.cpp). This node implements:
* A ROS publisher
* A ROS subscriber
* A ROS client
## Second node
The second node is: [rand_targ.cpp](https://github.com/piquet8/RT1_assignment1/blob/main/src/rand_targ.cpp). This node implements a random generator of two numbers between -6.0 and 6.0

