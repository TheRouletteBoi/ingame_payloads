#ifndef __MARS_MUTEX_H__
#define __MARS_MUTEX_H__

#include <ppu-types.h>
#include <mars/mutex_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Creates a mutex.
 *
 * This function creates a mutex instance that can be locked or unlocked
 * from both host and MPU to restrict concurrent accesses.
 *
 * \param[in] mutex_ea		- ea of mutex instance
 * \return
 *	MARS_SUCCESS		- successfully created mutex
 * \n	MARS_ERROR_NULL		- null pointer is specified
 * \n	MARS_ERROR_MEMORY	- instance not aligned properly
 */
int mars_mutex_create(uint64_t *mutex_ea);

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Destroys a mutex.
 *
 * This function destroys a mutex instance.
 *
 * \param[in] mutex_ea		- ea of mutex instance
 * \return
 *	MARS_SUCCESS		- successfully destroyed mutex
 * \n	MARS_ERROR_NULL		- null pointer is specified
 * \n	MARS_ERROR_ALIGN	- instance not aligned properly
 */
int mars_mutex_destroy(uint64_t mutex_ea);

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Resets a mutex.
 *
 * This function resets a mutex instance and forces it into an unlocked state
 * regardless of whether it is locked or unlocked.
 *
 * \param[in] mutex_ea		- ea of mutex instance
 * \return
 *	MARS_SUCCESS		- successfully reset mutex
 * \n	MARS_ERROR_NULL		- null pointer is specified
 * \n	MARS_ERROR_ALIGN	- instance not aligned properly
 */
int mars_mutex_reset(uint64_t mutex_ea);

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Locks a mutex.
 *
 * This function locks a mutex and blocks other requests to lock it.
 *
 * \param[in] mutex_ea		- ea of mutex instance
 * \return
 *	MARS_SUCCESS		- successfully locked mutex
 * \n	MARS_ERROR_NULL		- null pointer is specified
 * \n	MARS_ERROR_ALIGN	- instance not aligned properly
 */
int mars_mutex_lock(uint64_t mutex_ea);

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Unlocks a mutex.
 *
 * This function unlocks a previously locked mutex to allow other lock requests.
 *
 * \param[in] mutex_ea		- ea of mutex instance
 * \return
 *	MARS_SUCCESS		- successfully unlocked mutex
 * \n	MARS_ERROR_NULL		- null pointer is specified
 * \n	MARS_ERROR_ALIGN	- instance not aligned properly
 * \n	MARS_ERROR_STATE	- instance not in locked state
 */
int mars_mutex_unlock(uint64_t mutex_ea);

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Locks a mutex.
 *
 * This function locks a mutex and blocks other requests to lock it.
 * It also loads the mutex instance from the effective address specified
 * into the local mutex instance.
 *
 * \note This call should only be used when MARS_ENABLE_DISCRETE_SHARED_MEMORY
 * is enabled. Otherwise, the mutex parameter is ignored and the function
 * behaves the same as \ref mars_mutex_lock.
 *
 * \param[in] mutex_ea		- ea of mutex instance to lock
 * \param[in] mutex		- pointer to local mutex instance
 * \return
 *	MARS_SUCCESS		- successfully locked mutex
 * \n	MARS_ERROR_NULL		- ea is 0 or mutex is NULL
 * \n	MARS_ERROR_ALIGN	- ea or mutex not aligned properly
 */
int mars_mutex_lock_get(uint64_t mutex_ea, struct mars_mutex *mutex);

/**
 * \ingroup group_mars_mutex
 * \brief <b>[host]</b> Unlocks a mutex.
 *
 * This function unlocks a previously locked mutex to allow other lock requests.
 * It also stores the local mutex instance into the effective address specified.
 *
 * \note This call should only be used when MARS_ENABLE_DISCRETE_SHARED_MEMORY
 * is enabled. Otherwise, the mutex parameter is ignored and the function
 * behaves the same as \ref mars_mutex_unlock.
 *
 * \param[in] mutex_ea		- ea of mutex instance to unlock
 * \param[in] mutex		- pointer to local mutex instance
 * \return
 *	MARS_SUCCESS		- successfully unlocked mutex
 * \n	MARS_ERROR_NULL		- ea is 0 or mutex is NULL
 * \n	MARS_ERROR_ALIGN	- ea or mutex not aligned properly
 * \n	MARS_ERROR_STATE	- instance not in locked state
 */
int mars_mutex_unlock_put(uint64_t mutex_ea, struct mars_mutex *mutex);

#ifdef __cplusplus
	}
#endif

#endif
