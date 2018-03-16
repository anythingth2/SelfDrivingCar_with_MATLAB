/*
 * File: LaneDetection.c
 *
 * Code generated for Simulink model 'LaneDetection'.
 *
 * Model version                  : 1.264
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Mar 17 01:21:22 2018
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

extern const real_T rtCP_pooled_lpgonDqdKy1l[61];
extern const real_T rtCP_pooled_eOCOUVt9XfID[281];
extern const real_T rtCP_pooled_hNlvttwOChI0[13];
extern const real_T rtCP_pooled_ai66rjwJqI4l;
extern const int32_T rtCP_pooled_9H9mPzIgD49d[6];
extern const int32_T rtCP_pooled_berHTRPvDDTn[6];
extern const int32_T rtCP_pooled_vw7bACqMwvtP[6];
extern const int32_T rtCP_pooled_RXsOmBvvADoW[6];
extern const int32_T rtCP_pooled_I29smDgh1ZlF[6];
extern const int32_T rtCP_pooled_C08a0ezfB1lz[6];

#define rtCP_ROI_Y_Value               rtCP_pooled_lpgonDqdKy1l  /* Expression: [140:200]
                                                                  * Referenced by: '<Root>/ROI_Y'
                                                                  */
#define rtCP_ROI_X_Value               rtCP_pooled_eOCOUVt9XfID  /* Expression: [20:300]
                                                                  * Referenced by: '<Root>/ROI_X'
                                                                  */
#define rtCP_HoughTransform_SINE_TABLE_ rtCP_pooled_hNlvttwOChI0 /* Computed Parameter: rtCP_HoughTransform_SINE_TABLE_
                                                                  * Referenced by: '<S1>/Hough Transform'
                                                                  */
#define rtCP_HoughTransform_FIRSTRHO_RT rtCP_pooled_ai66rjwJqI4l /* Computed Parameter: rtCP_HoughTransform_FIRSTRHO_RT
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

/* Forward declaration for local functions */
static real_T LaneDetection_rt_powd_snf(real_T u0, real_T u1, LaneDetection_DW_f
  *localDW);
static real_T LaneDetection_rt_powd_snf(real_T u0, real_T u1, LaneDetection_DW_f
  *localDW)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    localDW->d0 = fabs(u0);
    localDW->d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (localDW->d0 == 1.0) {
        y = 1.0;
      } else if (localDW->d0 > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (localDW->d1 == 0.0) {
      y = 1.0;
    } else if (localDW->d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Start for referenced model: 'LaneDetection' */
void LaneDetection_Start(LaneDetection_DW_f *localDW)
{
  int32_T nonZeroIdx;

  /* Start for S-Function (svipedge): '<Root>/Edge Detection' */
  localDW->EdgeDetection_MEAN_FACTOR_DW = 125283;
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
void LaneDetection(const uint8_T rtu_I[76800], const real_T
                   rtu_SupportLeftLineVector[2], int32_T rty_TwoPoints[20],
                   int32_T rty_TwoPoints_DIMS1[2], real_T rty_Slope[5], int32_T
                   rty_Slope_DIMS1[2], uint8_T rty_LineImage[17141], boolean_T
                   rty_Edge[17141], real_T *rty_Angle, int32_T
                   rty_LeftLaneTwoPts[4], int32_T rty_LeftLaneTwoPts_DIMS1[2],
                   LaneDetection_DW_f *localDW)
{
  boolean_T done;
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
  int32_T rtb_NearestVector_idx_0;

  /* Selector: '<Root>/ROI_Tracking' incorporates:
   *  Constant: '<Root>/ROI_X'
   *  Constant: '<Root>/ROI_Y'
   */
  for (imgCol = 0; imgCol < 281; imgCol++) {
    for (rtb_NearestVector_idx_0 = 0; rtb_NearestVector_idx_0 < 61;
         rtb_NearestVector_idx_0++) {
      localDW->ROI_Tracking[rtb_NearestVector_idx_0 + 61 * imgCol] = rtu_I
        [(((int32_T)rtCP_ROI_X_Value[imgCol] - 1) * 240 + (int32_T)
          rtCP_ROI_Y_Value[rtb_NearestVector_idx_0]) - 1];
    }
  }

  /* End of Selector: '<Root>/ROI_Tracking' */

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (imgCol = 0; imgCol < 279; imgCol++) {
    for (imgRow = 0; imgRow < 59; imgRow++) {
      accumOne = 0;
      accumTwo = 0;
      rtb_NearestVector_idx_0 = ((imgCol + 1) * 61 + imgRow) + 1;
      for (m = 0; m < 6; m++) {
        accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
          localDW->ROI_Tracking[rtb_NearestVector_idx_0 +
          localDW->EdgeDetection_VO_DW[m]], 23U);
        accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
          localDW->ROI_Tracking[rtb_NearestVector_idx_0 +
          localDW->EdgeDetection_HO_DW[m]], 23U);
      }

      localDW->EdgeDetection_GV_SQUARED_DW[rtb_NearestVector_idx_0] =
        mul_s32_loSR(accumOne, accumOne, 8U);
      localDW->EdgeDetection_GH_SQUARED_DW[rtb_NearestVector_idx_0] =
        mul_s32_loSR(accumTwo, accumTwo, 8U);
    }
  }

  for (imgCol = 0; imgCol < 279; imgCol++) {
    accumOne = 0;
    accumTwo = 0;
    accumThree = 0;
    accumFour = 0;
    imgRow = (imgCol + 1) * 61;
    rtb_NearestVector_idx_0 = (imgCol + 1) * 61 + 60;
    for (m = 0; m < 6; m++) {
      accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
        localDW->ROI_Tracking[imgRow + localDW->EdgeDetection_HOU_DW[m]], 23U);
      accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
        localDW->ROI_Tracking[rtb_NearestVector_idx_0 +
        localDW->EdgeDetection_HOD_DW[m]], 23U);
      accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
        localDW->ROI_Tracking[imgRow + localDW->EdgeDetection_VOU_DW[m]], 23U);
      accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
        localDW->ROI_Tracking[rtb_NearestVector_idx_0 +
        localDW->EdgeDetection_VOD_DW[m]], 23U);
    }

    localDW->EdgeDetection_GV_SQUARED_DW[imgRow] = mul_s32_loSR(accumThree,
      accumThree, 8U);
    localDW->EdgeDetection_GH_SQUARED_DW[imgRow] = mul_s32_loSR(accumOne,
      accumOne, 8U);
    localDW->EdgeDetection_GV_SQUARED_DW[rtb_NearestVector_idx_0] = mul_s32_loSR
      (accumFour, accumFour, 8U);
    localDW->EdgeDetection_GH_SQUARED_DW[rtb_NearestVector_idx_0] = mul_s32_loSR
      (accumTwo, accumTwo, 8U);
  }

  for (imgRow = 0; imgRow < 59; imgRow++) {
    accumOne = 0;
    accumTwo = 0;
    accumThree = 0;
    accumFour = 0;
    imgCol = imgRow + 17081;
    for (m = 0; m < 6; m++) {
      accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
        localDW->ROI_Tracking[(imgRow + localDW->EdgeDetection_VOL_DW[m]) + 1],
        23U);
      accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
        localDW->ROI_Tracking[imgCol + localDW->EdgeDetection_VOR_DW[m]], 23U);
      accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
        localDW->ROI_Tracking[(imgRow + localDW->EdgeDetection_HOL_DW[m]) + 1],
        23U);
      accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
        localDW->ROI_Tracking[imgCol + localDW->EdgeDetection_HOR_DW[m]], 23U);
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
    accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
      localDW->ROI_Tracking[localDW->EdgeDetection_VOUL_DW[m]], 23U);
    accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
      localDW->ROI_Tracking[localDW->EdgeDetection_HOUL_DW[m]], 23U);
    accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
      localDW->ROI_Tracking[60 + localDW->EdgeDetection_VOLL_DW[m]], 23U);
    accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
      localDW->ROI_Tracking[60 + localDW->EdgeDetection_HOLL_DW[m]], 23U);
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
    accumOne += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
      localDW->ROI_Tracking[17080 + localDW->EdgeDetection_VOUR_DW[m]], 23U);
    accumTwo += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
      localDW->ROI_Tracking[17080 + localDW->EdgeDetection_HOUR_DW[m]], 23U);
    accumThree += mul_ssu32_loSR(rtCP_EdgeDetection_VC_RTP[m],
      localDW->ROI_Tracking[17140 + localDW->EdgeDetection_VOLR_DW[m]], 23U);
    accumFour += mul_ssu32_loSR(rtCP_EdgeDetection_HC_RTP[m],
      localDW->ROI_Tracking[17140 + localDW->EdgeDetection_HOLR_DW[m]], 23U);
  }

  localDW->EdgeDetection_GV_SQUARED_DW[17080] = mul_s32_loSR(accumOne, accumOne,
    8U);
  localDW->EdgeDetection_GH_SQUARED_DW[17080] = mul_s32_loSR(accumTwo, accumTwo,
    8U);
  localDW->EdgeDetection_GV_SQUARED_DW[17140] = mul_s32_loSR(accumThree,
    accumThree, 8U);
  localDW->EdgeDetection_GH_SQUARED_DW[17140] = mul_s32_loSR(accumFour,
    accumFour, 8U);
  accumTwo = 0;
  for (m = 0; m < 17141; m++) {
    localDW->EdgeDetection_GRAD_SUM_DW[m] = localDW->
      EdgeDetection_GV_SQUARED_DW[m];
    localDW->EdgeDetection_GRAD_SUM_DW[m] +=
      localDW->EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += mul_s32_loSR(localDW->EdgeDetection_GRAD_SUM_DW[m],
      localDW->EdgeDetection_MEAN_FACTOR_DW, 31U);
  }

  accumOne = accumTwo << 2;
  for (imgCol = 0; imgCol < 281; imgCol++) {
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

      if (imgCol != 280) {
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
                &rtCP_HoughTransform_FIRSTRHO_RT, 61, 281, 575, 13);

  /* S-Function (svipfindlocalmax): '<S1>/Find Local Maxima' */
  accumOne = 0;
  done = false;
  for (m = 0; m < 13800; m++) {
    localDW->FindLocalMaxima_TEMP_IN_DWORKS[m] = localDW->HoughTransform_o1[m];
  }

  memset(&localDW->FindLocalMaxima[0], 0, 10U * sizeof(real_T));
  while (!done) {
    accumTwo = 0;
    localDW->NearestSimilarity = localDW->FindLocalMaxima_TEMP_IN_DWORKS[0];
    for (m = 0; m < 13800; m++) {
      if (localDW->FindLocalMaxima_TEMP_IN_DWORKS[m] >
          localDW->NearestSimilarity) {
        accumTwo = m;
        localDW->NearestSimilarity = localDW->FindLocalMaxima_TEMP_IN_DWORKS[m];
      }
    }

    imgCol = accumTwo % 575;
    m = accumTwo / 575;
    if (localDW->FindLocalMaxima_TEMP_IN_DWORKS[accumTwo] >= 10.0) {
      localDW->FindLocalMaxima[accumOne] = 1.0 + (real_T)m;
      localDW->FindLocalMaxima[5U + accumOne] = 1 + imgCol;
      accumOne++;
      if (accumOne == 5) {
        done = true;
      }

      accumTwo = imgCol - 2;
      if (!(accumTwo > 0)) {
        accumTwo = 0;
      }

      imgCol += 2;
      if (!(imgCol < 574)) {
        imgCol = 574;
      }

      imgRow = m - 3;
      rtb_NearestVector_idx_0 = m + 3;
      if (!((imgRow < 0) || (rtb_NearestVector_idx_0 > 23))) {
        while (imgRow <= rtb_NearestVector_idx_0) {
          accumThree = imgRow * 575;
          for (m = accumTwo; m <= imgCol; m++) {
            localDW->FindLocalMaxima_TEMP_IN_DWORKS[m + accumThree] = 0.0;
          }

          imgRow++;
        }
      } else {
        if (imgRow < 0) {
          for (accumFour = imgRow; accumFour <= rtb_NearestVector_idx_0;
               accumFour++) {
            if (accumFour < 0) {
              accumThree = (accumFour + 24) * 575 + 574;
              for (m = accumTwo; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[accumThree - m] = 0.0;
              }
            } else {
              accumThree = accumFour * 575;
              for (m = accumTwo; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[m + accumThree] = 0.0;
              }
            }
          }
        }

        if (rtb_NearestVector_idx_0 > 23) {
          for (accumFour = imgRow; accumFour <= rtb_NearestVector_idx_0;
               accumFour++) {
            if (accumFour > 23) {
              accumThree = (accumFour - 24) * 575 + 574;
              for (m = accumTwo; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[accumThree - m] = 0.0;
              }
            } else {
              accumThree = accumFour * 575;
              for (m = accumTwo; m <= imgCol; m++) {
                localDW->FindLocalMaxima_TEMP_IN_DWORKS[m + accumThree] = 0.0;
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

  m = localDW->FindLocalMaxima_DIMS1[0];
  for (imgCol = 0; imgCol < m; imgCol++) {
    localDW->Selector_g[imgCol] = localDW->rtb_FindLocalMaxima_data[imgCol];
  }

  /* End of Selector: '<S1>/Selector' */

  /* Selector: '<S1>/Selector1' */
  localDW->Selector1_DIMS1[0] = 1;
  localDW->Selector1_DIMS1[1] = localDW->Selector_DIMS1[0] *
    localDW->Selector_DIMS1[1];
  imgRow = localDW->Selector_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    m = localDW->Selector_DIMS1[0];
    for (rtb_NearestVector_idx_0 = 0; rtb_NearestVector_idx_0 < m;
         rtb_NearestVector_idx_0++) {
      localDW->rtb_Selector_g_data[rtb_NearestVector_idx_0 +
        localDW->Selector_DIMS1[0] * imgCol] = (int32_T)localDW->
        Selector_g[localDW->Selector_DIMS1[0] * imgCol + rtb_NearestVector_idx_0]
        - 1;
    }
  }

  imgRow = localDW->Selector_DIMS1[0] * localDW->Selector_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Product_e[localDW->Selector1_DIMS1[0] * imgCol] =
      localDW->HoughTransform_o2[localDW->rtb_Selector_g_data[imgCol]];
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

  m = localDW->FindLocalMaxima_DIMS1[0];
  for (imgCol = 0; imgCol < m; imgCol++) {
    localDW->Selector_g[imgCol] = localDW->rtb_FindLocalMaxima_data[imgCol];
  }

  /* End of Selector: '<S1>/Selector2' */

  /* Selector: '<S1>/Selector5' */
  localDW->Selector5_DIMS1[0] = 1;
  localDW->Selector5_DIMS1[1] = localDW->Selector2_DIMS1[0] *
    localDW->Selector2_DIMS1[1];
  imgRow = localDW->Selector2_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    m = localDW->Selector2_DIMS1[0];
    for (rtb_NearestVector_idx_0 = 0; rtb_NearestVector_idx_0 < m;
         rtb_NearestVector_idx_0++) {
      localDW->rtb_Selector_g_data[rtb_NearestVector_idx_0 +
        localDW->Selector2_DIMS1[0] * imgCol] = (int32_T)localDW->
        Selector_g[localDW->Selector2_DIMS1[0] * imgCol +
        rtb_NearestVector_idx_0] - 1;
    }
  }

  imgRow = localDW->Selector2_DIMS1[0] * localDW->Selector2_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Subtract1[localDW->Selector5_DIMS1[0] * imgCol] =
      localDW->HoughTransform_o3[localDW->rtb_Selector_g_data[imgCol]];
  }

  /* End of Selector: '<S1>/Selector5' */

  /* S-Function (sviphoughlines): '<S1>/Hough Lines' */
  rty_TwoPoints_DIMS1[1] = 4;
  rty_TwoPoints_DIMS1[0] = localDW->Selector1_DIMS1[0] *
    localDW->Selector1_DIMS1[1];
  for (m = 0; m < localDW->Selector1_DIMS1[1]; m++) {
    accumTwo = 0;
    localDW->NearestSimilarity = (localDW->Subtract1[m] + 2.2204460492503131E-16)
      / (cos(localDW->Product_e[m]) + 2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    localDW->tmpRound = floor(localDW->NearestSimilarity + 0.5);
    if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 280.0)) {
      localDW->rty_TwoPoints_data[0U] = 0;
      if (localDW->tmpRound >= 0.5) {
        localDW->rty_TwoPoints_data[1U] = (int32_T)floor(localDW->tmpRound + 0.5);
      } else {
        localDW->rty_TwoPoints_data[1U] = 0;
      }

      accumTwo = 1;
    }

    localDW->y2 = (localDW->Subtract1[m] + 2.2204460492503131E-16) / (sin
      (localDW->Product_e[m]) + 2.2204460492503131E-16);

    /* part-2: left vertical axis */
    localDW->tmpRound = floor(localDW->y2 + 0.5);
    if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 60.0)) {
      if (localDW->tmpRound >= 0.5) {
        localDW->rty_TwoPoints_data[accumTwo << 1] = (int32_T)floor
          (localDW->tmpRound + 0.5);
      } else {
        localDW->rty_TwoPoints_data[accumTwo << 1] = 0;
      }

      localDW->rty_TwoPoints_data[1 + (accumTwo << 1)] = 0;
      accumTwo++;
    }

    /* part-3: Right vertical axis */
    if (accumTwo < 2) {
      localDW->tmpRound = floor((localDW->NearestSimilarity - 280.0) *
        (localDW->y2 / localDW->NearestSimilarity) + 0.5);
      if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 60.0)) {
        if (localDW->tmpRound >= 0.5) {
          localDW->rty_TwoPoints_data[accumTwo << 1] = (int32_T)floor
            (localDW->tmpRound + 0.5);
        } else {
          localDW->rty_TwoPoints_data[accumTwo << 1] = 0;
        }

        localDW->rty_TwoPoints_data[1 + (accumTwo << 1)] = 280;
        accumTwo++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (accumTwo < 2) {
      localDW->tmpRound = floor((localDW->NearestSimilarity -
        localDW->NearestSimilarity / localDW->y2 * 60.0) + 0.5);
      if ((localDW->tmpRound >= 0.0) && (localDW->tmpRound <= 280.0)) {
        localDW->rty_TwoPoints_data[accumTwo << 1] = 60;
        if (localDW->tmpRound >= 0.5) {
          localDW->rty_TwoPoints_data[1 + (accumTwo << 1)] = (int32_T)floor
            (localDW->tmpRound + 0.5);
        } else {
          localDW->rty_TwoPoints_data[1 + (accumTwo << 1)] = 0;
        }

        accumTwo++;
      }
    }

    if (accumTwo < 2) {
      localDW->rty_TwoPoints_data[0U] = -1;
      localDW->rty_TwoPoints_data[1U] = -1;
      localDW->rty_TwoPoints_data[2U] = -1;
      localDW->rty_TwoPoints_data[3U] = -1;
    }

    rty_TwoPoints[m] = localDW->rty_TwoPoints_data[1] + 1;
    rty_TwoPoints[m + localDW->Selector1_DIMS1[1]] = localDW->
      rty_TwoPoints_data[0] + 1;
    if (localDW->rty_TwoPoints_data[3] > 2147483646) {
      rty_TwoPoints[m + (localDW->Selector1_DIMS1[1] << 1)] = MAX_int32_T;
    } else {
      rty_TwoPoints[m + (localDW->Selector1_DIMS1[1] << 1)] =
        localDW->rty_TwoPoints_data[3] + 1;
    }

    if (localDW->rty_TwoPoints_data[2] > 2147483646) {
      rty_TwoPoints[m + 3 * localDW->Selector1_DIMS1[1]] = MAX_int32_T;
    } else {
      rty_TwoPoints[m + 3 * localDW->Selector1_DIMS1[1]] =
        localDW->rty_TwoPoints_data[2] + 1;
    }
  }

  /* End of S-Function (sviphoughlines): '<S1>/Hough Lines' */

  /* S-Function (svipdrawshapes): '<Root>/Draw Shapes' */
  /* Compute output for unity line width
   */
  accumTwo = 0;
  accumOne = 0;
  if (rty_TwoPoints_DIMS1[1] > 1) {
    accumOne = rty_TwoPoints_DIMS1[1] >> 1;
    done = (accumOne << 1 == rty_TwoPoints_DIMS1[1]);
    accumTwo = rty_TwoPoints_DIMS1[0];
  } else {
    if (rty_TwoPoints_DIMS1[1] == 1) {
      accumOne = rty_TwoPoints_DIMS1[0] >> 1;
      done = (accumOne << 1 == rty_TwoPoints_DIMS1[0]);
      accumTwo = 1;
    }
  }

  /* Copy the image from input to output. */
  memcpy(&rty_LineImage[0], &localDW->ROI_Tracking[0], 17141U * sizeof(uint8_T));
  if (done && (accumTwo > 0)) {
    /* Update view port. */
    for (imgCol = 0; imgCol < accumTwo; imgCol++) {
      imgRow = 0;
      for (rtb_NearestVector_idx_0 = 0; rtb_NearestVector_idx_0 < accumOne - 1;
           rtb_NearestVector_idx_0++) {
        line_idx_0 = rty_TwoPoints[((imgRow * accumTwo << 1) + imgCol) +
          accumTwo] - 1;
        line_idx_1_0 = rty_TwoPoints[(imgRow * accumTwo << 1) + imgCol] - 1;
        imgRow++;
        line_idx_2_0 = rty_TwoPoints[((imgRow * accumTwo << 1) + imgCol) +
          accumTwo] - 1;
        line_idx_3_0 = rty_TwoPoints[(imgRow * accumTwo << 1) + imgCol] - 1;
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
              if (line_idx_1 > 280) {
                localDW->fromIdx |= 2U;
              }
            }

            if (line_idx_3 < 0) {
              localDW->toIdx |= 1U;
            } else {
              if (line_idx_3 > 280) {
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
              accumThree = line_idx_3 - line_idx_1;
              if ((m > 1073741824) || (m < -1073741824) || ((accumThree >
                    1073741824) || (accumThree < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b3 = true;
              } else if ((localDW->fromIdx & 4U) != 0U) {
                /* Violated RMin. */
                localDW->numEdge = -accumFour * accumThree;
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
                localDW->numEdge = (60 - accumFour) * accumThree;
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
                } else if (((localDW->numEdge >= 0) && (accumThree >= 0)) ||
                           ((localDW->numEdge < 0) && (accumThree < 0))) {
                  accumFour += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                } else {
                  accumFour -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                }

                line_idx_1 = 0;
                b3 = true;
              } else {
                /* Violated CMax. */
                localDW->numEdge = (280 - line_idx_1) * m;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (accumThree >= 0)) ||
                           ((localDW->numEdge < 0) && (accumThree < 0))) {
                  accumFour += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                } else {
                  accumFour -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                }

                line_idx_1 = 280;
                b3 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (b4) {
                line_idx_2 = line_idx_2_0;
                line_idx_3 = line_idx_3_0;
              }

              m = line_idx_2 - accumFour;
              accumThree = line_idx_3 - line_idx_1;
              if ((m > 1073741824) || (m < -1073741824) || ((accumThree >
                    1073741824) || (accumThree < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b4 = true;
              } else if ((localDW->toIdx & 4U) != 0U) {
                /* Violated RMin. */
                localDW->numEdge = -line_idx_2 * accumThree;
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
                localDW->numEdge = (60 - line_idx_2) * accumThree;
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
                } else if (((localDW->numEdge >= 0) && (accumThree >= 0)) ||
                           ((localDW->numEdge < 0) && (accumThree < 0))) {
                  line_idx_2 += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                }

                line_idx_3 = 0;
                b4 = true;
              } else {
                /* Violated CMax. */
                localDW->numEdge = (280 - line_idx_3) * m;
                if ((localDW->numEdge > 1073741824) || (localDW->numEdge <
                     -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((localDW->numEdge >= 0) && (accumThree >= 0)) ||
                           ((localDW->numEdge < 0) && (accumThree < 0))) {
                  line_idx_2 += (div_nde_s32_floor(localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_nde_s32_floor(-localDW->numEdge << 1,
                    accumThree) + 1) >> 1;
                }

                line_idx_3 = 280;
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
              accumThree = accumFour;
              accumFour = line_idx_1;
              line_idx_1 = accumThree;
              accumThree = line_idx_2;
              line_idx_2 = line_idx_3;
              line_idx_3 = accumThree;
            }

            if (accumFour > line_idx_2) {
              accumThree = accumFour;
              accumFour = line_idx_2;
              line_idx_2 = accumThree;
              accumThree = line_idx_1;
              line_idx_1 = line_idx_3;
              line_idx_3 = accumThree;
            }

            accumThree = line_idx_2 - accumFour;
            if (line_idx_1 <= line_idx_3) {
              line_idx_0 = 1;
              line_idx_3 -= line_idx_1;
            } else {
              line_idx_0 = -1;
              line_idx_3 = line_idx_1 - line_idx_3;
            }

            line_idx_1_0 = -((accumThree + 1) >> 1);
            line_idx_1 = accumFour * m + line_idx_1 * localDW->numEdge;
            line_idx_0 = line_idx_0 * localDW->numEdge + m;
            done = (accumFour <= line_idx_2);
            while (done) {
              rty_LineImage[line_idx_1] = MAX_uint8_T;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next pixel location. */
              line_idx_1_0 += line_idx_3;
              if (line_idx_1_0 >= 0) {
                line_idx_1_0 -= accumThree;
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

  /* MATLAB Function: '<S1>/TwoPoints2Vector' */
  /* MATLAB Function 'Find Line/TwoPoints2Vector': '<S5>:1' */
  /* '<S5>:1:2' Vector = int32([ TwoPts(:,1)-TwoPts(:,3) TwoPts(:,2)-TwoPts(:,4)]); */
  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    m = rty_TwoPoints[imgCol];
    rtb_NearestVector_idx_0 = rty_TwoPoints[(rty_TwoPoints_DIMS1[0] << 1) +
      imgCol];
    if ((m >= 0) && (rtb_NearestVector_idx_0 < m - MAX_int32_T)) {
      localDW->reshapes[0].f1.data[imgCol] = MAX_int32_T;
    } else if ((m < 0) && (rtb_NearestVector_idx_0 > m - MIN_int32_T)) {
      localDW->reshapes[0].f1.data[imgCol] = MIN_int32_T;
    } else {
      localDW->reshapes[0].f1.data[imgCol] = m - rtb_NearestVector_idx_0;
    }
  }

  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    m = rty_TwoPoints[imgCol + rty_TwoPoints_DIMS1[0]];
    rtb_NearestVector_idx_0 = rty_TwoPoints[rty_TwoPoints_DIMS1[0] * 3 + imgCol];
    if ((m >= 0) && (rtb_NearestVector_idx_0 < m - MAX_int32_T)) {
      localDW->reshapes[1].f1.data[imgCol] = MAX_int32_T;
    } else if ((m < 0) && (rtb_NearestVector_idx_0 > m - MIN_int32_T)) {
      localDW->reshapes[1].f1.data[imgCol] = MIN_int32_T;
    } else {
      localDW->reshapes[1].f1.data[imgCol] = m - rtb_NearestVector_idx_0;
    }
  }

  localDW->SFunction_DIMS2_g[0] = rty_TwoPoints_DIMS1[0];
  localDW->SFunction_DIMS2_g[1] = 2;
  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Vector_m[imgCol] = localDW->reshapes[0].f1.data[imgCol];
  }

  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Vector_m[imgCol + rty_TwoPoints_DIMS1[0]] = localDW->reshapes[1].
      f1.data[imgCol];
  }

  /* End of MATLAB Function: '<S1>/TwoPoints2Vector' */

  /* MATLAB Function: '<S2>/Find Line Similarity with Support Line' */
  /* MATLAB Function 'Find Nearest Support Line/Find Line Similarity with Support Line': '<S6>:1' */
  /* '<S6>:1:2' [m,n] = size(LineVectors); */
  /* '<S6>:1:3' LineVectors = double(LineVectors); */
  /* '<S6>:1:5' Similaritys = double(zeros(m,1)); */
  localDW->SFunction_DIMS2 = localDW->SFunction_DIMS2_g[0];
  imgRow = localDW->SFunction_DIMS2_g[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->FindLocalMaxima[imgCol] = 0.0;
  }

  /* SupportLineVector = double([5 5]); */
  /* '<S6>:1:7' for i=1:m */
  for (m = 0; m < localDW->SFunction_DIMS2_g[0]; m++) {
    /* '<S6>:1:8' Similaritys(i) = (LineVectors(i,1)*SupportLineVector(1) + LineVectors(i,2)*SupportLineVector(2)) / (( sqrt(sum(LineVectors(i).^2)))*sqrt(sum(SupportLineVector.^2))); */
    localDW->FindLocalMaxima[m] = ((real_T)localDW->Vector_m[m +
      localDW->SFunction_DIMS2_g[0]] * rtu_SupportLeftLineVector[1] + (real_T)
      localDW->Vector_m[m] * rtu_SupportLeftLineVector[0]) / (sqrt
      (rtu_SupportLeftLineVector[0] * rtu_SupportLeftLineVector[0] +
       rtu_SupportLeftLineVector[1] * rtu_SupportLeftLineVector[1]) * sqrt
      ((real_T)localDW->Vector_m[m] * (real_T)localDW->Vector_m[m]));
  }

  /* End of MATLAB Function: '<S2>/Find Line Similarity with Support Line' */

  /* MATLAB Function: '<S2>/Find Nearest Line' */
  /* MATLAB Function 'Find Nearest Support Line/Find Nearest Line': '<S7>:1' */
  /* '<S7>:1:2' Similaritys = abs(Similaritys); */
  for (accumTwo = 0; accumTwo + 1 <= localDW->SFunction_DIMS2; accumTwo++) {
    localDW->Similaritys_data[accumTwo] = fabs(localDW->FindLocalMaxima[accumTwo]);
  }

  /* '<S7>:1:3' [m,~]=size(Vectors); */
  /* '<S7>:1:3' ~ */
  /* '<S7>:1:4' i=double(1); */
  m = 0;

  /* '<S7>:1:5' if m ~= 0 */
  if (localDW->SFunction_DIMS2_g[0] != 0) {
    /* '<S7>:1:6' NearestSimilarity = Similaritys(1); */
    localDW->NearestSimilarity = localDW->Similaritys_data[0];

    /* '<S7>:1:7' NearestVector = double(Vectors(1,1:2)); */
    rtb_NearestVector_idx_0 = localDW->Vector_m[0];
    accumOne = localDW->Vector_m[localDW->SFunction_DIMS2_g[0]];

    /* '<S7>:1:9' for i = 1:m */
    for (accumTwo = 0; accumTwo < localDW->SFunction_DIMS2_g[0]; accumTwo++) {
      m = accumTwo;

      /* '<S7>:1:10' if Similaritys(i) < NearestSimilarity */
      if (localDW->Similaritys_data[accumTwo] < localDW->NearestSimilarity) {
        /* '<S7>:1:11' NearestSimilarity = Similaritys(i); */
        localDW->NearestSimilarity = localDW->Similaritys_data[accumTwo];

        /* '<S7>:1:12' NearestVector = double(Vectors(i,1:2)); */
        rtb_NearestVector_idx_0 = localDW->Vector_m[accumTwo];
        accumOne = localDW->Vector_m[accumTwo + localDW->SFunction_DIMS2_g[0]];
      }
    }
  } else {
    /* '<S7>:1:15' else */
    /* '<S7>:1:16' NearestVector = double([0 0]); */
    rtb_NearestVector_idx_0 = 0;
    accumOne = 0;
  }

  /* Selector: '<S2>/Selector' incorporates:
   *  MATLAB Function: '<S2>/Find Nearest Line'
   */
  rty_LeftLaneTwoPts_DIMS1[0] = 1;
  rty_LeftLaneTwoPts_DIMS1[1] = rty_TwoPoints_DIMS1[1];
  imgRow = rty_TwoPoints_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rty_TwoPoints_data[imgCol] = rty_TwoPoints[rty_TwoPoints_DIMS1[0] *
      imgCol + m];
  }

  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    rty_LeftLaneTwoPts[rty_LeftLaneTwoPts_DIMS1[0] * imgCol] =
      localDW->rty_TwoPoints_data[imgCol];
  }

  /* End of Selector: '<S2>/Selector' */

  /* Selector: '<S3>/Selector' */
  localDW->Selector_DIMS1_o[0] = rty_TwoPoints_DIMS1[0];
  localDW->Selector_DIMS1_o[1] = 1;
  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_g_data[imgCol] = rty_TwoPoints[imgCol];
  }

  m = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < m; imgCol++) {
    localDW->Selector_p[imgCol] = localDW->rtb_Selector_g_data[imgCol];
  }

  /* End of Selector: '<S3>/Selector' */

  /* Selector: '<S3>/Selector3' */
  localDW->Selector3_DIMS1[0] = rty_TwoPoints_DIMS1[0];
  localDW->Selector3_DIMS1[1] = 1;
  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_g_data[imgCol] = rty_TwoPoints[(rty_TwoPoints_DIMS1[0]
      << 1) + imgCol];
  }

  m = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < m; imgCol++) {
    localDW->Selector3[imgCol] = localDW->rtb_Selector_g_data[imgCol];
  }

  /* End of Selector: '<S3>/Selector3' */

  /* Sum: '<S3>/Subtract' */
  imgRow = localDW->Selector_DIMS1_o[0] * localDW->Selector_DIMS1_o[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Selector_p[imgCol] -= localDW->Selector3[imgCol];
  }

  /* End of Sum: '<S3>/Subtract' */

  /* Selector: '<S3>/Selector2' */
  localDW->Selector2_DIMS1_g[0] = rty_TwoPoints_DIMS1[0];
  localDW->Selector2_DIMS1_g[1] = 1;
  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_g_data[imgCol] = rty_TwoPoints[imgCol +
      rty_TwoPoints_DIMS1[0]];
  }

  m = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < m; imgCol++) {
    localDW->Selector3[imgCol] = localDW->rtb_Selector_g_data[imgCol];
  }

  /* End of Selector: '<S3>/Selector2' */

  /* Product: '<S3>/Product1' */
  imgRow = localDW->Selector2_DIMS1_g[0] * localDW->Selector2_DIMS1_g[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Subtract1[imgCol] = -(real_T)localDW->Selector3[imgCol];
  }

  /* End of Product: '<S3>/Product1' */

  /* Selector: '<S3>/Selector4' */
  localDW->Selector4_DIMS1[0] = rty_TwoPoints_DIMS1[0];
  localDW->Selector4_DIMS1[1] = 1;
  imgRow = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->rtb_Selector_g_data[imgCol] = rty_TwoPoints[rty_TwoPoints_DIMS1[0] *
      3 + imgCol];
  }

  m = rty_TwoPoints_DIMS1[0];
  for (imgCol = 0; imgCol < m; imgCol++) {
    localDW->Selector3[imgCol] = localDW->rtb_Selector_g_data[imgCol];
  }

  /* End of Selector: '<S3>/Selector4' */

  /* Product: '<S3>/Product' */
  imgRow = localDW->Selector4_DIMS1[0] * localDW->Selector4_DIMS1[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Product_e[imgCol] = -(real_T)localDW->Selector3[imgCol];
  }

  /* End of Product: '<S3>/Product' */

  /* Sum: '<S3>/Subtract1' */
  imgRow = localDW->Selector2_DIMS1_g[0] * localDW->Selector2_DIMS1_g[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    localDW->Subtract1[imgCol] -= localDW->Product_e[imgCol];
  }

  /* End of Sum: '<S3>/Subtract1' */

  /* Product: '<S3>/Divide' */
  rty_Slope_DIMS1[0] = localDW->Selector_DIMS1_o[0];
  rty_Slope_DIMS1[1] = localDW->Selector_DIMS1_o[1];
  imgRow = localDW->Selector2_DIMS1_g[0] * localDW->Selector2_DIMS1_g[1];
  for (imgCol = 0; imgCol < imgRow; imgCol++) {
    rty_Slope[imgCol] = localDW->Subtract1[imgCol] / (real_T)localDW->
      Selector_p[imgCol];
  }

  /* End of Product: '<S3>/Divide' */

  /* Product: '<S4>/Divide' incorporates:
   *  DotProduct: '<S4>/Dot Product'
   *  Math: '<S4>/Math Function'
   *  Sqrt: '<S4>/Sqrt1'
   *  Sum: '<S4>/Sum of Elements'
   */
  localDW->NearestSimilarity = (real_T)rtb_NearestVector_idx_0 / sqrt
    (LaneDetection_rt_powd_snf((real_T)rtb_NearestVector_idx_0, 2.0, localDW) +
     LaneDetection_rt_powd_snf((real_T)accumOne, 2.0, localDW));

  /* Trigonometry: '<S4>/Trigonometric Function' */
  if (localDW->NearestSimilarity > 1.0) {
    localDW->NearestSimilarity = 1.0;
  } else {
    if (localDW->NearestSimilarity < -1.0) {
      localDW->NearestSimilarity = -1.0;
    }
  }

  *rty_Angle = acos(localDW->NearestSimilarity);

  /* End of Trigonometry: '<S4>/Trigonometric Function' */
}

/* Model initialize function */
void LaneDetection_initialize(const char_T **rt_errorStatus,
  LaneDetection_RT_MODEL *const LaneDetectionrtM, LaneDetection_DW_f *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(LaneDetectionrtM, rt_errorStatus);

  /* states (dwork) */
  {
    localDW->HoughTransform_o2[0] = -1.5707963267948966;
    localDW->HoughTransform_o2[1] = -1.4398966328953218;
    localDW->HoughTransform_o2[2] = -1.3089969389957472;
    localDW->HoughTransform_o2[3] = -1.1780972450961724;
    localDW->HoughTransform_o2[4] = -1.0471975511965976;
    localDW->HoughTransform_o2[5] = -0.91629785729702307;
    localDW->HoughTransform_o2[6] = -0.78539816339744828;
    localDW->HoughTransform_o2[7] = -0.6544984694978736;
    localDW->HoughTransform_o2[8] = -0.52359877559829882;
    localDW->HoughTransform_o2[9] = -0.39269908169872414;
    localDW->HoughTransform_o2[10] = -0.26179938779914941;
    localDW->HoughTransform_o2[11] = -0.1308996938995747;
    localDW->HoughTransform_o2[13] = 0.1308996938995747;
    localDW->HoughTransform_o2[14] = 0.26179938779914941;
    localDW->HoughTransform_o2[15] = 0.39269908169872414;
    localDW->HoughTransform_o2[16] = 0.52359877559829882;
    localDW->HoughTransform_o2[17] = 0.6544984694978736;
    localDW->HoughTransform_o2[18] = 0.78539816339744828;
    localDW->HoughTransform_o2[19] = 0.91629785729702307;
    localDW->HoughTransform_o2[20] = 1.0471975511965976;
    localDW->HoughTransform_o2[21] = 1.1780972450961724;
    localDW->HoughTransform_o2[22] = 1.3089969389957472;
    localDW->HoughTransform_o2[23] = 1.4398966328953218;
    localDW->HoughTransform_o3[0] = -287.0;
    localDW->HoughTransform_o3[1] = -286.0;
    localDW->HoughTransform_o3[2] = -285.0;
    localDW->HoughTransform_o3[3] = -284.0;
    localDW->HoughTransform_o3[4] = -283.0;
    localDW->HoughTransform_o3[5] = -282.0;
    localDW->HoughTransform_o3[6] = -281.0;
    localDW->HoughTransform_o3[7] = -280.0;
    localDW->HoughTransform_o3[8] = -279.0;
    localDW->HoughTransform_o3[9] = -278.0;
    localDW->HoughTransform_o3[10] = -277.0;
    localDW->HoughTransform_o3[11] = -276.0;
    localDW->HoughTransform_o3[12] = -275.0;
    localDW->HoughTransform_o3[13] = -274.0;
    localDW->HoughTransform_o3[14] = -273.0;
    localDW->HoughTransform_o3[15] = -272.0;
    localDW->HoughTransform_o3[16] = -271.0;
    localDW->HoughTransform_o3[17] = -270.0;
    localDW->HoughTransform_o3[18] = -269.0;
    localDW->HoughTransform_o3[19] = -268.0;
    localDW->HoughTransform_o3[20] = -267.0;
    localDW->HoughTransform_o3[21] = -266.0;
    localDW->HoughTransform_o3[22] = -265.0;
    localDW->HoughTransform_o3[23] = -264.0;
    localDW->HoughTransform_o3[24] = -263.0;
    localDW->HoughTransform_o3[25] = -262.0;
    localDW->HoughTransform_o3[26] = -261.0;
    localDW->HoughTransform_o3[27] = -260.0;
    localDW->HoughTransform_o3[28] = -259.0;
    localDW->HoughTransform_o3[29] = -258.0;
    localDW->HoughTransform_o3[30] = -257.0;
    localDW->HoughTransform_o3[31] = -256.0;
    localDW->HoughTransform_o3[32] = -255.0;
    localDW->HoughTransform_o3[33] = -254.0;
    localDW->HoughTransform_o3[34] = -253.0;
    localDW->HoughTransform_o3[35] = -252.0;
    localDW->HoughTransform_o3[36] = -251.0;
    localDW->HoughTransform_o3[37] = -250.0;
    localDW->HoughTransform_o3[38] = -249.0;
    localDW->HoughTransform_o3[39] = -248.0;
    localDW->HoughTransform_o3[40] = -247.0;
    localDW->HoughTransform_o3[41] = -246.0;
    localDW->HoughTransform_o3[42] = -245.0;
    localDW->HoughTransform_o3[43] = -244.0;
    localDW->HoughTransform_o3[44] = -243.0;
    localDW->HoughTransform_o3[45] = -242.0;
    localDW->HoughTransform_o3[46] = -241.0;
    localDW->HoughTransform_o3[47] = -240.0;
    localDW->HoughTransform_o3[48] = -239.0;
    localDW->HoughTransform_o3[49] = -238.0;
    localDW->HoughTransform_o3[50] = -237.0;
    localDW->HoughTransform_o3[51] = -236.0;
    localDW->HoughTransform_o3[52] = -235.0;
    localDW->HoughTransform_o3[53] = -234.0;
    localDW->HoughTransform_o3[54] = -233.0;
    localDW->HoughTransform_o3[55] = -232.0;
    localDW->HoughTransform_o3[56] = -231.0;
    localDW->HoughTransform_o3[57] = -230.0;
    localDW->HoughTransform_o3[58] = -229.0;
    localDW->HoughTransform_o3[59] = -228.0;
    localDW->HoughTransform_o3[60] = -227.0;
    localDW->HoughTransform_o3[61] = -226.0;
    localDW->HoughTransform_o3[62] = -225.0;
    localDW->HoughTransform_o3[63] = -224.0;
    localDW->HoughTransform_o3[64] = -223.0;
    localDW->HoughTransform_o3[65] = -222.0;
    localDW->HoughTransform_o3[66] = -221.0;
    localDW->HoughTransform_o3[67] = -220.0;
    localDW->HoughTransform_o3[68] = -219.0;
    localDW->HoughTransform_o3[69] = -218.0;
    localDW->HoughTransform_o3[70] = -217.0;
    localDW->HoughTransform_o3[71] = -216.0;
    localDW->HoughTransform_o3[72] = -215.0;
    localDW->HoughTransform_o3[73] = -214.0;
    localDW->HoughTransform_o3[74] = -213.0;
    localDW->HoughTransform_o3[75] = -212.0;
    localDW->HoughTransform_o3[76] = -211.0;
    localDW->HoughTransform_o3[77] = -210.0;
    localDW->HoughTransform_o3[78] = -209.0;
    localDW->HoughTransform_o3[79] = -208.0;
    localDW->HoughTransform_o3[80] = -207.0;
    localDW->HoughTransform_o3[81] = -206.0;
    localDW->HoughTransform_o3[82] = -205.0;
    localDW->HoughTransform_o3[83] = -204.0;
    localDW->HoughTransform_o3[84] = -203.0;
    localDW->HoughTransform_o3[85] = -202.0;
    localDW->HoughTransform_o3[86] = -201.0;
    localDW->HoughTransform_o3[87] = -200.0;
    localDW->HoughTransform_o3[88] = -199.0;
    localDW->HoughTransform_o3[89] = -198.0;
    localDW->HoughTransform_o3[90] = -197.0;
    localDW->HoughTransform_o3[91] = -196.0;
    localDW->HoughTransform_o3[92] = -195.0;
    localDW->HoughTransform_o3[93] = -194.0;
    localDW->HoughTransform_o3[94] = -193.0;
    localDW->HoughTransform_o3[95] = -192.0;
    localDW->HoughTransform_o3[96] = -191.0;
    localDW->HoughTransform_o3[97] = -190.0;
    localDW->HoughTransform_o3[98] = -189.0;
    localDW->HoughTransform_o3[99] = -188.0;
    localDW->HoughTransform_o3[100] = -187.0;
    localDW->HoughTransform_o3[101] = -186.0;
    localDW->HoughTransform_o3[102] = -185.0;
    localDW->HoughTransform_o3[103] = -184.0;
    localDW->HoughTransform_o3[104] = -183.0;
    localDW->HoughTransform_o3[105] = -182.0;
    localDW->HoughTransform_o3[106] = -181.0;
    localDW->HoughTransform_o3[107] = -180.0;
    localDW->HoughTransform_o3[108] = -179.0;
    localDW->HoughTransform_o3[109] = -178.0;
    localDW->HoughTransform_o3[110] = -177.0;
    localDW->HoughTransform_o3[111] = -176.0;
    localDW->HoughTransform_o3[112] = -175.0;
    localDW->HoughTransform_o3[113] = -174.0;
    localDW->HoughTransform_o3[114] = -173.0;
    localDW->HoughTransform_o3[115] = -172.0;
    localDW->HoughTransform_o3[116] = -171.0;
    localDW->HoughTransform_o3[117] = -170.0;
    localDW->HoughTransform_o3[118] = -169.0;
    localDW->HoughTransform_o3[119] = -168.0;
    localDW->HoughTransform_o3[120] = -167.0;
    localDW->HoughTransform_o3[121] = -166.0;
    localDW->HoughTransform_o3[122] = -165.0;
    localDW->HoughTransform_o3[123] = -164.0;
    localDW->HoughTransform_o3[124] = -163.0;
    localDW->HoughTransform_o3[125] = -162.0;
    localDW->HoughTransform_o3[126] = -161.0;
    localDW->HoughTransform_o3[127] = -160.0;
    localDW->HoughTransform_o3[128] = -159.0;
    localDW->HoughTransform_o3[129] = -158.0;
    localDW->HoughTransform_o3[130] = -157.0;
    localDW->HoughTransform_o3[131] = -156.0;
    localDW->HoughTransform_o3[132] = -155.0;
    localDW->HoughTransform_o3[133] = -154.0;
    localDW->HoughTransform_o3[134] = -153.0;
    localDW->HoughTransform_o3[135] = -152.0;
    localDW->HoughTransform_o3[136] = -151.0;
    localDW->HoughTransform_o3[137] = -150.0;
    localDW->HoughTransform_o3[138] = -149.0;
    localDW->HoughTransform_o3[139] = -148.0;
    localDW->HoughTransform_o3[140] = -147.0;
    localDW->HoughTransform_o3[141] = -146.0;
    localDW->HoughTransform_o3[142] = -145.0;
    localDW->HoughTransform_o3[143] = -144.0;
    localDW->HoughTransform_o3[144] = -143.0;
    localDW->HoughTransform_o3[145] = -142.0;
    localDW->HoughTransform_o3[146] = -141.0;
    localDW->HoughTransform_o3[147] = -140.0;
    localDW->HoughTransform_o3[148] = -139.0;
    localDW->HoughTransform_o3[149] = -138.0;
    localDW->HoughTransform_o3[150] = -137.0;
    localDW->HoughTransform_o3[151] = -136.0;
    localDW->HoughTransform_o3[152] = -135.0;
    localDW->HoughTransform_o3[153] = -134.0;
    localDW->HoughTransform_o3[154] = -133.0;
    localDW->HoughTransform_o3[155] = -132.0;
    localDW->HoughTransform_o3[156] = -131.0;
    localDW->HoughTransform_o3[157] = -130.0;
    localDW->HoughTransform_o3[158] = -129.0;
    localDW->HoughTransform_o3[159] = -128.0;
    localDW->HoughTransform_o3[160] = -127.0;
    localDW->HoughTransform_o3[161] = -126.0;
    localDW->HoughTransform_o3[162] = -125.0;
    localDW->HoughTransform_o3[163] = -124.0;
    localDW->HoughTransform_o3[164] = -123.0;
    localDW->HoughTransform_o3[165] = -122.0;
    localDW->HoughTransform_o3[166] = -121.0;
    localDW->HoughTransform_o3[167] = -120.0;
    localDW->HoughTransform_o3[168] = -119.0;
    localDW->HoughTransform_o3[169] = -118.0;
    localDW->HoughTransform_o3[170] = -117.0;
    localDW->HoughTransform_o3[171] = -116.0;
    localDW->HoughTransform_o3[172] = -115.0;
    localDW->HoughTransform_o3[173] = -114.0;
    localDW->HoughTransform_o3[174] = -113.0;
    localDW->HoughTransform_o3[175] = -112.0;
    localDW->HoughTransform_o3[176] = -111.0;
    localDW->HoughTransform_o3[177] = -110.0;
    localDW->HoughTransform_o3[178] = -109.0;
    localDW->HoughTransform_o3[179] = -108.0;
    localDW->HoughTransform_o3[180] = -107.0;
    localDW->HoughTransform_o3[181] = -106.0;
    localDW->HoughTransform_o3[182] = -105.0;
    localDW->HoughTransform_o3[183] = -104.0;
    localDW->HoughTransform_o3[184] = -103.0;
    localDW->HoughTransform_o3[185] = -102.0;
    localDW->HoughTransform_o3[186] = -101.0;
    localDW->HoughTransform_o3[187] = -100.0;
    localDW->HoughTransform_o3[188] = -99.0;
    localDW->HoughTransform_o3[189] = -98.0;
    localDW->HoughTransform_o3[190] = -97.0;
    localDW->HoughTransform_o3[191] = -96.0;
    localDW->HoughTransform_o3[192] = -95.0;
    localDW->HoughTransform_o3[193] = -94.0;
    localDW->HoughTransform_o3[194] = -93.0;
    localDW->HoughTransform_o3[195] = -92.0;
    localDW->HoughTransform_o3[196] = -91.0;
    localDW->HoughTransform_o3[197] = -90.0;
    localDW->HoughTransform_o3[198] = -89.0;
    localDW->HoughTransform_o3[199] = -88.0;
    localDW->HoughTransform_o3[200] = -87.0;
    localDW->HoughTransform_o3[201] = -86.0;
    localDW->HoughTransform_o3[202] = -85.0;
    localDW->HoughTransform_o3[203] = -84.0;
    localDW->HoughTransform_o3[204] = -83.0;
    localDW->HoughTransform_o3[205] = -82.0;
    localDW->HoughTransform_o3[206] = -81.0;
    localDW->HoughTransform_o3[207] = -80.0;
    localDW->HoughTransform_o3[208] = -79.0;
    localDW->HoughTransform_o3[209] = -78.0;
    localDW->HoughTransform_o3[210] = -77.0;
    localDW->HoughTransform_o3[211] = -76.0;
    localDW->HoughTransform_o3[212] = -75.0;
    localDW->HoughTransform_o3[213] = -74.0;
    localDW->HoughTransform_o3[214] = -73.0;
    localDW->HoughTransform_o3[215] = -72.0;
    localDW->HoughTransform_o3[216] = -71.0;
    localDW->HoughTransform_o3[217] = -70.0;
    localDW->HoughTransform_o3[218] = -69.0;
    localDW->HoughTransform_o3[219] = -68.0;
    localDW->HoughTransform_o3[220] = -67.0;
    localDW->HoughTransform_o3[221] = -66.0;
    localDW->HoughTransform_o3[222] = -65.0;
    localDW->HoughTransform_o3[223] = -64.0;
    localDW->HoughTransform_o3[224] = -63.0;
    localDW->HoughTransform_o3[225] = -62.0;
    localDW->HoughTransform_o3[226] = -61.0;
    localDW->HoughTransform_o3[227] = -60.0;
    localDW->HoughTransform_o3[228] = -59.0;
    localDW->HoughTransform_o3[229] = -58.0;
    localDW->HoughTransform_o3[230] = -57.0;
    localDW->HoughTransform_o3[231] = -56.0;
    localDW->HoughTransform_o3[232] = -55.0;
    localDW->HoughTransform_o3[233] = -54.0;
    localDW->HoughTransform_o3[234] = -53.0;
    localDW->HoughTransform_o3[235] = -52.0;
    localDW->HoughTransform_o3[236] = -51.0;
    localDW->HoughTransform_o3[237] = -50.0;
    localDW->HoughTransform_o3[238] = -49.0;
    localDW->HoughTransform_o3[239] = -48.0;
    localDW->HoughTransform_o3[240] = -47.0;
    localDW->HoughTransform_o3[241] = -46.0;
    localDW->HoughTransform_o3[242] = -45.0;
    localDW->HoughTransform_o3[243] = -44.0;
    localDW->HoughTransform_o3[244] = -43.0;
    localDW->HoughTransform_o3[245] = -42.0;
    localDW->HoughTransform_o3[246] = -41.0;
    localDW->HoughTransform_o3[247] = -40.0;
    localDW->HoughTransform_o3[248] = -39.0;
    localDW->HoughTransform_o3[249] = -38.0;
    localDW->HoughTransform_o3[250] = -37.0;
    localDW->HoughTransform_o3[251] = -36.0;
    localDW->HoughTransform_o3[252] = -35.0;
    localDW->HoughTransform_o3[253] = -34.0;
    localDW->HoughTransform_o3[254] = -33.0;
    localDW->HoughTransform_o3[255] = -32.0;
    localDW->HoughTransform_o3[256] = -31.0;
    localDW->HoughTransform_o3[257] = -30.0;
    localDW->HoughTransform_o3[258] = -29.0;
    localDW->HoughTransform_o3[259] = -28.0;
    localDW->HoughTransform_o3[260] = -27.0;
    localDW->HoughTransform_o3[261] = -26.0;
    localDW->HoughTransform_o3[262] = -25.0;
    localDW->HoughTransform_o3[263] = -24.0;
    localDW->HoughTransform_o3[264] = -23.0;
    localDW->HoughTransform_o3[265] = -22.0;
    localDW->HoughTransform_o3[266] = -21.0;
    localDW->HoughTransform_o3[267] = -20.0;
    localDW->HoughTransform_o3[268] = -19.0;
    localDW->HoughTransform_o3[269] = -18.0;
    localDW->HoughTransform_o3[270] = -17.0;
    localDW->HoughTransform_o3[271] = -16.0;
    localDW->HoughTransform_o3[272] = -15.0;
    localDW->HoughTransform_o3[273] = -14.0;
    localDW->HoughTransform_o3[274] = -13.0;
    localDW->HoughTransform_o3[275] = -12.0;
    localDW->HoughTransform_o3[276] = -11.0;
    localDW->HoughTransform_o3[277] = -10.0;
    localDW->HoughTransform_o3[278] = -9.0;
    localDW->HoughTransform_o3[279] = -8.0;
    localDW->HoughTransform_o3[280] = -7.0;
    localDW->HoughTransform_o3[281] = -6.0;
    localDW->HoughTransform_o3[282] = -5.0;
    localDW->HoughTransform_o3[283] = -4.0;
    localDW->HoughTransform_o3[284] = -3.0;
    localDW->HoughTransform_o3[285] = -2.0;
    localDW->HoughTransform_o3[286] = -1.0;
    localDW->HoughTransform_o3[288] = 1.0;
    localDW->HoughTransform_o3[289] = 2.0;
    localDW->HoughTransform_o3[290] = 3.0;
    localDW->HoughTransform_o3[291] = 4.0;
    localDW->HoughTransform_o3[292] = 5.0;
    localDW->HoughTransform_o3[293] = 6.0;
    localDW->HoughTransform_o3[294] = 7.0;
    localDW->HoughTransform_o3[295] = 8.0;
    localDW->HoughTransform_o3[296] = 9.0;
    localDW->HoughTransform_o3[297] = 10.0;
    localDW->HoughTransform_o3[298] = 11.0;
    localDW->HoughTransform_o3[299] = 12.0;
    localDW->HoughTransform_o3[300] = 13.0;
    localDW->HoughTransform_o3[301] = 14.0;
    localDW->HoughTransform_o3[302] = 15.0;
    localDW->HoughTransform_o3[303] = 16.0;
    localDW->HoughTransform_o3[304] = 17.0;
    localDW->HoughTransform_o3[305] = 18.0;
    localDW->HoughTransform_o3[306] = 19.0;
    localDW->HoughTransform_o3[307] = 20.0;
    localDW->HoughTransform_o3[308] = 21.0;
    localDW->HoughTransform_o3[309] = 22.0;
    localDW->HoughTransform_o3[310] = 23.0;
    localDW->HoughTransform_o3[311] = 24.0;
    localDW->HoughTransform_o3[312] = 25.0;
    localDW->HoughTransform_o3[313] = 26.0;
    localDW->HoughTransform_o3[314] = 27.0;
    localDW->HoughTransform_o3[315] = 28.0;
    localDW->HoughTransform_o3[316] = 29.0;
    localDW->HoughTransform_o3[317] = 30.0;
    localDW->HoughTransform_o3[318] = 31.0;
    localDW->HoughTransform_o3[319] = 32.0;
    localDW->HoughTransform_o3[320] = 33.0;
    localDW->HoughTransform_o3[321] = 34.0;
    localDW->HoughTransform_o3[322] = 35.0;
    localDW->HoughTransform_o3[323] = 36.0;
    localDW->HoughTransform_o3[324] = 37.0;
    localDW->HoughTransform_o3[325] = 38.0;
    localDW->HoughTransform_o3[326] = 39.0;
    localDW->HoughTransform_o3[327] = 40.0;
    localDW->HoughTransform_o3[328] = 41.0;
    localDW->HoughTransform_o3[329] = 42.0;
    localDW->HoughTransform_o3[330] = 43.0;
    localDW->HoughTransform_o3[331] = 44.0;
    localDW->HoughTransform_o3[332] = 45.0;
    localDW->HoughTransform_o3[333] = 46.0;
    localDW->HoughTransform_o3[334] = 47.0;
    localDW->HoughTransform_o3[335] = 48.0;
    localDW->HoughTransform_o3[336] = 49.0;
    localDW->HoughTransform_o3[337] = 50.0;
    localDW->HoughTransform_o3[338] = 51.0;
    localDW->HoughTransform_o3[339] = 52.0;
    localDW->HoughTransform_o3[340] = 53.0;
    localDW->HoughTransform_o3[341] = 54.0;
    localDW->HoughTransform_o3[342] = 55.0;
    localDW->HoughTransform_o3[343] = 56.0;
    localDW->HoughTransform_o3[344] = 57.0;
    localDW->HoughTransform_o3[345] = 58.0;
    localDW->HoughTransform_o3[346] = 59.0;
    localDW->HoughTransform_o3[347] = 60.0;
    localDW->HoughTransform_o3[348] = 61.0;
    localDW->HoughTransform_o3[349] = 62.0;
    localDW->HoughTransform_o3[350] = 63.0;
    localDW->HoughTransform_o3[351] = 64.0;
    localDW->HoughTransform_o3[352] = 65.0;
    localDW->HoughTransform_o3[353] = 66.0;
    localDW->HoughTransform_o3[354] = 67.0;
    localDW->HoughTransform_o3[355] = 68.0;
    localDW->HoughTransform_o3[356] = 69.0;
    localDW->HoughTransform_o3[357] = 70.0;
    localDW->HoughTransform_o3[358] = 71.0;
    localDW->HoughTransform_o3[359] = 72.0;
    localDW->HoughTransform_o3[360] = 73.0;
    localDW->HoughTransform_o3[361] = 74.0;
    localDW->HoughTransform_o3[362] = 75.0;
    localDW->HoughTransform_o3[363] = 76.0;
    localDW->HoughTransform_o3[364] = 77.0;
    localDW->HoughTransform_o3[365] = 78.0;
    localDW->HoughTransform_o3[366] = 79.0;
    localDW->HoughTransform_o3[367] = 80.0;
    localDW->HoughTransform_o3[368] = 81.0;
    localDW->HoughTransform_o3[369] = 82.0;
    localDW->HoughTransform_o3[370] = 83.0;
    localDW->HoughTransform_o3[371] = 84.0;
    localDW->HoughTransform_o3[372] = 85.0;
    localDW->HoughTransform_o3[373] = 86.0;
    localDW->HoughTransform_o3[374] = 87.0;
    localDW->HoughTransform_o3[375] = 88.0;
    localDW->HoughTransform_o3[376] = 89.0;
    localDW->HoughTransform_o3[377] = 90.0;
    localDW->HoughTransform_o3[378] = 91.0;
    localDW->HoughTransform_o3[379] = 92.0;
    localDW->HoughTransform_o3[380] = 93.0;
    localDW->HoughTransform_o3[381] = 94.0;
    localDW->HoughTransform_o3[382] = 95.0;
    localDW->HoughTransform_o3[383] = 96.0;
    localDW->HoughTransform_o3[384] = 97.0;
    localDW->HoughTransform_o3[385] = 98.0;
    localDW->HoughTransform_o3[386] = 99.0;
    localDW->HoughTransform_o3[387] = 100.0;
    localDW->HoughTransform_o3[388] = 101.0;
    localDW->HoughTransform_o3[389] = 102.0;
    localDW->HoughTransform_o3[390] = 103.0;
    localDW->HoughTransform_o3[391] = 104.0;
    localDW->HoughTransform_o3[392] = 105.0;
    localDW->HoughTransform_o3[393] = 106.0;
    localDW->HoughTransform_o3[394] = 107.0;
    localDW->HoughTransform_o3[395] = 108.0;
    localDW->HoughTransform_o3[396] = 109.0;
    localDW->HoughTransform_o3[397] = 110.0;
    localDW->HoughTransform_o3[398] = 111.0;
    localDW->HoughTransform_o3[399] = 112.0;
    localDW->HoughTransform_o3[400] = 113.0;
    localDW->HoughTransform_o3[401] = 114.0;
    localDW->HoughTransform_o3[402] = 115.0;
    localDW->HoughTransform_o3[403] = 116.0;
    localDW->HoughTransform_o3[404] = 117.0;
    localDW->HoughTransform_o3[405] = 118.0;
    localDW->HoughTransform_o3[406] = 119.0;
    localDW->HoughTransform_o3[407] = 120.0;
    localDW->HoughTransform_o3[408] = 121.0;
    localDW->HoughTransform_o3[409] = 122.0;
    localDW->HoughTransform_o3[410] = 123.0;
    localDW->HoughTransform_o3[411] = 124.0;
    localDW->HoughTransform_o3[412] = 125.0;
    localDW->HoughTransform_o3[413] = 126.0;
    localDW->HoughTransform_o3[414] = 127.0;
    localDW->HoughTransform_o3[415] = 128.0;
    localDW->HoughTransform_o3[416] = 129.0;
    localDW->HoughTransform_o3[417] = 130.0;
    localDW->HoughTransform_o3[418] = 131.0;
    localDW->HoughTransform_o3[419] = 132.0;
    localDW->HoughTransform_o3[420] = 133.0;
    localDW->HoughTransform_o3[421] = 134.0;
    localDW->HoughTransform_o3[422] = 135.0;
    localDW->HoughTransform_o3[423] = 136.0;
    localDW->HoughTransform_o3[424] = 137.0;
    localDW->HoughTransform_o3[425] = 138.0;
    localDW->HoughTransform_o3[426] = 139.0;
    localDW->HoughTransform_o3[427] = 140.0;
    localDW->HoughTransform_o3[428] = 141.0;
    localDW->HoughTransform_o3[429] = 142.0;
    localDW->HoughTransform_o3[430] = 143.0;
    localDW->HoughTransform_o3[431] = 144.0;
    localDW->HoughTransform_o3[432] = 145.0;
    localDW->HoughTransform_o3[433] = 146.0;
    localDW->HoughTransform_o3[434] = 147.0;
    localDW->HoughTransform_o3[435] = 148.0;
    localDW->HoughTransform_o3[436] = 149.0;
    localDW->HoughTransform_o3[437] = 150.0;
    localDW->HoughTransform_o3[438] = 151.0;
    localDW->HoughTransform_o3[439] = 152.0;
    localDW->HoughTransform_o3[440] = 153.0;
    localDW->HoughTransform_o3[441] = 154.0;
    localDW->HoughTransform_o3[442] = 155.0;
    localDW->HoughTransform_o3[443] = 156.0;
    localDW->HoughTransform_o3[444] = 157.0;
    localDW->HoughTransform_o3[445] = 158.0;
    localDW->HoughTransform_o3[446] = 159.0;
    localDW->HoughTransform_o3[447] = 160.0;
    localDW->HoughTransform_o3[448] = 161.0;
    localDW->HoughTransform_o3[449] = 162.0;
    localDW->HoughTransform_o3[450] = 163.0;
    localDW->HoughTransform_o3[451] = 164.0;
    localDW->HoughTransform_o3[452] = 165.0;
    localDW->HoughTransform_o3[453] = 166.0;
    localDW->HoughTransform_o3[454] = 167.0;
    localDW->HoughTransform_o3[455] = 168.0;
    localDW->HoughTransform_o3[456] = 169.0;
    localDW->HoughTransform_o3[457] = 170.0;
    localDW->HoughTransform_o3[458] = 171.0;
    localDW->HoughTransform_o3[459] = 172.0;
    localDW->HoughTransform_o3[460] = 173.0;
    localDW->HoughTransform_o3[461] = 174.0;
    localDW->HoughTransform_o3[462] = 175.0;
    localDW->HoughTransform_o3[463] = 176.0;
    localDW->HoughTransform_o3[464] = 177.0;
    localDW->HoughTransform_o3[465] = 178.0;
    localDW->HoughTransform_o3[466] = 179.0;
    localDW->HoughTransform_o3[467] = 180.0;
    localDW->HoughTransform_o3[468] = 181.0;
    localDW->HoughTransform_o3[469] = 182.0;
    localDW->HoughTransform_o3[470] = 183.0;
    localDW->HoughTransform_o3[471] = 184.0;
    localDW->HoughTransform_o3[472] = 185.0;
    localDW->HoughTransform_o3[473] = 186.0;
    localDW->HoughTransform_o3[474] = 187.0;
    localDW->HoughTransform_o3[475] = 188.0;
    localDW->HoughTransform_o3[476] = 189.0;
    localDW->HoughTransform_o3[477] = 190.0;
    localDW->HoughTransform_o3[478] = 191.0;
    localDW->HoughTransform_o3[479] = 192.0;
    localDW->HoughTransform_o3[480] = 193.0;
    localDW->HoughTransform_o3[481] = 194.0;
    localDW->HoughTransform_o3[482] = 195.0;
    localDW->HoughTransform_o3[483] = 196.0;
    localDW->HoughTransform_o3[484] = 197.0;
    localDW->HoughTransform_o3[485] = 198.0;
    localDW->HoughTransform_o3[486] = 199.0;
    localDW->HoughTransform_o3[487] = 200.0;
    localDW->HoughTransform_o3[488] = 201.0;
    localDW->HoughTransform_o3[489] = 202.0;
    localDW->HoughTransform_o3[490] = 203.0;
    localDW->HoughTransform_o3[491] = 204.0;
    localDW->HoughTransform_o3[492] = 205.0;
    localDW->HoughTransform_o3[493] = 206.0;
    localDW->HoughTransform_o3[494] = 207.0;
    localDW->HoughTransform_o3[495] = 208.0;
    localDW->HoughTransform_o3[496] = 209.0;
    localDW->HoughTransform_o3[497] = 210.0;
    localDW->HoughTransform_o3[498] = 211.0;
    localDW->HoughTransform_o3[499] = 212.0;
    localDW->HoughTransform_o3[500] = 213.0;
    localDW->HoughTransform_o3[501] = 214.0;
    localDW->HoughTransform_o3[502] = 215.0;
    localDW->HoughTransform_o3[503] = 216.0;
    localDW->HoughTransform_o3[504] = 217.0;
    localDW->HoughTransform_o3[505] = 218.0;
    localDW->HoughTransform_o3[506] = 219.0;
    localDW->HoughTransform_o3[507] = 220.0;
    localDW->HoughTransform_o3[508] = 221.0;
    localDW->HoughTransform_o3[509] = 222.0;
    localDW->HoughTransform_o3[510] = 223.0;
    localDW->HoughTransform_o3[511] = 224.0;
    localDW->HoughTransform_o3[512] = 225.0;
    localDW->HoughTransform_o3[513] = 226.0;
    localDW->HoughTransform_o3[514] = 227.0;
    localDW->HoughTransform_o3[515] = 228.0;
    localDW->HoughTransform_o3[516] = 229.0;
    localDW->HoughTransform_o3[517] = 230.0;
    localDW->HoughTransform_o3[518] = 231.0;
    localDW->HoughTransform_o3[519] = 232.0;
    localDW->HoughTransform_o3[520] = 233.0;
    localDW->HoughTransform_o3[521] = 234.0;
    localDW->HoughTransform_o3[522] = 235.0;
    localDW->HoughTransform_o3[523] = 236.0;
    localDW->HoughTransform_o3[524] = 237.0;
    localDW->HoughTransform_o3[525] = 238.0;
    localDW->HoughTransform_o3[526] = 239.0;
    localDW->HoughTransform_o3[527] = 240.0;
    localDW->HoughTransform_o3[528] = 241.0;
    localDW->HoughTransform_o3[529] = 242.0;
    localDW->HoughTransform_o3[530] = 243.0;
    localDW->HoughTransform_o3[531] = 244.0;
    localDW->HoughTransform_o3[532] = 245.0;
    localDW->HoughTransform_o3[533] = 246.0;
    localDW->HoughTransform_o3[534] = 247.0;
    localDW->HoughTransform_o3[535] = 248.0;
    localDW->HoughTransform_o3[536] = 249.0;
    localDW->HoughTransform_o3[537] = 250.0;
    localDW->HoughTransform_o3[538] = 251.0;
    localDW->HoughTransform_o3[539] = 252.0;
    localDW->HoughTransform_o3[540] = 253.0;
    localDW->HoughTransform_o3[541] = 254.0;
    localDW->HoughTransform_o3[542] = 255.0;
    localDW->HoughTransform_o3[543] = 256.0;
    localDW->HoughTransform_o3[544] = 257.0;
    localDW->HoughTransform_o3[545] = 258.0;
    localDW->HoughTransform_o3[546] = 259.0;
    localDW->HoughTransform_o3[547] = 260.0;
    localDW->HoughTransform_o3[548] = 261.0;
    localDW->HoughTransform_o3[549] = 262.0;
    localDW->HoughTransform_o3[550] = 263.0;
    localDW->HoughTransform_o3[551] = 264.0;
    localDW->HoughTransform_o3[552] = 265.0;
    localDW->HoughTransform_o3[553] = 266.0;
    localDW->HoughTransform_o3[554] = 267.0;
    localDW->HoughTransform_o3[555] = 268.0;
    localDW->HoughTransform_o3[556] = 269.0;
    localDW->HoughTransform_o3[557] = 270.0;
    localDW->HoughTransform_o3[558] = 271.0;
    localDW->HoughTransform_o3[559] = 272.0;
    localDW->HoughTransform_o3[560] = 273.0;
    localDW->HoughTransform_o3[561] = 274.0;
    localDW->HoughTransform_o3[562] = 275.0;
    localDW->HoughTransform_o3[563] = 276.0;
    localDW->HoughTransform_o3[564] = 277.0;
    localDW->HoughTransform_o3[565] = 278.0;
    localDW->HoughTransform_o3[566] = 279.0;
    localDW->HoughTransform_o3[567] = 280.0;
    localDW->HoughTransform_o3[568] = 281.0;
    localDW->HoughTransform_o3[569] = 282.0;
    localDW->HoughTransform_o3[570] = 283.0;
    localDW->HoughTransform_o3[571] = 284.0;
    localDW->HoughTransform_o3[572] = 285.0;
    localDW->HoughTransform_o3[573] = 286.0;
    localDW->HoughTransform_o3[574] = 287.0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
