/*
 * File: webcams.h
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

#ifndef RTW_HEADER_webcams_h_
#define RTW_HEADER_webcams_h_
#include <string.h>
#include <stddef.h>
#ifndef webcams_COMMON_INCLUDES_
# define webcams_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "HostLib_MMFile.h"
#include "HostLib_Multimedia.h"
#include "vipedge_rt.h"
#endif                                 /* webcams_COMMON_INCLUDES_ */

#include "webcams_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

/* Block signals (auto storage) */
typedef struct {
  real32_T FromMultimediaFile[2764800];/* '<Root>/From Multimedia File' */
  real32_T Resize[691200];             /* '<Root>/Resize' */
  real32_T ColorSpaceConversion[230400];/* '<Root>/Color Space  Conversion' */
  boolean_T EdgeDetection[230400];     /* '<Root>/Edge Detection' */
} B_webcams_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real32_T Resize_IntBuffer[460800];   /* '<Root>/Resize' */
  real32_T EdgeDetection_TEMP_INP_DW[230400];/* '<Root>/Edge Detection' */
  real32_T EdgeDetection_DR_DW[230400];/* '<Root>/Edge Detection' */
  real32_T EdgeDetection_DC_DW[230400];/* '<Root>/Edge Detection' */
  real_T FromMultimediaFile_HostLib[137];/* '<Root>/From Multimedia File' */
  real_T FromMultimediaFile_AudioInfo[5];/* '<Root>/From Multimedia File' */
  real_T FromMultimediaFile_VideoInfo[11];/* '<Root>/From Multimedia File' */
  real32_T ColorSpaceConversion_DWORK1[691200];/* '<Root>/Color Space  Conversion' */
} DW_webcams_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: Resize_Yweights
   * Referenced by: '<Root>/Resize'
   */
  real32_T Resize_Yweights[1440];

  /* Computed Parameter: Resize_Xweights
   * Referenced by: '<Root>/Resize'
   */
  real32_T Resize_Xweights[2560];

  /* Computed Parameter: EdgeDetection_GAUSS1D_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  real32_T EdgeDetection_GAUSS1D_RTP[4];

  /* Computed Parameter: EdgeDetection_DGAUSS1D_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  real32_T EdgeDetection_DGAUSS1D_RTP[4];

  /* Computed Parameter: Resize_Yindex
   * Referenced by: '<Root>/Resize'
   */
  int32_T Resize_Yindex[1440];

  /* Computed Parameter: Resize_Xindex
   * Referenced by: '<Root>/Resize'
   */
  int32_T Resize_Xindex[2560];
} ConstP_webcams_T;

/* Parameters (auto storage) */
struct P_webcams_T_ {
  real32_T Constant_Value[2];          /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_webcams_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_webcams_T webcams_P;

/* Block signals (auto storage) */
extern B_webcams_T webcams_B;

/* Block states (auto storage) */
extern DW_webcams_T webcams_DW;

/* Constant parameters (auto storage) */
extern const ConstP_webcams_T webcams_ConstP;

/* Model entry point functions */
extern void webcams_initialize(void);
extern void webcams_step(void);
extern void webcams_terminate(void);

/* Real-time Model object */
extern RT_MODEL_webcams_T *const webcams_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'webcams'
 */
#endif                                 /* RTW_HEADER_webcams_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
