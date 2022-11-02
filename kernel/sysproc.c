#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_callcount(void) {
  return myproc()->callcount;
}

uint64
sys_myv2p(void) {
  struct proc *p;
  
  p = myproc();
  uint64 vaddr;
  argaddr(0, &vaddr);
  uint64 pa;
 
  printf("virutal address larger than maxmum\n");
  return 0;
  printf("MAXVA: %p\n", MAXVA);
  pa = walkaddr(p->pagetable, vaddr);
  uint64 mask = 0x0000000000000fff;
  uint64 offset = vaddr & mask;
  uint64 paandva = pa ^ offset;
  if (pa !=0)
  {
    printf("Succeed!!");
    printf("This is physical address %p\n", paandva);
  }else
  {
    printf("Physical address not found %d \n",vaddr);
  }
  return pa;
}


uint64
sys_haspages(void) {

  
  int proc_id;
  argint(0, &proc_id);
  struct proc *p = get_proc(proc_id);

  char info[][20] = {"code & static data", "guard page", "user stack", "heap"};

  // struct proc *p = myproc();
  uint32 default_pg_cnt = 3;
  uint32 page_cnt = p->sz / PGSIZE;
  uint32 start = 0;
  uint32 end = 4095;

  acquire(&p->lock);
  printf("-----------------pages_report----------------------\n");
  printf("%dpage has been allocated\n", page_cnt);
  for (int i = 0; i < default_pg_cnt; i ++) {
    printf("p_id:%d, start: %d, end: %d, size: %d, page_cnt: %d, content: %s\n", proc_id, start + i*PGSIZE, end + i*PGSIZE, PGSIZE, 1, info[i]);
  }
  uint32 heap_sz = p->sz - PGSIZE * default_pg_cnt;
  if (heap_sz != 0){
    printf("p_id:%d, start: %d, end: %d, size: %d, page_cnt: %d, content: %s\n", proc_id, start + default_pg_cnt * PGSIZE, p->sz-1, heap_sz, heap_sz / PGSIZE, info[default_pg_cnt]);
  }
  printf("--------------------------------------------------\n");
  release(&p->lock);

  return 0;


  // for(p = proc; p < &proc[NPROC]; p++) {

  //     if (p->state == RUNNABLE) {
  //       if (p->level > maxLevel) {
  //         maxLevel = p->level;
  //         maxSyscallCnt = p->callcount;
  //         maxSyscallProc = p;
  //       } else if (p->level == maxLevel) {
  //         if (p->callcount > maxSyscallCnt) {
  //           maxSyscallCnt = p->callcount;
  //           maxSyscallProc = p;
  //         } else {
  //           p->level ++;
  //         }
  //       } else {
  //         p->level ++;
  //       }
  //     }
  //   }
  
}
