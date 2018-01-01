/*
 * File: vipldws.c
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

#include "vipldws.h"
#include "vipldws_private.h"
#include "vipldws_dt.h"

/* Block signals (auto storage) */
B_vipldws_T vipldws_B;

/* Block states (auto storage) */
DW_vipldws_T vipldws_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_vipldws_T vipldws_PrevZCX;

/* Real-time model */
RT_MODEL_vipldws_T vipldws_M_;
RT_MODEL_vipldws_T *const vipldws_M = &vipldws_M_;

/* Forward declaration for local functions */
static void vipldws_Corr_M_IBRepl_uS_hS_yS(const real32_T h[], const int32_T
  hLoc[], const int32_T hDims[], const real32_T u[], const int32_T uDims[],
  real32_T y[], const int32_T yDims[], const int32_T yOrigin[]);
int8_T div_s8s32_floor(int32_T numerator, int32_T denominator)
{
  int8_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? 127 : -128;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? (int32_T)(int8_T)-(int32_T)
      tempAbsQuotient : (int32_T)(int8_T)tempAbsQuotient;
  }

  return quotient;
}

int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

real32_T PadBRepl_uS(const real32_T u[], const int32_T uStride[], int32_T idx[],
                     const int32_T uStart[], const int32_T uEnd[], const int32_T
                     sNumPreEdges, const int32_T sPreEdges[], const int32_T
                     sNumPostEdges, const int32_T sPostEdges[])
{
  real32_T uOut;
  int32_T edgeNum;

  /* S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
  /* For boundary sectors: */
  /* -check if index is outside of input bounds ... */
  /*   -if so then return pad extended value */
  /*   -else fetch input data at the index */
  /* loop through preEdges */
  for (edgeNum = 0; edgeNum < sNumPreEdges; edgeNum++) {
    if (idx[sPreEdges[edgeNum]] < uStart[sPreEdges[edgeNum]]) {
      /* redirect index across a pre edge */
      /* replicate pre-edge value */
      idx[sPreEdges[edgeNum]] = uStart[sPreEdges[edgeNum]];
    }
  }

  /* loop through postEdges */
  for (edgeNum = 0; edgeNum < sNumPostEdges; edgeNum++) {
    if (idx[sPostEdges[edgeNum]] > uEnd[sPostEdges[edgeNum]]) {
      /* redirect index across a post edge */
      /* replicate post-edge value */
      idx[sPostEdges[edgeNum]] = uEnd[sPostEdges[edgeNum]];
    }
  }

  /* linearize index and return input data */
  uOut = u[idx[0U] * uStride[0U] + idx[1U] * uStride[1U]];

  /* End of S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
  return uOut;
}

static void vipldws_Corr_M_IBRepl_uS_hS_yS(const real32_T h[], const int32_T
  hLoc[], const int32_T hDims[], const real32_T u[], const int32_T uDims[],
  real32_T y[], const int32_T yDims[], const int32_T yOrigin[])
{
  real32_T acc;
  int32_T hLoc_0;
  int32_T hEnd;
  int32_T uOrigin;
  int32_T uEnd;
  int32_T yEnd;
  int32_T yPost;
  int32_T hPost;
  int32_T bPreEnd;
  int32_T bPostEnd;
  boolean_T isSEmpty;
  boolean_T isEnd;
  boolean_T dimIsPre;
  real32_T uI;

  /* S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
  vipldws_B.uOrigin[0U] = 0;
  vipldws_B.uEnd[0U] = uDims[0U] - 1;
  vipldws_B.uStride[0U] = 1;
  vipldws_B.uOrigin[1U] = 0;
  vipldws_B.uEnd[1U] = uDims[1U] - 1;
  vipldws_B.uStride[1U] = uDims[0U];
  vipldws_B.hEnd[0U] = hDims[0U] - 1;
  vipldws_B.hEnd[1U] = hDims[1U] - 1;
  vipldws_B.yEnd[0U] = yDims[0U] - 1;
  vipldws_B.yEnd[1U] = yDims[1U] - 1;

  /*  COMPUTE MARGINS BETWEEN INPUT AND OUTPUT       */
  /* =============================================== */
  /*      _________________________________________  */
  /*     |u                                        | */
  /*     |                                         | */
  /*     |         ______________________          | */
  /*     |        |y                     |         | */
  /*     |        |                      |         | */
  /*     |<-yPre->|                      |<-yPost->| */
  /*     |        |                      |         | */
  /*  */
  /*  KERNEL MARIGINS                               */
  /* ============================================== */
  /*      ____________________  */
  /*     |h                   | */
  /*     |        |<--hPost-->| */
  /*     |        |           | */
  /*     |        x(hCenter)  | */
  /*     |<-hPre->|           | */
  /*     |        |           | */
  /*  */
  /*  MARGINS (Valid, Boundary and Outside) definitions: */
  /*  Valid Margin: Processing region where entire kernel stays inside input boundaries. All input data thus considered is 'valid' data */
  /*  Boundary Margin: Processing region where part of kernel stays inside the input boundaries and part of it goes outside input boundaries. */
  /*  Outside Margin: Processing region where entire kernel stays outside the input boundaries and never touches input data. In most situations this region does not need to be processed. Instead output pad values are filled in */
  /* =========================================================== */
  /*   y |        |        |               |         |         | */
  /*     |<-oPre->|<-bPre->|<----valid---->|<-bPost->|<-oPost->| */
  /*     |        |        |               |         |         | */
  /*  */
  /*  All margin locations are stored relative to the output origin */
  /* margins between y and u */
  uOrigin = -yOrigin[0];
  yPost = (yOrigin[0] + vipldws_B.yEnd[0]) - vipldws_B.uEnd[0];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPost = hLoc[0] + vipldws_B.hEnd[0];

  /* margins outside of kernel's influence around input */
  /* note that we subtract h'Post' from y'Pre' */
  uEnd = uOrigin - hPost;

  /* note that we subtract h'Pre' from y'Post' */
  hEnd = yPost + hLoc[0];
  uOrigin -= hLoc[0];
  hPost += yPost;

  /* W refers to margin Width */
  /* L refers to margin Location */
  /* outer Pre */
  /* saturate */
  if (uEnd < 0) {
    hLoc_0 = 0;
  } else if (uEnd > yDims[0]) {
    hLoc_0 = yDims[0];
  } else {
    hLoc_0 = uEnd;
  }

  /* boundary Pre */
  /* saturate */
  if (uOrigin < 0) {
    uOrigin = 0;
  } else {
    if (uOrigin > yDims[0]) {
      uOrigin = yDims[0];
    }
  }

  if (uEnd < 0) {
    uEnd = 0;
  } else {
    if (uEnd > yDims[0]) {
      uEnd = yDims[0];
    }
  }

  uEnd = uOrigin - uEnd;
  uOrigin = yOrigin[0] + hLoc_0;

  /* outer Post */
  /* saturate */
  if (hEnd < 0) {
    yPost = 0;
  } else if (hEnd > yDims[0]) {
    yPost = yDims[0];
  } else {
    yPost = hEnd;
  }

  yEnd = ((yOrigin[0] + vipldws_B.yEnd[0]) - yPost) + 1;

  /* boundary Post */
  /* saturate */
  if (hPost < 0) {
    hPost = 0;
  } else {
    if (hPost > yDims[0]) {
      hPost = yDims[0];
    }
  }

  if (hEnd < 0) {
    hEnd = 0;
  } else {
    if (hEnd > yDims[0]) {
      hEnd = yDims[0];
    }
  }

  hEnd = hPost - hEnd;
  hPost = yEnd - hEnd;
  bPreEnd = uOrigin + uEnd;
  bPostEnd = hPost + hEnd;
  if (bPreEnd - 1 >= hPost) {
    /* defines situation where hDims > uDims */
    uEnd = hPost - uOrigin;
    hPost = bPreEnd;
    hEnd = bPostEnd - bPreEnd;
  }

  /* assign to the margin set of mLoc and mWidth */
  vipldws_B.mLoc[0] = uOrigin + uEnd;
  vipldws_B.mWidth[0] = (((yDims[0] - hLoc_0) - yPost) - uEnd) - hEnd;
  vipldws_B.mLoc[2] = uOrigin;
  vipldws_B.mWidth[2] = uEnd;
  vipldws_B.mLoc[4] = hPost;
  vipldws_B.mWidth[4] = hEnd;
  vipldws_B.mLoc[6] = yOrigin[0];
  vipldws_B.mWidth[6] = hLoc_0;
  vipldws_B.mLoc[8] = yEnd;
  vipldws_B.mWidth[8] = yPost;

  /* margins between y and u */
  uOrigin = -yOrigin[1];
  yPost = (yOrigin[1] + vipldws_B.yEnd[1]) - vipldws_B.uEnd[1];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPost = hLoc[1] + vipldws_B.hEnd[1];

  /* margins outside of kernel's influence around input */
  /* note that we subtract h'Post' from y'Pre' */
  uEnd = uOrigin - hPost;

  /* note that we subtract h'Pre' from y'Post' */
  hEnd = yPost + hLoc[1];
  uOrigin -= hLoc[1];
  hPost += yPost;

  /* W refers to margin Width */
  /* L refers to margin Location */
  /* outer Pre */
  /* saturate */
  if (uEnd < 0) {
    hLoc_0 = 0;
  } else if (uEnd > yDims[1]) {
    hLoc_0 = yDims[1];
  } else {
    hLoc_0 = uEnd;
  }

  /* boundary Pre */
  /* saturate */
  if (uOrigin < 0) {
    uOrigin = 0;
  } else {
    if (uOrigin > yDims[1]) {
      uOrigin = yDims[1];
    }
  }

  if (uEnd < 0) {
    uEnd = 0;
  } else {
    if (uEnd > yDims[1]) {
      uEnd = yDims[1];
    }
  }

  uEnd = uOrigin - uEnd;
  uOrigin = yOrigin[1] + hLoc_0;

  /* outer Post */
  /* saturate */
  if (hEnd < 0) {
    yPost = 0;
  } else if (hEnd > yDims[1]) {
    yPost = yDims[1];
  } else {
    yPost = hEnd;
  }

  yEnd = ((yOrigin[1] + vipldws_B.yEnd[1]) - yPost) + 1;

  /* boundary Post */
  /* saturate */
  if (hPost < 0) {
    hPost = 0;
  } else {
    if (hPost > yDims[1]) {
      hPost = yDims[1];
    }
  }

  if (hEnd < 0) {
    hEnd = 0;
  } else {
    if (hEnd > yDims[1]) {
      hEnd = yDims[1];
    }
  }

  hEnd = hPost - hEnd;
  hPost = yEnd - hEnd;
  bPreEnd = uOrigin + uEnd;
  bPostEnd = hPost + hEnd;
  if (bPreEnd - 1 >= hPost) {
    /* defines situation where hDims > uDims */
    uEnd = hPost - uOrigin;
    hPost = bPreEnd;
    hEnd = bPostEnd - bPreEnd;
  }

  /* assign to the margin set of mLoc and mWidth */
  vipldws_B.mLoc[1] = uOrigin + uEnd;
  vipldws_B.mWidth[1] = (((yDims[1] - hLoc_0) - yPost) - uEnd) - hEnd;
  vipldws_B.mLoc[3] = uOrigin;
  vipldws_B.mWidth[3] = uEnd;
  vipldws_B.mLoc[5] = hPost;
  vipldws_B.mWidth[5] = hEnd;
  vipldws_B.mLoc[7] = yOrigin[1];
  vipldws_B.mWidth[7] = hLoc_0;
  vipldws_B.mLoc[9] = yEnd;
  vipldws_B.mWidth[9] = yPost;

  /*  ////////////////////////////////////////// */
  /*  COMPUTE INSIDE SECTOR                      */
  /*  ////////////////////////////////////////// */
  /*  ========================================== */
  /*  Original arrangement of sectors            */
  /*  ========================================== */
  /*   |   3   |   1   |   0   |   2   |   4   | */
  /*   | OutPre| BndPre| Inside|BndPost|OutPost| */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,3) | (3,1) | (3,0) | (3,2) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  1| (1,3) | (1,1) | (1,0) | (1,2) | (1,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*   |       |       | VALID |       |       | */
  /*  0| (0,3) | (0,1) | (0,0) | (0,2) | (0,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  2| (2,3) | (2,1) | (2,0) | (2,2) | (2,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,3) | (4,1) | (4,0) | (4,2) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  /*  Sectors rearranged in order from 0 to 4 */
  /*  ========================================== */
  /*   |   0   |   1   |   2   |   3   |   4   | */
  /*   | Inside| BndPre|BndPost| OutPre|OutPost| */
  /*    _______________________________________  */
  /*   |///////|       |       |       |       | */
  /*   |/VALID/|       |       |       |       | */
  /*  0|/(0,0)/| (0,1) | (0,2) | (0,3) | (0,4) | */
  /*   |///////|       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  1| (1,0) | (1,1) | (1,2) | (1,3) | (1,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  2| (2,0) | (2,1) | (2,2) | (2,3) | (2,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  /* setup counter for valid sector, that is 0 in all dims */
  /* compute inside sector */
  /* compute sector if not empty */
  if (!((vipldws_B.mWidth[0] <= 0) || (vipldws_B.mWidth[1] <= 0))) {
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* setup indices for the loops */
    /* Origin stores the origin of Y with respect to U */
    /*  where the origin of Y is at its top left corner */
    /* Compute offset between origin of Y and origin of U(0,0) */
    vipldws_B.offset_p[0U] = -yOrigin[0U];
    vipldws_B.offset_p[1U] = -yOrigin[1U];

    /* sector start and end were computed relative to U */
    /* make them relative to Y by adding offset */
    vipldws_B.sStart_c[0U] = vipldws_B.mLoc[0] + vipldws_B.offset_p[0U];
    vipldws_B.sEnd_b[0U] = ((vipldws_B.mLoc[0] + vipldws_B.mWidth[0]) +
      vipldws_B.offset_p[0U]) - 1;
    vipldws_B.sStart_c[1U] = vipldws_B.mLoc[1] + vipldws_B.offset_p[1U];
    vipldws_B.sEnd_b[1U] = ((vipldws_B.mLoc[1] + vipldws_B.mWidth[1]) +
      vipldws_B.offset_p[1U]) - 1;

    /* adjust offset for kernel center */
    vipldws_B.offset_p[0U] -= hLoc[0U];
    vipldws_B.offset_p[1U] -= hLoc[1U];

    /* loop kernel over data */
    vipldws_B.idxB_c[1U] = vipldws_B.sStart_c[1U];
    while (vipldws_B.idxB_c[1U] <= vipldws_B.sEnd_b[1U]) {
      vipldws_B.idxALin[1U] = (vipldws_B.idxB_c[1U] - vipldws_B.offset_p[1U]) *
        uDims[0U];
      vipldws_B.idxBLin[1U] = yDims[0U] * vipldws_B.idxB_c[1U];
      vipldws_B.idxB_c[0U] = vipldws_B.sStart_c[0U];
      while (vipldws_B.idxB_c[0U] <= vipldws_B.sEnd_b[0U]) {
        vipldws_B.idxALin[0U] = (vipldws_B.idxB_c[0U] - vipldws_B.offset_p[0U])
          + vipldws_B.idxALin[1U];
        vipldws_B.idxBLin[0U] = vipldws_B.idxBLin[1U] + vipldws_B.idxB_c[0U];
        uOrigin = vipldws_B.idxALin[0U];

        /* loop over kernel and compute conv/corr */
        hPost = 0;
        acc = 0.0F;

        /* loop over kernel */
        vipldws_B.hIdxA[1U] = 0;
        while (vipldws_B.hIdxA[1U] <= vipldws_B.hEnd[1U]) {
          vipldws_B.hIdxA[0U] = 0;
          while (vipldws_B.hIdxA[0U] <= vipldws_B.hEnd[0U]) {
            acc += u[uOrigin] * h[hPost];
            uOrigin++;
            hPost++;
            vipldws_B.hIdxA[0U]++;
          }

          uOrigin = (uOrigin + uDims[0U]) - hDims[0U];
          vipldws_B.hIdxA[1U]++;
        }

        if (vipldws_B.idxBLin[0U] >= 0) {
          y[vipldws_B.idxBLin[0U]] = acc;
        }

        vipldws_B.idxB_c[0U]++;
      }

      vipldws_B.idxB_c[1U]++;
    }
  }

  /*  ////////////////////////////////////////// */
  /*  COMPUTE ON-BOUNDARY SECTORS                */
  /*  ////////////////////////////////////////// */
  /* =========================================== */
  /*   |   0   |   1   |   2   |   3   |   4   | */
  /*   | Inside| BndPre|BndPost| OutPre|OutPost| */
  /*    _______________________________________  */
  /*   |       |///////|///////|       |       | */
  /*   | VALID |///////|///////|       |       | */
  /*  0| (0,0) |/(0,1)/|/(0,2)/| (0,3) | (0,4) | */
  /*   |       |///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |///////|///////|///////|       |       | */
  /*  1|/(1,0)/|/(1,1)/|/(1,2)/| (1,3) | (1,4) | */
  /*   |///////|///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |///////|///////|///////|       |       | */
  /*  2|/(2,0)/|/(2,1)/|/(2,2)/| (2,3) | (2,4) | */
  /*   |///////|///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  vipldws_B.o[0U] = 0;
  vipldws_B.o[1U] = 1;
  vipldws_B.o[2U] = 2;
  vipldws_B.o[3U] = 3;
  vipldws_B.o[4U] = 4;
  isEnd = false;
  vipldws_B.c[1U] = 0;

  /* if hDims < uDims then the all INSIDE sector will not be pushed into the boundary sectors... hence the counter needs to skip the all INSIDEs sector and start from one sector down. */
  vipldws_B.c[0U] = 1;
  while (!isEnd) {
    uOrigin = 0;
    yPost = 0;

    /* compute on-boundary sector */
    /* compute sector if not empty */
    if (!((vipldws_B.mWidth[vipldws_B.o[vipldws_B.c[0U]] << 1] <= 0) ||
          (vipldws_B.mWidth[(vipldws_B.o[vipldws_B.c[1U]] << 1) + 1] <= 0))) {
      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (vipldws_B.o[vipldws_B.c[0]] == 0);
      dimIsPre = ((vipldws_B.o[vipldws_B.c[0]] == 3) ||
                  (vipldws_B.o[vipldws_B.c[0]] == 1));
      if (dimIsPre || isSEmpty) {
        vipldws_B.sPreEdges[0] = 0;
        uOrigin = 1;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        vipldws_B.sPostEdges[0] = 0;
        yPost = 1;
      }

      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (vipldws_B.o[vipldws_B.c[1]] == 0);
      dimIsPre = ((vipldws_B.o[vipldws_B.c[1]] == 3) ||
                  (vipldws_B.o[vipldws_B.c[1]] == 1));
      if (dimIsPre || isSEmpty) {
        vipldws_B.sPreEdges[uOrigin] = 1;
        uOrigin++;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        vipldws_B.sPostEdges[yPost] = 1;
        yPost++;
      }

      /* setup indices for the loops */
      /* Origin stores the origin of Y with respect to U */
      /*  where the origin of Y is at its top left corner */
      /* Compute offset between origin of Y and origin of U(0,0) */
      vipldws_B.offset[0U] = -yOrigin[0U];
      vipldws_B.offset[1U] = -yOrigin[1U];

      /* sector start and end were computed relative to U */
      /* make them relative to Y by adding offset */
      vipldws_B.sStart[0U] = vipldws_B.mLoc[vipldws_B.o[vipldws_B.c[0]] << 1] +
        vipldws_B.offset[0U];
      vipldws_B.sEnd[0U] = ((vipldws_B.mLoc[vipldws_B.o[vipldws_B.c[0]] << 1] +
        vipldws_B.mWidth[vipldws_B.o[vipldws_B.c[0]] << 1]) + vipldws_B.offset
                            [0U]) - 1;
      vipldws_B.sStart[1U] = vipldws_B.mLoc[(vipldws_B.o[vipldws_B.c[1]] << 1) +
        1] + vipldws_B.offset[1U];
      vipldws_B.sEnd[1U] = ((vipldws_B.mLoc[(vipldws_B.o[vipldws_B.c[1]] << 1) +
        1] + vipldws_B.mWidth[(vipldws_B.o[vipldws_B.c[1]] << 1) + 1]) +
                            vipldws_B.offset[1U]) - 1;

      /* adjust offset for kernel center */
      vipldws_B.offset[0U] -= hLoc[0U];
      vipldws_B.offset[1U] -= hLoc[1U];

      /* loop kernel over data */
      vipldws_B.idxB[1U] = vipldws_B.sStart[1U];
      while (vipldws_B.idxB[1U] <= vipldws_B.sEnd[1U]) {
        vipldws_B.idxA[1U] = vipldws_B.idxB[1U] - vipldws_B.offset[1U];
        vipldws_B.idxBLin_c[1U] = yDims[0U] * vipldws_B.idxB[1U];
        vipldws_B.idxB[0U] = vipldws_B.sStart[0U];
        while (vipldws_B.idxB[0U] <= vipldws_B.sEnd[0U]) {
          vipldws_B.idxA[0U] = vipldws_B.idxB[0U] - vipldws_B.offset[0U];
          vipldws_B.idxBLin_c[0U] = vipldws_B.idxBLin_c[1U] + vipldws_B.idxB[0U];

          /* loop over kernel and compute conv/corr */
          hPost = 0;
          acc = 0.0F;

          /* loop over kernel */
          vipldws_B.hIdxA_k[1U] = 0;
          while (vipldws_B.hIdxA_k[1U] <= vipldws_B.hEnd[1U]) {
            vipldws_B.hIdxB[1U] = vipldws_B.idxA[1U] + vipldws_B.hIdxA_k[1U];
            vipldws_B.hIdxA_k[0U] = 0;
            while (vipldws_B.hIdxA_k[0U] <= vipldws_B.hEnd[0U]) {
              vipldws_B.hIdxB[0U] = vipldws_B.idxA[0U] + vipldws_B.hIdxA_k[0U];
              uI = PadBRepl_uS(&u[0U], &vipldws_B.uStride[0U], &vipldws_B.hIdxB
                               [0U], &vipldws_B.uOrigin[0U], &vipldws_B.uEnd[0U],
                               uOrigin, &vipldws_B.sPreEdges[0U], yPost,
                               &vipldws_B.sPostEdges[0U]);
              acc += uI * h[hPost];
              hPost++;
              vipldws_B.hIdxA_k[0U]++;
            }

            vipldws_B.hIdxA_k[1U]++;
          }

          if (vipldws_B.idxBLin_c[0U] >= 0) {
            y[vipldws_B.idxBLin_c[0U]] = acc;
          }

          vipldws_B.idxB[0U]++;
        }

        vipldws_B.idxB[1U]++;
      }
    }

    /* advance sector counter */
    uOrigin = 0;
    while (uOrigin < 2) {
      vipldws_B.c[uOrigin]++;
      if (vipldws_B.c[uOrigin] <= 2) {
        isEnd = false;
        uOrigin = 2;
      } else {
        vipldws_B.c[uOrigin] = 0;
        isEnd = true;
      }

      uOrigin++;
    }
  }

  /* End of S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
}

int8_T rt_sqrt_Us8_Ys4_Is8_f_pw(int8_T u)
{
  int8_T y;
  int8_T tmp01_y;

  /* Fixed-Point Sqrt Computation by the bisection method. */
  if (u > 0) {
    y = 0;
    if (16 <= u) {
      y = 4;
    }

    tmp01_y = (int8_T)(y | 2);
    if (tmp01_y * tmp01_y <= u) {
      y = tmp01_y;
    }

    tmp01_y = (int8_T)(y | 1);
    if (tmp01_y * tmp01_y <= u) {
      y = tmp01_y;
    }
  } else {
    y = 0;
  }

  return y;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

void LDLf_int32_Treal32_T(real32_T out[], real32_T vArray[], int32_T nRows,
  const real32_T in[])
{
  int32_T c;
  int32_T r;
  int32_T idx1;
  int32_T idx2;
  real32_T mYTmp;
  real32_T mYTmpR;
  boolean_T done;
  int32_T k;

  /* S-Function (sdspldl2): '<S46>/LDL Factorization' */
  done = false;

  /* use done to control the for loop return early  */
  /* when non-positive definite eigenvalue is detected */
  c = 0;
  while ((c < nRows) && (!done)) {
    idx2 = c * nRows;
    for (r = 0; r < c; r++) {
      idx1 = r * nRows;
      vArray[r] = out[idx1 + c] * out[idx1 + r];
    }

    mYTmp = in[idx2 + c];
    idx1 = c;
    for (r = 0; r < c; r++) {
      mYTmp -= out[idx1] * vArray[r];
      idx1 += nRows;
    }

    mYTmpR = mYTmp;
    if (mYTmp <= 0.0F) {
      done = true;
    } else {
      out[idx2 + c] = mYTmp;
      for (r = c + 1; r < nRows; r++) {
        mYTmp = in[idx2 + r];
        idx1 = r;
        for (k = 0; k < c; k++) {
          mYTmp -= out[idx1] * vArray[k];
          idx1 += nRows;
        }

        out[idx2 + r] = mYTmp / mYTmpR;
      }
    }

    c++;
  }

  /* transpose and copy lower sub-triang to upper */
  c = 0;
  while ((c < nRows) && (!done)) {
    for (r = c + 1; r < nRows; r++) {
      out[r * nRows + c] = out[c * nRows + r];
    }

    c++;
  }

  /* End of S-Function (sdspldl2): '<S46>/LDL Factorization' */
}

/* Model step function */
void vipldws_step(void)
{
  boolean_T c_gotAlLeastOneYellowPixelInThe;
  boolean_T prevEdgeIsVertical;
  int8_T idxTmpArray[2];
  boolean_T countTwice;
  int8_T idxTmpArray_0[2];
  boolean_T done;
  static const int8_T tmp[4] = { 1, 0, 3, 2 };

  static const int8_T tmp_0[12] = { 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10 };

  int8_T acc4_idx_0;
  int8_T acc1_idx_1;
  int8_T acc1_idx_5;
  int8_T lineColorIdx_idx_0;
  int8_T solidBrokenIdx_idx_0;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.SampleandHold_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Enablesignalgenerator_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Core_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Options_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Differencebetweentwolines_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Selectalinefromtherepositoryifi);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Draw3rdLine_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.DrawPolygon_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws_DW.Subsystem_SubsysRanBC);

  /* S-Function (v4l2_video_capture_sfcn): '<S2>/V4L2 Video Capture' */
  MW_videoCaptureOutput(vipldws_ConstP.V4L2VideoCapture_p1,
                        &vipldws_B.MatrixConcatenate[0],
                        &vipldws_B.MatrixConcatenate[76800],
                        &vipldws_B.MatrixConcatenate[153600]);

  /* S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion' */
  for (vipldws_B.i = 0; vipldws_B.i < 230400; vipldws_B.i++) {
    vipldws_B.ImageDataTypeConversion[vipldws_B.i] = (real32_T)
      vipldws_B.MatrixConcatenate[vipldws_B.i] / 255.0F;
  }

  /* End of S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion' */

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion' */
  for (vipldws_B.i = 0; vipldws_B.i < 76800; vipldws_B.i++) {
    vipldws_B.ColorSpaceConversion[vipldws_B.i] =
      (vipldws_B.ImageDataTypeConversion[76800 + vipldws_B.i] * 0.587F +
       vipldws_B.ImageDataTypeConversion[vipldws_B.i] * 0.299F) +
      vipldws_B.ImageDataTypeConversion[153600 + vipldws_B.i] * 0.114F;
    if (vipldws_B.ColorSpaceConversion[vipldws_B.i] > 1.0F) {
      vipldws_B.ColorSpaceConversion[vipldws_B.i] = 1.0F;
    } else {
      if (vipldws_B.ColorSpaceConversion[vipldws_B.i] < 0.0F) {
        vipldws_B.ColorSpaceConversion[vipldws_B.i] = 0.0F;
      }
    }
  }

  /* End of S-Function (svipcolorconv): '<S2>/Color Space  Conversion' */

  /* S-Function (sdspsubmtrx): '<S2>/Clip image' */
  vipldws_B.yIdx = 0;
  for (vipldws_B.i = 0; vipldws_B.i < 240; vipldws_B.i++) {
    memcpy(&vipldws_B.Clipimage[vipldws_B.yIdx],
           &vipldws_B.ColorSpaceConversion[vipldws_B.i * 320 + 120], 200U *
           sizeof(real32_T));
    vipldws_B.yIdx += 200;
  }

  /* End of S-Function (sdspsubmtrx): '<S2>/Clip image' */

  /* S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
  /* Dimensions of the filter */
  vipldws_B.h1Dims[0U] = 1;
  vipldws_B.h1Dims[1U] = 3;
  vipldws_B.uDims[0U] = 200;
  vipldws_B.uDims[1U] = 240;

  /* set up kernel related coordinates */
  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  vipldws_B.hLoc[0U] = 0;

  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  vipldws_B.hLoc[1U] = -1;

  /* Region of Support (ROS) definition: A selected region that restricts the input space for processing. */
  /* ====================================================== */
  /*                       ---------------------            */
  /*                      |ROI                  |           */
  /*                      |                     |           */
  /*  ----------------------------------------------------  */
  /* | INPUT(u)           |                     |         | */
  /* |                    |                     |         | */
  /* |   ---------------------------------------------    | */
  /* |  | ROS             |OUTPUT(y)////////////|     |   | */
  /* |  |                 |/////////////////////|     |   | */
  /* |  |                  ---------------------      |   | */
  /* |  |                                             |   | */
  /* The user's output mode choices of 'Valid', 'Same as input' and 'Full' map onto correspending definitions of a rectangular ROS. */
  /* Output range support is computed as an intersection of ROS with Region of Interest (ROI) */
  /* ///////////////////// */
  /* begin ROS computation */
  /* compute ROS based on u, h and output mode */
  /* ROS is SAME AS INPUT */
  /* end ROS computation */
  /* /////////////////// */
  /* ///////////////////////// */
  /* begin y sizes computation */
  /* we need to compute yOrigin and yEnd */
  /* yOrigin definition: Location of center of reference (origin) of output (y) coordintate system with respect to input (u) coordinate system */
  /* y sizes are same as ros sizes because there is no ROI */
  vipldws_B.yOrigin[0U] = 0;
  vipldws_B.yDims[0U] = 200;

  /* y sizes are same as ros sizes because there is no ROI */
  vipldws_B.yOrigin[1U] = 0;
  vipldws_B.yDims[1U] = 240;

  /* make yOrigin same as roiLoc when y is empty */
  /* end y sizes computation */
  /* /////////////////////// */
  vipldws_Corr_M_IBRepl_uS_hS_yS(&vipldws_P.uDFIRFilter_filterMtrx[0U],
    &vipldws_B.hLoc[0U], &vipldws_B.h1Dims[0U], &vipldws_B.Clipimage[0U],
    &vipldws_B.uDims[0U], &vipldws_B.uDFIRFilter[0U], &vipldws_B.yDims[0U],
    &vipldws_B.yOrigin[0U]);

  /* Saturate: '<S3>/Saturation' */
  /* check if any input is empty
   */
  for (vipldws_B.i = 0; vipldws_B.i < 48000; vipldws_B.i++) {
    if (vipldws_B.uDFIRFilter[vipldws_B.i] > vipldws_P.Saturation_UpperSat) {
      vipldws_B.Saturation[vipldws_B.i] = vipldws_P.Saturation_UpperSat;
    } else if (vipldws_B.uDFIRFilter[vipldws_B.i] <
               vipldws_P.Saturation_LowerSat) {
      vipldws_B.Saturation[vipldws_B.i] = vipldws_P.Saturation_LowerSat;
    } else {
      vipldws_B.Saturation[vipldws_B.i] = vipldws_B.uDFIRFilter[vipldws_B.i];
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* S-Function (svipgraythresh): '<S3>/Image thresholding' */
  for (vipldws_B.i = 0; vipldws_B.i < 256; vipldws_B.i++) {
    vipldws_DW.Imagethresholding_P_DW[vipldws_B.i] = 0.0F;
    vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i] = 0.0F;
  }

  vipldws_B.scale = 255.0F;
  for (vipldws_B.i = 0; vipldws_B.i < 48000; vipldws_B.i++) {
    if (vipldws_B.Saturation[vipldws_B.i] < 0.0F) {
      vipldws_DW.Imagethresholding_P_DW[0]++;
    } else if (vipldws_B.Saturation[vipldws_B.i] > 1.0F) {
      vipldws_DW.Imagethresholding_P_DW[255]++;
    } else {
      vipldws_DW.Imagethresholding_P_DW[(uint8_T)
        (vipldws_B.Saturation[vipldws_B.i] * vipldws_B.scale + 0.5F)]++;
    }
  }

  for (vipldws_B.i = 0; vipldws_B.i < 256; vipldws_B.i++) {
    vipldws_DW.Imagethresholding_P_DW[vipldws_B.i] /= 48000.0F;
  }

  vipldws_DW.Imagethresholding_MU_DW[0] = vipldws_DW.Imagethresholding_P_DW[0];
  vipldws_B.cnt = 2.0F;
  for (vipldws_B.i = 0; vipldws_B.i < 255; vipldws_B.i++) {
    vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i + 1] =
      vipldws_DW.Imagethresholding_P_DW[vipldws_B.i + 1] * vipldws_B.cnt +
      vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i];
    vipldws_B.cnt++;
    vipldws_DW.Imagethresholding_P_DW[vipldws_B.i + 1] +=
      vipldws_DW.Imagethresholding_P_DW[vipldws_B.i];
  }

  vipldws_B.cnt = vipldws_DW.Imagethresholding_MU_DW[255];
  for (vipldws_B.i = 0; vipldws_B.i < 256; vipldws_B.i++) {
    vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i] =
      vipldws_DW.Imagethresholding_P_DW[vipldws_B.i] * vipldws_B.cnt -
      vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i];
    vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i] *=
      vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i];
    vipldws_DW.Imagethresholding_P_DW[vipldws_B.i] *= 1.0F -
      vipldws_DW.Imagethresholding_P_DW[vipldws_B.i];
    vipldws_DW.Imagethresholding_P_DW[vipldws_B.i] =
      vipldws_DW.Imagethresholding_MU_DW[vipldws_B.i] /
      vipldws_DW.Imagethresholding_P_DW[vipldws_B.i];
  }

  vipldws_B.yIdx = 0;
  vipldws_B.cnt = 0.0F;
  for (vipldws_B.i = 0; vipldws_B.i < 256; vipldws_B.i++) {
    if (vipldws_DW.Imagethresholding_P_DW[vipldws_B.i] > vipldws_B.cnt) {
      vipldws_B.cnt = vipldws_DW.Imagethresholding_P_DW[vipldws_B.i];
      vipldws_B.yIdx = vipldws_B.i;
    }
  }

  vipldws_B.scale = (real32_T)vipldws_B.yIdx / vipldws_B.scale;
  for (vipldws_B.i = 0; vipldws_B.i < 48000; vipldws_B.i++) {
    vipldws_B.Imagethresholding[vipldws_B.i] = (vipldws_B.Saturation[vipldws_B.i]
      > vipldws_B.scale);
  }

  /* End of S-Function (svipgraythresh): '<S3>/Image thresholding' */

  /* S-Function (sviphough): '<S3>/Hough Transform' */
  MWVIP_Hough_R(&vipldws_B.Imagethresholding[0], &vipldws_B.HoughTransform_o1[0],
                &vipldws_ConstP.HoughTransform_SINE_TABLE_RTP[0],
                &vipldws_ConstP.HoughTransform_FIRSTRHO_RTP, 200, 240, 625, 91);

  /* Selector: '<S30>/select rho5' */
  for (vipldws_B.i = 0; vipldws_B.i < 21; vipldws_B.i++) {
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 11; vipldws_B.countPeak
         ++) {
      vipldws_B.selectrho5[vipldws_B.countPeak + 11 * vipldws_B.i] =
        vipldws_B.HoughTransform_o1[(625 * vipldws_B.i + vipldws_B.countPeak) +
        414];
    }
  }

  /* End of Selector: '<S30>/select rho5' */

  /* S-Function (svipfindlocalmax): '<S30>/Find Local Maxima1' */
  vipldws_B.countPeak = 0;
  done = false;
  vipldws_B.i = 0;
  while (vipldws_B.i < 231) {
    vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.i] =
      vipldws_B.selectrho5[vipldws_B.i];
    vipldws_B.i++;
  }

  vipldws_B.FindLocalMaxima1_o1[0] = 0U;
  vipldws_B.FindLocalMaxima1_o1[1] = 0U;
  while (!done) {
    vipldws_B.C1 = 0;
    vipldws_B.scale = vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[0];
    vipldws_B.i = 0;
    while (vipldws_B.i < 231) {
      if (vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.i] >
          vipldws_B.scale) {
        vipldws_B.C1 = vipldws_B.i;
        vipldws_B.scale = vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.i];
      }

      vipldws_B.i++;
    }

    vipldws_B.R2 = vipldws_B.C1 % 11;
    vipldws_B.i = vipldws_B.C1 / 11;
    if (vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.C1] >=
        vipldws_P.FindLocalMaxima1_threshold) {
      vipldws_B.FindLocalMaxima1_o1[vipldws_B.countPeak] = (uint16_T)(1 +
        vipldws_B.i);
      vipldws_B.FindLocalMaxima1_o1[1U + vipldws_B.countPeak] = (uint16_T)(1 +
        vipldws_B.R2);
      vipldws_B.countPeak++;
      if (vipldws_B.countPeak == 1) {
        done = true;
      }

      vipldws_B.C1 = vipldws_B.R2 - 3;
      if (!(vipldws_B.C1 > 0)) {
        vipldws_B.C1 = 0;
      }

      vipldws_B.R2 += 3;
      if (!(vipldws_B.R2 < 10)) {
        vipldws_B.R2 = 10;
      }

      vipldws_B.C2 = vipldws_B.i - 3;
      vipldws_B.c2 = vipldws_B.i + 3;
      if (!((vipldws_B.C2 < 0) || (vipldws_B.c2 > 20))) {
        while (vipldws_B.C2 <= vipldws_B.c2) {
          vipldws_B.c1 = vipldws_B.C2 * 11;
          vipldws_B.i = vipldws_B.C1;
          while (vipldws_B.i <= vipldws_B.R2) {
            vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.i +
              vipldws_B.c1] = 0.0F;
            vipldws_B.i++;
          }

          vipldws_B.C2++;
        }
      } else {
        if (vipldws_B.C2 < 0) {
          vipldws_B.ii = vipldws_B.C2;
          while (vipldws_B.ii <= vipldws_B.c2) {
            if (vipldws_B.ii < 0) {
              vipldws_B.c1 = (vipldws_B.ii + 21) * 11 + 10;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.c1 -
                  vipldws_B.i] = 0.0F;
                vipldws_B.i++;
              }
            } else {
              vipldws_B.c1 = vipldws_B.ii * 11;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.i +
                  vipldws_B.c1] = 0.0F;
                vipldws_B.i++;
              }
            }

            vipldws_B.ii++;
          }
        }

        if (vipldws_B.c2 > 20) {
          vipldws_B.ii = vipldws_B.C2;
          while (vipldws_B.ii <= vipldws_B.c2) {
            if (vipldws_B.ii > 20) {
              vipldws_B.c1 = (vipldws_B.ii - 21) * 11 + 10;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.c1 -
                  vipldws_B.i] = 0.0F;
                vipldws_B.i++;
              }
            } else {
              vipldws_B.c1 = vipldws_B.ii * 11;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws_B.i +
                  vipldws_B.c1] = 0.0F;
                vipldws_B.i++;
              }
            }

            vipldws_B.ii++;
          }
        }
      }
    } else {
      done = true;
    }
  }

  vipldws_B.FindLocalMaxima1_o2 = (uint16_T)vipldws_B.countPeak;

  /* End of S-Function (svipfindlocalmax): '<S30>/Find Local Maxima1' */

  /* UnitDelay: '<S36>/FixPt Unit Delay2' */
  vipldws_B.FixPtLogicalOperator = vipldws_DW.FixPtUnitDelay2_DSTATE;

  /* Logic: '<S36>/FixPt Logical Operator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  vipldws_B.FixPtUnitDelay2 = (uint8_T)(vipldws_P.Constant_Value_n ||
    (vipldws_B.FixPtLogicalOperator != 0));
  for (vipldws_B.i = 0; vipldws_B.i < 40; vipldws_B.i++) {
    /* UnitDelay: '<S36>/FixPt Unit Delay1' */
    vipldws_B.Xold[vipldws_B.i] = vipldws_DW.FixPtUnitDelay1_DSTATE[vipldws_B.i];

    /* Switch: '<S36>/Init' incorporates:
     *  Constant: '<S36>/Initial Condition'
     */
    if (vipldws_B.FixPtUnitDelay2 != 0) {
      vipldws_B.Init[vipldws_B.i] =
        vipldws_P.UnitDelayResettable1_vinit[vipldws_B.i];
    } else {
      vipldws_B.Init[vipldws_B.i] = vipldws_B.Xold[vipldws_B.i];
    }

    /* End of Switch: '<S36>/Init' */
  }

  /* UnitDelay: '<S35>/FixPt Unit Delay2' */
  vipldws_B.FixPtUnitDelay2 = vipldws_DW.FixPtUnitDelay2_DSTATE_b;

  /* Logic: '<S35>/FixPt Logical Operator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  vipldws_B.FixPtLogicalOperator = (uint8_T)(vipldws_P.Constant_Value_n ||
    (vipldws_B.FixPtUnitDelay2 != 0));
  for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
    /* UnitDelay: '<S35>/FixPt Unit Delay1' */
    vipldws_B.Xold_g[vipldws_B.i] =
      vipldws_DW.FixPtUnitDelay1_DSTATE_d[vipldws_B.i];

    /* Switch: '<S35>/Init' incorporates:
     *  Constant: '<S35>/Initial Condition'
     */
    if (vipldws_B.FixPtLogicalOperator != 0) {
      vipldws_B.Init_p[vipldws_B.i] = vipldws_P.UnitDelayResettable_vinit;
    } else {
      vipldws_B.Init_p[vipldws_B.i] = vipldws_B.Xold_g[vipldws_B.i];
    }

    /* End of Switch: '<S35>/Init' */
  }

  /* S-Function (sdspoverwrite): '<S27>/Overwrite Values' */
  memcpy(&vipldws_B.OverwriteValues[0], &vipldws_B.HoughTransform_o1[0], 112500U
         * sizeof(real32_T));
  for (vipldws_B.i = 0; vipldws_B.i < 12; vipldws_B.i++) {
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 625; vipldws_B.countPeak
         ++) {
      vipldws_B.OverwriteValues[vipldws_B.countPeak + vipldws_B.i * 625] = 0.0F;
    }
  }

  /* End of S-Function (sdspoverwrite): '<S27>/Overwrite Values' */

  /* S-Function (sdspoverwrite): '<S27>/Overwrite Values1' */
  memcpy(&vipldws_B.OverwriteValues1[0], &vipldws_B.OverwriteValues[0], 112500U *
         sizeof(real32_T));
  for (vipldws_B.i = 0; vipldws_B.i < 13; vipldws_B.i++) {
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 625; vipldws_B.countPeak
         ++) {
      vipldws_B.OverwriteValues1[vipldws_B.countPeak + (vipldws_B.i + 167) * 625]
        = 0.0F;
    }
  }

  /* End of S-Function (sdspoverwrite): '<S27>/Overwrite Values1' */

  /* S-Function (svipfindlocalmax): '<S28>/Find Local Maxima' */
  vipldws_B.countPeak = 0;
  done = false;
  vipldws_B.i = 0;
  while (vipldws_B.i < 112500) {
    vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.i] =
      vipldws_B.OverwriteValues1[vipldws_B.i];
    vipldws_B.i++;
  }

  vipldws_B.FindLocalMaxima[0] = 0U;
  vipldws_B.FindLocalMaxima[1] = 0U;
  vipldws_B.FindLocalMaxima[2] = 0U;
  vipldws_B.FindLocalMaxima[3] = 0U;
  while (!done) {
    vipldws_B.C1 = 0;
    vipldws_B.scale = vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[0];
    vipldws_B.i = 0;
    while (vipldws_B.i < 112500) {
      if (vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.i] >
          vipldws_B.scale) {
        vipldws_B.C1 = vipldws_B.i;
        vipldws_B.scale = vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.i];
      }

      vipldws_B.i++;
    }

    vipldws_B.R2 = vipldws_B.C1 % 625;
    vipldws_B.i = vipldws_B.C1 / 625;
    if (vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.C1] >=
        vipldws_P.FindLocalMaxima_threshold) {
      vipldws_B.FindLocalMaxima[vipldws_B.countPeak] = (uint16_T)(1 +
        vipldws_B.i);
      vipldws_B.FindLocalMaxima[2U + vipldws_B.countPeak] = (uint16_T)(1 +
        vipldws_B.R2);
      vipldws_B.countPeak++;
      if (vipldws_B.countPeak == 2) {
        done = true;
      }

      vipldws_B.C1 = vipldws_B.R2 - 150;
      if (!(vipldws_B.C1 > 0)) {
        vipldws_B.C1 = 0;
      }

      vipldws_B.R2 += 150;
      if (!(vipldws_B.R2 < 624)) {
        vipldws_B.R2 = 624;
      }

      vipldws_B.C2 = vipldws_B.i - 40;
      vipldws_B.c2 = vipldws_B.i + 40;
      if (!((vipldws_B.C2 < 0) || (vipldws_B.c2 > 179))) {
        while (vipldws_B.C2 <= vipldws_B.c2) {
          vipldws_B.c1 = vipldws_B.C2 * 625;
          vipldws_B.i = vipldws_B.C1;
          while (vipldws_B.i <= vipldws_B.R2) {
            vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.i + vipldws_B.c1]
              = 0.0F;
            vipldws_B.i++;
          }

          vipldws_B.C2++;
        }
      } else {
        if (vipldws_B.C2 < 0) {
          vipldws_B.ii = vipldws_B.C2;
          while (vipldws_B.ii <= vipldws_B.c2) {
            if (vipldws_B.ii < 0) {
              vipldws_B.c1 = (vipldws_B.ii + 180) * 625 + 624;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.c1 -
                  vipldws_B.i] = 0.0F;
                vipldws_B.i++;
              }
            } else {
              vipldws_B.c1 = vipldws_B.ii * 625;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.i +
                  vipldws_B.c1] = 0.0F;
                vipldws_B.i++;
              }
            }

            vipldws_B.ii++;
          }
        }

        if (vipldws_B.c2 > 179) {
          vipldws_B.ii = vipldws_B.C2;
          while (vipldws_B.ii <= vipldws_B.c2) {
            if (vipldws_B.ii > 179) {
              vipldws_B.c1 = (vipldws_B.ii - 180) * 625 + 624;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.c1 -
                  vipldws_B.i] = 0.0F;
                vipldws_B.i++;
              }
            } else {
              vipldws_B.c1 = vipldws_B.ii * 625;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws_B.i +
                  vipldws_B.c1] = 0.0F;
                vipldws_B.i++;
              }
            }

            vipldws_B.ii++;
          }
        }
      }
    } else {
      done = true;
    }
  }

  vipldws_DW.FindLocalMaxima_NUMPEAKS_DWORK = (uint32_T)vipldws_B.countPeak;
  vipldws_B.fromIdx = 2U;
  vipldws_B.toIdx = (uint32_T)vipldws_B.countPeak;
  vipldws_B.i = 0;
  while (vipldws_B.i < vipldws_B.countPeak) {
    vipldws_B.FindLocalMaxima[vipldws_B.toIdx] =
      vipldws_B.FindLocalMaxima[vipldws_B.fromIdx];
    vipldws_B.fromIdx++;
    vipldws_B.toIdx++;
    vipldws_B.i++;
  }

  vipldws_DW.FindLocalMaxima_DIMS1[0] = (int32_T)
    vipldws_DW.FindLocalMaxima_NUMPEAKS_DWORK;
  vipldws_DW.FindLocalMaxima_DIMS1[1] = 2;

  /* End of S-Function (svipfindlocalmax): '<S28>/Find Local Maxima' */

  /* Selector: '<S28>/Selector1' */
  vipldws_DW.Selector1_DIMS1[0] = vipldws_DW.FindLocalMaxima_DIMS1[0];
  vipldws_DW.Selector1_DIMS1[1] = 2;
  vipldws_B.c1 = vipldws_DW.FindLocalMaxima_DIMS1[0];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.Selector1_m[vipldws_B.i] = vipldws_B.FindLocalMaxima[vipldws_B.i +
      vipldws_DW.FindLocalMaxima_DIMS1[0]];
  }

  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.Selector1_m[vipldws_B.i + vipldws_DW.Selector1_DIMS1[0]] =
      vipldws_B.FindLocalMaxima[vipldws_B.i];
  }

  /* End of Selector: '<S28>/Selector1' */

  /* Math: '<S28>/Transpose' */
  vipldws_DW.Transpose_DIMS1[0] = vipldws_DW.Selector1_DIMS1[1];
  vipldws_DW.Transpose_DIMS1[1] = vipldws_DW.Selector1_DIMS1[0];
  vipldws_B.c1 = vipldws_DW.Selector1_DIMS1[0];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.C1 = vipldws_DW.Selector1_DIMS1[1];
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < vipldws_B.C1;
         vipldws_B.countPeak++) {
      vipldws_B.Transpose_m[vipldws_B.countPeak + vipldws_DW.Transpose_DIMS1[0] *
        vipldws_B.i] = vipldws_B.Selector1_m[vipldws_DW.Selector1_DIMS1[0] *
        vipldws_B.countPeak + vipldws_B.i];
    }
  }

  /* End of Math: '<S28>/Transpose' */

  /* Selector: '<S28>/select rho' */
  vipldws_DW.selectrho_DIMS1[0] = 1;
  vipldws_DW.selectrho_DIMS1[1] = vipldws_DW.Transpose_DIMS1[1];
  vipldws_B.c1 = vipldws_DW.Transpose_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.selectrho3[vipldws_DW.selectrho_DIMS1[0] * vipldws_B.i] =
      vipldws_B.Transpose_m[vipldws_DW.Transpose_DIMS1[0] * vipldws_B.i];
  }

  /* End of Selector: '<S28>/select rho' */

  /* Selector: '<S28>/Selector rho' */
  vipldws_DW.Selectorrho_DIMS1[0] = 1;
  vipldws_DW.Selectorrho_DIMS1[1] = vipldws_DW.selectrho_DIMS1[0] *
    vipldws_DW.selectrho_DIMS1[1];
  vipldws_B.c1 = vipldws_DW.selectrho_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.C1 = vipldws_DW.selectrho_DIMS1[0];
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < vipldws_B.C1;
         vipldws_B.countPeak++) {
      vipldws_B.h1Dims[vipldws_B.countPeak + vipldws_DW.selectrho_DIMS1[0] *
        vipldws_B.i] = vipldws_B.selectrho3[vipldws_DW.selectrho_DIMS1[0] *
        vipldws_B.i + vipldws_B.countPeak] - 1;
    }
  }

  vipldws_B.c1 = vipldws_DW.selectrho_DIMS1[0] * vipldws_DW.selectrho_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.Selectorrho[vipldws_DW.Selectorrho_DIMS1[0] * vipldws_B.i] =
      vipldws_B.HoughTransform_o3[vipldws_B.h1Dims[vipldws_B.i]];
  }

  /* End of Selector: '<S28>/Selector rho' */

  /* Selector: '<S28>/select rho3' */
  vipldws_DW.selectrho3_DIMS1[0] = 1;
  vipldws_DW.selectrho3_DIMS1[1] = vipldws_DW.Transpose_DIMS1[1];
  vipldws_B.c1 = vipldws_DW.Transpose_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.selectrho3[vipldws_DW.selectrho3_DIMS1[0] * vipldws_B.i] =
      vipldws_B.Transpose_m[vipldws_DW.Transpose_DIMS1[0] * vipldws_B.i + 1];
  }

  /* End of Selector: '<S28>/select rho3' */

  /* Selector: '<S28>/Selector theta' */
  vipldws_DW.Selectortheta_DIMS1[0] = 1;
  vipldws_DW.Selectortheta_DIMS1[1] = vipldws_DW.selectrho3_DIMS1[0] *
    vipldws_DW.selectrho3_DIMS1[1];
  vipldws_B.c1 = vipldws_DW.selectrho3_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.C1 = vipldws_DW.selectrho3_DIMS1[0];
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < vipldws_B.C1;
         vipldws_B.countPeak++) {
      vipldws_B.h1Dims[vipldws_B.countPeak + vipldws_DW.selectrho3_DIMS1[0] *
        vipldws_B.i] = vipldws_B.selectrho3[vipldws_DW.selectrho3_DIMS1[0] *
        vipldws_B.i + vipldws_B.countPeak] - 1;
    }
  }

  vipldws_B.c1 = vipldws_DW.selectrho3_DIMS1[0] * vipldws_DW.selectrho3_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.Selectortheta[vipldws_DW.Selectortheta_DIMS1[0] * vipldws_B.i] =
      vipldws_B.HoughTransform_o2[vipldws_B.h1Dims[vipldws_B.i]];
  }

  /* End of Selector: '<S28>/Selector theta' */

  /* Concatenate: '<S28>/Matrix Concatenation3' */
  vipldws_DW.MatrixConcatenation3_DIMS1[0] = vipldws_DW.Selectorrho_DIMS1[0] +
    vipldws_DW.Selectortheta_DIMS1[0];
  vipldws_DW.MatrixConcatenation3_DIMS1[1] = vipldws_DW.Selectorrho_DIMS1[1];
  vipldws_B.c1 = vipldws_DW.Selectorrho_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.C1 = vipldws_DW.Selectorrho_DIMS1[0];
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < vipldws_B.C1;
         vipldws_B.countPeak++) {
      vipldws_B.MatrixConcatenation3[vipldws_B.countPeak +
        vipldws_DW.MatrixConcatenation3_DIMS1[0] * vipldws_B.i] =
        vipldws_B.Selectorrho[vipldws_DW.Selectorrho_DIMS1[0] * vipldws_B.i +
        vipldws_B.countPeak];
    }
  }

  vipldws_B.c1 = vipldws_DW.Selectortheta_DIMS1[1];
  for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
    vipldws_B.C1 = vipldws_DW.Selectortheta_DIMS1[0];
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < vipldws_B.C1;
         vipldws_B.countPeak++) {
      vipldws_B.MatrixConcatenation3[(vipldws_B.countPeak +
        vipldws_DW.Selectorrho_DIMS1[0]) +
        vipldws_DW.MatrixConcatenation3_DIMS1[0] * vipldws_B.i] =
        vipldws_B.Selectortheta[vipldws_DW.Selectortheta_DIMS1[0] * vipldws_B.i
        + vipldws_B.countPeak];
    }
  }

  /* End of Concatenate: '<S28>/Matrix Concatenation3' */

  /* Probe: '<S28>/Probe' */
  vipldws_B.Probe[0] = vipldws_DW.Transpose_DIMS1[0];
  vipldws_B.Probe[1] = vipldws_DW.Transpose_DIMS1[1];

  /* Selector: '<S28>/Selector' */
  vipldws_B.Selector = vipldws_B.Probe[1];

  /* Outputs for Iterator SubSystem: '<S28>/Enable signal generator' incorporates:
   *  ForIterator: '<S31>/For Iterator'
   */
  vipldws_B.yIdx = 1;
  do {
    exitg1 = 0;
    if (vipldws_B.Selector < 0.0) {
      vipldws_B.d0 = ceil(vipldws_B.Selector);
    } else {
      vipldws_B.d0 = floor(vipldws_B.Selector);
    }

    if (rtIsNaN(vipldws_B.d0) || rtIsInf(vipldws_B.d0)) {
      vipldws_B.d0 = 0.0;
    } else {
      vipldws_B.d0 = fmod(vipldws_B.d0, 4.294967296E+9);
    }

    if (vipldws_B.yIdx <= (vipldws_B.d0 < 0.0 ? -(int32_T)(uint32_T)
                           -vipldws_B.d0 : (int32_T)(uint32_T)vipldws_B.d0)) {
      vipldws_B.ForIterator_e = vipldws_B.yIdx;
      if (vipldws_B.yIdx == 1) {
        vipldws_B.Assignment_d[0] = vipldws_P.Constant_Value_b[0];
        vipldws_B.Assignment_d[1] = vipldws_P.Constant_Value_b[1];
      }

      vipldws_B.Assignment_d[vipldws_B.ForIterator_e - 1] =
        vipldws_P.Constant1_Value_d;
      srUpdateBC(vipldws_DW.Enablesignalgenerator_SubsysRan);
      vipldws_B.yIdx++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Outputs for SubSystem: '<S28>/Enable signal generator' */

  /* Outputs for Iterator SubSystem: '<S33>/Calculate the distances between  the lines found in the current  frame and those in the repository' incorporates:
   *  ForIterator: '<S50>/For Iterator'
   */
  vipldws_DW.ForIterator_IterationMarker = 1U;
  vipldws_B.yIdx = 1;
  while (vipldws_B.yIdx <= vipldws_P.ForIterator_IterationLimit_j) {
    vipldws_B.ForIterator_j = vipldws_B.yIdx;

    /* Selector: '<S50>/Selector1' */
    vipldws_B.Selector1_n = vipldws_B.Init_p[vipldws_B.ForIterator_j - 1];

    /* Outputs for Enabled SubSystem: '<S50>/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines.' incorporates:
     *  EnablePort: '<S53>/EnablePort'
     */
    if (vipldws_B.Selector1_n > 0) {
      /* Selector: '<S53>/Selector2' */
      vipldws_B.Selector2_f[0] = vipldws_B.Init[(vipldws_B.ForIterator_j - 1) <<
        1];
      vipldws_B.Selector2_f[1] = vipldws_B.Init[((vipldws_B.ForIterator_j - 1) <<
        1) + 1];

      /* Outputs for Iterator SubSystem: '<S53>/Calculate the distances between  the chosen line in the repository  and all input lines.' incorporates:
       *  ForIterator: '<S54>/For Iterator'
       */
      /* Selector: '<S53>/Selector1' incorporates:
       *  Constant: '<S53>/Constant2'
       */
      for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
        vipldws_B.Selector1_i[vipldws_B.i] = vipldws_P.Constant2_Value_o[(20 *
          vipldws_B.i + vipldws_B.ForIterator_j) - 1];
        vipldws_B.Assignment_j[vipldws_B.i] = vipldws_B.Selector1_i[vipldws_B.i];
      }

      /* End of Selector: '<S53>/Selector1' */
      vipldws_DW.ForIterator_IterationMarker_c = 1U;
      vipldws_B.countPeak = 1;
      while (vipldws_B.countPeak <= vipldws_P.ForIterator_IterationLimit_g) {
        vipldws_B.ForIterator_f = vipldws_B.countPeak;

        /* Selector: '<S54>/Selector1' */
        vipldws_DW.Selector1_DIMS1_l[0] = vipldws_DW.MatrixConcatenation3_DIMS1
          [0];
        vipldws_DW.Selector1_DIMS1_l[1] = 1;
        vipldws_B.c1 = vipldws_DW.MatrixConcatenation3_DIMS1[0];
        for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
          vipldws_B.tmp_data[vipldws_B.i] = vipldws_B.MatrixConcatenation3
            [(vipldws_B.ForIterator_f - 1) *
            vipldws_DW.MatrixConcatenation3_DIMS1[0] + vipldws_B.i];
        }

        vipldws_B.c1 = vipldws_DW.MatrixConcatenation3_DIMS1[0];
        for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
          vipldws_B.Selector1_k[vipldws_B.i] = vipldws_B.tmp_data[vipldws_B.i];
        }

        /* End of Selector: '<S54>/Selector1' */

        /* Selector: '<S54>/Selector2' */
        vipldws_B.Selector2_fh = vipldws_B.Assignment_d[vipldws_B.ForIterator_f
          - 1];

        /* Outputs for Enabled SubSystem: '<S54>/Difference between  two lines' incorporates:
         *  EnablePort: '<S55>/Enable'
         */
        /* Switch: '<S54>/Switch1' incorporates:
         *  Constant: '<S54>/Constant'
         */
        if (vipldws_B.Selector2_fh) {
          /* Selector: '<S55>/Theta_2' incorporates:
           *  Constant: '<S55>/Constant1'
           */
          vipldws_B.Gain = vipldws_B.Selector1_k[(int32_T)
            vipldws_P.Constant1_Value - 1];

          /* Sum: '<S55>/Add8' */
          vipldws_B.Gain = vipldws_B.Selector2_f[1] - vipldws_B.Gain;

          /* Abs: '<S55>/Abs' */
          vipldws_B.Gain = (real32_T)fabs(vipldws_B.Gain);

          /* Selector: '<S55>/Rho_2' incorporates:
           *  Constant: '<S55>/Constant'
           */
          vipldws_B.Rho_2 = vipldws_B.Selector1_k[(int32_T)
            vipldws_P.Constant_Value - 1];

          /* Sum: '<S55>/Add1' */
          vipldws_B.cnt = (real32_T)floor(vipldws_B.Selector2_f[0] -
            vipldws_B.Rho_2);
          if (rtIsNaNF(vipldws_B.cnt) || rtIsInfF(vipldws_B.cnt)) {
            vipldws_B.cnt = 0.0F;
          } else {
            vipldws_B.cnt = (real32_T)fmod(vipldws_B.cnt, 4.2949673E+9F);
          }

          vipldws_B.Abs1 = vipldws_B.cnt < 0.0F ? -(int32_T)(uint32_T)
            -vipldws_B.cnt : (int32_T)(uint32_T)vipldws_B.cnt;

          /* End of Sum: '<S55>/Add1' */

          /* Abs: '<S55>/Abs1' */
          if (vipldws_B.Abs1 < 0) {
            vipldws_B.Abs1 = -vipldws_B.Abs1;
          }

          /* End of Abs: '<S55>/Abs1' */

          /* Gain: '<S55>/Gain' */
          vipldws_B.Gain *= vipldws_P.Gain_Gain;

          /* Sum: '<S55>/Add7' */
          vipldws_B.cnt = (real32_T)floor((real32_T)vipldws_B.Abs1 +
            vipldws_B.Gain);
          if (rtIsNaNF(vipldws_B.cnt) || rtIsInfF(vipldws_B.cnt)) {
            vipldws_B.cnt = 0.0F;
          } else {
            vipldws_B.cnt = (real32_T)fmod(vipldws_B.cnt, 4.2949673E+9F);
          }

          vipldws_B.Add7 = vipldws_B.cnt < 0.0F ? -(int32_T)(uint32_T)
            -vipldws_B.cnt : (int32_T)(uint32_T)vipldws_B.cnt;

          /* End of Sum: '<S55>/Add7' */
          vipldws_DW.Differencebetweentwolines_Subsy = 4;
          vipldws_B.Switch1_l = vipldws_B.Add7;
        } else {
          vipldws_B.Switch1_l = vipldws_P.Constant_Value_l;
        }

        /* End of Switch: '<S54>/Switch1' */
        /* End of Outputs for SubSystem: '<S54>/Difference between  two lines' */

        /* Assignment: '<S54>/Assignment' */
        vipldws_B.Assignment_j[vipldws_B.ForIterator_f - 1] =
          vipldws_B.Switch1_l;
        vipldws_B.countPeak++;
      }

      /* End of Outputs for SubSystem: '<S53>/Calculate the distances between  the chosen line in the repository  and all input lines.' */

      /* Assignment: '<S53>/Assignment' incorporates:
       *  Constant: '<S53>/Constant2'
       */
      if (vipldws_DW.ForIterator_IterationMarker < 2) {
        vipldws_DW.ForIterator_IterationMarker = 2U;
        memcpy(&vipldws_B.Assignment_p2[0], &vipldws_P.Constant2_Value_o[0],
               400U * sizeof(int32_T));
      }

      for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
        vipldws_B.Assignment_p2[(vipldws_B.ForIterator_j + 20 * vipldws_B.i) - 1]
          = vipldws_B.Assignment_j[vipldws_B.i];
      }

      /* End of Assignment: '<S53>/Assignment' */
      vipldws_DW.Selectalinefromtherepositoryifi = 4;
    }

    /* End of Outputs for SubSystem: '<S50>/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines.' */
    vipldws_B.yIdx++;
  }

  /* End of Outputs for SubSystem: '<S33>/Calculate the distances between  the lines found in the current  frame and those in the repository' */

  /* Outputs for Iterator SubSystem: '<S33>/Find the best  matches between the current  lines and those in the repository' incorporates:
   *  ForIterator: '<S51>/For Iterator'
   */
  memcpy(&vipldws_B.Assignment1_m[0], &vipldws_B.Assignment_p2[0], 400U * sizeof
         (int32_T));
  memcpy(&vipldws_B.Assignment2[0], &vipldws_B.Assignment_p2[0], 400U * sizeof
         (int32_T));
  vipldws_B.yIdx = 1;
  while (vipldws_B.yIdx <= vipldws_P.ForIterator_IterationLimit_n) {
    vipldws_B.ForIterator_l = vipldws_B.yIdx;

    /* RelationalOperator: '<S56>/Compare' incorporates:
     *  Constant: '<S56>/Constant'
     */
    vipldws_B.Compare_mb = (vipldws_B.ForIterator_l <=
      vipldws_P.CompareToConstant_const);
    for (vipldws_B.i = 0; vipldws_B.i < 400; vipldws_B.i++) {
      /* Delay: '<S51>/Delay1' */
      vipldws_B.Switch1_bi[vipldws_B.i] = vipldws_DW.Delay1_DSTATE[vipldws_B.i];

      /* Switch: '<S51>/Switch1' */
      if (vipldws_B.Compare_mb) {
        vipldws_B.Switch1_bi[vipldws_B.i] = vipldws_B.Assignment_p2[vipldws_B.i];
      }

      /* End of Switch: '<S51>/Switch1' */
    }

    /* S-Function (sdspstatminmax): '<S51>/Minimum' */
    vipldws_B.Minimum_o1 = vipldws_B.Switch1_bi[0];
    vipldws_B.countPeak = 0;
    for (vipldws_B.i = 0; vipldws_B.i < 399; vipldws_B.i++) {
      if (vipldws_B.Switch1_bi[vipldws_B.i + 1] < vipldws_B.Minimum_o1) {
        vipldws_B.Minimum_o1 = vipldws_B.Switch1_bi[vipldws_B.i + 1];
        vipldws_B.countPeak = vipldws_B.i + 1;
      }
    }

    vipldws_B.Minimum_o2[1] = (uint32_T)(div_s32_floor(vipldws_B.countPeak,
      vipldws_P.Minimum_prodDims[0]) + 1);
    vipldws_B.countPeak = vipldws_B.countPeak % vipldws_P.Minimum_prodDims[0] +
      1;
    vipldws_B.Minimum_o2[0U] = (uint32_T)vipldws_B.countPeak;

    /* End of S-Function (sdspstatminmax): '<S51>/Minimum' */

    /* Assignment: '<S51>/Assignment1' */
    vipldws_B.i = (int32_T)vipldws_B.Minimum_o2[0];

    /* Assignment: '<S51>/Assignment2' */
    vipldws_B.countPeak = (int32_T)vipldws_B.Minimum_o2[1];
    for (vipldws_B.R2 = 0; vipldws_B.R2 < 20; vipldws_B.R2++) {
      /* Assignment: '<S51>/Assignment1' incorporates:
       *  Constant: '<S51>/Constant'
       */
      vipldws_B.Assignment1_m[(vipldws_B.i + 20 * vipldws_B.R2) - 1] =
        vipldws_P.Constant_Value_iw;

      /* Assignment: '<S51>/Assignment2' incorporates:
       *  Constant: '<S51>/Constant'
       */
      vipldws_B.Assignment2[vipldws_B.R2 + 20 * (vipldws_B.countPeak - 1)] =
        vipldws_P.Constant_Value_iw;
    }

    /* Sum: '<S51>/Add' */
    for (vipldws_B.i = 0; vipldws_B.i < 400; vipldws_B.i++) {
      vipldws_B.Add_e[vipldws_B.i] = vipldws_B.Assignment1_m[vipldws_B.i] +
        vipldws_B.Assignment2[vipldws_B.i];
    }

    /* End of Sum: '<S51>/Add' */

    /* DataTypeConversion: '<S51>/Data Type  Conversion3' */
    vipldws_B.fromIdx = vipldws_B.Minimum_o2[0];
    if (vipldws_B.Minimum_o2[0] > 2147483647U) {
      vipldws_B.fromIdx = 2147483647U;
    }

    vipldws_B.DataTypeConversion3[0] = (int32_T)vipldws_B.fromIdx;
    vipldws_B.fromIdx = vipldws_B.Minimum_o2[1];
    if (vipldws_B.Minimum_o2[1] > 2147483647U) {
      vipldws_B.fromIdx = 2147483647U;
    }

    vipldws_B.DataTypeConversion3[1] = (int32_T)vipldws_B.fromIdx;

    /* End of DataTypeConversion: '<S51>/Data Type  Conversion3' */

    /* Assignment: '<S51>/Assignment' incorporates:
     *  Assignment: '<S51>/Assignment3'
     *  Constant: '<S51>/Constant1'
     *  Constant: '<S51>/Constant2'
     */
    if (vipldws_B.yIdx == 1) {
      memcpy(&vipldws_B.Assignment_k[0], &vipldws_P.Constant2_Value_d[0], 40U *
             sizeof(int32_T));
      memcpy(&vipldws_B.Assignment3[0], &vipldws_P.Constant1_Value_c[0], 20U *
             sizeof(int32_T));
    }

    vipldws_B.Assignment_k[(vipldws_B.ForIterator_l - 1) << 1] =
      vipldws_B.DataTypeConversion3[0];
    vipldws_B.Assignment_k[1 + ((vipldws_B.ForIterator_l - 1) << 1)] =
      vipldws_B.DataTypeConversion3[1];

    /* End of Assignment: '<S51>/Assignment' */

    /* Assignment: '<S51>/Assignment3' */
    vipldws_B.Assignment3[vipldws_B.ForIterator_l - 1] = vipldws_B.Minimum_o1;

    /* Update for Delay: '<S51>/Delay1' */
    memcpy(&vipldws_DW.Delay1_DSTATE[0], &vipldws_B.Add_e[0], 400U * sizeof
           (int32_T));
    vipldws_B.yIdx++;
  }

  /* End of Outputs for SubSystem: '<S33>/Find the best  matches between the current  lines and those in the repository' */

  /* Outputs for Iterator SubSystem: '<S33>/Update the repository' incorporates:
   *  ForIterator: '<S52>/For Iterator'
   */
  memcpy(&vipldws_B.Assignment_i[0], &vipldws_B.Init[0], 40U * sizeof(real32_T));

  /* InitializeConditions for Delay: '<S52>/Delay1' */
  for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
    vipldws_DW.Delay1_DSTATE_g[vipldws_B.i] =
      vipldws_P.Delay1_InitialCondition_n;
  }

  /* End of InitializeConditions for Delay: '<S52>/Delay1' */
  vipldws_B.yIdx = 1;
  while (vipldws_B.yIdx <= vipldws_P.ForIterator_IterationLimit_a) {
    vipldws_B.ForIterator_a = vipldws_B.yIdx;

    /* RelationalOperator: '<S57>/Compare' incorporates:
     *  Constant: '<S57>/Constant'
     */
    vipldws_B.Compare_n = (vipldws_B.ForIterator_a <=
      vipldws_P.CompareToConstant_const_m);
    for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
      /* RelationalOperator: '<S59>/Compare' incorporates:
       *  Constant: '<S59>/Constant'
       */
      vipldws_B.Compare_p[vipldws_B.i] = (vipldws_B.Init_p[vipldws_B.i] >
        vipldws_P.Constant_Value_m);

      /* Delay: '<S52>/Delay1' */
      vipldws_B.Switch1_m[vipldws_B.i] = vipldws_DW.Delay1_DSTATE_g[vipldws_B.i];

      /* Switch: '<S52>/Switch1' */
      if (vipldws_B.Compare_n) {
        vipldws_B.Switch1_m[vipldws_B.i] = vipldws_B.Compare_p[vipldws_B.i];
      }

      /* End of Switch: '<S52>/Switch1' */
    }

    /* S-Function (sdspstatminmax): '<S52>/Minimum' */
    vipldws_B.c1 = 1;
    vipldws_DW.Minimum_Valdata = vipldws_B.Switch1_m[0];
    vipldws_B.Minimum = 1U;
    for (vipldws_B.ii = 0; vipldws_B.ii < 19; vipldws_B.ii++) {
      if ((int32_T)vipldws_B.Switch1_m[vipldws_B.c1] < (int32_T)
          vipldws_DW.Minimum_Valdata) {
        vipldws_DW.Minimum_Valdata = vipldws_B.Switch1_m[vipldws_B.c1];
        vipldws_B.Minimum = (uint32_T)(vipldws_B.ii + 2);
      }

      vipldws_B.c1++;
    }

    /* End of S-Function (sdspstatminmax): '<S52>/Minimum' */

    /* Selector: '<S52>/Selector3' */
    vipldws_B.Selector_n = vipldws_B.Assignment3[vipldws_B.ForIterator_a - 1];

    /* RelationalOperator: '<S58>/Compare' incorporates:
     *  Constant: '<S58>/Constant'
     */
    vipldws_B.Compare_n = (vipldws_B.Selector_n >
      vipldws_P.CompareToConstant1_const);

    /* Switch: '<S52>/Switch3' */
    if (vipldws_B.Compare_n) {
      vipldws_B.Switch3 = vipldws_B.Minimum;
    } else {
      /* Selector: '<S52>/Selector1' */
      vipldws_B.Selector1_b = vipldws_B.Assignment_k[(vipldws_B.ForIterator_a -
        1) << 1];
      vipldws_B.Switch3 = (uint32_T)vipldws_B.Selector1_b;
    }

    /* End of Switch: '<S52>/Switch3' */

    /* Assignment: '<S52>/Assignment1' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S52>/Constant2'
     */
    if (vipldws_B.yIdx == 1) {
      memcpy(&vipldws_B.Assignment1[0], &vipldws_P.Constant2_Value_b[0], 20U *
             sizeof(int32_T));
    }

    vipldws_B.Assignment1[(int32_T)vipldws_B.Switch3 - 1] =
      vipldws_P.Constant_Value_i0;

    /* End of Assignment: '<S52>/Assignment1' */
    for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
      /* Sum: '<S52>/Add1' */
      vipldws_B.Add_j[vipldws_B.i] = vipldws_B.Assignment1[vipldws_B.i] +
        vipldws_B.Assignment1[vipldws_B.i];

      /* Bias: '<S52>/Bias' */
      vipldws_B.Add_j[vipldws_B.i] += vipldws_P.Bias_Bias;

      /* Sum: '<S52>/Add' */
      vipldws_B.Add_j[vipldws_B.i] += vipldws_B.Init_p[vipldws_B.i];
    }

    /* Selector: '<S52>/Selector' */
    vipldws_B.Selector_n = vipldws_B.Assignment_k[((vipldws_B.ForIterator_a - 1)
      << 1) + 1];

    /* Selector: '<S52>/Selector2' */
    vipldws_DW.Selector2_DIMS1[0] = vipldws_DW.MatrixConcatenation3_DIMS1[0];
    vipldws_DW.Selector2_DIMS1[1] = 1;
    vipldws_B.c1 = vipldws_DW.MatrixConcatenation3_DIMS1[0];
    for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
      vipldws_B.tmp_data[vipldws_B.i] = vipldws_B.MatrixConcatenation3
        [(vipldws_B.Selector_n - 1) * vipldws_DW.MatrixConcatenation3_DIMS1[0] +
        vipldws_B.i];
    }

    vipldws_B.c1 = vipldws_DW.MatrixConcatenation3_DIMS1[0];
    for (vipldws_B.i = 0; vipldws_B.i < vipldws_B.c1; vipldws_B.i++) {
      vipldws_B.Selector2_b[vipldws_B.i] = vipldws_B.tmp_data[vipldws_B.i];
    }

    /* End of Selector: '<S52>/Selector2' */

    /* Assignment: '<S52>/Assignment' */
    vipldws_B.i = (int32_T)vipldws_B.Switch3;
    vipldws_B.c1 = vipldws_DW.Selector2_DIMS1[1];
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < vipldws_B.c1;
         vipldws_B.countPeak++) {
      vipldws_B.C1 = vipldws_DW.Selector2_DIMS1[0];
      for (vipldws_B.R2 = 0; vipldws_B.R2 < vipldws_B.C1; vipldws_B.R2++) {
        vipldws_B.Assignment_i[vipldws_B.R2 + (((vipldws_B.countPeak +
          vipldws_B.i) - 1) << 1)] =
          vipldws_B.Selector2_b[vipldws_DW.Selector2_DIMS1[0] *
          vipldws_B.countPeak + vipldws_B.R2];
      }
    }

    /* End of Assignment: '<S52>/Assignment' */

    /* Assignment: '<S52>/Assignment2' */
    if (vipldws_B.yIdx == 1) {
      for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
        vipldws_B.Assignment2_m[vipldws_B.i] = vipldws_B.Compare_p[vipldws_B.i];
      }
    }

    vipldws_B.Assignment2_m[(int32_T)vipldws_B.Minimum - 1] =
      vipldws_B.Compare_n;

    /* End of Assignment: '<S52>/Assignment2' */
    for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
      /* Saturate: '<S52>/Saturation' */
      if (vipldws_B.Add_j[vipldws_B.i] > vipldws_P.Saturation_UpperSat_m) {
        vipldws_B.Saturation_h[vipldws_B.i] = vipldws_P.Saturation_UpperSat_m;
      } else if (vipldws_B.Add_j[vipldws_B.i] < vipldws_P.Saturation_LowerSat_o)
      {
        vipldws_B.Saturation_h[vipldws_B.i] = vipldws_P.Saturation_LowerSat_o;
      } else {
        vipldws_B.Saturation_h[vipldws_B.i] = vipldws_B.Add_j[vipldws_B.i];
      }

      /* End of Saturate: '<S52>/Saturation' */

      /* Update for Delay: '<S52>/Delay1' */
      vipldws_DW.Delay1_DSTATE_g[vipldws_B.i] =
        vipldws_B.Assignment2_m[vipldws_B.i];
    }

    vipldws_B.yIdx++;
  }

  /* End of Outputs for SubSystem: '<S33>/Update the repository' */

  /* UnitDelay: '<S32>/En_Delay' */
  memcpy(&vipldws_B.En_Delay[0], &vipldws_DW.En_Delay_DSTATE[0], 20U * sizeof
         (int32_T));

  /* UnitDelay: '<S32>/Unit Delay2' */
  memcpy(&vipldws_B.UnitDelay2[0], &vipldws_DW.UnitDelay2_DSTATE[0], 80U *
         sizeof(real32_T));

  /* UnitDelay: '<S32>/Unit Delay3' */
  memcpy(&vipldws_B.UnitDelay3[0], &vipldws_DW.UnitDelay3_DSTATE[0], 320U *
         sizeof(real32_T));

  /* Outputs for Iterator SubSystem: '<S32>/Control' incorporates:
   *  ForIterator: '<S39>/Iterator'
   */
  vipldws_DW.Iterator_IterationMarker[0] = 1U;
  vipldws_DW.Iterator_IterationMarker[1] = 1U;
  vipldws_DW.Iterator_IterationMarker[2] = 1U;
  vipldws_DW.Iterator_IterationMarker[3] = 1U;
  vipldws_B.yIdx = 1;
  while (vipldws_B.yIdx <= vipldws_P.Iterator_IterationLimit) {
    vipldws_B.Iterator = vipldws_B.yIdx;

    /* Selector: '<S39>/En_Selector' */
    vipldws_B.En_Selector = vipldws_B.Saturation_h[vipldws_B.Iterator - 1];

    /* Logic: '<S39>/En_Not' */
    vipldws_B.En_Not = !(vipldws_B.En_Selector != 0);

    /* Selector: '<S39>/Rst_Selector' */
    vipldws_B.Rst_Selector = vipldws_B.En_Delay[vipldws_B.Iterator - 1];

    /* Logic: '<S39>/Rst_And' */
    vipldws_B.Rst_And = (vipldws_B.En_Not && (vipldws_B.Rst_Selector != 0));

    /* Logic: '<S39>/En_Or' */
    vipldws_B.En_Or = ((vipldws_B.En_Selector != 0) || vipldws_B.Rst_And);

    /* Outputs for Enabled SubSystem: '<S39>/Options' incorporates:
     *  EnablePort: '<S40>/EnablePort'
     */
    if (vipldws_B.En_Or) {
      /* Selector: '<S40>/Selector' */
      vipldws_B.Selector_i[0] = vipldws_B.Assignment_i[(vipldws_B.Iterator - 1) <<
        1];
      vipldws_B.Selector_i[1] = vipldws_B.Assignment_i[((vipldws_B.Iterator - 1)
        << 1) + 1];

      /* Selector: '<S40>/Selector1' */
      vipldws_B.Selector1_c[0] = vipldws_B.UnitDelay2[(vipldws_B.Iterator - 1) <<
        2];
      vipldws_B.Selector1_c[1] = vipldws_B.UnitDelay2[((vipldws_B.Iterator - 1) <<
        2) + 1];
      vipldws_B.Selector1_c[2] = vipldws_B.UnitDelay2[((vipldws_B.Iterator - 1) <<
        2) + 2];
      vipldws_B.Selector1_c[3] = vipldws_B.UnitDelay2[((vipldws_B.Iterator - 1) <<
        2) + 3];

      /* Selector: '<S40>/Selector2' */
      for (vipldws_B.i = 0; vipldws_B.i < 16; vipldws_B.i++) {
        vipldws_B.Selector2_n[vipldws_B.i] = vipldws_B.UnitDelay3
          [((vipldws_B.Iterator - 1) << 4) + vipldws_B.i];
      }

      /* End of Selector: '<S40>/Selector2' */

      /* Outputs for Enabled SubSystem: '<S40>/Core' incorporates:
       *  EnablePort: '<S41>/EnablePort'
       */
      if (vipldws_B.En_Selector > 0) {
        /* Math: '<S41>/P_prd Trans' */
        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          vipldws_B.P_prdKHP_prd[vipldws_B.i << 2] =
            vipldws_B.Selector2_n[vipldws_B.i];
          vipldws_B.P_prdKHP_prd[1 + (vipldws_B.i << 2)] =
            vipldws_B.Selector2_n[vipldws_B.i + 4];
          vipldws_B.P_prdKHP_prd[2 + (vipldws_B.i << 2)] =
            vipldws_B.Selector2_n[vipldws_B.i + 8];
          vipldws_B.P_prdKHP_prd[3 + (vipldws_B.i << 2)] =
            vipldws_B.Selector2_n[vipldws_B.i + 12];
        }

        /* End of Math: '<S41>/P_prd Trans' */
        for (vipldws_B.i = 0; vipldws_B.i < 2; vipldws_B.i++) {
          /* Product: '<S41>/H*P_prdt' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 4;
               vipldws_B.countPeak++) {
            vipldws_B.HP_prdt[vipldws_B.i + (vipldws_B.countPeak << 1)] = 0.0F;
            vipldws_B.HP_prdt[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.P_prdKHP_prd[vipldws_B.countPeak << 2] *
              vipldws_P.Hcst_Value[vipldws_B.i];
            vipldws_B.HP_prdt[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.P_prdKHP_prd[(vipldws_B.countPeak << 2) + 1] *
              vipldws_P.Hcst_Value[vipldws_B.i + 2];
            vipldws_B.HP_prdt[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.P_prdKHP_prd[(vipldws_B.countPeak << 2) + 2] *
              vipldws_P.Hcst_Value[vipldws_B.i + 4];
            vipldws_B.HP_prdt[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.P_prdKHP_prd[(vipldws_B.countPeak << 2) + 3] *
              vipldws_P.Hcst_Value[vipldws_B.i + 6];
          }

          /* End of Product: '<S41>/H*P_prdt' */

          /* Product: '<S41>/H*P_prdt*Ht' incorporates:
           *  Constant: '<S41>/Hcst_t'
           */
          for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 2;
               vipldws_B.countPeak++) {
            vipldws_B.HP_prdtHtR[vipldws_B.i + (vipldws_B.countPeak << 1)] =
              0.0F;
            vipldws_B.HP_prdtHtR[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_P.Hcst_t_Value[vipldws_B.countPeak << 2] *
              vipldws_B.HP_prdt[vipldws_B.i];
            vipldws_B.HP_prdtHtR[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_P.Hcst_t_Value[(vipldws_B.countPeak << 2) + 1] *
              vipldws_B.HP_prdt[vipldws_B.i + 2];
            vipldws_B.HP_prdtHtR[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_P.Hcst_t_Value[(vipldws_B.countPeak << 2) + 2] *
              vipldws_B.HP_prdt[vipldws_B.i + 4];
            vipldws_B.HP_prdtHtR[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_P.Hcst_t_Value[(vipldws_B.countPeak << 2) + 3] *
              vipldws_B.HP_prdt[vipldws_B.i + 6];
          }

          /* End of Product: '<S41>/H*P_prdt*Ht' */
        }

        /* Sum: '<S41>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S41>/Constant2'
         */
        vipldws_B.HP_prdtHtR[0] += vipldws_P.Constant2_Value[0];

        /* S-Function (sdspldl2): '<S46>/LDL Factorization' */
        vipldws_B.LDLFactorization[0] = vipldws_B.HP_prdtHtR[0];

        /* Sum: '<S41>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S41>/Constant2'
         */
        vipldws_B.HP_prdtHtR[1] += vipldws_P.Constant2_Value[1];

        /* S-Function (sdspldl2): '<S46>/LDL Factorization' */
        vipldws_B.LDLFactorization[1] = vipldws_B.HP_prdtHtR[1];

        /* Sum: '<S41>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S41>/Constant2'
         */
        vipldws_B.HP_prdtHtR[2] += vipldws_P.Constant2_Value[2];

        /* S-Function (sdspldl2): '<S46>/LDL Factorization' */
        vipldws_B.LDLFactorization[2] = vipldws_B.HP_prdtHtR[2];

        /* Sum: '<S41>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S41>/Constant2'
         */
        vipldws_B.HP_prdtHtR[3] += vipldws_P.Constant2_Value[3];

        /* S-Function (sdspldl2): '<S46>/LDL Factorization' */
        vipldws_B.LDLFactorization[3] = vipldws_B.HP_prdtHtR[3];
        LDLf_int32_Treal32_T(&vipldws_B.LDLFactorization[0U],
                             &vipldws_DW.LDLFactorization_VMX[0U], 2,
                             &vipldws_B.HP_prdtHtR[0U]);

        /* S-Function (sdspfbsub2): '<S46>/Forward Substitution' */
        vipldws_B.y[0] = vipldws_B.HP_prdt[0];
        vipldws_B.R2 = 1;
        vipldws_B.scale = vipldws_B.HP_prdt[1];
        vipldws_B.countPeak = 0;
        while (vipldws_B.countPeak < 1) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2] *
            vipldws_B.y[0];
          vipldws_B.R2 += 2;
          vipldws_B.countPeak = 1;
        }

        vipldws_B.y[1] = vipldws_B.scale;
        vipldws_B.y[2] = vipldws_B.HP_prdt[2];
        vipldws_B.R2 = 1;
        vipldws_B.scale = vipldws_B.HP_prdt[3];
        vipldws_B.countPeak = 0;
        while (vipldws_B.countPeak < 1) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2] *
            vipldws_B.y[2];
          vipldws_B.R2 += 2;
          vipldws_B.countPeak = 1;
        }

        vipldws_B.y[3] = vipldws_B.scale;
        vipldws_B.y[4] = vipldws_B.HP_prdt[4];
        vipldws_B.R2 = 1;
        vipldws_B.scale = vipldws_B.HP_prdt[5];
        vipldws_B.countPeak = 0;
        while (vipldws_B.countPeak < 1) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2] *
            vipldws_B.y[4];
          vipldws_B.R2 += 2;
          vipldws_B.countPeak = 1;
        }

        vipldws_B.y[5] = vipldws_B.scale;
        vipldws_B.y[6] = vipldws_B.HP_prdt[6];
        vipldws_B.R2 = 1;
        vipldws_B.scale = vipldws_B.HP_prdt[7];
        vipldws_B.countPeak = 0;
        while (vipldws_B.countPeak < 1) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2] *
            vipldws_B.y[6];
          vipldws_B.R2 += 2;
          vipldws_B.countPeak = 1;
        }

        vipldws_B.y[7] = vipldws_B.scale;

        /* End of S-Function (sdspfbsub2): '<S46>/Forward Substitution' */

        /* S-Function (sdspdiag2): '<S46>/Extract Diagonal' */
        vipldws_B.d[0] = vipldws_B.LDLFactorization[0];

        /* Math: '<S46>/Math Function'
         *
         * About '<S46>/Math Function':
         *  Operator: reciprocal
         */
        vipldws_B.ZHX_prd[0] = 1.0F / vipldws_B.d[0];

        /* S-Function (sdspdiag2): '<S46>/Extract Diagonal' */
        vipldws_B.d[1] = vipldws_B.LDLFactorization[3];

        /* Math: '<S46>/Math Function'
         *
         * About '<S46>/Math Function':
         *  Operator: reciprocal
         */
        vipldws_B.ZHX_prd[1] = 1.0F / vipldws_B.d[1];

        /* S-Function (sdspdmult2): '<S46>/Matrix Scaling' */
        vipldws_B.C1 = 0;
        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          vipldws_B.MatrixScaling[vipldws_B.C1] = vipldws_B.y[vipldws_B.C1] *
            vipldws_B.ZHX_prd[0];
          vipldws_B.C1++;
          vipldws_B.MatrixScaling[vipldws_B.C1] = vipldws_B.y[vipldws_B.C1] *
            vipldws_B.ZHX_prd[1];
          vipldws_B.C1++;
        }

        /* End of S-Function (sdspdmult2): '<S46>/Matrix Scaling' */

        /* S-Function (sdspfbsub2): '<S46>/Backward Substitution' */
        vipldws_B.BackwardSubstitution[1] = vipldws_B.MatrixScaling[1];
        vipldws_B.R2 = 0;
        vipldws_B.scale = vipldws_B.MatrixScaling[0];
        while (vipldws_B.countPeak > 0) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2 + 2] *
            vipldws_B.BackwardSubstitution[1];
          vipldws_B.R2 -= 2;
          vipldws_B.countPeak = 0;
        }

        vipldws_B.BackwardSubstitution[0] = vipldws_B.scale;
        vipldws_B.BackwardSubstitution[3] = vipldws_B.MatrixScaling[3];
        vipldws_B.R2 = 0;
        vipldws_B.scale = vipldws_B.MatrixScaling[2];
        vipldws_B.countPeak = 1;
        while (vipldws_B.countPeak > 0) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2 + 2] *
            vipldws_B.BackwardSubstitution[3];
          vipldws_B.R2 -= 2;
          vipldws_B.countPeak = 0;
        }

        vipldws_B.BackwardSubstitution[2] = vipldws_B.scale;
        vipldws_B.BackwardSubstitution[5] = vipldws_B.MatrixScaling[5];
        vipldws_B.R2 = 0;
        vipldws_B.scale = vipldws_B.MatrixScaling[4];
        vipldws_B.countPeak = 1;
        while (vipldws_B.countPeak > 0) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2 + 2] *
            vipldws_B.BackwardSubstitution[5];
          vipldws_B.R2 -= 2;
          vipldws_B.countPeak = 0;
        }

        vipldws_B.BackwardSubstitution[4] = vipldws_B.scale;
        vipldws_B.BackwardSubstitution[7] = vipldws_B.MatrixScaling[7];
        vipldws_B.R2 = 0;
        vipldws_B.scale = vipldws_B.MatrixScaling[6];
        vipldws_B.countPeak = 1;
        while (vipldws_B.countPeak > 0) {
          vipldws_B.scale -= vipldws_B.LDLFactorization[vipldws_B.R2 + 2] *
            vipldws_B.BackwardSubstitution[7];
          vipldws_B.R2 -= 2;
          vipldws_B.countPeak = 0;
        }

        vipldws_B.BackwardSubstitution[6] = vipldws_B.scale;

        /* End of S-Function (sdspfbsub2): '<S46>/Backward Substitution' */
        for (vipldws_B.i = 0; vipldws_B.i < 2; vipldws_B.i++) {
          for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 4;
               vipldws_B.countPeak++) {
            /* Math: '<S41>/K Trans' */
            vipldws_B.KTrans[vipldws_B.countPeak + (vipldws_B.i << 2)] =
              vipldws_B.BackwardSubstitution[(vipldws_B.countPeak << 1) +
              vipldws_B.i];

            /* Product: '<S41>/K*H*P_prd' incorporates:
             *  Constant: '<S41>/Hcst'
             */
            vipldws_B.fv1[vipldws_B.i + (vipldws_B.countPeak << 1)] = 0.0F;
            vipldws_B.fv1[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.Selector2_n[vipldws_B.countPeak << 2] *
              vipldws_P.Hcst_Value[vipldws_B.i];
            vipldws_B.fv1[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.Selector2_n[(vipldws_B.countPeak << 2) + 1] *
              vipldws_P.Hcst_Value[vipldws_B.i + 2];
            vipldws_B.fv1[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.Selector2_n[(vipldws_B.countPeak << 2) + 2] *
              vipldws_P.Hcst_Value[vipldws_B.i + 4];
            vipldws_B.fv1[vipldws_B.i + (vipldws_B.countPeak << 1)] +=
              vipldws_B.Selector2_n[(vipldws_B.countPeak << 2) + 3] *
              vipldws_P.Hcst_Value[vipldws_B.i + 6];
          }
        }

        /* Product: '<S41>/K*H*P_prd' */
        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 4;
               vipldws_B.countPeak++) {
            vipldws_B.P_prdKHP_prd[vipldws_B.i + (vipldws_B.countPeak << 2)] =
              0.0F;
            vipldws_B.P_prdKHP_prd[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_B.fv1[vipldws_B.countPeak << 1] *
              vipldws_B.KTrans[vipldws_B.i];
            vipldws_B.P_prdKHP_prd[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_B.fv1[(vipldws_B.countPeak << 1) + 1] *
              vipldws_B.KTrans[vipldws_B.i + 4];
          }
        }

        /* Sum: '<S41>/P_prd-K*H*P_prd' */
        for (vipldws_B.i = 0; vipldws_B.i < 16; vipldws_B.i++) {
          vipldws_B.P_prdKHP_prd[vipldws_B.i] =
            vipldws_B.Selector2_n[vipldws_B.i] -
            vipldws_B.P_prdKHP_prd[vipldws_B.i];
        }

        /* End of Sum: '<S41>/P_prd-K*H*P_prd' */

        /* Product: '<S41>/A*P*At' incorporates:
         *  Constant: '<S41>/Constant3'
         *  Constant: '<S41>/Constant4'
         */
        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 4;
               vipldws_B.countPeak++) {
            vipldws_B.fv0[vipldws_B.i + (vipldws_B.countPeak << 2)] = 0.0F;
            vipldws_B.fv0[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_P.Constant4_Value[vipldws_B.countPeak << 2] *
              vipldws_B.P_prdKHP_prd[vipldws_B.i];
            vipldws_B.fv0[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_P.Constant4_Value[(vipldws_B.countPeak << 2) + 1] *
              vipldws_B.P_prdKHP_prd[vipldws_B.i + 4];
            vipldws_B.fv0[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_P.Constant4_Value[(vipldws_B.countPeak << 2) + 2] *
              vipldws_B.P_prdKHP_prd[vipldws_B.i + 8];
            vipldws_B.fv0[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_P.Constant4_Value[(vipldws_B.countPeak << 2) + 3] *
              vipldws_B.P_prdKHP_prd[vipldws_B.i + 12];
          }
        }

        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 4;
               vipldws_B.countPeak++) {
            vipldws_B.APAtQ[vipldws_B.i + (vipldws_B.countPeak << 2)] = 0.0F;
            vipldws_B.APAtQ[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_B.fv0[vipldws_B.countPeak << 2] *
              vipldws_P.Constant3_Value[vipldws_B.i];
            vipldws_B.APAtQ[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_B.fv0[(vipldws_B.countPeak << 2) + 1] *
              vipldws_P.Constant3_Value[vipldws_B.i + 4];
            vipldws_B.APAtQ[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_B.fv0[(vipldws_B.countPeak << 2) + 2] *
              vipldws_P.Constant3_Value[vipldws_B.i + 8];
            vipldws_B.APAtQ[vipldws_B.i + (vipldws_B.countPeak << 2)] +=
              vipldws_B.fv0[(vipldws_B.countPeak << 2) + 3] *
              vipldws_P.Constant3_Value[vipldws_B.i + 12];
          }
        }

        /* End of Product: '<S41>/A*P*At' */

        /* Sum: '<S41>/A*P*At+Q' incorporates:
         *  Constant: '<S41>/Constant5'
         */
        for (vipldws_B.i = 0; vipldws_B.i < 16; vipldws_B.i++) {
          vipldws_B.APAtQ[vipldws_B.i] += vipldws_P.Constant5_Value[vipldws_B.i];
        }

        /* End of Sum: '<S41>/A*P*At+Q' */
        for (vipldws_B.i = 0; vipldws_B.i < 2; vipldws_B.i++) {
          /* Product: '<S41>/H*X_prd' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.ZHX_prd[vipldws_B.i] = 0.0F;
          vipldws_B.ZHX_prd[vipldws_B.i] += vipldws_P.Hcst_Value[vipldws_B.i] *
            vipldws_B.Selector1_c[0];
          vipldws_B.ZHX_prd[vipldws_B.i] += vipldws_P.Hcst_Value[vipldws_B.i + 2]
            * vipldws_B.Selector1_c[1];
          vipldws_B.ZHX_prd[vipldws_B.i] += vipldws_P.Hcst_Value[vipldws_B.i + 4]
            * vipldws_B.Selector1_c[2];
          vipldws_B.ZHX_prd[vipldws_B.i] += vipldws_P.Hcst_Value[vipldws_B.i + 6]
            * vipldws_B.Selector1_c[3];

          /* Sum: '<S41>/Z-H*X_prd' */
          vipldws_B.ZHX_prd[vipldws_B.i] = vipldws_B.Selector_i[vipldws_B.i] -
            vipldws_B.ZHX_prd[vipldws_B.i];
        }

        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          /* Product: '<S41>/K*(Z-H*X_prd)' */
          vipldws_B.X_prdKZHX_prd[vipldws_B.i] = 0.0F;
          vipldws_B.X_prdKZHX_prd[vipldws_B.i] += vipldws_B.KTrans[vipldws_B.i] *
            vipldws_B.ZHX_prd[0];
          vipldws_B.X_prdKZHX_prd[vipldws_B.i] += vipldws_B.KTrans[vipldws_B.i +
            4] * vipldws_B.ZHX_prd[1];

          /* Sum: '<S41>/X_prd+K*(Z-H*X_prd)' */
          vipldws_B.X_prdKZHX_prd[vipldws_B.i] +=
            vipldws_B.Selector1_c[vipldws_B.i];
        }

        /* Product: '<S41>/A*X' incorporates:
         *  Constant: '<S41>/Constant3'
         */
        for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
          vipldws_B.AX[vipldws_B.i] = 0.0F;
          vipldws_B.AX[vipldws_B.i] += vipldws_P.Constant3_Value[vipldws_B.i] *
            vipldws_B.X_prdKZHX_prd[0];
          vipldws_B.AX[vipldws_B.i] += vipldws_P.Constant3_Value[vipldws_B.i + 4]
            * vipldws_B.X_prdKZHX_prd[1];
          vipldws_B.AX[vipldws_B.i] += vipldws_P.Constant3_Value[vipldws_B.i + 8]
            * vipldws_B.X_prdKZHX_prd[2];
          vipldws_B.AX[vipldws_B.i] += vipldws_P.Constant3_Value[vipldws_B.i +
            12] * vipldws_B.X_prdKZHX_prd[3];
        }

        /* End of Product: '<S41>/A*X' */

        /* Reshape: '<S41>/P_prd_Reshape' */
        memcpy(&vipldws_B.P_prd_Reshape[0], &vipldws_B.APAtQ[0], sizeof(real32_T)
               << 4U);
        for (vipldws_B.i = 0; vipldws_B.i < 2; vipldws_B.i++) {
          /* Product: '<S41>/Z_est_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_est_Multiply[vipldws_B.i] = 0.0F;

          /* Product: '<S41>/Z_prd_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_prd_Multiply[vipldws_B.i] = 0.0F;

          /* Product: '<S41>/Z_est_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_est_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i] * vipldws_B.X_prdKZHX_prd[0];

          /* Product: '<S41>/Z_prd_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_prd_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i] * vipldws_B.AX[0];

          /* Product: '<S41>/Z_est_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_est_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i + 2] * vipldws_B.X_prdKZHX_prd[1];

          /* Product: '<S41>/Z_prd_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_prd_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i + 2] * vipldws_B.AX[1];

          /* Product: '<S41>/Z_est_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_est_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i + 4] * vipldws_B.X_prdKZHX_prd[2];

          /* Product: '<S41>/Z_prd_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_prd_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i + 4] * vipldws_B.AX[2];

          /* Product: '<S41>/Z_est_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_est_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i + 6] * vipldws_B.X_prdKZHX_prd[3];

          /* Product: '<S41>/Z_prd_Multiply' incorporates:
           *  Constant: '<S41>/Hcst'
           */
          vipldws_B.Z_prd_Multiply[vipldws_B.i] +=
            vipldws_P.Hcst_Value[vipldws_B.i + 6] * vipldws_B.AX[3];
        }

        vipldws_DW.Core_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S40>/Core' */

      /* Switch: '<S42>/Switch' incorporates:
       *  Constant: '<S42>/Reset_Value'
       */
      if (vipldws_B.Rst_And) {
        memcpy(&vipldws_B.Switch_m[0], &vipldws_P.Reset_Value_Value[0], sizeof
               (real32_T) << 4U);
      } else {
        memcpy(&vipldws_B.Switch_m[0], &vipldws_B.P_prd_Reshape[0], sizeof
               (real32_T) << 4U);
      }

      /* End of Switch: '<S42>/Switch' */

      /* Assignment: '<S42>/Assignment' */
      if (vipldws_DW.Iterator_IterationMarker[0] < 2) {
        vipldws_DW.Iterator_IterationMarker[0] = 2U;
        memcpy(&vipldws_B.Assignment_io[0], &vipldws_B.UnitDelay3[0], 320U *
               sizeof(real32_T));
      }

      for (vipldws_B.i = 0; vipldws_B.i < 16; vipldws_B.i++) {
        vipldws_B.Assignment_io[vipldws_B.i + ((vipldws_B.Iterator - 1) << 4)] =
          vipldws_B.Switch_m[vipldws_B.i];
      }

      /* End of Assignment: '<S42>/Assignment' */

      /* Switch: '<S43>/Switch' incorporates:
       *  Constant: '<S43>/Reset_Value'
       */
      if (vipldws_B.Rst_And) {
        vipldws_B.Switch_l[0] = vipldws_P.Reset_Value_Value_j[0];
        vipldws_B.Switch_l[1] = vipldws_P.Reset_Value_Value_j[1];
        vipldws_B.Switch_l[2] = vipldws_P.Reset_Value_Value_j[2];
        vipldws_B.Switch_l[3] = vipldws_P.Reset_Value_Value_j[3];
      } else {
        vipldws_B.Switch_l[0] = vipldws_B.AX[0];
        vipldws_B.Switch_l[1] = vipldws_B.AX[1];
        vipldws_B.Switch_l[2] = vipldws_B.AX[2];
        vipldws_B.Switch_l[3] = vipldws_B.AX[3];
      }

      /* End of Switch: '<S43>/Switch' */

      /* Assignment: '<S43>/Assignment' */
      if (vipldws_DW.Iterator_IterationMarker[1] < 2) {
        vipldws_DW.Iterator_IterationMarker[1] = 2U;
        memcpy(&vipldws_B.Assignment_o[0], &vipldws_B.UnitDelay2[0], 80U *
               sizeof(real32_T));
      }

      vipldws_B.Assignment_o[(vipldws_B.Iterator - 1) << 2] =
        vipldws_B.Switch_l[0];
      vipldws_B.Assignment_o[1 + ((vipldws_B.Iterator - 1) << 2)] =
        vipldws_B.Switch_l[1];
      vipldws_B.Assignment_o[2 + ((vipldws_B.Iterator - 1) << 2)] =
        vipldws_B.Switch_l[2];
      vipldws_B.Assignment_o[3 + ((vipldws_B.Iterator - 1) << 2)] =
        vipldws_B.Switch_l[3];

      /* End of Assignment: '<S43>/Assignment' */

      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S44>/Reset_Value'
       */
      if (vipldws_B.Rst_And) {
        vipldws_B.Switch_j[0] = vipldws_P.Reset_Value_Value_b[0];
      } else {
        vipldws_B.Switch_j[0] = vipldws_B.Z_est_Multiply[0];
      }

      /* Assignment: '<S44>/Assignment' */
      vipldws_B.Assignment_p[(vipldws_B.Iterator - 1) << 1] =
        vipldws_B.Switch_j[0];

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S45>/Reset_Value'
       */
      if (vipldws_B.Rst_And) {
        vipldws_B.Switch_j[0] = vipldws_P.Reset_Value_Value_p[0];
      } else {
        vipldws_B.Switch_j[0] = vipldws_B.Z_prd_Multiply[0];
      }

      /* Assignment: '<S45>/Assignment' */
      vipldws_B.Assignment_a[(vipldws_B.Iterator - 1) << 1] =
        vipldws_B.Switch_j[0];

      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S44>/Reset_Value'
       */
      if (vipldws_B.Rst_And) {
        vipldws_B.Switch_j[1] = vipldws_P.Reset_Value_Value_b[1];
      } else {
        vipldws_B.Switch_j[1] = vipldws_B.Z_est_Multiply[1];
      }

      /* Assignment: '<S44>/Assignment' */
      vipldws_B.Assignment_p[1 + ((vipldws_B.Iterator - 1) << 1)] =
        vipldws_B.Switch_j[1];

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S45>/Reset_Value'
       */
      if (vipldws_B.Rst_And) {
        vipldws_B.Switch_j[1] = vipldws_P.Reset_Value_Value_p[1];
      } else {
        vipldws_B.Switch_j[1] = vipldws_B.Z_prd_Multiply[1];
      }

      /* Assignment: '<S45>/Assignment' */
      vipldws_B.Assignment_a[1 + ((vipldws_B.Iterator - 1) << 1)] =
        vipldws_B.Switch_j[1];
      vipldws_DW.Options_SubsysRanBC = 4;
    }

    /* End of Outputs for SubSystem: '<S39>/Options' */
    vipldws_B.yIdx++;
  }

  /* End of Outputs for SubSystem: '<S32>/Control' */
  for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
    /* Selector: '<S1>/select rho5' */
    vipldws_B.selectrho5_f[vipldws_B.i] = vipldws_B.Assignment_p[(vipldws_B.i <<
      1) + 1];

    /* Selector: '<S1>/select rho2' */
    vipldws_B.selectrho2[vipldws_B.i] = vipldws_B.Assignment_p[vipldws_B.i << 1];
  }

  /* S-Function (sviphoughlines): '<S1>/Convert lines from  Polar to Cartesian space' */
  for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
    vipldws_B.yIdx = 0;
    vipldws_B.scale = (vipldws_B.selectrho2[vipldws_B.i] + 1.1920929E-7F) /
      ((real32_T)cos(vipldws_B.selectrho5_f[vipldws_B.i]) + 1.1920929E-7F);

    /* part-1: top horizontal axis */
    vipldws_B.cnt = (real32_T)floor(vipldws_B.scale + 0.5F);
    if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 239.0F)) {
      vipldws_B.tmpOutRC[0U] = 0;
      if (vipldws_B.cnt >= 0.5F) {
        vipldws_B.tmpOutRC[1U] = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
      } else {
        vipldws_B.tmpOutRC[1U] = 0;
      }

      vipldws_B.yIdx = 1;
    }

    vipldws_B.y2 = (vipldws_B.selectrho2[vipldws_B.i] + 1.1920929E-7F) /
      ((real32_T)sin(vipldws_B.selectrho5_f[vipldws_B.i]) + 1.1920929E-7F);

    /* part-2: left vertical axis */
    vipldws_B.cnt = (real32_T)floor(vipldws_B.y2 + 0.5F);
    if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 199.0F)) {
      if (vipldws_B.cnt >= 0.5F) {
        vipldws_B.tmpOutRC[vipldws_B.yIdx << 1] = (int32_T)(real32_T)floor
          (vipldws_B.cnt + 0.5F);
      } else {
        vipldws_B.tmpOutRC[vipldws_B.yIdx << 1] = 0;
      }

      vipldws_B.tmpOutRC[1 + (vipldws_B.yIdx << 1)] = 0;
      vipldws_B.yIdx++;
    }

    /* part-3: Right vertical axis */
    if (vipldws_B.yIdx < 2) {
      vipldws_B.cnt = (real32_T)floor((vipldws_B.scale - 239.0F) * (vipldws_B.y2
        / vipldws_B.scale) + 0.5F);
      if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 199.0F)) {
        if (vipldws_B.cnt >= 0.5F) {
          vipldws_B.tmpOutRC[vipldws_B.yIdx << 1] = (int32_T)(real32_T)floor
            (vipldws_B.cnt + 0.5F);
        } else {
          vipldws_B.tmpOutRC[vipldws_B.yIdx << 1] = 0;
        }

        vipldws_B.tmpOutRC[1 + (vipldws_B.yIdx << 1)] = 239;
        vipldws_B.yIdx++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (vipldws_B.yIdx < 2) {
      vipldws_B.cnt = (real32_T)floor((vipldws_B.scale - vipldws_B.scale /
        vipldws_B.y2 * 199.0F) + 0.5F);
      if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 239.0F)) {
        vipldws_B.tmpOutRC[vipldws_B.yIdx << 1] = 199;
        if (vipldws_B.cnt >= 0.5F) {
          vipldws_B.tmpOutRC[1 + (vipldws_B.yIdx << 1)] = (int32_T)(real32_T)
            floor(vipldws_B.cnt + 0.5F);
        } else {
          vipldws_B.tmpOutRC[1 + (vipldws_B.yIdx << 1)] = 0;
        }

        vipldws_B.yIdx++;
      }
    }

    if (vipldws_B.yIdx < 2) {
      vipldws_B.tmpOutRC[0U] = -1;
      vipldws_B.tmpOutRC[1U] = -1;
      vipldws_B.tmpOutRC[2U] = -1;
      vipldws_B.tmpOutRC[3U] = -1;
    }

    vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i] = vipldws_B.tmpOutRC
      [1] + 1;
    vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i + 20] =
      vipldws_B.tmpOutRC[0] + 1;
    if (vipldws_B.tmpOutRC[3] > 2147483646) {
      vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i + 40] = MAX_int32_T;
    } else {
      vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i + 40] =
        vipldws_B.tmpOutRC[3] + 1;
    }

    if (vipldws_B.tmpOutRC[2] > 2147483646) {
      vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i + 60] = MAX_int32_T;
    } else {
      vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i + 60] =
        vipldws_B.tmpOutRC[2] + 1;
    }
  }

  /* End of S-Function (sviphoughlines): '<S1>/Convert lines from  Polar to Cartesian space' */

  /* Bias: '<S1>/Bias1' */
  for (vipldws_B.i = 0; vipldws_B.i < 80; vipldws_B.i++) {
    vipldws_B.Bias1[vipldws_B.i] =
      vipldws_B.ConvertlinesfromPolartoCartesia[vipldws_B.i] +
      vipldws_P.Bias1_Bias_l;
  }

  /* End of Bias: '<S1>/Bias1' */

  /* Selector: '<S1>/Selector1' */
  for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 20; vipldws_B.countPeak
         ++) {
      vipldws_B.Selector1_il[vipldws_B.countPeak + 20 * vipldws_B.i] =
        vipldws_B.Bias1[20 * tmp[vipldws_B.i] + vipldws_B.countPeak];
    }
  }

  /* End of Selector: '<S1>/Selector1' */

  /* Math: '<S1>/Transpose' */
  for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
    vipldws_B.Transpose[vipldws_B.i << 2] = vipldws_B.Selector1_il[vipldws_B.i];
    vipldws_B.Transpose[1 + (vipldws_B.i << 2)] =
      vipldws_B.Selector1_il[vipldws_B.i + 20];
    vipldws_B.Transpose[2 + (vipldws_B.i << 2)] =
      vipldws_B.Selector1_il[vipldws_B.i + 40];
    vipldws_B.Transpose[3 + (vipldws_B.i << 2)] =
      vipldws_B.Selector1_il[vipldws_B.i + 60];
  }

  /* End of Math: '<S1>/Transpose' */

  /* Gain: '<S1>/rho_1' */
  vipldws_B.rho_1 = (int32_T)((int64_T)vipldws_P.rho_1_Gain *
    vipldws_B.Widthoftheimage[1] >> 31);

  /* Outputs for Iterator SubSystem: '<S1>/Find the left and  right lanes from the depository' incorporates:
   *  ForIterator: '<S7>/For Iterator'
   */
  /* InitializeConditions for UnitDelay: '<S24>/Min_left_dis' */
  vipldws_DW.Min_left_dis_DSTATE = vipldws_P.Min_left_dis_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_dis' */
  vipldws_DW.Min_right_dis_DSTATE = vipldws_P.Min_right_dis_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws_DW.Min_left_pts_DSTATE[0] = vipldws_P.Min_left_pts_InitialCondition[0];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws_DW.Min_right_pts_DSTATE[0] = vipldws_P.Min_right_pts_InitialCondition
    [0];

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws_DW.Min_left_pts_DSTATE[1] = vipldws_P.Min_left_pts_InitialCondition[1];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws_DW.Min_right_pts_DSTATE[1] = vipldws_P.Min_right_pts_InitialCondition
    [1];

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws_DW.Min_left_pts_DSTATE[2] = vipldws_P.Min_left_pts_InitialCondition[2];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws_DW.Min_right_pts_DSTATE[2] = vipldws_P.Min_right_pts_InitialCondition
    [2];

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws_DW.Min_left_pts_DSTATE[3] = vipldws_P.Min_left_pts_InitialCondition[3];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws_DW.Min_right_pts_DSTATE[3] = vipldws_P.Min_right_pts_InitialCondition
    [3];
  vipldws_B.yIdx = 1;
  while (vipldws_B.yIdx <= vipldws_P.ForIterator_IterationLimit) {
    vipldws_B.ForIterator_fi = vipldws_B.yIdx;

    /* Selector: '<S7>/select rho1' */
    vipldws_B.Intersectionwithbottomimagebo_j =
      vipldws_B.Saturation_h[vipldws_B.ForIterator_fi - 1];

    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     */
    vipldws_B.LogicalOperator2_j = (vipldws_B.Intersectionwithbottomimagebo_j >=
      vipldws_P.CompareToConstant2_const);

    /* Selector: '<S7>/select rho5' */
    vipldws_B.selectrho5_b[0] = vipldws_B.Transpose[(vipldws_B.ForIterator_fi -
      1) << 2];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws_B.Min_right_pts[0] = vipldws_DW.Min_left_pts_DSTATE[0];

    /* Selector: '<S7>/select rho5' */
    vipldws_B.selectrho5_b[1] = vipldws_B.Transpose[((vipldws_B.ForIterator_fi -
      1) << 2) + 1];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws_B.Min_right_pts[1] = vipldws_DW.Min_left_pts_DSTATE[1];

    /* Selector: '<S7>/select rho5' */
    vipldws_B.selectrho5_b[2] = vipldws_B.Transpose[((vipldws_B.ForIterator_fi -
      1) << 2) + 2];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws_B.Min_right_pts[2] = vipldws_DW.Min_left_pts_DSTATE[2];

    /* Selector: '<S7>/select rho5' */
    vipldws_B.selectrho5_b[3] = vipldws_B.Transpose[((vipldws_B.ForIterator_fi -
      1) << 2) + 3];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws_B.Min_right_pts[3] = vipldws_DW.Min_left_pts_DSTATE[3];

    /* RelationalOperator: '<S24>/Relational Operator' */
    vipldws_B.LogicalOperator1_m = (vipldws_B.selectrho5_b[0] >=
      vipldws_B.selectrho5_b[2]);

    /* Switch: '<S24>/Intersection with  bottom image boundary' */
    if (vipldws_B.LogicalOperator1_m) {
      vipldws_B.Intersectionwithbottomimagebo_j = vipldws_B.selectrho5_b[1];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_j = vipldws_B.selectrho5_b[3];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary' */

    /* Sum: '<S24>/Add2' */
    vipldws_B.Intersectionwithbottomimagebo_j = vipldws_B.rho_1 -
      vipldws_B.Intersectionwithbottomimagebo_j;

    /* Abs: '<S24>/Abs' */
    if (vipldws_B.Intersectionwithbottomimagebo_j < 0) {
      vipldws_B.Intersectionwithbottomimagebo_d =
        -vipldws_B.Intersectionwithbottomimagebo_j;
    } else {
      vipldws_B.Intersectionwithbottomimagebo_d =
        vipldws_B.Intersectionwithbottomimagebo_j;
    }

    /* End of Abs: '<S24>/Abs' */

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     */
    vipldws_B.LogicalOperator1_m = (vipldws_B.Intersectionwithbottomimagebo_j >=
      vipldws_P.Constant_Value_i);

    /* Logic: '<S24>/Logical Operator' */
    vipldws_B.RelationalOperator2_e = (vipldws_B.LogicalOperator1_m &&
      vipldws_B.LogicalOperator2_j);

    /* Switch: '<S24>/Intersection with  bottom image boundary1' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_j =
        vipldws_B.Intersectionwithbottomimagebo_d;
    } else {
      vipldws_B.Intersectionwithbottomimagebo_j = vipldws_B.Widthoftheimage[1];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary1' */

    /* UnitDelay: '<S24>/Min_left_dis' */
    vipldws_B.Min_right_dis = vipldws_DW.Min_left_dis_DSTATE;

    /* RelationalOperator: '<S24>/Relational Operator1' */
    vipldws_B.RelationalOperator2_e = (vipldws_B.Min_right_dis <=
      vipldws_B.Intersectionwithbottomimagebo_j);

    /* Switch: '<S24>/Intersection with  bottom image boundary2' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimageboun = vipldws_B.Min_right_dis;
    } else {
      vipldws_B.Intersectionwithbottomimageboun =
        vipldws_B.Intersectionwithbottomimagebo_j;
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary2' */

    /* Logic: '<S24>/Logical Operator1' */
    vipldws_B.LogicalOperator1_m = !vipldws_B.LogicalOperator1_m;

    /* Logic: '<S24>/Logical Operator2' */
    vipldws_B.LogicalOperator2_j = (vipldws_B.LogicalOperator2_j &&
      vipldws_B.LogicalOperator1_m);

    /* Switch: '<S24>/Intersection with  bottom image boundary4' */
    if (!vipldws_B.LogicalOperator2_j) {
      vipldws_B.Intersectionwithbottomimagebo_d = vipldws_B.Widthoftheimage[1];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary4' */

    /* UnitDelay: '<S24>/Min_right_dis' */
    vipldws_B.Min_right_dis = vipldws_DW.Min_right_dis_DSTATE;

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_o[0] = vipldws_B.Min_right_pts[0];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_o[0] = vipldws_B.selectrho5_b[0];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws_B.Min_right_pts[0] = vipldws_DW.Min_right_pts_DSTATE[0];

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_o[1] = vipldws_B.Min_right_pts[1];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_o[1] = vipldws_B.selectrho5_b[1];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws_B.Min_right_pts[1] = vipldws_DW.Min_right_pts_DSTATE[1];

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_o[2] = vipldws_B.Min_right_pts[2];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_o[2] = vipldws_B.selectrho5_b[2];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws_B.Min_right_pts[2] = vipldws_DW.Min_right_pts_DSTATE[2];

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_o[3] = vipldws_B.Min_right_pts[3];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_o[3] = vipldws_B.selectrho5_b[3];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws_B.Min_right_pts[3] = vipldws_DW.Min_right_pts_DSTATE[3];

    /* RelationalOperator: '<S24>/Relational Operator2' */
    vipldws_B.RelationalOperator2_e = (vipldws_B.Min_right_dis <=
      vipldws_B.Intersectionwithbottomimagebo_d);

    /* Switch: '<S24>/Intersection with  bottom image boundary5' incorporates:
     *  Switch: '<S24>/Intersection with  bottom image boundary6'
     */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_g = vipldws_B.Min_right_dis;
      vipldws_B.Intersectionwithbottomimagebo_c[0] = vipldws_B.Min_right_pts[0];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_g =
        vipldws_B.Intersectionwithbottomimagebo_d;
      vipldws_B.Intersectionwithbottomimagebo_c[0] = vipldws_B.selectrho5_b[0];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary5' */

    /* Update for UnitDelay: '<S24>/Min_left_dis' */
    vipldws_DW.Min_left_dis_DSTATE = vipldws_B.Intersectionwithbottomimageboun;

    /* Update for UnitDelay: '<S24>/Min_right_dis' */
    vipldws_DW.Min_right_dis_DSTATE = vipldws_B.Intersectionwithbottomimagebo_g;

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[0] =
      vipldws_B.Intersectionwithbottomimagebo_o[0];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[0] =
      vipldws_B.Intersectionwithbottomimagebo_c[0];

    /* Switch: '<S24>/Intersection with  bottom image boundary6' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_c[1] = vipldws_B.Min_right_pts[1];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_c[1] = vipldws_B.selectrho5_b[1];
    }

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[1] =
      vipldws_B.Intersectionwithbottomimagebo_o[1];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[1] =
      vipldws_B.Intersectionwithbottomimagebo_c[1];

    /* Switch: '<S24>/Intersection with  bottom image boundary6' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_c[2] = vipldws_B.Min_right_pts[2];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_c[2] = vipldws_B.selectrho5_b[2];
    }

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[2] =
      vipldws_B.Intersectionwithbottomimagebo_o[2];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[2] =
      vipldws_B.Intersectionwithbottomimagebo_c[2];

    /* Switch: '<S24>/Intersection with  bottom image boundary6' */
    if (vipldws_B.RelationalOperator2_e) {
      vipldws_B.Intersectionwithbottomimagebo_c[3] = vipldws_B.Min_right_pts[3];
    } else {
      vipldws_B.Intersectionwithbottomimagebo_c[3] = vipldws_B.selectrho5_b[3];
    }

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[3] =
      vipldws_B.Intersectionwithbottomimagebo_o[3];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[3] =
      vipldws_B.Intersectionwithbottomimagebo_c[3];
    vipldws_B.yIdx++;
  }

  /* End of Outputs for SubSystem: '<S1>/Find the left and  right lanes from the depository' */

  /* Gain: '<S1>/Distance threshold  for departure warning' */
  vipldws_B.Distancethresholdfordeparturewa = (int32_T)((int64_T)
    vipldws_P.Distancethresholdfordeparturewa * vipldws_B.Widthoftheimage[1] >>
    32);

  /* RelationalOperator: '<S6>/Relational Operator4' */
  vipldws_B.Compare_ni = (vipldws_B.Intersectionwithbottomimageboun <=
    vipldws_B.Intersectionwithbottomimagebo_g);

  /* Switch: '<S6>/Switch2' */
  if (vipldws_B.Compare_ni) {
    /* RelationalOperator: '<S6>/Relational Operator2' */
    vipldws_B.RelationalOperator2 = (vipldws_B.Intersectionwithbottomimageboun <
      vipldws_B.Distancethresholdfordeparturewa);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Draw Lines'
     *  Constant: '<S6>/Draw Lines1'
     */
    if (vipldws_B.RelationalOperator2) {
      vipldws_B.Switch_a = vipldws_P.DrawLines_Value;
    } else {
      vipldws_B.Switch_a = vipldws_P.DrawLines1_Value;
    }

    /* End of Switch: '<S6>/Switch' */
    vipldws_B.RawMessage = vipldws_B.Switch_a;
  } else {
    /* RelationalOperator: '<S6>/Relational Operator3' */
    vipldws_B.RelationalOperator3 = (vipldws_B.Intersectionwithbottomimagebo_g <
      vipldws_B.Distancethresholdfordeparturewa);

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Draw Lines2'
     *  Constant: '<S6>/Draw Lines3'
     */
    if (vipldws_B.RelationalOperator3) {
      vipldws_B.Switch1_j = vipldws_P.DrawLines2_Value;
    } else {
      vipldws_B.Switch1_j = vipldws_P.DrawLines3_Value;
    }

    /* End of Switch: '<S6>/Switch1' */
    vipldws_B.RawMessage = vipldws_B.Switch1_j;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Delay: '<S17>/Delay' */
  vipldws_B.Delay = vipldws_DW.Delay_DSTATE;

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   */
  vipldws_B.Compare_ni = (vipldws_B.RawMessage ==
    vipldws_P.CompareToConstant_const_h);

  /* Delay: '<S17>/Delay1' */
  vipldws_B.Bias_h = vipldws_DW.Delay1_DSTATE_e;

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  vipldws_B.Compare = (vipldws_B.Bias_h != vipldws_P.CompareToConstant1_const_h);

  /* S-Function (sdspcount2): '<S17>/Counter' */
  if (vipldws_B.Compare) {
    vipldws_DW.Counter_Count = vipldws_P.Counter_InitialCount;
  }

  if (vipldws_B.Compare_ni) {
    vipldws_DW.Counter_Count++;
  }

  vipldws_B.Counter = vipldws_DW.Counter_Count;

  /* End of S-Function (sdspcount2): '<S17>/Counter' */

  /* MATLAB Function: '<S17>/Combine Left Right Departure' */
  /*  It combines left-right departure to left departure */
  /*          and right-left departure to right departure */
  /*  It utilizes the fact that there must be at least 4 frames of normal driving  */
  /*  between a left departure warning and a right departure warning */
  /* MATLAB Function 'Departure Warning/Departure detection/subsystem/Combine Left Right Departure': '<S20>:1' */
  /* RIGHT_DEP=0; NORMAL=1; LEFT_DEP=2 */
  /* '<S20>:1:9' NORMAL = int8(1); */
  /* '<S20>:1:11' if curMsg == NORMAL */
  if (vipldws_B.RawMessage == 1) {
    /* '<S20>:1:12' outMsg = NORMAL; */
    vipldws_B.outMsg = 1;
  } else {
    /* '<S20>:1:13' else */
    /*  curMsg == RIGHT_DEP  || curMsg == LEFT_DEP */
    /* '<S20>:1:14' if (numNormalDrivenFrames < int32(4)) */
    if (vipldws_B.Counter < 4) {
      /*  use the previous message */
      /* '<S20>:1:16' outMsg = prevMsg; */
      vipldws_B.outMsg = vipldws_B.Delay;
    } else {
      /* '<S20>:1:17' else */
      /* '<S20>:1:18' outMsg = curMsg; */
      vipldws_B.outMsg = vipldws_B.RawMessage;
    }
  }

  /* End of MATLAB Function: '<S17>/Combine Left Right Departure' */

  /* RelationalOperator: '<S61>/Compare' incorporates:
   *  Constant: '<S61>/Constant'
   */
  vipldws_B.Compare_ni = (vipldws_B.outMsg ==
    vipldws_P.CompareToConstant2_const_i);

  /* Selector: '<S29>/select rho5' */
  for (vipldws_B.i = 0; vipldws_B.i < 21; vipldws_B.i++) {
    memcpy(&vipldws_B.selectrho5_m[vipldws_B.i * 36],
           &vipldws_B.HoughTransform_o1[vipldws_B.i * 625 + 91004], 36U * sizeof
           (real32_T));
  }

  /* End of Selector: '<S29>/select rho5' */

  /* S-Function (svipfindlocalmax): '<S29>/Find Local Maxima1' */
  vipldws_B.countPeak = 0;
  done = false;
  vipldws_B.i = 0;
  while (vipldws_B.i < 756) {
    vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.i] =
      vipldws_B.selectrho5_m[vipldws_B.i];
    vipldws_B.i++;
  }

  vipldws_B.FindLocalMaxima1_o1_f[0] = 0U;
  vipldws_B.FindLocalMaxima1_o1_f[1] = 0U;
  while (!done) {
    vipldws_B.C1 = 0;
    vipldws_B.scale = vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[0];
    vipldws_B.i = 0;
    while (vipldws_B.i < 756) {
      if (vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.i] >
          vipldws_B.scale) {
        vipldws_B.C1 = vipldws_B.i;
        vipldws_B.scale = vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.i];
      }

      vipldws_B.i++;
    }

    vipldws_B.R2 = vipldws_B.C1 % 36;
    vipldws_B.i = vipldws_B.C1 / 36;
    if (vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.C1] >=
        vipldws_P.FindLocalMaxima1_threshold_b) {
      vipldws_B.FindLocalMaxima1_o1_f[vipldws_B.countPeak] = (uint16_T)(1 +
        vipldws_B.i);
      vipldws_B.FindLocalMaxima1_o1_f[1U + vipldws_B.countPeak] = (uint16_T)(1 +
        vipldws_B.R2);
      vipldws_B.countPeak++;
      if (vipldws_B.countPeak == 1) {
        done = true;
      }

      vipldws_B.C1 = vipldws_B.R2 - 3;
      if (!(vipldws_B.C1 > 0)) {
        vipldws_B.C1 = 0;
      }

      vipldws_B.R2 += 3;
      if (!(vipldws_B.R2 < 35)) {
        vipldws_B.R2 = 35;
      }

      vipldws_B.C2 = vipldws_B.i - 3;
      vipldws_B.c2 = vipldws_B.i + 3;
      if (!((vipldws_B.C2 < 0) || (vipldws_B.c2 > 20))) {
        while (vipldws_B.C2 <= vipldws_B.c2) {
          vipldws_B.c1 = vipldws_B.C2 * 36;
          vipldws_B.i = vipldws_B.C1;
          while (vipldws_B.i <= vipldws_B.R2) {
            vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.i +
              vipldws_B.c1] = 0.0F;
            vipldws_B.i++;
          }

          vipldws_B.C2++;
        }
      } else {
        if (vipldws_B.C2 < 0) {
          vipldws_B.ii = vipldws_B.C2;
          while (vipldws_B.ii <= vipldws_B.c2) {
            if (vipldws_B.ii < 0) {
              vipldws_B.c1 = (vipldws_B.ii + 21) * 36 + 35;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.c1 -
                  vipldws_B.i] = 0.0F;
                vipldws_B.i++;
              }
            } else {
              vipldws_B.c1 = vipldws_B.ii * 36;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.i +
                  vipldws_B.c1] = 0.0F;
                vipldws_B.i++;
              }
            }

            vipldws_B.ii++;
          }
        }

        if (vipldws_B.c2 > 20) {
          vipldws_B.ii = vipldws_B.C2;
          while (vipldws_B.ii <= vipldws_B.c2) {
            if (vipldws_B.ii > 20) {
              vipldws_B.c1 = (vipldws_B.ii - 21) * 36 + 35;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.c1 -
                  vipldws_B.i] = 0.0F;
                vipldws_B.i++;
              }
            } else {
              vipldws_B.c1 = vipldws_B.ii * 36;
              vipldws_B.i = vipldws_B.C1;
              while (vipldws_B.i <= vipldws_B.R2) {
                vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws_B.i +
                  vipldws_B.c1] = 0.0F;
                vipldws_B.i++;
              }
            }

            vipldws_B.ii++;
          }
        }
      }
    } else {
      done = true;
    }
  }

  vipldws_B.FindLocalMaxima1_o2_c = (uint16_T)vipldws_B.countPeak;

  /* End of S-Function (svipfindlocalmax): '<S29>/Find Local Maxima1' */

  /* Switch: '<S5>/Switch1' */
  if (vipldws_B.Compare_ni) {
    /* Selector: '<S30>/Selector2' */
    vipldws_B.Selector2_mw[0] = vipldws_B.FindLocalMaxima1_o1[1];

    /* Math: '<S30>/Transpose' */
    vipldws_B.Transpose_b[0] = vipldws_B.Selector2_mw[0];

    /* Selector: '<S30>/Selector2' */
    vipldws_B.Selector2_mw[1] = vipldws_B.FindLocalMaxima1_o1[0];

    /* Math: '<S30>/Transpose' */
    vipldws_B.Transpose_b[1] = vipldws_B.Selector2_mw[1];

    /* Selector: '<S30>/select rho4' */
    vipldws_B.Bias3_f = vipldws_B.Transpose_b[0];

    /* Bias: '<S30>/Bias2' */
    vipldws_B.Bias3_f = (uint16_T)((uint32_T)vipldws_B.Bias3_f +
      vipldws_P.Bias2_Bias_h);

    /* Selector: '<S30>/Selector rho' */
    vipldws_B.Selectorrho_c = vipldws_B.HoughTransform_o3[vipldws_B.Bias3_f - 1];

    /* Selector: '<S30>/select rho7' */
    vipldws_B.Bias3_f = vipldws_B.Transpose_b[1];

    /* Bias: '<S30>/Bias3' */
    vipldws_B.Bias3_f = (uint16_T)((uint32_T)vipldws_B.Bias3_f +
      vipldws_P.Bias3_Bias_d);

    /* Selector: '<S30>/Selector theta' */
    vipldws_B.Selectortheta_i = vipldws_B.HoughTransform_o2[vipldws_B.Bias3_f -
      1];

    /* S-Function (sviphoughlines): '<S26>/Hough Lines' */
    vipldws_B.yIdx = 0;
    vipldws_B.scale = (vipldws_B.Selectorrho_c + 1.1920929E-7F) / ((real32_T)cos
      (vipldws_B.Selectortheta_i) + 1.1920929E-7F);

    /* part-1: top horizontal axis */
    vipldws_B.cnt = (real32_T)floor(vipldws_B.scale + 0.5F);
    if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 239.0F)) {
      vipldws_B.tmpOutRC_m[0U] = 0;
      if (vipldws_B.cnt >= 0.5F) {
        vipldws_B.tmpOutRC_m[1U] = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
      } else {
        vipldws_B.tmpOutRC_m[1U] = 0;
      }

      vipldws_B.yIdx = 1;
    }

    vipldws_B.y2 = (vipldws_B.Selectorrho_c + 1.1920929E-7F) / ((real32_T)sin
      (vipldws_B.Selectortheta_i) + 1.1920929E-7F);

    /* part-2: left vertical axis */
    vipldws_B.cnt = (real32_T)floor(vipldws_B.y2 + 0.5F);
    if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 199.0F)) {
      if (vipldws_B.cnt >= 0.5F) {
        vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = (int32_T)(real32_T)floor
          (vipldws_B.cnt + 0.5F);
      } else {
        vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = 0;
      }

      vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = 0;
      vipldws_B.yIdx++;
    }

    /* part-3: Right vertical axis */
    if (vipldws_B.yIdx < 2) {
      vipldws_B.cnt = (real32_T)floor((vipldws_B.scale - 239.0F) * (vipldws_B.y2
        / vipldws_B.scale) + 0.5F);
      if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 199.0F)) {
        if (vipldws_B.cnt >= 0.5F) {
          vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = (int32_T)(real32_T)floor
            (vipldws_B.cnt + 0.5F);
        } else {
          vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = 0;
        }

        vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = 239;
        vipldws_B.yIdx++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (vipldws_B.yIdx < 2) {
      vipldws_B.cnt = (real32_T)floor((vipldws_B.scale - vipldws_B.scale /
        vipldws_B.y2 * 199.0F) + 0.5F);
      if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 239.0F)) {
        vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = 199;
        if (vipldws_B.cnt >= 0.5F) {
          vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = (int32_T)(real32_T)
            floor(vipldws_B.cnt + 0.5F);
        } else {
          vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = 0;
        }

        vipldws_B.yIdx++;
      }
    }

    if (vipldws_B.yIdx < 2) {
      vipldws_B.tmpOutRC_m[0U] = -1;
      vipldws_B.tmpOutRC_m[1U] = -1;
      vipldws_B.tmpOutRC_m[2U] = -1;
      vipldws_B.tmpOutRC_m[3U] = -1;
    }

    vipldws_B.HoughLines[0] = vipldws_B.tmpOutRC_m[1] + 1;
    vipldws_B.HoughLines[1] = vipldws_B.tmpOutRC_m[0] + 1;
    vipldws_B.HoughLines[2] = vipldws_B.tmpOutRC_m[3] + 1;
    vipldws_B.HoughLines[3] = vipldws_B.tmpOutRC_m[2] + 1;

    /* End of S-Function (sviphoughlines): '<S26>/Hough Lines' */

    /* Selector: '<S26>/Selector1' */
    vipldws_B.Selector1_ce[0] = vipldws_B.HoughLines[1];

    /* Math: '<S26>/Transpose' */
    vipldws_B.Transpose_g[0] = vipldws_B.Selector1_ce[0];
    vipldws_B.Switch1_b[0] = vipldws_B.Transpose_g[0];

    /* Selector: '<S26>/Selector1' */
    vipldws_B.Selector1_ce[1] = vipldws_B.HoughLines[0];

    /* Math: '<S26>/Transpose' */
    vipldws_B.Transpose_g[1] = vipldws_B.Selector1_ce[1];
    vipldws_B.Switch1_b[1] = vipldws_B.Transpose_g[1];

    /* Selector: '<S26>/Selector1' */
    vipldws_B.Selector1_ce[2] = vipldws_B.HoughLines[3];

    /* Math: '<S26>/Transpose' */
    vipldws_B.Transpose_g[2] = vipldws_B.Selector1_ce[2];
    vipldws_B.Switch1_b[2] = vipldws_B.Transpose_g[2];

    /* Selector: '<S26>/Selector1' */
    vipldws_B.Selector1_ce[3] = vipldws_B.HoughLines[2];

    /* Math: '<S26>/Transpose' */
    vipldws_B.Transpose_g[3] = vipldws_B.Selector1_ce[3];
    vipldws_B.Switch1_b[3] = vipldws_B.Transpose_g[3];
  } else {
    /* Selector: '<S29>/Selector1' */
    vipldws_B.Selector1_e[0] = vipldws_B.FindLocalMaxima1_o1_f[1];

    /* Math: '<S29>/Transpose' */
    vipldws_B.Transpose_gb[0] = vipldws_B.Selector1_e[0];

    /* Selector: '<S29>/Selector1' */
    vipldws_B.Selector1_e[1] = vipldws_B.FindLocalMaxima1_o1_f[0];

    /* Math: '<S29>/Transpose' */
    vipldws_B.Transpose_gb[1] = vipldws_B.Selector1_e[1];

    /* Selector: '<S29>/select rho4' */
    vipldws_B.Bias3_d = vipldws_B.Transpose_gb[0];

    /* Bias: '<S29>/Bias2' */
    vipldws_B.Bias3_d = (uint16_T)((uint32_T)vipldws_B.Bias3_d +
      vipldws_P.Bias2_Bias_k);

    /* Selector: '<S29>/Selector rho' */
    vipldws_B.Selectorrho_o = vipldws_B.HoughTransform_o3[vipldws_B.Bias3_d - 1];

    /* Selector: '<S29>/select rho7' */
    vipldws_B.Bias3_d = vipldws_B.Transpose_gb[1];

    /* Bias: '<S29>/Bias3' */
    vipldws_B.Bias3_d = (uint16_T)((uint32_T)vipldws_B.Bias3_d +
      vipldws_P.Bias3_Bias_c);

    /* Selector: '<S29>/Selector theta' */
    vipldws_B.Selectortheta_g = vipldws_B.HoughTransform_o2[vipldws_B.Bias3_d -
      1];

    /* S-Function (sviphoughlines): '<S26>/Hough Lines1' */
    vipldws_B.yIdx = 0;
    vipldws_B.scale = (vipldws_B.Selectorrho_o + 1.1920929E-7F) / ((real32_T)cos
      (vipldws_B.Selectortheta_g) + 1.1920929E-7F);

    /* part-1: top horizontal axis */
    vipldws_B.cnt = (real32_T)floor(vipldws_B.scale + 0.5F);
    if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 239.0F)) {
      vipldws_B.tmpOutRC_m[0U] = 0;
      if (vipldws_B.cnt >= 0.5F) {
        vipldws_B.tmpOutRC_m[1U] = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
      } else {
        vipldws_B.tmpOutRC_m[1U] = 0;
      }

      vipldws_B.yIdx = 1;
    }

    vipldws_B.y2 = (vipldws_B.Selectorrho_o + 1.1920929E-7F) / ((real32_T)sin
      (vipldws_B.Selectortheta_g) + 1.1920929E-7F);

    /* part-2: left vertical axis */
    vipldws_B.cnt = (real32_T)floor(vipldws_B.y2 + 0.5F);
    if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 199.0F)) {
      if (vipldws_B.cnt >= 0.5F) {
        vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = (int32_T)(real32_T)floor
          (vipldws_B.cnt + 0.5F);
      } else {
        vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = 0;
      }

      vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = 0;
      vipldws_B.yIdx++;
    }

    /* part-3: Right vertical axis */
    if (vipldws_B.yIdx < 2) {
      vipldws_B.cnt = (real32_T)floor((vipldws_B.scale - 239.0F) * (vipldws_B.y2
        / vipldws_B.scale) + 0.5F);
      if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 199.0F)) {
        if (vipldws_B.cnt >= 0.5F) {
          vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = (int32_T)(real32_T)floor
            (vipldws_B.cnt + 0.5F);
        } else {
          vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = 0;
        }

        vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = 239;
        vipldws_B.yIdx++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (vipldws_B.yIdx < 2) {
      vipldws_B.cnt = (real32_T)floor((vipldws_B.scale - vipldws_B.scale /
        vipldws_B.y2 * 199.0F) + 0.5F);
      if ((vipldws_B.cnt >= 0.0F) && (vipldws_B.cnt <= 239.0F)) {
        vipldws_B.tmpOutRC_m[vipldws_B.yIdx << 1] = 199;
        if (vipldws_B.cnt >= 0.5F) {
          vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = (int32_T)(real32_T)
            floor(vipldws_B.cnt + 0.5F);
        } else {
          vipldws_B.tmpOutRC_m[1 + (vipldws_B.yIdx << 1)] = 0;
        }

        vipldws_B.yIdx++;
      }
    }

    if (vipldws_B.yIdx < 2) {
      vipldws_B.tmpOutRC_m[0U] = -1;
      vipldws_B.tmpOutRC_m[1U] = -1;
      vipldws_B.tmpOutRC_m[2U] = -1;
      vipldws_B.tmpOutRC_m[3U] = -1;
    }

    vipldws_B.HoughLines1[0] = vipldws_B.tmpOutRC_m[1] + 1;
    vipldws_B.HoughLines1[1] = vipldws_B.tmpOutRC_m[0] + 1;
    vipldws_B.HoughLines1[2] = vipldws_B.tmpOutRC_m[3] + 1;
    vipldws_B.HoughLines1[3] = vipldws_B.tmpOutRC_m[2] + 1;

    /* End of S-Function (sviphoughlines): '<S26>/Hough Lines1' */

    /* Selector: '<S26>/Selector2' */
    vipldws_B.Selector2_l[0] = vipldws_B.HoughLines1[1];

    /* Math: '<S26>/Transpose1' */
    vipldws_B.Transpose1[0] = vipldws_B.Selector2_l[0];
    vipldws_B.Switch1_b[0] = vipldws_B.Transpose1[0];

    /* Selector: '<S26>/Selector2' */
    vipldws_B.Selector2_l[1] = vipldws_B.HoughLines1[0];

    /* Math: '<S26>/Transpose1' */
    vipldws_B.Transpose1[1] = vipldws_B.Selector2_l[1];
    vipldws_B.Switch1_b[1] = vipldws_B.Transpose1[1];

    /* Selector: '<S26>/Selector2' */
    vipldws_B.Selector2_l[2] = vipldws_B.HoughLines1[3];

    /* Math: '<S26>/Transpose1' */
    vipldws_B.Transpose1[2] = vipldws_B.Selector2_l[2];
    vipldws_B.Switch1_b[2] = vipldws_B.Transpose1[2];

    /* Selector: '<S26>/Selector2' */
    vipldws_B.Selector2_l[3] = vipldws_B.HoughLines1[2];

    /* Math: '<S26>/Transpose1' */
    vipldws_B.Transpose1[3] = vipldws_B.Selector2_l[3];
    vipldws_B.Switch1_b[3] = vipldws_B.Transpose1[3];
  }

  /* End of Switch: '<S5>/Switch1' */

  /* RelationalOperator: '<S60>/Compare' incorporates:
   *  Constant: '<S60>/Constant'
   */
  vipldws_B.Compare_ni = (vipldws_B.outMsg !=
    vipldws_P.CompareToConstant1_const_j);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  vipldws_B.LogicalOperator2_n = (vipldws_B.outMsg !=
    vipldws_P.CompareToConstant1_const_l);

  /* RelationalOperator: '<S6>/Relational Operator' */
  vipldws_B.LogicalOperator_b = (vipldws_B.Intersectionwithbottomimageboun <=
    vipldws_B.Widthoftheimage[1]);

  /* RelationalOperator: '<S6>/Relational Operator1' */
  vipldws_B.RelationalOperator1 = (vipldws_B.Intersectionwithbottomimagebo_g <
    vipldws_B.Widthoftheimage[1]);

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.LogicalOperator_b) {
    vipldws_B.MatrixConcatenation5[0] =
      vipldws_B.Intersectionwithbottomimagebo_o[0];
  } else {
    vipldws_B.MatrixConcatenation5[0] = vipldws_P.DrawLines4_Value[0];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.RelationalOperator1) {
    vipldws_B.MatrixConcatenation5[4] =
      vipldws_B.Intersectionwithbottomimagebo_c[0];
  } else {
    vipldws_B.MatrixConcatenation5[4] = vipldws_P.DrawLines4_Value[0];
  }

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.LogicalOperator_b) {
    vipldws_B.MatrixConcatenation5[1] =
      vipldws_B.Intersectionwithbottomimagebo_o[1];
  } else {
    vipldws_B.MatrixConcatenation5[1] = vipldws_P.DrawLines4_Value[1];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.RelationalOperator1) {
    vipldws_B.MatrixConcatenation5[5] =
      vipldws_B.Intersectionwithbottomimagebo_c[1];
  } else {
    vipldws_B.MatrixConcatenation5[5] = vipldws_P.DrawLines4_Value[1];
  }

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.LogicalOperator_b) {
    vipldws_B.MatrixConcatenation5[2] =
      vipldws_B.Intersectionwithbottomimagebo_o[2];
  } else {
    vipldws_B.MatrixConcatenation5[2] = vipldws_P.DrawLines4_Value[2];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.RelationalOperator1) {
    vipldws_B.MatrixConcatenation5[6] =
      vipldws_B.Intersectionwithbottomimagebo_c[2];
  } else {
    vipldws_B.MatrixConcatenation5[6] = vipldws_P.DrawLines4_Value[2];
  }

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.LogicalOperator_b) {
    vipldws_B.MatrixConcatenation5[3] =
      vipldws_B.Intersectionwithbottomimagebo_o[3];
  } else {
    vipldws_B.MatrixConcatenation5[3] = vipldws_P.DrawLines4_Value[3];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws_B.RelationalOperator1) {
    vipldws_B.MatrixConcatenation5[7] =
      vipldws_B.Intersectionwithbottomimagebo_c[3];
  } else {
    vipldws_B.MatrixConcatenation5[7] = vipldws_P.DrawLines4_Value[3];
  }

  /* Selector: '<S2>/Selector' */
  for (vipldws_B.i = 0; vipldws_B.i < 3; vipldws_B.i++) {
    for (vipldws_B.countPeak = 0; vipldws_B.countPeak < 240; vipldws_B.countPeak
         ++) {
      memcpy(&vipldws_B.Selector_a[vipldws_B.i * 28800 + vipldws_B.countPeak *
             120], &vipldws_B.ImageDataTypeConversion[(vipldws_B.i * 76800 +
              vipldws_B.countPeak * 320) + 120], 120U * sizeof(real32_T));
    }
  }

  /* End of Selector: '<S2>/Selector' */

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion1' */
  for (vipldws_B.i = 0; vipldws_B.i < 28800; vipldws_B.i++) {
    vipldws_B.ColorSpaceConversion1[vipldws_B.i] =
      ((vipldws_B.Selector_a[vipldws_B.i] * 0.256788224F + 0.0627451F) +
       vipldws_B.Selector_a[28800 + vipldws_B.i] * 0.50412941F) +
      vipldws_B.Selector_a[57600 + vipldws_B.i] * 0.0979058817F;
    vipldws_B.ColorSpaceConversion1[28800 + vipldws_B.i] =
      ((vipldws_B.Selector_a[vipldws_B.i] * -0.148222893F + 0.501960814F) +
       vipldws_B.Selector_a[28800 + vipldws_B.i] * -0.290992796F) +
      vipldws_B.Selector_a[57600 + vipldws_B.i] * 0.43921569F;
    vipldws_B.ColorSpaceConversion1[57600 + vipldws_B.i] =
      ((vipldws_B.Selector_a[vipldws_B.i] * 0.43921569F + 0.501960814F) +
       vipldws_B.Selector_a[28800 + vipldws_B.i] * -0.367788315F) +
      vipldws_B.Selector_a[57600 + vipldws_B.i] * -0.0714273751F;
  }

  /* End of S-Function (svipcolorconv): '<S2>/Color Space  Conversion1' */

  /* MATLAB Function: '<S6>/DetectColorAndType1' */
  /*  Detects if the lane detected is Yellow/White and Solid/Broken */
  /*  twoLines_0b =  coordinate points of lines (0 based) */
  /* MATLAB Function 'Departure Warning/Departure detection/DetectColorAndType1': '<S13>:1' */
  /*  Here, for a line with start point (r1,c1) and end point (r2,c2), */
  /*  we form a ROI with points:  */
  /*  (r1,c1-HALF_OFFSET) (r1,c1+HALF_OFFSET)  */
  /*  (r2,c2-HALF_OFFSET) (r2,c2+HALF_OFFSET)  */
  /*  We search for yellow/white color within this ROI  */
  /* '<S13>:1:12' INVALID_COLOR = int8(0); */
  /* '<S13>:1:13' WHITE_COLOR   = int8(1); */
  /* '<S13>:1:14' YELLOW_COLOR  = int8(2); */
  /* '<S13>:1:16' INVALID_MARKING = int8(0); */
  /* '<S13>:1:17' BROKEN_MARKING  = int8(1); */
  /* '<S13>:1:18' SOLID_MARKING   = int8(2); */
  /* '<S13>:1:20' INVALID_COLOR_OR_TYPE = int8(0); */
  /*  color=yellow/white; type=broken or solid */
  /* '<S13>:1:21' YELLOW_BROKEN  = int8(1); */
  /* '<S13>:1:22' YELLOW_SOLID   = int8(2); */
  /* '<S13>:1:23' WHITE_BROKEN   = int8(3); */
  /* '<S13>:1:24' WHITE_SOLID    = int8(4); */
  /* '<S13>:1:26' lineColorIdx    = int8([0 0]); */
  /* '<S13>:1:27' solidBrokenIdx  = int8([0 0]); */
  /* '<S13>:1:28' colorAndTypeIdx = int8([0 0]); */
  vipldws_B.colorAndTypeIdx[0] = 0;
  vipldws_B.colorAndTypeIdx[1] = 0;

  /* '<S13>:1:29' HALF_OFFSET =  int32(10); */
  /* '<S13>:1:31' zeroI32 = int32(0); */
  /* '<S13>:1:32' oneI32  = int32(1); */
  /* '<S13>:1:33' twoI32  = int32(2); */
  /* '<S13>:1:35' rH = int32(size(YCbCr(:,:,1),1)); */
  /* '<S13>:1:36' cW = int32(size(YCbCr(:,:,1),2)); */
  /* '<S13>:1:38' tmpInImage_Y  = YCbCr(:,:,1); */
  /* '<S13>:1:39' tmpInImage_Cb = YCbCr(:,:,2); */
  /* '<S13>:1:41' leftC  = int32(zeros(rH,1)); */
  /* '<S13>:1:42' rightC = int32(zeros(rH,1)); */
  /* '<S13>:1:43' Rs     = int32(zeros(rH,1)); */
  memset(&vipldws_B.leftC[0], 0, 120U * sizeof(int32_T));
  memset(&vipldws_B.rightC[0], 0, 120U * sizeof(int32_T));
  memset(&vipldws_B.Rs[0], 0, 120U * sizeof(int32_T));

  /* twoLines_1b = twoLines_0b+int32(1); */
  /* '<S13>:1:46' twoLines_1b = twoLines_0b; */
  /* '<S13>:1:47' for i=oneI32:int32(length(twoLines_1b(:))) */
  for (vipldws_B.yIdx = 0; vipldws_B.yIdx < 8; vipldws_B.yIdx++) {
    /* '<S13>:1:48' twoLines_1b(i) = twoLines_1b(i) + oneI32; */
    if (vipldws_B.MatrixConcatenation5[vipldws_B.yIdx] > 2147483646) {
      vipldws_B.twoLines_1b[vipldws_B.yIdx] = MAX_int32_T;
    } else {
      vipldws_B.twoLines_1b[vipldws_B.yIdx] =
        vipldws_B.MatrixConcatenation5[vipldws_B.yIdx] + 1;
    }
  }

  /* '<S13>:1:51' for lineIdx =oneI32:twoI32 */
  /* 1:2 */
  /*     %% one line */
  /* '<S13>:1:53' r1c1r2c2 = twoLines_1b(:,lineIdx); */
  /* '<S13>:1:54' r1 = r1c1r2c2(1); */
  vipldws_B.r1 = vipldws_B.twoLines_1b[0];

  /* '<S13>:1:55' c1 = r1c1r2c2(2); */
  vipldws_B.c1 = vipldws_B.twoLines_1b[1];

  /* '<S13>:1:56' r2 = r1c1r2c2(3); */
  vipldws_B.r2 = vipldws_B.twoLines_1b[2];

  /* '<S13>:1:57' c2 = r1c1r2c2(4); */
  vipldws_B.c2 = vipldws_B.twoLines_1b[3];

  /*  make sure r1 is the min (r1,r2) */
  /* '<S13>:1:60' if r1>r2 */
  if (vipldws_B.twoLines_1b[0] > vipldws_B.twoLines_1b[2]) {
    /* '<S13>:1:61' tmp=r2; */
    /* '<S13>:1:62' r2=r1; */
    vipldws_B.r2 = vipldws_B.twoLines_1b[0];

    /* '<S13>:1:63' r1=tmp; */
    vipldws_B.r1 = vipldws_B.twoLines_1b[2];

    /* '<S13>:1:65' tmp=c2; */
    /* '<S13>:1:66' c2=c1; */
    vipldws_B.c2 = vipldws_B.twoLines_1b[1];

    /* '<S13>:1:67' c1=tmp; */
    vipldws_B.c1 = vipldws_B.twoLines_1b[3];
  }

  /* '<S13>:1:70' pointNotLine = (r1==r2) && (c1==c2); */
  /*  find if line is within image: (r1,c1)  and (r2,c2) must be within image */
  /* '<S13>:1:73' if ((r1>zeroI32 && r1 <= rH) && (c1>zeroI32 && c1 <= cW) && ... */
  /* '<S13>:1:74'         (r2>zeroI32 && r2 <= rH) && (c2>zeroI32 && c2 <= cW)) && ~pointNotLine */
  if (!((vipldws_B.r1 > 0) && (vipldws_B.r1 <= 120) && (vipldws_B.c1 > 0) &&
        (vipldws_B.c1 <= 240) && (vipldws_B.r2 > 0) && (vipldws_B.r2 <= 120) &&
        (vipldws_B.c2 > 0) && (vipldws_B.c2 <= 240) && (!((vipldws_B.r1 ==
          vipldws_B.r2) && (vipldws_B.c1 == vipldws_B.c2))))) {
    /* '<S13>:1:76' else */
    /* '<S13>:1:77' line_within_image = logical(false); */
    done = false;
  } else {
    /* '<S13>:1:75' line_within_image = logical(true); */
  }

  /* '<S13>:1:80' if (line_within_image) */
  if (done) {
    /* '<S13>:1:81' len = r2-r1+oneI32; */
    if ((vipldws_B.r2 >= 0) && (vipldws_B.r1 < vipldws_B.r2 - MAX_int32_T)) {
      vipldws_B.qY_g = MAX_int32_T;
    } else if ((vipldws_B.r2 < 0) && (vipldws_B.r1 > vipldws_B.r2 - MIN_int32_T))
    {
      vipldws_B.qY_g = MIN_int32_T;
    } else {
      vipldws_B.qY_g = vipldws_B.r2 - vipldws_B.r1;
    }

    if (vipldws_B.qY_g > 2147483646) {
      vipldws_B.qY_g = MAX_int32_T;
    } else {
      vipldws_B.qY_g++;
    }

    /* '<S13>:1:82' i=oneI32; */
    vipldws_B.i = 1;

    /*  Rs(1:len)=r1:r2 */
    /* '<S13>:1:84' for p=r1:r2 */
    while (vipldws_B.r1 <= vipldws_B.r2) {
      /* '<S13>:1:85' Rs(i) = p; */
      vipldws_B.Rs[vipldws_B.i - 1] = vipldws_B.r1;

      /* '<S13>:1:86' i=i+oneI32; */
      if (vipldws_B.i > 2147483646) {
        vipldws_B.i = MAX_int32_T;
      } else {
        vipldws_B.i++;
      }

      vipldws_B.r1++;
    }

    /* leftC(1:len) = int32(linspace(c1-HALF_OFFSET, c2-HALF_OFFSET, len)); */
    /* y = linspace(d1, d2, n) */
    /* y = [d1+(0:n-2)*(d2-d1)/(floor(n)-1) d2]; */
    /* '<S13>:1:92' quotient = (single(c2-c1))/(single(len)-single(1) + single(eps)); */
    if ((vipldws_B.c2 >= 0) && (vipldws_B.c1 < vipldws_B.c2 - MAX_int32_T)) {
      vipldws_B.c2 = MAX_int32_T;
    } else if ((vipldws_B.c2 < 0) && (vipldws_B.c1 > vipldws_B.c2 - MIN_int32_T))
    {
      vipldws_B.c2 = MIN_int32_T;
    } else {
      vipldws_B.c2 -= vipldws_B.c1;
    }

    vipldws_B.scale = (real32_T)vipldws_B.c2 / (((real32_T)vipldws_B.qY_g - 1.0F)
      + 2.22044605E-16F);

    /* (d2-d1)/(floor(n)-1) */
    /* '<S13>:1:93' for i=oneI32:len */
    vipldws_B.i = 0;
    while (vipldws_B.i + 1 <= vipldws_B.qY_g) {
      /* '<S13>:1:94' leftC(i)  = (c1-HALF_OFFSET) + int32((single(i)-single(1))*quotient); */
      if (vipldws_B.c1 < -2147483638) {
        vipldws_B.qY = MIN_int32_T;
      } else {
        vipldws_B.qY = vipldws_B.c1 - 10;
      }

      vipldws_B.cnt = rt_roundf_snf(((real32_T)(vipldws_B.i + 1) - 1.0F) *
        vipldws_B.scale);
      if (vipldws_B.cnt < 2.14748365E+9F) {
        if (vipldws_B.cnt >= -2.14748365E+9F) {
          vipldws_B.countPeak = (int32_T)vipldws_B.cnt;
        } else {
          vipldws_B.countPeak = MIN_int32_T;
        }
      } else if (vipldws_B.cnt >= 2.14748365E+9F) {
        vipldws_B.countPeak = MAX_int32_T;
      } else {
        vipldws_B.countPeak = 0;
      }

      if ((vipldws_B.qY < 0) && (vipldws_B.countPeak < MIN_int32_T
           - vipldws_B.qY)) {
        vipldws_B.leftC[vipldws_B.i] = MIN_int32_T;
      } else if ((vipldws_B.qY > 0) && (vipldws_B.countPeak > MAX_int32_T
                  - vipldws_B.qY)) {
        vipldws_B.leftC[vipldws_B.i] = MAX_int32_T;
      } else {
        vipldws_B.leftC[vipldws_B.i] = vipldws_B.qY + vipldws_B.countPeak;
      }

      /* '<S13>:1:95' rightC(i) = leftC(i)+ twoI32*HALF_OFFSET; */
      if (vipldws_B.leftC[vipldws_B.i] > 2147483627) {
        vipldws_B.rightC[vipldws_B.i] = MAX_int32_T;
      } else {
        vipldws_B.rightC[vipldws_B.i] = vipldws_B.leftC[vipldws_B.i] + 20;
      }

      /* '<S13>:1:96' if leftC(i) < oneI32 */
      if (vipldws_B.leftC[vipldws_B.i] < 1) {
        /* '<S13>:1:97' leftC(i) = oneI32; */
        vipldws_B.leftC[vipldws_B.i] = 1;

        /* '<S13>:1:98' if rightC(i) < oneI32 */
        if (vipldws_B.rightC[vipldws_B.i] < 1) {
          /* '<S13>:1:99' rightC(i) = oneI32; */
          vipldws_B.rightC[vipldws_B.i] = 1;
        }
      }

      /* '<S13>:1:102' if rightC(i) > cW */
      if (vipldws_B.rightC[vipldws_B.i] > 240) {
        /* '<S13>:1:103' rightC(i) = cW; */
        vipldws_B.rightC[vipldws_B.i] = 240;
      }

      vipldws_B.i++;
    }

    /* '<S13>:1:107' whiteCount  = zeroI32; */
    vipldws_B.i = 0;

    /* '<S13>:1:108' yellowCount = zeroI32; */
    vipldws_B.C1 = 0;

    /* '<S13>:1:109' grayCount   = zeroI32; */
    vipldws_B.R2 = 0;

    /* '<S13>:1:111' SumOfGotAlLeastOneWhitePixelInTheRow  = zeroI32; */
    vipldws_B.C2 = 0;

    /* '<S13>:1:112' SumOfGotAlLeastOneYellowPixelInTheRow = zeroI32; */
    vipldws_B.c2 = 0;

    /* '<S13>:1:114' for i=oneI32:len */
    vipldws_B.c1 = 0;
    while (vipldws_B.c1 + 1 <= vipldws_B.qY_g) {
      /* '<S13>:1:115' gotAlLeastOneWhitePixelInTheRow  = logical(false); */
      done = false;

      /* '<S13>:1:116' gotAlLeastOneYellowPixelInTheRow = logical(false); */
      c_gotAlLeastOneYellowPixelInThe = false;

      /* '<S13>:1:117' for cv = leftC(i):rightC(i) */
      vipldws_B.r2 = vipldws_B.leftC[vipldws_B.c1] - 1;
      while (vipldws_B.r2 + 1 <= vipldws_B.rightC[vipldws_B.c1]) {
        /* '<S13>:1:119' if tmpInImage_Y(Rs(i), cv) >= single(175/255) */
        if (vipldws_B.ColorSpaceConversion1[(120 * vipldws_B.r2 +
             vipldws_B.Rs[vipldws_B.c1]) - 1] >= 0.686274529F) {
          /* '<S13>:1:120' whiteCount = whiteCount+oneI32; */
          if (vipldws_B.i > 2147483646) {
            vipldws_B.i = MAX_int32_T;
          } else {
            vipldws_B.i++;
          }

          /* '<S13>:1:121' gotAlLeastOneWhitePixelInTheRow = logical(true); */
          done = true;
        } else if (vipldws_B.ColorSpaceConversion1[(120 * vipldws_B.r2 +
                    vipldws_B.Rs[vipldws_B.c1]) + 28799] >= 0.352941185F) {
          if (vipldws_B.ColorSpaceConversion1[(120 * vipldws_B.r2 +
               vipldws_B.Rs[vipldws_B.c1]) + 28799] <= 0.498039216F) {
            /* '<S13>:1:122' elseif tmpInImage_Cb(Rs(i), cv) >= single(90/255) && tmpInImage_Cb(Rs(i), cv) <= single(127/255) */
            /* '<S13>:1:123' yellowCount = yellowCount+oneI32; */
            if (vipldws_B.C1 > 2147483646) {
              vipldws_B.C1 = MAX_int32_T;
            } else {
              vipldws_B.C1++;
            }

            /* '<S13>:1:124' gotAlLeastOneYellowPixelInTheRow = logical(true); */
            c_gotAlLeastOneYellowPixelInThe = true;
          } else {
            /* '<S13>:1:125' else */
            /* '<S13>:1:126' grayCount = grayCount+oneI32; */
            if (vipldws_B.R2 > 2147483646) {
              vipldws_B.R2 = MAX_int32_T;
            } else {
              vipldws_B.R2++;
            }
          }
        } else {
          /* '<S13>:1:125' else */
          /* '<S13>:1:126' grayCount = grayCount+oneI32; */
          if (vipldws_B.R2 > 2147483646) {
            vipldws_B.R2 = MAX_int32_T;
          } else {
            vipldws_B.R2++;
          }
        }

        vipldws_B.r2++;
      }

      /* '<S13>:1:129' if gotAlLeastOneWhitePixelInTheRow */
      if (done) {
        /* '<S13>:1:130' SumOfGotAlLeastOneWhitePixelInTheRow = SumOfGotAlLeastOneWhitePixelInTheRow+oneI32; */
        if (vipldws_B.C2 > 2147483646) {
          vipldws_B.C2 = MAX_int32_T;
        } else {
          vipldws_B.C2++;
        }
      }

      /* '<S13>:1:132' if gotAlLeastOneYellowPixelInTheRow */
      if (c_gotAlLeastOneYellowPixelInThe) {
        /* '<S13>:1:133' SumOfGotAlLeastOneYellowPixelInTheRow = SumOfGotAlLeastOneYellowPixelInTheRow+oneI32; */
        if (vipldws_B.c2 > 2147483646) {
          vipldws_B.c2 = MAX_int32_T;
        } else {
          vipldws_B.c2++;
        }
      }

      vipldws_B.c1++;
    }

    /* '<S13>:1:137' yellowVsTotal = single(yellowCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:138' whiteVsTotal  = single(whiteCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:140' if yellowVsTotal > whiteVsTotal */
    if ((vipldws_B.R2 < 0) && (vipldws_B.C1 < MIN_int32_T - vipldws_B.R2)) {
      vipldws_B.qY = MIN_int32_T;
      vipldws_B.c1 = MIN_int32_T;
    } else if ((vipldws_B.R2 > 0) && (vipldws_B.C1 > MAX_int32_T - vipldws_B.R2))
    {
      vipldws_B.qY = MAX_int32_T;
      vipldws_B.c1 = MAX_int32_T;
    } else {
      vipldws_B.qY = vipldws_B.R2 + vipldws_B.C1;
      vipldws_B.c1 = vipldws_B.R2 + vipldws_B.C1;
    }

    if ((vipldws_B.qY < 0) && (vipldws_B.i < MIN_int32_T - vipldws_B.qY)) {
      vipldws_B.qY = MIN_int32_T;
    } else if ((vipldws_B.qY > 0) && (vipldws_B.i > MAX_int32_T - vipldws_B.qY))
    {
      vipldws_B.qY = MAX_int32_T;
    } else {
      vipldws_B.qY += vipldws_B.i;
    }

    if ((vipldws_B.c1 < 0) && (vipldws_B.i < MIN_int32_T - vipldws_B.c1)) {
      vipldws_B.c1 = MIN_int32_T;
    } else if ((vipldws_B.c1 > 0) && (vipldws_B.i > MAX_int32_T - vipldws_B.c1))
    {
      vipldws_B.c1 = MAX_int32_T;
    } else {
      vipldws_B.c1 += vipldws_B.i;
    }

    if ((real32_T)vipldws_B.C1 / (real32_T)vipldws_B.qY > (real32_T)vipldws_B.i /
        (real32_T)vipldws_B.c1) {
      /* '<S13>:1:141' lineColorIdx(lineIdx) = YELLOW_COLOR; */
      lineColorIdx_idx_0 = 2;

      /* '<S13>:1:142' linearPixelRatio = single(SumOfGotAlLeastOneYellowPixelInTheRow)/single(len); */
      vipldws_B.scale = (real32_T)vipldws_B.c2 / (real32_T)vipldws_B.qY_g;
    } else {
      /* '<S13>:1:143' else */
      /* '<S13>:1:144' lineColorIdx(lineIdx) = WHITE_COLOR; */
      lineColorIdx_idx_0 = 1;

      /* '<S13>:1:145' linearPixelRatio = single(SumOfGotAlLeastOneWhitePixelInTheRow)/single(len); */
      vipldws_B.scale = (real32_T)vipldws_B.C2 / (real32_T)vipldws_B.qY_g;
    }

    /*         %% distinguish solid and broken lane markers */
    /*  if we use yellowVsTotal(==whiteVsTotal) to find marker type (solid/broken) */
    /*  it would not give accurate result; because in the patch we are searching  */
    /*  for yellow/white pixel- we do not know what's the pecentage of gray pixels  */
    /*  are there */
    /*  that's why we are considering a different method; here we try to find one */
    /*  yellow (==white) pixel in one row; once we find a yellow (==white) pixel */
    /*  in the row we don't need to find anything in that row of the patch (ROI) */
    /* '<S13>:1:157' if linearPixelRatio > single(0.8) */
    if (vipldws_B.scale > 0.8F) {
      /* '<S13>:1:158' solidBrokenIdx(lineIdx) = SOLID_MARKING; */
      solidBrokenIdx_idx_0 = 2;
    } else {
      /* '<S13>:1:159' else */
      /* '<S13>:1:160' solidBrokenIdx(lineIdx) = BROKEN_MARKING; */
      solidBrokenIdx_idx_0 = 1;
    }

    /* '<S13>:1:163' if (lineColorIdx(lineIdx) == YELLOW_COLOR) && (solidBrokenIdx(lineIdx) == BROKEN_MARKING) */
    if ((lineColorIdx_idx_0 == 2) && (solidBrokenIdx_idx_0 == 1)) {
      /* '<S13>:1:164' colorAndTypeIdx(lineIdx) = YELLOW_BROKEN; */
      vipldws_B.colorAndTypeIdx[0] = 1;
    } else if ((lineColorIdx_idx_0 == 2) && (solidBrokenIdx_idx_0 == 2)) {
      /* '<S13>:1:165' elseif (lineColorIdx(lineIdx) == YELLOW_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
      /* '<S13>:1:166' colorAndTypeIdx(lineIdx) = YELLOW_SOLID; */
      vipldws_B.colorAndTypeIdx[0] = 2;
    } else if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 1)) {
      /* '<S13>:1:167' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == BROKEN_MARKING) */
      /* '<S13>:1:168' colorAndTypeIdx(lineIdx) = WHITE_BROKEN; */
      vipldws_B.colorAndTypeIdx[0] = 3;
    } else {
      if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 2)) {
        /* '<S13>:1:169' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
        /* '<S13>:1:170' colorAndTypeIdx(lineIdx) = WHITE_SOLID; */
        vipldws_B.colorAndTypeIdx[0] = 4;
      }
    }
  } else {
    /* '<S13>:1:173' else */
    /* '<S13>:1:174' lineColorIdx(lineIdx) = INVALID_COLOR; */
    /* '<S13>:1:175' solidBrokenIdx(lineIdx) = INVALID_MARKING; */
    /* '<S13>:1:176' colorAndTypeIdx(lineIdx) = INVALID_COLOR_OR_TYPE; */
    vipldws_B.colorAndTypeIdx[0] = 0;
  }

  /* 1:2 */
  /*     %% one line */
  /* '<S13>:1:53' r1c1r2c2 = twoLines_1b(:,lineIdx); */
  /* '<S13>:1:54' r1 = r1c1r2c2(1); */
  vipldws_B.r1 = vipldws_B.twoLines_1b[4];

  /* '<S13>:1:55' c1 = r1c1r2c2(2); */
  vipldws_B.c1 = vipldws_B.twoLines_1b[5];

  /* '<S13>:1:56' r2 = r1c1r2c2(3); */
  vipldws_B.r2 = vipldws_B.twoLines_1b[6];

  /* '<S13>:1:57' c2 = r1c1r2c2(4); */
  vipldws_B.c2 = vipldws_B.twoLines_1b[7];

  /*  make sure r1 is the min (r1,r2) */
  /* '<S13>:1:60' if r1>r2 */
  if (vipldws_B.twoLines_1b[4] > vipldws_B.twoLines_1b[6]) {
    /* '<S13>:1:61' tmp=r2; */
    /* '<S13>:1:62' r2=r1; */
    vipldws_B.r2 = vipldws_B.twoLines_1b[4];

    /* '<S13>:1:63' r1=tmp; */
    vipldws_B.r1 = vipldws_B.twoLines_1b[6];

    /* '<S13>:1:65' tmp=c2; */
    /* '<S13>:1:66' c2=c1; */
    vipldws_B.c2 = vipldws_B.twoLines_1b[5];

    /* '<S13>:1:67' c1=tmp; */
    vipldws_B.c1 = vipldws_B.twoLines_1b[7];
  }

  /* '<S13>:1:70' pointNotLine = (r1==r2) && (c1==c2); */
  /*  find if line is within image: (r1,c1)  and (r2,c2) must be within image */
  /* '<S13>:1:73' if ((r1>zeroI32 && r1 <= rH) && (c1>zeroI32 && c1 <= cW) && ... */
  /* '<S13>:1:74'         (r2>zeroI32 && r2 <= rH) && (c2>zeroI32 && c2 <= cW)) && ~pointNotLine */
  if ((vipldws_B.r1 > 0) && (vipldws_B.r1 <= 120) && (vipldws_B.c1 > 0) &&
      (vipldws_B.c1 <= 240) && (vipldws_B.r2 > 0) && (vipldws_B.r2 <= 120) &&
      (vipldws_B.c2 > 0) && (vipldws_B.c2 <= 240) && (!((vipldws_B.r1 ==
         vipldws_B.r2) && (vipldws_B.c1 == vipldws_B.c2)))) {
    /* '<S13>:1:75' line_within_image = logical(true); */
    done = true;
  } else {
    /* '<S13>:1:76' else */
    /* '<S13>:1:77' line_within_image = logical(false); */
    done = false;
  }

  /* '<S13>:1:80' if (line_within_image) */
  if (done) {
    /* '<S13>:1:81' len = r2-r1+oneI32; */
    if ((vipldws_B.r2 >= 0) && (vipldws_B.r1 < vipldws_B.r2 - MAX_int32_T)) {
      vipldws_B.qY_g = MAX_int32_T;
    } else if ((vipldws_B.r2 < 0) && (vipldws_B.r1 > vipldws_B.r2 - MIN_int32_T))
    {
      vipldws_B.qY_g = MIN_int32_T;
    } else {
      vipldws_B.qY_g = vipldws_B.r2 - vipldws_B.r1;
    }

    if (vipldws_B.qY_g > 2147483646) {
      vipldws_B.qY_g = MAX_int32_T;
    } else {
      vipldws_B.qY_g++;
    }

    /* '<S13>:1:82' i=oneI32; */
    vipldws_B.i = 1;

    /*  Rs(1:len)=r1:r2 */
    /* '<S13>:1:84' for p=r1:r2 */
    while (vipldws_B.r1 <= vipldws_B.r2) {
      /* '<S13>:1:85' Rs(i) = p; */
      vipldws_B.Rs[vipldws_B.i - 1] = vipldws_B.r1;

      /* '<S13>:1:86' i=i+oneI32; */
      if (vipldws_B.i > 2147483646) {
        vipldws_B.i = MAX_int32_T;
      } else {
        vipldws_B.i++;
      }

      vipldws_B.r1++;
    }

    /* leftC(1:len) = int32(linspace(c1-HALF_OFFSET, c2-HALF_OFFSET, len)); */
    /* y = linspace(d1, d2, n) */
    /* y = [d1+(0:n-2)*(d2-d1)/(floor(n)-1) d2]; */
    /* '<S13>:1:92' quotient = (single(c2-c1))/(single(len)-single(1) + single(eps)); */
    if ((vipldws_B.c2 >= 0) && (vipldws_B.c1 < vipldws_B.c2 - MAX_int32_T)) {
      vipldws_B.c2 = MAX_int32_T;
    } else if ((vipldws_B.c2 < 0) && (vipldws_B.c1 > vipldws_B.c2 - MIN_int32_T))
    {
      vipldws_B.c2 = MIN_int32_T;
    } else {
      vipldws_B.c2 -= vipldws_B.c1;
    }

    vipldws_B.scale = (real32_T)vipldws_B.c2 / (((real32_T)vipldws_B.qY_g - 1.0F)
      + 2.22044605E-16F);

    /* (d2-d1)/(floor(n)-1) */
    /* '<S13>:1:93' for i=oneI32:len */
    vipldws_B.i = 0;
    while (vipldws_B.i + 1 <= vipldws_B.qY_g) {
      /* '<S13>:1:94' leftC(i)  = (c1-HALF_OFFSET) + int32((single(i)-single(1))*quotient); */
      if (vipldws_B.c1 < -2147483638) {
        vipldws_B.qY = MIN_int32_T;
      } else {
        vipldws_B.qY = vipldws_B.c1 - 10;
      }

      vipldws_B.cnt = rt_roundf_snf(((real32_T)(vipldws_B.i + 1) - 1.0F) *
        vipldws_B.scale);
      if (vipldws_B.cnt < 2.14748365E+9F) {
        if (vipldws_B.cnt >= -2.14748365E+9F) {
          vipldws_B.countPeak = (int32_T)vipldws_B.cnt;
        } else {
          vipldws_B.countPeak = MIN_int32_T;
        }
      } else if (vipldws_B.cnt >= 2.14748365E+9F) {
        vipldws_B.countPeak = MAX_int32_T;
      } else {
        vipldws_B.countPeak = 0;
      }

      if ((vipldws_B.qY < 0) && (vipldws_B.countPeak < MIN_int32_T
           - vipldws_B.qY)) {
        vipldws_B.leftC[vipldws_B.i] = MIN_int32_T;
      } else if ((vipldws_B.qY > 0) && (vipldws_B.countPeak > MAX_int32_T
                  - vipldws_B.qY)) {
        vipldws_B.leftC[vipldws_B.i] = MAX_int32_T;
      } else {
        vipldws_B.leftC[vipldws_B.i] = vipldws_B.qY + vipldws_B.countPeak;
      }

      /* '<S13>:1:95' rightC(i) = leftC(i)+ twoI32*HALF_OFFSET; */
      if (vipldws_B.leftC[vipldws_B.i] > 2147483627) {
        vipldws_B.rightC[vipldws_B.i] = MAX_int32_T;
      } else {
        vipldws_B.rightC[vipldws_B.i] = vipldws_B.leftC[vipldws_B.i] + 20;
      }

      /* '<S13>:1:96' if leftC(i) < oneI32 */
      if (vipldws_B.leftC[vipldws_B.i] < 1) {
        /* '<S13>:1:97' leftC(i) = oneI32; */
        vipldws_B.leftC[vipldws_B.i] = 1;

        /* '<S13>:1:98' if rightC(i) < oneI32 */
        if (vipldws_B.rightC[vipldws_B.i] < 1) {
          /* '<S13>:1:99' rightC(i) = oneI32; */
          vipldws_B.rightC[vipldws_B.i] = 1;
        }
      }

      /* '<S13>:1:102' if rightC(i) > cW */
      if (vipldws_B.rightC[vipldws_B.i] > 240) {
        /* '<S13>:1:103' rightC(i) = cW; */
        vipldws_B.rightC[vipldws_B.i] = 240;
      }

      vipldws_B.i++;
    }

    /* '<S13>:1:107' whiteCount  = zeroI32; */
    vipldws_B.i = 0;

    /* '<S13>:1:108' yellowCount = zeroI32; */
    vipldws_B.C1 = 0;

    /* '<S13>:1:109' grayCount   = zeroI32; */
    vipldws_B.R2 = 0;

    /* '<S13>:1:111' SumOfGotAlLeastOneWhitePixelInTheRow  = zeroI32; */
    vipldws_B.C2 = 0;

    /* '<S13>:1:112' SumOfGotAlLeastOneYellowPixelInTheRow = zeroI32; */
    vipldws_B.c2 = 0;

    /* '<S13>:1:114' for i=oneI32:len */
    vipldws_B.c1 = 0;
    while (vipldws_B.c1 + 1 <= vipldws_B.qY_g) {
      /* '<S13>:1:115' gotAlLeastOneWhitePixelInTheRow  = logical(false); */
      done = false;

      /* '<S13>:1:116' gotAlLeastOneYellowPixelInTheRow = logical(false); */
      c_gotAlLeastOneYellowPixelInThe = false;

      /* '<S13>:1:117' for cv = leftC(i):rightC(i) */
      vipldws_B.r2 = vipldws_B.leftC[vipldws_B.c1] - 1;
      while (vipldws_B.r2 + 1 <= vipldws_B.rightC[vipldws_B.c1]) {
        /* '<S13>:1:119' if tmpInImage_Y(Rs(i), cv) >= single(175/255) */
        if (vipldws_B.ColorSpaceConversion1[(120 * vipldws_B.r2 +
             vipldws_B.Rs[vipldws_B.c1]) - 1] >= 0.686274529F) {
          /* '<S13>:1:120' whiteCount = whiteCount+oneI32; */
          if (vipldws_B.i > 2147483646) {
            vipldws_B.i = MAX_int32_T;
          } else {
            vipldws_B.i++;
          }

          /* '<S13>:1:121' gotAlLeastOneWhitePixelInTheRow = logical(true); */
          done = true;
        } else if (vipldws_B.ColorSpaceConversion1[(120 * vipldws_B.r2 +
                    vipldws_B.Rs[vipldws_B.c1]) + 28799] >= 0.352941185F) {
          if (vipldws_B.ColorSpaceConversion1[(120 * vipldws_B.r2 +
               vipldws_B.Rs[vipldws_B.c1]) + 28799] <= 0.498039216F) {
            /* '<S13>:1:122' elseif tmpInImage_Cb(Rs(i), cv) >= single(90/255) && tmpInImage_Cb(Rs(i), cv) <= single(127/255) */
            /* '<S13>:1:123' yellowCount = yellowCount+oneI32; */
            if (vipldws_B.C1 > 2147483646) {
              vipldws_B.C1 = MAX_int32_T;
            } else {
              vipldws_B.C1++;
            }

            /* '<S13>:1:124' gotAlLeastOneYellowPixelInTheRow = logical(true); */
            c_gotAlLeastOneYellowPixelInThe = true;
          } else {
            /* '<S13>:1:125' else */
            /* '<S13>:1:126' grayCount = grayCount+oneI32; */
            if (vipldws_B.R2 > 2147483646) {
              vipldws_B.R2 = MAX_int32_T;
            } else {
              vipldws_B.R2++;
            }
          }
        } else {
          /* '<S13>:1:125' else */
          /* '<S13>:1:126' grayCount = grayCount+oneI32; */
          if (vipldws_B.R2 > 2147483646) {
            vipldws_B.R2 = MAX_int32_T;
          } else {
            vipldws_B.R2++;
          }
        }

        vipldws_B.r2++;
      }

      /* '<S13>:1:129' if gotAlLeastOneWhitePixelInTheRow */
      if (done) {
        /* '<S13>:1:130' SumOfGotAlLeastOneWhitePixelInTheRow = SumOfGotAlLeastOneWhitePixelInTheRow+oneI32; */
        if (vipldws_B.C2 > 2147483646) {
          vipldws_B.C2 = MAX_int32_T;
        } else {
          vipldws_B.C2++;
        }
      }

      /* '<S13>:1:132' if gotAlLeastOneYellowPixelInTheRow */
      if (c_gotAlLeastOneYellowPixelInThe) {
        /* '<S13>:1:133' SumOfGotAlLeastOneYellowPixelInTheRow = SumOfGotAlLeastOneYellowPixelInTheRow+oneI32; */
        if (vipldws_B.c2 > 2147483646) {
          vipldws_B.c2 = MAX_int32_T;
        } else {
          vipldws_B.c2++;
        }
      }

      vipldws_B.c1++;
    }

    /* '<S13>:1:137' yellowVsTotal = single(yellowCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:138' whiteVsTotal  = single(whiteCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:140' if yellowVsTotal > whiteVsTotal */
    if ((vipldws_B.R2 < 0) && (vipldws_B.C1 < MIN_int32_T - vipldws_B.R2)) {
      vipldws_B.qY = MIN_int32_T;
      vipldws_B.c1 = MIN_int32_T;
    } else if ((vipldws_B.R2 > 0) && (vipldws_B.C1 > MAX_int32_T - vipldws_B.R2))
    {
      vipldws_B.qY = MAX_int32_T;
      vipldws_B.c1 = MAX_int32_T;
    } else {
      vipldws_B.qY = vipldws_B.R2 + vipldws_B.C1;
      vipldws_B.c1 = vipldws_B.R2 + vipldws_B.C1;
    }

    if ((vipldws_B.qY < 0) && (vipldws_B.i < MIN_int32_T - vipldws_B.qY)) {
      vipldws_B.qY = MIN_int32_T;
    } else if ((vipldws_B.qY > 0) && (vipldws_B.i > MAX_int32_T - vipldws_B.qY))
    {
      vipldws_B.qY = MAX_int32_T;
    } else {
      vipldws_B.qY += vipldws_B.i;
    }

    if ((vipldws_B.c1 < 0) && (vipldws_B.i < MIN_int32_T - vipldws_B.c1)) {
      vipldws_B.c1 = MIN_int32_T;
    } else if ((vipldws_B.c1 > 0) && (vipldws_B.i > MAX_int32_T - vipldws_B.c1))
    {
      vipldws_B.c1 = MAX_int32_T;
    } else {
      vipldws_B.c1 += vipldws_B.i;
    }

    if ((real32_T)vipldws_B.C1 / (real32_T)vipldws_B.qY > (real32_T)vipldws_B.i /
        (real32_T)vipldws_B.c1) {
      /* '<S13>:1:141' lineColorIdx(lineIdx) = YELLOW_COLOR; */
      lineColorIdx_idx_0 = 2;

      /* '<S13>:1:142' linearPixelRatio = single(SumOfGotAlLeastOneYellowPixelInTheRow)/single(len); */
      vipldws_B.scale = (real32_T)vipldws_B.c2 / (real32_T)vipldws_B.qY_g;
    } else {
      /* '<S13>:1:143' else */
      /* '<S13>:1:144' lineColorIdx(lineIdx) = WHITE_COLOR; */
      lineColorIdx_idx_0 = 1;

      /* '<S13>:1:145' linearPixelRatio = single(SumOfGotAlLeastOneWhitePixelInTheRow)/single(len); */
      vipldws_B.scale = (real32_T)vipldws_B.C2 / (real32_T)vipldws_B.qY_g;
    }

    /*         %% distinguish solid and broken lane markers */
    /*  if we use yellowVsTotal(==whiteVsTotal) to find marker type (solid/broken) */
    /*  it would not give accurate result; because in the patch we are searching  */
    /*  for yellow/white pixel- we do not know what's the pecentage of gray pixels  */
    /*  are there */
    /*  that's why we are considering a different method; here we try to find one */
    /*  yellow (==white) pixel in one row; once we find a yellow (==white) pixel */
    /*  in the row we don't need to find anything in that row of the patch (ROI) */
    /* '<S13>:1:157' if linearPixelRatio > single(0.8) */
    if (vipldws_B.scale > 0.8F) {
      /* '<S13>:1:158' solidBrokenIdx(lineIdx) = SOLID_MARKING; */
      solidBrokenIdx_idx_0 = 2;
    } else {
      /* '<S13>:1:159' else */
      /* '<S13>:1:160' solidBrokenIdx(lineIdx) = BROKEN_MARKING; */
      solidBrokenIdx_idx_0 = 1;
    }

    /* '<S13>:1:163' if (lineColorIdx(lineIdx) == YELLOW_COLOR) && (solidBrokenIdx(lineIdx) == BROKEN_MARKING) */
    if ((lineColorIdx_idx_0 == 2) && (solidBrokenIdx_idx_0 == 1)) {
      /* '<S13>:1:164' colorAndTypeIdx(lineIdx) = YELLOW_BROKEN; */
      vipldws_B.colorAndTypeIdx[1] = 1;
    } else if ((lineColorIdx_idx_0 == 2) && (solidBrokenIdx_idx_0 == 2)) {
      /* '<S13>:1:165' elseif (lineColorIdx(lineIdx) == YELLOW_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
      /* '<S13>:1:166' colorAndTypeIdx(lineIdx) = YELLOW_SOLID; */
      vipldws_B.colorAndTypeIdx[1] = 2;
    } else if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 1)) {
      /* '<S13>:1:167' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == BROKEN_MARKING) */
      /* '<S13>:1:168' colorAndTypeIdx(lineIdx) = WHITE_BROKEN; */
      vipldws_B.colorAndTypeIdx[1] = 3;
    } else {
      if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 2)) {
        /* '<S13>:1:169' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
        /* '<S13>:1:170' colorAndTypeIdx(lineIdx) = WHITE_SOLID; */
        vipldws_B.colorAndTypeIdx[1] = 4;
      }
    }
  } else {
    /* '<S13>:1:173' else */
    /* '<S13>:1:174' lineColorIdx(lineIdx) = INVALID_COLOR; */
    /* '<S13>:1:175' solidBrokenIdx(lineIdx) = INVALID_MARKING; */
    /* '<S13>:1:176' colorAndTypeIdx(lineIdx) = INVALID_COLOR_OR_TYPE; */
    vipldws_B.colorAndTypeIdx[1] = 0;
  }

  /* End of MATLAB Function: '<S6>/DetectColorAndType1' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  vipldws_B.Compare_d = (vipldws_B.outMsg ==
    vipldws_P.CompareToConstant2_const_h);

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (vipldws_B.Compare_d) {
    vipldws_B.Bias_h = vipldws_P.Constant_Value_f;
  } else {
    vipldws_B.Bias_h = vipldws_P.Constant1_Value_b;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* Selector: '<S6>/Selector' */
  vipldws_B.Bias_h = vipldws_B.colorAndTypeIdx[vipldws_B.Bias_h];

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  vipldws_B.Compare_d = (vipldws_B.Bias_h == vipldws_P.CompareToConstant_const_n);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  vipldws_B.Switch_h = (vipldws_B.Bias_h == vipldws_P.CompareToConstant3_const);

  /* Logic: '<S6>/Logical Operator4' */
  vipldws_B.LogicalOperator4 = (vipldws_B.Compare_d || vipldws_B.Switch_h);

  /* DataTypeConversion: '<S8>/Data Type  Conversion' */
  vipldws_B.Saturation_d = vipldws_B.outMsg;

  /* Selector: '<S8>/Selector' incorporates:
   *  Constant: '<S8>/Constant'
   */
  vipldws_B.Selector_h = vipldws_P.Constant_Value_j[vipldws_B.Saturation_d];

  /* Outputs for Triggered SubSystem: '<S6>/Sample and Hold' incorporates:
   *  TriggerPort: '<S15>/Trigger'
   */
  vipldws_B.zcEvent = rt_I32ZCFcn(ANY_ZERO_CROSSING,
    &vipldws_PrevZCX.SampleandHold_Trig_ZCE,
    (vipldws_B.Selector_h));
  if (vipldws_B.zcEvent != NO_ZCEVENT) {
    /* Inport: '<S15>/In' */
    vipldws_B.In = vipldws_B.LogicalOperator4;
    vipldws_DW.SampleandHold_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S6>/Sample and Hold' */

  /* Logic: '<S6>/Logical Operator2' */
  vipldws_B.LogicalOperator2_n = (vipldws_B.LogicalOperator2_n && vipldws_B.In);

  /* Logic: '<S5>/Logical Operator2' */
  vipldws_B.LogicalOperator2 = (vipldws_B.Compare_ni &&
    vipldws_B.LogicalOperator2_n);

  /* S-Function (sdspmultiportsel): '<S16>/Multiport Selector' */
  vipldws_B.MultiportSelector_o1[0] = vipldws_B.MatrixConcatenation5[0];
  vipldws_B.MultiportSelector_o1[1] = vipldws_B.MatrixConcatenation5[4];
  vipldws_B.MultiportSelector_o2[0] = vipldws_B.MatrixConcatenation5[2];
  vipldws_B.MultiportSelector_o2[1] = vipldws_B.MatrixConcatenation5[6];
  vipldws_B.MultiportSelector_o3[0] = vipldws_B.MatrixConcatenation5[1];
  vipldws_B.MultiportSelector_o3[1] = vipldws_B.MatrixConcatenation5[5];
  vipldws_B.MultiportSelector_o4[0] = vipldws_B.MatrixConcatenation5[3];

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  vipldws_B.LogicalOperator7[0] = (vipldws_B.MultiportSelector_o1[0] >=
    vipldws_P.CompareToConstant10_const);

  /* RelationalOperator: '<S16>/Relational Operator' */
  vipldws_B.LogicalOperator8[0] = (vipldws_B.MultiportSelector_o1[0] !=
    vipldws_B.MultiportSelector_o2[0]);

  /* RelationalOperator: '<S16>/Relational Operator1' */
  vipldws_B.Compare_g[0] = (vipldws_B.MultiportSelector_o3[0] !=
    vipldws_B.MultiportSelector_o4[0]);

  /* Logic: '<S16>/Logical Operator8' */
  vipldws_B.LogicalOperator8[0] = (vipldws_B.LogicalOperator8[0] ||
    vipldws_B.Compare_g[0]);

  /* Sum: '<S16>/Add' */
  vipldws_B.Bias2[0] = vipldws_B.MultiportSelector_o1[0] -
    vipldws_B.MultiportSelector_o2[0];

  /* Abs: '<S16>/Abs' */
  if (vipldws_B.Bias2[0] < 0) {
    vipldws_B.Bias2[0] = -vipldws_B.Bias2[0];
  }

  /* Sum: '<S16>/Add1' */
  vipldws_B.Transpose2[0] = vipldws_B.MultiportSelector_o3[0] -
    vipldws_B.MultiportSelector_o4[0];

  /* Abs: '<S16>/Abs1' */
  if (vipldws_B.Transpose2[0] < 0) {
    vipldws_B.Transpose2[0] = -vipldws_B.Transpose2[0];
  }

  /* Sum: '<S16>/Add2' */
  vipldws_B.Bias2[0] += vipldws_B.Transpose2[0];

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  vipldws_B.Compare_g[0] = (vipldws_B.Bias2[0] >=
    vipldws_P.CompareToConstant1_const_o);

  /* Logic: '<S16>/Logical Operator7' */
  vipldws_B.LogicalOperator7[0] = (vipldws_B.LogicalOperator7[0] &&
    vipldws_B.LogicalOperator8[0] && vipldws_B.Compare_g[0]);

  /* S-Function (sdspmultiportsel): '<S16>/Multiport Selector' */
  vipldws_B.MultiportSelector_o4[1] = vipldws_B.MatrixConcatenation5[7];

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  vipldws_B.LogicalOperator7[1] = (vipldws_B.MultiportSelector_o1[1] >=
    vipldws_P.CompareToConstant10_const);

  /* RelationalOperator: '<S16>/Relational Operator' */
  vipldws_B.LogicalOperator8[1] = (vipldws_B.MultiportSelector_o1[1] !=
    vipldws_B.MultiportSelector_o2[1]);

  /* RelationalOperator: '<S16>/Relational Operator1' */
  vipldws_B.Compare_g[1] = (vipldws_B.MultiportSelector_o3[1] !=
    vipldws_B.MultiportSelector_o4[1]);

  /* Logic: '<S16>/Logical Operator8' */
  vipldws_B.LogicalOperator8[1] = (vipldws_B.LogicalOperator8[1] ||
    vipldws_B.Compare_g[1]);

  /* Sum: '<S16>/Add' */
  vipldws_B.Bias2[1] = vipldws_B.MultiportSelector_o1[1] -
    vipldws_B.MultiportSelector_o2[1];

  /* Abs: '<S16>/Abs' */
  if (vipldws_B.Bias2[1] < 0) {
    vipldws_B.Bias2[1] = -vipldws_B.Bias2[1];
  }

  /* Sum: '<S16>/Add1' */
  vipldws_B.Transpose2[1] = vipldws_B.MultiportSelector_o3[1] -
    vipldws_B.MultiportSelector_o4[1];

  /* Abs: '<S16>/Abs1' */
  if (vipldws_B.Transpose2[1] < 0) {
    vipldws_B.Transpose2[1] = -vipldws_B.Transpose2[1];
  }

  /* Sum: '<S16>/Add2' */
  vipldws_B.Bias2[1] += vipldws_B.Transpose2[1];

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  vipldws_B.Compare_g[1] = (vipldws_B.Bias2[1] >=
    vipldws_P.CompareToConstant1_const_o);

  /* Logic: '<S16>/Logical Operator7' */
  vipldws_B.LogicalOperator7[1] = (vipldws_B.LogicalOperator7[1] &&
    vipldws_B.LogicalOperator8[1] && vipldws_B.Compare_g[1]);

  /* S-Function (sdspmultiportsel): '<S16>/Multiport Selector1' */
  vipldws_B.MultiportSelector1_o1 = vipldws_B.LogicalOperator7[0];
  vipldws_B.MultiportSelector1_o2 = vipldws_B.LogicalOperator7[1];

  /* Logic: '<S16>/Logical Operator' */
  vipldws_B.Switch_h = (vipldws_B.MultiportSelector1_o1 &&
                        vipldws_B.MultiportSelector1_o2);

  /* Logic: '<S6>/Logical Operator' */
  vipldws_B.LogicalOperator_b = (vipldws_B.LogicalOperator_b &&
    vipldws_B.RelationalOperator1);

  /* Logic: '<S6>/Logical Operator1' */
  vipldws_B.LogicalOperator1 = (vipldws_B.Switch_h &&
    vipldws_B.LogicalOperator_b);

  /* MATLAB Function: '<S5>/Exclude 3rd Lane' */
  /*  Exclude third (left or right lane) if it is very close to the other lane  */
  /*  already detected and tracked by Kalman filter. */
  /* MATLAB Function 'Output/Exclude 3rd Lane': '<S63>:1' */
  /* '<S63>:1:6' [rH cW] = size(RefImg(:,:,1)); */
  /* '<S63>:1:7' out3rdLane = in3rdLane; */
  vipldws_B.out3rdLane[0] = vipldws_B.Switch1_b[0];
  vipldws_B.out3rdLane[1] = vipldws_B.Switch1_b[1];
  vipldws_B.out3rdLane[2] = vipldws_B.Switch1_b[2];
  vipldws_B.out3rdLane[3] = vipldws_B.Switch1_b[3];

  /* '<S63>:1:9' if (Show3rdLane && twoLanesFlag) */
  if (vipldws_B.LogicalOperator2 && vipldws_B.LogicalOperator1) {
    /* '<S63>:1:10' R1C1R2C2 = in3rdLane; */
    /* '<S63>:1:11' R1 = R1C1R2C2(1)+int32(1); */
    if (vipldws_B.Switch1_b[0] > 2147483646) {
      vipldws_B.countPeak = MAX_int32_T;
    } else {
      vipldws_B.countPeak = vipldws_B.Switch1_b[0] + 1;
    }

    /* '<S63>:1:12' C1 = R1C1R2C2(2)+int32(1); */
    if (vipldws_B.Switch1_b[1] > 2147483646) {
      vipldws_B.C1 = MAX_int32_T;
    } else {
      vipldws_B.C1 = vipldws_B.Switch1_b[1] + 1;
    }

    /* '<S63>:1:13' R2 = R1C1R2C2(3)+int32(1); */
    if (vipldws_B.Switch1_b[2] > 2147483646) {
      vipldws_B.qY_g = MAX_int32_T;
    } else {
      vipldws_B.qY_g = vipldws_B.Switch1_b[2] + 1;
    }

    vipldws_B.R2 = vipldws_B.qY_g;

    /* '<S63>:1:14' C2 = R1C1R2C2(4)+int32(1); */
    if (vipldws_B.Switch1_b[3] > 2147483646) {
      vipldws_B.qY = MAX_int32_T;
    } else {
      vipldws_B.qY = vipldws_B.Switch1_b[3] + 1;
    }

    vipldws_B.C2 = vipldws_B.qY;

    /*  make sure R1 is the min(R1,R2) */
    /* '<S63>:1:16' if R1>R2 */
    if (vipldws_B.countPeak > vipldws_B.qY_g) {
      /* '<S63>:1:17' TMP=R2; */
      /* '<S63>:1:18' R2=R1; */
      vipldws_B.R2 = vipldws_B.countPeak;

      /* '<S63>:1:19' R1=TMP; */
      vipldws_B.countPeak = vipldws_B.qY_g;

      /* '<S63>:1:21' TMP=C2; */
      /* '<S63>:1:22' C2=C1; */
      vipldws_B.C2 = vipldws_B.C1;

      /* '<S63>:1:23' C1=TMP; */
      vipldws_B.C1 = vipldws_B.qY;
    }

    /* '<S63>:1:26' for lineIdx =1:2 */
    for (vipldws_B.yIdx = 0; vipldws_B.yIdx < 2; vipldws_B.yIdx++) {
      /* '<S63>:1:28' r1c1r2c2 = mainTwoLanes(:,lineIdx); */
      /* '<S63>:1:29' r1 = r1c1r2c2(1)+int32(1); */
      if (vipldws_B.MatrixConcatenation5[vipldws_B.yIdx << 2] > 2147483646) {
        vipldws_B.r1 = MAX_int32_T;
      } else {
        vipldws_B.r1 = vipldws_B.MatrixConcatenation5[vipldws_B.yIdx << 2] + 1;
      }

      /* '<S63>:1:30' c1 = r1c1r2c2(2)+int32(1); */
      if (vipldws_B.MatrixConcatenation5[(vipldws_B.yIdx << 2) + 1] > 2147483646)
      {
        vipldws_B.c1 = MAX_int32_T;
      } else {
        vipldws_B.c1 = vipldws_B.MatrixConcatenation5[(vipldws_B.yIdx << 2) + 1]
          + 1;
      }

      /* '<S63>:1:31' r2 = r1c1r2c2(3)+int32(1); */
      if (vipldws_B.MatrixConcatenation5[(vipldws_B.yIdx << 2) + 2] > 2147483646)
      {
        vipldws_B.qY_g = MAX_int32_T;
      } else {
        vipldws_B.qY_g = vipldws_B.MatrixConcatenation5[(vipldws_B.yIdx << 2) +
          2] + 1;
      }

      vipldws_B.r2 = vipldws_B.qY_g;

      /* '<S63>:1:32' c2 = r1c1r2c2(4)+int32(1); */
      if (vipldws_B.MatrixConcatenation5[(vipldws_B.yIdx << 2) + 3] > 2147483646)
      {
        vipldws_B.qY = MAX_int32_T;
      } else {
        vipldws_B.qY = vipldws_B.MatrixConcatenation5[(vipldws_B.yIdx << 2) + 3]
          + 1;
      }

      vipldws_B.c2 = vipldws_B.qY;

      /*  make sure r1 is the min(r1,r2) */
      /* '<S63>:1:35' if r1>r2 */
      if (vipldws_B.r1 > vipldws_B.qY_g) {
        /* '<S63>:1:36' tmp=r2; */
        /* '<S63>:1:37' r2=r1; */
        vipldws_B.r2 = vipldws_B.r1;

        /* '<S63>:1:38' r1=tmp; */
        vipldws_B.r1 = vipldws_B.qY_g;

        /* '<S63>:1:40' tmp=c2; */
        /* '<S63>:1:41' c2=c1; */
        vipldws_B.c2 = vipldws_B.c1;

        /* '<S63>:1:42' c1=tmp; */
        vipldws_B.c1 = vipldws_B.qY;
      }

      /* '<S63>:1:45' pointNotLine = (r1==r2) && (c1==c2); */
      /*  find if line is within image: (r1,c1)  and (r2,c2) must be within image */
      /* '<S63>:1:48' if ((r1>0 && r1 <= rH) && (c1>0 && c1 <= cW) && ... */
      /* '<S63>:1:49'         (r2>0 && r2 <= rH) && (c2>0 && c2 <= cW)) && ~pointNotLine */
      if ((vipldws_B.r1 > 0) && (vipldws_B.r1 <= 120) && (vipldws_B.c1 > 0) &&
          (vipldws_B.c1 <= 240) && (vipldws_B.r2 > 0) && (vipldws_B.r2 <= 120) &&
          (vipldws_B.c2 > 0) && (vipldws_B.c2 <= 240) && (!((vipldws_B.r1 ==
             vipldws_B.r2) && (vipldws_B.c1 == vipldws_B.c2)))) {
        /* line_within_image = true; */
        /* '<S63>:1:51' if (abs(r1-R1)+ abs(c1-C1) + abs(r2-R2) +abs(c2-C2))< int32(20) */
        if (vipldws_B.countPeak < vipldws_B.r1 - MAX_int32_T) {
          vipldws_B.qY_g = MAX_int32_T;
        } else {
          vipldws_B.qY_g = vipldws_B.r1 - vipldws_B.countPeak;
        }

        if (vipldws_B.C1 < vipldws_B.c1 - MAX_int32_T) {
          vipldws_B.qY = MAX_int32_T;
        } else {
          vipldws_B.qY = vipldws_B.c1 - vipldws_B.C1;
        }

        if (vipldws_B.R2 < vipldws_B.r2 - MAX_int32_T) {
          vipldws_B.c1 = MAX_int32_T;
        } else {
          vipldws_B.c1 = vipldws_B.r2 - vipldws_B.R2;
        }

        if (vipldws_B.C2 < vipldws_B.c2 - MAX_int32_T) {
          vipldws_B.i = MAX_int32_T;
        } else {
          vipldws_B.i = vipldws_B.c2 - vipldws_B.C2;
        }

        if (vipldws_B.qY_g < 0) {
          vipldws_B.qY_g = -vipldws_B.qY_g;
        }

        if (vipldws_B.qY < 0) {
          vipldws_B.qY = -vipldws_B.qY;
        }

        if (vipldws_B.c1 < 0) {
          vipldws_B.c1 = -vipldws_B.c1;
        }

        if (vipldws_B.i < 0) {
          vipldws_B.i = -vipldws_B.i;
        }

        if ((vipldws_B.qY_g < 0) && (vipldws_B.qY < MIN_int32_T - vipldws_B.qY_g))
        {
          vipldws_B.qY_g = MIN_int32_T;
        } else if ((vipldws_B.qY_g > 0) && (vipldws_B.qY > MAX_int32_T
                    - vipldws_B.qY_g)) {
          vipldws_B.qY_g = MAX_int32_T;
        } else {
          vipldws_B.qY_g += vipldws_B.qY;
        }

        if ((vipldws_B.qY_g < 0) && (vipldws_B.c1 < MIN_int32_T - vipldws_B.qY_g))
        {
          vipldws_B.qY_g = MIN_int32_T;
        } else if ((vipldws_B.qY_g > 0) && (vipldws_B.c1 > MAX_int32_T
                    - vipldws_B.qY_g)) {
          vipldws_B.qY_g = MAX_int32_T;
        } else {
          vipldws_B.qY_g += vipldws_B.c1;
        }

        if ((vipldws_B.qY_g < 0) && (vipldws_B.i < MIN_int32_T - vipldws_B.qY_g))
        {
          vipldws_B.qY_g = MIN_int32_T;
        } else if ((vipldws_B.qY_g > 0) && (vipldws_B.i > MAX_int32_T
                    - vipldws_B.qY_g)) {
          vipldws_B.qY_g = MAX_int32_T;
        } else {
          vipldws_B.qY_g += vipldws_B.i;
        }

        if (vipldws_B.qY_g < 20) {
          /* '<S63>:1:52' out3rdLane = int32([-1000 -1000 -1000 -1000]'); */
          vipldws_B.out3rdLane[0] = -1000;
          vipldws_B.out3rdLane[1] = -1000;
          vipldws_B.out3rdLane[2] = -1000;
          vipldws_B.out3rdLane[3] = -1000;
        }
      } else {
        /* '<S63>:1:54' else */
        /*  line outside image */
        /*  go to nextLine */
      }
    }
  } else {
    /* '<S63>:1:59' else */
    /* '<S63>:1:60' out3rdLane = in3rdLane; */
  }

  /* End of MATLAB Function: '<S5>/Exclude 3rd Lane' */

  /* Bias: '<S5>/Bias3' */
  vipldws_B.Bias3[0] = vipldws_B.out3rdLane[0] + vipldws_P.Bias3_Bias[0];
  vipldws_B.Bias3[1] = vipldws_B.out3rdLane[1] + vipldws_P.Bias3_Bias[1];
  vipldws_B.Bias3[2] = vipldws_B.out3rdLane[2] + vipldws_P.Bias3_Bias[2];
  vipldws_B.Bias3[3] = vipldws_B.out3rdLane[3] + vipldws_P.Bias3_Bias[3];

  /* ManualSwitch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Draw Lines'
   *  Constant: '<Root>/Draw Polygon'
   */
  if (vipldws_P.Switch_CurrentSetting == 1) {
    vipldws_B.Switch_h = vipldws_P.DrawLines_Value_j;
  } else {
    vipldws_B.Switch_h = vipldws_P.DrawPolygon_Value;
  }

  /* End of ManualSwitch: '<Root>/Switch' */

  /* Logic: '<Root>/Logical Operator' */
  vipldws_B.LogicalOperator = (vipldws_B.LogicalOperator1 && vipldws_B.Switch_h);

  /* Bias: '<S5>/Bias' */
  for (vipldws_B.i = 0; vipldws_B.i < 8; vipldws_B.i++) {
    vipldws_B.Bias[vipldws_B.i] = vipldws_B.MatrixConcatenation5[vipldws_B.i] +
      vipldws_P.Bias_Bias_i[vipldws_B.i];
  }

  /* End of Bias: '<S5>/Bias' */

  /* S-Function (sdspnsamp2): '<S5>/N-Sample Enable' incorporates:
   *  Constant: '<S2>/Constant'
   */
  /* DSP System Toolbox N-Sample Enable  (sdspnsamp2) - '<S5>/N-Sample Enable' */
  {
    {
      if (vipldws_P.Constant_Value_n) {
        /* Reset iteration count. */
        vipldws_DW.NSampleEnable_Counter = 0;
      }

      if (vipldws_DW.NSampleEnable_Counter == vipldws_P.NSampleEnable_N) {
        vipldws_B.NSampleEnable = (boolean_T)(2 -
          vipldws_P.NSampleEnable_ActiveLevel);
      } else {
        vipldws_B.NSampleEnable = (boolean_T)
          (vipldws_P.NSampleEnable_ActiveLevel - 1);
        (vipldws_DW.NSampleEnable_Counter)++;
      }
    }
  }

  /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  if (vipldws_B.NSampleEnable) {
    /* Bias: '<S65>/Bias' */
    vipldws_B.Bias_h = (int8_T)(vipldws_B.outMsg + vipldws_P.Bias_Bias_d);

    /* Bias: '<S65>/Bias1' */
    vipldws_B.Bias1_j[0] = (int8_T)(vipldws_B.colorAndTypeIdx[0] +
      vipldws_P.Bias1_Bias_e);
    vipldws_B.Bias1_j[1] = (int8_T)(vipldws_B.colorAndTypeIdx[1] +
      vipldws_P.Bias1_Bias_e);

    /* Outputs for Enabled SubSystem: '<S65>/Draw  Polygon' incorporates:
     *  EnablePort: '<S66>/Enable'
     */
    if (vipldws_B.LogicalOperator) {
      /* S-Function (svipscalenconvert): '<S66>/Image Data Type Conversion' */
      for (vipldws_B.i = 0; vipldws_B.i < 230400; vipldws_B.i++) {
        if (vipldws_B.ImageDataTypeConversion[vipldws_B.i] > 1.0F) {
          vipldws_B.ImageDataTypeConversion_n[vipldws_B.i] = 1.0F;
        } else if (vipldws_B.ImageDataTypeConversion[vipldws_B.i] < 0.0F) {
          vipldws_B.ImageDataTypeConversion_n[vipldws_B.i] = 0.0F;
        } else {
          vipldws_B.ImageDataTypeConversion_n[vipldws_B.i] =
            vipldws_B.ImageDataTypeConversion[vipldws_B.i];
        }
      }

      /* End of S-Function (svipscalenconvert): '<S66>/Image Data Type Conversion' */

      /* Selector: '<S69>/Selector1' */
      vipldws_B.MatrixConcatenation6[0] = vipldws_B.Bias[0];

      /* Selector: '<S69>/Selector4' */
      vipldws_B.Selector7[0] = vipldws_B.Bias[2];

      /* SignalConversion: '<S69>/ConcatBufferAtMatrix Concatenation6In2' */
      vipldws_B.MatrixConcatenation6[2] = vipldws_B.Selector7[0];

      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S69>/DSP Constant'
       */
      if (vipldws_B.Selector7[0] >= vipldws_P.Switch_Threshold) {
        vipldws_B.MatrixConcatenation6[4] = vipldws_B.Selector7[0];
      } else {
        vipldws_B.MatrixConcatenation6[4] = vipldws_P.DSPConstant_Value[0];
      }

      /* Selector: '<S69>/Selector1' */
      vipldws_B.MatrixConcatenation6[1] = vipldws_B.Bias[1];

      /* Selector: '<S69>/Selector4' */
      vipldws_B.Selector7[1] = vipldws_B.Bias[3];

      /* SignalConversion: '<S69>/ConcatBufferAtMatrix Concatenation6In2' */
      vipldws_B.MatrixConcatenation6[3] = vipldws_B.Selector7[1];

      /* Switch: '<S69>/Switch' incorporates:
       *  Constant: '<S69>/DSP Constant'
       */
      if (vipldws_B.Selector7[0] >= vipldws_P.Switch_Threshold) {
        vipldws_B.MatrixConcatenation6[5] = vipldws_B.Selector7[1];
      } else {
        vipldws_B.MatrixConcatenation6[5] = vipldws_P.DSPConstant_Value[1];
      }

      /* Selector: '<S69>/Selector' */
      vipldws_B.Selector7[0] = vipldws_B.Bias[6];

      /* Switch: '<S69>/Switch1' incorporates:
       *  Constant: '<S69>/DSP Constant2'
       */
      if (vipldws_B.Selector7[0] >= vipldws_P.Switch1_Threshold) {
        vipldws_B.MatrixConcatenation6[6] = vipldws_B.Selector7[0];
      } else {
        vipldws_B.MatrixConcatenation6[6] = vipldws_P.DSPConstant2_Value[0];
      }

      /* SignalConversion: '<S69>/ConcatBufferAtMatrix Concatenation6In5' */
      vipldws_B.MatrixConcatenation6[8] = vipldws_B.Selector7[0];

      /* Selector: '<S69>/Selector2' */
      vipldws_B.MatrixConcatenation6[10] = vipldws_B.Bias[4];

      /* Selector: '<S69>/Selector' */
      vipldws_B.Selector7[1] = vipldws_B.Bias[7];

      /* Switch: '<S69>/Switch1' incorporates:
       *  Constant: '<S69>/DSP Constant2'
       */
      if (vipldws_B.Selector7[0] >= vipldws_P.Switch1_Threshold) {
        vipldws_B.MatrixConcatenation6[7] = vipldws_B.Selector7[1];
      } else {
        vipldws_B.MatrixConcatenation6[7] = vipldws_P.DSPConstant2_Value[1];
      }

      /* SignalConversion: '<S69>/ConcatBufferAtMatrix Concatenation6In5' */
      vipldws_B.MatrixConcatenation6[9] = vipldws_B.Selector7[1];

      /* Selector: '<S69>/Selector2' */
      vipldws_B.MatrixConcatenation6[11] = vipldws_B.Bias[5];
      for (vipldws_B.i = 0; vipldws_B.i < 12; vipldws_B.i++) {
        /* Selector: '<S66>/Selector2' */
        vipldws_B.Selector2_h[vipldws_B.i] =
          vipldws_B.MatrixConcatenation6[tmp_0[vipldws_B.i]];

        /* Math: '<S66>/Transpose1' */
        vipldws_B.Transpose1_b[vipldws_B.i] = vipldws_B.Selector2_h[vipldws_B.i];
      }

      /* S-Function (svipdrawshapes): '<S66>/DrawShapes' */
      /* Copy the image from input to output. */
      memcpy(&vipldws_B.DrawShapes_f[0], &vipldws_B.ImageDataTypeConversion_n[0],
             230400U * sizeof(real32_T));

      /* Calculate FillColor times Opacity. */
      vipldws_DW.DrawShapes_DW_FillColorAdd[0] = vipldws_P.DrawShapes_color[0] *
        vipldws_P.DrawShapes_opacity;
      vipldws_DW.DrawShapes_DW_FillColorAdd[1] = vipldws_P.DrawShapes_color[1] *
        vipldws_P.DrawShapes_opacity;
      vipldws_DW.DrawShapes_DW_FillColorAdd[2] = vipldws_P.DrawShapes_color[2] *
        vipldws_P.DrawShapes_opacity;

      /* Calculate One minus Opacity. */
      vipldws_DW.DrawShapes_DW_OneMOpacity = 1.0F - vipldws_P.DrawShapes_opacity;

      /* Update view port. */
      /* ProcessStep-start-1
       */
      /* ProcessStep-after poly points-1
       */
      /* Reset scanline states. */
      vipldws_B.R2 = 0;
      c_gotAlLeastOneYellowPixelInThe = true;
      while (c_gotAlLeastOneYellowPixelInThe) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        done = false;
        vipldws_B.numEdge = 0;
        vipldws_B.qY_g = vipldws_B.R2;
        vipldws_B.qY = vipldws_B.R2;
        vipldws_B.ii = 0;
        while (vipldws_B.ii < 1) {
          /* start for loop
           */
          vipldws_B.lastActiveEdgeIdxBdy = 11;
          vipldws_B.yIdx = 10;
          vipldws_B.firstRowOut = 5;
          vipldws_B.activeColBdy = 8;
          vipldws_B.activeCol = 6;

          /* getLoc-3
           */
          vipldws_B.i = vipldws_B.Transpose1_b[8];
          while ((vipldws_B.activeColBdy >= 0) && (vipldws_B.Transpose1_b[10] -
                  1 == vipldws_B.i - 1)) {
            vipldws_B.firstRowOut--;
            vipldws_B.activeColBdy = (vipldws_B.firstRowOut - 1) << 1;
            vipldws_B.activeCol--;

            /* getLoc-3
             */
            vipldws_B.i = vipldws_B.Transpose1_b[vipldws_B.activeColBdy];
          }

          if (vipldws_B.activeColBdy < 0) {
            vipldws_B.activeColBdy = 0;
          }

          /* getLoc-3
           */
          c_gotAlLeastOneYellowPixelInThe =
            (vipldws_B.Transpose1_b[vipldws_B.activeColBdy] - 1 >
             vipldws_B.Transpose1_b[10] - 1);
          vipldws_B.colOut = 1;
          vipldws_B.activeColBdy = 0;
          prevEdgeIsVertical = false;

          /* getLoc-3
           */
          done = (vipldws_B.Transpose1_b[10] - 1 == vipldws_B.Transpose1_b[0] -
                  1);
          vipldws_B.i = 0;
          while (vipldws_B.i < vipldws_B.activeCol) {
            /* getLoc-3
             */
            if (vipldws_B.Transpose1_b[vipldws_B.yIdx] - 1 !=
                vipldws_B.Transpose1_b[vipldws_B.activeColBdy] - 1) {
              /* getLoc-3
               */
              if (vipldws_B.Transpose1_b[vipldws_B.yIdx] - 1 <
                  vipldws_B.Transpose1_b[vipldws_B.activeColBdy] - 1) {
                countTwice = false;
              } else {
                countTwice = true;
                vipldws_B.firstRowOut = vipldws_B.lastActiveEdgeIdxBdy;
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
                vipldws_B.colOut = vipldws_B.firstRowOut;
                vipldws_B.firstRowOut = vipldws_B.yIdx;
                vipldws_B.yIdx = vipldws_B.activeColBdy;
                vipldws_B.activeColBdy = vipldws_B.firstRowOut;
              }

              /* getLoc-3
               */
              /* Initialize a Bresenham line. */
              vipldws_B.firstRow = vipldws_B.Transpose1_b[vipldws_B.activeColBdy]
                - vipldws_B.Transpose1_b[vipldws_B.yIdx];
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] = 0;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] =
                vipldws_B.Transpose1_b[vipldws_B.lastActiveEdgeIdxBdy] - 1;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2] =
                vipldws_B.Transpose1_b[vipldws_B.yIdx] - 1;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] =
                vipldws_B.Transpose1_b[vipldws_B.activeColBdy] - 1;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] = 0;
              if (vipldws_B.Transpose1_b[vipldws_B.colOut] - 1 >=
                  vipldws_B.Transpose1_b[vipldws_B.lastActiveEdgeIdxBdy] - 1) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] =
                  vipldws_B.Transpose1_b[vipldws_B.colOut] -
                  vipldws_B.Transpose1_b[vipldws_B.lastActiveEdgeIdxBdy];
              } else {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] =
                  vipldws_B.Transpose1_b[vipldws_B.lastActiveEdgeIdxBdy] -
                  vipldws_B.Transpose1_b[vipldws_B.colOut];
              }

              while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] >= 0) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6]++;
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] -=
                  vipldws_B.firstRow;
              }

              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] - 1;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] +
                vipldws_B.firstRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 4] =
                vipldws_B.firstRow -
                (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7] << 1);
              if (vipldws_B.Transpose1_b[vipldws_B.lastActiveEdgeIdxBdy] - 1 >
                  vipldws_B.Transpose1_b[vipldws_B.colOut] - 1) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5] =
                  -vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] =
                  -vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6];
              }

              if ((!c_gotAlLeastOneYellowPixelInThe) && (!countTwice)) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2]++;
                if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] << 1) >
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 4]) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6];
                } else {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5];
                }
              } else {
                if (c_gotAlLeastOneYellowPixelInThe && countTwice) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3]--;
                }
              }

              c_gotAlLeastOneYellowPixelInThe = countTwice;
              if (!prevEdgeIsVertical) {
                /* Merge two Bresenham lines. */
                if ((vipldws_B.qY_g != vipldws_B.qY) &&
                    ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 5] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 6] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 7] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 8] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8]))) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] + 1 ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2]) {
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] =
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3];
                    prevEdgeIsVertical = true;
                  } else {
                    if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] + 1 ==
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2]) {
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 1] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2];
                      prevEdgeIsVertical = true;
                    }
                  }
                }

                if (!prevEdgeIsVertical) {
                  vipldws_B.qY_g = vipldws_B.qY;
                  vipldws_B.numEdge++;
                }
              } else {
                vipldws_B.qY_g = vipldws_B.qY;
                vipldws_B.numEdge++;
              }

              vipldws_B.qY = vipldws_B.qY_g + 9;
              if (!countTwice) {
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
                vipldws_B.yIdx = vipldws_B.activeColBdy;
              }

              vipldws_B.colOut = vipldws_B.lastActiveEdgeIdxBdy + 2;
              vipldws_B.activeColBdy = vipldws_B.yIdx + 2;
              prevEdgeIsVertical = false;
            } else {
              prevEdgeIsVertical = true;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
              vipldws_B.yIdx = vipldws_B.activeColBdy;
              vipldws_B.colOut += 2;
              vipldws_B.activeColBdy += 2;
            }

            vipldws_B.i++;
          }

          vipldws_B.ii = 1;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((vipldws_B.R2 != vipldws_B.qY_g) &&
              ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 5] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 5]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 6] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 6]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 7] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 7]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 8] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 8]))) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3] + 1 ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2]) {
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3];
              done = true;
            } else {
              if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] + 1 ==
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2]) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 1] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 1];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2];
                done = true;
              }
            }
          }

          if (done) {
            vipldws_B.numEdge--;
            vipldws_B.qY -= 9;
          }
        }

        /* Set all other edges to invalid. */
        vipldws_B.i = vipldws_B.numEdge;
        while (vipldws_B.i < 6) {
          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2] = 1;
          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] = 0;
          vipldws_B.qY += 9;
          vipldws_B.i++;
        }

        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws_B.r1 = vipldws_B.R2;
          vipldws_B.r2 = vipldws_B.R2 + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.i = 1;
          while (vipldws_B.i < vipldws_B.numEdge) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 2] >
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_B.lastSeparator =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii] =
                  vipldws_B.lastSeparator;
              }
            }

            vipldws_B.r1 = vipldws_B.r2;
            vipldws_B.r2 += 9;
            vipldws_B.i++;
          }
        }

        /* Find out the last column of the polygon. */
        vipldws_B.C1 = vipldws_B.R2 + 3;
        vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3];
        vipldws_B.i = 1;
        while (vipldws_B.i < vipldws_B.numEdge) {
          vipldws_B.C1 += 9;
          if (vipldws_B.qY_g < vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1]) {
            vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1];
          }

          vipldws_B.i++;
        }

        vipldws_B.qY = vipldws_B.qY_g;
        if (vipldws_B.qY_g > 239) {
          vipldws_B.qY = 239;
        }

        /* Find out the first column of the polygon. */
        vipldws_B.C1 = vipldws_B.R2 + 2;
        vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2];
        vipldws_B.i = 1;
        while (vipldws_B.i < vipldws_B.numEdge) {
          vipldws_B.C1 += 9;
          if (vipldws_B.qY_g > vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1]) {
            vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1];
          }

          vipldws_B.i++;
        }

        if (vipldws_B.qY_g < 0) {
          vipldws_B.qY_g = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        vipldws_B.r1 = vipldws_B.R2;
        vipldws_B.r2 = vipldws_B.R2;
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.R2;
        vipldws_B.yIdx = 0;
        vipldws_B.C1 = 0;
        vipldws_B.i = 0;
        while (vipldws_B.i < vipldws_B.numEdge) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 3] >=
              vipldws_B.qY_g) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <=
                vipldws_B.qY_g) {
              while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <
                     vipldws_B.qY_g) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]++;
                if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] << 1) >
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 4]) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 8];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 6];
                } else {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 7];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 5];
                }
              }

              vipldws_B.lastActiveEdgeIdxBdy += 9;
              vipldws_B.C1++;
            }

            if (vipldws_B.r2 != vipldws_B.r1) {
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
              }
            }

            vipldws_B.r1 += 9;
            vipldws_B.yIdx++;
          }

          vipldws_B.r2 += 9;
          vipldws_B.i++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws_B.r1 = vipldws_B.R2;
          vipldws_B.r2 = vipldws_B.R2 + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.i = 1;
          while (vipldws_B.i < vipldws_B.C1) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1] >
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_B.lastSeparator =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii] =
                  vipldws_B.lastSeparator;
              }
            }

            vipldws_B.r1 = vipldws_B.r2;
            vipldws_B.r2 += 9;
            vipldws_B.i++;
          }
        }

        vipldws_B.r1 = vipldws_B.R2;
        vipldws_B.activeColBdy = vipldws_B.qY_g + 1;
        vipldws_B.activeCol = 0;
        vipldws_B.r2 = 0;
        vipldws_B.lastSeparator = -1;
        c_gotAlLeastOneYellowPixelInThe = (0 <= vipldws_B.qY);
        while (c_gotAlLeastOneYellowPixelInThe) {
          /* Get a string of pixels */
          countTwice = false;
          done = (vipldws_B.r2 != 0);
          vipldws_B.col = vipldws_B.activeCol;
          if ((vipldws_B.activeCol >= vipldws_B.qY_g) && (vipldws_B.activeCol <=
               vipldws_B.qY)) {
            if (vipldws_B.r1 < vipldws_B.lastActiveEdgeIdxBdy) {
              vipldws_B.i = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1];
              vipldws_B.r1 += 9;
              if ((vipldws_B.i == vipldws_B.lastSeparator) && (vipldws_B.r1 <
                   vipldws_B.lastActiveEdgeIdxBdy)) {
                vipldws_B.C1 = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1];
                c_gotAlLeastOneYellowPixelInThe = (vipldws_B.r1 <
                  vipldws_B.lastActiveEdgeIdxBdy);
                while (c_gotAlLeastOneYellowPixelInThe && (vipldws_B.i ==
                        vipldws_B.C1)) {
                  countTwice = true;
                  vipldws_B.i = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                    1];
                  vipldws_B.r1 += 9;
                  c_gotAlLeastOneYellowPixelInThe = (vipldws_B.r1 <
                    vipldws_B.lastActiveEdgeIdxBdy);
                  if (c_gotAlLeastOneYellowPixelInThe) {
                    vipldws_B.C1 = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1
                      + 1];
                  }
                }

                if (!c_gotAlLeastOneYellowPixelInThe) {
                  countTwice = false;
                }
              }

              if (vipldws_B.r2 != 0) {
                vipldws_B.firstRow = vipldws_B.lastSeparator;
                if (vipldws_B.i <= 319) {
                  vipldws_B.lastRow = vipldws_B.i;
                  vipldws_B.lastSeparator = vipldws_B.i;
                } else {
                  vipldws_B.lastRow = 319;
                  vipldws_B.lastSeparator = 319;
                }
              } else {
                vipldws_B.firstRow = vipldws_B.lastSeparator + 1;
                if ((vipldws_B.i > 0) && (vipldws_B.i <= 319)) {
                  vipldws_B.lastRow = vipldws_B.i - 1;
                  vipldws_B.lastSeparator = vipldws_B.i;
                } else if (vipldws_B.i <= 0) {
                  vipldws_B.lastRow = -1;
                  vipldws_B.lastSeparator = 0;
                } else {
                  vipldws_B.lastRow = 319;
                  vipldws_B.lastSeparator = 320;
                }
              }

              if (!countTwice) {
                vipldws_B.r2 = !(vipldws_B.r2 != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              vipldws_B.firstRow = vipldws_B.lastSeparator + 1;
              vipldws_B.lastRow = 319;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              vipldws_B.r1 = vipldws_B.R2;
              vipldws_B.r2 = vipldws_B.R2;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.R2;
              vipldws_B.numEdge = 0;
              vipldws_B.C1 = 0;
              vipldws_B.i = 0;
              while (vipldws_B.i < vipldws_B.yIdx) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 3] >=
                    vipldws_B.activeColBdy) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <=
                      vipldws_B.activeColBdy) {
                    while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <
                           vipldws_B.activeColBdy) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]++;
                      if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] << 1) >
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 4]) {
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 8];
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 6];
                      } else {
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 7];
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 5];
                      }
                    }

                    vipldws_B.lastActiveEdgeIdxBdy += 9;
                    vipldws_B.C1++;
                  }

                  if (vipldws_B.r2 != vipldws_B.r1) {
                    for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii];
                    }
                  }

                  vipldws_B.r1 += 9;
                  vipldws_B.numEdge++;
                }

                vipldws_B.r2 += 9;
                vipldws_B.i++;
              }

              vipldws_B.yIdx = vipldws_B.numEdge;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (c_gotAlLeastOneYellowPixelInThe) {
                vipldws_B.r1 = vipldws_B.R2;
                vipldws_B.r2 = vipldws_B.R2 + 9;
                c_gotAlLeastOneYellowPixelInThe = false;
                vipldws_B.i = 1;
                while (vipldws_B.i < vipldws_B.C1) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1] >
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1]) {
                    c_gotAlLeastOneYellowPixelInThe = true;
                    for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                      vipldws_B.lastSeparator =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii] = vipldws_B.lastSeparator;
                    }
                  }

                  vipldws_B.r1 = vipldws_B.r2;
                  vipldws_B.r2 += 9;
                  vipldws_B.i++;
                }
              }

              vipldws_B.r1 = vipldws_B.R2;
              vipldws_B.activeColBdy++;
              vipldws_B.r2 = 0;
              vipldws_B.lastSeparator = -1;
              vipldws_B.activeCol++;
            }
          } else {
            vipldws_B.firstRow = 0;
            vipldws_B.lastRow = 319;
            vipldws_B.activeCol++;
          }

          if (vipldws_B.firstRow < 0) {
            vipldws_B.firstRow = 0;
          }

          if (vipldws_B.lastRow < vipldws_B.firstRow) {
            vipldws_B.lastRow = vipldws_B.firstRow - 1;
          }

          if (done) {
            vipldws_B.ii = vipldws_B.col * 320 + vipldws_B.firstRow;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.i = vipldws_B.firstRow;
            while (vipldws_B.i <= vipldws_B.lastRow) {
              vipldws_B.DrawShapes_f[vipldws_B.col] *=
                vipldws_DW.DrawShapes_DW_OneMOpacity;
              vipldws_B.DrawShapes_f[vipldws_B.col] +=
                vipldws_DW.DrawShapes_DW_FillColorAdd[0];
              vipldws_B.col++;
              vipldws_B.i++;
            }

            vipldws_B.ii += 76800;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.i = vipldws_B.firstRow;
            while (vipldws_B.i <= vipldws_B.lastRow) {
              vipldws_B.DrawShapes_f[vipldws_B.col] *=
                vipldws_DW.DrawShapes_DW_OneMOpacity;
              vipldws_B.DrawShapes_f[vipldws_B.col] +=
                vipldws_DW.DrawShapes_DW_FillColorAdd[1];
              vipldws_B.col++;
              vipldws_B.i++;
            }

            vipldws_B.ii += 76800;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.i = vipldws_B.firstRow;
            while (vipldws_B.i <= vipldws_B.lastRow) {
              vipldws_B.DrawShapes_f[vipldws_B.col] *=
                vipldws_DW.DrawShapes_DW_OneMOpacity;
              vipldws_B.DrawShapes_f[vipldws_B.col] +=
                vipldws_DW.DrawShapes_DW_FillColorAdd[2];
              vipldws_B.col++;
              vipldws_B.i++;
            }
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws_B.activeCol <= vipldws_B.qY);
        }

        /* Move to the next polygon. */
        vipldws_B.R2 += 54;
        c_gotAlLeastOneYellowPixelInThe = (vipldws_B.R2 < 54);
      }

      /* End of S-Function (svipdrawshapes): '<S66>/DrawShapes' */

      /* S-Function (svipscalenconvert): '<S66>/Image Data Type Conversion1' */
      for (vipldws_B.i = 0; vipldws_B.i < 230400; vipldws_B.i++) {
        vipldws_B.scale = vipldws_B.DrawShapes_f[vipldws_B.i] * 255.0F + 0.5F;
        if (vipldws_B.scale > 255.0F) {
          vipldws_B.scale = 255.0F;
        }

        if (vipldws_B.scale < 0.0F) {
          vipldws_B.scale = 0.0F;
        }

        vipldws_B.ImageDataTypeConversion1[vipldws_B.i] = (uint8_T)
          vipldws_B.scale;
      }

      /* End of S-Function (svipscalenconvert): '<S66>/Image Data Type Conversion1' */
      srUpdateBC(vipldws_DW.DrawPolygon_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S65>/Draw  Polygon' */

    /* Selector: '<S67>/Selector1' */
    vipldws_B.Transpose2[0] = vipldws_B.Bias[0];

    /* Bias: '<S67>/Bias1' */
    vipldws_B.Transpose2[0] += vipldws_P.Bias1_Bias[0];

    /* Selector: '<S67>/Selector3' */
    vipldws_B.Bias2[0] = vipldws_B.Bias[4];

    /* Bias: '<S67>/Bias2' */
    vipldws_B.Bias2[0] += vipldws_P.Bias2_Bias[0];

    /* Selector: '<S67>/Selector1' */
    vipldws_B.Transpose2[1] = vipldws_B.Bias[1];

    /* Bias: '<S67>/Bias1' */
    vipldws_B.Transpose2[1] += vipldws_P.Bias1_Bias[1];

    /* Selector: '<S67>/Selector3' */
    vipldws_B.Bias2[1] = vipldws_B.Bias[5];

    /* Bias: '<S67>/Bias2' */
    vipldws_B.Bias2[1] += vipldws_P.Bias2_Bias[1];

    /* Switch: '<S65>/Switch' */
    for (vipldws_B.i = 0; vipldws_B.i < 230400; vipldws_B.i++) {
      if (vipldws_B.LogicalOperator) {
        vipldws_B.Switch[vipldws_B.i] =
          vipldws_B.ImageDataTypeConversion1[vipldws_B.i];
      } else {
        vipldws_B.Switch[vipldws_B.i] =
          vipldws_B.ImageDataTypeConversion[vipldws_B.i];
      }
    }

    /* End of Switch: '<S65>/Switch' */

    /* Selector: '<S65>/Selector2' */
    for (vipldws_B.i = 0; vipldws_B.i < 2; vipldws_B.i++) {
      vipldws_B.Selector2_m[vipldws_B.i << 2] = vipldws_B.Bias[(vipldws_B.i << 2)
        + 1];
      vipldws_B.Selector2_m[1 + (vipldws_B.i << 2)] = vipldws_B.Bias[vipldws_B.i
        << 2];
      vipldws_B.Selector2_m[2 + (vipldws_B.i << 2)] = vipldws_B.Bias
        [(vipldws_B.i << 2) + 3];
      vipldws_B.Selector2_m[3 + (vipldws_B.i << 2)] = vipldws_B.Bias
        [(vipldws_B.i << 2) + 2];
    }

    /* End of Selector: '<S65>/Selector2' */

    /* Math: '<S65>/Transpose1' */
    for (vipldws_B.i = 0; vipldws_B.i < 4; vipldws_B.i++) {
      vipldws_B.Transpose1_p[vipldws_B.i << 1] =
        vipldws_B.Selector2_m[vipldws_B.i];
      vipldws_B.Transpose1_p[1 + (vipldws_B.i << 1)] =
        vipldws_B.Selector2_m[vipldws_B.i + 4];
    }

    /* End of Math: '<S65>/Transpose1' */

    /* S-Function (svipdrawshapes): '<S65>/DrawShapes' */
    if (vipldws_P.DrawShapes_lineWidth_i == 1) {
      /* Compute output for unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws_B.DrawShapes[0], &vipldws_B.Switch[0], 230400U * sizeof
             (real32_T));

      /* Update view port. */
      vipldws_B.countPeak = 0;
      for (vipldws_B.R2 = 0; vipldws_B.R2 < 2; vipldws_B.R2++) {
        vipldws_B.qY_g = vipldws_B.Transpose1_p[vipldws_B.R2 + 2] - 1;
        vipldws_B.qY = vipldws_B.Transpose1_p[vipldws_B.R2] - 1;
        if ((vipldws_B.Transpose1_p[vipldws_B.R2 + 6] - 1 != vipldws_B.qY_g) ||
            (vipldws_B.Transpose1_p[4 + vipldws_B.R2] - 1 != vipldws_B.qY)) {
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.qY_g = (vipldws_B.qY_g << 3) + 4;
          vipldws_B.numEdge = ((vipldws_B.Transpose1_p[vipldws_B.R2 + 6] - 1) <<
                               3) + 4;
          vipldws_B.qY = (vipldws_B.qY << 3) + 4;
          vipldws_B.col = ((vipldws_B.Transpose1_p[4 + vipldws_B.R2] - 1) << 3)
            + 4;

          /* Find the visible portion of a line. */
          countTwice = false;
          prevEdgeIsVertical = false;
          done = false;
          vipldws_B.yIdx = vipldws_B.qY_g;
          vipldws_B.c2 = vipldws_B.qY;
          vipldws_B.C2 = vipldws_B.numEdge;
          vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.col;
          while (!done) {
            vipldws_B.fromIdx = 0U;
            vipldws_B.toIdx = 0U;

            /* Determine viewport violations. */
            if (vipldws_B.yIdx < 0) {
              vipldws_B.fromIdx = 4U;
            } else {
              if (vipldws_B.yIdx > 2559) {
                vipldws_B.fromIdx = 8U;
              }
            }

            if (vipldws_B.C2 < 0) {
              vipldws_B.toIdx = 4U;
            } else {
              if (vipldws_B.C2 > 2559) {
                vipldws_B.toIdx = 8U;
              }
            }

            if (vipldws_B.c2 < 0) {
              vipldws_B.fromIdx |= 1U;
            } else {
              if (vipldws_B.c2 > 1919) {
                vipldws_B.fromIdx |= 2U;
              }
            }

            if (vipldws_B.lastActiveEdgeIdxBdy < 0) {
              vipldws_B.toIdx |= 1U;
            } else {
              if (vipldws_B.lastActiveEdgeIdxBdy > 1919) {
                vipldws_B.toIdx |= 2U;
              }
            }

            if (!((vipldws_B.fromIdx | vipldws_B.toIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = true;
            } else if ((vipldws_B.fromIdx & vipldws_B.toIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = false;
            } else if (vipldws_B.fromIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (countTwice) {
                vipldws_B.yIdx = vipldws_B.qY_g;
                vipldws_B.c2 = vipldws_B.qY;
              }

              vipldws_B.i = vipldws_B.C2 - vipldws_B.yIdx;
              vipldws_B.C1 = vipldws_B.lastActiveEdgeIdxBdy - vipldws_B.c2;
              if ((vipldws_B.i > 1073741824) || (vipldws_B.i < -1073741824) ||
                  ((vipldws_B.C1 > 1073741824) || (vipldws_B.C1 < -1073741824)))
              {
                /* Possible Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
                countTwice = true;
              } else if ((vipldws_B.fromIdx & 4U) != 0U) {
                /* Violated RMin. */
                vipldws_B.c1 = -vipldws_B.yIdx * vipldws_B.C1;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                  vipldws_B.c2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.i)
                                   + 1) >> 1;
                } else {
                  vipldws_B.c2 -= (div_s32_floor(-vipldws_B.c1 << 1, vipldws_B.i)
                                   + 1) >> 1;
                }

                vipldws_B.yIdx = 0;
                countTwice = true;
              } else if ((vipldws_B.fromIdx & 8U) != 0U) {
                /* Violated RMax. */
                vipldws_B.c1 = (2559 - vipldws_B.yIdx) * vipldws_B.C1;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                  vipldws_B.c2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.i)
                                   + 1) >> 1;
                } else {
                  vipldws_B.c2 -= (div_s32_floor(-vipldws_B.c1 << 1, vipldws_B.i)
                                   + 1) >> 1;
                }

                vipldws_B.yIdx = 2559;
                countTwice = true;
              } else if ((vipldws_B.fromIdx & 1U) != 0U) {
                /* Violated CMin. */
                vipldws_B.c1 = -vipldws_B.c2 * vipldws_B.i;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                  vipldws_B.yIdx += (div_s32_floor(vipldws_B.c1 << 1,
                    vipldws_B.C1) + 1) >> 1;
                } else {
                  vipldws_B.yIdx -= (div_s32_floor(-vipldws_B.c1 << 1,
                    vipldws_B.C1) + 1) >> 1;
                }

                vipldws_B.c2 = 0;
                countTwice = true;
              } else {
                /* Violated CMax. */
                vipldws_B.c1 = (1919 - vipldws_B.c2) * vipldws_B.i;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                  vipldws_B.yIdx += (div_s32_floor(vipldws_B.c1 << 1,
                    vipldws_B.C1) + 1) >> 1;
                } else {
                  vipldws_B.yIdx -= (div_s32_floor(-vipldws_B.c1 << 1,
                    vipldws_B.C1) + 1) >> 1;
                }

                vipldws_B.c2 = 1919;
                countTwice = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (prevEdgeIsVertical) {
                vipldws_B.C2 = vipldws_B.numEdge;
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.col;
              }

              vipldws_B.i = vipldws_B.C2 - vipldws_B.yIdx;
              vipldws_B.C1 = vipldws_B.lastActiveEdgeIdxBdy - vipldws_B.c2;
              if ((vipldws_B.i > 1073741824) || (vipldws_B.i < -1073741824) ||
                  ((vipldws_B.C1 > 1073741824) || (vipldws_B.C1 < -1073741824)))
              {
                /* Possible Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
                prevEdgeIsVertical = true;
              } else if ((vipldws_B.toIdx & 4U) != 0U) {
                /* Violated RMin. */
                vipldws_B.c1 = -vipldws_B.C2 * vipldws_B.C1;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                  vipldws_B.lastActiveEdgeIdxBdy += (div_s32_floor(vipldws_B.c1 <<
                    1, vipldws_B.i) + 1) >> 1;
                } else {
                  vipldws_B.lastActiveEdgeIdxBdy -= (div_s32_floor(-vipldws_B.c1
                    << 1, vipldws_B.i) + 1) >> 1;
                }

                vipldws_B.C2 = 0;
                prevEdgeIsVertical = true;
              } else if ((vipldws_B.toIdx & 8U) != 0U) {
                /* Violated RMax. */
                vipldws_B.c1 = (2559 - vipldws_B.C2) * vipldws_B.C1;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                  vipldws_B.lastActiveEdgeIdxBdy += (div_s32_floor(vipldws_B.c1 <<
                    1, vipldws_B.i) + 1) >> 1;
                } else {
                  vipldws_B.lastActiveEdgeIdxBdy -= (div_s32_floor(-vipldws_B.c1
                    << 1, vipldws_B.i) + 1) >> 1;
                }

                vipldws_B.C2 = 2559;
                prevEdgeIsVertical = true;
              } else if ((vipldws_B.toIdx & 1U) != 0U) {
                /* Violated CMin. */
                vipldws_B.c1 = -vipldws_B.lastActiveEdgeIdxBdy * vipldws_B.i;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                  vipldws_B.C2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.C1)
                                   + 1) >> 1;
                } else {
                  vipldws_B.C2 -= (div_s32_floor(-vipldws_B.c1 << 1,
                    vipldws_B.C1) + 1) >> 1;
                }

                vipldws_B.lastActiveEdgeIdxBdy = 0;
                prevEdgeIsVertical = true;
              } else {
                /* Violated CMax. */
                vipldws_B.c1 = (1919 - vipldws_B.lastActiveEdgeIdxBdy) *
                  vipldws_B.i;
                if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                           ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                  vipldws_B.C2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.C1)
                                   + 1) >> 1;
                } else {
                  vipldws_B.C2 -= (div_s32_floor(-vipldws_B.c1 << 1,
                    vipldws_B.C1) + 1) >> 1;
                }

                vipldws_B.lastActiveEdgeIdxBdy = 1919;
                prevEdgeIsVertical = true;
              }
            }
          }

          if (c_gotAlLeastOneYellowPixelInThe) {
            /* Initialize the Bresenham algorithm. */
            if (vipldws_B.C2 >= vipldws_B.yIdx) {
              vipldws_B.numEdge = vipldws_B.C2 - vipldws_B.yIdx;
            } else {
              vipldws_B.numEdge = vipldws_B.yIdx - vipldws_B.C2;
            }

            if (vipldws_B.lastActiveEdgeIdxBdy >= vipldws_B.c2) {
              vipldws_B.col = vipldws_B.lastActiveEdgeIdxBdy - vipldws_B.c2;
            } else {
              vipldws_B.col = vipldws_B.c2 - vipldws_B.lastActiveEdgeIdxBdy;
            }

            if (vipldws_B.numEdge > vipldws_B.col) {
              vipldws_B.r2 = 1;
              vipldws_B.r1 = 320;
            } else {
              vipldws_B.r2 = 320;
              vipldws_B.r1 = 1;
              vipldws_B.i = vipldws_B.yIdx;
              vipldws_B.yIdx = vipldws_B.c2;
              vipldws_B.c2 = vipldws_B.i;
              vipldws_B.i = vipldws_B.C2;
              vipldws_B.C2 = vipldws_B.lastActiveEdgeIdxBdy;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.i;
            }

            if (vipldws_B.yIdx > vipldws_B.C2) {
              vipldws_B.i = vipldws_B.yIdx;
              vipldws_B.yIdx = vipldws_B.C2;
              vipldws_B.C2 = vipldws_B.i;
              vipldws_B.i = vipldws_B.c2;
              vipldws_B.c2 = vipldws_B.lastActiveEdgeIdxBdy;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.i;
            }

            vipldws_B.qY_g = vipldws_B.C2 - vipldws_B.yIdx;
            if (vipldws_B.c2 <= vipldws_B.lastActiveEdgeIdxBdy) {
              vipldws_B.qY = 1;
              vipldws_B.lastActiveEdgeIdxBdy -= vipldws_B.c2;
            } else {
              vipldws_B.qY = -1;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.c2 -
                vipldws_B.lastActiveEdgeIdxBdy;
            }

            vipldws_B.activeColBdy = vipldws_B.c2 - 4;
            vipldws_B.activeCol = -((vipldws_B.qY_g + 1) >> 1);
            if (vipldws_B.r2 != 1) {
              vipldws_B.colBoundary = 2559;
            } else {
              vipldws_B.colBoundary = 1919;
            }

            vipldws_B.c1 = vipldws_B.yIdx >> 3;
            vipldws_B.ii = ((vipldws_B.c1 + 1) << 3) - vipldws_B.yIdx;
            vipldws_B.firstRowOut = 320;
            vipldws_B.lastRowOut = 0;
            memset(&vipldws_DW.DrawShapes_DW_PixCount[0], 0, 320U * sizeof
                   (uint8_T));
            done = (vipldws_B.yIdx <= vipldws_B.C2);
            while (done) {
              vipldws_B.ii--;
              vipldws_B.numEdge = vipldws_B.activeColBdy;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next sub-pixel location. */
              vipldws_B.activeCol += vipldws_B.lastActiveEdgeIdxBdy;
              if (vipldws_B.activeCol >= 0) {
                vipldws_B.activeColBdy += vipldws_B.qY;
                vipldws_B.activeCol -= vipldws_B.qY_g;
              }

              vipldws_B.yIdx++;
              done = (vipldws_B.yIdx <= vipldws_B.C2);
              if (done) {
                vipldws_B.col = vipldws_B.numEdge + 7;
                if ((vipldws_B.numEdge + 7 > 0) && (vipldws_B.numEdge <
                     vipldws_B.colBoundary)) {
                  if (vipldws_B.numEdge < 0) {
                    vipldws_B.numEdge = 0;
                  }

                  if (vipldws_B.col > vipldws_B.colBoundary) {
                    vipldws_B.col = vipldws_B.colBoundary;
                  }

                  vipldws_B.C1 = vipldws_B.numEdge >> 3;
                  vipldws_B.i = vipldws_B.col >> 3;
                  if (vipldws_B.firstRowOut > vipldws_B.C1) {
                    vipldws_B.firstRowOut = vipldws_B.C1;
                  }

                  if (vipldws_B.lastRowOut < vipldws_B.i) {
                    vipldws_B.lastRowOut = vipldws_B.i;
                  }

                  if (vipldws_B.i > vipldws_B.C1) {
                    vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                      (((uint32_T)((vipldws_B.C1 + 1) << 3) +
                        vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1]) -
                       vipldws_B.numEdge);
                    vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i] = (uint8_T)
                      ((((uint32_T)vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i]
                         + vipldws_B.col) - (vipldws_B.i << 3)) + 1U);
                    vipldws_B.numEdge = vipldws_B.C1 + 1;
                    while (vipldws_B.numEdge < vipldws_B.i) {
                      vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] =
                        (uint8_T)
                        (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] +
                         8U);
                      vipldws_B.numEdge++;
                    }
                  } else {
                    if (vipldws_B.i == vipldws_B.C1) {
                      vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                        ((((uint32_T)
                           vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] +
                           vipldws_B.col) - vipldws_B.numEdge) + 1U);
                    }
                  }
                }
              }

              if ((vipldws_B.ii == 0) || (!done)) {
                while (vipldws_B.firstRowOut <= vipldws_B.lastRowOut) {
                  vipldws_B.col = vipldws_B.c1 * vipldws_B.r2 +
                    vipldws_B.firstRowOut * vipldws_B.r1;
                  if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] ==
                      64) {
                    vipldws_B.DrawShapes[vipldws_B.col] +=
                      vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.countPeak] -
                      vipldws_B.DrawShapes[vipldws_B.col];
                  } else {
                    vipldws_B.DrawShapes[vipldws_B.col] +=
                      (vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.countPeak] -
                       vipldws_B.DrawShapes[vipldws_B.col]) * (real32_T)
                      vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] /
                      64.0F;
                  }

                  vipldws_B.col += 76800;
                  vipldws_B.C1 = vipldws_B.countPeak + 2;
                  if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] ==
                      64) {
                    vipldws_B.DrawShapes[vipldws_B.col] +=
                      vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                      vipldws_B.DrawShapes[vipldws_B.col];
                  } else {
                    vipldws_B.DrawShapes[vipldws_B.col] +=
                      (vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                       vipldws_B.DrawShapes[vipldws_B.col]) * (real32_T)
                      vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] /
                      64.0F;
                  }

                  vipldws_B.col += 76800;
                  vipldws_B.C1 += 2;
                  if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] ==
                      64) {
                    vipldws_B.DrawShapes[vipldws_B.col] +=
                      vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                      vipldws_B.DrawShapes[vipldws_B.col];
                  } else {
                    vipldws_B.DrawShapes[vipldws_B.col] +=
                      (vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                       vipldws_B.DrawShapes[vipldws_B.col]) * (real32_T)
                      vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] /
                      64.0F;
                  }

                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] = 0U;
                  vipldws_B.firstRowOut++;
                }

                vipldws_B.ii = 8;
                vipldws_B.firstRowOut = 320;
                vipldws_B.lastRowOut = 0;
                vipldws_B.c1++;
              }
            }
          }
        }

        if (vipldws_B.countPeak < 3) {
          vipldws_B.countPeak++;
        } else {
          vipldws_B.countPeak = 0;
        }
      }
    } else {
      /* Compute output for non-unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws_B.DrawShapes[0], &vipldws_B.Switch[0], 230400U * sizeof
             (real32_T));

      /* Update view port. */
      /* ProcessStep-start-1
       */
      if (vipldws_P.DrawShapes_lineWidth_i > 1) {
        /* convertLinePts2PolygonPts
         */
        vipldws_B.numEdge = vipldws_P.DrawShapes_lineWidth_i >> 1;

        /* getLineParams-1
         */
        /* getLineParams-main fcn
         */
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.Transpose1_p[2] -
          vipldws_B.Transpose1_p[6];
        vipldws_B.yIdx = vipldws_B.Transpose1_p[0] - vipldws_B.Transpose1_p[4];
        if (vipldws_B.yIdx == 0) {
          vipldws_B.scale = 0.0F;
          vipldws_B.col = 1;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[0] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[0] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[2] - 1);
        } else if (vipldws_B.lastActiveEdgeIdxBdy == 0) {
          vipldws_B.col = 2;
          vipldws_B.scale = 0.0F;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[2] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[2] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[0] - 1);
        } else {
          vipldws_B.col = 0;
          vipldws_B.scale = (real32_T)vipldws_B.lastActiveEdgeIdxBdy / (real32_T)
            vipldws_B.yIdx;
          vipldws_B.y2 = (real32_T)(vipldws_B.Transpose1_p[2] - 1) - (real32_T)
            (vipldws_B.Transpose1_p[0] - 1) * vipldws_B.scale;
          vipldws_B.acc4_idx_0 = (real32_T)vipldws_B.numEdge / ((real32_T)
            vipldws_B.yIdx / (real32_T)sqrt((real32_T)
            (vipldws_B.lastActiveEdgeIdxBdy * vipldws_B.lastActiveEdgeIdxBdy +
             vipldws_B.yIdx * vipldws_B.yIdx)));
          vipldws_B.cnt = vipldws_B.y2 + vipldws_B.acc4_idx_0;
          vipldws_B.y2 -= vipldws_B.acc4_idx_0;
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[0] - 1) /
            vipldws_B.scale + (real32_T)(vipldws_B.Transpose1_p[2] - 1);
        }

        /* findPointOfIntersectionNormal-1
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.cnt;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.acc4_idx_0 +
                0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.cnt) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt += vipldws_B.scale * vipldws_B.acc1_idx_5;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[0] = vipldws_B.lastActiveEdgeIdxBdy;
        vipldws_DW.DrawShapes_DW_Points[2] = vipldws_B.yIdx;

        /* findPointOfIntersectionNormal-2
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor(vipldws_B.y2 +
                0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.y2;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.y2 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.y2;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.y2) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt = vipldws_B.scale * vipldws_B.acc1_idx_5 + vipldws_B.y2;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.cnt +
                0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[14] = vipldws_B.activeCol;
        vipldws_DW.DrawShapes_DW_Points[12] = vipldws_B.activeColBdy;

        /* getLineParams-2
         */
        /* getLineParams-main fcn
         */
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.Transpose1_p[2] -
          vipldws_B.Transpose1_p[6];
        vipldws_B.yIdx = vipldws_B.Transpose1_p[0] - vipldws_B.Transpose1_p[4];
        if (vipldws_B.yIdx == 0) {
          vipldws_B.scale = 0.0F;
          vipldws_B.col = 1;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[0] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[0] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[6] - 1);
        } else if (vipldws_B.lastActiveEdgeIdxBdy == 0) {
          vipldws_B.col = 2;
          vipldws_B.scale = 0.0F;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[2] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[2] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[4] - 1);
        } else {
          vipldws_B.col = 0;
          vipldws_B.scale = (real32_T)vipldws_B.lastActiveEdgeIdxBdy / (real32_T)
            vipldws_B.yIdx;
          vipldws_B.y2 = (real32_T)(vipldws_B.Transpose1_p[2] - 1) - (real32_T)
            (vipldws_B.Transpose1_p[0] - 1) * vipldws_B.scale;
          vipldws_B.acc4_idx_0 = (real32_T)vipldws_B.numEdge / ((real32_T)
            vipldws_B.yIdx / (real32_T)sqrt((real32_T)
            (vipldws_B.lastActiveEdgeIdxBdy * vipldws_B.lastActiveEdgeIdxBdy +
             vipldws_B.yIdx * vipldws_B.yIdx)));
          vipldws_B.cnt = vipldws_B.y2 + vipldws_B.acc4_idx_0;
          vipldws_B.y2 -= vipldws_B.acc4_idx_0;
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[4] - 1) /
            vipldws_B.scale + (real32_T)(vipldws_B.Transpose1_p[6] - 1);
        }

        /* findPointOfIntersectionNormal-3
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.cnt;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.acc4_idx_0 +
                0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.cnt) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt += vipldws_B.scale * vipldws_B.acc1_idx_5;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[4] = vipldws_B.lastActiveEdgeIdxBdy;
        vipldws_DW.DrawShapes_DW_Points[6] = vipldws_B.yIdx;

        /* findPointOfIntersectionNormal-4
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor(vipldws_B.y2 +
                0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.y2;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.y2 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.y2;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.y2) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt = vipldws_B.scale * vipldws_B.acc1_idx_5 + vipldws_B.y2;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.cnt +
                0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[10] = vipldws_B.activeCol;
        vipldws_DW.DrawShapes_DW_Points[8] = vipldws_B.activeColBdy;
        vipldws_B.numEdge = vipldws_P.DrawShapes_lineWidth_i >> 1;

        /* getLineParams-1
         */
        /* getLineParams-main fcn
         */
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.Transpose1_p[3] -
          vipldws_B.Transpose1_p[7];
        vipldws_B.yIdx = vipldws_B.Transpose1_p[1] - vipldws_B.Transpose1_p[5];
        if (vipldws_B.yIdx == 0) {
          vipldws_B.scale = 0.0F;
          vipldws_B.col = 1;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[1] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[1] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[3] - 1);
        } else if (vipldws_B.lastActiveEdgeIdxBdy == 0) {
          vipldws_B.col = 2;
          vipldws_B.scale = 0.0F;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[3] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[3] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[1] - 1);
        } else {
          vipldws_B.col = 0;
          vipldws_B.scale = (real32_T)vipldws_B.lastActiveEdgeIdxBdy / (real32_T)
            vipldws_B.yIdx;
          vipldws_B.y2 = (real32_T)(vipldws_B.Transpose1_p[3] - 1) - (real32_T)
            (vipldws_B.Transpose1_p[1] - 1) * vipldws_B.scale;
          vipldws_B.acc4_idx_0 = (real32_T)vipldws_B.numEdge / ((real32_T)
            vipldws_B.yIdx / (real32_T)sqrt((real32_T)
            (vipldws_B.lastActiveEdgeIdxBdy * vipldws_B.lastActiveEdgeIdxBdy +
             vipldws_B.yIdx * vipldws_B.yIdx)));
          vipldws_B.cnt = vipldws_B.y2 + vipldws_B.acc4_idx_0;
          vipldws_B.y2 -= vipldws_B.acc4_idx_0;
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[1] - 1) /
            vipldws_B.scale + (real32_T)(vipldws_B.Transpose1_p[3] - 1);
        }

        /* findPointOfIntersectionNormal-1
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.cnt;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.acc4_idx_0 +
                0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.cnt) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt += vipldws_B.scale * vipldws_B.acc1_idx_5;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[1] = vipldws_B.lastActiveEdgeIdxBdy;
        vipldws_DW.DrawShapes_DW_Points[3] = vipldws_B.yIdx;

        /* findPointOfIntersectionNormal-2
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor(vipldws_B.y2 +
                0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.y2;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.y2 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.y2;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.y2) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt = vipldws_B.scale * vipldws_B.acc1_idx_5 + vipldws_B.y2;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.cnt +
                0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[15] = vipldws_B.activeCol;
        vipldws_DW.DrawShapes_DW_Points[13] = vipldws_B.activeColBdy;

        /* getLineParams-2
         */
        /* getLineParams-main fcn
         */
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.Transpose1_p[3] -
          vipldws_B.Transpose1_p[7];
        vipldws_B.yIdx = vipldws_B.Transpose1_p[1] - vipldws_B.Transpose1_p[5];
        if (vipldws_B.yIdx == 0) {
          vipldws_B.scale = 0.0F;
          vipldws_B.col = 1;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[1] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[1] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[7] - 1);
        } else if (vipldws_B.lastActiveEdgeIdxBdy == 0) {
          vipldws_B.col = 2;
          vipldws_B.scale = 0.0F;
          vipldws_B.cnt = (real32_T)((vipldws_B.Transpose1_p[3] -
            vipldws_B.numEdge) - 1);
          vipldws_B.y2 = (real32_T)((vipldws_B.Transpose1_p[3] +
            vipldws_B.numEdge) - 1);
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[5] - 1);
        } else {
          vipldws_B.col = 0;
          vipldws_B.scale = (real32_T)vipldws_B.lastActiveEdgeIdxBdy / (real32_T)
            vipldws_B.yIdx;
          vipldws_B.y2 = (real32_T)(vipldws_B.Transpose1_p[3] - 1) - (real32_T)
            (vipldws_B.Transpose1_p[1] - 1) * vipldws_B.scale;
          vipldws_B.acc4_idx_0 = (real32_T)vipldws_B.numEdge / ((real32_T)
            vipldws_B.yIdx / (real32_T)sqrt((real32_T)
            (vipldws_B.lastActiveEdgeIdxBdy * vipldws_B.lastActiveEdgeIdxBdy +
             vipldws_B.yIdx * vipldws_B.yIdx)));
          vipldws_B.cnt = vipldws_B.y2 + vipldws_B.acc4_idx_0;
          vipldws_B.y2 -= vipldws_B.acc4_idx_0;
          vipldws_B.acc4_idx_0 = (real32_T)(vipldws_B.Transpose1_p[5] - 1) /
            vipldws_B.scale + (real32_T)(vipldws_B.Transpose1_p[7] - 1);
        }

        /* findPointOfIntersectionNormal-3
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.cnt;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.acc4_idx_0 +
                0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.cnt) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws_B.lastActiveEdgeIdxBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt += vipldws_B.scale * vipldws_B.acc1_idx_5;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.yIdx = (int32_T)(real32_T)floor(vipldws_B.cnt + 0.5F);
            } else {
              vipldws_B.yIdx = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.yIdx = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[5] = vipldws_B.lastActiveEdgeIdxBdy;
        vipldws_DW.DrawShapes_DW_Points[7] = vipldws_B.yIdx;

        /* findPointOfIntersectionNormal-4
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor(vipldws_B.y2 +
                0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.y2;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.acc4_idx_0;
          }
        } else if (vipldws_B.col == 2) {
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc4_idx_0);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc4_idx_0;
          }

          vipldws_B.v = (real32_T)fabs(vipldws_B.y2);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.y2 + 0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.y2 * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.y2;
          }
        } else {
          vipldws_B.acc1_idx_5 = (vipldws_B.acc4_idx_0 - vipldws_B.y2) *
            vipldws_B.scale / (vipldws_B.scale * vipldws_B.scale + 1.0F);
          vipldws_B.v = (real32_T)fabs(vipldws_B.acc1_idx_5);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws_B.activeColBdy = (int32_T)(vipldws_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws_B.activeColBdy = (int32_T)vipldws_B.acc1_idx_5;
          }

          vipldws_B.cnt = vipldws_B.scale * vipldws_B.acc1_idx_5 + vipldws_B.y2;
          vipldws_B.v = (real32_T)fabs(vipldws_B.cnt);
          if (vipldws_B.v < 8.388608E+6F) {
            if (vipldws_B.v >= 0.5F) {
              vipldws_B.activeCol = (int32_T)(real32_T)floor(vipldws_B.cnt +
                0.5F);
            } else {
              vipldws_B.activeCol = (int32_T)(vipldws_B.cnt * 0.0F);
            }
          } else {
            vipldws_B.activeCol = (int32_T)vipldws_B.cnt;
          }
        }

        vipldws_DW.DrawShapes_DW_Points[11] = vipldws_B.activeCol;
        vipldws_DW.DrawShapes_DW_Points[9] = vipldws_B.activeColBdy;
      }

      /* ProcessStep-after poly points-1
       */
      vipldws_B.c2 = 2;

      /* just before call for cgpolygon
       */
      if (vipldws_P.DrawShapes_lineWidth_i > 1) {
        /* just before call for cgpolygon-2
         */
        vipldws_B.c2 = 4;
      }

      vipldws_B.c1 = vipldws_B.c2 << 1;
      memset(&vipldws_DW.DrawShapes_DW_PixCount[0], 0, 320U * sizeof(uint8_T));

      /* Reset scanline states. */
      vipldws_B.R2 = 0;
      vipldws_B.C2 = 0;
      vipldws_B.countPeak = 0;
      c_gotAlLeastOneYellowPixelInThe = true;
      while (c_gotAlLeastOneYellowPixelInThe) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        done = false;
        vipldws_B.numEdge = 0;
        vipldws_B.qY_g = vipldws_B.R2;
        vipldws_B.qY = vipldws_B.R2;
        idxTmpArray[0U] = (int8_T)(vipldws_B.c2 - 1);
        vipldws_B.ii = 0;
        while (vipldws_B.ii < 1) {
          /* start for loop
           */
          vipldws_B.lastActiveEdgeIdxBdy = (((idxTmpArray[0] << 1) + 1) << 1) +
            vipldws_B.C2;
          vipldws_B.yIdx = (idxTmpArray[0] << 2) + vipldws_B.C2;
          vipldws_B.firstRowOut = idxTmpArray[0];
          vipldws_B.activeColBdy = ((idxTmpArray[0] - 1) << 2) + vipldws_B.C2;
          vipldws_B.activeCol = vipldws_B.c2;
          if (vipldws_P.DrawShapes_lineWidth_i > 1) {
            /* getLoc-1
             */
            vipldws_B.colBoundary =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];

            /* getLoc-1
             */
            vipldws_B.lastRowOut =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws_B.colBoundary = vipldws_B.Transpose1_p[vipldws_B.yIdx];

            /* getLoc-2
             */
            vipldws_B.lastRowOut = vipldws_B.Transpose1_p[vipldws_B.activeColBdy];
          }

          vipldws_B.i = vipldws_B.lastRowOut;
          while ((vipldws_B.activeColBdy >= 0) && (vipldws_B.colBoundary - 1 ==
                  vipldws_B.i - 1)) {
            vipldws_B.firstRowOut--;
            vipldws_B.activeColBdy = ((vipldws_B.firstRowOut - 1) << 2) +
              vipldws_B.C2;
            vipldws_B.activeCol--;
            if (vipldws_P.DrawShapes_lineWidth_i > 1) {
              /* getLoc-1
               */
              vipldws_B.lastRowOut =
                vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];
            } else {
              /* getLoc-2
               */
              vipldws_B.lastRowOut =
                vipldws_B.Transpose1_p[vipldws_B.activeColBdy];
            }

            vipldws_B.i = vipldws_B.lastRowOut;
          }

          if (vipldws_B.activeColBdy < 0) {
            vipldws_B.activeColBdy = 0;
          }

          if (vipldws_P.DrawShapes_lineWidth_i > 1) {
            /* getLoc-1
             */
            vipldws_B.colBoundary =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];

            /* getLoc-1
             */
            vipldws_B.lastRowOut =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws_B.colBoundary = vipldws_B.Transpose1_p[vipldws_B.yIdx];

            /* getLoc-2
             */
            vipldws_B.lastRowOut = vipldws_B.Transpose1_p[vipldws_B.activeColBdy];
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws_B.lastRowOut - 1 >
            vipldws_B.colBoundary - 1);
          vipldws_B.colOut = 2 + vipldws_B.C2;
          vipldws_B.activeColBdy = vipldws_B.C2;
          prevEdgeIsVertical = false;
          if (vipldws_P.DrawShapes_lineWidth_i > 1) {
            /* getLoc-1
             */
            vipldws_B.colBoundary = vipldws_DW.DrawShapes_DW_Points[vipldws_B.C2];

            /* getLoc-1
             */
            vipldws_B.lastRowOut =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];
          } else {
            /* getLoc-2
             */
            vipldws_B.colBoundary = vipldws_B.Transpose1_p[vipldws_B.C2];

            /* getLoc-2
             */
            vipldws_B.lastRowOut = vipldws_B.Transpose1_p[vipldws_B.yIdx];
          }

          done = (vipldws_B.lastRowOut - 1 == vipldws_B.colBoundary - 1);
          vipldws_B.i = 0;
          while (vipldws_B.i < vipldws_B.activeCol) {
            if (vipldws_P.DrawShapes_lineWidth_i > 1) {
              /* getLoc-1
               */
              vipldws_B.colBoundary =
                vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];

              /* getLoc-1
               */
              vipldws_B.lastRowOut =
                vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];
            } else {
              /* getLoc-2
               */
              vipldws_B.colBoundary =
                vipldws_B.Transpose1_p[vipldws_B.activeColBdy];

              /* getLoc-2
               */
              vipldws_B.lastRowOut = vipldws_B.Transpose1_p[vipldws_B.yIdx];
            }

            if (vipldws_B.lastRowOut - 1 != vipldws_B.colBoundary - 1) {
              if (vipldws_P.DrawShapes_lineWidth_i > 1) {
                /* getLoc-1
                 */
                vipldws_B.colBoundary =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws_B.lastRowOut =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];
              } else {
                /* getLoc-2
                 */
                vipldws_B.colBoundary =
                  vipldws_B.Transpose1_p[vipldws_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws_B.lastRowOut = vipldws_B.Transpose1_p[vipldws_B.yIdx];
              }

              if (vipldws_B.lastRowOut - 1 < vipldws_B.colBoundary - 1) {
                countTwice = false;
              } else {
                countTwice = true;
                vipldws_B.firstRowOut = vipldws_B.lastActiveEdgeIdxBdy;
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
                vipldws_B.colOut = vipldws_B.firstRowOut;
                vipldws_B.firstRowOut = vipldws_B.yIdx;
                vipldws_B.yIdx = vipldws_B.activeColBdy;
                vipldws_B.activeColBdy = vipldws_B.firstRowOut;
              }

              if (vipldws_P.DrawShapes_lineWidth_i > 1) {
                /* getLoc-1
                 */
                vipldws_B.colBoundary =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws_B.lastRowOut =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.colOut];

                /* getLoc-1
                 */
                vipldws_B.lastRow =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];

                /* getLoc-1
                 */
                vipldws_B.firstRowOut =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.lastActiveEdgeIdxBdy];
              } else {
                /* getLoc-2
                 */
                vipldws_B.colBoundary =
                  vipldws_B.Transpose1_p[vipldws_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws_B.lastRowOut = vipldws_B.Transpose1_p[vipldws_B.colOut];

                /* getLoc-2
                 */
                vipldws_B.lastRow = vipldws_B.Transpose1_p[vipldws_B.yIdx];

                /* getLoc-2
                 */
                vipldws_B.firstRowOut =
                  vipldws_B.Transpose1_p[vipldws_B.lastActiveEdgeIdxBdy];
              }

              /* Initialize a Bresenham line. */
              vipldws_B.firstRowOut = ((vipldws_B.firstRowOut - 1) << 3) + 4;
              vipldws_B.lastRow = ((vipldws_B.lastRow - 1) << 3) + 4;
              vipldws_B.lastRowOut = ((vipldws_B.lastRowOut - 1) << 3) + 4;
              vipldws_B.colBoundary = ((vipldws_B.colBoundary - 1) << 3) + 4;
              vipldws_B.firstRow = vipldws_B.colBoundary - vipldws_B.lastRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] = 0;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] =
                vipldws_B.firstRowOut;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2] =
                vipldws_B.lastRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] =
                vipldws_B.colBoundary;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] = 0;
              if (vipldws_B.lastRowOut >= vipldws_B.firstRowOut) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] =
                  vipldws_B.lastRowOut - vipldws_B.firstRowOut;
              } else {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] =
                  vipldws_B.firstRowOut - vipldws_B.lastRowOut;
              }

              while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] >= 0) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6]++;
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] -=
                  vipldws_B.firstRow;
              }

              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] - 1;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] +
                vipldws_B.firstRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 4] =
                vipldws_B.firstRow -
                (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7] << 1);
              if (vipldws_B.firstRowOut > vipldws_B.lastRowOut) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5] =
                  -vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] =
                  -vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6];
              }

              if ((!c_gotAlLeastOneYellowPixelInThe) && (!countTwice)) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2]++;
                if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] << 1) >
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 4]) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6];
                } else {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5];
                }
              } else {
                if (c_gotAlLeastOneYellowPixelInThe && countTwice) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3]--;
                }
              }

              c_gotAlLeastOneYellowPixelInThe = countTwice;
              if (!prevEdgeIsVertical) {
                /* Merge two Bresenham lines. */
                if ((vipldws_B.qY_g != vipldws_B.qY) &&
                    ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 5] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 6] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 7] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 8] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8]))) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] + 1 ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2]) {
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] =
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3];
                    prevEdgeIsVertical = true;
                  } else {
                    if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] + 1 ==
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2]) {
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 1] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2];
                      prevEdgeIsVertical = true;
                    }
                  }
                }

                if (!prevEdgeIsVertical) {
                  vipldws_B.qY_g = vipldws_B.qY;
                  vipldws_B.numEdge++;
                }
              } else {
                vipldws_B.qY_g = vipldws_B.qY;
                vipldws_B.numEdge++;
              }

              vipldws_B.qY = vipldws_B.qY_g + 9;
              if (!countTwice) {
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
                vipldws_B.yIdx = vipldws_B.activeColBdy;
              }

              vipldws_B.colOut = vipldws_B.lastActiveEdgeIdxBdy + 4;
              vipldws_B.activeColBdy = vipldws_B.yIdx + 4;
              prevEdgeIsVertical = false;
            } else {
              prevEdgeIsVertical = true;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
              vipldws_B.yIdx = vipldws_B.activeColBdy;
              vipldws_B.colOut += 4;
              vipldws_B.activeColBdy += 4;
            }

            vipldws_B.i++;
          }

          vipldws_B.ii = 1;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((vipldws_B.R2 != vipldws_B.qY_g) &&
              ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 5] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 5]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 6] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 6]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 7] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 7]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 8] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 8]))) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3] + 1 ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2]) {
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3];
              done = true;
            } else {
              if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] + 1 ==
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2]) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 1] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 1];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2];
                done = true;
              }
            }
          }

          if (done) {
            vipldws_B.numEdge--;
            vipldws_B.qY -= 9;
          }
        }

        /* Set all other edges to invalid. */
        vipldws_B.i = vipldws_B.numEdge;
        while (vipldws_B.i < vipldws_B.c2) {
          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2] = 1;
          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] = 0;
          vipldws_B.qY += 9;
          vipldws_B.i++;
        }

        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws_B.r1 = vipldws_B.R2;
          vipldws_B.r2 = vipldws_B.R2 + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.i = 1;
          while (vipldws_B.i < vipldws_B.numEdge) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 2] >
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_B.lastSeparator =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii] =
                  vipldws_B.lastSeparator;
              }
            }

            vipldws_B.r1 = vipldws_B.r2;
            vipldws_B.r2 += 9;
            vipldws_B.i++;
          }
        }

        /* Find out the last column of the polygon. */
        vipldws_B.C1 = vipldws_B.R2 + 3;
        vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3];
        vipldws_B.i = 1;
        while (vipldws_B.i < vipldws_B.numEdge) {
          vipldws_B.C1 += 9;
          if (vipldws_B.qY_g < vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1]) {
            vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1];
          }

          vipldws_B.i++;
        }

        vipldws_B.qY = vipldws_B.qY_g;
        if (vipldws_B.qY_g > 1919) {
          vipldws_B.qY = 1919;
        }

        /* Find out the first column of the polygon. */
        vipldws_B.C1 = vipldws_B.R2 + 2;
        vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2];
        vipldws_B.i = 1;
        while (vipldws_B.i < vipldws_B.numEdge) {
          vipldws_B.C1 += 9;
          if (vipldws_B.qY_g > vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1]) {
            vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1];
          }

          vipldws_B.i++;
        }

        if (vipldws_B.qY_g < 0) {
          vipldws_B.qY_g = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        vipldws_B.r1 = vipldws_B.R2;
        vipldws_B.r2 = vipldws_B.R2;
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.R2;
        vipldws_B.yIdx = 0;
        vipldws_B.C1 = 0;
        vipldws_B.i = 0;
        while (vipldws_B.i < vipldws_B.numEdge) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 3] >=
              vipldws_B.qY_g) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <=
                vipldws_B.qY_g) {
              while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <
                     vipldws_B.qY_g) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]++;
                if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] << 1) >
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 4]) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 8];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 6];
                } else {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 7];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 5];
                }
              }

              vipldws_B.lastActiveEdgeIdxBdy += 9;
              vipldws_B.C1++;
            }

            if (vipldws_B.r2 != vipldws_B.r1) {
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
              }
            }

            vipldws_B.r1 += 9;
            vipldws_B.yIdx++;
          }

          vipldws_B.r2 += 9;
          vipldws_B.i++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws_B.r1 = vipldws_B.R2;
          vipldws_B.r2 = vipldws_B.R2 + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.i = 1;
          while (vipldws_B.i < vipldws_B.C1) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1] >
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_B.lastSeparator =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii] =
                  vipldws_B.lastSeparator;
              }
            }

            vipldws_B.r1 = vipldws_B.r2;
            vipldws_B.r2 += 9;
            vipldws_B.i++;
          }
        }

        vipldws_B.r1 = vipldws_B.R2;
        vipldws_B.activeColBdy = vipldws_B.qY_g + 1;
        vipldws_B.activeCol = 0;
        vipldws_B.r2 = 0;
        vipldws_B.lastSeparator = -1;
        vipldws_B.colOut = vipldws_B.qY_g >> 3;
        vipldws_B.colBoundary = (vipldws_B.colOut + 1) << 3;
        vipldws_B.firstRowOut = 320;
        vipldws_B.lastRowOut = 0;
        c_gotAlLeastOneYellowPixelInThe = (0 <= vipldws_B.qY);
        while (c_gotAlLeastOneYellowPixelInThe) {
          /* Get a string of pixels */
          countTwice = false;
          done = (vipldws_B.r2 != 0);
          vipldws_B.col = vipldws_B.activeCol;
          if ((vipldws_B.activeCol >= vipldws_B.qY_g) && (vipldws_B.activeCol <=
               vipldws_B.qY)) {
            if (vipldws_B.r1 < vipldws_B.lastActiveEdgeIdxBdy) {
              vipldws_B.i = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1];
              vipldws_B.r1 += 9;
              if ((vipldws_B.i == vipldws_B.lastSeparator) && (vipldws_B.r1 <
                   vipldws_B.lastActiveEdgeIdxBdy)) {
                vipldws_B.C1 = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1];
                c_gotAlLeastOneYellowPixelInThe = (vipldws_B.r1 <
                  vipldws_B.lastActiveEdgeIdxBdy);
                while (c_gotAlLeastOneYellowPixelInThe && (vipldws_B.i ==
                        vipldws_B.C1)) {
                  countTwice = true;
                  vipldws_B.i = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                    1];
                  vipldws_B.r1 += 9;
                  c_gotAlLeastOneYellowPixelInThe = (vipldws_B.r1 <
                    vipldws_B.lastActiveEdgeIdxBdy);
                  if (c_gotAlLeastOneYellowPixelInThe) {
                    vipldws_B.C1 = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1
                      + 1];
                  }
                }

                if (!c_gotAlLeastOneYellowPixelInThe) {
                  countTwice = false;
                }
              }

              if (vipldws_B.r2 != 0) {
                vipldws_B.firstRow = vipldws_B.lastSeparator;
                if (vipldws_B.i <= 2559) {
                  vipldws_B.lastRow = vipldws_B.i;
                  vipldws_B.lastSeparator = vipldws_B.i;
                } else {
                  vipldws_B.lastRow = 2559;
                  vipldws_B.lastSeparator = 2559;
                }
              } else {
                vipldws_B.firstRow = vipldws_B.lastSeparator + 1;
                if ((vipldws_B.i > 0) && (vipldws_B.i <= 2559)) {
                  vipldws_B.lastRow = vipldws_B.i - 1;
                  vipldws_B.lastSeparator = vipldws_B.i;
                } else if (vipldws_B.i <= 0) {
                  vipldws_B.lastRow = -1;
                  vipldws_B.lastSeparator = 0;
                } else {
                  vipldws_B.lastRow = 2559;
                  vipldws_B.lastSeparator = 2560;
                }
              }

              if (!countTwice) {
                vipldws_B.r2 = !(vipldws_B.r2 != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              vipldws_B.firstRow = vipldws_B.lastSeparator + 1;
              vipldws_B.lastRow = 2559;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              vipldws_B.r1 = vipldws_B.R2;
              vipldws_B.r2 = vipldws_B.R2;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.R2;
              vipldws_B.numEdge = 0;
              vipldws_B.C1 = 0;
              vipldws_B.i = 0;
              while (vipldws_B.i < vipldws_B.yIdx) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 3] >=
                    vipldws_B.activeColBdy) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <=
                      vipldws_B.activeColBdy) {
                    while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <
                           vipldws_B.activeColBdy) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]++;
                      if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] << 1) >
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 4]) {
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 8];
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 6];
                      } else {
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 7];
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 5];
                      }
                    }

                    vipldws_B.lastActiveEdgeIdxBdy += 9;
                    vipldws_B.C1++;
                  }

                  if (vipldws_B.r2 != vipldws_B.r1) {
                    for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii];
                    }
                  }

                  vipldws_B.r1 += 9;
                  vipldws_B.numEdge++;
                }

                vipldws_B.r2 += 9;
                vipldws_B.i++;
              }

              vipldws_B.yIdx = vipldws_B.numEdge;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (c_gotAlLeastOneYellowPixelInThe) {
                vipldws_B.r1 = vipldws_B.R2;
                vipldws_B.r2 = vipldws_B.R2 + 9;
                c_gotAlLeastOneYellowPixelInThe = false;
                vipldws_B.i = 1;
                while (vipldws_B.i < vipldws_B.C1) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1] >
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1]) {
                    c_gotAlLeastOneYellowPixelInThe = true;
                    for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                      vipldws_B.lastSeparator =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii] = vipldws_B.lastSeparator;
                    }
                  }

                  vipldws_B.r1 = vipldws_B.r2;
                  vipldws_B.r2 += 9;
                  vipldws_B.i++;
                }
              }

              vipldws_B.r1 = vipldws_B.R2;
              vipldws_B.activeColBdy++;
              vipldws_B.r2 = 0;
              vipldws_B.lastSeparator = -1;
              vipldws_B.activeCol++;
            }
          } else {
            vipldws_B.firstRow = 0;
            vipldws_B.lastRow = 2559;
            vipldws_B.activeCol++;
          }

          if (vipldws_B.firstRow < 0) {
            vipldws_B.firstRow = 0;
          }

          if (vipldws_B.lastRow < vipldws_B.firstRow) {
            vipldws_B.lastRow = vipldws_B.firstRow - 1;
          }

          if (done && ((vipldws_B.lastRow > 0) && (vipldws_B.firstRow < 2559)))
          {
            if (vipldws_B.lastRow > 2559) {
              vipldws_B.lastRow = 2559;
            }

            vipldws_B.C1 = vipldws_B.firstRow >> 3;
            vipldws_B.i = vipldws_B.lastRow >> 3;
            if (vipldws_B.firstRowOut > vipldws_B.C1) {
              vipldws_B.firstRowOut = vipldws_B.C1;
            }

            if (vipldws_B.lastRowOut < vipldws_B.i) {
              vipldws_B.lastRowOut = vipldws_B.i;
            }

            if (vipldws_B.i > vipldws_B.C1) {
              vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                (((uint32_T)((vipldws_B.C1 + 1) << 3) +
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1]) -
                 vipldws_B.firstRow);
              vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i] = (uint8_T)
                ((((uint32_T)vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i] +
                   vipldws_B.lastRow) - (vipldws_B.i << 3)) + 1U);
              vipldws_B.numEdge = vipldws_B.C1 + 1;
              while (vipldws_B.numEdge < vipldws_B.i) {
                vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] = (uint8_T)
                  (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] + 8U);
                vipldws_B.numEdge++;
              }
            } else {
              if (vipldws_B.i == vipldws_B.C1) {
                vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                  ((((uint32_T)vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] +
                     vipldws_B.lastRow) - vipldws_B.firstRow) + 1U);
              }
            }
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws_B.activeCol <= vipldws_B.qY);
          if (((vipldws_B.colBoundary - 1 == vipldws_B.col) ||
               (!c_gotAlLeastOneYellowPixelInThe)) && (vipldws_B.lastRow >= 2559))
          {
            vipldws_B.ii = vipldws_B.colOut * 320 + vipldws_B.firstRowOut;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.numEdge = vipldws_B.firstRowOut;
            while (vipldws_B.numEdge <= vipldws_B.lastRowOut) {
              if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] == 64) {
                vipldws_B.DrawShapes[vipldws_B.col] +=
                  vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.countPeak] -
                  vipldws_B.DrawShapes[vipldws_B.col];
              } else {
                vipldws_B.DrawShapes[vipldws_B.col] +=
                  (vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.countPeak] -
                   vipldws_B.DrawShapes[vipldws_B.col]) * (real32_T)
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] / 64.0F;
              }

              vipldws_B.col++;
              vipldws_B.numEdge++;
            }

            vipldws_B.ii += 76800;
            vipldws_B.C1 = vipldws_B.countPeak + 2;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.numEdge = vipldws_B.firstRowOut;
            while (vipldws_B.numEdge <= vipldws_B.lastRowOut) {
              if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] == 64) {
                vipldws_B.DrawShapes[vipldws_B.col] +=
                  vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                  vipldws_B.DrawShapes[vipldws_B.col];
              } else {
                vipldws_B.DrawShapes[vipldws_B.col] +=
                  (vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                   vipldws_B.DrawShapes[vipldws_B.col]) * (real32_T)
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] / 64.0F;
              }

              vipldws_B.col++;
              vipldws_B.numEdge++;
            }

            vipldws_B.ii += 76800;
            vipldws_B.C1 += 2;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.numEdge = vipldws_B.firstRowOut;
            while (vipldws_B.numEdge <= vipldws_B.lastRowOut) {
              if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] == 64) {
                vipldws_B.DrawShapes[vipldws_B.col] +=
                  vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                  vipldws_B.DrawShapes[vipldws_B.col];
              } else {
                vipldws_B.DrawShapes[vipldws_B.col] +=
                  (vipldws_P.DrawShapes_RTP_FILLCOLOR[vipldws_B.C1] -
                   vipldws_B.DrawShapes[vipldws_B.col]) * (real32_T)
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] / 64.0F;
              }

              vipldws_B.col++;
              vipldws_B.numEdge++;
            }

            while (vipldws_B.firstRowOut <= vipldws_B.lastRowOut) {
              vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] = 0U;
              vipldws_B.firstRowOut++;
            }

            vipldws_B.colOut++;
            vipldws_B.colBoundary += 8;
            vipldws_B.firstRowOut = 320;
            vipldws_B.lastRowOut = 0;
          }
        }

        if (vipldws_B.countPeak < 3) {
          vipldws_B.countPeak++;
        } else {
          vipldws_B.countPeak = 0;
        }

        /* Move to the next polygon. */
        vipldws_B.R2 += vipldws_B.c2 * 9;
        if (vipldws_B.C2 >= div_s32_floor(vipldws_B.c1, vipldws_B.c2) - 1) {
          vipldws_B.C2 = 0;
        } else {
          vipldws_B.C2++;
        }

        c_gotAlLeastOneYellowPixelInThe = (vipldws_B.R2 < (vipldws_B.c2 << 1) *
          9);
      }
    }

    /* End of S-Function (svipdrawshapes): '<S65>/DrawShapes' */

    /* FromWorkspace: '<S68>/From Workspace' */
    {
      int_T currIndex = vipldws_DW.FromWorkspace_IWORK.PrevIndex+1;
      real32_T *pDataValues = (real32_T *)
        vipldws_DW.FromWorkspace_PWORK.DataPtr;
      if (currIndex >= 4) {
        currIndex = 0;
      }

      if (currIndex < 4) {
        pDataValues += currIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&vipldws_B.Selector5[0])[elIdx] = *pDataValues;
            pDataValues += 4;
          }
        }
      } else {
        pDataValues += (3);

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&vipldws_B.Selector5[0])[elIdx] = *pDataValues;
            pDataValues += 4;
          }
        }
      }

      vipldws_DW.FromWorkspace_IWORK.PrevIndex = currIndex;
    }

    /* S-Function (sviptextrender): '<S65>/Insert Text' */
    /* put the pen at the beginning of the string */
    vipldws_B.countPeak = 1;

    /* copy input to output since Simulink isn't giving us in-place operation */
    memcpy(&vipldws_B.InsertText[0], &vipldws_B.DrawShapes[0], 230400U * sizeof
           (real32_T));
    done = false;
    while (vipldws_B.countPeak > 0) {
      c_gotAlLeastOneYellowPixelInThe = true;
      if (vipldws_P.InsertText_TxtOpacity == 0.0F) {
        c_gotAlLeastOneYellowPixelInThe = false;
      }

      /* copy location to int32 container */
      vipldws_B.C1 = vipldws_P.InsertText_textLoc[0] - 1;

      /* update the color/intensity */
      vipldws_DW.InsertText_colorVectorDW[0] = vipldws_B.Selector5[0];

      /* Saturate color values */
      if (vipldws_DW.InsertText_colorVectorDW[0] < 0.0F) {
        vipldws_DW.InsertText_colorVectorDW[0] = 0.0F;
      } else {
        if (vipldws_DW.InsertText_colorVectorDW[0] > 1.0F) {
          vipldws_DW.InsertText_colorVectorDW[0] = 1.0F;
        }
      }

      vipldws_DW.InsertText_colorVectorDW[1] = vipldws_B.Selector5[1];

      /* Saturate color values */
      if (vipldws_DW.InsertText_colorVectorDW[1] < 0.0F) {
        vipldws_DW.InsertText_colorVectorDW[1] = 0.0F;
      } else {
        if (vipldws_DW.InsertText_colorVectorDW[1] > 1.0F) {
          vipldws_DW.InsertText_colorVectorDW[1] = 1.0F;
        }
      }

      vipldws_DW.InsertText_colorVectorDW[2] = vipldws_B.Selector5[2];

      /* Saturate color values */
      if (vipldws_DW.InsertText_colorVectorDW[2] < 0.0F) {
        vipldws_DW.InsertText_colorVectorDW[2] = 0.0F;
      } else {
        if (vipldws_DW.InsertText_colorVectorDW[2] > 1.0F) {
          vipldws_DW.InsertText_colorVectorDW[2] = 1.0F;
        }
      }

      /* copy selection to uint32 container */
      vipldws_B.fromIdx = vipldws_B.Bias_h - 1U;
      if (vipldws_B.fromIdx >= 3U) {
        done = true;
        vipldws_B.countPeak = -1;
      } else {
        vipldws_B.textIdx = (int32_T)
          vipldws_ConstP.InsertText_stringRTP[vipldws_B.fromIdx];
      }

      if (!done) {
        vipldws_B.i = MWVIP_strlen
          (&vipldws_DW.InsertText_StringDataDW[vipldws_B.textIdx]);
        vipldws_B.countPeak = 0;
        if (c_gotAlLeastOneYellowPixelInThe) {
          /* put the pen at the beginning of the string */
          vipldws_B.C2 = vipldws_P.InsertText_textLoc[0] - 1;
          vipldws_B.c2 = vipldws_P.InsertText_textLoc[1];
          vipldws_B.c1 = 0;
          while (vipldws_B.c1 < vipldws_B.i) {
            if (vipldws_DW.InsertText_StringDataDW[vipldws_B.textIdx +
                vipldws_B.c1] == 10) {
              vipldws_B.c2 += 23;
              vipldws_B.C2 = vipldws_B.C1;
            } else {
              vipldws_B.r2 =
                vipldws_DW.InsertText_StringDataDW[vipldws_B.textIdx +
                vipldws_B.c1];
              vipldws_B.r1 = (int32_T)
                vipldws_ConstP.InsertText_GlyIndexes[vipldws_B.r2];
              if (!((vipldws_ConstP.InsertText_GlyWidths[vipldws_B.r2] != 0) &&
                    (vipldws_ConstP.InsertText_GlyHeights[vipldws_B.r2] != 0) &&
                    (vipldws_ConstP.InsertText_GlyXAdvances[vipldws_B.r2] != 0)))
              {
                vipldws_B.r2 = 32;
                vipldws_B.r1 = 0;
              }

              vipldws_B.scale = vipldws_P.InsertText_TxtOpacity;
              MWVIP_DrawText_I_single_AA
                (&vipldws_ConstP.InsertText_GlyData[vipldws_B.r1], vipldws_B.C2,
                 vipldws_B.c2 + 18,
                 vipldws_ConstP.InsertText_GlyLBearings[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyTBearings[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyWidths[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyHeights[vipldws_B.r2], 240U, 320U,
                 &vipldws_B.InsertText[0], &vipldws_DW.InsertText_colorVectorDW
                 [0], &vipldws_B.scale, false);
              MWVIP_DrawText_I_single_AA
                (&vipldws_ConstP.InsertText_GlyData[vipldws_B.r1], vipldws_B.C2,
                 vipldws_B.c2 + 18,
                 vipldws_ConstP.InsertText_GlyLBearings[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyTBearings[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyWidths[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyHeights[vipldws_B.r2], 240U, 320U,
                 &vipldws_B.InsertText[76800],
                 &vipldws_DW.InsertText_colorVectorDW[1], &vipldws_B.scale,
                 false);
              MWVIP_DrawText_I_single_AA
                (&vipldws_ConstP.InsertText_GlyData[vipldws_B.r1], vipldws_B.C2,
                 vipldws_B.c2 + 18,
                 vipldws_ConstP.InsertText_GlyLBearings[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyTBearings[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyWidths[vipldws_B.r2],
                 vipldws_ConstP.InsertText_GlyHeights[vipldws_B.r2], 240U, 320U,
                 &vipldws_B.InsertText[153600],
                 &vipldws_DW.InsertText_colorVectorDW[2], &vipldws_B.scale,
                 false);
              vipldws_B.C2 +=
                vipldws_ConstP.InsertText_GlyXAdvances[vipldws_B.r2];
            }

            vipldws_B.c1++;
          }
        }
      }
    }

    /* End of S-Function (sviptextrender): '<S65>/Insert Text' */

    /* Selector: '<S67>/Selector4' incorporates:
     *  Constant: '<S67>/Yellow1'
     */
    vipldws_B.Selector5[0] = vipldws_P.Yellow1_Value[(vipldws_B.Bias1_j[0] - 1) *
      3];
    vipldws_B.Selector5[1] = vipldws_P.Yellow1_Value[(vipldws_B.Bias1_j[0] - 1) *
      3 + 1];
    vipldws_B.Selector5[2] = vipldws_P.Yellow1_Value[(vipldws_B.Bias1_j[0] - 1) *
      3 + 2];

    /* Selector: '<S67>/Selector6' */
    vipldws_B.Selector7[0] = vipldws_B.Transpose2[1];
    vipldws_B.Selector7[1] = vipldws_B.Transpose2[0];

    /* Math: '<S67>/Transpose1' */
    vipldws_B.Transpose2[0] = vipldws_B.Selector7[0];
    vipldws_B.Transpose2[1] = vipldws_B.Selector7[1];

    /* S-Function (sviptextrender): '<S67>/Insert Text: Left Lane' */
    /* put the pen at the beginning of the string */
    vipldws_B.countPeak = 1;

    /* copy input to output since Simulink isn't giving us in-place operation */
    memcpy(&vipldws_B.InsertTextLeftLane[0], &vipldws_B.InsertText[0], 230400U *
           sizeof(real32_T));
    done = false;
    while (vipldws_B.countPeak > 0) {
      c_gotAlLeastOneYellowPixelInThe = true;
      if (vipldws_P.InsertTextLeftLane_TxtOpacity == 0.0F) {
        c_gotAlLeastOneYellowPixelInThe = false;
      }

      /* copy location to int32 container */
      vipldws_B.C1 = vipldws_B.Transpose2[0] - 1;

      /* update the color/intensity */
      vipldws_DW.InsertTextLeftLane_colorVectorD[0] = vipldws_B.Selector5[0];

      /* Saturate color values */
      if (vipldws_DW.InsertTextLeftLane_colorVectorD[0] < 0.0F) {
        vipldws_DW.InsertTextLeftLane_colorVectorD[0] = 0.0F;
      } else {
        if (vipldws_DW.InsertTextLeftLane_colorVectorD[0] > 1.0F) {
          vipldws_DW.InsertTextLeftLane_colorVectorD[0] = 1.0F;
        }
      }

      vipldws_DW.InsertTextLeftLane_colorVectorD[1] = vipldws_B.Selector5[1];

      /* Saturate color values */
      if (vipldws_DW.InsertTextLeftLane_colorVectorD[1] < 0.0F) {
        vipldws_DW.InsertTextLeftLane_colorVectorD[1] = 0.0F;
      } else {
        if (vipldws_DW.InsertTextLeftLane_colorVectorD[1] > 1.0F) {
          vipldws_DW.InsertTextLeftLane_colorVectorD[1] = 1.0F;
        }
      }

      vipldws_DW.InsertTextLeftLane_colorVectorD[2] = vipldws_B.Selector5[2];

      /* Saturate color values */
      if (vipldws_DW.InsertTextLeftLane_colorVectorD[2] < 0.0F) {
        vipldws_DW.InsertTextLeftLane_colorVectorD[2] = 0.0F;
      } else {
        if (vipldws_DW.InsertTextLeftLane_colorVectorD[2] > 1.0F) {
          vipldws_DW.InsertTextLeftLane_colorVectorD[2] = 1.0F;
        }
      }

      /* copy selection to uint32 container */
      vipldws_B.fromIdx = vipldws_B.Bias1_j[0] - 1U;
      if (vipldws_B.fromIdx >= 5U) {
        done = true;
        vipldws_B.countPeak = -1;
      } else {
        vipldws_B.textIdx_f = (int32_T)vipldws_ConstP.pooled9[vipldws_B.fromIdx];
      }

      if (!done) {
        vipldws_B.i = MWVIP_strlen
          (&vipldws_DW.InsertTextLeftLane_StringDataDW[vipldws_B.textIdx_f]);
        vipldws_B.countPeak = 0;
        if (c_gotAlLeastOneYellowPixelInThe) {
          /* put the pen at the beginning of the string */
          vipldws_B.C2 = vipldws_B.Transpose2[0] - 1;
          vipldws_B.c2 = vipldws_B.Transpose2[1];
          vipldws_B.c1 = 0;
          while (vipldws_B.c1 < vipldws_B.i) {
            if (vipldws_DW.InsertTextLeftLane_StringDataDW[vipldws_B.textIdx_f +
                vipldws_B.c1] == 10) {
              vipldws_B.c2 += 16;
              vipldws_B.C2 = vipldws_B.C1;
            } else {
              vipldws_B.r2 =
                vipldws_DW.InsertTextLeftLane_StringDataDW[vipldws_B.textIdx_f +
                vipldws_B.c1];
              vipldws_B.r1 = (int32_T)vipldws_ConstP.pooled8[vipldws_B.r2];
              if (!((vipldws_ConstP.pooled11[vipldws_B.r2] != 0) &&
                    (vipldws_ConstP.pooled12[vipldws_B.r2] != 0) &&
                    (vipldws_ConstP.pooled13[vipldws_B.r2] != 0))) {
                vipldws_B.r2 = 32;
                vipldws_B.r1 = 0;
              }

              vipldws_B.scale = vipldws_P.InsertTextLeftLane_TxtOpacity;
              MWVIP_DrawText_I_single_AA(&vipldws_ConstP.pooled16[vipldws_B.r1],
                vipldws_B.C2, vipldws_B.c2 + 12,
                vipldws_ConstP.pooled2[vipldws_B.r2],
                vipldws_ConstP.pooled3[vipldws_B.r2],
                vipldws_ConstP.pooled11[vipldws_B.r2],
                vipldws_ConstP.pooled12[vipldws_B.r2], 240U, 320U,
                &vipldws_B.InsertTextLeftLane[0],
                &vipldws_DW.InsertTextLeftLane_colorVectorD[0], &vipldws_B.scale,
                false);
              MWVIP_DrawText_I_single_AA(&vipldws_ConstP.pooled16[vipldws_B.r1],
                vipldws_B.C2, vipldws_B.c2 + 12,
                vipldws_ConstP.pooled2[vipldws_B.r2],
                vipldws_ConstP.pooled3[vipldws_B.r2],
                vipldws_ConstP.pooled11[vipldws_B.r2],
                vipldws_ConstP.pooled12[vipldws_B.r2], 240U, 320U,
                &vipldws_B.InsertTextLeftLane[76800],
                &vipldws_DW.InsertTextLeftLane_colorVectorD[1], &vipldws_B.scale,
                false);
              MWVIP_DrawText_I_single_AA(&vipldws_ConstP.pooled16[vipldws_B.r1],
                vipldws_B.C2, vipldws_B.c2 + 12,
                vipldws_ConstP.pooled2[vipldws_B.r2],
                vipldws_ConstP.pooled3[vipldws_B.r2],
                vipldws_ConstP.pooled11[vipldws_B.r2],
                vipldws_ConstP.pooled12[vipldws_B.r2], 240U, 320U,
                &vipldws_B.InsertTextLeftLane[153600],
                &vipldws_DW.InsertTextLeftLane_colorVectorD[2], &vipldws_B.scale,
                false);
              vipldws_B.C2 += vipldws_ConstP.pooled13[vipldws_B.r2];
            }

            vipldws_B.c1++;
          }
        }
      }
    }

    /* End of S-Function (sviptextrender): '<S67>/Insert Text: Left Lane' */

    /* Selector: '<S67>/Selector5' incorporates:
     *  Constant: '<S67>/Yellow1'
     */
    vipldws_B.Selector5[0] = vipldws_P.Yellow1_Value[(vipldws_B.Bias1_j[1] - 1) *
      3];
    vipldws_B.Selector5[1] = vipldws_P.Yellow1_Value[(vipldws_B.Bias1_j[1] - 1) *
      3 + 1];
    vipldws_B.Selector5[2] = vipldws_P.Yellow1_Value[(vipldws_B.Bias1_j[1] - 1) *
      3 + 2];

    /* Selector: '<S67>/Selector7' */
    vipldws_B.Selector7[0] = vipldws_B.Bias2[1];

    /* Math: '<S67>/Transpose2' */
    vipldws_B.Transpose2[0] = vipldws_B.Selector7[0];

    /* Selector: '<S67>/Selector7' */
    vipldws_B.Selector7[1] = vipldws_B.Bias2[0];

    /* Math: '<S67>/Transpose2' */
    vipldws_B.Transpose2[1] = vipldws_B.Selector7[1];

    /* S-Function (sviptextrender): '<S67>/Insert Text: Right Lane' */
    /* put the pen at the beginning of the string */
    vipldws_B.countPeak = 1;

    /* copy input to output since Simulink isn't giving us in-place operation */
    memcpy(&vipldws_B.InsertTextRightLane[0], &vipldws_B.InsertTextLeftLane[0],
           230400U * sizeof(real32_T));
    done = false;
    while (vipldws_B.countPeak > 0) {
      c_gotAlLeastOneYellowPixelInThe = true;
      if (vipldws_P.InsertTextRightLane_TxtOpacity == 0.0F) {
        c_gotAlLeastOneYellowPixelInThe = false;
      }

      /* copy location to int32 container */
      vipldws_B.C1 = vipldws_B.Transpose2[0] - 1;

      /* update the color/intensity */
      vipldws_DW.InsertTextRightLane_colorVector[0] = vipldws_B.Selector5[0];

      /* Saturate color values */
      if (vipldws_DW.InsertTextRightLane_colorVector[0] < 0.0F) {
        vipldws_DW.InsertTextRightLane_colorVector[0] = 0.0F;
      } else {
        if (vipldws_DW.InsertTextRightLane_colorVector[0] > 1.0F) {
          vipldws_DW.InsertTextRightLane_colorVector[0] = 1.0F;
        }
      }

      vipldws_DW.InsertTextRightLane_colorVector[1] = vipldws_B.Selector5[1];

      /* Saturate color values */
      if (vipldws_DW.InsertTextRightLane_colorVector[1] < 0.0F) {
        vipldws_DW.InsertTextRightLane_colorVector[1] = 0.0F;
      } else {
        if (vipldws_DW.InsertTextRightLane_colorVector[1] > 1.0F) {
          vipldws_DW.InsertTextRightLane_colorVector[1] = 1.0F;
        }
      }

      vipldws_DW.InsertTextRightLane_colorVector[2] = vipldws_B.Selector5[2];

      /* Saturate color values */
      if (vipldws_DW.InsertTextRightLane_colorVector[2] < 0.0F) {
        vipldws_DW.InsertTextRightLane_colorVector[2] = 0.0F;
      } else {
        if (vipldws_DW.InsertTextRightLane_colorVector[2] > 1.0F) {
          vipldws_DW.InsertTextRightLane_colorVector[2] = 1.0F;
        }
      }

      /* copy selection to uint32 container */
      vipldws_B.fromIdx = vipldws_B.Bias1_j[1] - 1U;
      if (vipldws_B.fromIdx >= 5U) {
        done = true;
        vipldws_B.countPeak = -1;
      } else {
        vipldws_B.s37_iter = (int32_T)vipldws_ConstP.pooled9[vipldws_B.fromIdx];
      }

      if (!done) {
        vipldws_B.i = MWVIP_strlen
          (&vipldws_DW.InsertTextRightLane_StringDataD[vipldws_B.s37_iter]);
        vipldws_B.countPeak = 0;
        if (c_gotAlLeastOneYellowPixelInThe) {
          /* put the pen at the beginning of the string */
          vipldws_B.C2 = vipldws_B.Transpose2[0] - 1;
          vipldws_B.c2 = vipldws_B.Transpose2[1];
          vipldws_B.c1 = 0;
          while (vipldws_B.c1 < vipldws_B.i) {
            if (vipldws_DW.InsertTextRightLane_StringDataD[vipldws_B.s37_iter +
                vipldws_B.c1] == 10) {
              vipldws_B.c2 += 16;
              vipldws_B.C2 = vipldws_B.C1;
            } else {
              vipldws_B.r2 =
                vipldws_DW.InsertTextRightLane_StringDataD[vipldws_B.s37_iter +
                vipldws_B.c1];
              vipldws_B.r1 = (int32_T)vipldws_ConstP.pooled8[vipldws_B.r2];
              if (!((vipldws_ConstP.pooled11[vipldws_B.r2] != 0) &&
                    (vipldws_ConstP.pooled12[vipldws_B.r2] != 0) &&
                    (vipldws_ConstP.pooled13[vipldws_B.r2] != 0))) {
                vipldws_B.r2 = 32;
                vipldws_B.r1 = 0;
              }

              vipldws_B.scale = vipldws_P.InsertTextRightLane_TxtOpacity;
              MWVIP_DrawText_I_single_AA(&vipldws_ConstP.pooled16[vipldws_B.r1],
                vipldws_B.C2, vipldws_B.c2 + 12,
                vipldws_ConstP.pooled2[vipldws_B.r2],
                vipldws_ConstP.pooled3[vipldws_B.r2],
                vipldws_ConstP.pooled11[vipldws_B.r2],
                vipldws_ConstP.pooled12[vipldws_B.r2], 240U, 320U,
                &vipldws_B.InsertTextRightLane[0],
                &vipldws_DW.InsertTextRightLane_colorVector[0], &vipldws_B.scale,
                false);
              MWVIP_DrawText_I_single_AA(&vipldws_ConstP.pooled16[vipldws_B.r1],
                vipldws_B.C2, vipldws_B.c2 + 12,
                vipldws_ConstP.pooled2[vipldws_B.r2],
                vipldws_ConstP.pooled3[vipldws_B.r2],
                vipldws_ConstP.pooled11[vipldws_B.r2],
                vipldws_ConstP.pooled12[vipldws_B.r2], 240U, 320U,
                &vipldws_B.InsertTextRightLane[76800],
                &vipldws_DW.InsertTextRightLane_colorVector[1], &vipldws_B.scale,
                false);
              MWVIP_DrawText_I_single_AA(&vipldws_ConstP.pooled16[vipldws_B.r1],
                vipldws_B.C2, vipldws_B.c2 + 12,
                vipldws_ConstP.pooled2[vipldws_B.r2],
                vipldws_ConstP.pooled3[vipldws_B.r2],
                vipldws_ConstP.pooled11[vipldws_B.r2],
                vipldws_ConstP.pooled12[vipldws_B.r2], 240U, 320U,
                &vipldws_B.InsertTextRightLane[153600],
                &vipldws_DW.InsertTextRightLane_colorVector[2], &vipldws_B.scale,
                false);
              vipldws_B.C2 += vipldws_ConstP.pooled13[vipldws_B.r2];
            }

            vipldws_B.c1++;
          }
        }
      }
    }

    /* End of S-Function (sviptextrender): '<S67>/Insert Text: Right Lane' */
    srUpdateBC(vipldws_DW.Subsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S5>/Subsystem' */

  /* Switch: '<S5>/Switch' */
  for (vipldws_B.i = 0; vipldws_B.i < 230400; vipldws_B.i++) {
    if (vipldws_B.NSampleEnable) {
      vipldws_B.cnt = (real32_T)floor(vipldws_B.InsertTextRightLane[vipldws_B.i]);
      if (rtIsNaNF(vipldws_B.cnt) || rtIsInfF(vipldws_B.cnt)) {
        vipldws_B.cnt = 0.0F;
      } else {
        vipldws_B.cnt = (real32_T)fmod(vipldws_B.cnt, 256.0F);
      }

      vipldws_B.Switch_mz[vipldws_B.i] = (uint8_T)(vipldws_B.cnt < 0.0F ?
        (int32_T)(uint8_T)-(int8_T)(uint8_T)-vipldws_B.cnt : (int32_T)(uint8_T)
        vipldws_B.cnt);
    } else {
      vipldws_B.cnt = (real32_T)floor
        (vipldws_B.ImageDataTypeConversion[vipldws_B.i]);
      if (rtIsNaNF(vipldws_B.cnt) || rtIsInfF(vipldws_B.cnt)) {
        vipldws_B.cnt = 0.0F;
      } else {
        vipldws_B.cnt = (real32_T)fmod(vipldws_B.cnt, 256.0F);
      }

      vipldws_B.Switch_mz[vipldws_B.i] = (uint8_T)(vipldws_B.cnt < 0.0F ?
        (int32_T)(uint8_T)-(int8_T)(uint8_T)-vipldws_B.cnt : (int32_T)(uint8_T)
        vipldws_B.cnt);
    }
  }

  /* End of Switch: '<S5>/Switch' */

  /* Outputs for Enabled SubSystem: '<S5>/Draw  3rd Line' incorporates:
   *  EnablePort: '<S62>/Enable'
   */
  if (vipldws_B.LogicalOperator2) {
    /* SignalConversion: '<S62>/TmpSignal ConversionAtDrawShapesInport2' */
    vipldws_B.TmpSignalConversionAtDrawShapes[0] = vipldws_B.Bias3[1];
    vipldws_B.TmpSignalConversionAtDrawShapes[1] = vipldws_B.Bias3[0];
    vipldws_B.TmpSignalConversionAtDrawShapes[2] = vipldws_B.Bias3[3];
    vipldws_B.TmpSignalConversionAtDrawShapes[3] = vipldws_B.Bias3[2];

    /* S-Function (svipdrawshapes): '<S62>/DrawShapes' */
    if (vipldws_P.DrawShapes_lineWidth == 1) {
      /* Compute output for unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws_B.DrawShapes_l[0], &vipldws_B.Switch_mz[0], 230400U *
             sizeof(uint8_T));

      /* Update view port. */
      vipldws_B.qY_g = vipldws_B.TmpSignalConversionAtDrawShapes[1] - 1;
      vipldws_B.qY = vipldws_B.TmpSignalConversionAtDrawShapes[0] - 1;
      if ((vipldws_B.TmpSignalConversionAtDrawShapes[3] - 1 != vipldws_B.qY_g) ||
          (vipldws_B.TmpSignalConversionAtDrawShapes[2] - 1 != vipldws_B.qY)) {
        c_gotAlLeastOneYellowPixelInThe = false;
        vipldws_B.qY_g = (vipldws_B.qY_g << 3) + 4;
        vipldws_B.numEdge = ((vipldws_B.TmpSignalConversionAtDrawShapes[3] - 1) <<
                             3) + 4;
        vipldws_B.qY = (vipldws_B.qY << 3) + 4;
        vipldws_B.col = ((vipldws_B.TmpSignalConversionAtDrawShapes[2] - 1) << 3)
          + 4;

        /* Find the visible portion of a line. */
        countTwice = false;
        prevEdgeIsVertical = false;
        done = false;
        vipldws_B.yIdx = vipldws_B.qY_g;
        vipldws_B.c2 = vipldws_B.qY;
        vipldws_B.C2 = vipldws_B.numEdge;
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.col;
        while (!done) {
          vipldws_B.fromIdx = 0U;
          vipldws_B.toIdx = 0U;

          /* Determine viewport violations. */
          if (vipldws_B.yIdx < 0) {
            vipldws_B.fromIdx = 4U;
          } else {
            if (vipldws_B.yIdx > 2559) {
              vipldws_B.fromIdx = 8U;
            }
          }

          if (vipldws_B.C2 < 0) {
            vipldws_B.toIdx = 4U;
          } else {
            if (vipldws_B.C2 > 2559) {
              vipldws_B.toIdx = 8U;
            }
          }

          if (vipldws_B.c2 < 0) {
            vipldws_B.fromIdx |= 1U;
          } else {
            if (vipldws_B.c2 > 1919) {
              vipldws_B.fromIdx |= 2U;
            }
          }

          if (vipldws_B.lastActiveEdgeIdxBdy < 0) {
            vipldws_B.toIdx |= 1U;
          } else {
            if (vipldws_B.lastActiveEdgeIdxBdy > 1919) {
              vipldws_B.toIdx |= 2U;
            }
          }

          if (!((vipldws_B.fromIdx | vipldws_B.toIdx) != 0U)) {
            /* Line falls completely within bounds. */
            done = true;
            c_gotAlLeastOneYellowPixelInThe = true;
          } else if ((vipldws_B.fromIdx & vipldws_B.toIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            c_gotAlLeastOneYellowPixelInThe = false;
          } else if (vipldws_B.fromIdx != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (countTwice) {
              vipldws_B.yIdx = vipldws_B.qY_g;
              vipldws_B.c2 = vipldws_B.qY;
            }

            vipldws_B.i = vipldws_B.C2 - vipldws_B.yIdx;
            vipldws_B.C1 = vipldws_B.lastActiveEdgeIdxBdy - vipldws_B.c2;
            if ((vipldws_B.i > 1073741824) || (vipldws_B.i < -1073741824) ||
                ((vipldws_B.C1 > 1073741824) || (vipldws_B.C1 < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = false;
              countTwice = true;
            } else if ((vipldws_B.fromIdx & 4U) != 0U) {
              /* Violated RMin. */
              vipldws_B.c1 = -vipldws_B.yIdx * vipldws_B.C1;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                vipldws_B.c2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.i) +
                                 1) >> 1;
              } else {
                vipldws_B.c2 -= (div_s32_floor(-vipldws_B.c1 << 1, vipldws_B.i)
                                 + 1) >> 1;
              }

              vipldws_B.yIdx = 0;
              countTwice = true;
            } else if ((vipldws_B.fromIdx & 8U) != 0U) {
              /* Violated RMax. */
              vipldws_B.c1 = (2559 - vipldws_B.yIdx) * vipldws_B.C1;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                vipldws_B.c2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.i) +
                                 1) >> 1;
              } else {
                vipldws_B.c2 -= (div_s32_floor(-vipldws_B.c1 << 1, vipldws_B.i)
                                 + 1) >> 1;
              }

              vipldws_B.yIdx = 2559;
              countTwice = true;
            } else if ((vipldws_B.fromIdx & 1U) != 0U) {
              /* Violated CMin. */
              vipldws_B.c1 = -vipldws_B.c2 * vipldws_B.i;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                vipldws_B.yIdx += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.C1)
                                   + 1) >> 1;
              } else {
                vipldws_B.yIdx -= (div_s32_floor(-vipldws_B.c1 << 1,
                  vipldws_B.C1) + 1) >> 1;
              }

              vipldws_B.c2 = 0;
              countTwice = true;
            } else {
              /* Violated CMax. */
              vipldws_B.c1 = (1919 - vipldws_B.c2) * vipldws_B.i;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                vipldws_B.yIdx += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.C1)
                                   + 1) >> 1;
              } else {
                vipldws_B.yIdx -= (div_s32_floor(-vipldws_B.c1 << 1,
                  vipldws_B.C1) + 1) >> 1;
              }

              vipldws_B.c2 = 1919;
              countTwice = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (prevEdgeIsVertical) {
              vipldws_B.C2 = vipldws_B.numEdge;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.col;
            }

            vipldws_B.i = vipldws_B.C2 - vipldws_B.yIdx;
            vipldws_B.C1 = vipldws_B.lastActiveEdgeIdxBdy - vipldws_B.c2;
            if ((vipldws_B.i > 1073741824) || (vipldws_B.i < -1073741824) ||
                ((vipldws_B.C1 > 1073741824) || (vipldws_B.C1 < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = false;
              prevEdgeIsVertical = true;
            } else if ((vipldws_B.toIdx & 4U) != 0U) {
              /* Violated RMin. */
              vipldws_B.c1 = -vipldws_B.C2 * vipldws_B.C1;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                vipldws_B.lastActiveEdgeIdxBdy += (div_s32_floor(vipldws_B.c1 <<
                  1, vipldws_B.i) + 1) >> 1;
              } else {
                vipldws_B.lastActiveEdgeIdxBdy -= (div_s32_floor(-vipldws_B.c1 <<
                  1, vipldws_B.i) + 1) >> 1;
              }

              vipldws_B.C2 = 0;
              prevEdgeIsVertical = true;
            } else if ((vipldws_B.toIdx & 8U) != 0U) {
              /* Violated RMax. */
              vipldws_B.c1 = (2559 - vipldws_B.C2) * vipldws_B.C1;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.i >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.i < 0))) {
                vipldws_B.lastActiveEdgeIdxBdy += (div_s32_floor(vipldws_B.c1 <<
                  1, vipldws_B.i) + 1) >> 1;
              } else {
                vipldws_B.lastActiveEdgeIdxBdy -= (div_s32_floor(-vipldws_B.c1 <<
                  1, vipldws_B.i) + 1) >> 1;
              }

              vipldws_B.C2 = 2559;
              prevEdgeIsVertical = true;
            } else if ((vipldws_B.toIdx & 1U) != 0U) {
              /* Violated CMin. */
              vipldws_B.c1 = -vipldws_B.lastActiveEdgeIdxBdy * vipldws_B.i;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                vipldws_B.C2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.C1)
                                 + 1) >> 1;
              } else {
                vipldws_B.C2 -= (div_s32_floor(-vipldws_B.c1 << 1, vipldws_B.C1)
                                 + 1) >> 1;
              }

              vipldws_B.lastActiveEdgeIdxBdy = 0;
              prevEdgeIsVertical = true;
            } else {
              /* Violated CMax. */
              vipldws_B.c1 = (1919 - vipldws_B.lastActiveEdgeIdxBdy) *
                vipldws_B.i;
              if ((vipldws_B.c1 > 1073741824) || (vipldws_B.c1 < -1073741824)) {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws_B.c1 >= 0) && (vipldws_B.C1 >= 0)) ||
                         ((vipldws_B.c1 < 0) && (vipldws_B.C1 < 0))) {
                vipldws_B.C2 += (div_s32_floor(vipldws_B.c1 << 1, vipldws_B.C1)
                                 + 1) >> 1;
              } else {
                vipldws_B.C2 -= (div_s32_floor(-vipldws_B.c1 << 1, vipldws_B.C1)
                                 + 1) >> 1;
              }

              vipldws_B.lastActiveEdgeIdxBdy = 1919;
              prevEdgeIsVertical = true;
            }
          }
        }

        if (c_gotAlLeastOneYellowPixelInThe) {
          /* Initialize the Bresenham algorithm. */
          if (vipldws_B.C2 >= vipldws_B.yIdx) {
            vipldws_B.numEdge = vipldws_B.C2 - vipldws_B.yIdx;
          } else {
            vipldws_B.numEdge = vipldws_B.yIdx - vipldws_B.C2;
          }

          if (vipldws_B.lastActiveEdgeIdxBdy >= vipldws_B.c2) {
            vipldws_B.col = vipldws_B.lastActiveEdgeIdxBdy - vipldws_B.c2;
          } else {
            vipldws_B.col = vipldws_B.c2 - vipldws_B.lastActiveEdgeIdxBdy;
          }

          if (vipldws_B.numEdge > vipldws_B.col) {
            vipldws_B.r2 = 1;
            vipldws_B.r1 = 320;
          } else {
            vipldws_B.r2 = 320;
            vipldws_B.r1 = 1;
            vipldws_B.i = vipldws_B.yIdx;
            vipldws_B.yIdx = vipldws_B.c2;
            vipldws_B.c2 = vipldws_B.i;
            vipldws_B.i = vipldws_B.C2;
            vipldws_B.C2 = vipldws_B.lastActiveEdgeIdxBdy;
            vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.i;
          }

          if (vipldws_B.yIdx > vipldws_B.C2) {
            vipldws_B.i = vipldws_B.yIdx;
            vipldws_B.yIdx = vipldws_B.C2;
            vipldws_B.C2 = vipldws_B.i;
            vipldws_B.i = vipldws_B.c2;
            vipldws_B.c2 = vipldws_B.lastActiveEdgeIdxBdy;
            vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.i;
          }

          vipldws_B.qY_g = vipldws_B.C2 - vipldws_B.yIdx;
          if (vipldws_B.c2 <= vipldws_B.lastActiveEdgeIdxBdy) {
            vipldws_B.qY = 1;
            vipldws_B.lastActiveEdgeIdxBdy -= vipldws_B.c2;
          } else {
            vipldws_B.qY = -1;
            vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.c2 -
              vipldws_B.lastActiveEdgeIdxBdy;
          }

          vipldws_B.activeColBdy = vipldws_B.c2 - 4;
          vipldws_B.activeCol = -((vipldws_B.qY_g + 1) >> 1);
          if (vipldws_B.r2 != 1) {
            vipldws_B.colBoundary = 2559;
          } else {
            vipldws_B.colBoundary = 1919;
          }

          vipldws_B.c1 = vipldws_B.yIdx >> 3;
          vipldws_B.ii = ((vipldws_B.c1 + 1) << 3) - vipldws_B.yIdx;
          vipldws_B.firstRowOut = 320;
          vipldws_B.lastRowOut = 0;
          memset(&vipldws_DW.DrawShapes_DW_PixCount[0], 0, 320U * sizeof(uint8_T));
          done = (vipldws_B.yIdx <= vipldws_B.C2);
          while (done) {
            vipldws_B.ii--;
            vipldws_B.numEdge = vipldws_B.activeColBdy;

            /* Compute the next location using Bresenham algorithm. */
            /* Move to the next sub-pixel location. */
            vipldws_B.activeCol += vipldws_B.lastActiveEdgeIdxBdy;
            if (vipldws_B.activeCol >= 0) {
              vipldws_B.activeColBdy += vipldws_B.qY;
              vipldws_B.activeCol -= vipldws_B.qY_g;
            }

            vipldws_B.yIdx++;
            done = (vipldws_B.yIdx <= vipldws_B.C2);
            if (done) {
              vipldws_B.col = vipldws_B.numEdge + 7;
              if ((vipldws_B.numEdge + 7 > 0) && (vipldws_B.numEdge <
                   vipldws_B.colBoundary)) {
                if (vipldws_B.numEdge < 0) {
                  vipldws_B.numEdge = 0;
                }

                if (vipldws_B.col > vipldws_B.colBoundary) {
                  vipldws_B.col = vipldws_B.colBoundary;
                }

                vipldws_B.C1 = vipldws_B.numEdge >> 3;
                vipldws_B.i = vipldws_B.col >> 3;
                if (vipldws_B.firstRowOut > vipldws_B.C1) {
                  vipldws_B.firstRowOut = vipldws_B.C1;
                }

                if (vipldws_B.lastRowOut < vipldws_B.i) {
                  vipldws_B.lastRowOut = vipldws_B.i;
                }

                if (vipldws_B.i > vipldws_B.C1) {
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                    (((uint32_T)((vipldws_B.C1 + 1) << 3) +
                      vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1]) -
                     vipldws_B.numEdge);
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i] = (uint8_T)
                    ((((uint32_T)vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i]
                       + vipldws_B.col) - (vipldws_B.i << 3)) + 1U);
                  vipldws_B.numEdge = vipldws_B.C1 + 1;
                  while (vipldws_B.numEdge < vipldws_B.i) {
                    vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] =
                      (uint8_T)
                      (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] + 8U);
                    vipldws_B.numEdge++;
                  }
                } else {
                  if (vipldws_B.i == vipldws_B.C1) {
                    vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                      ((((uint32_T)
                         vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] +
                         vipldws_B.col) - vipldws_B.numEdge) + 1U);
                  }
                }
              }
            }

            if ((vipldws_B.ii == 0) || (!done)) {
              while (vipldws_B.firstRowOut <= vipldws_B.lastRowOut) {
                vipldws_B.col = vipldws_B.c1 * vipldws_B.r2 +
                  vipldws_B.firstRowOut * vipldws_B.r1;
                if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] ==
                    64) {
                  vipldws_B.DrawShapes_l[vipldws_B.col] += (int8_T)((int8_T)
                    vipldws_P.DrawShapes_color_e[0] -
                    vipldws_B.DrawShapes_l[vipldws_B.col]);
                } else {
                  vipldws_B.DrawShapes_l[vipldws_B.col] = (uint8_T)(((int8_T)
                    ((int8_T)((int8_T)vipldws_P.DrawShapes_color_e[0] -
                              vipldws_B.DrawShapes_l[vipldws_B.col]) *
                     vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut]) >>
                    6) + vipldws_B.DrawShapes_l[vipldws_B.col]);
                }

                vipldws_B.col += 76800;
                if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] ==
                    64) {
                  vipldws_B.DrawShapes_l[vipldws_B.col] += (int8_T)((int8_T)
                    vipldws_P.DrawShapes_color_e[1] -
                    vipldws_B.DrawShapes_l[vipldws_B.col]);
                } else {
                  vipldws_B.DrawShapes_l[vipldws_B.col] = (uint8_T)(((int8_T)
                    ((int8_T)((int8_T)vipldws_P.DrawShapes_color_e[1] -
                              vipldws_B.DrawShapes_l[vipldws_B.col]) *
                     vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut]) >>
                    6) + vipldws_B.DrawShapes_l[vipldws_B.col]);
                }

                vipldws_B.col += 76800;
                if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] ==
                    64) {
                  vipldws_B.DrawShapes_l[vipldws_B.col] += (int8_T)((int8_T)
                    vipldws_P.DrawShapes_color_e[2] -
                    vipldws_B.DrawShapes_l[vipldws_B.col]);
                } else {
                  vipldws_B.DrawShapes_l[vipldws_B.col] = (uint8_T)(((int8_T)
                    ((int8_T)((int8_T)vipldws_P.DrawShapes_color_e[2] -
                              vipldws_B.DrawShapes_l[vipldws_B.col]) *
                     vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut]) >>
                    6) + vipldws_B.DrawShapes_l[vipldws_B.col]);
                }

                vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] = 0U;
                vipldws_B.firstRowOut++;
              }

              vipldws_B.ii = 8;
              vipldws_B.firstRowOut = 320;
              vipldws_B.lastRowOut = 0;
              vipldws_B.c1++;
            }
          }
        }
      }
    } else {
      /* Compute output for non-unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws_B.DrawShapes_l[0], &vipldws_B.Switch_mz[0], 230400U *
             sizeof(uint8_T));

      /* Update view port. */
      /* ProcessStep-start-1
       */
      /* ProcessStep-after poly points-1
       */
      vipldws_B.c2 = 2;

      /* just before call for cgpolygon
       */
      if (vipldws_P.DrawShapes_lineWidth > 1) {
        /* convertLinePts2PolygonPts
         */
        vipldws_B.numEdge = vipldws_P.DrawShapes_lineWidth >> 1;

        /* getLineParams-1
         */
        /* getLineParams-main fcn
         */
        vipldws_B.lastActiveEdgeIdxBdy =
          vipldws_B.TmpSignalConversionAtDrawShapes[1] -
          vipldws_B.TmpSignalConversionAtDrawShapes[3];
        vipldws_B.yIdx = vipldws_B.TmpSignalConversionAtDrawShapes[0] -
          vipldws_B.TmpSignalConversionAtDrawShapes[2];
        if (vipldws_B.yIdx == 0) {
          lineColorIdx_idx_0 = 0;
          vipldws_B.col = 1;
          solidBrokenIdx_idx_0 = (int8_T)
            ((vipldws_B.TmpSignalConversionAtDrawShapes[0] - vipldws_B.numEdge)
             - 1);
          acc1_idx_1 = (int8_T)((vipldws_B.TmpSignalConversionAtDrawShapes[0] +
            vipldws_B.numEdge) - 1);
          acc4_idx_0 = (int8_T)(vipldws_B.TmpSignalConversionAtDrawShapes[1] - 1);
        } else if (vipldws_B.lastActiveEdgeIdxBdy == 0) {
          vipldws_B.col = 2;
          lineColorIdx_idx_0 = 0;
          solidBrokenIdx_idx_0 = (int8_T)
            ((vipldws_B.TmpSignalConversionAtDrawShapes[1] - vipldws_B.numEdge)
             - 1);
          acc1_idx_1 = (int8_T)((vipldws_B.TmpSignalConversionAtDrawShapes[1] +
            vipldws_B.numEdge) - 1);
          acc4_idx_0 = (int8_T)(vipldws_B.TmpSignalConversionAtDrawShapes[0] - 1);
        } else {
          vipldws_B.col = 0;
          lineColorIdx_idx_0 = div_s8s32_floor((int8_T)
            vipldws_B.lastActiveEdgeIdxBdy, (int8_T)vipldws_B.yIdx);
          acc1_idx_1 = (int8_T)((int8_T)
                                (vipldws_B.TmpSignalConversionAtDrawShapes[1] -
            1) - (int8_T)((int8_T)(vipldws_B.TmpSignalConversionAtDrawShapes[0]
            - 1) * lineColorIdx_idx_0));
          acc4_idx_0 = div_s8s32_floor((int8_T)vipldws_B.numEdge,
            div_s8s32_floor((int8_T)vipldws_B.yIdx, rt_sqrt_Us8_Ys4_Is8_f_pw
                            ((int8_T)(vipldws_B.lastActiveEdgeIdxBdy *
            vipldws_B.lastActiveEdgeIdxBdy + vipldws_B.yIdx * vipldws_B.yIdx))));
          solidBrokenIdx_idx_0 = (int8_T)(acc1_idx_1 + acc4_idx_0);
          acc1_idx_1 -= acc4_idx_0;
          acc4_idx_0 = (int8_T)(div_s8s32_floor((int8_T)
            (vipldws_B.TmpSignalConversionAtDrawShapes[0] - 1),
            lineColorIdx_idx_0) + (int8_T)
                                (vipldws_B.TmpSignalConversionAtDrawShapes[1] -
            1));
        }

        /* findPointOfIntersectionNormal-1
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.lastActiveEdgeIdxBdy = solidBrokenIdx_idx_0;
          vipldws_B.yIdx = acc4_idx_0;
          vipldws_B.activeColBdy = acc1_idx_1;
          vipldws_B.activeCol = acc4_idx_0;
        } else {
          if (vipldws_B.col == 2) {
            vipldws_B.lastActiveEdgeIdxBdy = acc4_idx_0;
            vipldws_B.yIdx = solidBrokenIdx_idx_0;
          } else {
            acc1_idx_5 = div_s8s32_floor((int8_T)((int8_T)(acc4_idx_0 -
              solidBrokenIdx_idx_0) * lineColorIdx_idx_0), (int8_T)((int8_T)
              (lineColorIdx_idx_0 * lineColorIdx_idx_0) + 1));
            vipldws_B.lastActiveEdgeIdxBdy = acc1_idx_5;
            vipldws_B.yIdx = (int8_T)((int8_T)(lineColorIdx_idx_0 * acc1_idx_5)
              + solidBrokenIdx_idx_0);
          }

          if (vipldws_B.col == 2) {
            vipldws_B.activeColBdy = acc4_idx_0;
            vipldws_B.activeCol = acc1_idx_1;
          } else {
            acc1_idx_5 = div_s8s32_floor((int8_T)((int8_T)(acc4_idx_0 -
              acc1_idx_1) * lineColorIdx_idx_0), (int8_T)((int8_T)
              (lineColorIdx_idx_0 * lineColorIdx_idx_0) + 1));
            vipldws_B.activeColBdy = acc1_idx_5;
            vipldws_B.activeCol = (int8_T)((int8_T)(lineColorIdx_idx_0 *
              acc1_idx_5) + acc1_idx_1);
          }
        }

        vipldws_DW.DrawShapes_DW_Points[0] = vipldws_B.lastActiveEdgeIdxBdy;
        vipldws_DW.DrawShapes_DW_Points[1] = vipldws_B.yIdx;

        /* findPointOfIntersectionNormal-2
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        vipldws_DW.DrawShapes_DW_Points[7] = vipldws_B.activeCol;
        vipldws_DW.DrawShapes_DW_Points[6] = vipldws_B.activeColBdy;

        /* getLineParams-2
         */
        /* getLineParams-main fcn
         */
        vipldws_B.lastActiveEdgeIdxBdy =
          vipldws_B.TmpSignalConversionAtDrawShapes[1] -
          vipldws_B.TmpSignalConversionAtDrawShapes[3];
        vipldws_B.yIdx = vipldws_B.TmpSignalConversionAtDrawShapes[0] -
          vipldws_B.TmpSignalConversionAtDrawShapes[2];
        if (vipldws_B.yIdx == 0) {
          lineColorIdx_idx_0 = 0;
          vipldws_B.col = 1;
          solidBrokenIdx_idx_0 = (int8_T)
            ((vipldws_B.TmpSignalConversionAtDrawShapes[0] - vipldws_B.numEdge)
             - 1);
          acc1_idx_1 = (int8_T)((vipldws_B.TmpSignalConversionAtDrawShapes[0] +
            vipldws_B.numEdge) - 1);
          acc4_idx_0 = (int8_T)(vipldws_B.TmpSignalConversionAtDrawShapes[3] - 1);
        } else if (vipldws_B.lastActiveEdgeIdxBdy == 0) {
          vipldws_B.col = 2;
          lineColorIdx_idx_0 = 0;
          solidBrokenIdx_idx_0 = (int8_T)
            ((vipldws_B.TmpSignalConversionAtDrawShapes[1] - vipldws_B.numEdge)
             - 1);
          acc1_idx_1 = (int8_T)((vipldws_B.TmpSignalConversionAtDrawShapes[1] +
            vipldws_B.numEdge) - 1);
          acc4_idx_0 = (int8_T)(vipldws_B.TmpSignalConversionAtDrawShapes[2] - 1);
        } else {
          vipldws_B.col = 0;
          lineColorIdx_idx_0 = div_s8s32_floor((int8_T)
            vipldws_B.lastActiveEdgeIdxBdy, (int8_T)vipldws_B.yIdx);
          acc1_idx_1 = (int8_T)((int8_T)
                                (vipldws_B.TmpSignalConversionAtDrawShapes[1] -
            1) - (int8_T)((int8_T)(vipldws_B.TmpSignalConversionAtDrawShapes[0]
            - 1) * lineColorIdx_idx_0));
          acc4_idx_0 = div_s8s32_floor((int8_T)vipldws_B.numEdge,
            div_s8s32_floor((int8_T)vipldws_B.yIdx, rt_sqrt_Us8_Ys4_Is8_f_pw
                            ((int8_T)(vipldws_B.lastActiveEdgeIdxBdy *
            vipldws_B.lastActiveEdgeIdxBdy + vipldws_B.yIdx * vipldws_B.yIdx))));
          solidBrokenIdx_idx_0 = (int8_T)(acc1_idx_1 + acc4_idx_0);
          acc1_idx_1 -= acc4_idx_0;
          acc4_idx_0 = (int8_T)(div_s8s32_floor((int8_T)
            (vipldws_B.TmpSignalConversionAtDrawShapes[2] - 1),
            lineColorIdx_idx_0) + (int8_T)
                                (vipldws_B.TmpSignalConversionAtDrawShapes[3] -
            1));
        }

        /* findPointOfIntersectionNormal-3
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws_B.col == 1) {
          vipldws_B.lastActiveEdgeIdxBdy = solidBrokenIdx_idx_0;
          vipldws_B.yIdx = acc4_idx_0;
          vipldws_B.activeColBdy = acc1_idx_1;
          vipldws_B.activeCol = acc4_idx_0;
        } else {
          if (vipldws_B.col == 2) {
            vipldws_B.lastActiveEdgeIdxBdy = acc4_idx_0;
            vipldws_B.yIdx = solidBrokenIdx_idx_0;
          } else {
            acc1_idx_5 = div_s8s32_floor((int8_T)((int8_T)(acc4_idx_0 -
              solidBrokenIdx_idx_0) * lineColorIdx_idx_0), (int8_T)((int8_T)
              (lineColorIdx_idx_0 * lineColorIdx_idx_0) + 1));
            vipldws_B.lastActiveEdgeIdxBdy = acc1_idx_5;
            vipldws_B.yIdx = (int8_T)((int8_T)(lineColorIdx_idx_0 * acc1_idx_5)
              + solidBrokenIdx_idx_0);
          }

          if (vipldws_B.col == 2) {
            vipldws_B.activeColBdy = acc4_idx_0;
            vipldws_B.activeCol = acc1_idx_1;
          } else {
            acc1_idx_5 = div_s8s32_floor((int8_T)((int8_T)(acc4_idx_0 -
              acc1_idx_1) * lineColorIdx_idx_0), (int8_T)((int8_T)
              (lineColorIdx_idx_0 * lineColorIdx_idx_0) + 1));
            vipldws_B.activeColBdy = acc1_idx_5;
            vipldws_B.activeCol = (int8_T)((int8_T)(lineColorIdx_idx_0 *
              acc1_idx_5) + acc1_idx_1);
          }
        }

        vipldws_DW.DrawShapes_DW_Points[2] = vipldws_B.lastActiveEdgeIdxBdy;
        vipldws_DW.DrawShapes_DW_Points[3] = vipldws_B.yIdx;

        /* findPointOfIntersectionNormal-4
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        vipldws_DW.DrawShapes_DW_Points[5] = vipldws_B.activeCol;
        vipldws_DW.DrawShapes_DW_Points[4] = vipldws_B.activeColBdy;

        /* just before call for cgpolygon-2
         */
        vipldws_B.c2 = 4;
      }

      memset(&vipldws_DW.DrawShapes_DW_PixCount[0], 0, 320U * sizeof(uint8_T));

      /* Reset scanline states. */
      vipldws_B.R2 = 0;
      vipldws_B.C2 = 0;
      c_gotAlLeastOneYellowPixelInThe = true;
      while (c_gotAlLeastOneYellowPixelInThe) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        done = false;
        vipldws_B.numEdge = 0;
        vipldws_B.qY_g = vipldws_B.R2;
        vipldws_B.qY = vipldws_B.R2;
        idxTmpArray_0[0U] = (int8_T)(vipldws_B.c2 - 1);
        vipldws_B.ii = 0;
        while (vipldws_B.ii < 1) {
          /* start for loop
           */
          vipldws_B.lastActiveEdgeIdxBdy = ((idxTmpArray_0[0] << 1) +
            vipldws_B.C2) + 1;
          vipldws_B.yIdx = (idxTmpArray_0[0] << 1) + vipldws_B.C2;
          vipldws_B.firstRowOut = idxTmpArray_0[0];
          vipldws_B.activeColBdy = ((idxTmpArray_0[0] - 1) << 1) + vipldws_B.C2;
          vipldws_B.activeCol = vipldws_B.c2;
          if (vipldws_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            vipldws_B.colBoundary =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];

            /* getLoc-1
             */
            vipldws_B.lastRowOut =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws_B.colBoundary =
              vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.yIdx];

            /* getLoc-2
             */
            vipldws_B.lastRowOut =
              vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.activeColBdy];
          }

          vipldws_B.i = vipldws_B.lastRowOut;
          while ((vipldws_B.activeColBdy >= 0) && (vipldws_B.colBoundary - 1 ==
                  vipldws_B.i - 1)) {
            vipldws_B.firstRowOut--;
            vipldws_B.activeColBdy = ((vipldws_B.firstRowOut - 1) << 1) +
              vipldws_B.C2;
            vipldws_B.activeCol--;
            if (vipldws_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              vipldws_B.lastRowOut =
                vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];
            } else {
              /* getLoc-2
               */
              vipldws_B.lastRowOut =
                vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.activeColBdy];
            }

            vipldws_B.i = vipldws_B.lastRowOut;
          }

          if (vipldws_B.activeColBdy < 0) {
            vipldws_B.activeColBdy = 0;
          }

          if (vipldws_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            vipldws_B.colBoundary =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];

            /* getLoc-1
             */
            vipldws_B.lastRowOut =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws_B.colBoundary =
              vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.yIdx];

            /* getLoc-2
             */
            vipldws_B.lastRowOut =
              vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.activeColBdy];
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws_B.lastRowOut - 1 >
            vipldws_B.colBoundary - 1);
          vipldws_B.colOut = vipldws_B.C2 + 1;
          vipldws_B.activeColBdy = vipldws_B.C2;
          prevEdgeIsVertical = false;
          if (vipldws_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            vipldws_B.colBoundary = vipldws_DW.DrawShapes_DW_Points[vipldws_B.C2];

            /* getLoc-1
             */
            vipldws_B.lastRowOut =
              vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];
          } else {
            /* getLoc-2
             */
            vipldws_B.colBoundary =
              vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.C2];

            /* getLoc-2
             */
            vipldws_B.lastRowOut =
              vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.yIdx];
          }

          done = (vipldws_B.lastRowOut - 1 == vipldws_B.colBoundary - 1);
          vipldws_B.i = 0;
          while (vipldws_B.i < vipldws_B.activeCol) {
            if (vipldws_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              vipldws_B.colBoundary =
                vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];

              /* getLoc-1
               */
              vipldws_B.lastRowOut =
                vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];
            } else {
              /* getLoc-2
               */
              vipldws_B.colBoundary =
                vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.activeColBdy];

              /* getLoc-2
               */
              vipldws_B.lastRowOut =
                vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.yIdx];
            }

            if (vipldws_B.lastRowOut - 1 != vipldws_B.colBoundary - 1) {
              if (vipldws_P.DrawShapes_lineWidth > 1) {
                /* getLoc-1
                 */
                vipldws_B.colBoundary =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws_B.lastRowOut =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];
              } else {
                /* getLoc-2
                 */
                vipldws_B.colBoundary =
                  vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws_B.lastRowOut =
                  vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.yIdx];
              }

              if (vipldws_B.lastRowOut - 1 < vipldws_B.colBoundary - 1) {
                countTwice = false;
              } else {
                countTwice = true;
                vipldws_B.firstRowOut = vipldws_B.lastActiveEdgeIdxBdy;
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
                vipldws_B.colOut = vipldws_B.firstRowOut;
                vipldws_B.firstRowOut = vipldws_B.yIdx;
                vipldws_B.yIdx = vipldws_B.activeColBdy;
                vipldws_B.activeColBdy = vipldws_B.firstRowOut;
              }

              if (vipldws_P.DrawShapes_lineWidth > 1) {
                /* getLoc-1
                 */
                vipldws_B.colBoundary =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws_B.lastRowOut =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.colOut];

                /* getLoc-1
                 */
                vipldws_B.lastRow =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.yIdx];

                /* getLoc-1
                 */
                vipldws_B.firstRowOut =
                  vipldws_DW.DrawShapes_DW_Points[vipldws_B.lastActiveEdgeIdxBdy];
              } else {
                /* getLoc-2
                 */
                vipldws_B.colBoundary =
                  vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws_B.lastRowOut =
                  vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.colOut];

                /* getLoc-2
                 */
                vipldws_B.lastRow =
                  vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.yIdx];

                /* getLoc-2
                 */
                vipldws_B.firstRowOut =
                  vipldws_B.TmpSignalConversionAtDrawShapes[vipldws_B.lastActiveEdgeIdxBdy];
              }

              /* Initialize a Bresenham line. */
              vipldws_B.firstRowOut = ((vipldws_B.firstRowOut - 1) << 3) + 4;
              vipldws_B.lastRow = ((vipldws_B.lastRow - 1) << 3) + 4;
              vipldws_B.lastRowOut = ((vipldws_B.lastRowOut - 1) << 3) + 4;
              vipldws_B.colBoundary = ((vipldws_B.colBoundary - 1) << 3) + 4;
              vipldws_B.firstRow = vipldws_B.colBoundary - vipldws_B.lastRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] = 0;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] =
                vipldws_B.firstRowOut;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2] =
                vipldws_B.lastRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] =
                vipldws_B.colBoundary;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] = 0;
              if (vipldws_B.lastRowOut >= vipldws_B.firstRowOut) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] =
                  vipldws_B.lastRowOut - vipldws_B.firstRowOut;
              } else {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] =
                  vipldws_B.firstRowOut - vipldws_B.lastRowOut;
              }

              while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] >= 0) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6]++;
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] -=
                  vipldws_B.firstRow;
              }

              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] - 1;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8] +
                vipldws_B.firstRow;
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 4] =
                vipldws_B.firstRow -
                (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7] << 1);
              if (vipldws_B.firstRowOut > vipldws_B.lastRowOut) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5] =
                  -vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6] =
                  -vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6];
              }

              if ((!c_gotAlLeastOneYellowPixelInThe) && (!countTwice)) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2]++;
                if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] << 1) >
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 4]) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6];
                } else {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5];
                }
              } else {
                if (c_gotAlLeastOneYellowPixelInThe && countTwice) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3]--;
                }
              }

              c_gotAlLeastOneYellowPixelInThe = countTwice;
              if (!prevEdgeIsVertical) {
                /* Merge two Bresenham lines. */
                if ((vipldws_B.qY_g != vipldws_B.qY) &&
                    ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 5] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 5]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 6] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 6]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 7] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 7]) &&
                     (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 8] ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 8]))) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] + 1 ==
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2]) {
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] =
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3];
                    prevEdgeIsVertical = true;
                  } else {
                    if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] + 1 ==
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2]) {
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 1] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 1];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2];
                      prevEdgeIsVertical = true;
                    }
                  }
                }

                if (!prevEdgeIsVertical) {
                  vipldws_B.qY_g = vipldws_B.qY;
                  vipldws_B.numEdge++;
                }
              } else {
                vipldws_B.qY_g = vipldws_B.qY;
                vipldws_B.numEdge++;
              }

              vipldws_B.qY = vipldws_B.qY_g + 9;
              if (!countTwice) {
                vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
                vipldws_B.yIdx = vipldws_B.activeColBdy;
              }

              vipldws_B.colOut = vipldws_B.lastActiveEdgeIdxBdy + 2;
              vipldws_B.activeColBdy = vipldws_B.yIdx + 2;
              prevEdgeIsVertical = false;
            } else {
              prevEdgeIsVertical = true;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.colOut;
              vipldws_B.yIdx = vipldws_B.activeColBdy;
              vipldws_B.colOut += 2;
              vipldws_B.activeColBdy += 2;
            }

            vipldws_B.i++;
          }

          vipldws_B.ii = 1;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((vipldws_B.R2 != vipldws_B.qY_g) &&
              ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 5] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 5]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 6] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 6]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 7] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 7]) &&
               (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 8] ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 8]))) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3] + 1 ==
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2]) {
              vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3] =
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3];
              done = true;
            } else {
              if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 3] + 1 ==
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2]) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 1] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 1];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY_g + 2];
                done = true;
              }
            }
          }

          if (done) {
            vipldws_B.numEdge--;
            vipldws_B.qY -= 9;
          }
        }

        /* Set all other edges to invalid. */
        vipldws_B.i = vipldws_B.numEdge;
        while (vipldws_B.i < vipldws_B.c2) {
          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 2] = 1;
          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.qY + 3] = 0;
          vipldws_B.qY += 9;
          vipldws_B.i++;
        }

        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws_B.r1 = vipldws_B.R2;
          vipldws_B.r2 = vipldws_B.R2 + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.i = 1;
          while (vipldws_B.i < vipldws_B.numEdge) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 2] >
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_B.lastSeparator =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii] =
                  vipldws_B.lastSeparator;
              }
            }

            vipldws_B.r1 = vipldws_B.r2;
            vipldws_B.r2 += 9;
            vipldws_B.i++;
          }
        }

        /* Find out the last column of the polygon. */
        vipldws_B.C1 = vipldws_B.R2 + 3;
        vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 3];
        vipldws_B.i = 1;
        while (vipldws_B.i < vipldws_B.numEdge) {
          vipldws_B.C1 += 9;
          if (vipldws_B.qY_g < vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1]) {
            vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1];
          }

          vipldws_B.i++;
        }

        vipldws_B.qY = vipldws_B.qY_g;
        if (vipldws_B.qY_g > 1919) {
          vipldws_B.qY = 1919;
        }

        /* Find out the first column of the polygon. */
        vipldws_B.C1 = vipldws_B.R2 + 2;
        vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.R2 + 2];
        vipldws_B.i = 1;
        while (vipldws_B.i < vipldws_B.numEdge) {
          vipldws_B.C1 += 9;
          if (vipldws_B.qY_g > vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1]) {
            vipldws_B.qY_g = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.C1];
          }

          vipldws_B.i++;
        }

        if (vipldws_B.qY_g < 0) {
          vipldws_B.qY_g = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        vipldws_B.r1 = vipldws_B.R2;
        vipldws_B.r2 = vipldws_B.R2;
        vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.R2;
        vipldws_B.yIdx = 0;
        vipldws_B.C1 = 0;
        vipldws_B.i = 0;
        while (vipldws_B.i < vipldws_B.numEdge) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 3] >=
              vipldws_B.qY_g) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <=
                vipldws_B.qY_g) {
              while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <
                     vipldws_B.qY_g) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]++;
                if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] << 1) >
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 4]) {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 8];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 6];
                } else {
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 7];
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                    vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 5];
                }
              }

              vipldws_B.lastActiveEdgeIdxBdy += 9;
              vipldws_B.C1++;
            }

            if (vipldws_B.r2 != vipldws_B.r1) {
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
              }
            }

            vipldws_B.r1 += 9;
            vipldws_B.yIdx++;
          }

          vipldws_B.r2 += 9;
          vipldws_B.i++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws_B.r1 = vipldws_B.R2;
          vipldws_B.r2 = vipldws_B.R2 + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws_B.i = 1;
          while (vipldws_B.i < vipldws_B.C1) {
            if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1] >
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                vipldws_B.lastSeparator =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + vipldws_B.ii] =
                  vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii];
                vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + vipldws_B.ii] =
                  vipldws_B.lastSeparator;
              }
            }

            vipldws_B.r1 = vipldws_B.r2;
            vipldws_B.r2 += 9;
            vipldws_B.i++;
          }
        }

        vipldws_B.r1 = vipldws_B.R2;
        vipldws_B.activeColBdy = vipldws_B.qY_g + 1;
        vipldws_B.activeCol = 0;
        vipldws_B.r2 = 0;
        vipldws_B.lastSeparator = -1;
        vipldws_B.colOut = vipldws_B.qY_g >> 3;
        vipldws_B.colBoundary = (vipldws_B.colOut + 1) << 3;
        vipldws_B.firstRowOut = 320;
        vipldws_B.lastRowOut = 0;
        c_gotAlLeastOneYellowPixelInThe = (0 <= vipldws_B.qY);
        while (c_gotAlLeastOneYellowPixelInThe) {
          /* Get a string of pixels */
          countTwice = false;
          done = (vipldws_B.r2 != 0);
          vipldws_B.col = vipldws_B.activeCol;
          if ((vipldws_B.activeCol >= vipldws_B.qY_g) && (vipldws_B.activeCol <=
               vipldws_B.qY)) {
            if (vipldws_B.r1 < vipldws_B.lastActiveEdgeIdxBdy) {
              vipldws_B.i = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1];
              vipldws_B.r1 += 9;
              if ((vipldws_B.i == vipldws_B.lastSeparator) && (vipldws_B.r1 <
                   vipldws_B.lastActiveEdgeIdxBdy)) {
                vipldws_B.C1 = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1];
                c_gotAlLeastOneYellowPixelInThe = (vipldws_B.r1 <
                  vipldws_B.lastActiveEdgeIdxBdy);
                while (c_gotAlLeastOneYellowPixelInThe && (vipldws_B.i ==
                        vipldws_B.C1)) {
                  countTwice = true;
                  vipldws_B.i = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                    1];
                  vipldws_B.r1 += 9;
                  c_gotAlLeastOneYellowPixelInThe = (vipldws_B.r1 <
                    vipldws_B.lastActiveEdgeIdxBdy);
                  if (c_gotAlLeastOneYellowPixelInThe) {
                    vipldws_B.C1 = vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1
                      + 1];
                  }
                }

                if (!c_gotAlLeastOneYellowPixelInThe) {
                  countTwice = false;
                }
              }

              if (vipldws_B.r2 != 0) {
                vipldws_B.firstRow = vipldws_B.lastSeparator;
                if (vipldws_B.i <= 2559) {
                  vipldws_B.lastRow = vipldws_B.i;
                  vipldws_B.lastSeparator = vipldws_B.i;
                } else {
                  vipldws_B.lastRow = 2559;
                  vipldws_B.lastSeparator = 2559;
                }
              } else {
                vipldws_B.firstRow = vipldws_B.lastSeparator + 1;
                if ((vipldws_B.i > 0) && (vipldws_B.i <= 2559)) {
                  vipldws_B.lastRow = vipldws_B.i - 1;
                  vipldws_B.lastSeparator = vipldws_B.i;
                } else if (vipldws_B.i <= 0) {
                  vipldws_B.lastRow = -1;
                  vipldws_B.lastSeparator = 0;
                } else {
                  vipldws_B.lastRow = 2559;
                  vipldws_B.lastSeparator = 2560;
                }
              }

              if (!countTwice) {
                vipldws_B.r2 = !(vipldws_B.r2 != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              vipldws_B.firstRow = vipldws_B.lastSeparator + 1;
              vipldws_B.lastRow = 2559;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              vipldws_B.r1 = vipldws_B.R2;
              vipldws_B.r2 = vipldws_B.R2;
              vipldws_B.lastActiveEdgeIdxBdy = vipldws_B.R2;
              vipldws_B.numEdge = 0;
              vipldws_B.C1 = 0;
              vipldws_B.i = 0;
              while (vipldws_B.i < vipldws_B.yIdx) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 3] >=
                    vipldws_B.activeColBdy) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <=
                      vipldws_B.activeColBdy) {
                    while (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2] <
                           vipldws_B.activeColBdy) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 2]++;
                      if ((vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] << 1) >
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 4]) {
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 8];
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 6];
                      } else {
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 7];
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1] +=
                          vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 5];
                      }
                    }

                    vipldws_B.lastActiveEdgeIdxBdy += 9;
                    vipldws_B.C1++;
                  }

                  if (vipldws_B.r2 != vipldws_B.r1) {
                    for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii];
                    }
                  }

                  vipldws_B.r1 += 9;
                  vipldws_B.numEdge++;
                }

                vipldws_B.r2 += 9;
                vipldws_B.i++;
              }

              vipldws_B.yIdx = vipldws_B.numEdge;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (c_gotAlLeastOneYellowPixelInThe) {
                vipldws_B.r1 = vipldws_B.R2;
                vipldws_B.r2 = vipldws_B.R2 + 9;
                c_gotAlLeastOneYellowPixelInThe = false;
                vipldws_B.i = 1;
                while (vipldws_B.i < vipldws_B.C1) {
                  if (vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 + 1] >
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 + 1]) {
                    c_gotAlLeastOneYellowPixelInThe = true;
                    for (vipldws_B.ii = 0; vipldws_B.ii < 9; vipldws_B.ii++) {
                      vipldws_B.lastSeparator =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r1 +
                        vipldws_B.ii] =
                        vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii];
                      vipldws_DW.DrawShapes_DW_Polygon[vipldws_B.r2 +
                        vipldws_B.ii] = vipldws_B.lastSeparator;
                    }
                  }

                  vipldws_B.r1 = vipldws_B.r2;
                  vipldws_B.r2 += 9;
                  vipldws_B.i++;
                }
              }

              vipldws_B.r1 = vipldws_B.R2;
              vipldws_B.activeColBdy++;
              vipldws_B.r2 = 0;
              vipldws_B.lastSeparator = -1;
              vipldws_B.activeCol++;
            }
          } else {
            vipldws_B.firstRow = 0;
            vipldws_B.lastRow = 2559;
            vipldws_B.activeCol++;
          }

          if (vipldws_B.firstRow < 0) {
            vipldws_B.firstRow = 0;
          }

          if (vipldws_B.lastRow < vipldws_B.firstRow) {
            vipldws_B.lastRow = vipldws_B.firstRow - 1;
          }

          if (done && ((vipldws_B.lastRow > 0) && (vipldws_B.firstRow < 2559)))
          {
            if (vipldws_B.lastRow > 2559) {
              vipldws_B.lastRow = 2559;
            }

            vipldws_B.C1 = vipldws_B.firstRow >> 3;
            vipldws_B.i = vipldws_B.lastRow >> 3;
            if (vipldws_B.firstRowOut > vipldws_B.C1) {
              vipldws_B.firstRowOut = vipldws_B.C1;
            }

            if (vipldws_B.lastRowOut < vipldws_B.i) {
              vipldws_B.lastRowOut = vipldws_B.i;
            }

            if (vipldws_B.i > vipldws_B.C1) {
              vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                (((uint32_T)((vipldws_B.C1 + 1) << 3) +
                  vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1]) -
                 vipldws_B.firstRow);
              vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i] = (uint8_T)
                ((((uint32_T)vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.i] +
                   vipldws_B.lastRow) - (vipldws_B.i << 3)) + 1U);
              vipldws_B.numEdge = vipldws_B.C1 + 1;
              while (vipldws_B.numEdge < vipldws_B.i) {
                vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] = (uint8_T)
                  (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] + 8U);
                vipldws_B.numEdge++;
              }
            } else {
              if (vipldws_B.i == vipldws_B.C1) {
                vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] = (uint8_T)
                  ((((uint32_T)vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.C1] +
                     vipldws_B.lastRow) - vipldws_B.firstRow) + 1U);
              }
            }
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws_B.activeCol <= vipldws_B.qY);
          if (((vipldws_B.colBoundary - 1 == vipldws_B.col) ||
               (!c_gotAlLeastOneYellowPixelInThe)) && (vipldws_B.lastRow >= 2559))
          {
            vipldws_B.ii = vipldws_B.colOut * 320 + vipldws_B.firstRowOut;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.numEdge = vipldws_B.firstRowOut;
            while (vipldws_B.numEdge <= vipldws_B.lastRowOut) {
              if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] == 64) {
                vipldws_B.DrawShapes_l[vipldws_B.col] += (int8_T)((int8_T)
                  vipldws_P.DrawShapes_color_e[0] -
                  vipldws_B.DrawShapes_l[vipldws_B.col]);
              } else {
                vipldws_B.DrawShapes_l[vipldws_B.col] = (uint8_T)(((int8_T)
                  ((int8_T)((int8_T)vipldws_P.DrawShapes_color_e[0] -
                            vipldws_B.DrawShapes_l[vipldws_B.col]) *
                   vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge]) >> 6) +
                  vipldws_B.DrawShapes_l[vipldws_B.col]);
              }

              vipldws_B.col++;
              vipldws_B.numEdge++;
            }

            vipldws_B.ii += 76800;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.numEdge = vipldws_B.firstRowOut;
            while (vipldws_B.numEdge <= vipldws_B.lastRowOut) {
              if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] == 64) {
                vipldws_B.DrawShapes_l[vipldws_B.col] += (int8_T)((int8_T)
                  vipldws_P.DrawShapes_color_e[1] -
                  vipldws_B.DrawShapes_l[vipldws_B.col]);
              } else {
                vipldws_B.DrawShapes_l[vipldws_B.col] = (uint8_T)(((int8_T)
                  ((int8_T)((int8_T)vipldws_P.DrawShapes_color_e[1] -
                            vipldws_B.DrawShapes_l[vipldws_B.col]) *
                   vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge]) >> 6) +
                  vipldws_B.DrawShapes_l[vipldws_B.col]);
              }

              vipldws_B.col++;
              vipldws_B.numEdge++;
            }

            vipldws_B.ii += 76800;
            vipldws_B.col = vipldws_B.ii;
            vipldws_B.numEdge = vipldws_B.firstRowOut;
            while (vipldws_B.numEdge <= vipldws_B.lastRowOut) {
              if (vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge] == 64) {
                vipldws_B.DrawShapes_l[vipldws_B.col] += (int8_T)((int8_T)
                  vipldws_P.DrawShapes_color_e[2] -
                  vipldws_B.DrawShapes_l[vipldws_B.col]);
              } else {
                vipldws_B.DrawShapes_l[vipldws_B.col] = (uint8_T)(((int8_T)
                  ((int8_T)((int8_T)vipldws_P.DrawShapes_color_e[2] -
                            vipldws_B.DrawShapes_l[vipldws_B.col]) *
                   vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.numEdge]) >> 6) +
                  vipldws_B.DrawShapes_l[vipldws_B.col]);
              }

              vipldws_B.col++;
              vipldws_B.numEdge++;
            }

            while (vipldws_B.firstRowOut <= vipldws_B.lastRowOut) {
              vipldws_DW.DrawShapes_DW_PixCount[vipldws_B.firstRowOut] = 0U;
              vipldws_B.firstRowOut++;
            }

            vipldws_B.colOut++;
            vipldws_B.colBoundary += 8;
            vipldws_B.firstRowOut = 320;
            vipldws_B.lastRowOut = 0;
          }
        }

        /* Move to the next polygon. */
        vipldws_B.R2 += vipldws_B.c2 * 9;
        if (vipldws_B.C2 >= div_s32_floor(vipldws_B.c2, vipldws_B.c2) - 1) {
          vipldws_B.C2 = 0;
        } else {
          vipldws_B.C2++;
        }

        c_gotAlLeastOneYellowPixelInThe = (vipldws_B.R2 < vipldws_B.c2 * 9);
      }
    }

    /* End of S-Function (svipdrawshapes): '<S62>/DrawShapes' */
    srUpdateBC(vipldws_DW.Draw3rdLine_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S5>/Draw  3rd Line' */
  for (vipldws_B.i = 0; vipldws_B.i < 230400; vipldws_B.i++) {
    /* Switch: '<S5>/Switch2' */
    if (vipldws_B.LogicalOperator2) {
      vipldws_B.Switch2[vipldws_B.i] = vipldws_B.DrawShapes_l[vipldws_B.i];
    } else {
      vipldws_B.Switch2[vipldws_B.i] = vipldws_B.Switch_mz[vipldws_B.i];
    }

    /* End of Switch: '<S5>/Switch2' */

    /* S-Function (svipscalenconvert): '<S5>/Image Data Type Conversion' */
    vipldws_B.ImageDataTypeConversion_f[vipldws_B.i] =
      vipldws_B.Switch2[vipldws_B.i];
  }

  for (vipldws_B.i = 0; vipldws_B.i < 240; vipldws_B.i++) {
    /* Selector: '<S5>/Selector' */
    memcpy(&vipldws_B.Selector_hy[vipldws_B.i * 320],
           &vipldws_B.ImageDataTypeConversion_f[vipldws_B.i * 320], 320U *
           sizeof(uint8_T));

    /* Selector: '<S5>/Selector1' */
    memcpy(&vipldws_B.Selector1_p[vipldws_B.i * 320],
           &vipldws_B.ImageDataTypeConversion_f[vipldws_B.i * 320 + 76800], 320U
           * sizeof(uint8_T));

    /* Selector: '<S5>/Selector2' */
    memcpy(&vipldws_B.Selector2_c[vipldws_B.i * 320],
           &vipldws_B.ImageDataTypeConversion_f[vipldws_B.i * 320 + 153600],
           320U * sizeof(uint8_T));
  }

  /* Start for MATLABSystem: '<S64>/MATLAB System' incorporates:
   *  MATLABSystem: '<S64>/MATLAB System'
   */
  memcpy(&vipldws_B.pln1[0], &vipldws_B.Selector_hy[0], 76800U * sizeof(uint8_T));
  memcpy(&vipldws_B.pln2[0], &vipldws_B.Selector1_p[0], 76800U * sizeof(uint8_T));
  memcpy(&vipldws_B.pln3[0], &vipldws_B.Selector2_c[0], 76800U * sizeof(uint8_T));
  MW_SDL_videoDisplayOutput(vipldws_B.pln1, vipldws_B.pln2, vipldws_B.pln3);

  /* MinMax: '<S14>/MinMax' */
  if (vipldws_B.Intersectionwithbottomimageboun <
      vipldws_B.Intersectionwithbottomimagebo_g) {
    vipldws_B.Saturation_d = vipldws_B.Intersectionwithbottomimageboun;
  } else {
    vipldws_B.Saturation_d = vipldws_B.Intersectionwithbottomimagebo_g;
  }

  /* End of MinMax: '<S14>/MinMax' */

  /* Saturate: '<S14>/Saturation' */
  if (vipldws_B.Saturation_d > vipldws_P.Saturation_UpperSat_h) {
    vipldws_B.Saturation_d = vipldws_P.Saturation_UpperSat_h;
  } else {
    if (vipldws_B.Saturation_d < vipldws_P.Saturation_LowerSat_a) {
      vipldws_B.Saturation_d = vipldws_P.Saturation_LowerSat_a;
    }
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* DataTypeConversion: '<S14>/Data Type  Conversion' */
  vipldws_B.Add = (real32_T)vipldws_B.Saturation_d;

  /* DataTypeConversion: '<S14>/Data Type  Conversion1' */
  vipldws_B.DataTypeConversion1 = (real32_T)
    vipldws_B.Distancethresholdfordeparturewa;

  /* Sum: '<S14>/Add' */
  vipldws_B.Add -= vipldws_B.DataTypeConversion1;

  /* Product: '<S14>/Divide' */
  vipldws_B.MatrixConcatenation2[0] = vipldws_B.Add /
    vipldws_B.DataTypeConversion1;

  /* Constant: '<S14>/min_safety' */
  vipldws_B.MatrixConcatenation2[1] = vipldws_P.min_safety_Value;
  for (vipldws_B.i = 0; vipldws_B.i < 20; vipldws_B.i++) {
    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S34>/Constant'
     */
    vipldws_B.Compare_m[vipldws_B.i] = (vipldws_B.Saturation_h[vipldws_B.i] >=
      vipldws_P.OnlyupdatethelineswhichKalmanfi);

    /* Switch: '<S35>/Reset' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S35>/Initial Condition'
     */
    if (vipldws_P.Constant_Value_n) {
      vipldws_B.Xnew_m[vipldws_B.i] = vipldws_P.UnitDelayResettable_vinit;
    } else {
      vipldws_B.Xnew_m[vipldws_B.i] = vipldws_B.Saturation_h[vipldws_B.i];
    }

    /* End of Switch: '<S35>/Reset' */
  }

  /* Outputs for Iterator SubSystem: '<S4>/Update' incorporates:
   *  ForIterator: '<S37>/For Iterator'
   */
  memcpy(&vipldws_B.Assignment[0], &vipldws_B.Assignment_a[0], 40U * sizeof
         (real32_T));
  vipldws_B.s37_iter = 1;
  while (vipldws_B.s37_iter <= vipldws_P.ForIterator_IterationLimit_gd) {
    vipldws_B.ForIterator = vipldws_B.s37_iter;

    /* Selector: '<S37>/Selector' */
    vipldws_B.Selector_b = vipldws_B.Compare_m[vipldws_B.ForIterator - 1];

    /* Switch: '<S37>/Switch1' */
    if (vipldws_B.Selector_b) {
      /* Selector: '<S37>/Selector1' */
      vipldws_B.Selector1[0] = vipldws_B.Assignment_a[(vipldws_B.ForIterator - 1)
        << 1];
      vipldws_B.Switch1[0] = vipldws_B.Selector1[0];

      /* Selector: '<S37>/Selector1' */
      vipldws_B.Selector1[1] = vipldws_B.Assignment_a[((vipldws_B.ForIterator -
        1) << 1) + 1];
      vipldws_B.Switch1[1] = vipldws_B.Selector1[1];
    } else {
      /* Selector: '<S37>/Selector2' */
      vipldws_B.Selector2[0] = vipldws_B.Assignment_i[(vipldws_B.ForIterator - 1)
        << 1];
      vipldws_B.Switch1[0] = vipldws_B.Selector2[0];

      /* Selector: '<S37>/Selector2' */
      vipldws_B.Selector2[1] = vipldws_B.Assignment_i[((vipldws_B.ForIterator -
        1) << 1) + 1];
      vipldws_B.Switch1[1] = vipldws_B.Selector2[1];
    }

    /* End of Switch: '<S37>/Switch1' */

    /* Assignment: '<S37>/Assignment' */
    vipldws_B.Assignment[(vipldws_B.ForIterator - 1) << 1] = vipldws_B.Switch1[0];
    vipldws_B.Assignment[1 + ((vipldws_B.ForIterator - 1) << 1)] =
      vipldws_B.Switch1[1];
    vipldws_B.s37_iter++;
  }

  /* End of Outputs for SubSystem: '<S4>/Update' */

  /* Update for UnitDelay: '<S36>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S36>/FixPt Constant'
   */
  vipldws_DW.FixPtUnitDelay2_DSTATE = vipldws_P.FixPtConstant_Value_e;
  for (vipldws_B.i = 0; vipldws_B.i < 40; vipldws_B.i++) {
    /* Switch: '<S36>/Reset' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S36>/Initial Condition'
     */
    if (vipldws_P.Constant_Value_n) {
      vipldws_B.Xnew[vipldws_B.i] =
        vipldws_P.UnitDelayResettable1_vinit[vipldws_B.i];
    } else {
      vipldws_B.Xnew[vipldws_B.i] = vipldws_B.Assignment[vipldws_B.i];
    }

    /* End of Switch: '<S36>/Reset' */

    /* Update for UnitDelay: '<S36>/FixPt Unit Delay1' */
    vipldws_DW.FixPtUnitDelay1_DSTATE[vipldws_B.i] = vipldws_B.Xnew[vipldws_B.i];
  }

  /* Update for UnitDelay: '<S35>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S35>/FixPt Constant'
   */
  vipldws_DW.FixPtUnitDelay2_DSTATE_b = vipldws_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S35>/FixPt Unit Delay1' */
  memcpy(&vipldws_DW.FixPtUnitDelay1_DSTATE_d[0], &vipldws_B.Xnew_m[0], 20U *
         sizeof(int32_T));

  /* Update for UnitDelay: '<S32>/En_Delay' */
  memcpy(&vipldws_DW.En_Delay_DSTATE[0], &vipldws_B.Saturation_h[0], 20U *
         sizeof(int32_T));

  /* Update for UnitDelay: '<S32>/Unit Delay2' */
  memcpy(&vipldws_DW.UnitDelay2_DSTATE[0], &vipldws_B.Assignment_o[0], 80U *
         sizeof(real32_T));

  /* Update for UnitDelay: '<S32>/Unit Delay3' */
  memcpy(&vipldws_DW.UnitDelay3_DSTATE[0], &vipldws_B.Assignment_io[0], 320U *
         sizeof(real32_T));

  /* Update for Delay: '<S17>/Delay' */
  vipldws_DW.Delay_DSTATE = vipldws_B.outMsg;

  /* Update for Delay: '<S17>/Delay1' */
  vipldws_DW.Delay1_DSTATE_e = vipldws_B.RawMessage;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    rtExtModeUpload(0, vipldws_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    if ((rtmGetTFinal(vipldws_M)!=-1) &&
        !((rtmGetTFinal(vipldws_M)-vipldws_M->Timing.taskTime0) >
          vipldws_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(vipldws_M, "Simulation finished");
    }

    if (rtmGetStopRequested(vipldws_M)) {
      rtmSetErrorStatus(vipldws_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  vipldws_M->Timing.taskTime0 =
    (++vipldws_M->Timing.clockTick0) * vipldws_M->Timing.stepSize0;
}

/* Model initialize function */
void vipldws_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)vipldws_M, 0,
                sizeof(RT_MODEL_vipldws_T));
  rtmSetTFinal(vipldws_M, -1);
  vipldws_M->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  vipldws_M->Sizes.checksums[0] = (3292013895U);
  vipldws_M->Sizes.checksums[1] = (1028096924U);
  vipldws_M->Sizes.checksums[2] = (2331457176U);
  vipldws_M->Sizes.checksums[3] = (2336779331U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    vipldws_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = (sysRanDType *)&vipldws_DW.SampleandHold_SubsysRanBC;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)&vipldws_DW.Enablesignalgenerator_SubsysRan;
    systemRan[16] = (sysRanDType *)&vipldws_DW.Core_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&vipldws_DW.Options_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&vipldws_DW.Options_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&vipldws_DW.Options_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&vipldws_DW.Options_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&vipldws_DW.Options_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)&vipldws_DW.Selectalinefromtherepositoryifi;
    systemRan[24] = (sysRanDType *)&vipldws_DW.Differencebetweentwolines_Subsy;
    systemRan[25] = (sysRanDType *)&vipldws_DW.Selectalinefromtherepositoryifi;
    systemRan[26] = (sysRanDType *)&vipldws_DW.Selectalinefromtherepositoryifi;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = (sysRanDType *)&vipldws_DW.Draw3rdLine_SubsysRanBC;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = (sysRanDType *)&vipldws_DW.DrawPolygon_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&vipldws_DW.Subsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(vipldws_M->extModeInfo,
      &vipldws_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(vipldws_M->extModeInfo, vipldws_M->Sizes.checksums);
    rteiSetTPtr(vipldws_M->extModeInfo, rtmGetTPtr(vipldws_M));
  }

  /* block I/O */
  (void) memset(((void *) &vipldws_B), 0,
                sizeof(B_vipldws_T));

  {
    int32_T i;
    for (i = 0; i < 230400; i++) {
      vipldws_B.ImageDataTypeConversion[i] = 0.0F;
    }

    for (i = 0; i < 76800; i++) {
      vipldws_B.ColorSpaceConversion[i] = 0.0F;
    }

    for (i = 0; i < 48000; i++) {
      vipldws_B.Clipimage[i] = 0.0F;
    }

    for (i = 0; i < 112500; i++) {
      vipldws_B.HoughTransform_o1[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Init[i] = 0.0F;
    }

    for (i = 0; i < 80; i++) {
      vipldws_B.UnitDelay2[i] = 0.0F;
    }

    for (i = 0; i < 320; i++) {
      vipldws_B.UnitDelay3[i] = 0.0F;
    }

    for (i = 0; i < 86400; i++) {
      vipldws_B.ColorSpaceConversion1[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Xnew[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.InsertTextRightLane[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Assignment[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Assignment_i[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws_B.Selector2_n[i] = 0.0F;
    }

    for (i = 0; i < 320; i++) {
      vipldws_B.Assignment_io[i] = 0.0F;
    }

    for (i = 0; i < 80; i++) {
      vipldws_B.Assignment_o[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Assignment_p[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Assignment_a[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws_B.P_prd_Reshape[i] = 0.0F;
    }

    for (i = 0; i < 48000; i++) {
      vipldws_B.uDFIRFilter[i] = 0.0F;
    }

    for (i = 0; i < 48000; i++) {
      vipldws_B.Saturation[i] = 0.0F;
    }

    for (i = 0; i < 231; i++) {
      vipldws_B.selectrho5[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws_B.Xold[i] = 0.0F;
    }

    for (i = 0; i < 112500; i++) {
      vipldws_B.OverwriteValues[i] = 0.0F;
    }

    for (i = 0; i < 112500; i++) {
      vipldws_B.OverwriteValues1[i] = 0.0F;
    }

    for (i = 0; i < 20; i++) {
      vipldws_B.selectrho5_f[i] = 0.0F;
    }

    for (i = 0; i < 20; i++) {
      vipldws_B.selectrho2[i] = 0.0F;
    }

    for (i = 0; i < 756; i++) {
      vipldws_B.selectrho5_m[i] = 0.0F;
    }

    for (i = 0; i < 86400; i++) {
      vipldws_B.Selector_a[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.Switch[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.DrawShapes[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.InsertText[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.InsertTextLeftLane[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.ImageDataTypeConversion_n[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws_B.DrawShapes_f[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws_B.Switch_m[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws_B.HP_prdt[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws_B.y[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws_B.MatrixScaling[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws_B.BackwardSubstitution[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws_B.KTrans[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws_B.APAtQ[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws_B.P_prdKHP_prd[i] = 0.0F;
    }

    vipldws_B.Probe[0] = 0.0;
    vipldws_B.Probe[1] = 0.0;
    vipldws_B.Selector = 0.0;
    vipldws_B.MatrixConcatenation3[0] = 0.0F;
    vipldws_B.MatrixConcatenation3[1] = 0.0F;
    vipldws_B.MatrixConcatenation3[2] = 0.0F;
    vipldws_B.MatrixConcatenation3[3] = 0.0F;
    vipldws_B.MatrixConcatenation2[0] = 0.0F;
    vipldws_B.MatrixConcatenation2[1] = 0.0F;
    vipldws_B.Selector1[0] = 0.0F;
    vipldws_B.Selector1[1] = 0.0F;
    vipldws_B.Selector2[0] = 0.0F;
    vipldws_B.Selector2[1] = 0.0F;
    vipldws_B.Selector2_f[0] = 0.0F;
    vipldws_B.Selector2_f[1] = 0.0F;
    vipldws_B.Selector1_k[0] = 0.0F;
    vipldws_B.Selector1_k[1] = 0.0F;
    vipldws_B.Selector_i[0] = 0.0F;
    vipldws_B.Selector_i[1] = 0.0F;
    vipldws_B.Selector1_c[0] = 0.0F;
    vipldws_B.Selector1_c[1] = 0.0F;
    vipldws_B.Selector1_c[2] = 0.0F;
    vipldws_B.Selector1_c[3] = 0.0F;
    vipldws_B.AX[0] = 0.0F;
    vipldws_B.AX[1] = 0.0F;
    vipldws_B.AX[2] = 0.0F;
    vipldws_B.AX[3] = 0.0F;
    vipldws_B.Z_est_Multiply[0] = 0.0F;
    vipldws_B.Z_est_Multiply[1] = 0.0F;
    vipldws_B.Z_prd_Multiply[0] = 0.0F;
    vipldws_B.Z_prd_Multiply[1] = 0.0F;
    vipldws_B.Selectorrho[0] = 0.0F;
    vipldws_B.Selectorrho[1] = 0.0F;
    vipldws_B.Selectortheta[0] = 0.0F;
    vipldws_B.Selectortheta[1] = 0.0F;
    vipldws_B.DataTypeConversion1 = 0.0F;
    vipldws_B.Selectorrho_c = 0.0F;
    vipldws_B.Selectortheta_i = 0.0F;
    vipldws_B.Selectorrho_o = 0.0F;
    vipldws_B.Selectortheta_g = 0.0F;
    vipldws_B.Switch1[0] = 0.0F;
    vipldws_B.Switch1[1] = 0.0F;
    vipldws_B.Selector2_b[0] = 0.0F;
    vipldws_B.Selector2_b[1] = 0.0F;
    vipldws_B.Rho_2 = 0.0F;
    vipldws_B.Switch_l[0] = 0.0F;
    vipldws_B.Switch_l[1] = 0.0F;
    vipldws_B.Switch_l[2] = 0.0F;
    vipldws_B.Switch_l[3] = 0.0F;
    vipldws_B.LDLFactorization[0] = 0.0F;
    vipldws_B.LDLFactorization[1] = 0.0F;
    vipldws_B.LDLFactorization[2] = 0.0F;
    vipldws_B.LDLFactorization[3] = 0.0F;
    vipldws_B.d[0] = 0.0F;
    vipldws_B.d[1] = 0.0F;
    vipldws_B.Add = 0.0F;
    vipldws_B.Switch_j[0] = 0.0F;
    vipldws_B.Switch_j[1] = 0.0F;
    vipldws_B.HP_prdtHtR[0] = 0.0F;
    vipldws_B.HP_prdtHtR[1] = 0.0F;
    vipldws_B.HP_prdtHtR[2] = 0.0F;
    vipldws_B.HP_prdtHtR[3] = 0.0F;
    vipldws_B.X_prdKZHX_prd[0] = 0.0F;
    vipldws_B.X_prdKZHX_prd[1] = 0.0F;
    vipldws_B.X_prdKZHX_prd[2] = 0.0F;
    vipldws_B.X_prdKZHX_prd[3] = 0.0F;
    vipldws_B.Selector5[0] = 0.0F;
    vipldws_B.Selector5[1] = 0.0F;
    vipldws_B.Selector5[2] = 0.0F;
    vipldws_B.ZHX_prd[0] = 0.0F;
    vipldws_B.ZHX_prd[1] = 0.0F;
    vipldws_B.Gain = 0.0F;
    vipldws_B.HoughTransform_o2[0] = -1.57079637F;
    vipldws_B.HoughTransform_o2[1] = -1.55334306F;
    vipldws_B.HoughTransform_o2[2] = -1.53588974F;
    vipldws_B.HoughTransform_o2[3] = -1.51843643F;
    vipldws_B.HoughTransform_o2[4] = -1.50098312F;
    vipldws_B.HoughTransform_o2[5] = -1.48352981F;
    vipldws_B.HoughTransform_o2[6] = -1.46607661F;
    vipldws_B.HoughTransform_o2[7] = -1.4486233F;
    vipldws_B.HoughTransform_o2[8] = -1.43117F;
    vipldws_B.HoughTransform_o2[9] = -1.41371667F;
    vipldws_B.HoughTransform_o2[10] = -1.39626336F;
    vipldws_B.HoughTransform_o2[11] = -1.37881017F;
    vipldws_B.HoughTransform_o2[12] = -1.36135685F;
    vipldws_B.HoughTransform_o2[13] = -1.34390354F;
    vipldws_B.HoughTransform_o2[14] = -1.32645023F;
    vipldws_B.HoughTransform_o2[15] = -1.30899692F;
    vipldws_B.HoughTransform_o2[16] = -1.2915436F;
    vipldws_B.HoughTransform_o2[17] = -1.27409041F;
    vipldws_B.HoughTransform_o2[18] = -1.2566371F;
    vipldws_B.HoughTransform_o2[19] = -1.23918378F;
    vipldws_B.HoughTransform_o2[20] = -1.22173047F;
    vipldws_B.HoughTransform_o2[21] = -1.20427716F;
    vipldws_B.HoughTransform_o2[22] = -1.18682384F;
    vipldws_B.HoughTransform_o2[23] = -1.16937065F;
    vipldws_B.HoughTransform_o2[24] = -1.15191734F;
    vipldws_B.HoughTransform_o2[25] = -1.13446403F;
    vipldws_B.HoughTransform_o2[26] = -1.11701071F;
    vipldws_B.HoughTransform_o2[27] = -1.0995574F;
    vipldws_B.HoughTransform_o2[28] = -1.08210409F;
    vipldws_B.HoughTransform_o2[29] = -1.06465089F;
    vipldws_B.HoughTransform_o2[30] = -1.04719758F;
    vipldws_B.HoughTransform_o2[31] = -1.02974427F;
    vipldws_B.HoughTransform_o2[32] = -1.01229095F;
    vipldws_B.HoughTransform_o2[33] = -0.994837701F;
    vipldws_B.HoughTransform_o2[34] = -0.977384388F;
    vipldws_B.HoughTransform_o2[35] = -0.959931076F;
    vipldws_B.HoughTransform_o2[36] = -0.942477822F;
    vipldws_B.HoughTransform_o2[37] = -0.925024509F;
    vipldws_B.HoughTransform_o2[38] = -0.907571197F;
    vipldws_B.HoughTransform_o2[39] = -0.890117943F;
    vipldws_B.HoughTransform_o2[40] = -0.87266463F;
    vipldws_B.HoughTransform_o2[41] = -0.855211318F;
    vipldws_B.HoughTransform_o2[42] = -0.837758064F;
    vipldws_B.HoughTransform_o2[43] = -0.820304751F;
    vipldws_B.HoughTransform_o2[44] = -0.802851439F;
    vipldws_B.HoughTransform_o2[45] = -0.785398185F;
    vipldws_B.HoughTransform_o2[46] = -0.767944872F;
    vipldws_B.HoughTransform_o2[47] = -0.75049156F;
    vipldws_B.HoughTransform_o2[48] = -0.733038306F;
    vipldws_B.HoughTransform_o2[49] = -0.715585F;
    vipldws_B.HoughTransform_o2[50] = -0.69813168F;
    vipldws_B.HoughTransform_o2[51] = -0.680678427F;
    vipldws_B.HoughTransform_o2[52] = -0.663225114F;
    vipldws_B.HoughTransform_o2[53] = -0.645771801F;
    vipldws_B.HoughTransform_o2[54] = -0.628318548F;
    vipldws_B.HoughTransform_o2[55] = -0.610865235F;
    vipldws_B.HoughTransform_o2[56] = -0.593411922F;
    vipldws_B.HoughTransform_o2[57] = -0.575958669F;
    vipldws_B.HoughTransform_o2[58] = -0.558505356F;
    vipldws_B.HoughTransform_o2[59] = -0.541052043F;
    vipldws_B.HoughTransform_o2[60] = -0.52359879F;
    vipldws_B.HoughTransform_o2[61] = -0.506145477F;
    vipldws_B.HoughTransform_o2[62] = -0.488692194F;
    vipldws_B.HoughTransform_o2[63] = -0.471238911F;
    vipldws_B.HoughTransform_o2[64] = -0.453785598F;
    vipldws_B.HoughTransform_o2[65] = -0.436332315F;
    vipldws_B.HoughTransform_o2[66] = -0.418879032F;
    vipldws_B.HoughTransform_o2[67] = -0.401425719F;
    vipldws_B.HoughTransform_o2[68] = -0.383972436F;
    vipldws_B.HoughTransform_o2[69] = -0.366519153F;
    vipldws_B.HoughTransform_o2[70] = -0.34906584F;
    vipldws_B.HoughTransform_o2[71] = -0.331612557F;
    vipldws_B.HoughTransform_o2[72] = -0.314159274F;
    vipldws_B.HoughTransform_o2[73] = -0.296705961F;
    vipldws_B.HoughTransform_o2[74] = -0.279252678F;
    vipldws_B.HoughTransform_o2[75] = -0.261799395F;
    vipldws_B.HoughTransform_o2[76] = -0.244346097F;
    vipldws_B.HoughTransform_o2[77] = -0.226892799F;
    vipldws_B.HoughTransform_o2[78] = -0.209439516F;
    vipldws_B.HoughTransform_o2[79] = -0.191986218F;
    vipldws_B.HoughTransform_o2[80] = -0.17453292F;
    vipldws_B.HoughTransform_o2[81] = -0.157079637F;
    vipldws_B.HoughTransform_o2[82] = -0.139626339F;
    vipldws_B.HoughTransform_o2[83] = -0.122173049F;
    vipldws_B.HoughTransform_o2[84] = -0.104719758F;
    vipldws_B.HoughTransform_o2[85] = -0.0872664601F;
    vipldws_B.HoughTransform_o2[86] = -0.0698131695F;
    vipldws_B.HoughTransform_o2[87] = -0.052359879F;
    vipldws_B.HoughTransform_o2[88] = -0.0349065848F;
    vipldws_B.HoughTransform_o2[89] = -0.0174532924F;
    vipldws_B.HoughTransform_o2[90] = 0.0F;
    vipldws_B.HoughTransform_o2[91] = 0.0174532924F;
    vipldws_B.HoughTransform_o2[92] = 0.0349065848F;
    vipldws_B.HoughTransform_o2[93] = 0.052359879F;
    vipldws_B.HoughTransform_o2[94] = 0.0698131695F;
    vipldws_B.HoughTransform_o2[95] = 0.0872664601F;
    vipldws_B.HoughTransform_o2[96] = 0.104719758F;
    vipldws_B.HoughTransform_o2[97] = 0.122173049F;
    vipldws_B.HoughTransform_o2[98] = 0.139626339F;
    vipldws_B.HoughTransform_o2[99] = 0.157079637F;
    vipldws_B.HoughTransform_o2[100] = 0.17453292F;
    vipldws_B.HoughTransform_o2[101] = 0.191986218F;
    vipldws_B.HoughTransform_o2[102] = 0.209439516F;
    vipldws_B.HoughTransform_o2[103] = 0.226892799F;
    vipldws_B.HoughTransform_o2[104] = 0.244346097F;
    vipldws_B.HoughTransform_o2[105] = 0.261799395F;
    vipldws_B.HoughTransform_o2[106] = 0.279252678F;
    vipldws_B.HoughTransform_o2[107] = 0.296705961F;
    vipldws_B.HoughTransform_o2[108] = 0.314159274F;
    vipldws_B.HoughTransform_o2[109] = 0.331612557F;
    vipldws_B.HoughTransform_o2[110] = 0.34906584F;
    vipldws_B.HoughTransform_o2[111] = 0.366519153F;
    vipldws_B.HoughTransform_o2[112] = 0.383972436F;
    vipldws_B.HoughTransform_o2[113] = 0.401425719F;
    vipldws_B.HoughTransform_o2[114] = 0.418879032F;
    vipldws_B.HoughTransform_o2[115] = 0.436332315F;
    vipldws_B.HoughTransform_o2[116] = 0.453785598F;
    vipldws_B.HoughTransform_o2[117] = 0.471238911F;
    vipldws_B.HoughTransform_o2[118] = 0.488692194F;
    vipldws_B.HoughTransform_o2[119] = 0.506145477F;
    vipldws_B.HoughTransform_o2[120] = 0.52359879F;
    vipldws_B.HoughTransform_o2[121] = 0.541052043F;
    vipldws_B.HoughTransform_o2[122] = 0.558505356F;
    vipldws_B.HoughTransform_o2[123] = 0.575958669F;
    vipldws_B.HoughTransform_o2[124] = 0.593411922F;
    vipldws_B.HoughTransform_o2[125] = 0.610865235F;
    vipldws_B.HoughTransform_o2[126] = 0.628318548F;
    vipldws_B.HoughTransform_o2[127] = 0.645771801F;
    vipldws_B.HoughTransform_o2[128] = 0.663225114F;
    vipldws_B.HoughTransform_o2[129] = 0.680678427F;
    vipldws_B.HoughTransform_o2[130] = 0.69813168F;
    vipldws_B.HoughTransform_o2[131] = 0.715585F;
    vipldws_B.HoughTransform_o2[132] = 0.733038306F;
    vipldws_B.HoughTransform_o2[133] = 0.75049156F;
    vipldws_B.HoughTransform_o2[134] = 0.767944872F;
    vipldws_B.HoughTransform_o2[135] = 0.785398185F;
    vipldws_B.HoughTransform_o2[136] = 0.802851439F;
    vipldws_B.HoughTransform_o2[137] = 0.820304751F;
    vipldws_B.HoughTransform_o2[138] = 0.837758064F;
    vipldws_B.HoughTransform_o2[139] = 0.855211318F;
    vipldws_B.HoughTransform_o2[140] = 0.87266463F;
    vipldws_B.HoughTransform_o2[141] = 0.890117943F;
    vipldws_B.HoughTransform_o2[142] = 0.907571197F;
    vipldws_B.HoughTransform_o2[143] = 0.925024509F;
    vipldws_B.HoughTransform_o2[144] = 0.942477822F;
    vipldws_B.HoughTransform_o2[145] = 0.959931076F;
    vipldws_B.HoughTransform_o2[146] = 0.977384388F;
    vipldws_B.HoughTransform_o2[147] = 0.994837701F;
    vipldws_B.HoughTransform_o2[148] = 1.01229095F;
    vipldws_B.HoughTransform_o2[149] = 1.02974427F;
    vipldws_B.HoughTransform_o2[150] = 1.04719758F;
    vipldws_B.HoughTransform_o2[151] = 1.06465089F;
    vipldws_B.HoughTransform_o2[152] = 1.08210409F;
    vipldws_B.HoughTransform_o2[153] = 1.0995574F;
    vipldws_B.HoughTransform_o2[154] = 1.11701071F;
    vipldws_B.HoughTransform_o2[155] = 1.13446403F;
    vipldws_B.HoughTransform_o2[156] = 1.15191734F;
    vipldws_B.HoughTransform_o2[157] = 1.16937065F;
    vipldws_B.HoughTransform_o2[158] = 1.18682384F;
    vipldws_B.HoughTransform_o2[159] = 1.20427716F;
    vipldws_B.HoughTransform_o2[160] = 1.22173047F;
    vipldws_B.HoughTransform_o2[161] = 1.23918378F;
    vipldws_B.HoughTransform_o2[162] = 1.2566371F;
    vipldws_B.HoughTransform_o2[163] = 1.27409041F;
    vipldws_B.HoughTransform_o2[164] = 1.2915436F;
    vipldws_B.HoughTransform_o2[165] = 1.30899692F;
    vipldws_B.HoughTransform_o2[166] = 1.32645023F;
    vipldws_B.HoughTransform_o2[167] = 1.34390354F;
    vipldws_B.HoughTransform_o2[168] = 1.36135685F;
    vipldws_B.HoughTransform_o2[169] = 1.37881017F;
    vipldws_B.HoughTransform_o2[170] = 1.39626336F;
    vipldws_B.HoughTransform_o2[171] = 1.41371667F;
    vipldws_B.HoughTransform_o2[172] = 1.43117F;
    vipldws_B.HoughTransform_o2[173] = 1.4486233F;
    vipldws_B.HoughTransform_o2[174] = 1.46607661F;
    vipldws_B.HoughTransform_o2[175] = 1.48352981F;
    vipldws_B.HoughTransform_o2[176] = 1.50098312F;
    vipldws_B.HoughTransform_o2[177] = 1.51843643F;
    vipldws_B.HoughTransform_o2[178] = 1.53588974F;
    vipldws_B.HoughTransform_o2[179] = 1.55334306F;
    vipldws_B.HoughTransform_o3[0] = -312.0F;
    vipldws_B.HoughTransform_o3[1] = -311.0F;
    vipldws_B.HoughTransform_o3[2] = -310.0F;
    vipldws_B.HoughTransform_o3[3] = -309.0F;
    vipldws_B.HoughTransform_o3[4] = -308.0F;
    vipldws_B.HoughTransform_o3[5] = -307.0F;
    vipldws_B.HoughTransform_o3[6] = -306.0F;
    vipldws_B.HoughTransform_o3[7] = -305.0F;
    vipldws_B.HoughTransform_o3[8] = -304.0F;
    vipldws_B.HoughTransform_o3[9] = -303.0F;
    vipldws_B.HoughTransform_o3[10] = -302.0F;
    vipldws_B.HoughTransform_o3[11] = -301.0F;
    vipldws_B.HoughTransform_o3[12] = -300.0F;
    vipldws_B.HoughTransform_o3[13] = -299.0F;
    vipldws_B.HoughTransform_o3[14] = -298.0F;
    vipldws_B.HoughTransform_o3[15] = -297.0F;
    vipldws_B.HoughTransform_o3[16] = -296.0F;
    vipldws_B.HoughTransform_o3[17] = -295.0F;
    vipldws_B.HoughTransform_o3[18] = -294.0F;
    vipldws_B.HoughTransform_o3[19] = -293.0F;
    vipldws_B.HoughTransform_o3[20] = -292.0F;
    vipldws_B.HoughTransform_o3[21] = -291.0F;
    vipldws_B.HoughTransform_o3[22] = -290.0F;
    vipldws_B.HoughTransform_o3[23] = -289.0F;
    vipldws_B.HoughTransform_o3[24] = -288.0F;
    vipldws_B.HoughTransform_o3[25] = -287.0F;
    vipldws_B.HoughTransform_o3[26] = -286.0F;
    vipldws_B.HoughTransform_o3[27] = -285.0F;
    vipldws_B.HoughTransform_o3[28] = -284.0F;
    vipldws_B.HoughTransform_o3[29] = -283.0F;
    vipldws_B.HoughTransform_o3[30] = -282.0F;
    vipldws_B.HoughTransform_o3[31] = -281.0F;
    vipldws_B.HoughTransform_o3[32] = -280.0F;
    vipldws_B.HoughTransform_o3[33] = -279.0F;
    vipldws_B.HoughTransform_o3[34] = -278.0F;
    vipldws_B.HoughTransform_o3[35] = -277.0F;
    vipldws_B.HoughTransform_o3[36] = -276.0F;
    vipldws_B.HoughTransform_o3[37] = -275.0F;
    vipldws_B.HoughTransform_o3[38] = -274.0F;
    vipldws_B.HoughTransform_o3[39] = -273.0F;
    vipldws_B.HoughTransform_o3[40] = -272.0F;
    vipldws_B.HoughTransform_o3[41] = -271.0F;
    vipldws_B.HoughTransform_o3[42] = -270.0F;
    vipldws_B.HoughTransform_o3[43] = -269.0F;
    vipldws_B.HoughTransform_o3[44] = -268.0F;
    vipldws_B.HoughTransform_o3[45] = -267.0F;
    vipldws_B.HoughTransform_o3[46] = -266.0F;
    vipldws_B.HoughTransform_o3[47] = -265.0F;
    vipldws_B.HoughTransform_o3[48] = -264.0F;
    vipldws_B.HoughTransform_o3[49] = -263.0F;
    vipldws_B.HoughTransform_o3[50] = -262.0F;
    vipldws_B.HoughTransform_o3[51] = -261.0F;
    vipldws_B.HoughTransform_o3[52] = -260.0F;
    vipldws_B.HoughTransform_o3[53] = -259.0F;
    vipldws_B.HoughTransform_o3[54] = -258.0F;
    vipldws_B.HoughTransform_o3[55] = -257.0F;
    vipldws_B.HoughTransform_o3[56] = -256.0F;
    vipldws_B.HoughTransform_o3[57] = -255.0F;
    vipldws_B.HoughTransform_o3[58] = -254.0F;
    vipldws_B.HoughTransform_o3[59] = -253.0F;
    vipldws_B.HoughTransform_o3[60] = -252.0F;
    vipldws_B.HoughTransform_o3[61] = -251.0F;
    vipldws_B.HoughTransform_o3[62] = -250.0F;
    vipldws_B.HoughTransform_o3[63] = -249.0F;
    vipldws_B.HoughTransform_o3[64] = -248.0F;
    vipldws_B.HoughTransform_o3[65] = -247.0F;
    vipldws_B.HoughTransform_o3[66] = -246.0F;
    vipldws_B.HoughTransform_o3[67] = -245.0F;
    vipldws_B.HoughTransform_o3[68] = -244.0F;
    vipldws_B.HoughTransform_o3[69] = -243.0F;
    vipldws_B.HoughTransform_o3[70] = -242.0F;
    vipldws_B.HoughTransform_o3[71] = -241.0F;
    vipldws_B.HoughTransform_o3[72] = -240.0F;
    vipldws_B.HoughTransform_o3[73] = -239.0F;
    vipldws_B.HoughTransform_o3[74] = -238.0F;
    vipldws_B.HoughTransform_o3[75] = -237.0F;
    vipldws_B.HoughTransform_o3[76] = -236.0F;
    vipldws_B.HoughTransform_o3[77] = -235.0F;
    vipldws_B.HoughTransform_o3[78] = -234.0F;
    vipldws_B.HoughTransform_o3[79] = -233.0F;
    vipldws_B.HoughTransform_o3[80] = -232.0F;
    vipldws_B.HoughTransform_o3[81] = -231.0F;
    vipldws_B.HoughTransform_o3[82] = -230.0F;
    vipldws_B.HoughTransform_o3[83] = -229.0F;
    vipldws_B.HoughTransform_o3[84] = -228.0F;
    vipldws_B.HoughTransform_o3[85] = -227.0F;
    vipldws_B.HoughTransform_o3[86] = -226.0F;
    vipldws_B.HoughTransform_o3[87] = -225.0F;
    vipldws_B.HoughTransform_o3[88] = -224.0F;
    vipldws_B.HoughTransform_o3[89] = -223.0F;
    vipldws_B.HoughTransform_o3[90] = -222.0F;
    vipldws_B.HoughTransform_o3[91] = -221.0F;
    vipldws_B.HoughTransform_o3[92] = -220.0F;
    vipldws_B.HoughTransform_o3[93] = -219.0F;
    vipldws_B.HoughTransform_o3[94] = -218.0F;
    vipldws_B.HoughTransform_o3[95] = -217.0F;
    vipldws_B.HoughTransform_o3[96] = -216.0F;
    vipldws_B.HoughTransform_o3[97] = -215.0F;
    vipldws_B.HoughTransform_o3[98] = -214.0F;
    vipldws_B.HoughTransform_o3[99] = -213.0F;
    vipldws_B.HoughTransform_o3[100] = -212.0F;
    vipldws_B.HoughTransform_o3[101] = -211.0F;
    vipldws_B.HoughTransform_o3[102] = -210.0F;
    vipldws_B.HoughTransform_o3[103] = -209.0F;
    vipldws_B.HoughTransform_o3[104] = -208.0F;
    vipldws_B.HoughTransform_o3[105] = -207.0F;
    vipldws_B.HoughTransform_o3[106] = -206.0F;
    vipldws_B.HoughTransform_o3[107] = -205.0F;
    vipldws_B.HoughTransform_o3[108] = -204.0F;
    vipldws_B.HoughTransform_o3[109] = -203.0F;
    vipldws_B.HoughTransform_o3[110] = -202.0F;
    vipldws_B.HoughTransform_o3[111] = -201.0F;
    vipldws_B.HoughTransform_o3[112] = -200.0F;
    vipldws_B.HoughTransform_o3[113] = -199.0F;
    vipldws_B.HoughTransform_o3[114] = -198.0F;
    vipldws_B.HoughTransform_o3[115] = -197.0F;
    vipldws_B.HoughTransform_o3[116] = -196.0F;
    vipldws_B.HoughTransform_o3[117] = -195.0F;
    vipldws_B.HoughTransform_o3[118] = -194.0F;
    vipldws_B.HoughTransform_o3[119] = -193.0F;
    vipldws_B.HoughTransform_o3[120] = -192.0F;
    vipldws_B.HoughTransform_o3[121] = -191.0F;
    vipldws_B.HoughTransform_o3[122] = -190.0F;
    vipldws_B.HoughTransform_o3[123] = -189.0F;
    vipldws_B.HoughTransform_o3[124] = -188.0F;
    vipldws_B.HoughTransform_o3[125] = -187.0F;
    vipldws_B.HoughTransform_o3[126] = -186.0F;
    vipldws_B.HoughTransform_o3[127] = -185.0F;
    vipldws_B.HoughTransform_o3[128] = -184.0F;
    vipldws_B.HoughTransform_o3[129] = -183.0F;
    vipldws_B.HoughTransform_o3[130] = -182.0F;
    vipldws_B.HoughTransform_o3[131] = -181.0F;
    vipldws_B.HoughTransform_o3[132] = -180.0F;
    vipldws_B.HoughTransform_o3[133] = -179.0F;
    vipldws_B.HoughTransform_o3[134] = -178.0F;
    vipldws_B.HoughTransform_o3[135] = -177.0F;
    vipldws_B.HoughTransform_o3[136] = -176.0F;
    vipldws_B.HoughTransform_o3[137] = -175.0F;
    vipldws_B.HoughTransform_o3[138] = -174.0F;
    vipldws_B.HoughTransform_o3[139] = -173.0F;
    vipldws_B.HoughTransform_o3[140] = -172.0F;
    vipldws_B.HoughTransform_o3[141] = -171.0F;
    vipldws_B.HoughTransform_o3[142] = -170.0F;
    vipldws_B.HoughTransform_o3[143] = -169.0F;
    vipldws_B.HoughTransform_o3[144] = -168.0F;
    vipldws_B.HoughTransform_o3[145] = -167.0F;
    vipldws_B.HoughTransform_o3[146] = -166.0F;
    vipldws_B.HoughTransform_o3[147] = -165.0F;
    vipldws_B.HoughTransform_o3[148] = -164.0F;
    vipldws_B.HoughTransform_o3[149] = -163.0F;
    vipldws_B.HoughTransform_o3[150] = -162.0F;
    vipldws_B.HoughTransform_o3[151] = -161.0F;
    vipldws_B.HoughTransform_o3[152] = -160.0F;
    vipldws_B.HoughTransform_o3[153] = -159.0F;
    vipldws_B.HoughTransform_o3[154] = -158.0F;
    vipldws_B.HoughTransform_o3[155] = -157.0F;
    vipldws_B.HoughTransform_o3[156] = -156.0F;
    vipldws_B.HoughTransform_o3[157] = -155.0F;
    vipldws_B.HoughTransform_o3[158] = -154.0F;
    vipldws_B.HoughTransform_o3[159] = -153.0F;
    vipldws_B.HoughTransform_o3[160] = -152.0F;
    vipldws_B.HoughTransform_o3[161] = -151.0F;
    vipldws_B.HoughTransform_o3[162] = -150.0F;
    vipldws_B.HoughTransform_o3[163] = -149.0F;
    vipldws_B.HoughTransform_o3[164] = -148.0F;
    vipldws_B.HoughTransform_o3[165] = -147.0F;
    vipldws_B.HoughTransform_o3[166] = -146.0F;
    vipldws_B.HoughTransform_o3[167] = -145.0F;
    vipldws_B.HoughTransform_o3[168] = -144.0F;
    vipldws_B.HoughTransform_o3[169] = -143.0F;
    vipldws_B.HoughTransform_o3[170] = -142.0F;
    vipldws_B.HoughTransform_o3[171] = -141.0F;
    vipldws_B.HoughTransform_o3[172] = -140.0F;
    vipldws_B.HoughTransform_o3[173] = -139.0F;
    vipldws_B.HoughTransform_o3[174] = -138.0F;
    vipldws_B.HoughTransform_o3[175] = -137.0F;
    vipldws_B.HoughTransform_o3[176] = -136.0F;
    vipldws_B.HoughTransform_o3[177] = -135.0F;
    vipldws_B.HoughTransform_o3[178] = -134.0F;
    vipldws_B.HoughTransform_o3[179] = -133.0F;
    vipldws_B.HoughTransform_o3[180] = -132.0F;
    vipldws_B.HoughTransform_o3[181] = -131.0F;
    vipldws_B.HoughTransform_o3[182] = -130.0F;
    vipldws_B.HoughTransform_o3[183] = -129.0F;
    vipldws_B.HoughTransform_o3[184] = -128.0F;
    vipldws_B.HoughTransform_o3[185] = -127.0F;
    vipldws_B.HoughTransform_o3[186] = -126.0F;
    vipldws_B.HoughTransform_o3[187] = -125.0F;
    vipldws_B.HoughTransform_o3[188] = -124.0F;
    vipldws_B.HoughTransform_o3[189] = -123.0F;
    vipldws_B.HoughTransform_o3[190] = -122.0F;
    vipldws_B.HoughTransform_o3[191] = -121.0F;
    vipldws_B.HoughTransform_o3[192] = -120.0F;
    vipldws_B.HoughTransform_o3[193] = -119.0F;
    vipldws_B.HoughTransform_o3[194] = -118.0F;
    vipldws_B.HoughTransform_o3[195] = -117.0F;
    vipldws_B.HoughTransform_o3[196] = -116.0F;
    vipldws_B.HoughTransform_o3[197] = -115.0F;
    vipldws_B.HoughTransform_o3[198] = -114.0F;
    vipldws_B.HoughTransform_o3[199] = -113.0F;
    vipldws_B.HoughTransform_o3[200] = -112.0F;
    vipldws_B.HoughTransform_o3[201] = -111.0F;
    vipldws_B.HoughTransform_o3[202] = -110.0F;
    vipldws_B.HoughTransform_o3[203] = -109.0F;
    vipldws_B.HoughTransform_o3[204] = -108.0F;
    vipldws_B.HoughTransform_o3[205] = -107.0F;
    vipldws_B.HoughTransform_o3[206] = -106.0F;
    vipldws_B.HoughTransform_o3[207] = -105.0F;
    vipldws_B.HoughTransform_o3[208] = -104.0F;
    vipldws_B.HoughTransform_o3[209] = -103.0F;
    vipldws_B.HoughTransform_o3[210] = -102.0F;
    vipldws_B.HoughTransform_o3[211] = -101.0F;
    vipldws_B.HoughTransform_o3[212] = -100.0F;
    vipldws_B.HoughTransform_o3[213] = -99.0F;
    vipldws_B.HoughTransform_o3[214] = -98.0F;
    vipldws_B.HoughTransform_o3[215] = -97.0F;
    vipldws_B.HoughTransform_o3[216] = -96.0F;
    vipldws_B.HoughTransform_o3[217] = -95.0F;
    vipldws_B.HoughTransform_o3[218] = -94.0F;
    vipldws_B.HoughTransform_o3[219] = -93.0F;
    vipldws_B.HoughTransform_o3[220] = -92.0F;
    vipldws_B.HoughTransform_o3[221] = -91.0F;
    vipldws_B.HoughTransform_o3[222] = -90.0F;
    vipldws_B.HoughTransform_o3[223] = -89.0F;
    vipldws_B.HoughTransform_o3[224] = -88.0F;
    vipldws_B.HoughTransform_o3[225] = -87.0F;
    vipldws_B.HoughTransform_o3[226] = -86.0F;
    vipldws_B.HoughTransform_o3[227] = -85.0F;
    vipldws_B.HoughTransform_o3[228] = -84.0F;
    vipldws_B.HoughTransform_o3[229] = -83.0F;
    vipldws_B.HoughTransform_o3[230] = -82.0F;
    vipldws_B.HoughTransform_o3[231] = -81.0F;
    vipldws_B.HoughTransform_o3[232] = -80.0F;
    vipldws_B.HoughTransform_o3[233] = -79.0F;
    vipldws_B.HoughTransform_o3[234] = -78.0F;
    vipldws_B.HoughTransform_o3[235] = -77.0F;
    vipldws_B.HoughTransform_o3[236] = -76.0F;
    vipldws_B.HoughTransform_o3[237] = -75.0F;
    vipldws_B.HoughTransform_o3[238] = -74.0F;
    vipldws_B.HoughTransform_o3[239] = -73.0F;
    vipldws_B.HoughTransform_o3[240] = -72.0F;
    vipldws_B.HoughTransform_o3[241] = -71.0F;
    vipldws_B.HoughTransform_o3[242] = -70.0F;
    vipldws_B.HoughTransform_o3[243] = -69.0F;
    vipldws_B.HoughTransform_o3[244] = -68.0F;
    vipldws_B.HoughTransform_o3[245] = -67.0F;
    vipldws_B.HoughTransform_o3[246] = -66.0F;
    vipldws_B.HoughTransform_o3[247] = -65.0F;
    vipldws_B.HoughTransform_o3[248] = -64.0F;
    vipldws_B.HoughTransform_o3[249] = -63.0F;
    vipldws_B.HoughTransform_o3[250] = -62.0F;
    vipldws_B.HoughTransform_o3[251] = -61.0F;
    vipldws_B.HoughTransform_o3[252] = -60.0F;
    vipldws_B.HoughTransform_o3[253] = -59.0F;
    vipldws_B.HoughTransform_o3[254] = -58.0F;
    vipldws_B.HoughTransform_o3[255] = -57.0F;
    vipldws_B.HoughTransform_o3[256] = -56.0F;
    vipldws_B.HoughTransform_o3[257] = -55.0F;
    vipldws_B.HoughTransform_o3[258] = -54.0F;
    vipldws_B.HoughTransform_o3[259] = -53.0F;
    vipldws_B.HoughTransform_o3[260] = -52.0F;
    vipldws_B.HoughTransform_o3[261] = -51.0F;
    vipldws_B.HoughTransform_o3[262] = -50.0F;
    vipldws_B.HoughTransform_o3[263] = -49.0F;
    vipldws_B.HoughTransform_o3[264] = -48.0F;
    vipldws_B.HoughTransform_o3[265] = -47.0F;
    vipldws_B.HoughTransform_o3[266] = -46.0F;
    vipldws_B.HoughTransform_o3[267] = -45.0F;
    vipldws_B.HoughTransform_o3[268] = -44.0F;
    vipldws_B.HoughTransform_o3[269] = -43.0F;
    vipldws_B.HoughTransform_o3[270] = -42.0F;
    vipldws_B.HoughTransform_o3[271] = -41.0F;
    vipldws_B.HoughTransform_o3[272] = -40.0F;
    vipldws_B.HoughTransform_o3[273] = -39.0F;
    vipldws_B.HoughTransform_o3[274] = -38.0F;
    vipldws_B.HoughTransform_o3[275] = -37.0F;
    vipldws_B.HoughTransform_o3[276] = -36.0F;
    vipldws_B.HoughTransform_o3[277] = -35.0F;
    vipldws_B.HoughTransform_o3[278] = -34.0F;
    vipldws_B.HoughTransform_o3[279] = -33.0F;
    vipldws_B.HoughTransform_o3[280] = -32.0F;
    vipldws_B.HoughTransform_o3[281] = -31.0F;
    vipldws_B.HoughTransform_o3[282] = -30.0F;
    vipldws_B.HoughTransform_o3[283] = -29.0F;
    vipldws_B.HoughTransform_o3[284] = -28.0F;
    vipldws_B.HoughTransform_o3[285] = -27.0F;
    vipldws_B.HoughTransform_o3[286] = -26.0F;
    vipldws_B.HoughTransform_o3[287] = -25.0F;
    vipldws_B.HoughTransform_o3[288] = -24.0F;
    vipldws_B.HoughTransform_o3[289] = -23.0F;
    vipldws_B.HoughTransform_o3[290] = -22.0F;
    vipldws_B.HoughTransform_o3[291] = -21.0F;
    vipldws_B.HoughTransform_o3[292] = -20.0F;
    vipldws_B.HoughTransform_o3[293] = -19.0F;
    vipldws_B.HoughTransform_o3[294] = -18.0F;
    vipldws_B.HoughTransform_o3[295] = -17.0F;
    vipldws_B.HoughTransform_o3[296] = -16.0F;
    vipldws_B.HoughTransform_o3[297] = -15.0F;
    vipldws_B.HoughTransform_o3[298] = -14.0F;
    vipldws_B.HoughTransform_o3[299] = -13.0F;
    vipldws_B.HoughTransform_o3[300] = -12.0F;
    vipldws_B.HoughTransform_o3[301] = -11.0F;
    vipldws_B.HoughTransform_o3[302] = -10.0F;
    vipldws_B.HoughTransform_o3[303] = -9.0F;
    vipldws_B.HoughTransform_o3[304] = -8.0F;
    vipldws_B.HoughTransform_o3[305] = -7.0F;
    vipldws_B.HoughTransform_o3[306] = -6.0F;
    vipldws_B.HoughTransform_o3[307] = -5.0F;
    vipldws_B.HoughTransform_o3[308] = -4.0F;
    vipldws_B.HoughTransform_o3[309] = -3.0F;
    vipldws_B.HoughTransform_o3[310] = -2.0F;
    vipldws_B.HoughTransform_o3[311] = -1.0F;
    vipldws_B.HoughTransform_o3[312] = 0.0F;
    vipldws_B.HoughTransform_o3[313] = 1.0F;
    vipldws_B.HoughTransform_o3[314] = 2.0F;
    vipldws_B.HoughTransform_o3[315] = 3.0F;
    vipldws_B.HoughTransform_o3[316] = 4.0F;
    vipldws_B.HoughTransform_o3[317] = 5.0F;
    vipldws_B.HoughTransform_o3[318] = 6.0F;
    vipldws_B.HoughTransform_o3[319] = 7.0F;
    vipldws_B.HoughTransform_o3[320] = 8.0F;
    vipldws_B.HoughTransform_o3[321] = 9.0F;
    vipldws_B.HoughTransform_o3[322] = 10.0F;
    vipldws_B.HoughTransform_o3[323] = 11.0F;
    vipldws_B.HoughTransform_o3[324] = 12.0F;
    vipldws_B.HoughTransform_o3[325] = 13.0F;
    vipldws_B.HoughTransform_o3[326] = 14.0F;
    vipldws_B.HoughTransform_o3[327] = 15.0F;
    vipldws_B.HoughTransform_o3[328] = 16.0F;
    vipldws_B.HoughTransform_o3[329] = 17.0F;
    vipldws_B.HoughTransform_o3[330] = 18.0F;
    vipldws_B.HoughTransform_o3[331] = 19.0F;
    vipldws_B.HoughTransform_o3[332] = 20.0F;
    vipldws_B.HoughTransform_o3[333] = 21.0F;
    vipldws_B.HoughTransform_o3[334] = 22.0F;
    vipldws_B.HoughTransform_o3[335] = 23.0F;
    vipldws_B.HoughTransform_o3[336] = 24.0F;
    vipldws_B.HoughTransform_o3[337] = 25.0F;
    vipldws_B.HoughTransform_o3[338] = 26.0F;
    vipldws_B.HoughTransform_o3[339] = 27.0F;
    vipldws_B.HoughTransform_o3[340] = 28.0F;
    vipldws_B.HoughTransform_o3[341] = 29.0F;
    vipldws_B.HoughTransform_o3[342] = 30.0F;
    vipldws_B.HoughTransform_o3[343] = 31.0F;
    vipldws_B.HoughTransform_o3[344] = 32.0F;
    vipldws_B.HoughTransform_o3[345] = 33.0F;
    vipldws_B.HoughTransform_o3[346] = 34.0F;
    vipldws_B.HoughTransform_o3[347] = 35.0F;
    vipldws_B.HoughTransform_o3[348] = 36.0F;
    vipldws_B.HoughTransform_o3[349] = 37.0F;
    vipldws_B.HoughTransform_o3[350] = 38.0F;
    vipldws_B.HoughTransform_o3[351] = 39.0F;
    vipldws_B.HoughTransform_o3[352] = 40.0F;
    vipldws_B.HoughTransform_o3[353] = 41.0F;
    vipldws_B.HoughTransform_o3[354] = 42.0F;
    vipldws_B.HoughTransform_o3[355] = 43.0F;
    vipldws_B.HoughTransform_o3[356] = 44.0F;
    vipldws_B.HoughTransform_o3[357] = 45.0F;
    vipldws_B.HoughTransform_o3[358] = 46.0F;
    vipldws_B.HoughTransform_o3[359] = 47.0F;
    vipldws_B.HoughTransform_o3[360] = 48.0F;
    vipldws_B.HoughTransform_o3[361] = 49.0F;
    vipldws_B.HoughTransform_o3[362] = 50.0F;
    vipldws_B.HoughTransform_o3[363] = 51.0F;
    vipldws_B.HoughTransform_o3[364] = 52.0F;
    vipldws_B.HoughTransform_o3[365] = 53.0F;
    vipldws_B.HoughTransform_o3[366] = 54.0F;
    vipldws_B.HoughTransform_o3[367] = 55.0F;
    vipldws_B.HoughTransform_o3[368] = 56.0F;
    vipldws_B.HoughTransform_o3[369] = 57.0F;
    vipldws_B.HoughTransform_o3[370] = 58.0F;
    vipldws_B.HoughTransform_o3[371] = 59.0F;
    vipldws_B.HoughTransform_o3[372] = 60.0F;
    vipldws_B.HoughTransform_o3[373] = 61.0F;
    vipldws_B.HoughTransform_o3[374] = 62.0F;
    vipldws_B.HoughTransform_o3[375] = 63.0F;
    vipldws_B.HoughTransform_o3[376] = 64.0F;
    vipldws_B.HoughTransform_o3[377] = 65.0F;
    vipldws_B.HoughTransform_o3[378] = 66.0F;
    vipldws_B.HoughTransform_o3[379] = 67.0F;
    vipldws_B.HoughTransform_o3[380] = 68.0F;
    vipldws_B.HoughTransform_o3[381] = 69.0F;
    vipldws_B.HoughTransform_o3[382] = 70.0F;
    vipldws_B.HoughTransform_o3[383] = 71.0F;
    vipldws_B.HoughTransform_o3[384] = 72.0F;
    vipldws_B.HoughTransform_o3[385] = 73.0F;
    vipldws_B.HoughTransform_o3[386] = 74.0F;
    vipldws_B.HoughTransform_o3[387] = 75.0F;
    vipldws_B.HoughTransform_o3[388] = 76.0F;
    vipldws_B.HoughTransform_o3[389] = 77.0F;
    vipldws_B.HoughTransform_o3[390] = 78.0F;
    vipldws_B.HoughTransform_o3[391] = 79.0F;
    vipldws_B.HoughTransform_o3[392] = 80.0F;
    vipldws_B.HoughTransform_o3[393] = 81.0F;
    vipldws_B.HoughTransform_o3[394] = 82.0F;
    vipldws_B.HoughTransform_o3[395] = 83.0F;
    vipldws_B.HoughTransform_o3[396] = 84.0F;
    vipldws_B.HoughTransform_o3[397] = 85.0F;
    vipldws_B.HoughTransform_o3[398] = 86.0F;
    vipldws_B.HoughTransform_o3[399] = 87.0F;
    vipldws_B.HoughTransform_o3[400] = 88.0F;
    vipldws_B.HoughTransform_o3[401] = 89.0F;
    vipldws_B.HoughTransform_o3[402] = 90.0F;
    vipldws_B.HoughTransform_o3[403] = 91.0F;
    vipldws_B.HoughTransform_o3[404] = 92.0F;
    vipldws_B.HoughTransform_o3[405] = 93.0F;
    vipldws_B.HoughTransform_o3[406] = 94.0F;
    vipldws_B.HoughTransform_o3[407] = 95.0F;
    vipldws_B.HoughTransform_o3[408] = 96.0F;
    vipldws_B.HoughTransform_o3[409] = 97.0F;
    vipldws_B.HoughTransform_o3[410] = 98.0F;
    vipldws_B.HoughTransform_o3[411] = 99.0F;
    vipldws_B.HoughTransform_o3[412] = 100.0F;
    vipldws_B.HoughTransform_o3[413] = 101.0F;
    vipldws_B.HoughTransform_o3[414] = 102.0F;
    vipldws_B.HoughTransform_o3[415] = 103.0F;
    vipldws_B.HoughTransform_o3[416] = 104.0F;
    vipldws_B.HoughTransform_o3[417] = 105.0F;
    vipldws_B.HoughTransform_o3[418] = 106.0F;
    vipldws_B.HoughTransform_o3[419] = 107.0F;
    vipldws_B.HoughTransform_o3[420] = 108.0F;
    vipldws_B.HoughTransform_o3[421] = 109.0F;
    vipldws_B.HoughTransform_o3[422] = 110.0F;
    vipldws_B.HoughTransform_o3[423] = 111.0F;
    vipldws_B.HoughTransform_o3[424] = 112.0F;
    vipldws_B.HoughTransform_o3[425] = 113.0F;
    vipldws_B.HoughTransform_o3[426] = 114.0F;
    vipldws_B.HoughTransform_o3[427] = 115.0F;
    vipldws_B.HoughTransform_o3[428] = 116.0F;
    vipldws_B.HoughTransform_o3[429] = 117.0F;
    vipldws_B.HoughTransform_o3[430] = 118.0F;
    vipldws_B.HoughTransform_o3[431] = 119.0F;
    vipldws_B.HoughTransform_o3[432] = 120.0F;
    vipldws_B.HoughTransform_o3[433] = 121.0F;
    vipldws_B.HoughTransform_o3[434] = 122.0F;
    vipldws_B.HoughTransform_o3[435] = 123.0F;
    vipldws_B.HoughTransform_o3[436] = 124.0F;
    vipldws_B.HoughTransform_o3[437] = 125.0F;
    vipldws_B.HoughTransform_o3[438] = 126.0F;
    vipldws_B.HoughTransform_o3[439] = 127.0F;
    vipldws_B.HoughTransform_o3[440] = 128.0F;
    vipldws_B.HoughTransform_o3[441] = 129.0F;
    vipldws_B.HoughTransform_o3[442] = 130.0F;
    vipldws_B.HoughTransform_o3[443] = 131.0F;
    vipldws_B.HoughTransform_o3[444] = 132.0F;
    vipldws_B.HoughTransform_o3[445] = 133.0F;
    vipldws_B.HoughTransform_o3[446] = 134.0F;
    vipldws_B.HoughTransform_o3[447] = 135.0F;
    vipldws_B.HoughTransform_o3[448] = 136.0F;
    vipldws_B.HoughTransform_o3[449] = 137.0F;
    vipldws_B.HoughTransform_o3[450] = 138.0F;
    vipldws_B.HoughTransform_o3[451] = 139.0F;
    vipldws_B.HoughTransform_o3[452] = 140.0F;
    vipldws_B.HoughTransform_o3[453] = 141.0F;
    vipldws_B.HoughTransform_o3[454] = 142.0F;
    vipldws_B.HoughTransform_o3[455] = 143.0F;
    vipldws_B.HoughTransform_o3[456] = 144.0F;
    vipldws_B.HoughTransform_o3[457] = 145.0F;
    vipldws_B.HoughTransform_o3[458] = 146.0F;
    vipldws_B.HoughTransform_o3[459] = 147.0F;
    vipldws_B.HoughTransform_o3[460] = 148.0F;
    vipldws_B.HoughTransform_o3[461] = 149.0F;
    vipldws_B.HoughTransform_o3[462] = 150.0F;
    vipldws_B.HoughTransform_o3[463] = 151.0F;
    vipldws_B.HoughTransform_o3[464] = 152.0F;
    vipldws_B.HoughTransform_o3[465] = 153.0F;
    vipldws_B.HoughTransform_o3[466] = 154.0F;
    vipldws_B.HoughTransform_o3[467] = 155.0F;
    vipldws_B.HoughTransform_o3[468] = 156.0F;
    vipldws_B.HoughTransform_o3[469] = 157.0F;
    vipldws_B.HoughTransform_o3[470] = 158.0F;
    vipldws_B.HoughTransform_o3[471] = 159.0F;
    vipldws_B.HoughTransform_o3[472] = 160.0F;
    vipldws_B.HoughTransform_o3[473] = 161.0F;
    vipldws_B.HoughTransform_o3[474] = 162.0F;
    vipldws_B.HoughTransform_o3[475] = 163.0F;
    vipldws_B.HoughTransform_o3[476] = 164.0F;
    vipldws_B.HoughTransform_o3[477] = 165.0F;
    vipldws_B.HoughTransform_o3[478] = 166.0F;
    vipldws_B.HoughTransform_o3[479] = 167.0F;
    vipldws_B.HoughTransform_o3[480] = 168.0F;
    vipldws_B.HoughTransform_o3[481] = 169.0F;
    vipldws_B.HoughTransform_o3[482] = 170.0F;
    vipldws_B.HoughTransform_o3[483] = 171.0F;
    vipldws_B.HoughTransform_o3[484] = 172.0F;
    vipldws_B.HoughTransform_o3[485] = 173.0F;
    vipldws_B.HoughTransform_o3[486] = 174.0F;
    vipldws_B.HoughTransform_o3[487] = 175.0F;
    vipldws_B.HoughTransform_o3[488] = 176.0F;
    vipldws_B.HoughTransform_o3[489] = 177.0F;
    vipldws_B.HoughTransform_o3[490] = 178.0F;
    vipldws_B.HoughTransform_o3[491] = 179.0F;
    vipldws_B.HoughTransform_o3[492] = 180.0F;
    vipldws_B.HoughTransform_o3[493] = 181.0F;
    vipldws_B.HoughTransform_o3[494] = 182.0F;
    vipldws_B.HoughTransform_o3[495] = 183.0F;
    vipldws_B.HoughTransform_o3[496] = 184.0F;
    vipldws_B.HoughTransform_o3[497] = 185.0F;
    vipldws_B.HoughTransform_o3[498] = 186.0F;
    vipldws_B.HoughTransform_o3[499] = 187.0F;
    vipldws_B.HoughTransform_o3[500] = 188.0F;
    vipldws_B.HoughTransform_o3[501] = 189.0F;
    vipldws_B.HoughTransform_o3[502] = 190.0F;
    vipldws_B.HoughTransform_o3[503] = 191.0F;
    vipldws_B.HoughTransform_o3[504] = 192.0F;
    vipldws_B.HoughTransform_o3[505] = 193.0F;
    vipldws_B.HoughTransform_o3[506] = 194.0F;
    vipldws_B.HoughTransform_o3[507] = 195.0F;
    vipldws_B.HoughTransform_o3[508] = 196.0F;
    vipldws_B.HoughTransform_o3[509] = 197.0F;
    vipldws_B.HoughTransform_o3[510] = 198.0F;
    vipldws_B.HoughTransform_o3[511] = 199.0F;
    vipldws_B.HoughTransform_o3[512] = 200.0F;
    vipldws_B.HoughTransform_o3[513] = 201.0F;
    vipldws_B.HoughTransform_o3[514] = 202.0F;
    vipldws_B.HoughTransform_o3[515] = 203.0F;
    vipldws_B.HoughTransform_o3[516] = 204.0F;
    vipldws_B.HoughTransform_o3[517] = 205.0F;
    vipldws_B.HoughTransform_o3[518] = 206.0F;
    vipldws_B.HoughTransform_o3[519] = 207.0F;
    vipldws_B.HoughTransform_o3[520] = 208.0F;
    vipldws_B.HoughTransform_o3[521] = 209.0F;
    vipldws_B.HoughTransform_o3[522] = 210.0F;
    vipldws_B.HoughTransform_o3[523] = 211.0F;
    vipldws_B.HoughTransform_o3[524] = 212.0F;
    vipldws_B.HoughTransform_o3[525] = 213.0F;
    vipldws_B.HoughTransform_o3[526] = 214.0F;
    vipldws_B.HoughTransform_o3[527] = 215.0F;
    vipldws_B.HoughTransform_o3[528] = 216.0F;
    vipldws_B.HoughTransform_o3[529] = 217.0F;
    vipldws_B.HoughTransform_o3[530] = 218.0F;
    vipldws_B.HoughTransform_o3[531] = 219.0F;
    vipldws_B.HoughTransform_o3[532] = 220.0F;
    vipldws_B.HoughTransform_o3[533] = 221.0F;
    vipldws_B.HoughTransform_o3[534] = 222.0F;
    vipldws_B.HoughTransform_o3[535] = 223.0F;
    vipldws_B.HoughTransform_o3[536] = 224.0F;
    vipldws_B.HoughTransform_o3[537] = 225.0F;
    vipldws_B.HoughTransform_o3[538] = 226.0F;
    vipldws_B.HoughTransform_o3[539] = 227.0F;
    vipldws_B.HoughTransform_o3[540] = 228.0F;
    vipldws_B.HoughTransform_o3[541] = 229.0F;
    vipldws_B.HoughTransform_o3[542] = 230.0F;
    vipldws_B.HoughTransform_o3[543] = 231.0F;
    vipldws_B.HoughTransform_o3[544] = 232.0F;
    vipldws_B.HoughTransform_o3[545] = 233.0F;
    vipldws_B.HoughTransform_o3[546] = 234.0F;
    vipldws_B.HoughTransform_o3[547] = 235.0F;
    vipldws_B.HoughTransform_o3[548] = 236.0F;
    vipldws_B.HoughTransform_o3[549] = 237.0F;
    vipldws_B.HoughTransform_o3[550] = 238.0F;
    vipldws_B.HoughTransform_o3[551] = 239.0F;
    vipldws_B.HoughTransform_o3[552] = 240.0F;
    vipldws_B.HoughTransform_o3[553] = 241.0F;
    vipldws_B.HoughTransform_o3[554] = 242.0F;
    vipldws_B.HoughTransform_o3[555] = 243.0F;
    vipldws_B.HoughTransform_o3[556] = 244.0F;
    vipldws_B.HoughTransform_o3[557] = 245.0F;
    vipldws_B.HoughTransform_o3[558] = 246.0F;
    vipldws_B.HoughTransform_o3[559] = 247.0F;
    vipldws_B.HoughTransform_o3[560] = 248.0F;
    vipldws_B.HoughTransform_o3[561] = 249.0F;
    vipldws_B.HoughTransform_o3[562] = 250.0F;
    vipldws_B.HoughTransform_o3[563] = 251.0F;
    vipldws_B.HoughTransform_o3[564] = 252.0F;
    vipldws_B.HoughTransform_o3[565] = 253.0F;
    vipldws_B.HoughTransform_o3[566] = 254.0F;
    vipldws_B.HoughTransform_o3[567] = 255.0F;
    vipldws_B.HoughTransform_o3[568] = 256.0F;
    vipldws_B.HoughTransform_o3[569] = 257.0F;
    vipldws_B.HoughTransform_o3[570] = 258.0F;
    vipldws_B.HoughTransform_o3[571] = 259.0F;
    vipldws_B.HoughTransform_o3[572] = 260.0F;
    vipldws_B.HoughTransform_o3[573] = 261.0F;
    vipldws_B.HoughTransform_o3[574] = 262.0F;
    vipldws_B.HoughTransform_o3[575] = 263.0F;
    vipldws_B.HoughTransform_o3[576] = 264.0F;
    vipldws_B.HoughTransform_o3[577] = 265.0F;
    vipldws_B.HoughTransform_o3[578] = 266.0F;
    vipldws_B.HoughTransform_o3[579] = 267.0F;
    vipldws_B.HoughTransform_o3[580] = 268.0F;
    vipldws_B.HoughTransform_o3[581] = 269.0F;
    vipldws_B.HoughTransform_o3[582] = 270.0F;
    vipldws_B.HoughTransform_o3[583] = 271.0F;
    vipldws_B.HoughTransform_o3[584] = 272.0F;
    vipldws_B.HoughTransform_o3[585] = 273.0F;
    vipldws_B.HoughTransform_o3[586] = 274.0F;
    vipldws_B.HoughTransform_o3[587] = 275.0F;
    vipldws_B.HoughTransform_o3[588] = 276.0F;
    vipldws_B.HoughTransform_o3[589] = 277.0F;
    vipldws_B.HoughTransform_o3[590] = 278.0F;
    vipldws_B.HoughTransform_o3[591] = 279.0F;
    vipldws_B.HoughTransform_o3[592] = 280.0F;
    vipldws_B.HoughTransform_o3[593] = 281.0F;
    vipldws_B.HoughTransform_o3[594] = 282.0F;
    vipldws_B.HoughTransform_o3[595] = 283.0F;
    vipldws_B.HoughTransform_o3[596] = 284.0F;
    vipldws_B.HoughTransform_o3[597] = 285.0F;
    vipldws_B.HoughTransform_o3[598] = 286.0F;
    vipldws_B.HoughTransform_o3[599] = 287.0F;
    vipldws_B.HoughTransform_o3[600] = 288.0F;
    vipldws_B.HoughTransform_o3[601] = 289.0F;
    vipldws_B.HoughTransform_o3[602] = 290.0F;
    vipldws_B.HoughTransform_o3[603] = 291.0F;
    vipldws_B.HoughTransform_o3[604] = 292.0F;
    vipldws_B.HoughTransform_o3[605] = 293.0F;
    vipldws_B.HoughTransform_o3[606] = 294.0F;
    vipldws_B.HoughTransform_o3[607] = 295.0F;
    vipldws_B.HoughTransform_o3[608] = 296.0F;
    vipldws_B.HoughTransform_o3[609] = 297.0F;
    vipldws_B.HoughTransform_o3[610] = 298.0F;
    vipldws_B.HoughTransform_o3[611] = 299.0F;
    vipldws_B.HoughTransform_o3[612] = 300.0F;
    vipldws_B.HoughTransform_o3[613] = 301.0F;
    vipldws_B.HoughTransform_o3[614] = 302.0F;
    vipldws_B.HoughTransform_o3[615] = 303.0F;
    vipldws_B.HoughTransform_o3[616] = 304.0F;
    vipldws_B.HoughTransform_o3[617] = 305.0F;
    vipldws_B.HoughTransform_o3[618] = 306.0F;
    vipldws_B.HoughTransform_o3[619] = 307.0F;
    vipldws_B.HoughTransform_o3[620] = 308.0F;
    vipldws_B.HoughTransform_o3[621] = 309.0F;
    vipldws_B.HoughTransform_o3[622] = 310.0F;
    vipldws_B.HoughTransform_o3[623] = 311.0F;
    vipldws_B.HoughTransform_o3[624] = 312.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&vipldws_DW, 0,
                sizeof(DW_vipldws_T));

  {
    int32_T i;
    for (i = 0; i < 40; i++) {
      vipldws_DW.FixPtUnitDelay1_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 80; i++) {
      vipldws_DW.UnitDelay2_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 320; i++) {
      vipldws_DW.UnitDelay3_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 230400; i++) {
      vipldws_DW.ColorSpaceConversion_DWORK1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 256; i++) {
      vipldws_DW.Imagethresholding_P_DW[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 256; i++) {
      vipldws_DW.Imagethresholding_MU_DW[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 231; i++) {
      vipldws_DW.FindLocalMaxima1_TEMP_IN_DWORKS[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 112500; i++) {
      vipldws_DW.FindLocalMaxima_TEMP_IN_DWORKS[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 756; i++) {
      vipldws_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 86400; i++) {
      vipldws_DW.ColorSpaceConversion1_DWORK1[i] = 0.0F;
    }
  }

  vipldws_DW.InsertText_colorVectorDW[0] = 0.0F;
  vipldws_DW.InsertText_colorVectorDW[1] = 0.0F;
  vipldws_DW.InsertText_colorVectorDW[2] = 0.0F;
  vipldws_DW.InsertTextLeftLane_colorVectorD[0] = 0.0F;
  vipldws_DW.InsertTextLeftLane_colorVectorD[1] = 0.0F;
  vipldws_DW.InsertTextLeftLane_colorVectorD[2] = 0.0F;
  vipldws_DW.InsertTextRightLane_colorVector[0] = 0.0F;
  vipldws_DW.InsertTextRightLane_colorVector[1] = 0.0F;
  vipldws_DW.InsertTextRightLane_colorVector[2] = 0.0F;
  vipldws_DW.DrawShapes_DW_FillColorAdd[0] = 0.0F;
  vipldws_DW.DrawShapes_DW_FillColorAdd[1] = 0.0F;
  vipldws_DW.DrawShapes_DW_FillColorAdd[2] = 0.0F;
  vipldws_DW.DrawShapes_DW_OneMOpacity = 0.0F;
  vipldws_DW.Add1_DWORK1 = 0.0F;
  vipldws_DW.LDLFactorization_VMX[0] = 0.0F;
  vipldws_DW.LDLFactorization_VMX[1] = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    vipldws_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    int32_T i;

    /* Start for S-Function (v4l2_video_capture_sfcn): '<S2>/V4L2 Video Capture' */
    MW_videoCaptureInit(vipldws_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U,
                        240U, 2U, 2U, 1U, 0.033333333333333333);

    /* Start for Probe: '<S1>/Width of the image' */
    vipldws_B.Widthoftheimage[0] = 200;
    vipldws_B.Widthoftheimage[1] = 240;

    /* Start for Enabled SubSystem: '<S5>/Subsystem' */
    /* Start for Enabled SubSystem: '<S65>/Draw  Polygon' */
    /* Start for S-Function (svipdrawshapes): '<S66>/DrawShapes' */
    /* Calculate FillColor times Opacity. */
    vipldws_DW.DrawShapes_DW_FillColorAdd[0] = vipldws_P.DrawShapes_color[0] *
      vipldws_P.DrawShapes_opacity;
    vipldws_DW.DrawShapes_DW_FillColorAdd[1] = vipldws_P.DrawShapes_color[1] *
      vipldws_P.DrawShapes_opacity;
    vipldws_DW.DrawShapes_DW_FillColorAdd[2] = vipldws_P.DrawShapes_color[2] *
      vipldws_P.DrawShapes_opacity;

    /* Calculate One minus Opacity. */
    vipldws_DW.DrawShapes_DW_OneMOpacity = 1.0F - vipldws_P.DrawShapes_opacity;

    /* End of Start for SubSystem: '<S65>/Draw  Polygon' */

    /* Start for FromWorkspace: '<S68>/From Workspace' */
    {
      static real32_T pDataValues0[] = { 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

      vipldws_DW.FromWorkspace_PWORK.TimePtr = (void *) 0;
      vipldws_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
      vipldws_DW.FromWorkspace_IWORK.PrevIndex = -1;
    }

    /* Start for S-Function (sviptextrender): '<S65>/Insert Text' */
    memcpy(&vipldws_DW.InsertText_StringDataDW[0],
           &vipldws_ConstP.InsertText_StrArray[0], 74U * sizeof(uint8_T));
    for (i = 0; i < 53; i++) {
      /* Start for S-Function (sviptextrender): '<S67>/Insert Text: Left Lane' */
      vipldws_DW.InsertTextLeftLane_StringDataDW[i] = vipldws_ConstP.pooled15[i];

      /* Start for S-Function (sviptextrender): '<S67>/Insert Text: Right Lane' */
      vipldws_DW.InsertTextRightLane_StringDataD[i] = vipldws_ConstP.pooled15[i];
    }

    /* End of Start for SubSystem: '<S5>/Subsystem' */
    /* Start for MATLABSystem: '<S64>/MATLAB System' */
    vipldws_DW.obj.isInitialized = 0;
    vipldws_DW.objisempty = true;
    vipldws_DW.obj.isInitialized = 1;
    vipldws_DW.obj.PixelFormatEnum = 1;
    MW_SDL_videoDisplayInit(vipldws_DW.obj.PixelFormatEnum, 1, 1, 320.0, 240.0);

    /* End of Start for SubSystem: '<S5>/SDL Video Display' */
    vipldws_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S36>/FixPt Unit Delay2' */
    vipldws_DW.FixPtUnitDelay2_DSTATE =
      vipldws_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S36>/FixPt Unit Delay1' */
    memcpy(&vipldws_DW.FixPtUnitDelay1_DSTATE[0],
           &vipldws_P.UnitDelayResettable1_vinit[0], 40U * sizeof(real32_T));

    /* InitializeConditions for UnitDelay: '<S35>/FixPt Unit Delay2' */
    vipldws_DW.FixPtUnitDelay2_DSTATE_b =
      vipldws_P.FixPtUnitDelay2_InitialCondit_p;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for UnitDelay: '<S35>/FixPt Unit Delay1' */
      vipldws_DW.FixPtUnitDelay1_DSTATE_d[i] =
        vipldws_P.UnitDelayResettable_vinit;

      /* InitializeConditions for UnitDelay: '<S32>/En_Delay' */
      vipldws_DW.En_Delay_DSTATE[i] = vipldws_P.En_Delay_InitialCondition;
    }

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay2' */
    memcpy(&vipldws_DW.UnitDelay2_DSTATE[0],
           &vipldws_P.UnitDelay2_InitialCondition[0], 80U * sizeof(real32_T));

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay3' */
    memcpy(&vipldws_DW.UnitDelay3_DSTATE[0],
           &vipldws_P.UnitDelay3_InitialCondition[0], 320U * sizeof(real32_T));

    /* InitializeConditions for Delay: '<S17>/Delay' */
    vipldws_DW.Delay_DSTATE = vipldws_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S17>/Delay1' */
    vipldws_DW.Delay1_DSTATE_e = vipldws_P.Delay1_InitialCondition_p;

    /* InitializeConditions for S-Function (sdspcount2): '<S17>/Counter' */
    vipldws_DW.Counter_Count = vipldws_P.Counter_InitialCount;

    /* InitializeConditions for S-Function (sdspnsamp2): '<S5>/N-Sample Enable' incorporates:
     *  Constant: '<S2>/Constant'
     */

    /* DSP System Toolbox N-Sample Enable  (sdspnsamp2) - '<S5>/N-Sample Enable' */
    vipldws_DW.NSampleEnable_Counter = (uint32_T) 0;

    /* SystemInitialize for Iterator SubSystem: '<S33>/Find the best  matches between the current  lines and those in the repository' */
    /* InitializeConditions for Delay: '<S51>/Delay1' */
    for (i = 0; i < 400; i++) {
      vipldws_DW.Delay1_DSTATE[i] = vipldws_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S51>/Delay1' */
    /* End of SystemInitialize for SubSystem: '<S33>/Find the best  matches between the current  lines and those in the repository' */

    /* SystemInitialize for Iterator SubSystem: '<S33>/Update the repository' */
    /* InitializeConditions for Delay: '<S52>/Delay1' */
    for (i = 0; i < 20; i++) {
      vipldws_DW.Delay1_DSTATE_g[i] = vipldws_P.Delay1_InitialCondition_n;
    }

    /* End of InitializeConditions for Delay: '<S52>/Delay1' */
    /* End of SystemInitialize for SubSystem: '<S33>/Update the repository' */

    /* SystemInitialize for Iterator SubSystem: '<S1>/Find the left and  right lanes from the depository' */
    /* InitializeConditions for UnitDelay: '<S24>/Min_left_dis' */
    vipldws_DW.Min_left_dis_DSTATE = vipldws_P.Min_left_dis_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_dis' */
    vipldws_DW.Min_right_dis_DSTATE = vipldws_P.Min_right_dis_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[0] = vipldws_P.Min_left_pts_InitialCondition
      [0];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[0] =
      vipldws_P.Min_right_pts_InitialCondition[0];

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[1] = vipldws_P.Min_left_pts_InitialCondition
      [1];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[1] =
      vipldws_P.Min_right_pts_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[2] = vipldws_P.Min_left_pts_InitialCondition
      [2];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[2] =
      vipldws_P.Min_right_pts_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws_DW.Min_left_pts_DSTATE[3] = vipldws_P.Min_left_pts_InitialCondition
      [3];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws_DW.Min_right_pts_DSTATE[3] =
      vipldws_P.Min_right_pts_InitialCondition[3];

    /* End of SystemInitialize for SubSystem: '<S1>/Find the left and  right lanes from the depository' */

    /* SystemInitialize for Triggered SubSystem: '<S6>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S15>/ ' */
    vipldws_B.In = vipldws_P._Y0;

    /* End of SystemInitialize for SubSystem: '<S6>/Sample and Hold' */
  }
}

/* Model terminate function */
void vipldws_terminate(void)
{
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<S2>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(vipldws_ConstP.V4L2VideoCapture_p1);

  /* Start for MATLABSystem: '<S64>/MATLAB System' incorporates:
   *  Terminate for MATLABSystem: '<S64>/MATLAB System'
   */
  if (vipldws_DW.obj.isInitialized == 1) {
    vipldws_DW.obj.isInitialized = 2;
    MW_SDL_videoDisplayTerminate(0, 0);
  }

  /* End of Start for MATLABSystem: '<S64>/MATLAB System' */
  /* End of Terminate for SubSystem: '<S5>/SDL Video Display' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
