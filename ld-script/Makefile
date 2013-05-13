# tary, 23:30 2013/5/13

NAME = am18x

all: $(NAME).bin

$(NAME).bin: $(NAME).elf
	arm-none-eabi-objcopy -O binary $< $@

$(NAME).elf: $(NAME)_t.ld Makefile
	arm-none-eabi-ld -Map=$(NAME).map -o $@ $<

clean:
	rm -f $(NAME).bin
	rm -f $(NAME).elf
	rm -f $(NAME).map
