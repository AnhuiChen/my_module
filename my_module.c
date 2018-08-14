#include <linux/init.h>		/* __init and __exit macroses */
#include <linux/kernel.h>	/* KERN_INFO macros */
#include <linux/module.h>	/* required for all kernel modules */
#include <linux/moduleparam.h>	/* module_param() and MODULE_PARM_DESC() */
#include <linux/time.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
#include <asm/atomic.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("chenxj");
MODULE_DESCRIPTION("This is my first module.");

struct timer_data {
    struct timer_list timer;
    struct workqueue_struct *work_queue;
    unsigned long prev_jiffies;
    unsigned int loops;
};



static int __init reverse_init(void)
{

    printk(KERN_INFO "[insmod %s]: hello, nice to meet you!\n", THIS_MODULE->name);

    return 0;
}

static void __exit reverse_exit(void)
{
    printk(KERN_INFO "[rmmod %s]: Goodbye!\n", THIS_MODULE->name);
}

module_init(reverse_init);
module_exit(reverse_exit);
