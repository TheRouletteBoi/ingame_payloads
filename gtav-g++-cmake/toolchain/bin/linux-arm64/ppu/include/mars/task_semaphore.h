#ifndef __MARS_TASK_SEMAPHORE_H__
#define __MARS_TASK_SEMAPHORE_H__

#include <ppu-types.h>
#include <mars/task_semaphore_types.h>

struct mars_context;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_task_semaphore
 * \brief <b>[host]</b> Creates a task semaphore.
 *
 * This function will allocate an instance of the task semaphore.
 * The semaphore allows for tasks to wait until a semaphore can be obtained.
 * The semaphore should be used in pairs with calls to acquire and release.
 *
 * <b>Key Parameters</b>:
 * \n \n
 * \e count
 * - Specify the total number of entities that can have access to the semaphore
 * simultaneously.
 * - Must not be greater than \ref MARS_TASK_SEMAPHORE_WAIT_MAX.
 *
 * \param[in] mars		- pointer to MARS context
 * \param[out] semaphore_ea	- ea of semaphore instance
 * \param[in] count		- initial number of task accesses allowed
 * \return
 *	MARS_SUCCESS		- successfully created semaphore
 * \n	MARS_ERROR_NULL		- null pointer is specified
 * \n	MARS_ERROR_PARAMS	- count exceeds allowed limit
 */
int mars_task_semaphore_create(struct mars_context *mars,
			       uint64_t *semaphore_ea,
			       int32_t count);

/**
 * \ingroup group_mars_task_semaphore
 * \brief <b>[host]</b> Destroys a task semaphore.
 *
 * This function will free any resources allocated during creation of the task
 * semaphore.
 *
 * \param[in] semaphore_ea	- ea of semaphore instance
 * \return
 *	MARS_SUCCESS		- successfully destroyed semaphore
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_ALIGN	- ea not properly aligned
 * \n	MARS_ERROR_STATE	- tasks still waiting
 */
int mars_task_semaphore_destroy(uint64_t semaphore_ea);

#ifdef __cplusplus
	}
#endif

#endif
