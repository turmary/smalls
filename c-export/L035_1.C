
generate_initializer(char * string){
	static char separator = ' ';
	printf("%c %s\n", separator, string);
	separator = ',';
}

main(void){
	int i;
	for(i = 0; i < 10; i++)
		generate_initializer("Hello World!");
}
