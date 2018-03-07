/*
 * File: LaneDetection.c
 *
 * Code generated for Simulink model 'LaneDetection'.
 *
 * Model version                  : 1.110
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Mar 08 01:05:57 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "LaneDetection.h"
#include "div_nde_s32_floor.h"
#include "mul_s32_loSR.h"
#include "mul_ssu32_loSR.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

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

extern const real_T rtCP_pooled_gtKkVs9eS62J[91];
extern const real_T rtCP_pooled_OHe5xkPYJZLy;
extern const int32_T rtCP_pooled_9H9mPzIgD49d[6];
extern const int32_T rtCP_pooled_berHTRPvDDTn[6];
extern const int32_T rtCP_pooled_vw7bACqMwvtP[6];
extern const int32_T rtCP_pooled_RXsOmBvvADoW[6];
extern const int32_T rtCP_pooled_I29smDgh1ZlF[6];
extern const int32_T rtCP_pooled_C08a0ezfB1lz[6];

#define rtCP_HoughTransform_SINE_TABLE_ rtCP_pooled_gtKkVs9eS62J /* Computed Parameter: rtCP_HoughTransform_SINE_TABLE_
                                                                  * Referenced by: '<S1>/Hough Transform'
                                                                  */
#define rtCP_HoughTransform_FIRSTRHO_RT rtCP_pooled_OHe5xkPYJZLy /* Computed Parameter: rtCP_HoughTransform_FIRSTRHO_RT
                                                                  * Referenced by: '<S1>/Hough Transform'
                                                                  */
#define rtCP_EdgeDetection_VRO_RTP     rtCP_pooled_9H9mPzIgD49d  /* Computed Parameter: rtCP_EdgeDetection_VRO_RTP
                                                                  * Referenced by: '<Root>/Edge Detection'
                                                                  */
#define rtCP_EdgeDetection_VCO_RTP     rtCP_pooled_berHTRPvDDTn  /* Computed Parameter: rtCP_EdgeDetection_VCO_RTP
                                                                  * Referenced by: '<Root>/Edge Detection'
                                                                  */
#define rtCP_EdgeDetection_HRO_RTP     rtCP_pooled_vw7bACqMwvtP  /* Computed Parameter: rtCP_EdgeDetection_HRO_RTP
                                                                  * Referenced by: '<Root>/Edge Detection'
                                                                  */
#define rtCP_EdgeDetection_HCO_RTP     rtCP_pooled_RXsOmBvvADoW  /* Computed Parameter: rtCP_EdgeDetection_HCO_RTP
                                                                  * Referenced by: '<Root>/Edge Detection'
                                                                  */
#define rtCP_EdgeDetection_VC_RTP      rtCP_pooled_I29smDgh1ZlF  /* Computed Parameter: rtCP_EdgeDetection_VC_RTP
                                                                  * Referenced by: '<Root>/Edge Detection'
                                                                  */
#define rtCP_EdgeDetection_HC_RTP      rtCP_pooled_C08a0ezfB1lz  /* Computed Parameter: rtCP_EdgeDetection_HC_RTP
                                                                  * Referenced by: '<Root>/Edge Detection'
                                                                  */

/* Start for referenced model: 'LaneDetection' */
void LaneDetection_Start(LaneDetection_DW_f *localDW)
{
  int32_T nonZeroIdx;

  /* Start for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 134883;
  for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
    localDW->EdgeDetection_VO_DW[nonZeroIdx] =
      rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
      rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
    if (rtCP_EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
    } else {
      localDW->EdgeDetection_VOU_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
      localDW->EdgeDetection_VOD_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if (rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_VOL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((rtCP_EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
    }

    if ((rtCP_EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
    }

    if ((rtCP_EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
        (rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    if ((rtCP_EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
        (rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_VOUL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_VOLL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VRO_RTP[nonZeroIdx] * 61;
      localDW->EdgeDetection_VOUR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_VCO_RTP[nonZeroIdx];
    }

    localDW->EdgeDetection_HO_DW[nonZeroIdx] =
      rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
      rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
    if (rtCP_EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
    } else {
      localDW->EdgeDetection_HOU_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
      localDW->EdgeDetection_HOD_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if (rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
    } else {
      localDW->EdgeDetection_HOL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((rtCP_EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
    }

    if ((rtCP_EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
    }

    if ((rtCP_EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
        (rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
    }

    if ((rtCP_EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
        (rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
      localDW->EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
      localDW->EdgeDetection_HOUL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61 +
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
      localDW->EdgeDetection_HOLL_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HRO_RTP[nonZeroIdx] * 61;
      localDW->EdgeDetection_HOUR_DW[nonZeroIdx] =
        rtCP_EdgeDetection_HCO_RTP[nonZeroIdx];
    }
  }

  /* End of Start for S-Function (svipedge): '<Root>/Edge Detection' */
}

/* Output and update for referenced model: 'LaneDetection' */
void LaneDetection(const uint8_T rtu_I[15921], int32_T rty_Points[20], int32_T
                   rty_Points_DIMS1[2], real_T rty_Slope[5], int32_T
                   rty_Slope_DIMS1[2], uint8_T rty_LineImage[15921], boolean_T
                   rty_Edge[15921], LaneDetection_DW_f *localDW)
{
  boolean_T done;
  int32_T q2;
  int32_T imgCol;
  int32_T imgRow;
  int32_T m;
  boolean_T b4;
  boolean_T b3;
  boolean_T b2;
  int32_T accumOne;
  int32_T accumTwo;
  int32_T accumFour;
  int32_T accumThree;
  int32_T line_idx_1;
  int32_T line_idx_3;
  int32_T line_idx_2;
  int32_T line_idx_1_0;
  int32_T line_idx_0;
  int32_T line_idx_3_0;
  int32_T line_idx_2_0;

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 0; imgCol < 259; imgCol++) {
    for (imgRow = 0; imgRow < 59; imgRow++) {
      accumOne = 0;
      accumTwo = 0;
      q2 = ((imgCol + 1) * 61 + imgRow) + 1;
      for (m = 0; m < 6; m++) {
        accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[q2 +
          localDW->EdgeDetection_VO_DW[m]], 23U);
        accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[q2 +
          localDW->EdgeDetection_HO_DW[m]], 23U);
      }

      localDW->EdgeDetection_GV_SQUARED_DW[q2] = mul_s32_loSR(accumOne, accumOne,
        8U);
      localDW->EdgeDetection_GH_SQUARED_DW[q2] = mul_s32_loSR(accumTwo, accumTwo,
        8U);
    }
  }

  for (imgCol = 0; imgCol < 259; imgCol++) {
    accumOne = 0;
    accumTwo = 0;
    accumThree = 0;
    accumFour = 0;
    imgRow = (imgCol + 1) * 61;
    q2 = (imgCol + 1) * 61 + 60;
    for (m = 0; m < 6; m++) {
      accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[imgRow +
        localDW->EdgeDetection_HOU_DW[m]], 23U);
      accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[q2 +
        localDW->EdgeDetection_HOD_DW[m]], 23U);
      accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[imgRow +
        localDW->EdgeDetection_VOU_DW[m]], 23U);
      accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[q2 +
        localDW->EdgeDetection_VOD_DW[m]], 23U);
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgRow] = mul_s32_loSR(accumThree,
      accumThree, 8U);
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow] = mul_s32_loSR(accumOne,
      accumOne, 8U);
    localDW->EdgeDetection_GV_SQUARED_DW[q2] = mul_s32_loSR(accumFour, accumFour,
      8U);
    localDW->EdgeDetection_GH_SQUARED_DW[q2] = mul_s32_loSR(accumTwo, accumTwo,
      8U);
  }

  for (imgRow = 0; imgRow < 59; imgRow++) {
    accumOne = 0;
    accumTwo = 0;
    accumThree = 0;
    accumFour = 0;
    imgCol = imgRow + 15861;
    for (m = 0; m < 6; m++) {
      accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[(imgRow +
        localDW->EdgeDetection_VOL_DW[m]) + 1], 23U);
      accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[imgCol +
        localDW->EdgeDetection_VOR_DW[m]], 23U);
      accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[(imgRow +
        localDW->EdgeDetection_HOL_DW[m]) + 1], 23U);
      accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[imgCol +
        localDW->EdgeDetection_HOR_DW[m]], 23U);
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgRow + 1] = mul_s32_loSR(accumOne,
      accumOne, 8U);
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow + 1] = mul_s32_loSR(accumThree,
      accumThree, 8U);
    localDW->EdgeDetection_GV_SQUARED_DW[imgCol] = mul_s32_loSR(accumTwo,
      accumTwo, 8U);
    localDW->EdgeDetection_GH_SQUARED_DW[imgCol] = mul_s32_loSR(accumFour,
      accumFour, 8U);
  }

  accumOne = 0;
  accumTwo = 0;
  accumThree = 0;
  accumFour = 0;
  for (m = 0; m < 6; m++) {
    accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I
      [localDW->EdgeDetection_VOUL_DW[m]], 23U);
    accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I
      [localDW->EdgeDetection_HOUL_DW[m]], 23U);
    accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[60 +
      localDW->EdgeDetection_VOLL_DW[m]], 23U);
    accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[60 +
      localDW->EdgeDetection_HOLL_DW[m]], 23U);
  }

  localDW->EdgeDetection_GV_SQUARED_DW[0] = mul_s32_loSR(accumOne, accumOne, 8U);
  localDW->EdgeDetection_GH_SQUARED_DW[0] = mul_s32_loSR(accumTwo, accumTwo, 8U);
  localDW->EdgeDetection_GV_SQUARED_DW[60] = mul_s32_loSR(accumThree, accumThree,
    8U);
  localDW->EdgeDetection_GH_SQUARED_DW[60] = mul_s32_loSR(accumFour, accumFour,
    8U);
  accumOne = 0;
  accumTwo = 0;
  accumThree = 0;
  accumFour = 0;
  for (m = 0; m < 6; m++) {
    accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[15860 +
      localDW->EdgeDetection_VOUR_DW[m]], 23U);
    accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[15860 +
      localDW->EdgeDetection_HOUR_DW[m]], 23U);
    accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m], rtu_I[15920 +
      localDW->EdgeDetection_VOLR_DW[m]], 23U);
    accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m], rtu_I[15920 +
      localDW->EdgeDetection_HOLR_DW[m]], 23U);
  }

  localDW->EdgeDetection_GV_SQUARED_DW[15860] = mul_s32_loSR(accumOne, accumOne,
    8U);
  localDW->EdgeDetection_GH_SQUARED_DW[15860] = mul_s32_loSR(accumTwo, accumTwo,
    8U);
  localDW->EdgeDetection_GV_SQUARED_DW[15920] = mul_s32_loSR(accumThree,
    accumThree, 8U);
  localDW->EdgeDetection_GH_SQUARED_DW[15920] = mul_s32_loSR(accumFour,
    accumFour, 8U);
  accumTwo = 0;
  for (m = 0; m < 15921; m++) {
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->
      EdgeDetection_GV_SQUARED_DW[m];
    localDW->EdgeDetection_GRAD_SUM_DW[m] +=
      localDW->EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += mul_s32_loSR(localDW->EdgeDetection_GRAD_SUM_DW[m],
      localDW->EdgeDetection_MEAN_FACTOR_DW, 31U);
  }

  accumOne = accumTwo << 2;
  for (imgCol = 0; imgCol < 261; imgCol++) {
    for (imgRow = 0; imgRow < 61; imgRow++) {
      m = imgCol * 61 + imgRow;
      done = true;
      b2 = true;
      b3 = true;
      b4 = true;
      if (imgCol != 0) {
        done = (localDW->EdgeDetection_GRAD_SUM_DW[m - 61] <=
                localDW->EdgeDetection_GRAD_SUM_DW[m]);
      }

      if (imgCol != 260) {
        b2 = (localDW->EdgeDetection_GRAD_SUM_DW[m] >
              localDW->EdgeDetection_GRAD_SUM_DW[m + 61]);
      }

      if (imgRow != 0) {
        b3 = (localDW->EdgeDetection_GRAD_SUM_DW[m - 1] <=
              localDW->EdgeDetection_GRAD_SUM_DW[m]);
      }

      if (imgRow != 60) {
        b4 = (localDW->EdgeDetection_GRAD_SUM_DW[m] >
              localDW->EdgeDetection_GRAD_SUM_DW[m + 1]);
      }

      rty_Edge[m] = ((localDW->EdgeDetection_GRAD_SUM_DW[m] > accumOne) &&
                     (((localDW->EdgeDetection_GV_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GH_SQUARED_DW[m]) && done && b2) ||
                      ((localDW->EdgeDetection_GH_SQUARED_DW[m] >=
                        localDW->EdgeDetection_GV_SQUARED_DW[m]) && b3 && b4)));
    }
  }

  /* End of S-Function (svipedge): '<Root>/Edge Detection' */

  /* S-Function (sviphough): '<S1>/Hough Transform' */
  MWVIP_Hough_D(&rty_Edge[0], &localDW->HoughTransform_o1[0],
                &rtCP_HoughTransform_SINE_TABLE_[0],
                &rtCP_HoughTransform_FIRSTRHO_RT, 61, 261, 535, 91);

  /* S-Function (svipfindlocalmax): '<S1>/Find Local Maxima' */
  accumOne = 0;
  done = false;
  for (m = 0; m < 96300; m++) {
    localDW->FindLocalMaxima_TEMP_IN_DWORKS[m] = localDW->HoughTransform_o1[m];
  }

  memset(&localDW->FindLocalMaxima[0], 0, 10U * sizeof(real_T));
  while (!done) {
    accumThree = 0;
    localDW->maxValue = localDW->FindLocalMaxima_TEMP_IN_DWORKS[0];
    for (m = 0; m < 96300; m++) {
      if (localDW->FindLocalMaxima_TEMP_IN_DWORKS[m] > localDW->maxValue) {
        accumThree = m;
        localDW->maxValue = localDW->FindLocalMaxima_TEMP_IN_DWORKS[m];
      }
    }

    imgCol = accumThree % 535;
    m = accumThree / 535;
    if (localDW->FindLocalMaxima_TEMP_IN_DWORKS[accumThree] >= 10.0) {
      localDW->FindLocalMaxima[accumOne] = 1.0 + (real_T)m;
      localDW->FindLocalMaxima[5U + accumOne] = 1 + imgCol;
      accumOne++;
      if (accumOne == 5) {
        done = true;
      }

      accumThree = imgCol - 2;
      if (!(accumThree > 0)) {
        accumThree = 0;
      }

      imgCol += 2;
      if (!(imgCol < 534)) {
        imgCol = 534;
      }

      imgRow = m - 3;
      q2 = m + 3;
      if (!((imgRow < 0) || (q2 > 179))) {
        while (imgRow <= q2) {
          accumTwo = imgRow * 535;
          for (m = accumThree; m <= imgCol; m++) {
            localDW->FindLocalMaxima_TEMP_IN_DWORKS[m + accumTwo] = 0.0;
          }

          imgRow++;
        }
      } else {
        if (imgRow < 0) {
          for (accumFour = imgRow; accumFour <= q2; accumFour++) {
            if (accumFour < 0) {
              accumTwo = (accumFour + 180) * 535 + 534;
              for (m = accumThree; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[accumTwo - m] = 0.0;
              }
            } else {
              accumTwo = accumFour * 535;
              for (m = accumThree; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[m + accumTwo] = 0.0;
              }
            }
          }
        }

        if (q2 > 179) {
          for (accumFour = imgRow; accumFour <= q2; accumFour++) {
            if (accumFour > 179) {
              accumTwo = (accumFour - 180) * 535 + 534;
              for (m = accumThree; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[accumTwo - m] = 0.0;
              }
            } else {
              accumTwo = accumFour * 535;
              for (m = accumThree; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[m + accumTwo] = 0.0;
              }
            }
          }
        }
      }
    } else {
      done = true;
    }
  }

  localDW->FindLocalMaxima_NUMPEAKS_DWORK = (uint32_T)accumOne;
  localDW->fromIdx = 5U;
  localDW->toIdx = (uint32_T)accumOne;
  for (m = 0; m < accumOne; m++) {
    localDW->FindLocalMaxima[localDW->toIdx] = localDW->FindLocalMaxima
      [localDW->fromIdx];
    localDW->fromIdx++;
    localDW->toIdx++;
  }

  localDW->FindLocalMaxima_DIMS1[0] = (int32_T)
    localDW->FindLocalMaxima_NUMPEAKS_DWORK;
  localDW->FindLocalMaxima_DIMS1[1] = 2;

  /* End of S-Function (svipfindlocalmax): '<S1>/Find Local Maxima' */

  /* Selector: '<S1>/Selector' */
  localDW->Selector_DIMS1[0] = localDW->FindLocalMaxima_DIMS1[0];
  localDW->Selector_DIMS1[1] = 1;
  imgRow = localDW->FindLocalMaxima_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_FindLocalMaxima_data[imgCol] = localDW->FindLocalMaxima[imgCol];
  }

  imgRow = localDW->FindLocalMaxima_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector[imgCol] = localDW->rtb_FindLocalMaxima_data[imgCol];
  }

  /* End of Selector: '<S1>/Selector' */

  /* Selector: '<S1>/Selector1' */
  localDW->Selector1_DIMS1[0] = 1;
  localDW->Selector1_DIMS1[1] = localDW->Selector_DIMS1[0] *
    localDW->Selector_DIMS1[1];
  imgRow = localDW->Selector_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    m = localDW->Selector_DIMS1[0];
    for (q2 = 0; q2 < m; q2++) {
      localDW->rtb_Selector_data[q2 + localDW->Selector_DIMS1[0] * imgCol] =
        (int32_T)localDW->Selector[localDW->Selector_DIMS1[0] * imgCol + q2] - 1;
    }
  }

  imgRow = localDW->Selector_DIMS1[0] * localDW->Selector_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector1[localDW->Selector1_DIMS1[0] * imgCol] =
      localDW->HoughTransform_o2[localDW->rtb_Selector_data[imgCol]];
  }

  /* End of Selector: '<S1>/Selector1' */

  /* Selector: '<S1>/Selector2' */
  localDW->Selector2_DIMS1[0] = localDW->FindLocalMaxima_DIMS1[0];
  localDW->Selector2_DIMS1[1] = 1;
  imgRow = localDW->FindLocalMaxima_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_FindLocalMaxima_data[imgCol] = localDW->FindLocalMaxima[imgCol
      + localDW->FindLocalMaxima_DIMS1[0]];
  }

  imgRow = localDW->FindLocalMaxima_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector[imgCol] = localDW->rtb_FindLocalMaxima_data[imgCol];
  }

  /* End of Selector: '<S1>/Selector2' */

  /* Selector: '<S1>/Selector5' */
  localDW->Selector5_DIMS1[0] = 1;
  localDW->Selector5_DIMS1[1] = localDW->Selector2_DIMS1[0] *
    localDW->Selector2_DIMS1[1];
  imgRow = localDW->Selector2_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    m = localDW->Selector2_DIMS1[0];
    for (q2 = 0; q2 < m; q2++) {
      localDW->rtb_Selector_data[q2 + localDW->Selector2_DIMS1[0] * imgCol] =
        (int32_T)localDW->Selector[localDW->Selector2_DIMS1[0] * imgCol + q2] -
        1;
    }
  }

  imgRow = localDW->Selector2_DIMS1[0] * localDW->Selector2_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector5[localDW->Selector5_DIMS1[0] * imgCol] =
      localDW->HoughTransform_o3[localDW->rtb_Selector_data[imgCol]];
  }

  /* End of Selector: '<S1>/Selector5' */

  /* S-Function (sviphoughlines): '<S1>/Hough Lines' */
  rty_Points_DIMS1[1] = 4;
  rty_Points_DIMS1[0] = localDW->Selector1_DIMS1[0] * localDW->Selector1_DIMS1[1];
  for (m = 0; m < localDW->Selector1_DIMS1[1]; m++) {
    accumThree = 0;
    localDW->maxValue = (localDW->Selector5[m] + 2.2204460492503131E-16) / (cos
      (localDW->Selector1[m]) + 2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    localDW->tmpRound = floor(localDW->maxValue + 0.5);
    if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 260.0)) {
      localDW->tmpOutRC[0U] = 0;
      if (localDW->tmpRound >= 0.5) {
        localDW->tmpOutRC[1U] = (int32_T)floor(localDW->tmpRound + 0.5);
      } else {
        localDW->tmpOutRC[1U] = 0;
      }

      accumThree = 1;
    }

    localDW->y2 = (localDW->Selector5[m] + 2.2204460492503131E-16) / (sin
      (localDW->Selector1[m]) + 2.2204460492503131E-16);

    /* part-2: left vertical axis */
    localDW->tmpRound = floor(localDW->y2 + 0.5);
    if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 60.0)) {
      if (localDW->tmpRound >= 0.5) {
        localDW->tmpOutRC[accumThree << 1] = (int32_T)floor(localDW->tmpRound +
          0.5);
      } else {
        localDW->tmpOutRC[accumThree << 1] = 0;
      }

      localDW->tmpOutRC[1 + (accumThree << 1)] = 0;
      accumThree++;
    }

    /* part-3: Right vertical axis */
    if (accumThree < 2) {
      localDW->tmpRound = floor((localDW->maxValue - 260.0) * (localDW->y2 /
        localDW->maxValue) + 0.5);
      if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 60.0)) {
        if (localDW->tmpRound >= 0.5) {
          localDW->tmpOutRC[accumThree << 1] = (int32_T)floor(localDW->tmpRound
            + 0.5);
        } else {
          localDW->tmpOutRC[accumThree << 1] = 0;
        }

        localDW->tmpOutRC[1 + (accumThree << 1)] = 260;
        accumThree++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (accumThree < 2) {
      localDW->tmpRound = floor((localDW->maxValue - localDW->maxValue /
        localDW->y2 * 60.0) + 0.5);
      if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 260.0)) {
        localDW->tmpOutRC[accumThree << 1] = 60;
        if (localDW->tmpRound >= 0.5) {
          localDW->tmpOutRC[1 + (accumThree << 1)] = (int32_T)floor
            (localDW->tmpRound + 0.5);
        } else {
          localDW->tmpOutRC[1 + (accumThree << 1)] = 0;
        }

        accumThree++;
      }
    }

    if (accumThree < 2) {
      localDW->tmpOutRC[0U] = -1;
      localDW->tmpOutRC[1U] = -1;
      localDW->tmpOutRC[2U] = -1;
      localDW->tmpOutRC[3U] = -1;
    }

    rty_Points[m] = localDW->tmpOutRC[1] + 1;
    rty_Points[m + localDW->Selector1_DIMS1[1]] = localDW->tmpOutRC[0] + 1;
    if (localDW->tmpOutRC[3] > 2147483646) {
      rty_Points[m + (localDW->Selector1_DIMS1[1] << 1)] = MAX_int32_T;
    } else {
      rty_Points[m + (localDW->Selector1_DIMS1[1] << 1)] = localDW->tmpOutRC[3]
        + 1;
    }

    if (localDW->tmpOutRC[2] > 2147483646) {
      rty_Points[m + 3 * localDW->Selector1_DIMS1[1]] = MAX_int32_T;
    } else {
      rty_Points[m + 3 * localDW->Selector1_DIMS1[1]] = localDW->tmpOutRC[2] + 1;
    }
  }

  /* End of S-Function (sviphoughlines): '<S1>/Hough Lines' */

  /* S-Function (svipdrawshapes): '<Root>/Draw Shapes' */
  /* Compute output for unity line width
   */
  accumThree = 0;
  accumOne = 0;
  if (rty_Points_DIMS1[1] > 1) {
    accumOne = rty_Points_DIMS1[1] >> 1;
    done = (accumOne << 1 == rty_Points_DIMS1[1]);
    accumThree = rty_Points_DIMS1[0];
  } else {
    if (rty_Points_DIMS1[1] == 1) {
      accumOne = rty_Points_DIMS1[0] >> 1;
      done = (accumOne << 1 == rty_Points_DIMS1[0]);
      accumThree = 1;
    }
  }

  /* Copy the image from input to output. */
  memcpy(&rty_LineImage[0], &rtu_I[0], 15921U * sizeof(uint8_T));
  if (done && (accumThree > 0)) {
    /* Update view port. */
    for (imgCol = 0; imgCol < accumThree; imgCol++) {
      imgRow = 0;
      for (q2 = 0; q2 < accumOne - 1; q2++) {
        line_idx_0 = rty_Points[((imgRow * accumThree << 1) + imgCol) +
          accumThree] - 1;
        line_idx_1_0 = rty_Points[(imgRow * accumThree << 1) + imgCol] - 1;
        imgRow++;
        line_idx_2_0 = rty_Points[((imgRow * accumThree << 1) + imgCol) +
          accumThree] - 1;
        line_idx_3_0 = rty_Points[(imgRow * accumThree << 1) + imgCol] - 1;
        if ((line_idx_0 != line_idx_2_0) || (line_idx_1_0 != line_idx_3_0)) {
          b2 = false;

          /* Find the visible portion of a line. */
          b3 = false;
          b4 = false;
          done = false;
          accumFour = line_idx_0;
          line_idx_1 = line_idx_1_0;
          line_idx_2 = line_idx_2_0;
          line_idx_3 = line_idx_3_0;
          while (!done) {
            localDW->fromIdx = 0U;
            localDW->toIdx = 0U;

            /* Determine viewport violations. */
            if (accumFour < 0) {
              localDW->fromIdx = 4U;
            } else {
              if (accumFour > 60) {
                localDW->fromIdx = 8U;
              }
            }

            if (line_idx_2 < 0) {
              localDW->toIdx = 4U;
            } else {
              if (line_idx_2 > 60) {
                localDW->toIdx = 8U;
              }
            }

            if (line_idx_1 < 0) {
              localDW->fromIdx |= 1U;
            } else {
              if (line_idx_1 > 260) {
                localDW->fromIdx |= 2U;
              }
            }

            if (line_idx_3 < 0) {
              localDW->toIdx |= 1U;
            } else {
              if (line_idx_3 > 260) {
                localDW->toIdx |= 2U;
              }
            }

            if (!((localDW->fromIdx | localDW->toIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              b2 = true;
            } else if ((localDW->fromIdx & localDW->toIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              b2 = false;
            } else if (localDW->fromIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (b3) {
                accumFour = line_idx_0;
                line_idx_1 = line_idx_1_0;
              }

              m = line_idx_2 - accumFour;
              accumTwo = line_idx_3 - line_idx_1;
              if ((m > 1073741824) || (m < -1073741824) || ((accumTwo >
                    1073741824) || (accumTwo < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b3 = true;
              } else if ((localDW->fromIdx & 4U) != 0U) {
                /* Violated RMin. */
                localDW->numEdge = -accumFour * accumTwo;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (m >= 0)) ||
                           ((localDW->numEdge < 0) && (m < 0))) {
                  line_idx_1 += (div_nde_s32_floor(localDW->numEdge << 1, m) + 1)
                    >> 1;
                } else {
                  line_idx_1 -= (div_nde_s32_floor(-localDW->numEdge << 1, m) +
                                 1) >> 1;
                }

                accumFour = 0;
                b3 = true;
              } else if ((localDW->fromIdx & 8U) != 0U) {
                /* Violated RMax. */
                localDW->numEdge = (60 - accumFour) * accumTwo;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (m >= 0)) ||
                           ((localDW->numEdge < 0) && (m < 0))) {
                  line_idx_1 += (div_nde_s32_floor(localDW->numEdge << 1, m) + 1)
                    >> 1;
                } else {
                  line_idx_1 -= (div_nde_s32_floor(-localDW->numEdge << 1, m) +
                                 1) >> 1;
                }

                accumFour = 60;
                b3 = true;
              } else if ((localDW->fromIdx & 1U) != 0U) {
                /* Violated CMin. */
                localDW->numEdge = -line_idx_1 * m;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (accumTwo >= 0)) ||
                           ((localDW->numEdge < 0) && (accumTwo < 0))) {
                  accumFour += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                } else {
                  accumFour -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                }

                line_idx_1 = 0;
                b3 = true;
              } else {
                /* Violated CMax. */
                localDW->numEdge = (260 - line_idx_1) * m;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (accumTwo >= 0)) ||
                           ((localDW->numEdge < 0) && (accumTwo < 0))) {
                  accumFour += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                } else {
                  accumFour -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                }

                line_idx_1 = 260;
                b3 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (b4) {
                line_idx_2 = line_idx_2_0;
                line_idx_3 = line_idx_3_0;
              }

              m = line_idx_2 - accumFour;
              accumTwo = line_idx_3 - line_idx_1;
              if ((m > 1073741824) || (m < -1073741824) || ((accumTwo >
                    1073741824) || (accumTwo < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b4 = true;
              } else if ((localDW->toIdx & 4U) != 0U) {
                /* Violated RMin. */
                localDW->numEdge = -line_idx_2 * accumTwo;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (m >= 0)) ||
                           ((localDW->numEdge < 0) && (m < 0))) {
                  line_idx_3 += (div_nde_s32_floor(localDW->numEdge << 1, m) + 1)
                    >> 1;
                } else {
                  line_idx_3 -= (div_nde_s32_floor(-localDW->numEdge << 1, m) +
                                 1) >> 1;
                }

                line_idx_2 = 0;
                b4 = true;
              } else if ((localDW->toIdx & 8U) != 0U) {
                /* Violated RMax. */
                localDW->numEdge = (60 - line_idx_2) * accumTwo;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (m >= 0)) ||
                           ((localDW->numEdge < 0) && (m < 0))) {
                  line_idx_3 += (div_nde_s32_floor(localDW->numEdge << 1, m) + 1)
                    >> 1;
                } else {
                  line_idx_3 -= (div_nde_s32_floor(-localDW->numEdge << 1, m) +
                                 1) >> 1;
                }

                line_idx_2 = 60;
                b4 = true;
              } else if ((localDW->toIdx & 1U) != 0U) {
                /* Violated CMin. */
                localDW->numEdge = -line_idx_3 * m;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (accumTwo >= 0)) ||
                           ((localDW->numEdge < 0) && (accumTwo < 0))) {
                  line_idx_2 += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                }

                line_idx_3 = 0;
                b4 = true;
              } else {
                /* Violated CMax. */
                localDW->numEdge = (260 - line_idx_3) * m;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (accumTwo >= 0)) ||
                           ((localDW->numEdge < 0) && (accumTwo < 0))) {
                  line_idx_2 += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumTwo) + 1) >> 1;
                }

                line_idx_3 = 260;
                b4 = true;
              }
            }
          }

          if (b2) {
            /* Draw a line using Bresenham algorithm. */
            /* Initialize the Bresenham algorithm. */
            if (line_idx_2 >= accumFour) {
              line_idx_2_0 = line_idx_2 - accumFour;
            } else {
              line_idx_2_0 = accumFour - line_idx_2;
            }

            if (line_idx_3 >= line_idx_1) {
              line_idx_3_0 = line_idx_3 - line_idx_1;
            } else {
              line_idx_3_0 = line_idx_1 - line_idx_3;
            }

            if (line_idx_2_0 > line_idx_3_0) {
              m = 1;
              localDW->numEdge = 61;
            } else {
              m = 61;
              localDW->numEdge = 1;
              accumTwo = accumFour;
              accumFour = line_idx_1;
              line_idx_1 = accumTwo;
              accumTwo = line_idx_2;
              line_idx_2 = line_idx_3;
              line_idx_3 = accumTwo;
            }

            if (accumFour > line_idx_2) {
              accumTwo = accumFour;
              accumFour = line_idx_2;
              line_idx_2 = accumTwo;
              accumTwo = line_idx_1;
              line_idx_1 = line_idx_3;
              line_idx_3 = accumTwo;
            }

            accumTwo = line_idx_2 - accumFour;
            if (line_idx_1 <= line_idx_3) {
              line_idx_0 = 1;
              line_idx_3 -= line_idx_1;
            } else {
              line_idx_0 = -1;
              line_idx_3 = line_idx_1 - line_idx_3;
            }

            line_idx_1_0 = -((accumTwo + 1) >> 1);
            line_idx_1 = accumFour * m + line_idx_1 * localDW->numEdge;
            line_idx_0 = line_idx_0 * localDW->numEdge + m;
            done = (accumFour <= line_idx_2);
            while (done) {
              rty_LineImage[line_idx_1] = MAX_uint8_T;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next pixel location. */
              line_idx_1_0 += line_idx_3;
              if (line_idx_1_0 >= 0) {
                line_idx_1_0 -= accumTwo;
                line_idx_1 += line_idx_0;
              } else {
                line_idx_1 += m;
              }

              accumFour++;
              done = (accumFour <= line_idx_2);
            }
          }
        }
      }
    }
  }

  /* End of S-Function (svipdrawshapes): '<Root>/Draw Shapes' */

  /* Selector: '<S2>/Selector' */
  localDW->Selector_DIMS1_o[0] = rty_Points_DIMS1[0];
  localDW->Selector_DIMS1_o[1] = 1;
  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_data[imgCol] = rty_Points[imgCol];
  }

  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector_p[imgCol] = localDW->rtb_Selector_data[imgCol];
  }

  /* End of Selector: '<S2>/Selector' */

  /* Selector: '<S2>/Selector3' */
  localDW->Selector3_DIMS1[0] = rty_Points_DIMS1[0];
  localDW->Selector3_DIMS1[1] = 1;
  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_data[imgCol] = rty_Points[(rty_Points_DIMS1[0] << 1) +
      imgCol];
  }

  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector3[imgCol] = localDW->rtb_Selector_data[imgCol];
  }

  /* End of Selector: '<S2>/Selector3' */

  /* Sum: '<S2>/Subtract' */
  imgRow = localDW->Selector_DIMS1_o[0] * localDW->Selector_DIMS1_o[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector_p[imgCol] -= localDW->Selector3[imgCol];
  }

  /* End of Sum: '<S2>/Subtract' */

  /* Selector: '<S2>/Selector2' */
  localDW->Selector2_DIMS1_g[0] = rty_Points_DIMS1[0];
  localDW->Selector2_DIMS1_g[1] = 1;
  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_data[imgCol] = rty_Points[imgCol + rty_Points_DIMS1[0]];
  }

  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector3[imgCol] = localDW->rtb_Selector_data[imgCol];
  }

  /* End of Selector: '<S2>/Selector2' */

  /* Selector: '<S2>/Selector4' */
  localDW->Selector4_DIMS1[0] = rty_Points_DIMS1[0];
  localDW->Selector4_DIMS1[1] = 1;
  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_data[imgCol] = rty_Points[rty_Points_DIMS1[0] * 3 +
      imgCol];
  }

  imgRow = rty_Points_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector4[imgCol] = localDW->rtb_Selector_data[imgCol];
  }

  /* End of Selector: '<S2>/Selector4' */

  /* Sum: '<S2>/Subtract1' */
  imgRow = localDW->Selector2_DIMS1_g[0] * localDW->Selector2_DIMS1_g[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector3[imgCol] -= localDW->Selector4[imgCol];
  }

  /* End of Sum: '<S2>/Subtract1' */

  /* Product: '<S2>/Divide' */
  rty_Slope_DIMS1[0] = localDW->Selector_DIMS1_o[0];
  rty_Slope_DIMS1[1] = localDW->Selector_DIMS1_o[1];
  imgRow = localDW->Selector2_DIMS1_g[0] * localDW->Selector2_DIMS1_g[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    rty_Slope[imgCol] = (real_T)localDW->Selector3[imgCol] / (real_T)
      localDW->Selector_p[imgCol];
  }

  /* End of Product: '<S2>/Divide' */
}

/* Model initialize function */
void LaneDetection_initialize(const char_T **rt_errorStatus,
  LaneDetection_RT_MODEL *const LaneDetectionrtM, LaneDetection_DW_f *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(LaneDetectionrtM, rt_errorStatus);

  /* states (dwork) */
  {
    localDW->HoughTransform_o2[0] = -1.5707963267948966;
    localDW->HoughTransform_o2[1] = -1.5533430342749532;
    localDW->HoughTransform_o2[2] = -1.53588974175501;
    localDW->HoughTransform_o2[3] = -1.5184364492350666;
    localDW->HoughTransform_o2[4] = -1.5009831567151235;
    localDW->HoughTransform_o2[5] = -1.4835298641951802;
    localDW->HoughTransform_o2[6] = -1.4660765716752369;
    localDW->HoughTransform_o2[7] = -1.4486232791552935;
    localDW->HoughTransform_o2[8] = -1.4311699866353502;
    localDW->HoughTransform_o2[9] = -1.4137166941154069;
    localDW->HoughTransform_o2[10] = -1.3962634015954636;
    localDW->HoughTransform_o2[11] = -1.3788101090755203;
    localDW->HoughTransform_o2[12] = -1.3613568165555769;
    localDW->HoughTransform_o2[13] = -1.3439035240356338;
    localDW->HoughTransform_o2[14] = -1.3264502315156905;
    localDW->HoughTransform_o2[15] = -1.3089969389957472;
    localDW->HoughTransform_o2[16] = -1.2915436464758039;
    localDW->HoughTransform_o2[17] = -1.2740903539558606;
    localDW->HoughTransform_o2[18] = -1.2566370614359172;
    localDW->HoughTransform_o2[19] = -1.2391837689159739;
    localDW->HoughTransform_o2[20] = -1.2217304763960306;
    localDW->HoughTransform_o2[21] = -1.2042771838760873;
    localDW->HoughTransform_o2[22] = -1.1868238913561442;
    localDW->HoughTransform_o2[23] = -1.1693705988362009;
    localDW->HoughTransform_o2[24] = -1.1519173063162575;
    localDW->HoughTransform_o2[25] = -1.1344640137963142;
    localDW->HoughTransform_o2[26] = -1.1170107212763709;
    localDW->HoughTransform_o2[27] = -1.0995574287564276;
    localDW->HoughTransform_o2[28] = -1.0821041362364843;
    localDW->HoughTransform_o2[29] = -1.064650843716541;
    localDW->HoughTransform_o2[30] = -1.0471975511965976;
    localDW->HoughTransform_o2[31] = -1.0297442586766545;
    localDW->HoughTransform_o2[32] = -1.0122909661567112;
    localDW->HoughTransform_o2[33] = -0.99483767363676789;
    localDW->HoughTransform_o2[34] = -0.97738438111682457;
    localDW->HoughTransform_o2[35] = -0.95993108859688125;
    localDW->HoughTransform_o2[36] = -0.94247779607693793;
    localDW->HoughTransform_o2[37] = -0.92502450355699462;
    localDW->HoughTransform_o2[38] = -0.90757121103705141;
    localDW->HoughTransform_o2[39] = -0.89011791851710809;
    localDW->HoughTransform_o2[40] = -0.87266462599716477;
    localDW->HoughTransform_o2[41] = -0.85521133347722145;
    localDW->HoughTransform_o2[42] = -0.83775804095727824;
    localDW->HoughTransform_o2[43] = -0.82030474843733492;
    localDW->HoughTransform_o2[44] = -0.8028514559173916;
    localDW->HoughTransform_o2[45] = -0.78539816339744828;
    localDW->HoughTransform_o2[46] = -0.767944870877505;
    localDW->HoughTransform_o2[47] = -0.75049157835756175;
    localDW->HoughTransform_o2[48] = -0.73303828583761843;
    localDW->HoughTransform_o2[49] = -0.71558499331767511;
    localDW->HoughTransform_o2[50] = -0.69813170079773179;
    localDW->HoughTransform_o2[51] = -0.68067840827778847;
    localDW->HoughTransform_o2[52] = -0.66322511575784526;
    localDW->HoughTransform_o2[53] = -0.64577182323790194;
    localDW->HoughTransform_o2[54] = -0.62831853071795862;
    localDW->HoughTransform_o2[55] = -0.6108652381980153;
    localDW->HoughTransform_o2[56] = -0.59341194567807209;
    localDW->HoughTransform_o2[57] = -0.57595865315812877;
    localDW->HoughTransform_o2[58] = -0.55850536063818546;
    localDW->HoughTransform_o2[59] = -0.54105206811824214;
    localDW->HoughTransform_o2[60] = -0.52359877559829882;
    localDW->HoughTransform_o2[61] = -0.50614548307835561;
    localDW->HoughTransform_o2[62] = -0.48869219055841229;
    localDW->HoughTransform_o2[63] = -0.47123889803846897;
    localDW->HoughTransform_o2[64] = -0.4537856055185257;
    localDW->HoughTransform_o2[65] = -0.43633231299858238;
    localDW->HoughTransform_o2[66] = -0.41887902047863912;
    localDW->HoughTransform_o2[67] = -0.4014257279586958;
    localDW->HoughTransform_o2[68] = -0.38397243543875248;
    localDW->HoughTransform_o2[69] = -0.36651914291880922;
    localDW->HoughTransform_o2[70] = -0.3490658503988659;
    localDW->HoughTransform_o2[71] = -0.33161255787892263;
    localDW->HoughTransform_o2[72] = -0.31415926535897931;
    localDW->HoughTransform_o2[73] = -0.29670597283903605;
    localDW->HoughTransform_o2[74] = -0.27925268031909273;
    localDW->HoughTransform_o2[75] = -0.26179938779914941;
    localDW->HoughTransform_o2[76] = -0.24434609527920614;
    localDW->HoughTransform_o2[77] = -0.22689280275926285;
    localDW->HoughTransform_o2[78] = -0.20943951023931956;
    localDW->HoughTransform_o2[79] = -0.19198621771937624;
    localDW->HoughTransform_o2[80] = -0.17453292519943295;
    localDW->HoughTransform_o2[81] = -0.15707963267948966;
    localDW->HoughTransform_o2[82] = -0.13962634015954636;
    localDW->HoughTransform_o2[83] = -0.12217304763960307;
    localDW->HoughTransform_o2[84] = -0.10471975511965978;
    localDW->HoughTransform_o2[85] = -0.087266462599716474;
    localDW->HoughTransform_o2[86] = -0.069813170079773182;
    localDW->HoughTransform_o2[87] = -0.05235987755982989;
    localDW->HoughTransform_o2[88] = -0.034906585039886591;
    localDW->HoughTransform_o2[89] = -0.017453292519943295;
    localDW->HoughTransform_o2[91] = 0.017453292519943295;
    localDW->HoughTransform_o2[92] = 0.034906585039886591;
    localDW->HoughTransform_o2[93] = 0.05235987755982989;
    localDW->HoughTransform_o2[94] = 0.069813170079773182;
    localDW->HoughTransform_o2[95] = 0.087266462599716474;
    localDW->HoughTransform_o2[96] = 0.10471975511965978;
    localDW->HoughTransform_o2[97] = 0.12217304763960307;
    localDW->HoughTransform_o2[98] = 0.13962634015954636;
    localDW->HoughTransform_o2[99] = 0.15707963267948966;
    localDW->HoughTransform_o2[100] = 0.17453292519943295;
    localDW->HoughTransform_o2[101] = 0.19198621771937624;
    localDW->HoughTransform_o2[102] = 0.20943951023931956;
    localDW->HoughTransform_o2[103] = 0.22689280275926285;
    localDW->HoughTransform_o2[104] = 0.24434609527920614;
    localDW->HoughTransform_o2[105] = 0.26179938779914941;
    localDW->HoughTransform_o2[106] = 0.27925268031909273;
    localDW->HoughTransform_o2[107] = 0.29670597283903605;
    localDW->HoughTransform_o2[108] = 0.31415926535897931;
    localDW->HoughTransform_o2[109] = 0.33161255787892263;
    localDW->HoughTransform_o2[110] = 0.3490658503988659;
    localDW->HoughTransform_o2[111] = 0.36651914291880922;
    localDW->HoughTransform_o2[112] = 0.38397243543875248;
    localDW->HoughTransform_o2[113] = 0.4014257279586958;
    localDW->HoughTransform_o2[114] = 0.41887902047863912;
    localDW->HoughTransform_o2[115] = 0.43633231299858238;
    localDW->HoughTransform_o2[116] = 0.4537856055185257;
    localDW->HoughTransform_o2[117] = 0.47123889803846897;
    localDW->HoughTransform_o2[118] = 0.48869219055841229;
    localDW->HoughTransform_o2[119] = 0.50614548307835561;
    localDW->HoughTransform_o2[120] = 0.52359877559829882;
    localDW->HoughTransform_o2[121] = 0.54105206811824214;
    localDW->HoughTransform_o2[122] = 0.55850536063818546;
    localDW->HoughTransform_o2[123] = 0.57595865315812877;
    localDW->HoughTransform_o2[124] = 0.59341194567807209;
    localDW->HoughTransform_o2[125] = 0.6108652381980153;
    localDW->HoughTransform_o2[126] = 0.62831853071795862;
    localDW->HoughTransform_o2[127] = 0.64577182323790194;
    localDW->HoughTransform_o2[128] = 0.66322511575784526;
    localDW->HoughTransform_o2[129] = 0.68067840827778847;
    localDW->HoughTransform_o2[130] = 0.69813170079773179;
    localDW->HoughTransform_o2[131] = 0.71558499331767511;
    localDW->HoughTransform_o2[132] = 0.73303828583761843;
    localDW->HoughTransform_o2[133] = 0.75049157835756175;
    localDW->HoughTransform_o2[134] = 0.767944870877505;
    localDW->HoughTransform_o2[135] = 0.78539816339744828;
    localDW->HoughTransform_o2[136] = 0.8028514559173916;
    localDW->HoughTransform_o2[137] = 0.82030474843733492;
    localDW->HoughTransform_o2[138] = 0.83775804095727824;
    localDW->HoughTransform_o2[139] = 0.85521133347722145;
    localDW->HoughTransform_o2[140] = 0.87266462599716477;
    localDW->HoughTransform_o2[141] = 0.89011791851710809;
    localDW->HoughTransform_o2[142] = 0.90757121103705141;
    localDW->HoughTransform_o2[143] = 0.92502450355699462;
    localDW->HoughTransform_o2[144] = 0.94247779607693793;
    localDW->HoughTransform_o2[145] = 0.95993108859688125;
    localDW->HoughTransform_o2[146] = 0.97738438111682457;
    localDW->HoughTransform_o2[147] = 0.99483767363676789;
    localDW->HoughTransform_o2[148] = 1.0122909661567112;
    localDW->HoughTransform_o2[149] = 1.0297442586766545;
    localDW->HoughTransform_o2[150] = 1.0471975511965976;
    localDW->HoughTransform_o2[151] = 1.064650843716541;
    localDW->HoughTransform_o2[152] = 1.0821041362364843;
    localDW->HoughTransform_o2[153] = 1.0995574287564276;
    localDW->HoughTransform_o2[154] = 1.1170107212763709;
    localDW->HoughTransform_o2[155] = 1.1344640137963142;
    localDW->HoughTransform_o2[156] = 1.1519173063162575;
    localDW->HoughTransform_o2[157] = 1.1693705988362009;
    localDW->HoughTransform_o2[158] = 1.1868238913561442;
    localDW->HoughTransform_o2[159] = 1.2042771838760873;
    localDW->HoughTransform_o2[160] = 1.2217304763960306;
    localDW->HoughTransform_o2[161] = 1.2391837689159739;
    localDW->HoughTransform_o2[162] = 1.2566370614359172;
    localDW->HoughTransform_o2[163] = 1.2740903539558606;
    localDW->HoughTransform_o2[164] = 1.2915436464758039;
    localDW->HoughTransform_o2[165] = 1.3089969389957472;
    localDW->HoughTransform_o2[166] = 1.3264502315156905;
    localDW->HoughTransform_o2[167] = 1.3439035240356338;
    localDW->HoughTransform_o2[168] = 1.3613568165555769;
    localDW->HoughTransform_o2[169] = 1.3788101090755203;
    localDW->HoughTransform_o2[170] = 1.3962634015954636;
    localDW->HoughTransform_o2[171] = 1.4137166941154069;
    localDW->HoughTransform_o2[172] = 1.4311699866353502;
    localDW->HoughTransform_o2[173] = 1.4486232791552935;
    localDW->HoughTransform_o2[174] = 1.4660765716752369;
    localDW->HoughTransform_o2[175] = 1.4835298641951802;
    localDW->HoughTransform_o2[176] = 1.5009831567151235;
    localDW->HoughTransform_o2[177] = 1.5184364492350666;
    localDW->HoughTransform_o2[178] = 1.53588974175501;
    localDW->HoughTransform_o2[179] = 1.5533430342749532;
    localDW->HoughTransform_o3[0] = -267.0;
    localDW->HoughTransform_o3[1] = -266.0;
    localDW->HoughTransform_o3[2] = -265.0;
    localDW->HoughTransform_o3[3] = -264.0;
    localDW->HoughTransform_o3[4] = -263.0;
    localDW->HoughTransform_o3[5] = -262.0;
    localDW->HoughTransform_o3[6] = -261.0;
    localDW->HoughTransform_o3[7] = -260.0;
    localDW->HoughTransform_o3[8] = -259.0;
    localDW->HoughTransform_o3[9] = -258.0;
    localDW->HoughTransform_o3[10] = -257.0;
    localDW->HoughTransform_o3[11] = -256.0;
    localDW->HoughTransform_o3[12] = -255.0;
    localDW->HoughTransform_o3[13] = -254.0;
    localDW->HoughTransform_o3[14] = -253.0;
    localDW->HoughTransform_o3[15] = -252.0;
    localDW->HoughTransform_o3[16] = -251.0;
    localDW->HoughTransform_o3[17] = -250.0;
    localDW->HoughTransform_o3[18] = -249.0;
    localDW->HoughTransform_o3[19] = -248.0;
    localDW->HoughTransform_o3[20] = -247.0;
    localDW->HoughTransform_o3[21] = -246.0;
    localDW->HoughTransform_o3[22] = -245.0;
    localDW->HoughTransform_o3[23] = -244.0;
    localDW->HoughTransform_o3[24] = -243.0;
    localDW->HoughTransform_o3[25] = -242.0;
    localDW->HoughTransform_o3[26] = -241.0;
    localDW->HoughTransform_o3[27] = -240.0;
    localDW->HoughTransform_o3[28] = -239.0;
    localDW->HoughTransform_o3[29] = -238.0;
    localDW->HoughTransform_o3[30] = -237.0;
    localDW->HoughTransform_o3[31] = -236.0;
    localDW->HoughTransform_o3[32] = -235.0;
    localDW->HoughTransform_o3[33] = -234.0;
    localDW->HoughTransform_o3[34] = -233.0;
    localDW->HoughTransform_o3[35] = -232.0;
    localDW->HoughTransform_o3[36] = -231.0;
    localDW->HoughTransform_o3[37] = -230.0;
    localDW->HoughTransform_o3[38] = -229.0;
    localDW->HoughTransform_o3[39] = -228.0;
    localDW->HoughTransform_o3[40] = -227.0;
    localDW->HoughTransform_o3[41] = -226.0;
    localDW->HoughTransform_o3[42] = -225.0;
    localDW->HoughTransform_o3[43] = -224.0;
    localDW->HoughTransform_o3[44] = -223.0;
    localDW->HoughTransform_o3[45] = -222.0;
    localDW->HoughTransform_o3[46] = -221.0;
    localDW->HoughTransform_o3[47] = -220.0;
    localDW->HoughTransform_o3[48] = -219.0;
    localDW->HoughTransform_o3[49] = -218.0;
    localDW->HoughTransform_o3[50] = -217.0;
    localDW->HoughTransform_o3[51] = -216.0;
    localDW->HoughTransform_o3[52] = -215.0;
    localDW->HoughTransform_o3[53] = -214.0;
    localDW->HoughTransform_o3[54] = -213.0;
    localDW->HoughTransform_o3[55] = -212.0;
    localDW->HoughTransform_o3[56] = -211.0;
    localDW->HoughTransform_o3[57] = -210.0;
    localDW->HoughTransform_o3[58] = -209.0;
    localDW->HoughTransform_o3[59] = -208.0;
    localDW->HoughTransform_o3[60] = -207.0;
    localDW->HoughTransform_o3[61] = -206.0;
    localDW->HoughTransform_o3[62] = -205.0;
    localDW->HoughTransform_o3[63] = -204.0;
    localDW->HoughTransform_o3[64] = -203.0;
    localDW->HoughTransform_o3[65] = -202.0;
    localDW->HoughTransform_o3[66] = -201.0;
    localDW->HoughTransform_o3[67] = -200.0;
    localDW->HoughTransform_o3[68] = -199.0;
    localDW->HoughTransform_o3[69] = -198.0;
    localDW->HoughTransform_o3[70] = -197.0;
    localDW->HoughTransform_o3[71] = -196.0;
    localDW->HoughTransform_o3[72] = -195.0;
    localDW->HoughTransform_o3[73] = -194.0;
    localDW->HoughTransform_o3[74] = -193.0;
    localDW->HoughTransform_o3[75] = -192.0;
    localDW->HoughTransform_o3[76] = -191.0;
    localDW->HoughTransform_o3[77] = -190.0;
    localDW->HoughTransform_o3[78] = -189.0;
    localDW->HoughTransform_o3[79] = -188.0;
    localDW->HoughTransform_o3[80] = -187.0;
    localDW->HoughTransform_o3[81] = -186.0;
    localDW->HoughTransform_o3[82] = -185.0;
    localDW->HoughTransform_o3[83] = -184.0;
    localDW->HoughTransform_o3[84] = -183.0;
    localDW->HoughTransform_o3[85] = -182.0;
    localDW->HoughTransform_o3[86] = -181.0;
    localDW->HoughTransform_o3[87] = -180.0;
    localDW->HoughTransform_o3[88] = -179.0;
    localDW->HoughTransform_o3[89] = -178.0;
    localDW->HoughTransform_o3[90] = -177.0;
    localDW->HoughTransform_o3[91] = -176.0;
    localDW->HoughTransform_o3[92] = -175.0;
    localDW->HoughTransform_o3[93] = -174.0;
    localDW->HoughTransform_o3[94] = -173.0;
    localDW->HoughTransform_o3[95] = -172.0;
    localDW->HoughTransform_o3[96] = -171.0;
    localDW->HoughTransform_o3[97] = -170.0;
    localDW->HoughTransform_o3[98] = -169.0;
    localDW->HoughTransform_o3[99] = -168.0;
    localDW->HoughTransform_o3[100] = -167.0;
    localDW->HoughTransform_o3[101] = -166.0;
    localDW->HoughTransform_o3[102] = -165.0;
    localDW->HoughTransform_o3[103] = -164.0;
    localDW->HoughTransform_o3[104] = -163.0;
    localDW->HoughTransform_o3[105] = -162.0;
    localDW->HoughTransform_o3[106] = -161.0;
    localDW->HoughTransform_o3[107] = -160.0;
    localDW->HoughTransform_o3[108] = -159.0;
    localDW->HoughTransform_o3[109] = -158.0;
    localDW->HoughTransform_o3[110] = -157.0;
    localDW->HoughTransform_o3[111] = -156.0;
    localDW->HoughTransform_o3[112] = -155.0;
    localDW->HoughTransform_o3[113] = -154.0;
    localDW->HoughTransform_o3[114] = -153.0;
    localDW->HoughTransform_o3[115] = -152.0;
    localDW->HoughTransform_o3[116] = -151.0;
    localDW->HoughTransform_o3[117] = -150.0;
    localDW->HoughTransform_o3[118] = -149.0;
    localDW->HoughTransform_o3[119] = -148.0;
    localDW->HoughTransform_o3[120] = -147.0;
    localDW->HoughTransform_o3[121] = -146.0;
    localDW->HoughTransform_o3[122] = -145.0;
    localDW->HoughTransform_o3[123] = -144.0;
    localDW->HoughTransform_o3[124] = -143.0;
    localDW->HoughTransform_o3[125] = -142.0;
    localDW->HoughTransform_o3[126] = -141.0;
    localDW->HoughTransform_o3[127] = -140.0;
    localDW->HoughTransform_o3[128] = -139.0;
    localDW->HoughTransform_o3[129] = -138.0;
    localDW->HoughTransform_o3[130] = -137.0;
    localDW->HoughTransform_o3[131] = -136.0;
    localDW->HoughTransform_o3[132] = -135.0;
    localDW->HoughTransform_o3[133] = -134.0;
    localDW->HoughTransform_o3[134] = -133.0;
    localDW->HoughTransform_o3[135] = -132.0;
    localDW->HoughTransform_o3[136] = -131.0;
    localDW->HoughTransform_o3[137] = -130.0;
    localDW->HoughTransform_o3[138] = -129.0;
    localDW->HoughTransform_o3[139] = -128.0;
    localDW->HoughTransform_o3[140] = -127.0;
    localDW->HoughTransform_o3[141] = -126.0;
    localDW->HoughTransform_o3[142] = -125.0;
    localDW->HoughTransform_o3[143] = -124.0;
    localDW->HoughTransform_o3[144] = -123.0;
    localDW->HoughTransform_o3[145] = -122.0;
    localDW->HoughTransform_o3[146] = -121.0;
    localDW->HoughTransform_o3[147] = -120.0;
    localDW->HoughTransform_o3[148] = -119.0;
    localDW->HoughTransform_o3[149] = -118.0;
    localDW->HoughTransform_o3[150] = -117.0;
    localDW->HoughTransform_o3[151] = -116.0;
    localDW->HoughTransform_o3[152] = -115.0;
    localDW->HoughTransform_o3[153] = -114.0;
    localDW->HoughTransform_o3[154] = -113.0;
    localDW->HoughTransform_o3[155] = -112.0;
    localDW->HoughTransform_o3[156] = -111.0;
    localDW->HoughTransform_o3[157] = -110.0;
    localDW->HoughTransform_o3[158] = -109.0;
    localDW->HoughTransform_o3[159] = -108.0;
    localDW->HoughTransform_o3[160] = -107.0;
    localDW->HoughTransform_o3[161] = -106.0;
    localDW->HoughTransform_o3[162] = -105.0;
    localDW->HoughTransform_o3[163] = -104.0;
    localDW->HoughTransform_o3[164] = -103.0;
    localDW->HoughTransform_o3[165] = -102.0;
    localDW->HoughTransform_o3[166] = -101.0;
    localDW->HoughTransform_o3[167] = -100.0;
    localDW->HoughTransform_o3[168] = -99.0;
    localDW->HoughTransform_o3[169] = -98.0;
    localDW->HoughTransform_o3[170] = -97.0;
    localDW->HoughTransform_o3[171] = -96.0;
    localDW->HoughTransform_o3[172] = -95.0;
    localDW->HoughTransform_o3[173] = -94.0;
    localDW->HoughTransform_o3[174] = -93.0;
    localDW->HoughTransform_o3[175] = -92.0;
    localDW->HoughTransform_o3[176] = -91.0;
    localDW->HoughTransform_o3[177] = -90.0;
    localDW->HoughTransform_o3[178] = -89.0;
    localDW->HoughTransform_o3[179] = -88.0;
    localDW->HoughTransform_o3[180] = -87.0;
    localDW->HoughTransform_o3[181] = -86.0;
    localDW->HoughTransform_o3[182] = -85.0;
    localDW->HoughTransform_o3[183] = -84.0;
    localDW->HoughTransform_o3[184] = -83.0;
    localDW->HoughTransform_o3[185] = -82.0;
    localDW->HoughTransform_o3[186] = -81.0;
    localDW->HoughTransform_o3[187] = -80.0;
    localDW->HoughTransform_o3[188] = -79.0;
    localDW->HoughTransform_o3[189] = -78.0;
    localDW->HoughTransform_o3[190] = -77.0;
    localDW->HoughTransform_o3[191] = -76.0;
    localDW->HoughTransform_o3[192] = -75.0;
    localDW->HoughTransform_o3[193] = -74.0;
    localDW->HoughTransform_o3[194] = -73.0;
    localDW->HoughTransform_o3[195] = -72.0;
    localDW->HoughTransform_o3[196] = -71.0;
    localDW->HoughTransform_o3[197] = -70.0;
    localDW->HoughTransform_o3[198] = -69.0;
    localDW->HoughTransform_o3[199] = -68.0;
    localDW->HoughTransform_o3[200] = -67.0;
    localDW->HoughTransform_o3[201] = -66.0;
    localDW->HoughTransform_o3[202] = -65.0;
    localDW->HoughTransform_o3[203] = -64.0;
    localDW->HoughTransform_o3[204] = -63.0;
    localDW->HoughTransform_o3[205] = -62.0;
    localDW->HoughTransform_o3[206] = -61.0;
    localDW->HoughTransform_o3[207] = -60.0;
    localDW->HoughTransform_o3[208] = -59.0;
    localDW->HoughTransform_o3[209] = -58.0;
    localDW->HoughTransform_o3[210] = -57.0;
    localDW->HoughTransform_o3[211] = -56.0;
    localDW->HoughTransform_o3[212] = -55.0;
    localDW->HoughTransform_o3[213] = -54.0;
    localDW->HoughTransform_o3[214] = -53.0;
    localDW->HoughTransform_o3[215] = -52.0;
    localDW->HoughTransform_o3[216] = -51.0;
    localDW->HoughTransform_o3[217] = -50.0;
    localDW->HoughTransform_o3[218] = -49.0;
    localDW->HoughTransform_o3[219] = -48.0;
    localDW->HoughTransform_o3[220] = -47.0;
    localDW->HoughTransform_o3[221] = -46.0;
    localDW->HoughTransform_o3[222] = -45.0;
    localDW->HoughTransform_o3[223] = -44.0;
    localDW->HoughTransform_o3[224] = -43.0;
    localDW->HoughTransform_o3[225] = -42.0;
    localDW->HoughTransform_o3[226] = -41.0;
    localDW->HoughTransform_o3[227] = -40.0;
    localDW->HoughTransform_o3[228] = -39.0;
    localDW->HoughTransform_o3[229] = -38.0;
    localDW->HoughTransform_o3[230] = -37.0;
    localDW->HoughTransform_o3[231] = -36.0;
    localDW->HoughTransform_o3[232] = -35.0;
    localDW->HoughTransform_o3[233] = -34.0;
    localDW->HoughTransform_o3[234] = -33.0;
    localDW->HoughTransform_o3[235] = -32.0;
    localDW->HoughTransform_o3[236] = -31.0;
    localDW->HoughTransform_o3[237] = -30.0;
    localDW->HoughTransform_o3[238] = -29.0;
    localDW->HoughTransform_o3[239] = -28.0;
    localDW->HoughTransform_o3[240] = -27.0;
    localDW->HoughTransform_o3[241] = -26.0;
    localDW->HoughTransform_o3[242] = -25.0;
    localDW->HoughTransform_o3[243] = -24.0;
    localDW->HoughTransform_o3[244] = -23.0;
    localDW->HoughTransform_o3[245] = -22.0;
    localDW->HoughTransform_o3[246] = -21.0;
    localDW->HoughTransform_o3[247] = -20.0;
    localDW->HoughTransform_o3[248] = -19.0;
    localDW->HoughTransform_o3[249] = -18.0;
    localDW->HoughTransform_o3[250] = -17.0;
    localDW->HoughTransform_o3[251] = -16.0;
    localDW->HoughTransform_o3[252] = -15.0;
    localDW->HoughTransform_o3[253] = -14.0;
    localDW->HoughTransform_o3[254] = -13.0;
    localDW->HoughTransform_o3[255] = -12.0;
    localDW->HoughTransform_o3[256] = -11.0;
    localDW->HoughTransform_o3[257] = -10.0;
    localDW->HoughTransform_o3[258] = -9.0;
    localDW->HoughTransform_o3[259] = -8.0;
    localDW->HoughTransform_o3[260] = -7.0;
    localDW->HoughTransform_o3[261] = -6.0;
    localDW->HoughTransform_o3[262] = -5.0;
    localDW->HoughTransform_o3[263] = -4.0;
    localDW->HoughTransform_o3[264] = -3.0;
    localDW->HoughTransform_o3[265] = -2.0;
    localDW->HoughTransform_o3[266] = -1.0;
    localDW->HoughTransform_o3[268] = 1.0;
    localDW->HoughTransform_o3[269] = 2.0;
    localDW->HoughTransform_o3[270] = 3.0;
    localDW->HoughTransform_o3[271] = 4.0;
    localDW->HoughTransform_o3[272] = 5.0;
    localDW->HoughTransform_o3[273] = 6.0;
    localDW->HoughTransform_o3[274] = 7.0;
    localDW->HoughTransform_o3[275] = 8.0;
    localDW->HoughTransform_o3[276] = 9.0;
    localDW->HoughTransform_o3[277] = 10.0;
    localDW->HoughTransform_o3[278] = 11.0;
    localDW->HoughTransform_o3[279] = 12.0;
    localDW->HoughTransform_o3[280] = 13.0;
    localDW->HoughTransform_o3[281] = 14.0;
    localDW->HoughTransform_o3[282] = 15.0;
    localDW->HoughTransform_o3[283] = 16.0;
    localDW->HoughTransform_o3[284] = 17.0;
    localDW->HoughTransform_o3[285] = 18.0;
    localDW->HoughTransform_o3[286] = 19.0;
    localDW->HoughTransform_o3[287] = 20.0;
    localDW->HoughTransform_o3[288] = 21.0;
    localDW->HoughTransform_o3[289] = 22.0;
    localDW->HoughTransform_o3[290] = 23.0;
    localDW->HoughTransform_o3[291] = 24.0;
    localDW->HoughTransform_o3[292] = 25.0;
    localDW->HoughTransform_o3[293] = 26.0;
    localDW->HoughTransform_o3[294] = 27.0;
    localDW->HoughTransform_o3[295] = 28.0;
    localDW->HoughTransform_o3[296] = 29.0;
    localDW->HoughTransform_o3[297] = 30.0;
    localDW->HoughTransform_o3[298] = 31.0;
    localDW->HoughTransform_o3[299] = 32.0;
    localDW->HoughTransform_o3[300] = 33.0;
    localDW->HoughTransform_o3[301] = 34.0;
    localDW->HoughTransform_o3[302] = 35.0;
    localDW->HoughTransform_o3[303] = 36.0;
    localDW->HoughTransform_o3[304] = 37.0;
    localDW->HoughTransform_o3[305] = 38.0;
    localDW->HoughTransform_o3[306] = 39.0;
    localDW->HoughTransform_o3[307] = 40.0;
    localDW->HoughTransform_o3[308] = 41.0;
    localDW->HoughTransform_o3[309] = 42.0;
    localDW->HoughTransform_o3[310] = 43.0;
    localDW->HoughTransform_o3[311] = 44.0;
    localDW->HoughTransform_o3[312] = 45.0;
    localDW->HoughTransform_o3[313] = 46.0;
    localDW->HoughTransform_o3[314] = 47.0;
    localDW->HoughTransform_o3[315] = 48.0;
    localDW->HoughTransform_o3[316] = 49.0;
    localDW->HoughTransform_o3[317] = 50.0;
    localDW->HoughTransform_o3[318] = 51.0;
    localDW->HoughTransform_o3[319] = 52.0;
    localDW->HoughTransform_o3[320] = 53.0;
    localDW->HoughTransform_o3[321] = 54.0;
    localDW->HoughTransform_o3[322] = 55.0;
    localDW->HoughTransform_o3[323] = 56.0;
    localDW->HoughTransform_o3[324] = 57.0;
    localDW->HoughTransform_o3[325] = 58.0;
    localDW->HoughTransform_o3[326] = 59.0;
    localDW->HoughTransform_o3[327] = 60.0;
    localDW->HoughTransform_o3[328] = 61.0;
    localDW->HoughTransform_o3[329] = 62.0;
    localDW->HoughTransform_o3[330] = 63.0;
    localDW->HoughTransform_o3[331] = 64.0;
    localDW->HoughTransform_o3[332] = 65.0;
    localDW->HoughTransform_o3[333] = 66.0;
    localDW->HoughTransform_o3[334] = 67.0;
    localDW->HoughTransform_o3[335] = 68.0;
    localDW->HoughTransform_o3[336] = 69.0;
    localDW->HoughTransform_o3[337] = 70.0;
    localDW->HoughTransform_o3[338] = 71.0;
    localDW->HoughTransform_o3[339] = 72.0;
    localDW->HoughTransform_o3[340] = 73.0;
    localDW->HoughTransform_o3[341] = 74.0;
    localDW->HoughTransform_o3[342] = 75.0;
    localDW->HoughTransform_o3[343] = 76.0;
    localDW->HoughTransform_o3[344] = 77.0;
    localDW->HoughTransform_o3[345] = 78.0;
    localDW->HoughTransform_o3[346] = 79.0;
    localDW->HoughTransform_o3[347] = 80.0;
    localDW->HoughTransform_o3[348] = 81.0;
    localDW->HoughTransform_o3[349] = 82.0;
    localDW->HoughTransform_o3[350] = 83.0;
    localDW->HoughTransform_o3[351] = 84.0;
    localDW->HoughTransform_o3[352] = 85.0;
    localDW->HoughTransform_o3[353] = 86.0;
    localDW->HoughTransform_o3[354] = 87.0;
    localDW->HoughTransform_o3[355] = 88.0;
    localDW->HoughTransform_o3[356] = 89.0;
    localDW->HoughTransform_o3[357] = 90.0;
    localDW->HoughTransform_o3[358] = 91.0;
    localDW->HoughTransform_o3[359] = 92.0;
    localDW->HoughTransform_o3[360] = 93.0;
    localDW->HoughTransform_o3[361] = 94.0;
    localDW->HoughTransform_o3[362] = 95.0;
    localDW->HoughTransform_o3[363] = 96.0;
    localDW->HoughTransform_o3[364] = 97.0;
    localDW->HoughTransform_o3[365] = 98.0;
    localDW->HoughTransform_o3[366] = 99.0;
    localDW->HoughTransform_o3[367] = 100.0;
    localDW->HoughTransform_o3[368] = 101.0;
    localDW->HoughTransform_o3[369] = 102.0;
    localDW->HoughTransform_o3[370] = 103.0;
    localDW->HoughTransform_o3[371] = 104.0;
    localDW->HoughTransform_o3[372] = 105.0;
    localDW->HoughTransform_o3[373] = 106.0;
    localDW->HoughTransform_o3[374] = 107.0;
    localDW->HoughTransform_o3[375] = 108.0;
    localDW->HoughTransform_o3[376] = 109.0;
    localDW->HoughTransform_o3[377] = 110.0;
    localDW->HoughTransform_o3[378] = 111.0;
    localDW->HoughTransform_o3[379] = 112.0;
    localDW->HoughTransform_o3[380] = 113.0;
    localDW->HoughTransform_o3[381] = 114.0;
    localDW->HoughTransform_o3[382] = 115.0;
    localDW->HoughTransform_o3[383] = 116.0;
    localDW->HoughTransform_o3[384] = 117.0;
    localDW->HoughTransform_o3[385] = 118.0;
    localDW->HoughTransform_o3[386] = 119.0;
    localDW->HoughTransform_o3[387] = 120.0;
    localDW->HoughTransform_o3[388] = 121.0;
    localDW->HoughTransform_o3[389] = 122.0;
    localDW->HoughTransform_o3[390] = 123.0;
    localDW->HoughTransform_o3[391] = 124.0;
    localDW->HoughTransform_o3[392] = 125.0;
    localDW->HoughTransform_o3[393] = 126.0;
    localDW->HoughTransform_o3[394] = 127.0;
    localDW->HoughTransform_o3[395] = 128.0;
    localDW->HoughTransform_o3[396] = 129.0;
    localDW->HoughTransform_o3[397] = 130.0;
    localDW->HoughTransform_o3[398] = 131.0;
    localDW->HoughTransform_o3[399] = 132.0;
    localDW->HoughTransform_o3[400] = 133.0;
    localDW->HoughTransform_o3[401] = 134.0;
    localDW->HoughTransform_o3[402] = 135.0;
    localDW->HoughTransform_o3[403] = 136.0;
    localDW->HoughTransform_o3[404] = 137.0;
    localDW->HoughTransform_o3[405] = 138.0;
    localDW->HoughTransform_o3[406] = 139.0;
    localDW->HoughTransform_o3[407] = 140.0;
    localDW->HoughTransform_o3[408] = 141.0;
    localDW->HoughTransform_o3[409] = 142.0;
    localDW->HoughTransform_o3[410] = 143.0;
    localDW->HoughTransform_o3[411] = 144.0;
    localDW->HoughTransform_o3[412] = 145.0;
    localDW->HoughTransform_o3[413] = 146.0;
    localDW->HoughTransform_o3[414] = 147.0;
    localDW->HoughTransform_o3[415] = 148.0;
    localDW->HoughTransform_o3[416] = 149.0;
    localDW->HoughTransform_o3[417] = 150.0;
    localDW->HoughTransform_o3[418] = 151.0;
    localDW->HoughTransform_o3[419] = 152.0;
    localDW->HoughTransform_o3[420] = 153.0;
    localDW->HoughTransform_o3[421] = 154.0;
    localDW->HoughTransform_o3[422] = 155.0;
    localDW->HoughTransform_o3[423] = 156.0;
    localDW->HoughTransform_o3[424] = 157.0;
    localDW->HoughTransform_o3[425] = 158.0;
    localDW->HoughTransform_o3[426] = 159.0;
    localDW->HoughTransform_o3[427] = 160.0;
    localDW->HoughTransform_o3[428] = 161.0;
    localDW->HoughTransform_o3[429] = 162.0;
    localDW->HoughTransform_o3[430] = 163.0;
    localDW->HoughTransform_o3[431] = 164.0;
    localDW->HoughTransform_o3[432] = 165.0;
    localDW->HoughTransform_o3[433] = 166.0;
    localDW->HoughTransform_o3[434] = 167.0;
    localDW->HoughTransform_o3[435] = 168.0;
    localDW->HoughTransform_o3[436] = 169.0;
    localDW->HoughTransform_o3[437] = 170.0;
    localDW->HoughTransform_o3[438] = 171.0;
    localDW->HoughTransform_o3[439] = 172.0;
    localDW->HoughTransform_o3[440] = 173.0;
    localDW->HoughTransform_o3[441] = 174.0;
    localDW->HoughTransform_o3[442] = 175.0;
    localDW->HoughTransform_o3[443] = 176.0;
    localDW->HoughTransform_o3[444] = 177.0;
    localDW->HoughTransform_o3[445] = 178.0;
    localDW->HoughTransform_o3[446] = 179.0;
    localDW->HoughTransform_o3[447] = 180.0;
    localDW->HoughTransform_o3[448] = 181.0;
    localDW->HoughTransform_o3[449] = 182.0;
    localDW->HoughTransform_o3[450] = 183.0;
    localDW->HoughTransform_o3[451] = 184.0;
    localDW->HoughTransform_o3[452] = 185.0;
    localDW->HoughTransform_o3[453] = 186.0;
    localDW->HoughTransform_o3[454] = 187.0;
    localDW->HoughTransform_o3[455] = 188.0;
    localDW->HoughTransform_o3[456] = 189.0;
    localDW->HoughTransform_o3[457] = 190.0;
    localDW->HoughTransform_o3[458] = 191.0;
    localDW->HoughTransform_o3[459] = 192.0;
    localDW->HoughTransform_o3[460] = 193.0;
    localDW->HoughTransform_o3[461] = 194.0;
    localDW->HoughTransform_o3[462] = 195.0;
    localDW->HoughTransform_o3[463] = 196.0;
    localDW->HoughTransform_o3[464] = 197.0;
    localDW->HoughTransform_o3[465] = 198.0;
    localDW->HoughTransform_o3[466] = 199.0;
    localDW->HoughTransform_o3[467] = 200.0;
    localDW->HoughTransform_o3[468] = 201.0;
    localDW->HoughTransform_o3[469] = 202.0;
    localDW->HoughTransform_o3[470] = 203.0;
    localDW->HoughTransform_o3[471] = 204.0;
    localDW->HoughTransform_o3[472] = 205.0;
    localDW->HoughTransform_o3[473] = 206.0;
    localDW->HoughTransform_o3[474] = 207.0;
    localDW->HoughTransform_o3[475] = 208.0;
    localDW->HoughTransform_o3[476] = 209.0;
    localDW->HoughTransform_o3[477] = 210.0;
    localDW->HoughTransform_o3[478] = 211.0;
    localDW->HoughTransform_o3[479] = 212.0;
    localDW->HoughTransform_o3[480] = 213.0;
    localDW->HoughTransform_o3[481] = 214.0;
    localDW->HoughTransform_o3[482] = 215.0;
    localDW->HoughTransform_o3[483] = 216.0;
    localDW->HoughTransform_o3[484] = 217.0;
    localDW->HoughTransform_o3[485] = 218.0;
    localDW->HoughTransform_o3[486] = 219.0;
    localDW->HoughTransform_o3[487] = 220.0;
    localDW->HoughTransform_o3[488] = 221.0;
    localDW->HoughTransform_o3[489] = 222.0;
    localDW->HoughTransform_o3[490] = 223.0;
    localDW->HoughTransform_o3[491] = 224.0;
    localDW->HoughTransform_o3[492] = 225.0;
    localDW->HoughTransform_o3[493] = 226.0;
    localDW->HoughTransform_o3[494] = 227.0;
    localDW->HoughTransform_o3[495] = 228.0;
    localDW->HoughTransform_o3[496] = 229.0;
    localDW->HoughTransform_o3[497] = 230.0;
    localDW->HoughTransform_o3[498] = 231.0;
    localDW->HoughTransform_o3[499] = 232.0;
    localDW->HoughTransform_o3[500] = 233.0;
    localDW->HoughTransform_o3[501] = 234.0;
    localDW->HoughTransform_o3[502] = 235.0;
    localDW->HoughTransform_o3[503] = 236.0;
    localDW->HoughTransform_o3[504] = 237.0;
    localDW->HoughTransform_o3[505] = 238.0;
    localDW->HoughTransform_o3[506] = 239.0;
    localDW->HoughTransform_o3[507] = 240.0;
    localDW->HoughTransform_o3[508] = 241.0;
    localDW->HoughTransform_o3[509] = 242.0;
    localDW->HoughTransform_o3[510] = 243.0;
    localDW->HoughTransform_o3[511] = 244.0;
    localDW->HoughTransform_o3[512] = 245.0;
    localDW->HoughTransform_o3[513] = 246.0;
    localDW->HoughTransform_o3[514] = 247.0;
    localDW->HoughTransform_o3[515] = 248.0;
    localDW->HoughTransform_o3[516] = 249.0;
    localDW->HoughTransform_o3[517] = 250.0;
    localDW->HoughTransform_o3[518] = 251.0;
    localDW->HoughTransform_o3[519] = 252.0;
    localDW->HoughTransform_o3[520] = 253.0;
    localDW->HoughTransform_o3[521] = 254.0;
    localDW->HoughTransform_o3[522] = 255.0;
    localDW->HoughTransform_o3[523] = 256.0;
    localDW->HoughTransform_o3[524] = 257.0;
    localDW->HoughTransform_o3[525] = 258.0;
    localDW->HoughTransform_o3[526] = 259.0;
    localDW->HoughTransform_o3[527] = 260.0;
    localDW->HoughTransform_o3[528] = 261.0;
    localDW->HoughTransform_o3[529] = 262.0;
    localDW->HoughTransform_o3[530] = 263.0;
    localDW->HoughTransform_o3[531] = 264.0;
    localDW->HoughTransform_o3[532] = 265.0;
    localDW->HoughTransform_o3[533] = 266.0;
    localDW->HoughTransform_o3[534] = 267.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
