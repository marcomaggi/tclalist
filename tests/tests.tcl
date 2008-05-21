# tests.tcl --
# 
# Part of: AList
# Contents: tests
# Date: Mon Aug 18, 2003
# 
# Abstract
# 
# 
# 
# Copyright (c) 2003 Marco Maggi
# 
# The author  hereby grant permission to use,  copy, modify, distribute,
# and  license this  software  and its  documentation  for any  purpose,
# provided that  existing copyright notices  are retained in  all copies
# and that  this notice  is included verbatim  in any  distributions. No
# written agreement, license, or royalty  fee is required for any of the
# authorized uses.  Modifications to this software may be copyrighted by
# their authors and need not  follow the licensing terms described here,
# provided that the new terms are clearly indicated on the first page of
# each file where they apply.
# 
# IN NO  EVENT SHALL THE AUTHOR  OR DISTRIBUTORS BE LIABLE  TO ANY PARTY
# FOR  DIRECT, INDIRECT, SPECIAL,  INCIDENTAL, OR  CONSEQUENTIAL DAMAGES
# ARISING OUT  OF THE  USE OF THIS  SOFTWARE, ITS DOCUMENTATION,  OR ANY
# DERIVATIVES  THEREOF, EVEN  IF THE  AUTHOR  HAVE BEEN  ADVISED OF  THE
# POSSIBILITY OF SUCH DAMAGE.
# 
# THE  AUTHOR  AND DISTRIBUTORS  SPECIFICALLY  DISCLAIM ANY  WARRANTIES,
# INCLUDING,   BUT   NOT  LIMITED   TO,   THE   IMPLIED  WARRANTIES   OF
# MERCHANTABILITY,    FITNESS   FOR    A    PARTICULAR   PURPOSE,    AND
# NON-INFRINGEMENT.  THIS  SOFTWARE IS PROVIDED  ON AN "AS  IS" BASIS,
# AND  THE  AUTHOR  AND  DISTRIBUTORS  HAVE  NO  OBLIGATION  TO  PROVIDE
# MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
# 
# $Id: tests.tcl,v 1.1.1.1 2003/08/18 11:08:57 marco Exp $
#


#PAGE
## ------------------------------------------------------------
## Test namespace.
## ------------------------------------------------------------

namespace eval test {

#PAGE

::tcltest::test alist-1.1 "assign element" {
    -body	{
	$alist assign {a 1 b 2 c 3 d 4} c 10
    }
    -result {a 1 b 2 c 10 d 4}
}

#PAGE

::tcltest::test alist-2.1 "get key value" {
    -body	{
	$alist at { a 1 b 2 c 3 d 4 } c
    }
    -result 3
}

#PAGE

::tcltest::test alist-3.1 "get names" {
    -body	{
	$alist names { a 1 b 2 c 3 d 4 }
    }
    -result {a b c d}
}

#PAGE

::tcltest::test alist-4.1 "get name from a list with an odd number of elements" {
    -body	{
	$alist names { a 1 b 2 c 3 d 4 e }
    }
    -result {a b c d}
}

#PAGE

::tcltest::test alist-5.1 "get values" {
    -body	{
	$alist values { a 1 b 2 c 3 d 4 }
    }
    -result {1 2 3 4}
}

::tcltest::test alist-5.2 "get values from a list with an odd number of elements" {
    -body	{
	$alist values { a 1 b 2 c 3 d 4 e }
    }
    -result {1 2 3 4}
}

#PAGE

::tcltest::test alist-6.1 "get version" {
    -body	{
	regexp -- {[0-9]+\.[0-9]+\.[0-9]+} [$alist version]
    }
    -result 1
}


#PAGE
## ------------------------------------------------------------
## End of "test" namespace.
## ------------------------------------------------------------

::tcltest::cleanupTests
}
namespace delete test


### end of file
# Local Variables:
# mode: tcl
# page-delimiter: "^#PAGE"
# End:
