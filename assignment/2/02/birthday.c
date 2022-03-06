#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/list.h>

struct birthday {
    int day;
    int month
    int year;
    struct list_head list;
}

static LIST_HEAD(birthday_list);

int 
birthday_init(void)
{
    printk(KERN_INFO "Loading Module\n");

    int i = 0;
    struct birthday *person;

    for(i=0; i<5; i++) {
        person = kmalloc(sizeof(person), GFP_KERNEL);
        person->day = i+1; person->month = i+1; person->year = i+2001;

        INIT_LIST_HEAD(&person->list);
    list_add_tail(&person->list, &birthday_list);
    }

    struct birthday *ptr;
    list_for_each_entry(ptr, &birthday_list, list) {
        printk(KERN_INFO "Birthday: %4d/%02d/%02d\n", ptr->year, ptr->month, ptr->day);
    }
    
    return 0;
}

void
birthday_exit(void) {
    printk(KERN_INFO "Removing List Nodes\n");
    
    struct birthday *ptr;
    long id;

    list_for_each_entry(ptr, &birthday_list, list) {
        printk(KERN_INFO "DEL %ld.\n", id);
        id++;
        list_del(&ptr->list);
        kfree(ptr);
    }
    
    printk(KERN_INFO "Removing Module\n");
}

module_init(birthday_init);
module_exit(birthday_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("birthday module");
MODULE_AUTHOR("Warlock");