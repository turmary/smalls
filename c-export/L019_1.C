/*我的TC2.0不是ANSI C编译器,所以没有下面的警告信息
warning: argument is incompatible with prototype

In cygwin Gcc --->
In function `main':
warning: passing arg 1 of `foo' from incompatible
 pointer type
*/
foo(const char **p){
	printf("%s\n", *p);
}

main(int argc, char ** argv){
	foo(argv);
}