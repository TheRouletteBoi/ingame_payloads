#ifndef __LV2_SPU_THREAD_PRINTF_H__
#define __LV2_SPU_THREAD_PRINTF_H__

#include <ppu-types.h>

#ifdef __cplusplus
extern "C" {
#endif

s32 spu_thread_printf(sys_spu_thread_t id, u32 arg_addr);
s32 spu_thread_sprintf(char *buf, sys_spu_thread_t id, u32 arg_addr);

#ifdef __cplusplus
	}
#endif

#endif
