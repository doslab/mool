#include <begin_include.h>
#include<linux/mm.h>
#include<linux/sched.h>

#include <end_include.h>

class pgd
{

 public:

 /*all returns 1 if the coresponding entry does not exist*/
 static inline int mool_pgd_none(pgd_t pgd)
 {
 	return(pgd_none(pgd));
 }
 /*all returns 1 if the corresponding  table entries have present bit set*/
 static inline int mool_pgd_present(pgd_t pgd)
 {
	return(pgd_present(pgd));
 }
 
 /**/
 pgd_t *mool_pgd_alloc(struct mm_struct *mm)
 {
 	return(pgd_alloc(mm));

 }
 /**/
 void mool_pgd_free(pgd_t *pgd)
 {
 	pgd_free(pgd);
 }
 /**/
 static inline pgd_t *mool_pgd_alloc_one_fast(struct mm_struct *mm)
 {
	return(pgd_alloc_one_fast(mm));
 }

};
