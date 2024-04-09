#ifndef __LV2_FONTFT_H__
#define __LV2_FONTFT_H__

#include <ppu-types.h>

#include <font/font.h>

#define FONT_LIBRARY_TYPE_FREETYPE  			2

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _font_library_configFT
{
	void *library ATTRIBUTE_PRXPTR;
	fontMemoryInterface memoryIF;
} fontLibraryConfigFT;

typedef struct _font_renderer_configFT
{
	struct {
		void *buffer ATTRIBUTE_PRXPTR;
		u32 initSize;
		u32 maxSize;
		u32 expandSize;
		u32 resetSize;
	} bufferingPolicy;
} fontRendererConfigFT;

static inline void fontLibraryConfigFT_initialize(fontLibraryConfigFT *config)
{
	config->library = NULL;
	fontMemoryInterface_initialize(&config->memoryIF);
}

s32 fontInitLibraryFreeType(fontLibraryConfigFT *config,const fontLibrary **lib);

#ifdef __cplusplus
	}
#endif

#endif
