#!/bin/bash

# for more information
# info ld.so

gcc -shared -fPIC liblv1.c -o liblv1.so

mn=$(uname -m)
gcc -shared -fPIC -DPREFIX=\"/lib/$mn\" liblv1.c -o liblv1-$mn.so
[ -d "/lib/$mn" ] || {
    sudo mkdir /lib/$mn
}
sudo cp liblv1-$mn.so /lib/$mn/liblv1.so

function main_elf_test() {
    gcc main.c -o main.elf -ldl -Wl,--rpath=.,--enable-new-dtags
    sleep 0.5
    readelf -d main.elf | head -n 10
    echo "========"
    ./main.elf

    gcc main.c -o main.elf -ldl -Wl,--rpath=.,--disable-new-dtags
    sleep 0.5
    readelf -d main.elf | head -n 10
    echo "========"
    ./main.elf
}

echo -e "\n\n\nlibrary level0 has no RPATH/RUNPATH\n"
gcc -shared -fPIC liblv0.c -o liblv0.so -L. -llv1
main_elf_test

echo -e "\n\n\nlibrary level0 has RUNPATH = (..)\n"
gcc -shared -fPIC liblv0.c -o liblv0.so -L. -llv1 -Wl,--rpath=..,--enable-new-dtags
main_elf_test

echo -e "\n\n\nlibrary level0 has RPATH\n"
gcc -shared -fPIC liblv0.c -o liblv0.so -L. -llv1 -Wl,--rpath=.,--disable-new-dtags
main_elf_test


# https://www.spinics.net/lists/linux-man/msg02291.html
echo -e '#include <dlfcn.h>\n#include <stdio.h>\nvoid lib1(void) { if
(dlopen("liblib2.so", RTLD_NOW)) printf("ok\\n"); }' > lib1.c
gcc lib1.c -shared -fPIC -o liblib1.so -ldl
cp liblib1.so liblib2.so

echo "void lib1(void); int main(void) { lib1(); }" > main0.c
gcc main0.c -o main0 $PWD/liblib1.so -Wl,-rpath,$PWD -Wl,--enable-new-dtags

./main0 # does not print 'ok'

