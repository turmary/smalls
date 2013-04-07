#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dos.h>

int main() {
	char far* cp;
	unsigned far * p, i, tseg;

	clrscr();
	p = MK_FP(0 , 0);
	printf("INO= SEG: OFF \n");
	printf("Cur=%04X:%04X\n", _CS, 0);
	for (i=0; i < 256; i++){
		printf("0x%02X=%04X:%04X\t", i, tseg=p[i*2+1], p[i*2]);
		if(tseg >= 0xF000)
			cp = "sys ROM";
		else if(tseg >= 0xE000)
			cp = "reserved area";
		else if(tseg >= 0xA000)
			cp = "video/disk bios/ems/rom extended";
		else if(tseg >= min(_CS, _DS))
			cp = "tc/current program";
		else if(tseg >= 0x0060)
			cp = "io.sys/msdos.sys/tsr";
		else if(tseg >= 0x0040)
			cp = "bios data area";
		else if(tseg > 0)
			cp = "interrupt vector";
		else
			cp = "0(unused)";
		if (tseg != 0){
			if (tseg < 0xA000) printf("basic--->");
			else		   printf("high---->");
		}
		printf("%s\n", cp);
		if (i % 20 == 19)
			assert(getch());
	}

	return 0;
}
