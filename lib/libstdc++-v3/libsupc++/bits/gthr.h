/*  gthr.h
 *
 *  Copyright (C) - Reykjavik University 2004
 *  Authors:            Petur Runolfsson
 *  E-mail:     pronto@ru.is
 */

#ifndef CXX_BITS_GTHR_H_INCLUDED
#define CXX_BITS_GTHR_H_INCLUDED

/* See gcc/gthr.h in gcc-3.4.0 */

#include <c++/begin_include.h>
#include <linux/spinlock.h>
#include <c++/end_include.h>

#define __GTHREADS 1

typedef spinlock_t __gthread_mutex_t;

#define __gthread_mutex_lock(lock) spin_lock_irq(lock)
#define __gthread_mutex_unlock(lock) spin_unlock_irq(lock)
#define __GTHREAD_MUTEX_INIT SPIN_LOCK_UNLOCKED

typedef struct {
   spinlock_t lock;
   volatile int initialized;
} __gthread_once_t;

#define __GTHREAD_ONCE_INIT { SPIN_LOCK_UNLOCKED, 0 }

#ifdef __cplusplus
extern "C"
#else
static
#endif
inline int __gthread_once(__gthread_once_t *once, void (*func) (void))
{
   if (!once->initialized) {
      spin_lock_irq(&once->lock);

      if (!once->initialized) {
         func();
         once->initialized = 1;
      }

      spin_unlock_irq(&once->lock);
   }
   return 0;
}

#ifdef __cplusplus
extern "C"
#else
static
#endif
inline int __gthread_active_p(void)
{
   return 1;
}

#endif
