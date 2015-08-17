#include <stdio.h>

typedef struct bb  
{  
    int id;            
    double weight;      
    float height;      
}BB;

#define X 5
#error X ## wps

int main() {
	printf("size of BB = %d\n", sizeof(BB));
	printf("%d\n", &(((BB*)0)->id));
	printf("%d\n", &(((BB*)0)->weight));
	printf("%d\n", &(((BB*)0)->height));
	printf("size of float = %d\n", sizeof(float));
	return 0;
}

