/*
 * File: lane_departure.c
 *
 * Code generated for Simulink model 'lane_departure'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Wed Feb 14 01:43:31 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "lane_departure.h"
#include "lane_departure_dt.h"

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
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
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

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

/* Model step function */
void lane_departure_step(void)
{
  boolean_T done;
  boolean_T b4;
  boolean_T b3;
  boolean_T b2;
  uint8_T minVal;
  int32_T outIdx;
  int32_T outIdxAdj;
  int32_T inIdx;
  int32_T col;
  int32_T hOffset;
  int32_T gOffset;
  int32_T numIter;
  int32_T numEleTmp;
  int32_T lastBlockCol;
  int32_T i;
  int32_T ky;
  int32_T ku;
  int32_T line_idx_3;
  int32_T line_idx_2;

  /* S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
  MW_videoCaptureOutput(rtConstP.V4L2VideoCapture_p1, rtB.V4L2VideoCapture_o1,
                        rtB.V4L2VideoCapture_o2, rtB.V4L2VideoCapture_o3);

  /* S-Function (svipmorphop): '<Root>/Erosion' */
  ku = 0;
  rtDW.Erosion_ONE_PAD_IMG_DW[0] = MAX_uint8_T;
  ky = 1;
  for (numEleTmp = 0; numEleTmp < 326; numEleTmp++) {
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    ky++;
  }

  for (i = 0; i < 240; i++) {
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    memcpy(&rtDW.Erosion_ONE_PAD_IMG_DW[ky + 1], &rtB.V4L2VideoCapture_o1[ku],
           320U * sizeof(uint8_T));
    ky += 321;
    ku += 320;
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    ky++;
    for (numEleTmp = 0; numEleTmp < 5; numEleTmp++) {
      rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
      ky++;
    }
  }

  for (i = 0; i < 6; i++) {
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    ky++;
    for (numEleTmp = 0; numEleTmp < 326; numEleTmp++) {
      rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
      ky++;
    }
  }

  memset(&rtDW.Erosion_TWO_PAD_IMG_DW[0], 255, 80769U * sizeof(uint8_T));
  ky = rtDW.Erosion_NUMNONZ_DW[0];
  inIdx = 0;
  outIdx = 1;
  if (rtDW.Erosion_STREL_DW[0] == 0) {
    for (col = 0; col < 246; col++) {
      rtB.row = 0;
      while (rtB.row < 323) {
        minVal = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx + rtDW.Erosion_ERODE_OFF_DW[0]];
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_ONE_PAD_IMG_DW[inIdx + rtDW.Erosion_ERODE_OFF_DW[i]] <
              minVal) {
            minVal = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx +
              rtDW.Erosion_ERODE_OFF_DW[i]];
          }
        }

        rtDW.Erosion_TWO_PAD_IMG_DW[outIdx] = minVal;
        inIdx++;
        outIdx++;
        rtB.row++;
      }

      inIdx += 4;
      outIdx += 4;
    }
  } else if (rtDW.Erosion_STREL_DW[0] == 1) {
    numIter = 324 / rtDW.Erosion_NUMNONZ_DW[0];
    numEleTmp = rtDW.Erosion_ERODE_OFF_DW[0] / 327 * 327;
    i = rtDW.Erosion_ERODE_OFF_DW[0] - numEleTmp;
    gOffset = (rtDW.Erosion_NUMNONZ_DW[0] + i) - 1;
    hOffset = i - 1;
    inIdx = 1 + numEleTmp;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[0];
    for (i = 0; i < ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[0];
    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    for (i = 0; i < ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    for (col = 0; col < 246; col++) {
      numEleTmp = ky;
      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
          }

          numEleTmp++;
          inIdx++;
        }
      }

      if (lastBlockCol <= 323) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        ku = lastBlockCol + ky;
        for (i = lastBlockCol + 1; i < ku; i++) {
          if (i < 323) {
            if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp -
                1];
            } else {
              rtDW.Erosion_GBUF_DW[numEleTmp] =
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          }

          numEleTmp++;
          inIdx++;
        }
      }

      inIdx--;
      if (lastBlockCol <= 323) {
        for (i = 1; i - 1 < ky; i++) {
          if ((ky - i) + lastBlockCol < 323) {
            if (rtDW.Erosion_HBUF_DW[numEleTmp] <
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_HBUF_DW[numEleTmp];
            } else {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          }

          numEleTmp--;
          inIdx--;
        }
      }

      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx--;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_HBUF_DW[numEleTmp] <
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
          }

          numEleTmp--;
          inIdx--;
        }
      }

      rtB.row = 0;
      while (rtB.row < 323) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtDW.Erosion_TWO_PAD_IMG_DW[outIdx] = rtDW.Erosion_GBUF_DW[(numEleTmp
            + gOffset) - 1];
        } else {
          rtDW.Erosion_TWO_PAD_IMG_DW[outIdx] = rtDW.Erosion_HBUF_DW[numEleTmp +
            hOffset];
        }

        numEleTmp++;
        outIdx++;
        rtB.row++;
      }

      inIdx += 328;
      outIdx += 4;
    }
  } else {
    numIter = 246 / rtDW.Erosion_NUMNONZ_DW[0];
    i = rtDW.Erosion_ERODE_OFF_DW[0] / 327;
    gOffset = rtDW.Erosion_NUMNONZ_DW[0] + i;
    hOffset = i;
    inIdx = rtDW.Erosion_ERODE_OFF_DW[0] - i * 327;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[0];
    for (i = 0; i < ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[0];
    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    for (i = 0; i < ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    rtB.row = 0;
    while (rtB.row < 323) {
      numEleTmp = ky;
      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 327;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
          }

          numEleTmp++;
          inIdx += 327;
        }
      }

      if (lastBlockCol <= 246) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 327;
        ku = lastBlockCol + ky;
        for (i = lastBlockCol + 1; i < ku; i++) {
          if (i < 246) {
            if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp -
                1];
            } else {
              rtDW.Erosion_GBUF_DW[numEleTmp] =
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          }

          numEleTmp++;
          inIdx += 327;
        }
      }

      inIdx -= 327;
      if (lastBlockCol <= 246) {
        for (i = 1; i - 1 < ky; i++) {
          if ((ky - i) + lastBlockCol < 246) {
            if (rtDW.Erosion_HBUF_DW[numEleTmp] <
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_HBUF_DW[numEleTmp];
            } else {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          }

          numEleTmp--;
          inIdx -= 327;
        }
      }

      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx -= 327;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_HBUF_DW[numEleTmp] <
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
          }

          numEleTmp--;
          inIdx -= 327;
        }
      }

      for (col = 0; col < 246; col++) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtDW.Erosion_TWO_PAD_IMG_DW[outIdx] = rtDW.Erosion_GBUF_DW[(numEleTmp
            + gOffset) - 1];
        } else {
          rtDW.Erosion_TWO_PAD_IMG_DW[outIdx] = rtDW.Erosion_HBUF_DW[numEleTmp +
            hOffset];
        }

        numEleTmp++;
        outIdx += 327;
      }

      inIdx += 328;
      outIdx += -80441;
      rtB.row++;
    }
  }

  numEleTmp = rtDW.Erosion_NUMNONZ_DW[0];
  ky = rtDW.Erosion_NUMNONZ_DW[1];
  inIdx = 1;
  outIdx = 0;
  if (rtDW.Erosion_STREL_DW[1] == 0) {
    for (col = 0; col < 240; col++) {
      rtB.row = 1;
      while (rtB.row < 321) {
        minVal = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx +
          rtDW.Erosion_ERODE_OFF_DW[numEleTmp]];
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_TWO_PAD_IMG_DW[rtDW.Erosion_ERODE_OFF_DW[i +
              numEleTmp] + inIdx] < minVal) {
            minVal = rtDW.Erosion_TWO_PAD_IMG_DW[rtDW.Erosion_ERODE_OFF_DW[i +
              numEleTmp] + inIdx];
          }
        }

        rtB.Erosion[outIdx] = minVal;
        inIdx++;
        outIdx++;
        rtB.row++;
      }

      inIdx += 7;
    }
  } else if (rtDW.Erosion_STREL_DW[1] == 1) {
    numIter = 320 / rtDW.Erosion_NUMNONZ_DW[1];
    numEleTmp = rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] / 327 *
      327;
    i = rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] - numEleTmp;
    gOffset = rtDW.Erosion_NUMNONZ_DW[1] + i;
    hOffset = i;
    inIdx = numEleTmp + 1;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[1] + 1;
    for (i = 0; i < ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[1];
    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    for (i = 0; i < ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    for (col = 0; col < 240; col++) {
      numEleTmp = ky;
      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
          }

          numEleTmp++;
          inIdx++;
        }
      }

      if (lastBlockCol <= 321) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        ku = lastBlockCol + ky;
        for (i = lastBlockCol + 1; i < ku; i++) {
          if (i < 321) {
            if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp -
                1];
            } else {
              rtDW.Erosion_GBUF_DW[numEleTmp] =
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          }

          numEleTmp++;
          inIdx++;
        }
      }

      inIdx--;
      if (lastBlockCol <= 321) {
        for (i = 1; i - 1 < ky; i++) {
          if ((ky - i) + lastBlockCol < 321) {
            if (rtDW.Erosion_HBUF_DW[numEleTmp] <
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_HBUF_DW[numEleTmp];
            } else {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          }

          numEleTmp--;
          inIdx--;
        }
      }

      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx--;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_HBUF_DW[numEleTmp] <
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
          }

          numEleTmp--;
          inIdx--;
        }
      }

      rtB.row = 1;
      while (rtB.row < 321) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtB.Erosion[outIdx] = rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1];
        } else {
          rtB.Erosion[outIdx] = rtDW.Erosion_HBUF_DW[numEleTmp + hOffset];
        }

        numEleTmp++;
        outIdx++;
        rtB.row++;
      }

      inIdx += 328;
    }
  } else {
    numIter = 241 / rtDW.Erosion_NUMNONZ_DW[1];
    i = rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] / 327;
    gOffset = (rtDW.Erosion_NUMNONZ_DW[1] + i) - 1;
    hOffset = i - 1;
    inIdx = (rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] - i * 327) +
      328;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[1];
    for (i = 0; i < ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[1];
    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_GBUF_DW[i] = MAX_uint8_T;
    }

    for (i = 0; i < ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    for (i = numEleTmp; i < numEleTmp + ky; i++) {
      rtDW.Erosion_HBUF_DW[i] = MAX_uint8_T;
    }

    rtB.row = 1;
    while (rtB.row < 321) {
      numEleTmp = ky;
      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 327;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
          }

          numEleTmp++;
          inIdx += 327;
        }
      }

      if (lastBlockCol <= 240) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 327;
        ku = lastBlockCol + ky;
        for (i = lastBlockCol + 1; i < ku; i++) {
          if (i < 240) {
            if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp -
                1];
            } else {
              rtDW.Erosion_GBUF_DW[numEleTmp] =
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          }

          numEleTmp++;
          inIdx += 327;
        }
      }

      inIdx -= 327;
      if (lastBlockCol <= 240) {
        for (i = 1; i - 1 < ky; i++) {
          if ((ky - i) + lastBlockCol < 240) {
            if (rtDW.Erosion_HBUF_DW[numEleTmp] <
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_HBUF_DW[numEleTmp];
            } else {
              rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
                rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
            }
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          }

          numEleTmp--;
          inIdx -= 327;
        }
      }

      for (ku = 0; ku < numIter; ku++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx -= 327;
        for (i = 1; i < ky; i++) {
          if (rtDW.Erosion_HBUF_DW[numEleTmp] <
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
          }

          numEleTmp--;
          inIdx -= 327;
        }
      }

      for (col = 0; col < 240; col++) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtB.Erosion[outIdx] = rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1];
        } else {
          rtB.Erosion[outIdx] = rtDW.Erosion_HBUF_DW[numEleTmp + hOffset];
        }

        numEleTmp++;
        outIdx += 320;
      }

      inIdx += 328;
      outIdx += -76799;
      rtB.row++;
    }
  }

  /* End of S-Function (svipmorphop): '<Root>/Erosion' */

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (numEleTmp = 0; numEleTmp < 238; numEleTmp++) {
    for (lastBlockCol = 0; lastBlockCol < 318; lastBlockCol++) {
      inIdx = 0;
      numIter = 0;
      outIdx = ((numEleTmp + 1) * 320 + lastBlockCol) + 1;
      for (i = 0; i < 6; i++) {
        inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i],
          rtB.Erosion[outIdx + rtDW.EdgeDetection_VO_DW[i]], 23U);
        numIter += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
          rtB.Erosion[outIdx + rtDW.EdgeDetection_HO_DW[i]], 23U);
      }

      rtDW.EdgeDetection_GV_SQUARED_DW[outIdx] = mul_s32_loSR(inIdx, inIdx, 8U);
      rtDW.EdgeDetection_GH_SQUARED_DW[outIdx] = mul_s32_loSR(numIter, numIter,
        8U);
    }
  }

  for (numEleTmp = 0; numEleTmp < 238; numEleTmp++) {
    inIdx = 0;
    numIter = 0;
    ku = 0;
    rtB.accumFour = 0;
    lastBlockCol = (numEleTmp + 1) * 320;
    outIdx = (numEleTmp + 1) * 320 + 319;
    for (i = 0; i < 6; i++) {
      inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
        rtB.Erosion[lastBlockCol + rtDW.EdgeDetection_HOU_DW[i]], 23U);
      numIter += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
        rtB.Erosion[outIdx + rtDW.EdgeDetection_HOD_DW[i]], 23U);
      ku += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i],
                           rtB.Erosion[lastBlockCol +
                           rtDW.EdgeDetection_VOU_DW[i]], 23U);
      rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i],
        rtB.Erosion[outIdx + rtDW.EdgeDetection_VOD_DW[i]], 23U);
    }

    rtDW.EdgeDetection_GV_SQUARED_DW[lastBlockCol] = mul_s32_loSR(ku, ku, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[lastBlockCol] = mul_s32_loSR(inIdx, inIdx,
      8U);
    rtDW.EdgeDetection_GV_SQUARED_DW[outIdx] = mul_s32_loSR(rtB.accumFour,
      rtB.accumFour, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[outIdx] = mul_s32_loSR(numIter, numIter, 8U);
  }

  for (lastBlockCol = 0; lastBlockCol < 318; lastBlockCol++) {
    inIdx = 0;
    numIter = 0;
    ku = 0;
    rtB.accumFour = 0;
    numEleTmp = lastBlockCol + 76481;
    for (i = 0; i < 6; i++) {
      inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i], rtB.Erosion
        [(lastBlockCol + rtDW.EdgeDetection_VOL_DW[i]) + 1], 23U);
      numIter += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i],
        rtB.Erosion[numEleTmp + rtDW.EdgeDetection_VOR_DW[i]], 23U);
      ku += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i], rtB.Erosion
                           [(lastBlockCol + rtDW.EdgeDetection_HOL_DW[i]) + 1],
                           23U);
      rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
        rtB.Erosion[numEleTmp + rtDW.EdgeDetection_HOR_DW[i]], 23U);
    }

    rtDW.EdgeDetection_GV_SQUARED_DW[lastBlockCol + 1] = mul_s32_loSR(inIdx,
      inIdx, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[lastBlockCol + 1] = mul_s32_loSR(ku, ku, 8U);
    rtDW.EdgeDetection_GV_SQUARED_DW[numEleTmp] = mul_s32_loSR(numIter, numIter,
      8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[numEleTmp] = mul_s32_loSR(rtB.accumFour,
      rtB.accumFour, 8U);
  }

  inIdx = 0;
  numIter = 0;
  ku = 0;
  rtB.accumFour = 0;
  for (i = 0; i < 6; i++) {
    inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i],
      rtB.Erosion[rtDW.EdgeDetection_VOUL_DW[i]], 23U);
    numIter += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
      rtB.Erosion[rtDW.EdgeDetection_HOUL_DW[i]], 23U);
    ku += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i], rtB.Erosion[319 +
                         rtDW.EdgeDetection_VOLL_DW[i]], 23U);
    rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
      rtB.Erosion[319 + rtDW.EdgeDetection_HOLL_DW[i]], 23U);
  }

  rtDW.EdgeDetection_GV_SQUARED_DW[0] = mul_s32_loSR(inIdx, inIdx, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[0] = mul_s32_loSR(numIter, numIter, 8U);
  rtDW.EdgeDetection_GV_SQUARED_DW[319] = mul_s32_loSR(ku, ku, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[319] = mul_s32_loSR(rtB.accumFour,
    rtB.accumFour, 8U);
  inIdx = 0;
  numIter = 0;
  ku = 0;
  rtB.accumFour = 0;
  for (i = 0; i < 6; i++) {
    inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i], rtB.Erosion[76480
      + rtDW.EdgeDetection_VOUR_DW[i]], 23U);
    numIter += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i], rtB.Erosion
      [76480 + rtDW.EdgeDetection_HOUR_DW[i]], 23U);
    ku += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[i], rtB.Erosion[76799 +
                         rtDW.EdgeDetection_VOLR_DW[i]], 23U);
    rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[i],
      rtB.Erosion[76799 + rtDW.EdgeDetection_HOLR_DW[i]], 23U);
  }

  rtDW.EdgeDetection_GV_SQUARED_DW[76480] = mul_s32_loSR(inIdx, inIdx, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[76480] = mul_s32_loSR(numIter, numIter, 8U);
  rtDW.EdgeDetection_GV_SQUARED_DW[76799] = mul_s32_loSR(ku, ku, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[76799] = mul_s32_loSR(rtB.accumFour,
    rtB.accumFour, 8U);
  numIter = 0;
  for (i = 0; i < 76800; i++) {
    rtDW.EdgeDetection_GRAD_SUM_DW[i] = rtDW.EdgeDetection_GV_SQUARED_DW[i];
    rtDW.EdgeDetection_GRAD_SUM_DW[i] += rtDW.EdgeDetection_GH_SQUARED_DW[i];
    numIter += mul_s32_loSR(rtDW.EdgeDetection_GRAD_SUM_DW[i],
      rtDW.EdgeDetection_MEAN_FACTOR_DW, 31U);
  }

  inIdx = numIter << 2;
  for (numEleTmp = 0; numEleTmp < 240; numEleTmp++) {
    for (lastBlockCol = 0; lastBlockCol < 320; lastBlockCol++) {
      i = numEleTmp * 320 + lastBlockCol;
      done = true;
      b2 = true;
      b3 = true;
      b4 = true;
      if (numEleTmp != 0) {
        done = (rtDW.EdgeDetection_GRAD_SUM_DW[i - 320] <=
                rtDW.EdgeDetection_GRAD_SUM_DW[i]);
      }

      if (numEleTmp != 239) {
        b2 = (rtDW.EdgeDetection_GRAD_SUM_DW[i] >
              rtDW.EdgeDetection_GRAD_SUM_DW[i + 320]);
      }

      if (lastBlockCol != 0) {
        b3 = (rtDW.EdgeDetection_GRAD_SUM_DW[i - 1] <=
              rtDW.EdgeDetection_GRAD_SUM_DW[i]);
      }

      if (lastBlockCol != 319) {
        b4 = (rtDW.EdgeDetection_GRAD_SUM_DW[i] >
              rtDW.EdgeDetection_GRAD_SUM_DW[i + 1]);
      }

      rtB.EdgeDetection[i] = ((rtDW.EdgeDetection_GRAD_SUM_DW[i] > inIdx) &&
        (((rtDW.EdgeDetection_GV_SQUARED_DW[i] >=
           rtDW.EdgeDetection_GH_SQUARED_DW[i]) && done && b2) ||
         ((rtDW.EdgeDetection_GH_SQUARED_DW[i] >=
           rtDW.EdgeDetection_GV_SQUARED_DW[i]) && b3 && b4)));
    }
  }

  /* End of S-Function (svipedge): '<Root>/Edge Detection' */

  /* S-Function (sviphough): '<S2>/Hough Transform' */
  MWVIP_Hough_D(&rtB.EdgeDetection[0], &rtB.HoughTransform_o1[0],
                &rtConstP.HoughTransform_SINE_TABLE_RTP[0],
                &rtConstP.HoughTransform_FIRSTRHO_RTP, 320, 240, 799, 91);

  /* S-Function (svipfindlocalmax): '<S2>/Find Local Maxima' */
  ku = 0;
  done = false;
  for (i = 0; i < 143820; i++) {
    rtDW.FindLocalMaxima_TEMP_IN_DWORKS[i] = rtB.HoughTransform_o1[i];
  }

  for (i = 0; i < 6; i++) {
    rtB.FindLocalMaxima[i] = 0.0;
  }

  while (!done) {
    ky = 0;
    rtB.maxValue = rtDW.FindLocalMaxima_TEMP_IN_DWORKS[0];
    for (i = 0; i < 143820; i++) {
      if (rtDW.FindLocalMaxima_TEMP_IN_DWORKS[i] > rtB.maxValue) {
        ky = i;
        rtB.maxValue = rtDW.FindLocalMaxima_TEMP_IN_DWORKS[i];
      }
    }

    numEleTmp = ky % 799;
    i = ky / 799;
    if (rtDW.FindLocalMaxima_TEMP_IN_DWORKS[ky] >= 10.0) {
      rtB.FindLocalMaxima[ku] = 1.0 + (real_T)i;
      rtB.FindLocalMaxima[3U + ku] = 1 + numEleTmp;
      ku++;
      if (ku == 3) {
        done = true;
      }

      ky = numEleTmp - 2;
      if (!(ky > 0)) {
        ky = 0;
      }

      lastBlockCol = numEleTmp + 2;
      if (!(lastBlockCol < 798)) {
        lastBlockCol = 798;
      }

      outIdx = i - 3;
      rtB.accumFour = i + 3;
      if (!((outIdx < 0) || (rtB.accumFour > 179))) {
        while (outIdx <= rtB.accumFour) {
          inIdx = outIdx * 799;
          for (i = ky; i <= lastBlockCol; i++) {
            rtDW.FindLocalMaxima_TEMP_IN_DWORKS[i + inIdx] = 0.0;
          }

          outIdx++;
        }
      } else {
        if (outIdx < 0) {
          for (numEleTmp = outIdx; numEleTmp <= rtB.accumFour; numEleTmp++) {
            if (numEleTmp < 0) {
              inIdx = (numEleTmp + 180) * 799 + 798;
              for (i = ky; i <= lastBlockCol; i++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[inIdx - i] = 0.0;
              }
            } else {
              inIdx = numEleTmp * 799;
              for (i = ky; i <= lastBlockCol; i++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[i + inIdx] = 0.0;
              }
            }
          }
        }

        if (rtB.accumFour > 179) {
          for (numEleTmp = outIdx; numEleTmp <= rtB.accumFour; numEleTmp++) {
            if (numEleTmp > 179) {
              inIdx = (numEleTmp - 180) * 799 + 798;
              for (i = ky; i <= lastBlockCol; i++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[inIdx - i] = 0.0;
              }
            } else {
              inIdx = numEleTmp * 799;
              for (i = ky; i <= lastBlockCol; i++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[i + inIdx] = 0.0;
              }
            }
          }
        }
      }
    } else {
      done = true;
    }
  }

  rtB.fromIdx = 3U;
  rtB.toIdx = (uint32_T)ku;
  for (i = 0; i < ku; i++) {
    rtB.FindLocalMaxima[rtB.toIdx] = rtB.FindLocalMaxima[rtB.fromIdx];
    rtB.fromIdx++;
    rtB.toIdx++;
  }

  rtDW.FindLocalMaxima_DIMS1[0] = ku;
  rtDW.FindLocalMaxima_DIMS1[1] = 2;

  /* End of S-Function (svipfindlocalmax): '<S2>/Find Local Maxima' */

  /* Selector: '<S2>/Selector' */
  rtDW.Selector_DIMS1[0] = rtDW.FindLocalMaxima_DIMS1[0];
  rtDW.Selector_DIMS1[1] = 1;
  i = rtDW.FindLocalMaxima_DIMS1[0];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    rtB.rtb_FindLocalMaxima_data[numEleTmp] = rtB.FindLocalMaxima[numEleTmp];
  }

  i = rtDW.FindLocalMaxima_DIMS1[0];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    rtB.Selector[numEleTmp] = rtB.rtb_FindLocalMaxima_data[numEleTmp];
  }

  /* End of Selector: '<S2>/Selector' */

  /* Selector: '<S2>/Selector1' */
  rtDW.Selector1_DIMS1[0] = 1;
  rtDW.Selector1_DIMS1[1] = rtDW.Selector_DIMS1[0] * rtDW.Selector_DIMS1[1];
  i = rtDW.Selector_DIMS1[1];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    outIdx = rtDW.Selector_DIMS1[0];
    for (lastBlockCol = 0; lastBlockCol < outIdx; lastBlockCol++) {
      rtB.rtb_Selector_data[lastBlockCol + rtDW.Selector_DIMS1[0] * numEleTmp] =
        (int32_T)rtB.Selector[rtDW.Selector_DIMS1[0] * numEleTmp + lastBlockCol]
        - 1;
    }
  }

  i = rtDW.Selector_DIMS1[0] * rtDW.Selector_DIMS1[1];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    rtB.Selector1[rtDW.Selector1_DIMS1[0] * numEleTmp] =
      rtB.HoughTransform_o2[rtB.rtb_Selector_data[numEleTmp]];
  }

  /* End of Selector: '<S2>/Selector1' */

  /* Selector: '<S2>/Selector2' */
  rtDW.Selector2_DIMS1[0] = rtDW.FindLocalMaxima_DIMS1[0];
  rtDW.Selector2_DIMS1[1] = 1;
  i = rtDW.FindLocalMaxima_DIMS1[0];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    rtB.rtb_FindLocalMaxima_data[numEleTmp] = rtB.FindLocalMaxima[numEleTmp +
      rtDW.FindLocalMaxima_DIMS1[0]];
  }

  i = rtDW.FindLocalMaxima_DIMS1[0];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    rtB.Selector[numEleTmp] = rtB.rtb_FindLocalMaxima_data[numEleTmp];
  }

  /* End of Selector: '<S2>/Selector2' */

  /* Selector: '<S2>/Selector5' */
  rtDW.Selector5_DIMS1[0] = 1;
  rtDW.Selector5_DIMS1[1] = rtDW.Selector2_DIMS1[0] * rtDW.Selector2_DIMS1[1];
  i = rtDW.Selector2_DIMS1[1];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    outIdx = rtDW.Selector2_DIMS1[0];
    for (lastBlockCol = 0; lastBlockCol < outIdx; lastBlockCol++) {
      rtB.rtb_Selector_data[lastBlockCol + rtDW.Selector2_DIMS1[0] * numEleTmp] =
        (int32_T)rtB.Selector[rtDW.Selector2_DIMS1[0] * numEleTmp + lastBlockCol]
        - 1;
    }
  }

  i = rtDW.Selector2_DIMS1[0] * rtDW.Selector2_DIMS1[1];
  for (numEleTmp = 0; numEleTmp < i; numEleTmp++) {
    rtB.Selector5[rtDW.Selector5_DIMS1[0] * numEleTmp] =
      rtB.HoughTransform_o3[rtB.rtb_Selector_data[numEleTmp]];
  }

  /* End of Selector: '<S2>/Selector5' */

  /* S-Function (sviphoughlines): '<S2>/Hough Lines' */
  rtDW.HoughLines_DIMS1[1] = 4;
  rtDW.HoughLines_DIMS1[0] = rtDW.Selector1_DIMS1[0] * rtDW.Selector1_DIMS1[1];
  for (i = 0; i < rtDW.Selector1_DIMS1[1]; i++) {
    ky = 0;
    rtB.maxValue = (rtB.Selector5[i] + 2.2204460492503131E-16) / (cos
      (rtB.Selector1[i]) + 2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    rtB.tmpRound = floor(rtB.maxValue + 0.5);
    if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 239.0)) {
      rtB.tmpOutRC[0U] = 0;
      if (rtB.tmpRound >= 0.5) {
        rtB.tmpOutRC[1U] = (int32_T)floor(rtB.tmpRound + 0.5);
      } else {
        rtB.tmpOutRC[1U] = 0;
      }

      ky = 1;
    }

    rtB.y2 = (rtB.Selector5[i] + 2.2204460492503131E-16) / (sin(rtB.Selector1[i])
      + 2.2204460492503131E-16);

    /* part-2: left vertical axis */
    rtB.tmpRound = floor(rtB.y2 + 0.5);
    if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 319.0)) {
      if (rtB.tmpRound >= 0.5) {
        rtB.tmpOutRC[ky << 1] = (int32_T)floor(rtB.tmpRound + 0.5);
      } else {
        rtB.tmpOutRC[ky << 1] = 0;
      }

      rtB.tmpOutRC[1 + (ky << 1)] = 0;
      ky++;
    }

    /* part-3: Right vertical axis */
    if (ky < 2) {
      rtB.tmpRound = floor((rtB.maxValue - 239.0) * (rtB.y2 / rtB.maxValue) +
                           0.5);
      if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 319.0)) {
        if (rtB.tmpRound >= 0.5) {
          rtB.tmpOutRC[ky << 1] = (int32_T)floor(rtB.tmpRound + 0.5);
        } else {
          rtB.tmpOutRC[ky << 1] = 0;
        }

        rtB.tmpOutRC[1 + (ky << 1)] = 239;
        ky++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (ky < 2) {
      rtB.tmpRound = floor((rtB.maxValue - rtB.maxValue / rtB.y2 * 319.0) + 0.5);
      if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 239.0)) {
        rtB.tmpOutRC[ky << 1] = 319;
        if (rtB.tmpRound >= 0.5) {
          rtB.tmpOutRC[1 + (ky << 1)] = (int32_T)floor(rtB.tmpRound + 0.5);
        } else {
          rtB.tmpOutRC[1 + (ky << 1)] = 0;
        }

        ky++;
      }
    }

    if (ky < 2) {
      rtB.tmpOutRC[0U] = -1;
      rtB.tmpOutRC[1U] = -1;
      rtB.tmpOutRC[2U] = -1;
      rtB.tmpOutRC[3U] = -1;
    }

    rtB.HoughLines[i] = rtB.tmpOutRC[1] + 1;
    rtB.HoughLines[i + rtDW.Selector1_DIMS1[1]] = rtB.tmpOutRC[0] + 1;
    if (rtB.tmpOutRC[3] > 2147483646) {
      rtB.HoughLines[i + (rtDW.Selector1_DIMS1[1] << 1)] = MAX_int32_T;
    } else {
      rtB.HoughLines[i + (rtDW.Selector1_DIMS1[1] << 1)] = rtB.tmpOutRC[3] + 1;
    }

    if (rtB.tmpOutRC[2] > 2147483646) {
      rtB.HoughLines[i + 3 * rtDW.Selector1_DIMS1[1]] = MAX_int32_T;
    } else {
      rtB.HoughLines[i + 3 * rtDW.Selector1_DIMS1[1]] = rtB.tmpOutRC[2] + 1;
    }
  }

  /* End of S-Function (sviphoughlines): '<S2>/Hough Lines' */

  /* S-Function (svipdrawshapes): '<Root>/Draw Shapes' */
  /* Compute output for unity line width
   */
  ky = 0;
  ku = 0;
  if (rtDW.HoughLines_DIMS1[1] > 1) {
    ku = rtDW.HoughLines_DIMS1[1] >> 1;
    done = (ku << 1 == rtDW.HoughLines_DIMS1[1]);
    ky = rtDW.HoughLines_DIMS1[0];
  } else {
    if (rtDW.HoughLines_DIMS1[1] == 1) {
      ku = rtDW.HoughLines_DIMS1[0] >> 1;
      done = (ku << 1 == rtDW.HoughLines_DIMS1[0]);
      ky = 1;
    }
  }

  /* Copy the image from input to output. */
  memcpy(&rtB.DrawShapes[0], &rtB.V4L2VideoCapture_o1[0], 76800U * sizeof
         (uint8_T));
  if (done && (ky > 0)) {
    /* Update view port. */
    for (lastBlockCol = 0; lastBlockCol < ky; lastBlockCol++) {
      outIdx = 0;
      rtB.accumFour = 0;
      while (rtB.accumFour < ku - 1) {
        col = rtB.HoughLines[((outIdx * ky << 1) + lastBlockCol) + ky] - 1;
        rtB.row = rtB.HoughLines[(outIdx * ky << 1) + lastBlockCol] - 1;
        outIdx++;
        outIdxAdj = rtB.HoughLines[((outIdx * ky << 1) + lastBlockCol) + ky] - 1;
        line_idx_3 = rtB.HoughLines[(outIdx * ky << 1) + lastBlockCol] - 1;
        if ((rtB.HoughLines[((outIdx * ky << 1) + lastBlockCol) + ky] - 1 != col)
            || (rtB.HoughLines[(outIdx * ky << 1) + lastBlockCol] - 1 != rtB.row))
        {
          b2 = false;

          /* Find the visible portion of a line. */
          b3 = false;
          b4 = false;
          done = false;
          numIter = col;
          hOffset = rtB.row;
          line_idx_2 = outIdxAdj;
          gOffset = line_idx_3;
          while (!done) {
            rtB.fromIdx = 0U;
            rtB.toIdx = 0U;

            /* Determine viewport violations. */
            if (numIter < 0) {
              rtB.fromIdx = 4U;
            } else {
              if (numIter > 319) {
                rtB.fromIdx = 8U;
              }
            }

            if (line_idx_2 < 0) {
              rtB.toIdx = 4U;
            } else {
              if (line_idx_2 > 319) {
                rtB.toIdx = 8U;
              }
            }

            if (hOffset < 0) {
              rtB.fromIdx |= 1U;
            } else {
              if (hOffset > 239) {
                rtB.fromIdx |= 2U;
              }
            }

            if (gOffset < 0) {
              rtB.toIdx |= 1U;
            } else {
              if (gOffset > 239) {
                rtB.toIdx |= 2U;
              }
            }

            if (!((rtB.fromIdx | rtB.toIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              b2 = true;
            } else if ((rtB.fromIdx & rtB.toIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              b2 = false;
            } else if (rtB.fromIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (b3) {
                numIter = col;
                hOffset = rtB.row;
              }

              i = line_idx_2 - numIter;
              numEleTmp = gOffset - hOffset;
              if ((i > 1073741824) || (i < -1073741824) || ((numEleTmp >
                    1073741824) || (numEleTmp < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b3 = true;
              } else if ((rtB.fromIdx & 4U) != 0U) {
                /* Violated RMin. */
                inIdx = -numIter * numEleTmp;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (i >= 0)) || ((inIdx < 0) && (i < 0)))
                {
                  hOffset += (div_nde_s32_floor(inIdx << 1, i) + 1) >> 1;
                } else {
                  hOffset -= (div_nde_s32_floor(-inIdx << 1, i) + 1) >> 1;
                }

                numIter = 0;
                b3 = true;
              } else if ((rtB.fromIdx & 8U) != 0U) {
                /* Violated RMax. */
                inIdx = (319 - numIter) * numEleTmp;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (i >= 0)) || ((inIdx < 0) && (i < 0)))
                {
                  hOffset += (div_nde_s32_floor(inIdx << 1, i) + 1) >> 1;
                } else {
                  hOffset -= (div_nde_s32_floor(-inIdx << 1, i) + 1) >> 1;
                }

                numIter = 319;
                b3 = true;
              } else if ((rtB.fromIdx & 1U) != 0U) {
                /* Violated CMin. */
                inIdx = -hOffset * i;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (numEleTmp >= 0)) || ((inIdx < 0) &&
                            (numEleTmp < 0))) {
                  numIter += (div_nde_s32_floor(inIdx << 1, numEleTmp) + 1) >> 1;
                } else {
                  numIter -= (div_nde_s32_floor(-inIdx << 1, numEleTmp) + 1) >>
                    1;
                }

                hOffset = 0;
                b3 = true;
              } else {
                /* Violated CMax. */
                inIdx = (239 - hOffset) * i;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (numEleTmp >= 0)) || ((inIdx < 0) &&
                            (numEleTmp < 0))) {
                  numIter += (div_nde_s32_floor(inIdx << 1, numEleTmp) + 1) >> 1;
                } else {
                  numIter -= (div_nde_s32_floor(-inIdx << 1, numEleTmp) + 1) >>
                    1;
                }

                hOffset = 239;
                b3 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (b4) {
                line_idx_2 = outIdxAdj;
                gOffset = line_idx_3;
              }

              i = line_idx_2 - numIter;
              numEleTmp = gOffset - hOffset;
              if ((i > 1073741824) || (i < -1073741824) || ((numEleTmp >
                    1073741824) || (numEleTmp < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b4 = true;
              } else if ((rtB.toIdx & 4U) != 0U) {
                /* Violated RMin. */
                inIdx = -line_idx_2 * numEleTmp;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (i >= 0)) || ((inIdx < 0) && (i < 0)))
                {
                  gOffset += (div_nde_s32_floor(inIdx << 1, i) + 1) >> 1;
                } else {
                  gOffset -= (div_nde_s32_floor(-inIdx << 1, i) + 1) >> 1;
                }

                line_idx_2 = 0;
                b4 = true;
              } else if ((rtB.toIdx & 8U) != 0U) {
                /* Violated RMax. */
                inIdx = (319 - line_idx_2) * numEleTmp;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (i >= 0)) || ((inIdx < 0) && (i < 0)))
                {
                  gOffset += (div_nde_s32_floor(inIdx << 1, i) + 1) >> 1;
                } else {
                  gOffset -= (div_nde_s32_floor(-inIdx << 1, i) + 1) >> 1;
                }

                line_idx_2 = 319;
                b4 = true;
              } else if ((rtB.toIdx & 1U) != 0U) {
                /* Violated CMin. */
                inIdx = -gOffset * i;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (numEleTmp >= 0)) || ((inIdx < 0) &&
                            (numEleTmp < 0))) {
                  line_idx_2 += (div_nde_s32_floor(inIdx << 1, numEleTmp) + 1) >>
                    1;
                } else {
                  line_idx_2 -= (div_nde_s32_floor(-inIdx << 1, numEleTmp) + 1) >>
                    1;
                }

                gOffset = 0;
                b4 = true;
              } else {
                /* Violated CMax. */
                inIdx = (239 - gOffset) * i;
                if ((inIdx > 1073741824) || (inIdx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((inIdx >= 0) && (numEleTmp >= 0)) || ((inIdx < 0) &&
                            (numEleTmp < 0))) {
                  line_idx_2 += (div_nde_s32_floor(inIdx << 1, numEleTmp) + 1) >>
                    1;
                } else {
                  line_idx_2 -= (div_nde_s32_floor(-inIdx << 1, numEleTmp) + 1) >>
                    1;
                }

                gOffset = 239;
                b4 = true;
              }
            }
          }

          if (b2) {
            /* Draw a line using Bresenham algorithm. */
            /* Initialize the Bresenham algorithm. */
            if (line_idx_2 >= numIter) {
              outIdxAdj = line_idx_2 - numIter;
            } else {
              outIdxAdj = numIter - line_idx_2;
            }

            if (gOffset >= hOffset) {
              line_idx_3 = gOffset - hOffset;
            } else {
              line_idx_3 = hOffset - gOffset;
            }

            if (outIdxAdj > line_idx_3) {
              i = 1;
              numEleTmp = 320;
            } else {
              i = 320;
              numEleTmp = 1;
              inIdx = numIter;
              numIter = hOffset;
              hOffset = inIdx;
              inIdx = line_idx_2;
              line_idx_2 = gOffset;
              gOffset = inIdx;
            }

            if (numIter > line_idx_2) {
              inIdx = numIter;
              numIter = line_idx_2;
              line_idx_2 = inIdx;
              inIdx = hOffset;
              hOffset = gOffset;
              gOffset = inIdx;
            }

            inIdx = line_idx_2 - numIter;
            if (hOffset <= gOffset) {
              col = 1;
              outIdxAdj = gOffset - hOffset;
            } else {
              col = -1;
              outIdxAdj = hOffset - gOffset;
            }

            gOffset = -((inIdx + 1) >> 1);
            hOffset = numIter * i + hOffset * numEleTmp;
            rtB.row = col * numEleTmp + i;
            done = (numIter <= line_idx_2);
            while (done) {
              rtB.DrawShapes[hOffset] = MAX_uint8_T;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next pixel location. */
              gOffset += outIdxAdj;
              if (gOffset >= 0) {
                gOffset -= inIdx;
                hOffset += rtB.row;
              } else {
                hOffset += i;
              }

              numIter++;
              done = (numIter <= line_idx_2);
            }
          }
        }

        rtB.accumFour++;
      }
    }
  }

  /* End of S-Function (svipdrawshapes): '<Root>/Draw Shapes' */
  /* Start for MATLABSystem: '<S4>/MATLAB System' incorporates:
   *  MATLABSystem: '<S4>/MATLAB System'
   */
  memcpy(&rtB.Erosion[0], &rtB.DrawShapes[0], 76800U * sizeof(uint8_T));
  memcpy(&rtB.pln2[0], &rtB.DrawShapes[0], 76800U * sizeof(uint8_T));
  memcpy(&rtB.pln3[0], &rtB.DrawShapes[0], 76800U * sizeof(uint8_T));
  MW_SDL_videoDisplayOutput(rtB.Erosion, rtB.pln2, rtB.pln3);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    rtExtModeUpload(0, rtM->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
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
void lane_departure_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  rtM->Sizes.checksums[0] = (608052785U);
  rtM->Sizes.checksums[1] = (3207004011U);
  rtM->Sizes.checksums[2] = (243929478U);
  rtM->Sizes.checksums[3] = (1842160048U);

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

  /* block I/O */
  {
    rtB.HoughTransform_o2[0] = -1.5707963267948966;
    rtB.HoughTransform_o2[1] = -1.5533430342749532;
    rtB.HoughTransform_o2[2] = -1.53588974175501;
    rtB.HoughTransform_o2[3] = -1.5184364492350666;
    rtB.HoughTransform_o2[4] = -1.5009831567151235;
    rtB.HoughTransform_o2[5] = -1.4835298641951802;
    rtB.HoughTransform_o2[6] = -1.4660765716752369;
    rtB.HoughTransform_o2[7] = -1.4486232791552935;
    rtB.HoughTransform_o2[8] = -1.4311699866353502;
    rtB.HoughTransform_o2[9] = -1.4137166941154069;
    rtB.HoughTransform_o2[10] = -1.3962634015954636;
    rtB.HoughTransform_o2[11] = -1.3788101090755203;
    rtB.HoughTransform_o2[12] = -1.3613568165555769;
    rtB.HoughTransform_o2[13] = -1.3439035240356338;
    rtB.HoughTransform_o2[14] = -1.3264502315156905;
    rtB.HoughTransform_o2[15] = -1.3089969389957472;
    rtB.HoughTransform_o2[16] = -1.2915436464758039;
    rtB.HoughTransform_o2[17] = -1.2740903539558606;
    rtB.HoughTransform_o2[18] = -1.2566370614359172;
    rtB.HoughTransform_o2[19] = -1.2391837689159739;
    rtB.HoughTransform_o2[20] = -1.2217304763960306;
    rtB.HoughTransform_o2[21] = -1.2042771838760873;
    rtB.HoughTransform_o2[22] = -1.1868238913561442;
    rtB.HoughTransform_o2[23] = -1.1693705988362009;
    rtB.HoughTransform_o2[24] = -1.1519173063162575;
    rtB.HoughTransform_o2[25] = -1.1344640137963142;
    rtB.HoughTransform_o2[26] = -1.1170107212763709;
    rtB.HoughTransform_o2[27] = -1.0995574287564276;
    rtB.HoughTransform_o2[28] = -1.0821041362364843;
    rtB.HoughTransform_o2[29] = -1.064650843716541;
    rtB.HoughTransform_o2[30] = -1.0471975511965976;
    rtB.HoughTransform_o2[31] = -1.0297442586766545;
    rtB.HoughTransform_o2[32] = -1.0122909661567112;
    rtB.HoughTransform_o2[33] = -0.99483767363676789;
    rtB.HoughTransform_o2[34] = -0.97738438111682457;
    rtB.HoughTransform_o2[35] = -0.95993108859688125;
    rtB.HoughTransform_o2[36] = -0.94247779607693793;
    rtB.HoughTransform_o2[37] = -0.92502450355699462;
    rtB.HoughTransform_o2[38] = -0.90757121103705141;
    rtB.HoughTransform_o2[39] = -0.89011791851710809;
    rtB.HoughTransform_o2[40] = -0.87266462599716477;
    rtB.HoughTransform_o2[41] = -0.85521133347722145;
    rtB.HoughTransform_o2[42] = -0.83775804095727824;
    rtB.HoughTransform_o2[43] = -0.82030474843733492;
    rtB.HoughTransform_o2[44] = -0.8028514559173916;
    rtB.HoughTransform_o2[45] = -0.78539816339744828;
    rtB.HoughTransform_o2[46] = -0.767944870877505;
    rtB.HoughTransform_o2[47] = -0.75049157835756175;
    rtB.HoughTransform_o2[48] = -0.73303828583761843;
    rtB.HoughTransform_o2[49] = -0.71558499331767511;
    rtB.HoughTransform_o2[50] = -0.69813170079773179;
    rtB.HoughTransform_o2[51] = -0.68067840827778847;
    rtB.HoughTransform_o2[52] = -0.66322511575784526;
    rtB.HoughTransform_o2[53] = -0.64577182323790194;
    rtB.HoughTransform_o2[54] = -0.62831853071795862;
    rtB.HoughTransform_o2[55] = -0.6108652381980153;
    rtB.HoughTransform_o2[56] = -0.59341194567807209;
    rtB.HoughTransform_o2[57] = -0.57595865315812877;
    rtB.HoughTransform_o2[58] = -0.55850536063818546;
    rtB.HoughTransform_o2[59] = -0.54105206811824214;
    rtB.HoughTransform_o2[60] = -0.52359877559829882;
    rtB.HoughTransform_o2[61] = -0.50614548307835561;
    rtB.HoughTransform_o2[62] = -0.48869219055841229;
    rtB.HoughTransform_o2[63] = -0.47123889803846897;
    rtB.HoughTransform_o2[64] = -0.4537856055185257;
    rtB.HoughTransform_o2[65] = -0.43633231299858238;
    rtB.HoughTransform_o2[66] = -0.41887902047863912;
    rtB.HoughTransform_o2[67] = -0.4014257279586958;
    rtB.HoughTransform_o2[68] = -0.38397243543875248;
    rtB.HoughTransform_o2[69] = -0.36651914291880922;
    rtB.HoughTransform_o2[70] = -0.3490658503988659;
    rtB.HoughTransform_o2[71] = -0.33161255787892263;
    rtB.HoughTransform_o2[72] = -0.31415926535897931;
    rtB.HoughTransform_o2[73] = -0.29670597283903605;
    rtB.HoughTransform_o2[74] = -0.27925268031909273;
    rtB.HoughTransform_o2[75] = -0.26179938779914941;
    rtB.HoughTransform_o2[76] = -0.24434609527920614;
    rtB.HoughTransform_o2[77] = -0.22689280275926285;
    rtB.HoughTransform_o2[78] = -0.20943951023931956;
    rtB.HoughTransform_o2[79] = -0.19198621771937624;
    rtB.HoughTransform_o2[80] = -0.17453292519943295;
    rtB.HoughTransform_o2[81] = -0.15707963267948966;
    rtB.HoughTransform_o2[82] = -0.13962634015954636;
    rtB.HoughTransform_o2[83] = -0.12217304763960307;
    rtB.HoughTransform_o2[84] = -0.10471975511965978;
    rtB.HoughTransform_o2[85] = -0.087266462599716474;
    rtB.HoughTransform_o2[86] = -0.069813170079773182;
    rtB.HoughTransform_o2[87] = -0.05235987755982989;
    rtB.HoughTransform_o2[88] = -0.034906585039886591;
    rtB.HoughTransform_o2[89] = -0.017453292519943295;
    rtB.HoughTransform_o2[91] = 0.017453292519943295;
    rtB.HoughTransform_o2[92] = 0.034906585039886591;
    rtB.HoughTransform_o2[93] = 0.05235987755982989;
    rtB.HoughTransform_o2[94] = 0.069813170079773182;
    rtB.HoughTransform_o2[95] = 0.087266462599716474;
    rtB.HoughTransform_o2[96] = 0.10471975511965978;
    rtB.HoughTransform_o2[97] = 0.12217304763960307;
    rtB.HoughTransform_o2[98] = 0.13962634015954636;
    rtB.HoughTransform_o2[99] = 0.15707963267948966;
    rtB.HoughTransform_o2[100] = 0.17453292519943295;
    rtB.HoughTransform_o2[101] = 0.19198621771937624;
    rtB.HoughTransform_o2[102] = 0.20943951023931956;
    rtB.HoughTransform_o2[103] = 0.22689280275926285;
    rtB.HoughTransform_o2[104] = 0.24434609527920614;
    rtB.HoughTransform_o2[105] = 0.26179938779914941;
    rtB.HoughTransform_o2[106] = 0.27925268031909273;
    rtB.HoughTransform_o2[107] = 0.29670597283903605;
    rtB.HoughTransform_o2[108] = 0.31415926535897931;
    rtB.HoughTransform_o2[109] = 0.33161255787892263;
    rtB.HoughTransform_o2[110] = 0.3490658503988659;
    rtB.HoughTransform_o2[111] = 0.36651914291880922;
    rtB.HoughTransform_o2[112] = 0.38397243543875248;
    rtB.HoughTransform_o2[113] = 0.4014257279586958;
    rtB.HoughTransform_o2[114] = 0.41887902047863912;
    rtB.HoughTransform_o2[115] = 0.43633231299858238;
    rtB.HoughTransform_o2[116] = 0.4537856055185257;
    rtB.HoughTransform_o2[117] = 0.47123889803846897;
    rtB.HoughTransform_o2[118] = 0.48869219055841229;
    rtB.HoughTransform_o2[119] = 0.50614548307835561;
    rtB.HoughTransform_o2[120] = 0.52359877559829882;
    rtB.HoughTransform_o2[121] = 0.54105206811824214;
    rtB.HoughTransform_o2[122] = 0.55850536063818546;
    rtB.HoughTransform_o2[123] = 0.57595865315812877;
    rtB.HoughTransform_o2[124] = 0.59341194567807209;
    rtB.HoughTransform_o2[125] = 0.6108652381980153;
    rtB.HoughTransform_o2[126] = 0.62831853071795862;
    rtB.HoughTransform_o2[127] = 0.64577182323790194;
    rtB.HoughTransform_o2[128] = 0.66322511575784526;
    rtB.HoughTransform_o2[129] = 0.68067840827778847;
    rtB.HoughTransform_o2[130] = 0.69813170079773179;
    rtB.HoughTransform_o2[131] = 0.71558499331767511;
    rtB.HoughTransform_o2[132] = 0.73303828583761843;
    rtB.HoughTransform_o2[133] = 0.75049157835756175;
    rtB.HoughTransform_o2[134] = 0.767944870877505;
    rtB.HoughTransform_o2[135] = 0.78539816339744828;
    rtB.HoughTransform_o2[136] = 0.8028514559173916;
    rtB.HoughTransform_o2[137] = 0.82030474843733492;
    rtB.HoughTransform_o2[138] = 0.83775804095727824;
    rtB.HoughTransform_o2[139] = 0.85521133347722145;
    rtB.HoughTransform_o2[140] = 0.87266462599716477;
    rtB.HoughTransform_o2[141] = 0.89011791851710809;
    rtB.HoughTransform_o2[142] = 0.90757121103705141;
    rtB.HoughTransform_o2[143] = 0.92502450355699462;
    rtB.HoughTransform_o2[144] = 0.94247779607693793;
    rtB.HoughTransform_o2[145] = 0.95993108859688125;
    rtB.HoughTransform_o2[146] = 0.97738438111682457;
    rtB.HoughTransform_o2[147] = 0.99483767363676789;
    rtB.HoughTransform_o2[148] = 1.0122909661567112;
    rtB.HoughTransform_o2[149] = 1.0297442586766545;
    rtB.HoughTransform_o2[150] = 1.0471975511965976;
    rtB.HoughTransform_o2[151] = 1.064650843716541;
    rtB.HoughTransform_o2[152] = 1.0821041362364843;
    rtB.HoughTransform_o2[153] = 1.0995574287564276;
    rtB.HoughTransform_o2[154] = 1.1170107212763709;
    rtB.HoughTransform_o2[155] = 1.1344640137963142;
    rtB.HoughTransform_o2[156] = 1.1519173063162575;
    rtB.HoughTransform_o2[157] = 1.1693705988362009;
    rtB.HoughTransform_o2[158] = 1.1868238913561442;
    rtB.HoughTransform_o2[159] = 1.2042771838760873;
    rtB.HoughTransform_o2[160] = 1.2217304763960306;
    rtB.HoughTransform_o2[161] = 1.2391837689159739;
    rtB.HoughTransform_o2[162] = 1.2566370614359172;
    rtB.HoughTransform_o2[163] = 1.2740903539558606;
    rtB.HoughTransform_o2[164] = 1.2915436464758039;
    rtB.HoughTransform_o2[165] = 1.3089969389957472;
    rtB.HoughTransform_o2[166] = 1.3264502315156905;
    rtB.HoughTransform_o2[167] = 1.3439035240356338;
    rtB.HoughTransform_o2[168] = 1.3613568165555769;
    rtB.HoughTransform_o2[169] = 1.3788101090755203;
    rtB.HoughTransform_o2[170] = 1.3962634015954636;
    rtB.HoughTransform_o2[171] = 1.4137166941154069;
    rtB.HoughTransform_o2[172] = 1.4311699866353502;
    rtB.HoughTransform_o2[173] = 1.4486232791552935;
    rtB.HoughTransform_o2[174] = 1.4660765716752369;
    rtB.HoughTransform_o2[175] = 1.4835298641951802;
    rtB.HoughTransform_o2[176] = 1.5009831567151235;
    rtB.HoughTransform_o2[177] = 1.5184364492350666;
    rtB.HoughTransform_o2[178] = 1.53588974175501;
    rtB.HoughTransform_o2[179] = 1.5533430342749532;
    rtB.HoughTransform_o3[0] = -399.0;
    rtB.HoughTransform_o3[1] = -398.0;
    rtB.HoughTransform_o3[2] = -397.0;
    rtB.HoughTransform_o3[3] = -396.0;
    rtB.HoughTransform_o3[4] = -395.0;
    rtB.HoughTransform_o3[5] = -394.0;
    rtB.HoughTransform_o3[6] = -393.0;
    rtB.HoughTransform_o3[7] = -392.0;
    rtB.HoughTransform_o3[8] = -391.0;
    rtB.HoughTransform_o3[9] = -390.0;
    rtB.HoughTransform_o3[10] = -389.0;
    rtB.HoughTransform_o3[11] = -388.0;
    rtB.HoughTransform_o3[12] = -387.0;
    rtB.HoughTransform_o3[13] = -386.0;
    rtB.HoughTransform_o3[14] = -385.0;
    rtB.HoughTransform_o3[15] = -384.0;
    rtB.HoughTransform_o3[16] = -383.0;
    rtB.HoughTransform_o3[17] = -382.0;
    rtB.HoughTransform_o3[18] = -381.0;
    rtB.HoughTransform_o3[19] = -380.0;
    rtB.HoughTransform_o3[20] = -379.0;
    rtB.HoughTransform_o3[21] = -378.0;
    rtB.HoughTransform_o3[22] = -377.0;
    rtB.HoughTransform_o3[23] = -376.0;
    rtB.HoughTransform_o3[24] = -375.0;
    rtB.HoughTransform_o3[25] = -374.0;
    rtB.HoughTransform_o3[26] = -373.0;
    rtB.HoughTransform_o3[27] = -372.0;
    rtB.HoughTransform_o3[28] = -371.0;
    rtB.HoughTransform_o3[29] = -370.0;
    rtB.HoughTransform_o3[30] = -369.0;
    rtB.HoughTransform_o3[31] = -368.0;
    rtB.HoughTransform_o3[32] = -367.0;
    rtB.HoughTransform_o3[33] = -366.0;
    rtB.HoughTransform_o3[34] = -365.0;
    rtB.HoughTransform_o3[35] = -364.0;
    rtB.HoughTransform_o3[36] = -363.0;
    rtB.HoughTransform_o3[37] = -362.0;
    rtB.HoughTransform_o3[38] = -361.0;
    rtB.HoughTransform_o3[39] = -360.0;
    rtB.HoughTransform_o3[40] = -359.0;
    rtB.HoughTransform_o3[41] = -358.0;
    rtB.HoughTransform_o3[42] = -357.0;
    rtB.HoughTransform_o3[43] = -356.0;
    rtB.HoughTransform_o3[44] = -355.0;
    rtB.HoughTransform_o3[45] = -354.0;
    rtB.HoughTransform_o3[46] = -353.0;
    rtB.HoughTransform_o3[47] = -352.0;
    rtB.HoughTransform_o3[48] = -351.0;
    rtB.HoughTransform_o3[49] = -350.0;
    rtB.HoughTransform_o3[50] = -349.0;
    rtB.HoughTransform_o3[51] = -348.0;
    rtB.HoughTransform_o3[52] = -347.0;
    rtB.HoughTransform_o3[53] = -346.0;
    rtB.HoughTransform_o3[54] = -345.0;
    rtB.HoughTransform_o3[55] = -344.0;
    rtB.HoughTransform_o3[56] = -343.0;
    rtB.HoughTransform_o3[57] = -342.0;
    rtB.HoughTransform_o3[58] = -341.0;
    rtB.HoughTransform_o3[59] = -340.0;
    rtB.HoughTransform_o3[60] = -339.0;
    rtB.HoughTransform_o3[61] = -338.0;
    rtB.HoughTransform_o3[62] = -337.0;
    rtB.HoughTransform_o3[63] = -336.0;
    rtB.HoughTransform_o3[64] = -335.0;
    rtB.HoughTransform_o3[65] = -334.0;
    rtB.HoughTransform_o3[66] = -333.0;
    rtB.HoughTransform_o3[67] = -332.0;
    rtB.HoughTransform_o3[68] = -331.0;
    rtB.HoughTransform_o3[69] = -330.0;
    rtB.HoughTransform_o3[70] = -329.0;
    rtB.HoughTransform_o3[71] = -328.0;
    rtB.HoughTransform_o3[72] = -327.0;
    rtB.HoughTransform_o3[73] = -326.0;
    rtB.HoughTransform_o3[74] = -325.0;
    rtB.HoughTransform_o3[75] = -324.0;
    rtB.HoughTransform_o3[76] = -323.0;
    rtB.HoughTransform_o3[77] = -322.0;
    rtB.HoughTransform_o3[78] = -321.0;
    rtB.HoughTransform_o3[79] = -320.0;
    rtB.HoughTransform_o3[80] = -319.0;
    rtB.HoughTransform_o3[81] = -318.0;
    rtB.HoughTransform_o3[82] = -317.0;
    rtB.HoughTransform_o3[83] = -316.0;
    rtB.HoughTransform_o3[84] = -315.0;
    rtB.HoughTransform_o3[85] = -314.0;
    rtB.HoughTransform_o3[86] = -313.0;
    rtB.HoughTransform_o3[87] = -312.0;
    rtB.HoughTransform_o3[88] = -311.0;
    rtB.HoughTransform_o3[89] = -310.0;
    rtB.HoughTransform_o3[90] = -309.0;
    rtB.HoughTransform_o3[91] = -308.0;
    rtB.HoughTransform_o3[92] = -307.0;
    rtB.HoughTransform_o3[93] = -306.0;
    rtB.HoughTransform_o3[94] = -305.0;
    rtB.HoughTransform_o3[95] = -304.0;
    rtB.HoughTransform_o3[96] = -303.0;
    rtB.HoughTransform_o3[97] = -302.0;
    rtB.HoughTransform_o3[98] = -301.0;
    rtB.HoughTransform_o3[99] = -300.0;
    rtB.HoughTransform_o3[100] = -299.0;
    rtB.HoughTransform_o3[101] = -298.0;
    rtB.HoughTransform_o3[102] = -297.0;
    rtB.HoughTransform_o3[103] = -296.0;
    rtB.HoughTransform_o3[104] = -295.0;
    rtB.HoughTransform_o3[105] = -294.0;
    rtB.HoughTransform_o3[106] = -293.0;
    rtB.HoughTransform_o3[107] = -292.0;
    rtB.HoughTransform_o3[108] = -291.0;
    rtB.HoughTransform_o3[109] = -290.0;
    rtB.HoughTransform_o3[110] = -289.0;
    rtB.HoughTransform_o3[111] = -288.0;
    rtB.HoughTransform_o3[112] = -287.0;
    rtB.HoughTransform_o3[113] = -286.0;
    rtB.HoughTransform_o3[114] = -285.0;
    rtB.HoughTransform_o3[115] = -284.0;
    rtB.HoughTransform_o3[116] = -283.0;
    rtB.HoughTransform_o3[117] = -282.0;
    rtB.HoughTransform_o3[118] = -281.0;
    rtB.HoughTransform_o3[119] = -280.0;
    rtB.HoughTransform_o3[120] = -279.0;
    rtB.HoughTransform_o3[121] = -278.0;
    rtB.HoughTransform_o3[122] = -277.0;
    rtB.HoughTransform_o3[123] = -276.0;
    rtB.HoughTransform_o3[124] = -275.0;
    rtB.HoughTransform_o3[125] = -274.0;
    rtB.HoughTransform_o3[126] = -273.0;
    rtB.HoughTransform_o3[127] = -272.0;
    rtB.HoughTransform_o3[128] = -271.0;
    rtB.HoughTransform_o3[129] = -270.0;
    rtB.HoughTransform_o3[130] = -269.0;
    rtB.HoughTransform_o3[131] = -268.0;
    rtB.HoughTransform_o3[132] = -267.0;
    rtB.HoughTransform_o3[133] = -266.0;
    rtB.HoughTransform_o3[134] = -265.0;
    rtB.HoughTransform_o3[135] = -264.0;
    rtB.HoughTransform_o3[136] = -263.0;
    rtB.HoughTransform_o3[137] = -262.0;
    rtB.HoughTransform_o3[138] = -261.0;
    rtB.HoughTransform_o3[139] = -260.0;
    rtB.HoughTransform_o3[140] = -259.0;
    rtB.HoughTransform_o3[141] = -258.0;
    rtB.HoughTransform_o3[142] = -257.0;
    rtB.HoughTransform_o3[143] = -256.0;
    rtB.HoughTransform_o3[144] = -255.0;
    rtB.HoughTransform_o3[145] = -254.0;
    rtB.HoughTransform_o3[146] = -253.0;
    rtB.HoughTransform_o3[147] = -252.0;
    rtB.HoughTransform_o3[148] = -251.0;
    rtB.HoughTransform_o3[149] = -250.0;
    rtB.HoughTransform_o3[150] = -249.0;
    rtB.HoughTransform_o3[151] = -248.0;
    rtB.HoughTransform_o3[152] = -247.0;
    rtB.HoughTransform_o3[153] = -246.0;
    rtB.HoughTransform_o3[154] = -245.0;
    rtB.HoughTransform_o3[155] = -244.0;
    rtB.HoughTransform_o3[156] = -243.0;
    rtB.HoughTransform_o3[157] = -242.0;
    rtB.HoughTransform_o3[158] = -241.0;
    rtB.HoughTransform_o3[159] = -240.0;
    rtB.HoughTransform_o3[160] = -239.0;
    rtB.HoughTransform_o3[161] = -238.0;
    rtB.HoughTransform_o3[162] = -237.0;
    rtB.HoughTransform_o3[163] = -236.0;
    rtB.HoughTransform_o3[164] = -235.0;
    rtB.HoughTransform_o3[165] = -234.0;
    rtB.HoughTransform_o3[166] = -233.0;
    rtB.HoughTransform_o3[167] = -232.0;
    rtB.HoughTransform_o3[168] = -231.0;
    rtB.HoughTransform_o3[169] = -230.0;
    rtB.HoughTransform_o3[170] = -229.0;
    rtB.HoughTransform_o3[171] = -228.0;
    rtB.HoughTransform_o3[172] = -227.0;
    rtB.HoughTransform_o3[173] = -226.0;
    rtB.HoughTransform_o3[174] = -225.0;
    rtB.HoughTransform_o3[175] = -224.0;
    rtB.HoughTransform_o3[176] = -223.0;
    rtB.HoughTransform_o3[177] = -222.0;
    rtB.HoughTransform_o3[178] = -221.0;
    rtB.HoughTransform_o3[179] = -220.0;
    rtB.HoughTransform_o3[180] = -219.0;
    rtB.HoughTransform_o3[181] = -218.0;
    rtB.HoughTransform_o3[182] = -217.0;
    rtB.HoughTransform_o3[183] = -216.0;
    rtB.HoughTransform_o3[184] = -215.0;
    rtB.HoughTransform_o3[185] = -214.0;
    rtB.HoughTransform_o3[186] = -213.0;
    rtB.HoughTransform_o3[187] = -212.0;
    rtB.HoughTransform_o3[188] = -211.0;
    rtB.HoughTransform_o3[189] = -210.0;
    rtB.HoughTransform_o3[190] = -209.0;
    rtB.HoughTransform_o3[191] = -208.0;
    rtB.HoughTransform_o3[192] = -207.0;
    rtB.HoughTransform_o3[193] = -206.0;
    rtB.HoughTransform_o3[194] = -205.0;
    rtB.HoughTransform_o3[195] = -204.0;
    rtB.HoughTransform_o3[196] = -203.0;
    rtB.HoughTransform_o3[197] = -202.0;
    rtB.HoughTransform_o3[198] = -201.0;
    rtB.HoughTransform_o3[199] = -200.0;
    rtB.HoughTransform_o3[200] = -199.0;
    rtB.HoughTransform_o3[201] = -198.0;
    rtB.HoughTransform_o3[202] = -197.0;
    rtB.HoughTransform_o3[203] = -196.0;
    rtB.HoughTransform_o3[204] = -195.0;
    rtB.HoughTransform_o3[205] = -194.0;
    rtB.HoughTransform_o3[206] = -193.0;
    rtB.HoughTransform_o3[207] = -192.0;
    rtB.HoughTransform_o3[208] = -191.0;
    rtB.HoughTransform_o3[209] = -190.0;
    rtB.HoughTransform_o3[210] = -189.0;
    rtB.HoughTransform_o3[211] = -188.0;
    rtB.HoughTransform_o3[212] = -187.0;
    rtB.HoughTransform_o3[213] = -186.0;
    rtB.HoughTransform_o3[214] = -185.0;
    rtB.HoughTransform_o3[215] = -184.0;
    rtB.HoughTransform_o3[216] = -183.0;
    rtB.HoughTransform_o3[217] = -182.0;
    rtB.HoughTransform_o3[218] = -181.0;
    rtB.HoughTransform_o3[219] = -180.0;
    rtB.HoughTransform_o3[220] = -179.0;
    rtB.HoughTransform_o3[221] = -178.0;
    rtB.HoughTransform_o3[222] = -177.0;
    rtB.HoughTransform_o3[223] = -176.0;
    rtB.HoughTransform_o3[224] = -175.0;
    rtB.HoughTransform_o3[225] = -174.0;
    rtB.HoughTransform_o3[226] = -173.0;
    rtB.HoughTransform_o3[227] = -172.0;
    rtB.HoughTransform_o3[228] = -171.0;
    rtB.HoughTransform_o3[229] = -170.0;
    rtB.HoughTransform_o3[230] = -169.0;
    rtB.HoughTransform_o3[231] = -168.0;
    rtB.HoughTransform_o3[232] = -167.0;
    rtB.HoughTransform_o3[233] = -166.0;
    rtB.HoughTransform_o3[234] = -165.0;
    rtB.HoughTransform_o3[235] = -164.0;
    rtB.HoughTransform_o3[236] = -163.0;
    rtB.HoughTransform_o3[237] = -162.0;
    rtB.HoughTransform_o3[238] = -161.0;
    rtB.HoughTransform_o3[239] = -160.0;
    rtB.HoughTransform_o3[240] = -159.0;
    rtB.HoughTransform_o3[241] = -158.0;
    rtB.HoughTransform_o3[242] = -157.0;
    rtB.HoughTransform_o3[243] = -156.0;
    rtB.HoughTransform_o3[244] = -155.0;
    rtB.HoughTransform_o3[245] = -154.0;
    rtB.HoughTransform_o3[246] = -153.0;
    rtB.HoughTransform_o3[247] = -152.0;
    rtB.HoughTransform_o3[248] = -151.0;
    rtB.HoughTransform_o3[249] = -150.0;
    rtB.HoughTransform_o3[250] = -149.0;
    rtB.HoughTransform_o3[251] = -148.0;
    rtB.HoughTransform_o3[252] = -147.0;
    rtB.HoughTransform_o3[253] = -146.0;
    rtB.HoughTransform_o3[254] = -145.0;
    rtB.HoughTransform_o3[255] = -144.0;
    rtB.HoughTransform_o3[256] = -143.0;
    rtB.HoughTransform_o3[257] = -142.0;
    rtB.HoughTransform_o3[258] = -141.0;
    rtB.HoughTransform_o3[259] = -140.0;
    rtB.HoughTransform_o3[260] = -139.0;
    rtB.HoughTransform_o3[261] = -138.0;
    rtB.HoughTransform_o3[262] = -137.0;
    rtB.HoughTransform_o3[263] = -136.0;
    rtB.HoughTransform_o3[264] = -135.0;
    rtB.HoughTransform_o3[265] = -134.0;
    rtB.HoughTransform_o3[266] = -133.0;
    rtB.HoughTransform_o3[267] = -132.0;
    rtB.HoughTransform_o3[268] = -131.0;
    rtB.HoughTransform_o3[269] = -130.0;
    rtB.HoughTransform_o3[270] = -129.0;
    rtB.HoughTransform_o3[271] = -128.0;
    rtB.HoughTransform_o3[272] = -127.0;
    rtB.HoughTransform_o3[273] = -126.0;
    rtB.HoughTransform_o3[274] = -125.0;
    rtB.HoughTransform_o3[275] = -124.0;
    rtB.HoughTransform_o3[276] = -123.0;
    rtB.HoughTransform_o3[277] = -122.0;
    rtB.HoughTransform_o3[278] = -121.0;
    rtB.HoughTransform_o3[279] = -120.0;
    rtB.HoughTransform_o3[280] = -119.0;
    rtB.HoughTransform_o3[281] = -118.0;
    rtB.HoughTransform_o3[282] = -117.0;
    rtB.HoughTransform_o3[283] = -116.0;
    rtB.HoughTransform_o3[284] = -115.0;
    rtB.HoughTransform_o3[285] = -114.0;
    rtB.HoughTransform_o3[286] = -113.0;
    rtB.HoughTransform_o3[287] = -112.0;
    rtB.HoughTransform_o3[288] = -111.0;
    rtB.HoughTransform_o3[289] = -110.0;
    rtB.HoughTransform_o3[290] = -109.0;
    rtB.HoughTransform_o3[291] = -108.0;
    rtB.HoughTransform_o3[292] = -107.0;
    rtB.HoughTransform_o3[293] = -106.0;
    rtB.HoughTransform_o3[294] = -105.0;
    rtB.HoughTransform_o3[295] = -104.0;
    rtB.HoughTransform_o3[296] = -103.0;
    rtB.HoughTransform_o3[297] = -102.0;
    rtB.HoughTransform_o3[298] = -101.0;
    rtB.HoughTransform_o3[299] = -100.0;
    rtB.HoughTransform_o3[300] = -99.0;
    rtB.HoughTransform_o3[301] = -98.0;
    rtB.HoughTransform_o3[302] = -97.0;
    rtB.HoughTransform_o3[303] = -96.0;
    rtB.HoughTransform_o3[304] = -95.0;
    rtB.HoughTransform_o3[305] = -94.0;
    rtB.HoughTransform_o3[306] = -93.0;
    rtB.HoughTransform_o3[307] = -92.0;
    rtB.HoughTransform_o3[308] = -91.0;
    rtB.HoughTransform_o3[309] = -90.0;
    rtB.HoughTransform_o3[310] = -89.0;
    rtB.HoughTransform_o3[311] = -88.0;
    rtB.HoughTransform_o3[312] = -87.0;
    rtB.HoughTransform_o3[313] = -86.0;
    rtB.HoughTransform_o3[314] = -85.0;
    rtB.HoughTransform_o3[315] = -84.0;
    rtB.HoughTransform_o3[316] = -83.0;
    rtB.HoughTransform_o3[317] = -82.0;
    rtB.HoughTransform_o3[318] = -81.0;
    rtB.HoughTransform_o3[319] = -80.0;
    rtB.HoughTransform_o3[320] = -79.0;
    rtB.HoughTransform_o3[321] = -78.0;
    rtB.HoughTransform_o3[322] = -77.0;
    rtB.HoughTransform_o3[323] = -76.0;
    rtB.HoughTransform_o3[324] = -75.0;
    rtB.HoughTransform_o3[325] = -74.0;
    rtB.HoughTransform_o3[326] = -73.0;
    rtB.HoughTransform_o3[327] = -72.0;
    rtB.HoughTransform_o3[328] = -71.0;
    rtB.HoughTransform_o3[329] = -70.0;
    rtB.HoughTransform_o3[330] = -69.0;
    rtB.HoughTransform_o3[331] = -68.0;
    rtB.HoughTransform_o3[332] = -67.0;
    rtB.HoughTransform_o3[333] = -66.0;
    rtB.HoughTransform_o3[334] = -65.0;
    rtB.HoughTransform_o3[335] = -64.0;
    rtB.HoughTransform_o3[336] = -63.0;
    rtB.HoughTransform_o3[337] = -62.0;
    rtB.HoughTransform_o3[338] = -61.0;
    rtB.HoughTransform_o3[339] = -60.0;
    rtB.HoughTransform_o3[340] = -59.0;
    rtB.HoughTransform_o3[341] = -58.0;
    rtB.HoughTransform_o3[342] = -57.0;
    rtB.HoughTransform_o3[343] = -56.0;
    rtB.HoughTransform_o3[344] = -55.0;
    rtB.HoughTransform_o3[345] = -54.0;
    rtB.HoughTransform_o3[346] = -53.0;
    rtB.HoughTransform_o3[347] = -52.0;
    rtB.HoughTransform_o3[348] = -51.0;
    rtB.HoughTransform_o3[349] = -50.0;
    rtB.HoughTransform_o3[350] = -49.0;
    rtB.HoughTransform_o3[351] = -48.0;
    rtB.HoughTransform_o3[352] = -47.0;
    rtB.HoughTransform_o3[353] = -46.0;
    rtB.HoughTransform_o3[354] = -45.0;
    rtB.HoughTransform_o3[355] = -44.0;
    rtB.HoughTransform_o3[356] = -43.0;
    rtB.HoughTransform_o3[357] = -42.0;
    rtB.HoughTransform_o3[358] = -41.0;
    rtB.HoughTransform_o3[359] = -40.0;
    rtB.HoughTransform_o3[360] = -39.0;
    rtB.HoughTransform_o3[361] = -38.0;
    rtB.HoughTransform_o3[362] = -37.0;
    rtB.HoughTransform_o3[363] = -36.0;
    rtB.HoughTransform_o3[364] = -35.0;
    rtB.HoughTransform_o3[365] = -34.0;
    rtB.HoughTransform_o3[366] = -33.0;
    rtB.HoughTransform_o3[367] = -32.0;
    rtB.HoughTransform_o3[368] = -31.0;
    rtB.HoughTransform_o3[369] = -30.0;
    rtB.HoughTransform_o3[370] = -29.0;
    rtB.HoughTransform_o3[371] = -28.0;
    rtB.HoughTransform_o3[372] = -27.0;
    rtB.HoughTransform_o3[373] = -26.0;
    rtB.HoughTransform_o3[374] = -25.0;
    rtB.HoughTransform_o3[375] = -24.0;
    rtB.HoughTransform_o3[376] = -23.0;
    rtB.HoughTransform_o3[377] = -22.0;
    rtB.HoughTransform_o3[378] = -21.0;
    rtB.HoughTransform_o3[379] = -20.0;
    rtB.HoughTransform_o3[380] = -19.0;
    rtB.HoughTransform_o3[381] = -18.0;
    rtB.HoughTransform_o3[382] = -17.0;
    rtB.HoughTransform_o3[383] = -16.0;
    rtB.HoughTransform_o3[384] = -15.0;
    rtB.HoughTransform_o3[385] = -14.0;
    rtB.HoughTransform_o3[386] = -13.0;
    rtB.HoughTransform_o3[387] = -12.0;
    rtB.HoughTransform_o3[388] = -11.0;
    rtB.HoughTransform_o3[389] = -10.0;
    rtB.HoughTransform_o3[390] = -9.0;
    rtB.HoughTransform_o3[391] = -8.0;
    rtB.HoughTransform_o3[392] = -7.0;
    rtB.HoughTransform_o3[393] = -6.0;
    rtB.HoughTransform_o3[394] = -5.0;
    rtB.HoughTransform_o3[395] = -4.0;
    rtB.HoughTransform_o3[396] = -3.0;
    rtB.HoughTransform_o3[397] = -2.0;
    rtB.HoughTransform_o3[398] = -1.0;
    rtB.HoughTransform_o3[400] = 1.0;
    rtB.HoughTransform_o3[401] = 2.0;
    rtB.HoughTransform_o3[402] = 3.0;
    rtB.HoughTransform_o3[403] = 4.0;
    rtB.HoughTransform_o3[404] = 5.0;
    rtB.HoughTransform_o3[405] = 6.0;
    rtB.HoughTransform_o3[406] = 7.0;
    rtB.HoughTransform_o3[407] = 8.0;
    rtB.HoughTransform_o3[408] = 9.0;
    rtB.HoughTransform_o3[409] = 10.0;
    rtB.HoughTransform_o3[410] = 11.0;
    rtB.HoughTransform_o3[411] = 12.0;
    rtB.HoughTransform_o3[412] = 13.0;
    rtB.HoughTransform_o3[413] = 14.0;
    rtB.HoughTransform_o3[414] = 15.0;
    rtB.HoughTransform_o3[415] = 16.0;
    rtB.HoughTransform_o3[416] = 17.0;
    rtB.HoughTransform_o3[417] = 18.0;
    rtB.HoughTransform_o3[418] = 19.0;
    rtB.HoughTransform_o3[419] = 20.0;
    rtB.HoughTransform_o3[420] = 21.0;
    rtB.HoughTransform_o3[421] = 22.0;
    rtB.HoughTransform_o3[422] = 23.0;
    rtB.HoughTransform_o3[423] = 24.0;
    rtB.HoughTransform_o3[424] = 25.0;
    rtB.HoughTransform_o3[425] = 26.0;
    rtB.HoughTransform_o3[426] = 27.0;
    rtB.HoughTransform_o3[427] = 28.0;
    rtB.HoughTransform_o3[428] = 29.0;
    rtB.HoughTransform_o3[429] = 30.0;
    rtB.HoughTransform_o3[430] = 31.0;
    rtB.HoughTransform_o3[431] = 32.0;
    rtB.HoughTransform_o3[432] = 33.0;
    rtB.HoughTransform_o3[433] = 34.0;
    rtB.HoughTransform_o3[434] = 35.0;
    rtB.HoughTransform_o3[435] = 36.0;
    rtB.HoughTransform_o3[436] = 37.0;
    rtB.HoughTransform_o3[437] = 38.0;
    rtB.HoughTransform_o3[438] = 39.0;
    rtB.HoughTransform_o3[439] = 40.0;
    rtB.HoughTransform_o3[440] = 41.0;
    rtB.HoughTransform_o3[441] = 42.0;
    rtB.HoughTransform_o3[442] = 43.0;
    rtB.HoughTransform_o3[443] = 44.0;
    rtB.HoughTransform_o3[444] = 45.0;
    rtB.HoughTransform_o3[445] = 46.0;
    rtB.HoughTransform_o3[446] = 47.0;
    rtB.HoughTransform_o3[447] = 48.0;
    rtB.HoughTransform_o3[448] = 49.0;
    rtB.HoughTransform_o3[449] = 50.0;
    rtB.HoughTransform_o3[450] = 51.0;
    rtB.HoughTransform_o3[451] = 52.0;
    rtB.HoughTransform_o3[452] = 53.0;
    rtB.HoughTransform_o3[453] = 54.0;
    rtB.HoughTransform_o3[454] = 55.0;
    rtB.HoughTransform_o3[455] = 56.0;
    rtB.HoughTransform_o3[456] = 57.0;
    rtB.HoughTransform_o3[457] = 58.0;
    rtB.HoughTransform_o3[458] = 59.0;
    rtB.HoughTransform_o3[459] = 60.0;
    rtB.HoughTransform_o3[460] = 61.0;
    rtB.HoughTransform_o3[461] = 62.0;
    rtB.HoughTransform_o3[462] = 63.0;
    rtB.HoughTransform_o3[463] = 64.0;
    rtB.HoughTransform_o3[464] = 65.0;
    rtB.HoughTransform_o3[465] = 66.0;
    rtB.HoughTransform_o3[466] = 67.0;
    rtB.HoughTransform_o3[467] = 68.0;
    rtB.HoughTransform_o3[468] = 69.0;
    rtB.HoughTransform_o3[469] = 70.0;
    rtB.HoughTransform_o3[470] = 71.0;
    rtB.HoughTransform_o3[471] = 72.0;
    rtB.HoughTransform_o3[472] = 73.0;
    rtB.HoughTransform_o3[473] = 74.0;
    rtB.HoughTransform_o3[474] = 75.0;
    rtB.HoughTransform_o3[475] = 76.0;
    rtB.HoughTransform_o3[476] = 77.0;
    rtB.HoughTransform_o3[477] = 78.0;
    rtB.HoughTransform_o3[478] = 79.0;
    rtB.HoughTransform_o3[479] = 80.0;
    rtB.HoughTransform_o3[480] = 81.0;
    rtB.HoughTransform_o3[481] = 82.0;
    rtB.HoughTransform_o3[482] = 83.0;
    rtB.HoughTransform_o3[483] = 84.0;
    rtB.HoughTransform_o3[484] = 85.0;
    rtB.HoughTransform_o3[485] = 86.0;
    rtB.HoughTransform_o3[486] = 87.0;
    rtB.HoughTransform_o3[487] = 88.0;
    rtB.HoughTransform_o3[488] = 89.0;
    rtB.HoughTransform_o3[489] = 90.0;
    rtB.HoughTransform_o3[490] = 91.0;
    rtB.HoughTransform_o3[491] = 92.0;
    rtB.HoughTransform_o3[492] = 93.0;
    rtB.HoughTransform_o3[493] = 94.0;
    rtB.HoughTransform_o3[494] = 95.0;
    rtB.HoughTransform_o3[495] = 96.0;
    rtB.HoughTransform_o3[496] = 97.0;
    rtB.HoughTransform_o3[497] = 98.0;
    rtB.HoughTransform_o3[498] = 99.0;
    rtB.HoughTransform_o3[499] = 100.0;
    rtB.HoughTransform_o3[500] = 101.0;
    rtB.HoughTransform_o3[501] = 102.0;
    rtB.HoughTransform_o3[502] = 103.0;
    rtB.HoughTransform_o3[503] = 104.0;
    rtB.HoughTransform_o3[504] = 105.0;
    rtB.HoughTransform_o3[505] = 106.0;
    rtB.HoughTransform_o3[506] = 107.0;
    rtB.HoughTransform_o3[507] = 108.0;
    rtB.HoughTransform_o3[508] = 109.0;
    rtB.HoughTransform_o3[509] = 110.0;
    rtB.HoughTransform_o3[510] = 111.0;
    rtB.HoughTransform_o3[511] = 112.0;
    rtB.HoughTransform_o3[512] = 113.0;
    rtB.HoughTransform_o3[513] = 114.0;
    rtB.HoughTransform_o3[514] = 115.0;
    rtB.HoughTransform_o3[515] = 116.0;
    rtB.HoughTransform_o3[516] = 117.0;
    rtB.HoughTransform_o3[517] = 118.0;
    rtB.HoughTransform_o3[518] = 119.0;
    rtB.HoughTransform_o3[519] = 120.0;
    rtB.HoughTransform_o3[520] = 121.0;
    rtB.HoughTransform_o3[521] = 122.0;
    rtB.HoughTransform_o3[522] = 123.0;
    rtB.HoughTransform_o3[523] = 124.0;
    rtB.HoughTransform_o3[524] = 125.0;
    rtB.HoughTransform_o3[525] = 126.0;
    rtB.HoughTransform_o3[526] = 127.0;
    rtB.HoughTransform_o3[527] = 128.0;
    rtB.HoughTransform_o3[528] = 129.0;
    rtB.HoughTransform_o3[529] = 130.0;
    rtB.HoughTransform_o3[530] = 131.0;
    rtB.HoughTransform_o3[531] = 132.0;
    rtB.HoughTransform_o3[532] = 133.0;
    rtB.HoughTransform_o3[533] = 134.0;
    rtB.HoughTransform_o3[534] = 135.0;
    rtB.HoughTransform_o3[535] = 136.0;
    rtB.HoughTransform_o3[536] = 137.0;
    rtB.HoughTransform_o3[537] = 138.0;
    rtB.HoughTransform_o3[538] = 139.0;
    rtB.HoughTransform_o3[539] = 140.0;
    rtB.HoughTransform_o3[540] = 141.0;
    rtB.HoughTransform_o3[541] = 142.0;
    rtB.HoughTransform_o3[542] = 143.0;
    rtB.HoughTransform_o3[543] = 144.0;
    rtB.HoughTransform_o3[544] = 145.0;
    rtB.HoughTransform_o3[545] = 146.0;
    rtB.HoughTransform_o3[546] = 147.0;
    rtB.HoughTransform_o3[547] = 148.0;
    rtB.HoughTransform_o3[548] = 149.0;
    rtB.HoughTransform_o3[549] = 150.0;
    rtB.HoughTransform_o3[550] = 151.0;
    rtB.HoughTransform_o3[551] = 152.0;
    rtB.HoughTransform_o3[552] = 153.0;
    rtB.HoughTransform_o3[553] = 154.0;
    rtB.HoughTransform_o3[554] = 155.0;
    rtB.HoughTransform_o3[555] = 156.0;
    rtB.HoughTransform_o3[556] = 157.0;
    rtB.HoughTransform_o3[557] = 158.0;
    rtB.HoughTransform_o3[558] = 159.0;
    rtB.HoughTransform_o3[559] = 160.0;
    rtB.HoughTransform_o3[560] = 161.0;
    rtB.HoughTransform_o3[561] = 162.0;
    rtB.HoughTransform_o3[562] = 163.0;
    rtB.HoughTransform_o3[563] = 164.0;
    rtB.HoughTransform_o3[564] = 165.0;
    rtB.HoughTransform_o3[565] = 166.0;
    rtB.HoughTransform_o3[566] = 167.0;
    rtB.HoughTransform_o3[567] = 168.0;
    rtB.HoughTransform_o3[568] = 169.0;
    rtB.HoughTransform_o3[569] = 170.0;
    rtB.HoughTransform_o3[570] = 171.0;
    rtB.HoughTransform_o3[571] = 172.0;
    rtB.HoughTransform_o3[572] = 173.0;
    rtB.HoughTransform_o3[573] = 174.0;
    rtB.HoughTransform_o3[574] = 175.0;
    rtB.HoughTransform_o3[575] = 176.0;
    rtB.HoughTransform_o3[576] = 177.0;
    rtB.HoughTransform_o3[577] = 178.0;
    rtB.HoughTransform_o3[578] = 179.0;
    rtB.HoughTransform_o3[579] = 180.0;
    rtB.HoughTransform_o3[580] = 181.0;
    rtB.HoughTransform_o3[581] = 182.0;
    rtB.HoughTransform_o3[582] = 183.0;
    rtB.HoughTransform_o3[583] = 184.0;
    rtB.HoughTransform_o3[584] = 185.0;
    rtB.HoughTransform_o3[585] = 186.0;
    rtB.HoughTransform_o3[586] = 187.0;
    rtB.HoughTransform_o3[587] = 188.0;
    rtB.HoughTransform_o3[588] = 189.0;
    rtB.HoughTransform_o3[589] = 190.0;
    rtB.HoughTransform_o3[590] = 191.0;
    rtB.HoughTransform_o3[591] = 192.0;
    rtB.HoughTransform_o3[592] = 193.0;
    rtB.HoughTransform_o3[593] = 194.0;
    rtB.HoughTransform_o3[594] = 195.0;
    rtB.HoughTransform_o3[595] = 196.0;
    rtB.HoughTransform_o3[596] = 197.0;
    rtB.HoughTransform_o3[597] = 198.0;
    rtB.HoughTransform_o3[598] = 199.0;
    rtB.HoughTransform_o3[599] = 200.0;
    rtB.HoughTransform_o3[600] = 201.0;
    rtB.HoughTransform_o3[601] = 202.0;
    rtB.HoughTransform_o3[602] = 203.0;
    rtB.HoughTransform_o3[603] = 204.0;
    rtB.HoughTransform_o3[604] = 205.0;
    rtB.HoughTransform_o3[605] = 206.0;
    rtB.HoughTransform_o3[606] = 207.0;
    rtB.HoughTransform_o3[607] = 208.0;
    rtB.HoughTransform_o3[608] = 209.0;
    rtB.HoughTransform_o3[609] = 210.0;
    rtB.HoughTransform_o3[610] = 211.0;
    rtB.HoughTransform_o3[611] = 212.0;
    rtB.HoughTransform_o3[612] = 213.0;
    rtB.HoughTransform_o3[613] = 214.0;
    rtB.HoughTransform_o3[614] = 215.0;
    rtB.HoughTransform_o3[615] = 216.0;
    rtB.HoughTransform_o3[616] = 217.0;
    rtB.HoughTransform_o3[617] = 218.0;
    rtB.HoughTransform_o3[618] = 219.0;
    rtB.HoughTransform_o3[619] = 220.0;
    rtB.HoughTransform_o3[620] = 221.0;
    rtB.HoughTransform_o3[621] = 222.0;
    rtB.HoughTransform_o3[622] = 223.0;
    rtB.HoughTransform_o3[623] = 224.0;
    rtB.HoughTransform_o3[624] = 225.0;
    rtB.HoughTransform_o3[625] = 226.0;
    rtB.HoughTransform_o3[626] = 227.0;
    rtB.HoughTransform_o3[627] = 228.0;
    rtB.HoughTransform_o3[628] = 229.0;
    rtB.HoughTransform_o3[629] = 230.0;
    rtB.HoughTransform_o3[630] = 231.0;
    rtB.HoughTransform_o3[631] = 232.0;
    rtB.HoughTransform_o3[632] = 233.0;
    rtB.HoughTransform_o3[633] = 234.0;
    rtB.HoughTransform_o3[634] = 235.0;
    rtB.HoughTransform_o3[635] = 236.0;
    rtB.HoughTransform_o3[636] = 237.0;
    rtB.HoughTransform_o3[637] = 238.0;
    rtB.HoughTransform_o3[638] = 239.0;
    rtB.HoughTransform_o3[639] = 240.0;
    rtB.HoughTransform_o3[640] = 241.0;
    rtB.HoughTransform_o3[641] = 242.0;
    rtB.HoughTransform_o3[642] = 243.0;
    rtB.HoughTransform_o3[643] = 244.0;
    rtB.HoughTransform_o3[644] = 245.0;
    rtB.HoughTransform_o3[645] = 246.0;
    rtB.HoughTransform_o3[646] = 247.0;
    rtB.HoughTransform_o3[647] = 248.0;
    rtB.HoughTransform_o3[648] = 249.0;
    rtB.HoughTransform_o3[649] = 250.0;
    rtB.HoughTransform_o3[650] = 251.0;
    rtB.HoughTransform_o3[651] = 252.0;
    rtB.HoughTransform_o3[652] = 253.0;
    rtB.HoughTransform_o3[653] = 254.0;
    rtB.HoughTransform_o3[654] = 255.0;
    rtB.HoughTransform_o3[655] = 256.0;
    rtB.HoughTransform_o3[656] = 257.0;
    rtB.HoughTransform_o3[657] = 258.0;
    rtB.HoughTransform_o3[658] = 259.0;
    rtB.HoughTransform_o3[659] = 260.0;
    rtB.HoughTransform_o3[660] = 261.0;
    rtB.HoughTransform_o3[661] = 262.0;
    rtB.HoughTransform_o3[662] = 263.0;
    rtB.HoughTransform_o3[663] = 264.0;
    rtB.HoughTransform_o3[664] = 265.0;
    rtB.HoughTransform_o3[665] = 266.0;
    rtB.HoughTransform_o3[666] = 267.0;
    rtB.HoughTransform_o3[667] = 268.0;
    rtB.HoughTransform_o3[668] = 269.0;
    rtB.HoughTransform_o3[669] = 270.0;
    rtB.HoughTransform_o3[670] = 271.0;
    rtB.HoughTransform_o3[671] = 272.0;
    rtB.HoughTransform_o3[672] = 273.0;
    rtB.HoughTransform_o3[673] = 274.0;
    rtB.HoughTransform_o3[674] = 275.0;
    rtB.HoughTransform_o3[675] = 276.0;
    rtB.HoughTransform_o3[676] = 277.0;
    rtB.HoughTransform_o3[677] = 278.0;
    rtB.HoughTransform_o3[678] = 279.0;
    rtB.HoughTransform_o3[679] = 280.0;
    rtB.HoughTransform_o3[680] = 281.0;
    rtB.HoughTransform_o3[681] = 282.0;
    rtB.HoughTransform_o3[682] = 283.0;
    rtB.HoughTransform_o3[683] = 284.0;
    rtB.HoughTransform_o3[684] = 285.0;
    rtB.HoughTransform_o3[685] = 286.0;
    rtB.HoughTransform_o3[686] = 287.0;
    rtB.HoughTransform_o3[687] = 288.0;
    rtB.HoughTransform_o3[688] = 289.0;
    rtB.HoughTransform_o3[689] = 290.0;
    rtB.HoughTransform_o3[690] = 291.0;
    rtB.HoughTransform_o3[691] = 292.0;
    rtB.HoughTransform_o3[692] = 293.0;
    rtB.HoughTransform_o3[693] = 294.0;
    rtB.HoughTransform_o3[694] = 295.0;
    rtB.HoughTransform_o3[695] = 296.0;
    rtB.HoughTransform_o3[696] = 297.0;
    rtB.HoughTransform_o3[697] = 298.0;
    rtB.HoughTransform_o3[698] = 299.0;
    rtB.HoughTransform_o3[699] = 300.0;
    rtB.HoughTransform_o3[700] = 301.0;
    rtB.HoughTransform_o3[701] = 302.0;
    rtB.HoughTransform_o3[702] = 303.0;
    rtB.HoughTransform_o3[703] = 304.0;
    rtB.HoughTransform_o3[704] = 305.0;
    rtB.HoughTransform_o3[705] = 306.0;
    rtB.HoughTransform_o3[706] = 307.0;
    rtB.HoughTransform_o3[707] = 308.0;
    rtB.HoughTransform_o3[708] = 309.0;
    rtB.HoughTransform_o3[709] = 310.0;
    rtB.HoughTransform_o3[710] = 311.0;
    rtB.HoughTransform_o3[711] = 312.0;
    rtB.HoughTransform_o3[712] = 313.0;
    rtB.HoughTransform_o3[713] = 314.0;
    rtB.HoughTransform_o3[714] = 315.0;
    rtB.HoughTransform_o3[715] = 316.0;
    rtB.HoughTransform_o3[716] = 317.0;
    rtB.HoughTransform_o3[717] = 318.0;
    rtB.HoughTransform_o3[718] = 319.0;
    rtB.HoughTransform_o3[719] = 320.0;
    rtB.HoughTransform_o3[720] = 321.0;
    rtB.HoughTransform_o3[721] = 322.0;
    rtB.HoughTransform_o3[722] = 323.0;
    rtB.HoughTransform_o3[723] = 324.0;
    rtB.HoughTransform_o3[724] = 325.0;
    rtB.HoughTransform_o3[725] = 326.0;
    rtB.HoughTransform_o3[726] = 327.0;
    rtB.HoughTransform_o3[727] = 328.0;
    rtB.HoughTransform_o3[728] = 329.0;
    rtB.HoughTransform_o3[729] = 330.0;
    rtB.HoughTransform_o3[730] = 331.0;
    rtB.HoughTransform_o3[731] = 332.0;
    rtB.HoughTransform_o3[732] = 333.0;
    rtB.HoughTransform_o3[733] = 334.0;
    rtB.HoughTransform_o3[734] = 335.0;
    rtB.HoughTransform_o3[735] = 336.0;
    rtB.HoughTransform_o3[736] = 337.0;
    rtB.HoughTransform_o3[737] = 338.0;
    rtB.HoughTransform_o3[738] = 339.0;
    rtB.HoughTransform_o3[739] = 340.0;
    rtB.HoughTransform_o3[740] = 341.0;
    rtB.HoughTransform_o3[741] = 342.0;
    rtB.HoughTransform_o3[742] = 343.0;
    rtB.HoughTransform_o3[743] = 344.0;
    rtB.HoughTransform_o3[744] = 345.0;
    rtB.HoughTransform_o3[745] = 346.0;
    rtB.HoughTransform_o3[746] = 347.0;
    rtB.HoughTransform_o3[747] = 348.0;
    rtB.HoughTransform_o3[748] = 349.0;
    rtB.HoughTransform_o3[749] = 350.0;
    rtB.HoughTransform_o3[750] = 351.0;
    rtB.HoughTransform_o3[751] = 352.0;
    rtB.HoughTransform_o3[752] = 353.0;
    rtB.HoughTransform_o3[753] = 354.0;
    rtB.HoughTransform_o3[754] = 355.0;
    rtB.HoughTransform_o3[755] = 356.0;
    rtB.HoughTransform_o3[756] = 357.0;
    rtB.HoughTransform_o3[757] = 358.0;
    rtB.HoughTransform_o3[758] = 359.0;
    rtB.HoughTransform_o3[759] = 360.0;
    rtB.HoughTransform_o3[760] = 361.0;
    rtB.HoughTransform_o3[761] = 362.0;
    rtB.HoughTransform_o3[762] = 363.0;
    rtB.HoughTransform_o3[763] = 364.0;
    rtB.HoughTransform_o3[764] = 365.0;
    rtB.HoughTransform_o3[765] = 366.0;
    rtB.HoughTransform_o3[766] = 367.0;
    rtB.HoughTransform_o3[767] = 368.0;
    rtB.HoughTransform_o3[768] = 369.0;
    rtB.HoughTransform_o3[769] = 370.0;
    rtB.HoughTransform_o3[770] = 371.0;
    rtB.HoughTransform_o3[771] = 372.0;
    rtB.HoughTransform_o3[772] = 373.0;
    rtB.HoughTransform_o3[773] = 374.0;
    rtB.HoughTransform_o3[774] = 375.0;
    rtB.HoughTransform_o3[775] = 376.0;
    rtB.HoughTransform_o3[776] = 377.0;
    rtB.HoughTransform_o3[777] = 378.0;
    rtB.HoughTransform_o3[778] = 379.0;
    rtB.HoughTransform_o3[779] = 380.0;
    rtB.HoughTransform_o3[780] = 381.0;
    rtB.HoughTransform_o3[781] = 382.0;
    rtB.HoughTransform_o3[782] = 383.0;
    rtB.HoughTransform_o3[783] = 384.0;
    rtB.HoughTransform_o3[784] = 385.0;
    rtB.HoughTransform_o3[785] = 386.0;
    rtB.HoughTransform_o3[786] = 387.0;
    rtB.HoughTransform_o3[787] = 388.0;
    rtB.HoughTransform_o3[788] = 389.0;
    rtB.HoughTransform_o3[789] = 390.0;
    rtB.HoughTransform_o3[790] = 391.0;
    rtB.HoughTransform_o3[791] = 392.0;
    rtB.HoughTransform_o3[792] = 393.0;
    rtB.HoughTransform_o3[793] = 394.0;
    rtB.HoughTransform_o3[794] = 395.0;
    rtB.HoughTransform_o3[795] = 396.0;
    rtB.HoughTransform_o3[796] = 397.0;
    rtB.HoughTransform_o3[797] = 398.0;
    rtB.HoughTransform_o3[798] = 399.0;
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rtM->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  {
    int32_T curNumNonZ;
    int32_T n;
    int32_T m;
    int32_T step;
    boolean_T isValid;
    int32_T idxOut;
    int32_T previous;

    /* Start for S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
    MW_videoCaptureInit(rtConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U, 240U, 1U,
                        2U, 1U, 0.033333333333333333);

    /* Start for S-Function (svipmorphop): '<Root>/Erosion' */
    previous = 0;
    step = 0;
    curNumNonZ = 0;
    isValid = true;
    idxOut = 0;
    n = 0;
    while (n < 1) {
      m = 0;
      while (m < 4) {
        if (curNumNonZ == 0) {
          curNumNonZ = 1;
        } else if (curNumNonZ == 1) {
          step = idxOut - previous;
          curNumNonZ = 2;
        } else if (idxOut - previous == step) {
          curNumNonZ++;
        } else {
          isValid = false;
          m = 4;
          n = 1;
        }

        previous = idxOut;
        idxOut++;
        m++;
      }

      idxOut += 323;
      n++;
    }

    if (isValid && (curNumNonZ >= 4)) {
      if (step == 327) {
        rtDW.Erosion_STREL_DW[0] = 2;
      } else {
        rtDW.Erosion_STREL_DW[0] = (step == 1);
      }
    } else {
      rtDW.Erosion_STREL_DW[0] = 0;
    }

    curNumNonZ = 0;
    isValid = true;
    idxOut = 0;
    n = 0;
    while (n < 4) {
      m = 0;
      while (m < 1) {
        if (curNumNonZ == 0) {
          curNumNonZ = 1;
        } else if (curNumNonZ == 1) {
          step = idxOut - previous;
          curNumNonZ = 2;
        } else if (idxOut - previous == step) {
          curNumNonZ++;
        } else {
          isValid = false;
          m = 1;
          n = 4;
        }

        previous = idxOut;
        idxOut++;
        m++;
      }

      idxOut += 326;
      n++;
    }

    if (isValid && (curNumNonZ >= 4)) {
      if (step == 327) {
        rtDW.Erosion_STREL_DW[1] = 2;
      } else {
        rtDW.Erosion_STREL_DW[1] = (step == 1);
      }
    } else {
      rtDW.Erosion_STREL_DW[1] = 0;
    }

    previous = 0;
    curNumNonZ = 0;
    n = 0;
    while (n < 1) {
      for (m = 0; m < 4; m++) {
        rtDW.Erosion_ERODE_OFF_DW[previous] = m;
        curNumNonZ++;
        previous++;
      }

      n = 1;
    }

    rtDW.Erosion_NUMNONZ_DW[0] = curNumNonZ;
    curNumNonZ = 0;
    for (n = 0; n < 4; n++) {
      m = 0;
      while (m < 1) {
        rtDW.Erosion_ERODE_OFF_DW[previous] = n * 327;
        curNumNonZ++;
        previous++;
        m = 1;
      }
    }

    rtDW.Erosion_NUMNONZ_DW[1] = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<Root>/Erosion' */

    /* Start for S-Function (svipedge): '<Root>/Edge Detection' */
    rtDW.EdgeDetection_MEAN_FACTOR_DW = 27962;
    for (previous = 0; previous < 6; previous++) {
      rtDW.EdgeDetection_VO_DW[previous] =
        rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
        rtConstP.EdgeDetection_VCO_RTP[previous];
      if (rtConstP.EdgeDetection_VCO_RTP[previous] > 0) {
        rtDW.EdgeDetection_VOU_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOD_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320;
      } else {
        rtDW.EdgeDetection_VOU_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320;
        rtDW.EdgeDetection_VOD_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      if (rtConstP.EdgeDetection_VRO_RTP[previous] > 0) {
        rtDW.EdgeDetection_VOL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOR_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
      } else {
        rtDW.EdgeDetection_VOL_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_VOUL_DW[previous] = 0;
        rtDW.EdgeDetection_VOLR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOLL_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOUR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320;
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_VOLL_DW[previous] = 0;
        rtDW.EdgeDetection_VOUR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOUL_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOLR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320;
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_VOUR_DW[previous] = 0;
        rtDW.EdgeDetection_VOLL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOUL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320;
        rtDW.EdgeDetection_VOLR_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_VOLR_DW[previous] = 0;
        rtDW.EdgeDetection_VOUL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOLL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 320;
        rtDW.EdgeDetection_VOUR_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      rtDW.EdgeDetection_HO_DW[previous] =
        rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
        rtConstP.EdgeDetection_HCO_RTP[previous];
      if (rtConstP.EdgeDetection_HCO_RTP[previous] > 0) {
        rtDW.EdgeDetection_HOU_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOD_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320;
      } else {
        rtDW.EdgeDetection_HOU_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320;
        rtDW.EdgeDetection_HOD_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }

      if (rtConstP.EdgeDetection_HRO_RTP[previous] > 0) {
        rtDW.EdgeDetection_HOL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOR_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
      } else {
        rtDW.EdgeDetection_HOL_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_HOUL_DW[previous] = 0;
        rtDW.EdgeDetection_HOLR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOLL_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOUR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320;
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_HOLL_DW[previous] = 0;
        rtDW.EdgeDetection_HOUR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOUL_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOLR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320;
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_HOUR_DW[previous] = 0;
        rtDW.EdgeDetection_HOLL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOUL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320;
        rtDW.EdgeDetection_HOLR_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_HOLR_DW[previous] = 0;
        rtDW.EdgeDetection_HOUL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOLL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 320;
        rtDW.EdgeDetection_HOUR_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }
    }

    /* End of Start for S-Function (svipedge): '<Root>/Edge Detection' */
    /* Start for MATLABSystem: '<S4>/MATLAB System' */
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
