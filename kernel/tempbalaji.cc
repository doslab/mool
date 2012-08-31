#include <c++/begin_include.h>
#include <linux/kernel.h>
#include <c++/end_include.h>

class rdclass
{

	protected: 
		int x;
	public:  rdclass();
}B;
rdclass::rdclass()
{
	x=111;
	printk("\n3rd class  coinstructor called:balaj: x is %d\n",x);

}

