/*
 * lane_departure_dt.h
 *
 * Code generation for model "lane_departure".
 *
 * Model version              : 1.64
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Feb 14 01:43:31 2018
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
  sizeof(codertarget_linux_blocks_SDLVid),
  sizeof(int32_T),
  sizeof(int16_T),
  sizeof(int16_T)
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
  "codertarget_linux_blocks_SDLVid",
  "int32_T",
  "int16_T",
  "int16_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.HoughTransform_o1[0]), 0, 0, 143820 },

  { (char_T *)(&rtB.HoughTransform_o2[0]), 0, 0, 979 },

  { (char_T *)(&rtB.HoughLines[0]), 6, 0, 12 },

  { (char_T *)(&rtB.V4L2VideoCapture_o1[0]), 3, 0, 230400 },

  { (char_T *)(&rtB.EdgeDetection[0]), 8, 0, 76800 }
  ,

  { (char_T *)(&rtDW.FrameRateDisplay_PrevTime), 0, 0, 143823 },

  { (char_T *)(&rtDW.obj), 16, 0, 1 },

  { (char_T *)(&rtDW.MATLABSystem_PWORK), 11, 0, 1 },

  { (char_T *)(&rtDW.Erosion_NUMNONZ_DW[0]), 6, 0, 133 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* [EOF] lane_departure_dt.h */
