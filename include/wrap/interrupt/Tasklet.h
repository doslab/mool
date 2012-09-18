#include<begin_include.h>
#include<linux/interrupt.h>
#include<end_include.h>


class Tasklet
{
 public:

  void mool_tasklet_init(struct tasklet_struct *t, void (*func)(unsigned long), unsigned long data)
   {
     tasklet_init(t, func, data);
   }


  static inline void mool_tasklet_disable_nosync(struct tasklet_struct *t)
    {
      tasklet_disable_nosync(t);
    }


  static inline void mool_tasklet_disable(struct tasklet_struct *t)
    { 
      tasklet_disable(t);
    }

    
  static inline void mool_tasklet_enable(struct tasklet_struct *t)
    {
      tasklet_enable(t);
    }


  static inline void mool_tasklet_schedule(struct tasklet_struct *t)
    {
      tasklet_schedule(t);
    }


  static inline void mool_tasklet_hi_schedule(struct tasklet_struct *t)
    {
      tasklet_hi_schedule(t);
    }


  static inline void mool_tasklet_hi_enable(struct tasklet_struct *t)
    {
      tasklet_hi_enable(t);
    }


}
