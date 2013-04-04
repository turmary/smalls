# tary, 14:44 2013/4/4

TARGET=smallest

TARGETX=smallwindow

all: $(TARGET) $(TARGETX)

$(TARGET): $(TARGET).o $(TARGET).res
	gcc -o $@ $^ -lgdi32 -lcomctl32 -lws2_32 -Wl,--subsystem=windows

$(TARGETX): $(TARGETX).o
	gcc -o $@ $^ -lgdi32 -Wl,--subsystem=windows

%.o: %.c
	gcc -c -o $@ $<

%.res: %.rc
	windres -O coff -o $@ $<

clean:
	rm -f *.o *.obj
	rm -f *.res
	rm *.exe
