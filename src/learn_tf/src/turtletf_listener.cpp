//
// Created by yinlei on 2020/5/28.
//

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "learn_tf_turtletf_listener");
    ros::NodeHandle handle;
    ros::service::waitForService("spawn");
    ros::ServiceClient add_turtle = handle.serviceClient<turtlesim::Spawn>("spawn");

    turtlesim::Spawn srv;
    add_turtle.call(srv);

    ros::Publisher turtle_vel = handle.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

    tf::TransformListener listener;

    ros::Rate rate(10.0);
    while (handle.ok()) {
        tf::StampedTransform transform;
        try {
            // 查找两只乌龟之间的坐标变换
            listener.waitForTransform("/turtle2", "/turtle1", ros::Time(0), ros::Duration(3.0));
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
        } catch (tf::TransformException & exception) {
            ROS_ERROR("%s", exception.what());
            ros::Duration(1).sleep();
            continue;
        }

        // 根据turtle1和turtle2之间的坐标变换，计算turtle2需要运动的线速度和角速度
        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                        transform.getOrigin().x());
        vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                      pow(transform.getOrigin().y(), 2));
        // 发布速度控制指令，让turtle2向turtle1移动
        turtle_vel.publish(vel_msg);

        rate.sleep();
    }

    return 0;
}

