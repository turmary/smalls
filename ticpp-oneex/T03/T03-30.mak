
CPP=g++
.SUFFIXES:	.exe .cpp
.cpp.exe:
	@echo @=$@
	@echo ^<=$<
	@echo *=$*
	$(CPP) -o$@ $<

all:		execute

clean:	
	@del YourPets1.exe
	@del YourPets2.exe

execute:	YourPets1.exe YourPets2.exe
	@YourPets1.exe
	@YourPets2.exe

YourPets1.exe:	YourPets1.cpp
YourPets2.exe:	YourPets2.cpp
