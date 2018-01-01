/*
 * File: vipldws_data.c
 *
 * Code generated for Simulink model 'vipldws'.
 *
 * Model version                  : 1.2210
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 31 20:26:07 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "vipldws.h"
#include "vipldws_private.h"

/* Block parameters (auto storage) */
P_vipldws_T vipldws_P = {
  /*  Mask Parameter: DrawShapes_color
   * Referenced by: '<S66>/DrawShapes'
   */
  { 0.0F, 1.0F, 1.0F },

  /*  Mask Parameter: uDFIRFilter_filterMtrx
   * Referenced by: '<S3>/2-D FIR Filter'
   */
  { -1.0F, 0.0F, 1.0F },
  0.2F,                                /* Mask Parameter: DrawShapes_opacity
                                        * Referenced by: '<S66>/DrawShapes'
                                        */
  1.0F,                                /* Mask Parameter: FindLocalMaxima1_threshold
                                        * Referenced by: '<S30>/Find Local Maxima1'
                                        */
  1.0F,                                /* Mask Parameter: FindLocalMaxima_threshold
                                        * Referenced by: '<S28>/Find Local Maxima'
                                        */
  1.0F,                                /* Mask Parameter: FindLocalMaxima1_threshold_b
                                        * Referenced by: '<S29>/Find Local Maxima1'
                                        */

  /*  Mask Parameter: UnitDelayResettable1_vinit
   * Referenced by:
   *   '<S36>/Initial Condition'
   *   '<S36>/FixPt Unit Delay1'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F },
  5,                                   /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S23>/Constant'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S56>/Constant'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant_const_m
                                        * Referenced by: '<S57>/Constant'
                                        */
  75,                                  /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S58>/Constant'
                                        */
  0,                                   /* Mask Parameter: CompareToConstant10_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  10,                                  /* Mask Parameter: CompareToConstant1_const_o
                                        * Referenced by: '<S18>/Constant'
                                        */
  5,                                   /* Mask Parameter: OnlyupdatethelineswhichKalmanfi
                                        * Referenced by: '<S34>/Constant'
                                        */
  1,                                   /* Mask Parameter: DrawShapes_lineWidth
                                        * Referenced by: '<S62>/DrawShapes'
                                        */
  1,                                   /* Mask Parameter: DrawShapes_lineWidth_i
                                        * Referenced by: '<S65>/DrawShapes'
                                        */

  /*  Mask Parameter: InsertText_textLoc
   * Referenced by: '<S65>/Insert Text'
   */
  { 2, 170 },
  0,                                   /* Mask Parameter: UnitDelayResettable_vinit
                                        * Referenced by:
                                        *   '<S35>/Initial Condition'
                                        *   '<S35>/FixPt Unit Delay1'
                                        */
  1U,                                  /* Mask Parameter: NSampleEnable_ActiveLevel
                                        * Referenced by: '<S5>/N-Sample Enable'
                                        */
  8U,                                  /* Mask Parameter: NSampleEnable_N
                                        * Referenced by: '<S5>/N-Sample Enable'
                                        */
  0U,                                  /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<S17>/Counter'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S21>/Constant'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S22>/Constant'
                                        */
  0,                                   /* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S61>/Constant'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S60>/Constant'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S10>/Constant'
                                        */
  2,                                   /* Mask Parameter: CompareToConstant2_const_h
                                        * Referenced by: '<S11>/Constant'
                                        */
  1,                                   /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S9>/Constant'
                                        */
  3,                                   /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S12>/Constant'
                                        */

  /*  Mask Parameter: DrawShapes_color_e
   * Referenced by: '<S62>/DrawShapes'
   */
  { 0U, 1U, 0U },
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S55>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */

  /*  Computed Parameter: Constant3_Value
   * Referenced by: '<S41>/Constant3'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    1.0F, 0.0F, 1.0F },

  /*  Computed Parameter: Hcst_Value
   * Referenced by: '<S41>/Hcst'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: Hcst_t_Value
   * Referenced by: '<S41>/Hcst_t'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F },

  /*  Computed Parameter: Constant2_Value
   * Referenced by: '<S41>/Constant2'
   */
  { 1.0F, 0.0F, 0.0F, 1.0F },

  /*  Computed Parameter: Constant4_Value
   * Referenced by: '<S41>/Constant4'
   */
  { 1.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F },

  /*  Computed Parameter: Constant5_Value
   * Referenced by: '<S41>/Constant5'
   */
  { 0.05F, 0.0F, 0.0F, 0.0F, 0.0F, 0.05F, 0.0F, 0.0F, 0.0F, 0.0F, 0.05F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.05F },

  /*  Computed Parameter: Reset_Value_Value
   * Referenced by: '<S42>/Reset_Value'
   */
  { 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F,
    100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F },

  /*  Computed Parameter: Reset_Value_Value_j
   * Referenced by: '<S43>/Reset_Value'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /*  Computed Parameter: Reset_Value_Value_b
   * Referenced by: '<S44>/Reset_Value'
   */
  { 0.0F, 0.0F },

  /*  Computed Parameter: Reset_Value_Value_p
   * Referenced by: '<S45>/Reset_Value'
   */
  { 0.0F, 0.0F },
  200.0F,                              /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S55>/Gain'
                                        */

  /*  Computed Parameter: DrawShapes_RTP_FILLCOLOR
   * Referenced by: '<S65>/DrawShapes'
   */
  { 1.0F, 1.0F, 1.0F, 0.0F, 0.0F, 1.0F },
  1.0F,                                /* Computed Parameter: InsertText_TxtOpacity
                                        * Referenced by: '<S65>/Insert Text'
                                        */

  /*  Computed Parameter: Yellow1_Value
   * Referenced by: '<S67>/Yellow1'
   */
  { 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.0F, 1.0F, 1.0F, 0.0F, 1.0F, 1.0F, 1.0F, 1.0F,
    1.0F, 1.0F },
  1.0F,                                /* Computed Parameter: InsertTextLeftLane_TxtOpacity
                                        * Referenced by: '<S67>/Insert Text: Left Lane'
                                        */
  1.0F,                                /* Computed Parameter: InsertTextRightLane_TxtOpacity
                                        * Referenced by: '<S67>/Insert Text: Right Lane'
                                        */
  1.0F,                                /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0.0F,                                /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S3>/Saturation'
                                        */

  /*  Computed Parameter: UnitDelay2_InitialCondition
   * Referenced by: '<S32>/Unit Delay2'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F },

  /*  Computed Parameter: UnitDelay3_InitialCondition
   * Referenced by: '<S32>/Unit Delay3'
   */
  { 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F,
    100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F,
    0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F,
    100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F,
    0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F,
    0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F,
    0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F,
    100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F,
    100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F,
    100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F,
    100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F,
    0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F,
    0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F,
    0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F,
    200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F,
    100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F,
    0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F,
    100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F,
    0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F,
    0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F,
    0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F,
    100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F,
    100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F,
    100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F,
    100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F,
    0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F,
    0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F,
    0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F,
    200.05F, 0.0F, 100.0F, 0.0F, 0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F,
    100.05F, 0.0F, 0.0F, 100.0F, 0.0F, 100.05F, 200.05F, 0.0F, 100.0F, 0.0F,
    0.0F, 200.05F, 0.0F, 100.0F, 100.0F, 0.0F, 100.05F, 0.0F, 0.0F, 100.0F, 0.0F,
    100.05F },
  0.0F,                                /* Expression: single(0)
                                        * Referenced by: '<S14>/min_safety'
                                        */
  20,                                  /* Computed Parameter: ForIterator_IterationLimit
                                        * Referenced by: '<S7>/For Iterator'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S25>/Constant'
                                        */
  32767,                               /* Computed Parameter: Min_left_dis_InitialCondition
                                        * Referenced by: '<S24>/Min_left_dis'
                                        */

  /*  Computed Parameter: Min_left_pts_InitialCondition
   * Referenced by: '<S24>/Min_left_pts'
   */
  { 0, 0, 0, 0 },
  32767,                               /* Computed Parameter: Min_right_dis_InitialCondition
                                        * Referenced by: '<S24>/Min_right_dis'
                                        */

  /*  Computed Parameter: Min_right_pts_InitialCondition
   * Referenced by: '<S24>/Min_right_pts'
   */
  { 0, 0, 0, 0 },
  20,                                  /* Computed Parameter: Iterator_IterationLimit
                                        * Referenced by: '<S39>/Iterator'
                                        */
  32767,                               /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S54>/Constant'
                                        */
  2,                                   /* Computed Parameter: ForIterator_IterationLimit_g
                                        * Referenced by: '<S54>/For Iterator'
                                        */

  /*  Computed Parameter: Constant2_Value_o
   * Referenced by: '<S53>/Constant2'
   */
  { 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767 },
  20,                                  /* Computed Parameter: ForIterator_IterationLimit_j
                                        * Referenced by: '<S50>/For Iterator'
                                        */
  32767,                               /* Computed Parameter: Constant_Value_iw
                                        * Referenced by: '<S51>/Constant'
                                        */
  2,                                   /* Computed Parameter: ForIterator_IterationLimit_n
                                        * Referenced by: '<S51>/For Iterator'
                                        */
  0,                                   /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S51>/Delay1'
                                        */

  /*  Computed Parameter: Minimum_prodDims
   * Referenced by: '<S51>/Minimum'
   */
  { 20, 0 },

  /*  Computed Parameter: Constant2_Value_d
   * Referenced by: '<S51>/Constant2'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /*  Computed Parameter: Constant1_Value_c
   * Referenced by: '<S51>/Constant1'
   */
  { 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767,
    32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767, 32767 },

  /*  Computed Parameter: Constant2_Value_b
   * Referenced by: '<S52>/Constant2'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  1,                                   /* Computed Parameter: Constant_Value_i0
                                        * Referenced by: '<S52>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S59>/Constant'
                                        */
  2,                                   /* Computed Parameter: ForIterator_IterationLimit_a
                                        * Referenced by: '<S52>/For Iterator'
                                        */
  -1,                                  /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S52>/Bias'
                                        */
  25,                                  /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S52>/Saturation'
                                        */
  0,                                   /* Computed Parameter: Saturation_LowerSat_o
                                        * Referenced by: '<S52>/Saturation'
                                        */
  20,                                  /* Computed Parameter: ForIterator_IterationLimit_gd
                                        * Referenced by: '<S37>/For Iterator'
                                        */

  /*  Computed Parameter: DSPConstant_Value
   * Referenced by: '<S69>/DSP Constant'
   */
  { 239, 0 },
  239,                                 /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S69>/Switch'
                                        */

  /*  Computed Parameter: DSPConstant2_Value
   * Referenced by: '<S69>/DSP Constant2'
   */
  { 239, 359 },
  239,                                 /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S69>/Switch1'
                                        */

  /*  Computed Parameter: Bias1_Bias
   * Referenced by: '<S67>/Bias1'
   */
  { -35, 0 },

  /*  Computed Parameter: Bias2_Bias
   * Referenced by: '<S67>/Bias2'
   */
  { -35, 0 },
  0,                                   /* Computed Parameter: En_Delay_InitialCondition
                                        * Referenced by: '<S32>/En_Delay'
                                        */
  -1,                                  /* Computed Parameter: Bias1_Bias_l
                                        * Referenced by: '<S1>/Bias1'
                                        */

  /*  Computed Parameter: DrawLines4_Value
   * Referenced by: '<S6>/Draw Lines4'
   */
  { 0, 0, 0, 0 },

  /*  Computed Parameter: Constant_Value_j
   * Referenced by: '<S8>/Constant'
   */
  { 0, -1, 1 },

  /*  Computed Parameter: Bias3_Bias
   * Referenced by: '<S5>/Bias3'
   */
  { 120, 0, 120, 0 },

  /*  Computed Parameter: Bias_Bias_i
   * Referenced by: '<S5>/Bias'
   */
  { 120, 0, 120, 0, 120, 0, 120, 0 },
  180,                                 /* Computed Parameter: Saturation_UpperSat_h
                                        * Referenced by: '<S14>/Saturation'
                                        */
  0,                                   /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S14>/Saturation'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S51>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_n
                                        * Referenced by: '<S52>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S17>/Delay'
                                        */
  1U,                                  /* Computed Parameter: Delay1_DelayLength_j
                                        * Referenced by: '<S17>/Delay1'
                                        */
  1717986918,                          /* Computed Parameter: Distancethresholdfordeparturewa
                                        * Referenced by: '<S1>/Distance threshold  for departure warning'
                                        */
  1073741824,                          /* Computed Parameter: rho_1_Gain
                                        * Referenced by: '<S1>/rho_1'
                                        */
  379U,                                /* Computed Parameter: Bias2_Bias_k
                                        * Referenced by: '<S29>/Bias2'
                                        */
  145U,                                /* Computed Parameter: Bias3_Bias_c
                                        * Referenced by: '<S29>/Bias3'
                                        */
  414U,                                /* Computed Parameter: Bias2_Bias_h
                                        * Referenced by: '<S30>/Bias2'
                                        */
  0U,                                  /* Computed Parameter: Bias3_Bias_d
                                        * Referenced by: '<S30>/Bias3'
                                        */
  1,                                   /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S6>/Constant1'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S6>/Constant'
                                        */
  1,                                   /* Computed Parameter: DrawLines3_Value
                                        * Referenced by: '<S6>/Draw Lines3'
                                        */
  0,                                   /* Computed Parameter: DrawLines2_Value
                                        * Referenced by: '<S6>/Draw Lines2'
                                        */
  1,                                   /* Computed Parameter: DrawLines1_Value
                                        * Referenced by: '<S6>/Draw Lines1'
                                        */
  2,                                   /* Computed Parameter: DrawLines_Value
                                        * Referenced by: '<S6>/Draw Lines'
                                        */
  1,                                   /* Computed Parameter: Bias_Bias_d
                                        * Referenced by: '<S65>/Bias'
                                        */
  1,                                   /* Computed Parameter: Bias1_Bias_e
                                        * Referenced by: '<S65>/Bias1'
                                        */
  -1,                                  /* Expression: int8(-1)
                                        * Referenced by: '<S17>/Delay'
                                        */
  -1,                                  /* Expression: int8(-1)
                                        * Referenced by: '<S17>/Delay1'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                        * Referenced by: '<S36>/FixPt Unit Delay2'
                                        */
  1U,                                  /* Computed Parameter: FixPtUnitDelay2_InitialCondit_p
                                        * Referenced by: '<S35>/FixPt Unit Delay2'
                                        */
  0U,                                  /* Computed Parameter: Switch_CurrentSetting
                                        * Referenced by: '<Root>/Switch'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S35>/FixPt Constant'
                                        */
  0U,                                  /* Computed Parameter: FixPtConstant_Value_e
                                        * Referenced by: '<S36>/FixPt Constant'
                                        */
  1,                                   /* Computed Parameter: DrawPolygon_Value
                                        * Referenced by: '<Root>/Draw Polygon'
                                        */
  0,                                   /* Computed Parameter: DrawLines_Value_j
                                        * Referenced by: '<Root>/Draw Lines'
                                        */
  0,                                   /* Computed Parameter: _Y0
                                        * Referenced by: '<S15>/ '
                                        */

  /*  Computed Parameter: Constant_Value_b
   * Referenced by: '<S31>/Constant'
   */
  { 0, 0 },
  1,                                   /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S31>/Constant1'
                                        */
  0,                                   /* Computed Parameter: Delay1_InitialCondition_n
                                        * Referenced by: '<S52>/Delay1'
                                        */
  0                                    /* Expression: false
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_vipldws_T vipldws_ConstP = {
  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  { -1.0F, -0.99984771F, -0.999390841F, -0.99862951F, -0.997564077F,
    -0.99619472F, -0.994521916F, -0.992546141F, -0.990268052F, -0.987688363F,
    -0.98480773F, -0.981627166F, -0.978147626F, -0.974370062F, -0.970295727F,
    -0.965925813F, -0.96126169F, -0.956304729F, -0.95105654F, -0.945518553F,
    -0.939692616F, -0.933580399F, -0.927183867F, -0.920504868F, -0.91354543F,
    -0.906307817F, -0.898794055F, -0.891006529F, -0.882947564F, -0.874619722F,
    -0.866025388F, -0.857167304F, -0.848048091F, -0.838670552F, -0.829037547F,
    -0.819152057F, -0.809017F, -0.798635483F, -0.788010776F, -0.777146F,
    -0.766044438F, -0.754709601F, -0.74314481F, -0.7313537F, -0.719339788F,
    -0.707106769F, -0.694658399F, -0.681998372F, -0.669130623F, -0.656059F,
    -0.642787635F, -0.629320383F, -0.615661502F, -0.601815045F, -0.587785244F,
    -0.57357645F, -0.559192896F, -0.544639051F, -0.529919267F, -0.515038073F,
    -0.5F, -0.484809607F, -0.469471574F, -0.453990489F, -0.438371152F,
    -0.42261827F, -0.406736642F, -0.390731126F, -0.37460658F, -0.35836795F,
    -0.342020154F, -0.325568169F, -0.309017F, -0.29237169F, -0.275637358F,
    -0.258819044F, -0.241921902F, -0.224951059F, -0.207911685F, -0.190809F,
    -0.173648179F, -0.156434461F, -0.139173105F, -0.121869341F, -0.104528464F,
    -0.0871557444F, -0.0697564706F, -0.0523359552F, -0.0348994955F,
    -0.0174524058F, 0.0F },

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  -312.0F,

  /* Computed Parameter: InsertText_GlyLBearings
   * Referenced by: '<S65>/Insert Text'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 1,
    1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Computed Parameter: InsertText_GlyTBearings
   * Referenced by: '<S65>/Insert Text'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0,
    15, 0, 0, 0, 0, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, 0,
    11, 15, 11, 15, 15, 0, 0, 0, 0, 0, 0, 11, 0, 11, 0, 14, 11, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 10, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11,
    7, 0, 0, 11, 11, 0, 11, 11, 0, 7, 7, 0, 0, 7, 0, 9, 0, 0, 7, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 },

  /* Computed Parameter: InsertText_GlyIndexes
   * Referenced by: '<S65>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 78U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    228U, 0U, 0U, 0U, 0U, 0U, 363U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 528U, 0U, 0U, 0U, 649U, 759U, 909U, 1059U, 1209U, 0U, 0U, 0U, 0U,
    0U, 0U, 1314U, 0U, 1464U, 0U, 1574U, 1700U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_stringRTP
   * Referenced by: '<S65>/Insert Text'
   */
  { 0U, 56U, 57U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 36U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 106U, 0U, 0U, 0U, 176U, 0U, 246U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 346U, 412U, 0U, 0U, 454U, 520U, 0U, 575U, 652U, 0U,
    707U, 749U, 0U, 0U, 791U, 0U, 833U, 0U, 0U, 896U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0U, 1U, 15U, 28U, 41U },

  /* Computed Parameter: InsertText_GlyWidths
   * Referenced by: '<S65>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 6U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 10U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    9U, 0U, 0U, 0U, 0U, 0U, 11U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 11U, 0U, 0U, 0U, 10U, 10U, 10U, 10U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 10U,
    0U, 10U, 0U, 9U, 10U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_GlyHeights
   * Referenced by: '<S65>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 13U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 15U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    15U, 0U, 0U, 0U, 0U, 0U, 15U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 11U, 0U, 0U, 0U, 11U, 15U, 15U, 15U, 15U, 0U, 0U, 0U, 0U, 0U, 0U,
    15U, 0U, 11U, 0U, 14U, 11U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_GlyXAdvances
   * Referenced by: '<S65>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 12U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 12U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 12U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    12U, 0U, 0U, 0U, 0U, 0U, 12U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 12U, 0U, 0U, 0U, 12U, 12U, 12U, 12U, 12U, 0U, 0U, 0U, 0U, 0U, 0U,
    12U, 0U, 12U, 0U, 12U, 12U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 4U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 7U, 0U, 10U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 6U, 6U, 0U, 0U, 6U, 5U, 0U, 7U, 5U, 0U, 6U, 6U, 0U, 0U,
    6U, 0U, 7U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 9U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 10U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 10U, 0U, 0U, 0U, 10U, 0U, 10U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 11U, 7U, 0U, 0U, 11U, 11U, 0U, 11U, 11U, 0U, 7U, 7U,
    0U, 0U, 7U, 0U, 9U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 8U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 8U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 8U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 8U, 0U, 0U, 0U, 8U, 0U, 8U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 8U, 8U, 0U, 0U, 8U, 8U, 0U, 8U, 8U, 0U, 8U, 8U, 0U, 0U,
    8U, 0U, 8U, 0U, 0U, 8U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_StrArray
   * Referenced by: '<S65>/Insert Text'
   */
  { 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U,
    32U, 32U, 32U, 32U, 32U, 82U, 105U, 103U, 104U, 116U, 10U, 32U, 32U, 32U,
    32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U, 32U,
    32U, 32U, 68U, 101U, 112U, 97U, 114U, 116U, 117U, 114U, 101U, 0U, 0U, 32U,
    76U, 101U, 102U, 116U, 10U, 32U, 68U, 101U, 112U, 97U, 114U, 116U, 117U,
    114U, 101U, 0U },

  /* Computed Parameter: InsertText_GlyData
   * Referenced by: '<S65>/Insert Text'
   */
  { 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U,
    0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U,
    0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U,
    255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 247U, 215U, 137U, 17U, 0U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 228U, 36U, 0U, 255U, 255U, 255U, 0U, 22U, 125U, 255U, 255U,
    206U, 3U, 255U, 255U, 255U, 0U, 0U, 0U, 162U, 255U, 255U, 81U, 255U, 255U,
    255U, 0U, 0U, 0U, 73U, 255U, 255U, 165U, 255U, 255U, 255U, 0U, 0U, 0U, 30U,
    255U, 255U, 215U, 255U, 255U, 255U, 0U, 0U, 0U, 8U, 255U, 255U, 241U, 255U,
    255U, 255U, 0U, 0U, 0U, 2U, 255U, 255U, 252U, 255U, 255U, 255U, 0U, 0U, 0U,
    9U, 255U, 255U, 240U, 255U, 255U, 255U, 0U, 0U, 0U, 32U, 255U, 255U, 214U,
    255U, 255U, 255U, 0U, 0U, 0U, 77U, 255U, 255U, 162U, 255U, 255U, 255U, 0U,
    0U, 0U, 167U, 255U, 255U, 77U, 255U, 255U, 255U, 0U, 22U, 127U, 255U, 255U,
    201U, 2U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 225U, 32U, 0U, 255U,
    255U, 255U, 255U, 248U, 216U, 136U, 16U, 0U, 0U, 255U, 255U, 255U, 0U, 0U,
    0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U,
    0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U,
    255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U,
    0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U,
    0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 240U, 186U, 64U, 0U, 0U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 253U, 71U, 0U, 255U, 255U,
    255U, 0U, 4U, 29U, 150U, 255U, 255U, 201U, 0U, 255U, 255U, 255U, 0U, 0U, 0U,
    19U, 255U, 255U, 247U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 24U, 255U, 255U,
    229U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 112U, 255U, 255U, 158U, 0U, 255U,
    255U, 255U, 3U, 33U, 124U, 248U, 255U, 227U, 28U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 189U, 31U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U,
    208U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 172U, 255U, 255U, 99U, 0U, 0U,
    0U, 255U, 255U, 255U, 0U, 23U, 237U, 255U, 240U, 26U, 0U, 0U, 255U, 255U,
    255U, 0U, 0U, 92U, 255U, 255U, 178U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U,
    180U, 255U, 255U, 91U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 27U, 240U, 255U,
    236U, 22U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 100U, 255U, 255U, 171U, 0U, 46U,
    138U, 204U, 234U, 250U, 230U, 176U, 64U, 0U, 0U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 253U, 84U, 0U, 0U, 206U, 105U, 42U, 9U, 26U, 143U, 255U,
    255U, 208U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 7U, 255U, 255U, 245U, 0U, 0U, 30U,
    138U, 204U, 238U, 252U, 255U, 255U, 255U, 255U, 0U, 58U, 242U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 0U, 202U, 255U, 255U, 166U, 43U, 9U, 0U,
    255U, 255U, 255U, 0U, 248U, 255U, 255U, 16U, 0U, 0U, 15U, 255U, 255U, 255U,
    0U, 226U, 255U, 255U, 111U, 9U, 63U, 212U, 255U, 255U, 255U, 34U, 109U, 255U,
    255U, 255U, 255U, 255U, 213U, 244U, 255U, 255U, 255U, 0U, 87U, 204U, 244U,
    234U, 154U, 16U, 77U, 220U, 254U, 255U, 0U, 0U, 61U, 177U, 235U, 249U, 223U,
    141U, 15U, 0U, 0U, 112U, 254U, 255U, 255U, 255U, 255U, 255U, 210U, 11U, 59U,
    254U, 255U, 178U, 27U, 16U, 149U, 255U, 255U, 129U, 173U, 255U, 255U, 32U,
    0U, 0U, 18U, 255U, 255U, 212U, 233U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 247U, 251U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    234U, 255U, 255U, 35U, 0U, 0U, 0U, 0U, 0U, 0U, 174U, 255U, 255U, 131U, 0U,
    0U, 0U, 0U, 0U, 0U, 58U, 253U, 255U, 252U, 123U, 30U, 10U, 42U, 106U, 206U,
    0U, 105U, 252U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 50U, 162U,
    225U, 249U, 233U, 198U, 127U, 42U, 0U, 0U, 6U, 122U, 206U, 243U, 255U, 255U,
    255U, 255U, 0U, 0U, 159U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U,
    245U, 255U, 255U, 89U, 10U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U,
    0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 255U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U,
    255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U,
    255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U,
    0U, 16U, 152U, 235U, 245U, 175U, 30U, 218U, 255U, 255U, 4U, 200U, 255U, 255U,
    255U, 255U, 236U, 254U, 255U, 255U, 100U, 255U, 255U, 213U, 36U, 32U, 183U,
    255U, 255U, 255U, 188U, 255U, 255U, 83U, 0U, 0U, 4U, 255U, 255U, 255U, 235U,
    255U, 255U, 24U, 0U, 0U, 0U, 255U, 255U, 255U, 252U, 255U, 255U, 5U, 0U, 0U,
    0U, 255U, 255U, 255U, 244U, 255U, 255U, 14U, 0U, 0U, 18U, 255U, 255U, 255U,
    205U, 255U, 255U, 54U, 0U, 0U, 125U, 255U, 255U, 255U, 128U, 255U, 255U,
    181U, 20U, 75U, 208U, 255U, 255U, 255U, 17U, 227U, 255U, 255U, 255U, 254U,
    77U, 255U, 255U, 253U, 0U, 36U, 185U, 246U, 222U, 95U, 5U, 255U, 255U, 238U,
    0U, 0U, 0U, 0U, 0U, 0U, 47U, 255U, 255U, 194U, 0U, 208U, 112U, 44U, 10U, 41U,
    195U, 255U, 255U, 106U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 195U,
    4U, 0U, 42U, 127U, 197U, 232U, 249U, 218U, 131U, 10U, 0U, 255U, 255U, 255U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 95U, 210U, 246U, 222U, 133U, 6U, 255U,
    255U, 255U, 100U, 255U, 255U, 255U, 255U, 255U, 124U, 255U, 255U, 255U, 236U,
    109U, 14U, 103U, 255U, 255U, 217U, 255U, 255U, 255U, 126U, 0U, 0U, 8U, 255U,
    255U, 248U, 255U, 255U, 255U, 7U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U,
    0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U,
    0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U,
    0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U,
    255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U,
    0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U,
    255U, 0U, 92U, 220U, 245U, 186U, 39U, 0U, 255U, 255U, 255U, 92U, 255U, 255U,
    255U, 255U, 230U, 18U, 255U, 255U, 255U, 236U, 80U, 20U, 180U, 255U, 255U,
    131U, 255U, 255U, 255U, 126U, 0U, 0U, 51U, 255U, 255U, 207U, 255U, 255U,
    255U, 13U, 0U, 0U, 12U, 255U, 255U, 244U, 255U, 255U, 255U, 0U, 0U, 0U, 9U,
    255U, 255U, 251U, 255U, 255U, 255U, 0U, 0U, 0U, 29U, 255U, 255U, 232U, 255U,
    255U, 255U, 0U, 0U, 0U, 91U, 255U, 255U, 184U, 255U, 255U, 255U, 148U, 20U,
    39U, 218U, 255U, 255U, 92U, 255U, 255U, 255U, 239U, 255U, 255U, 255U, 255U,
    191U, 2U, 255U, 255U, 255U, 44U, 190U, 247U, 233U, 146U, 12U, 0U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 26U, 147U, 222U, 250U, 255U, 255U,
    255U, 255U, 255U, 52U, 238U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    235U, 234U, 110U, 30U, 4U, 255U, 255U, 255U, 255U, 255U, 222U, 32U, 0U, 0U,
    0U, 0U, 0U, 255U, 255U, 255U, 53U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U,
    0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U,
    0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 255U, 255U, 0U, 0U,
    0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U,
    0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 0U, 0U, 247U, 255U, 255U, 17U, 0U, 0U, 0U, 0U, 0U,
    210U, 255U, 255U, 129U, 12U, 41U, 168U, 0U, 0U, 102U, 255U, 255U, 255U, 255U,
    255U, 255U, 0U, 0U, 1U, 96U, 204U, 240U, 232U, 172U, 59U, 255U, 255U, 255U,
    0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U,
    255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U,
    255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 0U, 0U, 0U, 7U, 255U, 255U, 255U, 249U, 255U, 255U, 7U, 0U, 0U,
    129U, 255U, 255U, 255U, 217U, 255U, 255U, 101U, 13U, 113U, 235U, 255U, 255U,
    255U, 126U, 255U, 255U, 255U, 255U, 255U, 98U, 255U, 255U, 255U, 7U, 135U,
    223U, 247U, 211U, 95U, 0U, 255U, 255U, 255U },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 0U, 89U, 101U, 108U, 108U, 111U, 119U, 10U, 66U, 114U, 111U, 107U, 101U,
    110U, 0U, 89U, 101U, 108U, 108U, 111U, 119U, 10U, 83U, 111U, 108U, 105U,
    100U, 0U, 87U, 104U, 105U, 116U, 101U, 10U, 66U, 114U, 111U, 107U, 101U,
    110U, 0U, 87U, 104U, 105U, 116U, 101U, 10U, 83U, 111U, 108U, 105U, 100U, 0U
  },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  { 255U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 255U, 0U, 0U, 255U, 255U, 0U, 0U,
    255U, 255U, 0U, 0U, 255U, 255U, 0U, 0U, 255U, 255U, 0U, 0U, 255U, 255U, 0U,
    0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 238U, 191U, 53U,
    255U, 255U, 0U, 10U, 90U, 255U, 217U, 255U, 255U, 0U, 0U, 17U, 255U, 237U,
    255U, 255U, 2U, 33U, 168U, 252U, 97U, 255U, 255U, 255U, 255U, 255U, 104U, 0U,
    255U, 255U, 3U, 45U, 196U, 254U, 86U, 255U, 255U, 0U, 0U, 37U, 255U, 217U,
    255U, 255U, 0U, 0U, 13U, 255U, 243U, 255U, 255U, 0U, 12U, 133U, 255U, 180U,
    255U, 255U, 255U, 255U, 235U, 166U, 23U, 15U, 133U, 215U, 243U, 233U, 183U,
    65U, 188U, 255U, 96U, 11U, 20U, 75U, 193U, 247U, 255U, 46U, 0U, 0U, 0U, 0U,
    171U, 255U, 236U, 90U, 0U, 0U, 0U, 9U, 155U, 255U, 255U, 189U, 32U, 0U, 0U,
    0U, 67U, 217U, 255U, 241U, 59U, 0U, 0U, 0U, 7U, 158U, 255U, 213U, 0U, 0U, 0U,
    0U, 16U, 255U, 246U, 192U, 75U, 18U, 20U, 143U, 255U, 164U, 62U, 179U, 236U,
    241U, 209U, 118U, 7U, 247U, 255U, 16U, 0U, 0U, 32U, 247U, 229U, 255U, 34U,
    0U, 0U, 47U, 229U, 211U, 255U, 52U, 0U, 0U, 62U, 211U, 193U, 255U, 108U,
    255U, 230U, 77U, 193U, 175U, 255U, 153U, 255U, 255U, 112U, 175U, 157U, 255U,
    199U, 255U, 255U, 172U, 157U, 139U, 255U, 243U, 245U, 255U, 231U, 139U, 121U,
    255U, 255U, 165U, 255U, 255U, 121U, 103U, 255U, 255U, 73U, 254U, 255U, 103U,
    85U, 255U, 255U, 21U, 213U, 255U, 85U, 7U, 225U, 241U, 22U, 0U, 0U, 0U, 18U,
    204U, 4U, 0U, 97U, 255U, 155U, 0U, 0U, 0U, 137U, 91U, 0U, 0U, 3U, 214U, 253U,
    48U, 0U, 24U, 200U, 2U, 0U, 0U, 0U, 82U, 255U, 192U, 0U, 149U, 79U, 0U, 0U,
    0U, 0U, 0U, 202U, 255U, 116U, 194U, 0U, 0U, 0U, 0U, 0U, 0U, 68U, 255U, 255U,
    67U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U,
    0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U,
    14U, 180U, 239U, 141U, 255U, 255U, 142U, 255U, 108U, 87U, 255U, 255U, 222U,
    255U, 24U, 0U, 255U, 255U, 248U, 255U, 4U, 0U, 255U, 255U, 233U, 255U, 10U,
    26U, 255U, 255U, 169U, 255U, 80U, 120U, 255U, 255U, 33U, 207U, 233U, 70U,
    255U, 255U, 1U, 117U, 220U, 239U, 164U, 13U, 109U, 255U, 101U, 84U, 255U,
    147U, 215U, 255U, 16U, 9U, 255U, 227U, 249U, 255U, 255U, 255U, 255U, 254U,
    232U, 255U, 31U, 0U, 0U, 0U, 153U, 255U, 170U, 19U, 0U, 0U, 11U, 138U, 223U,
    252U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 70U,
    225U, 237U, 94U, 255U, 255U, 135U, 42U, 255U, 227U, 255U, 255U, 28U, 0U,
    255U, 254U, 255U, 255U, 0U, 0U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 255U,
    255U, 255U, 0U, 0U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 255U, 0U, 0U, 0U,
    255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U,
    0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U,
    0U, 0U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U,
    0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 255U,
    255U, 0U, 0U, 87U, 132U, 0U, 255U, 255U, 0U, 75U, 144U, 0U, 0U, 255U, 255U,
    63U, 189U, 1U, 0U, 0U, 255U, 255U, 255U, 252U, 65U, 0U, 0U, 255U, 255U, 66U,
    248U, 234U, 29U, 0U, 255U, 255U, 0U, 83U, 253U, 202U, 7U, 255U, 255U, 0U, 0U,
    102U, 255U, 155U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U,
    0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U,
    0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U,
    255U, 255U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 70U,
    225U, 237U, 94U, 255U, 255U, 135U, 42U, 255U, 227U, 255U, 255U, 28U, 0U,
    255U, 254U, 255U, 255U, 0U, 0U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 255U,
    255U, 255U, 0U, 0U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 255U, 5U, 139U,
    231U, 231U, 137U, 5U, 125U, 255U, 99U, 99U, 255U, 122U, 219U, 255U, 18U, 18U,
    255U, 218U, 247U, 255U, 3U, 4U, 255U, 246U, 219U, 255U, 17U, 18U, 255U, 218U,
    124U, 255U, 95U, 100U, 255U, 121U, 5U, 141U, 233U, 230U, 136U, 5U, 255U,
    255U, 36U, 190U, 248U, 255U, 255U, 255U, 209U, 85U, 9U, 255U, 255U, 255U,
    82U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 255U,
    0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 255U, 255U, 0U, 0U, 0U,
    0U, 0U, 255U, 255U, 0U, 0U, 0U, 0U, 0U, 251U, 255U, 3U, 0U, 0U, 0U, 0U, 207U,
    255U, 79U, 1U, 0U, 0U, 0U, 48U, 196U, 245U, 255U, 255U, 240U, 255U, 25U, 0U,
    0U, 43U, 240U, 209U, 255U, 101U, 255U, 239U, 65U, 209U, 178U, 255U, 156U,
    255U, 255U, 121U, 178U, 146U, 255U, 210U, 231U, 255U, 193U, 147U, 115U, 255U,
    252U, 156U, 255U, 250U, 116U, 83U, 255U, 255U, 90U, 244U, 255U, 85U, 52U,
    255U, 255U, 46U, 212U, 255U, 55U },

  /* Expression: devName
   * Referenced by: '<S2>/V4L2 Video Capture'
   */
  { 47U, 100U, 101U, 118U, 47U, 118U, 105U, 100U, 101U, 111U, 48U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
