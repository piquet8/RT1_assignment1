#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include <math.h>
#include "assignment_1/Rand_targ.h"
#include "assignment_1/target.h"

ros::Publisher pub1;
ros::Publisher pub2;
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
    	
    	assignment_1::target t_msg; 
    	t_msg.name = "target:";
    	t_msg.targx = t_x;
    	t_msg.targy = t_y;
    	pub2.publish(t_msg);   
    	ROS_INFO("Robot reached the target! \n New Target: [%f, %f]", t_x, t_y);
    }
   geometry_msgs::Twist vel;
   vel.linear.x=2.0*(t_x-msg->pose.pose.position.x);
   vel.linear.y=2.0*(t_y-msg->pose.pose.position.y);
   pub1.publish(vel);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "robot_control");
  ros::NodeHandle n;
  
  client = n.serviceClient<assignment_1::Rand_targ>("/Rand_targ");
  pub1 = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  pub2 = n.advertise<assignment_1::target>("/Target", 1000);
  sub = n.subscribe("/odom", 1000, posCallback);

  ros::spin();
  return 0;
}
