#include <stdio.h>
#include <string.h>

#ifndef METHOD
#define METHOD	4
#endif

unsigned short do_crc(unsigned short, unsigned char *, unsigned int);

unsigned short do_crc(unsigned short init, unsigned char *message, unsigned int len)
#if METHOD == 0
{
	int i, j, sig_1;
	unsigned short crc_reg = init;

	crc_reg = (message[0] << 8) + message[1];
	for (i = 0; i < len; i++) {
		for (j = 0; j < 8; j++) {
			sig_1 = (short) crc_reg < 0;
			crc_reg <<= 1;
			crc_reg |= ((i < len - 2) ? 
			  (0x01 & (message[i + 2] >> (7 - j)))
			  : 0);
			if (sig_1)
				crc_reg ^= (unsigned short) 0x1021;
		}
	}
	return crc_reg;
}

#elif METHOD == 1
{
	int i, j;
	unsigned short crc_reg = init;
	unsigned short current;

	for (i = 0; i < len; i++) {
		current = message[i] << 8;
		for (j = 0; j < 8; j++) {
			if ((short) (crc_reg ^ current) < 0)
				crc_reg = (crc_reg << 1) ^ 0x1021;
			else
				crc_reg <<= 1;
			current <<= 1;
		}
	}
	return crc_reg;
}
#elif METHOD == 2
{
	int i, j;
	unsigned short crc_reg = init;
	unsigned short current;

	for (i = 0; i < len; i++) {
		current = message[i];
		for (j = 0; j < 8; j++) {
			if ((crc_reg ^ current) & 0x0001)
				crc_reg = (crc_reg >> 1) ^ 0x8408;
			else
				crc_reg >>= 1;
			current >>= 1;
		}
	}
	return crc_reg;
}
#elif METHOD == 3
{
	int i, j;
	unsigned short crc_reg = init;
	unsigned short to_xor;

	for (i = 0; i < len; i++) {
		to_xor = (crc_reg ^ message[i]) & 0xffff;
		for (j = 0; j < 8; j++) {
			if (to_xor & 0x0001)
				to_xor = (to_xor >> 1) ^ 0x8408;
			else
				to_xor >>= 1;
		}
		crc_reg = (crc_reg >> 8) ^ to_xor;
	}
	return crc_reg;
}

#elif METHOD == 4
/* crc16 in usb data packet */
{
	int i, j;
	unsigned short crc_reg = init;

	for (i = 0; i < len; i++) {
		for (j = 0; j < 8; j++) {
			if (((message[i] >> j) ^ crc_reg) & 0x01) {
				crc_reg = (crc_reg >> 1) ^ 0xA001;
			} else {
				crc_reg >>= 1;
			}
		}
	}
	return crc_reg;
}
#else
#error "METHOD must in [0..4]"
#endif


int main()
{
	char cs[100] = 
#ifdef TEST1
	"Hello World!\n";
#else
	{0x10, 0x07};
#endif
	unsigned short int code, n;
	char *s = &cs[0];

	n = strlen(s);
	printf("Data Len = %d CRC 0x%04X\n", n, code = ~do_crc(-1, s, n));
	//code = ~code;
#if METHOD < 2
	code = ((code & 0x00ff) << 8) | ((code >> 8) & 0x00ff);
#endif
	*((unsigned short *) (s + n)) = code & 0xffff;
	s[n += 2] = 0;

	printf("Transmitted Len = %d Check CRC 0x%04X\n", n,
	       (unsigned int) (code = do_crc(-1, s, n)));
	return 0;
}
