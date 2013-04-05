#include <stdio.h>

/*reverce print the table from fahr to celsius*/

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = upper;
	printf("%6s %3s", "fahr", "celsius\n");
	while(fahr >= lower){
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr - step;
	}
}