
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mehregan Mohseni");
MODULE_DESCRIPTION("Hooking open system call.");
MODULE_VERSION("0.01");

void** sys_call_table_ptr;

asmlinkage int (*original_open)( const char __user *, int , mode_t);

asmlinkage int  new_open( const char __user * pathname, int flags, mode_t mode ){
        printk(KERN_INFO "97110788-97107245\n");
        return ( *original_open )( pathname, flags, mode );
}

static int __init open_hook_init(void){
        printk(KERN_INFO "Module started.\n");
        write_cr0(read_cr0() & (~0x10000));
        sys_call_table_ptr = (void*) kallsyms_lookup_name("sys_call_table");
        original_open = sys_call_table_ptr[__NR_openat];
        sys_call_table_ptr[__NR_openat] = new_open;
        write_cr0(read_cr0() | (0x10000));
        return 0;
}

static void __exit open_hook_exit(void){
        write_cr0(read_cr0() & (~0x10000));
        sys_call_table_ptr[__NR_openat] = original_open;
        write_cr0(read_cr0() | (0x10000));
        printk(KERN_INFO "Module ends.\n");
}

module_init(open_hook_init);
module_exit(open_hook_exit);

