/*
 * File: lane_departure.h
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

#ifndef RTW_HEADER_lane_departure_h_
#define RTW_HEADER_lane_departure_h_
#include "rtwtypes.h"
#include "multiword_types.h"
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
#include "MW_SDL_video_display.h"
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

#define lane_departure_M               (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef typedef_codertarget_linux_blocks_SDLVid
#define typedef_codertarget_linux_blocks_SDLVid

typedef struct {
  int32_T isInitialized;
  int32_T PixelFormatEnum;
} codertarget_linux_blocks_SDLVid;

#endif                                 /*typedef_codertarget_linux_blocks_SDLVid*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T f1[2];
  real_T f2[2];
  real_T f3[2];
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Block signals (auto storage) */
typedef struct {
  real_T HoughTransform_o1[143820];    /* '<S2>/Hough Transform' */
  uint8_T pln2[76800];
  uint8_T pln3[76800];
  uint8_T Erosion[76800];              /* '<Root>/Erosion' */
  real_T HoughTransform_o2[180];       /* '<S2>/Hough Transform' */
  real_T HoughTransform_o3[799];       /* '<S2>/Hough Transform' */
  int32_T HoughLines[12];              /* '<S2>/Hough Lines' */
  uint8_T V4L2VideoCapture_o1[76800];  /* '<S1>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o2[38400];  /* '<S1>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o3[38400];  /* '<S1>/V4L2 Video Capture' */
  uint8_T DrawShapes[76800];           /* '<Root>/Draw Shapes' */
  boolean_T EdgeDetection[76800];      /* '<Root>/Edge Detection' */
  real_T FindLocalMaxima[6];           /* '<S2>/Find Local Maxima' */
  real_T Selector1[3];                 /* '<S2>/Selector1' */
  real_T Selector5[3];                 /* '<S2>/Selector5' */
  real_T Selector[3];                  /* '<S2>/Selector' */
  real_T rtb_FindLocalMaxima_data[3];
  int32_T tmpOutRC[4];
  int32_T rtb_Selector_data[3];
  real_T tmpRound;
  real_T y2;
  real_T maxValue;
  int32_T accumFour;
  int32_T row;
  uint32_T toIdx;
  uint32_T fromIdx;
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T EdgeDetection_GV_SQUARED_DW[76800];/* '<Root>/Edge Detection' */
  int32_T EdgeDetection_GH_SQUARED_DW[76800];/* '<Root>/Edge Detection' */
  int32_T EdgeDetection_GRAD_SUM_DW[76800];/* '<Root>/Edge Detection' */
  uint8_T Erosion_TWO_PAD_IMG_DW[80769];/* '<Root>/Erosion' */
  uint8_T Erosion_ONE_PAD_IMG_DW[80769];/* '<Root>/Erosion' */
  uint8_T Erosion_HBUF_DW[335];        /* '<Root>/Erosion' */
  uint8_T Erosion_GBUF_DW[335];        /* '<Root>/Erosion' */
  real_T FrameRateDisplay_PrevTime;    /* '<Root>/Frame Rate Display' */
  real_T FrameRateDisplay_TotalTime;   /* '<Root>/Frame Rate Display' */
  real_T FrameRateDisplay_Count;       /* '<Root>/Frame Rate Display' */
  real_T FindLocalMaxima_TEMP_IN_DWORKS[143820];/* '<S2>/Find Local Maxima' */
  codertarget_linux_blocks_SDLVid obj; /* '<S4>/MATLAB System' */
  void *MATLABSystem_PWORK;            /* '<S4>/MATLAB System' */
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
  int32_T FindLocalMaxima_DIMS1[2];    /* '<S2>/Find Local Maxima' */
  int32_T Selector_DIMS1[2];           /* '<S2>/Selector' */
  int32_T Selector1_DIMS1[2];          /* '<S2>/Selector1' */
  int32_T Selector2_DIMS1[2];          /* '<S2>/Selector2' */
  int32_T Selector5_DIMS1[2];          /* '<S2>/Selector5' */
  int32_T HoughLines_DIMS1[2];         /* '<S2>/Hough Lines' */
  int32_T EdgeDetection_MEAN_FACTOR_DW;/* '<Root>/Edge Detection' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<S2>/Hough Transform'
   */
  real_T HoughTransform_SINE_TABLE_RTP[91];

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<S2>/Hough Transform'
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

/* Model entry point functions */
extern void lane_departure_initialize(void);
extern void lane_departure_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<S2>'   : 'lane_departure/Lane Departure'
 * '<S3>'   : 'lane_departure/ROI'
 * '<S4>'   : 'lane_departure/SDL Video Display'
 * '<S5>'   : 'lane_departure/Input /MATLAB Function'
 * '<S6>'   : 'lane_departure/ROI/mask'
 */
#endif                                 /* RTW_HEADER_lane_departure_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
