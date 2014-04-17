# tary, 11:46 2013-4-7
# tary, 11:31 2014-4-17

MAIN?=mfloat-abi
CROSS_COMPILE?=arm-none-linux-gnueabi-

SRC=$(MAIN).c
CC=$(CROSS_COMPILE)gcc
OBJDUMP=$(CROSS_COMPILE)objdump

TARGETS = $(addprefix $(MAIN)-,soft softfp hard)
FLOATABI = -lm -mfloat-abi=$(subst $(MAIN)-,,$@)
CFLAGS = -fno-builtin -march=armv7-a -mfpu=neon -g
# CFLAGS = -fno-builtin -march=armv7-a -mfpu=neon -g -c

all : $(TARGETS)

$(TARGETS): $(SRC)
	-$(CC) $(CFLAGS) $(FLOATABI) -o $@ $<
	-$(OBJDUMP) -x -d -S -z $@ > $@.lss

clean:
	-rm $(TARGETS)
	-rm *.lss


help:
	@echo command like :
	@echo "  make -k"
	@echo "  MAIN=mfloat-abi make -k"
	@echo "  CROSS_COMPILE=arm-none-linux-gnueabi- MAIN=hello-mfloat make -k"
