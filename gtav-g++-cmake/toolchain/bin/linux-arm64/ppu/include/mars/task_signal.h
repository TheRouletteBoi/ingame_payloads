#ifndef __MARS_TASK_SIGNAL_H__
#define __MARS_TASK_SIGNAL_H__

#include <ppu-types.h>
#include <mars/task_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_task_signal
 */
int mars_task_signal_send(struct mars_task_id *id);

#ifdef __cplusplus
	}
#endif

#endif
