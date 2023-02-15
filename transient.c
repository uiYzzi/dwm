/* cc transient.c -o transient -lX11 */

#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

/*
	这个函数的作用是创建一个浮动窗口，并在5秒后创建一个透明窗口，并将其设置为浮动窗口的子窗口。
*/
int main(void) {

	// 声明一个Display指针，用于连接X服务器
	Display *d;

	// 声明三个Window变量，用于存储窗口的ID
	// r是默认根窗口，f是后面创建的浮动窗口
	Window r, f, t = None;

	// 声明一个XSizeHints结构体，用于设置窗口的大小
	XSizeHints h;

	// 声明一个XEvent结构体，用于存储X事件
	XEvent e;

	// XOpenDisplay函数用于连接X服务器，NULL参数表示使用默认的X服务器连接。
	d = XOpenDisplay(NULL);

	// 如果连接失败，则退出程序
	if (!d)
		exit(1);
	
	// DefaultRootWindow函数用于获取默认根窗口，d参数表示X服务器连接，返回值表示根窗口的ID。
	// 获取默认根窗口
	r = DefaultRootWindow(d);

	// XCreateSimpleWindow函数用于创建一个简单的窗口
	// d参数表示X服务器连接，r参数表示父窗口的ID，100，100表示窗口的位置，400，400表示窗口的大小，0，0表示窗口的边框宽度和颜色，返回值表示窗口的ID。
	// 创建浮动窗口
	f = XCreateSimpleWindow(d, r, 100, 100, 400, 400, 0, 0, 0);

	// 设置窗口的最小和最大大小
	h.min_width = h.max_width = h.min_height = h.max_height = 400;

	// PMinSize和PMaxSize标志用于设置窗口的最小和最大尺寸，这样可以限制窗口的大小，以免窗口过大或过小。
	h.flags = PMinSize | PMaxSize;

	// XSetWMNormalHints函数用于设置窗口的普通提示，d参数表示X服务器连接，f参数表示窗口的ID，h参数表示窗口的普通提示，这样可以限制窗口的大小。
	// 设置窗口的大小
	XSetWMNormalHints(d, f, &h);

	// XStoreName函数用于设置窗口的名称，d参数表示X服务器连接，f参数表示窗口的ID，"floating"参数表示窗口的名称，这样可以让窗口更容易被识别。
	// 设置窗口的标题
	XStoreName(d, f, "floating");

	// XMapWindow函数用于显示窗口，d参数表示X服务器连接，f参数表示窗口的ID，这样可以让窗口可见。
	// 显示窗口
	XMapWindow(d, f);

	// XSelectInput函数用于设置窗口的事件监听，ExposureMask参数表示监听窗口重绘事件，当窗口重绘时，XNextEvent函数会返回一个Exposure事件。
	// 设置窗口的事件监听
	XSelectInput(d, f, ExposureMask);

	// 死循环，用于保证透明窗口存在
	while (1) {

		// 获取下一个事件
		XNextEvent(d, &e);

		if (t == None) {

			// 等待5秒
			sleep(5);

			// d参数表示X服务器连接，r参数表示父窗口的ID，50，50表示窗口的位置，100，100表示窗口的大小，0，0，0表示窗口的边框宽度和颜色，这样可以创建一个简单的窗口。
			// 创建透明窗口
			t = XCreateSimpleWindow(d, r, 50, 50, 100, 100, 0, 0, 0);

			// XSetTransientForHint函数用于设置窗口的暂时性提示，d参数表示X服务器连接，t参数表示窗口的ID，f参数表示父窗口的ID，这样可以让窗口暂时显示在父窗口之上。
			// 设置透明窗口的父窗口
			XSetTransientForHint(d, t, f);

			// 设置透明窗口的标题
			XStoreName(d, t, "transient");

			// 显示透明窗口
			XMapWindow(d, t);

			// 设置透明窗口的事件监听
			XSelectInput(d, t, ExposureMask);
		}
	}

	// 关闭X服务器连接
	XCloseDisplay(d);

	// 退出程序
	exit(0);
}
