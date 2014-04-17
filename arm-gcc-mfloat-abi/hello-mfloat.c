#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
        double a, f;
        int i;

        printf("hello world!\n");

        a = 1.00001;
        f = 0.0000012;
        for (i = 0; i < 5000000; i++) {
                f = f * a;
        }

        printf("result = %lf %lf\n", f, sin(f));

        return 0;
}

