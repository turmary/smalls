#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif

double pow(double, double);
int atoi(char s[]);
double atof(char s[]);

double atof(char *s){
        double val, power;
	int i, sign, ep;

        for(i = 0; isspace(s[i]); i++)
                ;
	sign = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
                i++;
        for(val = 0.0; isdigit(s[i]); i++)
                val = 10.0 * val + (s[i] - '0');
        if(s[i] == '.')
                i++;
        for(power = 1.0; isdigit(s[i]); i++){
                val = 10.0 * val + (s[i] - '0');
                power *= 10.0;
	}
	if(s[i] == 'e' || s[i] == 'E'){
		ep = atof(&s[++i]);
		val *= pow(10.0, ep);
	}
        return sign * val / power;
}

#if D_S
int main(){
	char	i,
		a[][16] = {
			"10e+5",
			".5334e3",
			"9342e-2",
			"342.36298",
			"+6342.39",
			"-1",
			"0e0"
		};

	clrscr();
	for(i = 0; i < sizeof(a) / sizeof(char [16]); i++){
		printf("atof(%10s)\t= %18.5g\n", a[i], atof(a[i]));
	}
	return 0;
}
#endif