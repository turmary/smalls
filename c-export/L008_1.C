main(){
	int b, value, open;
	float epsilon;

	b=10;
	b=-3;
	printf("b=%d\n", b);
	/*注意,复合赋值符来自于=*形式,
	但是这容易形成问题如=-
	现在的编译器再也不使用(兼容)这种旧格式了,
	所有我没有这么好的运气可以看见上面的错误
	*/
	epsilon=.0001;
	/*epsilon.=0001;
	*/open = 10;
	value=!open;
	value!=open;
	printf("Epsilon=%f\n", epsilon);
	printf("open=%d value=%d\n", open, value);
}