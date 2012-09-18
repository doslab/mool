


#include<c++/begin_include.h>
#include<linux/fs.h>
#include<c++/end_include.h>

class Char_Driver
{
public:
	int mool_register_chrdev(unsigned int  major, const char *name,struct file_operations *ops)
	{
		return register_chrdev(major,name,ops);	
	}
	
	int mool_unregister_chrdev(unsigned  int  major,  const  char *name)
	{
		return unregister_chrdev(major,name);
	}
	/*void unregister_chrdev_region(dev_t from, unsigned count)
        {
         unregister_chrdev_region(from,count);
          }

        int register_chrdev_region(dev_t from, unsigned count, const char *name)
        {
         return  register_chrdev_region(from,count,name);
        }

int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count,
                         const char *name)
        {
          return alloc_chrdev_region(dev,baseminor,count,name);
        }*/

};
