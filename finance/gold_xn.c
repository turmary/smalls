// tary, 23:13 2013/11/26
#include <stdio.h>
#include <math.h>

static double X[256];
static int n = 1;
static double pp = 2.0;
static double zz = 1.5;

double f(double x) {
	int i;
	double a, b;
	double right;
	double left;

	a = x;
	for (i = 0; i < n - 1; i++) {
		a += X[i];
	}
	b = a / n;

	left = (x - b) * (x - b);

	right = 4 * pp * pp;
	a = (x - b) * (x - b);
	for (i = 0; i < n - 1; i++) {
		a += (X[i] - b) * (X[i] - b);
	}
	right *= a;
	right -= (n - 1) * zz * zz;

	return right - left;
}

double twoPart(double an, double bn){
	double f12, t;

	for(; (bn - an) / 2 >= 1e-6;){
		f12 = f(an) * f(t = (an + bn) / 2);
		if(f12>0)	an = t;
		else if(f12<0)	bn = t;
		else		break;
	}
	return t;
}

#define AUTO_SA_SB		1
int main(int argc, char* argv[]){
	double fsa;
	double sa, sb, sm, step;
	double x;
	int i;

repeat:
#if AUTO_SA_SB
	fprintf(stderr, "Input N,PP,ZZ,X[1],...,X[n-1]\n");
#else
	fprintf(stderr, "Input N,PP,ZZ,X[1],...,X[n-1],Xn1,Xn2\n");
#endif
	scanf("%d", &n);
	if (n < 2) {
		fprintf(stderr, "N two small\n");
		exit(1);
	}
	scanf("%lf %lf", &pp, &zz);
	for (i = 0; i < n - 1; i++) {
		scanf("%lf", &X[i]);
	}
#if AUTO_SA_SB
	sa = -5000;
	sb = 5000;
#else
	scanf("%lf %lf", &sa, &sb);
#endif

	if (f(sa) * f(sb) < 0) {
		x = twoPart(sa, sb);
		printf("The Result: Xn1* = %10.4lf f(Xn1) = %10.4lf\n", x, f(x));
		goto result;
	}

	sm = sa;
	fsa = f(sa);
	step = (sb - sa) / 10000;
	for (x = sa; x < sb; x += step) {
		if (fsa * f(x) < 0) {
			sm = x;
			break;
		}
	}

	if (f(sa) * f(sm) >= 0) {
		fprintf(stderr, "Xn1 = %10.4lf Xn2 = %10.4lf Invalid\n", f(sa), f(sm));
		goto result;
	}

	x = twoPart(sa, sm);
	printf("The Result: Xn1* = %10.4lf f(Xn1) = %10.4lf\n", x, f(x));
	x = twoPart(sm, sb);
	printf("The Result: Xn2* = %10.4lf f(Xn2) = %10.4lf\n", x, f(x));

result:
	fflush(stdin);
	goto repeat;
	getchar();
	return 0;
}
