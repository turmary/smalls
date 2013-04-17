# tary, 11:51 2013-3-30

TARGET=tty

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).o $(TARGET).res
	gcc -o $@ $^ -lcomctl32 -lcomdlg32 -lgdi32 -lws2_32 -Wl,--subsystem=console

%.o: %.c
	gcc -c -o $@ $<

$(TARGET).res: $(TARGET).rc
	windres -O coff -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f $(TARGET).res
	rm -f $(TARGET).exe
