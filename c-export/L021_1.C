int main(){
	const int limit = 10;
	const int * limitp = &limit;

	/*这里limitp不能修改他指向的值
	但其本身的值却可以变化*/
	int i = 27;
        printf("first *p=%d\n", *limitp);
	limitp = &i;
	printf("second *p=%d\n", *limitp);
	return 0;
}