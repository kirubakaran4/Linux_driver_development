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
	{ 0x57eddb30, "gpiod_set_value" },
	{ 0x9e00c8ec, "gpio_to_desc" },
	{ 0x7c268b39, "gpiod_direction_output" },
	{ 0x7c252db5, "gpiod_direction_input" },
	{ 0x31a2770b, "gpiod_get_value" },
	{ 0x122c3a7e, "_printk" },
	{ 0x47e64c59, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EA6E6FBDB484AF181734CC3");
