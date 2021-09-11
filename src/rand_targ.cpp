#include "ros/ros.h"
#include "assignment_1/Rand_targ.h"

double rand(double M, double N)
{ return M + (rand() / ( RAND_MAX / (N-M) ) ) ; }


bool myrandom(assignment_1::Rand_targ::Request &req, assignment_1::Rand_targ::Response&res){ 

  res.x = rand(-6.0, 6.0);
  res.y = rand(-6.0, 6.0);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Rand_targ");
  ros::NodeHandle n;
  ros::ServiceServer service= n.advertiseService("/Rand_targ", myrandom);
  ros::spin();
  
  return 0;
}
