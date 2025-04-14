#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruba");
MODULE_DESCRIPTION("A simple Hello World Linux Kernel Module");

static int __init my_init(void)
{
	printk("Entry - Hello, Kernel!\n");
	return 0;
}

static void __exit my_exit(void)
{
	printk("Exit - Goodbye, Kernel!\n");
}

module_init(my_init);
module_exit(my_exit);

