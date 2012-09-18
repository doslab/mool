/*
 * test.cc
 *
 *  Created on: May 23, 2012
 *      Author: hemang
 */

#include <c++/begin_include.h>
#include <linux/kernel.h>
#include <c++/end_include.h>

class Test_Class
{
private:
	char version[10];
public:
	Test_Class();
	void print_version();

}test_class_obj1;

void Test_Class::print_version()
{
	printk("\n-------------------------------\nVersion (a random string) is: %s\n------------------------------------------\n", version);
}

Test_Class::Test_Class()
{
	*version='L';
	version[1]='i';
	version[2]='n';
	version[3]='u';
	version[4]='x';
	version[5]='-';
	version[6]='3';
	version[7]='.';
	version[8]='0';
	version[9]='\0';
	printk("\n-------------------------------\nVersion (a random string) is: %s\n--------------------------------------\n", version);
}


class Test_Class2
{
private:
	char version2[10];
public:
	Test_Class2();
	void print_version2();

}test_class_obj2;

void Test_Class2::print_version2()
{
	printk("\n-------------------------%s-----------------------------------------\n", version2);
}

Test_Class2::Test_Class2()
{
	*version2='L';
	version2[1]='i';
	version2[2]='n';
	version2[3]='u';
	version2[4]='x';
	version2[5]='-';
	version2[6]='!';
	version2[7]='.';
	version2[8]='0';
	version2[9]='\0';
	printk("\n-------------------------%s--------------------------- --------------\n", version2);
}
class Test_Class3
{
private:
	char version2[10];
public:
	Test_Class3();
	void print_version3();

}test_class_obj3;

void Test_Class3::print_version3()
{
	printk("\n-------------------------%s-----------------------------------------\n", version2);
}

Test_Class3::Test_Class3()
{
	*version2='L';
	version2[1]='i';
	version2[2]='n';
	version2[3]='u';
	version2[4]='x';
	version2[5]='-';
	version2[6]='*';
	version2[7]='.';
	version2[8]='B';
	version2[9]='\0';
	printk("\n-------------------------%s--------------------------- --------------\n", version2);
}
