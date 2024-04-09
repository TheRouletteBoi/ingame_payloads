#ifndef __MARS_TASK_QUEUE_H__
#define __MARS_TASK_QUEUE_H__

#include <ppu-types.h>
#include <mars/task_queue_types.h>

struct mars_context;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_task_queue
 * \brief <b>[host]</b> Creates a task queue.
 *
 * This function will allocate an instance of the task queue.
 * The queue allows for tasks to wait until data is available from a FIFO
 * data queue.
 * The queue should be used in pairs with various calls to push and pop the
 * the queue
 *
 * <b>Key Parameters</b>:
 * \n \n
 * \e size
 * - Specify the size of each data item in the queue.
 * - The size needs to be a multiple of 16 bytes and no larger than
 * \ref MARS_TASK_QUEUE_ENTRY_SIZE_MAX.
 *
 * \e depth
 * - Specify the depth of the total queue.
 * - The number specified here is the total number of data items the queue
 * can hold at a time.
 * - The size of the total queue is \e size * \e depth.
 *
 * \e direction
 * - Specify the communication direction of the queue.
 * - Must be one of \ref MARS_TASK_QUEUE_HOST_TO_MPU,
 * \ref MARS_TASK_QUEUE_MPU_TO_HOST, \ref MARS_TASK_QUEUE_MPU_TO_MPU.
 *
 * \param[in] mars		- pointer to MARS context
 * \param[out] queue_ea		- address of 64-bit address of queue instance
 * \param[in] size		- size of each data item in data buffer
 * \param[in] depth		- maximum number of data entries in data buffer
 * \param[in] direction		- direction of the event flag
 * \return
 *	MARS_SUCCESS		- successfully created queue
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- size is not multiple of 16 bytes or is greater
 *				  than 16KB maximum
 * \n	MARS_ERROR_PARAMS	- invalid direction specified
 * \n	MARS_ERROR_MEMORY	- not enough memory for queue buffer allocation
 */
int mars_task_queue_create(struct mars_context *mars,
			   uint64_t *queue_ea,
			   uint32_t size,
			   uint32_t depth,
			   uint8_t direction);

/**
 * \ingroup group_mars_task_queue
 * \brief <b>[host]</b> Destroys a task queue.
 *
 * This function will free any resources allocated during creation of the task
 * queue.
 *
 * \param[in] queue_ea		- ea of queue instance
 * \return
 *	MARS_SUCCESS		- successfully destroyed queue
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_ALIGN	- ea not properly aligned
 * \n	MARS_ERROR_STATE	- tasks still waiting
 */
int mars_task_queue_destroy(uint64_t queue_ea);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_count(uint64_t queue_ea, uint32_t *count);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_clear(uint64_t queue_ea);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_push(uint64_t queue_ea, const void *data);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_try_push(uint64_t queue_ea, const void *data);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_pop(uint64_t queue_ea, void *data);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_try_pop(uint64_t queue_ea, void *data);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_peek(uint64_t queue_ea, void *data);

/**
 * \ingroup group_mars_task_queue
 */
int mars_task_queue_try_peek(uint64_t queue_ea, void *data);

#ifdef __cplusplus
	}
#endif

#endif
