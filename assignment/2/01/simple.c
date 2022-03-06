#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int 
simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    printk(KERN_INFO "Birthday: 2001/01/01\n");
    printk(KERN_INFO "Birthday: 2002/02/02\n");
    printk(KERN_INFO "Birthday: 2003/03/03\n");
    printk(KERN_INFO "Birthday: 2004/04/04\n");
    printk(KERN_INFO "Birthday: 2005/05/05\n");
    return 0;
}

void
simple_exit(void)
{
    printk(KERN_INFO "Removing List Nodes\n");

    printk(KERN_INFO "DEL 0");
    printk(KERN_INFO "DEL 1");
    printk(KERN_INFO "DEL 2");
    printk(KERN_INFO "DEL 3");
    printk(KERN_INFO "DEL 4");

    printk(KERN_INFO "Removing Module\n");
}

module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("simple module");
MODULE_AUTHOR("Warlock");