/* alistInt.c --
   
   Part of: Alist
   Contents: internal include file
   Date: Sat Apr 27, 2002
   
   Abstract
   
   
   
   Copyright (c) 2002, 2003 Marco Maggi
   
   The author hereby grant  permission to use, copy, modify, distribute,
   and  license this  software and  its documentation  for  any purpose,
   provided that  existing copyright notices are retained  in all copies
   and that  this notice is  included verbatim in any  distributions. No
   written agreement, license, or royalty fee is required for any of the
   authorized uses.   Modifications to this software  may be copyrighted
   by their  authors and need  not follow the licensing  terms described
   here, provided that the new  terms are clearly indicated on the first
   page of each file where they apply.
   
   IN NO EVENT  SHALL THE AUTHOR OR DISTRIBUTORS BE  LIABLE TO ANY PARTY
   FOR DIRECT,  INDIRECT, SPECIAL, INCIDENTAL,  OR CONSEQUENTIAL DAMAGES
   ARISING OUT  OF THE USE OF  THIS SOFTWARE, ITS  DOCUMENTATION, OR ANY
   DERIVATIVES  THEREOF, EVEN  IF THE  AUTHOR HAVE  BEEN ADVISED  OF THE
   POSSIBILITY OF SUCH DAMAGE.
   
   THE  AUTHOR AND  DISTRIBUTORS SPECIFICALLY  DISCLAIM  ANY WARRANTIES,
   INCLUDING,   BUT  NOT   LIMITED   TO,  THE   IMPLIED  WARRANTIES   OF
   MERCHANTABILITY,    FITNESS   FOR    A   PARTICULAR    PURPOSE,   AND
   NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, AND
   THE   AUTHOR  AND   DISTRIBUTORS  HAVE   NO  OBLIGATION   TO  PROVIDE
   MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
   
   $Id: alistInt.h,v 1.20 2003/09/12 17:43:42 marco Exp $
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

/*
  Windows  needs  to know  which  symbols  to  export.  Unix  does  not.
  BUILD_alist should be undefined for Unix.
*/

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
