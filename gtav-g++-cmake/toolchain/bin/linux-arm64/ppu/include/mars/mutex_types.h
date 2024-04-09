#ifndef __MARS_MUTEX_TYPES_H__
#define __MARS_MUTEX_TYPES_H__

#include <stdint.h>

#define MARS_MUTEX_SIZE					128
#define MARS_MUTEX_ALIGN				128
#define MARS_MUTEX_ALIGN_MASK			0x7f
#define MARS_MUTEX_LOCKED				0x1
#define MARS_MUTEX_UNLOCKED				0x0

#ifdef __cplusplus
extern "C" {
#endif

struct mars_mutex_status
{
	uint8_t lock;
	uint8_t pad;
	uint8_t current_id;
	uint8_t next_id;
};

struct mars_mutex
{
	struct mars_mutex_status status;
	uint8_t pad[124];
} __attribute__((aligned(MARS_MUTEX_ALIGN)));

#ifdef __cplusplus
	}
#endif

#endif
