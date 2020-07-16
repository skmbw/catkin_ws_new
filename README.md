# sudo rosdep init & rosdep update，因为网络问题，无法执行的问题
* sudo rosdep init 这个命令是下载 20-default.list这个文件，放入 /etc/ros/rosdep/sources.list.d 这个目录
那么我们可以，手动下载后放入这个目录，就可以跳过这一步
* rosdep update才是真正的更新，可以修改20-default.list中无法下载的http url地址，使用本地的nginx代理
* nginx的配置文件在/etc/nginx中
* nginx的日志文件在/var/log/nginx中
* nginx的html文件在/usr/share/nginx/html中。或者 /var/www/html中
* nginx的可执行文件在/usr/sbin/nginx
* ./nginx -c /etc/nginx/nginx.conf 启动，可以指定配置文件 ./nginx -s stop 快速关闭 ./nginx -s reload 重启 ./nginx -s quit 正常停止关闭

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
* 也可以使用 rosrun package_name executable_file，例如 rosrun learn_comm talker.py
* 对于C++的运行，可以使用rosrun命令，rosrun learn_comm talker，talker是在CMakeLists.txt中配置的可执行文件名
* debug模式，需要在debug的configuration中配置main函数的参数，默认情况下这两个参数可以不用传。可以直接右键run/debug启动程序

# clion中ROS c++开发配置
* c++源文件，要在CMakeLists.txt里面配置，否则不属于任何项目，将无法代码提示，也没法编译

# ROS的样例的调试
* ros自带的tf变换例子，不能是debug启动的。要roslaunch运行。其实可以启动，配置好main的参数就行了
* 第二，roslaunch所在的命令行窗口要获取焦点，否则方向键不起作用

# vi删除全部
* 在命令行模式下，（也就是用vi打开文件后）输入gg进入到第1行
* 按下d，然后输入G回车，此时内容被全部清除
* 现在可以按i进入编辑模式了