#include <stdio.h>
#ifndef PREFIX
#define PREFIX ""
#endif
int funcB(int a, int b)
{
    printf("from %s:%d (%s)\n", __FILE__, __LINE__, PREFIX);
    if (PREFIX[0] == '\0')
        return a * b;
    return a + b;
}

