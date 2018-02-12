/*
 * File: lane_departure.h
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

#ifndef RTW_HEADER_lane_departure_h_
#define RTW_HEADER_lane_departure_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef lane_departure_COMMON_INCLUDES_
# define lane_departure_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "v4l2_capture.h"
#include "math.h"
#include "viphough_rt.h"
#endif                                 /* lane_departure_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define lane_departure_M               (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals (auto storage) */
typedef struct {
  real_T HoughTransform_o1[71820];     /* '<Root>/Hough Transform' */
  uint8_T MatrixConcatenate[57600];    /* '<S1>/Matrix Concatenate' */
  uint8_T DrawShapes[57600];           /* '<Root>/Draw Shapes' */
  uint8_T Erosion[19200];              /* '<Root>/Erosion' */
  uint8_T ColorSpaceConversion[19200];
  real_T HoughTransform_o2[180];       /* '<Root>/Hough Transform' */
  real_T HoughTransform_o3[399];       /* '<Root>/Hough Transform' */
  boolean_T EdgeDetection[19200];      /* '<Root>/Edge Detection' */
  real_T FindLocalMaxima[6];           /* '<Root>/Find Local Maxima' */
  int32_T HoughLines[12];              /* '<Root>/Hough Lines' */
  real_T Selector1[3];                 /* '<Root>/Selector1' */
  real_T Selector5[3];                 /* '<Root>/Selector5' */
  real_T Selector[3];                  /* '<Root>/Selector' */
  real_T rtb_FindLocalMaxima_data[3];
  int32_T tmpOutRC[4];
  int32_T rtb_Selector_data[3];
  real_T tmpRound;
  real_T y2;
  real_T maxValue;
  int32_T accumFour;
  int32_T curNumNonZ;
  uint32_T toIdx;
  uint32_T fromIdx;
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T EdgeDetection_GV_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  int32_T EdgeDetection_GH_SQUARED_DW[19200];/* '<Root>/Edge Detection' */
  int32_T EdgeDetection_GRAD_SUM_DW[19200];/* '<Root>/Edge Detection' */
  uint8_T Erosion_TWO_PAD_IMG_DW[21209];/* '<Root>/Erosion' */
  uint8_T Erosion_ONE_PAD_IMG_DW[21209];/* '<Root>/Erosion' */
  uint8_T Erosion_HBUF_DW[175];        /* '<Root>/Erosion' */
  uint8_T Erosion_GBUF_DW[175];        /* '<Root>/Erosion' */
  real_T FrameRateDisplay_PrevTime;    /* '<Root>/Frame Rate Display' */
  real_T FrameRateDisplay_TotalTime;   /* '<Root>/Frame Rate Display' */
  real_T FrameRateDisplay_Count;       /* '<Root>/Frame Rate Display' */
  real_T FindLocalMaxima_TEMP_IN_DWORKS[71820];/* '<Root>/Find Local Maxima' */
  int32_T Erosion_NUMNONZ_DW[2];       /* '<Root>/Erosion' */
  int32_T Erosion_STREL_DW[2];         /* '<Root>/Erosion' */
  int32_T Erosion_ERODE_OFF_DW[8];     /* '<Root>/Erosion' */
  int32_T EdgeDetection_VO_DW[6];      /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HO_DW[6];      /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOU_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOD_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOL_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOR_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOU_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOD_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOL_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOR_DW[6];     /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOUL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOLL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOUR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_VOLR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOUL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOLL_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOUR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T EdgeDetection_HOLR_DW[6];    /* '<Root>/Edge Detection' */
  int32_T FindLocalMaxima_DIMS1[2];    /* '<Root>/Find Local Maxima' */
  int32_T Selector_DIMS1[2];           /* '<Root>/Selector' */
  int32_T Selector1_DIMS1[2];          /* '<Root>/Selector1' */
  int32_T Selector2_DIMS1[2];          /* '<Root>/Selector2' */
  int32_T Selector5_DIMS1[2];          /* '<Root>/Selector5' */
  int32_T HoughLines_DIMS1[2];         /* '<Root>/Hough Lines' */
  int32_T EdgeDetection_MEAN_FACTOR_DW;/* '<Root>/Edge Detection' */
  uint8_T ColorSpaceConversion_DWORK1[57600];/* '<Root>/Color Space  Conversion' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<Root>/Hough Transform'
   */
  real_T HoughTransform_SINE_TABLE_RTP[91];

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<Root>/Hough Transform'
   */
  real_T HoughTransform_FIRSTRHO_RTP;

  /* Computed Parameter: EdgeDetection_VRO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_VRO_RTP[6];

  /* Computed Parameter: EdgeDetection_VCO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_VCO_RTP[6];

  /* Computed Parameter: EdgeDetection_HRO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_HRO_RTP[6];

  /* Computed Parameter: EdgeDetection_HCO_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_HCO_RTP[6];

  /* Computed Parameter: EdgeDetection_VC_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_VC_RTP[6];

  /* Computed Parameter: EdgeDetection_HC_RTP
   * Referenced by: '<Root>/Edge Detection'
   */
  int32_T EdgeDetection_HC_RTP[6];

  /* Expression: devName
   * Referenced by: '<S1>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B rtB;

/* Block states (auto storage) */
extern DW rtDW;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* External function called from main */
extern void lane_departure_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void lane_departure_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void lane_departure_initialize(void);
extern void lane_departure_step(int_T tid);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<S1>/From Multimedia File' : Unused code path elimination
 */

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
 * '<Root>' : 'lane_departure'
 * '<S1>'   : 'lane_departure/Input '
 * '<S2>'   : 'lane_departure/roi '
 */
#endif                                 /* RTW_HEADER_lane_departure_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
