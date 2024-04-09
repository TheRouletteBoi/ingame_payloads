#ifndef __MARS_TASK_QUEUE_TYPES_H__
#define __MARS_TASK_QUEUE_TYPES_H__

/**
 * \file
 * \ingroup group_mars_task_queue
 * \brief <b>[host/MPU]</b> MARS Task Queue Types
 */

/**
 * \ingroup group_mars_task_queue
 * \brief Queue direction from PPU to SPU
 */
#define MARS_TASK_QUEUE_HOST_TO_MPU		0x10

/**
 * \ingroup group_mars_task_queue
 * \brief Queue direction from SPU to PPU
 */
#define MARS_TASK_QUEUE_MPU_TO_HOST		0x11

/**
 * \ingroup group_mars_task_queue
 * \brief Queue direction from SPU to SPU
 */
#define MARS_TASK_QUEUE_MPU_TO_MPU		0x12

/**
 * \ingroup group_mars_task_queue
 * \brief Maximum tasks allowed to wait on a queue
 */
#define MARS_TASK_QUEUE_WAIT_MAX		18

/**
 * \ingroup group_mars_task_queue
 * \brief Maximum size allowed for queue entry
 */
#define MARS_TASK_QUEUE_ENTRY_SIZE_MAX		16384

/**
 * \ingroup group_mars_task_queue
 * \brief MARS task queue structure
 *
 * An instance of this structure must be created when using any of the
 * MARS queue API.
 */
struct mars_task_queue;

#endif
