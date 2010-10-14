/*
  Part of: TclAList
  Contents: command functions
  Date: Mon May  6, 2002

  Abstract



  Copyright (c) 2002, 2003, 2010 Marco Maggi <marco.maggi-ipsu@poste.it>

  See   the  file   "license.terms"   for  information   on  usage   and
  redistribution of this  file, and for a DISCLAIMER  OF ALL WARRANTIES.
*/


/** ------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------*/

#ifndef ALIST_STUBS_TEST
#  include "alistInt.h"
#else
#  include "alistTest.h"
#endif


/** ------------------------------------------------------------
 ** Defines.
 ** ----------------------------------------------------------*/

#ifdef ALIST_ENABLE_NAMESPACE
#  define	NUMARG		1
#  define	DELTAARG	0
#else
#  define	NUMARG		2
#  define	DELTAARG	1
#endif


/** ------------------------------------------------------------
 ** Typedefs.
 ** ----------------------------------------------------------*/

/* Used to select a subcommand function callback. */

typedef struct SubcommandsTable {
  char *name;
  int (*function) _ANSI_ARGS_((__TCL_COMMAND_ARGS__));
} SubcommandsTable;


/** ------------------------------------------------------------
 ** Prototypes.
 ** ----------------------------------------------------------*/

#ifdef ALIST_STUBS_TEST

EXTERN int	AlistCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));

EXTERN int	AlistAtCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistAssignCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistNamesCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistValuesCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));
EXTERN int	AlistVersionCmd	_ANSI_ARGS_((__TCL_COMMAND_ARGS__));

#endif


#if (0 == ALIST_ENABLE_NAMESPACE)

int
AlistCmd (__TCL_COMMAND_ARGS__)
/* Callback  function  for  the   [alist]  command.   Return  TCL_OK  or
   TCL_ERROR. */
{
  int	e;
  int	index;
  static CONST SubcommandsTable table[] = {
    { "at",		AlistAtCmd },
    { "assign",		AlistAssignCmd },
    { "names",		AlistNamesCmd },
    { "values",		AlistValuesCmd },
    { "version",	AlistVersionCmd },
    { NULL,		NULL }
  };
  static CONST SubcommandsTable *tablePtr = table;

  if (objc < 2) {
    Tcl_WrongNumArgs(interp, 1, objv, "command ?options?");
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, NULL);
    return TCL_ERROR;
  }
  e = Tcl_GetIndexFromObjStruct(interp, objv[1], tablePtr, sizeof(SubcommandsTable), "option",
				TCL_EXACT, &index);
  if (e != TCL_OK) {
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    return e;
  }
  return table[index].function(D, interp, objc, objv);
}

#endif


int
AlistAssignCmd (__TCL_COMMAND_ARGS__)
/* Set a new value for the  element associated with a key.  Keys are all
   the  even elements.  The  value associated  to a  key is  the element
   following it.  Return TCL_OK or TCL_ERROR. */
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	key;
  Tcl_Obj *	value;
  if (objc != 4+DELTAARG) {
    Tcl_WrongNumArgs(interp, NUMARG, objv, "alist key value");
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
    return TCL_ERROR;
  }
  alist = objv[1+DELTAARG];
  key	= objv[2+DELTAARG];
  value = objv[3+DELTAARG];
  e = Alist_ObjAssign(interp, alist, key, value, &alist);
  if (TCL_OK != e) return e;
  Tcl_SetObjResult(interp, alist);
  return TCL_OK;
}


int
AlistAtCmd (__TCL_COMMAND_ARGS__)
/* Search a  key in a list and  set the TCL result  to the corresponding
   value.  Keys  are all the even  elements.  The value  associated to a
   key is the element following it.  Return TCL_OK or TCL_ERROR. */
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	key;
  Tcl_Obj *	value;
  if (objc != 3+DELTAARG) {
    Tcl_WrongNumArgs(interp, NUMARG, objv, "alist key");
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
    return TCL_ERROR;
  }
  alist = objv[1+DELTAARG];
  key	= objv[2+DELTAARG];
  e = Alist_ObjAt(interp, alist, key, &value);
  if (TCL_OK != e) return e;
  Tcl_SetObjResult(interp, value);
  return TCL_OK;
}


int
AlistNamesCmd (__TCL_COMMAND_ARGS__)
/* Set the TCL result to a list  holding all the keys in the alist, that
   is: a list holding elements number  0, 2, 4, 6, ...  Return TCL_OK or
   TCL_ERROR. */
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	names;
  if (objc != 2+DELTAARG) {
    Tcl_WrongNumArgs(interp, NUMARG, objv, "alist");
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
    return TCL_ERROR;
  }
  alist = objv[1+DELTAARG];
  e = Alist_GetNames(interp, alist, &names);
  if (TCL_OK != e) return e;
  Tcl_SetObjResult(interp, names);
  return TCL_OK;
}


int
AlistValuesCmd (__TCL_COMMAND_ARGS__)
/* Set the  TCL result to  a list holding  all the values in  the alist,
   that is: a  list holding elements number 1, 3,  5, ...  Return TCL_OK
   or TCL_ERROR. */
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	values;
  if (objc != 2+DELTAARG) {
    Tcl_WrongNumArgs(interp, NUMARG, objv, "alist");
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
    return TCL_ERROR;
  }
  alist = objv[1+DELTAARG];
  e = Alist_GetValues(interp, alist, &values);
  if (TCL_OK != e) return e;
  Tcl_SetObjResult(interp, values);
  return TCL_OK;
}


int
AlistVersionCmd (__TCL_COMMAND_ARGS__)
/* Set  the  TCL  result  to  the library  version.   Return  TCL_OK  or
   TCL_ERROR. */
{
  Tcl_Obj *	objPtr;


  if (objc != 1+DELTAARG)
    {
      Tcl_WrongNumArgs(interp, NUMARG, objv, NULL);
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
      return TCL_ERROR;
    }

  objPtr = Tcl_NewStringObj(PACKAGE_VERSION, -1);
  Tcl_SetObjResult(interp, objPtr);
  return TCL_OK;
}

/* end of file */
