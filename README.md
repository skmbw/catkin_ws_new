# rossrv show learn_comm/AddTwoInts 显示所有的srv信息
* 是因为没有 source devel/setup.bash，估计是编译后要source
* rosmsg show learn_comm/Num 也是同样的道理
* http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv，显示不一样就是这个原因
# ubuntu下关于clion从2019升级到2020的问题
* jetbrains安装的快捷方式在~/.local/share/applications下
* 2020以后，jetbrains的配置默认配置文件发生了变化，在.local .cache .config中都存在
# clion启动要加载ros的环境变量，否则找不到catkin
* 两种方法：一是，在同一个shell中启动，先source ～/catkin_ws/devel/setup.bash, 然后使用sh/bash 命令启动clion.sh
* 第二个是，在.local/share/applications/jetbrains-clion.desktop 中的exec 前添加，bash -i -c 命令，但是要重启系统。我更改了以后
没有重启，导致不生效。
# 使用clion调试python
* yaml么有安装，可以下载下来，手动安装
# C++的例子可以运行，python2的不行，ImportError: No module named rospkg
* 在命令行中，输入 python，然后import rospkg 是可以运行的，说明系统安装的python2是对的，是有rospkg。那就是venv下的那个python有问题了，
使用系统的 python interceptor
* 系统自带的库的路径 /usr/lib/python2.7/dist-packages/ 自己安装的 site-packages
* 或者是 /usr/local/lib/python2.7/dist-packages/
* https://blog.csdn.net/cc1949/article/details/78286224
# pycharm.desktop 如果添加了 bash -i -c
* 只能启动一次，第二次会被阻塞，java进程没有起来
* 需要将Terminal设为true，每次都带terminal，才能多次启动，-i参数就是强制是交互式模式，也就是要在终端中启动
# python的命名规范是PEP8
* 主要的规则就是，类名使用首字母大写的驼峰命名法，变量和函数使用小写的下划线命名法
# python文件无法运行的问题
* 是权限问题，至少要给+x的权限，或者a+x，或者755，777没必要

# ros模块的运行
* 可以直接在python文件中debug运行，右键运行
* 也可以使用 rosrun package_name executable_file，例如 rosrun learn_comm talker
* 对于C++的运行，可以使用rosrun命令，debug模式，需要在debug的configuration中配置main函数的参数