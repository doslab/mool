#include<begin_include.h>
#include<linux/wait.h>
#include<end_include.h>

class WaitQueue
{

public:

 static inline void mool_init_waitqueue_head(wait_queue_head_t *q)
{
init_waitqueue_head(q);
}

static inline void mool_init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
{
init_waitqueue_entry(q,p);
}

void mool_add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
{
 add_wait_queue(q,wait);
}
void fastcall mool_remove_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
{
remove_wait_queue(q, wait);
}

void fastcall __sched mool_sleep_on(wait_queue_head_t *q)
{
 sleep_on(q);
}




 static inline int mool_waitqueue_active(wait_queue_head_t *q)
{
waitqueue_active(q);
}


};


