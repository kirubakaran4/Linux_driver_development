#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbae73575, "default_llseek" },
	{ 0x5cf5454c, "__register_chrdev" },
	{ 0x122c3a7e, "_printk" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0xdcb764ad, "memset" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x47e64c59, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E0DE99E5EAB40FD799EECCC");
