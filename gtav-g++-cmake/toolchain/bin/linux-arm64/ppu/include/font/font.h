#ifndef __LV2_FONT_H__
#define __LV2_FONT_H__

#include <ppu-types.h>

#include <font/fontset.h>

#define FONT_LIBRARY_TYPE_NONE 				0

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*fontMallocCallback)(void *object,u32 size);
typedef void  (*fontFreeCallback)(void *object,void *ptr);
typedef void* (*fontReallocCallback)(void *object,void *p,u32 reallocSize);
typedef void* (*fontCallocCallback)(void *object,u32 num,u32 size);

typedef struct _font_memory_interface
{
	void *object ATTRIBUTE_PRXPTR;
	fontMallocCallback malloc_func ATTRIBUTE_PRXPTR;
	fontFreeCallback free_func ATTRIBUTE_PRXPTR;
	fontReallocCallback realloc_func ATTRIBUTE_PRXPTR;
	fontCallocCallback calloc_func ATTRIBUTE_PRXPTR;	
} fontMemoryInterface;

typedef struct _font_entry
{
	u32 lock;
	u32 uniqueId;
	const void* fontLib ATTRIBUTE_PRXPTR;
	void* fontH ATTRIBUTE_PRXPTR;
} fontEntry;

typedef struct _font_config
{
	struct {
		u32 *buffer ATTRIBUTE_PRXPTR;
		u32 size;
	} fileCache;
	
	u32 userFontEntryMax;
	fontEntry *userFontEntries ATTRIBUTE_PRXPTR;
	u32 flags;
} fontConfig;

typedef struct _font_library
{
	u32 libraryType, libraryVersion;
	u32 systemClosed[];
} fontLibrary;

typedef struct _font_type
{
	u32 type;
	u32 map;
} fontType;

typedef struct _font
{
	void* ATTRIBUTE_PRXPTR systemReserved[64];
} font;

typedef struct _font_renderer
{
	void* ATTRIBUTE_PRXPTR systemReserved[64];
} fontRenderer;

typedef struct _font_renderer_config
{
	struct {
		void* buffer ATTRIBUTE_PRXPTR;
		u32 initSize;
		u32 maxSize;
		u32 expandSize;
		u32 resetSize;
	} bufferingPolicy;
} fontRendererConfig;

typedef struct _font_horizontal_layout
{
	f32 baseLineY;
	f32 lineHeight;
	f32 effectHeight;
} fontHorizontalLayout;

typedef struct _font_vertical_layout
{
	f32 baseLineX;
	f32 lineWidth;
	f32 effectWidth;
} fontVerticalLayout;

typedef struct _font_glyph_metrics
{
	f32 width;
	f32 height;

	struct {
		f32 bearingX;
		f32 bearingY;
		f32 advance;
	} horizontal;
	struct {
		f32 bearingX;
		f32 bearingY;
		f32 advance;
	} vertical;
} fontGlyphMetrics;

typedef struct _font_glyph_outline
{
	s16 contoursCount;
	s16 pointsCount;
	
	struct {
		f32 x, y;
	} *Points ATTRIBUTE_PRXPTR;
	
	u8 * pointTags ATTRIBUTE_PRXPTR;
	u16* contourIndexs ATTRIBUTE_PRXPTR;
	u32 flags;
	void* generateEnv ATTRIBUTE_PRXPTR;
} fontGlyphOutline;

typedef struct _font_glyph
{
	u16 cf_type, type;
	u32 size;
	fontGlyphMetrics metrics;
	fontGlyphOutline outline;
} fontGlyph;

typedef struct _font_kerning
{
	f32 offsetX;
	f32 offsetY;
} fontKerning;

typedef struct _font_glyph_style
{
	struct {
		f32 widthPixel;
		f32 heightPixel;
	} Scale;
	struct {
		f32 weight;
		f32 slant;
	} Effect;
} fontGlyphStyle;

typedef struct _font_render_surface
{
	void* buffer ATTRIBUTE_PRXPTR;
	s32 widthByte;
	s32 pixelSizeByte;
	s32 width, height;
	struct {
		u32 x0, y0;
		u32 x1, y1;
	} Scissor;
} fontRenderSurface;

typedef struct _font_image_trans_info
{
	u8 *image ATTRIBUTE_PRXPTR;
	u32 imageWidthByte;
	u32 imageWidth;
	u32 imageHeight;
	void *surface ATTRIBUTE_PRXPTR;
	u32 surfWidthByte;
} fontImageTransInfo;

static inline void fontMemoryInterface_initialize(fontMemoryInterface *mIF)
{
	mIF->object       = NULL;
	mIF->malloc_func  = NULL;
	mIF->free_func    = NULL;
	mIF->realloc_func = NULL;
	mIF->calloc_func  = NULL;
}

static inline void fontConfig_initialize(fontConfig *config)
{
	config->fileCache.buffer = NULL;
	config->fileCache.size   = 0;
	config->userFontEntryMax = 0;
	config->userFontEntries  = NULL;
	config->flags 			 = 0x00000000;
}

static inline s32 fontInit(fontConfig *config)
{
	extern void fontGetStubRevisionFlags(u64 *revisionFlags);
	extern s32 fontInitializeWithRevision(u64 revision, fontConfig *config);
	u64 revisionFlags = 0LL;
	
	fontGetStubRevisionFlags(&revisionFlags);
	return fontInitializeWithRevision(revisionFlags, config);
}

s32 fontOpenFontset(const fontLibrary *lib,fontType *type,font *f);
s32 fontOpenFontsetOnMemory(const fontLibrary *lib,fontType *type,font *f);
s32 fontOpenFontFile(const fontLibrary *lib,const char *fontPath,u32 subNum,s32 uniqueID,font *f);
s32 fontOpenFontMemory(const fontLibrary *lib,void *fontAddr,u32 fontSize,u32 subNum,s32 uniqueID,font *f);
s32 fontOpenFontInstance(font *openedFont,font *f);
s32 fontGetLibrary(font *f,const fontLibrary **lib,u32 *type);
s32 fontAdjustGlyphExpandBuffer(font *f,s32 pointN,s32 contourN);
s32 fontGetGlyphExpandBufferInfo(font *f,s32 *pointN,s32 *contourN);
s32 fontAdjustFontScaling(font *f,f32 fontScale);
s32 fontSetResolutionDpi(font *f,u32 hDpi,u32 vDpi);
s32 fontSetScalePoint(font *f,f32 w,f32 h);
s32 fontontSetScalePixel(font *f,f32 w,f32 h);
s32 fontSetEffectWeight(font *f,f32 effectWeight);
s32 fontSetEffectSlant(font *f,f32 effectSlant);
s32 fontGetResolutionDpi(font *f,u32 *hDpi,u32 *vDpi);
s32 fontGetScalePoint(font *f,f32 *w,f32 *h);
s32 fontGetScalePixel(font *f,f32 *w,f32 *h);
s32 fontGetEffectWeight(font *f,f32 *effectWeight);
s32 fontGetEffectSlant(font *f,f32 *effectSlant);
s32 fontGetHorizontalLayout(font *f,fontHorizontalLayout *layout);
s32 fontGetVerticalLayout(font *f,fontVerticalLayout *layout);
s32 fontGetFontIdCode(font *f,u32 code,u32 *fontId,u32 *fontcode);
s32 fontGetCharGlyphMetrics(font *f,u32 code,fontGlyphMetrics *metrics);
s32 fontGetCharGlyphMetricsVertical(font *f,u32 code,fontGlyphMetrics *metrics);
s32 fontGetKerning(font *f,u32 preCode,u32 code,fontKerning *kerning);
s32 fontCreateRenderer(const fontLibrary *lib,fontRendererConfig *confing,fontRenderer *renderer);
s32 fontBindRenderer(font *f,fontRenderer *renderer);
s32 fontGetBindingRenderer(font *f,fontRenderer **renderer);
s32 fontSetupRenderScalePoint(font *f,f32 w,f32 h);
s32 fontSetupRenderScalePixel(font *f,f32 w,f32 h);
s32 fontSetupRenderEffectWeight(font *f,f32 additionalWeight);
s32 fontSetupRenderEffectSlant(font *f,f32 effectSlant);
s32 fontGetRenderScalePoint(font *f,f32 *w,f32 *h);
s32 fontGetRenderScalePixel(font *f,f32 *w,f32 *h);
s32 fontGetRenderEffectWeight(font *f,f32 *effectWeight);
s32 fontGetRenderEffectSlant(font *f,f32 *effectSlant);
s32 fontGetRenderCharGlyphMetrics(font *f,u32 code,fontGlyphMetrics *metrics);
s32 fontGetRenderCharGlyphMetricsVertical(font *cfEx,u32 code,fontGlyphMetrics *metrics);
s32 fontGetRenderScaledKerning(font *f,u32 preCode,u32 code,fontKerning *kerning);
s32 fontGenerateCharGlyph(font *f,u32 code,fontGlyph **glyph);
s32 fontGenerateCharGlyphVertical(font *f,u32 code,fontGlyph **glyph);
s32 fontDeleteGlyph(font *f,fontGlyph *glyph);
s32 fontDelete(const fontLibrary *library,void *p);
void fontRenderSurfaceInit(fontRenderSurface *surface,void *buffer,s32 bufWidthByte,s32 pixelSizeByte,s32 w,s32 h);
void fontRenderSurfaceSetScissor(fontRenderSurface *surface,s32 x0,s32 y0,u32 w,u32 h);
s32 fontRenderCharGlyphImage(font *f,u32 code,fontRenderSurface *surface,f32 x,f32 y,fontGlyphMetrics *metrics,fontImageTransInfo *transInfo);
s32 fontRenderCharGlyphImageHorizontal(font *f,u32 code,fontRenderSurface *surface,f32 x,f32 y,fontGlyphMetrics *metrics,fontImageTransInfo *transInfo);
s32 fontRenderCharGlyphImageVertical(font *f,u32 code,fontRenderSurface *surface,f32 x,f32 y,fontGlyphMetrics *metrics,fontImageTransInfo *transInfo);
s32 fontUnbindRenderer(font *f);
s32 fontGlyphRenderImage(fontGlyph *glyph,fontGlyphStyle *style,fontRenderer *renderer,fontRenderSurface *surface,f32 x,f32 y,fontGlyphMetrics *metrics,fontImageTransInfo *transInfo);
s32 fontGlyphRenderImageHorizontal(fontGlyph *glyph,fontGlyphStyle *style,fontRenderer *renderer,fontRenderSurface *surface,f32 x,f32 y,fontGlyphMetrics *metrics,fontImageTransInfo *transInfo);
s32 fontGlyphRenderImageVertical(fontGlyph *glyph,fontGlyphStyle *style,fontRenderer *renderer,fontRenderSurface *surface,f32 x,f32 y,fontGlyphMetrics *metrics,fontImageTransInfo *transInfo);
s32 fontGlyphGetHorizontalShift(fontGlyph *glyph,f32 *shiftX,f32 *shiftY);
s32 fontGlyphGetVerticalShift(fontGlyph *glyph,f32 *shiftX,f32 *shiftY);
s32 fontDestroyRenderer(fontRenderer *renderer);
s32 fontCloseFont(font *cf);
s32 fontEndLibrary(const fontLibrary *lib);
s32 fontEnd();

#ifdef __cplusplus
	}
#endif

#endif
