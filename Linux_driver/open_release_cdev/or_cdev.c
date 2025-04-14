#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruba");
MODULE_DESCRIPTION("Creating a sample driver for registering a character device and making use of open and release funtion with kernel logs pr_info()");


static int major;

static int my_open(struct inode *inode, struct file *filp)
{
	pr_info("openrel_cdev - Major: %d, Minor %d\n", imajor(inode), iminor(inode));


	pr_info("openrel_cdev - filp->f_pos: %lld\n", filp->f_pos);
	pr_info("openrel_cdev - filp->f_mode: 0x%x\n", filp->f_mode);
	pr_info("openrel_cdev - filp->f_flags: 0x%x\n", filp->f_flags);

	return 0;
}

static int my_release(struct inode *inode, struct file *filp)
{
	pr_info("openrel_cdev - File is closed\n");
	return 0;
}

static struct file_operations fops = {
	.open = my_open,
	.release = my_release,
};

static int __init my_init(void)
{
	major = register_chrdev(0, "openrel_cdev", &fops);
	if (major < 0) {
		pr_err("openrel_cdev - Error registering chrdev\n");
		return major;
	}
	pr_info("openrel_cdev - Major Device Number: %d\n", major);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_chrdev(major, "openrel_cdev");
}

module_init(my_init);
module_exit(my_exit);

