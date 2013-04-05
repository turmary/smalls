main(){
	if(-1 < (unsigned char)1)
		printf("-1 is less than (unsigned char)1:ANSI semantics");
	else
		printf("-1 is NOT less than (unsigned char)1: K&R semantics");
}