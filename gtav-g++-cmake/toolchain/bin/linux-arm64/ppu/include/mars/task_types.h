#ifndef __MARS_TASK_TYPES_H__
#define __MARS_TASK_TYPES_H__

#include <stdint.h>

#include <mars/callback_types.h>

#define MARS_TASK_BASE_ADDR					0x3a00
#define MARS_TASK_CONTEXT_SAVE_SIZE_MAX		0x3c600
#define MARS_TASK_NAME_LEN_MAX				21

#ifdef __cplusplus
extern "C" {
#endif


struct mars_task_id {
	uint64_t mars_context_ea;
	uint16_t workload_id;
	uint8_t name[MARS_TASK_NAME_LEN_MAX + 1];
};

struct mars_task_args {
	union {
		uint8_t  u8[32];
		uint16_t u16[16];
		uint32_t u32[8];
		uint64_t u64[4];
	} type;
};

#ifdef __cplusplus
	}
#endif

#endif
