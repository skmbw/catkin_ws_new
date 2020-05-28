//
// Created by yinlei on 2020/5/28.
//
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

std::string turtle_name; // 全局空字符串？

void poseCallback(const turtlesim::PoseConstPtr & msg) {
    static tf::TransformBroadcaster broadcaster;

    tf::Transform transform;
    transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0)); // 平移变换
    tf::Quaternion quaternion;
    quaternion.setRPY(0, 0, msg->theta);
    transform.setRotation(quaternion); // 旋转变换

    broadcaster.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "learn_tf_turtletf_broadcaster");
    if (argc != 2) {
        ROS_ERROR("need turtle name as a argument.");
        return -1;
    }

    turtle_name = argv[1]; // argv[0]是当前文件的名字

    ros::NodeHandle handle;
    ros::Subscriber subscriber = handle.subscribe(turtle_name + "/pose", 10, &poseCallback);

    ros::spin();
    return 0;
}
