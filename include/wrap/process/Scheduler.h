#include<begin_include.h>
#include<linux/sched.h>
#include<end_include.h>


class Scheduler
{
public:
void schedule(void)
{
schedule();

signed long mool_schedule_timeout_uninterruptible(signed long timeout)
{
schedule_timeout_uninterruptible( timeout);
}

signed long mool_schedule_timeout_interruptible(signed long timeout)
{

schedule_timeout_interruptible(timeout);
}

};
