// tary, 11:33 2013-4-7
#include <math.h>

int main(int argc, char* argv[]) {
	volatile float x, y;
	float z;

	x = 3.25f;
	y = 2.125f;

	z = x * y;
	return (int)z;
}
