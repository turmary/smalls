# tary, 16:02 2015/6/6

TARGET=hclient

all: $(TARGET)

$(TARGET): $(TARGET).o $(TARGET).res buffers.o ecdisp.o logpnp.o pnp.o report.o strings.o
	gcc -o $@ $^ -lgdi32 -lcomctl32 -lcomdlg32 -lws2_32 -lhid -lsetupapi -Wl,--subsystem=console

%.o: %.c
	gcc -DWINVER=0x0500 -D_WIN32_WINNT=0x0500 -c -o $@ $<

%.res: %.rc
	windres -O coff -o $@ $<

clean:
	rm -f *.o *.obj
	rm -f *.res
	# rm $(TARGET)
	rm $(TARGET).exe
