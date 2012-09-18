#include <c++/begin_include.h>
#include <linux/init.h>
#include <linux/module.h>
#include <c++/end_include.h>
class Term
{

public:

 int printk(const char *fmt, ...)
{
         va_list args;
         int r;

         va_start(args, fmt);
         r = vprintk(fmt, args);
         va_end(args);

         return r;
}
};

