/* init.c --
   
   Part of: Alist
   Contents: initialisation functions
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

   $Id: init.c,v 1.32 2003/09/12 17:34:21 marco Exp $
*/



/** ------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------*/

#include "alistInt.h"


/** ------------------------------------------------------------
 ** Prototypes.
 ** ----------------------------------------------------------*/

EXTERN int	Alist_Init		_ANSI_ARGS_((Tcl_Interp *interp));
EXTERN int	Alist_SafeInit		_ANSI_ARGS_((Tcl_Interp *interp));


/** ------------------------------------------------------------
 ** Global variables.
 ** ----------------------------------------------------------*/

EXTERN CONST Alist_StubTable		alistStub;


/* Alist_Init --

	Initialises the package.

   Arguments:

	interp -	the interpreter in which load the package

   Results:

        Returns TCL_OK or TCL_ERROR.

   Side effects:

        None.

*/

EXTERN int
Alist_Init (Tcl_Interp *interp)
{
  int	e;

#ifdef ALIST_ENABLE_NAMESPACE
  Tcl_Obj *obj;
  static char script[] = "namespace eval alist { namespace export \\[a-z\\]* }";
#endif
  

#ifdef USE_TCL_STUBS
  if (Tcl_InitStubs(interp, "8.2", 0) == NULL) {
    return TCL_ERROR;
  }
#endif

  e = Tcl_PkgProvideEx(interp, "alist", QUOTED_VERSION, (char *)&alistStub);
  if (e != TCL_OK)
    {
      return e;
    }

#ifdef ALIST_ENABLE_NAMESPACE
  obj = Tcl_NewStringObj(script, -1);
  Tcl_IncrRefCount(obj);
  e = Tcl_EvalObjEx(interp, obj, 0);
  Tcl_DecrRefCount(obj);
  if (e != TCL_OK)
    {
      return TCL_ERROR;
    }

  Tcl_CreateObjCommand(interp, "alist::at",	AlistAtCmd,	NULL, NULL);
  Tcl_CreateObjCommand(interp, "alist::assign", AlistAssignCmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "alist::names",	AlistNamesCmd,	NULL, NULL);
  Tcl_CreateObjCommand(interp, "alist::values", AlistValuesCmd, NULL, NULL);
  Tcl_CreateObjCommand(interp, "alist::version",AlistVersionCmd,NULL, NULL);
#else
  Tcl_CreateObjCommand(interp, "alist", AlistCmd, NULL, NULL);
#endif /* defined ALIST_ENABLE_NAMESPACE */

  return TCL_OK;
}

/* Alist_SafeInit --

	Initialise the package for a safe Tcl interp.

   Arguments:

	interp -	the invoking interpreter

   Results:

        Return TCL_OK or TCL_ERROR.

   Side effects:

        none

*/

EXTERN int
Alist_SafeInit(Tcl_Interp *interp)
{
  return Alist_Init (interp);
}

/* end of file */
