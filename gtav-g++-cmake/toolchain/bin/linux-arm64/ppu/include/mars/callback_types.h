#ifndef __MARS_CALLBACK_TYPES_H__
#define __MARS_CALLBACK_TYPES_H__

#include <stdint.h>

#define MARS_CALLBACK_ARGS_SIZE					48
#define MARS_CALLBACK_ARGS_ALIGN				16

#ifdef __cplusplus
extern "C" {
#endif

struct mars_callback_args
{
	union
	{
		uint8_t 	u8[48];
		uint16_t 	u16[24];
		uint32_t	u32[12];
		uint64_t	u64[6];
	} type;
}__attribute__((aligned(MARS_CALLBACK_ARGS_ALIGN)));

typedef int (*mars_callback)(const struct mars_callback_args *in, struct mars_callback_args *out);

#ifdef __cplusplus
	}
#endif

#endif
