#
# Makefile for C++ runtime library (libgcc)
#

LIBGCC_CFLAGS := -Dinhibit_libc  -DIN_GCC \
	-static  -I$(src)/../../include/c++/bits \
	-I$(src)/../../include/asm/gcc -I$(src)/../../include/gcc \
	-include $(src)/fixdefines.h -I$(src)

ifeq ($(build_crt),1)
include $(src)/Makefile.crt
else

EXTRA_CFLAGS	+= -fexceptions $(LIBGCC_CFLAGS)

obj-$(CONFIG_CXX_RUNTIME)	+= libgcc.o

libgcc-objs	+= unwind-dw2.o unwind-dw2-fde.o libgcc_syms.o

endif # not build_crt
