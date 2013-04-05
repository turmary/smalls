#include <stdio.h>

/*输入^Z,将是0
否则是-1*/
main(){
	printf("getchar()!=EOF = %d\n", getchar() != EOF);
}