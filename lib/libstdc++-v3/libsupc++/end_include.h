/*  end_include.h
 *
 *  Copyright (C) - Reykjavik University 2004
 *  Authors:            Petur Runolfsson
 *  E-mail:     pronto@ru.is
 */

/* This file must always be paired with begin_include.h */
#ifndef CXX_BEGIN_INCLUDE_H_INCLUDED
# error "end_include.h used without begin_include.h"
#endif

#ifdef __cplusplus
# undef new
# undef namespace
# undef private
# undef class
# undef typename
# undef virtual 
//#undef bool
} 
/* extern "C" */

#endif

