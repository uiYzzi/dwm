/* See LICENSE file for copyright and license details. */
/* 有关版权和许可证的详细信息，请参阅许可证文件。 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

/*
	die函数用于在程序发生错误时显示错误消息，并退出程序。它接受一个格式化字符串作为参数，
	并使用可变参数列表来格式化输出。如果格式字符串以冒号结尾，则会显示系统错误消息，否则会显示换行符。
	最后，它会调用exit函数以退出程序。
*/
void
die(const char *fmt, ...)
{
	// 关于可变参数的解释可看 https://www.runoob.com/cprogramming/c-macro-va_start.html
	// VA_LIST 是在C语言中解决变参问题的一组宏，所在头文件：#include <stdarg.h>，用于获取不确定个数的参数。
	va_list ap;

	// void va_start(va_list ap, last_arg) 初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。
	// 初始化可变参数列表
	va_start(ap, fmt);

	// 将可变参数列表作为格式化字符串输出到stderr
	vfprintf(stderr, fmt, ap);

	// 结束可变参数列表
	va_end(ap);

	// 如果格式化字符串以冒号结尾，则输出一个错误消息
	if (fmt[0] && fmt[strlen(fmt)-1] == ':') {
		fputc(' ', stderr);
		perror(NULL);
	} else {
		// 否则输出一个换行符
		fputc('\n', stderr);
	}

	// 以退出状态1终止程序
	exit(1);
}

/* 
	这个函数的作用是申请一块内存，并将其初始化为零。如果申请失败，则会调用die函数终止程序
*/
void *
ecalloc(size_t nmemb, size_t size)
{
	// 声明一个指针变量
	void *p;

	// 调用calloc函数申请一块内存
	if (!(p = calloc(nmemb, size)))
		// 如果申请失败，则调用die函数终止程序
		die("calloc:");
		
	// 返回申请的内存指针
	return p;
}
