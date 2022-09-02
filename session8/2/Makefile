
obj-m += m.o


modules:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

modules_install:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules_install

test:
        sudo dmesg -C
        sudo insmod m.ko
        cat test.txt
        sudo rmmod m.ko
        sudo dmesg

all:    modules modules_install