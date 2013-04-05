main(void){
	char *cp;
	const *ccp;
	/*Suspicious pointer conversion in function main*/
	ccp = cp;
	/*Suspicious pointer conversion in function main
	if ANSI C,don't allow this statement
	左边指针指向类型要有右边类型的所有限定符*/
	cp = ccp;
	return 0;
}