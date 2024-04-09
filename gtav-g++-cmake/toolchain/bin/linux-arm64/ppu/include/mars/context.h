#ifndef __MARS_CONTEXT_H__
#define __MARS_CONTEXT_H__

#include <ppu-types.h>

/**
 * \ingroup group_mars_context
 * \brief MARS context structure
 *
 * An instance of this structure must be created and initialized before
 * using any of the MARS API.
 */
struct mars_context;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_context
 * \brief <b>[host]</b> Creates a single MARS context.
 *
 * This function creates a single MARS context. A MARS context must be
 * created before any of the MARS functionality can be used. This will
 * create the MPU contexts that are each loaded with and run the MARS kernel.
 * The MARS kernel on each MPU will continue to run until the MARS context
 * is destroyed through \ref mars_context_destroy.
 *
 * <b>Key Parameters</b>:
 * \n \n
 * \e num_mpus
 * - Specify total number of MPUs to be used by the MARS context
 * - If 0 is specified, MARS will use the maximum number of MPUs available in
 * the system.
 *
 * \e shared
 * - Specify 1 to share the context with other libraries linked into the
 * application that also utilize MARS.
 * - Specify 0 to create an independent MARS context that is not shared with
 * other libraries linked into the application that also utilize MARS.
 * - Sharing a single MARS context within an application with other libraries
 * will maximize the MARS benefits of MPU utilization.
 *
 * \note If there are multiple MARS contexts created in the system, then
 * each MARS context will suffer the large over head of MPU context switches.
 *
 * \param[out] mars			- address of pointer to MARS context
 * \param[in] num_mpus		- number of mpus requested by MARS context
 * \param[in] spu_prio		- priority of SPU thread group
 * \param[in] ppuPriority	- priority of MARS handler PPU thread
 * \return
 *	MARS_SUCCESS		- successfully created MARS context
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_LIMIT	- no more available MPUs or system threads
 * \n	MARS_ERROR_PARAMS	- more MPUs requested than there are available
 * \n	MARS_ERROR_MEMORY	- not enough memory
 * \n	MARS_ERROR_INTERNAL	- some internal error occurred
 */
int mars_context_create(struct mars_context **mars, uint32_t num_mpus, uint32_t spu_prio, uint32_t ppu_prio);

/**
 * \ingroup group_mars_context
 * \brief <b>[host]</b> Destroys a single MARS context.
 *
 * This function destroys a single MARS context that was previously
 * created by \ref mars_context_create. In order to successfully destroy
 * a MARS context, all workloads added to the workload queue must be
 * completed and destroyed so that the workload queue is empty.
 *
 * \param[in] mars		- pointer to MARS context
 * \return
 *	MARS_SUCCESS		- successfully destroyed MARS context
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_STATE	- workload queue is not empty
 */
int mars_context_destroy(struct mars_context *mars);

/**
 * \ingroup group_mars_context
 * \brief <b>[host]</b> Returns number of MPUs allocated for MARS context.
 *
 * This function returns the number of MPUs allocated for the MARS context.
 *
 * \param[in] mars		- pointer to MARS context
 * \return
 *	non-zero		- number of MPUs
 * \n	0			- invalid MARS context
 */
uint32_t mars_context_get_num_mpus(struct mars_context *mars);

#ifdef __cplusplus
	}
#endif

#endif
