#ifndef __MARS_TASK_BARRIER_H__
#define __MARS_TASK_BARRIER_H__

#include <ppu-types.h>
#include <mars/task_barrier_types.h>

struct mars_context;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_task_barrier
 * \brief <b>[host]</b> Creates a task barrier.
 *
 * This function will allocate an instance of the task barrier.
 * The barrier allows for tasks within the barrier group to wait until all
 * tasks arrive at some synchronization point and notify the barrier.
 * All tasks included in the barrier group should call the notify and wait in
 * pairs.
 *
 * <b>Key Parameters</b>:
 * \n \n
 * \e total
 * - Specify total number of tasks that will be associated with this barrier.
 * - Total must be a value between 1 and \ref MARS_TASK_BARRIER_WAIT_MAX.
 *
 * \param[in] mars		- pointer to MARS context
 * \param[out] barrier_ea	- ea of barrier instance
 * \param[in] total		- number of notifies before barrier released
 * \return
 *	MARS_SUCCESS		- successfully created barrier
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- total is 0 or exceeds allowed limit
 */
int mars_task_barrier_create(struct mars_context *mars,
			     uint64_t *barrier_ea,
			     uint32_t total);


/**
 * \ingroup group_mars_task_barrier
 * \brief <b>[host]</b> Initialize a task barrier.
 *
 * This function will initialize a task barrier to a new number
 * of notifies before barrier release.
 *
 * \param[in] barrier_ea	- ea of barrier instance
 * \param[in] total			- number of notifies before barrier released
 * \return
 *	MARS_SUCCESS		- successfully destroyed barrier
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- total is 0 or exceeds allowed limit
 */
int mars_task_barrier_initialize(uint64_t barrier_ea,
								 uint32_t total);
/**
 * \ingroup group_mars_task_barrier
 * \brief <b>[host]</b> Destroys a task barrier.
 *
 * This function will free any resources allocated during creation of the task
 * barrier.
 *
 * \param[in] barrier_ea	- ea of barrier instance
 * \return
 *	MARS_SUCCESS		- successfully destroyed barrier
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_ALIGN	- ea not properly aligned
 * \n	MARS_ERROR_STATE	- tasks still waiting
 */
int mars_task_barrier_destroy(uint64_t barrier_ea);

#ifdef __cplusplus
	}
#endif

#endif
