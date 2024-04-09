#ifndef __MARS_WORKLOAD_QUEUE_H__
#define __MARS_WORKLOAD_QUEUE_H__

#include <ppu-types.h>
#include <mars/workload_types.h>

struct mars_context;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Returns whether or not specified query is satisfied.
 *
 * \note Query type \ref MARS_WORKLOAD_QUERY_IS_MODULE_CACHED and
 * \ref MARS_WORKLOAD_QUERY_IS_CONTEXT_CACHED are only valid queries for the
 * MPU-side call to \ref mars_module_workload_query.
 * Calling \ref mars_workload_queue_query with these queries will always return
 * 0.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[in] query		- query type
 * \return
 *	int			- non-zero if query satisfied
 */
int mars_workload_queue_query(struct mars_context *mars,
			      uint16_t id,
			      int query);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Begins adding workload to workload queue.
 *
 * This function will begin the process to add a workload to the workload queue.
 * This only initiates the add operation.
 * This function must be completed with a matching call to
 * \ref mars_workload_queue_add_end to guarantee the completion of the add
 * operation.
 *
 * If workload_ea is not NULL, the ea of the workload will be returned.
 *
 * The workload adding process is not completed until the matching call to
 * \ref mars_workload_queue_add_end is made.
 * The user should make any necessary updates to the returned workload context
 * in between this begin call and the end call.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[out] id		- pointer to return workload id
 * \param[out] workload_ea	- address of pointer to workload context ea
 * \param[in] module_elf	- pointer to workload module elf image
 * \param[in] module_name	- name of module
 * \return
 *	MARS_SUCCESS		- workload adding started
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or module specified
 * \n	MARS_ERROR_LIMIT	- workload queue is full
 */
int mars_workload_queue_add_begin(struct mars_context *mars,
				  uint16_t *id,
				  uint64_t *workload_ea,
				  const void *module_elf,
				  const char *module_name);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Ends adding of specified workload.
 *
 * This function will complete a add operation previously initiated with
 * \ref mars_workload_queue_add_begin.
 * This function must be called in pair for each call to
 * \ref mars_workload_queue_add_begin to guarantee the completion of the
 * initiated add operation.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload to end add
 * \param[in] cancel		- cancels the add operation
 * \return
 *	MARS_SUCCESS		- workload adding complete
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- workload adding not started
 */
int mars_workload_queue_add_end(struct mars_context *mars,
				uint16_t id,
				int cancel);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Begins removing workload from workload queue.
 *
 * This function will begin the process to remove a workload from the workload
 * queue.
 * This only initiates the remove operation.
 * This function must be completed with a matching call to
 * \ref mars_workload_queue_remove_end to guarantee the completion of the remove
 * operation.
 *
 * If workload_ea is not NULL, the ea of the workload will be returned.
 *
 * The workload removing process is not completed until the matching call to
 * \ref mars_workload_queue_remove_end is made.
 * The user should make any necessary updates to the returned workload context
 * in between this begin call and the end call.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload to begin remove
 * \param[out] workload_ea	- address of pointer to workload context ea
 * \return
 *	MARS_SUCCESS		- workload removing started
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context specified
 * \n	MARS_ERROR_STATE	- specified workload not added or finished
 */
int mars_workload_queue_remove_begin(struct mars_context *mars,
				     uint16_t id,
				     uint64_t *workload_ea);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Ends removing of specified workload.
 *
 * This function will complete a remove operation previously initiated with
 * \ref mars_workload_queue_remove_begin.
 * This function must be called in pair for each call to
 * \ref mars_workload_queue_remove_begin to guarantee the completion of the
 * initiated remove operation.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[in] cancel		- cancels the remove operation
 * \return
 *	MARS_SUCCESS		- workload removing complete
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- workload removing not started
 */
int mars_workload_queue_remove_end(struct mars_context *mars,
				   uint16_t id,
				   int cancel);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Begins scheduling of specified workload.
 *
 * This function will begin scheduling the workload specified.
 * This only initiates the scheduling of the workload.
 * This function must be completed with a matching call to
 * \ref mars_workload_queue_schedule_end to guarantee the completion of the
 * scheduling.
 *
 * If workload_ea is not NULL, the ea of the workload will be returned.
 *
 * The workload scheduling process is not completed until the matching call to
 * \ref mars_workload_queue_schedule_end is made.
 * The user should make any necessary updates to the returned workload context
 * in between this begin call and the end call.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[in] priority		- scheduling priority of workload
 * \param[out] workload_ea	- address of pointer to workload context ea
 * \return
 *	MARS_SUCCESS		- workload scheduling started
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- specified workload not added or finished
 */
int mars_workload_queue_schedule_begin(struct mars_context *mars,
				       uint16_t id, uint8_t priority,
				       uint64_t *workload_ea);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Ends scheduling of specified workload.
 *
 * This function will complete a schedule operation previously initiated with
 * \ref mars_workload_queue_schedule_begin.
 * This function must be called in pair for each call to
 * \ref mars_workload_queue_schedule_begin to guarantee the completion of the
 * initiated schedule operation.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[in] cancel		- cancels the schedule operation
 * \return
 *	MARS_SUCCESS		- workload scheduling complete
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- workload scheduling not started
 */
int mars_workload_queue_schedule_end(struct mars_context *mars,
				     uint16_t id,
				     int cancel);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Begins unscheduling of specified workload.
 *
 * This function will begin unscheduling the workload specified.
 * This only initiates the unscheduling of the workload.
 * This function must be completed with a matching call to
 * \ref mars_workload_queue_unschedule_end to guarantee the completion of the
 * unscheduling.
 *
 * If workload_ea is not NULL, the ea of the workload will be returned.
 *
 * The workload unscheduling process is not completed until the matching call to
 * \ref mars_workload_queue_unschedule_end is made.
 * The user should make any necessary updates to the returned workload context
 * in between this begin call and the end call.
 *
 * When a workload is unscheduled, it will be put into a finished state and any
 * entities waiting on the workload to finish will be resumed.
 *
 * If a scheduled workload is unscheduled before execution, the workload will
 * not be executed until a subsequent scheduling request is made.
 *
 * If the workload is currently in a waiting state, calling unschedule will
 * finish the workload and will not be resumed from the waiting state.
 *
 * If the workload is currently in a running state, calling unschedule will
 * immediately put the workload into a finished state. However, execution of the
 * workload will only be suspended when the workload yields, waits, or finishes.
 *
 * \note
 * Trying to unschedule a workload that has not yet been scheduled, or has
 * already finished a previously scheduled execution will return an error.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[out] workload_ea	- address of pointer to workload context ea
 * \return
 *	MARS_SUCCESS		- workload aborted
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- workload is not scheduled or has finished
 */
int mars_workload_queue_unschedule_begin(struct mars_context *mars,
					 uint16_t id,
					 uint64_t *workload_ea);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Ends unscheduling of specified workload.
 *
 * This function will complete an unschedule operation previously initiated with
 * \ref mars_workload_queue_unschedule_begin.
 * This function must be called in pair for each call to
 * \ref mars_workload_queue_unschedule_begin to guarantee the completion of the
 * initiated unschedule operation.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \return
 *	MARS_SUCCESS		- workload unscheduling complete
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- workload unscheduling not started
 */
int mars_workload_queue_unschedule_end(struct mars_context *mars,
				       uint16_t id);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Waits for specified workload to finish.
 *
 * This function will block and wait until the specified workload finishes.
 *
 * If workload_ea is not NULL, the ea of the workload will be returned.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[out] workload_ea	- address of pointer to workload context ea
 * \return
 *	MARS_SUCCESS		- workload is finished
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- invalid workload specified
 */
int mars_workload_queue_wait(struct mars_context *mars,
			     uint16_t id,
			     uint64_t *workload_ea);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Waits for specified workload to finish.
 *
 * This function will check whether the workload specified is finished or not
 * and return immediately without blocking.
 *
 * If workload_ea is not NULL, the ea of the workload will be returned.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \param[out] workload_ea	- address of pointer to workload context ea
 * \return
 *	MARS_SUCCESS		- workload is finished
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- invalid workload specified
 * \n	MARS_ERROR_BUSY		- workload has not yet finished
 */
int mars_workload_queue_try_wait(struct mars_context *mars,
				 uint16_t id,
				 uint64_t *workload_ea);

/**
 * \ingroup group_mars_workload_queue
 * \brief <b>[host]</b> Sends signal to specified workload.
 *
 * This function will send a signal to the specified workload.
 *
 * \param[in] mars		- address of pointer to MARS context
 * \param[in] id		- id of workload
 * \return
 *	MARS_SUCCESS		- signalled workload
 * \n	MARS_ERROR_NULL		- null pointer specified
 * \n	MARS_ERROR_PARAMS	- invalid mars context or workload id specified
 * \n	MARS_ERROR_STATE	- invalid workload specified
 */
int mars_workload_queue_signal_send(struct mars_context *mars,
				    uint16_t id);

#ifdef __cplusplus
	}
#endif

#endif
