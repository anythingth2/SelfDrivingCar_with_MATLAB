/*
 * File: lane_departure.c
 *
 * Code generated for Simulink model 'lane_departure'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Feb 12 22:10:15 2018
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
extern void lane_departure_step0(void);
extern void lane_departure_step1(void);
static void rate_monotonic_scheduler(void);
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

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void lane_departure_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 5) {/* Sample time: [0.2s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void lane_departure_step0(void)        /* Sample time: [0.033333333333333333s, 0.0s] */
{
  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, rtM->Timing.taskTime0);

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

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.taskTime0 =
    (++rtM->Timing.clockTick0) * rtM->Timing.stepSize0;
}

/* Model step function for TID1 */
void lane_departure_step1(void)        /* Sample time: [0.2s, 0.0s] */
{
  boolean_T done;
  boolean_T b4;
  boolean_T b3;
  boolean_T b2;
  uint8_T minVal;
  int32_T row;
  int32_T outIdxAdj;
  int32_T inIdx;
  int32_T col;
  int32_T hOffset;
  int32_T gOffset;
  int32_T iter;
  int32_T numIter;
  int32_T numEleTmp;
  int32_T lastBlockCol;
  int32_T lineOff;
  int32_T ky;
  int32_T ku;
  int32_T line_idx_3;

  /* S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
  MW_videoCaptureOutput(rtConstP.V4L2VideoCapture_p1, &rtB.MatrixConcatenate[0],
                        &rtB.MatrixConcatenate[19200], &rtB.MatrixConcatenate
                        [38400]);

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  for (lineOff = 0; lineOff < 19200; lineOff++) {
    rtB.fromIdx = ((rtB.MatrixConcatenate[19200 + lineOff] * 38470U +
                    rtB.MatrixConcatenate[lineOff] * 19595U) +
                   rtB.MatrixConcatenate[38400 + lineOff] * 7471U) + 32768U;
    rtB.fromIdx >>= 16;
    rtB.ColorSpaceConversion[lineOff] = (uint8_T)rtB.fromIdx;
  }

  /* End of S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */

  /* S-Function (svipmorphop): '<Root>/Erosion' */
  ku = 0;
  rtDW.Erosion_ONE_PAD_IMG_DW[0] = MAX_uint8_T;
  ky = 1;
  for (numIter = 0; numIter < 166; numIter++) {
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    ky++;
  }

  for (lineOff = 0; lineOff < 120; lineOff++) {
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    memcpy(&rtDW.Erosion_ONE_PAD_IMG_DW[ky + 1], &rtB.ColorSpaceConversion[ku],
           160U * sizeof(uint8_T));
    ky += 161;
    ku += 160;
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    ky++;
    for (numIter = 0; numIter < 5; numIter++) {
      rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
      ky++;
    }
  }

  for (lineOff = 0; lineOff < 6; lineOff++) {
    rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
    ky++;
    for (numIter = 0; numIter < 166; numIter++) {
      rtDW.Erosion_ONE_PAD_IMG_DW[ky] = MAX_uint8_T;
      ky++;
    }
  }

  memset(&rtDW.Erosion_TWO_PAD_IMG_DW[0], 255, 21209U * sizeof(uint8_T));
  rtB.curNumNonZ = rtDW.Erosion_NUMNONZ_DW[0];
  inIdx = 0;
  ky = 1;
  if (rtDW.Erosion_STREL_DW[0] == 0) {
    for (col = 0; col < 126; col++) {
      for (row = 0; row < 163; row++) {
        minVal = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx + rtDW.Erosion_ERODE_OFF_DW[0]];
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
          if (rtDW.Erosion_ONE_PAD_IMG_DW[inIdx +
              rtDW.Erosion_ERODE_OFF_DW[lineOff]] < minVal) {
            minVal = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx +
              rtDW.Erosion_ERODE_OFF_DW[lineOff]];
          }
        }

        rtDW.Erosion_TWO_PAD_IMG_DW[ky] = minVal;
        inIdx++;
        ky++;
      }

      inIdx += 4;
      ky += 4;
    }
  } else if (rtDW.Erosion_STREL_DW[0] == 1) {
    numIter = 164 / rtDW.Erosion_NUMNONZ_DW[0];
    numEleTmp = rtDW.Erosion_ERODE_OFF_DW[0] / 167 * 167;
    lineOff = rtDW.Erosion_ERODE_OFF_DW[0] - numEleTmp;
    gOffset = (rtDW.Erosion_NUMNONZ_DW[0] + lineOff) - 1;
    hOffset = lineOff - 1;
    inIdx = 1 + numEleTmp;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[0];
    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[0];
    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (col = 0; col < 126; col++) {
      numEleTmp = rtB.curNumNonZ;
      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
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

      if (lastBlockCol <= 163) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        iter = lastBlockCol + rtB.curNumNonZ;
        for (lineOff = lastBlockCol + 1; lineOff < iter; lineOff++) {
          if (lineOff < 163) {
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
      if (lastBlockCol <= 163) {
        for (lineOff = 1; lineOff - 1 < rtB.curNumNonZ; lineOff++) {
          if ((rtB.curNumNonZ - lineOff) + lastBlockCol < 163) {
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

      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx--;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
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

      for (row = 0; row < 163; row++) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtDW.Erosion_TWO_PAD_IMG_DW[ky] = rtDW.Erosion_GBUF_DW[(numEleTmp +
            gOffset) - 1];
        } else {
          rtDW.Erosion_TWO_PAD_IMG_DW[ky] = rtDW.Erosion_HBUF_DW[numEleTmp +
            hOffset];
        }

        numEleTmp++;
        ky++;
      }

      inIdx += 168;
      ky += 4;
    }
  } else {
    numIter = 126 / rtDW.Erosion_NUMNONZ_DW[0];
    lineOff = rtDW.Erosion_ERODE_OFF_DW[0] / 167;
    gOffset = rtDW.Erosion_NUMNONZ_DW[0] + lineOff;
    hOffset = lineOff;
    inIdx = rtDW.Erosion_ERODE_OFF_DW[0] - lineOff * 167;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[0];
    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[0];
    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (row = 0; row < 163; row++) {
      numEleTmp = rtB.curNumNonZ;
      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 167;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
          if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
          }

          numEleTmp++;
          inIdx += 167;
        }
      }

      if (lastBlockCol <= 126) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 167;
        iter = lastBlockCol + rtB.curNumNonZ;
        for (lineOff = lastBlockCol + 1; lineOff < iter; lineOff++) {
          if (lineOff < 126) {
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
          inIdx += 167;
        }
      }

      inIdx -= 167;
      if (lastBlockCol <= 126) {
        for (lineOff = 1; lineOff - 1 < rtB.curNumNonZ; lineOff++) {
          if ((rtB.curNumNonZ - lineOff) + lastBlockCol < 126) {
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
          inIdx -= 167;
        }
      }

      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx -= 167;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
          if (rtDW.Erosion_HBUF_DW[numEleTmp] <
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
              rtDW.Erosion_ONE_PAD_IMG_DW[inIdx];
          }

          numEleTmp--;
          inIdx -= 167;
        }
      }

      for (col = 0; col < 126; col++) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtDW.Erosion_TWO_PAD_IMG_DW[ky] = rtDW.Erosion_GBUF_DW[(numEleTmp +
            gOffset) - 1];
        } else {
          rtDW.Erosion_TWO_PAD_IMG_DW[ky] = rtDW.Erosion_HBUF_DW[numEleTmp +
            hOffset];
        }

        numEleTmp++;
        ky += 167;
      }

      inIdx += 168;
      ky += -21041;
    }
  }

  numEleTmp = rtDW.Erosion_NUMNONZ_DW[0];
  rtB.curNumNonZ = rtDW.Erosion_NUMNONZ_DW[1];
  inIdx = 1;
  ky = 0;
  if (rtDW.Erosion_STREL_DW[1] == 0) {
    for (col = 0; col < 120; col++) {
      for (row = 1; row < 161; row++) {
        minVal = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx +
          rtDW.Erosion_ERODE_OFF_DW[numEleTmp]];
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
          if (rtDW.Erosion_TWO_PAD_IMG_DW[rtDW.Erosion_ERODE_OFF_DW[lineOff +
              numEleTmp] + inIdx] < minVal) {
            minVal =
              rtDW.Erosion_TWO_PAD_IMG_DW[rtDW.Erosion_ERODE_OFF_DW[lineOff +
              numEleTmp] + inIdx];
          }
        }

        rtB.Erosion[ky] = minVal;
        inIdx++;
        ky++;
      }

      inIdx += 7;
    }
  } else if (rtDW.Erosion_STREL_DW[1] == 1) {
    numIter = 160 / rtDW.Erosion_NUMNONZ_DW[1];
    numEleTmp = rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] / 167 *
      167;
    lineOff = rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] - numEleTmp;
    gOffset = rtDW.Erosion_NUMNONZ_DW[1] + lineOff;
    hOffset = lineOff;
    inIdx = numEleTmp + 1;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[1] + 1;
    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[1];
    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (col = 0; col < 120; col++) {
      numEleTmp = rtB.curNumNonZ;
      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
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

      if (lastBlockCol <= 161) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx++;
        iter = lastBlockCol + rtB.curNumNonZ;
        for (lineOff = lastBlockCol + 1; lineOff < iter; lineOff++) {
          if (lineOff < 161) {
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
      if (lastBlockCol <= 161) {
        for (lineOff = 1; lineOff - 1 < rtB.curNumNonZ; lineOff++) {
          if ((rtB.curNumNonZ - lineOff) + lastBlockCol < 161) {
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

      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx--;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
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

      for (row = 1; row < 161; row++) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtB.Erosion[ky] = rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1];
        } else {
          rtB.Erosion[ky] = rtDW.Erosion_HBUF_DW[numEleTmp + hOffset];
        }

        numEleTmp++;
        ky++;
      }

      inIdx += 168;
    }
  } else {
    numIter = 121 / rtDW.Erosion_NUMNONZ_DW[1];
    lineOff = rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] / 167;
    gOffset = (rtDW.Erosion_NUMNONZ_DW[1] + lineOff) - 1;
    hOffset = lineOff - 1;
    inIdx = (rtDW.Erosion_ERODE_OFF_DW[rtDW.Erosion_NUMNONZ_DW[0]] - lineOff *
             167) + 168;
    lastBlockCol = numIter * rtDW.Erosion_NUMNONZ_DW[1];
    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    numEleTmp = (numIter + 1) * rtDW.Erosion_NUMNONZ_DW[1];
    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_GBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = 0; lineOff < rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (lineOff = numEleTmp; lineOff < numEleTmp + rtB.curNumNonZ; lineOff++) {
      rtDW.Erosion_HBUF_DW[lineOff] = MAX_uint8_T;
    }

    for (row = 1; row < 161; row++) {
      numEleTmp = rtB.curNumNonZ;
      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 167;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
          if (rtDW.Erosion_GBUF_DW[numEleTmp - 1] <
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_GBUF_DW[numEleTmp - 1];
          } else {
            rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
          }

          numEleTmp++;
          inIdx += 167;
        }
      }

      if (lastBlockCol <= 120) {
        rtDW.Erosion_GBUF_DW[numEleTmp] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp++;
        inIdx += 167;
        iter = lastBlockCol + rtB.curNumNonZ;
        for (lineOff = lastBlockCol + 1; lineOff < iter; lineOff++) {
          if (lineOff < 120) {
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
          inIdx += 167;
        }
      }

      inIdx -= 167;
      if (lastBlockCol <= 120) {
        for (lineOff = 1; lineOff - 1 < rtB.curNumNonZ; lineOff++) {
          if ((rtB.curNumNonZ - lineOff) + lastBlockCol < 120) {
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
          inIdx -= 167;
        }
      }

      for (iter = 0; iter < numIter; iter++) {
        rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
        numEleTmp--;
        inIdx -= 167;
        for (lineOff = 1; lineOff < rtB.curNumNonZ; lineOff++) {
          if (rtDW.Erosion_HBUF_DW[numEleTmp] <
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx]) {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] = rtDW.Erosion_HBUF_DW[numEleTmp];
          } else {
            rtDW.Erosion_HBUF_DW[numEleTmp - 1] =
              rtDW.Erosion_TWO_PAD_IMG_DW[inIdx];
          }

          numEleTmp--;
          inIdx -= 167;
        }
      }

      for (col = 0; col < 120; col++) {
        if (rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1] <
            rtDW.Erosion_HBUF_DW[numEleTmp + hOffset]) {
          rtB.Erosion[ky] = rtDW.Erosion_GBUF_DW[(numEleTmp + gOffset) - 1];
        } else {
          rtB.Erosion[ky] = rtDW.Erosion_HBUF_DW[numEleTmp + hOffset];
        }

        numEleTmp++;
        ky += 160;
      }

      inIdx += 168;
      ky += -19199;
    }
  }

  /* End of S-Function (svipmorphop): '<Root>/Erosion' */

  /* S-Function (svipedge): '<Root>/Edge Detection' */
  for (ky = 0; ky < 118; ky++) {
    for (numEleTmp = 0; numEleTmp < 158; numEleTmp++) {
      inIdx = 0;
      gOffset = 0;
      iter = ((ky + 1) * 160 + numEleTmp) + 1;
      for (lineOff = 0; lineOff < 6; lineOff++) {
        inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff],
          rtB.Erosion[iter + rtDW.EdgeDetection_VO_DW[lineOff]], 23U);
        gOffset += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
          rtB.Erosion[iter + rtDW.EdgeDetection_HO_DW[lineOff]], 23U);
      }

      rtDW.EdgeDetection_GV_SQUARED_DW[iter] = mul_s32_loSR(inIdx, inIdx, 8U);
      rtDW.EdgeDetection_GH_SQUARED_DW[iter] = mul_s32_loSR(gOffset, gOffset, 8U);
    }
  }

  for (ky = 0; ky < 118; ky++) {
    inIdx = 0;
    gOffset = 0;
    ku = 0;
    rtB.accumFour = 0;
    numEleTmp = (ky + 1) * 160;
    iter = (ky + 1) * 160 + 159;
    for (lineOff = 0; lineOff < 6; lineOff++) {
      inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
        rtB.Erosion[numEleTmp + rtDW.EdgeDetection_HOU_DW[lineOff]], 23U);
      gOffset += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
        rtB.Erosion[iter + rtDW.EdgeDetection_HOD_DW[lineOff]], 23U);
      ku += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff],
                           rtB.Erosion[numEleTmp +
                           rtDW.EdgeDetection_VOU_DW[lineOff]], 23U);
      rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff],
        rtB.Erosion[iter + rtDW.EdgeDetection_VOD_DW[lineOff]], 23U);
    }

    rtDW.EdgeDetection_GV_SQUARED_DW[numEleTmp] = mul_s32_loSR(ku, ku, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[numEleTmp] = mul_s32_loSR(inIdx, inIdx, 8U);
    rtDW.EdgeDetection_GV_SQUARED_DW[iter] = mul_s32_loSR(rtB.accumFour,
      rtB.accumFour, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[iter] = mul_s32_loSR(gOffset, gOffset, 8U);
  }

  for (numEleTmp = 0; numEleTmp < 158; numEleTmp++) {
    inIdx = 0;
    gOffset = 0;
    ku = 0;
    rtB.accumFour = 0;
    ky = numEleTmp + 19041;
    for (lineOff = 0; lineOff < 6; lineOff++) {
      inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff],
        rtB.Erosion[(numEleTmp + rtDW.EdgeDetection_VOL_DW[lineOff]) + 1], 23U);
      gOffset += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff],
        rtB.Erosion[ky + rtDW.EdgeDetection_VOR_DW[lineOff]], 23U);
      ku += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff], rtB.Erosion
                           [(numEleTmp + rtDW.EdgeDetection_HOL_DW[lineOff]) + 1],
                           23U);
      rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
        rtB.Erosion[ky + rtDW.EdgeDetection_HOR_DW[lineOff]], 23U);
    }

    rtDW.EdgeDetection_GV_SQUARED_DW[numEleTmp + 1] = mul_s32_loSR(inIdx, inIdx,
      8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[numEleTmp + 1] = mul_s32_loSR(ku, ku, 8U);
    rtDW.EdgeDetection_GV_SQUARED_DW[ky] = mul_s32_loSR(gOffset, gOffset, 8U);
    rtDW.EdgeDetection_GH_SQUARED_DW[ky] = mul_s32_loSR(rtB.accumFour,
      rtB.accumFour, 8U);
  }

  inIdx = 0;
  gOffset = 0;
  ku = 0;
  rtB.accumFour = 0;
  for (lineOff = 0; lineOff < 6; lineOff++) {
    inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff],
      rtB.Erosion[rtDW.EdgeDetection_VOUL_DW[lineOff]], 23U);
    gOffset += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
      rtB.Erosion[rtDW.EdgeDetection_HOUL_DW[lineOff]], 23U);
    ku += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff], rtB.Erosion[159
                         + rtDW.EdgeDetection_VOLL_DW[lineOff]], 23U);
    rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
      rtB.Erosion[159 + rtDW.EdgeDetection_HOLL_DW[lineOff]], 23U);
  }

  rtDW.EdgeDetection_GV_SQUARED_DW[0] = mul_s32_loSR(inIdx, inIdx, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[0] = mul_s32_loSR(gOffset, gOffset, 8U);
  rtDW.EdgeDetection_GV_SQUARED_DW[159] = mul_s32_loSR(ku, ku, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[159] = mul_s32_loSR(rtB.accumFour,
    rtB.accumFour, 8U);
  inIdx = 0;
  gOffset = 0;
  ku = 0;
  rtB.accumFour = 0;
  for (lineOff = 0; lineOff < 6; lineOff++) {
    inIdx += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff], rtB.Erosion
      [19040 + rtDW.EdgeDetection_VOUR_DW[lineOff]], 23U);
    gOffset += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
      rtB.Erosion[19040 + rtDW.EdgeDetection_HOUR_DW[lineOff]], 23U);
    ku += mul_ssu32_loSR(rtConstP.EdgeDetection_VC_RTP[lineOff], rtB.Erosion
                         [19199 + rtDW.EdgeDetection_VOLR_DW[lineOff]], 23U);
    rtB.accumFour += mul_ssu32_loSR(rtConstP.EdgeDetection_HC_RTP[lineOff],
      rtB.Erosion[19199 + rtDW.EdgeDetection_HOLR_DW[lineOff]], 23U);
  }

  rtDW.EdgeDetection_GV_SQUARED_DW[19040] = mul_s32_loSR(inIdx, inIdx, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[19040] = mul_s32_loSR(gOffset, gOffset, 8U);
  rtDW.EdgeDetection_GV_SQUARED_DW[19199] = mul_s32_loSR(ku, ku, 8U);
  rtDW.EdgeDetection_GH_SQUARED_DW[19199] = mul_s32_loSR(rtB.accumFour,
    rtB.accumFour, 8U);
  gOffset = 0;
  for (lineOff = 0; lineOff < 19200; lineOff++) {
    rtDW.EdgeDetection_GRAD_SUM_DW[lineOff] =
      rtDW.EdgeDetection_GV_SQUARED_DW[lineOff];
    rtDW.EdgeDetection_GRAD_SUM_DW[lineOff] +=
      rtDW.EdgeDetection_GH_SQUARED_DW[lineOff];
    gOffset += mul_s32_loSR(rtDW.EdgeDetection_GRAD_SUM_DW[lineOff],
      rtDW.EdgeDetection_MEAN_FACTOR_DW, 31U);
  }

  inIdx = gOffset << 2;
  for (ky = 0; ky < 120; ky++) {
    for (numEleTmp = 0; numEleTmp < 160; numEleTmp++) {
      lineOff = ky * 160 + numEleTmp;
      done = true;
      b2 = true;
      b3 = true;
      b4 = true;
      if (ky != 0) {
        done = (rtDW.EdgeDetection_GRAD_SUM_DW[lineOff - 160] <=
                rtDW.EdgeDetection_GRAD_SUM_DW[lineOff]);
      }

      if (ky != 119) {
        b2 = (rtDW.EdgeDetection_GRAD_SUM_DW[lineOff] >
              rtDW.EdgeDetection_GRAD_SUM_DW[lineOff + 160]);
      }

      if (numEleTmp != 0) {
        b3 = (rtDW.EdgeDetection_GRAD_SUM_DW[lineOff - 1] <=
              rtDW.EdgeDetection_GRAD_SUM_DW[lineOff]);
      }

      if (numEleTmp != 159) {
        b4 = (rtDW.EdgeDetection_GRAD_SUM_DW[lineOff] >
              rtDW.EdgeDetection_GRAD_SUM_DW[lineOff + 1]);
      }

      rtB.EdgeDetection[lineOff] = ((rtDW.EdgeDetection_GRAD_SUM_DW[lineOff] >
        inIdx) && (((rtDW.EdgeDetection_GV_SQUARED_DW[lineOff] >=
                     rtDW.EdgeDetection_GH_SQUARED_DW[lineOff]) && done && b2) ||
                   ((rtDW.EdgeDetection_GH_SQUARED_DW[lineOff] >=
                     rtDW.EdgeDetection_GV_SQUARED_DW[lineOff]) && b3 && b4)));
    }
  }

  /* End of S-Function (svipedge): '<Root>/Edge Detection' */

  /* S-Function (sviphough): '<Root>/Hough Transform' */
  MWVIP_Hough_D(&rtB.EdgeDetection[0], &rtB.HoughTransform_o1[0],
                &rtConstP.HoughTransform_SINE_TABLE_RTP[0],
                &rtConstP.HoughTransform_FIRSTRHO_RTP, 160, 120, 399, 91);

  /* S-Function (svipfindlocalmax): '<Root>/Find Local Maxima' */
  ku = 0;
  done = false;
  for (lineOff = 0; lineOff < 71820; lineOff++) {
    rtDW.FindLocalMaxima_TEMP_IN_DWORKS[lineOff] = rtB.HoughTransform_o1[lineOff];
  }

  for (lineOff = 0; lineOff < 6; lineOff++) {
    rtB.FindLocalMaxima[lineOff] = 0.0;
  }

  while (!done) {
    rtB.curNumNonZ = 0;
    rtB.maxValue = rtDW.FindLocalMaxima_TEMP_IN_DWORKS[0];
    for (lineOff = 0; lineOff < 71820; lineOff++) {
      if (rtDW.FindLocalMaxima_TEMP_IN_DWORKS[lineOff] > rtB.maxValue) {
        rtB.curNumNonZ = lineOff;
        rtB.maxValue = rtDW.FindLocalMaxima_TEMP_IN_DWORKS[lineOff];
      }
    }

    ky = rtB.curNumNonZ % 399;
    lineOff = rtB.curNumNonZ / 399;
    if (rtDW.FindLocalMaxima_TEMP_IN_DWORKS[rtB.curNumNonZ] >= 10.0) {
      rtB.FindLocalMaxima[ku] = 1.0 + (real_T)lineOff;
      rtB.FindLocalMaxima[3U + ku] = 1 + ky;
      ku++;
      if (ku == 3) {
        done = true;
      }

      rtB.curNumNonZ = ky - 2;
      if (!(rtB.curNumNonZ > 0)) {
        rtB.curNumNonZ = 0;
      }

      ky += 2;
      if (!(ky < 398)) {
        ky = 398;
      }

      numEleTmp = lineOff - 3;
      iter = lineOff + 3;
      if (!((numEleTmp < 0) || (iter > 179))) {
        while (numEleTmp <= iter) {
          rtB.accumFour = numEleTmp * 399;
          for (lineOff = rtB.curNumNonZ; lineOff <= ky; lineOff++) {
            rtDW.FindLocalMaxima_TEMP_IN_DWORKS[lineOff + rtB.accumFour] = 0.0;
          }

          numEleTmp++;
        }
      } else {
        if (numEleTmp < 0) {
          for (numIter = numEleTmp; numIter <= iter; numIter++) {
            if (numIter < 0) {
              rtB.accumFour = (numIter + 180) * 399 + 398;
              for (lineOff = rtB.curNumNonZ; lineOff <= ky; lineOff++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[rtB.accumFour - lineOff] =
                  0.0;
              }
            } else {
              rtB.accumFour = numIter * 399;
              for (lineOff = rtB.curNumNonZ; lineOff <= ky; lineOff++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[lineOff + rtB.accumFour] =
                  0.0;
              }
            }
          }
        }

        if (iter > 179) {
          for (numIter = numEleTmp; numIter <= iter; numIter++) {
            if (numIter > 179) {
              rtB.accumFour = (numIter - 180) * 399 + 398;
              for (lineOff = rtB.curNumNonZ; lineOff <= ky; lineOff++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[rtB.accumFour - lineOff] =
                  0.0;
              }
            } else {
              rtB.accumFour = numIter * 399;
              for (lineOff = rtB.curNumNonZ; lineOff <= ky; lineOff++) {
                rtDW.FindLocalMaxima_TEMP_IN_DWORKS[lineOff + rtB.accumFour] =
                  0.0;
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
  for (lineOff = 0; lineOff < ku; lineOff++) {
    rtB.FindLocalMaxima[rtB.toIdx] = rtB.FindLocalMaxima[rtB.fromIdx];
    rtB.fromIdx++;
    rtB.toIdx++;
  }

  rtDW.FindLocalMaxima_DIMS1[0] = ku;
  rtDW.FindLocalMaxima_DIMS1[1] = 2;

  /* End of S-Function (svipfindlocalmax): '<Root>/Find Local Maxima' */

  /* Selector: '<Root>/Selector' */
  rtDW.Selector_DIMS1[0] = rtDW.FindLocalMaxima_DIMS1[0];
  rtDW.Selector_DIMS1[1] = 1;
  numEleTmp = rtDW.FindLocalMaxima_DIMS1[0];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    rtB.rtb_FindLocalMaxima_data[lineOff] = rtB.FindLocalMaxima[lineOff];
  }

  numEleTmp = rtDW.FindLocalMaxima_DIMS1[0];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    rtB.Selector[lineOff] = rtB.rtb_FindLocalMaxima_data[lineOff];
  }

  /* End of Selector: '<Root>/Selector' */

  /* Selector: '<Root>/Selector1' */
  rtDW.Selector1_DIMS1[0] = 1;
  rtDW.Selector1_DIMS1[1] = rtDW.Selector_DIMS1[0] * rtDW.Selector_DIMS1[1];
  numEleTmp = rtDW.Selector_DIMS1[1];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    iter = rtDW.Selector_DIMS1[0];
    for (inIdx = 0; inIdx < iter; inIdx++) {
      rtB.rtb_Selector_data[inIdx + rtDW.Selector_DIMS1[0] * lineOff] = (int32_T)
        rtB.Selector[rtDW.Selector_DIMS1[0] * lineOff + inIdx] - 1;
    }
  }

  numEleTmp = rtDW.Selector_DIMS1[0] * rtDW.Selector_DIMS1[1];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    rtB.Selector1[rtDW.Selector1_DIMS1[0] * lineOff] =
      rtB.HoughTransform_o2[rtB.rtb_Selector_data[lineOff]];
  }

  /* End of Selector: '<Root>/Selector1' */

  /* Selector: '<Root>/Selector2' */
  rtDW.Selector2_DIMS1[0] = rtDW.FindLocalMaxima_DIMS1[0];
  rtDW.Selector2_DIMS1[1] = 1;
  numEleTmp = rtDW.FindLocalMaxima_DIMS1[0];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    rtB.rtb_FindLocalMaxima_data[lineOff] = rtB.FindLocalMaxima[lineOff +
      rtDW.FindLocalMaxima_DIMS1[0]];
  }

  numEleTmp = rtDW.FindLocalMaxima_DIMS1[0];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    rtB.Selector[lineOff] = rtB.rtb_FindLocalMaxima_data[lineOff];
  }

  /* End of Selector: '<Root>/Selector2' */

  /* Selector: '<Root>/Selector5' */
  rtDW.Selector5_DIMS1[0] = 1;
  rtDW.Selector5_DIMS1[1] = rtDW.Selector2_DIMS1[0] * rtDW.Selector2_DIMS1[1];
  numEleTmp = rtDW.Selector2_DIMS1[1];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    iter = rtDW.Selector2_DIMS1[0];
    for (inIdx = 0; inIdx < iter; inIdx++) {
      rtB.rtb_Selector_data[inIdx + rtDW.Selector2_DIMS1[0] * lineOff] =
        (int32_T)rtB.Selector[rtDW.Selector2_DIMS1[0] * lineOff + inIdx] - 1;
    }
  }

  numEleTmp = rtDW.Selector2_DIMS1[0] * rtDW.Selector2_DIMS1[1];
  for (lineOff = 0; lineOff < numEleTmp; lineOff++) {
    rtB.Selector5[rtDW.Selector5_DIMS1[0] * lineOff] =
      rtB.HoughTransform_o3[rtB.rtb_Selector_data[lineOff]];
  }

  /* End of Selector: '<Root>/Selector5' */

  /* S-Function (sviphoughlines): '<Root>/Hough Lines' */
  rtDW.HoughLines_DIMS1[1] = 4;
  rtDW.HoughLines_DIMS1[0] = rtDW.Selector1_DIMS1[0] * rtDW.Selector1_DIMS1[1];
  for (lineOff = 0; lineOff < rtDW.Selector1_DIMS1[1]; lineOff++) {
    ky = 0;
    rtB.maxValue = (rtB.Selector5[lineOff] + 2.2204460492503131E-16) / (cos
      (rtB.Selector1[lineOff]) + 2.2204460492503131E-16);

    /* part-1: top horizontal axis */
    rtB.tmpRound = floor(rtB.maxValue + 0.5);
    if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 119.0)) {
      rtB.tmpOutRC[0U] = 0;
      if (rtB.tmpRound >= 0.5) {
        rtB.tmpOutRC[1U] = (int32_T)floor(rtB.tmpRound + 0.5);
      } else {
        rtB.tmpOutRC[1U] = 0;
      }

      ky = 1;
    }

    rtB.y2 = (rtB.Selector5[lineOff] + 2.2204460492503131E-16) / (sin
      (rtB.Selector1[lineOff]) + 2.2204460492503131E-16);

    /* part-2: left vertical axis */
    rtB.tmpRound = floor(rtB.y2 + 0.5);
    if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 159.0)) {
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
      rtB.tmpRound = floor((rtB.maxValue - 119.0) * (rtB.y2 / rtB.maxValue) +
                           0.5);
      if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 159.0)) {
        if (rtB.tmpRound >= 0.5) {
          rtB.tmpOutRC[ky << 1] = (int32_T)floor(rtB.tmpRound + 0.5);
        } else {
          rtB.tmpOutRC[ky << 1] = 0;
        }

        rtB.tmpOutRC[1 + (ky << 1)] = 119;
        ky++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (ky < 2) {
      rtB.tmpRound = floor((rtB.maxValue - rtB.maxValue / rtB.y2 * 159.0) + 0.5);
      if ((rtB.tmpRound >= 0.0) && (rtB.tmpRound <= 119.0)) {
        rtB.tmpOutRC[ky << 1] = 159;
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

    rtB.HoughLines[lineOff] = rtB.tmpOutRC[1] + 1;
    rtB.HoughLines[lineOff + rtDW.Selector1_DIMS1[1]] = rtB.tmpOutRC[0] + 1;
    if (rtB.tmpOutRC[3] > 2147483646) {
      rtB.HoughLines[lineOff + (rtDW.Selector1_DIMS1[1] << 1)] = MAX_int32_T;
    } else {
      rtB.HoughLines[lineOff + (rtDW.Selector1_DIMS1[1] << 1)] = rtB.tmpOutRC[3]
        + 1;
    }

    if (rtB.tmpOutRC[2] > 2147483646) {
      rtB.HoughLines[lineOff + 3 * rtDW.Selector1_DIMS1[1]] = MAX_int32_T;
    } else {
      rtB.HoughLines[lineOff + 3 * rtDW.Selector1_DIMS1[1]] = rtB.tmpOutRC[2] +
        1;
    }
  }

  /* End of S-Function (sviphoughlines): '<Root>/Hough Lines' */

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
  memcpy(&rtB.DrawShapes[0], &rtB.MatrixConcatenate[0], 57600U * sizeof(uint8_T));
  if (done && (ky > 0)) {
    /* Update view port. */
    for (numEleTmp = 0; numEleTmp < ky; numEleTmp++) {
      iter = 0;
      rtB.accumFour = 0;
      while (rtB.accumFour < ku - 1) {
        numIter = rtB.HoughLines[((iter * ky << 1) + numEleTmp) + ky] - 1;
        col = rtB.HoughLines[(iter * ky << 1) + numEleTmp] - 1;
        iter++;
        row = rtB.HoughLines[((iter * ky << 1) + numEleTmp) + ky] - 1;
        line_idx_3 = rtB.HoughLines[(iter * ky << 1) + numEleTmp] - 1;
        if ((rtB.HoughLines[((iter * ky << 1) + numEleTmp) + ky] - 1 != numIter)
            || (rtB.HoughLines[(iter * ky << 1) + numEleTmp] - 1 != col)) {
          b2 = false;

          /* Find the visible portion of a line. */
          b3 = false;
          b4 = false;
          done = false;
          gOffset = numIter;
          lastBlockCol = col;
          rtB.curNumNonZ = row;
          hOffset = line_idx_3;
          while (!done) {
            rtB.fromIdx = 0U;
            rtB.toIdx = 0U;

            /* Determine viewport violations. */
            if (gOffset < 0) {
              rtB.fromIdx = 4U;
            } else {
              if (gOffset > 159) {
                rtB.fromIdx = 8U;
              }
            }

            if (rtB.curNumNonZ < 0) {
              rtB.toIdx = 4U;
            } else {
              if (rtB.curNumNonZ > 159) {
                rtB.toIdx = 8U;
              }
            }

            if (lastBlockCol < 0) {
              rtB.fromIdx |= 1U;
            } else {
              if (lastBlockCol > 119) {
                rtB.fromIdx |= 2U;
              }
            }

            if (hOffset < 0) {
              rtB.toIdx |= 1U;
            } else {
              if (hOffset > 119) {
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
                gOffset = numIter;
                lastBlockCol = col;
              }

              lineOff = rtB.curNumNonZ - gOffset;
              inIdx = hOffset - lastBlockCol;
              if ((lineOff > 1073741824) || (lineOff < -1073741824) || ((inIdx >
                    1073741824) || (inIdx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b3 = true;
              } else if ((rtB.fromIdx & 4U) != 0U) {
                /* Violated RMin. */
                outIdxAdj = -gOffset * inIdx;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (lineOff >= 0)) || ((outIdxAdj <
                  0) && (lineOff < 0))) {
                  lastBlockCol += (div_nde_s32_floor(outIdxAdj << 1, lineOff) +
                                   1) >> 1;
                } else {
                  lastBlockCol -= (div_nde_s32_floor(-outIdxAdj << 1, lineOff) +
                                   1) >> 1;
                }

                gOffset = 0;
                b3 = true;
              } else if ((rtB.fromIdx & 8U) != 0U) {
                /* Violated RMax. */
                outIdxAdj = (159 - gOffset) * inIdx;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (lineOff >= 0)) || ((outIdxAdj <
                  0) && (lineOff < 0))) {
                  lastBlockCol += (div_nde_s32_floor(outIdxAdj << 1, lineOff) +
                                   1) >> 1;
                } else {
                  lastBlockCol -= (div_nde_s32_floor(-outIdxAdj << 1, lineOff) +
                                   1) >> 1;
                }

                gOffset = 159;
                b3 = true;
              } else if ((rtB.fromIdx & 1U) != 0U) {
                /* Violated CMin. */
                outIdxAdj = -lastBlockCol * lineOff;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (inIdx >= 0)) || ((outIdxAdj < 0)
                            && (inIdx < 0))) {
                  gOffset += (div_nde_s32_floor(outIdxAdj << 1, inIdx) + 1) >> 1;
                } else {
                  gOffset -= (div_nde_s32_floor(-outIdxAdj << 1, inIdx) + 1) >>
                    1;
                }

                lastBlockCol = 0;
                b3 = true;
              } else {
                /* Violated CMax. */
                outIdxAdj = (119 - lastBlockCol) * lineOff;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (inIdx >= 0)) || ((outIdxAdj < 0)
                            && (inIdx < 0))) {
                  gOffset += (div_nde_s32_floor(outIdxAdj << 1, inIdx) + 1) >> 1;
                } else {
                  gOffset -= (div_nde_s32_floor(-outIdxAdj << 1, inIdx) + 1) >>
                    1;
                }

                lastBlockCol = 119;
                b3 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (b4) {
                rtB.curNumNonZ = row;
                hOffset = line_idx_3;
              }

              lineOff = rtB.curNumNonZ - gOffset;
              inIdx = hOffset - lastBlockCol;
              if ((lineOff > 1073741824) || (lineOff < -1073741824) || ((inIdx >
                    1073741824) || (inIdx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                b2 = false;
                b4 = true;
              } else if ((rtB.toIdx & 4U) != 0U) {
                /* Violated RMin. */
                outIdxAdj = -rtB.curNumNonZ * inIdx;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (lineOff >= 0)) || ((outIdxAdj <
                  0) && (lineOff < 0))) {
                  hOffset += (div_nde_s32_floor(outIdxAdj << 1, lineOff) + 1) >>
                    1;
                } else {
                  hOffset -= (div_nde_s32_floor(-outIdxAdj << 1, lineOff) + 1) >>
                    1;
                }

                rtB.curNumNonZ = 0;
                b4 = true;
              } else if ((rtB.toIdx & 8U) != 0U) {
                /* Violated RMax. */
                outIdxAdj = (159 - rtB.curNumNonZ) * inIdx;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (lineOff >= 0)) || ((outIdxAdj <
                  0) && (lineOff < 0))) {
                  hOffset += (div_nde_s32_floor(outIdxAdj << 1, lineOff) + 1) >>
                    1;
                } else {
                  hOffset -= (div_nde_s32_floor(-outIdxAdj << 1, lineOff) + 1) >>
                    1;
                }

                rtB.curNumNonZ = 159;
                b4 = true;
              } else if ((rtB.toIdx & 1U) != 0U) {
                /* Violated CMin. */
                outIdxAdj = -hOffset * lineOff;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (inIdx >= 0)) || ((outIdxAdj < 0)
                            && (inIdx < 0))) {
                  rtB.curNumNonZ += (div_nde_s32_floor(outIdxAdj << 1, inIdx) +
                                     1) >> 1;
                } else {
                  rtB.curNumNonZ -= (div_nde_s32_floor(-outIdxAdj << 1, inIdx) +
                                     1) >> 1;
                }

                hOffset = 0;
                b4 = true;
              } else {
                /* Violated CMax. */
                outIdxAdj = (119 - hOffset) * lineOff;
                if ((outIdxAdj > 1073741824) || (outIdxAdj < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  b2 = false;
                } else if (((outIdxAdj >= 0) && (inIdx >= 0)) || ((outIdxAdj < 0)
                            && (inIdx < 0))) {
                  rtB.curNumNonZ += (div_nde_s32_floor(outIdxAdj << 1, inIdx) +
                                     1) >> 1;
                } else {
                  rtB.curNumNonZ -= (div_nde_s32_floor(-outIdxAdj << 1, inIdx) +
                                     1) >> 1;
                }

                hOffset = 119;
                b4 = true;
              }
            }
          }

          if (b2) {
            /* Draw a line using Bresenham algorithm. */
            /* Initialize the Bresenham algorithm. */
            if (rtB.curNumNonZ >= gOffset) {
              row = rtB.curNumNonZ - gOffset;
            } else {
              row = gOffset - rtB.curNumNonZ;
            }

            if (hOffset >= lastBlockCol) {
              line_idx_3 = hOffset - lastBlockCol;
            } else {
              line_idx_3 = lastBlockCol - hOffset;
            }

            if (row > line_idx_3) {
              lineOff = 1;
              col = 160;
            } else {
              lineOff = 160;
              col = 1;
              inIdx = gOffset;
              gOffset = lastBlockCol;
              lastBlockCol = inIdx;
              inIdx = rtB.curNumNonZ;
              rtB.curNumNonZ = hOffset;
              hOffset = inIdx;
            }

            if (gOffset > rtB.curNumNonZ) {
              inIdx = gOffset;
              gOffset = rtB.curNumNonZ;
              rtB.curNumNonZ = inIdx;
              inIdx = lastBlockCol;
              lastBlockCol = hOffset;
              hOffset = inIdx;
            }

            inIdx = rtB.curNumNonZ - gOffset;
            if (lastBlockCol <= hOffset) {
              numIter = 1;
              outIdxAdj = hOffset - lastBlockCol;
            } else {
              numIter = -1;
              outIdxAdj = lastBlockCol - hOffset;
            }

            hOffset = -((inIdx + 1) >> 1);
            row = gOffset * lineOff + lastBlockCol * col;
            lastBlockCol = numIter * col + lineOff;
            done = (gOffset <= rtB.curNumNonZ);
            while (done) {
              rtB.DrawShapes[row] = MAX_uint8_T;
              numIter = row + 19200;
              rtB.DrawShapes[numIter] = MAX_uint8_T;
              numIter += 19200;
              rtB.DrawShapes[numIter] = MAX_uint8_T;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next pixel location. */
              hOffset += outIdxAdj;
              if (hOffset >= 0) {
                hOffset -= inIdx;
                row += lastBlockCol;
              } else {
                row += lineOff;
              }

              gOffset++;
              done = (gOffset <= rtB.curNumNonZ);
            }
          }
        }

        rtB.accumFour++;
      }
    }
  }

  /* End of S-Function (svipdrawshapes): '<Root>/Draw Shapes' */
  rtExtModeUpload(1, ((rtM->Timing.clockTick1) * 0.2));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick1++;
}

/* Model step wrapper function for compatibility with a static main program */
void lane_departure_step(int_T tid)
{
  switch (tid) {
   case 0 :
    lane_departure_step0();
    break;

   case 1 :
    lane_departure_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void lane_departure_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  rtM->Sizes.checksums[0] = (1917102677U);
  rtM->Sizes.checksums[1] = (1693815341U);
  rtM->Sizes.checksums[2] = (2059061006U);
  rtM->Sizes.checksums[3] = (728033140U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
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
    rtB.HoughTransform_o3[0] = -199.0;
    rtB.HoughTransform_o3[1] = -198.0;
    rtB.HoughTransform_o3[2] = -197.0;
    rtB.HoughTransform_o3[3] = -196.0;
    rtB.HoughTransform_o3[4] = -195.0;
    rtB.HoughTransform_o3[5] = -194.0;
    rtB.HoughTransform_o3[6] = -193.0;
    rtB.HoughTransform_o3[7] = -192.0;
    rtB.HoughTransform_o3[8] = -191.0;
    rtB.HoughTransform_o3[9] = -190.0;
    rtB.HoughTransform_o3[10] = -189.0;
    rtB.HoughTransform_o3[11] = -188.0;
    rtB.HoughTransform_o3[12] = -187.0;
    rtB.HoughTransform_o3[13] = -186.0;
    rtB.HoughTransform_o3[14] = -185.0;
    rtB.HoughTransform_o3[15] = -184.0;
    rtB.HoughTransform_o3[16] = -183.0;
    rtB.HoughTransform_o3[17] = -182.0;
    rtB.HoughTransform_o3[18] = -181.0;
    rtB.HoughTransform_o3[19] = -180.0;
    rtB.HoughTransform_o3[20] = -179.0;
    rtB.HoughTransform_o3[21] = -178.0;
    rtB.HoughTransform_o3[22] = -177.0;
    rtB.HoughTransform_o3[23] = -176.0;
    rtB.HoughTransform_o3[24] = -175.0;
    rtB.HoughTransform_o3[25] = -174.0;
    rtB.HoughTransform_o3[26] = -173.0;
    rtB.HoughTransform_o3[27] = -172.0;
    rtB.HoughTransform_o3[28] = -171.0;
    rtB.HoughTransform_o3[29] = -170.0;
    rtB.HoughTransform_o3[30] = -169.0;
    rtB.HoughTransform_o3[31] = -168.0;
    rtB.HoughTransform_o3[32] = -167.0;
    rtB.HoughTransform_o3[33] = -166.0;
    rtB.HoughTransform_o3[34] = -165.0;
    rtB.HoughTransform_o3[35] = -164.0;
    rtB.HoughTransform_o3[36] = -163.0;
    rtB.HoughTransform_o3[37] = -162.0;
    rtB.HoughTransform_o3[38] = -161.0;
    rtB.HoughTransform_o3[39] = -160.0;
    rtB.HoughTransform_o3[40] = -159.0;
    rtB.HoughTransform_o3[41] = -158.0;
    rtB.HoughTransform_o3[42] = -157.0;
    rtB.HoughTransform_o3[43] = -156.0;
    rtB.HoughTransform_o3[44] = -155.0;
    rtB.HoughTransform_o3[45] = -154.0;
    rtB.HoughTransform_o3[46] = -153.0;
    rtB.HoughTransform_o3[47] = -152.0;
    rtB.HoughTransform_o3[48] = -151.0;
    rtB.HoughTransform_o3[49] = -150.0;
    rtB.HoughTransform_o3[50] = -149.0;
    rtB.HoughTransform_o3[51] = -148.0;
    rtB.HoughTransform_o3[52] = -147.0;
    rtB.HoughTransform_o3[53] = -146.0;
    rtB.HoughTransform_o3[54] = -145.0;
    rtB.HoughTransform_o3[55] = -144.0;
    rtB.HoughTransform_o3[56] = -143.0;
    rtB.HoughTransform_o3[57] = -142.0;
    rtB.HoughTransform_o3[58] = -141.0;
    rtB.HoughTransform_o3[59] = -140.0;
    rtB.HoughTransform_o3[60] = -139.0;
    rtB.HoughTransform_o3[61] = -138.0;
    rtB.HoughTransform_o3[62] = -137.0;
    rtB.HoughTransform_o3[63] = -136.0;
    rtB.HoughTransform_o3[64] = -135.0;
    rtB.HoughTransform_o3[65] = -134.0;
    rtB.HoughTransform_o3[66] = -133.0;
    rtB.HoughTransform_o3[67] = -132.0;
    rtB.HoughTransform_o3[68] = -131.0;
    rtB.HoughTransform_o3[69] = -130.0;
    rtB.HoughTransform_o3[70] = -129.0;
    rtB.HoughTransform_o3[71] = -128.0;
    rtB.HoughTransform_o3[72] = -127.0;
    rtB.HoughTransform_o3[73] = -126.0;
    rtB.HoughTransform_o3[74] = -125.0;
    rtB.HoughTransform_o3[75] = -124.0;
    rtB.HoughTransform_o3[76] = -123.0;
    rtB.HoughTransform_o3[77] = -122.0;
    rtB.HoughTransform_o3[78] = -121.0;
    rtB.HoughTransform_o3[79] = -120.0;
    rtB.HoughTransform_o3[80] = -119.0;
    rtB.HoughTransform_o3[81] = -118.0;
    rtB.HoughTransform_o3[82] = -117.0;
    rtB.HoughTransform_o3[83] = -116.0;
    rtB.HoughTransform_o3[84] = -115.0;
    rtB.HoughTransform_o3[85] = -114.0;
    rtB.HoughTransform_o3[86] = -113.0;
    rtB.HoughTransform_o3[87] = -112.0;
    rtB.HoughTransform_o3[88] = -111.0;
    rtB.HoughTransform_o3[89] = -110.0;
    rtB.HoughTransform_o3[90] = -109.0;
    rtB.HoughTransform_o3[91] = -108.0;
    rtB.HoughTransform_o3[92] = -107.0;
    rtB.HoughTransform_o3[93] = -106.0;
    rtB.HoughTransform_o3[94] = -105.0;
    rtB.HoughTransform_o3[95] = -104.0;
    rtB.HoughTransform_o3[96] = -103.0;
    rtB.HoughTransform_o3[97] = -102.0;
    rtB.HoughTransform_o3[98] = -101.0;
    rtB.HoughTransform_o3[99] = -100.0;
    rtB.HoughTransform_o3[100] = -99.0;
    rtB.HoughTransform_o3[101] = -98.0;
    rtB.HoughTransform_o3[102] = -97.0;
    rtB.HoughTransform_o3[103] = -96.0;
    rtB.HoughTransform_o3[104] = -95.0;
    rtB.HoughTransform_o3[105] = -94.0;
    rtB.HoughTransform_o3[106] = -93.0;
    rtB.HoughTransform_o3[107] = -92.0;
    rtB.HoughTransform_o3[108] = -91.0;
    rtB.HoughTransform_o3[109] = -90.0;
    rtB.HoughTransform_o3[110] = -89.0;
    rtB.HoughTransform_o3[111] = -88.0;
    rtB.HoughTransform_o3[112] = -87.0;
    rtB.HoughTransform_o3[113] = -86.0;
    rtB.HoughTransform_o3[114] = -85.0;
    rtB.HoughTransform_o3[115] = -84.0;
    rtB.HoughTransform_o3[116] = -83.0;
    rtB.HoughTransform_o3[117] = -82.0;
    rtB.HoughTransform_o3[118] = -81.0;
    rtB.HoughTransform_o3[119] = -80.0;
    rtB.HoughTransform_o3[120] = -79.0;
    rtB.HoughTransform_o3[121] = -78.0;
    rtB.HoughTransform_o3[122] = -77.0;
    rtB.HoughTransform_o3[123] = -76.0;
    rtB.HoughTransform_o3[124] = -75.0;
    rtB.HoughTransform_o3[125] = -74.0;
    rtB.HoughTransform_o3[126] = -73.0;
    rtB.HoughTransform_o3[127] = -72.0;
    rtB.HoughTransform_o3[128] = -71.0;
    rtB.HoughTransform_o3[129] = -70.0;
    rtB.HoughTransform_o3[130] = -69.0;
    rtB.HoughTransform_o3[131] = -68.0;
    rtB.HoughTransform_o3[132] = -67.0;
    rtB.HoughTransform_o3[133] = -66.0;
    rtB.HoughTransform_o3[134] = -65.0;
    rtB.HoughTransform_o3[135] = -64.0;
    rtB.HoughTransform_o3[136] = -63.0;
    rtB.HoughTransform_o3[137] = -62.0;
    rtB.HoughTransform_o3[138] = -61.0;
    rtB.HoughTransform_o3[139] = -60.0;
    rtB.HoughTransform_o3[140] = -59.0;
    rtB.HoughTransform_o3[141] = -58.0;
    rtB.HoughTransform_o3[142] = -57.0;
    rtB.HoughTransform_o3[143] = -56.0;
    rtB.HoughTransform_o3[144] = -55.0;
    rtB.HoughTransform_o3[145] = -54.0;
    rtB.HoughTransform_o3[146] = -53.0;
    rtB.HoughTransform_o3[147] = -52.0;
    rtB.HoughTransform_o3[148] = -51.0;
    rtB.HoughTransform_o3[149] = -50.0;
    rtB.HoughTransform_o3[150] = -49.0;
    rtB.HoughTransform_o3[151] = -48.0;
    rtB.HoughTransform_o3[152] = -47.0;
    rtB.HoughTransform_o3[153] = -46.0;
    rtB.HoughTransform_o3[154] = -45.0;
    rtB.HoughTransform_o3[155] = -44.0;
    rtB.HoughTransform_o3[156] = -43.0;
    rtB.HoughTransform_o3[157] = -42.0;
    rtB.HoughTransform_o3[158] = -41.0;
    rtB.HoughTransform_o3[159] = -40.0;
    rtB.HoughTransform_o3[160] = -39.0;
    rtB.HoughTransform_o3[161] = -38.0;
    rtB.HoughTransform_o3[162] = -37.0;
    rtB.HoughTransform_o3[163] = -36.0;
    rtB.HoughTransform_o3[164] = -35.0;
    rtB.HoughTransform_o3[165] = -34.0;
    rtB.HoughTransform_o3[166] = -33.0;
    rtB.HoughTransform_o3[167] = -32.0;
    rtB.HoughTransform_o3[168] = -31.0;
    rtB.HoughTransform_o3[169] = -30.0;
    rtB.HoughTransform_o3[170] = -29.0;
    rtB.HoughTransform_o3[171] = -28.0;
    rtB.HoughTransform_o3[172] = -27.0;
    rtB.HoughTransform_o3[173] = -26.0;
    rtB.HoughTransform_o3[174] = -25.0;
    rtB.HoughTransform_o3[175] = -24.0;
    rtB.HoughTransform_o3[176] = -23.0;
    rtB.HoughTransform_o3[177] = -22.0;
    rtB.HoughTransform_o3[178] = -21.0;
    rtB.HoughTransform_o3[179] = -20.0;
    rtB.HoughTransform_o3[180] = -19.0;
    rtB.HoughTransform_o3[181] = -18.0;
    rtB.HoughTransform_o3[182] = -17.0;
    rtB.HoughTransform_o3[183] = -16.0;
    rtB.HoughTransform_o3[184] = -15.0;
    rtB.HoughTransform_o3[185] = -14.0;
    rtB.HoughTransform_o3[186] = -13.0;
    rtB.HoughTransform_o3[187] = -12.0;
    rtB.HoughTransform_o3[188] = -11.0;
    rtB.HoughTransform_o3[189] = -10.0;
    rtB.HoughTransform_o3[190] = -9.0;
    rtB.HoughTransform_o3[191] = -8.0;
    rtB.HoughTransform_o3[192] = -7.0;
    rtB.HoughTransform_o3[193] = -6.0;
    rtB.HoughTransform_o3[194] = -5.0;
    rtB.HoughTransform_o3[195] = -4.0;
    rtB.HoughTransform_o3[196] = -3.0;
    rtB.HoughTransform_o3[197] = -2.0;
    rtB.HoughTransform_o3[198] = -1.0;
    rtB.HoughTransform_o3[200] = 1.0;
    rtB.HoughTransform_o3[201] = 2.0;
    rtB.HoughTransform_o3[202] = 3.0;
    rtB.HoughTransform_o3[203] = 4.0;
    rtB.HoughTransform_o3[204] = 5.0;
    rtB.HoughTransform_o3[205] = 6.0;
    rtB.HoughTransform_o3[206] = 7.0;
    rtB.HoughTransform_o3[207] = 8.0;
    rtB.HoughTransform_o3[208] = 9.0;
    rtB.HoughTransform_o3[209] = 10.0;
    rtB.HoughTransform_o3[210] = 11.0;
    rtB.HoughTransform_o3[211] = 12.0;
    rtB.HoughTransform_o3[212] = 13.0;
    rtB.HoughTransform_o3[213] = 14.0;
    rtB.HoughTransform_o3[214] = 15.0;
    rtB.HoughTransform_o3[215] = 16.0;
    rtB.HoughTransform_o3[216] = 17.0;
    rtB.HoughTransform_o3[217] = 18.0;
    rtB.HoughTransform_o3[218] = 19.0;
    rtB.HoughTransform_o3[219] = 20.0;
    rtB.HoughTransform_o3[220] = 21.0;
    rtB.HoughTransform_o3[221] = 22.0;
    rtB.HoughTransform_o3[222] = 23.0;
    rtB.HoughTransform_o3[223] = 24.0;
    rtB.HoughTransform_o3[224] = 25.0;
    rtB.HoughTransform_o3[225] = 26.0;
    rtB.HoughTransform_o3[226] = 27.0;
    rtB.HoughTransform_o3[227] = 28.0;
    rtB.HoughTransform_o3[228] = 29.0;
    rtB.HoughTransform_o3[229] = 30.0;
    rtB.HoughTransform_o3[230] = 31.0;
    rtB.HoughTransform_o3[231] = 32.0;
    rtB.HoughTransform_o3[232] = 33.0;
    rtB.HoughTransform_o3[233] = 34.0;
    rtB.HoughTransform_o3[234] = 35.0;
    rtB.HoughTransform_o3[235] = 36.0;
    rtB.HoughTransform_o3[236] = 37.0;
    rtB.HoughTransform_o3[237] = 38.0;
    rtB.HoughTransform_o3[238] = 39.0;
    rtB.HoughTransform_o3[239] = 40.0;
    rtB.HoughTransform_o3[240] = 41.0;
    rtB.HoughTransform_o3[241] = 42.0;
    rtB.HoughTransform_o3[242] = 43.0;
    rtB.HoughTransform_o3[243] = 44.0;
    rtB.HoughTransform_o3[244] = 45.0;
    rtB.HoughTransform_o3[245] = 46.0;
    rtB.HoughTransform_o3[246] = 47.0;
    rtB.HoughTransform_o3[247] = 48.0;
    rtB.HoughTransform_o3[248] = 49.0;
    rtB.HoughTransform_o3[249] = 50.0;
    rtB.HoughTransform_o3[250] = 51.0;
    rtB.HoughTransform_o3[251] = 52.0;
    rtB.HoughTransform_o3[252] = 53.0;
    rtB.HoughTransform_o3[253] = 54.0;
    rtB.HoughTransform_o3[254] = 55.0;
    rtB.HoughTransform_o3[255] = 56.0;
    rtB.HoughTransform_o3[256] = 57.0;
    rtB.HoughTransform_o3[257] = 58.0;
    rtB.HoughTransform_o3[258] = 59.0;
    rtB.HoughTransform_o3[259] = 60.0;
    rtB.HoughTransform_o3[260] = 61.0;
    rtB.HoughTransform_o3[261] = 62.0;
    rtB.HoughTransform_o3[262] = 63.0;
    rtB.HoughTransform_o3[263] = 64.0;
    rtB.HoughTransform_o3[264] = 65.0;
    rtB.HoughTransform_o3[265] = 66.0;
    rtB.HoughTransform_o3[266] = 67.0;
    rtB.HoughTransform_o3[267] = 68.0;
    rtB.HoughTransform_o3[268] = 69.0;
    rtB.HoughTransform_o3[269] = 70.0;
    rtB.HoughTransform_o3[270] = 71.0;
    rtB.HoughTransform_o3[271] = 72.0;
    rtB.HoughTransform_o3[272] = 73.0;
    rtB.HoughTransform_o3[273] = 74.0;
    rtB.HoughTransform_o3[274] = 75.0;
    rtB.HoughTransform_o3[275] = 76.0;
    rtB.HoughTransform_o3[276] = 77.0;
    rtB.HoughTransform_o3[277] = 78.0;
    rtB.HoughTransform_o3[278] = 79.0;
    rtB.HoughTransform_o3[279] = 80.0;
    rtB.HoughTransform_o3[280] = 81.0;
    rtB.HoughTransform_o3[281] = 82.0;
    rtB.HoughTransform_o3[282] = 83.0;
    rtB.HoughTransform_o3[283] = 84.0;
    rtB.HoughTransform_o3[284] = 85.0;
    rtB.HoughTransform_o3[285] = 86.0;
    rtB.HoughTransform_o3[286] = 87.0;
    rtB.HoughTransform_o3[287] = 88.0;
    rtB.HoughTransform_o3[288] = 89.0;
    rtB.HoughTransform_o3[289] = 90.0;
    rtB.HoughTransform_o3[290] = 91.0;
    rtB.HoughTransform_o3[291] = 92.0;
    rtB.HoughTransform_o3[292] = 93.0;
    rtB.HoughTransform_o3[293] = 94.0;
    rtB.HoughTransform_o3[294] = 95.0;
    rtB.HoughTransform_o3[295] = 96.0;
    rtB.HoughTransform_o3[296] = 97.0;
    rtB.HoughTransform_o3[297] = 98.0;
    rtB.HoughTransform_o3[298] = 99.0;
    rtB.HoughTransform_o3[299] = 100.0;
    rtB.HoughTransform_o3[300] = 101.0;
    rtB.HoughTransform_o3[301] = 102.0;
    rtB.HoughTransform_o3[302] = 103.0;
    rtB.HoughTransform_o3[303] = 104.0;
    rtB.HoughTransform_o3[304] = 105.0;
    rtB.HoughTransform_o3[305] = 106.0;
    rtB.HoughTransform_o3[306] = 107.0;
    rtB.HoughTransform_o3[307] = 108.0;
    rtB.HoughTransform_o3[308] = 109.0;
    rtB.HoughTransform_o3[309] = 110.0;
    rtB.HoughTransform_o3[310] = 111.0;
    rtB.HoughTransform_o3[311] = 112.0;
    rtB.HoughTransform_o3[312] = 113.0;
    rtB.HoughTransform_o3[313] = 114.0;
    rtB.HoughTransform_o3[314] = 115.0;
    rtB.HoughTransform_o3[315] = 116.0;
    rtB.HoughTransform_o3[316] = 117.0;
    rtB.HoughTransform_o3[317] = 118.0;
    rtB.HoughTransform_o3[318] = 119.0;
    rtB.HoughTransform_o3[319] = 120.0;
    rtB.HoughTransform_o3[320] = 121.0;
    rtB.HoughTransform_o3[321] = 122.0;
    rtB.HoughTransform_o3[322] = 123.0;
    rtB.HoughTransform_o3[323] = 124.0;
    rtB.HoughTransform_o3[324] = 125.0;
    rtB.HoughTransform_o3[325] = 126.0;
    rtB.HoughTransform_o3[326] = 127.0;
    rtB.HoughTransform_o3[327] = 128.0;
    rtB.HoughTransform_o3[328] = 129.0;
    rtB.HoughTransform_o3[329] = 130.0;
    rtB.HoughTransform_o3[330] = 131.0;
    rtB.HoughTransform_o3[331] = 132.0;
    rtB.HoughTransform_o3[332] = 133.0;
    rtB.HoughTransform_o3[333] = 134.0;
    rtB.HoughTransform_o3[334] = 135.0;
    rtB.HoughTransform_o3[335] = 136.0;
    rtB.HoughTransform_o3[336] = 137.0;
    rtB.HoughTransform_o3[337] = 138.0;
    rtB.HoughTransform_o3[338] = 139.0;
    rtB.HoughTransform_o3[339] = 140.0;
    rtB.HoughTransform_o3[340] = 141.0;
    rtB.HoughTransform_o3[341] = 142.0;
    rtB.HoughTransform_o3[342] = 143.0;
    rtB.HoughTransform_o3[343] = 144.0;
    rtB.HoughTransform_o3[344] = 145.0;
    rtB.HoughTransform_o3[345] = 146.0;
    rtB.HoughTransform_o3[346] = 147.0;
    rtB.HoughTransform_o3[347] = 148.0;
    rtB.HoughTransform_o3[348] = 149.0;
    rtB.HoughTransform_o3[349] = 150.0;
    rtB.HoughTransform_o3[350] = 151.0;
    rtB.HoughTransform_o3[351] = 152.0;
    rtB.HoughTransform_o3[352] = 153.0;
    rtB.HoughTransform_o3[353] = 154.0;
    rtB.HoughTransform_o3[354] = 155.0;
    rtB.HoughTransform_o3[355] = 156.0;
    rtB.HoughTransform_o3[356] = 157.0;
    rtB.HoughTransform_o3[357] = 158.0;
    rtB.HoughTransform_o3[358] = 159.0;
    rtB.HoughTransform_o3[359] = 160.0;
    rtB.HoughTransform_o3[360] = 161.0;
    rtB.HoughTransform_o3[361] = 162.0;
    rtB.HoughTransform_o3[362] = 163.0;
    rtB.HoughTransform_o3[363] = 164.0;
    rtB.HoughTransform_o3[364] = 165.0;
    rtB.HoughTransform_o3[365] = 166.0;
    rtB.HoughTransform_o3[366] = 167.0;
    rtB.HoughTransform_o3[367] = 168.0;
    rtB.HoughTransform_o3[368] = 169.0;
    rtB.HoughTransform_o3[369] = 170.0;
    rtB.HoughTransform_o3[370] = 171.0;
    rtB.HoughTransform_o3[371] = 172.0;
    rtB.HoughTransform_o3[372] = 173.0;
    rtB.HoughTransform_o3[373] = 174.0;
    rtB.HoughTransform_o3[374] = 175.0;
    rtB.HoughTransform_o3[375] = 176.0;
    rtB.HoughTransform_o3[376] = 177.0;
    rtB.HoughTransform_o3[377] = 178.0;
    rtB.HoughTransform_o3[378] = 179.0;
    rtB.HoughTransform_o3[379] = 180.0;
    rtB.HoughTransform_o3[380] = 181.0;
    rtB.HoughTransform_o3[381] = 182.0;
    rtB.HoughTransform_o3[382] = 183.0;
    rtB.HoughTransform_o3[383] = 184.0;
    rtB.HoughTransform_o3[384] = 185.0;
    rtB.HoughTransform_o3[385] = 186.0;
    rtB.HoughTransform_o3[386] = 187.0;
    rtB.HoughTransform_o3[387] = 188.0;
    rtB.HoughTransform_o3[388] = 189.0;
    rtB.HoughTransform_o3[389] = 190.0;
    rtB.HoughTransform_o3[390] = 191.0;
    rtB.HoughTransform_o3[391] = 192.0;
    rtB.HoughTransform_o3[392] = 193.0;
    rtB.HoughTransform_o3[393] = 194.0;
    rtB.HoughTransform_o3[394] = 195.0;
    rtB.HoughTransform_o3[395] = 196.0;
    rtB.HoughTransform_o3[396] = 197.0;
    rtB.HoughTransform_o3[397] = 198.0;
    rtB.HoughTransform_o3[398] = 199.0;
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rtM->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  {
    int32_T previous;
    int32_T step;
    boolean_T isValid;
    int32_T idxOut;
    int32_T curNumNonZ;
    int32_T n;
    int32_T m;

    /* Start for S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
    MW_videoCaptureInit(rtConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 160U, 120U, 2U,
                        2U, 1U, 0.2);

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

      idxOut += 163;
      n++;
    }

    if (isValid && (curNumNonZ >= 4)) {
      if (step == 167) {
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

      idxOut += 166;
      n++;
    }

    if (isValid && (curNumNonZ >= 4)) {
      if (step == 167) {
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
        rtDW.Erosion_ERODE_OFF_DW[previous] = n * 167;
        curNumNonZ++;
        previous++;
        m = 1;
      }
    }

    rtDW.Erosion_NUMNONZ_DW[1] = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<Root>/Erosion' */

    /* Start for S-Function (svipedge): '<Root>/Edge Detection' */
    rtDW.EdgeDetection_MEAN_FACTOR_DW = 111848;
    for (previous = 0; previous < 6; previous++) {
      rtDW.EdgeDetection_VO_DW[previous] =
        rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
        rtConstP.EdgeDetection_VCO_RTP[previous];
      if (rtConstP.EdgeDetection_VCO_RTP[previous] > 0) {
        rtDW.EdgeDetection_VOU_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOD_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160;
      } else {
        rtDW.EdgeDetection_VOU_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160;
        rtDW.EdgeDetection_VOD_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      if (rtConstP.EdgeDetection_VRO_RTP[previous] > 0) {
        rtDW.EdgeDetection_VOL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOR_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
      } else {
        rtDW.EdgeDetection_VOL_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_VOUL_DW[previous] = 0;
        rtDW.EdgeDetection_VOLR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOLL_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOUR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160;
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_VOLL_DW[previous] = 0;
        rtDW.EdgeDetection_VOUR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOUL_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOLR_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160;
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_VOUR_DW[previous] = 0;
        rtDW.EdgeDetection_VOLL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOUL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160;
        rtDW.EdgeDetection_VOLR_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_VCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_VRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_VOLR_DW[previous] = 0;
        rtDW.EdgeDetection_VOUL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_VCO_RTP[previous];
        rtDW.EdgeDetection_VOLL_DW[previous] =
          rtConstP.EdgeDetection_VRO_RTP[previous] * 160;
        rtDW.EdgeDetection_VOUR_DW[previous] =
          rtConstP.EdgeDetection_VCO_RTP[previous];
      }

      rtDW.EdgeDetection_HO_DW[previous] =
        rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
        rtConstP.EdgeDetection_HCO_RTP[previous];
      if (rtConstP.EdgeDetection_HCO_RTP[previous] > 0) {
        rtDW.EdgeDetection_HOU_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOD_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160;
      } else {
        rtDW.EdgeDetection_HOU_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160;
        rtDW.EdgeDetection_HOD_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }

      if (rtConstP.EdgeDetection_HRO_RTP[previous] > 0) {
        rtDW.EdgeDetection_HOL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOR_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
      } else {
        rtDW.EdgeDetection_HOL_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_HOUL_DW[previous] = 0;
        rtDW.EdgeDetection_HOLR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOLL_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOUR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160;
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] < 0)) {
        rtDW.EdgeDetection_HOLL_DW[previous] = 0;
        rtDW.EdgeDetection_HOUR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOUL_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOLR_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160;
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] < 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_HOUR_DW[previous] = 0;
        rtDW.EdgeDetection_HOLL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOUL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160;
        rtDW.EdgeDetection_HOLR_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }

      if ((rtConstP.EdgeDetection_HCO_RTP[previous] >= 0) &&
          (rtConstP.EdgeDetection_HRO_RTP[previous] >= 0)) {
        rtDW.EdgeDetection_HOLR_DW[previous] = 0;
        rtDW.EdgeDetection_HOUL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160 +
          rtConstP.EdgeDetection_HCO_RTP[previous];
        rtDW.EdgeDetection_HOLL_DW[previous] =
          rtConstP.EdgeDetection_HRO_RTP[previous] * 160;
        rtDW.EdgeDetection_HOUR_DW[previous] =
          rtConstP.EdgeDetection_HCO_RTP[previous];
      }
    }

    /* End of Start for S-Function (svipedge): '<Root>/Edge Detection' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
