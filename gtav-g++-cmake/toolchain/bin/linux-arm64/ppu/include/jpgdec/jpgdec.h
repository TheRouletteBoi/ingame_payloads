#ifndef __LV2_JPGDEC_H__
#define __LV2_JPGDEC_H__

#include <ppu-types.h>

#define JPGDEC_ERROR_OK						0
#define JPGDEC_ERROR_HEADER					0x80611101
#define JPGDEC_ERROR_STREAM_FORMAT			0x80611102
#define JPGDEC_ERROR_ARG					0x80611103
#define JPGDEC_ERROR_SEQ					0x80611104
#define JPGDEC_ERROR_BUSY					0x80611105
#define JPGDEC_ERROR_FATAL					0x80611106
#define JPGDEC_ERROR_OPEN_FILE				0x80611107
#define JPGDEC_ERROR_SPU_UNSUPPORT			0x80611108
#define JPGDEC_ERROR_CB_PARAM				0x80611109

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _jpgdec_strm_info jpgDecStrmInfo;
typedef struct _jpgdec_strm_param jpgDecStrmParam;
typedef struct _jpgdec_disp_info jpgDecDispInfo;
typedef struct _jpgdec_disp_param jpgDecDispParam;

typedef void* (*jpgCbCtrlMalloc)(u32 size,void *cbCtrlArg);
typedef void (*jpgCbCtrlFree)(void *ptr,void *cbCtrlArg);

typedef s32 (*jpgCbCtrlStrm)(jpgDecStrmInfo *strmInfo,jpgDecStrmParam *strmParam,void *cbCtrlArg);
typedef s32 (*jpgCbCtrlDisp)(jpgDecDispInfo *dispInfo,jpgDecDispParam *dispParam,void *cbDispArg);

typedef enum
{
	JPGDEC_FILE		= 0,
	JPGDEC_BUFFER	= 1
} jpgStreamSel;

typedef enum
{
	JPGDEC_SPU_THREAD_DISABLE = 0,
	JPGDEC_SPU_THREAD_ENABLE = 1
} jpgSpuThreadEna;

typedef enum
{
	JPGDEC_GRAYSCALE		= 1,
	JPGDEC_RGB				= 2,
	JPGDEC_YCBCR			= 3,
	JPGDEC_RGBA				= 10,
	JPGDEC_UPSTREAM			= 11,
	JPGDEC_ARGB				= 20,
} jpgColorSpace;

typedef enum
{
	JPGDEC_STATUS_FINISH = 0,
	JPGDEC_STATUS_STOP = 1
} jpgDecodeStatus;

typedef enum
{
	JPGDEC_CONTINUE = 0,
	JPGDEC_STOP = 1
} jpgCommand;

typedef enum
{
	JPGDEC_QUALITY = 0,
	JPGDEC_FAST = 5
} jpgMethod;

typedef enum
{
	JPGDEC_TOP_TO_BOTTOM = 0,
	JPGDEC_BOTTOM_TO_TOP = 1
} jpgOutputMode;

typedef enum
{
	JPGDEC_MCU_MODE = 0,
	JPGDEC_LINE_MODE = 1
} jpgBufferMode;

typedef enum
{
	JPGDEC_RECEIVE_EVENT = 0,
	JPGDEC_TRYRECEIVE_EVENT = 1
} jpgSpuMode;

typedef struct _jpgdec_thread_in_param
{
	u32 spu_enable;
	u32 ppu_prio;
	u32 spu_prio;
	jpgCbCtrlMalloc malloc_func ATTRIBUTE_PRXPTR;
	void *malloc_arg ATTRIBUTE_PRXPTR;
	jpgCbCtrlFree free_func ATTRIBUTE_PRXPTR;
	void *free_arg ATTRIBUTE_PRXPTR;
} jpgDecThreadInParam;

typedef struct _jpgdec_thread_out_param
{
	u32 version;
} jpgDecThreadOutParam;

typedef struct _jpgdec_src
{
	u32 stream_sel;
	const char *file_name ATTRIBUTE_PRXPTR;
	s64 file_offset;
	u32 file_size;
	void *stream_ptr ATTRIBUTE_PRXPTR;
	u32 stream_size;
	u32 spu_enable;
} jpgDecSource;

typedef struct _jpgdec_info
{
	u32 width;
	u32 height;
	u32 num_comp;
	u32 color_space;
} jpgDecInfo;

typedef struct _jpgdec_data_info
{
	f32 value;
	u32 output_lines;
	u32 decode_status;
} jpgDecDataInfo;

typedef struct _jpgdec_opn_info
{
	u32 init_space_allocated;
} jpgDecOpnInfo;

typedef struct _jpgdec_in_param
{
	vu32 *cmd_ptr ATTRIBUTE_PRXPTR;
	u32 down_scale;
	u32 quality_mode;
	u32 output_mode;
	u32 color_space;
	u8 alpha;
	u8 pad[3];
} jpgDecInParam;

typedef struct _jpgdec_out_param
{
	u64 width_bytes;
	u32 width;
	u32 height;
	u32 num_comp;
	u32 output_mode;
	u32 color_space;
	u32 down_scale;
	u32 use_memory_space;
} jpgDecOutParam;

typedef struct _jpgdec_datactrl_param
{
	u64 output_bytes_per_line;
} jpgDecDataCtrlParam;

typedef struct _jpgdec_ctrl_strm
{
	jpgCbCtrlStrm strm_func ATTRIBUTE_PRXPTR;
	void *strm_arg ATTRIBUTE_PRXPTR;
} jpgDecCtrlStrm;

typedef struct _jpgdec_ext_info
{
	u64 coeff_buffer_size;
	u32 mcu_width;
} jpgDecExtInfo;

typedef struct _jpgdec_extin_param
{
	void *coeff_buffer ATTRIBUTE_PRXPTR;
	u32 buffer_mode;
	u32 output_counts;
	u32 spu_mode;
} jpgDecExtInParam;

typedef struct _jpgdec_extout_param
{
	u64 output_width_byte;
	u32 output_height;
	u32 one_mcu_width;
	u32 one_mcu_height;
} jpgDecExtOutParam;

typedef struct _jpgdec_ctrl_disp
{
	jpgCbCtrlDisp disp_func ATTRIBUTE_PRXPTR;
	void *disp_arg ATTRIBUTE_PRXPTR;
} jpgDecCtrlDisp;

struct _jpgdec_strm_info
{
	u32 decoded_strm_size;
};

struct _jpgdec_strm_param
{
	void *strm_ptr ATTRIBUTE_PRXPTR;
	u32 strm_size;
};

struct _jpgdec_disp_info
{
	u64 output_frame_width_byte;
	u32 output_frame_height;
	u64 output_start_xbyte;
	u32 output_start_y;
	u64 output_width_byte;
	u32 output_height;
	u32 output_components;
	void *output_image ATTRIBUTE_PRXPTR;
};

struct _jpgdec_disp_param
{
	void *next_output_image ATTRIBUTE_PRXPTR;
};

typedef struct _jpg_data
{
	void *bmp_out;

	u32 pitch;
	u32 width;
	u32 height;
} jpgData;

s32 jpgDecCreate(s32 *handle,jpgDecThreadInParam *in,jpgDecThreadOutParam *out);
s32 jpgDecOpen(s32 handle,s32 *subhandle,const jpgDecSource *src,jpgDecOpnInfo *openInfo);
s32 jpgDecReadHeader(s32 handle,s32 subhandle,jpgDecInfo *info);
s32 jpgDecSetParameter(s32 handle,s32 subhandle,const jpgDecInParam *in,jpgDecOutParam *out);
s32 jpgDecDecodeData(s32 handle,s32 subhandle,u8 *data,const jpgDecDataCtrlParam *dataCtrlParam,jpgDecDataInfo *info);
s32 jpgDecClose(s32 handle,s32 subhandle);
s32 jpgDecDestroy(s32 handle);

s32 jpgDecExtOpen(s32 handle,s32 *subhandle,const jpgDecSource *src,jpgDecOpnInfo *openInfo,const jpgDecCtrlStrm *cbCtrlStrm);
s32 jpgDecExtReadHeader(s32 handle,s32 subhandle,jpgDecInfo *info,jpgDecExtInfo *extInfo);
s32 jpgDecExtSetParameter(s32 handle,s32 subhandle,const jpgDecInParam *inParam,jpgDecOutParam *outParam,const jpgDecExtInParam *extInParam,jpgDecExtOutParam *extOutParam);
s32 jpgDecExtDecodeData(s32 handle,s32 subhandle,u8 *data,const jpgDecDataCtrlParam *dataCtrlParam,jpgDecDataInfo *info,const jpgDecCtrlDisp *cbCtrlDisp,jpgDecDispParam *dispParam);

s32 jpgLoadFromFile(const char *filename,jpgData *out);
s32 jpgLoadFromBuffer(const void *buffer,u32 size,jpgData *out);

#ifdef __cplusplus
	}
#endif

#endif
