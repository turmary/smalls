// tary, 1:49 2013/4/8
#include <stdio.h>
#include <math.h>

int main(void){
        union fc{
                float f;
		unsigned long l;
	} fu;
	float f;
	int S, E;
	long M;

	scanf("%f", &fu.f);
	/* fu.f = 176.0625;
	{
	int i;

	for (i = 0; i < 4; i++){
		printf("%0x ", fu.c[i]);
	}
	}*/
	S = (fu.l & 0x80000000) >> 31;
	E = ((fu.l & 0x7F800000) >> 23) - 127;
	M = fu.l & 0x007FFFFF;

	printf("float S=%d	E=%d	M=%06lX\n", S, E, M);
	f = pow(-1, S);
	f *= (1.0 + M / pow(2, 23));
	f *= pow(2.0, E);
	printf("float Real=%f	float Calc=%f	long=%lX\n", fu.f, f, fu.l);

	return 0;
}
