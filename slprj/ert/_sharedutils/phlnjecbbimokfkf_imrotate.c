/*
 * File: phlnjecbbimokfkf_imrotate.c
 *
 * Code generated for Simulink model 'lane_departure'.
 *
 * Model version                  : 1.261
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Mar 17 00:07:09 2018
 */

#include "rtwtypes.h"
#include "phlnjecbbimokfkf_imrotate.h"

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
void phlnjecbbimokfkf_imrotate(const uint8_T varargin_1[76800], uint8_T B_0
  [76800])
{
  int32_T i;
  int32_T j;
  for (i = 0; i < 240; i++) {
    for (j = 0; j < 320; j++) {
      B_0[i + 240 * j] = varargin_1[(239 - i) * 320 + j];
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
