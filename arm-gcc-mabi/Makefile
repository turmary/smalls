# tary, 0:46 2016/11/3

MAIN?=conc
CROSS_COMPILE?=arm-none-eabi-

SRC=$(MAIN).c
CC=$(CROSS_COMPILE)gcc
OBJDUMP=$(CROSS_COMPILE)objdump

TARGETS = $(addsuffix .S,$(addprefix $(MAIN)-,aapcs aapcs-linux apcs-gnu atpcs))
TARGETS += $(addsuffix .S,$(addprefix $(MAIN)-frame-,aapcs aapcs-linux apcs-gnu atpcs))
MABI = -lm -mabi=$(basename $(subst frame-,,$(subst $(MAIN)-,,$@)))
MABI += $(patsubst %,-mapcs-frame,$(filter $(MAIN)-frame-%,$@))
CFLAGS = -fno-builtin -march=armv7-a -mfpu=neon

all : $(TARGETS)

$(TARGETS): $(SRC)
	-$(CC) $(CFLAGS) $(MABI) -S -o $@ $<

clean:
	-rm $(TARGETS)


help:
	@echo command like :
	@echo "  make -k"
	@echo "  MAIN=conc make -k"
	@echo "  CROSS_COMPILE=arm-none-eabi- MAIN=conc make -k"
