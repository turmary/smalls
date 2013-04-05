#define STRING char *
#define IF if(
#define THEN ){
#define ELSE }else{
#define FI ;}
#define WHILE while(
#define DO ){
#define OD ;}
#define INT int
#define BEGIN {
#define END }

INT compare(s1, s2)
	STRING s1;
	STRING s2;
BEGIN
	WHILE *s1++ == *s2
	DO	IF *s2++ == 0
		THEN return(0);
		FI
	OD
		return(*--s1 - *s2);
END

INT main()
BEGIN
	printf("\n%s\n", compare("HELLo World!",
	 "HELLo WorlD!")? "differ": "same");
END

/*
cpp executed:
int compare(s1, s)
	char * s1;
	char * s;
{
	while( *s1++ == *s){
		if( *s++ == 0){
			return(0);
		;}
	;}
	return(*--s1 - *s);
}

int main()
{
	printf("\n%s\n", compare("HELLo World!",
	 "HELLo WorlD!")? "differ": "same");
}
*/