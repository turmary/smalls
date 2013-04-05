/*Only Used K&R C*/
#define ISUNSIGNED1(v) (v >= 0 && ~v >= 0)
/*Used ANSI C*/
#define ISUNSIGNED2(type) ((type)0 - 1 > 0)

main(){
	int a;
	unsigned b;
	char c;

	clrscr();
	printf("a=%d %d\n", ISUNSIGNED1(a), ISUNSIGNED2(signed int));
	printf("b=%d %d\n", ISUNSIGNED1(b), ISUNSIGNED2(unsigned));
	printf("c=%d %d\n", ISUNSIGNED1(c), ISUNSIGNED2(unsigned long));
	return 0;
}