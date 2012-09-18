/*  cxa_atexit.c
 *
 *  Copyright (C) - Reykjavik University 2004
 *  Authors:            Petur Runolfsson
 *  E-mail:     pronto@ru.is
 */

#include <linux/module.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <asm/bug.h>

/*  This code is loosely based on cxa_atexit.c and cxa_finalize.c in
 *  glibc-2.3. */

/* A registered destructor function */
struct atexit_fn {
   void (*func) (void *);
   void *arg;
   void *d;
   struct atexit_fn *next;
};

/* Linked list of registered destructors, protected by callbacks_lock */
static struct atexit_fn *callbacks;
//static spinlock_t callbacks_lock = SPIN_LOCK_UNLOCKED;
static DEFINE_SPINLOCK(callbacks_lock);

/* This function is called by code injected by the compiler, when constructors
 * of static objects are run. The last argument is the __dso_handle of the
 * module from which the call is made. */
int
__cxa_atexit (void (*func) (void *), void *arg, void *d)
{
   struct atexit_fn *afn;

   /* Since the kernel never exits, static objects defined within the
    * kernel image will dever be destroyed. Hence no need to register */
   if (!d)
      return 0;

   afn = kmalloc(sizeof(struct atexit_fn), GFP_KERNEL);
   if (!afn) {
      printk(KERN_ERR "Failed to alloc atexit_fn\n");
      return -1;
   }

   afn->func = func;
   afn->arg = arg;
   afn->d = d;

   spin_lock_irq(&callbacks_lock);
   afn->next = callbacks;
   callbacks = afn;
   spin_unlock_irq(&callbacks_lock);

   return 0;
}
EXPORT_SYMBOL(__cxa_atexit);

/* This is called from crtbeginM.o during module unloading. The argument d
 * is the __dso_handle of the module being unloaded. This calls destructors
 * of static objects defined in the module. */
void
__cxa_finalize (void *d)
{
   struct atexit_fn **p;

   /* See comment in __cxa_atexit */
   BUG_ON(d == NULL);

   spin_lock_irq(&callbacks_lock);
   p = &callbacks;
   while (*p) {
      struct atexit_fn *afn = *p;

      if (afn->d == d) {
         *p = afn->next;
         /* Need to unlock while the destructor is called
          * because the destructor may do funky things */
         spin_unlock_irq(&callbacks_lock);

         (afn->func)(afn->arg);
         kfree(afn);

         spin_lock_irq(&callbacks_lock);
      } else {
         p = &afn->next;
      }
   }
   spin_unlock_irq(&callbacks_lock);
}
EXPORT_SYMBOL(__cxa_finalize);
