// tary, 11:32 2013/9/20
#include <stdio.h>

int main(int argc, char* argv[]) {
	double unit_price;
	double s;
	double weight = 4.6; //g
	double step = 3.0;  //g
	double money;

	s = 0.0;
	money = 0.0;
	for (unit_price = 220.6; unit_price > 143.0; unit_price -= step) {
		double m = weight * unit_price;
		money += m;
		s += weight;

		printf("spend=%8.1f loss=-%8.1f price=%4.2f aver=%4.2f weight=%8.2f g\n",
		              money, (money / s - unit_price) * s, unit_price,  money / s,       weight);

		weight += 4.6 * 0.02;
	}
	printf("weight sum    = %8.2f g\n", s);
	printf("money spend   = %8.1f US $\n", money);
	printf("average price = %4.2f US $\n", money / s);
	return 0;
}
