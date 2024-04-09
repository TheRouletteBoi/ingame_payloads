#ifndef __MARS_ERROR_H__
#define __MARS_ERROR_H__

#ifdef __cplusplus
extern "C" {
#endif

enum {
	MARS_SUCCESS = 0,	/**< successful with no errors */
	MARS_ERROR_NULL,	/**< null pointer passed in */
	MARS_ERROR_PARAMS,	/**< invalid parameter specified */
	MARS_ERROR_INTERNAL,	/**< internal library error */
	MARS_ERROR_MEMORY,	/**< out of memory */
	MARS_ERROR_ALIGN,	/**< bad memory alignment */
	MARS_ERROR_LIMIT,	/**< some limit exceeded */
	MARS_ERROR_STATE,	/**< something is in an invalid state */
	MARS_ERROR_FORMAT,	/**< invalid format specified */
	MARS_ERROR_BUSY		/**< operation returned due to being busy */
};

#ifdef __cplusplus
	}
#endif

#endif
