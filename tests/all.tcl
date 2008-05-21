# AList --
# 
# Part of: AList
# Contents: test file
# Date: Wed May  8, 2002
# 
# Abstract
# 
# 
# 
# Copyright (c) 2002 Marco Maggi
# email: <marcomaggi at tiscalinet dot it>
# 
# The author hereby grant permission to use, copy, modify, distribute,
# and license this software and its documentation for any purpose,
# provided that existing copyright notices are retained in all copies
# and that this notice is included verbatim in any distributions. No
# written agreement, license, or royalty fee is required for any of the
# authorized uses.  Modifications to this software may be copyrighted by
# their authors and need not follow the licensing terms described here,
# provided that the new terms are clearly indicated on the first page of
# each file where they apply.
# 
# IN NO EVENT SHALL THE AUTHOR OR DISTRIBUTORS BE LIABLE TO ANY PARTY
# FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
# ARISING OUT OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY
# DERIVATIVES THEREOF, EVEN IF THE AUTHOR HAVE BEEN ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# 
# THE  AUTHOR  AND DISTRIBUTORS  SPECIFICALLY  DISCLAIM ANY  WARRANTIES,
# INCLUDING,   BUT   NOT  LIMITED   TO,   THE   IMPLIED  WARRANTIES   OF
# MERCHANTABILITY,    FITNESS   FOR    A    PARTICULAR   PURPOSE,    AND
# NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS,
# AND  THE  AUTHOR  AND  DISTRIBUTORS  HAVE  NO  OBLIGATION  TO  PROVIDE
# MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
# 
# $Id: all.tcl,v 1.2 2002/10/26 13:48:48 marco Exp $
#

package require Tcl 8.4
package require tcltest 2.2

::tcltest::configure -testdir \
	[file dirname [file normalize [info script]]]
::tcltest::configure -verbose "pass error"
eval ::tcltest::configure $argv

::tcltest::runAllTests


### end of file
