#include <begin_include.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <end_include.h>


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testing C++ dynamic cast");
MODULE_AUTHOR("Halldor Isak Gylfason <halldorisak AT ru DOT is>");

class A
{
public:
	virtual void speak();	
};

//void A::speak() { printk("Class A is speaking!\n");}

class B : public A
{
public:
	virtual void speak();	
};

void B::speak() { printk("Class B is speaking!\n");}


void doDynamicCast(A* a)
{
   B* b = dynamic_cast<B*>(a);
   if(b)
   {
   	  printk("Dynamic cast succeeded\n");
   }
   else
   {
   	  printk("Dynamic cast did not succeed\n");
   }	
}

void testDynamicCast()
{
   B b;
   doDynamicCast(&b);
}

extern "C" {
static int __init test_dynamic_cast_init()
{
   printk("Exception dynamic_cast installed\n");
   testDynamicCast();
   return 0;
}

static void __exit test_dynamic_cast_fini()
{
    printk("Exception dynamic_cast removed\n");
}

module_init(test_dynamic_cast_init);
module_exit(test_dynamic_cast_fini);
}
