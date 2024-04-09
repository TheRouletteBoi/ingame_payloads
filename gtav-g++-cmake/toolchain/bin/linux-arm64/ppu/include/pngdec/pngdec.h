#ifndef __LV2_PNGDEC_H__
#define __LV2_PNGDEC_H__

#include <ppu-types.h>

#define PNGDEC_ERROR_OK						0
#define PNGDEC_ERROR_HEADER					0x80611201
#define PNGDEC_ERROR_STREAM_FORMAT			0x80611202
#define PNGDEC_ERROR_ARG					0x80611203
#define PNGDEC_ERROR_SEQ					0x80611204
#define PNGDEC_ERROR_BUSY					0x80611205
#define PNGDEC_ERROR_FATAL					0x80611206
#define PNGDEC_ERROR_OPEN_FILE				0x80611207
#define PNGDEC_ERROR_SPU_UNSUPPORT			0x80611208
#define PNGDEC_ERROR_SPU_ERROR				0x80611209
#define PNGDEC_ERROR_CB_PARAM				0x8061120a

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _pngdec_stream_info pngDecStreamInfo;
typedef struct _pngdec_stream_param pngDecStreamParam;
typedef struct _pngdec_disp_info pngDecDispInfo;
typedef struct _pngdec_disp_param pngDecDispParam;

typedef void* (*pngCbCtrlMalloc)(u32 size,void *cbCtrlArg);
typedef void (*pngCbCtrlFree)(void *ptr,void *cbCtrlArg);

typedef s32 (*pngCbCtrlStrm)(pngDecStreamInfo *strmInfo,pngDecStreamParam *strmParam,void *cbStrmArg);

typedef s32 (*pngCbCtrlDisp)(pngDecDispInfo *dispInfo,pngDecDispParam *dispParam,void *cbDispArg);

typedef enum
{
	PNGDEC_SPU_THREAD_DISABLE = 0,
	PNGDEC_SPU_THREAD_ENABLE = 1
} pngSpuThreadEna;

typedef enum
{
	PNGDEC_FILE		= 0,
	PNGDEC_BUFFER	= 1
} pngStreamSel;

typedef enum
{
	PNGDEC_GRAYSCALE		= 1,
	PNGDEC_RGB				= 2,
	PNGDEC_PALETTE			= 4,
	PNGDEC_GRAYSCALE_ALPHA	= 9,
	PNGDEC_RGBA				= 10,
	PNGDEC_ARGB				= 20
} pngColorSpace;

typedef enum
{
	PNGDEC_NO_INTERLACE = 0,
	PNGDEC_ADAM7_INTERLACE = 1
} pngInterlaceMode;

typedef enum
{
	PNGDEC_STATUS_FINISH = 0,
	PNGDEC_STATUS_STOP = 1
} pngDecodeStatus;

typedef enum
{
	PNGDEC_CONTINUE = 0,
	PNGDEC_STOP = 1
} pngCommand;

typedef enum
{
	PNGDEC_TOP_TO_BOTTOM = 0,
	PNGDEC_BOTTOM_TO_TOP = 1
} pngOutputMode;

typedef enum
{
	PNGDEC_1BYTE_PER_NPIXEL = 0,
	PNGDEC_1BYTE_PER_1PIXEL = 1
} pngPackFlag;

typedef enum
{
	PNGDEC_STREAM_ALPHA = 0,
	PNGDEC_FIX_ALPHA = 1
} pngAlphaSelect;

typedef enum
{
	PNGDEC_LINE_MODE = 1					/*! \brief LINE mode.<br>Decode the number of lines specified with <i>output_counts</i> at one time. */
} pngBufferMode;

typedef enum
{
	PNGDEC_RECEIVE_EVENT = 0,				/*! \brief Decoder uses \ref spursQueuePopBegin to wait for termination of Disp callback function.<br>Transistion to WAITING state and may be affected by the behavior of other SPU threads. */
	PNGDEC_TRYRECEIVE_EVENT = 1				/*! \brief Decoder uses \ref spursQueueTryPopBegin to wait for termination of Disp callback function.<br>Since there is no state transistion, it is not affected by the behavior of other SPU threads. */
} pngSpuMode;

typedef struct _pngdec_thread_in_param
{
	u32 spu_enable;
	u32 ppu_prio;
	u32 spu_prio;
	pngCbCtrlMalloc malloc_func ATTRIBUTE_PRXPTR;
	void *malloc_arg ATTRIBUTE_PRXPTR;
	pngCbCtrlFree free_func ATTRIBUTE_PRXPTR;
	void *free_arg ATTRIBUTE_PRXPTR;
} pngDecThreadInParam;

typedef struct _pngdec_thread_out_param
{
	u32 version;
} pngDecThreadOutParam;

typedef struct _pngdec_src
{
	/*! \brief Input stream selection. Possible values:
	  - \ref PNGDEC_FILE
	  - \ref PNGDEC_BUFFER
	*/
	u32 stream_sel;
	const char *file_name ATTRIBUTE_PRXPTR;
	s64 file_offset;
	u32 file_size;
	void *stream_ptr ATTRIBUTE_PRXPTR;
	u32 stream_size;
	u32 spu_enable;
} pngDecSource;

typedef struct _pngdec_info
{
	u32 width;
	u32 height;
	u32 num_comp;
	u32 color_space;
	u32 bit_depth;
	u32 interlace_mode;
	u32 chunk_info;
} pngDecInfo;

typedef struct _pngdec_data_info
{
	u32 chunk_info;
	u32 num_text;
	u32 num_unk_chunk;
	u32 decode_status;
} pngDecDataInfo;

typedef struct _pngdec_in_param
{
	vu32 *cmd_ptr ATTRIBUTE_PRXPTR;
	u32 output_mode;
	u32 color_space;
	u32 bit_depth;
	u32 pack_flag;
	u32 alpha_select;
	u32 alpha;
} pngDecInParam;

typedef struct _pngdec_out_param
{
	u64 width_byte;
	u32 width;
	u32 height;
	u32 num_comp;
	u32 bit_depth;
	u32 output_mode;
	u32 color_space;
	u32 use_memory_space;
} pngDecOutParam;

typedef struct _pngdec_datactrl_param
{
	u64 output_bytes_per_line;
} pngDecDataCtrlParam;

typedef struct _pngdec_opn_info
{
	u32 init_space_allocated;
} pngDecOpnInfo;

typedef struct _pngdec_opn_param
{
	u32 select_chunk;
} pngDecOpnParam;

typedef struct _pngdec_ctrl_strm
{
	pngCbCtrlStrm stream_func ATTRIBUTE_PRXPTR;
	void *stream_arg ATTRIBUTE_PRXPTR;
} pngDecCtrlStrm;

typedef struct _pngdec_ext_info
{
	u64 reserved;
} pngDecExtInfo;

typedef struct _pngdec_extin_param
{
	/*! \brief Mode of output of partial images. Possible values:
	  - \ref PNGDEC_LINE_MODE
	*/
	u32 buffer_mode;
	u32 output_counts;
	u32 spu_mode;
}  pngDecExtInParam;

typedef struct _pngdec_extout_param
{
	u64 output_width_bytes;
	u32 output_height;
} pngDecExtOutParam;

typedef struct _pngdec_ctrl_disp
{
	pngCbCtrlDisp disp_func ATTRIBUTE_PRXPTR;
	void *disp_arg ATTRIBUTE_PRXPTR;
} pngDecCtrlDisp;

struct _pngdec_stream_info
{
	u32 decoded_stream_size;
};

struct _pngdec_stream_param
{
	void *strm_ptr ATTRIBUTE_PRXPTR;
	u32 strm_size;
};

struct _pngdec_disp_param
{
	void *next_output_image ATTRIBUTE_PRXPTR;
};

struct _pngdec_disp_info
{
	u64 output_frame_width_bytes;
	u32 output_frame_height;
	u64 output_start_xbyte;
	u32 output_start_y;
	u64 output_width_byte;
	u32 output_height;
	u32 output_bit_depth;
	u32 output_components;
	u32 next_output_start_y;
	u32 scan_pass_count;
	void *output_image ATTRIBUTE_PRXPTR;
};

typedef struct _png_data
{
	void *bmp_out;

	u32 pitch;
	u32 width;
	u32 height;
} pngData;

s32 pngDecCreate(s32 *handle,pngDecThreadInParam *in,pngDecThreadOutParam *out);
s32 pngDecOpen(s32 handle,s32 *subhandle,const pngDecSource *src,pngDecOpnInfo *open_info);
s32 pngDecReadHeader(s32 handle,s32 subhandle,pngDecInfo *info);
s32 pngDecSetParameter(s32 handle,s32 subhandle,const pngDecInParam *in,pngDecOutParam *out);
s32 pngDecDecodeData(s32 handle,s32 subhandle,u8 *data,const pngDecDataCtrlParam *dataCtrlParam,pngDecDataInfo *info);
s32 pngDecClose(s32 handle,s32 subhandle);
s32 pngDecDestroy(s32 handle);

s32 pngDecExtOpen(s32 handle,s32 *subhandle,const pngDecSource *src,pngDecOpnInfo *open_info,const pngDecCtrlStrm *cbCtrlStrm,const pngDecOpnParam *opnParam);
s32 pngDecExtReadHeader(s32 handle,s32 subhandle,pngDecInfo *info,pngDecExtInfo *extInfo);
s32 pngDecExtSetParameter(s32 handle,s32 subhandle,const pngDecInParam *inParam,pngDecOutParam *outParam,const pngDecExtInParam *extInParam,pngDecExtOutParam *extOutParam);
s32 pngDecExtDecodeData(s32 handle,s32 subhandle,u8 *data,const pngDecDataCtrlParam *dataCtrlParam,pngDecDataInfo *dataOutInfo,const pngDecCtrlDisp *cbCtrlDisp,pngDecDispParam *dispParam);

s32 pngLoadFromFile(const char *filename,pngData *out);
s32 pngLoadFromBuffer(const void *buffer,u32 size,pngData *out);

#ifdef __cplusplus
	}
#endif

#endif
