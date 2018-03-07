/*
 * File: mul_s32_loSR.c
 *
 * Code generated for Simulink model 'LaneDetection'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Mar 08 01:05:57 2018
 */

#include "rtwtypes.h"
#include "mul_wide_s32.h"
#include "mul_s32_loSR.h"

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
