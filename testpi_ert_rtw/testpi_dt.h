/*
 * testpi_dt.h
 *
 * Code generation for model "testpi".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun Dec 31 19:55:17 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(codertarget_linux_blocks_SDLVid)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int32_T",
  "int32_T",
  "codertarget_linux_blocks_SDLVid"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.V4L2VideoCapture_o1[0]), 3, 0, 384000 },

  { (char_T *)(&rtB.EdgeDetection[0]), 8, 0, 76800 }
  ,

  { (char_T *)(&rtDW.FrameRateDisplay_PrevTime), 0, 0, 3 },

  { (char_T *)(&rtDW.obj), 16, 0, 1 },

  { (char_T *)(&rtDW.MATLABSystem_PWORK), 11, 0, 1 },

  { (char_T *)(&rtDW.EdgeDetection_VO_DW[0]), 6, 0, 109 },

  { (char_T *)(&rtDW.ColorSpaceConversion_DWORK1[0]), 3, 0, 76800 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* [EOF] testpi_dt.h */
