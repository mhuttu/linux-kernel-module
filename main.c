#include <linux/kernel.h>
#include <linux/in.h>
#include <linux/mdio.h>

static char* person="World";
static int times=1;

MODULE_DESCRIPTION("Hello world module");
MODULE_AUTHOR("Marko");
MODULE_LICENSE("GPL");

module_param(person,charp,0);
MODULE_PARAM_DESC(person,"Person to be greeted");
module_param(times,int,0);
MODULE_PARAM_DESC(times, "How many times the person is greeted");

static int hello_init_module(void)
{
    int i;
    printk(KERN_ALERT "Hello World!\n");
    for (i=0; i<times;i++)
        printk(KERN_ALERT "%d. Hello %s!\n",i,person);
    return 0;
}

static int hello_exit_module(void)
{
    printk(KERN_ALERT "Goodbye World!\n");
}

module_init(hello_init_module);
module_exit(hello_exit_module);
