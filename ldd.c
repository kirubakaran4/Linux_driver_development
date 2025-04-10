#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KIRUBA");
MODULE_DESCRIPTION("LEARNING DEVICE DRIVERS");

static int learn_init(void)
{
printk("Hello Kernel \n");
return 0;
}

static void learn_exit(void)
{
printk("Exiting from Kernel \n");
}

module_init(learn_init);
module_exit(leran_exit);
