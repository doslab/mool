#include<begin_include.h>
#include<linux/spinlock_types.h>
#include<end_include.h>

#ifdef __cplusplus
#ifdef CONFIG_DEBUG_SPINLOCK

extern "C" spinlock_t __SPIN_LOCK_UNLOCKED(spinlock_t lockname)
{
spinlock_t n;
	n.raw_lock = {__RAW_SPIN_LOCK_UNLOCKED};
				n.magic = SPINLOCK_MAGIC;		
				n.owner = SPINLOCK_OWNER_INIT;	
				n.owner_cpu = -1;	
#ifdef CONFIG_DEBUG_LOCK_ALLOC				
				n.dep_map.name=SPIN_DEP_MAP_INIT(lockname); 
#endif
return n;
}


extern "C" rwlock_t __RW_LOCK_UNLOCKED(rwlock_t lockname)
{
rwlock_t t;
t.raw_lock = {__RAW_RW_LOCK_UNLOCKED};	
				t.magic = RWLOCK_MAGIC;			
				t.owner = SPINLOCK_OWNER_INIT;		
				t.owner_cpu = -1;
#ifdef CONFIG_DEBUG_LOCK_ALLOC			
				t.dep_map.name=RW_DEP_MAP_INIT(lockname); 
#endif
return t;

}


#else

extern "C" spinlock_t __SPIN_LOCK_UNLOCKED(spinlock_t lockname)
{
spinlock_t n;
	n.raw_lock = {__RAW_SPIN_LOCK_UNLOCKED};
#ifdef CONFIG_DEBUG_LOCK_ALLOC			
	n.dep_map.name=SPIN_DEP_MAP_INIT(lockname); 
#endif
return n;
}

extern "C" rwlock_t __RW_LOCK_UNLOCKED(rwlock_t lockname)
{
rwlock_t t;
   t.raw_lock.lock = __RAW_RW_LOCK_UNLOCKED;	
#ifdef CONFIG_DEBUG_LOCK_ALLOC			
   t.dep_map.name=RW_DEP_MAP_INIT(lockname); 
#endif
return t;

}
#endif
#endif
