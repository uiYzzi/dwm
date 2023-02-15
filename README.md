# dwm
本仓库是对DWM源码的分析学习
以下是Dwm的原版README和其对应的中文翻译

# dwm - dynamic window manager
# dwm - 动态窗口管理器
============================
dwm is an extremely fast, small, and dynamic window manager for X.
Dwm 是用于 X 的一个非常快速、小型和动态的窗口管理器。


# Requirements
# 规定
------------
In order to build dwm you need the Xlib header files.
为了构建 dwm，需要 Xlib 头文件。


# Installation
# 安装
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).
编辑 config.mk 以匹配本地设置(默认情况下，dwm 安装在/usr/local 名称空间中)。

Afterwards enter the following command to build and install dwm (if
necessary as root):
然后输入以下命令来构建和安装 dwm (可能需要 root 用户) :


    make clean install


# Running dwm
# 运行dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:
在.xinitrc 中添加以下代码行，使用 startx 启动 dwm:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:
为了将 dwm 连接到一个特定的显示器，确保 disdisplay 环境变量设置正确，例如:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)
(这将在一个主机 foo.bar 的 display :1 上启动 dwm。)

In order to display status info in the bar, you can do something
like this in your .xinitrc:
为了在工具条中显示状态信息，您可以在. xinitrc 中执行以下操作:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


# Configuration
# 配置
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
Dwm 的配置是通过创建一个自定义 config.h 和(重新)编译源代码来完成的。