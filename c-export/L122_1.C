/*该程序可以发现系统中堆栈的大致位置*/

#include <stdio.h>

main(){
	int i;

	printf("The stack top is near %p\n", &i);
	return 0;
}