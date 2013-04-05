#include <stdio.h>

/*add a title to the table convert fahr to celsius*/
float f2c(float f){
	float c;

	c = (5.0/9.0) * (f - 32.0);
	return c;
}

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	printf("%3s %6s", "fahr", "celsius\n ");
	while(fahr <= upper){
		printf("%3.0f %6.1f\n", fahr, f2c(fahr));
		fahr = fahr + step;
	}
}