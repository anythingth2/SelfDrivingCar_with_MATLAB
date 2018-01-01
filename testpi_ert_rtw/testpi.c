/*
 * File: testpi.c
 *
 * Code generated for Simulink model 'testpi'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 31 19:55:17 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "testpi.h"
#include "testpi_dt.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

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

/* Block signals (auto storage) */
B rtB;

/* Block states (auto storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo);
int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift);
void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo);
int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn0;
  uint32_T absIn1;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  absIn1 = in1 < 0 ? ~(uint32_T)in1 + 1U : (uint32_T)in1;
  in0Hi = absIn0 >> 16U;
  in0Lo = absIn0 & 65535U;
  in1Hi = absIn1 >> 16U;
  absIn0 = absIn1 & 65535U;
  productHiLo = in0Hi * absIn0;
  productLoHi = in0Lo * in1Hi;
  absIn0 *= in0Lo;
  absIn1 = 0U;
  in0Lo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (in0Lo < absIn0) {
    absIn1 = 1U;
  }

  absIn0 = in0Lo;
  in0Lo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (in0Lo < absIn0) {
    absIn1++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    absIn1;
  if (!((in0 == 0) || ((in1 == 0) || ((in0 > 0) == (in1 > 0))))) {
    absIn0 = ~absIn0;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_loSR(int32_T a, int32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

void mul_wide_su32(int32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                   *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T absIn0;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn0 = in0 < 0 ? ~(uint32_T)in0 + 1U : (uint32_T)in0;
  in0Hi = absIn0 >> 16U;
  absIn0 &= 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << /*MW:OvBitwiseOk*/ 16U) + /*MW:OvCarryOk*/ absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1U;
  }

  absIn0 = outBitsLo;
  outBitsLo += /*MW:OvCarryOk*/ productHiLo << /*MW:OvBitwiseOk*/ 16U;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi) +
    in1Lo;
  if (!((in1 == 0U) || (in0 >= 0))) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0U) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

int32_T mul_ssu32_loSR(int32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_su32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << /*MW:OvBitwiseOk*/ (32U - aShift) | u32_clo >> aShift;
  return (int32_T)u32_clo;
}

/* Model step function */
void testpi_step(void)
{
  uint32_T acc;
  real_T val;
  int32_T imgRow;
  int32_T m;
  boolean_T b4;
  boolean_T b3;
  boolean_T b2;
  boolean_T b1;
  int32_T accumOne;
  int32_T accumTwo;
  int32_T numElem;
  int32_T accumFour;
  int32_T accumThree;
  int32_T imgIdx_d;

  /* S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureOutput(rtConstP.V4L2VideoCapture_p1, rtB.V4L2VideoCapture_o1,
                        rtB.V4L2VideoCapture_o2, rtB.V4L2VideoCapture_o3);

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  for (numElem = 0; numElem < 76800; numElem++) {
    acc = ((rtB.V4L2VideoCapture_o1[numElem] * 19595U +
            rtB.V4L2VideoCapture_o2[numElem] * 38470U) +
           rtB.V4L2VideoCapture_o3[numElem] * 7471U) + 32768U;
    acc >>= 16;
    rtB.ColorSpaceConversion[numElem] = (uint8_T)acc;
  }

  /* End of S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (numElem = 0; numElem < 238; numElem++) {
    for (imgRow = 0; imgRow < 318; imgRow++) {
      accumOne = 0;
      accumTwo = 0;
      imgIdx_d = ((numElem + 1) * 320 + imgRow) + 1;
      for (m = 0; m < 6; m++) {
        accumOne += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
          rtB.ColorSpaceConversion[imgIdx_d + rtDW.EdgeDetection_VO_DW[m]], 23U);
        accumTwo += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
          rtB.ColorSpaceConversion[imgIdx_d + rtDW.EdgeDetection_HO_DW[m]], 23U);
      }

      rtDW.EdgeDetection_GV_SQUARED_DW[imgIdx_d] = mul_s32_loSR(accumOne,
        accumOne, 8U);
      rtDW.EdgeDetection_GH_SQUARED_DW[imgIdx_d] = mul_s32_loSR(accumTwo,
        accumTwo, 8U);
    }
  }

  for (numElem = 0; numElem < 238; numElem++) {
    accumOne = 0;
    accumTwo = 0;
    accumThree = 0;
    accumFour = 0;
    imgRow = (numElem + 1) * 320;
    imgIdx_d = (numElem + 1) * 320 + 319;
    for (m = 0; m < 6; m++) {
      accumOne += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
        rtB.ColorSpaceConversion[imgRow + rtDW.EdgeDetection_HOU_DW[m]], 23U);
      accumTwo += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
        rtB.ColorSpaceConversion[imgIdx_d + rtDW.EdgeDetection_HOD_DW[m]], 23U);
      accumThree += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
        rtB.ColorSpaceConversion[imgRow + rtDW.EdgeDetection_VOU_DW[m]], 23U);
      accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
        rtB.ColorSpaceConversion[imgIdx_d + rtDW.EdgeDetection_VOD_DW[m]], 23U);
    }

    rtDW.EdgeDetection_GV_SQUARED_DW[imgRow] = mul_s32_loSR(accumThree,
      accumThree, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[imgRow] = mul_s32_loSR(accumOne, accumOne,
      8U);
    rtDW.EdgeDetection_GV_SQUARED_DW[imgIdx_d] = mul_s32_loSR(accumFour,
      accumFour, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[imgIdx_d] = mul_s32_loSR(accumTwo, accumTwo,
      8U);
  }

  for (imgRow = 0; imgRow < 318; imgRow++) {
    accumOne = 0;
    accumTwo = 0;
    accumThree = 0;
    accumFour = 0;
    numElem = imgRow + 76481;
    for (m = 0; m < 6; m++) {
      accumOne += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
        rtB.ColorSpaceConversion[(imgRow + rtDW.EdgeDetection_VOL_DW[m]) + 1],
        23U);
      accumTwo += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
        rtB.ColorSpaceConversion[numElem + rtDW.EdgeDetection_VOR_DW[m]], 23U);
      accumThree += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
        rtB.ColorSpaceConversion[(imgRow + rtDW.EdgeDetection_HOL_DW[m]) + 1],
        23U);
      accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
        rtB.ColorSpaceConversion[numElem + rtDW.EdgeDetection_HOR_DW[m]], 23U);
    }

    rtDW.EdgeDetection_GV_SQUARED_DW[imgRow + 1] = mul_s32_loSR(accumOne,
      accumOne, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[imgRow + 1] = mul_s32_loSR(accumThree,
      accumThree, 8U);
    rtDW.EdgeDetection_GV_SQUARED_DW[numElem] = mul_s32_loSR(accumTwo, accumTwo,
      8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[numElem] = mul_s32_loSR(accumFour,
      accumFour, 8U);
  }

  accumOne = 0;
  accumTwo = 0;
  accumThree = 0;
  accumFour = 0;
  for (m = 0; m < 6; m++) {
    accumOne += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
      rtB.ColorSpaceConversion[rtDW.EdgeDetection_VOUL_DW[m]], 23U);
    accumTwo += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
      rtB.ColorSpaceConversion[rtDW.EdgeDetection_HOUL_DW[m]], 23U);
    accumThree += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
      rtB.ColorSpaceConversion[319 + rtDW.EdgeDetection_VOLL_DW[m]], 23U);
    accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
      rtB.ColorSpaceConversion[319 + rtDW.EdgeDetection_HOLL_DW[m]], 23U);
  }

  rtDW.EdgeDetection_GV_SQUARED_DW[0] = mul_s32_loSR(accumOne, accumOne, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[0] = mul_s32_loSR(accumTwo, accumTwo, 8U);
  rtDW.EdgeDetection_GV_SQUARED_DW[319] = mul_s32_loSR(accumThree, accumThree,
    8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[319] = mul_s32_loSR(accumFour, accumFour, 8U);
  accumOne = 0;
  accumTwo = 0;
  accumThree = 0;
  accumFour = 0;
  for (m = 0; m < 6; m++) {
    accumOne += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
      rtB.ColorSpaceConversion[76480 + rtDW.EdgeDetection_VOUR_DW[m]], 23U);
    accumTwo += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
      rtB.ColorSpaceConversion[76480 + rtDW.EdgeDetection_HOUR_DW[m]], 23U);
    accumThree += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[m],
      rtB.ColorSpaceConversion[76799 + rtDW.EdgeDetection_VOLR_DW[m]], 23U);
    accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[m],
      rtB.ColorSpaceConversion[76799 + rtDW.EdgeDetection_HOLR_DW[m]], 23U);
  }

  rtDW.EdgeDetection_GV_SQUARED_DW[76480] = mul_s32_loSR(accumOne, accumOne, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[76480] = mul_s32_loSR(accumTwo, accumTwo, 8U);
  rtDW.EdgeDetection_GV_SQUARED_DW[76799] = mul_s32_loSR(accumThree, accumThree,
    8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[76799] = mul_s32_loSR(accumFour, accumFour,
    8U);
  accumTwo = 0;
  for (m = 0; m < 76800; m++) {
    rtDW.EdgeDetection_GRAD_SUM_DW[m] = rtDW.EdgeDetection_GV_SQUARED_DW[m];
    rtDW.EdgeDetection_GRAD_SUM_DW[m] += rtDW.EdgeDetection_GH_SQUARED_DW[m];
    accumTwo += mul_s32_loSR(rtDW.EdgeDetection_GRAD_SUM_DW[m],
      rtDW.EdgeDetection_MEAN_FACTOR_DW, 31U);
  }

  accumOne = accumTwo << 2;
  for (numElem = 0; numElem < 240; numElem++) {
    for (imgRow = 0; imgRow < 320; imgRow++) {
      m = numElem * 320 + imgRow;
      b1 = true;
      b2 = true;
      b3 = true;
      b4 = true;
      if (numElem != 0) {
        b1 = (rtDW.EdgeDetection_GRAD_SUM_DW[m - 320] <=
              rtDW.EdgeDetection_GRAD_SUM_DW[m]);
      }

      if (numElem != 239) {
        b2 = (rtDW.EdgeDetection_GRAD_SUM_DW[m] >
              rtDW.EdgeDetection_GRAD_SUM_DW[m + 320]);
      }

      if (imgRow != 0) {
        b3 = (rtDW.EdgeDetection_GRAD_SUM_DW[m - 1] <=
              rtDW.EdgeDetection_GRAD_SUM_DW[m]);
      }

      if (imgRow != 319) {
        b4 = (rtDW.EdgeDetection_GRAD_SUM_DW[m] >
              rtDW.EdgeDetection_GRAD_SUM_DW[m + 1]);
      }

      rtB.EdgeDetection[m] = ((rtDW.EdgeDetection_GRAD_SUM_DW[m] > accumOne) &&
        (((rtDW.EdgeDetection_GV_SQUARED_DW[m] >=
           rtDW.EdgeDetection_GH_SQUARED_DW[m]) && b1 && b2) ||
         ((rtDW.EdgeDetection_GH_SQUARED_DW[m] >=
           rtDW.EdgeDetection_GV_SQUARED_DW[m]) && b3 && b4)));
    }
  }

  /* End of S-Function (svipedge): '<Root>/Edge Detection' */
  for (numElem = 0; numElem < 76800; numElem++) {
    /* S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Product: '<S1>/Divide'
     */
    val = (real_T)(rtB.EdgeDetection[numElem] * 255) * 255.0 + 0.5;
    if (val > 255.0) {
      val = 255.0;
    }

    rtB.ImageDataTypeConversion[numElem] = (uint8_T)val;

    /* End of S-Function (svipscalenconvert): '<S1>/Image Data Type Conversion' */
  }

  /* Start for MATLABSystem: '<S2>/MATLAB System' incorporates:
   *  MATLABSystem: '<S2>/MATLAB System'
   */
  memcpy(&rtB.pln1[0], &rtB.ImageDataTypeConversion[0], 76800U * sizeof(uint8_T));
  memcpy(&rtB.pln2[0], &rtB.ImageDataTypeConversion[0], 76800U * sizeof(uint8_T));
  memcpy(&rtB.pln3[0], &rtB.ImageDataTypeConversion[0], 76800U * sizeof(uint8_T));
  MW_SDL_videoDisplayOutput(rtB.pln1, rtB.pln2, rtB.pln3);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.25s, 0.0s] */
    rtExtModeUpload(0, rtM->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.25s, 0.0s] */
    if ((rtmGetTFinal(rtM)!=-1) &&
        !((rtmGetTFinal(rtM)-rtM->Timing.taskTime0) > rtM->Timing.taskTime0 *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(rtM, "Simulation finished");
    }

    if (rtmGetStopRequested(rtM)) {
      rtmSetErrorStatus(rtM, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.taskTime0 =
    (++rtM->Timing.clockTick0) * rtM->Timing.stepSize0;
}

/* Model initialize function */
void testpi_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize0 = 0.25;

  /* External mode info */
  rtM->Sizes.checksums[0] = (293578282U);
  rtM->Sizes.checksums[1] = (3341415545U);
  rtM->Sizes.checksums[2] = (1926451745U);
  rtM->Sizes.checksums[3] = (3053112511U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rtM->extModeInfo, &rtM->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rtM->extModeInfo, rtM->Sizes.checksums);
    rteiSetTPtr(rtM->extModeInfo, rtmGetTPtr(rtM));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rtM->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  {
    int32_T nonZeroIdx;

    /* Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
    MW_videoCaptureInit(rtConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U, 240U, 2U,
                        2U, 1U, 0.25);

    /* Start for S-Function (svipedge): '<Root>/Edge Detection' */
    rtDW.EdgeDetection_MEAN_FACTOR_DW = 27962;
    for (nonZeroIdx = 0; nonZeroIdx < 6; nonZeroIdx++) {
      rtDW.EdgeDetection_VO_DW[nonZeroIdx] =
        rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
        rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      if (rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx] > 0) {
        rtDW.EdgeDetection_VOU_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOD_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320;
      } else {
        rtDW.EdgeDetection_VOU_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320;
        rtDW.EdgeDetection_VOD_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if (rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] > 0) {
        rtDW.EdgeDetection_VOL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      } else {
        rtDW.EdgeDetection_VOL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
        rtDW.EdgeDetection_VOUL_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_VOLR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOLL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOUR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320;
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] < 0)) {
        rtDW.EdgeDetection_VOLL_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_VOUR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOUL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOLR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320;
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx] < 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
        rtDW.EdgeDetection_VOUR_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_VOLL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOUL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320;
        rtDW.EdgeDetection_VOLR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx] >= 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] >= 0)) {
        rtDW.EdgeDetection_VOLR_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_VOUL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_VOLL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VRO_RTP[nonZeroIdx] * 320;
        rtDW.EdgeDetection_VOUR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_VCO_RTP[nonZeroIdx];
      }

      rtDW.EdgeDetection_HO_DW[nonZeroIdx] =
        rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
        rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      if (rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx] > 0) {
        rtDW.EdgeDetection_HOU_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOD_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320;
      } else {
        rtDW.EdgeDetection_HOU_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320;
        rtDW.EdgeDetection_HOD_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if (rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] > 0) {
        rtDW.EdgeDetection_HOL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      } else {
        rtDW.EdgeDetection_HOL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
        rtDW.EdgeDetection_HOUL_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_HOLR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOLL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOUR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320;
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] < 0)) {
        rtDW.EdgeDetection_HOLL_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_HOUR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOUL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOLR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320;
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx] < 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
        rtDW.EdgeDetection_HOUR_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_HOLL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOUL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320;
        rtDW.EdgeDetection_HOLR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx] >= 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] >= 0)) {
        rtDW.EdgeDetection_HOLR_DW[nonZeroIdx] = 0;
        rtDW.EdgeDetection_HOUL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
        rtDW.EdgeDetection_HOLL_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HRO_RTP[nonZeroIdx] * 320;
        rtDW.EdgeDetection_HOUR_DW[nonZeroIdx] =
          rtConstP.EdgeDetection_HCO_RTP[nonZeroIdx];
      }
    }

    /* End of Start for S-Function (svipedge): '<Root>/Edge Detection' */
    /* Start for MATLABSystem: '<S2>/MATLAB System' */
    rtDW.obj.isInitialized = 0;
    rtDW.obj.isInitialized = 1;
    rtDW.obj.PixelFormatEnum = 1;
    MW_SDL_videoDisplayInit(rtDW.obj.PixelFormatEnum, 1, 1, 320.0, 240.0);

    /* End of Start for SubSystem: '<Root>/SDL Video Display' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
