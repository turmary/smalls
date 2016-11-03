
int bssvar = 0;
int globalvar = 1;

int con(int c) {
	
	return c & 0x100 & globalvar;
}
