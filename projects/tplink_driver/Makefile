#
# Makefile for IC Plus Ethernet Adapter driver for Linux
# Copyright (c) 2004 by IC Plus Corporation.
#
#
OBJS	= sundance_main.o mii.o
TARGET  = sundance.o
MAPPING_MODE= -DUSE_IO_OPS
#MAPPING_MODE= -DUSE_IO_OPS -DNO_EEPROM -DMP_EEPROM

KernelVersion            := $(shell uname -r)
KernelBuildDir           := /lib/modules/$(KernelVersion)/build
kernelMisc               := /lib/modules/$(KernelVersion)/kernel/drivers/net/
kernelExtension          := $(shell echo $(KernelVersion) | sed -ne 's/^2\.[567]\..*/k/p')o
kernelFlag26               := kernel2$(shell echo $(KernelVersion) | sed -ne 's/^2\.[6]\..*/6/p')x


#======================Makefile for kernel 2.2.x and 2.4.x======================
ifneq ($(kernelFlag26),kernel26x)
CC 	= gcc
CFLAGS = -D__KERNEL__ -DMODULE -O -Wall -Wstrict-prototypes -I$(INCLUDEDIR)
EXTRA_CFLAGS := $(MAPPING_MODE) 
EXTRA_CFLAGS := $(EXTRA_CFLAGS) -D_COMPAT_WITH_OLD_KERNEL


KernelSrcPath :=  /lib/modules/$(shell uname -r)/build \
        /usr/src/linux-$(shell uname -r) \
        /usr/src/linux-$(shell uname -r | sed 's/-.*//') \
        /usr/src/kernel-headers-$(shell uname -r) \
        /usr/src/kernel-source-$(shell uname -r) \
        /usr/src/linux-$(shell uname -r | sed 's/\([0-9]*\.[0-9]*\)\..*/\1/') \
        /usr/src/linux
FindDir = $(shell [ -e $(dir)/include/linux ] && echo $(dir))
KernelSrcPath := $(foreach dir, $(KernelSrcPath), $(FindDir))
KernelSrc := $(firstword $(KernelSrcPath))

# Support Linux software VLAN
#EXTRA_CFLAGS := $(EXTRA_CFLAGS) -DCONFIG_VLAN_8021Q

#EXTRA_CFLAGS := $(EXTRA_CFLAGS) -DEXTRA_STATS
#DEBUG_FLAGS = -O -g -DALTA_DEBUG
K_VER=$(shell uname -r)
INCLUDEDIR=$(shell if [ -e /usr/src/linux-$(K_VER)/include ]; \
	then echo "/usr/src/linux-$(K_VER)/include"; \
	elif [ -e /usr/src/linux-2.4/include ]; \
	then echo "/usr/src/linux-2.4/include"; \
	elif [ -e /usr/src/linux/include ]; \
	then echo "/usr/src/linux/include"; \
	else echo "/usr/include"; fi)
#
# Old kernel need to configure modversions.h
#
#EXTRA_CFLAGS := $(EXTRA_CFLAGS) \
#	$(shell if [ -e $(INCLUDEDIR)/linux/modversions.h ]; \
#	then echo -DCONFIG_MODVERSIONS; fi)

CFLAGS+=$(shell [ -f $(KernelSrc)/include/linux/modversions.h ] && \
                echo "-DMODVERSIONS -include $(KernelSrc)/include/linux/modversions.h")
                
$(TARGET):	$(OBJS)
		$(LD) -r -o $@ $(OBJS)
#
# Dependency to create object file.
#
all:    $(TARGET)
#
#
# Common make rules
# 
%.o:%.c
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) $(DEBUG_FLAGS) -c -o $@ $< 
endif


#===========================Makefile for kernel 2.6.x===========================
ifeq ($(kernelFlag26),kernel26x)
EXTRA_CFLAGS+=$(MAPPING_MODE)
all:
	$(MAKE) -C $(KernelBuildDir) SUBDIRS=$(PWD) modules 
	
install:
	install -m 644 -c sundance.$(kernelExtension) $(kernelMisc)

sundance-objs:=$(OBJS)
obj-m+=$(TARGET)
endif

#===========================Makefile common section============================
# Delete existing object file 
#
clean:
	rm -f *.o *.ko *~ core* .dep* .*.d .*.cmd *.mod.c *.a *.s .*.flags
