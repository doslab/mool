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
# define nameispace namespacex
# define private privatex
# define class classx
# define typename typenamex
# define virtual virtualx
#define true true_bool
#define false false_bool
#define namespace namespacex
//#define bool _Bool
//typedef int _Bool
#include <generated/autoconf.h>
#include <asm/linkage.h>
//extern asmlinkage void asdasd(){}
#endif
