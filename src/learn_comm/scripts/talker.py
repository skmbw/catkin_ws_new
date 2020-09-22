#!/usr/bin/env python
# coding=utf-8
import rospy
from std_msgs.msg import String


def talker():
    # topic 的名字叫 chatter，订阅者要订阅这个名字
    pub = rospy.Publisher("/chatter", String, queue_size=5)
    rospy.init_node("talker2")  # 节点的名字叫 talker，不要让节点名字重复，否则会有延迟
    rate = rospy.Rate(5)
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()


if __name__ == "__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass




