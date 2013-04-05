#include <stdio.h>
#include <conio.h>
#define N1 1
#define N2 2
#define N3 2

static void forcefloat(float *p){
float f = *p; forcefloat(&f);}

main(){
	float score[N1][N2][N3], studav[N1][N2];
	int i, j, k;
	float sum;
	clrscr();
	for(i = 0; i < N1; i++)
		for(j = 0; j < N2; j++)
			for(k = 0; k < N3; k++){
				printf("\nInput %d class No. %d student subject %d score[%d][%d][%d]: ", i+1, j+1, k+1, i, j, k);
				scanf("%f", &score[i][j][k]);
			}
	for(i = 0; i < N1; i++)
		for(j = 0; j < N2; j++){
			sum = 0;
			for(k = 0; k < N3; k++)
				sum += score[i][j][k];
			studav[i][j] = sum / N3;
			printf("\n%d class No. %d student average score studav[%d][%d] is: %f", i+1, j+1, i, j, studav[i][j]);
		}
}