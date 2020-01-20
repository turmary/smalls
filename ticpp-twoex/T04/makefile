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
	T04-01.exe \
	T04-02.exe \
	T04-05.exe \
	T04-06.exe \
	T04-07.exe \
	T04-08.exe \
	T04-12.exe \

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


%.exe: %.$(OBJEXT) ../T03/T03Util.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	-$@

%.$(OBJEXT): %.cpp
	$(CPP) -c $(CPPFLAGS) $(EXEFLAG)$@ $^
