// -*- C++ -*- Exception handling routines for throwing.
// Copyright (C) 2001, 2003 Free Software Foundation, Inc.
//
// This file is part of GCC.
//
// GCC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GCC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GCC; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.


#include <bits/c++config.h>
#include "unwind-cxx.h"


using namespace __cxxabiv1;


static void
__gxx_exception_cleanup (_Unwind_Reason_Code code, _Unwind_Exception *exc)
{
  __cxa_exception *header = __get_exception_header_from_ue (exc);

  // If we haven't been caught by a foreign handler, then this is
  // some sort of unwind error.  In that case just die immediately.
  // _Unwind_DeleteException in the HP-UX IA64 libunwind library
  //  returns _URC_NO_REASON and not _URC_FOREIGN_EXCEPTION_CAUGHT
  // like the GCC _Unwind_DeleteException function does.
  if (code != _URC_FOREIGN_EXCEPTION_CAUGHT && code != _URC_NO_REASON)
    __terminate (header->terminateHandler);

  if (header->exceptionDestructor)
    header->exceptionDestructor (header + 1);

  __cxa_free_exception (header + 1);
}


extern "C" 
{
struct dwarf_eh_bases
{
  void *tbase;
  void *dbase;
  void *func;
};
struct _Unwind_Context
{
  void *reg[17 +1];
  void *cfa;
  void *ra;
  void *lsda;
  struct dwarf_eh_bases bases;
  _Unwind_Word args_size;
};
 void
uw_init_context_1 (struct _Unwind_Context *context,
                   void *outer_cfa, void *outer_ra);

#define uw_init_context(CONTEXT)					   \
  do									   \
    {									   \
      /* Do any necessary initialization to access arbitrary stack frames. \
	 On the SPARC, this means flushing the register windows.  */	   \
      __builtin_unwind_init ();						   \
      uw_init_context_1 (CONTEXT, __builtin_dwarf_cfa (),		   \
			 __builtin_return_address (0));			   \
    }									   \
  while (0)
  
typedef struct
{


  struct frame_state_reg_info
  {
    struct {
      union {
        _Unwind_Word reg;
        _Unwind_Sword offset;
        const unsigned char *exp;
      } loc;
      enum {
        REG_UNSAVED,
        REG_SAVED_OFFSET,
        REG_SAVED_REG,
        REG_SAVED_EXP
      } how;
    } reg[17 +1];


    struct frame_state_reg_info *prev;
  } regs;



  _Unwind_Sword cfa_offset;
  _Unwind_Word cfa_reg;
  const unsigned char *cfa_exp;
  enum {
    CFA_UNSET,
    CFA_REG_OFFSET,
    CFA_EXP
  } cfa_how;


  void *pc;


  _Unwind_Personality_Fn personality;
  _Unwind_Sword data_align;
  _Unwind_Word code_align;
  unsigned char retaddr_column;
  unsigned char fde_encoding;
  unsigned char lsda_encoding;
  unsigned char saw_z;
  void *eh_ptr;
} _Unwind_FrameState;
 _Unwind_Reason_Code
uw_frame_state_for (struct _Unwind_Context *context, _Unwind_FrameState **fs);  

 void
uw_update_context (struct _Unwind_Context *context, _Unwind_FrameState *fs);
 __inline__ __attribute__((always_inline)) _Unwind_Ptr
uw_identify_context (struct _Unwind_Context *context);

#define uw_install_context(CURRENT, TARGET)				 \
  do									 \
    {									 \
      long offset = uw_install_context_1 ((CURRENT), (TARGET));		 \
      void *handler = __builtin_frob_return_addr ((TARGET)->ra);	 \
      __builtin_eh_return (offset, handler);				 \
    }									 \
  while (0)

 long
uw_install_context_1 (struct _Unwind_Context *myCurrent,
                      struct _Unwind_Context *target);
 _Unwind_Reason_Code
_Unwind_RaiseException_Phase2(struct _Unwind_Exception *exc,
			      struct _Unwind_Context *context);                      
}

 static inline  _Unwind_Reason_Code
_Unwind_RaiseException_In_One_Phase(struct _Unwind_Exception *exc) __attribute__ ((always_inline));
 
static inline  _Unwind_Reason_Code
_Unwind_RaiseException_In_One_Phase(struct _Unwind_Exception *exc)  
{
//	 
  struct _Unwind_Context this_context, cur_context;
  _Unwind_Reason_Code code;
  
  /* Set up this_context to describe the current stack frame.  */
 uw_init_context (&this_context);
  cur_context = this_context;

  /* Phase 1: Search.  Unwind the stack, calling the personality routine
     with the _UA_SEARCH_PHASE flag set.  Do not modify the stack yet.  */
  while (1)
    {
      _Unwind_FrameState *fs;
      //count++;
     // printk("Count nr: %u \n", count);
      /* Set up fs to describe the FDE for the caller of cur_context.  The
	 first time through the loop, that means __cxa_throw.  */
      code = uw_frame_state_for (&cur_context, &fs);

      if (code == _URC_END_OF_STACK)
	/* Hit end of stack with no handler found.  */
	return _URC_END_OF_STACK;

      if (code != _URC_NO_REASON)
	/* Some error encountered.  Ususally the unwinder doesn't
	   diagnose these and merely crashes.  */
	return _URC_FATAL_PHASE1_ERROR;

      /* Unwind successful.  Run the personality routine, if any.  */
      if (fs->personality)
	{
	  code = (*fs->personality) (1, _UA_CLEANUP_PHASE, exc->exception_class,
				    exc, &cur_context);
	  if (code == _URC_INSTALL_CONTEXT)
	    break;
	  else if (code != _URC_CONTINUE_UNWIND)
	    return _URC_FATAL_PHASE1_ERROR;
	}

      /* Update cur_context to describe the same frame as fs.  */
      uw_update_context (&cur_context, fs);
    }

  /* Indicate to _Unwind_Resume and associated subroutines that this
     is not a forced unwind.  Further, note where we found a handler.  */
   if (code != _URC_INSTALL_CONTEXT)
    return code;

  uw_install_context (&this_context, &cur_context);


  // Some sort of unwinding error.  Note that terminate is a handler.
  __cxa_begin_catch (exc);
  std::terminate ();
} 


extern "C" void
__cxa_throw (void *obj, std::type_info *tinfo, void (*dest) (void *))
{
  struct _Unwind_Exception *exc;
  struct _Unwind_Context this_context, cur_context;
  _Unwind_Reason_Code code;
  
  __cxa_exception *header = __get_exception_header_from_obj (obj);
  header->exceptionType = tinfo;
  header->exceptionDestructor = dest;
  header->unexpectedHandler = __unexpected_handler;
  header->terminateHandler = __terminate_handler;
  header->unwindHeader.exception_class = __gxx_exception_class;
  header->unwindHeader.exception_cleanup = __gxx_exception_cleanup;


  __cxa_eh_globals *globals = __cxa_get_globals ();
  globals->uncaughtExceptions += 1;


#ifdef _GLIBCXX_SJLJ_EXCEPTIONS
  _Unwind_SjLj_RaiseException (&header->unwindHeader);
#else
  //INLINE THE METHOD TO SAVE ONE!!!
_Unwind_RaiseException_In_One_Phase(&header->unwindHeader);
#endif
}

void
_Unwind_Resume (struct _Unwind_Exception *exc)
{
  struct _Unwind_Context this_context, cur_context;
  _Unwind_Reason_Code code;
_Unwind_RaiseException_In_One_Phase(exc);
 
}


extern "C" void
__cxa_rethrow ()
{
  __cxa_eh_globals *globals = __cxa_get_globals ();
  __cxa_exception *header = globals->caughtExceptions;

  // Watch for luser rethrowing with no active exception.
  if (header)
    {
      // Tell __cxa_end_catch this is a rethrow.
      if (header->unwindHeader.exception_class != __gxx_exception_class)
	globals->caughtExceptions = 0;
      else
	header->handlerCount = -header->handlerCount;

#ifdef _GLIBCXX_SJLJ_EXCEPTIONS
      _Unwind_SjLj_Resume_or_Rethrow (&header->unwindHeader);
#else
#ifdef _LIBUNWIND_STD_ABI
      _Unwind_RaiseException_In_One_Phase (&header->unwindHeader);
#else
      _Unwind_RaiseException_In_One_Phase (&header->unwindHeader);
#endif
#endif
  
      // Some sort of unwinding error.  Note that terminate is a handler.
      __cxa_begin_catch (&header->unwindHeader);
    }
  std::terminate ();
}
