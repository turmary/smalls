# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C02
# Invoke with: make compiler-name
# or: make clean

ifeq ($(MAKECMDGOALS),)
MAKECMDGOALS = g++
endif

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe

g++:  \
	T03-01.exe \
	T03-02.exe \
	T03-03.exe \
	T03-04.exe \
	T03-05.exe \
	T03-06.exe \
	T03-07.exe \
	T03-08.exe \
	T03-09.exe \
	T03-12.exe

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.o
	del *.obj
	del *.exe
	del *.tds
	del *.map
else
	rm -f *.o *.obj *.exe *.tds *.map
endif


%.exe: T03Util.$(OBJEXT) %.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	-$@

%.$(OBJEXT): %.cpp
	$(CPP) -c $(CPPFLAGS) $(EXEFLAG)$@ $^
