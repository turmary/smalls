
all: hello.so main main.exe

hello.so: hello_so.c hello_so.h
	gcc -shared -o hello.so hello_so.c

main main.exe: hello_so.h
	gcc -o main main.c ./hello.so

clean:
	rm -f hello.so main main.exe

run: all
	./main 100 50


.PHONY:	all clean run
