/*
 * File: webcams.c
 *
 * Code generated for Simulink model 'webcams'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Dec 28 17:21:48 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "webcams.h"
#include "webcams_private.h"

/* Block signals (auto storage) */
B_webcams_T webcams_B;

/* Block states (auto storage) */
DW_webcams_T webcams_DW;

/* Real-time model */
RT_MODEL_webcams_T webcams_M_;
RT_MODEL_webcams_T *const webcams_M = &webcams_M_;

/* Model step function */
void webcams_step(void)
{
  char_T *sErr;
  void *source_R;
  int32_T inIdx;
  int32_T outIdx;
  int32_T m;
  int32_T n;
  int32_T chan;
  real32_T sum;
  int32_T ctr;
  int32_T ictr;
  int32_T indx;
  real32_T *Resize_LineBuffer;

  /* S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&webcams_DW.FromMultimediaFile_HostLib[0U]);
  source_R = (void *)&webcams_B.FromMultimediaFile[0U];
  LibOutputs_FromMMFile(&webcams_DW.FromMultimediaFile_HostLib[0U],
                        GetNullPointer(), GetNullPointer(), source_R,
                        GetNullPointer(), GetNullPointer());
  if (*sErr != 0) {
    rtmSetErrorStatus(webcams_M, sErr);
    rtmSetStopRequested(webcams_M, 1);
  }

  /* End of S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

  /* S-Function (svipresize): '<Root>/Resize' */
  inIdx = 0;
  outIdx = 0;

  /* use pre-computed weights and index table to perform interpolation */
  for (chan = 0; chan < 3; chan++) {
    ctr = 0;
    for (m = 0; m < 720; m++) {
      indx = m;
      for (n = 0; n < 640; n++) {
        sum = webcams_B.FromMultimediaFile[(inIdx + m) +
          webcams_ConstP.Resize_Xindex[n] * 720] *
          webcams_ConstP.Resize_Xweights[n];
        ictr = n + 640;
        sum += webcams_B.FromMultimediaFile[(inIdx + m) +
          webcams_ConstP.Resize_Xindex[ictr] * 720] *
          webcams_ConstP.Resize_Xweights[ictr];
        ictr += 640;
        sum += webcams_B.FromMultimediaFile[(inIdx + m) +
          webcams_ConstP.Resize_Xindex[ictr] * 720] *
          webcams_ConstP.Resize_Xweights[ictr];
        ictr += 640;
        sum += webcams_B.FromMultimediaFile[(inIdx + m) +
          webcams_ConstP.Resize_Xindex[ictr] * 720] *
          webcams_ConstP.Resize_Xweights[ictr];
        webcams_DW.Resize_IntBuffer[indx] = sum;
        indx += 720;
      }
    }

    for (n = 0; n < 640; n++) {
      Resize_LineBuffer = &webcams_DW.Resize_IntBuffer[n * 720];
      for (m = 0; m < 360; m++) {
        ictr = m + 360;
        sum = Resize_LineBuffer[webcams_ConstP.Resize_Yindex[m]] *
          webcams_ConstP.Resize_Yweights[m] +
          Resize_LineBuffer[webcams_ConstP.Resize_Yindex[ictr]] *
          webcams_ConstP.Resize_Yweights[ictr];
        ictr += 360;
        sum += Resize_LineBuffer[webcams_ConstP.Resize_Yindex[ictr]] *
          webcams_ConstP.Resize_Yweights[ictr];
        ictr += 360;
        sum += Resize_LineBuffer[webcams_ConstP.Resize_Yindex[ictr]] *
          webcams_ConstP.Resize_Yweights[ictr];
        webcams_B.Resize[outIdx + ctr] = sum;
        ctr++;
      }
    }

    inIdx += 921600;
    outIdx += 230400;
  }

  /* End of S-Function (svipresize): '<Root>/Resize' */

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  for (outIdx = 0; outIdx < 230400; outIdx++) {
    webcams_B.ColorSpaceConversion[outIdx] = (webcams_B.Resize[230400 + outIdx] *
      0.587F + webcams_B.Resize[outIdx] * 0.299F) + webcams_B.Resize[460800 +
      outIdx] * 0.114F;
    if (webcams_B.ColorSpaceConversion[outIdx] > 1.0F) {
      webcams_B.ColorSpaceConversion[outIdx] = 1.0F;
    } else {
      if (webcams_B.ColorSpaceConversion[outIdx] < 0.0F) {
        webcams_B.ColorSpaceConversion[outIdx] = 0.0F;
      }
    }
  }

  /* End of S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */

  /* S-Function (svipedge): '<Root>/Edge Detection' incorporates:
   *  Constant: '<Root>/Constant'
   */
  MWVIP_EdgeCanny_userTh_R(&webcams_B.ColorSpaceConversion[0],
    &webcams_ConstP.EdgeDetection_GAUSS1D_RTP[0],
    &webcams_ConstP.EdgeDetection_DGAUSS1D_RTP[0],
    &webcams_DW.EdgeDetection_DC_DW[0], &webcams_DW.EdgeDetection_DR_DW[0],
    &webcams_B.EdgeDetection[0], &webcams_DW.EdgeDetection_TEMP_INP_DW[0],
    &webcams_P.Constant_Value[0], 360, 640, 4);
}

/* Model initialize function */
void webcams_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)webcams_M, 0,
                sizeof(RT_MODEL_webcams_T));

  /* block I/O */
  (void) memset(((void *) &webcams_B), 0,
                sizeof(B_webcams_T));

  /* states (dwork) */
  (void) memset((void *)&webcams_DW, 0,
                sizeof(DW_webcams_T));

  {
    char_T *sErr;

    /* Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    sErr = GetErrorBuffer(&webcams_DW.FromMultimediaFile_HostLib[0U]);
    CreateHostLibrary("frommmfile.dll", &webcams_DW.FromMultimediaFile_HostLib
                      [0U]);
    createAudioInfo(&webcams_DW.FromMultimediaFile_AudioInfo[0U], 0U, 0U,
                    48000.0, 32, 6, 1024, 4, 0);
    createVideoInfo(&webcams_DW.FromMultimediaFile_VideoInfo[0U], 1U, 25.0, 25.0,
                    "YUY2", 1, 3, 1280, 720, 0U, 1, 1, 0);
    if (*sErr == 0) {
      LibCreate_FromMMFile(&webcams_DW.FromMultimediaFile_HostLib[0U], 0, (void *)
                           "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\challenge.mp4",
                           1, "", "", &webcams_DW.FromMultimediaFile_AudioInfo
                           [0U], &webcams_DW.FromMultimediaFile_VideoInfo[0U],
                           0U, 1U, 1U, 0U, 0U, 1U);
    }

    if (*sErr == 0) {
      LibStart(&webcams_DW.FromMultimediaFile_HostLib[0U]);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&webcams_DW.FromMultimediaFile_HostLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(webcams_M, sErr);
        rtmSetStopRequested(webcams_M, 1);
      }
    }

    /* End of Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

    /* InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    LibReset(&webcams_DW.FromMultimediaFile_HostLib[0U]);
  }
}

/* Model terminate function */
void webcams_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&webcams_DW.FromMultimediaFile_HostLib[0U]);
  LibTerminate(&webcams_DW.FromMultimediaFile_HostLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(webcams_M, sErr);
    rtmSetStopRequested(webcams_M, 1);
  }

  LibDestroy(&webcams_DW.FromMultimediaFile_HostLib[0U], 0);
  DestroyHostLibrary(&webcams_DW.FromMultimediaFile_HostLib[0U]);

  /* End of Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
