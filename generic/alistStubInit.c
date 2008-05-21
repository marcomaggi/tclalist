/* alistStubInit.c --
   
   Part of: AList
   Contents: stub initialisation
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
   
   $Id: alistStubInit.c,v 1.1.1.6 2003/09/12 17:39:50 marco Exp $
*/


#include "alistInt.h"


CONST Alist_StubTable alistStub = {
  Alist_Assign,
  Alist_At,
  Alist_GetNames,
  Alist_GetValues,
  Alist_ObjAssign,
  Alist_ObjAt
};


/* end of file */
