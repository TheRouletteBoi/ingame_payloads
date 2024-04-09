#ifndef __MARS_TASK_SEMAPHORE_TYPES_H__
#define __MARS_TASK_SEMAPHORE_TYPES_H__

/**
 * \file
 * \ingroup group_mars_task_semaphore
 * \brief <b>[host/MPU]</b> MARS Task Semaphore Types
 */

/**
 * \ingroup group_mars_task_semaphore
 * \brief Maximum task accesses allowed for single semaphore
 */
#define MARS_TASK_SEMAPHORE_WAIT_MAX		54

/**
 * \ingroup group_mars_task_semaphore
 * \brief MARS task semaphore structure
 *
 * An instance of this structure must be created when using any of the
 * MARS semaphore API.
 */
struct mars_task_semaphore;

#endif
