CURRENT = $(shell uname -r)
KDIR = /lib/modules/$(CURRENT)/build
PWD = $(shell pwd)
TARGET1 = test_module
obj-m := $(TARGET1).o
default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
