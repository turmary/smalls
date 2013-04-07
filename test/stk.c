#include <stdio.h>

int function (int x, int y, int z) {
    int *p;

    p = &x;
    if (p < &y) p--;
    else p++;
    *p += 8;

    return 0;
}

int main(void) {

    int x;
    x = 0;
    function(1,2,3);
    x = 1;
    printf("%d\n",x);
}
