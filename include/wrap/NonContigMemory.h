#include <begin_include.h>
#include<linux/vmalloc.h>
#include <end_include.h>

class NonContiguousMemory
{
public:
void * mool_vmalloc (unsigned long size)
{
 vmalloc ( size);
}

void mool_vfree(void * addr)
{
vfree(addr);
}

};



