/*
 * File: vipldws.h
 *
 * Code generated for Simulink model 'vipldws'.
 *
 * Model version                  : 1.2210
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Sun Dec 31 20:26:07 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_vipldws_h_
#define RTW_HEADER_vipldws_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef vipldws_COMMON_INCLUDES_
# define vipldws_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SDL_video_display.h"
#include "vipdrawtext_rt.h"
#include "v4l2_capture.h"
#include "math.h"
#include "viphough_rt.h"
#endif                                 /* vipldws_COMMON_INCLUDES_ */

#include "vipldws_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_i32zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

/* Block signals (auto storage) */
typedef struct {
  real32_T ColorSpaceConversion[76800];/* '<S2>/Color Space  Conversion' */
  real32_T Clipimage[48000];           /* '<S2>/Clip image' */
  real32_T HoughTransform_o1[112500];  /* '<S3>/Hough Transform' */
  real32_T DrawShapes[230400];         /* '<S65>/DrawShapes' */
  real32_T InsertText[230400];         /* '<S65>/Insert Text' */
  real32_T InsertTextLeftLane[230400]; /* '<S67>/Insert Text: Left Lane' */
  real32_T ImageDataTypeConversion_n[230400];/* '<S66>/Image Data Type Conversion' */
  real32_T DrawShapes_f[230400];       /* '<S66>/DrawShapes' */
  uint8_T pln1[76800];
  uint8_T pln2[76800];
  uint8_T pln3[76800];
  real32_T HoughTransform_o2[180];     /* '<S3>/Hough Transform' */
  real32_T HoughTransform_o3[625];     /* '<S3>/Hough Transform' */
  int32_T leftC[120];
  int32_T rightC[120];
  int32_T Rs[120];
  real32_T Init[40];                   /* '<S36>/Init' */
  real32_T fv0[16];
  int32_T mLoc[10];
  int32_T mWidth[10];
  real32_T KTrans[8];                  /* '<S41>/K Trans' */
  real32_T fv1[8];
  int32_T twoLines_1b[8];
  int32_T Transpose_g[4];              /* '<S26>/Transpose' */
  int32_T HoughLines1[4];              /* '<S26>/Hough Lines1' */
  int32_T Transpose1[4];               /* '<S26>/Transpose1' */
  int32_T tmpOutRC[4];
  int32_T tmpOutRC_m[4];
  real_T Probe[2];                     /* '<S28>/Probe' */
  real_T Selector;                     /* '<S28>/Selector' */
  real32_T ImageDataTypeConversion[230400];/* '<S2>/Image Data Type Conversion' */
  real32_T MatrixConcatenation3[4];    /* '<S28>/Matrix Concatenation3' */
  real32_T UnitDelay2[80];             /* '<S32>/Unit Delay2' */
  real32_T UnitDelay3[320];            /* '<S32>/Unit Delay3' */
  real32_T ColorSpaceConversion1[86400];/* '<S2>/Color Space  Conversion1' */
  real32_T Xnew[40];                   /* '<S36>/Reset' */
  real32_T InsertTextRightLane[230400];/* '<S67>/Insert Text: Right Lane' */
  real32_T Assignment[40];             /* '<S37>/Assignment' */
  real_T d0;
  real32_T MatrixConcatenation2[2];    /* '<S14>/Matrix Concatenation2' */
  real32_T Selector1[2];               /* '<S37>/Selector1' */
  real32_T Selector2[2];               /* '<S37>/Selector2' */
  real32_T Assignment_i[40];           /* '<S52>/Assignment' */
  real32_T Selector2_f[2];             /* '<S53>/Selector2' */
  real32_T Selector1_k[2];             /* '<S54>/Selector1' */
  real32_T Selector_i[2];              /* '<S40>/Selector' */
  real32_T Selector1_c[4];             /* '<S40>/Selector1' */
  real32_T Selector2_n[16];            /* '<S40>/Selector2' */
  real32_T Assignment_io[320];         /* '<S42>/Assignment' */
  real32_T Assignment_o[80];           /* '<S43>/Assignment' */
  real32_T Assignment_p[40];           /* '<S44>/Assignment' */
  real32_T Assignment_a[40];           /* '<S45>/Assignment' */
  real32_T AX[4];                      /* '<S41>/A*X' */
  real32_T P_prd_Reshape[16];          /* '<S41>/P_prd_Reshape' */
  real32_T Z_est_Multiply[2];          /* '<S41>/Z_est_Multiply' */
  real32_T Z_prd_Multiply[2];          /* '<S41>/Z_prd_Multiply' */
  real32_T uDFIRFilter[48000];         /* '<S3>/2-D FIR Filter' */
  real32_T Saturation[48000];          /* '<S3>/Saturation' */
  real32_T selectrho5[231];            /* '<S30>/select rho5' */
  real32_T Xold[40];                   /* '<S36>/FixPt Unit Delay1' */
  real32_T OverwriteValues[112500];    /* '<S27>/Overwrite Values' */
  real32_T OverwriteValues1[112500];   /* '<S27>/Overwrite Values1' */
  real32_T Selectorrho[2];             /* '<S28>/Selector rho' */
  real32_T Selectortheta[2];           /* '<S28>/Selector theta' */
  real32_T selectrho5_f[20];           /* '<S1>/select rho5' */
  real32_T selectrho2[20];             /* '<S1>/select rho2' */
  real32_T selectrho5_m[756];          /* '<S29>/select rho5' */
  real32_T Selector_a[86400];          /* '<S2>/Selector' */
  real32_T tmp_data[2];
  int32_T idxBLin[2];
  int32_T hIdxA[2];
  int32_T sStart[2];
  int32_T sEnd[2];
  int32_T sPreEdges[2];
  int32_T sPostEdges[2];
  int32_T c[2];
  int32_T offset[2];
  int32_T idxA[2];
  int32_T idxB[2];
  int32_T idxBLin_c[2];
  int32_T hIdxA_k[2];
  int32_T hIdxB[2];
  int8_T o[5];
  real32_T DataTypeConversion1;        /* '<S14>/Data Type  Conversion1' */
  real32_T Switch[230400];             /* '<S65>/Switch' */
  real32_T Selectorrho_c;              /* '<S30>/Selector rho' */
  real32_T Selectortheta_i;            /* '<S30>/Selector theta' */
  real32_T Selectorrho_o;              /* '<S29>/Selector rho' */
  real32_T Selectortheta_g;            /* '<S29>/Selector theta' */
  real32_T Switch1[2];                 /* '<S37>/Switch1' */
  real32_T Selector2_b[2];             /* '<S52>/Selector2' */
  real32_T Rho_2;                      /* '<S55>/Rho_2' */
  real32_T Switch_m[16];               /* '<S42>/Switch' */
  real32_T Switch_l[4];                /* '<S43>/Switch' */
  real32_T HP_prdt[8];                 /* '<S41>/H*P_prdt' */
  real32_T LDLFactorization[4];        /* '<S46>/LDL Factorization' */
  real32_T y[8];                       /* '<S46>/Forward Substitution' */
  real32_T d[2];                       /* '<S46>/Extract Diagonal' */
  real32_T MatrixScaling[8];           /* '<S46>/Matrix Scaling' */
  real32_T BackwardSubstitution[8];    /* '<S46>/Backward Substitution' */
  real32_T Add;                        /* '<S14>/Add' */
  real32_T Switch_j[2];                /* '<S45>/Switch' */
  real32_T HP_prdtHtR[4];              /* '<S41>/H*P_prdt*Ht+R' */
  real32_T APAtQ[16];                  /* '<S41>/A*P*At+Q' */
  real32_T X_prdKZHX_prd[4];           /* '<S41>/X_prd+K*(Z-H*X_prd)' */
  real32_T Selector5[3];               /* '<S67>/Selector5' */
  real32_T P_prdKHP_prd[16];           /* '<S41>/P_prd-K*H*P_prd' */
  real32_T ZHX_prd[2];                 /* '<S41>/Z-H*X_prd' */
  real32_T Gain;                       /* '<S55>/Gain' */
  int32_T Init_p[20];                  /* '<S35>/Init' */
  int32_T En_Delay[20];                /* '<S32>/En_Delay' */
  int32_T ConvertlinesfromPolartoCartesia[80];/* '<S1>/Convert lines from  Polar to Cartesian space' */
  int32_T Transpose[80];               /* '<S1>/Transpose' */
  int32_T Widthoftheimage[2];          /* '<S1>/Width of the image' */
  int32_T Switch1_b[4];                /* '<S5>/Switch1' */
  int32_T MatrixConcatenation5[8];     /* '<S6>/Matrix Concatenation5' */
  real32_T y2;
  real32_T scale;
  real32_T cnt;
  real32_T acc4_idx_0;
  real32_T acc1_idx_5;
  real32_T v;
  int32_T rho_1;                       /* '<S1>/rho_1' */
  int32_T Distancethresholdfordeparturewa;/* '<S1>/Distance threshold  for departure warning' */
  int32_T Counter;                     /* '<S17>/Counter' */
  int32_T Selector_h;                  /* '<S8>/Selector' */
  int32_T Bias3[4];                    /* '<S5>/Bias3' */
  int32_T Bias[8];                     /* '<S5>/Bias' */
  int32_T Xnew_m[20];                  /* '<S35>/Reset' */
  int32_T out3rdLane[4];               /* '<S5>/Exclude 3rd Lane' */
  int32_T HoughLines[4];               /* '<S26>/Hough Lines' */
  int32_T ForIterator;                 /* '<S37>/For Iterator' */
  int32_T ForIterator_a;               /* '<S52>/For Iterator' */
  int32_T Assignment1[20];             /* '<S52>/Assignment1' */
  int32_T Saturation_h[20];            /* '<S52>/Saturation' */
  int32_T Selector1_b;                 /* '<S52>/Selector1' */
  int32_T ForIterator_l;               /* '<S51>/For Iterator' */
  int32_T Assignment1_m[400];          /* '<S51>/Assignment1' */
  int32_T Assignment2[400];            /* '<S51>/Assignment2' */
  int32_T Add_e[400];                  /* '<S51>/Add' */
  int32_T Assignment_k[40];            /* '<S51>/Assignment' */
  int32_T Assignment3[20];             /* '<S51>/Assignment3' */
  int32_T ForIterator_j;               /* '<S50>/For Iterator' */
  int32_T Selector1_n;                 /* '<S50>/Selector1' */
  int32_T Selector1_i[20];             /* '<S53>/Selector1' */
  int32_T Assignment_p2[400];          /* '<S53>/Assignment' */
  int32_T ForIterator_f;               /* '<S54>/For Iterator' */
  int32_T Assignment_j[20];            /* '<S54>/Assignment' */
  int32_T Add7;                        /* '<S55>/Add7' */
  int32_T Iterator;                    /* '<S39>/Iterator' */
  int32_T En_Selector;                 /* '<S39>/En_Selector' */
  int32_T ForIterator_e;               /* '<S31>/For Iterator' */
  int32_T ForIterator_fi;              /* '<S7>/For Iterator' */
  int32_T Intersectionwithbottomimageboun;/* '<S24>/Intersection with  bottom image boundary2' */
  int32_T Intersectionwithbottomimagebo_o[4];/* '<S24>/Intersection with  bottom image boundary3' */
  int32_T Intersectionwithbottomimagebo_g;/* '<S24>/Intersection with  bottom image boundary5' */
  int32_T Intersectionwithbottomimagebo_c[4];/* '<S24>/Intersection with  bottom image boundary6' */
  int32_T Xold_g[20];                  /* '<S35>/FixPt Unit Delay1' */
  int32_T Bias1[80];                   /* '<S1>/Bias1' */
  int32_T Selector1_il[80];            /* '<S1>/Selector1' */
  int32_T MultiportSelector_o1[2];     /* '<S16>/Multiport Selector' */
  int32_T MultiportSelector_o2[2];     /* '<S16>/Multiport Selector' */
  int32_T MultiportSelector_o3[2];     /* '<S16>/Multiport Selector' */
  int32_T MultiportSelector_o4[2];     /* '<S16>/Multiport Selector' */
  int32_T Selector2_m[8];              /* '<S65>/Selector2' */
  int32_T Transpose1_p[8];             /* '<S65>/Transpose1' */
  int32_T MatrixConcatenation6[12];    /* '<S69>/Matrix Concatenation6' */
  int32_T Selector2_h[12];             /* '<S66>/Selector2' */
  int32_T Transpose1_b[12];            /* '<S66>/Transpose1' */
  int32_T TmpSignalConversionAtDrawShapes[4];
  int32_T Selector1_ce[4];             /* '<S26>/Selector1' */
  int32_T Selector2_l[4];              /* '<S26>/Selector2' */
  int32_T DataTypeConversion3[2];      /* '<S51>/Data Type  Conversion3' */
  int32_T h1Dims[2];
  int32_T uDims[2];
  int32_T yDims[2];
  int32_T hLoc[2];
  int32_T yOrigin[2];
  int32_T uOrigin[2];
  int32_T uEnd[2];
  int32_T uStride[2];
  int32_T hEnd[2];
  int32_T yEnd[2];
  int32_T sStart_c[2];
  int32_T sEnd_b[2];
  int32_T offset_p[2];
  int32_T idxB_c[2];
  int32_T idxALin[2];
  int32_T Minimum_o1;                  /* '<S51>/Minimum' */
  int32_T Switch1_l;                   /* '<S54>/Switch1' */
  int32_T Rst_Selector;                /* '<S39>/Rst_Selector' */
  int32_T selectrho5_b[4];             /* '<S7>/select rho5' */
  int32_T Selector_n;                  /* '<S52>/Selector' */
  int32_T Switch1_bi[400];             /* '<S51>/Switch1' */
  int32_T Abs1;                        /* '<S55>/Abs1' */
  int32_T Intersectionwithbottomimagebo_d;/* '<S24>/Intersection with  bottom image boundary4' */
  int32_T Min_right_dis;               /* '<S24>/Min_right_dis' */
  int32_T Min_right_pts[4];            /* '<S24>/Min_right_pts' */
  int32_T Saturation_d;                /* '<S14>/Saturation' */
  int32_T Add_j[20];                   /* '<S52>/Add' */
  int32_T Selector7[2];                /* '<S67>/Selector7' */
  int32_T Intersectionwithbottomimagebo_j;/* '<S24>/Intersection with  bottom image boundary1' */
  int32_T Bias2[2];                    /* '<S67>/Bias2' */
  int32_T Transpose2[2];               /* '<S67>/Transpose2' */
  int32_T col;
  int32_T C1;
  int32_T R2;
  int32_T C2;
  int32_T r1;
  int32_T c1;
  int32_T r2;
  int32_T c2;
  int32_T firstRow;
  int32_T lastRow;
  int32_T activeColBdy;
  int32_T lastActiveEdgeIdxBdy;
  int32_T activeCol;
  int32_T lastSeparator;
  int32_T colOut;
  int32_T colBoundary;
  int32_T firstRowOut;
  int32_T lastRowOut;
  int32_T ii;
  int32_T numEdge;
  int32_T textIdx;
  int32_T textIdx_f;
  int32_T i;
  int32_T yIdx;
  int32_T countPeak;
  int32_T s37_iter;
  int32_T qY;
  int32_T qY_g;
  uint32_T Minimum;                    /* '<S52>/Minimum' */
  uint32_T Switch3;                    /* '<S52>/Switch3' */
  uint32_T Minimum_o2[2];              /* '<S51>/Minimum' */
  uint32_T fromIdx;
  uint32_T toIdx;
  ZCEventType zcEvent;
  uint16_T FindLocalMaxima1_o1[2];     /* '<S30>/Find Local Maxima1' */
  uint16_T FindLocalMaxima1_o2;        /* '<S30>/Find Local Maxima1' */
  uint16_T FindLocalMaxima1_o1_f[2];   /* '<S29>/Find Local Maxima1' */
  uint16_T FindLocalMaxima1_o2_c;      /* '<S29>/Find Local Maxima1' */
  uint16_T FindLocalMaxima[4];         /* '<S28>/Find Local Maxima' */
  uint16_T Selector1_m[4];             /* '<S28>/Selector1' */
  uint16_T Transpose_m[4];             /* '<S28>/Transpose' */
  uint16_T Selector2_mw[2];            /* '<S30>/Selector2' */
  uint16_T Transpose_b[2];             /* '<S30>/Transpose' */
  uint16_T Selector1_e[2];             /* '<S29>/Selector1' */
  uint16_T Transpose_gb[2];            /* '<S29>/Transpose' */
  uint16_T selectrho3[2];              /* '<S28>/select rho3' */
  uint16_T Bias3_f;                    /* '<S30>/Bias3' */
  uint16_T Bias3_d;                    /* '<S29>/Bias3' */
  int8_T RawMessage;                   /* '<S6>/Switch2' */
  int8_T Delay;                        /* '<S17>/Delay' */
  int8_T outMsg;                       /* '<S17>/Combine Left Right Departure' */
  int8_T colorAndTypeIdx[2];           /* '<S6>/DetectColorAndType1' */
  int8_T Switch_a;                     /* '<S6>/Switch' */
  int8_T Switch1_j;                    /* '<S6>/Switch1' */
  int8_T Bias1_j[2];                   /* '<S65>/Bias1' */
  int8_T Bias_h;                       /* '<S65>/Bias' */
  uint8_T MatrixConcatenate[230400];   /* '<S2>/Matrix Concatenate' */
  uint8_T Switch_mz[230400];           /* '<S5>/Switch' */
  uint8_T Selector_hy[76800];          /* '<S5>/Selector' */
  uint8_T Selector1_p[76800];          /* '<S5>/Selector1' */
  uint8_T Selector2_c[76800];          /* '<S5>/Selector2' */
  uint8_T ImageDataTypeConversion1[230400];/* '<S66>/Image Data Type Conversion1' */
  uint8_T DrawShapes_l[230400];        /* '<S62>/DrawShapes' */
  uint8_T Switch2[230400];             /* '<S5>/Switch2' */
  uint8_T ImageDataTypeConversion_f[230400];/* '<S5>/Image Data Type Conversion' */
  uint8_T FixPtLogicalOperator;        /* '<S35>/FixPt Logical Operator' */
  uint8_T FixPtUnitDelay2;             /* '<S35>/FixPt Unit Delay2' */
  boolean_T Compare;                   /* '<S22>/Compare' */
  boolean_T LogicalOperator4;          /* '<S6>/Logical Operator4' */
  boolean_T LogicalOperator2;          /* '<S5>/Logical Operator2' */
  boolean_T LogicalOperator1;          /* '<S6>/Logical Operator1' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
  boolean_T NSampleEnable;             /* '<S5>/N-Sample Enable' */
  boolean_T Compare_m[20];             /* '<S34>/Compare' */
  boolean_T Assignment2_m[20];         /* '<S52>/Assignment2' */
  boolean_T Selector2_fh;              /* '<S54>/Selector2' */
  boolean_T Rst_And;                   /* '<S39>/Rst_And' */
  boolean_T En_Or;                     /* '<S39>/En_Or' */
  boolean_T Assignment_d[2];           /* '<S31>/Assignment' */
  boolean_T In;                        /* '<S15>/In' */
  boolean_T Imagethresholding[48000];  /* '<S3>/Image thresholding' */
  boolean_T RelationalOperator1;       /* '<S6>/Relational Operator1' */
  boolean_T MultiportSelector1_o1;     /* '<S16>/Multiport Selector1' */
  boolean_T MultiportSelector1_o2;     /* '<S16>/Multiport Selector1' */
  boolean_T Selector_b;                /* '<S37>/Selector' */
  boolean_T Compare_p[20];             /* '<S59>/Compare' */
  boolean_T Compare_mb;                /* '<S56>/Compare' */
  boolean_T En_Not;                    /* '<S39>/En_Not' */
  boolean_T RelationalOperator2;       /* '<S6>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S6>/Relational Operator3' */
  boolean_T LogicalOperator2_n;        /* '<S6>/Logical Operator2' */
  boolean_T LogicalOperator_b;         /* '<S6>/Logical Operator' */
  boolean_T Compare_d;                 /* '<S9>/Compare' */
  boolean_T LogicalOperator7[2];       /* '<S16>/Logical Operator7' */
  boolean_T LogicalOperator8[2];       /* '<S16>/Logical Operator8' */
  boolean_T Compare_g[2];              /* '<S18>/Compare' */
  boolean_T Compare_n;                 /* '<S58>/Compare' */
  boolean_T Switch1_m[20];             /* '<S52>/Switch1' */
  boolean_T LogicalOperator2_j;        /* '<S24>/Logical Operator2' */
  boolean_T Switch_h;                  /* '<Root>/Switch' */
  boolean_T LogicalOperator1_m;        /* '<S24>/Logical Operator1' */
  boolean_T RelationalOperator2_e;     /* '<S24>/Relational Operator2' */
  boolean_T Compare_ni;                /* '<S60>/Compare' */
} B_vipldws_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_SDLV_T obj; /* '<S64>/MATLAB System' */
  void *MatrixConcatenation3_PWORK;    /* '<S28>/Matrix Concatenation3' */
  struct {
    void *LoggedData;
  } SafetyMarginSignals_PWORK;         /* '<S5>/Safety Margin Signals' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S68>/From Workspace' */

  void *MATLABSystem_PWORK;            /* '<S64>/MATLAB System' */
  real32_T FixPtUnitDelay1_DSTATE[40]; /* '<S36>/FixPt Unit Delay1' */
  real32_T UnitDelay2_DSTATE[80];      /* '<S32>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE[320];     /* '<S32>/Unit Delay3' */
  int32_T FixPtUnitDelay1_DSTATE_d[20];/* '<S35>/FixPt Unit Delay1' */
  int32_T En_Delay_DSTATE[20];         /* '<S32>/En_Delay' */
  int32_T Delay1_DSTATE[400];          /* '<S51>/Delay1' */
  int32_T Min_left_dis_DSTATE;         /* '<S24>/Min_left_dis' */
  int32_T Min_left_pts_DSTATE[4];      /* '<S24>/Min_left_pts' */
  int32_T Min_right_dis_DSTATE;        /* '<S24>/Min_right_dis' */
  int32_T Min_right_pts_DSTATE[4];     /* '<S24>/Min_right_pts' */
  real32_T ColorSpaceConversion_DWORK1[230400];/* '<S2>/Color Space  Conversion' */
  real32_T Imagethresholding_P_DW[256];/* '<S3>/Image thresholding' */
  real32_T Imagethresholding_MU_DW[256];/* '<S3>/Image thresholding' */
  real32_T FindLocalMaxima1_TEMP_IN_DWORKS[231];/* '<S30>/Find Local Maxima1' */
  real32_T FindLocalMaxima_TEMP_IN_DWORKS[112500];/* '<S28>/Find Local Maxima' */
  real32_T FindLocalMaxima1_TEMP_IN_DWOR_e[756];/* '<S29>/Find Local Maxima1' */
  real32_T ColorSpaceConversion1_DWORK1[86400];/* '<S2>/Color Space  Conversion1' */
  real32_T InsertText_colorVectorDW[3];/* '<S65>/Insert Text' */
  real32_T InsertTextLeftLane_colorVectorD[3];/* '<S67>/Insert Text: Left Lane' */
  real32_T InsertTextRightLane_colorVector[3];/* '<S67>/Insert Text: Right Lane' */
  real32_T DrawShapes_DW_FillColorAdd[3];/* '<S66>/DrawShapes' */
  real32_T DrawShapes_DW_OneMOpacity;  /* '<S66>/DrawShapes' */
  real32_T Add1_DWORK1;                /* '<S55>/Add1' */
  real32_T LDLFactorization_VMX[2];    /* '<S46>/LDL Factorization' */
  int32_T uDFIRFilter_bSEnd[2];        /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_bSPreEdg[2];     /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_bSPstEdg[2];     /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_bSStart[2];      /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_inSEnd[2];       /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_inSStart[2];     /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_mLoc[10];        /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_mWidth[10];      /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_oSPreEdg[2];     /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_oSPstEdg[2];     /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_oSStart[2];      /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_oSecEnd[2];      /* '<S3>/2-D FIR Filter' */
  int32_T uDFIRFilter_sCnt[2];         /* '<S3>/2-D FIR Filter' */
  int32_T FindLocalMaxima_DIMS1[2];    /* '<S28>/Find Local Maxima' */
  int32_T Selector1_DIMS1[2];          /* '<S28>/Selector1' */
  int32_T Transpose_DIMS1[2];          /* '<S28>/Transpose' */
  int32_T selectrho_DIMS1[2];          /* '<S28>/select rho' */
  int32_T Selectorrho_DIMS1[2];        /* '<S28>/Selector rho' */
  int32_T selectrho3_DIMS1[2];         /* '<S28>/select rho3' */
  int32_T Selectortheta_DIMS1[2];      /* '<S28>/Selector theta' */
  int32_T MatrixConcatenation3_DIMS1[2];/* '<S28>/Matrix Concatenation3' */
  int32_T DrawShapes_DW_Polygon[72];   /* '<S65>/DrawShapes' */
  int32_T DrawShapes_DW_Points[16];    /* '<S65>/DrawShapes' */
  int32_T InsertText_TxtLoc[2];        /* '<S65>/Insert Text' */
  int32_T InsertTextLeftLane_TxtLoc[2];/* '<S67>/Insert Text: Left Lane' */
  int32_T InsertTextRightLane_TxtLoc[2];/* '<S67>/Insert Text: Right Lane' */
  int32_T Selector2_DIMS1[2];          /* '<S52>/Selector2' */
  int32_T Selector1_DIMS1_l[2];        /* '<S54>/Selector1' */
  uint32_T FindLocalMaxima_NUMPEAKS_DWORK;/* '<S28>/Find Local Maxima' */
  uint32_T NSampleEnable_Counter;      /* '<S5>/N-Sample Enable' */
  uint32_T InsertText_TxtSelctn;       /* '<S65>/Insert Text' */
  uint32_T InsertTextLeftLane_TxtSelctn;/* '<S67>/Insert Text: Left Lane' */
  uint32_T InsertTextRightLane_TxtSelctn;/* '<S67>/Insert Text: Right Lane' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S68>/From Workspace' */

  uint16_T Counter_Count;              /* '<S17>/Counter' */
  int8_T Delay_DSTATE;                 /* '<S17>/Delay' */
  int8_T Delay1_DSTATE_e;              /* '<S17>/Delay1' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S36>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S35>/FixPt Unit Delay2' */
  boolean_T Delay1_DSTATE_g[20];       /* '<S52>/Delay1' */
  boolean_T Minimum_Valdata;           /* '<S52>/Minimum' */
  int8_T Enablesignalgenerator_SubsysRan;/* '<S28>/Enable signal generator' */
  int8_T SampleandHold_SubsysRanBC;    /* '<S6>/Sample and Hold' */
  int8_T Subsystem_SubsysRanBC;        /* '<S5>/Subsystem' */
  int8_T Draw3rdLine_SubsysRanBC;      /* '<S5>/Draw  3rd Line' */
  int8_T DrawPolygon_SubsysRanBC;      /* '<S65>/Draw  Polygon' */
  int8_T Selectalinefromtherepositoryifi;/* '<S50>/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines.' */
  int8_T Differencebetweentwolines_Subsy;/* '<S54>/Difference between  two lines' */
  int8_T Options_SubsysRanBC;          /* '<S39>/Options' */
  int8_T Core_SubsysRanBC;             /* '<S40>/Core' */
  uint8_T DrawShapes_DW_PixCount[320]; /* '<S65>/DrawShapes' */
  uint8_T InsertText_RepBuf;           /* '<S65>/Insert Text' */
  uint8_T InsertText_VarHolder;        /* '<S65>/Insert Text' */
  uint8_T InsertText_StringDataDW[74]; /* '<S65>/Insert Text' */
  uint8_T InsertTextLeftLane_RepBuf;   /* '<S67>/Insert Text: Left Lane' */
  uint8_T InsertTextLeftLane_VarHolder;/* '<S67>/Insert Text: Left Lane' */
  uint8_T InsertTextLeftLane_StringDataDW[53];/* '<S67>/Insert Text: Left Lane' */
  uint8_T InsertTextRightLane_RepBuf;  /* '<S67>/Insert Text: Right Lane' */
  uint8_T InsertTextRightLane_VarHolder;/* '<S67>/Insert Text: Right Lane' */
  uint8_T InsertTextRightLane_StringDataD[53];/* '<S67>/Insert Text: Right Lane' */
  uint8_T ForIterator_IterationMarker; /* '<S50>/For Iterator' */
  uint8_T ForIterator_IterationMarker_c;/* '<S54>/For Iterator' */
  uint8_T Iterator_IterationMarker[4]; /* '<S39>/Iterator' */
  boolean_T uDFIRFilter_isHgtUpd[2];   /* '<S3>/2-D FIR Filter' */
  boolean_T objisempty;                /* '<S64>/MATLAB System' */
  boolean_T LDLFactorization_STATE;    /* '<S46>/LDL Factorization' */
} DW_vipldws_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SampleandHold_Trig_ZCE;   /* '<S6>/Sample and Hold' */
} PrevZCX_vipldws_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: HoughTransform_SINE_TABLE_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  real32_T HoughTransform_SINE_TABLE_RTP[91];

  /* Computed Parameter: HoughTransform_FIRSTRHO_RTP
   * Referenced by: '<S3>/Hough Transform'
   */
  real32_T HoughTransform_FIRSTRHO_RTP;

  /* Computed Parameter: InsertText_GlyLBearings
   * Referenced by: '<S65>/Insert Text'
   */
  int32_T InsertText_GlyLBearings[256];

  /* Computed Parameter: InsertText_GlyTBearings
   * Referenced by: '<S65>/Insert Text'
   */
  int32_T InsertText_GlyTBearings[256];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  int32_T pooled2[256];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  int32_T pooled3[256];

  /* Computed Parameter: InsertText_GlyIndexes
   * Referenced by: '<S65>/Insert Text'
   */
  uint32_T InsertText_GlyIndexes[256];

  /* Computed Parameter: InsertText_stringRTP
   * Referenced by: '<S65>/Insert Text'
   */
  uint32_T InsertText_stringRTP[3];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint32_T pooled8[256];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint32_T pooled9[5];

  /* Computed Parameter: InsertText_GlyWidths
   * Referenced by: '<S65>/Insert Text'
   */
  uint16_T InsertText_GlyWidths[256];

  /* Computed Parameter: InsertText_GlyHeights
   * Referenced by: '<S65>/Insert Text'
   */
  uint16_T InsertText_GlyHeights[256];

  /* Computed Parameter: InsertText_GlyXAdvances
   * Referenced by: '<S65>/Insert Text'
   */
  uint16_T InsertText_GlyXAdvances[256];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint16_T pooled11[256];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint16_T pooled12[256];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint16_T pooled13[256];

  /* Computed Parameter: InsertText_StrArray
   * Referenced by: '<S65>/Insert Text'
   */
  uint8_T InsertText_StrArray[74];

  /* Computed Parameter: InsertText_GlyData
   * Referenced by: '<S65>/Insert Text'
   */
  uint8_T InsertText_GlyData[1810];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint8_T pooled15[53];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/Insert Text: Left Lane'
   *   '<S67>/Insert Text: Right Lane'
   */
  uint8_T pooled16[945];

  /* Expression: devName
   * Referenced by: '<S2>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP_vipldws_T;

/* Parameters (auto storage) */
struct P_vipldws_T_ {
  real32_T DrawShapes_color[3];        /* Mask Parameter: DrawShapes_color
                                        * Referenced by: '<S66>/DrawShapes'
                                        */
  real32_T uDFIRFilter_filterMtrx[3];  /* Mask Parameter: uDFIRFilter_filterMtrx
                                        * Referenced by: '<S3>/2-D FIR Filter'
                                        */
  real32_T DrawShapes_opacity;         /* Mask Parameter: DrawShapes_opacity
                                        * Referenced by: '<S66>/DrawShapes'
                                        */
  real32_T FindLocalMaxima1_threshold; /* Mask Parameter: FindLocalMaxima1_threshold
                                        * Referenced by: '<S30>/Find Local Maxima1'
                                        */
  real32_T FindLocalMaxima_threshold;  /* Mask Parameter: FindLocalMaxima_threshold
                                        * Referenced by: '<S28>/Find Local Maxima'
                                        */
  real32_T FindLocalMaxima1_threshold_b;/* Mask Parameter: FindLocalMaxima1_threshold_b
                                         * Referenced by: '<S29>/Find Local Maxima1'
                                         */
  real32_T UnitDelayResettable1_vinit[40];/* Mask Parameter: UnitDelayResettable1_vinit
                                           * Referenced by:
                                           *   '<S36>/Initial Condition'
                                           *   '<S36>/FixPt Unit Delay1'
                                           */
  int32_T CompareToConstant2_const;    /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S23>/Constant'
                                        */
  int32_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S56>/Constant'
                                        */
  int32_T CompareToConstant_const_m;   /* Mask Parameter: CompareToConstant_const_m
                                        * Referenced by: '<S57>/Constant'
                                        */
  int32_T CompareToConstant1_const;    /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S58>/Constant'
                                        */
  int32_T CompareToConstant10_const;   /* Mask Parameter: CompareToConstant10_const
                                        * Referenced by: '<S19>/Constant'
                                        */
  int32_T CompareToConstant1_const_o;  /* Mask Parameter: CompareToConstant1_const_o
                                        * Referenced by: '<S18>/Constant'
                                        */
  int32_T OnlyupdatethelineswhichKalmanfi;/* Mask Parameter: OnlyupdatethelineswhichKalmanfi
                                           * Referenced by: '<S34>/Constant'
                                           */
  int32_T DrawShapes_lineWidth;        /* Mask Parameter: DrawShapes_lineWidth
                                        * Referenced by: '<S62>/DrawShapes'
                                        */
  int32_T DrawShapes_lineWidth_i;      /* Mask Parameter: DrawShapes_lineWidth_i
                                        * Referenced by: '<S65>/DrawShapes'
                                        */
  int32_T InsertText_textLoc[2];       /* Mask Parameter: InsertText_textLoc
                                        * Referenced by: '<S65>/Insert Text'
                                        */
  int32_T UnitDelayResettable_vinit;   /* Mask Parameter: UnitDelayResettable_vinit
                                        * Referenced by:
                                        *   '<S35>/Initial Condition'
                                        *   '<S35>/FixPt Unit Delay1'
                                        */
  uint32_T NSampleEnable_ActiveLevel;  /* Mask Parameter: NSampleEnable_ActiveLevel
                                        * Referenced by: '<S5>/N-Sample Enable'
                                        */
  uint32_T NSampleEnable_N;            /* Mask Parameter: NSampleEnable_N
                                        * Referenced by: '<S5>/N-Sample Enable'
                                        */
  uint16_T Counter_InitialCount;       /* Mask Parameter: Counter_InitialCount
                                        * Referenced by: '<S17>/Counter'
                                        */
  int8_T CompareToConstant_const_h;    /* Mask Parameter: CompareToConstant_const_h
                                        * Referenced by: '<S21>/Constant'
                                        */
  int8_T CompareToConstant1_const_h;   /* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S22>/Constant'
                                        */
  int8_T CompareToConstant2_const_i;   /* Mask Parameter: CompareToConstant2_const_i
                                        * Referenced by: '<S61>/Constant'
                                        */
  int8_T CompareToConstant1_const_j;   /* Mask Parameter: CompareToConstant1_const_j
                                        * Referenced by: '<S60>/Constant'
                                        */
  int8_T CompareToConstant1_const_l;   /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S10>/Constant'
                                        */
  int8_T CompareToConstant2_const_h;   /* Mask Parameter: CompareToConstant2_const_h
                                        * Referenced by: '<S11>/Constant'
                                        */
  int8_T CompareToConstant_const_n;    /* Mask Parameter: CompareToConstant_const_n
                                        * Referenced by: '<S9>/Constant'
                                        */
  int8_T CompareToConstant3_const;     /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T DrawShapes_color_e[3];       /* Mask Parameter: DrawShapes_color_e
                                        * Referenced by: '<S62>/DrawShapes'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */
  real32_T Constant3_Value[16];        /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S41>/Constant3'
                                        */
  real32_T Hcst_Value[8];              /* Computed Parameter: Hcst_Value
                                        * Referenced by: '<S41>/Hcst'
                                        */
  real32_T Hcst_t_Value[8];            /* Computed Parameter: Hcst_t_Value
                                        * Referenced by: '<S41>/Hcst_t'
                                        */
  real32_T Constant2_Value[4];         /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S41>/Constant2'
                                        */
  real32_T Constant4_Value[16];        /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S41>/Constant4'
                                        */
  real32_T Constant5_Value[16];        /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S41>/Constant5'
                                        */
  real32_T Reset_Value_Value[16];      /* Computed Parameter: Reset_Value_Value
                                        * Referenced by: '<S42>/Reset_Value'
                                        */
  real32_T Reset_Value_Value_j[4];     /* Computed Parameter: Reset_Value_Value_j
                                        * Referenced by: '<S43>/Reset_Value'
                                        */
  real32_T Reset_Value_Value_b[2];     /* Computed Parameter: Reset_Value_Value_b
                                        * Referenced by: '<S44>/Reset_Value'
                                        */
  real32_T Reset_Value_Value_p[2];     /* Computed Parameter: Reset_Value_Value_p
                                        * Referenced by: '<S45>/Reset_Value'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S55>/Gain'
                                        */
  real32_T DrawShapes_RTP_FILLCOLOR[6];/* Computed Parameter: DrawShapes_RTP_FILLCOLOR
                                        * Referenced by: '<S65>/DrawShapes'
                                        */
  real32_T InsertText_TxtOpacity;      /* Computed Parameter: InsertText_TxtOpacity
                                        * Referenced by: '<S65>/Insert Text'
                                        */
  real32_T Yellow1_Value[15];          /* Computed Parameter: Yellow1_Value
                                        * Referenced by: '<S67>/Yellow1'
                                        */
  real32_T InsertTextLeftLane_TxtOpacity;/* Computed Parameter: InsertTextLeftLane_TxtOpacity
                                          * Referenced by: '<S67>/Insert Text: Left Lane'
                                          */
  real32_T InsertTextRightLane_TxtOpacity;/* Computed Parameter: InsertTextRightLane_TxtOpacity
                                           * Referenced by: '<S67>/Insert Text: Right Lane'
                                           */
  real32_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real32_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real32_T UnitDelay2_InitialCondition[80];/* Computed Parameter: UnitDelay2_InitialCondition
                                            * Referenced by: '<S32>/Unit Delay2'
                                            */
  real32_T UnitDelay3_InitialCondition[320];/* Computed Parameter: UnitDelay3_InitialCondition
                                             * Referenced by: '<S32>/Unit Delay3'
                                             */
  real32_T min_safety_Value;           /* Expression: single(0)
                                        * Referenced by: '<S14>/min_safety'
                                        */
  int32_T ForIterator_IterationLimit;  /* Computed Parameter: ForIterator_IterationLimit
                                        * Referenced by: '<S7>/For Iterator'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S25>/Constant'
                                        */
  int32_T Min_left_dis_InitialCondition;/* Computed Parameter: Min_left_dis_InitialCondition
                                         * Referenced by: '<S24>/Min_left_dis'
                                         */
  int32_T Min_left_pts_InitialCondition[4];/* Computed Parameter: Min_left_pts_InitialCondition
                                            * Referenced by: '<S24>/Min_left_pts'
                                            */
  int32_T Min_right_dis_InitialCondition;/* Computed Parameter: Min_right_dis_InitialCondition
                                          * Referenced by: '<S24>/Min_right_dis'
                                          */
  int32_T Min_right_pts_InitialCondition[4];/* Computed Parameter: Min_right_pts_InitialCondition
                                             * Referenced by: '<S24>/Min_right_pts'
                                             */
  int32_T Iterator_IterationLimit;     /* Computed Parameter: Iterator_IterationLimit
                                        * Referenced by: '<S39>/Iterator'
                                        */
  int32_T Constant_Value_l;            /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S54>/Constant'
                                        */
  int32_T ForIterator_IterationLimit_g;/* Computed Parameter: ForIterator_IterationLimit_g
                                        * Referenced by: '<S54>/For Iterator'
                                        */
  int32_T Constant2_Value_o[400];      /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S53>/Constant2'
                                        */
  int32_T ForIterator_IterationLimit_j;/* Computed Parameter: ForIterator_IterationLimit_j
                                        * Referenced by: '<S50>/For Iterator'
                                        */
  int32_T Constant_Value_iw;           /* Computed Parameter: Constant_Value_iw
                                        * Referenced by: '<S51>/Constant'
                                        */
  int32_T ForIterator_IterationLimit_n;/* Computed Parameter: ForIterator_IterationLimit_n
                                        * Referenced by: '<S51>/For Iterator'
                                        */
  int32_T Delay1_InitialCondition;     /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<S51>/Delay1'
                                        */
  int32_T Minimum_prodDims[2];         /* Computed Parameter: Minimum_prodDims
                                        * Referenced by: '<S51>/Minimum'
                                        */
  int32_T Constant2_Value_d[40];       /* Computed Parameter: Constant2_Value_d
                                        * Referenced by: '<S51>/Constant2'
                                        */
  int32_T Constant1_Value_c[20];       /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S51>/Constant1'
                                        */
  int32_T Constant2_Value_b[20];       /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S52>/Constant2'
                                        */
  int32_T Constant_Value_i0;           /* Computed Parameter: Constant_Value_i0
                                        * Referenced by: '<S52>/Constant'
                                        */
  int32_T Constant_Value_m;            /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S59>/Constant'
                                        */
  int32_T ForIterator_IterationLimit_a;/* Computed Parameter: ForIterator_IterationLimit_a
                                        * Referenced by: '<S52>/For Iterator'
                                        */
  int32_T Bias_Bias;                   /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S52>/Bias'
                                        */
  int32_T Saturation_UpperSat_m;       /* Computed Parameter: Saturation_UpperSat_m
                                        * Referenced by: '<S52>/Saturation'
                                        */
  int32_T Saturation_LowerSat_o;       /* Computed Parameter: Saturation_LowerSat_o
                                        * Referenced by: '<S52>/Saturation'
                                        */
  int32_T ForIterator_IterationLimit_gd;/* Computed Parameter: ForIterator_IterationLimit_gd
                                         * Referenced by: '<S37>/For Iterator'
                                         */
  int32_T DSPConstant_Value[2];        /* Computed Parameter: DSPConstant_Value
                                        * Referenced by: '<S69>/DSP Constant'
                                        */
  int32_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S69>/Switch'
                                        */
  int32_T DSPConstant2_Value[2];       /* Computed Parameter: DSPConstant2_Value
                                        * Referenced by: '<S69>/DSP Constant2'
                                        */
  int32_T Switch1_Threshold;           /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S69>/Switch1'
                                        */
  int32_T Bias1_Bias[2];               /* Computed Parameter: Bias1_Bias
                                        * Referenced by: '<S67>/Bias1'
                                        */
  int32_T Bias2_Bias[2];               /* Computed Parameter: Bias2_Bias
                                        * Referenced by: '<S67>/Bias2'
                                        */
  int32_T En_Delay_InitialCondition;   /* Computed Parameter: En_Delay_InitialCondition
                                        * Referenced by: '<S32>/En_Delay'
                                        */
  int32_T Bias1_Bias_l;                /* Computed Parameter: Bias1_Bias_l
                                        * Referenced by: '<S1>/Bias1'
                                        */
  int32_T DrawLines4_Value[4];         /* Computed Parameter: DrawLines4_Value
                                        * Referenced by: '<S6>/Draw Lines4'
                                        */
  int32_T Constant_Value_j[3];         /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S8>/Constant'
                                        */
  int32_T Bias3_Bias[4];               /* Computed Parameter: Bias3_Bias
                                        * Referenced by: '<S5>/Bias3'
                                        */
  int32_T Bias_Bias_i[8];              /* Computed Parameter: Bias_Bias_i
                                        * Referenced by: '<S5>/Bias'
                                        */
  int32_T Saturation_UpperSat_h;       /* Computed Parameter: Saturation_UpperSat_h
                                        * Referenced by: '<S14>/Saturation'
                                        */
  int32_T Saturation_LowerSat_a;       /* Computed Parameter: Saturation_LowerSat_a
                                        * Referenced by: '<S14>/Saturation'
                                        */
  uint32_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S51>/Delay1'
                                        */
  uint32_T Delay1_DelayLength_n;       /* Computed Parameter: Delay1_DelayLength_n
                                        * Referenced by: '<S52>/Delay1'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S17>/Delay'
                                        */
  uint32_T Delay1_DelayLength_j;       /* Computed Parameter: Delay1_DelayLength_j
                                        * Referenced by: '<S17>/Delay1'
                                        */
  int32_T Distancethresholdfordeparturewa;/* Computed Parameter: Distancethresholdfordeparturewa
                                           * Referenced by: '<S1>/Distance threshold  for departure warning'
                                           */
  int32_T rho_1_Gain;                  /* Computed Parameter: rho_1_Gain
                                        * Referenced by: '<S1>/rho_1'
                                        */
  uint16_T Bias2_Bias_k;               /* Computed Parameter: Bias2_Bias_k
                                        * Referenced by: '<S29>/Bias2'
                                        */
  uint16_T Bias3_Bias_c;               /* Computed Parameter: Bias3_Bias_c
                                        * Referenced by: '<S29>/Bias3'
                                        */
  uint16_T Bias2_Bias_h;               /* Computed Parameter: Bias2_Bias_h
                                        * Referenced by: '<S30>/Bias2'
                                        */
  uint16_T Bias3_Bias_d;               /* Computed Parameter: Bias3_Bias_d
                                        * Referenced by: '<S30>/Bias3'
                                        */
  int8_T Constant1_Value_b;            /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S6>/Constant1'
                                        */
  int8_T Constant_Value_f;             /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S6>/Constant'
                                        */
  int8_T DrawLines3_Value;             /* Computed Parameter: DrawLines3_Value
                                        * Referenced by: '<S6>/Draw Lines3'
                                        */
  int8_T DrawLines2_Value;             /* Computed Parameter: DrawLines2_Value
                                        * Referenced by: '<S6>/Draw Lines2'
                                        */
  int8_T DrawLines1_Value;             /* Computed Parameter: DrawLines1_Value
                                        * Referenced by: '<S6>/Draw Lines1'
                                        */
  int8_T DrawLines_Value;              /* Computed Parameter: DrawLines_Value
                                        * Referenced by: '<S6>/Draw Lines'
                                        */
  int8_T Bias_Bias_d;                  /* Computed Parameter: Bias_Bias_d
                                        * Referenced by: '<S65>/Bias'
                                        */
  int8_T Bias1_Bias_e;                 /* Computed Parameter: Bias1_Bias_e
                                        * Referenced by: '<S65>/Bias1'
                                        */
  int8_T Delay_InitialCondition;       /* Expression: int8(-1)
                                        * Referenced by: '<S17>/Delay'
                                        */
  int8_T Delay1_InitialCondition_p;    /* Expression: int8(-1)
                                        * Referenced by: '<S17>/Delay1'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S36>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_p;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_p
                                           * Referenced by: '<S35>/FixPt Unit Delay2'
                                           */
  uint8_T Switch_CurrentSetting;       /* Computed Parameter: Switch_CurrentSetting
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S35>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_e;       /* Computed Parameter: FixPtConstant_Value_e
                                        * Referenced by: '<S36>/FixPt Constant'
                                        */
  boolean_T DrawPolygon_Value;         /* Computed Parameter: DrawPolygon_Value
                                        * Referenced by: '<Root>/Draw Polygon'
                                        */
  boolean_T DrawLines_Value_j;         /* Computed Parameter: DrawLines_Value_j
                                        * Referenced by: '<Root>/Draw Lines'
                                        */
  boolean_T _Y0;                       /* Computed Parameter: _Y0
                                        * Referenced by: '<S15>/ '
                                        */
  boolean_T Constant_Value_b[2];       /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S31>/Constant'
                                        */
  boolean_T Constant1_Value_d;         /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S31>/Constant1'
                                        */
  boolean_T Delay1_InitialCondition_n; /* Computed Parameter: Delay1_InitialCondition_n
                                        * Referenced by: '<S52>/Delay1'
                                        */
  boolean_T Constant_Value_n;          /* Expression: false
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_vipldws_T {
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

/* Block parameters (auto storage) */
extern P_vipldws_T vipldws_P;

/* Block signals (auto storage) */
extern B_vipldws_T vipldws_B;

/* Block states (auto storage) */
extern DW_vipldws_T vipldws_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_vipldws_T vipldws_PrevZCX;

/* Constant parameters (auto storage) */
extern const ConstP_vipldws_T vipldws_ConstP;

/* Model entry point functions */
extern void vipldws_initialize(void);
extern void vipldws_step(void);
extern void vipldws_terminate(void);

/* Real-time Model object */
extern RT_MODEL_vipldws_T *const vipldws_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/From Multimedia File1' : Unused code path elimination
 * Block '<S38>/Check Signal Attributes' : Unused code path elimination
 * Block '<S47>/Check Signal Attributes' : Unused code path elimination
 * Block '<S48>/Check Signal Attributes' : Unused code path elimination
 * Block '<S49>/Check Signal Attributes' : Unused code path elimination
 * Block '<S35>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type  Conversion1' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type  Conversion2' : Eliminate redundant data type conversion
 * Block '<S29>/Zero-Order Hold3' : Eliminated since input and output rates are identical
 * Block '<S29>/Zero-Order Hold4' : Eliminated since input and output rates are identical
 * Block '<S30>/Zero-Order Hold3' : Eliminated since input and output rates are identical
 * Block '<S30>/Zero-Order Hold4' : Eliminated since input and output rates are identical
 * Block '<S28>/Zero-Order Hold1' : Eliminated since input and output rates are identical
 * Block '<S28>/Zero-Order Hold2' : Eliminated since input and output rates are identical
 * Block '<S41>/P_Reshape' : Reshape block reduction
 * Block '<S51>/Reshape' : Reshape block reduction
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
 * '<Root>' : 'vipldws'
 * '<S1>'   : 'vipldws/Departure Warning'
 * '<S2>'   : 'vipldws/Input'
 * '<S3>'   : 'vipldws/Lane Detection'
 * '<S4>'   : 'vipldws/Lane Tracking'
 * '<S5>'   : 'vipldws/Output'
 * '<S6>'   : 'vipldws/Departure Warning/Departure detection'
 * '<S7>'   : 'vipldws/Departure Warning/Find the left and  right lanes from the depository'
 * '<S8>'   : 'vipldws/Departure Warning/Departure detection/Change Index'
 * '<S9>'   : 'vipldws/Departure Warning/Departure detection/Compare To Constant'
 * '<S10>'  : 'vipldws/Departure Warning/Departure detection/Compare To Constant1'
 * '<S11>'  : 'vipldws/Departure Warning/Departure detection/Compare To Constant2'
 * '<S12>'  : 'vipldws/Departure Warning/Departure detection/Compare To Constant3'
 * '<S13>'  : 'vipldws/Departure Warning/Departure detection/DetectColorAndType1'
 * '<S14>'  : 'vipldws/Departure Warning/Departure detection/Safety Margin'
 * '<S15>'  : 'vipldws/Departure Warning/Departure detection/Sample and Hold'
 * '<S16>'  : 'vipldws/Departure Warning/Departure detection/Subsystem3'
 * '<S17>'  : 'vipldws/Departure Warning/Departure detection/subsystem'
 * '<S18>'  : 'vipldws/Departure Warning/Departure detection/Subsystem3/Compare To Constant1'
 * '<S19>'  : 'vipldws/Departure Warning/Departure detection/Subsystem3/Compare To Constant10'
 * '<S20>'  : 'vipldws/Departure Warning/Departure detection/subsystem/Combine Left Right Departure'
 * '<S21>'  : 'vipldws/Departure Warning/Departure detection/subsystem/Compare To Constant'
 * '<S22>'  : 'vipldws/Departure Warning/Departure detection/subsystem/Compare To Constant1'
 * '<S23>'  : 'vipldws/Departure Warning/Find the left and  right lanes from the depository/Compare To Constant2'
 * '<S24>'  : 'vipldws/Departure Warning/Find the left and  right lanes from the depository/Search for the left and right lanes'
 * '<S25>'  : 'vipldws/Departure Warning/Find the left and  right lanes from the depository/Search for the left and right lanes/Left lane?'
 * '<S26>'  : 'vipldws/Lane Detection/3rd lane: Right-Left'
 * '<S27>'  : 'vipldws/Lane Detection/Overwrite'
 * '<S28>'  : 'vipldws/Lane Detection/Peak detection'
 * '<S29>'  : 'vipldws/Lane Detection/3rd lane: Right-Left/Find Left 3rd Lane'
 * '<S30>'  : 'vipldws/Lane Detection/3rd lane: Right-Left/Find Right 3rd Lane'
 * '<S31>'  : 'vipldws/Lane Detection/Peak detection/Enable signal generator'
 * '<S32>'  : 'vipldws/Lane Tracking/Kalman Filter'
 * '<S33>'  : 'vipldws/Lane Tracking/Matching'
 * '<S34>'  : 'vipldws/Lane Tracking/Only update the lines which  Kalman filter has been  trained for enough time'
 * '<S35>'  : 'vipldws/Lane Tracking/Unit Delay Resettable'
 * '<S36>'  : 'vipldws/Lane Tracking/Unit Delay Resettable1'
 * '<S37>'  : 'vipldws/Lane Tracking/Update'
 * '<S38>'  : 'vipldws/Lane Tracking/Kalman Filter/Check Signal Attributes'
 * '<S39>'  : 'vipldws/Lane Tracking/Kalman Filter/Control'
 * '<S40>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options'
 * '<S41>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Core'
 * '<S42>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/P_prd_Assign'
 * '<S43>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/X_prd_Assign'
 * '<S44>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Z_est_Assign'
 * '<S45>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Z_prd_Assign'
 * '<S46>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Core/LDL Solver'
 * '<S47>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Core/LDL Solver/Check Signal Attributes'
 * '<S48>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Core/LDL Solver/Check Signal Attributes1'
 * '<S49>'  : 'vipldws/Lane Tracking/Kalman Filter/Control/Options/Core/LDL Solver/Check Signal Attributes2'
 * '<S50>'  : 'vipldws/Lane Tracking/Matching/Calculate the distances between  the lines found in the current  frame and those in the repository'
 * '<S51>'  : 'vipldws/Lane Tracking/Matching/Find the best  matches between the current  lines and those in the repository'
 * '<S52>'  : 'vipldws/Lane Tracking/Matching/Update the repository'
 * '<S53>'  : 'vipldws/Lane Tracking/Matching/Calculate the distances between  the lines found in the current  frame and those in the repository/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines.'
 * '<S54>'  : 'vipldws/Lane Tracking/Matching/Calculate the distances between  the lines found in the current  frame and those in the repository/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines./Calculate the distances between  the chosen line in the repository  and all input lines.'
 * '<S55>'  : 'vipldws/Lane Tracking/Matching/Calculate the distances between  the lines found in the current  frame and those in the repository/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines./Calculate the distances between  the chosen line in the repository  and all input lines./Difference between  two lines'
 * '<S56>'  : 'vipldws/Lane Tracking/Matching/Find the best  matches between the current  lines and those in the repository/Compare To Constant'
 * '<S57>'  : 'vipldws/Lane Tracking/Matching/Update the repository/Compare To Constant'
 * '<S58>'  : 'vipldws/Lane Tracking/Matching/Update the repository/Compare To Constant1'
 * '<S59>'  : 'vipldws/Lane Tracking/Matching/Update the repository/Compare To Zero'
 * '<S60>'  : 'vipldws/Output/Compare To Constant1'
 * '<S61>'  : 'vipldws/Output/Compare To Constant2'
 * '<S62>'  : 'vipldws/Output/Draw  3rd Line'
 * '<S63>'  : 'vipldws/Output/Exclude 3rd Lane'
 * '<S64>'  : 'vipldws/Output/SDL Video Display'
 * '<S65>'  : 'vipldws/Output/Subsystem'
 * '<S66>'  : 'vipldws/Output/Subsystem/Draw  Polygon'
 * '<S67>'  : 'vipldws/Output/Subsystem/Draw Color and Marker Type'
 * '<S68>'  : 'vipldws/Output/Subsystem/Signal From Workspace'
 * '<S69>'  : 'vipldws/Output/Subsystem/Draw  Polygon/Line to Polygon Coordinates'
 */
#endif                                 /* RTW_HEADER_vipldws_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
