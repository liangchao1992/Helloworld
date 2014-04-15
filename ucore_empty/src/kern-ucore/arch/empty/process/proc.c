/* 
 * Chen Yuheng 2012/3
 * 
 */

#include <proc.h>
#include <mmu.h>
#include <vmm.h>
#include <slab.h>
#include <trap.h>
#include <arch.h>
#include <unistd.h>
#include <stdio.h>
#include <kio.h>
#include <string.h>
#include <sched.h>
#include <assert.h>
#include <syscall.h>
#include <signal.h>

#include <file.h>

/* ------------- process/thread mechanism design&implementation -------------
(an simplified Linux process/thread mechanism )
introduction:
  ucore implements a simple process/thread mechanism. process contains the independent memory sapce, at least one threads
for execution, the kernel data(for management), processor state (for context switch), files(in lab6), etc. ucore needs to
manage all these details efficiently. In ucore, a thread is just a special kind of process(share process's memory).
------------------------------
process state       :     meaning               -- reason
    PROC_UNINIT     :   uninitialized           -- alloc_proc
    PROC_SLEEPING   :   sleeping                -- try_free_pages, do_wait, do_sleep
    PROC_RUNNABLE   :   runnable(maybe running) -- proc_init, wakeup_proc, 
    PROC_ZOMBIE     :   almost dead             -- do_exit

-----------------------------
process state changing:
                                            
  alloc_proc                                 RUNNING
      +                                   +--<----<--+
      +                                   + proc_run +
      V                                   +-->---->--+ 
PROC_UNINIT -- proc_init/wakeup_proc --> PROC_RUNNABLE -- try_free_pages/do_wait/do_sleep --> PROC_SLEEPING --
                                           A      +                                                           +
                                           |      +--- do_exit --> PROC_ZOMBIE                                +
                                           +                                                                  + 
                                           -----------------------wakeup_proc----------------------------------
-----------------------------
process relations
parent:           proc->parent  (proc is children)
children:         proc->cptr    (proc is parent)
older sibling:    proc->optr    (proc is younger sibling)
younger sibling:  proc->yptr    (proc is older sibling)
-----------------------------
related syscall for process:
SYS_exit        : process exit,                           -->do_exit
SYS_fork        : create child process, dup mm            -->do_fork-->wakeup_proc
SYS_wait        : wait process                            -->do_wait
SYS_exec        : after fork, process execute a program   -->load a program and refresh the mm
SYS_clone       : create child thread                     -->do_fork-->wakeup_proc
SYS_yield       : process flag itself need resecheduling, -- proc->need_sched=1, then scheduler will rescheule this process
SYS_sleep       : process sleep                           -->do_sleep 
SYS_kill        : kill process                            -->do_kill-->proc->flags |= PF_EXITING
                                                                 -->wakeup_proc-->do_wait-->do_exit   
SYS_getpid      : get the process's pid

*/

static void forkret();
//trap/entry.S
extern void forkrets(struct trapframe *tf);

void switch_to(struct context *from, struct context *to);

void tls_switch(struct proc_struct *proc)
{
}

static void proc_signal_init(struct proc_signal *ps)
{
}

// alloc_proc - create a proc struct and init fields
struct proc_struct *alloc_proc(void)
{
	return NULL;
}

// forkret -- the first kernel entry point of a new thread/process
// NOTE: the addr of forkret is setted in copy_thread function
//       after switch_to, the current proc will execute here.
static void forkret(void)
{
}

// kernel_thread - create a kernel thread using "fn" function
int ucore_kernel_thread(int (*fn) (void *), void *arg, uint32_t clone_flags)
{
	return 0;
}

void de_thread_arch_hook(struct proc_struct *proc)
{
}

int do_execve_arch_hook(int argc, char **kargv)
{
	return 0;
}

// copy_thread - setup the trapframe on the  process's kernel stack top and
//             - setup the kernel entry point and stack of process
int
copy_thread(uint32_t clone_flags, struct proc_struct *proc,
	    uintptr_t esp, struct trapframe *tf)
{
	return 0;
}

/*  
 	At this entry point, most registers' values are unspecified, except:

    a1		Contains a function pointer to be registered with `atexit'.
		This is how the dynamic linker arranges to have DT_FINI
		functions called for shared libraries that have been loaded
		before this code runs.
 
    sp		The stack contains the arguments and environment:
		0(sp)			argc
		4(sp)			argv[0]
		...
		(4*argc)(sp)		NULL
		(4*(argc+1))(sp)	envp[0]
		...
					NULL
*/

int
init_new_context(struct proc_struct *proc, struct elfhdr *elf, int argc,
		 char **kargv, int envc, char **kenvp)
{
	return 0;
}

#ifdef UCONFIG_BIONIC_LIBC
int
init_new_context_dynamic(struct proc_struct *proc, struct elfhdr *elf, int argc,
			 char **kargv, int envc, char **kenvp,
			 uint32_t is_dynamic, uint32_t real_entry,
			 uint32_t load_address, uint32_t linker_base)
{
	return 0;
}

#endif //UCONFIG_BIONIC_LIBC

// kernel_execve - do SYS_exec syscall to exec a user program called by user_main kernel_thread
int kernel_execve(const char *name, const char **argv, const char **kenvp)
{
	return 0;
}

// cpu_idle - at the end of kern_init, the first kernel thread idleproc will do below works
void cpu_idle(void)
{
}
