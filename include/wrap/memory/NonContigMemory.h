
#include <begin_include.h>
#include<linux/vmalloc.h>
#include <end_include.h>

class NonContiguousMemory
{
public:
void * vmalloc (unsigned long size)
{
 vmalloc ( size);
}

void vfree(void * addr)
{
vfree(addr);
}

};  



