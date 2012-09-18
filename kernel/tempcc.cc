#include <c++/begin_include.h>
#include <linux/kernel.h>
#include <c++/end_include.h>

class rd_class
{

	protected: 
		int x;
	public:  rd_class();
}X;
rd_class::rd_class()
{
	x=100;
	printk("\n3rd class constructor called: x is %d\n",x);

}

