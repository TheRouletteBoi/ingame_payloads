/***
* crt0 and linker examples
* C:\PSDK3v2\libraries-src\PSL1GHT-master\ppu\include\ppu-lv2.h       // syscalls example
* C:\PSDK3v2\libraries-src\PSL1GHT-master\ppu\crt\lv2.ld			   // liker and crt0 example
* C:\PSDK3v2\ps3dev\ppu\ppu\lib\lv2.ld								   // liker and crt0 example
*
*/

#include "types.h"

#define	PPU_THREAD_CREATE_JOINABLE	0x0000000000000001
#define	PPU_THREAD_CREATE_INTERRUPT	0x0000000000000002

typedef uint64_t sys_ppu_thread_t;

#define __ALWAYS_INLINE static inline __attribute__( ( always_inline ) )

struct opd_s
{
    uint32_t func;
    uint32_t toc;
};

uint32_t GetCurrentToc()
{
    uint32_t* entry_point = *reinterpret_cast<uint32_t**>(0x1001C); // ElfHeader->e_entry 
    return entry_point[1];
}

__attribute__((naked, noinline)) uint64_t syscall(int index, ...)
{
    asm
    (
        "mflr %r0;"
        "std %r0, 0x10(%r1);"
        "stdu %r1, -0x70(%r1);"
        "mr %r0, %r3;"
        "mr %r3, %r4;"
        "mr %r4, %r5;"
        "mr %r5, %r6;"
        "mr %r6, %r7;"
        "mr %r7, %r8;"
        "mr %r8, %r9;"
        "mr %r9, %r10;"
        "mr %r10, %r11;"
        "mr %r11, %r0;"
        "sc;"
        "addi %r1, %r1, 0x70;"
        "ld %r0, 0x10(%r1);"
        "mtlr %r0;"
        "blr;"
    );
}


#define MAKE_FN(addr, ret_type, name, args)	\
    uint32_t name##Opd[2] = { addr, GetCurrentToc() }; \
    using name##_t = ret_type(*)args;	\
    name##_t name = (name##_t)name##Opd;

MAKE_FN(0x014FDC5C, int, game_printf, (const char* format, ...));
MAKE_FN(0x014FDCEC, int, game_snprintf, (char* s, size_t n, const char* format, ...));
MAKE_FN(0x01803DBC, int, game_sys_ppu_thread_create, (sys_ppu_thread_t* thread_id, void(*entry)(uint64_t), uint64_t arg, int prio, size_t stacksize, uint64_t flags, const char *threadname));
MAKE_FN(0x01803FEC, void, game_sys_ppu_thread_exit, (uint64_t val));


static inline uint64_t _sys_ppu_thread_exit(uint64_t val)
{
    return syscall(41, val);
}

int find_value_40()
{
    int val = 0;
    for (int i = 0; i < 50; i++)
    {
        if (i < 40)
        {
            val = i;
        }
    }

    return val;
}

int addition(int left, int right)
{
    return left + right;
}

void thread_entry(uint64_t arg)
{

}


extern "C" uint64_t PayloadEntry(uint64_t TOC, uint64_t payloadTOC)
{
    sys_ppu_thread_t id;
    game_sys_ppu_thread_create(&id, thread_entry, 0, 0x8AE, 0x2000, 0, "thread_from_main");

    _sys_ppu_thread_exit(0);


    return 0;
}
