set DEVCPP=C:/MinGW
set LIB=%DEVCPP%/lib
%DEVCPP%/bin/gcc -S -o clock.s clock.c 
%DEVCPP%/bin/as -o clock.o clock.s
%DEVCPP%/bin/ld -Bdynamic -Map clock.map -o clock.exe %LIB%/crt2.o %LIB%/gcc/mingw32/3.4.5/crtbegin.o -L%LIB%/gcc/mingw32/3.4.5 -L%LIB%/gcc -L%DEVCPP%/mingw32/lib -L%LIB% clock.o -lgcc -lmingw32 -lmsvcrt -lkernel32 %LIB%/gcc/mingw32/3.4.5/crtend.o
