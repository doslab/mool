#include<begin_include.h>
#include<linux/sched.h>
#include<end_include.h>


class page1
{

 public:

 /**/
 void mool_paging_init(void)
	{
		paging_init();
	}

/*this function is responsible  for statically initializing page tables*/
 static void mool_pagetable_init(void)
	{
		pagetable_init();
	}

/*this function only exist if CONFIG_HIGHMEM is set during compile time.*/
 static void mool_kmap_init(void)
	{
		kmap_init();
	}
/*this function returns the struct page used by the PTE at address in mm's pagetables*/
 static struct page *mool_follow_page(struct mm_struct *mm, unsigned long address, int write)
	{
		follow_page(mm,address,write);
	}


};
