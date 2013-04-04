#tary, 20:29 2013/4/4

TARGETS = cedit

all: $(TARGETS)

$(TARGETS):% : %.c
	gcc -o $@ $< -lkernel32 -luser32 -lgdi32

clean:
	rm $(TARGETS:=.exe)
