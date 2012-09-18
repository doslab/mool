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
#include <end_include.h>

class Pager
{
public:

  struct page * fastcall mool___alloc_pages(unsigned int gfp_mask, unsigned int order,                 struct zonelist *zonelist)
  {
    __alloc_pages(gfp_mask, order,zonelist);
    
  }
  
  
  fastcall unsigned long mool___get_free_pages(unsigned int gfp_mask, unsigned int order)
  {
    __get_free_pages(gfp_mask,  order);
    
  }
  
  fastcall unsigned long mool_get_zeroed_page(unsigned int gfp_mask)
  {
    get_zeroed_page( gfp_mask);
  }
  
  static int mool_free_pages_bulk(struct zone *zone, int count,struct list_head *list, unsigned int order)
  {
    free_pages_bulk(zone, count,list,  order);
  }

  fastcall void mool___free_pages(struct page *page, unsigned int order)
  {
    __free_pages(page, order);
    
  }
  
  fastcall void mool_free_pages(unsigned long addr, unsigned int order)
  {
    free_pages( addr,  order);
  }
  
  unsigned int mool_nr_free_pages(void)
  {
    nr_free_pages();
  }
};












