#ifndef __MARS_WORKLOAD_TYPES_H__
#define __MARS_WORKLOAD_TYPES_H__

#include <stdint.h>

#define MARS_WORKLOAD_MODULE_BASE_ADDR					0x2a00
#define MARS_WORKLOAD_MODULE_NAME_LEN_MAX				23
#define MARS_WORKLOAD_RESERVED_SIZE						128
#define MARS_WORKLOAD_CONTEXT_SIZE						256
#define MARS_WORKLOAD_CONTEXT_ALIGN						128

#ifdef __cplusplus
extern "C" {
#endif

struct mars_workload_context
{
	uint8_t reserved[MARS_WORKLOAD_RESERVED_SIZE];
	uint8_t data[MARS_WORKLOAD_CONTEXT_SIZE - MARS_WORKLOAD_RESERVED_SIZE];
} __attribute__((aligned(MARS_WORKLOAD_CONTEXT_ALIGN)));

enum mars_workload_query
{
	MARS_WORKLOAD_QUERY_IS_MODULE_CACHED = 0,	/**< module cached? */
	MARS_WORKLOAD_QUERY_IS_CONTEXT_CACHED,		/**< context cached? */
	MARS_WORKLOAD_QUERY_IS_INITIALIZED,		/**< is initialized? */
	MARS_WORKLOAD_QUERY_IS_READY,			/**< is ready? */
	MARS_WORKLOAD_QUERY_IS_WAITING,			/**< is waiting? */
	MARS_WORKLOAD_QUERY_IS_RUNNING,			/**< is running? */
	MARS_WORKLOAD_QUERY_IS_FINISHED,		/**< is finished? */
	MARS_WORKLOAD_QUERY_IS_SIGNAL_SET		/**< has signal set? */
};

#ifdef __cplusplus
	}
#endif

#endif
