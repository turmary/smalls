# tary 1:54 2011/7/15
all: wldlg.exe

wldlg.exe: wldlg.cpp wldlg.rc
	windres -O coff -o wldlgrc.o wldlg.rc
	g++ -o wldlg.o -c wldlg.cpp
	g++ -o wldlg wldlgrc.o wldlg.o

clean:
	rm -f wldlg.exe wldlgrc.o wldlg.o

.PHONY: all clean
