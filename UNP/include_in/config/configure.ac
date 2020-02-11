# Must init the autoconf setup
# The first parameter is project name
# second is version number
# third is bug report address
AC_INIT([hello], [1.0])

# Safety checks in case user overwritten --srcdir
#AC_CONFIG_SRCDIR([hello.c])

# Store the auxiliary build tools (e.g., install-sh, config.sub, config.guess)
# in this dir (build-aux)
#AC_CONFIG_AUX_DIR([build-aux])

# Init automake, and specify this program use relaxed structures.
# i.e. this program doesn't follow the gnu coding standards, and doesn't have
# ChangeLog, COPYING, AUTHORS, INSTALL, README etc. files.
#AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Check for C compiler
AC_PROG_CC
# We can add more checks in this section

AC_CONFIG_HEADERS([config.h])

AC_DEFINE_UNQUOTED(CPU_VENDOR_OS,"$host",[CPU,vendor,and operating system])
AC_CHECK_TYPE(struct addrinfo,
 AC_DEFINE(HAVE_ADDRINFO_STRUCT, 1, Define to 1 if <netdb.h> defines struct addrinfo),,[
#include <netdb.h>])

# Tells automake to create a Makefile
# See https://www.gnu.org/software/automake/manual/html_node/Requirements.html
#AC_CONFIG_FILES([Makefile])

# Generate the output
AC_OUTPUT
