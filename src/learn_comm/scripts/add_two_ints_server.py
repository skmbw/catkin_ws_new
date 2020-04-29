#!/usr/bin/env python
# coding=utf-8

from learn_comm.srv import AddTwoInts, AddTwoIntsResponse
import rospy


def handle_add_two(req):
    print "Returning [%s + %s = %s]" % (req.a, req.b, (req.a + req.b))
    return AddTwoIntsResponse(req.a + req.b)


def add_two_server():
    rospy.init_node("add_two_ints_server")  # 节点的名字
    s = rospy.Service("add_two_ints", AddTwoInts, handle_add_two)
    print "Ready to add two ints."
    rospy.spin()


if __name__ == "__main__":
    add_two_server()
