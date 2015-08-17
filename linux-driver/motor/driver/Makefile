
ifneq ($(KERNELRELEASE),)
	obj-m := step_motor.o
else
	KERNELDIR = ../../OMAP35x_EVM/kernel/linux-2.6.29-0xlab

	PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o	\
		*~	\
		core	\
		.depend	\
		.*.cmd 	\
		*.ko	\
		*.mod.c	\
		.tmp_versions \
		modules.order \
		Module.symvers
endif

