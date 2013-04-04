#include <stdio.h>
#include <limits.h>

#define _STR(s) #s
#define STR(s) _STR(s) // 转换宏

int main() {
	printf("STR int max: %s \n", STR(INT_MAX));
	printf("_STR int max: %s \n", _STR(INT_MAX));
	return 0;
}
