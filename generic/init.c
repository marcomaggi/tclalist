/*
  Part of: TclAList
  Contents: initialisation functions
  Date: Sat Apr 27, 2002

  Abstract



  Copyright (c) 2002, 2003, 2010 Marco Maggi <marco.maggi-ipsu@poste.it>

  See   the  file   "license.terms"   for  information   on  usage   and
  redistribution of this  file, and for a DISCLAIMER  OF ALL WARRANTIES.
*/


/** ------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------*/

#include "alistInt.h"


/** ------------------------------------------------------------
 ** Prototypes.
 ** ----------------------------------------------------------*/

EXTERN int	Tclalist_Init		_ANSI_ARGS_((Tcl_Interp *interp));
EXTERN int	Tclalist_SafeInit	_ANSI_ARGS_((Tcl_Interp *interp));


/** ------------------------------------------------------------
 ** Global variables.
 ** ----------------------------------------------------------*/

EXTERN CONST Alist_StubTable		alistStub;


EXTERN int
Tclalist_Init (Tcl_Interp *interp)
{
  if (NULL == Tcl_InitStubs(interp, "8.5", 0)) {
    return TCL_ERROR;
  }
  if (NULL == Tcl_PkgRequire(interp, "Tcl", "8.5", 0)) {
    return TCL_ERROR;
  }
  if (TCL_OK != Tcl_PkgProvideEx(interp, PACKAGE_NAME, PACKAGE_VERSION, (char *)&alistStub)) {
    return TCL_ERROR;
  }
  if (ALIST_ENABLE_NAMESPACE) {
    int		e;
    Tcl_Obj *	obj;
    static char script[] = "namespace eval alist { namespace export \\[a-z\\]* }";

    obj = Tcl_NewStringObj(script, -1);
    Tcl_IncrRefCount(obj);
    e = Tcl_EvalObjEx(interp, obj, 0);
    Tcl_DecrRefCount(obj);
    if (TCL_OK != e)
      return TCL_ERROR;
    Tcl_CreateObjCommand(interp, "alist::at",     AlistAtCmd,     NULL, NULL);
    Tcl_CreateObjCommand(interp, "alist::assign", AlistAssignCmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, "alist::names",  AlistNamesCmd,  NULL, NULL);
    Tcl_CreateObjCommand(interp, "alist::values", AlistValuesCmd, NULL, NULL);
    Tcl_CreateObjCommand(interp, "alist::version",AlistVersionCmd,NULL, NULL);
  } else {
    Tcl_CreateObjCommand(interp, "alist", AlistCmd, NULL, NULL);
  }
  return TCL_OK;
}

EXTERN int
Tclalist_SafeInit(Tcl_Interp *interp)
{
  return Tclalist_Init (interp);
}

/* end of file */
