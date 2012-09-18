/*  begin_include.h
 *
 *  Copyright (C) - Reykjavik University 2004
 *  Authors:            Petur Runolfsson
 *  E-mail:     pronto@ru.is
 */

#ifndef CXX_BEGIN_INCLUDE_H_INCLUDED
# define CXX_BEGIN_INCLUDE_H_INCLUDED
#endif

/* Provide defines for C++ keywords that are used as identifiers in
 * kernel headers. Those headers can be included from C++ code if this
 * file is included first. */
#ifdef __cplusplus

extern "C" {

# define new newx
# define namespace namespacex
# define private privatex
# define class classx
# define typename typenamex
# define virtual virtualx
//#define bool boolx

#endif
