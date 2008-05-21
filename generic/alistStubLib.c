/* alistStubLib.c --
   
   Part of: AList
   Contents: stubs library
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
   
   $Id: alistStubLib.c,v 1.1.1.2 2003/09/12 17:39:29 marco Exp $
*/



/** ------------------------------------------------------------
 ** Header files.
 ** ----------------------------------------------------------*/

#ifndef USE_TCL_STUBS
#  define USE_TCL_STUBS
#endif
#undef USE_TCL_STUB_PROCS

#include "alistInt.h"

#undef TCL_STORAGE_CLASS
#define TCL_STORAGE_CLASS DLLEXPORT



/** ------------------------------------------------------------
 ** Global variables.
 ** ----------------------------------------------------------*/

Alist_StubTable *	alistStubPtr = NULL;



/* Alist_InitStubs --

	Checks that the  correct version of ALIST is  loaded and that it
	supports stubs; then it initialises the stub table pointer.

   Arguments:

	interp -	the interpreter
	version -	pointer to a string representing the requested
			version
	exact -		a flag indicating if the version number should
			match exactly the one of the extension

   Results:

        Returns  a  string  representing   the  actual  version  of  the
        extension  that satisfies  the request,  or NULL  to  indicat an
        error.

   Side effects:

        Initialises the stubs table pointer.

*/

CONST char *
Alist_InitStubs (Tcl_Interp *interp, char *version, int exact)
{
  CONST char *	v;


  v = Tcl_PkgRequireEx(interp, "alist", version, exact,
		       (ClientData *) &alistStubPtr);
  if (v == NULL)
    {
      return v;
    }

  if (alistStubPtr == NULL)
    {
      Tcl_SetResult(interp, "this version of alist doesn't support stubs",
		    TCL_STATIC);
      return NULL;
    }
  return v;
}


/* end of file */
