#ifndef __MARS_TASK_BARRIER_TYPES_H__
#define __MARS_TASK_BARRIER_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \file
 * \ingroup group_mars_task_barrier
 * \brief <b>[host/MPU]</b> MARS Task Barrier Types
 */

/**
 * \ingroup group_mars_task_barrier
 * \brief Maximum tasks allowed for single barrier
 */
#define MARS_TASK_BARRIER_WAIT_MAX		25

/**
 * \ingroup group_mars_task_barrier
 * \brief MARS task barrier structure
 *
 * An instance of this structure must be created when using any of the
 * MARS task barrier API.
 */
struct mars_task_barrier;

#ifdef __cplusplus
	}
#endif

#endif
