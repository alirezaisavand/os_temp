#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alireza Isavand");
MODULE_DESCRIPTION("prints all syscall addresses in kernel.");
MODULE_VERSION("0.01");

static int __init sys_tbl_sh_init(void) {
        printk(KERN_INFO "Module started.\n");
        void ** sys_table = (void *)kallsyms_lookup_name("sys_call_table");
        int i;
        for(i = 0; i < NR_syscalls; i++){
                printk("%d --> %p", i, sys_table[i]);
        }
        return 0;
}

static void __exit sys_tbl_sh_exit(void) {
        printk(KERN_INFO "Module ends.\n");
}

module_init(sys_tbl_sh_init);
module_exit(sys_tbl_sh_exit);

