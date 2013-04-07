#include <stdio.h>

main(int argc, char* argv[]){
	char letter[17];
	int c, i, count;
	FILE* fp;
	if(argc < 2){
		printf("Usage:mtype <filename>\n");
		exit(1);
	}
	if((fp = fopen(argv[1], "rb")) == NULL){
		printf("Can't open file: %s\n", argv[1]);
		exit(2);
	}
	count = 0;
	do{
		i = 0;
		printf("%08X:", count * 16);
		c = fgetc(fp);
		while(!feof(fp)){
			printf(" %02X", c);
			if(c < ' ' || c > 0x7e)
				letter[i] = '.';
			else
				letter[i] = c;
			if(++i == 16)
				break;
			c = fgetc(fp);
		}
		letter[i] = '\0';
		if(i != 16)
			for(; i < 16; i++)
				printf("%3s", " ");
		printf(" %s\n", letter);
		count++;
		if(count % 10 == 0){
			printf("Press a key to continue...\n");
			getch();
		}
	}while(!feof(fp));
	fclose(fp);
}
