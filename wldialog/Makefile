# tary 1:54 2011/7/15
all: wl.exe

wl.exe: wldialog.cpp wlrc.rc
	windres -O coff -o wlrc.o wlrc.rc
	g++ -o wldialog.o -c wldialog.cpp
	g++ -o wl wlrc.o wldialog.o -Wl,--subsystem,console
#	g++ -o wl wlrc.o wldialog.o -Wl,--subsystem,windows

clean:
	rm -f wl.exe wlrc.o wldialog.o

.PHONY: all clean
