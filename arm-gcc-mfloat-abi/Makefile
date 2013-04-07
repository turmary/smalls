# tary, 11:46 2013-4-7

MAIN=mfloat-abi

SRC=$(MAIN).c
CC=arm-none-linux-gnueabi-gcc
OBJDUMP=arm-none-linux-gnueabi-objdump

TARGETS = $(addprefix $(MAIN)-,soft softfp hard)
FLOATABI = -mfloat-abi=$(subst $(MAIN)-,,$@)
# CFLAGS = -fno-builtin -march=armv7-a -mfpu=neon -g
CFLAGS = -fno-builtin -march=armv7-a -mfpu=neon -g -c

all : $(TARGETS)

$(TARGETS): $(SRC)
	-$(CC) $(CFLAGS) $(FLOATABI) -o $@ $<
	-$(OBJDUMP) -x -d -S -z $@ > $@.lss

clean:
	-rm $(TARGETS)
	-rm *.lss
