/*
 * File: Region_of_Interest.h
 *
 * Code generated for Simulink model 'Region_of_Interest'.
 *
 * Model version                  : 1.116
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Mar 12 22:40:27 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Region_of_Interest_h_
#define RTW_HEADER_Region_of_Interest_h_
#ifndef Region_of_Interest_COMMON_INCLUDES_
# define Region_of_Interest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Region_of_Interest_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Forward declaration for rtModel */
typedef struct Region_of_Interest_tag_RTM Region_of_Interest_RT_MODEL;

/* Real-time Model Data Structure */
struct Region_of_Interest_tag_RTM {
  const char_T **errorStatus;
};

typedef struct {
  Region_of_Interest_RT_MODEL rtm;
} Region_of_Interest_MdlrefDW;

/* Model reference registration function */
extern void Region_of_Interest_initialize(const char_T **rt_errorStatus,
  Region_of_Interest_RT_MODEL *const Region_of_InterestrtM);
extern void Region_of_Interest(const uint8_T rtu_Image[76800], const real_T
  rtu_ROI_X[261], const real_T rtu_ROI_Y[61], uint8_T rty_MaskedImage[15921]);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Region_of_Interest'
 */
#endif                                 /* RTW_HEADER_Region_of_Interest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
