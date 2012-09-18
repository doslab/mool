#include<iostream.h>
//the functions required for load balancing

extern "C"
{
 	#include "sched.c"
}
class loadbal
{
	struct sched_group *	mool_find_busiest_group(struct sched_domain *sd, int this_cpu,unsigned long *imbalance, enum idle_type idle)
	{ 
		return(find_busiest_group(sd,this_cpu,imbalance,idle));
	}
	
	int mool_load_balance(int this_cpu, runqueue_t *this_rq, struct sched_domain *sd, enum idle_type idle)
	{
	 return(load_balance(this_cpu,this_rq, sd, idle));
	}
	static runqueue_t* mool_find_busiest_queue(struct sched_group *group)
	{	
	return(find_busiest_queue(struct sched_group *group));
	}
}
