/*
 * lane_departure_dt.h
 *
 * Code generation for model "lane_departure".
 *
 * Model version              : 1.268
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sat Mar 17 01:21:50 2018
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
  sizeof(LaneDetection_MdlrefDW)
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
  "LaneDetection_MdlrefDW"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&rtB.TmpRTBAtLaneDetectionInport1[0]), 3, 0, 76800 },

  { (char_T *)(&rtB.LaneDetection_o2[0]), 0, 0, 6 },

  { (char_T *)(&rtB.LaneDetection_o1[0]), 6, 0, 24 },

  { (char_T *)(&rtB.V4L2VideoCapture_o1[0]), 3, 0, 247541 },

  { (char_T *)(&rtB.LaneDetection_o4[0]), 8, 0, 17141 }
  ,

  { (char_T *)(&rtDW.FrameRateDisplay_PrevTime), 0, 0, 3 },

  { (char_T *)(&rtDW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&rtDW.LaneDetection_DWORK1), 14, 0, 1 },

  { (char_T *)(&rtDW.LaneDetection_DIMS1[0]), 6, 0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&rtP.DummySupporLefttLine_Value[0]), 0, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] lane_departure_dt.h */
