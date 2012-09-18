#include <begin_include.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <end_include.h>


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Testing C++ classes");
MODULE_AUTHOR("Halldor Isak Gylfason <halldorisak AT ru DOT is>");

class FileSystemException
{
private:
   char* message;
   
public:
   	FileSystemException(char* msg) : message(msg){}
   	char* getMessage() const { return message;} 
};

class FileSystem
{
public:
	virtual void mount() throw(FileSystemException) = 0;		
};


class NetworkFileSystem : public FileSystem
{
public:
	virtual void mount() throw(FileSystemException) 
	{
	   printk("Mounting Network File System\n");	
	}		
	
	NetworkFileSystem() { 
		printk("NetworkFileSystem initializing\n");
    }
};

class ReiserFileSystem : public FileSystem
{
public:
	virtual void mount() throw(FileSystemException) 
	{
	   printk("Mounting Reiser File system\n");	
	}		
	
	ReiserFileSystem() { 
		printk("ReiserFileSystem initializing\n");
    }	
};

template<class T> void do_throw(T & object)
{
    throw object;	
}

class ExceptionFileSystem : public FileSystem
{
public:
	virtual void mount() throw(FileSystemException) 
	{
	   FileSystemException exc("Unable to mount\n");
	   do_throw(exc);
	}		
	
	ExceptionFileSystem() { 
		printk("ExceptionFileSystem initializing\n");
    }	
};

NetworkFileSystem nfs;
ReiserFileSystem rfs;
ExceptionFileSystem efs;

FileSystem* allFileSystems[] = {&nfs,&rfs,&efs};

extern "C" {
static int __init test_classes_init()
{
   printk("File system classes installed\n"); 
   try
   { 
      allFileSystems[0]->mount();
      allFileSystems[1]->mount();
      
      ExceptionFileSystem* efs = dynamic_cast<ExceptionFileSystem*>(allFileSystems[2]);
      
      if(efs)
      {
      	efs->mount();
      }
   }
   catch(FileSystemException& fse)
   {
   	  printk("Unable to mount, error message: %s\n",fse.getMessage());
   }
   return 0;
}

static void __exit test_classes_fini()
{
    printk("File system classes  removed\n");
}

module_init(test_classes_init);
module_exit(test_classes_fini);
}