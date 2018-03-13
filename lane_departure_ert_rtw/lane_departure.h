/*
 * File: lane_departure.h
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
#include "v4l2_capture.h"
#endif                                 /* lane_departure_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "Region_of_Interest.h"
#include "LaneDetection.h"

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

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
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

/* Custom Type definition for MATLAB Function: '<S1>/MATLAB Function' */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  char_T f1[7];
  char_T f2[7];
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  char_T f1[7];
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  char_T f1[4];
  char_T f2[6];
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef typedef_e_struct_T
#define typedef_e_struct_T

typedef struct {
  char_T f1[7];
  char_T f2[8];
  char_T f3[7];
  char_T f4[4];
  char_T f5[5];
} e_struct_T;

#endif                                 /*typedef_e_struct_T*/

/* Block signals (auto storage) */
typedef struct {
  uint8_T uv0[76800];
  real_T LaneDetection_o2[5];          /* '<Root>/LaneDetection' */
  real_T Abs;                          /* '<S7>/Abs' */
  int32_T LaneDetection_o1[20];        /* '<Root>/LaneDetection' */
  int32_T LeftClosetPts[4];            /* '<S2>/Find Closest Lane' */
  int32_T RightClosetPts[4];           /* '<S2>/Find Closest Lane' */
  uint8_T V4L2VideoCapture_o1[76800];  /* '<S1>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o2[38400];  /* '<S1>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o3[38400];  /* '<S1>/V4L2 Video Capture' */
  uint8_T ROI[15921];                  /* '<Root>/ROI' */
  uint8_T LaneDetection_o3[15921];     /* '<Root>/LaneDetection' */
  uint8_T Image[76800];                /* '<S1>/MATLAB Function' */
  boolean_T LaneDetection_o4[15921];   /* '<Root>/LaneDetection' */
  real_T d0;
  int32_T i;
  int32_T closetLeft;
  int32_T closetRight;
  int32_T qY;
  int32_T q0;
  int32_T i_m;
  int32_T j;
  uint8_T tmp;
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FrameRateDisplay_PrevTime;    /* '<Root>/Frame Rate Display' */
  real_T FrameRateDisplay_TotalTime;   /* '<Root>/Frame Rate Display' */
  real_T FrameRateDisplay_Count;       /* '<Root>/Frame Rate Display' */
  real_T numberLane;                   /* '<S2>/Chart' */
  uint8_T is_active_c4_lane_departure; /* '<S2>/Chart' */
  uint8_T is_c4_lane_departure;        /* '<S2>/Chart' */
  Region_of_Interest_MdlrefDW ROI_DWORK1;/* '<Root>/ROI' */
  LaneDetection_MdlrefDW LaneDetection_DWORK1;/* '<Root>/LaneDetection' */
  int32_T LaneDetection_DIMS1[2];      /* '<Root>/LaneDetection' */
  int32_T LaneDetection_DIMS2[2];      /* '<Root>/LaneDetection' */
} DW;

/* Parameters (auto storage) */
struct P_ {
  real_T ROI_X_Value[261];             /* Expression: [20:280]
                                        * Referenced by: '<Root>/ROI_X'
                                        */
  real_T ROI_Y_Value[61];              /* Expression: [140:200]
                                        * Referenced by: '<Root>/ROI_Y'
                                        */
  real_T SIZE_ROI_X_Value;             /* Expression: 261
                                        * Referenced by: '<Root>/SIZE_ROI_X'
                                        */
  real_T SIZE_ROI_Y_Value;             /* Expression: 61
                                        * Referenced by: '<Root>/SIZE_ROI_Y'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S7>/Constant2'
                                        */
};

/* Parameters (auto storage) */
typedef struct P_ P;

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
      uint32_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P rtP;

/* Block signals (auto storage) */
extern B rtB;

/* Block states (auto storage) */
extern DW rtDW;

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
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S2>/Divide' : Unused code path elimination
 * Block '<S2>/Selector' : Unused code path elimination
 * Block '<S2>/Selector1' : Unused code path elimination
 * Block '<S2>/Subtract' : Unused code path elimination
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
 * '<S2>'   : 'lane_departure/LaneDeparture'
 * '<S3>'   : 'lane_departure/Input /MATLAB Function'
 * '<S4>'   : 'lane_departure/Input /MATLAB Function1'
 * '<S5>'   : 'lane_departure/LaneDeparture/Chart'
 * '<S6>'   : 'lane_departure/LaneDeparture/Find Closest Lane'
 * '<S7>'   : 'lane_departure/LaneDeparture/Find Distance from lane to car'
 * '<S8>'   : 'lane_departure/LaneDeparture/ImageZoning'
 * '<S9>'   : 'lane_departure/LaneDeparture/LaneFilter'
 */
#endif                                 /* RTW_HEADER_lane_departure_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
