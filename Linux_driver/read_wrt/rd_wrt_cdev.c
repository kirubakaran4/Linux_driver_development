#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kiruba");
MODULE_DESCRIPTION("Creating a sample driver for registering a character device and performing read and write file ops");


static int major;
static char text[64];

static ssize_t my_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off)
{
    int not_copied, delta, to_copy = (len + *off) < sizeof(text) ? len : (sizeof(text) - *off);

    pr_info("hello_cdev - Write is called, we want to write %ld bytes, but actually only copying %d bytes. The offset is %lld\n", len, to_copy, *off);

    if (*off >= sizeof(text))
	{ 
        return 0;
	}
    not_copied = copy_from_user(&text[*off], user_buf, to_copy);
    delta = to_copy - not_copied;
    if (not_copied) 
        pr_warn("hello_cdev - Could only copy %d bytes\n", delta);

    *off += delta;

	 // Add null terminator (guard against overflow)
    if (*off < sizeof(text))
        text[*off] = '\0';
    else
        text[sizeof(text) - 1] = '\0';

    pr_info("hello_cdev - Write: wrote \"%s\" to text buffer. New offset: %lld\n", text, *off);

    return delta;
}


static loff_t my_llseek(struct file *file, loff_t offset, int whence)
{
    return default_llseek(file, offset, whence);
}


static ssize_t my_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off)
{   
   
    int not_copied, delta, to_copy = (len + *off) < sizeof(text) ? len : (sizeof(text) - *off);

    pr_info("hello_cdev - Read is called, we want to read %ld bytes, but actually only copying %d bytes. The offset is %lld\n", len, to_copy, *off);

    if (*off >= sizeof(text))
        return 0;

    not_copied = copy_to_user(user_buf, &text[*off], to_copy);
    delta = to_copy - not_copied;
    if (not_copied) 
        pr_warn("hello_cdev - Could only copy %d bytes\n", delta);

    *off += delta;

    pr_info("hello_cdev - Read: copied %d bytes. New offset: %lld\n", delta, *off);

    return delta;
}


static struct file_operations fops = {
	.read = my_read,
	.write = my_write,
    .llseek = my_llseek,
};

static int __init my_init(void)
{
	major = register_chrdev(0, "hello_cdev", &fops);
	if (major < 0) {
		pr_err("hello_cdev - Error registering chrdev\n");
		return major;
	}
	printk("hello_cdev - Major Device Number: %d\n", major);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_chrdev(major, "hello_cdev");
}

module_init(my_init);
module_exit(my_exit);

