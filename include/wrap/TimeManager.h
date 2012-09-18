#include <c++/begin_include.h>
#include<linux/init.h>
#include<linux/time.h>
#include<linux/timer.h>
#include <c++/end_include.h>

class TimerManager
{
public:

  /* -- INITIALIZE --*/
  /* Sets up the date and time during the system startup */
  /*void __init time_init(void)
  {
	time_init();
  }*/

  /* Obtain the CMOS time from the RTC */
 /* unsigned long get_cmos_time(void)
  {
	return(get_cmos_time());
  }*/

  /* Used to determine the actual frequency */
  /*unsigned long __init calibrate_tsc(void)
  {
	return(calibrate_tsc());
  }*/

  /* Obtaining the current time from TSC register */
  void mool_do_gettimeofday (struct timeval *tv)
  {
      do_gettimeofday(tv);
  }



  /* -- UPDATING THE TIMERS -- */
  static inline void mool_update_times(void)
  {
	update_times();
  }




  /* -- UPDATING RESOURCE USAGE STATISTICS -- */
  /* Counts the number of processes in running and uninterruptable states */
  static inline void mool_calc_load(unsigned long ticks)
  {
	calc_load(ticks);
  }

  /* Updates the Kernel Statistics */
  void mool_update_process_times(int user_tick)
  {
	update_process_times(user_tick);
  }




  /* -- DYNAMIC TIMER RELATED FUNCTIONS -- */
  /* Initialises a timer */
  static inline void mool_init_timer(struct timer_list * timer)
  {
	init_timer(timer);
  }

  /* Used to find whether a pending timer is modified or not */
  int mool_mod_timer(struct timer_list *timer, unsigned long expires)
  {
	return(mod_timer(timer,expires));
  }

  /* Adds the timer to the list / Starts the timer */
  static inline void mool_add_timer(struct timer_list * timer)
  {
	add_timer(timer);
  }

  /* Deactivates a timer */
  int mool_del_timer(struct timer_list *timer)
  {
	return(del_timer(timer));
  }

};

