obj-m += or_cdev.o

all: cdev_test
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -f cdev_test

cdev_test: test.c
	gcc test.c -o $@