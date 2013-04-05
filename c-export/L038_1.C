#define N 50

main(){
	int p, *q;
	char *r;

	/*注意,这里只有一个乘号,因为sizeof把q指向的东西(*q)作为操作数
	*与sizeof操作优先级相同,但右结合.
	sizeof的操作数是类型必须加(),如果是变量则不必
	(因为这个常使人认为其是函数)*/
	p = N * sizeof * q;
	r = (char *)malloc(p);
	gets(r);
	printf("You inputed--->%s\n", r);

	/*而下面这个语句究竟是强制转换*q,还是先求sizeof(int)呢?
	很是不幸,在多数的编译器中,它不能通过
	因为正如下面我加我括号,sizeof(int)会首先计算*/
	*q = 10;
	p = (sizeof(int)) * q;
	printf("(sizeof(int) * q) = %d", p);
}