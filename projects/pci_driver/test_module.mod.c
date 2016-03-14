#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x4d5503c4, "module_layout" },
	{ 0xcfbcf016, "pci_unregister_driver" },
	{ 0x8a5c6ba4, "__pci_register_driver" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0xaa1e9e8e, "netdev_info" },
	{ 0x13567738, "register_netdev" },
	{ 0xf10de535, "ioread8" },
	{ 0xcedc88a4, "pci_iomap" },
	{ 0x10f1f344, "pci_request_regions" },
	{ 0x99d11769, "alloc_etherdev_mqs" },
	{ 0x8bbb98b7, "pci_set_master" },
	{ 0x89be693, "pci_enable_device" },
	{ 0x50eedeb8, "printk" },
	{ 0xc11c504f, "dev_set_drvdata" },
	{ 0x4a8ba1c4, "pci_release_regions" },
	{ 0xe7daadc4, "pci_disable_device" },
	{ 0x3485c1df, "free_netdev" },
	{ 0xb3b905c5, "pci_iounmap" },
	{ 0xdb0bd739, "unregister_netdev" },
	{ 0x4be141b4, "dev_get_drvdata" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("pci:v000013F0d00000200sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "8ECA4269C83BEDD876D4E52");
