/*
 * File: LaneDetection.h
 *
 * Code generated for Simulink model 'LaneDetection'.
 *
 * Model version                  : 1.115
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sat Mar 10 10:54:43 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LaneDetection_h_
#define RTW_HEADER_LaneDetection_h_
#include <math.h>
#include <string.h>
#ifndef LaneDetection_COMMON_INCLUDES_
# define LaneDetection_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "viphough_rt.h"
#endif                                 /* LaneDetection_COMMON_INCLUDES_ */

/* Shared type includes */
#include "multiword_types.h"

/* Forward declaration for rtModel */
typedef struct LaneDetection_tag_RTM LaneDetection_RT_MODEL;

/* Block signals and states (auto storage) for model 'LaneDetection' */
typedef struct {
  real_T HoughTransform_o1[96300];     /* '<S1>/Hough Transform' */
  real_T HoughTransform_o2[180];       /* '<S1>/Hough Transform' */
  real_T HoughTransform_o3[535];       /* '<S1>/Hough Transform' */
  real_T FindLocalMaxima_TEMP_IN_DWORKS[96300];/* '<S1>/Find Local Maxima' */
  real_T FindLocalMaxima[10];          /* '<S1>/Find Local Maxima' */
  real_T Product[5];                   /* '<S2>/Product' */
  real_T Subtract1[5];                 /* '<S2>/Subtract1' */
  real_T Selector[5];                  /* '<S1>/Selector' */
  real_T rtb_FindLocalMaxima_data[5];
  real_T tmpRound;
  real_T y2;
  real_T maxValue;
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
  int32_T FindLocalMaxima_DIMS1[2];    /* '<S1>/Find Local Maxima' */
  int32_T Selector_DIMS1[2];           /* '<S1>/Selector' */
  int32_T Selector1_DIMS1[2];          /* '<S1>/Selector1' */
  int32_T Selector2_DIMS1[2];          /* '<S1>/Selector2' */
  int32_T Selector5_DIMS1[2];          /* '<S1>/Selector5' */
  int32_T Selector_DIMS1_o[2];         /* '<S2>/Selector' */
  int32_T Selector3_DIMS1[2];          /* '<S2>/Selector3' */
  int32_T Selector2_DIMS1_g[2];        /* '<S2>/Selector2' */
  int32_T Selector4_DIMS1[2];          /* '<S2>/Selector4' */
  int32_T EdgeDetection_GV_SQUARED_DW[15921];/* '<Root>/Edge Detection' */
  int32_T EdgeDetection_GH_SQUARED_DW[15921];/* '<Root>/Edge Detection' */
  int32_T EdgeDetection_GRAD_SUM_DW[15921];/* '<Root>/Edge Detection' */
  int32_T Selector3[5];                /* '<S2>/Selector3' */
  int32_T Selector_p[5];               /* '<S2>/Selector' */
  int32_T rtb_Selector_data[5];
  int32_T tmpOutRC[4];
  int32_T EdgeDetection_MEAN_FACTOR_DW;/* '<Root>/Edge Detection' */
  int32_T numEdge;
  uint32_T FindLocalMaxima_NUMPEAKS_DWORK;/* '<S1>/Find Local Maxima' */
  uint32_T toIdx;
  uint32_T fromIdx;
} LaneDetection_DW_f;

/* Real-time Model Data Structure */
struct LaneDetection_tag_RTM {
  const char_T **errorStatus;
};

typedef struct {
  LaneDetection_DW_f rtdw;
  LaneDetection_RT_MODEL rtm;
} LaneDetection_MdlrefDW;

/* Model reference registration function */
extern void LaneDetection_initialize(const char_T **rt_errorStatus,
  LaneDetection_RT_MODEL *const LaneDetectionrtM, LaneDetection_DW_f *localDW);
extern void LaneDetection_Start(LaneDetection_DW_f *localDW);
extern void LaneDetection(const uint8_T rtu_I[15921], int32_T rty_Points[20],
  int32_T rty_Points_DIMS1[2], real_T rty_Slope[5], int32_T rty_Slope_DIMS1[2],
  uint8_T rty_LineImage[15921], boolean_T rty_Edge[15921], LaneDetection_DW_f
  *localDW);

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
 * '<Root>' : 'LaneDetection'
 * '<S1>'   : 'LaneDetection/Find Line'
 * '<S2>'   : 'LaneDetection/Find Slope'
 */
#endif                                 /* RTW_HEADER_LaneDetection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
