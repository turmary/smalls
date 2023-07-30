target = ubasic
cc = gcc -c
link32 = gcc
objs = basic.o grammar.o

all: $(target)

.c.o:
	$(cc) -o $@ $<

$(target): $(objs)
	$(link32) -o $(target) $(objs)

clean:
	rm $(objs)
	rm $(target).exe $(target)
