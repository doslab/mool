#include <c++/begin_include.h>
//#include<linux/efi.h>
//#include<asm-i386/mach-default/mach_time.h>
//#include<linux/init.h>
#include<linux/module.h>
#include <c++/end_include.h>
class time
{ 
public:
 unsigned long get_cmos_time(void)
 {
/*        unsigned long retval;

//        spin_lock(&rtc_lock);
 
         if (efi_enabled)
                retval = efi_get_time();
         else
                retval = mach_get_cmos_time();
 
//         spin_unlock(&rtc_lock);
 
        return retval;
*/
	printk("inline function in wrapperrrrr");
	test();
 }
 void test()
 {
  printk("\n\nIn function test\n\n");
 }
 };

