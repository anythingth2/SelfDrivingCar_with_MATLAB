/*
 * File: vipldws2_types.h
 *
 * Code generated for Simulink model 'vipldws2'.
 *
 * Model version                  : 1.2212
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Jan 01 14:33:11 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_vipldws2_types_h_
#define RTW_HEADER_vipldws2_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef typedef_codertarget_linux_blocks_SDLV_T
#define typedef_codertarget_linux_blocks_SDLV_T

typedef struct {
  int32_T isInitialized;
  int32_T PixelFormatEnum;
} codertarget_linux_blocks_SDLV_T;

#endif                                 /*typedef_codertarget_linux_blocks_SDLV_T*/

#ifndef typedef_struct_T_vipldws2_T
#define typedef_struct_T_vipldws2_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
  real_T f3[2];
} struct_T_vipldws2_T;

#endif                                 /*typedef_struct_T_vipldws2_T*/

/* Parameters (auto storage) */
typedef struct P_vipldws2_T_ P_vipldws2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_vipldws2_T RT_MODEL_vipldws2_T;

#endif                                 /* RTW_HEADER_vipldws2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
