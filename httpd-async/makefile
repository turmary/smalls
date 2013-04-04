# tary, 14:44 2013/4/4

TARGET=httpa

all: $(TARGET)

$(TARGET): $(TARGET).o $(TARGET).res httpui.o reqlist.o
	gcc -o $(TARGET) $^ -lgdi32 -lcomctl32 -lws2_32 -Wl,--subsystem=windows

%.o: %.c
	gcc -c -o $@ $<

%.res: %.rc
	windres -O coff -o $@ $<

clean:
	rm -f *.o *.obj
	rm -f *.res
	# rm $(TARGET)
	rm $(TARGET).exe
