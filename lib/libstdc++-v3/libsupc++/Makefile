#
# Makefile for C++ runtime library (libsupc++)
# libsupc++ is imported from gcc-3.4.0
#

#CXX	=	g++
EXTRA_CXXFLAGS	+= -I$(srctree)/include/c++ -I$(src)/../../gcc -include $(src)/../../gcc/fixdefines.h



#obj-y += test/

obj-$(CONFIG_CXX_RUNTIME)	+= libsupcxx.o

libsupcxx-objs	:= del_op.o del_opnt.o del_opv.o del_opvnt.o \
	eh_alloc.o eh_aux_runtime.o eh_catch.o eh_exception.o eh_globals.o \
	eh_personality.o \
	eh_terminate.o eh_throw.o eh_term_handler.o

libsupcxx-objs	+= eh_type.o eh_unex_handler.o guard.o new_handler.o new_op.o \
	           new_opnt.o new_opv.o new_opvnt.o pure.o tinfo2.o tinfo.o vec.o \
	           libsupcxx_syms.o
