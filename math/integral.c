// tary, 21:26 2015/11/10
/*
	integer(0,sqrt(2)) 1/2 * r ^ 2 * sqrt(1 + r ^ 2) rdr
*/
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
	double f;
	double r;
	double dr;

	dr = 1e-6;
	f = 0.0;
	for  (r = 0.0; r < sqrt(2); r += dr) {
		f += 1.0 / 2 * pow(r, 3) * sqrt(1 + r * r) * dr;
	}
	printf("f = %lf\n", f);
	printf("x = %lf\n", (2 * sqrt(3) + 1.0 / 3) / 5.0);
	return 0;
}
