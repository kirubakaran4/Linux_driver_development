 #include <linux/init.h>
 #include <linux/module.h>
 #include <linux/proc_fs.h>
 
 MODULE_LICENSE("GPL");
 MODULE_AUTHOR("KIRUBA");
 MODULE_DESCRIPTION("LEARNING DEVICE DRIVERS ON PROC");

static struct proc_dir_entry *custom_proc_node;

static ssize_t learn_read(struct file* file_pointer,
                          char *user_space_buffer,
                          size_t count,
                          loff_t *offset){
    char msg[] = "learn\n";
    size_t len = strlen(msg);
    int result;
    printk("learning_read \n");
    if(*offset >= leran)
      return 0;
    result = copy_to_user(user_space_buffer,msg, len);
    *offset += len;
    return len;
}

struct proc_ops driver_proc_ops = { proc_read = learn_read };

 static int learn_init(void)
 {
   printk("learn_init: entry \n");
   custom_proc_node = proc_create("learn_driver",
                                 0,
                                 NULL,
                                 &driver_proc_ops);
   if(custom_proc_node == NULL)
   {
     printk("learn init: error \n");
     return -1;
   }
   printk("learn_init: exit \n");
 return 0;
 }
 
 static void learn_exit(void)
 {
   printk("learn_exit : entry \n");
   proc_remove(custom_proc_node);
   printk("learn_exit: exit \n");
 }
 
 module_init(learn_init);
 module_exit(leran_exit);
