#ifndef __MARS_BASE_H__
#define __MARS_BASE_H__

#include <alloca.h>
#include <malloc.h>
#include <ppu-types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Allocates memory in host storage.
 *
 * \param[in] size		- size of memory block to allocate
 * \return
 *	void *			- pointer to allocated memory block
 */
void *mars_malloc(size_t size);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Re-allocates memory in host storage.
 *
 * \param[in] ptr		- ptr to memory block to re-allocate
 * \param[in] size		- size of memory block to resize to
 * \return
 *	void *			- pointer to re-allocated memory block
 */
void *mars_realloc(void *ptr, size_t size);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Allocates memory on the stack
 *
 * \param[in] boundary		- memory address will be a multiple of boundary
 * \param[in] size		- size of memory block to allocate
 * \return
 *	void *			- pointer to allocated memory block
 */
#define mars_alloca_align(boundary, size)				\
	( (void *)( ( (uintptr_t)alloca((size) + (boundary) - 1) +	\
		      (boundary) - 1) &				\
		    ~(uintptr_t)((boundary) - 1) ) )

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Frees memory allocated in host storage.
 *
 * \param[in] ptr		- ptr to memory block to free
 */
void mars_free(void *ptr);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Allocates memory in shared storage accessible from MPU.
 *
 * \param[in] boundary		- memory address will be a multiple of boundary
 * \param[in] size		- size of memory block to allocate
 * \return
 *	uint64_t		- 64-bit address of allocated memory block
 */
uint64_t mars_ea_memalign(size_t boundary, size_t size);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Frees memory allocated in shared storage.
 *
 * \param[in] ea		- 64-bit address of allocated memory block to free
 */
void mars_ea_free(uint64_t ea);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Copy memory block from shared memory to host memory.
 *
 * \param[in] ea		- 64-bit address of source
 * \param[in] ptr		- pointer to destination
 * \param[in] size		- size of memory block to copy
 */
void mars_ea_get(uint64_t ea, void *ptr, size_t size);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Get 8-bit integer value from shared memory
 *
 * \param[in] ea		- 64-bit address of source
 *
 * \return
 *	uint8_t			- 8-bit result, no guarantee that it is loaded atomically
 */
uint8_t mars_ea_get_uint8(uint64_t ea);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Get 16-bit integer value from shared memory
 *
 * \param[in] ea		- 64-bit address of source
 *
 * \return
 *	uint16_t		- 16-bit result, no guarantee that it is loaded atomically
 */
uint16_t mars_ea_get_uint16(uint64_t ea);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Get 32-bit integer value from shared memory atomically
 *
 * \param[in] ea		- 64-bit address of source
 *
 * \return
 *	uint32_t		- 32-bit result
 */

uint32_t mars_ea_get_uint32(uint64_t ea);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Get 64-bit integer value from shared memory
 *
 * \param[in] ea		- 64-bit address of source
 *
 * \return
 *	uint64_t		- 64-bit result, no guarantee that it is loaded atomically
 */
uint64_t mars_ea_get_uint64(uint64_t ea);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Copy memory block from host memory to shared memory.
 *
 * \param[in] ea		- 64-bit address of destination
 * \param[in] ptr		- pointer to source
 * \param[in] size		- size of memory block to copy
 */
void mars_ea_put(uint64_t ea, const void *ptr, size_t size);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Put 8-bit integer value to shared memory atomically
 *
 * \param[in] ea		- 64-bit address of destination
 * \param[in] value		- 8-bit value to be stored in shared memory, no guarantee that it is stored atomically
 */
void mars_ea_put_uint8(uint64_t ea, uint8_t value);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Put 16-bit integer value to shared memory atomically
 *
 * \param[in] ea		- 64-bit address of destination
 * \param[in] value		- 16-bit value to be stored in shared memory, no guarantee that it is stored atomically
 */
void mars_ea_put_uint16(uint64_t ea, uint16_t value);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Put 32-bit integer value to shared memory atomically
 *
 * \param[in] ea		- 64-bit address of destination
 * \param[in] value		- 32-bit value to be stored in shared memory
 */
void mars_ea_put_uint32(uint64_t ea, uint32_t value);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Put 64-bit integer value to shared memory atomically
 *
 * \param[in] ea		- 64-bit address of destination
 * \param[in] value		- 64-bit value to be stored in shared memory, no guarantee that it is stored atomically
 */
void mars_ea_put_uint64(uint64_t ea, uint64_t value);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Enable read access to data in specified memory block from MPU
 *
 * \param[in] ptr		- pointer to source
 * \param[in] size		- size of memory block
 *
 * \return
 *	uint64_t		- 64-bit address of memory block
 */
uint64_t mars_ea_map(void *ptr, size_t size);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Disable data access enabled by mars_ea_map
 *
 * \param[in] ea		- 64-bit address of memory block
 * \param[in] size		- size of memory block
 */
void mars_ea_unmap(uint64_t ea, size_t size);

/* test_cond:
 *	MARS_SUCCESS: the condition is satisfied
 *	<0: the condition is not satisfied
 *	>0: error code
 */
int mars_ea_cond_wait(uint64_t watch_point_ea,
		      int (*test_cond)(uint32_t , void *),
		      void *test_cond_param);

int mars_ea_cond_signal(uint64_t watch_point_ea, int broadcast);

#ifdef MARS_ENABLE_DISCRETE_SHARED_MEMORY
#  define mars_ea_work_area_get(ea, boundary, size) mars_alloca_align(boundary, size)
#else /* !MARS_ENABLE_DISCRETE_SHARED_MEMORY */
	/* work area is unnecessary for non-discrete shared memory model */
#  define mars_ea_work_area_get(ea, boundary, size) mars_ea_to_ptr(ea)
#endif /* !MARS_ENABLE_DISCRETE_SHARED_MEMORY */

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Memory barrier
 */
void mars_ea_sync(void);

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Converts a 64-bit address to pointer.
 *
 * \param[in] ea		- 64-bit address
 * \return
 *	void *			- pointer value
 */
static inline void *mars_ea_to_ptr(uint64_t ea)
{
	return (void *)(uintptr_t)ea;
}

/**
 * \ingroup group_mars_base
 * \brief <b>[host]</b> Converts a pointer to 64-bit address.
 *
 * \param[in] ptr		- pointer value
 * \return
 *	uint64_t		- 64-bit address
 */
static inline uint64_t mars_ptr_to_ea(const void *ptr)
{
	return (uint64_t)(const uintptr_t)ptr;
}

/**
 * \ingroup group_mars_base
 * \brief <b>[host/MPU]</b> Returns tick counter value.
 *
 * \note Counter's frequency depends on runtime environment.
 *
 * \return
 *	uint32_t		- 32-bit tick counter value
 */
uint32_t mars_get_ticks(void);

#ifdef __cplusplus
	}
#endif

#endif
