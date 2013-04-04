#tary, 19:56 2013/4/4

TARGETS = randrect sinewave

all: $(TARGETS)

$(TARGETS):% : %.c
	gcc -o $@ $< -lkernel32 -luser32 -lgdi32

clean:
	rm $(TARGETS:=.exe)
