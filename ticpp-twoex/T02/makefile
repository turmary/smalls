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
	T02-01.exe \
	T02-04.exe \
	T02-05.exe

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


T02-01.exe: Test.$(OBJEXT) T02-01.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

T02-01.$(OBJEXT): T02-01.cpp

T02-04.exe: Test.$(OBJEXT) T02-03.$(OBJEXT) T02-04.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

T02-05.exe: Test.$(OBJEXT) T02-05.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

T02-03.$(OBJEXT): T02-03.cpp

T02-04.$(OBJEXT): T02-04.cpp

T02-05.$(OBJEXT): T02-05.cpp

Test.$(OBJEXT): ../TestSuite/Test.cpp
	$(CPP) -c $(CPPFLAGS) $(EXEFLAG)$@ $^
