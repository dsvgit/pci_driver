#include <linux/init.h>
#include <linux/module.h>
#include <asm-generic/current.h>
#include <linux/fs_struct.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DFGSFG");

static int __init md_init(void) {
	printk("testtest");
	return -1;
}

module_init(md_init);
