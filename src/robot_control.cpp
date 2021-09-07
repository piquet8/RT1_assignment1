#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include <math.h>
#include "assignment_1/Rand_targ.h"

ros::Publisher pub;
ros::Subscriber sub;
ros::ServiceClient client;
double t_x=0, t_y=0;

void posCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
   float dist = sqrt (pow((msg->pose.pose.position.x - t_x), 2)+pow((msg->pose.pose.position.y - t_y), 2));

   if (dist < 0.1)
    {
	assignment_1::Rand_targ targ; 
	client.call(targ); 
    	t_x = targ.response.x;  
    	t_y = targ.response.y;  
    	ROS_INFO("\nRobot reached the target! \nNew Target: [%f, %f]", t_x, t_y);
    }
   geometry_msgs::Twist vel;
   vel.linear.x=2.0*(t_x-msg->pose.pose.position.x);
   vel.linear.y=2.0*(t_y-msg->pose.pose.position.y);
   pub.publish(vel);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "robot_control");
  ros::NodeHandle n;
  
  client = n.serviceClient<assignment_1::Rand_targ>("/Rand_targ");
  pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  sub = n.subscribe("/odom", 1000, posCallback);

  ros::spin();
  return 0;
}
