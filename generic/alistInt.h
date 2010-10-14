/*
   Part of: TclAList
   Contents: internal include file
   Date: Sat Apr 27, 2002

   Abstract



   Copyright (c) 2002, 2003, 2010 Marco Maggi <marco.maggi-ipsu@poste.it>

   See   the  file   "license.terms"  for   information  on   usage  and
   redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
*/

#ifndef __ALISTINT_H
#define __ALISTINT_H 1

#include <tcl.h>

#ifdef __cplusplus
extern "C" {
#endif


/** ------------------------------------------------------------
 ** Defines.
 ** ----------------------------------------------------------*/

/* Windows  needs to  know  which  symbols to  export.   Unix does  not.
   BUILD_alist should be undefined for Unix.  */

#ifdef BUILD_alist
#  undef TCL_STORAGE_CLASS
#  define TCL_STORAGE_CLASS DLLEXPORT
#endif

#define __TCL_COMMAND_ARGS__	\
   ClientData D, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]


/** ------------------------------------------------------------
 ** Prototypes.
 ** ----------------------------------------------------------*/

EXTERN int	AlistCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));

EXTERN int	AlistAtCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistAssignCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistNamesCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistValuesCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistVersionCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));


/** ------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------*/

#include "alistDecls.h"


/** ------------------------------------------------------------
 ** Global variables.
 ** ----------------------------------------------------------*/

EXTERN CONST Alist_StubTable	alistStub;

#ifdef __cplusplus
} /* end C++ block */
#endif

#endif /* __ALISTINT_H */

/* end of file */
