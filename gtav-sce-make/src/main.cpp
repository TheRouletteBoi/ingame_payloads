/***
* crt0 and linker examples
* C:\PSDK3v2\libraries-src\PSL1GHT-master\ppu\include\ppu-lv2.h       // syscalls example
* C:\PSDK3v2\libraries-src\PSL1GHT-master\ppu\crt\lv2.ld			   // liker and crt0 example
* C:\PSDK3v2\ps3dev\ppu\ppu\lib\lv2.ld								   // liker and crt0 example
*
*/

#include <stddef.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <sys/timer.h>
#include <cell/cell_fs.h>

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

#define MAKE_FN(addr, ret_type, name, args)	\
    uint32_t name##Opd[2] = { addr, GetCurrentToc() }; \
    using name##_t = ret_type(*)args;	\
    name##_t name = (name##_t)name##Opd;

MAKE_FN(0x014FDC5C, int, game_printf, (const char* format, ...));
MAKE_FN(0x014FDCEC, int, game_snprintf, (char* s, size_t n, const char* format, ...));
MAKE_FN(0x01803DBC, int, game_sys_ppu_thread_create, (sys_ppu_thread_t* thread_id, void(*entry)(uint64_t), uint64_t arg, int prio, size_t stacksize, uint64_t flags, const char *threadname));
MAKE_FN(0x01803FEC, void, game_sys_ppu_thread_exit, (uint64_t val));


static inline int _sys_ppu_thread_exit(uint64_t val)
{
    system_call_1(41, val);
    return_to_user_prog(int);
}

int find_value_40()
{
    int var = 0;
    for (int i = 0; i < 50; i++)
    {
        if (i < 40)
        {
            var = i;
        }
    }

    return var;
}

int addition(int left, int right)
{
    return left + right;
}

void thread_entry(uint64_t arg)
{
    game_printf("game thread says hello\n");

    int _30 = find_value_40();
    int sum = addition(_30, 100);

    game_printf("sum %d\n", sum);


    game_sys_ppu_thread_exit(0);
}


int main(int argc, char* argv[])
{
    sys_ppu_thread_t id;
    game_sys_ppu_thread_create(&id, thread_entry, 0, 0x8AE, 0x2000, 0, "thread_from_main");

    _sys_ppu_thread_exit(0);

    return 0;
}