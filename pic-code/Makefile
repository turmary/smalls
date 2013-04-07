# tary, 9:45 2013-4-7
TARGET=piccode
CROSS=arm-none-eabi-

SRC=$(TARGET).c
ELF=$(TARGET).elf
LST=$(TARGET).lst
LSS=$(TARGET).lss
MAP=$(TARGET).map

CC=$(CROSS)gcc
OBJDUMP=$(CROSS)objdump

all: $(ELF) $(LSS)

$(ELF):	$(SRC)
	$(CC)	-o $(ELF) 		\
		-Wa,-adhlns=$(LST)	\
		-Wl,-Map=$(MAP),--cref	\
		-nostdlib		\
		-g			\
		-fpic 			\
		-msingle-pic-base	\
		-mpic-register=r10	\
		$(SRC)

$(LSS): $(ELF)
	$(OBJDUMP) -x -d -S $(ELF) >$(LSS)

clean:
	@-rm $(ELF) $(LST) $(LSS) $(MAP)

.PHONY:	clean
