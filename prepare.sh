# prepare.sh --

set -x

(cd ..
    if test \
        configure -ot prepare.sh                                -o \
        configure -ot configure.ac                              -o \
        configure -ot aclocal.m4
        then
        autoconf
    fi)

../configure \
    "$@"

### end of file
