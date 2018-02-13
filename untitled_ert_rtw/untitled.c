/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Feb 13 19:11:27 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Block states (auto storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  /* S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureOutput(untitled_ConstP.V4L2VideoCapture_p1,
                        untitled_B.V4L2VideoCapture_o1,
                        untitled_B.V4L2VideoCapture_o2,
                        untitled_B.V4L2VideoCapture_o3);

  /* MATLABSystem: '<S1>/MATLAB System' */
  memcpy(&untitled_B.u0[0], &untitled_B.V4L2VideoCapture_o1[0], 307200U * sizeof
         (uint8_T));
  memcpy(&untitled_B.u1[0], &untitled_B.V4L2VideoCapture_o2[0], 307200U * sizeof
         (uint8_T));
  memcpy(&untitled_B.u2[0], &untitled_B.V4L2VideoCapture_o3[0], 307200U * sizeof
         (uint8_T));

  /* Start for MATLABSystem: '<S1>/MATLAB System' incorporates:
   *  MATLABSystem: '<S1>/MATLAB System'
   */
  MW_SDL_videoDisplayOutput(untitled_B.u0, untitled_B.u1, untitled_B.u2);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1252808289U);
  untitled_M->Sizes.checksums[1] = (292692517U);
  untitled_M->Sizes.checksums[2] = (1954658084U);
  untitled_M->Sizes.checksums[3] = (2281432028U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureInit(untitled_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 640U,
                      480U, 2U, 2U, 1U, 0.1);

  /* Start for MATLABSystem: '<S1>/MATLAB System' */
  untitled_DW.obj.isInitialized = 0;
  untitled_DW.obj.isInitialized = 1;
  untitled_DW.obj.PixelFormatEnum = 1;
  MW_SDL_videoDisplayInit(untitled_DW.obj.PixelFormatEnum, 1, 1, 640.0, 480.0);

  /* End of Start for SubSystem: '<Root>/SDL Video Display' */
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(untitled_ConstP.V4L2VideoCapture_p1);

  /* Start for MATLABSystem: '<S1>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<S1>/MATLAB System'
   */
  if (untitled_DW.obj.isInitialized == 1) {
    untitled_DW.obj.isInitialized = 2;
    MW_SDL_videoDisplayTerminate(0, 0);
  }

  /* End of Start for MATLABSystem: '<S1>/MATLAB System' */
  /* End of Terminate for SubSystem: '<Root>/SDL Video Display' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
