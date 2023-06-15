#include <stdio.h>
#include <dlfcn.h>

/*
 * from https://www.cnblogs.com/LiuYanYGZ/p/5546242.html
 */
typedef int (*funcA)(int, int);
int main()
{
    void* plugin = dlopen("liblv0.so", RTLD_LAZY);

    funcA f = (funcA)dlsym(plugin, "funcA");
    printf("from %s:%d: %d\n", __FILE__, __LINE__, f(16, 8));
    return 0;
}

