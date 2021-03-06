#ifndef SAFETY_BRAKE_H
#define SAFETY_BRAKE_H

#include <iostream>
#include <ros/ros.h>

#include <std_msgs/Bool.h>
#include <cmath>
#include <typeinfo>

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>


class SafetyBrake
{
    public:
        SafetyBrake(ros::NodeHandle nh, ros::NodeHandle private_nh);

    private:
        void updateCartesianPoints(const sensor_msgs::LaserScan::ConstPtr& laserscan);
        void checkIfSafe(const geometry_msgs::Twist::ConstPtr& cmd_vel);

        // ROS variables
        ros::NodeHandle nh_;
        ros::NodeHandle private_nh_;
        ros::Subscriber sub_SafeCheck_;
        ros::Subscriber sub_Laserscan_;
        ros::Publisher pub_cmd_vel_;
        ros::Publisher pub_status_;

        // Parameters
        int number_of_points;
        std_msgs::Bool status;
        float min_width, min_length;
        geometry_msgs::Twist cmd_vel_safety_break;

        struct point
        {
            double x;
            double y;
            double angle;
        };

        std::vector<point> data;
        
    

       
};


#endif