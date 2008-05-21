/* commands.c --
   
   Part of: AList
   Contents: command functions
   Date: Mon May  6, 2002
   
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

   $Id: commands.c,v 1.15 2003/09/12 17:46:22 marco Exp $
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

/*SubcommandsTable --
 
   Used to select a subcommand function callback.
*/

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



/* AlistCmd --

	Callback function for the [alist] command.

   Arguments:

	D: unused
	interp: the interp to which the Tcl command belongs
	objc: the number of parameters in the call
	objv: the call parameters

   Results:

	Return TCL_OK or TCL_ERROR

   Side effects:

	none

*/

#ifndef ALIST_ENABLE_NAMESPACE

int
AlistCmd (__TCL_COMMAND_ARGS__)
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
  

  if (objc < 2)
    {
      Tcl_WrongNumArgs(interp, 1, objv, "command ?options?");
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, NULL);
      return TCL_ERROR;
    }

  e = Tcl_GetIndexFromObjStruct(interp, objv[1], tablePtr,
				sizeof(SubcommandsTable), "option",
				TCL_EXACT, &index);
  if (e != TCL_OK)
    {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
      return e;
    }

  return table[index].function(D, interp, objc, objv);
}

#endif


/* AlistAssignCmd --

	Set a new  value for the element associated with  a key Keys are
	all  the even elements.  The value  associated to  a key  is the
	element following it.

   Arguments:

	D: unused
	interp: the interp to which the Tcl command belongs
	objc: the number of parameters in the call
	objv: the call parameters

   Results:

	Return TCL_OK or TCL_ERROR

   Side effects:

	none

*/

int
AlistAssignCmd (__TCL_COMMAND_ARGS__)
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	key;
  Tcl_Obj *	value;


  if (objc != 4+DELTAARG)
    {
      Tcl_WrongNumArgs(interp, NUMARG, objv, "alist key value");
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
      return TCL_ERROR;
    }

  alist = objv[1+DELTAARG];
  key	= objv[2+DELTAARG];
  value = objv[3+DELTAARG];

  e = Alist_ObjAssign(interp, alist, key, value, &alist);
  if (e != TCL_OK)
    {
      return e;
    }

  Tcl_SetObjResult(interp, alist);
  return TCL_OK;
}



/* AlistAtCmd --

	Search a key in a  list and return the corresponding value. Keys
	are all the even elements. The  value associated to a key is the
	element following it.

   Arguments:

	D: unused
	interp: the interp to which the Tcl command belongs
	objc: the number of parameters in the call
	objv: the call parameters

   Results:

	Return TCL_OK or TCL_ERROR

   Side effects:

	none

*/

int
AlistAtCmd (__TCL_COMMAND_ARGS__)
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	key;
  Tcl_Obj *	value;


  if (objc != 3+DELTAARG)
    {
      Tcl_WrongNumArgs(interp, NUMARG, objv, "alist key");
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
      return TCL_ERROR;
    }

  alist = objv[1+DELTAARG];
  key	= objv[2+DELTAARG];

  e = Alist_ObjAt(interp, alist, key, &value);
  if (e != TCL_OK)
    {
      return e;
    }

  Tcl_SetObjResult(interp, value);
  return TCL_OK;
}



/* AlistNamesCmd --

	Return a list holding all the keys in the alist, that is: a list
	holding elements number 0, 2, 4, 6, ...

   Arguments:

	D: unused
	interp: the interp to which the Tcl command belongs
	objc: the number of parameters in the call
	objv: the call parameters

   Results:

	Return TCL_OK or TCL_ERROR.

   Side effects:

	none

*/

int
AlistNamesCmd (__TCL_COMMAND_ARGS__)
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	names;


  if (objc != 2+DELTAARG)
    {
      Tcl_WrongNumArgs(interp, NUMARG, objv, "alist");
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
      return TCL_ERROR;
    }

  alist = objv[1+DELTAARG];

  e = Alist_GetNames(interp, alist, &names);
  if (e != TCL_OK)
    {
      return e;
    }

  Tcl_SetObjResult(interp, names);
  return TCL_OK;
}



/* AlistValuesCmd --

	Return a list holding all the values in the alist, that is: a list
	holding elements number 1, 3, 5, ...

   Arguments:

	D: unused
	interp: the interp to which the Tcl command belongs
	objc: the number of parameters in the call
	objv: the call parameters

   Results:

	Return TCL_OK or TCL_ERROR.

   Side effects:

	none

*/

int
AlistValuesCmd (__TCL_COMMAND_ARGS__)
{
  int		e;
  Tcl_Obj *	alist;
  Tcl_Obj *	values;


  if (objc != 2+DELTAARG)
    {
      Tcl_WrongNumArgs(interp, NUMARG, objv, "alist");
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
      return TCL_ERROR;
    }

  alist = objv[1+DELTAARG];

  e = Alist_GetValues(interp, alist, &values);
  if (e != TCL_OK)
    {
      return e;
    }

  Tcl_SetObjResult(interp, values);
  return TCL_OK;
}



/* AlistVersionCmd --

	Returns the library version.

   Arguments:

	D -		pointer to the interpreter associated data
	interp -	the interp to which the Tcl command belongs
	objc -		the number of parameters in the call
	objv -		the call parameters

   Results:

	Return TCL_OK or TCL_ERROR.

   Side effects:

	none

*/

int
AlistVersionCmd (__TCL_COMMAND_ARGS__)
{
  Tcl_Obj *	objPtr;


  if (objc != 1+DELTAARG)
    {
      Tcl_WrongNumArgs(interp, NUMARG, objv, NULL);
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_WRONG_NUM_ARGS, 0);
      return TCL_ERROR;
    }

  objPtr = Tcl_NewStringObj(QUOTED_VERSION, -1);
  Tcl_SetObjResult(interp, objPtr);
  return TCL_OK;
}


/* end of file */
