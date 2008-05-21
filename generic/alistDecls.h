/* alistDecls.h --
   
   Part of: AList
   Contents: declarations header file
   Date: Mon Aug 18, 2003
   
   Abstract
   
   
   
   Copyright (c) 2003 Marco Maggi
   
   The author  hereby grant permission to use,  copy, modify, distribute,
   and  license this  software  and its  documentation  for any  purpose,
   provided that  existing copyright notices  are retained in  all copies
   and that  this notice  is included verbatim  in any  distributions. No
   written agreement, license, or royalty  fee is required for any of the
   authorized uses.  Modifications to this software may be copyrighted by
   their authors and need not  follow the licensing terms described here,
   provided that the new terms are clearly indicated on the first page of
   each file where they apply.
   
   IN NO  EVENT SHALL THE AUTHOR  OR DISTRIBUTORS BE LIABLE  TO ANY PARTY
   FOR  DIRECT, INDIRECT, SPECIAL,  INCIDENTAL, OR  CONSEQUENTIAL DAMAGES
   ARISING OUT  OF THE  USE OF THIS  SOFTWARE, ITS DOCUMENTATION,  OR ANY
   DERIVATIVES  THEREOF, EVEN  IF THE  AUTHOR  HAVE BEEN  ADVISED OF  THE
   POSSIBILITY OF SUCH DAMAGE.
   
   THE  AUTHOR  AND DISTRIBUTORS  SPECIFICALLY  DISCLAIM ANY  WARRANTIES,
   INCLUDING,   BUT   NOT  LIMITED   TO,   THE   IMPLIED  WARRANTIES   OF
   MERCHANTABILITY,    FITNESS   FOR    A    PARTICULAR   PURPOSE,    AND
   NON-INFRINGEMENT.  THIS  SOFTWARE IS PROVIDED  ON AN "AS  IS" BASIS,
   AND  THE  AUTHOR  AND  DISTRIBUTORS  HAVE  NO  OBLIGATION  TO  PROVIDE
   MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
   
   $Id: alistDecls.h,v 1.1.1.6 2003/09/12 17:37:52 marco Exp $
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

EXTERN CONST char *	Alist_InitStubs	_ANSI_ARGS_((Tcl_Interp *interp,
						     char *version,
						     int exact));
/*
  Declares the macros use to  indirectly invoke the ALust functions from
  the stubs table.
*/

#define Alist_Assign			((alistStubPtr)->alist_Assign)
#define Alist_At			((alistStubPtr)->alist_At)
#define Alist_GetNames			((alistStubPtr)->alist_GetNames)
#define Alist_GetValue			((alistStubPtr)->alist_GetValue)
#define Alist_ObjAssign			((alistStubPtr)->alist_ObjAssign)
#define Alist_ObjAt			((alistStubPtr)->alist_ObjAt)


#endif /* defined USE_ALIST_STUBS */


#endif /* __ALISTDECLS_H */


/* end of file */
