/* See LICENSE file for copyright and license details. */
/* 有关版权和许可证的详细信息，请参阅许可证文件。 */

/* 本头文件定义了几个“工具函数”，是为了方便在整个程序各处被调用 */

// 宏函数，用于比较两个量哪个更大，函数将返回更大的那个值
#define MAX(A, B)               ((A) > (B) ? (A) : (B))

// 宏函数，用于比较两个量哪个更小，函数将返回更小的那个值
#define MIN(A, B)               ((A) < (B) ? (A) : (B))

// 宏函数，用于检查一个值X是否在两个值A和B之间。如果X在A和B之间，则函数返回true，否则返回false
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))


void die(const char *fmt, ...);
void *ecalloc(size_t nmemb, size_t size);
