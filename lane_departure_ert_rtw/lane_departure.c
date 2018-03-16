/*
 * File: lane_departure.c
 *
 * Code generated for Simulink model 'lane_departure'.
 *
 * Model version                  : 1.270
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Mar 17 02:20:35 2018
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
#include "phlnjecbbimokfkf_imrotate.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (auto storage) */
B rtB;

/* Block states (auto storage) */
DW rtDW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern const uint8_T rtCP_pooled_twUID13wkc9R[12];

#define rtCP_V4L2VideoCapture_p1       rtCP_pooled_twUID13wkc9R  /* Expression: devName
                                                                  * Referenced by: '<S1>/V4L2 Video Capture'
                                                                  */

extern void lane_departure_step0(void);
extern void lane_departure_step1(void);
static void rate_monotonic_scheduler(void);

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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  rtM->Timing.RateInteraction.TID0_1 = (rtM->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.2s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void lane_departure_step0(void)        /* Sample time: [0.02s, 0.0s] */
{
  uint8_T tmp;
  int32_T i;
  int32_T k;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
  MW_videoCaptureOutput(rtCP_V4L2VideoCapture_p1, rtB.V4L2VideoCapture_o1,
                        rtB.V4L2VideoCapture_o2, rtB.V4L2VideoCapture_o3);

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'Input /MATLAB Function': '<S2>:1' */
  /* '<S2>:1:2' Image = imrotate(I,90,'bilinear'); */
  memcpy(&rtB.uv0[0], &rtB.V4L2VideoCapture_o1[0], 76800U * sizeof(uint8_T));
  phlnjecbbimokfkf_imrotate(rtB.uv0, rtB.Image);

  /* '<S2>:1:3' Image = flip(Image,2); */
  for (i = 0; i < 240; i++) {
    for (k = 0; k < 160; k++) {
      tmp = rtB.Image[k * 240 + i];
      rtB.Image[i + k * 240] = rtB.Image[(319 - k) * 240 + i];
      rtB.Image[i + (319 - k) * 240] = tmp;
    }
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* RateTransition: '<Root>/TmpRTBAtLaneDetectionInport1' */
  if (rtM->Timing.RateInteraction.TID0_1) {
    memcpy(&rtB.TmpRTBAtLaneDetectionInport1[0], &rtB.Image[0], 76800U * sizeof
           (uint8_T));
  }

  /* End of RateTransition: '<Root>/TmpRTBAtLaneDetectionInport1' */

  /* Outport: '<Root>/Brightness' */
  memcpy(&rtY.Brightness[0], &rtB.Image[0], 76800U * sizeof(uint8_T));

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, rtM->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
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
  /* ModelReference: '<Root>/LaneDetection' incorporates:
   *  Constant: '<Root>/DummySupporLefttLine'
   */
  LaneDetection(&rtB.TmpRTBAtLaneDetectionInport1[0],
                &rtP.DummySupporLefttLine_Value[0], &rtB.LaneDetection_o1[0],
                &rtDW.LaneDetection_DIMS1[0], &rtB.LaneDetection_o2[0],
                &rtDW.LaneDetection_DIMS2[0], &rtB.LaneDetection_o3[0],
                &rtB.LaneDetection_o4[0], &rtB.LaneDetection_o5,
                &rtB.LaneDetection_o6[0], &rtDW.LaneDetection_DIMS6[0],
                &(rtDW.LaneDetection_DWORK1.rtdw));

  /* Outport: '<Root>/Angle' */
  rtY.Angle = rtB.LaneDetection_o5;
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

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(rtM, -1);
  rtM->Timing.stepSize0 = 0.02;

  /* External mode info */
  rtM->Sizes.checksums[0] = (1651074697U);
  rtM->Sizes.checksums[1] = (975594651U);
  rtM->Sizes.checksums[2] = (3688910865U);
  rtM->Sizes.checksums[3] = (1969783294U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/LaneDetection' */
  LaneDetection_initialize(rtmGetErrorStatusPointer(rtM),
    &(rtDW.LaneDetection_DWORK1.rtm), &(rtDW.LaneDetection_DWORK1.rtdw));

  /* Start for S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
  MW_videoCaptureInit(rtCP_V4L2VideoCapture_p1, 0, 0, 0, 0, 320U, 240U, 1U, 2U,
                      1U, 0.02);

  /* Start for ModelReference: '<Root>/LaneDetection' incorporates:
   *  Constant: '<Root>/DummySupporLefttLine'
   */
  LaneDetection_Start(&(rtDW.LaneDetection_DWORK1.rtdw));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
