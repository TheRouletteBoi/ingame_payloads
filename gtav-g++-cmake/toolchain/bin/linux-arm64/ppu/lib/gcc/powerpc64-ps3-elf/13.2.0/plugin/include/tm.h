#ifndef GCC_TM_H
#define GCC_TM_H
#define TARGET_CPU_DEFAULT ("cell")
#ifndef LIBC_GLIBC
# define LIBC_GLIBC 1
#endif
#ifndef LIBC_UCLIBC
# define LIBC_UCLIBC 2
#endif
#ifndef LIBC_BIONIC
# define LIBC_BIONIC 3
#endif
#ifndef LIBC_MUSL
# define LIBC_MUSL 4
#endif
#ifdef IN_GCC
# include "options.h"
# include "insn-constants.h"
# include "config/vxworks-dummy.h"
# include "config/rs6000/biarch64.h"
# include "config/rs6000/rs6000.h"
# include "config/elfos.h"
# include "config/gnu-user.h"
# include "config/usegas.h"
# include "config/freebsd-spec.h"
# include "config/newlib-stdint.h"
# include "config/rs6000/sysv4.h"
# include "config/rs6000/default64.h"
# include "config/rs6000/cell64lv2.h"
# include "config/rs6000/option-defaults.h"
# include "config/initfini-array.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE && !defined USED_FOR_TARGET
# include "insn-flags.h"
#endif
#if defined IN_GCC && !defined GENERATOR_FILE
# include "insn-modes.h"
#endif
# include "defaults.h"
#endif /* GCC_TM_H */
