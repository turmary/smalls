
.cpp.o:
	g++ -c -o$@ $<

ALL: UseHandle.exe

UseHandle.exe:	T05-13.o UseHandle.o
	g++ -oUseHandle T05-13.o UseHandle.o

T05-13.o: T05-13.cpp Handle.h

UseHandle.o: UseHandle.cpp Handle.h

clean:
	@del UseHandle.o
	@del T05-13.o
	@del UseHandle.exe
