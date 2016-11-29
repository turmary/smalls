
int bssvar = 0;
int globalvar = 1;
unsigned short us = 2;
unsigned char uc = 3;

int con(int c) {
	
	return c & 0x100 & globalvar;
}
