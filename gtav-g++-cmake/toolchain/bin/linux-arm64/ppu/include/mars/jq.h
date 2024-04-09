#ifndef __MARS_JQ_H__
#define __MARS_JQ_H__

#include <ppu-types.h>

#include <mars/base.h>
#include <mars/context.h>
#include <mars/error.h>
#include <mars/jq_types.h>

#ifdef __cplusplus
extern "C" {
#endif

int mars_jq_create(struct mars_context *mars,struct mars_jq_id *id_ret,const char *name);

int mars_jq_run(struct mars_jq_id *id);

int mars_jq_wait(struct mars_jq_id *id);

#ifdef __cplusplus
	}
#endif

#endif /* __MARS_JQ_H__ */
