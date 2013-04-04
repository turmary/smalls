
CPP=g++
.SUFFIXES:	.cpp .exe
.cpp.exe:
	$(CPP) -o$@ $<

all:	T03-34.exe
debug:	T03-34d.exe
clean:
	@del T03-34.exe
	@del T03-34d.exe

T03-34.exe:	T03-34.cpp

T03-34d.exe:	T03-34.cpp
	$(CPP) -g -o$@ $<
