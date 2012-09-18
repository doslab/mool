#include<iostream.h>
//this wrapper has the functions which r involved in  the process of migrating a task from a runqueue


extern "C"
{

	#include "sched.c"
}

class migratetask
{
	public:
	//struct prio_array;
	//struct task_struct;
	//struct runqueue;
	int canmigratetask(struct task_struct *p,struct runqueue *rq,int this_cpu,struct sched_domain *sd,enum idle_type idle)
	{	return(can_migrate_task(p,rq,this_cpu,sd,idle));
	}
	void pulltask(runqueue *src_rq, prio_array *src_array, struct task_struct *p,struct runqueue *this_rq, struct prio_array *this_array, int this_cpu )
	{
	pull_task(src_rq,src_array,p,this_rq,this_array,this_cpu);
	}
	void removetaskfromqueue(struct task_struct *p,struct  prio_array *array)
	{
	 	dequeue_task(p,array)
	}
	void addtasktoqueue(struct task_struct *p, prio_array *array)
	{
		enqueue_task(p,array)
	}
	//put the task at the end of runqueue
//	call list_tail
	void appendatendofrunqueue(struct task_struct *p, struct prio_array *array)
	{
	requeue_task(p,array)
	}
};

