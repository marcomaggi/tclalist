#!/bin/bash -norc
dnl	This file is an input file used by the GNU "autoconf" program to
dnl	generate the file "configure", which is run during Tcl installation
dnl	to configure the system for the local environment.

AC_INIT([TclAList],[0.1])
TEA_INIT([3.9])
AC_CONFIG_AUX_DIR(tclconfig)
TEA_PATH_TCLCONFIG
TEA_LOAD_TCLCONFIG
#TEA_PATH_TKCONFIG
#TEA_LOAD_TKCONFIG
TEA_PREFIX
TEA_SETUP_COMPILER
TEA_ADD_SOURCES([init.c commands.c functions.c alistStubInit.c])
TEA_ADD_HEADERS([generic/alist.h generic/alistDecls.h])
TEA_ADD_INCLUDES([])
TEA_ADD_LIBS([])
TEA_ADD_CFLAGS([])
TEA_ADD_STUB_SOURCES([alistStubLib.c])
TEA_ADD_TCL_SOURCES([])

#CLEANFILES="$CLEANFILES pkgIndex.tcl"
if test "${TEA_PLATFORM}" = "windows" ; then
    # Ensure no empty if clauses
    :
    #TEA_ADD_SOURCES([win/winFile.c])
    #TEA_ADD_INCLUDES([-I\"$(${CYGPATH} ${srcdir}/win)\"])
else
    # Ensure no empty else clauses
    :
    #TEA_ADD_SOURCES([unix/unixFile.c])
    #TEA_ADD_LIBS([-lsuperfly])
fi

TEA_PUBLIC_TCL_HEADERS
#TEA_PRIVATE_TCL_HEADERS
#TEA_PUBLIC_TK_HEADERS
#TEA_PRIVATE_TK_HEADERS
#TEA_PATH_X
TEA_ENABLE_THREADS
TEA_ENABLE_SHARED
TEA_CONFIG_CFLAGS
TEA_ENABLE_SYMBOLS
AC_DEFINE(USE_TCL_STUBS, 1, [Use Tcl stubs])
#AC_DEFINE(USE_TK_STUBS, 1, [Use Tk stubs])
TEA_MAKE_LIB
TEA_PROG_TCLSH
#TEA_PROG_WISH

AC_MSG_CHECKING([package namespace])
AC_ARG_ENABLE([namespace],
  AC_HELP_STRING([--enable-namespace],[whether to enable package namespace (default: no)]),
  [if test "$enableval" = yes ;
   then
       ALIST_ENABLE_NAMESPACE=1
       AC_DEFINE([ALIST_ENABLE_NAMESPACE],1)
   else
       ALIST_ENABLE_NAMESPACE=0
       AC_DEFINE([ALIST_ENABLE_NAMESPACE],0)
   fi],
  [ALIST_ENABLE_NAMESPACE=0
   AC_DEFINE([ALIST_ENABLE_NAMESPACE],0)])
AC_MSG_RESULT([$[]ALIST_ENABLE_NAMESPACE])

AC_OUTPUT([Makefile pkgIndex.tcl])

dnl end of file
dnl Local Variables:
dnl mode: autoconf
dnl End:
