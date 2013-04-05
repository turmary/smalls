#include <limits.h>
#include <stdio.h>

/*并不严格遵循标准:
其输出结果是由编译器定义的*/

int main(){
	(void)printf("biggest int is %d\n", INT_MAX);
	return 0;
}