/*
  Part of: TclAList
  Contents: declarations header file
  Date: Mon Aug 18, 2003

  Abstract



  Copyright (c) 2003, 2010 Marco Maggi <marco.maggi-ipsu@poste.it>

  See   the  file   "license.terms"   for  information   on  usage   and
  redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES.
*/

#ifndef __ALISTDECLS_H
#define __ALISTDECLS_H 1


/** ------------------------------------------------------------
 ** Defines.
 ** ----------------------------------------------------------*/

#define ALIST_ERRCODE_INTERNAL_ERROR	"LOGIC INTERNAL_ERROR"
#define ALIST_ERRCODE_WRONG_NUM_ARGS	"LOGIC WRONG_NUM_ARGS"
#define ALIST_ERRCODE_INVALID_ARGUMENT	"LOGIC INVALID_ARGUMENT"


/** ------------------------------------------------------------
 ** Prototypes.
 ** ----------------------------------------------------------*/

#ifndef USE_ALIST_STUBS

EXTERN int	Alist_ObjAssign	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alistPre,
					     Tcl_Obj *key,
					     Tcl_Obj *value,
					     Tcl_Obj **alistPost));

EXTERN int	Alist_Assign	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alistPre,
					     CONST char *CONST key,
					     Tcl_Obj *value,
					     Tcl_Obj **alistPost));

EXTERN int	Alist_ObjAt	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     Tcl_Obj *key,
					     Tcl_Obj **valuePtr));

EXTERN int	Alist_At	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     CONST char *key,
					     Tcl_Obj **valuePtr));

EXTERN int	Alist_GetNames	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     Tcl_Obj **namesPtr));

EXTERN int	Alist_GetValues	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     Tcl_Obj **valuesPtr));

#endif /* no defined USE_ALIST_STUBS */


/** ------------------------------------------------------------
 ** Stub table.
 ** ----------------------------------------------------------*/

typedef struct Alist_StubTable {

int	(*alist_Assign)		_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alistPre,
					     CONST char *CONST key,
					     Tcl_Obj *value,
					     Tcl_Obj **alistPost));

int	(*alist_At)		_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     CONST char *key,
					     Tcl_Obj **valuePtr));

int	(*alist_GetNames)	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     Tcl_Obj **namesPtr));

int	(*alist_GetValues)	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     Tcl_Obj **valuesPtr));

int	(*alist_ObjAssign)	_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alistPre,
					     Tcl_Obj *key,
					     Tcl_Obj *value,
					     Tcl_Obj **alistPost));

int	(*alist_ObjAt)		_ANSI_ARGS_((Tcl_Interp *interp,
					     Tcl_Obj *alist,
					     Tcl_Obj *key,
					     Tcl_Obj **valuePtr));

} Alist_StubTable;


/** ------------------------------------------------------------
 ** Stubs declarations.
 ** ----------------------------------------------------------*/

#ifdef USE_ALIST_STUBS

EXTERN Alist_StubTable *	alistStubPtr;

EXTERN CONST char * Tclalist_InitStubs	_ANSI_ARGS_((Tcl_Interp *interp,
						     char *version,
						     int exact));
/* Declares the macros use to indirectly invoke the ALust functions from
   the stubs table. */

#define Alist_Assign			((alistStubPtr)->alist_Assign)
#define Alist_At			((alistStubPtr)->alist_At)
#define Alist_GetNames			((alistStubPtr)->alist_GetNames)
#define Alist_GetValue			((alistStubPtr)->alist_GetValue)
#define Alist_ObjAssign			((alistStubPtr)->alist_ObjAssign)
#define Alist_ObjAt			((alistStubPtr)->alist_ObjAt)

#endif /* defined USE_ALIST_STUBS */
#endif /* __ALISTDECLS_H */

/* end of file */
