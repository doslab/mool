#include<begin_include.h>
 #include <sched.c>
#include<end_include.h>

class loadbal
{
	struct sched_group *	busygroup(struct sched_domain *sd, int this_cpu,unsigned long *imbalance, enum idle_type idle)
	{ 
		return(find_busiest_group(sd,this_cpu,imbalance,idle));
	}
	
	int loadbal(int this_cpu, runqueue_t *this_rq, struct sched_domain *sd, enum idle_type idle)
	{
	 return(load_balance(this_cpu,this_rq, sd, idle));
	}
	static runqueue_t* findbusyqueue(struct sched_group *group)
	{	
	return(find_busiest_queue(struct sched_group *group));
	}
}
