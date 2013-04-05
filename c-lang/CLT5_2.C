#include <stdio.h>
#include <ctype.h>
#define D_S_MAIN 1
#define D_S 0

double pow(double x, double y){
	double t = 1.0;
	int i;

	for(i = 0; i < (int)y ; i++){
		t *= x;
	}
	return t;
}

char bufp = 0;
char buf[2];
#define getch() (bufp ? buf[--bufp] : getchar())
#define ungetch(c) (buf[bufp++] = (char)(c));  

int getfloat(float *pn){
	int nc, c, sign, power, ep;

	while(isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-'){
		nc = c, c = getch();
		if(!isdigit(c)){
			ungetch(nc);
			return -1;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
#if D_S
	printf("First *pn = %f\n", *pn);
#endif
	if(c == '.'){
                c = getch();
        	for(power = 1.0; isdigit(c); c = getch()){
        	        *pn = 10.0 * *pn + (c - '0');
        	        power *= 10.0;
		}
		*pn /= power;
	}
	*pn *= sign;
#if D_S
	printf("Second *pn = %f\n", *pn);
#endif
	if(c == 'e' || c == 'E'){
		ep = 0;
		while(isdigit(c = getch()))
			ep = 10 * ep +  (c - '0');
		*pn *= pow(10.0, ep);
	}
#if D_S
	printf("Third *pn = %f\n", *pn);
#endif
	if (c != EOF)
		ungetch(c);
	return c;
}

#if D_S_MAIN
int main(){
	int i;
	float a;

	i = getfloat(&a);
	printf("getfloat(&a) = %d a = %f\n", i, a);
	i = getfloat(&a);
	printf("getfloat(&a) = %d a = %f\n", i, a);
	i = getfloat(&a);
	printf("getfloat(&a) = %d a = %f\n", i, a);
	return 0;
}
#endif



