/*
 * vipldws_dt.h
 *
 * Code generation for model "vipldws".
 *
 * Model version              : 1.2210
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun Dec 31 20:26:07 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
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
  sizeof(codertarget_linux_blocks_SDLV_T),
  sizeof(int16_T),
  sizeof(int8_T)
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
  "codertarget_linux_blocks_SDLV_T",
  "int16_T",
  "int8_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&vipldws_B.ColorSpaceConversion[0]), 1, 0, 1389300 },

  { (char_T *)(&vipldws_B.HoughTransform_o2[0]), 1, 0, 805 },

  { (char_T *)(&vipldws_B.Init[0]), 1, 0, 40 },

  { (char_T *)(&vipldws_B.KTrans[0]), 1, 0, 8 },

  { (char_T *)(&vipldws_B.Transpose_g[0]), 6, 0, 12 },

  { (char_T *)(&vipldws_B.Probe[0]), 0, 0, 3 },

  { (char_T *)(&vipldws_B.ImageDataTypeConversion[0]), 1, 0, 547684 },

  { (char_T *)(&vipldws_B.MatrixConcatenation2[0]), 1, 0, 409047 },

  { (char_T *)(&vipldws_B.DataTypeConversion1), 1, 0, 230468 },

  { (char_T *)(&vipldws_B.Init_p[0]), 6, 0, 214 },

  { (char_T *)(&vipldws_B.rho_1), 6, 0, 2060 },

  { (char_T *)(&vipldws_B.Minimum_o1), 6, 0, 7 },

  { (char_T *)(&vipldws_B.Minimum), 7, 0, 4 },

  { (char_T *)(&vipldws_B.FindLocalMaxima1_o1[0]), 5, 0, 26 },

  { (char_T *)(&vipldws_B.RawMessage), 2, 0, 9 },

  { (char_T *)(&vipldws_B.MatrixConcatenate[0]), 3, 0, 1612800 },

  { (char_T *)(&vipldws_B.Compare), 8, 0, 48080 }
  ,

  { (char_T *)(&vipldws_DW.obj), 16, 0, 1 },

  { (char_T *)(&vipldws_DW.MatrixConcatenation3_PWORK), 11, 0, 4 },

  { (char_T *)(&vipldws_DW.FixPtUnitDelay1_DSTATE[0]), 1, 0, 440 },

  { (char_T *)(&vipldws_DW.FixPtUnitDelay1_DSTATE_d[0]), 6, 0, 450 },

  { (char_T *)(&vipldws_DW.ColorSpaceConversion_DWORK1[0]), 1, 0, 430815 },

  { (char_T *)(&vipldws_DW.uDFIRFilter_bSEnd[0]), 6, 0, 156 },

  { (char_T *)(&vipldws_DW.FindLocalMaxima_NUMPEAKS_DWORK), 7, 0, 5 },

  { (char_T *)(&vipldws_DW.FromWorkspace_IWORK.PrevIndex), 10, 0, 1 },

  { (char_T *)(&vipldws_DW.Counter_Count), 5, 0, 1 },

  { (char_T *)(&vipldws_DW.Delay_DSTATE), 2, 0, 2 },

  { (char_T *)(&vipldws_DW.FixPtUnitDelay2_DSTATE), 3, 0, 2 },

  { (char_T *)(&vipldws_DW.Delay1_DSTATE_g[0]), 8, 0, 21 },

  { (char_T *)(&vipldws_DW.Enablesignalgenerator_SubsysRan), 2, 0, 9 },

  { (char_T *)(&vipldws_DW.DrawShapes_DW_PixCount[0]), 3, 0, 512 },

  { (char_T *)(&vipldws_DW.uDFIRFilter_isHgtUpd[0]), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  32U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&vipldws_P.DrawShapes_color[0]), 1, 0, 50 },

  { (char_T *)(&vipldws_P.CompareToConstant2_const), 6, 0, 12 },

  { (char_T *)(&vipldws_P.NSampleEnable_ActiveLevel), 7, 0, 2 },

  { (char_T *)(&vipldws_P.Counter_InitialCount), 5, 0, 1 },

  { (char_T *)(&vipldws_P.CompareToConstant_const_h), 2, 0, 8 },

  { (char_T *)(&vipldws_P.DrawShapes_color_e[0]), 3, 0, 3 },

  { (char_T *)(&vipldws_P.Constant1_Value), 0, 0, 2 },

  { (char_T *)(&vipldws_P.Constant3_Value[0]), 1, 0, 520 },

  { (char_T *)(&vipldws_P.ForIterator_IterationLimit), 6, 0, 541 },

  { (char_T *)(&vipldws_P.Delay1_DelayLength), 7, 0, 4 },

  { (char_T *)(&vipldws_P.Distancethresholdfordeparturewa), 14, 0, 2 },

  { (char_T *)(&vipldws_P.Bias2_Bias_k), 5, 0, 4 },

  { (char_T *)(&vipldws_P.Constant1_Value_b), 2, 0, 10 },

  { (char_T *)(&vipldws_P.FixPtUnitDelay2_InitialConditio), 3, 0, 5 },

  { (char_T *)(&vipldws_P.DrawPolygon_Value), 8, 0, 8 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  15U,
  rtPTransitions
};

/* [EOF] vipldws_dt.h */
