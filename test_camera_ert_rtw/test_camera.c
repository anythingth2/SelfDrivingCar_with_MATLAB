/*
 * File: test_camera.c
 *
 * Code generated for Simulink model 'test_camera'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Fri Feb 02 17:54:55 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_camera.h"
#include "test_camera_private.h"
#include "test_camera_dt.h"

/* Block signals (auto storage) */
B_test_camera_T test_camera_B;

/* Real-time model */
RT_MODEL_test_camera_T test_camera_M_;
RT_MODEL_test_camera_T *const test_camera_M = &test_camera_M_;

/* Model step function */
void test_camera_step(void)
{
  /* S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureOutput(test_camera_ConstP.V4L2VideoCapture_p1,
                        &test_camera_B.MatrixConcatenate[0],
                        &test_camera_B.MatrixConcatenate[307200],
                        &test_camera_B.MatrixConcatenate[614400]);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, test_camera_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(test_camera_M)!=-1) &&
        !((rtmGetTFinal(test_camera_M)-test_camera_M->Timing.taskTime0) >
          test_camera_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_camera_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test_camera_M)) {
      rtmSetErrorStatus(test_camera_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_camera_M->Timing.taskTime0 =
    (++test_camera_M->Timing.clockTick0) * test_camera_M->Timing.stepSize0;
}

/* Model initialize function */
void test_camera_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_camera_M, 0,
                sizeof(RT_MODEL_test_camera_T));
  rtmSetTFinal(test_camera_M, -1);
  test_camera_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  test_camera_M->Sizes.checksums[0] = (1779960469U);
  test_camera_M->Sizes.checksums[1] = (536138880U);
  test_camera_M->Sizes.checksums[2] = (2338109480U);
  test_camera_M->Sizes.checksums[3] = (767336551U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test_camera_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_camera_M->extModeInfo,
      &test_camera_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_camera_M->extModeInfo,
                        test_camera_M->Sizes.checksums);
    rteiSetTPtr(test_camera_M->extModeInfo, rtmGetTPtr(test_camera_M));
  }

  /* block I/O */
  (void) memset(((void *) &test_camera_B), 0,
                sizeof(B_test_camera_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_camera_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Start for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureInit(test_camera_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 640U,
                      480U, 2U, 2U, 1U, 0.1);
}

/* Model terminate function */
void test_camera_terminate(void)
{
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<Root>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(test_camera_ConstP.V4L2VideoCapture_p1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
