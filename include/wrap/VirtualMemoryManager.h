#include <begin_include.h>
#include<linux/mm.h>
#include <end_include.h>


class VirtualMemoryManager
{
  
public:
  
  
  struct vm_area_struct * mool_find_vma(struct mm_struct * mm, unsigned long addr)
  {
    find_vma( mm,  addr);
  }
  
  
  struct vm_area_struct *mool_vma_merge(struct mm_struct *mm,struct vm_area_struct *prev, unsigned long addr, unsigned long end, unsigned long vm_flags,
				   struct anon_vma *anon_vma, struct file *file,
				   pgoff_t pgoff, struct mempolicy *policy)
  {
    
    vma_merge(mm,prev, addr,  end,vm_flags,anon_vma, file,pgoff, policy);
    
  }
  
};

