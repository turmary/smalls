#include <stdio.h>
#define D_S 1

#if D_S
#include <conio.h>
#endif
int binsearch(int, int [], int);

int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while(low <= high && x != v[mid]){
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	return (low <= high)? mid: -1;
}

#if D_S
#define N(ar) sizeof(ar) / sizeof ar[0]
int main(){
	int a[] = {1, 5, 8, 13, 64, 92, 113, 252};

	clrscr();
	printf("binsearch(5) =%d\n", binsearch(5, a, N(a)));
	printf("binsearch(127) =%d\n", binsearch(127, a, N(a)));
	printf("binsearch(252) =%d\n", binsearch(252, a, N(a)));
	return 0;
}
#endif