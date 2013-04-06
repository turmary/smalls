DEVROOT	=C:/MinGW

TARGET	=clock

CC	=$(DEVROOT)/bin/gcc.exe
AS	=$(DEVROOT)/bin/as.exe
LD	=$(DEVROOT)/bin/ld.exe

INCDIRS	=$(DEVROOT)/include \
	$(DEVROOT)/lib/gcc/mingw32/3.4.5/include

LIBDIRS	=$(DEVROOT)/lib/gcc/mingw32/3.4.5	\
	$(DEVROOT)/lib/gcc 			\
	$(DEVROOT)/mingw32/lib 			\
	$(DEVROOT)/lib

LIBS	=mingw32	\
	gcc		\
	msvcrt		\
	kernel32

OBJS	=$(TARGET).o					\
	$(DEVROOT)/lib/crt2.o				\
	$(DEVROOT)/lib/gcc/mingw32/3.4.5/crtbegin.o	\
	$(DEVROOT)/lib/gcc/mingw32/3.4.5/crtend.o	\

CCFLAGS	=$(patsubst %,-I%,$(INCDIRS))
ASFLGAS	=
LDFLAGS	=-Map $(TARGET).map				\
	$(patsubst %,-L%,$(LIBDIRS))			\
	$(patsubst %,-l%,$(LIBS))			\

#	$(OBJS)						\
#	$(TARGET).o					\
#	$(DEVROOT)/lib/crt2.o				\
#	$(DEVROOT)/lib/gcc/mingw32/3.4.5/crtbegin.o	\
#	$(DEVROOT)/lib/gcc/mingw32/3.4.5/crtend.o	\



all:	$(TARGET).exe

$(TARGET).exe: $(TARGET).o
	$(LD)  -Bdynamic $(OBJS) $(LDFLAGS) -o $@


$(TARGET).o: $(TARGET).s
	$(AS) $(ASFLAGS) -o $@ $<

$(TARGET).s: $(TARGET).c
	$(CC) $(CCFLAGS) -S -o $@ $<

clean:
	rm $(TARGET).s
	rm $(TARGET).o
	rm $(TARGET).exe
	rm $(TARGET).map
