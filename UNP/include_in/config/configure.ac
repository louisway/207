# Must init the autoconf setup
# The first parameter is project name
# second is version number
# third is bug report address
AC_INIT([config], [1.0])

# Check for C compiler
AC_PROG_CC
# We can add more checks in this section

AC_CONFIG_HEADERS([config.h])

AC_DEFINE_UNQUOTED(CPU_VENDOR_OS,"$host",[CPU,vendor,and operating system])
AC_CHECK_TYPE(struct addrinfo,
              AC_DEFINE(HAVE_ADDRINFO_STRUCT, 1, Define to 1 if <netdb.h> defines struct addrinfo),,[
              #include <netdb.h>])

# Generate the output
AC_OUTPUT
