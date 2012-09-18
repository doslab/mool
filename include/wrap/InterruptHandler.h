#include <begin_include.h>
#include<linux/interrupt.h>
#include <end_include.h>
class InterruptHandler
{
 
 public:

 /*inserts a interrupt gate in the nth IDT entry*/
 void mool_set_intr_gate(unsigned int n, void *addr)
	{
		set_intr_gate(n,addr);
	}
/*inserts a trap agte in the nth IDT entry*/
 static void mool_set_system_gate(unsigned int n, void *addr)
	{
		set_system_gate(n,addr);
	}
 /* */
 static void mool_set_trap_gate(unsigned int n, void *addr)
	{
		set_trap_gate(n,addr);
	}
/* to insert the final values i.e the function that handle the exception into
all IDT interies  that reffer to nonmaskable interrupts and exception */
void mool_trap_init(void)
	{
		trap_init();
	}
/*sets up the status field of each IRQ*/
 void mool_enable_irq(unsigned int irq)
 	{
		enable_irq(irq);
	}
 void mool_disable_irq(unsigned int irq)
 	{
		disable_irq(irq);
	}
/*invoked to execute all interuppt service routine associated with the interrupt*/
 void mool_do_IRQ(struct pt_regs *regs)
 	{
		 do_IRQ(regs);
	}
/*this function is to remove the descriptor from the IRQ list and release the memory area.*/
 void mool_free_irq(unsigned int irq, void *dev_id)
 	{
		free_irq(irq,dev_id);
	}

};
