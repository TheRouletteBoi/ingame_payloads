#ifndef __MARS_TASK_EVENT_FLAG_TYPES_H__
#define __MARS_TASK_EVENT_FLAG_TYPES_H__

/**
 * \file
 * \ingroup group_mars_task_event_flag
 * \brief <b>[host/MPU]</b> MARS Task Event Flag Types
 */

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag direction from PPU to SPU
 */
#define MARS_TASK_EVENT_FLAG_HOST_TO_MPU	0x10

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag direction from SPU to PPU
 */
#define MARS_TASK_EVENT_FLAG_MPU_TO_HOST	0x11

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag direction from SPU to SPU
 */
#define MARS_TASK_EVENT_FLAG_MPU_TO_MPU		0x12

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag clear mode automatic
 */
#define MARS_TASK_EVENT_FLAG_CLEAR_AUTO		0x20

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag clear mode manual
 */
#define MARS_TASK_EVENT_FLAG_CLEAR_MANUAL	0x21

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag mask mode bitwise OR
 */
#define MARS_TASK_EVENT_FLAG_MASK_OR		0x30

/**
 * \ingroup group_mars_task_event_flag
 * \brief Event flag mask mode bitwise AND
 */
#define MARS_TASK_EVENT_FLAG_MASK_AND		0x31

/**
 * \ingroup group_mars_task_event_flag
 * \brief Maximum tasks allowed to wait on a single event flag
 */
#define MARS_TASK_EVENT_FLAG_WAIT_MAX		15

/**
 * \ingroup group_mars_task_event_flag
 * \brief MARS task event flag structure
 *
 * An instance of this structure must be created when using any of the
 * MARS event flag API.
 */
struct mars_task_event_flag;

#endif
