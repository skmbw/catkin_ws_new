//
// Created by yinlei on 2020/4/17.
//

#include "ros/ros.h"
#include "learn_comm/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_client"); // 初始化节点，节点名
    if (argc != 3)
    {
        ROS_INFO("USAGE: add_client X Y");
        return 1;
    }
    ros::NodeHandle handle;
    // 获取服务客户端代理
    ros::ServiceClient client = handle.serviceClient<learn_comm::AddTwoInts>("add_two_ints");
    learn_comm::AddTwoInts srv;
    srv.request.a = std::strtoll(argv[1], nullptr, 10);
    srv.request.b = atoll(argv[2]);
    if (client.call(srv))
    {
        ROS_INFO("SUM: %ld", (long int)srv.response.sum);
    }
    else
    {
        ROS_INFO("Failed to call service add_two_ints");
        return 1;
    }
    return 0;
}