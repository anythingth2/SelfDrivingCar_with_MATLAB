/*
 * File: div_nde_s32_floor.c
 *
 * Code generated for Simulink model 'LaneDetection'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Mar 08 01:05:57 2018
 */

#include "rtwtypes.h"
#include "div_nde_s32_floor.h"

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
