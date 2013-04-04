/******************************************************************************
* File Name          : auxlib.c
* Author             : tary
* Date               : 2:01 2012/4/4
* Version            : 0.5
* Description        : common used functions
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "aux_lib.h"

int debug_buf(const char* head, unsigned char* buf, int len) {
	int i;

	printf("\r\nDBG:%s[%d] = \r\n\t", head, len);
	for (i = 0; i < len; i++) {
		printf("%.2X ", buf[i]);
	}
	printf("\r\n");
	return len;
}

int debug_line(const char* file, int lin, int nr, ...) {
	int val = 0;
	const char* s;
	va_list ap;

	printf("\r\nDBG:%s() L%d\t", file, lin);
	
	va_start(ap, nr);
	while (nr-- > 0) {
		s = va_arg(ap, char*);
		if (nr-- <= 0) {
			printf(s);
			break;
		}
		val = va_arg(ap, int);
		if (strchr(s, '%') == NULL) {
			printf("%s=%d", s, val);
		} else {
			printf(s, val);
		}
	}
 	va_end(ap);
	printf("\r\n");

	return nr;
}

/************************************END OF FILE******************************/
