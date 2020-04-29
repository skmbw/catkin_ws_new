// 要在CMakeLists.txt里面配置，否则不属于任何项目，将无法代码提示，也没法编译
// Created by yinlei on 2020/4/17.
//

#include "ros/ros.h"
#include "learn_comm/AddTwoInts.h"

bool add(learn_comm::AddTwoInts::Request &req, learn_comm::AddTwoInts::Response &rsp)
{
    rsp.sum = req.a + req.b;
    ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)rsp.sum);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_server"); // 初始化节点，节点名
    ros::NodeHandle handle; // 初始化，不需要使用new

    // 发布服务
    ros::ServiceServer serviceServer = handle.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();

    return 0;
}
