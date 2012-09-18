/*  fixdefines.h
 *
 *  Copyright (C) - Reykjavik University 2004
 *  Authors:            Petur Runolfsson
 *  E-mail:     pronto@ru.is
 */
#ifndef LINUX_FIXDEFINES_H_INCLUDED
#define LINUX_FIXDEFINES_H_INCLUDED

#include <c++/begin_include.h>
#include <linux/slab.h>
#include <c++/end_include.h>

/* Replacement macros for malloc, free and abort so the GCC runtime libraries
 * can be compiled for use in the kernel with minimal modifications. */
#ifdef __cplusplus
extern "C"
#else
static
#endif
inline void* cxx_malloc(size_t sz)
{
   return kmalloc(sz, GFP_KERNEL);
}

#ifdef __cplusplus
extern "C"
#else
static
#endif
inline void cxx_free(void* p)
{
   kfree(p);
}

#define free cxx_free
#define malloc cxx_malloc

#ifdef __cplusplus
extern "C"
inline void __attribute__((__noreturn__)) cxx_abort(void)
{
   printk("Aborted\n");
   BUG();
   for (;;);
}
#define abort cxx_abort
#else
static inline void __attribute__((__noreturn__))
c_abort(const char* file, int line, const char* function)
{
   printk("Aborted from %s:%d:%s\n", file, line, function);
   BUG();
   for (;;);
}

#define abort() c_abort(__FILE__, __LINE__, __FUNCTION__)
#endif

/* The libraries used are from gcc-3.4.0. This is needed so they can be
 * compiled with gcc-3.3.2. */
#if __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 4)
#define __builtin_extend_pointer(x) ((_Unwind_Ptr) (x))
#endif

#endif
