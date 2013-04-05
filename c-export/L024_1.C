int array[] = {23, 34, 12, 17, 204, 99, 16};
#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))

main(){
	int d = -1, x = 0;

	/*本来程序中d的值为-1,比较条件应该为真,但在ANSI编译器
	(比如Cygwin Gcc)中,却为假
	因为sizeof()返回无符号数,d被升级为unsigned int*/
	if(d <=TOTAL_ELEMENTS - 2){
	/*if((unsigned int)d <=TOTAL_ELEMENTS - 2){*/
		x = array[d+1];
	}
	printf("x(0) = %d", x);
}