#ifndef __MARS_TASK_H__
#define __MARS_TASK_H__

#include <ppu-types.h>

#include <mars/base.h>
#include <mars/context.h>
#include <mars/error.h>
#include <mars/task_barrier.h>
#include <mars/task_event_flag.h>
#include <mars/task_queue.h>
#include <mars/task_semaphore.h>
#include <mars/task_signal.h>
#include <mars/task_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_task
 * \brief <b>[host]</b> Creates a MARS task.
 *
 * This function creates a single task and adds it the MARS context's
 * workload queue.
 * Upon success, a valid task id will be returned.
 * You must call \ref mars_task_schedule in order for it to be scheduled for
 * execution by the kernel.
 * The task is in the finished state upon creation and may be destroyed by
 * \ref mars_task_destroy without ever being scheduled for execution.
 *
 * <b>Key Parameters</b>:
 * \n \n
 * \e name
 * - The name is optional, but if specified to other than NULL its
 * length must not exceed \ref MARS_TASK_NAME_LEN_MAX.
 * - An empty string will be treated the same as passing NULL, and will return
 * NULL if \ref mars_task_get_name is called on the task.
 * - The name does need to be kept allocated after this function returns.

 * \e elf_image
 * - The address of MPU program elf image in host storage that will be run
 * by this task.
 * - The elf image must remain allocated until the task is destroyed.

 * \e context_save_size
 * - If 0 is specified, then no context save area will be allocated for the task
 * and therefore the task must be a run-complete task.
 * - A run-complete task will run and occupy an MPU until it has completed
 * running and exits.
 * - A run-complete task cannot context switch, and therefore cannot call
 * functions that will enter that task into a wait state.
 * - If \ref MARS_TASK_CONTEXT_SAVE_SIZE_MAX is specified, the maximum size
 * context save area required will be allocated and all of the MPU storage area
 * used by the task will be saved and restored.
 * - Advanced users can specify a size between 0 and
 * \ref MARS_TASK_CONTEXT_SAVE_SIZE_MAX in order to minimize memory usage for
 * the context save area.
 * - The size specified must be large enough to hold all of the task program's
 * text, data, heap, stack and non-volatile registers 80-127.
 *
 * \param[in] mars		- pointer to MARS context
 * \param[out] id		- address of pointer to task id instance
 * \param[in] name		- name of task
 * \param[in] elf_image		- address of MPU program elf image
 * \param[in] context_save_size	- [ 0 ~ \ref MARS_TASK_CONTEXT_SAVE_SIZE_MAX ]
 * \return
 *	MARS_SUCCESS		- successfully created MARS task
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- bad params specified
 * \n	MARS_ERROR_MEMORY	- not enough memory
 * \n	MARS_ERROR_LIMIT	- task queue is currently full
 */
int mars_task_create(struct mars_context *mars,
		     struct mars_task_id *id,
		     const char *name,
		     const void *elf_image,
		     uint32_t context_save_size);

/**
 * \ingroup group_mars_task
 * \brief <b>[host]</b> Destroys a MARS task.
 *
 * This function destroys a task created by \ref mars_task_create.
 * The task will only be destroyed if the task is in the finished state.
 * Once this function returns successfully and the task is destroyed, the task
 * id is no longer valid.
 * To guarantee the task has finished before calling this function, you should
 * wait for task completion by calling \ref mars_task_wait or
 * \ref mars_task_try_wait.
 *
 * \param[in] id		- pointer to task id instance
 * \return
 *	MARS_SUCCESS		- successfully destroyed MARS task
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- bad task id specified
 * \n	MARS_ERROR_STATE	- task is in an invalid state
 */
int mars_task_destroy(struct mars_task_id *id);

/**
 * \ingroup group_mars_task
 */
int mars_task_schedule(const struct mars_task_id *id,
		       const struct mars_task_args *args,
		       uint8_t priority);

/**
 * \ingroup group_mars_task
 */
int mars_task_unschedule(const struct mars_task_id *id, int32_t exit_code);

/**
 * \ingroup group_mars_task
 */
int mars_task_wait(const struct mars_task_id *id, int32_t *exit_code);

/**
 * \ingroup group_mars_task
 */
int mars_task_try_wait(const struct mars_task_id *id, int32_t *exit_code);

/**
 * \ingroup group_mars_task
 */
uint32_t mars_task_get_ticks(void);

#ifdef __cplusplus
	}
#endif

#endif
