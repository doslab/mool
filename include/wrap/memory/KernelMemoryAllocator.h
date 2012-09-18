

#include <begin_include.h>
#include<linux/slab.h>
#include <end_include.h>


class KernelMemoryAllocator
{
  
  kmem_cache_t * mool_kmem_cache_create (const char *name, size_t size, size_t offset,
				    unsigned long flags, void (*ctor)(void*, kmem_cache_t *, unsigned long),
				    void (*dtor)(void*, kmem_cache_t *, unsigned long))
  {
    
    
    kmem_cache_create (name,size,offset,flags, ctor,dtor);
  }
  
  int fastcall mool_kmem_cache_reap (int gfp_mask)
  {
    kmem_cache_reap (gfp_mask);
  }
  
  
  int mool_kmem_cache_shrink(kmem_cache_t *cachep)
  {
    kmem_cache_shrink(cachep);
  }
  
  void * mool_kmem_cache_alloc (kmem_cache_t *cachep, int flags)
  {
    kmem_cache_alloc (cachep,  flags);
  }
  
  
  void mool_kmem_cache_free (kmem_cache_t *cachep, void *objp)
  {
    kmem_cache_free (cachep, objp);
  }
  
  void * mool_kmalloc (size_t size, int flags)
  {
    kmalloc (size, flags);
  }
  
  void mool_kfree (const void *objp)
  {
    kfree ( objp);
  }
  
  int mool_kmem_cache_destroy (kmem_cache_t * cachep)
  {
    kmem_cache_destroy (cachep);
  }
};
  
  //kmem_cache_create
  //kmem_cache_reap
  //kmem_cache_shrink
  //kmem_cache_alloc
  //kmem_cache_free
  //kmalloc
  //kfree
  //kmem_cache_destroy
  

