#include <stdio.h>
int funcB(int, int);
int funcA(int a, int b)
{
    printf("from %s:%d\n", __FILE__, __LINE__);
    return funcB(a, b);
}

