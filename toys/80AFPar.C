#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define SIZE	1024

typedef struct tagstr{
	char size;
	char buf[1];
}string, * pstring;


int trans_endian(char* buf, int cnt) {
	int i;
	char tmp;
	// 对四位二进制进行大小端逆转的数组
	static char trans_arr[] = {
		0x0, 0x8, 0x4, 0xC,
		0x2, 0xA, 0x6, 0xE,
		0x1, 0x9, 0x5, 0xD,
		0x3, 0xB, 0x7, 0xF
	};

	for (i = 0; i < cnt; i++) {
		tmp = trans_arr[buf[i] & 0x0F] << 4;
		tmp |= trans_arr[(buf[i] & 0xF0) >> 4];
		buf[i] = tmp;
	}
	for (i = 0; i < cnt; i += 2) {
		tmp = buf[i];
		buf[i] = buf[i+1];
		buf[i+1] = tmp;
	}
	return 1;
}

int get_change(void) {
	char buf[64], *nptr;

	printf("\n修改否?(Y/N)");
	fflush(stdin);
	gets(nptr = buf);
	/* skip whitespace */
	while (isspace((int)(unsigned char)*nptr))
        	++nptr;
	return ('Y' == toupper(*nptr));
}

int usage() {
	printf("\n本程序用于修改智能电流的EEPROM数据");
	printf("\n目前仅支持芯片组合为M37516+M61040+80AF的数据资料\n");	
	return 1;
}


int resolve_info(char* buf) {
	char strbuf[64];
	pstring pstr;
	unsigned short * uint16_p;
	unsigned int * uint32_p, tmp;
	int year, month, day;

	uint16_p = (unsigned short * )&buf[0x2c];
	printf("\n01*)  充放电次数(0x2c,0x2d): \t%d 次", *uint16_p);
	if (get_change()) {
		printf("请输入新的充放电次数:");
		scanf("%d", &tmp);
		*uint16_p = (unsigned short)tmp;
		uint16_p = (unsigned short * )&buf[0x200 + 0x2c];
		*uint16_p = (unsigned short)~tmp;
	}

	uint16_p = (unsigned short * )&buf[0x2e];
	printf("\n02*)  满充容量(0x2e,0x2f): \t%d mAh", *uint16_p);
	if (get_change()) {
		printf("请输入新的满充容量:");
		scanf("%d", &tmp);
		*uint16_p = (unsigned short)tmp;
		uint16_p = (unsigned short * )&buf[0x200 + 0x2e];
		*uint16_p = (unsigned short)~tmp;
	}

	uint32_p = (unsigned int * )&buf[0x32];
	printf("\n03 )  芯片标识位(0x32,0x33,0x34,0x35): \t0x%08X", *uint32_p);

	uint16_p = (unsigned short * )&buf[0x1b6];
	printf("\n04*)  设计容量(0x1b6,0x1b7): \t%d mAh", *uint16_p);
	if (get_change()) {
		printf("请输入新的设计容量:");
		scanf("%d", &tmp);
		*uint16_p = (unsigned short)tmp;
		uint16_p = (unsigned short * )&buf[0x200 + 0x1b6];
		*uint16_p = (unsigned short)~tmp;
	}

	uint16_p = (unsigned short * )&buf[0x1bc];
	printf("\n05*)  生产日期(0x1bc,0x1bd): \t%04d 年-%02d 月-%02d 日",
		1980 + (((*uint16_p) >> 9) & 0x7F),
		(((*uint16_p) >> 5) & 0xF),
		((*uint16_p) & 0x1F)
	);
	if (get_change()) {
		printf("请输入新的生产日期\n年:");
		scanf("%d", &year);
		printf("月:");
		scanf("%d", &month);
		printf("日:");
		scanf("%d", &day);

		tmp = ((year - 1980) & 0x7F) << 9;
		tmp |= (month & 0xF) << 5;
		tmp |= (day & 0x1F);

		*uint16_p = (unsigned short)tmp;
		uint16_p = (unsigned short * )&buf[0x200 + 0x1bc];
		*uint16_p = (unsigned short)~tmp;
	}

	pstr = (pstring)&buf[0x1c0];
	strncpy(strbuf, pstr->buf, pstr->size);
	strbuf[pstr->size] = '\0';
	printf("\n06 )  厂商名(0x1c0-0x1c9): \t%s", strbuf);

	pstr = (pstring)&buf[0x1ca];
	strncpy(strbuf, pstr->buf, pstr->size);
	strbuf[pstr->size] = '\0';
	printf("\n07 )  设备名(0x1ca-0x1d5): \t%s", strbuf);

	pstr = (pstring)&buf[0x1da];
	strncpy(strbuf, pstr->buf, pstr->size);
	strbuf[pstr->size] = '\0';
	printf("\n08 )  电芯类型(0x1da-0x1df): \t%s", strbuf);

	uint16_p = (unsigned short * )&buf[0x1f8];
	printf("\n09*)  首次使用日期(0x1f8,0x1f9): \t%04d 年-%02d 月-%02d 日",
		year = 1980 + (((*uint16_p) >> 9) & 0x7F),
		month = (((*uint16_p) >> 5) & 0xF),
		day = ((*uint16_p) & 0x1F)
	);
	if (get_change()) {
		printf("请输入新的首次使用日期\n年:");
		scanf("%d", &year);

		tmp = ((year - 1980) & 0x7F) << 9;
		tmp |= (month & 0xF) << 5;
		tmp |= (day & 0x1F);

		*uint16_p = (unsigned short)tmp;
		uint16_p = (unsigned short * )&buf[0x200 + 0x1f8];
		*uint16_p = (unsigned short)~tmp;
	}

	uint16_p = (unsigned short * )&buf[0x1fa];
	printf("\n10*)  报警锁定(0x1fa,0x1fb): \t0x%04X", *uint16_p);
	if (get_change()) {
		printf("默认置0\n");
		tmp = 0;
		*uint16_p = (unsigned short)tmp;
		uint16_p = (unsigned short * )&buf[0x200 + 0x1fa];
		*uint16_p = (unsigned short)~tmp;
	}

	return 1;
}

int main(int argc, char* argv[]){
	char* p, buf[SIZE+1], fname[MAX_PATH];
	int c, i, count;
	FILE *fpr, *fpw;

	usage();

	if(argc < 2){
		printf("Usage:%s <filename>\n", argv[0]);
		exit(1);
	}
	if((fpr = fopen(argv[1], "rb")) == NULL){
		printf("Can't open file: %s\n", argv[1]);
		exit(2);
	}

	p = argv[1];
	while (NULL != (p = (strchr(p, '.')))) {
		*p++ = '_';
	}
	strcpy(fname, argv[1]);
	strcat(fname, ".bin");

	if((fpw = fopen(fname, "wb")) == NULL){
		printf("Can't open file to write: %s\n", fname);
		exit(2);
	}

	count = 0;
	c = fgetc(fpr);
	while(!feof(fpr)){
		buf[count++] = c;
		c = fgetc(fpr);
		if (feof(fpr) || count >= SIZE)
			break;
	}

	trans_endian(buf, count);

	resolve_info(buf);

	trans_endian(buf, count);

	fwrite(buf, 1, count, fpw);
	fclose(fpr);
	fclose(fpw);
	printf("\n修收后的数据文件为: %s\n\n", fname);
	system("pause press any key to continue\n");
	return 0;
}
