/*
 * Load the arguments and system call numbers to the registers, and issue
 * the "sc" instruction.
 *
 * \param nr The number of arguments
 * \param syscall_num The system call number
 * \param args The argument list
 */
#define system_call_8(syscall_num, a1, a2, a3, a4, a5, a6, a7, a8)          \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5") = a3;                                   \
register uint64_t p4 __asm__ ("6") = a4;                                   \
register uint64_t p5 __asm__ ("7") = a5;                                   \
register uint64_t p6 __asm__ ("8") = a6;                                   \
register uint64_t p7 __asm__ ("9") = a7;                                   \
register uint64_t p8 __asm__ ("10") = a8;                                  \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (p3), "r" (p4),                \
                    "r" (p5), "r" (p6), "r" (p7), "r" (p8), "r" (n)        \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_7(syscall_num, a1, a2, a3, a4, a5, a6, a7)             \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5") = a3;                                   \
register uint64_t p4 __asm__ ("6") = a4;                                   \
register uint64_t p5 __asm__ ("7") = a5;                                   \
register uint64_t p6 __asm__ ("8") = a6;                                   \
register uint64_t p7 __asm__ ("9") = a7;                                   \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (p3), "r" (p4),                \
                    "r" (p5), "r" (p6), "r" (p7), "r" (n)                  \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_6(syscall_num, a1, a2, a3, a4, a5, a6)                 \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5") = a3;                                   \
register uint64_t p4 __asm__ ("6") = a4;                                   \
register uint64_t p5 __asm__ ("7") = a5;                                   \
register uint64_t p6 __asm__ ("8") = a6;                                   \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (p3), "r" (p4),                \
                    "r" (p5), "r" (p6), "r" (n)                            \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_5(syscall_num, a1, a2, a3, a4, a5)                     \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5") = a3;                                   \
register uint64_t p4 __asm__ ("6") = a4;                                   \
register uint64_t p5 __asm__ ("7") = a5;                                   \
register uint64_t p6 __asm__ ("8");                                        \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (p3), "r" (p4),                \
                    "r" (p5), "r" (n)                                      \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_4(syscall_num, a1, a2, a3, a4)                         \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5") = a3;                                   \
register uint64_t p4 __asm__ ("6") = a4;                                   \
register uint64_t p5 __asm__ ("7");                                        \
register uint64_t p6 __asm__ ("8");                                        \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (p3), "r" (p4),                \
                    "r" (n)                                                \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_3(syscall_num, a1, a2, a3)                             \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5") = a3;                                   \
register uint64_t p4 __asm__ ("6");                                        \
register uint64_t p5 __asm__ ("7");                                        \
register uint64_t p6 __asm__ ("8");                                        \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (p3), "r" (n)                  \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_2(syscall_num, a1, a2)                                 \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4") = a2;                                   \
register uint64_t p3 __asm__ ("5");                                        \
register uint64_t p4 __asm__ ("6");                                        \
register uint64_t p5 __asm__ ("7");                                        \
register uint64_t p6 __asm__ ("8");                                        \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1), "r" (p2), "r" (n)                            \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_1(syscall_num, a1)                                     \
register uint64_t p1 __asm__ ("3") = a1;                                   \
register uint64_t p2 __asm__ ("4");                                        \
register uint64_t p3 __asm__ ("5");                                        \
register uint64_t p4 __asm__ ("6");                                        \
register uint64_t p5 __asm__ ("7");                                        \
register uint64_t p6 __asm__ ("8");                                        \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (p1),  "r" (n)                                     \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


#define system_call_0(syscall_num)                                         \
register uint64_t p1 __asm__ ("3");                                        \
register uint64_t p2 __asm__ ("4");                                        \
register uint64_t p3 __asm__ ("5");                                        \
register uint64_t p4 __asm__ ("6");                                        \
register uint64_t p5 __asm__ ("7");                                        \
register uint64_t p6 __asm__ ("8");                                        \
register uint64_t p7 __asm__ ("9");                                        \
register uint64_t p8 __asm__ ("10");                                       \
register uint64_t n  __asm__ ("11") = syscall_num;                         \
                                                                           \
__asm__ volatile ("sc"                                                     \
                  : "=r" (p1), "=r" (p2), "=r" (p3), "=r" (p4),            \
                    "=r" (p5), "=r" (p6), "=r" (p7), "=r" (p8), "=r" (n)   \
                  : "r" (n)                                                \
                  : "0", "12", "lr", "ctr", "xer", "cr0", "cr1", "cr5", "cr6", "cr7", "memory") \


 /*
  * Calling this macro lets the stub return to the user program.
  *
  * \param ret_type The return parameter type
  */
#define return_to_user_prog(ret_type) return (ret_type)(p1)


  /*
   * Macros to obtain the register passing return arguments.
   */
#define register_passing_1(type) (type)(p2)
#define register_passing_2(type) (type)(p3)
#define register_passing_3(type) (type)(p4)
#define register_passing_4(type) (type)(p5)
#define register_passing_5(type) (type)(p6)
#define register_passing_6(type) (type)(p7)
#define register_passing_7(type) (type)(p8)