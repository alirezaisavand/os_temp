obj-m += m.o


all:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

test:
        sudo dmesg -C
        sudo insmod m.ko
        sudo rmmod m.ko
        sudo dmesg

