#include<ros/ros.h>
#include<std_msgs/Float64.h>

std_msgs::Float64 g_velocity;
std_msgs::Float64 g_vel_cmd;
std_msgs::Float64 g_force;

void myCallbackVelocity(const std_msgs::Float64& message_holder)