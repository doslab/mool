#include <begin_include.h>
#include<linux/swap.h>
#include<linux/types.h>
#include<linux/linkage.h>
#include<linux/compiler.h>
#include<linux/sched.h>
#include<linux/mm.h>
#include <end_include.h>

class SwapManager
{
public:
  /* SCANNING FOR FREE ENTRIES */
  /* Allocates a page slot by searching in the active swap areas */
  swp_entry_t mool_get_swap_page(void)
  {
	return(get_swap_page());
  }

  /* Searches the swap_map for free slots */
  static inline int mool_scan_swap_map(struct swap_info_struct *si)
  {
	return(scan_swap_map(si));
  }

  	/* --> Associated method */
  /* Stores the type+offset of the page identifier in an arch-independent format*/
  static inline swp_entry_t mool_swp_entry(unsigned long type,pgoff_t offset)
  {
   	return(swp_entry(type,offset));
  }

  /* ACTIVATING A SWAP AREA */
  /* Setting up the swap area specifying the page_cluster value */
  void __init mool_swap_setup(void)
  {
	swap_setup();
  }

  /* DEACTIVATING A SWAP AREA */
  /* Page in all the pages from the swap area that are to be deactivated */
  static int mool_try_to_unuse(unsigned int type)
  {
	return(try_to_unuse(type));
  }

  /* Removes the requested page and entry from the process page tables */
  static int mool_unuse_process(struct mm_struct * mm,swp_entry_t entry, struct page* page)
  {
	return(unuse_process(mm,entry,page));
  }

  /* Searches the VMA for a page using the swap entry */
  static unsigned long mool_unuse_vma(struct vm_area_struct *vma,swp_entry_t entry, struct page *page)
  {
	return(unuse_vma(vma,entry,page));
  }

  /* Searches the requested PGD for pagetable entries mapping the page using the specified swap entry */
  static unsigned long mool_unuse_pgd(struct vm_area_struct *vma, pgd_t *pgd,unsigned long address,
				 unsigned long end,swp_entry_t entry, struct page *page)
  {
	return(unuse_pgd(vma,pgd,address,end,entry,page));
  }

  /* Searches the requested PMD for pagetable entries mapping the page using the specified swap entry */
  static unsigned long mool_unuse_pmd(struct vm_area_struct *vma, pmd_t *dir,unsigned long address,
				 unsigned long end,swp_entry_t entry, struct page *page)
  {
	return(unuse_pmd(vma,dir,address,end,entry,page));
  }

  /* Frees a swap entry if PTE at dir matches with the swap entry */
  static void mool_unuse_pte(struct vm_area_struct *vma, unsigned long address, pte_t *dir,swp_entry_t entry, struct page *page)
  {
	unuse_pte(vma,address,dir,entry,page);
  }

};

