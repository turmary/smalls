#include <stdio.h>

/*print the table convert from celsius to fahr*/

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 100;
	step = 10;
	celsius = lower;
	printf("%6s %3s", "celsius", "fahr\n");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}