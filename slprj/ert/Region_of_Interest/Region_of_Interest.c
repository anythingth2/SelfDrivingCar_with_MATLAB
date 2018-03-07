/*
 * File: Region_of_Interest.c
 *
 * Code generated for Simulink model 'Region_of_Interest'.
 *
 * Model version                  : 1.111
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Mar 08 01:06:26 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Region_of_Interest.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

/* Output and update for referenced model: 'Region_of_Interest' */
void Region_of_Interest(const uint8_T rtu_Image[76800], const real_T rtu_ROI_X
  [261], const real_T rtu_ROI_Y[61], uint8_T rty_MaskedImage[15921])
{
  int32_T i;
  int32_T i_0;

  /* Selector: '<Root>/Selector1' */
  for (i_0 = 0; i_0 < 261; i_0++) {
    for (i = 0; i < 61; i++) {
      rty_MaskedImage[i + 61 * i_0] = rtu_Image[(((int32_T)rtu_ROI_X[i_0] - 1) *
        240 + (int32_T)rtu_ROI_Y[i]) - 1];
    }
  }

  /* End of Selector: '<Root>/Selector1' */
}

/* Model initialize function */
void Region_of_Interest_initialize(const char_T **rt_errorStatus,
  Region_of_Interest_RT_MODEL *const Region_of_InterestrtM)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(Region_of_InterestrtM, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
