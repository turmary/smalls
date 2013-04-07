# tary, 11:51 2013-3-30

TARGET=nettime

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(TARGET).o $(TARGET).res
	gcc -o $@ $^ -lwsock32 -Wl,--subsystem=windows

$(TARGET).o: $(TARGET).c
	gcc -c -o $@ $<

$(TARGET).res: $(TARGET).rc
	windres -O coff -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f $(TARGET).o
	rm -f $(TARGET).res
	rm -f $(TARGET).exe
