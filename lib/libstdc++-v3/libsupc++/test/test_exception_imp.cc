#include <begin_include.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <end_include.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testing C++ exceptions");
MODULE_AUTHOR("Halldor Isak Gylfason <halldorisak AT ru DOT is>");

class A
{
public:
	A(){printk("Constructor class A\n");}
	~A(){printk("Destructor class A\n");}
	virtual void speak();	
};

A globalobject;

void A::speak() { printk("Class A is speaking!\n");}

void throwInteger()
{
   throw 3;	
}

void throwObject()
{
	throw A();
}

void doReThrow2()
{
    throw;	
}

void doReThrow()
{
	A a;
    doReThrow2();	
}

void testInteger()
{
   try
   {
   	  throwInteger();
   }
   catch(int i)
   {
   	   printk("Caught integer %u\n",i);
   	   try
   	   {
   	   	  doReThrow();
   	   }
   	   catch(int j)
   	   {
   	   	  printk("Rethrow works!\n");
   	   }
   }	
}

void testObject()
{
   try
   {
   	  throwObject();
   }
   catch(A& ob)
   {
   	   printk("Caught object\n");
   	   ob.speak();   	   
   }	
}

extern "C" {
static int __init test_exception_init()
{
   printk("Exception test module installed\n");
   testInteger();
   testObject();
   return 0;
}

static void __exit test_exception_fini()
{
    printk("Exception test module removed\n");
}

module_init(test_exception_init);
module_exit(test_exception_fini);
}