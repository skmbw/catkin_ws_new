### /usr/bin/env: "python\r": 没有那个文件或目录
* 不同平台，换行符导致的
* 不要直接复制文件，新建一个文件，然后通过gedit文本文件复制过来，就好了

### rosbridge协议文档和api参考文档
* [ROSBRIDGE_PROTOCOL](https://github.com/RobotWebTools/rosbridge_suite/blob/develop/ROSBRIDGE_PROTOCOL.md)
* [ROSBRIDGE_API_REFERENCE_PDF](https://roslibpy.readthedocs.io/_/downloads/en/latest/pdf/)
* [ROSBRIDGE_API_REFERENCE_HTML](https://roslibpy.readthedocs.io/en/latest/reference/index.html)

### ROS节点名字的问题
* 即使发送相同的消息，多个节点的节点名字不能重复，因为是长连接，如果断掉重连，第二次会很慢。
* 启动rospy.Publisher，发送消息时，就是节点名字不要重复。rospy.init_node('node_name_221')