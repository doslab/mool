
#include <begin_include.h>

#include<linux/sched.h>
#include<linux/mm.h>
#include <end_include.h>

class MemoryManager
{
public:
  void mool_exit_mm(struct task_struct *tsk)
  {
    exit_mm(tsk);
  }
 /* void *allocate_mm()
  {
    allocate_mm();
  }*/
  
  struct mm_struct * mool_mm_alloc(void)
  {
    mm_alloc();
  }
  
  void mool_exit_mmap(struct mm_struct * mm)
  {
    exit_mmap( mm);
  }
  
  
  /*int copy_mm(unsigned long clone_flags, struct task_struct * tsk)
  {
    copy_mm(clone_flags,  tsk);
  }*/
  
  
  /*void * free_mm(mm_struct *mm)
  {
    free_mm(mm);
  }*/
  
};
//exit_mm
//switch_mm//
//mm_init//
//allocate_mm
//mm_alloc
//exit_mmap
//copy_mm
//free_mm

