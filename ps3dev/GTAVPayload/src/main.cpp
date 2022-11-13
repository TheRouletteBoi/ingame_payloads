// C:\PSDK3v2\libraries-src\PSL1GHT-master\ppu\include\ppu-lv2.h       // syscalls example
// C:\PSDK3v2\libraries-src\PSL1GHT-master\ppu\crt\lv2.ld			   // liker and crt0 example
// C:\PSDK3v2\ps3dev\ppu\ppu\lib\lv2.ld								   // liker and crt0 example

#include <vector>
#include <iostream>
#include <stdint.h>
#include "syscalls.h"

#define ADDR_TOC							0x01C85330
#define ADDR_PRINTF           				0x014FDC5C
#define ADDR_SNPRINTF         				0x014FDCEC
#define ADDR_SYS_PPU_THREAD_CREATE			0x01803DBC
#define ADDR_SYS_PPU_THREAD_EXIT			0x01803FEC

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

template <typename R, typename... TArgs>
__ALWAYS_INLINE R GameCall(uint32_t addr, TArgs... args)
{
   volatile opd_s opd = { addr, GetCurrentToc() };
   R(*func)(TArgs...) = (R(*)(TArgs...)) & opd;
   return func(args...);
}

#define __printf(format, ...) GameCall<int>(ADDR_PRINTF, format, ##__VA_ARGS__)
#define __snprintf(s, n, format, ...) GameCall<int>(ADDR_SNPRINTF, s, n, format, ##__VA_ARGS__)
#define __sys_ppu_thread_create(threadId, entry, arg, prio, stacksize, flags, threadname) GameCall<int>(ADDR_SYS_PPU_THREAD_CREATE, threadId, entry, arg, prio, stacksize, flags, threadname)
#define __sys_ppu_thread_exit(val) GameCall<int>(ADDR_SYS_PPU_THREAD_EXIT, val)

/*#define MAKE_FN(addr, ret_type, name, args)	\
    uint32_t name##Opd[2] = { addr, GetCurrentToc() }; \
    using name##_t = ret_type(*)args;	\
    name##_t name = (name##_t)name##Opd;

MAKE_FN(0x014FDC5C, int, __printf, (const char* format, ...));
MAKE_FN(0x014FDCEC, int, __snprintf, (char* s, size_t n, const char* format, ...));
MAKE_FN(0x01803DBC, int, __sys_ppu_thread_create, (sys_ppu_thread_t* thread_id, void(*entry)(uint64_t), uint64_t arg, int prio, size_t stacksize, uint64_t flags, const char *threadname));
MAKE_FN(0x01803FEC, void, __sys_ppu_thread_exit, (uint64_t val));*/


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
	__printf("game thread says hello\n");
	
	int _30 = find_value_40();
	int sum = addition(_30, 100);
	
	__printf("sum %d\n", sum);
	
	
	__sys_ppu_thread_exit(0);
}

int main(int argc, char* argv[])
{
	sys_ppu_thread_t id;
	__sys_ppu_thread_create(&id, thread_entry, 0, 0x8AE, 0x2000, 0, "thread_from_main");

	_sys_ppu_thread_exit(0);
	
    return 0;
}
