/*
 * File: lane_departure.c
 *
 * Code generated for Simulink model 'lane_departure'.
 *
 * Model version                  : 1.210
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Mar 12 22:40:41 2018
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
#include "rt_roundd_snf.h"

/* Named constants for Chart: '<S2>/Chart' */
#define IN_ErrorLane                   ((uint8_T)1U)
#define IN_FindTypeTrackingLane        ((uint8_T)2U)
#define IN_NoLane                      ((uint8_T)3U)
#define IN_OneLane                     ((uint8_T)4U)
#define IN_PerfectLane                 ((uint8_T)5U)

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

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern const uint8_T rtCP_pooled_twUID13wkc9R[12];

#define rtCP_V4L2VideoCapture_p1       rtCP_pooled_twUID13wkc9R  /* Expression: devName
                                                                  * Referenced by: '<S1>/V4L2 Video Capture'
                                                                  */

extern void lane_departure_step0(void);
extern void lane_departure_step1(void);

/* Forward declaration for local functions */
static void phlnjecbbimokfkf_imrotate(const uint8_T varargin_1[76800], uint8_T
  B_0[76800]);
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.2s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S1>/MATLAB Function' */
static void phlnjecbbimokfkf_imrotate(const uint8_T varargin_1[76800], uint8_T
  B_0[76800])
{
  for (rtB.i_m = 0; rtB.i_m < 240; rtB.i_m++) {
    for (rtB.j = 0; rtB.j < 320; rtB.j++) {
      B_0[rtB.i_m + 240 * rtB.j] = varargin_1[(239 - rtB.i_m) * 320 + rtB.j];
    }
  }
}

/* Model step function for TID0 */
void lane_departure_step0(void)        /* Sample time: [0.04s, 0.0s] */
{
  {                                    /* Sample time: [0.04s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, rtM->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.04s, 0.0s] */
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
  /* S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
  MW_videoCaptureOutput(rtCP_V4L2VideoCapture_p1, rtB.V4L2VideoCapture_o1,
                        rtB.V4L2VideoCapture_o2, rtB.V4L2VideoCapture_o3);

  /* MATLAB Function: '<S1>/MATLAB Function' */
  /* MATLAB Function 'Input /MATLAB Function': '<S3>:1' */
  /* '<S3>:1:2' Image = imrotate(I,90,'bilinear'); */
  memcpy(&rtB.uv0[0], &rtB.V4L2VideoCapture_o1[0], 76800U * sizeof(uint8_T));
  phlnjecbbimokfkf_imrotate(rtB.uv0, rtB.Image);

  /* '<S3>:1:3' Image = flip(Image,2); */
  for (rtB.i = 0; rtB.i < 240; rtB.i++) {
    for (rtB.closetLeft = 0; rtB.closetLeft < 160; rtB.closetLeft++) {
      rtB.tmp = rtB.Image[rtB.closetLeft * 240 + rtB.i];
      rtB.Image[rtB.i + rtB.closetLeft * 240] = rtB.Image[(319 - rtB.closetLeft)
        * 240 + rtB.i];
      rtB.Image[rtB.i + (319 - rtB.closetLeft) * 240] = rtB.tmp;
    }
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* ModelReference: '<Root>/ROI' incorporates:
   *  Constant: '<Root>/ROI_X'
   *  Constant: '<Root>/ROI_Y'
   */
  Region_of_Interest(&rtB.Image[0], &rtP.ROI_X_Value[0], &rtP.ROI_Y_Value[0],
                     &rtB.ROI[0]);

  /* ModelReference: '<Root>/LaneDetection' */
  LaneDetection(&rtB.ROI[0], &rtB.LaneDetection_o1[0],
                &rtDW.LaneDetection_DIMS1[0], &rtB.LaneDetection_o2[0],
                &rtDW.LaneDetection_DIMS2[0], &rtB.LaneDetection_o3[0],
                &rtB.LaneDetection_o4[0], &(rtDW.LaneDetection_DWORK1.rtdw));

  /* MATLAB Function: '<S2>/Find Closest Lane' incorporates:
   *  Constant: '<Root>/SIZE_ROI_X'
   *  Constant: '<Root>/SIZE_ROI_Y'
   */
  /* MATLAB Function 'LaneDeparture/Find Closest Lane': '<S6>:1' */
  /* '<S6>:1:2' LeftClosetPts = int32([0 0 0 0]); */
  /* '<S6>:1:3' RightClosetPts = int32([0 0 0 0]); */
  rtB.LeftClosetPts[0] = 0;
  rtB.RightClosetPts[0] = 0;
  rtB.LeftClosetPts[1] = 0;
  rtB.RightClosetPts[1] = 0;
  rtB.LeftClosetPts[2] = 0;
  rtB.RightClosetPts[2] = 0;
  rtB.LeftClosetPts[3] = 0;
  rtB.RightClosetPts[3] = 0;

  /* '<S6>:1:4' closetLeft = int32(9999); */
  rtB.closetLeft = 9999;

  /* '<S6>:1:5' closetRight = int32(9999); */
  rtB.closetRight = 9999;

  /* '<S6>:1:6' [mx,~] = size(LinePts); */
  /* '<S6>:1:6' ~ */
  /* '<S6>:1:7' for i=1:mx */
  rtB.i = 0;
  while (rtB.i <= rtDW.LaneDetection_DIMS1[0] - 1) {
    /* '<S6>:1:8' x = ( 0 - SIZE_ROI_Y - LinePts(i,2) )/Slope(i) + LinePts(i,1); */
    rtB.d0 = rt_roundd_snf((0.0 - rtP.SIZE_ROI_Y_Value) - (real_T)
      rtB.LaneDetection_o1[rtB.i + rtDW.LaneDetection_DIMS1[0]]);
    if (rtB.d0 < 2.147483648E+9) {
      if (rtB.d0 >= -2.147483648E+9) {
        rtB.q0 = (int32_T)rtB.d0;
      } else {
        rtB.q0 = MIN_int32_T;
      }
    } else {
      rtB.q0 = MAX_int32_T;
    }

    rtB.d0 = rt_roundd_snf((real_T)rtB.q0 / rtB.LaneDetection_o2[rtB.i]);
    if (rtB.d0 < 2.147483648E+9) {
      if (rtB.d0 >= -2.147483648E+9) {
        rtB.q0 = (int32_T)rtB.d0;
      } else {
        rtB.q0 = MIN_int32_T;
      }
    } else {
      rtB.q0 = MAX_int32_T;
    }

    if ((rtB.q0 < 0) && (rtB.LaneDetection_o1[rtB.i] < MIN_int32_T - rtB.q0)) {
      rtB.qY = MIN_int32_T;
    } else if ((rtB.q0 > 0) && (rtB.LaneDetection_o1[rtB.i] > MAX_int32_T
                - rtB.q0)) {
      rtB.qY = MAX_int32_T;
    } else {
      rtB.qY = rtB.q0 + rtB.LaneDetection_o1[rtB.i];
    }

    /* '<S6>:1:9' leftDiff = SIZE_ROI_X/2 - x; */
    rtB.d0 = rt_roundd_snf(rtP.SIZE_ROI_X_Value / 2.0 - (real_T)rtB.qY);
    if (rtB.d0 < 2.147483648E+9) {
      if (rtB.d0 >= -2.147483648E+9) {
        rtB.q0 = (int32_T)rtB.d0;
      } else {
        rtB.q0 = MIN_int32_T;
      }
    } else {
      rtB.q0 = MAX_int32_T;
    }

    /* '<S6>:1:10' rightDiff = x - SIZE_ROI_X; */
    rtB.d0 = rt_roundd_snf((real_T)rtB.qY - rtP.SIZE_ROI_X_Value);
    if (rtB.d0 < 2.147483648E+9) {
      if (rtB.d0 >= -2.147483648E+9) {
        rtB.qY = (int32_T)rtB.d0;
      } else {
        rtB.qY = MIN_int32_T;
      }
    } else {
      rtB.qY = MAX_int32_T;
    }

    /* '<S6>:1:11' if closetLeft > leftDiff(1) */
    if (rtB.closetLeft > rtB.q0) {
      /* '<S6>:1:12' closetLeft = leftDiff(1); */
      rtB.closetLeft = rtB.q0;

      /* '<S6>:1:13' LeftClosetPts = LinePts(i,1:4); */
      rtB.LeftClosetPts[0] = rtB.LaneDetection_o1[rtB.i];
      rtB.LeftClosetPts[1] = rtB.LaneDetection_o1[rtB.i +
        rtDW.LaneDetection_DIMS1[0]];
      rtB.LeftClosetPts[2] = rtB.LaneDetection_o1[(rtDW.LaneDetection_DIMS1[0] <<
        1) + rtB.i];
      rtB.LeftClosetPts[3] = rtB.LaneDetection_o1[rtDW.LaneDetection_DIMS1[0] *
        3 + rtB.i];
    }

    /* '<S6>:1:16' if closetRight > rightDiff(1) */
    if (rtB.closetRight > rtB.qY) {
      /* '<S6>:1:17' closetRight = rightDiff(1); */
      rtB.closetRight = rtB.qY;

      /* '<S6>:1:18' RightClosetPts = LinePts(i,1:4); */
      rtB.RightClosetPts[0] = rtB.LaneDetection_o1[rtB.i];
      rtB.RightClosetPts[1] = rtB.LaneDetection_o1[rtB.i +
        rtDW.LaneDetection_DIMS1[0]];
      rtB.RightClosetPts[2] = rtB.LaneDetection_o1[(rtDW.LaneDetection_DIMS1[0] <<
        1) + rtB.i];
      rtB.RightClosetPts[3] = rtB.LaneDetection_o1[rtDW.LaneDetection_DIMS1[0] *
        3 + rtB.i];
    }

    rtB.i++;
  }

  /* End of MATLAB Function: '<S2>/Find Closest Lane' */

  /* Abs: '<S7>/Abs' incorporates:
   *  Constant: '<Root>/SIZE_ROI_X'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Product: '<S7>/Divide1'
   *  Selector: '<S7>/Selector2'
   *  Sum: '<S7>/Subtract1'
   */
  rtB.Abs = fabs((real_T)rtB.LeftClosetPts[(int32_T)rtP.Constant3_Value - 1] -
                 rtP.SIZE_ROI_X_Value / rtP.Constant2_Value);

  /* Chart: '<S2>/Chart' */
  /* Gateway: LaneDeparture/Chart */
  /* During: LaneDeparture/Chart */
  if (rtDW.is_active_c4_lane_departure == 0U) {
    /* Entry: LaneDeparture/Chart */
    rtDW.is_active_c4_lane_departure = 1U;

    /* Entry Internal: LaneDeparture/Chart */
    /* Transition: '<S5>:28' */
    rtDW.is_c4_lane_departure = IN_FindTypeTrackingLane;

    /* Entry 'FindTypeTrackingLane': '<S5>:27' */
    /* '<S5>:27:1' numberLane = 1; */
    rtDW.numberLane = 1.0;
  } else {
    switch (rtDW.is_c4_lane_departure) {
     case IN_ErrorLane:
      /* During 'ErrorLane': '<S5>:35' */
      /* Transition: '<S5>:47' */
      rtDW.is_c4_lane_departure = IN_FindTypeTrackingLane;

      /* Entry 'FindTypeTrackingLane': '<S5>:27' */
      /* '<S5>:27:1' numberLane = 1; */
      rtDW.numberLane = 1.0;
      break;

     case IN_FindTypeTrackingLane:
      /* During 'FindTypeTrackingLane': '<S5>:27' */
      /* '<S5>:39:1' sf_internal_predicateOutput = ... */
      /* '<S5>:39:1' numberLane == 1; */
      if (rtDW.numberLane == 1.0) {
        /* Transition: '<S5>:39' */
        rtDW.is_c4_lane_departure = IN_OneLane;
      } else {
        /* '<S5>:36:1' sf_internal_predicateOutput = ... */
        /* '<S5>:36:1' numberLane == 2; */
        if (rtDW.numberLane == 2.0) {
          /* Transition: '<S5>:36' */
          rtDW.is_c4_lane_departure = IN_PerfectLane;
        } else {
          /* '<S5>:40:1' sf_internal_predicateOutput = ... */
          /* '<S5>:40:1' numberLane == 0; */
          if (rtDW.numberLane == 0.0) {
            /* Transition: '<S5>:40' */
            rtDW.is_c4_lane_departure = IN_NoLane;
          } else {
            /* '<S5>:42:1' sf_internal_predicateOutput = ... */
            /* '<S5>:42:1' numberLane == -1; */
            if (rtDW.numberLane == -1.0) {
              /* Transition: '<S5>:42' */
              rtDW.is_c4_lane_departure = IN_ErrorLane;
            }
          }
        }
      }
      break;

     case IN_NoLane:
      /* During 'NoLane': '<S5>:34' */
      /* Transition: '<S5>:46' */
      rtDW.is_c4_lane_departure = IN_FindTypeTrackingLane;

      /* Entry 'FindTypeTrackingLane': '<S5>:27' */
      /* '<S5>:27:1' numberLane = 1; */
      rtDW.numberLane = 1.0;
      break;

     case IN_OneLane:
      /* During 'OneLane': '<S5>:33' */
      /* Transition: '<S5>:45' */
      rtDW.is_c4_lane_departure = IN_FindTypeTrackingLane;

      /* Entry 'FindTypeTrackingLane': '<S5>:27' */
      /* '<S5>:27:1' numberLane = 1; */
      rtDW.numberLane = 1.0;
      break;

     default:
      /* During 'PerfectLane': '<S5>:32' */
      /* Transition: '<S5>:44' */
      rtDW.is_c4_lane_departure = IN_FindTypeTrackingLane;

      /* Entry 'FindTypeTrackingLane': '<S5>:27' */
      /* '<S5>:27:1' numberLane = 1; */
      rtDW.numberLane = 1.0;
      break;
    }
  }

  /* End of Chart: '<S2>/Chart' */
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
  rtM->Timing.stepSize0 = 0.04;

  /* External mode info */
  rtM->Sizes.checksums[0] = (300995268U);
  rtM->Sizes.checksums[1] = (3126738980U);
  rtM->Sizes.checksums[2] = (1789535886U);
  rtM->Sizes.checksums[3] = (3564134869U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    rtM->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 16;
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

  /* Model Initialize fcn for ModelReference Block: '<Root>/ROI' */
  Region_of_Interest_initialize(rtmGetErrorStatusPointer(rtM),
    &(rtDW.ROI_DWORK1.rtm));

  /* Start for S-Function (v4l2_video_capture_sfcn): '<S1>/V4L2 Video Capture' */
  MW_videoCaptureInit(rtCP_V4L2VideoCapture_p1, 0, 0, 0, 0, 320U, 240U, 1U, 2U,
                      1U, -1.0);

  /* Start for ModelReference: '<Root>/LaneDetection' */
  LaneDetection_Start(&(rtDW.LaneDetection_DWORK1.rtdw));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
