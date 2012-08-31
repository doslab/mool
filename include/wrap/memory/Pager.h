//alloc_page
//alloc_pages
//get_free_page
//_get_free_page
//_get_free_pages
//_get_dma_pages
//   rmqueue
//__free_pages
//__free_page
//free_page
#include <begin_include.h>
#include<linux/gfp.h>
#include<linux/swap.h>
#include <end_include.h>

class Pager
{
public:

   static inline struct page * mool_alloc_pages(gfp_t gfp_mask, unsigned int order)
{ 
alloc_pages(gfp_mask, order)

}
  unsigned long mool___get_free_pages(unsigned int gfp_mask, unsigned int order)
  {
    __get_free_pages(gfp_mask,  order);
    
  }
  
  unsigned long mool_get_zeroed_page(unsigned int gfp_mask)
  {
    get_zeroed_page( gfp_mask);
  }
  
  static int mool_free_pages_bulk(struct zone *zone, int count,struct list_head *list, unsigned int order)
  {
    free_pages_bulk(zone, count,list,  order);
  }

   void mool___free_pages(struct page *page, unsigned int order)
  {
    __free_pages(page, order);
    
  }
  
   void mool_free_pages(unsigned long addr, unsigned int order)
  {
    free_pages( addr,  order);
  }
  
  unsigned int mool_nr_free_pages(void)
  {
    nr_free_pages();
  }
};












