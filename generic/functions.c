/*
  Part of: TclAList
  Contents: alist functions
  Date: Mon May  6, 2002

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

static CONST char **	Alist_MakeKeyVector _ANSI_ARGS_((Tcl_Obj **objs, int length));


/* Alist_ObjAssign --

	Sets a new value for the element associated with a key.

   Arguments:

	interp -	if not NULL, the interpreter in which
			report errors
	alistPre -	pointer to the source alist
	keyObj -	pointer to an object holding the key
	valueObj -	pointer to an object holding the value
	alistPost -	pointer to a variable that will hold the
			modified alist

   Results:

        Returns TCL_OK or TCL_ERROR.

   Side effects:

        If  shared the  alist is  duplicated, the  object  referenced by
        alistPost has  refCount equal to  that of *alistPre or  equal to
        zero.

*/

int
Alist_ObjAssign (interp, alistPre, keyObj, valueObj, alistPost)
     Tcl_Interp *	interp;
     Tcl_Obj *		alistPre;
     Tcl_Obj *		keyObj;
     Tcl_Obj *		valueObj;
     Tcl_Obj **		alistPost;
{
  int		e, i, alistLen;
  Tcl_Obj *	alistObj;
  Tcl_Obj **	alistObjVector;
  CONST char **	keys;

  alistObj = alistPre;
  if (Tcl_IsShared(alistObj)) {
    alistObj = Tcl_DuplicateObj(alistObj);
  }
  e = Tcl_ListObjGetElements(interp, alistObj, &alistLen, &alistObjVector);
  if (TCL_OK != e) {
    if (NULL != interp) {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    }
    goto error;
  }
  keys = Alist_MakeKeyVector(alistObjVector, alistLen);
  e = Tcl_GetIndexFromObj(interp, keyObj, keys, "key", 0, &i);
  ckfree((char *) keys);
  if (TCL_OK != e) {
    if (NULL != interp) {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    }
    goto error;
  }

  /* Store the element. */

  i *= 2;
  if (i == alistLen)
    {
      if (interp != NULL)
	{
	  Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
	  Tcl_SetResult(interp, "too few elements in list", TCL_STATIC);
	}
      goto error;
    }

  e = Tcl_ListObjReplace(interp, alistObj, i+1, 1, 1, &valueObj);
  if (TCL_OK != e) {
    Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    goto error;
  }

  /* The result is the new list. */
  *alistPost = alistObj;
  return TCL_OK;

 error:
  Tcl_IncrRefCount(alistObj);
  Tcl_DecrRefCount(alistObj);
  return TCL_ERROR;
}


/* Alist_Assign --

	Sets a new value for the element associated with a key.

   Arguments:

	interp -	if not NULL, the interpreter in which
			report errors
	alistPre -	pointer to the list of objects
	key -		pointer to the string holding the key
	value -		pointer to the object holding the new value
	alistPost -	pointer to a target variable that will hold
			the new alist

   Results:

        Returns TCL_OK or TCL_ERROR.

   Side effects:

        If  shared the  alist is  duplicated, the  object  referenced by
        alistPost has  refCount equal to  that of *alistPre or  equal to
        zero.

*/

int
Alist_Assign (interp, alistPre, key, valueObj, alistPost)
     Tcl_Interp *	interp;
     Tcl_Obj *		alistPre;
     CONST char *	key;
     Tcl_Obj *		valueObj;
     Tcl_Obj **		alistPost;
{
  int		e;
  Tcl_Obj *	keyObj;
  keyObj = Tcl_NewStringObj(key, -1);
  Tcl_IncrRefCount(keyObj);
  e = Alist_ObjAssign(interp, alistPre, keyObj, valueObj, alistPost);
  Tcl_DecrRefCount(keyObj);
  return e;
}



/* Alist_ObjAt --

	Extracts the value associated to a given key.

   Arguments:

	interp -	if not NULL, the interpreter used to
			report errors
	alistObj -	pointer to the alist object
	keyObj -	pointer to the key object
	valueObjPtr -	pointer to the target variable that will hold
			the selecte object's pointer

   Results:

        Returns TCL_OK or TCL_ERROR if the key is not present.

   Side effects:

        The result object has reference counter untouched.

*/

int
Alist_ObjAt (interp, alistObj, keyObj, valueObjPtr)
     Tcl_Interp	*	interp;
     Tcl_Obj *		alistObj;
     Tcl_Obj *		keyObj;
     Tcl_Obj **		valueObjPtr;
{
  int		e, i, alistLen;
  Tcl_Obj **	alistObjVector;
  CONST char **	keys;


  e = Tcl_ListObjGetElements(interp, alistObj, &alistLen, &alistObjVector);
  if (TCL_OK != e) {
    if (NULL != interp) {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    }
    return e;
  }

  keys = Alist_MakeKeyVector(alistObjVector, alistLen);
  e = Tcl_GetIndexFromObj(interp, keyObj, keys, "key", 0, &i);
  Tcl_Free((char *) keys);
  if (TCL_OK != e) {
    if (NULL != interp) {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    }
    return e;
  }
  *valueObjPtr = alistObjVector[2*i+1];
  return TCL_OK;
}


/* Alist_At --

	Extracts the value associated to a given key.

   Arguments:

	interp -	if not NULL, the interpreter in which
			report errors
	alistObj -	pointer to the list of objects
	key -		pointer to the key string
	valueObjPtr -	pointer to the target variable that will hold
			the selecte object's pointer

   Results:

        Returns TCL_OK or TCL_ERROR.

   Side effects:

        If  shared the  alist is  duplicated, the  object  referenced by
        alistPost has  refCount equal to  that of *alistPre or  equal to
        zero.

*/

int
Alist_At (interp, alistObj, key, valueObjPtr)
     Tcl_Interp *	interp;
     Tcl_Obj *		alistObj;
     CONST char *CONST	key;
     Tcl_Obj **		valueObjPtr;
{
  int		e;
  Tcl_Obj *	keyObj;
  keyObj = Tcl_NewStringObj(key, -1);
  Tcl_IncrRefCount(keyObj);
  e = Alist_ObjAt(interp, alistObj, keyObj, valueObjPtr);
  Tcl_DecrRefCount(keyObj);
  return e;
}



/* Alist_GetNames --

	Extracts all the key objects from an alist.

   Arguments:

	interp -	if not NULL, the interp used to report errors
	alistObj -	poitner to the alist object
	namesObjPtr -	pointer to a target variable that will hold
			the result

   Results:

        Returns TCL_OK or TCL_ERROR.

   Side effects:

        The result object has refCount left to zero.

*/

int
Alist_GetNames (interp, alistObj, namesObjPtr)
     Tcl_Interp *	interp;
     Tcl_Obj *		alistObj;
     Tcl_Obj **		namesObjPtr;
{
  int		e, i, alistLen;
  Tcl_Obj *	namesObj;
  Tcl_Obj **	alistObjVector;


  e = Tcl_ListObjGetElements(interp, alistObj, &alistLen, &alistObjVector);
  if (TCL_OK != e) {
    if (NULL != interp) {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    }
    return e;
  }

  namesObj = Tcl_NewListObj(0, 0);
  if (alistLen % 2) --alistLen;
  for (i=0; i<alistLen; i+=2) {
    e = Tcl_ListObjAppendElement(interp, namesObj, alistObjVector[i]);
    if (TCL_OK != e) {
      if (NULL != interp) {
	Tcl_SetErrorCode(interp, ALIST_ERRCODE_INTERNAL_ERROR, NULL);
      }
      goto error;
    }
  }

  *namesObjPtr = namesObj;
  return TCL_OK;

 error:
  Tcl_IncrRefCount(namesObj);
  Tcl_DecrRefCount(namesObj);
  return TCL_ERROR;
}




/* Alist_GetValues --

   	Extracts all  the values in the  alist, that is:  a list holding
   	elements number 1, 3, 5, ...

   Arguments:

	interp -	if not NULL, the interpreter used to
			report errors
	alistObj -	pointer to the alist object
	valuesObjPtr -	pointer to a target variable that will hold
			the result

   Results:

        Returns TCL_OK or TCL_ERROR.

   Side effects:

        The result object has refCount left to zero.

*/

int
Alist_GetValues (interp, alistObj, valuesObjPtr)
     Tcl_Interp *	interp;
     Tcl_Obj *		alistObj;
     Tcl_Obj **		valuesObjPtr;
{
  int		e, i, alistLen;
  Tcl_Obj *	valuesObj;
  Tcl_Obj **	alistObjVector;


  e = Tcl_ListObjGetElements(interp, alistObj, &alistLen, &alistObjVector);
  if (TCL_OK != e) {
    if (NULL != interp) {
      Tcl_SetErrorCode(interp, ALIST_ERRCODE_INVALID_ARGUMENT, NULL);
    }
    return e;
  }

  valuesObj = Tcl_NewListObj(0, 0);

  if (alistLen % 2) --alistLen;
  for (i=1; i<alistLen; i+=2) {
    e = Tcl_ListObjAppendElement(interp, valuesObj, alistObjVector[i]);
    if (TCL_OK != e) {
      if (NULL != interp) {
	Tcl_SetErrorCode(interp, ALIST_ERRCODE_INTERNAL_ERROR, NULL);
      }
      goto error;
    }
  }

  *valuesObjPtr = valuesObj;
  return TCL_OK;

 error:
  Tcl_IncrRefCount(valuesObj);
  Tcl_DecrRefCount(valuesObj);
  return TCL_ERROR;
}




/* Alist_MakeKeyVector --

	Builds  a NULL-terminated array  of string  pointers to  be used
	with  Tcl_GetIndexFromObj(), the  strings  are the  keys of  the
	alist.  If the alist  has an  odd number  of elements,  the last
	element is ignored.

   Arguments:

	objs -		the array of alist objects
	length -	the number of objects in "objs"

   Results:

        Returns a pointer to a vector of strings.

   Side effects:

        It's  responsibility  of the  caller  to  free  the vector  with
        Tcl_Free().

*/

static CONST char **
Alist_MakeKeyVector (Tcl_Obj **objs, int length)
{
  int		i, knum;
  CONST char **	keys;
  knum = length/2;
  keys = (CONST char **) ckalloc(sizeof(char *) * (knum+1));
  for (i=0; i<knum; ++i) {
    keys[i] = Tcl_GetString(objs[i*2]);
  }
  keys[knum] = NULL;
  return keys;
}

/* end of file */
