/*! \brief Set drawing direction of front face.
\param context Pointer to the context object.
\param dir Drawing direction of front face. Possible values are:
- \ref GCM_FRONTFACE_CW
- \ref GCM_FRONTFACE_CCW
*/
void RSX_FUNC(SetFrontFace)(gcmContextData *context,u32 dir);

/*! \brief Set culling mode.
\param context Pointer to context object.
\param cull Type of cull mode. Possible values are:
- \ref GCM_CULL_FRONT
- \ref GCM_CULL_BACK
- \ref GCM_CULL_ALL
*/
void RSX_FUNC(SetCullFace)(gcmContextData *context,u32 cull);

/*! \brief Enable/Disable face culling.
\param context Pointer to the context object.
\param enable Enable flag. Possible values are:
 - \ref GCM_TRUE
 - \ref GCM_FALSE
 */
void RSX_FUNC(SetCullFaceEnable)(gcmContextData *context,u32 enable);

/*! \brief Control front-facing polygon rendering.
\param context Pointer to the context object.
\param enable Drawing mode. Possible values are:
 - \ref GCM_POLYGON_MODE_POINT
 - \ref GCM_POLYGON_MODE_LINE
 - \ref GCM_POLYGON_MODE_FILL
 */
void RSX_FUNC(SetFrontPolygonMode)(gcmContextData *context,u32 mode);

/*! \brief Control back-facing polygon rendering.
\param context Pointer to the context object.
\param enable Drawing mode. Possible values are:
 - \ref GCM_POLYGON_MODE_POINT
 - \ref GCM_POLYGON_MODE_LINE
 - \ref GCM_POLYGON_MODE_FILL
 */
void RSX_FUNC(SetBackPolygonMode)(gcmContextData *context,u32 mode);

void RSX_FUNC(SetPolygonOffsetFillEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetPolygonOffset)(gcmContextData *context,f32 factor,f32 units);
void RSX_FUNC(SetPolygonOffsetLineEnable)(gcmContextData *context,u32 enable);

/*! \brief Enable/Disable write to depth buffer.
\param context Pointer to the context object.
\param enable Enable flag. Possible values are:
- \ref GCM_TRUE
- \ref GCM_FALSE
*/
void RSX_FUNC(SetDepthWriteEnable)(gcmContextData *context,u32 enable);

/*! \brief Stop the render sequence.

Stops the rendering for a primitive, started by \ref rsxDrawVertexBegin.
\param context Pointer to the context object.
*/
void RSX_FUNC(DrawVertexEnd)(gcmContextData *context);

/*! \brief Set the shading model for the render sequence.
\param context Pointer to the context object.
\param shadeModel Type of shading model. Possible values are:
- \ref GCM_SHADE_MODEL_FLAT
- \ref GCM_SHADE_MODEL_SMOOTH
*/
void RSX_FUNC(SetShadeModel)(gcmContextData *context,u32 shadeModel);

/*! \brief Start the render sequence.

Starts the rendering for a primitive.
\param context Pointer to the context object.
\param type Type of primitive to render. Possible values are:
- \ref GCM_TYPE_POINTS
- \ref GCM_TYPE_LINES
- \ref GCM_TYPE_LINE_LOOP
- \ref GCM_TYPE_LINE_STRIP
- \ref GCM_TYPE_TRIANGLES
- \ref GCM_TYPE_TRIANGLE_STRIP
- \ref GCM_TYPE_TRIANGLE_FAN
- \ref GCM_TYPE_QUADS
- \ref GCM_TYPE_QUAD_STRIP
- \ref GCM_TYPE_POLYGON
*/
void RSX_FUNC(DrawVertexBegin)(gcmContextData *context,u32 type);
void RSX_FUNC(DrawVertex1f)(gcmContextData *context,u8 idx,f32 v);
void RSX_FUNC(DrawVertex2f)(gcmContextData *context,u8 idx,const f32 v[2]);
void RSX_FUNC(DrawVertex3f)(gcmContextData *context,u8 idx,const f32 v[3]);
void RSX_FUNC(DrawVertex4f)(gcmContextData *context,u8 idx,const f32 v[4]);
void RSX_FUNC(DrawVertex4s)(gcmContextData *context,u8 idx,const s16 v[4]);
void RSX_FUNC(DrawVertexScaled4s)(gcmContextData *context,u8 idx,const s16 v[4]);
void RSX_FUNC(DrawVertex2s)(gcmContextData *context,u8 idx,const s16 v[2]);
void RSX_FUNC(DrawVertex4ub)(gcmContextData *context,u8 idx,const u8 v[4]);
void RSX_FUNC(SetScissor)(gcmContextData *context,u16 x,u16 y,u16 w,u16 h);

/*! \brief Specify the value used for depth buffer comparisons.
\param context Pointer to the context object.
\param func Specifies the depth comparison function. Possible values are:
 - \ref GCM_NEVER
 - \ref GCM_LESS
 - \ref GCM_EQUAL
 - \ref GCM_LEQUAL
 - \ref GCM_GREATER
 - \ref GCM_NOTEQUAL
 - \ref GCM_GEQUAL
 - \ref GCM_ALWAYS
*/
void RSX_FUNC(SetDepthFunc)(gcmContextData *context,u32 func);

/*! \brief Enable or disable the depth test.

If depth test is enabled, the GPU performs depth comparisons and updates the
depth buffer.
Note that even if the depth buffer exists and the depth mask is non-zero,
the depth buffer is not updated if the depth test is disabled.
\param context Pointer to the context object.
\param enable Enable flag. Possible values are:
 - \ref GCM_TRUE
 - \ref GCM_FALSE
*/
void RSX_FUNC(SetDepthTestEnable)(gcmContextData *context,u32 enable);

/*! \brief Set depth format
*/
void RSX_FUNC(SetDepthFormat)(gcmContextData *context,u32 format);

/*! \brief Clear the render surface.

This function clears the chosen selection of color components, depth and stencil
values for all pixels in the destination surface. The clear color can be chosen
using \ref rsxSetClearColor, and the clear value for the depth buffer is set
using \ref rsxSetClearDepthValue.

\param context Pointer to the context object.
\param clear_mask A selection of components to be cleared. Must be an OR
combination of the following values:
 - \ref GCM_CLEAR_Z
 - \ref GCM_CLEAR_S
 - \ref GCM_CLEAR_R
 - \ref GCM_CLEAR_G
 - \ref GCM_CLEAR_B
 - \ref GCM_CLEAR_A
The value of \ref GCM_CLEAR_M can also be chosen, to clear all RGBA components,
depth and stencil buffers.
*/
void RSX_FUNC(ClearSurface)(gcmContextData *context,u32 clear_mask);

/*! \brief Set the clear depth value.

This value is used by the \ref rsxClearSurface function.
\param context Pointer to the context object.
\param value Color value 
*/
void RSX_FUNC(SetClearDepthStencil)(gcmContextData *context,u32 value);
void RSX_FUNC(SetReturnCommand)(gcmContextData *context);
void RSX_FUNC(SetCallCommand)(gcmContextData *context,u32 offset);
void RSX_FUNC(SetJumpCommand)(gcmContextData *context,u32 offset);
void RSX_FUNC(SetNopCommand)(gcmContextData *context,u32 count);
void RSX_FUNC(SetSkipNop)(gcmContextData *context,u32 count);

/*! \brief Set the clear color.

The clear color value is used by the \ref rsxClearSurface function.
\param context Pointer to the context object.
\param color The clear color value.
*/
void RSX_FUNC(SetClearColor)(gcmContextData *context,u32 color);

/*! \brief Enable or disable write access to the framebuffer color components.
\param context Pointer to the context object.
\param mask A selection of the components to enable write access. It is an OR
combination of the following values:
 - \ref GCM_COLOR_MASK_B
 - \ref GCM_COLOR_MASK_G
 - \ref GCM_COLOR_MASK_R
 - \ref GCM_COLOR_MASK_A
*/
void RSX_FUNC(SetColorMask)(gcmContextData *context,u32 mask);

/*! \brief Enable or disable write access to the framebuffer color components
(Multiple Render Target output).
\param context Pointer to the context object.
\param mask A selection of the components to enable write access. It is an OR
combination of the following values:
 - \ref GCM_COLOR_MASK_B
 - \ref GCM_COLOR_MASK_G
 - \ref GCM_COLOR_MASK_R
 - \ref GCM_COLOR_MASK_A
*/
void RSX_FUNC(SetColorMaskMrt)(gcmContextData *context,u32 mask);

void RSX_FUNC(SetPointSpriteControl)(gcmContextData *context,u32 enable,u32 rmode,u32 texcoordMask);
void RSX_FUNC(SetPointSize)(gcmContextData *context,f32 size);
void RSX_FUNC(SetAntialiasingControl)(gcmContextData *context,u32 enable,u32 alphaToCoverage,u32 alphaToOne,u32 sampleMask);
void RSX_FUNC(SetCylindricalWrap)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetStencilFunc)(gcmContextData *context,u32 func,u32 ref,u32 mask);
void RSX_FUNC(SetStencilMask)(gcmContextData *context,u32 mask);
void RSX_FUNC(SetStencilOp)(gcmContextData *context,u32 fail,u32 depthFail,u32 depthPass);
void RSX_FUNC(SetStencilTestEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetBackStencilFunc)(gcmContextData *context,u32 func,u32 ref,u32 mask);
void RSX_FUNC(SetBackStencilMask)(gcmContextData *context,u32 mask);
void RSX_FUNC(SetBackStencilOp)(gcmContextData *context,u32 fail,u32 depthFail,u32 depthPass);
void RSX_FUNC(SetTwoSidedStencilTestEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetTwoSideLightEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetRenderEnable)(gcmContextData *context,u8 mode,u32 index);
void RSX_FUNC(SetReport)(gcmContextData *context,u32 type,u32 index);
void RSX_FUNC(SetClearReport)(gcmContextData *context,u32 type);
void RSX_FUNC(SetSCullControl)(gcmContextData *context,u8 sFunc,u8 sRef,u8 sMask);
void RSX_FUNC(SetZCullEnable)(gcmContextData *context, u32 depth, u32 stencil);
void RSX_FUNC(SetClearZCullSurface)(gcmContextData *context, u32 depth, u32 stencil);
void RSX_FUNC(SetZCullLimit)(gcmContextData *context,u16 moveforwardlimit,u16 pushbacklimit);
void RSX_FUNC(SetZCullControl)(gcmContextData *context,u8 zculldir,u8 zcullformat);
void RSX_FUNC(SetZCullStatsEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetZCullInvalidate)(gcmContextData *context);
void RSX_FUNC(SetPolygonSmoothEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetDitherEnable)(gcmContextData *context,u32 enable);

/*! \brief Setup the render surface.

This function is used to setup the render target where RSX should render the frame into.
\param context Pointer to the context object.
\param surface Pointer to the surface object.
*/
void RSX_FUNC(SetSurface)(gcmContextData *context,const gcmSurface *surface);
void RSX_FUNC(SetReferenceCommand)(gcmContextData *context,u32 ref_value);

/*! \brief Enqueues a Wait for label command.
\param context Pointer to the context object.
\param index Label index
\param valuie Label value
*/
void RSX_FUNC(SetWaitLabel)(gcmContextData *context,u8 index,u32 value);

/*! \brief Enqueues a Write Command label command.
\param context Pointer to the context object.
\param index Label index
\param value Label value
*/
void RSX_FUNC(SetWriteCommandLabel)(gcmContextData *context,u8 index,u32 value);

/*! \brief Enqueues a Write Backend label command.
\param context Pointer to the context object.
\param index Label index
\param value Label value
*/
void RSX_FUNC(SetWriteBackendLabel)(gcmContextData *context,u8 index,u32 value);

void RSX_FUNC(SetWriteTextureLabel)(gcmContextData *context,u8 index,u32 value);

void RSX_FUNC(SetViewportClip)(gcmContextData *context,u8 sel,u16 width,u16 height);

/*! \brief Set viewport.

This function sets the viewport.<br/>
The origin (0,0) of the normalized device coordinate points to the center of the screen.<br/> 
Performing viewport conversion, where the upper left corner is the origin is as follows:
\code
	x = X;
	y = Y;
	width = WIDTH;
	height = HEIGHT;
	min = 0.0f;
	max = 1.0f;
	scale[0] = width * 0.5f;
	scale[1] = height * 0.5f;
	scale[2] = (max - min) * 0.5f;
	offset[0] = x + width * 0.5f;
	offset[1] = y + height * 0.5f;
	offset[2] = (max + min) * 0.5f;
\endcode
<br/><br/>
Performing viewport conversion, where the lower left corner is the origin is as follows (this is equivalent to glViewport):
\code
	x = X;
	y = WINDOW_HEIGHT - Y - HEIGHT;
	width = WIDTH;
	height = HEIGHT;
	min = 0.0f;
	max = 1.0f;
	scale[0] = width * 0.5f;
	scale[1] = height * -0.5f;
	scale[2] = (max - min) * 0.5f;
	offset[0] = x + width * 0.5f;
	offset[1] = y + height * 0.5f;
	offset[2] = (max + min) * 0.5f;
\endcode
\param context Pointer to the context object.
\param x Origin of the viewport rectangle in pixels (0 - 4095). Initial value is (0,0).
\param y Origin of the viewport rectangle in pixels (0 - 4095). Initial value is (0,0).
\param width Width of the viewport (0 - 4096). Initial value is 4096.
\param height Height of the viewport (0 - 4096). Initial value is 4096.
\param min Minimum Z clip value. Initial value is 0.0.
\param max Maximum Z clip value. Initial value is 1.0.
\param scale Scale values to be used for viewport conversion. Initial values are (2048.0,2048.0,0.5,0.0).
\param offset Offset values to be used for viewport conversion. Initial values are (2048.0,2048.0,0.5,0.0).
*/
void RSX_FUNC(SetViewport)(gcmContextData *context,u16 x,u16 y,u16 width,u16 height,f32 min,f32 max,const f32 scale[4],const f32 offset[4]);

/*! \brief Invalidates a texture cache.
\param context Pointer to the context object.
\param type Type of texture cache to be invalidated. Possible values are:
 - \ref GCM_INVALIDATE_TEXTURE
 - \ref GCM_INVALIDATE_VERTEX_TEXTURE
*/
void RSX_FUNC(InvalidateTextureCache)(gcmContextData *context,u32 type);

void RSX_FUNC(InvalidateVertexCache)(gcmContextData *context);

/*! \brief Loads a texture.
\param context Pointer to the context object.
\param index Texture index.
\param texture Pointer to the texture data.
*/
void RSX_FUNC(LoadTexture)(gcmContextData *context,u8 index,const gcmTexture *texture);

/*! \brief Set texture control parameters.
\param context Pointer to the context object.
\param index Texture index.
\param enable Enable flag. Possible values are:
 - \ref GCM_TRUE
 - \ref GCM_FALSE
\param minlod minimum level of detail.
\param maxlod maximum level of detail.
\param maxaniso sample level of the anisotropic filter. Possible values are:
 - \ref GCM_TEXTURE_MAX_ANISO_1
 - \ref GCM_TEXTURE_MAX_ANISO_2
 - \ref GCM_TEXTURE_MAX_ANISO_4
 - \ref GCM_TEXTURE_MAX_ANISO_6
 - \ref GCM_TEXTURE_MAX_ANISO_8
 - \ref GCM_TEXTURE_MAX_ANISO_10
 - \ref GCM_TEXTURE_MAX_ANISO_12
 - \ref GCM_TEXTURE_MAX_ANISO_16
\todo finish args documentation.
*/
void RSX_FUNC(TextureControl)(gcmContextData *context,u8 index,u32 enable,u16 minlod,u16 maxlod,u8 maxaniso);
void RSX_FUNC(TextureFilter)(gcmContextData *context,u8 index,u16 bias,u8 min,u8 mag,u8 conv);
void RSX_FUNC(TextureWrapMode)(gcmContextData *context,u8 index,u8 wraps,u8 wrapt,u8 wrapr,u8 unsignedRemap,u8 zfunc,u8 gamma);
void RSX_FUNC(TextureBorderColor)(gcmContextData *context,u8 index,u32 color);
void RSX_FUNC(TextureOptimization)(gcmContextData *context,u8 index,u8 slope,u8 iso,u8 aniso);
void RSX_FUNC(TextureAnisoSpread)(gcmContextData *context,u8 index,u8 reduceSamplesEnable,u8 hReduceSamplesEnable,u8 vReduceSamplesEnable,u8 spacingSelect,u8 hSpacingSelect,u8 vSpacingSelect);


void RSX_FUNC(LoadVertexTexture)(gcmContextData *context,u8 index,const gcmTexture *texture);
void RSX_FUNC(VertexTextureControl)(gcmContextData *context,u8 index,u32 enable,u16 minlod,u16 maxlod);
void RSX_FUNC(VertexTextureFilter)(gcmContextData *context,u8 index,u16 bias);
void RSX_FUNC(VertexTextureWrapMode)(gcmContextData *context,u8 index,u8 wraps,u8 wrapt);
void RSX_FUNC(VertexTextureBorderColor)(gcmContextData *context,u8 index,u32 color);

/*! \brief Load a compiled vertex shader program.
\param context Pointer to the context object
\param program Pointer to the vertex program configuration
\param ucode Pointer to the shader micro code
*/
void RSX_FUNC(LoadVertexProgram)(gcmContextData *context,const rsxVertexProgram *program,const void *ucode);

/*! \brief Load a compiled fragment shader program.
\param context Pointer to the context object
\param program Pointer to the fragment program configuration
\param offset Memory offset of fragment program
\param location Memory location type where the program relies. Possible values are:
- \ref GCM_LOCATION_RSX
- \ref GCM_LOCATION_CELL
*/
void RSX_FUNC(LoadFragmentProgramLocation)(gcmContextData *context,const rsxFragmentProgram *program,u32 offset,u32 location);
void RSX_FUNC(UpdateFragmentProgramLocation)(gcmContextData *context,u32 offset,u32 location);
void RSX_FUNC(SetFragmentProgramControl)(gcmContextData *context,const rsxFragmentProgram *program,u8 allowTex,u8 reserved0,u8 reserved1);
void RSX_FUNC(LoadVertexProgramBlock)(gcmContextData *context,const rsxVertexProgram *program,const void *ucode);
void RSX_FUNC(LoadVertexProgramParameterBlock)(gcmContextData *context,u32 base_const,u32 const_cnt,const f32 *value); 
void RSX_FUNC(SetVertexProgramParameter)(gcmContextData *context,const rsxVertexProgram *program,const rsxProgramConst *param,const f32 *value);
void RSX_FUNC(SetVertexProgramConstants)(gcmContextData *context,u32 start,u32 count,const f32 *data);
void RSX_FUNC(SetFragmentProgramParameter)(gcmContextData *context,const rsxFragmentProgram *program,const rsxProgramConst *param,const f32 *value,u32 offset,u32 location);
void RSX_FUNC(DrawVertexArray)(gcmContextData *context,u32 type,u32 start,u32 count);
void RSX_FUNC(BindVertexArrayAttrib)(gcmContextData *context,u8 attr,u16 frequency,u32 offset,u8 stride,u8 elems,u8 dtype,u8 location);
void RSX_FUNC(DrawIndexArray)(gcmContextData *context,u8 type,u32 offset,u32 count,u8 data_type,u8 location);
void RSX_FUNC(DrawInlineIndexArray16)(gcmContextData *context,u8 type,u32 start,u32 count,const u16 *data);
void RSX_FUNC(DrawInlineIndexArray32)(gcmContextData *context,u8 type,u32 start,u32 count,const u32 *data);
void RSX_FUNC(InlineTransfer)(gcmContextData *context,u32 dstOffset,const void *srcAddress,u32 sizeInWords,u8 location);
void RSX_FUNC(SetUserClipPlaneControl)(gcmContextData *context,u32 plane0,u32 plane1,u32 plane2,u32 plane3,u32 plane4,u32 plane5);
void RSX_FUNC(SetAlphaFunc)(gcmContextData *context,u32 alphaFunc,u32 ref);
void RSX_FUNC(SetAlphaTestEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetBlendEnableMrt)(gcmContextData *context, u32 mrt1, u32 mrt2, u32 mrt3);
void RSX_FUNC(SetBlendOptimization)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetLogicOp)(gcmContextData *context,u32 op);
void RSX_FUNC(SetLogicOpEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetFogMode)(gcmContextData *context,u32 mode);
void RSX_FUNC(SetFogParams)(gcmContextData *context,f32 p0,f32 p1);
void RSX_FUNC(SetZMinMaxControl)(gcmContextData *context,u8 cullNearFar,u8 zClampEnable,u8 cullIgnoreW);
void RSX_FUNC(SetZPixelCountEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetVertexAttribOutputMask)(gcmContextData *context,u32 mask);
void RSX_FUNC(SetFrequencyDividerOperation)(gcmContextData *context,u16 operation);
void RSX_FUNC(SetFragmentProgramGammaEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetRestartIndexEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetRestartIndex)(gcmContextData *context,u32 index);
void RSX_FUNC(SetDepthBoundsTestEnable)(gcmContextData *context,u32 enable);
void RSX_FUNC(SetDepthBounds)(gcmContextData *context,f32 zMin,f32 zMax);

/*! \brief Specify pixel arithmetic.

In RGBA mode, pixels can be drawn using a function that blends the incoming
(source) RGBA values with the RGBA values that are already in the frame buffer
(the destination values). Blending is initially disabled.
Use \ref rsxSetBlendEnable to enable and disable blending.

\c rsxSetBlendFunc defines the operation of blending when it is enabled.
\p sfcolor and and \p sfalpha specify which method is used to scale the source
color and alpha components.
\p dfcolor and and \p dfalpha specify which method is used to scale the
destination color and alpha components.
The possible methods are described in the following table.
Each method defines four scale factors, one each for red, green, blue, and
alpha.
In the table and in subsequent equations, source and destination color
components are referred to as R<sub>s</sub>, G<sub>s</sub>, B<sub>s</sub>,
A<sub>s</sub> and R<sub>d</sub>, G<sub>d</sub>, B<sub>d</sub>, A<sub>d</sub>,
respectively.
The color specified by \ref rsxSetBlendColor is referred to as
R<sub>c</sub>, G<sub>c</sub>, B<sub>c</sub>, A<sub>c</sub>.
They are understood to have integer values between 0 and
k<sub>R</sub>, k<sub>G</sub>, k<sub>B</sub>, k<sub>A</sub>, where

k<sub>c</sub> = 2<sup>m<sub>c</sub></sup> - 1

and m<sub>R</sub>, m<sub>G</sub>, m<sub>B</sub>, m<sub>A</sub> is the number of
red, green, blue, and alpha bitplanes.

Source and destination scale factors are referred to as
s<sub>R</sub>, s<sub>G</sub>, s<sub>B</sub>, s<sub>A</sub> and d<sub>R</sub>,
d<sub>G</sub>, d<sub>B</sub>, d<sub>A</sub>.
The scale factors described in the table, denoted f<sub>R</sub>, f<sub>G</sub>,
f<sub>B</sub>, f<sub>A</sub>, represent either source or destination
factors. All scale factors have range [0,1].

<table>
<tr><th>Parameter                        </th><th>f<sub>R</sub>                </th><th>f<sub>G</sub>                </th><th>f<sub>B</sub>                </th><th>f<sub>A</sub>                </th></tr>
<tr><td>\ref GCM_ZERO                    </td><td>0                            </td><td>0                            </td><td>0                            </td><td>0                            </td></tr>
<tr><td>\ref GCM_ONE                     </td><td>1                            </td><td>1                            </td><td>1                            </td><td>1                            </td></tr>
<tr><td>\ref GCM_SRC_COLOR               </td><td>R<sub>s</sub>/k<sub>R</sub>  </td><td>G<sub>s</sub>/k<sub>G</sub>  </td><td>B<sub>s</sub>/k<sub>B</sub>  </td><td>A<sub>s</sub>/k<sub>A</sub>  </td></tr>
<tr><td>\ref GCM_ONE_MINUS_SRC_COLOR     </td><td>1-R<sub>s</sub>/k<sub>R</sub></td><td>1-G<sub>s</sub>/k<sub>G</sub></td><td>1-B<sub>s</sub>/k<sub>B</sub></td><td>1-A<sub>s</sub>/k<sub>A</sub></td></tr>
<tr><td>\ref GCM_DST_COLOR               </td><td>R<sub>d</sub>/k<sub>R</sub>  </td><td>G<sub>d</sub>/k<sub>G</sub>  </td><td>B<sub>d</sub>/k<sub>B</sub>  </td><td>A<sub>d</sub>/k<sub>A</sub>  </td></tr>
<tr><td>\ref GCM_ONE_MINUS_DST_COLOR     </td><td>1-R<sub>d</sub>/k<sub>R</sub></td><td>1-G<sub>d</sub>/k<sub>G</sub></td><td>1-B<sub>d</sub>/k<sub>B</sub></td><td>1-A<sub>d</sub>/k<sub>A</sub></td></tr>
<tr><td>\ref GCM_SRC_ALPHA               </td><td>A<sub>s</sub>/k<sub>A</sub>  </td><td>A<sub>s</sub>/k<sub>A</sub>  </td><td>A<sub>s</sub>/k<sub>A</sub>  </td><td>A<sub>s</sub>/k<sub>A</sub>  </td></tr>
<tr><td>\ref GCM_ONE_MINUS_SRC_ALPHA     </td><td>1-A<sub>s</sub>/k<sub>A</sub></td><td>1-A<sub>s</sub>/k<sub>A</sub></td><td>1-A<sub>s</sub>/k<sub>A</sub></td><td>1-A<sub>s</sub>/k<sub>A</sub></td></tr>
<tr><td>\ref GCM_DST_ALPHA               </td><td>A<sub>d</sub>/k<sub>A</sub>  </td><td>A<sub>d</sub>/k<sub>A</sub>  </td><td>A<sub>d</sub>/k<sub>A</sub>  </td><td>A<sub>d</sub>/k<sub>A</sub>  </td></tr>
<tr><td>\ref GCM_ONE_MINUS_DST_ALPHA     </td><td>1-A<sub>d</sub>/k<sub>A</sub></td><td>1-A<sub>d</sub>/k<sub>A</sub></td><td>1-A<sub>d</sub>/k<sub>A</sub></td><td>1-A<sub>d</sub>/k<sub>A</sub></td></tr>
<tr><td>\ref GCM_CONSTANT_COLOR          </td><td>R<sub>c</sub>                </td><td>G<sub>c</sub>                </td><td>B<sub>c</sub>                </td><td>A<sub>c</sub>                </td></tr>
<tr><td>\ref GCM_ONE_MINUS_CONSTANT_COLOR</td><td>1-R<sub>c</sub>              </td><td>1-G<sub>c</sub>              </td><td>1-B<sub>c</sub>              </td><td>1-A<sub>c</sub>              </td></tr>
<tr><td>\ref GCM_CONSTANT_ALPHA          </td><td>A<sub>c</sub>                </td><td>A<sub>c</sub>                </td><td>A<sub>c</sub>                </td><td>A<sub>c</sub>                </td></tr>
<tr><td>\ref GCM_ONE_MINUS_CONSTANT_ALPHA</td><td>1-A<sub>c</sub>              </td><td>1-A<sub>c</sub>              </td><td>1-A<sub>c</sub>              </td><td>1-A<sub>c</sub>              </td></tr>
<tr><td>\ref GCM_SRC_ALPHA_SATURATE      </td><td>i                            </td><td>i                            </td><td>i                            </td><td>1                            </td></tr>
</table>
In the table,

i = min(A<sub>s</sub>/k<sub>A</sub>, 1 - A<sub>d</sub>/k<sub>A</sub>)

To determine the blended RGBA values of a pixel when drawing in RGBA mode,
the equation defined by \ref rsxSetBlendEquation us used. In the default mode
(\ref GCM_FUNC_ADD for RGB and alpha equations), the equations are the
following:

 - R<sub>d</sub> = min(k<sub>R</sub>, R<sub>s</sub>s<sub>R</sub> + R<sub>d</sub>d<sub>R</sub>)
 - G<sub>d</sub> = min(k<sub>G</sub>, G<sub>s</sub>s<sub>G</sub> + G<sub>d</sub>d<sub>G</sub>)
 - B<sub>d</sub> = min(k<sub>B</sub>, B<sub>s</sub>s<sub>B</sub> + B<sub>d</sub>d<sub>B</sub>)
 - A<sub>d</sub> = min(k<sub>A</sub>, A<sub>s</sub>s<sub>A</sub> + A<sub>d</sub>d<sub>A</sub>)

Despite the apparent precision of the above equations, blending arithmetic is
not exactly specified, because blending operates with imprecise integer color
values.
However, a blend factor that should be equal to 1 is guaranteed not to modify
its multiplicand, and a blend factor equal to 0 reduces its multiplicand to 0.
For example, when \p sfcolor is \ref GCM_SRC_ALPHA, \p fdcolor is
\ref GCM_ONE_MINUS_SRC_ALPHA, and A<sub>s</sub> is equal to k<sub>A</sub>,
the equations reduce to simple replacement:

R<sub>d</sub> = R<sub>s</sub> ;
G<sub>d</sub> = G<sub>s</sub> ;
B<sub>d</sub> = B<sub>s</sub>

\par Examples

Transparency is best implemented using blend function
(\p sfcolor = \p sfalpha = \ref GCM_SRC_ALPHA,
\p dfcolor = \p dfalpha = \ref GCM_ONE_MINUS_SRC_ALPHA) with primitives sorted from
farthest to nearest. Note that this transparency calculation does not require
the presence of alpha bitplanes in the frame buffer.

Blend function (\ref GCM_SRC_ALPHA, \ref GCM_ONE_MINUS_SRC_ALPHA) is also useful
for rendering antialiased points and lines in arbitrary order.

Polygon antialiasing is optimized using blend function
(\ref GCM_SRC_ALPHA_SATURATE, \ref GCM_ONE) with polygons sorted from nearest
to farthest. <!-- (See the glEnable, glDisable reference page and the GL_POLYGON_SMOOTH
argument for information on polygon antialiasing.) -->
Destination alpha bitplanes, which must be present for this blend function to
operate correctly, store the accumulated coverage.

\par Notes

Incoming (source) alpha is correctly thought of as a material opacity, ranging
from 1.0 ( k<sub>A</sub> ), representing complete opacity, to 0.0 (0),
representing complete transparency.


\param context Pointer to the context object
\param sfcolor Specifies how the red, green, and blue source blending factors are computed.
\param dfcolor Specifies how the red, green, and blue source blending factors are computed.
\param sfalpha Specifies how the alpha source blending factor is computed.
\param dfalpha Specifies how the alpha destination blending factor is computed.
*/
void RSX_FUNC(SetBlendFunc)(gcmContextData *context,u16 sfcolor,u16 dfcolor,u16 sfalpha,u16 dfalpha);

/*! \brief Set the blend equation.

The blend equations determine how a new pixel (the &ldquo;source&rdquo; color)
is combined with a pixel already in the framebuffer (the
&ldquo;destination&rdquo; color).
This function specifies one blend equation for the RGB-color components
and one blend equation for the alpha component.

These equations use the source and destination blend factors specified by
\ref rsxSetBlendFunc. See \ref rsxSetBlendFunc for a description of the various
blend factors.

In the equations that follow, source and destination color components are
referred to as R<sub>s</sub>, G<sub>s</sub>, B<sub>s</sub>, A<sub>s</sub>
and R<sub>d</sub>, G<sub>d</sub>, B<sub>d</sub>, A<sub>d</sub>, respectively.
The result color is referred to as R<sub>r</sub>, G<sub>r</sub>, B<sub>r</sub>,
A<sub>r</sub>.
The source and destination blend factors are denoted
s<sub>R</sub>, s<sub>G</sub>, s<sub>B</sub>, s<sub>A</sub> and d<sub>R</sub>,
d<sub>G</sub>, d<sub>B</sub>, d<sub>A</sub>, respectively.
For these equations all color components are understood to have values in the
range [0,1].

<table>
<tr><th>Mode                          </th><th>R<sub>r</sub>                                        </th><th>G<sub>r</sub>                                        </th><th>B<sub>r</sub>                                        </th><th>A<sub>r</sub>                                        </th></tr>
<tr><td>\ref GCM_FUNC_ADD             </td><td>R<sub>s</sub>s<sub>R</sub>+R<sub>d</sub>d<sub>R</sub></td><td>G<sub>s</sub>s<sub>G</sub>+G<sub>d</sub>d<sub>G</sub></td><td>B<sub>s</sub>s<sub>B</sub>+B<sub>d</sub>d<sub>B</sub></td><td>A<sub>s</sub>s<sub>A</sub>+A<sub>d</sub>d<sub>A</sub></td></tr>
<tr><td>\ref GCM_MIN                  </td><td>min(R<sub>s</sub>,R<sub>d</sub>)                     </td><td>min(G<sub>s</sub>,G<sub>d</sub>)                     </td><td>min(B<sub>s</sub>,B<sub>d</sub>)                     </td><td>min(A<sub>s</sub>,A<sub>d</sub>)                     </td></tr>
<tr><td>\ref GCM_MAX                  </td><td>max(R<sub>s</sub>,R<sub>d</sub>)                     </td><td>max(G<sub>s</sub>,G<sub>d</sub>)                     </td><td>max(B<sub>s</sub>,B<sub>d</sub>)                     </td><td>max(A<sub>s</sub>,A<sub>d</sub>)                     </td></tr>
<tr><td>\ref GCM_FUNC_SUBTRACT        </td><td>R<sub>s</sub>s<sub>R</sub>-R<sub>d</sub>d<sub>R</sub></td><td>G<sub>s</sub>s<sub>G</sub>-G<sub>d</sub>d<sub>G</sub></td><td>B<sub>s</sub>s<sub>B</sub>-B<sub>d</sub>d<sub>B</sub></td><td>A<sub>s</sub>s<sub>A</sub>-A<sub>d</sub>d<sub>A</sub></td></tr>
<tr><td>\ref GCM_FUNC_REVERSE_SUBTRACT</td><td>R<sub>d</sub>d<sub>R</sub>-R<sub>s</sub>s<sub>R</sub></td><td>G<sub>d</sub>d<sub>G</sub>-G<sub>s</sub>s<sub>G</sub></td><td>B<sub>d</sub>d<sub>B</sub>-B<sub>s</sub>s<sub>B</sub></td><td>A<sub>d</sub>d<sub>A</sub>-A<sub>s</sub>s<sub>A</sub></td></tr>
</table>

The results of these equations are clamped to the range [0,1].

The \ref GCM_MIN and \ref GCM_MAX equations are useful for applications that
analyze image data (image thresholding against a constant color, for example).
The \ref GCM_FUNC_ADD equation is useful for antialiasing and transparency,
among other things.

Initially, both the RGB blend equation and the alpha blend equation are set
to \ref GCM_FUNC_ADD.

\par Notes

The \ref GCM_MIN, and \ref GCM_MAX equations do not use the source or
destination factors, only the source and destination colors.

\param context Pointer to the context object
\param color Specifies the RGB blend equation, how the red, green, and blue
components of the source and destination colors are combined.
\param alpha Specifies the alpha blend equation, how the alpha component of
the source and destination colors are combined.
*/
void RSX_FUNC(SetBlendEquation)(gcmContextData *context,u16 color,u16 alpha);


/*! \brief Set the blending constant color.
\param context Pointer to the context object
\param color0 all A, R, G, B components in 8-bit component mode
\param color1 reserved for 16-bit components
*/
void RSX_FUNC(SetBlendColor)(gcmContextData *context,u32 color0,u32 color1);

/*! \brief Enable or disable blending.
\param context Pointer to the context object
\param enable
  - \c GCM_TRUE : enable blending
  - \c GCM_FALSE : disable blending
*/
void RSX_FUNC(SetBlendEnable)(gcmContextData *context,u32 enable);

void RSX_FUNC(SetTransformBranchBits)(gcmContextData *context,u32 branchBits);

/*! \brief Configuration the mode for an upcoming asynchronous RSX DMA transfer.
\param context Pointer to the context object
\param mode Specify source and destination memory areas. Possible values are:
- \ref GCM_TRANSFER_LOCAL_TO_LOCAL
- \ref GCM_TRANSFER_MAIN_TO_LOCAL
- \ref GCM_TRANSFER_LOCAL_TO_MAIN
- \ref GCM_TRANSFER_MAIN_TO_MAIN
*/
void RSX_FUNC(SetTransferDataMode)(gcmContextData *context,u8 mode);

/*! \brief Specify the memory locations for an RSX DMA transfer. This function should be called after rsxSetTransferDataMode() and rsxSetTransferDataFormat().
\param context Pointer to the context object
\param dst Destination memory offset, e.g., a value returned by gcmAddressToOffset() or gcmMapMainMemory().
\param src Source memory offset, e.g., a value returned by gcmAddressToOffset() or gcmMapMainMemory().
*/
void RSX_FUNC(SetTransferDataOffset)(gcmContextData *context,u32 dst,u32 src);

/*! \brief Format an upcoming asynchronous RSX DMA transfer.
\param context Pointer to the context object
\param inpitch Pitch size, in bytes, of the source buffer (e.g., for a buffer that represents a rectangular image, this would be the width multiplied by the number of bytes in each pixel).
\param outpitch Pitch size, in bytes, of the destination buffer (e.g., for a buffer that represents a rectangular image, this would be the width multiplied by the number of bytes in each pixel).
\param linelength Size, in bytes, of each line of data that will be transfered.
\param linecount Number of lines of data to transfer.
\param inbytes Number of bytes for each block (e.g., pixel) of data to be transfered: 1, 2, or 4. Will perform scatter-gather transfer if different from outbytes.
\param outbytes Number of bytes for each block (e.g., pixel) of data to be transfered: 1, 2, or 4. Will perform scatter-gather transfer if different from inbytes.
*/
void RSX_FUNC(SetTransferDataFormat)(gcmContextData *context,s32 inpitch,s32 outpitch,u32 linelength,u32 linecount,u8 inbytes,u8 outbytes);

/*! \brief Initiate an asynchronous RSX DMA transfer.
\param context Pointer to the context object
\param mode Specify source and destination memory areas. Possible values are:
- \ref GCM_TRANSFER_LOCAL_TO_LOCAL
- \ref GCM_TRANSFER_MAIN_TO_LOCAL
- \ref GCM_TRANSFER_LOCAL_TO_MAIN
- \ref GCM_TRANSFER_MAIN_TO_MAIN
\param dst Destination memory offset, e.g., a value returned by gcmAddressToOffset() or gcmMapMainMemory().
\param outpitch Pitch size, in bytes, of the destination buffer (e.g., for a buffer that represents a rectangular image, this would be the width multiplied by the number of bytes in each pixel).
\param src Source memory offset, e.g., a value returned by gcmAddressToOffset() or gcmMapMainMemory().
\param inpitch Pitch size, in bytes, of the source buffer (e.g., for a buffer that represents a rectangular image, this would be the width multiplied by the number of bytes in each pixel).
\param linelength Size, in bytes, of each line of data that will be transfered.
\param linecount Number of lines of data to transfer.
*/
void RSX_FUNC(SetTransferData)(gcmContextData *context,u8 mode,u32 dst,u32 outpitch,u32 src,u32 inpitch,u32 linelength,u32 linecount);

/*! \brief Configure an upcoming asynchronous RSX blit.
\param context Pointer to the context object
\param mode Specify source and destination memory areas. Possible values are:
- \ref GCM_TRANSFER_LOCAL_TO_LOCAL
- \ref GCM_TRANSFER_MAIN_TO_LOCAL
- \ref GCM_TRANSFER_LOCAL_TO_MAIN
- \ref GCM_TRANSFER_MAIN_TO_MAIN
\param surface Transfer surface mode. Possible values are:
- \ref GCM_TRANSFER_SURFACE
- \ref GCM_TRANSFER_SWIZZLE
*/
void RSX_FUNC(SetTransferScaleMode)(gcmContextData *context,u8 mode,u8 surface);

/*! \brief Initiate an asynchronous RSX blit.
\param context Pointer to the context object
\param scale Specify the transfer geometry & parameters.
\param surface Specify the surface to blit to.
*/
void RSX_FUNC(SetTransferScaleSurface)(gcmContextData *context,const gcmTransferScale *scale,const gcmTransferSurface *surface);

/*! \brief Initialiate an asynchronous transfer of a rectangular image from one area of memory to another.
\param context Pointer to the context object
\param mode Specify source and destination memory areas. Possible values are:
- \ref GCM_TRANSFER_LOCAL_TO_LOCAL
- \ref GCM_TRANSFER_MAIN_TO_LOCAL
- \ref GCM_TRANSFER_LOCAL_TO_MAIN
- \ref GCM_TRANSFER_MAIN_TO_MAIN
\param dstOffset Destination memory offset, e.g., a value returned by gcmAddressToOffset() or gcmMapMainMemory().
\param dstPitch Pitch size, in bytes, of the destination image data (width multiplied by the number of bytes in each pixel).
\param dstX Origin of the destination data, relative to the beginning of the destination buffer.
\param dstY Origin of the destination data, relative to the beginning of the destination buffer.
\param srcOffset Source memory offset, e.g., a value returned by gcmAddressToOffset() or gcmMapMainMemory().
\param srcPitch Pitch size, in bytes, of the source image data (width multiplied by the number of bytes in each pixel).
\param srcX Origin of the source rectangle, relative to the beginning of the source buffer.
\param srcY Origin of the source rectangle, relative to the beginning of the source buffer.
\param width Width of the transfer rectangle.
\param height Height of the transfer rectangle.
\param bytesPerPixel Number of bytes per pixel to transfer: 2 or 4.
*/
void RSX_FUNC(SetTransferImage)(gcmContextData *context,u8 mode,u32 dstOffset,u32 dstPitch,u32 dstX,u32 dstY,u32 srcOffset,u32 srcPitch,u32 srcX,u32 srcY,u32 width,u32 height,u32 bytesPerPixel);
void RSX_FUNC(SetTimeStamp)(gcmContextData *context,u32 index);

void RSX_FUNC(SetConvertSwizzleFormat)(gcmContextData *context,u32 dstOffset,u32 dstWidth,u32 dstHeight,u32 dstX,u32 dstY,u32 srcOffset,u32 srcPitch,u32 srcX,u32 srcY,u32 width,u32 height,u32 bytesPerPixel,u32 mode);

void RSX_FUNC(SetTransferScaleSwizzle)(gcmContextData *context,const gcmTransferScale *scale,const gcmTransferSwizzle *swizzle);

void RSX_FUNC(SetWaitForIdle)(gcmContextData *context);

/*! \brief Flushes the RSX command buffer.

This ensures all remaining commands in the command buffer are executed, and
that the buffer is empty when that function returns.
\param context Pointer to the context object.
*/
void RSX_FUNC(FlushBuffer)(gcmContextData *context);

/*! \brief Reset the RSX command buffer.
\param context Pointer to the context object.
*/
void RSX_FUNC(ResetCommandBuffer)(gcmContextData *context);
void RSX_FUNC(Finish)(gcmContextData *context,u32 ref_value);
