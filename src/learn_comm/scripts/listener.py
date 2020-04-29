#!/usr/bin/env python
# coding=utf-8
import rospy
from std_msgs.msg import String


def callback(str_data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s.", str_data.data)


def listener():
    # 节点名必须是唯一的. I如果两个节点名字相同，前一个会被踢掉
    # anonymous=True 允许同时有多个listener
    rospy.init_node("listener", anonymous=True)
    rospy.Subscriber("chatter", String, callback)
    rospy.spin()


if __name__ == '__main__':
    listener()
