/*
 * File: vipldws2.c
 *
 * Code generated for Simulink model 'vipldws2'.
 *
 * Model version                  : 1.2214
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jan 02 21:19:24 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "vipldws2.h"
#include "vipldws2_private.h"
#include "vipldws2_dt.h"

/* Block signals (auto storage) */
B_vipldws2_T vipldws2_B;

/* Block states (auto storage) */
DW_vipldws2_T vipldws2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_vipldws2_T vipldws2_PrevZCX;

/* Real-time model */
RT_MODEL_vipldws2_T vipldws2_M_;
RT_MODEL_vipldws2_T *const vipldws2_M = &vipldws2_M_;

/* Forward declaration for local functions */
static void vipldws2_Corr_M_IBRepl_uS_hS_yS(const real32_T h[], const int32_T
  hLoc[], const int32_T hDims[], const real32_T u[], const int32_T uDims[],
  real32_T y[], const int32_T yDims[], const int32_T yOrigin[]);
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

static void vipldws2_Corr_M_IBRepl_uS_hS_yS(const real32_T h[], const int32_T
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
  vipldws2_B.uOrigin[0U] = 0;
  vipldws2_B.uEnd[0U] = uDims[0U] - 1;
  vipldws2_B.uStride[0U] = 1;
  vipldws2_B.uOrigin[1U] = 0;
  vipldws2_B.uEnd[1U] = uDims[1U] - 1;
  vipldws2_B.uStride[1U] = uDims[0U];
  vipldws2_B.hEnd[0U] = hDims[0U] - 1;
  vipldws2_B.hEnd[1U] = hDims[1U] - 1;
  vipldws2_B.yEnd[0U] = yDims[0U] - 1;
  vipldws2_B.yEnd[1U] = yDims[1U] - 1;

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
  yPost = (yOrigin[0] + vipldws2_B.yEnd[0]) - vipldws2_B.uEnd[0];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPost = hLoc[0] + vipldws2_B.hEnd[0];

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

  yEnd = ((yOrigin[0] + vipldws2_B.yEnd[0]) - yPost) + 1;

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
  vipldws2_B.mLoc[0] = uOrigin + uEnd;
  vipldws2_B.mWidth[0] = (((yDims[0] - hLoc_0) - yPost) - uEnd) - hEnd;
  vipldws2_B.mLoc[2] = uOrigin;
  vipldws2_B.mWidth[2] = uEnd;
  vipldws2_B.mLoc[4] = hPost;
  vipldws2_B.mWidth[4] = hEnd;
  vipldws2_B.mLoc[6] = yOrigin[0];
  vipldws2_B.mWidth[6] = hLoc_0;
  vipldws2_B.mLoc[8] = yEnd;
  vipldws2_B.mWidth[8] = yPost;

  /* margins between y and u */
  uOrigin = -yOrigin[1];
  yPost = (yOrigin[1] + vipldws2_B.yEnd[1]) - vipldws2_B.uEnd[1];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPost = hLoc[1] + vipldws2_B.hEnd[1];

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

  yEnd = ((yOrigin[1] + vipldws2_B.yEnd[1]) - yPost) + 1;

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
  vipldws2_B.mLoc[1] = uOrigin + uEnd;
  vipldws2_B.mWidth[1] = (((yDims[1] - hLoc_0) - yPost) - uEnd) - hEnd;
  vipldws2_B.mLoc[3] = uOrigin;
  vipldws2_B.mWidth[3] = uEnd;
  vipldws2_B.mLoc[5] = hPost;
  vipldws2_B.mWidth[5] = hEnd;
  vipldws2_B.mLoc[7] = yOrigin[1];
  vipldws2_B.mWidth[7] = hLoc_0;
  vipldws2_B.mLoc[9] = yEnd;
  vipldws2_B.mWidth[9] = yPost;

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
  if (!((vipldws2_B.mWidth[0] <= 0) || (vipldws2_B.mWidth[1] <= 0))) {
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* setup indices for the loops */
    /* Origin stores the origin of Y with respect to U */
    /*  where the origin of Y is at its top left corner */
    /* Compute offset between origin of Y and origin of U(0,0) */
    vipldws2_B.offset_c[0U] = -yOrigin[0U];
    vipldws2_B.offset_c[1U] = -yOrigin[1U];

    /* sector start and end were computed relative to U */
    /* make them relative to Y by adding offset */
    vipldws2_B.sStart[0U] = vipldws2_B.mLoc[0] + vipldws2_B.offset_c[0U];
    vipldws2_B.sEnd[0U] = ((vipldws2_B.mLoc[0] + vipldws2_B.mWidth[0]) +
      vipldws2_B.offset_c[0U]) - 1;
    vipldws2_B.sStart[1U] = vipldws2_B.mLoc[1] + vipldws2_B.offset_c[1U];
    vipldws2_B.sEnd[1U] = ((vipldws2_B.mLoc[1] + vipldws2_B.mWidth[1]) +
      vipldws2_B.offset_c[1U]) - 1;

    /* adjust offset for kernel center */
    vipldws2_B.offset_c[0U] -= hLoc[0U];
    vipldws2_B.offset_c[1U] -= hLoc[1U];

    /* loop kernel over data */
    vipldws2_B.idxB_k[1U] = vipldws2_B.sStart[1U];
    while (vipldws2_B.idxB_k[1U] <= vipldws2_B.sEnd[1U]) {
      vipldws2_B.idxALin[1U] = (vipldws2_B.idxB_k[1U] - vipldws2_B.offset_c[1U])
        * uDims[0U];
      vipldws2_B.idxBLin_c[1U] = yDims[0U] * vipldws2_B.idxB_k[1U];
      vipldws2_B.idxB_k[0U] = vipldws2_B.sStart[0U];
      while (vipldws2_B.idxB_k[0U] <= vipldws2_B.sEnd[0U]) {
        vipldws2_B.idxALin[0U] = (vipldws2_B.idxB_k[0U] - vipldws2_B.offset_c[0U])
          + vipldws2_B.idxALin[1U];
        vipldws2_B.idxBLin_c[0U] = vipldws2_B.idxBLin_c[1U] + vipldws2_B.idxB_k
          [0U];
        uOrigin = vipldws2_B.idxALin[0U];

        /* loop over kernel and compute conv/corr */
        hPost = 0;
        acc = 0.0F;

        /* loop over kernel */
        vipldws2_B.hIdxA_b[1U] = 0;
        while (vipldws2_B.hIdxA_b[1U] <= vipldws2_B.hEnd[1U]) {
          vipldws2_B.hIdxA_b[0U] = 0;
          while (vipldws2_B.hIdxA_b[0U] <= vipldws2_B.hEnd[0U]) {
            acc += u[uOrigin] * h[hPost];
            uOrigin++;
            hPost++;
            vipldws2_B.hIdxA_b[0U]++;
          }

          uOrigin = (uOrigin + uDims[0U]) - hDims[0U];
          vipldws2_B.hIdxA_b[1U]++;
        }

        if (vipldws2_B.idxBLin_c[0U] >= 0) {
          y[vipldws2_B.idxBLin_c[0U]] = acc;
        }

        vipldws2_B.idxB_k[0U]++;
      }

      vipldws2_B.idxB_k[1U]++;
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
  vipldws2_B.o[0U] = 0;
  vipldws2_B.o[1U] = 1;
  vipldws2_B.o[2U] = 2;
  vipldws2_B.o[3U] = 3;
  vipldws2_B.o[4U] = 4;
  isEnd = false;
  vipldws2_B.c[1U] = 0;

  /* if hDims < uDims then the all INSIDE sector will not be pushed into the boundary sectors... hence the counter needs to skip the all INSIDEs sector and start from one sector down. */
  vipldws2_B.c[0U] = 1;
  while (!isEnd) {
    uOrigin = 0;
    yPost = 0;

    /* compute on-boundary sector */
    /* compute sector if not empty */
    if (!((vipldws2_B.mWidth[vipldws2_B.o[vipldws2_B.c[0U]] << 1] <= 0) ||
          (vipldws2_B.mWidth[(vipldws2_B.o[vipldws2_B.c[1U]] << 1) + 1] <= 0)))
    {
      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (vipldws2_B.o[vipldws2_B.c[0]] == 0);
      dimIsPre = ((vipldws2_B.o[vipldws2_B.c[0]] == 3) ||
                  (vipldws2_B.o[vipldws2_B.c[0]] == 1));
      if (dimIsPre || isSEmpty) {
        vipldws2_B.sPreEdges[0] = 0;
        uOrigin = 1;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        vipldws2_B.sPostEdges[0] = 0;
        yPost = 1;
      }

      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (vipldws2_B.o[vipldws2_B.c[1]] == 0);
      dimIsPre = ((vipldws2_B.o[vipldws2_B.c[1]] == 3) ||
                  (vipldws2_B.o[vipldws2_B.c[1]] == 1));
      if (dimIsPre || isSEmpty) {
        vipldws2_B.sPreEdges[uOrigin] = 1;
        uOrigin++;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        vipldws2_B.sPostEdges[yPost] = 1;
        yPost++;
      }

      /* setup indices for the loops */
      /* Origin stores the origin of Y with respect to U */
      /*  where the origin of Y is at its top left corner */
      /* Compute offset between origin of Y and origin of U(0,0) */
      vipldws2_B.offset[0U] = -yOrigin[0U];
      vipldws2_B.offset[1U] = -yOrigin[1U];

      /* sector start and end were computed relative to U */
      /* make them relative to Y by adding offset */
      vipldws2_B.sStart_p[0U] = vipldws2_B.mLoc[vipldws2_B.o[vipldws2_B.c[0]] <<
        1] + vipldws2_B.offset[0U];
      vipldws2_B.sEnd_c[0U] = ((vipldws2_B.mLoc[vipldws2_B.o[vipldws2_B.c[0]] <<
        1] + vipldws2_B.mWidth[vipldws2_B.o[vipldws2_B.c[0]] << 1]) +
        vipldws2_B.offset[0U]) - 1;
      vipldws2_B.sStart_p[1U] = vipldws2_B.mLoc[(vipldws2_B.o[vipldws2_B.c[1]] <<
        1) + 1] + vipldws2_B.offset[1U];
      vipldws2_B.sEnd_c[1U] = ((vipldws2_B.mLoc[(vipldws2_B.o[vipldws2_B.c[1]] <<
        1) + 1] + vipldws2_B.mWidth[(vipldws2_B.o[vipldws2_B.c[1]] << 1) + 1]) +
        vipldws2_B.offset[1U]) - 1;

      /* adjust offset for kernel center */
      vipldws2_B.offset[0U] -= hLoc[0U];
      vipldws2_B.offset[1U] -= hLoc[1U];

      /* loop kernel over data */
      vipldws2_B.idxB[1U] = vipldws2_B.sStart_p[1U];
      while (vipldws2_B.idxB[1U] <= vipldws2_B.sEnd_c[1U]) {
        vipldws2_B.idxA[1U] = vipldws2_B.idxB[1U] - vipldws2_B.offset[1U];
        vipldws2_B.idxBLin[1U] = yDims[0U] * vipldws2_B.idxB[1U];
        vipldws2_B.idxB[0U] = vipldws2_B.sStart_p[0U];
        while (vipldws2_B.idxB[0U] <= vipldws2_B.sEnd_c[0U]) {
          vipldws2_B.idxA[0U] = vipldws2_B.idxB[0U] - vipldws2_B.offset[0U];
          vipldws2_B.idxBLin[0U] = vipldws2_B.idxBLin[1U] + vipldws2_B.idxB[0U];

          /* loop over kernel and compute conv/corr */
          hPost = 0;
          acc = 0.0F;

          /* loop over kernel */
          vipldws2_B.hIdxA[1U] = 0;
          while (vipldws2_B.hIdxA[1U] <= vipldws2_B.hEnd[1U]) {
            vipldws2_B.hIdxB[1U] = vipldws2_B.idxA[1U] + vipldws2_B.hIdxA[1U];
            vipldws2_B.hIdxA[0U] = 0;
            while (vipldws2_B.hIdxA[0U] <= vipldws2_B.hEnd[0U]) {
              vipldws2_B.hIdxB[0U] = vipldws2_B.idxA[0U] + vipldws2_B.hIdxA[0U];
              uI = PadBRepl_uS(&u[0U], &vipldws2_B.uStride[0U],
                               &vipldws2_B.hIdxB[0U], &vipldws2_B.uOrigin[0U],
                               &vipldws2_B.uEnd[0U], uOrigin,
                               &vipldws2_B.sPreEdges[0U], yPost,
                               &vipldws2_B.sPostEdges[0U]);
              acc += uI * h[hPost];
              hPost++;
              vipldws2_B.hIdxA[0U]++;
            }

            vipldws2_B.hIdxA[1U]++;
          }

          if (vipldws2_B.idxBLin[0U] >= 0) {
            y[vipldws2_B.idxBLin[0U]] = acc;
          }

          vipldws2_B.idxB[0U]++;
        }

        vipldws2_B.idxB[1U]++;
      }
    }

    /* advance sector counter */
    uOrigin = 0;
    while (uOrigin < 2) {
      vipldws2_B.c[uOrigin]++;
      if (vipldws2_B.c[uOrigin] <= 2) {
        isEnd = false;
        uOrigin = 2;
      } else {
        vipldws2_B.c[uOrigin] = 0;
        isEnd = true;
      }

      uOrigin++;
    }
  }

  /* End of S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
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

  /* S-Function (sdspldl2): '<S49>/LDL Factorization' */
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

  /* End of S-Function (sdspldl2): '<S49>/LDL Factorization' */
}

/* Model step function */
void vipldws2_step(void)
{
  uint8_T tmp;
  boolean_T c_gotAlLeastOneYellowPixelInThe;
  boolean_T prevEdgeIsVertical;
  int8_T idxTmpArray[2];
  boolean_T countTwice;
  int8_T idxTmpArray_0[2];
  boolean_T done;
  static const int8_T tmp_0[4] = { 1, 0, 3, 2 };

  static const int8_T tmp_1[12] = { 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10 };

  int8_T lineColorIdx_idx_0;
  int8_T solidBrokenIdx_idx_0;
  int32_T exitg1;

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.SampleandHold_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Enablesignalgenerator_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Core_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Options_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Differencebetweentwolines_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Selectalinefromtherepositoryifi);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Draw3rdLine_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.DrawPolygon_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(vipldws2_DW.Subsystem_SubsysRanBC);

  /* S-Function (v4l2_video_capture_sfcn): '<S2>/V4L2 Video Capture' */
  MW_videoCaptureOutput(vipldws2_ConstP.V4L2VideoCapture_p1,
                        &vipldws2_B.MatrixConcatenate[0],
                        &vipldws2_B.MatrixConcatenate[76800],
                        &vipldws2_B.MatrixConcatenate[153600]);

  /* MATLAB Function: '<S2>/MATLAB Function' */
  /* MATLAB Function 'Input/MATLAB Function': '<S26>:1' */
  /* '<S26>:1:2' pause(t); */
  /* '<S26>:1:3' y = u; */
  memcpy(&vipldws2_B.y_b[0], &vipldws2_B.MatrixConcatenate[0], 230400U * sizeof
         (uint8_T));

  /* S-Function (sviprotate): '<S2>/Rotate' */
  vipldws2_B.indxI = 0;
  vipldws2_B.planeOffset = 239;
  for (vipldws2_B.plane = 0; vipldws2_B.plane < 3; vipldws2_B.plane++) {
    for (vipldws2_B.i = 0; vipldws2_B.i < 240; vipldws2_B.i++) {
      vipldws2_B.C2 = vipldws2_B.planeOffset - vipldws2_B.i;
      for (vipldws2_B.j = 0; vipldws2_B.j < 320; vipldws2_B.j++) {
        vipldws2_B.Rotate[vipldws2_B.C2] = vipldws2_B.y_b[vipldws2_B.indxI];
        vipldws2_B.indxI++;
        vipldws2_B.C2 += 240;
      }
    }

    vipldws2_B.planeOffset += 76800;
  }

  /* End of S-Function (sviprotate): '<S2>/Rotate' */

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  /* MATLAB Function 'Input/MATLAB Function1': '<S27>:1' */
  /* '<S27>:1:3' y = flip(u,2); */
  memcpy(&vipldws2_B.y_g[0], &vipldws2_B.Rotate[0], 230400U * sizeof(uint8_T));
  for (vipldws2_B.j = 0; vipldws2_B.j < 3; vipldws2_B.j++) {
    for (vipldws2_B.i = 0; vipldws2_B.i < 240; vipldws2_B.i++) {
      vipldws2_B.planeWidth = vipldws2_B.j * 76800 + vipldws2_B.i;
      for (vipldws2_B.indxI = 0; vipldws2_B.indxI < 160; vipldws2_B.indxI++) {
        tmp = vipldws2_B.y_g[vipldws2_B.indxI * 240 + vipldws2_B.planeWidth];
        vipldws2_B.y_g[vipldws2_B.planeWidth + vipldws2_B.indxI * 240] =
          vipldws2_B.y_g[(319 - vipldws2_B.indxI) * 240 + vipldws2_B.planeWidth];
        vipldws2_B.y_g[vipldws2_B.planeWidth + (319 - vipldws2_B.indxI) * 240] =
          tmp;
      }
    }
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function1' */

  /* S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 230400; vipldws2_B.i++) {
    vipldws2_B.ImageDataTypeConversion[vipldws2_B.i] = (real32_T)
      vipldws2_B.y_g[vipldws2_B.i] / 255.0F;
  }

  /* End of S-Function (svipscalenconvert): '<S2>/Image Data Type Conversion' */

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 76800; vipldws2_B.i++) {
    vipldws2_B.ColorSpaceConversion[vipldws2_B.i] =
      (vipldws2_B.ImageDataTypeConversion[76800 + vipldws2_B.i] * 0.587F +
       vipldws2_B.ImageDataTypeConversion[vipldws2_B.i] * 0.299F) +
      vipldws2_B.ImageDataTypeConversion[153600 + vipldws2_B.i] * 0.114F;
    if (vipldws2_B.ColorSpaceConversion[vipldws2_B.i] > 1.0F) {
      vipldws2_B.ColorSpaceConversion[vipldws2_B.i] = 1.0F;
    } else {
      if (vipldws2_B.ColorSpaceConversion[vipldws2_B.i] < 0.0F) {
        vipldws2_B.ColorSpaceConversion[vipldws2_B.i] = 0.0F;
      }
    }
  }

  /* End of S-Function (svipcolorconv): '<S2>/Color Space  Conversion' */

  /* S-Function (sdspsubmtrx): '<S2>/Clip image' */
  vipldws2_B.indxI = 0;
  for (vipldws2_B.i = 0; vipldws2_B.i < 320; vipldws2_B.i++) {
    memcpy(&vipldws2_B.Clipimage[vipldws2_B.indxI],
           &vipldws2_B.ColorSpaceConversion[vipldws2_B.i * 240 + 120], 120U *
           sizeof(real32_T));
    vipldws2_B.indxI += 120;
  }

  /* End of S-Function (sdspsubmtrx): '<S2>/Clip image' */

  /* S-Function (svip2dfirfilter): '<S3>/2-D FIR Filter' */
  /* Dimensions of the filter */
  vipldws2_B.h1Dims[0U] = 1;
  vipldws2_B.h1Dims[1U] = 3;
  vipldws2_B.uDims[0U] = 120;
  vipldws2_B.uDims[1U] = 320;

  /* set up kernel related coordinates */
  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  vipldws2_B.hLoc[0U] = 0;

  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  vipldws2_B.hLoc[1U] = -1;

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
  vipldws2_B.yOrigin[0U] = 0;
  vipldws2_B.yDims[0U] = 120;

  /* y sizes are same as ros sizes because there is no ROI */
  vipldws2_B.yOrigin[1U] = 0;
  vipldws2_B.yDims[1U] = 320;

  /* make yOrigin same as roiLoc when y is empty */
  /* end y sizes computation */
  /* /////////////////////// */
  vipldws2_Corr_M_IBRepl_uS_hS_yS(&vipldws2_P.uDFIRFilter_filterMtrx[0U],
    &vipldws2_B.hLoc[0U], &vipldws2_B.h1Dims[0U], &vipldws2_B.Clipimage[0U],
    &vipldws2_B.uDims[0U], &vipldws2_B.uDFIRFilter[0U], &vipldws2_B.yDims[0U],
    &vipldws2_B.yOrigin[0U]);

  /* Saturate: '<S3>/Saturation' */
  /* check if any input is empty
   */
  for (vipldws2_B.i = 0; vipldws2_B.i < 38400; vipldws2_B.i++) {
    if (vipldws2_B.uDFIRFilter[vipldws2_B.i] > vipldws2_P.Saturation_UpperSat) {
      vipldws2_B.Saturation[vipldws2_B.i] = vipldws2_P.Saturation_UpperSat;
    } else if (vipldws2_B.uDFIRFilter[vipldws2_B.i] <
               vipldws2_P.Saturation_LowerSat) {
      vipldws2_B.Saturation[vipldws2_B.i] = vipldws2_P.Saturation_LowerSat;
    } else {
      vipldws2_B.Saturation[vipldws2_B.i] = vipldws2_B.uDFIRFilter[vipldws2_B.i];
    }
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* S-Function (svipgraythresh): '<S3>/Image thresholding' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 256; vipldws2_B.i++) {
    vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i] = 0.0F;
    vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i] = 0.0F;
  }

  vipldws2_B.scale = 255.0F;
  for (vipldws2_B.i = 0; vipldws2_B.i < 38400; vipldws2_B.i++) {
    if (vipldws2_B.Saturation[vipldws2_B.i] < 0.0F) {
      vipldws2_DW.Imagethresholding_P_DW[0]++;
    } else if (vipldws2_B.Saturation[vipldws2_B.i] > 1.0F) {
      vipldws2_DW.Imagethresholding_P_DW[255]++;
    } else {
      vipldws2_DW.Imagethresholding_P_DW[(uint8_T)
        (vipldws2_B.Saturation[vipldws2_B.i] * vipldws2_B.scale + 0.5F)]++;
    }
  }

  for (vipldws2_B.i = 0; vipldws2_B.i < 256; vipldws2_B.i++) {
    vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i] /= 38400.0F;
  }

  vipldws2_DW.Imagethresholding_MU_DW[0] = vipldws2_DW.Imagethresholding_P_DW[0];
  vipldws2_B.cnt = 2.0F;
  for (vipldws2_B.i = 0; vipldws2_B.i < 255; vipldws2_B.i++) {
    vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i + 1] =
      vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i + 1] * vipldws2_B.cnt +
      vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i];
    vipldws2_B.cnt++;
    vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i + 1] +=
      vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i];
  }

  vipldws2_B.cnt = vipldws2_DW.Imagethresholding_MU_DW[255];
  for (vipldws2_B.i = 0; vipldws2_B.i < 256; vipldws2_B.i++) {
    vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i] =
      vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i] * vipldws2_B.cnt -
      vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i];
    vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i] *=
      vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i];
    vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i] *= 1.0F -
      vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i];
    vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i] =
      vipldws2_DW.Imagethresholding_MU_DW[vipldws2_B.i] /
      vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i];
  }

  vipldws2_B.indxI = 0;
  vipldws2_B.cnt = 0.0F;
  for (vipldws2_B.i = 0; vipldws2_B.i < 256; vipldws2_B.i++) {
    if (vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i] > vipldws2_B.cnt) {
      vipldws2_B.cnt = vipldws2_DW.Imagethresholding_P_DW[vipldws2_B.i];
      vipldws2_B.indxI = vipldws2_B.i;
    }
  }

  vipldws2_B.scale = (real32_T)vipldws2_B.indxI / vipldws2_B.scale;
  for (vipldws2_B.i = 0; vipldws2_B.i < 38400; vipldws2_B.i++) {
    vipldws2_B.Imagethresholding[vipldws2_B.i] =
      (vipldws2_B.Saturation[vipldws2_B.i] > vipldws2_B.scale);
  }

  /* End of S-Function (svipgraythresh): '<S3>/Image thresholding' */

  /* S-Function (sviphough): '<S3>/Hough Transform' */
  MWVIP_Hough_R(&vipldws2_B.Imagethresholding[0], &vipldws2_B.HoughTransform_o1
                [0], &vipldws2_ConstP.HoughTransform_SINE_TABLE_RTP[0],
                &vipldws2_ConstP.HoughTransform_FIRSTRHO_RTP, 120, 320, 683, 91);

  /* Selector: '<S33>/select rho5' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 21; vipldws2_B.i++) {
    for (vipldws2_B.plane = 0; vipldws2_B.plane < 11; vipldws2_B.plane++) {
      vipldws2_B.selectrho5[vipldws2_B.plane + 11 * vipldws2_B.i] =
        vipldws2_B.HoughTransform_o1[(683 * vipldws2_B.i + vipldws2_B.plane) +
        414];
    }
  }

  /* End of Selector: '<S33>/select rho5' */

  /* S-Function (svipfindlocalmax): '<S33>/Find Local Maxima1' */
  vipldws2_B.planeWidth = 0;
  done = false;
  vipldws2_B.i = 0;
  while (vipldws2_B.i < 231) {
    vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.i] =
      vipldws2_B.selectrho5[vipldws2_B.i];
    vipldws2_B.i++;
  }

  vipldws2_B.FindLocalMaxima1_o1[0] = 0U;
  vipldws2_B.FindLocalMaxima1_o1[1] = 0U;
  while (!done) {
    vipldws2_B.planeOffset = 0;
    vipldws2_B.scale = vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[0];
    vipldws2_B.i = 0;
    while (vipldws2_B.i < 231) {
      if (vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.i] >
          vipldws2_B.scale) {
        vipldws2_B.planeOffset = vipldws2_B.i;
        vipldws2_B.scale =
          vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.i];
      }

      vipldws2_B.i++;
    }

    vipldws2_B.plane = vipldws2_B.planeOffset % 11;
    vipldws2_B.i = vipldws2_B.planeOffset / 11;
    if (vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.planeOffset] >=
        vipldws2_P.FindLocalMaxima1_threshold) {
      vipldws2_B.FindLocalMaxima1_o1[vipldws2_B.planeWidth] = (uint16_T)(1 +
        vipldws2_B.i);
      vipldws2_B.FindLocalMaxima1_o1[1U + vipldws2_B.planeWidth] = (uint16_T)(1
        + vipldws2_B.plane);
      vipldws2_B.planeWidth++;
      if (vipldws2_B.planeWidth == 1) {
        done = true;
      }

      vipldws2_B.planeOffset = vipldws2_B.plane - 3;
      if (!(vipldws2_B.planeOffset > 0)) {
        vipldws2_B.planeOffset = 0;
      }

      vipldws2_B.plane += 3;
      if (!(vipldws2_B.plane < 10)) {
        vipldws2_B.plane = 10;
      }

      vipldws2_B.C2 = vipldws2_B.i - 3;
      vipldws2_B.c2 = vipldws2_B.i + 3;
      if (!((vipldws2_B.C2 < 0) || (vipldws2_B.c2 > 20))) {
        while (vipldws2_B.C2 <= vipldws2_B.c2) {
          vipldws2_B.c1 = vipldws2_B.C2 * 11;
          vipldws2_B.i = vipldws2_B.planeOffset;
          while (vipldws2_B.i <= vipldws2_B.plane) {
            vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.i +
              vipldws2_B.c1] = 0.0F;
            vipldws2_B.i++;
          }

          vipldws2_B.C2++;
        }
      } else {
        if (vipldws2_B.C2 < 0) {
          vipldws2_B.j = vipldws2_B.C2;
          while (vipldws2_B.j <= vipldws2_B.c2) {
            if (vipldws2_B.j < 0) {
              vipldws2_B.c1 = (vipldws2_B.j + 21) * 11 + 10;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.c1 -
                  vipldws2_B.i] = 0.0F;
                vipldws2_B.i++;
              }
            } else {
              vipldws2_B.c1 = vipldws2_B.j * 11;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.i +
                  vipldws2_B.c1] = 0.0F;
                vipldws2_B.i++;
              }
            }

            vipldws2_B.j++;
          }
        }

        if (vipldws2_B.c2 > 20) {
          vipldws2_B.j = vipldws2_B.C2;
          while (vipldws2_B.j <= vipldws2_B.c2) {
            if (vipldws2_B.j > 20) {
              vipldws2_B.c1 = (vipldws2_B.j - 21) * 11 + 10;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.c1 -
                  vipldws2_B.i] = 0.0F;
                vipldws2_B.i++;
              }
            } else {
              vipldws2_B.c1 = vipldws2_B.j * 11;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[vipldws2_B.i +
                  vipldws2_B.c1] = 0.0F;
                vipldws2_B.i++;
              }
            }

            vipldws2_B.j++;
          }
        }
      }
    } else {
      done = true;
    }
  }

  vipldws2_B.FindLocalMaxima1_o2 = (uint16_T)vipldws2_B.planeWidth;

  /* End of S-Function (svipfindlocalmax): '<S33>/Find Local Maxima1' */

  /* UnitDelay: '<S39>/FixPt Unit Delay2' */
  vipldws2_B.FixPtLogicalOperator = vipldws2_DW.FixPtUnitDelay2_DSTATE;

  /* Logic: '<S39>/FixPt Logical Operator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  vipldws2_B.FixPtUnitDelay2 = (uint8_T)(vipldws2_P.Constant_Value_g ||
    (vipldws2_B.FixPtLogicalOperator != 0));
  for (vipldws2_B.i = 0; vipldws2_B.i < 40; vipldws2_B.i++) {
    /* UnitDelay: '<S39>/FixPt Unit Delay1' */
    vipldws2_B.Xold[vipldws2_B.i] =
      vipldws2_DW.FixPtUnitDelay1_DSTATE[vipldws2_B.i];

    /* Switch: '<S39>/Init' incorporates:
     *  Constant: '<S39>/Initial Condition'
     */
    if (vipldws2_B.FixPtUnitDelay2 != 0) {
      vipldws2_B.Init[vipldws2_B.i] =
        vipldws2_P.UnitDelayResettable1_vinit[vipldws2_B.i];
    } else {
      vipldws2_B.Init[vipldws2_B.i] = vipldws2_B.Xold[vipldws2_B.i];
    }

    /* End of Switch: '<S39>/Init' */
  }

  /* UnitDelay: '<S38>/FixPt Unit Delay2' */
  vipldws2_B.FixPtUnitDelay2 = vipldws2_DW.FixPtUnitDelay2_DSTATE_b;

  /* Logic: '<S38>/FixPt Logical Operator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  vipldws2_B.FixPtLogicalOperator = (uint8_T)(vipldws2_P.Constant_Value_g ||
    (vipldws2_B.FixPtUnitDelay2 != 0));
  for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
    /* UnitDelay: '<S38>/FixPt Unit Delay1' */
    vipldws2_B.Xold_g[vipldws2_B.i] =
      vipldws2_DW.FixPtUnitDelay1_DSTATE_d[vipldws2_B.i];

    /* Switch: '<S38>/Init' incorporates:
     *  Constant: '<S38>/Initial Condition'
     */
    if (vipldws2_B.FixPtLogicalOperator != 0) {
      vipldws2_B.Init_p[vipldws2_B.i] = vipldws2_P.UnitDelayResettable_vinit;
    } else {
      vipldws2_B.Init_p[vipldws2_B.i] = vipldws2_B.Xold_g[vipldws2_B.i];
    }

    /* End of Switch: '<S38>/Init' */
  }

  /* S-Function (sdspoverwrite): '<S30>/Overwrite Values' */
  memcpy(&vipldws2_B.OverwriteValues[0], &vipldws2_B.HoughTransform_o1[0],
         122940U * sizeof(real32_T));
  for (vipldws2_B.i = 0; vipldws2_B.i < 12; vipldws2_B.i++) {
    for (vipldws2_B.planeWidth = 0; vipldws2_B.planeWidth < 683;
         vipldws2_B.planeWidth++) {
      vipldws2_B.OverwriteValues[vipldws2_B.planeWidth + vipldws2_B.i * 683] =
        0.0F;
    }
  }

  /* End of S-Function (sdspoverwrite): '<S30>/Overwrite Values' */

  /* S-Function (sdspoverwrite): '<S30>/Overwrite Values1' */
  memcpy(&vipldws2_B.OverwriteValues1[0], &vipldws2_B.OverwriteValues[0],
         122940U * sizeof(real32_T));
  for (vipldws2_B.i = 0; vipldws2_B.i < 13; vipldws2_B.i++) {
    for (vipldws2_B.planeWidth = 0; vipldws2_B.planeWidth < 683;
         vipldws2_B.planeWidth++) {
      vipldws2_B.OverwriteValues1[vipldws2_B.planeWidth + (vipldws2_B.i + 167) *
        683] = 0.0F;
    }
  }

  /* End of S-Function (sdspoverwrite): '<S30>/Overwrite Values1' */

  /* S-Function (svipfindlocalmax): '<S31>/Find Local Maxima' */
  vipldws2_B.planeWidth = 0;
  done = false;
  vipldws2_B.i = 0;
  while (vipldws2_B.i < 122940) {
    vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.i] =
      vipldws2_B.OverwriteValues1[vipldws2_B.i];
    vipldws2_B.i++;
  }

  vipldws2_B.FindLocalMaxima[0] = 0U;
  vipldws2_B.FindLocalMaxima[1] = 0U;
  vipldws2_B.FindLocalMaxima[2] = 0U;
  vipldws2_B.FindLocalMaxima[3] = 0U;
  while (!done) {
    vipldws2_B.planeOffset = 0;
    vipldws2_B.scale = vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[0];
    vipldws2_B.i = 0;
    while (vipldws2_B.i < 122940) {
      if (vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.i] >
          vipldws2_B.scale) {
        vipldws2_B.planeOffset = vipldws2_B.i;
        vipldws2_B.scale =
          vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.i];
      }

      vipldws2_B.i++;
    }

    vipldws2_B.plane = vipldws2_B.planeOffset % 683;
    vipldws2_B.i = vipldws2_B.planeOffset / 683;
    if (vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.planeOffset] >=
        vipldws2_P.FindLocalMaxima_threshold) {
      vipldws2_B.FindLocalMaxima[vipldws2_B.planeWidth] = (uint16_T)(1 +
        vipldws2_B.i);
      vipldws2_B.FindLocalMaxima[2U + vipldws2_B.planeWidth] = (uint16_T)(1 +
        vipldws2_B.plane);
      vipldws2_B.planeWidth++;
      if (vipldws2_B.planeWidth == 2) {
        done = true;
      }

      vipldws2_B.planeOffset = vipldws2_B.plane - 150;
      if (!(vipldws2_B.planeOffset > 0)) {
        vipldws2_B.planeOffset = 0;
      }

      vipldws2_B.plane += 150;
      if (!(vipldws2_B.plane < 682)) {
        vipldws2_B.plane = 682;
      }

      vipldws2_B.C2 = vipldws2_B.i - 40;
      vipldws2_B.c2 = vipldws2_B.i + 40;
      if (!((vipldws2_B.C2 < 0) || (vipldws2_B.c2 > 179))) {
        while (vipldws2_B.C2 <= vipldws2_B.c2) {
          vipldws2_B.c1 = vipldws2_B.C2 * 683;
          vipldws2_B.i = vipldws2_B.planeOffset;
          while (vipldws2_B.i <= vipldws2_B.plane) {
            vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.i +
              vipldws2_B.c1] = 0.0F;
            vipldws2_B.i++;
          }

          vipldws2_B.C2++;
        }
      } else {
        if (vipldws2_B.C2 < 0) {
          vipldws2_B.j = vipldws2_B.C2;
          while (vipldws2_B.j <= vipldws2_B.c2) {
            if (vipldws2_B.j < 0) {
              vipldws2_B.c1 = (vipldws2_B.j + 180) * 683 + 682;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.c1 -
                  vipldws2_B.i] = 0.0F;
                vipldws2_B.i++;
              }
            } else {
              vipldws2_B.c1 = vipldws2_B.j * 683;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.i +
                  vipldws2_B.c1] = 0.0F;
                vipldws2_B.i++;
              }
            }

            vipldws2_B.j++;
          }
        }

        if (vipldws2_B.c2 > 179) {
          vipldws2_B.j = vipldws2_B.C2;
          while (vipldws2_B.j <= vipldws2_B.c2) {
            if (vipldws2_B.j > 179) {
              vipldws2_B.c1 = (vipldws2_B.j - 180) * 683 + 682;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.c1 -
                  vipldws2_B.i] = 0.0F;
                vipldws2_B.i++;
              }
            } else {
              vipldws2_B.c1 = vipldws2_B.j * 683;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[vipldws2_B.i +
                  vipldws2_B.c1] = 0.0F;
                vipldws2_B.i++;
              }
            }

            vipldws2_B.j++;
          }
        }
      }
    } else {
      done = true;
    }
  }

  vipldws2_DW.FindLocalMaxima_NUMPEAKS_DWORK = (uint32_T)vipldws2_B.planeWidth;
  vipldws2_B.fromIdx = 2U;
  vipldws2_B.toIdx = (uint32_T)vipldws2_B.planeWidth;
  vipldws2_B.i = 0;
  while (vipldws2_B.i < vipldws2_B.planeWidth) {
    vipldws2_B.FindLocalMaxima[vipldws2_B.toIdx] =
      vipldws2_B.FindLocalMaxima[vipldws2_B.fromIdx];
    vipldws2_B.fromIdx++;
    vipldws2_B.toIdx++;
    vipldws2_B.i++;
  }

  vipldws2_DW.FindLocalMaxima_DIMS1[0] = (int32_T)
    vipldws2_DW.FindLocalMaxima_NUMPEAKS_DWORK;
  vipldws2_DW.FindLocalMaxima_DIMS1[1] = 2;

  /* End of S-Function (svipfindlocalmax): '<S31>/Find Local Maxima' */

  /* Selector: '<S31>/Selector1' */
  vipldws2_DW.Selector1_DIMS1[0] = vipldws2_DW.FindLocalMaxima_DIMS1[0];
  vipldws2_DW.Selector1_DIMS1[1] = 2;
  vipldws2_B.planeOffset = vipldws2_DW.FindLocalMaxima_DIMS1[0];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.Selector1_m[vipldws2_B.i] =
      vipldws2_B.FindLocalMaxima[vipldws2_B.i +
      vipldws2_DW.FindLocalMaxima_DIMS1[0]];
  }

  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.Selector1_m[vipldws2_B.i + vipldws2_DW.Selector1_DIMS1[0]] =
      vipldws2_B.FindLocalMaxima[vipldws2_B.i];
  }

  /* End of Selector: '<S31>/Selector1' */

  /* Math: '<S31>/Transpose' */
  vipldws2_DW.Transpose_DIMS1[0] = vipldws2_DW.Selector1_DIMS1[1];
  vipldws2_DW.Transpose_DIMS1[1] = vipldws2_DW.Selector1_DIMS1[0];
  vipldws2_B.planeOffset = vipldws2_DW.Selector1_DIMS1[0];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.planeWidth = vipldws2_DW.Selector1_DIMS1[1];
    for (vipldws2_B.plane = 0; vipldws2_B.plane < vipldws2_B.planeWidth;
         vipldws2_B.plane++) {
      vipldws2_B.Transpose_m[vipldws2_B.plane + vipldws2_DW.Transpose_DIMS1[0] *
        vipldws2_B.i] = vipldws2_B.Selector1_m[vipldws2_DW.Selector1_DIMS1[0] *
        vipldws2_B.plane + vipldws2_B.i];
    }
  }

  /* End of Math: '<S31>/Transpose' */

  /* Selector: '<S31>/select rho' */
  vipldws2_DW.selectrho_DIMS1[0] = 1;
  vipldws2_DW.selectrho_DIMS1[1] = vipldws2_DW.Transpose_DIMS1[1];
  vipldws2_B.planeOffset = vipldws2_DW.Transpose_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.selectrho3[vipldws2_DW.selectrho_DIMS1[0] * vipldws2_B.i] =
      vipldws2_B.Transpose_m[vipldws2_DW.Transpose_DIMS1[0] * vipldws2_B.i];
  }

  /* End of Selector: '<S31>/select rho' */

  /* Selector: '<S31>/Selector rho' */
  vipldws2_DW.Selectorrho_DIMS1[0] = 1;
  vipldws2_DW.Selectorrho_DIMS1[1] = vipldws2_DW.selectrho_DIMS1[0] *
    vipldws2_DW.selectrho_DIMS1[1];
  vipldws2_B.planeOffset = vipldws2_DW.selectrho_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.planeWidth = vipldws2_DW.selectrho_DIMS1[0];
    for (vipldws2_B.plane = 0; vipldws2_B.plane < vipldws2_B.planeWidth;
         vipldws2_B.plane++) {
      vipldws2_B.h1Dims[vipldws2_B.plane + vipldws2_DW.selectrho_DIMS1[0] *
        vipldws2_B.i] = vipldws2_B.selectrho3[vipldws2_DW.selectrho_DIMS1[0] *
        vipldws2_B.i + vipldws2_B.plane] - 1;
    }
  }

  vipldws2_B.planeOffset = vipldws2_DW.selectrho_DIMS1[0] *
    vipldws2_DW.selectrho_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.Selectorrho[vipldws2_DW.Selectorrho_DIMS1[0] * vipldws2_B.i] =
      vipldws2_B.HoughTransform_o3[vipldws2_B.h1Dims[vipldws2_B.i]];
  }

  /* End of Selector: '<S31>/Selector rho' */

  /* Selector: '<S31>/select rho3' */
  vipldws2_DW.selectrho3_DIMS1[0] = 1;
  vipldws2_DW.selectrho3_DIMS1[1] = vipldws2_DW.Transpose_DIMS1[1];
  vipldws2_B.planeOffset = vipldws2_DW.Transpose_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.selectrho3[vipldws2_DW.selectrho3_DIMS1[0] * vipldws2_B.i] =
      vipldws2_B.Transpose_m[vipldws2_DW.Transpose_DIMS1[0] * vipldws2_B.i + 1];
  }

  /* End of Selector: '<S31>/select rho3' */

  /* Selector: '<S31>/Selector theta' */
  vipldws2_DW.Selectortheta_DIMS1[0] = 1;
  vipldws2_DW.Selectortheta_DIMS1[1] = vipldws2_DW.selectrho3_DIMS1[0] *
    vipldws2_DW.selectrho3_DIMS1[1];
  vipldws2_B.planeOffset = vipldws2_DW.selectrho3_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.planeWidth = vipldws2_DW.selectrho3_DIMS1[0];
    for (vipldws2_B.plane = 0; vipldws2_B.plane < vipldws2_B.planeWidth;
         vipldws2_B.plane++) {
      vipldws2_B.h1Dims[vipldws2_B.plane + vipldws2_DW.selectrho3_DIMS1[0] *
        vipldws2_B.i] = vipldws2_B.selectrho3[vipldws2_DW.selectrho3_DIMS1[0] *
        vipldws2_B.i + vipldws2_B.plane] - 1;
    }
  }

  vipldws2_B.planeOffset = vipldws2_DW.selectrho3_DIMS1[0] *
    vipldws2_DW.selectrho3_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.Selectortheta[vipldws2_DW.Selectortheta_DIMS1[0] * vipldws2_B.i] =
      vipldws2_B.HoughTransform_o2[vipldws2_B.h1Dims[vipldws2_B.i]];
  }

  /* End of Selector: '<S31>/Selector theta' */

  /* Concatenate: '<S31>/Matrix Concatenation3' */
  vipldws2_DW.MatrixConcatenation3_DIMS1[0] = vipldws2_DW.Selectorrho_DIMS1[0] +
    vipldws2_DW.Selectortheta_DIMS1[0];
  vipldws2_DW.MatrixConcatenation3_DIMS1[1] = vipldws2_DW.Selectorrho_DIMS1[1];
  vipldws2_B.planeOffset = vipldws2_DW.Selectorrho_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.planeWidth = vipldws2_DW.Selectorrho_DIMS1[0];
    for (vipldws2_B.plane = 0; vipldws2_B.plane < vipldws2_B.planeWidth;
         vipldws2_B.plane++) {
      vipldws2_B.MatrixConcatenation3[vipldws2_B.plane +
        vipldws2_DW.MatrixConcatenation3_DIMS1[0] * vipldws2_B.i] =
        vipldws2_B.Selectorrho[vipldws2_DW.Selectorrho_DIMS1[0] * vipldws2_B.i +
        vipldws2_B.plane];
    }
  }

  vipldws2_B.planeOffset = vipldws2_DW.Selectortheta_DIMS1[1];
  for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
  {
    vipldws2_B.planeWidth = vipldws2_DW.Selectortheta_DIMS1[0];
    for (vipldws2_B.plane = 0; vipldws2_B.plane < vipldws2_B.planeWidth;
         vipldws2_B.plane++) {
      vipldws2_B.MatrixConcatenation3[(vipldws2_B.plane +
        vipldws2_DW.Selectorrho_DIMS1[0]) +
        vipldws2_DW.MatrixConcatenation3_DIMS1[0] * vipldws2_B.i] =
        vipldws2_B.Selectortheta[vipldws2_DW.Selectortheta_DIMS1[0] *
        vipldws2_B.i + vipldws2_B.plane];
    }
  }

  /* End of Concatenate: '<S31>/Matrix Concatenation3' */

  /* Probe: '<S31>/Probe' */
  vipldws2_B.Probe[0] = vipldws2_DW.Transpose_DIMS1[0];
  vipldws2_B.Probe[1] = vipldws2_DW.Transpose_DIMS1[1];

  /* Selector: '<S31>/Selector' */
  vipldws2_B.Selector = vipldws2_B.Probe[1];

  /* Outputs for Iterator SubSystem: '<S31>/Enable signal generator' incorporates:
   *  ForIterator: '<S34>/For Iterator'
   */
  vipldws2_B.indxI = 1;
  do {
    exitg1 = 0;
    if (vipldws2_B.Selector < 0.0) {
      vipldws2_B.d0 = ceil(vipldws2_B.Selector);
    } else {
      vipldws2_B.d0 = floor(vipldws2_B.Selector);
    }

    if (rtIsNaN(vipldws2_B.d0) || rtIsInf(vipldws2_B.d0)) {
      vipldws2_B.d0 = 0.0;
    } else {
      vipldws2_B.d0 = fmod(vipldws2_B.d0, 4.294967296E+9);
    }

    if (vipldws2_B.indxI <= (vipldws2_B.d0 < 0.0 ? -(int32_T)(uint32_T)
         -vipldws2_B.d0 : (int32_T)(uint32_T)vipldws2_B.d0)) {
      vipldws2_B.ForIterator_e = vipldws2_B.indxI;
      if (vipldws2_B.indxI == 1) {
        vipldws2_B.Assignment_d[0] = vipldws2_P.Constant_Value_b[0];
        vipldws2_B.Assignment_d[1] = vipldws2_P.Constant_Value_b[1];
      }

      vipldws2_B.Assignment_d[vipldws2_B.ForIterator_e - 1] =
        vipldws2_P.Constant1_Value_d0;
      srUpdateBC(vipldws2_DW.Enablesignalgenerator_SubsysRan);
      vipldws2_B.indxI++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* End of Outputs for SubSystem: '<S31>/Enable signal generator' */

  /* Outputs for Iterator SubSystem: '<S36>/Calculate the distances between  the lines found in the current  frame and those in the repository' incorporates:
   *  ForIterator: '<S53>/For Iterator'
   */
  vipldws2_DW.ForIterator_IterationMarker = 1U;
  vipldws2_B.indxI = 1;
  while (vipldws2_B.indxI <= vipldws2_P.ForIterator_IterationLimit_j) {
    vipldws2_B.ForIterator_j = vipldws2_B.indxI;

    /* Selector: '<S53>/Selector1' */
    vipldws2_B.Selector1_n = vipldws2_B.Init_p[vipldws2_B.ForIterator_j - 1];

    /* Outputs for Enabled SubSystem: '<S53>/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines.' incorporates:
     *  EnablePort: '<S56>/EnablePort'
     */
    if (vipldws2_B.Selector1_n > 0) {
      /* Selector: '<S56>/Selector2' */
      vipldws2_B.Selector2_f[0] = vipldws2_B.Init[(vipldws2_B.ForIterator_j - 1)
        << 1];
      vipldws2_B.Selector2_f[1] = vipldws2_B.Init[((vipldws2_B.ForIterator_j - 1)
        << 1) + 1];

      /* Outputs for Iterator SubSystem: '<S56>/Calculate the distances between  the chosen line in the repository  and all input lines.' incorporates:
       *  ForIterator: '<S57>/For Iterator'
       */
      /* Selector: '<S56>/Selector1' incorporates:
       *  Constant: '<S56>/Constant2'
       */
      for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
        vipldws2_B.Selector1_i[vipldws2_B.i] = vipldws2_P.Constant2_Value_o[(20 *
          vipldws2_B.i + vipldws2_B.ForIterator_j) - 1];
        vipldws2_B.Assignment_j[vipldws2_B.i] =
          vipldws2_B.Selector1_i[vipldws2_B.i];
      }

      /* End of Selector: '<S56>/Selector1' */
      vipldws2_DW.ForIterator_IterationMarker_c = 1U;
      vipldws2_B.planeWidth = 1;
      while (vipldws2_B.planeWidth <= vipldws2_P.ForIterator_IterationLimit_g) {
        vipldws2_B.ForIterator_f = vipldws2_B.planeWidth;

        /* Selector: '<S57>/Selector1' */
        vipldws2_DW.Selector1_DIMS1_l[0] =
          vipldws2_DW.MatrixConcatenation3_DIMS1[0];
        vipldws2_DW.Selector1_DIMS1_l[1] = 1;
        vipldws2_B.planeOffset = vipldws2_DW.MatrixConcatenation3_DIMS1[0];
        for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset;
             vipldws2_B.i++) {
          vipldws2_B.tmp_data[vipldws2_B.i] = vipldws2_B.MatrixConcatenation3
            [(vipldws2_B.ForIterator_f - 1) *
            vipldws2_DW.MatrixConcatenation3_DIMS1[0] + vipldws2_B.i];
        }

        vipldws2_B.planeOffset = vipldws2_DW.MatrixConcatenation3_DIMS1[0];
        for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset;
             vipldws2_B.i++) {
          vipldws2_B.Selector1_k[vipldws2_B.i] =
            vipldws2_B.tmp_data[vipldws2_B.i];
        }

        /* End of Selector: '<S57>/Selector1' */

        /* Selector: '<S57>/Selector2' */
        vipldws2_B.Selector2_fh =
          vipldws2_B.Assignment_d[vipldws2_B.ForIterator_f - 1];

        /* Outputs for Enabled SubSystem: '<S57>/Difference between  two lines' incorporates:
         *  EnablePort: '<S58>/Enable'
         */
        /* Switch: '<S57>/Switch1' incorporates:
         *  Constant: '<S57>/Constant'
         */
        if (vipldws2_B.Selector2_fh) {
          /* Selector: '<S58>/Theta_2' incorporates:
           *  Constant: '<S58>/Constant1'
           */
          vipldws2_B.Gain = vipldws2_B.Selector1_k[(int32_T)
            vipldws2_P.Constant1_Value - 1];

          /* Sum: '<S58>/Add8' */
          vipldws2_B.Gain = vipldws2_B.Selector2_f[1] - vipldws2_B.Gain;

          /* Abs: '<S58>/Abs' */
          vipldws2_B.Gain = (real32_T)fabs(vipldws2_B.Gain);

          /* Selector: '<S58>/Rho_2' incorporates:
           *  Constant: '<S58>/Constant'
           */
          vipldws2_B.Rho_2 = vipldws2_B.Selector1_k[(int32_T)
            vipldws2_P.Constant_Value - 1];

          /* Sum: '<S58>/Add1' */
          vipldws2_B.cnt = (real32_T)floor(vipldws2_B.Selector2_f[0] -
            vipldws2_B.Rho_2);
          if (rtIsNaNF(vipldws2_B.cnt) || rtIsInfF(vipldws2_B.cnt)) {
            vipldws2_B.cnt = 0.0F;
          } else {
            vipldws2_B.cnt = (real32_T)fmod(vipldws2_B.cnt, 4.2949673E+9F);
          }

          vipldws2_B.Abs1 = vipldws2_B.cnt < 0.0F ? -(int32_T)(uint32_T)
            -vipldws2_B.cnt : (int32_T)(uint32_T)vipldws2_B.cnt;

          /* End of Sum: '<S58>/Add1' */

          /* Abs: '<S58>/Abs1' */
          if (vipldws2_B.Abs1 < 0) {
            vipldws2_B.Abs1 = -vipldws2_B.Abs1;
          }

          /* End of Abs: '<S58>/Abs1' */

          /* Gain: '<S58>/Gain' */
          vipldws2_B.Gain *= vipldws2_P.Gain_Gain;

          /* Sum: '<S58>/Add7' */
          vipldws2_B.cnt = (real32_T)floor((real32_T)vipldws2_B.Abs1 +
            vipldws2_B.Gain);
          if (rtIsNaNF(vipldws2_B.cnt) || rtIsInfF(vipldws2_B.cnt)) {
            vipldws2_B.cnt = 0.0F;
          } else {
            vipldws2_B.cnt = (real32_T)fmod(vipldws2_B.cnt, 4.2949673E+9F);
          }

          vipldws2_B.Add7 = vipldws2_B.cnt < 0.0F ? -(int32_T)(uint32_T)
            -vipldws2_B.cnt : (int32_T)(uint32_T)vipldws2_B.cnt;

          /* End of Sum: '<S58>/Add7' */
          vipldws2_DW.Differencebetweentwolines_Subsy = 4;
          vipldws2_B.Switch1_l = vipldws2_B.Add7;
        } else {
          vipldws2_B.Switch1_l = vipldws2_P.Constant_Value_l;
        }

        /* End of Switch: '<S57>/Switch1' */
        /* End of Outputs for SubSystem: '<S57>/Difference between  two lines' */

        /* Assignment: '<S57>/Assignment' */
        vipldws2_B.Assignment_j[vipldws2_B.ForIterator_f - 1] =
          vipldws2_B.Switch1_l;
        vipldws2_B.planeWidth++;
      }

      /* End of Outputs for SubSystem: '<S56>/Calculate the distances between  the chosen line in the repository  and all input lines.' */

      /* Assignment: '<S56>/Assignment' incorporates:
       *  Constant: '<S56>/Constant2'
       */
      if (vipldws2_DW.ForIterator_IterationMarker < 2) {
        vipldws2_DW.ForIterator_IterationMarker = 2U;
        memcpy(&vipldws2_B.Assignment_p2[0], &vipldws2_P.Constant2_Value_o[0],
               400U * sizeof(int32_T));
      }

      for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
        vipldws2_B.Assignment_p2[(vipldws2_B.ForIterator_j + 20 * vipldws2_B.i)
          - 1] = vipldws2_B.Assignment_j[vipldws2_B.i];
      }

      /* End of Assignment: '<S56>/Assignment' */
      vipldws2_DW.Selectalinefromtherepositoryifi = 4;
    }

    /* End of Outputs for SubSystem: '<S53>/Select a line from the repository; if it is valid (Count > 0),  Calculate its distance to the input lines.' */
    vipldws2_B.indxI++;
  }

  /* End of Outputs for SubSystem: '<S36>/Calculate the distances between  the lines found in the current  frame and those in the repository' */

  /* Outputs for Iterator SubSystem: '<S36>/Find the best  matches between the current  lines and those in the repository' incorporates:
   *  ForIterator: '<S54>/For Iterator'
   */
  memcpy(&vipldws2_B.Assignment1_m[0], &vipldws2_B.Assignment_p2[0], 400U *
         sizeof(int32_T));
  memcpy(&vipldws2_B.Assignment2[0], &vipldws2_B.Assignment_p2[0], 400U * sizeof
         (int32_T));
  vipldws2_B.indxI = 1;
  while (vipldws2_B.indxI <= vipldws2_P.ForIterator_IterationLimit_n) {
    vipldws2_B.ForIterator_l = vipldws2_B.indxI;

    /* RelationalOperator: '<S59>/Compare' incorporates:
     *  Constant: '<S59>/Constant'
     */
    vipldws2_B.Compare_mb = (vipldws2_B.ForIterator_l <=
      vipldws2_P.CompareToConstant_const);
    for (vipldws2_B.i = 0; vipldws2_B.i < 400; vipldws2_B.i++) {
      /* Delay: '<S54>/Delay1' */
      vipldws2_B.Switch1_bi[vipldws2_B.i] =
        vipldws2_DW.Delay1_DSTATE[vipldws2_B.i];

      /* Switch: '<S54>/Switch1' */
      if (vipldws2_B.Compare_mb) {
        vipldws2_B.Switch1_bi[vipldws2_B.i] =
          vipldws2_B.Assignment_p2[vipldws2_B.i];
      }

      /* End of Switch: '<S54>/Switch1' */
    }

    /* S-Function (sdspstatminmax): '<S54>/Minimum' */
    vipldws2_B.Minimum_o1 = vipldws2_B.Switch1_bi[0];
    vipldws2_B.planeWidth = 0;
    for (vipldws2_B.i = 0; vipldws2_B.i < 399; vipldws2_B.i++) {
      if (vipldws2_B.Switch1_bi[vipldws2_B.i + 1] < vipldws2_B.Minimum_o1) {
        vipldws2_B.Minimum_o1 = vipldws2_B.Switch1_bi[vipldws2_B.i + 1];
        vipldws2_B.planeWidth = vipldws2_B.i + 1;
      }
    }

    vipldws2_B.Minimum_o2[1] = (uint32_T)(div_s32_floor(vipldws2_B.planeWidth,
      vipldws2_P.Minimum_prodDims[0]) + 1);
    vipldws2_B.planeWidth = vipldws2_B.planeWidth % vipldws2_P.Minimum_prodDims
      [0] + 1;
    vipldws2_B.Minimum_o2[0U] = (uint32_T)vipldws2_B.planeWidth;

    /* End of S-Function (sdspstatminmax): '<S54>/Minimum' */

    /* Assignment: '<S54>/Assignment1' */
    vipldws2_B.i = (int32_T)vipldws2_B.Minimum_o2[0];

    /* Assignment: '<S54>/Assignment2' */
    vipldws2_B.plane = (int32_T)vipldws2_B.Minimum_o2[1];
    for (vipldws2_B.c1 = 0; vipldws2_B.c1 < 20; vipldws2_B.c1++) {
      /* Assignment: '<S54>/Assignment1' incorporates:
       *  Constant: '<S54>/Constant'
       */
      vipldws2_B.Assignment1_m[(vipldws2_B.i + 20 * vipldws2_B.c1) - 1] =
        vipldws2_P.Constant_Value_iw;

      /* Assignment: '<S54>/Assignment2' incorporates:
       *  Constant: '<S54>/Constant'
       */
      vipldws2_B.Assignment2[vipldws2_B.c1 + 20 * (vipldws2_B.plane - 1)] =
        vipldws2_P.Constant_Value_iw;
    }

    /* Sum: '<S54>/Add' */
    for (vipldws2_B.i = 0; vipldws2_B.i < 400; vipldws2_B.i++) {
      vipldws2_B.Add_e[vipldws2_B.i] = vipldws2_B.Assignment1_m[vipldws2_B.i] +
        vipldws2_B.Assignment2[vipldws2_B.i];
    }

    /* End of Sum: '<S54>/Add' */

    /* DataTypeConversion: '<S54>/Data Type  Conversion3' */
    vipldws2_B.fromIdx = vipldws2_B.Minimum_o2[0];
    if (vipldws2_B.Minimum_o2[0] > 2147483647U) {
      vipldws2_B.fromIdx = 2147483647U;
    }

    vipldws2_B.DataTypeConversion3[0] = (int32_T)vipldws2_B.fromIdx;
    vipldws2_B.fromIdx = vipldws2_B.Minimum_o2[1];
    if (vipldws2_B.Minimum_o2[1] > 2147483647U) {
      vipldws2_B.fromIdx = 2147483647U;
    }

    vipldws2_B.DataTypeConversion3[1] = (int32_T)vipldws2_B.fromIdx;

    /* End of DataTypeConversion: '<S54>/Data Type  Conversion3' */

    /* Assignment: '<S54>/Assignment' incorporates:
     *  Assignment: '<S54>/Assignment3'
     *  Constant: '<S54>/Constant1'
     *  Constant: '<S54>/Constant2'
     */
    if (vipldws2_B.indxI == 1) {
      memcpy(&vipldws2_B.Assignment_k[0], &vipldws2_P.Constant2_Value_d[0], 40U *
             sizeof(int32_T));
      memcpy(&vipldws2_B.Assignment3[0], &vipldws2_P.Constant1_Value_c[0], 20U *
             sizeof(int32_T));
    }

    vipldws2_B.Assignment_k[(vipldws2_B.ForIterator_l - 1) << 1] =
      vipldws2_B.DataTypeConversion3[0];
    vipldws2_B.Assignment_k[1 + ((vipldws2_B.ForIterator_l - 1) << 1)] =
      vipldws2_B.DataTypeConversion3[1];

    /* End of Assignment: '<S54>/Assignment' */

    /* Assignment: '<S54>/Assignment3' */
    vipldws2_B.Assignment3[vipldws2_B.ForIterator_l - 1] = vipldws2_B.Minimum_o1;

    /* Update for Delay: '<S54>/Delay1' */
    memcpy(&vipldws2_DW.Delay1_DSTATE[0], &vipldws2_B.Add_e[0], 400U * sizeof
           (int32_T));
    vipldws2_B.indxI++;
  }

  /* End of Outputs for SubSystem: '<S36>/Find the best  matches between the current  lines and those in the repository' */

  /* Outputs for Iterator SubSystem: '<S36>/Update the repository' incorporates:
   *  ForIterator: '<S55>/For Iterator'
   */
  memcpy(&vipldws2_B.Assignment_i[0], &vipldws2_B.Init[0], 40U * sizeof(real32_T));

  /* InitializeConditions for Delay: '<S55>/Delay1' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
    vipldws2_DW.Delay1_DSTATE_g[vipldws2_B.i] =
      vipldws2_P.Delay1_InitialCondition_n;
  }

  /* End of InitializeConditions for Delay: '<S55>/Delay1' */
  vipldws2_B.indxI = 1;
  while (vipldws2_B.indxI <= vipldws2_P.ForIterator_IterationLimit_a) {
    vipldws2_B.ForIterator_a = vipldws2_B.indxI;

    /* RelationalOperator: '<S60>/Compare' incorporates:
     *  Constant: '<S60>/Constant'
     */
    vipldws2_B.Compare_n = (vipldws2_B.ForIterator_a <=
      vipldws2_P.CompareToConstant_const_m);
    for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
      /* RelationalOperator: '<S62>/Compare' incorporates:
       *  Constant: '<S62>/Constant'
       */
      vipldws2_B.Compare_p[vipldws2_B.i] = (vipldws2_B.Init_p[vipldws2_B.i] >
        vipldws2_P.Constant_Value_m);

      /* Delay: '<S55>/Delay1' */
      vipldws2_B.Switch1_m[vipldws2_B.i] =
        vipldws2_DW.Delay1_DSTATE_g[vipldws2_B.i];

      /* Switch: '<S55>/Switch1' */
      if (vipldws2_B.Compare_n) {
        vipldws2_B.Switch1_m[vipldws2_B.i] = vipldws2_B.Compare_p[vipldws2_B.i];
      }

      /* End of Switch: '<S55>/Switch1' */
    }

    /* S-Function (sdspstatminmax): '<S55>/Minimum' */
    vipldws2_B.c1 = 1;
    vipldws2_DW.Minimum_Valdata = vipldws2_B.Switch1_m[0];
    vipldws2_B.Minimum = 1U;
    for (vipldws2_B.j = 0; vipldws2_B.j < 19; vipldws2_B.j++) {
      if ((int32_T)vipldws2_B.Switch1_m[vipldws2_B.c1] < (int32_T)
          vipldws2_DW.Minimum_Valdata) {
        vipldws2_DW.Minimum_Valdata = vipldws2_B.Switch1_m[vipldws2_B.c1];
        vipldws2_B.Minimum = (uint32_T)(vipldws2_B.j + 2);
      }

      vipldws2_B.c1++;
    }

    /* End of S-Function (sdspstatminmax): '<S55>/Minimum' */

    /* Selector: '<S55>/Selector3' */
    vipldws2_B.Selector_n = vipldws2_B.Assignment3[vipldws2_B.ForIterator_a - 1];

    /* RelationalOperator: '<S61>/Compare' incorporates:
     *  Constant: '<S61>/Constant'
     */
    vipldws2_B.Compare_n = (vipldws2_B.Selector_n >
      vipldws2_P.CompareToConstant1_const);

    /* Switch: '<S55>/Switch3' */
    if (vipldws2_B.Compare_n) {
      vipldws2_B.Switch3 = vipldws2_B.Minimum;
    } else {
      /* Selector: '<S55>/Selector1' */
      vipldws2_B.Selector1_b = vipldws2_B.Assignment_k[(vipldws2_B.ForIterator_a
        - 1) << 1];
      vipldws2_B.Switch3 = (uint32_T)vipldws2_B.Selector1_b;
    }

    /* End of Switch: '<S55>/Switch3' */

    /* Assignment: '<S55>/Assignment1' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S55>/Constant2'
     */
    if (vipldws2_B.indxI == 1) {
      memcpy(&vipldws2_B.Assignment1[0], &vipldws2_P.Constant2_Value_b[0], 20U *
             sizeof(int32_T));
    }

    vipldws2_B.Assignment1[(int32_T)vipldws2_B.Switch3 - 1] =
      vipldws2_P.Constant_Value_i0;

    /* End of Assignment: '<S55>/Assignment1' */
    for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
      /* Sum: '<S55>/Add1' */
      vipldws2_B.Add_j[vipldws2_B.i] = vipldws2_B.Assignment1[vipldws2_B.i] +
        vipldws2_B.Assignment1[vipldws2_B.i];

      /* Bias: '<S55>/Bias' */
      vipldws2_B.Add_j[vipldws2_B.i] += vipldws2_P.Bias_Bias;

      /* Sum: '<S55>/Add' */
      vipldws2_B.Add_j[vipldws2_B.i] += vipldws2_B.Init_p[vipldws2_B.i];
    }

    /* Selector: '<S55>/Selector' */
    vipldws2_B.Selector_n = vipldws2_B.Assignment_k[((vipldws2_B.ForIterator_a -
      1) << 1) + 1];

    /* Selector: '<S55>/Selector2' */
    vipldws2_DW.Selector2_DIMS1[0] = vipldws2_DW.MatrixConcatenation3_DIMS1[0];
    vipldws2_DW.Selector2_DIMS1[1] = 1;
    vipldws2_B.planeOffset = vipldws2_DW.MatrixConcatenation3_DIMS1[0];
    for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
    {
      vipldws2_B.tmp_data[vipldws2_B.i] = vipldws2_B.MatrixConcatenation3
        [(vipldws2_B.Selector_n - 1) * vipldws2_DW.MatrixConcatenation3_DIMS1[0]
        + vipldws2_B.i];
    }

    vipldws2_B.planeOffset = vipldws2_DW.MatrixConcatenation3_DIMS1[0];
    for (vipldws2_B.i = 0; vipldws2_B.i < vipldws2_B.planeOffset; vipldws2_B.i++)
    {
      vipldws2_B.Selector2_b[vipldws2_B.i] = vipldws2_B.tmp_data[vipldws2_B.i];
    }

    /* End of Selector: '<S55>/Selector2' */

    /* Assignment: '<S55>/Assignment' */
    vipldws2_B.i = (int32_T)vipldws2_B.Switch3;
    vipldws2_B.planeOffset = vipldws2_DW.Selector2_DIMS1[1];
    for (vipldws2_B.plane = 0; vipldws2_B.plane < vipldws2_B.planeOffset;
         vipldws2_B.plane++) {
      vipldws2_B.planeWidth = vipldws2_DW.Selector2_DIMS1[0];
      for (vipldws2_B.c1 = 0; vipldws2_B.c1 < vipldws2_B.planeWidth;
           vipldws2_B.c1++) {
        vipldws2_B.Assignment_i[vipldws2_B.c1 + (((vipldws2_B.plane +
          vipldws2_B.i) - 1) << 1)] =
          vipldws2_B.Selector2_b[vipldws2_DW.Selector2_DIMS1[0] *
          vipldws2_B.plane + vipldws2_B.c1];
      }
    }

    /* End of Assignment: '<S55>/Assignment' */

    /* Assignment: '<S55>/Assignment2' */
    if (vipldws2_B.indxI == 1) {
      for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
        vipldws2_B.Assignment2_m[vipldws2_B.i] =
          vipldws2_B.Compare_p[vipldws2_B.i];
      }
    }

    vipldws2_B.Assignment2_m[(int32_T)vipldws2_B.Minimum - 1] =
      vipldws2_B.Compare_n;

    /* End of Assignment: '<S55>/Assignment2' */
    for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
      /* Saturate: '<S55>/Saturation' */
      if (vipldws2_B.Add_j[vipldws2_B.i] > vipldws2_P.Saturation_UpperSat_m) {
        vipldws2_B.Saturation_h[vipldws2_B.i] = vipldws2_P.Saturation_UpperSat_m;
      } else if (vipldws2_B.Add_j[vipldws2_B.i] <
                 vipldws2_P.Saturation_LowerSat_o) {
        vipldws2_B.Saturation_h[vipldws2_B.i] = vipldws2_P.Saturation_LowerSat_o;
      } else {
        vipldws2_B.Saturation_h[vipldws2_B.i] = vipldws2_B.Add_j[vipldws2_B.i];
      }

      /* End of Saturate: '<S55>/Saturation' */

      /* Update for Delay: '<S55>/Delay1' */
      vipldws2_DW.Delay1_DSTATE_g[vipldws2_B.i] =
        vipldws2_B.Assignment2_m[vipldws2_B.i];
    }

    vipldws2_B.indxI++;
  }

  /* End of Outputs for SubSystem: '<S36>/Update the repository' */

  /* UnitDelay: '<S35>/En_Delay' */
  memcpy(&vipldws2_B.En_Delay[0], &vipldws2_DW.En_Delay_DSTATE[0], 20U * sizeof
         (int32_T));

  /* UnitDelay: '<S35>/Unit Delay2' */
  memcpy(&vipldws2_B.UnitDelay2[0], &vipldws2_DW.UnitDelay2_DSTATE[0], 80U *
         sizeof(real32_T));

  /* UnitDelay: '<S35>/Unit Delay3' */
  memcpy(&vipldws2_B.UnitDelay3[0], &vipldws2_DW.UnitDelay3_DSTATE[0], 320U *
         sizeof(real32_T));

  /* Outputs for Iterator SubSystem: '<S35>/Control' incorporates:
   *  ForIterator: '<S42>/Iterator'
   */
  vipldws2_DW.Iterator_IterationMarker[0] = 1U;
  vipldws2_DW.Iterator_IterationMarker[1] = 1U;
  vipldws2_DW.Iterator_IterationMarker[2] = 1U;
  vipldws2_DW.Iterator_IterationMarker[3] = 1U;
  vipldws2_B.planeWidth = 1;
  while (vipldws2_B.planeWidth <= vipldws2_P.Iterator_IterationLimit) {
    vipldws2_B.Iterator = vipldws2_B.planeWidth;

    /* Selector: '<S42>/En_Selector' */
    vipldws2_B.En_Selector = vipldws2_B.Saturation_h[vipldws2_B.Iterator - 1];

    /* Logic: '<S42>/En_Not' */
    vipldws2_B.En_Not = !(vipldws2_B.En_Selector != 0);

    /* Selector: '<S42>/Rst_Selector' */
    vipldws2_B.Rst_Selector = vipldws2_B.En_Delay[vipldws2_B.Iterator - 1];

    /* Logic: '<S42>/Rst_And' */
    vipldws2_B.Rst_And = (vipldws2_B.En_Not && (vipldws2_B.Rst_Selector != 0));

    /* Logic: '<S42>/En_Or' */
    vipldws2_B.En_Or = ((vipldws2_B.En_Selector != 0) || vipldws2_B.Rst_And);

    /* Outputs for Enabled SubSystem: '<S42>/Options' incorporates:
     *  EnablePort: '<S43>/EnablePort'
     */
    if (vipldws2_B.En_Or) {
      /* Selector: '<S43>/Selector' */
      vipldws2_B.Selector_i[0] = vipldws2_B.Assignment_i[(vipldws2_B.Iterator -
        1) << 1];
      vipldws2_B.Selector_i[1] = vipldws2_B.Assignment_i[((vipldws2_B.Iterator -
        1) << 1) + 1];

      /* Selector: '<S43>/Selector1' */
      vipldws2_B.Selector1_c[0] = vipldws2_B.UnitDelay2[(vipldws2_B.Iterator - 1)
        << 2];
      vipldws2_B.Selector1_c[1] = vipldws2_B.UnitDelay2[((vipldws2_B.Iterator -
        1) << 2) + 1];
      vipldws2_B.Selector1_c[2] = vipldws2_B.UnitDelay2[((vipldws2_B.Iterator -
        1) << 2) + 2];
      vipldws2_B.Selector1_c[3] = vipldws2_B.UnitDelay2[((vipldws2_B.Iterator -
        1) << 2) + 3];

      /* Selector: '<S43>/Selector2' */
      for (vipldws2_B.i = 0; vipldws2_B.i < 16; vipldws2_B.i++) {
        vipldws2_B.Selector2_n[vipldws2_B.i] = vipldws2_B.UnitDelay3
          [((vipldws2_B.Iterator - 1) << 4) + vipldws2_B.i];
      }

      /* End of Selector: '<S43>/Selector2' */

      /* Outputs for Enabled SubSystem: '<S43>/Core' incorporates:
       *  EnablePort: '<S44>/EnablePort'
       */
      if (vipldws2_B.En_Selector > 0) {
        /* Math: '<S44>/P_prd Trans' */
        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          vipldws2_B.P_prdKHP_prd[vipldws2_B.i << 2] =
            vipldws2_B.Selector2_n[vipldws2_B.i];
          vipldws2_B.P_prdKHP_prd[1 + (vipldws2_B.i << 2)] =
            vipldws2_B.Selector2_n[vipldws2_B.i + 4];
          vipldws2_B.P_prdKHP_prd[2 + (vipldws2_B.i << 2)] =
            vipldws2_B.Selector2_n[vipldws2_B.i + 8];
          vipldws2_B.P_prdKHP_prd[3 + (vipldws2_B.i << 2)] =
            vipldws2_B.Selector2_n[vipldws2_B.i + 12];
        }

        /* End of Math: '<S44>/P_prd Trans' */
        for (vipldws2_B.i = 0; vipldws2_B.i < 2; vipldws2_B.i++) {
          /* Product: '<S44>/H*P_prdt' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          for (vipldws2_B.plane = 0; vipldws2_B.plane < 4; vipldws2_B.plane++) {
            vipldws2_B.HP_prdt[vipldws2_B.i + (vipldws2_B.plane << 1)] = 0.0F;
            vipldws2_B.HP_prdt[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.P_prdKHP_prd[vipldws2_B.plane << 2] *
              vipldws2_P.Hcst_Value[vipldws2_B.i];
            vipldws2_B.HP_prdt[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.P_prdKHP_prd[(vipldws2_B.plane << 2) + 1] *
              vipldws2_P.Hcst_Value[vipldws2_B.i + 2];
            vipldws2_B.HP_prdt[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.P_prdKHP_prd[(vipldws2_B.plane << 2) + 2] *
              vipldws2_P.Hcst_Value[vipldws2_B.i + 4];
            vipldws2_B.HP_prdt[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.P_prdKHP_prd[(vipldws2_B.plane << 2) + 3] *
              vipldws2_P.Hcst_Value[vipldws2_B.i + 6];
          }

          /* End of Product: '<S44>/H*P_prdt' */

          /* Product: '<S44>/H*P_prdt*Ht' incorporates:
           *  Constant: '<S44>/Hcst_t'
           */
          for (vipldws2_B.plane = 0; vipldws2_B.plane < 2; vipldws2_B.plane++) {
            vipldws2_B.HP_prdtHtR[vipldws2_B.i + (vipldws2_B.plane << 1)] = 0.0F;
            vipldws2_B.HP_prdtHtR[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_P.Hcst_t_Value[vipldws2_B.plane << 2] *
              vipldws2_B.HP_prdt[vipldws2_B.i];
            vipldws2_B.HP_prdtHtR[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_P.Hcst_t_Value[(vipldws2_B.plane << 2) + 1] *
              vipldws2_B.HP_prdt[vipldws2_B.i + 2];
            vipldws2_B.HP_prdtHtR[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_P.Hcst_t_Value[(vipldws2_B.plane << 2) + 2] *
              vipldws2_B.HP_prdt[vipldws2_B.i + 4];
            vipldws2_B.HP_prdtHtR[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_P.Hcst_t_Value[(vipldws2_B.plane << 2) + 3] *
              vipldws2_B.HP_prdt[vipldws2_B.i + 6];
          }

          /* End of Product: '<S44>/H*P_prdt*Ht' */
        }

        /* Sum: '<S44>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S44>/Constant2'
         */
        vipldws2_B.HP_prdtHtR[0] += vipldws2_P.Constant2_Value[0];

        /* S-Function (sdspldl2): '<S49>/LDL Factorization' */
        vipldws2_B.LDLFactorization[0] = vipldws2_B.HP_prdtHtR[0];

        /* Sum: '<S44>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S44>/Constant2'
         */
        vipldws2_B.HP_prdtHtR[1] += vipldws2_P.Constant2_Value[1];

        /* S-Function (sdspldl2): '<S49>/LDL Factorization' */
        vipldws2_B.LDLFactorization[1] = vipldws2_B.HP_prdtHtR[1];

        /* Sum: '<S44>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S44>/Constant2'
         */
        vipldws2_B.HP_prdtHtR[2] += vipldws2_P.Constant2_Value[2];

        /* S-Function (sdspldl2): '<S49>/LDL Factorization' */
        vipldws2_B.LDLFactorization[2] = vipldws2_B.HP_prdtHtR[2];

        /* Sum: '<S44>/H*P_prdt*Ht+R' incorporates:
         *  Constant: '<S44>/Constant2'
         */
        vipldws2_B.HP_prdtHtR[3] += vipldws2_P.Constant2_Value[3];

        /* S-Function (sdspldl2): '<S49>/LDL Factorization' */
        vipldws2_B.LDLFactorization[3] = vipldws2_B.HP_prdtHtR[3];
        LDLf_int32_Treal32_T(&vipldws2_B.LDLFactorization[0U],
                             &vipldws2_DW.LDLFactorization_VMX[0U], 2,
                             &vipldws2_B.HP_prdtHtR[0U]);

        /* S-Function (sdspfbsub2): '<S49>/Forward Substitution' */
        vipldws2_B.y[0] = vipldws2_B.HP_prdt[0];
        vipldws2_B.plane = 1;
        vipldws2_B.scale = vipldws2_B.HP_prdt[1];
        vipldws2_B.indxI = 0;
        while (vipldws2_B.indxI < 1) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane] *
            vipldws2_B.y[0];
          vipldws2_B.plane += 2;
          vipldws2_B.indxI = 1;
        }

        vipldws2_B.y[1] = vipldws2_B.scale;
        vipldws2_B.y[2] = vipldws2_B.HP_prdt[2];
        vipldws2_B.plane = 1;
        vipldws2_B.scale = vipldws2_B.HP_prdt[3];
        vipldws2_B.indxI = 0;
        while (vipldws2_B.indxI < 1) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane] *
            vipldws2_B.y[2];
          vipldws2_B.plane += 2;
          vipldws2_B.indxI = 1;
        }

        vipldws2_B.y[3] = vipldws2_B.scale;
        vipldws2_B.y[4] = vipldws2_B.HP_prdt[4];
        vipldws2_B.plane = 1;
        vipldws2_B.scale = vipldws2_B.HP_prdt[5];
        vipldws2_B.indxI = 0;
        while (vipldws2_B.indxI < 1) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane] *
            vipldws2_B.y[4];
          vipldws2_B.plane += 2;
          vipldws2_B.indxI = 1;
        }

        vipldws2_B.y[5] = vipldws2_B.scale;
        vipldws2_B.y[6] = vipldws2_B.HP_prdt[6];
        vipldws2_B.plane = 1;
        vipldws2_B.scale = vipldws2_B.HP_prdt[7];
        vipldws2_B.indxI = 0;
        while (vipldws2_B.indxI < 1) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane] *
            vipldws2_B.y[6];
          vipldws2_B.plane += 2;
          vipldws2_B.indxI = 1;
        }

        vipldws2_B.y[7] = vipldws2_B.scale;

        /* End of S-Function (sdspfbsub2): '<S49>/Forward Substitution' */

        /* S-Function (sdspdiag2): '<S49>/Extract Diagonal' */
        vipldws2_B.d[0] = vipldws2_B.LDLFactorization[0];

        /* Math: '<S49>/Math Function'
         *
         * About '<S49>/Math Function':
         *  Operator: reciprocal
         */
        vipldws2_B.ZHX_prd[0] = 1.0F / vipldws2_B.d[0];

        /* S-Function (sdspdiag2): '<S49>/Extract Diagonal' */
        vipldws2_B.d[1] = vipldws2_B.LDLFactorization[3];

        /* Math: '<S49>/Math Function'
         *
         * About '<S49>/Math Function':
         *  Operator: reciprocal
         */
        vipldws2_B.ZHX_prd[1] = 1.0F / vipldws2_B.d[1];

        /* S-Function (sdspdmult2): '<S49>/Matrix Scaling' */
        vipldws2_B.planeOffset = 0;
        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          vipldws2_B.MatrixScaling[vipldws2_B.planeOffset] =
            vipldws2_B.y[vipldws2_B.planeOffset] * vipldws2_B.ZHX_prd[0];
          vipldws2_B.planeOffset++;
          vipldws2_B.MatrixScaling[vipldws2_B.planeOffset] =
            vipldws2_B.y[vipldws2_B.planeOffset] * vipldws2_B.ZHX_prd[1];
          vipldws2_B.planeOffset++;
        }

        /* End of S-Function (sdspdmult2): '<S49>/Matrix Scaling' */

        /* S-Function (sdspfbsub2): '<S49>/Backward Substitution' */
        vipldws2_B.BackwardSubstitution[1] = vipldws2_B.MatrixScaling[1];
        vipldws2_B.plane = 0;
        vipldws2_B.scale = vipldws2_B.MatrixScaling[0];
        while (vipldws2_B.indxI > 0) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane + 2] *
            vipldws2_B.BackwardSubstitution[1];
          vipldws2_B.plane -= 2;
          vipldws2_B.indxI = 0;
        }

        vipldws2_B.BackwardSubstitution[0] = vipldws2_B.scale;
        vipldws2_B.BackwardSubstitution[3] = vipldws2_B.MatrixScaling[3];
        vipldws2_B.plane = 0;
        vipldws2_B.scale = vipldws2_B.MatrixScaling[2];
        vipldws2_B.indxI = 1;
        while (vipldws2_B.indxI > 0) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane + 2] *
            vipldws2_B.BackwardSubstitution[3];
          vipldws2_B.plane -= 2;
          vipldws2_B.indxI = 0;
        }

        vipldws2_B.BackwardSubstitution[2] = vipldws2_B.scale;
        vipldws2_B.BackwardSubstitution[5] = vipldws2_B.MatrixScaling[5];
        vipldws2_B.plane = 0;
        vipldws2_B.scale = vipldws2_B.MatrixScaling[4];
        vipldws2_B.indxI = 1;
        while (vipldws2_B.indxI > 0) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane + 2] *
            vipldws2_B.BackwardSubstitution[5];
          vipldws2_B.plane -= 2;
          vipldws2_B.indxI = 0;
        }

        vipldws2_B.BackwardSubstitution[4] = vipldws2_B.scale;
        vipldws2_B.BackwardSubstitution[7] = vipldws2_B.MatrixScaling[7];
        vipldws2_B.plane = 0;
        vipldws2_B.scale = vipldws2_B.MatrixScaling[6];
        vipldws2_B.indxI = 1;
        while (vipldws2_B.indxI > 0) {
          vipldws2_B.scale -= vipldws2_B.LDLFactorization[vipldws2_B.plane + 2] *
            vipldws2_B.BackwardSubstitution[7];
          vipldws2_B.plane -= 2;
          vipldws2_B.indxI = 0;
        }

        vipldws2_B.BackwardSubstitution[6] = vipldws2_B.scale;

        /* End of S-Function (sdspfbsub2): '<S49>/Backward Substitution' */
        for (vipldws2_B.i = 0; vipldws2_B.i < 2; vipldws2_B.i++) {
          for (vipldws2_B.plane = 0; vipldws2_B.plane < 4; vipldws2_B.plane++) {
            /* Math: '<S44>/K Trans' */
            vipldws2_B.KTrans[vipldws2_B.plane + (vipldws2_B.i << 2)] =
              vipldws2_B.BackwardSubstitution[(vipldws2_B.plane << 1) +
              vipldws2_B.i];

            /* Product: '<S44>/K*H*P_prd' incorporates:
             *  Constant: '<S44>/Hcst'
             */
            vipldws2_B.fv1[vipldws2_B.i + (vipldws2_B.plane << 1)] = 0.0F;
            vipldws2_B.fv1[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.Selector2_n[vipldws2_B.plane << 2] *
              vipldws2_P.Hcst_Value[vipldws2_B.i];
            vipldws2_B.fv1[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.Selector2_n[(vipldws2_B.plane << 2) + 1] *
              vipldws2_P.Hcst_Value[vipldws2_B.i + 2];
            vipldws2_B.fv1[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.Selector2_n[(vipldws2_B.plane << 2) + 2] *
              vipldws2_P.Hcst_Value[vipldws2_B.i + 4];
            vipldws2_B.fv1[vipldws2_B.i + (vipldws2_B.plane << 1)] +=
              vipldws2_B.Selector2_n[(vipldws2_B.plane << 2) + 3] *
              vipldws2_P.Hcst_Value[vipldws2_B.i + 6];
          }
        }

        /* Product: '<S44>/K*H*P_prd' */
        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          for (vipldws2_B.plane = 0; vipldws2_B.plane < 4; vipldws2_B.plane++) {
            vipldws2_B.P_prdKHP_prd[vipldws2_B.i + (vipldws2_B.plane << 2)] =
              0.0F;
            vipldws2_B.P_prdKHP_prd[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_B.fv1[vipldws2_B.plane << 1] *
              vipldws2_B.KTrans[vipldws2_B.i];
            vipldws2_B.P_prdKHP_prd[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_B.fv1[(vipldws2_B.plane << 1) + 1] *
              vipldws2_B.KTrans[vipldws2_B.i + 4];
          }
        }

        /* Sum: '<S44>/P_prd-K*H*P_prd' */
        for (vipldws2_B.i = 0; vipldws2_B.i < 16; vipldws2_B.i++) {
          vipldws2_B.P_prdKHP_prd[vipldws2_B.i] =
            vipldws2_B.Selector2_n[vipldws2_B.i] -
            vipldws2_B.P_prdKHP_prd[vipldws2_B.i];
        }

        /* End of Sum: '<S44>/P_prd-K*H*P_prd' */

        /* Product: '<S44>/A*P*At' incorporates:
         *  Constant: '<S44>/Constant3'
         *  Constant: '<S44>/Constant4'
         */
        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          for (vipldws2_B.plane = 0; vipldws2_B.plane < 4; vipldws2_B.plane++) {
            vipldws2_B.fv0[vipldws2_B.i + (vipldws2_B.plane << 2)] = 0.0F;
            vipldws2_B.fv0[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_P.Constant4_Value[vipldws2_B.plane << 2] *
              vipldws2_B.P_prdKHP_prd[vipldws2_B.i];
            vipldws2_B.fv0[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_P.Constant4_Value[(vipldws2_B.plane << 2) + 1] *
              vipldws2_B.P_prdKHP_prd[vipldws2_B.i + 4];
            vipldws2_B.fv0[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_P.Constant4_Value[(vipldws2_B.plane << 2) + 2] *
              vipldws2_B.P_prdKHP_prd[vipldws2_B.i + 8];
            vipldws2_B.fv0[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_P.Constant4_Value[(vipldws2_B.plane << 2) + 3] *
              vipldws2_B.P_prdKHP_prd[vipldws2_B.i + 12];
          }
        }

        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          for (vipldws2_B.plane = 0; vipldws2_B.plane < 4; vipldws2_B.plane++) {
            vipldws2_B.APAtQ[vipldws2_B.i + (vipldws2_B.plane << 2)] = 0.0F;
            vipldws2_B.APAtQ[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_B.fv0[vipldws2_B.plane << 2] *
              vipldws2_P.Constant3_Value[vipldws2_B.i];
            vipldws2_B.APAtQ[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_B.fv0[(vipldws2_B.plane << 2) + 1] *
              vipldws2_P.Constant3_Value[vipldws2_B.i + 4];
            vipldws2_B.APAtQ[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_B.fv0[(vipldws2_B.plane << 2) + 2] *
              vipldws2_P.Constant3_Value[vipldws2_B.i + 8];
            vipldws2_B.APAtQ[vipldws2_B.i + (vipldws2_B.plane << 2)] +=
              vipldws2_B.fv0[(vipldws2_B.plane << 2) + 3] *
              vipldws2_P.Constant3_Value[vipldws2_B.i + 12];
          }
        }

        /* End of Product: '<S44>/A*P*At' */

        /* Sum: '<S44>/A*P*At+Q' incorporates:
         *  Constant: '<S44>/Constant5'
         */
        for (vipldws2_B.i = 0; vipldws2_B.i < 16; vipldws2_B.i++) {
          vipldws2_B.APAtQ[vipldws2_B.i] +=
            vipldws2_P.Constant5_Value[vipldws2_B.i];
        }

        /* End of Sum: '<S44>/A*P*At+Q' */
        for (vipldws2_B.i = 0; vipldws2_B.i < 2; vipldws2_B.i++) {
          /* Product: '<S44>/H*X_prd' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.ZHX_prd[vipldws2_B.i] = 0.0F;
          vipldws2_B.ZHX_prd[vipldws2_B.i] += vipldws2_P.Hcst_Value[vipldws2_B.i]
            * vipldws2_B.Selector1_c[0];
          vipldws2_B.ZHX_prd[vipldws2_B.i] += vipldws2_P.Hcst_Value[vipldws2_B.i
            + 2] * vipldws2_B.Selector1_c[1];
          vipldws2_B.ZHX_prd[vipldws2_B.i] += vipldws2_P.Hcst_Value[vipldws2_B.i
            + 4] * vipldws2_B.Selector1_c[2];
          vipldws2_B.ZHX_prd[vipldws2_B.i] += vipldws2_P.Hcst_Value[vipldws2_B.i
            + 6] * vipldws2_B.Selector1_c[3];

          /* Sum: '<S44>/Z-H*X_prd' */
          vipldws2_B.ZHX_prd[vipldws2_B.i] = vipldws2_B.Selector_i[vipldws2_B.i]
            - vipldws2_B.ZHX_prd[vipldws2_B.i];
        }

        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          /* Product: '<S44>/K*(Z-H*X_prd)' */
          vipldws2_B.X_prdKZHX_prd[vipldws2_B.i] = 0.0F;
          vipldws2_B.X_prdKZHX_prd[vipldws2_B.i] +=
            vipldws2_B.KTrans[vipldws2_B.i] * vipldws2_B.ZHX_prd[0];
          vipldws2_B.X_prdKZHX_prd[vipldws2_B.i] +=
            vipldws2_B.KTrans[vipldws2_B.i + 4] * vipldws2_B.ZHX_prd[1];

          /* Sum: '<S44>/X_prd+K*(Z-H*X_prd)' */
          vipldws2_B.X_prdKZHX_prd[vipldws2_B.i] +=
            vipldws2_B.Selector1_c[vipldws2_B.i];
        }

        /* Product: '<S44>/A*X' incorporates:
         *  Constant: '<S44>/Constant3'
         */
        for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
          vipldws2_B.AX[vipldws2_B.i] = 0.0F;
          vipldws2_B.AX[vipldws2_B.i] += vipldws2_P.Constant3_Value[vipldws2_B.i]
            * vipldws2_B.X_prdKZHX_prd[0];
          vipldws2_B.AX[vipldws2_B.i] += vipldws2_P.Constant3_Value[vipldws2_B.i
            + 4] * vipldws2_B.X_prdKZHX_prd[1];
          vipldws2_B.AX[vipldws2_B.i] += vipldws2_P.Constant3_Value[vipldws2_B.i
            + 8] * vipldws2_B.X_prdKZHX_prd[2];
          vipldws2_B.AX[vipldws2_B.i] += vipldws2_P.Constant3_Value[vipldws2_B.i
            + 12] * vipldws2_B.X_prdKZHX_prd[3];
        }

        /* End of Product: '<S44>/A*X' */

        /* Reshape: '<S44>/P_prd_Reshape' */
        memcpy(&vipldws2_B.P_prd_Reshape[0], &vipldws2_B.APAtQ[0], sizeof
               (real32_T) << 4U);
        for (vipldws2_B.i = 0; vipldws2_B.i < 2; vipldws2_B.i++) {
          /* Product: '<S44>/Z_est_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_est_Multiply[vipldws2_B.i] = 0.0F;

          /* Product: '<S44>/Z_prd_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_prd_Multiply[vipldws2_B.i] = 0.0F;

          /* Product: '<S44>/Z_est_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_est_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i] * vipldws2_B.X_prdKZHX_prd[0];

          /* Product: '<S44>/Z_prd_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_prd_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i] * vipldws2_B.AX[0];

          /* Product: '<S44>/Z_est_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_est_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i + 2] * vipldws2_B.X_prdKZHX_prd[1];

          /* Product: '<S44>/Z_prd_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_prd_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i + 2] * vipldws2_B.AX[1];

          /* Product: '<S44>/Z_est_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_est_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i + 4] * vipldws2_B.X_prdKZHX_prd[2];

          /* Product: '<S44>/Z_prd_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_prd_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i + 4] * vipldws2_B.AX[2];

          /* Product: '<S44>/Z_est_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_est_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i + 6] * vipldws2_B.X_prdKZHX_prd[3];

          /* Product: '<S44>/Z_prd_Multiply' incorporates:
           *  Constant: '<S44>/Hcst'
           */
          vipldws2_B.Z_prd_Multiply[vipldws2_B.i] +=
            vipldws2_P.Hcst_Value[vipldws2_B.i + 6] * vipldws2_B.AX[3];
        }

        vipldws2_DW.Core_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S43>/Core' */

      /* Switch: '<S45>/Switch' incorporates:
       *  Constant: '<S45>/Reset_Value'
       */
      if (vipldws2_B.Rst_And) {
        memcpy(&vipldws2_B.Switch_m[0], &vipldws2_P.Reset_Value_Value[0], sizeof
               (real32_T) << 4U);
      } else {
        memcpy(&vipldws2_B.Switch_m[0], &vipldws2_B.P_prd_Reshape[0], sizeof
               (real32_T) << 4U);
      }

      /* End of Switch: '<S45>/Switch' */

      /* Assignment: '<S45>/Assignment' */
      if (vipldws2_DW.Iterator_IterationMarker[0] < 2) {
        vipldws2_DW.Iterator_IterationMarker[0] = 2U;
        memcpy(&vipldws2_B.Assignment_io[0], &vipldws2_B.UnitDelay3[0], 320U *
               sizeof(real32_T));
      }

      for (vipldws2_B.i = 0; vipldws2_B.i < 16; vipldws2_B.i++) {
        vipldws2_B.Assignment_io[vipldws2_B.i + ((vipldws2_B.Iterator - 1) << 4)]
          = vipldws2_B.Switch_m[vipldws2_B.i];
      }

      /* End of Assignment: '<S45>/Assignment' */

      /* Switch: '<S46>/Switch' incorporates:
       *  Constant: '<S46>/Reset_Value'
       */
      if (vipldws2_B.Rst_And) {
        vipldws2_B.Switch_l[0] = vipldws2_P.Reset_Value_Value_j[0];
        vipldws2_B.Switch_l[1] = vipldws2_P.Reset_Value_Value_j[1];
        vipldws2_B.Switch_l[2] = vipldws2_P.Reset_Value_Value_j[2];
        vipldws2_B.Switch_l[3] = vipldws2_P.Reset_Value_Value_j[3];
      } else {
        vipldws2_B.Switch_l[0] = vipldws2_B.AX[0];
        vipldws2_B.Switch_l[1] = vipldws2_B.AX[1];
        vipldws2_B.Switch_l[2] = vipldws2_B.AX[2];
        vipldws2_B.Switch_l[3] = vipldws2_B.AX[3];
      }

      /* End of Switch: '<S46>/Switch' */

      /* Assignment: '<S46>/Assignment' */
      if (vipldws2_DW.Iterator_IterationMarker[1] < 2) {
        vipldws2_DW.Iterator_IterationMarker[1] = 2U;
        memcpy(&vipldws2_B.Assignment_o[0], &vipldws2_B.UnitDelay2[0], 80U *
               sizeof(real32_T));
      }

      vipldws2_B.Assignment_o[(vipldws2_B.Iterator - 1) << 2] =
        vipldws2_B.Switch_l[0];
      vipldws2_B.Assignment_o[1 + ((vipldws2_B.Iterator - 1) << 2)] =
        vipldws2_B.Switch_l[1];
      vipldws2_B.Assignment_o[2 + ((vipldws2_B.Iterator - 1) << 2)] =
        vipldws2_B.Switch_l[2];
      vipldws2_B.Assignment_o[3 + ((vipldws2_B.Iterator - 1) << 2)] =
        vipldws2_B.Switch_l[3];

      /* End of Assignment: '<S46>/Assignment' */

      /* Switch: '<S47>/Switch' incorporates:
       *  Constant: '<S47>/Reset_Value'
       */
      if (vipldws2_B.Rst_And) {
        vipldws2_B.Switch_j[0] = vipldws2_P.Reset_Value_Value_b[0];
      } else {
        vipldws2_B.Switch_j[0] = vipldws2_B.Z_est_Multiply[0];
      }

      /* Assignment: '<S47>/Assignment' */
      vipldws2_B.Assignment_p[(vipldws2_B.Iterator - 1) << 1] =
        vipldws2_B.Switch_j[0];

      /* Switch: '<S48>/Switch' incorporates:
       *  Constant: '<S48>/Reset_Value'
       */
      if (vipldws2_B.Rst_And) {
        vipldws2_B.Switch_j[0] = vipldws2_P.Reset_Value_Value_p[0];
      } else {
        vipldws2_B.Switch_j[0] = vipldws2_B.Z_prd_Multiply[0];
      }

      /* Assignment: '<S48>/Assignment' */
      vipldws2_B.Assignment_a[(vipldws2_B.Iterator - 1) << 1] =
        vipldws2_B.Switch_j[0];

      /* Switch: '<S47>/Switch' incorporates:
       *  Constant: '<S47>/Reset_Value'
       */
      if (vipldws2_B.Rst_And) {
        vipldws2_B.Switch_j[1] = vipldws2_P.Reset_Value_Value_b[1];
      } else {
        vipldws2_B.Switch_j[1] = vipldws2_B.Z_est_Multiply[1];
      }

      /* Assignment: '<S47>/Assignment' */
      vipldws2_B.Assignment_p[1 + ((vipldws2_B.Iterator - 1) << 1)] =
        vipldws2_B.Switch_j[1];

      /* Switch: '<S48>/Switch' incorporates:
       *  Constant: '<S48>/Reset_Value'
       */
      if (vipldws2_B.Rst_And) {
        vipldws2_B.Switch_j[1] = vipldws2_P.Reset_Value_Value_p[1];
      } else {
        vipldws2_B.Switch_j[1] = vipldws2_B.Z_prd_Multiply[1];
      }

      /* Assignment: '<S48>/Assignment' */
      vipldws2_B.Assignment_a[1 + ((vipldws2_B.Iterator - 1) << 1)] =
        vipldws2_B.Switch_j[1];
      vipldws2_DW.Options_SubsysRanBC = 4;
    }

    /* End of Outputs for SubSystem: '<S42>/Options' */
    vipldws2_B.planeWidth++;
  }

  /* End of Outputs for SubSystem: '<S35>/Control' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
    /* Selector: '<S1>/select rho5' */
    vipldws2_B.selectrho5_f[vipldws2_B.i] = vipldws2_B.Assignment_p
      [(vipldws2_B.i << 1) + 1];

    /* Selector: '<S1>/select rho2' */
    vipldws2_B.selectrho2[vipldws2_B.i] = vipldws2_B.Assignment_p[vipldws2_B.i <<
      1];
  }

  /* S-Function (sviphoughlines): '<S1>/Convert lines from  Polar to Cartesian space' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
    vipldws2_B.indxI = 0;
    vipldws2_B.scale = (vipldws2_B.selectrho2[vipldws2_B.i] + 1.1920929E-7F) /
      ((real32_T)cos(vipldws2_B.selectrho5_f[vipldws2_B.i]) + 1.1920929E-7F);

    /* part-1: top horizontal axis */
    vipldws2_B.cnt = (real32_T)floor(vipldws2_B.scale + 0.5F);
    if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 319.0F)) {
      vipldws2_B.tmpOutRC[0U] = 0;
      if (vipldws2_B.cnt >= 0.5F) {
        vipldws2_B.tmpOutRC[1U] = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
      } else {
        vipldws2_B.tmpOutRC[1U] = 0;
      }

      vipldws2_B.indxI = 1;
    }

    vipldws2_B.y2 = (vipldws2_B.selectrho2[vipldws2_B.i] + 1.1920929E-7F) /
      ((real32_T)sin(vipldws2_B.selectrho5_f[vipldws2_B.i]) + 1.1920929E-7F);

    /* part-2: left vertical axis */
    vipldws2_B.cnt = (real32_T)floor(vipldws2_B.y2 + 0.5F);
    if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 119.0F)) {
      if (vipldws2_B.cnt >= 0.5F) {
        vipldws2_B.tmpOutRC[vipldws2_B.indxI << 1] = (int32_T)(real32_T)floor
          (vipldws2_B.cnt + 0.5F);
      } else {
        vipldws2_B.tmpOutRC[vipldws2_B.indxI << 1] = 0;
      }

      vipldws2_B.tmpOutRC[1 + (vipldws2_B.indxI << 1)] = 0;
      vipldws2_B.indxI++;
    }

    /* part-3: Right vertical axis */
    if (vipldws2_B.indxI < 2) {
      vipldws2_B.cnt = (real32_T)floor((vipldws2_B.scale - 319.0F) *
        (vipldws2_B.y2 / vipldws2_B.scale) + 0.5F);
      if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 119.0F)) {
        if (vipldws2_B.cnt >= 0.5F) {
          vipldws2_B.tmpOutRC[vipldws2_B.indxI << 1] = (int32_T)(real32_T)floor
            (vipldws2_B.cnt + 0.5F);
        } else {
          vipldws2_B.tmpOutRC[vipldws2_B.indxI << 1] = 0;
        }

        vipldws2_B.tmpOutRC[1 + (vipldws2_B.indxI << 1)] = 319;
        vipldws2_B.indxI++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (vipldws2_B.indxI < 2) {
      vipldws2_B.cnt = (real32_T)floor((vipldws2_B.scale - vipldws2_B.scale /
        vipldws2_B.y2 * 119.0F) + 0.5F);
      if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 319.0F)) {
        vipldws2_B.tmpOutRC[vipldws2_B.indxI << 1] = 119;
        if (vipldws2_B.cnt >= 0.5F) {
          vipldws2_B.tmpOutRC[1 + (vipldws2_B.indxI << 1)] = (int32_T)(real32_T)
            floor(vipldws2_B.cnt + 0.5F);
        } else {
          vipldws2_B.tmpOutRC[1 + (vipldws2_B.indxI << 1)] = 0;
        }

        vipldws2_B.indxI++;
      }
    }

    if (vipldws2_B.indxI < 2) {
      vipldws2_B.tmpOutRC[0U] = -1;
      vipldws2_B.tmpOutRC[1U] = -1;
      vipldws2_B.tmpOutRC[2U] = -1;
      vipldws2_B.tmpOutRC[3U] = -1;
    }

    vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i] =
      vipldws2_B.tmpOutRC[1] + 1;
    vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i + 20] =
      vipldws2_B.tmpOutRC[0] + 1;
    if (vipldws2_B.tmpOutRC[3] > 2147483646) {
      vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i + 40] =
        MAX_int32_T;
    } else {
      vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i + 40] =
        vipldws2_B.tmpOutRC[3] + 1;
    }

    if (vipldws2_B.tmpOutRC[2] > 2147483646) {
      vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i + 60] =
        MAX_int32_T;
    } else {
      vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i + 60] =
        vipldws2_B.tmpOutRC[2] + 1;
    }
  }

  /* End of S-Function (sviphoughlines): '<S1>/Convert lines from  Polar to Cartesian space' */

  /* Bias: '<S1>/Bias1' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 80; vipldws2_B.i++) {
    vipldws2_B.Bias1[vipldws2_B.i] =
      vipldws2_B.ConvertlinesfromPolartoCartesia[vipldws2_B.i] +
      vipldws2_P.Bias1_Bias_l;
  }

  /* End of Bias: '<S1>/Bias1' */

  /* Selector: '<S1>/Selector1' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
    for (vipldws2_B.plane = 0; vipldws2_B.plane < 20; vipldws2_B.plane++) {
      vipldws2_B.Selector1_il[vipldws2_B.plane + 20 * vipldws2_B.i] =
        vipldws2_B.Bias1[20 * tmp_0[vipldws2_B.i] + vipldws2_B.plane];
    }
  }

  /* End of Selector: '<S1>/Selector1' */

  /* Math: '<S1>/Transpose' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
    vipldws2_B.Transpose[vipldws2_B.i << 2] =
      vipldws2_B.Selector1_il[vipldws2_B.i];
    vipldws2_B.Transpose[1 + (vipldws2_B.i << 2)] =
      vipldws2_B.Selector1_il[vipldws2_B.i + 20];
    vipldws2_B.Transpose[2 + (vipldws2_B.i << 2)] =
      vipldws2_B.Selector1_il[vipldws2_B.i + 40];
    vipldws2_B.Transpose[3 + (vipldws2_B.i << 2)] =
      vipldws2_B.Selector1_il[vipldws2_B.i + 60];
  }

  /* End of Math: '<S1>/Transpose' */

  /* Gain: '<S1>/rho_1' */
  vipldws2_B.rho_1 = (int32_T)((int64_T)vipldws2_P.rho_1_Gain *
    vipldws2_B.Widthoftheimage[1] >> 31);

  /* Outputs for Iterator SubSystem: '<S1>/Find the left and  right lanes from the depository' incorporates:
   *  ForIterator: '<S7>/For Iterator'
   */
  /* InitializeConditions for UnitDelay: '<S24>/Min_left_dis' */
  vipldws2_DW.Min_left_dis_DSTATE = vipldws2_P.Min_left_dis_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_dis' */
  vipldws2_DW.Min_right_dis_DSTATE = vipldws2_P.Min_right_dis_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws2_DW.Min_left_pts_DSTATE[0] = vipldws2_P.Min_left_pts_InitialCondition
    [0];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws2_DW.Min_right_pts_DSTATE[0] =
    vipldws2_P.Min_right_pts_InitialCondition[0];

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws2_DW.Min_left_pts_DSTATE[1] = vipldws2_P.Min_left_pts_InitialCondition
    [1];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws2_DW.Min_right_pts_DSTATE[1] =
    vipldws2_P.Min_right_pts_InitialCondition[1];

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws2_DW.Min_left_pts_DSTATE[2] = vipldws2_P.Min_left_pts_InitialCondition
    [2];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws2_DW.Min_right_pts_DSTATE[2] =
    vipldws2_P.Min_right_pts_InitialCondition[2];

  /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
  vipldws2_DW.Min_left_pts_DSTATE[3] = vipldws2_P.Min_left_pts_InitialCondition
    [3];

  /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
  vipldws2_DW.Min_right_pts_DSTATE[3] =
    vipldws2_P.Min_right_pts_InitialCondition[3];
  vipldws2_B.indxI = 1;
  while (vipldws2_B.indxI <= vipldws2_P.ForIterator_IterationLimit) {
    vipldws2_B.ForIterator_fi = vipldws2_B.indxI;

    /* Selector: '<S7>/select rho1' */
    vipldws2_B.Intersectionwithbottomimagebo_j =
      vipldws2_B.Saturation_h[vipldws2_B.ForIterator_fi - 1];

    /* RelationalOperator: '<S23>/Compare' incorporates:
     *  Constant: '<S23>/Constant'
     */
    vipldws2_B.LogicalOperator2_j = (vipldws2_B.Intersectionwithbottomimagebo_j >=
      vipldws2_P.CompareToConstant2_const);

    /* Selector: '<S7>/select rho5' */
    vipldws2_B.selectrho5_b[0] = vipldws2_B.Transpose[(vipldws2_B.ForIterator_fi
      - 1) << 2];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_B.Min_right_pts[0] = vipldws2_DW.Min_left_pts_DSTATE[0];

    /* Selector: '<S7>/select rho5' */
    vipldws2_B.selectrho5_b[1] = vipldws2_B.Transpose
      [((vipldws2_B.ForIterator_fi - 1) << 2) + 1];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_B.Min_right_pts[1] = vipldws2_DW.Min_left_pts_DSTATE[1];

    /* Selector: '<S7>/select rho5' */
    vipldws2_B.selectrho5_b[2] = vipldws2_B.Transpose
      [((vipldws2_B.ForIterator_fi - 1) << 2) + 2];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_B.Min_right_pts[2] = vipldws2_DW.Min_left_pts_DSTATE[2];

    /* Selector: '<S7>/select rho5' */
    vipldws2_B.selectrho5_b[3] = vipldws2_B.Transpose
      [((vipldws2_B.ForIterator_fi - 1) << 2) + 3];

    /* UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_B.Min_right_pts[3] = vipldws2_DW.Min_left_pts_DSTATE[3];

    /* RelationalOperator: '<S24>/Relational Operator' */
    vipldws2_B.LogicalOperator1_m = (vipldws2_B.selectrho5_b[0] >=
      vipldws2_B.selectrho5_b[2]);

    /* Switch: '<S24>/Intersection with  bottom image boundary' */
    if (vipldws2_B.LogicalOperator1_m) {
      vipldws2_B.Intersectionwithbottomimagebo_j = vipldws2_B.selectrho5_b[1];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_j = vipldws2_B.selectrho5_b[3];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary' */

    /* Sum: '<S24>/Add2' */
    vipldws2_B.Intersectionwithbottomimagebo_j = vipldws2_B.rho_1 -
      vipldws2_B.Intersectionwithbottomimagebo_j;

    /* Abs: '<S24>/Abs' */
    if (vipldws2_B.Intersectionwithbottomimagebo_j < 0) {
      vipldws2_B.Intersectionwithbottomimagebo_d =
        -vipldws2_B.Intersectionwithbottomimagebo_j;
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_d =
        vipldws2_B.Intersectionwithbottomimagebo_j;
    }

    /* End of Abs: '<S24>/Abs' */

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     */
    vipldws2_B.LogicalOperator1_m = (vipldws2_B.Intersectionwithbottomimagebo_j >=
      vipldws2_P.Constant_Value_i);

    /* Logic: '<S24>/Logical Operator' */
    vipldws2_B.RelationalOperator2_e = (vipldws2_B.LogicalOperator1_m &&
      vipldws2_B.LogicalOperator2_j);

    /* Switch: '<S24>/Intersection with  bottom image boundary1' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_j =
        vipldws2_B.Intersectionwithbottomimagebo_d;
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_j = vipldws2_B.Widthoftheimage[1];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary1' */

    /* UnitDelay: '<S24>/Min_left_dis' */
    vipldws2_B.Min_right_dis = vipldws2_DW.Min_left_dis_DSTATE;

    /* RelationalOperator: '<S24>/Relational Operator1' */
    vipldws2_B.RelationalOperator2_e = (vipldws2_B.Min_right_dis <=
      vipldws2_B.Intersectionwithbottomimagebo_j);

    /* Switch: '<S24>/Intersection with  bottom image boundary2' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimageboun = vipldws2_B.Min_right_dis;
    } else {
      vipldws2_B.Intersectionwithbottomimageboun =
        vipldws2_B.Intersectionwithbottomimagebo_j;
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary2' */

    /* Logic: '<S24>/Logical Operator1' */
    vipldws2_B.LogicalOperator1_m = !vipldws2_B.LogicalOperator1_m;

    /* Logic: '<S24>/Logical Operator2' */
    vipldws2_B.LogicalOperator2_j = (vipldws2_B.LogicalOperator2_j &&
      vipldws2_B.LogicalOperator1_m);

    /* Switch: '<S24>/Intersection with  bottom image boundary4' */
    if (!vipldws2_B.LogicalOperator2_j) {
      vipldws2_B.Intersectionwithbottomimagebo_d = vipldws2_B.Widthoftheimage[1];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary4' */

    /* UnitDelay: '<S24>/Min_right_dis' */
    vipldws2_B.Min_right_dis = vipldws2_DW.Min_right_dis_DSTATE;

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_o[0] = vipldws2_B.Min_right_pts[0];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_o[0] = vipldws2_B.selectrho5_b[0];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_B.Min_right_pts[0] = vipldws2_DW.Min_right_pts_DSTATE[0];

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_o[1] = vipldws2_B.Min_right_pts[1];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_o[1] = vipldws2_B.selectrho5_b[1];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_B.Min_right_pts[1] = vipldws2_DW.Min_right_pts_DSTATE[1];

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_o[2] = vipldws2_B.Min_right_pts[2];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_o[2] = vipldws2_B.selectrho5_b[2];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_B.Min_right_pts[2] = vipldws2_DW.Min_right_pts_DSTATE[2];

    /* Switch: '<S24>/Intersection with  bottom image boundary3' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_o[3] = vipldws2_B.Min_right_pts[3];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_o[3] = vipldws2_B.selectrho5_b[3];
    }

    /* UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_B.Min_right_pts[3] = vipldws2_DW.Min_right_pts_DSTATE[3];

    /* RelationalOperator: '<S24>/Relational Operator2' */
    vipldws2_B.RelationalOperator2_e = (vipldws2_B.Min_right_dis <=
      vipldws2_B.Intersectionwithbottomimagebo_d);

    /* Switch: '<S24>/Intersection with  bottom image boundary5' incorporates:
     *  Switch: '<S24>/Intersection with  bottom image boundary6'
     */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_g = vipldws2_B.Min_right_dis;
      vipldws2_B.Intersectionwithbottomimagebo_c[0] = vipldws2_B.Min_right_pts[0];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_g =
        vipldws2_B.Intersectionwithbottomimagebo_d;
      vipldws2_B.Intersectionwithbottomimagebo_c[0] = vipldws2_B.selectrho5_b[0];
    }

    /* End of Switch: '<S24>/Intersection with  bottom image boundary5' */

    /* Update for UnitDelay: '<S24>/Min_left_dis' */
    vipldws2_DW.Min_left_dis_DSTATE = vipldws2_B.Intersectionwithbottomimageboun;

    /* Update for UnitDelay: '<S24>/Min_right_dis' */
    vipldws2_DW.Min_right_dis_DSTATE =
      vipldws2_B.Intersectionwithbottomimagebo_g;

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[0] =
      vipldws2_B.Intersectionwithbottomimagebo_o[0];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[0] =
      vipldws2_B.Intersectionwithbottomimagebo_c[0];

    /* Switch: '<S24>/Intersection with  bottom image boundary6' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_c[1] = vipldws2_B.Min_right_pts[1];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_c[1] = vipldws2_B.selectrho5_b[1];
    }

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[1] =
      vipldws2_B.Intersectionwithbottomimagebo_o[1];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[1] =
      vipldws2_B.Intersectionwithbottomimagebo_c[1];

    /* Switch: '<S24>/Intersection with  bottom image boundary6' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_c[2] = vipldws2_B.Min_right_pts[2];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_c[2] = vipldws2_B.selectrho5_b[2];
    }

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[2] =
      vipldws2_B.Intersectionwithbottomimagebo_o[2];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[2] =
      vipldws2_B.Intersectionwithbottomimagebo_c[2];

    /* Switch: '<S24>/Intersection with  bottom image boundary6' */
    if (vipldws2_B.RelationalOperator2_e) {
      vipldws2_B.Intersectionwithbottomimagebo_c[3] = vipldws2_B.Min_right_pts[3];
    } else {
      vipldws2_B.Intersectionwithbottomimagebo_c[3] = vipldws2_B.selectrho5_b[3];
    }

    /* Update for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[3] =
      vipldws2_B.Intersectionwithbottomimagebo_o[3];

    /* Update for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[3] =
      vipldws2_B.Intersectionwithbottomimagebo_c[3];
    vipldws2_B.indxI++;
  }

  /* End of Outputs for SubSystem: '<S1>/Find the left and  right lanes from the depository' */

  /* Gain: '<S1>/Distance threshold  for departure warning' */
  vipldws2_B.Distancethresholdfordeparturewa = (int32_T)((int64_T)
    vipldws2_P.Distancethresholdfordeparturewa * vipldws2_B.Widthoftheimage[1] >>
    32);

  /* RelationalOperator: '<S6>/Relational Operator4' */
  vipldws2_B.Compare_ni = (vipldws2_B.Intersectionwithbottomimageboun <=
    vipldws2_B.Intersectionwithbottomimagebo_g);

  /* Switch: '<S6>/Switch2' */
  if (vipldws2_B.Compare_ni) {
    /* RelationalOperator: '<S6>/Relational Operator2' */
    vipldws2_B.RelationalOperator2 = (vipldws2_B.Intersectionwithbottomimageboun
      < vipldws2_B.Distancethresholdfordeparturewa);

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Draw Lines'
     *  Constant: '<S6>/Draw Lines1'
     */
    if (vipldws2_B.RelationalOperator2) {
      vipldws2_B.Switch_a = vipldws2_P.DrawLines_Value;
    } else {
      vipldws2_B.Switch_a = vipldws2_P.DrawLines1_Value;
    }

    /* End of Switch: '<S6>/Switch' */
    vipldws2_B.RawMessage = vipldws2_B.Switch_a;
  } else {
    /* RelationalOperator: '<S6>/Relational Operator3' */
    vipldws2_B.RelationalOperator3 = (vipldws2_B.Intersectionwithbottomimagebo_g
      < vipldws2_B.Distancethresholdfordeparturewa);

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Draw Lines2'
     *  Constant: '<S6>/Draw Lines3'
     */
    if (vipldws2_B.RelationalOperator3) {
      vipldws2_B.Switch1_j = vipldws2_P.DrawLines2_Value;
    } else {
      vipldws2_B.Switch1_j = vipldws2_P.DrawLines3_Value;
    }

    /* End of Switch: '<S6>/Switch1' */
    vipldws2_B.RawMessage = vipldws2_B.Switch1_j;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Delay: '<S17>/Delay' */
  vipldws2_B.Delay = vipldws2_DW.Delay_DSTATE;

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   */
  vipldws2_B.Compare_ni = (vipldws2_B.RawMessage ==
    vipldws2_P.CompareToConstant_const_h);

  /* Delay: '<S17>/Delay1' */
  vipldws2_B.Bias_h = vipldws2_DW.Delay1_DSTATE_e;

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  vipldws2_B.Compare = (vipldws2_B.Bias_h !=
                        vipldws2_P.CompareToConstant1_const_h);

  /* S-Function (sdspcount2): '<S17>/Counter' */
  if (vipldws2_B.Compare) {
    vipldws2_DW.Counter_Count = vipldws2_P.Counter_InitialCount;
  }

  if (vipldws2_B.Compare_ni) {
    vipldws2_DW.Counter_Count++;
  }

  vipldws2_B.Counter = vipldws2_DW.Counter_Count;

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
  if (vipldws2_B.RawMessage == 1) {
    /* '<S20>:1:12' outMsg = NORMAL; */
    vipldws2_B.outMsg = 1;
  } else {
    /* '<S20>:1:13' else */
    /*  curMsg == RIGHT_DEP  || curMsg == LEFT_DEP */
    /* '<S20>:1:14' if (numNormalDrivenFrames < int32(4)) */
    if (vipldws2_B.Counter < 4) {
      /*  use the previous message */
      /* '<S20>:1:16' outMsg = prevMsg; */
      vipldws2_B.outMsg = vipldws2_B.Delay;
    } else {
      /* '<S20>:1:17' else */
      /* '<S20>:1:18' outMsg = curMsg; */
      vipldws2_B.outMsg = vipldws2_B.RawMessage;
    }
  }

  /* End of MATLAB Function: '<S17>/Combine Left Right Departure' */

  /* RelationalOperator: '<S64>/Compare' incorporates:
   *  Constant: '<S64>/Constant'
   */
  vipldws2_B.Compare_ni = (vipldws2_B.outMsg ==
    vipldws2_P.CompareToConstant2_const_i);

  /* Selector: '<S32>/select rho5' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 21; vipldws2_B.i++) {
    memcpy(&vipldws2_B.selectrho5_m[vipldws2_B.i * 36],
           &vipldws2_B.HoughTransform_o1[vipldws2_B.i * 683 + 99414], 36U *
           sizeof(real32_T));
  }

  /* End of Selector: '<S32>/select rho5' */

  /* S-Function (svipfindlocalmax): '<S32>/Find Local Maxima1' */
  vipldws2_B.planeWidth = 0;
  done = false;
  vipldws2_B.i = 0;
  while (vipldws2_B.i < 756) {
    vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.i] =
      vipldws2_B.selectrho5_m[vipldws2_B.i];
    vipldws2_B.i++;
  }

  vipldws2_B.FindLocalMaxima1_o1_f[0] = 0U;
  vipldws2_B.FindLocalMaxima1_o1_f[1] = 0U;
  while (!done) {
    vipldws2_B.planeOffset = 0;
    vipldws2_B.scale = vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[0];
    vipldws2_B.i = 0;
    while (vipldws2_B.i < 756) {
      if (vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.i] >
          vipldws2_B.scale) {
        vipldws2_B.planeOffset = vipldws2_B.i;
        vipldws2_B.scale =
          vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.i];
      }

      vipldws2_B.i++;
    }

    vipldws2_B.plane = vipldws2_B.planeOffset % 36;
    vipldws2_B.i = vipldws2_B.planeOffset / 36;
    if (vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.planeOffset] >=
        vipldws2_P.FindLocalMaxima1_threshold_b) {
      vipldws2_B.FindLocalMaxima1_o1_f[vipldws2_B.planeWidth] = (uint16_T)(1 +
        vipldws2_B.i);
      vipldws2_B.FindLocalMaxima1_o1_f[1U + vipldws2_B.planeWidth] = (uint16_T)
        (1 + vipldws2_B.plane);
      vipldws2_B.planeWidth++;
      if (vipldws2_B.planeWidth == 1) {
        done = true;
      }

      vipldws2_B.planeOffset = vipldws2_B.plane - 3;
      if (!(vipldws2_B.planeOffset > 0)) {
        vipldws2_B.planeOffset = 0;
      }

      vipldws2_B.plane += 3;
      if (!(vipldws2_B.plane < 35)) {
        vipldws2_B.plane = 35;
      }

      vipldws2_B.C2 = vipldws2_B.i - 3;
      vipldws2_B.c2 = vipldws2_B.i + 3;
      if (!((vipldws2_B.C2 < 0) || (vipldws2_B.c2 > 20))) {
        while (vipldws2_B.C2 <= vipldws2_B.c2) {
          vipldws2_B.c1 = vipldws2_B.C2 * 36;
          vipldws2_B.i = vipldws2_B.planeOffset;
          while (vipldws2_B.i <= vipldws2_B.plane) {
            vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.i +
              vipldws2_B.c1] = 0.0F;
            vipldws2_B.i++;
          }

          vipldws2_B.C2++;
        }
      } else {
        if (vipldws2_B.C2 < 0) {
          vipldws2_B.j = vipldws2_B.C2;
          while (vipldws2_B.j <= vipldws2_B.c2) {
            if (vipldws2_B.j < 0) {
              vipldws2_B.c1 = (vipldws2_B.j + 21) * 36 + 35;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.c1 -
                  vipldws2_B.i] = 0.0F;
                vipldws2_B.i++;
              }
            } else {
              vipldws2_B.c1 = vipldws2_B.j * 36;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.i +
                  vipldws2_B.c1] = 0.0F;
                vipldws2_B.i++;
              }
            }

            vipldws2_B.j++;
          }
        }

        if (vipldws2_B.c2 > 20) {
          vipldws2_B.j = vipldws2_B.C2;
          while (vipldws2_B.j <= vipldws2_B.c2) {
            if (vipldws2_B.j > 20) {
              vipldws2_B.c1 = (vipldws2_B.j - 21) * 36 + 35;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.c1 -
                  vipldws2_B.i] = 0.0F;
                vipldws2_B.i++;
              }
            } else {
              vipldws2_B.c1 = vipldws2_B.j * 36;
              vipldws2_B.i = vipldws2_B.planeOffset;
              while (vipldws2_B.i <= vipldws2_B.plane) {
                vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[vipldws2_B.i +
                  vipldws2_B.c1] = 0.0F;
                vipldws2_B.i++;
              }
            }

            vipldws2_B.j++;
          }
        }
      }
    } else {
      done = true;
    }
  }

  vipldws2_B.FindLocalMaxima1_o2_c = (uint16_T)vipldws2_B.planeWidth;

  /* End of S-Function (svipfindlocalmax): '<S32>/Find Local Maxima1' */

  /* Switch: '<S5>/Switch1' */
  if (vipldws2_B.Compare_ni) {
    /* Selector: '<S33>/Selector2' */
    vipldws2_B.Selector2_mw[0] = vipldws2_B.FindLocalMaxima1_o1[1];

    /* Math: '<S33>/Transpose' */
    vipldws2_B.Transpose_b[0] = vipldws2_B.Selector2_mw[0];

    /* Selector: '<S33>/Selector2' */
    vipldws2_B.Selector2_mw[1] = vipldws2_B.FindLocalMaxima1_o1[0];

    /* Math: '<S33>/Transpose' */
    vipldws2_B.Transpose_b[1] = vipldws2_B.Selector2_mw[1];

    /* Selector: '<S33>/select rho4' */
    vipldws2_B.Bias3_f = vipldws2_B.Transpose_b[0];

    /* Bias: '<S33>/Bias2' */
    vipldws2_B.Bias3_f = (uint16_T)((uint32_T)vipldws2_B.Bias3_f +
      vipldws2_P.Bias2_Bias_h);

    /* Selector: '<S33>/Selector rho' */
    vipldws2_B.Selectorrho_c = vipldws2_B.HoughTransform_o3[vipldws2_B.Bias3_f -
      1];

    /* Selector: '<S33>/select rho7' */
    vipldws2_B.Bias3_f = vipldws2_B.Transpose_b[1];

    /* Bias: '<S33>/Bias3' */
    vipldws2_B.Bias3_f = (uint16_T)((uint32_T)vipldws2_B.Bias3_f +
      vipldws2_P.Bias3_Bias_d);

    /* Selector: '<S33>/Selector theta' */
    vipldws2_B.Selectortheta_i = vipldws2_B.HoughTransform_o2[vipldws2_B.Bias3_f
      - 1];

    /* S-Function (sviphoughlines): '<S29>/Hough Lines' */
    vipldws2_B.indxI = 0;
    vipldws2_B.scale = (vipldws2_B.Selectorrho_c + 1.1920929E-7F) / ((real32_T)
      cos(vipldws2_B.Selectortheta_i) + 1.1920929E-7F);

    /* part-1: top horizontal axis */
    vipldws2_B.cnt = (real32_T)floor(vipldws2_B.scale + 0.5F);
    if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 319.0F)) {
      vipldws2_B.tmpOutRC_m[0U] = 0;
      if (vipldws2_B.cnt >= 0.5F) {
        vipldws2_B.tmpOutRC_m[1U] = (int32_T)(real32_T)floor(vipldws2_B.cnt +
          0.5F);
      } else {
        vipldws2_B.tmpOutRC_m[1U] = 0;
      }

      vipldws2_B.indxI = 1;
    }

    vipldws2_B.y2 = (vipldws2_B.Selectorrho_c + 1.1920929E-7F) / ((real32_T)sin
      (vipldws2_B.Selectortheta_i) + 1.1920929E-7F);

    /* part-2: left vertical axis */
    vipldws2_B.cnt = (real32_T)floor(vipldws2_B.y2 + 0.5F);
    if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 119.0F)) {
      if (vipldws2_B.cnt >= 0.5F) {
        vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = (int32_T)(real32_T)floor
          (vipldws2_B.cnt + 0.5F);
      } else {
        vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = 0;
      }

      vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = 0;
      vipldws2_B.indxI++;
    }

    /* part-3: Right vertical axis */
    if (vipldws2_B.indxI < 2) {
      vipldws2_B.cnt = (real32_T)floor((vipldws2_B.scale - 319.0F) *
        (vipldws2_B.y2 / vipldws2_B.scale) + 0.5F);
      if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 119.0F)) {
        if (vipldws2_B.cnt >= 0.5F) {
          vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = (int32_T)(real32_T)
            floor(vipldws2_B.cnt + 0.5F);
        } else {
          vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = 0;
        }

        vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = 319;
        vipldws2_B.indxI++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (vipldws2_B.indxI < 2) {
      vipldws2_B.cnt = (real32_T)floor((vipldws2_B.scale - vipldws2_B.scale /
        vipldws2_B.y2 * 119.0F) + 0.5F);
      if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 319.0F)) {
        vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = 119;
        if (vipldws2_B.cnt >= 0.5F) {
          vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = (int32_T)
            (real32_T)floor(vipldws2_B.cnt + 0.5F);
        } else {
          vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = 0;
        }

        vipldws2_B.indxI++;
      }
    }

    if (vipldws2_B.indxI < 2) {
      vipldws2_B.tmpOutRC_m[0U] = -1;
      vipldws2_B.tmpOutRC_m[1U] = -1;
      vipldws2_B.tmpOutRC_m[2U] = -1;
      vipldws2_B.tmpOutRC_m[3U] = -1;
    }

    vipldws2_B.HoughLines[0] = vipldws2_B.tmpOutRC_m[1] + 1;
    vipldws2_B.HoughLines[1] = vipldws2_B.tmpOutRC_m[0] + 1;
    vipldws2_B.HoughLines[2] = vipldws2_B.tmpOutRC_m[3] + 1;
    vipldws2_B.HoughLines[3] = vipldws2_B.tmpOutRC_m[2] + 1;

    /* End of S-Function (sviphoughlines): '<S29>/Hough Lines' */

    /* Selector: '<S29>/Selector1' */
    vipldws2_B.Selector1_ce[0] = vipldws2_B.HoughLines[1];

    /* Math: '<S29>/Transpose' */
    vipldws2_B.Transpose_g[0] = vipldws2_B.Selector1_ce[0];
    vipldws2_B.Switch1_b[0] = vipldws2_B.Transpose_g[0];

    /* Selector: '<S29>/Selector1' */
    vipldws2_B.Selector1_ce[1] = vipldws2_B.HoughLines[0];

    /* Math: '<S29>/Transpose' */
    vipldws2_B.Transpose_g[1] = vipldws2_B.Selector1_ce[1];
    vipldws2_B.Switch1_b[1] = vipldws2_B.Transpose_g[1];

    /* Selector: '<S29>/Selector1' */
    vipldws2_B.Selector1_ce[2] = vipldws2_B.HoughLines[3];

    /* Math: '<S29>/Transpose' */
    vipldws2_B.Transpose_g[2] = vipldws2_B.Selector1_ce[2];
    vipldws2_B.Switch1_b[2] = vipldws2_B.Transpose_g[2];

    /* Selector: '<S29>/Selector1' */
    vipldws2_B.Selector1_ce[3] = vipldws2_B.HoughLines[2];

    /* Math: '<S29>/Transpose' */
    vipldws2_B.Transpose_g[3] = vipldws2_B.Selector1_ce[3];
    vipldws2_B.Switch1_b[3] = vipldws2_B.Transpose_g[3];
  } else {
    /* Selector: '<S32>/Selector1' */
    vipldws2_B.Selector1_e[0] = vipldws2_B.FindLocalMaxima1_o1_f[1];

    /* Math: '<S32>/Transpose' */
    vipldws2_B.Transpose_gb[0] = vipldws2_B.Selector1_e[0];

    /* Selector: '<S32>/Selector1' */
    vipldws2_B.Selector1_e[1] = vipldws2_B.FindLocalMaxima1_o1_f[0];

    /* Math: '<S32>/Transpose' */
    vipldws2_B.Transpose_gb[1] = vipldws2_B.Selector1_e[1];

    /* Selector: '<S32>/select rho4' */
    vipldws2_B.Bias3_d = vipldws2_B.Transpose_gb[0];

    /* Bias: '<S32>/Bias2' */
    vipldws2_B.Bias3_d = (uint16_T)((uint32_T)vipldws2_B.Bias3_d +
      vipldws2_P.Bias2_Bias_k);

    /* Selector: '<S32>/Selector rho' */
    vipldws2_B.Selectorrho_o = vipldws2_B.HoughTransform_o3[vipldws2_B.Bias3_d -
      1];

    /* Selector: '<S32>/select rho7' */
    vipldws2_B.Bias3_d = vipldws2_B.Transpose_gb[1];

    /* Bias: '<S32>/Bias3' */
    vipldws2_B.Bias3_d = (uint16_T)((uint32_T)vipldws2_B.Bias3_d +
      vipldws2_P.Bias3_Bias_c);

    /* Selector: '<S32>/Selector theta' */
    vipldws2_B.Selectortheta_g = vipldws2_B.HoughTransform_o2[vipldws2_B.Bias3_d
      - 1];

    /* S-Function (sviphoughlines): '<S29>/Hough Lines1' */
    vipldws2_B.indxI = 0;
    vipldws2_B.scale = (vipldws2_B.Selectorrho_o + 1.1920929E-7F) / ((real32_T)
      cos(vipldws2_B.Selectortheta_g) + 1.1920929E-7F);

    /* part-1: top horizontal axis */
    vipldws2_B.cnt = (real32_T)floor(vipldws2_B.scale + 0.5F);
    if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 319.0F)) {
      vipldws2_B.tmpOutRC_m[0U] = 0;
      if (vipldws2_B.cnt >= 0.5F) {
        vipldws2_B.tmpOutRC_m[1U] = (int32_T)(real32_T)floor(vipldws2_B.cnt +
          0.5F);
      } else {
        vipldws2_B.tmpOutRC_m[1U] = 0;
      }

      vipldws2_B.indxI = 1;
    }

    vipldws2_B.y2 = (vipldws2_B.Selectorrho_o + 1.1920929E-7F) / ((real32_T)sin
      (vipldws2_B.Selectortheta_g) + 1.1920929E-7F);

    /* part-2: left vertical axis */
    vipldws2_B.cnt = (real32_T)floor(vipldws2_B.y2 + 0.5F);
    if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 119.0F)) {
      if (vipldws2_B.cnt >= 0.5F) {
        vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = (int32_T)(real32_T)floor
          (vipldws2_B.cnt + 0.5F);
      } else {
        vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = 0;
      }

      vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = 0;
      vipldws2_B.indxI++;
    }

    /* part-3: Right vertical axis */
    if (vipldws2_B.indxI < 2) {
      vipldws2_B.cnt = (real32_T)floor((vipldws2_B.scale - 319.0F) *
        (vipldws2_B.y2 / vipldws2_B.scale) + 0.5F);
      if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 119.0F)) {
        if (vipldws2_B.cnt >= 0.5F) {
          vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = (int32_T)(real32_T)
            floor(vipldws2_B.cnt + 0.5F);
        } else {
          vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = 0;
        }

        vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = 319;
        vipldws2_B.indxI++;
      }
    }

    /* part-4: bottom horizontal axis */
    if (vipldws2_B.indxI < 2) {
      vipldws2_B.cnt = (real32_T)floor((vipldws2_B.scale - vipldws2_B.scale /
        vipldws2_B.y2 * 119.0F) + 0.5F);
      if ((vipldws2_B.cnt >= 0.0F) && (vipldws2_B.cnt <= 319.0F)) {
        vipldws2_B.tmpOutRC_m[vipldws2_B.indxI << 1] = 119;
        if (vipldws2_B.cnt >= 0.5F) {
          vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = (int32_T)
            (real32_T)floor(vipldws2_B.cnt + 0.5F);
        } else {
          vipldws2_B.tmpOutRC_m[1 + (vipldws2_B.indxI << 1)] = 0;
        }

        vipldws2_B.indxI++;
      }
    }

    if (vipldws2_B.indxI < 2) {
      vipldws2_B.tmpOutRC_m[0U] = -1;
      vipldws2_B.tmpOutRC_m[1U] = -1;
      vipldws2_B.tmpOutRC_m[2U] = -1;
      vipldws2_B.tmpOutRC_m[3U] = -1;
    }

    vipldws2_B.HoughLines1[0] = vipldws2_B.tmpOutRC_m[1] + 1;
    vipldws2_B.HoughLines1[1] = vipldws2_B.tmpOutRC_m[0] + 1;
    vipldws2_B.HoughLines1[2] = vipldws2_B.tmpOutRC_m[3] + 1;
    vipldws2_B.HoughLines1[3] = vipldws2_B.tmpOutRC_m[2] + 1;

    /* End of S-Function (sviphoughlines): '<S29>/Hough Lines1' */

    /* Selector: '<S29>/Selector2' */
    vipldws2_B.Selector2_l[0] = vipldws2_B.HoughLines1[1];

    /* Math: '<S29>/Transpose1' */
    vipldws2_B.Transpose1[0] = vipldws2_B.Selector2_l[0];
    vipldws2_B.Switch1_b[0] = vipldws2_B.Transpose1[0];

    /* Selector: '<S29>/Selector2' */
    vipldws2_B.Selector2_l[1] = vipldws2_B.HoughLines1[0];

    /* Math: '<S29>/Transpose1' */
    vipldws2_B.Transpose1[1] = vipldws2_B.Selector2_l[1];
    vipldws2_B.Switch1_b[1] = vipldws2_B.Transpose1[1];

    /* Selector: '<S29>/Selector2' */
    vipldws2_B.Selector2_l[2] = vipldws2_B.HoughLines1[3];

    /* Math: '<S29>/Transpose1' */
    vipldws2_B.Transpose1[2] = vipldws2_B.Selector2_l[2];
    vipldws2_B.Switch1_b[2] = vipldws2_B.Transpose1[2];

    /* Selector: '<S29>/Selector2' */
    vipldws2_B.Selector2_l[3] = vipldws2_B.HoughLines1[2];

    /* Math: '<S29>/Transpose1' */
    vipldws2_B.Transpose1[3] = vipldws2_B.Selector2_l[3];
    vipldws2_B.Switch1_b[3] = vipldws2_B.Transpose1[3];
  }

  /* End of Switch: '<S5>/Switch1' */

  /* RelationalOperator: '<S63>/Compare' incorporates:
   *  Constant: '<S63>/Constant'
   */
  vipldws2_B.Compare_ni = (vipldws2_B.outMsg !=
    vipldws2_P.CompareToConstant1_const_j);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  vipldws2_B.LogicalOperator2_n = (vipldws2_B.outMsg !=
    vipldws2_P.CompareToConstant1_const_l);

  /* RelationalOperator: '<S6>/Relational Operator' */
  vipldws2_B.LogicalOperator_b = (vipldws2_B.Intersectionwithbottomimageboun <=
    vipldws2_B.Widthoftheimage[1]);

  /* RelationalOperator: '<S6>/Relational Operator1' */
  vipldws2_B.RelationalOperator1 = (vipldws2_B.Intersectionwithbottomimagebo_g <
    vipldws2_B.Widthoftheimage[1]);

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.LogicalOperator_b) {
    vipldws2_B.MatrixConcatenation5[0] =
      vipldws2_B.Intersectionwithbottomimagebo_o[0];
  } else {
    vipldws2_B.MatrixConcatenation5[0] = vipldws2_P.DrawLines4_Value[0];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.RelationalOperator1) {
    vipldws2_B.MatrixConcatenation5[4] =
      vipldws2_B.Intersectionwithbottomimagebo_c[0];
  } else {
    vipldws2_B.MatrixConcatenation5[4] = vipldws2_P.DrawLines4_Value[0];
  }

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.LogicalOperator_b) {
    vipldws2_B.MatrixConcatenation5[1] =
      vipldws2_B.Intersectionwithbottomimagebo_o[1];
  } else {
    vipldws2_B.MatrixConcatenation5[1] = vipldws2_P.DrawLines4_Value[1];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.RelationalOperator1) {
    vipldws2_B.MatrixConcatenation5[5] =
      vipldws2_B.Intersectionwithbottomimagebo_c[1];
  } else {
    vipldws2_B.MatrixConcatenation5[5] = vipldws2_P.DrawLines4_Value[1];
  }

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.LogicalOperator_b) {
    vipldws2_B.MatrixConcatenation5[2] =
      vipldws2_B.Intersectionwithbottomimagebo_o[2];
  } else {
    vipldws2_B.MatrixConcatenation5[2] = vipldws2_P.DrawLines4_Value[2];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.RelationalOperator1) {
    vipldws2_B.MatrixConcatenation5[6] =
      vipldws2_B.Intersectionwithbottomimagebo_c[2];
  } else {
    vipldws2_B.MatrixConcatenation5[6] = vipldws2_P.DrawLines4_Value[2];
  }

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.LogicalOperator_b) {
    vipldws2_B.MatrixConcatenation5[3] =
      vipldws2_B.Intersectionwithbottomimagebo_o[3];
  } else {
    vipldws2_B.MatrixConcatenation5[3] = vipldws2_P.DrawLines4_Value[3];
  }

  /* Switch: '<S6>/Switch3' incorporates:
   *  Constant: '<S6>/Draw Lines4'
   */
  if (vipldws2_B.RelationalOperator1) {
    vipldws2_B.MatrixConcatenation5[7] =
      vipldws2_B.Intersectionwithbottomimagebo_c[3];
  } else {
    vipldws2_B.MatrixConcatenation5[7] = vipldws2_P.DrawLines4_Value[3];
  }

  /* Selector: '<S2>/Selector' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 3; vipldws2_B.i++) {
    for (vipldws2_B.plane = 0; vipldws2_B.plane < 320; vipldws2_B.plane++) {
      memcpy(&vipldws2_B.Selector_a[vipldws2_B.i * 38400 + vipldws2_B.plane *
             120], &vipldws2_B.ImageDataTypeConversion[(vipldws2_B.i * 76800 +
              vipldws2_B.plane * 240) + 120], 120U * sizeof(real32_T));
    }
  }

  /* End of Selector: '<S2>/Selector' */

  /* S-Function (svipcolorconv): '<S2>/Color Space  Conversion1' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 38400; vipldws2_B.i++) {
    vipldws2_B.ColorSpaceConversion1[vipldws2_B.i] =
      ((vipldws2_B.Selector_a[vipldws2_B.i] * 0.256788224F + 0.0627451F) +
       vipldws2_B.Selector_a[38400 + vipldws2_B.i] * 0.50412941F) +
      vipldws2_B.Selector_a[76800 + vipldws2_B.i] * 0.0979058817F;
    vipldws2_B.ColorSpaceConversion1[38400 + vipldws2_B.i] =
      ((vipldws2_B.Selector_a[vipldws2_B.i] * -0.148222893F + 0.501960814F) +
       vipldws2_B.Selector_a[38400 + vipldws2_B.i] * -0.290992796F) +
      vipldws2_B.Selector_a[76800 + vipldws2_B.i] * 0.43921569F;
    vipldws2_B.ColorSpaceConversion1[76800 + vipldws2_B.i] =
      ((vipldws2_B.Selector_a[vipldws2_B.i] * 0.43921569F + 0.501960814F) +
       vipldws2_B.Selector_a[38400 + vipldws2_B.i] * -0.367788315F) +
      vipldws2_B.Selector_a[76800 + vipldws2_B.i] * -0.0714273751F;
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
  vipldws2_B.colorAndTypeIdx[0] = 0;
  vipldws2_B.colorAndTypeIdx[1] = 0;

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
  memset(&vipldws2_B.leftC[0], 0, 120U * sizeof(int32_T));
  memset(&vipldws2_B.rightC[0], 0, 120U * sizeof(int32_T));
  memset(&vipldws2_B.Rs[0], 0, 120U * sizeof(int32_T));

  /* twoLines_1b = twoLines_0b+int32(1); */
  /* '<S13>:1:46' twoLines_1b = twoLines_0b; */
  /* '<S13>:1:47' for i=oneI32:int32(length(twoLines_1b(:))) */
  for (vipldws2_B.indxI = 0; vipldws2_B.indxI < 8; vipldws2_B.indxI++) {
    /* '<S13>:1:48' twoLines_1b(i) = twoLines_1b(i) + oneI32; */
    if (vipldws2_B.MatrixConcatenation5[vipldws2_B.indxI] > 2147483646) {
      vipldws2_B.twoLines_1b[vipldws2_B.indxI] = MAX_int32_T;
    } else {
      vipldws2_B.twoLines_1b[vipldws2_B.indxI] =
        vipldws2_B.MatrixConcatenation5[vipldws2_B.indxI] + 1;
    }
  }

  /* '<S13>:1:51' for lineIdx =oneI32:twoI32 */
  /* 1:2 */
  /*     %% one line */
  /* '<S13>:1:53' r1c1r2c2 = twoLines_1b(:,lineIdx); */
  /* '<S13>:1:54' r1 = r1c1r2c2(1); */
  vipldws2_B.r1 = vipldws2_B.twoLines_1b[0];

  /* '<S13>:1:55' c1 = r1c1r2c2(2); */
  vipldws2_B.c1 = vipldws2_B.twoLines_1b[1];

  /* '<S13>:1:56' r2 = r1c1r2c2(3); */
  vipldws2_B.r2 = vipldws2_B.twoLines_1b[2];

  /* '<S13>:1:57' c2 = r1c1r2c2(4); */
  vipldws2_B.c2 = vipldws2_B.twoLines_1b[3];

  /*  make sure r1 is the min (r1,r2) */
  /* '<S13>:1:60' if r1>r2 */
  if (vipldws2_B.twoLines_1b[0] > vipldws2_B.twoLines_1b[2]) {
    /* '<S13>:1:61' tmp=r2; */
    /* '<S13>:1:62' r2=r1; */
    vipldws2_B.r2 = vipldws2_B.twoLines_1b[0];

    /* '<S13>:1:63' r1=tmp; */
    vipldws2_B.r1 = vipldws2_B.twoLines_1b[2];

    /* '<S13>:1:65' tmp=c2; */
    /* '<S13>:1:66' c2=c1; */
    vipldws2_B.c2 = vipldws2_B.twoLines_1b[1];

    /* '<S13>:1:67' c1=tmp; */
    vipldws2_B.c1 = vipldws2_B.twoLines_1b[3];
  }

  /* '<S13>:1:70' pointNotLine = (r1==r2) && (c1==c2); */
  /*  find if line is within image: (r1,c1)  and (r2,c2) must be within image */
  /* '<S13>:1:73' if ((r1>zeroI32 && r1 <= rH) && (c1>zeroI32 && c1 <= cW) && ... */
  /* '<S13>:1:74'         (r2>zeroI32 && r2 <= rH) && (c2>zeroI32 && c2 <= cW)) && ~pointNotLine */
  if (!((vipldws2_B.r1 > 0) && (vipldws2_B.r1 <= 120) && (vipldws2_B.c1 > 0) &&
        (vipldws2_B.c1 <= 320) && (vipldws2_B.r2 > 0) && (vipldws2_B.r2 <= 120) &&
        (vipldws2_B.c2 > 0) && (vipldws2_B.c2 <= 320) && (!((vipldws2_B.r1 ==
          vipldws2_B.r2) && (vipldws2_B.c1 == vipldws2_B.c2))))) {
    /* '<S13>:1:76' else */
    /* '<S13>:1:77' line_within_image = logical(false); */
    done = false;
  } else {
    /* '<S13>:1:75' line_within_image = logical(true); */
  }

  /* '<S13>:1:80' if (line_within_image) */
  if (done) {
    /* '<S13>:1:81' len = r2-r1+oneI32; */
    if ((vipldws2_B.r2 >= 0) && (vipldws2_B.r1 < vipldws2_B.r2 - MAX_int32_T)) {
      vipldws2_B.qY_g = MAX_int32_T;
    } else if ((vipldws2_B.r2 < 0) && (vipldws2_B.r1 > vipldws2_B.r2 -
                MIN_int32_T)) {
      vipldws2_B.qY_g = MIN_int32_T;
    } else {
      vipldws2_B.qY_g = vipldws2_B.r2 - vipldws2_B.r1;
    }

    if (vipldws2_B.qY_g > 2147483646) {
      vipldws2_B.qY_g = MAX_int32_T;
    } else {
      vipldws2_B.qY_g++;
    }

    /* '<S13>:1:82' i=oneI32; */
    vipldws2_B.i = 1;

    /*  Rs(1:len)=r1:r2 */
    /* '<S13>:1:84' for p=r1:r2 */
    while (vipldws2_B.r1 <= vipldws2_B.r2) {
      /* '<S13>:1:85' Rs(i) = p; */
      vipldws2_B.Rs[vipldws2_B.i - 1] = vipldws2_B.r1;

      /* '<S13>:1:86' i=i+oneI32; */
      if (vipldws2_B.i > 2147483646) {
        vipldws2_B.i = MAX_int32_T;
      } else {
        vipldws2_B.i++;
      }

      vipldws2_B.r1++;
    }

    /* leftC(1:len) = int32(linspace(c1-HALF_OFFSET, c2-HALF_OFFSET, len)); */
    /* y = linspace(d1, d2, n) */
    /* y = [d1+(0:n-2)*(d2-d1)/(floor(n)-1) d2]; */
    /* '<S13>:1:92' quotient = (single(c2-c1))/(single(len)-single(1) + single(eps)); */
    if ((vipldws2_B.c2 >= 0) && (vipldws2_B.c1 < vipldws2_B.c2 - MAX_int32_T)) {
      vipldws2_B.c2 = MAX_int32_T;
    } else if ((vipldws2_B.c2 < 0) && (vipldws2_B.c1 > vipldws2_B.c2 -
                MIN_int32_T)) {
      vipldws2_B.c2 = MIN_int32_T;
    } else {
      vipldws2_B.c2 -= vipldws2_B.c1;
    }

    vipldws2_B.scale = (real32_T)vipldws2_B.c2 / (((real32_T)vipldws2_B.qY_g -
      1.0F) + 2.22044605E-16F);

    /* (d2-d1)/(floor(n)-1) */
    /* '<S13>:1:93' for i=oneI32:len */
    vipldws2_B.i = 0;
    while (vipldws2_B.i + 1 <= vipldws2_B.qY_g) {
      /* '<S13>:1:94' leftC(i)  = (c1-HALF_OFFSET) + int32((single(i)-single(1))*quotient); */
      if (vipldws2_B.c1 < -2147483638) {
        vipldws2_B.qY = MIN_int32_T;
      } else {
        vipldws2_B.qY = vipldws2_B.c1 - 10;
      }

      vipldws2_B.cnt = rt_roundf_snf(((real32_T)(vipldws2_B.i + 1) - 1.0F) *
        vipldws2_B.scale);
      if (vipldws2_B.cnt < 2.14748365E+9F) {
        if (vipldws2_B.cnt >= -2.14748365E+9F) {
          vipldws2_B.planeWidth = (int32_T)vipldws2_B.cnt;
        } else {
          vipldws2_B.planeWidth = MIN_int32_T;
        }
      } else if (vipldws2_B.cnt >= 2.14748365E+9F) {
        vipldws2_B.planeWidth = MAX_int32_T;
      } else {
        vipldws2_B.planeWidth = 0;
      }

      if ((vipldws2_B.qY < 0) && (vipldws2_B.planeWidth < MIN_int32_T
           - vipldws2_B.qY)) {
        vipldws2_B.leftC[vipldws2_B.i] = MIN_int32_T;
      } else if ((vipldws2_B.qY > 0) && (vipldws2_B.planeWidth > MAX_int32_T
                  - vipldws2_B.qY)) {
        vipldws2_B.leftC[vipldws2_B.i] = MAX_int32_T;
      } else {
        vipldws2_B.leftC[vipldws2_B.i] = vipldws2_B.qY + vipldws2_B.planeWidth;
      }

      /* '<S13>:1:95' rightC(i) = leftC(i)+ twoI32*HALF_OFFSET; */
      if (vipldws2_B.leftC[vipldws2_B.i] > 2147483627) {
        vipldws2_B.rightC[vipldws2_B.i] = MAX_int32_T;
      } else {
        vipldws2_B.rightC[vipldws2_B.i] = vipldws2_B.leftC[vipldws2_B.i] + 20;
      }

      /* '<S13>:1:96' if leftC(i) < oneI32 */
      if (vipldws2_B.leftC[vipldws2_B.i] < 1) {
        /* '<S13>:1:97' leftC(i) = oneI32; */
        vipldws2_B.leftC[vipldws2_B.i] = 1;

        /* '<S13>:1:98' if rightC(i) < oneI32 */
        if (vipldws2_B.rightC[vipldws2_B.i] < 1) {
          /* '<S13>:1:99' rightC(i) = oneI32; */
          vipldws2_B.rightC[vipldws2_B.i] = 1;
        }
      }

      /* '<S13>:1:102' if rightC(i) > cW */
      if (vipldws2_B.rightC[vipldws2_B.i] > 320) {
        /* '<S13>:1:103' rightC(i) = cW; */
        vipldws2_B.rightC[vipldws2_B.i] = 320;
      }

      vipldws2_B.i++;
    }

    /* '<S13>:1:107' whiteCount  = zeroI32; */
    vipldws2_B.i = 0;

    /* '<S13>:1:108' yellowCount = zeroI32; */
    vipldws2_B.planeOffset = 0;

    /* '<S13>:1:109' grayCount   = zeroI32; */
    vipldws2_B.plane = 0;

    /* '<S13>:1:111' SumOfGotAlLeastOneWhitePixelInTheRow  = zeroI32; */
    vipldws2_B.C2 = 0;

    /* '<S13>:1:112' SumOfGotAlLeastOneYellowPixelInTheRow = zeroI32; */
    vipldws2_B.c2 = 0;

    /* '<S13>:1:114' for i=oneI32:len */
    vipldws2_B.c1 = 0;
    while (vipldws2_B.c1 + 1 <= vipldws2_B.qY_g) {
      /* '<S13>:1:115' gotAlLeastOneWhitePixelInTheRow  = logical(false); */
      done = false;

      /* '<S13>:1:116' gotAlLeastOneYellowPixelInTheRow = logical(false); */
      c_gotAlLeastOneYellowPixelInThe = false;

      /* '<S13>:1:117' for cv = leftC(i):rightC(i) */
      vipldws2_B.r2 = vipldws2_B.leftC[vipldws2_B.c1] - 1;
      while (vipldws2_B.r2 + 1 <= vipldws2_B.rightC[vipldws2_B.c1]) {
        /* '<S13>:1:119' if tmpInImage_Y(Rs(i), cv) >= single(175/255) */
        if (vipldws2_B.ColorSpaceConversion1[(120 * vipldws2_B.r2 +
             vipldws2_B.Rs[vipldws2_B.c1]) - 1] >= 0.686274529F) {
          /* '<S13>:1:120' whiteCount = whiteCount+oneI32; */
          if (vipldws2_B.i > 2147483646) {
            vipldws2_B.i = MAX_int32_T;
          } else {
            vipldws2_B.i++;
          }

          /* '<S13>:1:121' gotAlLeastOneWhitePixelInTheRow = logical(true); */
          done = true;
        } else if (vipldws2_B.ColorSpaceConversion1[(120 * vipldws2_B.r2 +
                    vipldws2_B.Rs[vipldws2_B.c1]) + 38399] >= 0.352941185F) {
          if (vipldws2_B.ColorSpaceConversion1[(120 * vipldws2_B.r2 +
               vipldws2_B.Rs[vipldws2_B.c1]) + 38399] <= 0.498039216F) {
            /* '<S13>:1:122' elseif tmpInImage_Cb(Rs(i), cv) >= single(90/255) && tmpInImage_Cb(Rs(i), cv) <= single(127/255) */
            /* '<S13>:1:123' yellowCount = yellowCount+oneI32; */
            if (vipldws2_B.planeOffset > 2147483646) {
              vipldws2_B.planeOffset = MAX_int32_T;
            } else {
              vipldws2_B.planeOffset++;
            }

            /* '<S13>:1:124' gotAlLeastOneYellowPixelInTheRow = logical(true); */
            c_gotAlLeastOneYellowPixelInThe = true;
          } else {
            /* '<S13>:1:125' else */
            /* '<S13>:1:126' grayCount = grayCount+oneI32; */
            if (vipldws2_B.plane > 2147483646) {
              vipldws2_B.plane = MAX_int32_T;
            } else {
              vipldws2_B.plane++;
            }
          }
        } else {
          /* '<S13>:1:125' else */
          /* '<S13>:1:126' grayCount = grayCount+oneI32; */
          if (vipldws2_B.plane > 2147483646) {
            vipldws2_B.plane = MAX_int32_T;
          } else {
            vipldws2_B.plane++;
          }
        }

        vipldws2_B.r2++;
      }

      /* '<S13>:1:129' if gotAlLeastOneWhitePixelInTheRow */
      if (done) {
        /* '<S13>:1:130' SumOfGotAlLeastOneWhitePixelInTheRow = SumOfGotAlLeastOneWhitePixelInTheRow+oneI32; */
        if (vipldws2_B.C2 > 2147483646) {
          vipldws2_B.C2 = MAX_int32_T;
        } else {
          vipldws2_B.C2++;
        }
      }

      /* '<S13>:1:132' if gotAlLeastOneYellowPixelInTheRow */
      if (c_gotAlLeastOneYellowPixelInThe) {
        /* '<S13>:1:133' SumOfGotAlLeastOneYellowPixelInTheRow = SumOfGotAlLeastOneYellowPixelInTheRow+oneI32; */
        if (vipldws2_B.c2 > 2147483646) {
          vipldws2_B.c2 = MAX_int32_T;
        } else {
          vipldws2_B.c2++;
        }
      }

      vipldws2_B.c1++;
    }

    /* '<S13>:1:137' yellowVsTotal = single(yellowCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:138' whiteVsTotal  = single(whiteCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:140' if yellowVsTotal > whiteVsTotal */
    if ((vipldws2_B.plane < 0) && (vipldws2_B.planeOffset < MIN_int32_T
         - vipldws2_B.plane)) {
      vipldws2_B.qY = MIN_int32_T;
      vipldws2_B.c1 = MIN_int32_T;
    } else if ((vipldws2_B.plane > 0) && (vipldws2_B.planeOffset > MAX_int32_T -
                vipldws2_B.plane)) {
      vipldws2_B.qY = MAX_int32_T;
      vipldws2_B.c1 = MAX_int32_T;
    } else {
      vipldws2_B.qY = vipldws2_B.plane + vipldws2_B.planeOffset;
      vipldws2_B.c1 = vipldws2_B.plane + vipldws2_B.planeOffset;
    }

    if ((vipldws2_B.qY < 0) && (vipldws2_B.i < MIN_int32_T - vipldws2_B.qY)) {
      vipldws2_B.qY = MIN_int32_T;
    } else if ((vipldws2_B.qY > 0) && (vipldws2_B.i > MAX_int32_T
                - vipldws2_B.qY)) {
      vipldws2_B.qY = MAX_int32_T;
    } else {
      vipldws2_B.qY += vipldws2_B.i;
    }

    if ((vipldws2_B.c1 < 0) && (vipldws2_B.i < MIN_int32_T - vipldws2_B.c1)) {
      vipldws2_B.c1 = MIN_int32_T;
    } else if ((vipldws2_B.c1 > 0) && (vipldws2_B.i > MAX_int32_T
                - vipldws2_B.c1)) {
      vipldws2_B.c1 = MAX_int32_T;
    } else {
      vipldws2_B.c1 += vipldws2_B.i;
    }

    if ((real32_T)vipldws2_B.planeOffset / (real32_T)vipldws2_B.qY > (real32_T)
        vipldws2_B.i / (real32_T)vipldws2_B.c1) {
      /* '<S13>:1:141' lineColorIdx(lineIdx) = YELLOW_COLOR; */
      lineColorIdx_idx_0 = 2;

      /* '<S13>:1:142' linearPixelRatio = single(SumOfGotAlLeastOneYellowPixelInTheRow)/single(len); */
      vipldws2_B.scale = (real32_T)vipldws2_B.c2 / (real32_T)vipldws2_B.qY_g;
    } else {
      /* '<S13>:1:143' else */
      /* '<S13>:1:144' lineColorIdx(lineIdx) = WHITE_COLOR; */
      lineColorIdx_idx_0 = 1;

      /* '<S13>:1:145' linearPixelRatio = single(SumOfGotAlLeastOneWhitePixelInTheRow)/single(len); */
      vipldws2_B.scale = (real32_T)vipldws2_B.C2 / (real32_T)vipldws2_B.qY_g;
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
    if (vipldws2_B.scale > 0.8F) {
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
      vipldws2_B.colorAndTypeIdx[0] = 1;
    } else if ((lineColorIdx_idx_0 == 2) && (solidBrokenIdx_idx_0 == 2)) {
      /* '<S13>:1:165' elseif (lineColorIdx(lineIdx) == YELLOW_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
      /* '<S13>:1:166' colorAndTypeIdx(lineIdx) = YELLOW_SOLID; */
      vipldws2_B.colorAndTypeIdx[0] = 2;
    } else if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 1)) {
      /* '<S13>:1:167' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == BROKEN_MARKING) */
      /* '<S13>:1:168' colorAndTypeIdx(lineIdx) = WHITE_BROKEN; */
      vipldws2_B.colorAndTypeIdx[0] = 3;
    } else {
      if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 2)) {
        /* '<S13>:1:169' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
        /* '<S13>:1:170' colorAndTypeIdx(lineIdx) = WHITE_SOLID; */
        vipldws2_B.colorAndTypeIdx[0] = 4;
      }
    }
  } else {
    /* '<S13>:1:173' else */
    /* '<S13>:1:174' lineColorIdx(lineIdx) = INVALID_COLOR; */
    /* '<S13>:1:175' solidBrokenIdx(lineIdx) = INVALID_MARKING; */
    /* '<S13>:1:176' colorAndTypeIdx(lineIdx) = INVALID_COLOR_OR_TYPE; */
    vipldws2_B.colorAndTypeIdx[0] = 0;
  }

  /* 1:2 */
  /*     %% one line */
  /* '<S13>:1:53' r1c1r2c2 = twoLines_1b(:,lineIdx); */
  /* '<S13>:1:54' r1 = r1c1r2c2(1); */
  vipldws2_B.r1 = vipldws2_B.twoLines_1b[4];

  /* '<S13>:1:55' c1 = r1c1r2c2(2); */
  vipldws2_B.c1 = vipldws2_B.twoLines_1b[5];

  /* '<S13>:1:56' r2 = r1c1r2c2(3); */
  vipldws2_B.r2 = vipldws2_B.twoLines_1b[6];

  /* '<S13>:1:57' c2 = r1c1r2c2(4); */
  vipldws2_B.c2 = vipldws2_B.twoLines_1b[7];

  /*  make sure r1 is the min (r1,r2) */
  /* '<S13>:1:60' if r1>r2 */
  if (vipldws2_B.twoLines_1b[4] > vipldws2_B.twoLines_1b[6]) {
    /* '<S13>:1:61' tmp=r2; */
    /* '<S13>:1:62' r2=r1; */
    vipldws2_B.r2 = vipldws2_B.twoLines_1b[4];

    /* '<S13>:1:63' r1=tmp; */
    vipldws2_B.r1 = vipldws2_B.twoLines_1b[6];

    /* '<S13>:1:65' tmp=c2; */
    /* '<S13>:1:66' c2=c1; */
    vipldws2_B.c2 = vipldws2_B.twoLines_1b[5];

    /* '<S13>:1:67' c1=tmp; */
    vipldws2_B.c1 = vipldws2_B.twoLines_1b[7];
  }

  /* '<S13>:1:70' pointNotLine = (r1==r2) && (c1==c2); */
  /*  find if line is within image: (r1,c1)  and (r2,c2) must be within image */
  /* '<S13>:1:73' if ((r1>zeroI32 && r1 <= rH) && (c1>zeroI32 && c1 <= cW) && ... */
  /* '<S13>:1:74'         (r2>zeroI32 && r2 <= rH) && (c2>zeroI32 && c2 <= cW)) && ~pointNotLine */
  if ((vipldws2_B.r1 > 0) && (vipldws2_B.r1 <= 120) && (vipldws2_B.c1 > 0) &&
      (vipldws2_B.c1 <= 320) && (vipldws2_B.r2 > 0) && (vipldws2_B.r2 <= 120) &&
      (vipldws2_B.c2 > 0) && (vipldws2_B.c2 <= 320) && (!((vipldws2_B.r1 ==
         vipldws2_B.r2) && (vipldws2_B.c1 == vipldws2_B.c2)))) {
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
    if ((vipldws2_B.r2 >= 0) && (vipldws2_B.r1 < vipldws2_B.r2 - MAX_int32_T)) {
      vipldws2_B.qY_g = MAX_int32_T;
    } else if ((vipldws2_B.r2 < 0) && (vipldws2_B.r1 > vipldws2_B.r2 -
                MIN_int32_T)) {
      vipldws2_B.qY_g = MIN_int32_T;
    } else {
      vipldws2_B.qY_g = vipldws2_B.r2 - vipldws2_B.r1;
    }

    if (vipldws2_B.qY_g > 2147483646) {
      vipldws2_B.qY_g = MAX_int32_T;
    } else {
      vipldws2_B.qY_g++;
    }

    /* '<S13>:1:82' i=oneI32; */
    vipldws2_B.i = 1;

    /*  Rs(1:len)=r1:r2 */
    /* '<S13>:1:84' for p=r1:r2 */
    while (vipldws2_B.r1 <= vipldws2_B.r2) {
      /* '<S13>:1:85' Rs(i) = p; */
      vipldws2_B.Rs[vipldws2_B.i - 1] = vipldws2_B.r1;

      /* '<S13>:1:86' i=i+oneI32; */
      if (vipldws2_B.i > 2147483646) {
        vipldws2_B.i = MAX_int32_T;
      } else {
        vipldws2_B.i++;
      }

      vipldws2_B.r1++;
    }

    /* leftC(1:len) = int32(linspace(c1-HALF_OFFSET, c2-HALF_OFFSET, len)); */
    /* y = linspace(d1, d2, n) */
    /* y = [d1+(0:n-2)*(d2-d1)/(floor(n)-1) d2]; */
    /* '<S13>:1:92' quotient = (single(c2-c1))/(single(len)-single(1) + single(eps)); */
    if ((vipldws2_B.c2 >= 0) && (vipldws2_B.c1 < vipldws2_B.c2 - MAX_int32_T)) {
      vipldws2_B.c2 = MAX_int32_T;
    } else if ((vipldws2_B.c2 < 0) && (vipldws2_B.c1 > vipldws2_B.c2 -
                MIN_int32_T)) {
      vipldws2_B.c2 = MIN_int32_T;
    } else {
      vipldws2_B.c2 -= vipldws2_B.c1;
    }

    vipldws2_B.scale = (real32_T)vipldws2_B.c2 / (((real32_T)vipldws2_B.qY_g -
      1.0F) + 2.22044605E-16F);

    /* (d2-d1)/(floor(n)-1) */
    /* '<S13>:1:93' for i=oneI32:len */
    vipldws2_B.i = 0;
    while (vipldws2_B.i + 1 <= vipldws2_B.qY_g) {
      /* '<S13>:1:94' leftC(i)  = (c1-HALF_OFFSET) + int32((single(i)-single(1))*quotient); */
      if (vipldws2_B.c1 < -2147483638) {
        vipldws2_B.qY = MIN_int32_T;
      } else {
        vipldws2_B.qY = vipldws2_B.c1 - 10;
      }

      vipldws2_B.cnt = rt_roundf_snf(((real32_T)(vipldws2_B.i + 1) - 1.0F) *
        vipldws2_B.scale);
      if (vipldws2_B.cnt < 2.14748365E+9F) {
        if (vipldws2_B.cnt >= -2.14748365E+9F) {
          vipldws2_B.planeWidth = (int32_T)vipldws2_B.cnt;
        } else {
          vipldws2_B.planeWidth = MIN_int32_T;
        }
      } else if (vipldws2_B.cnt >= 2.14748365E+9F) {
        vipldws2_B.planeWidth = MAX_int32_T;
      } else {
        vipldws2_B.planeWidth = 0;
      }

      if ((vipldws2_B.qY < 0) && (vipldws2_B.planeWidth < MIN_int32_T
           - vipldws2_B.qY)) {
        vipldws2_B.leftC[vipldws2_B.i] = MIN_int32_T;
      } else if ((vipldws2_B.qY > 0) && (vipldws2_B.planeWidth > MAX_int32_T
                  - vipldws2_B.qY)) {
        vipldws2_B.leftC[vipldws2_B.i] = MAX_int32_T;
      } else {
        vipldws2_B.leftC[vipldws2_B.i] = vipldws2_B.qY + vipldws2_B.planeWidth;
      }

      /* '<S13>:1:95' rightC(i) = leftC(i)+ twoI32*HALF_OFFSET; */
      if (vipldws2_B.leftC[vipldws2_B.i] > 2147483627) {
        vipldws2_B.rightC[vipldws2_B.i] = MAX_int32_T;
      } else {
        vipldws2_B.rightC[vipldws2_B.i] = vipldws2_B.leftC[vipldws2_B.i] + 20;
      }

      /* '<S13>:1:96' if leftC(i) < oneI32 */
      if (vipldws2_B.leftC[vipldws2_B.i] < 1) {
        /* '<S13>:1:97' leftC(i) = oneI32; */
        vipldws2_B.leftC[vipldws2_B.i] = 1;

        /* '<S13>:1:98' if rightC(i) < oneI32 */
        if (vipldws2_B.rightC[vipldws2_B.i] < 1) {
          /* '<S13>:1:99' rightC(i) = oneI32; */
          vipldws2_B.rightC[vipldws2_B.i] = 1;
        }
      }

      /* '<S13>:1:102' if rightC(i) > cW */
      if (vipldws2_B.rightC[vipldws2_B.i] > 320) {
        /* '<S13>:1:103' rightC(i) = cW; */
        vipldws2_B.rightC[vipldws2_B.i] = 320;
      }

      vipldws2_B.i++;
    }

    /* '<S13>:1:107' whiteCount  = zeroI32; */
    vipldws2_B.i = 0;

    /* '<S13>:1:108' yellowCount = zeroI32; */
    vipldws2_B.planeOffset = 0;

    /* '<S13>:1:109' grayCount   = zeroI32; */
    vipldws2_B.plane = 0;

    /* '<S13>:1:111' SumOfGotAlLeastOneWhitePixelInTheRow  = zeroI32; */
    vipldws2_B.C2 = 0;

    /* '<S13>:1:112' SumOfGotAlLeastOneYellowPixelInTheRow = zeroI32; */
    vipldws2_B.c2 = 0;

    /* '<S13>:1:114' for i=oneI32:len */
    vipldws2_B.c1 = 0;
    while (vipldws2_B.c1 + 1 <= vipldws2_B.qY_g) {
      /* '<S13>:1:115' gotAlLeastOneWhitePixelInTheRow  = logical(false); */
      done = false;

      /* '<S13>:1:116' gotAlLeastOneYellowPixelInTheRow = logical(false); */
      c_gotAlLeastOneYellowPixelInThe = false;

      /* '<S13>:1:117' for cv = leftC(i):rightC(i) */
      vipldws2_B.r2 = vipldws2_B.leftC[vipldws2_B.c1] - 1;
      while (vipldws2_B.r2 + 1 <= vipldws2_B.rightC[vipldws2_B.c1]) {
        /* '<S13>:1:119' if tmpInImage_Y(Rs(i), cv) >= single(175/255) */
        if (vipldws2_B.ColorSpaceConversion1[(120 * vipldws2_B.r2 +
             vipldws2_B.Rs[vipldws2_B.c1]) - 1] >= 0.686274529F) {
          /* '<S13>:1:120' whiteCount = whiteCount+oneI32; */
          if (vipldws2_B.i > 2147483646) {
            vipldws2_B.i = MAX_int32_T;
          } else {
            vipldws2_B.i++;
          }

          /* '<S13>:1:121' gotAlLeastOneWhitePixelInTheRow = logical(true); */
          done = true;
        } else if (vipldws2_B.ColorSpaceConversion1[(120 * vipldws2_B.r2 +
                    vipldws2_B.Rs[vipldws2_B.c1]) + 38399] >= 0.352941185F) {
          if (vipldws2_B.ColorSpaceConversion1[(120 * vipldws2_B.r2 +
               vipldws2_B.Rs[vipldws2_B.c1]) + 38399] <= 0.498039216F) {
            /* '<S13>:1:122' elseif tmpInImage_Cb(Rs(i), cv) >= single(90/255) && tmpInImage_Cb(Rs(i), cv) <= single(127/255) */
            /* '<S13>:1:123' yellowCount = yellowCount+oneI32; */
            if (vipldws2_B.planeOffset > 2147483646) {
              vipldws2_B.planeOffset = MAX_int32_T;
            } else {
              vipldws2_B.planeOffset++;
            }

            /* '<S13>:1:124' gotAlLeastOneYellowPixelInTheRow = logical(true); */
            c_gotAlLeastOneYellowPixelInThe = true;
          } else {
            /* '<S13>:1:125' else */
            /* '<S13>:1:126' grayCount = grayCount+oneI32; */
            if (vipldws2_B.plane > 2147483646) {
              vipldws2_B.plane = MAX_int32_T;
            } else {
              vipldws2_B.plane++;
            }
          }
        } else {
          /* '<S13>:1:125' else */
          /* '<S13>:1:126' grayCount = grayCount+oneI32; */
          if (vipldws2_B.plane > 2147483646) {
            vipldws2_B.plane = MAX_int32_T;
          } else {
            vipldws2_B.plane++;
          }
        }

        vipldws2_B.r2++;
      }

      /* '<S13>:1:129' if gotAlLeastOneWhitePixelInTheRow */
      if (done) {
        /* '<S13>:1:130' SumOfGotAlLeastOneWhitePixelInTheRow = SumOfGotAlLeastOneWhitePixelInTheRow+oneI32; */
        if (vipldws2_B.C2 > 2147483646) {
          vipldws2_B.C2 = MAX_int32_T;
        } else {
          vipldws2_B.C2++;
        }
      }

      /* '<S13>:1:132' if gotAlLeastOneYellowPixelInTheRow */
      if (c_gotAlLeastOneYellowPixelInThe) {
        /* '<S13>:1:133' SumOfGotAlLeastOneYellowPixelInTheRow = SumOfGotAlLeastOneYellowPixelInTheRow+oneI32; */
        if (vipldws2_B.c2 > 2147483646) {
          vipldws2_B.c2 = MAX_int32_T;
        } else {
          vipldws2_B.c2++;
        }
      }

      vipldws2_B.c1++;
    }

    /* '<S13>:1:137' yellowVsTotal = single(yellowCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:138' whiteVsTotal  = single(whiteCount)/single(grayCount+yellowCount+whiteCount); */
    /* '<S13>:1:140' if yellowVsTotal > whiteVsTotal */
    if ((vipldws2_B.plane < 0) && (vipldws2_B.planeOffset < MIN_int32_T
         - vipldws2_B.plane)) {
      vipldws2_B.qY = MIN_int32_T;
      vipldws2_B.c1 = MIN_int32_T;
    } else if ((vipldws2_B.plane > 0) && (vipldws2_B.planeOffset > MAX_int32_T -
                vipldws2_B.plane)) {
      vipldws2_B.qY = MAX_int32_T;
      vipldws2_B.c1 = MAX_int32_T;
    } else {
      vipldws2_B.qY = vipldws2_B.plane + vipldws2_B.planeOffset;
      vipldws2_B.c1 = vipldws2_B.plane + vipldws2_B.planeOffset;
    }

    if ((vipldws2_B.qY < 0) && (vipldws2_B.i < MIN_int32_T - vipldws2_B.qY)) {
      vipldws2_B.qY = MIN_int32_T;
    } else if ((vipldws2_B.qY > 0) && (vipldws2_B.i > MAX_int32_T
                - vipldws2_B.qY)) {
      vipldws2_B.qY = MAX_int32_T;
    } else {
      vipldws2_B.qY += vipldws2_B.i;
    }

    if ((vipldws2_B.c1 < 0) && (vipldws2_B.i < MIN_int32_T - vipldws2_B.c1)) {
      vipldws2_B.c1 = MIN_int32_T;
    } else if ((vipldws2_B.c1 > 0) && (vipldws2_B.i > MAX_int32_T
                - vipldws2_B.c1)) {
      vipldws2_B.c1 = MAX_int32_T;
    } else {
      vipldws2_B.c1 += vipldws2_B.i;
    }

    if ((real32_T)vipldws2_B.planeOffset / (real32_T)vipldws2_B.qY > (real32_T)
        vipldws2_B.i / (real32_T)vipldws2_B.c1) {
      /* '<S13>:1:141' lineColorIdx(lineIdx) = YELLOW_COLOR; */
      lineColorIdx_idx_0 = 2;

      /* '<S13>:1:142' linearPixelRatio = single(SumOfGotAlLeastOneYellowPixelInTheRow)/single(len); */
      vipldws2_B.scale = (real32_T)vipldws2_B.c2 / (real32_T)vipldws2_B.qY_g;
    } else {
      /* '<S13>:1:143' else */
      /* '<S13>:1:144' lineColorIdx(lineIdx) = WHITE_COLOR; */
      lineColorIdx_idx_0 = 1;

      /* '<S13>:1:145' linearPixelRatio = single(SumOfGotAlLeastOneWhitePixelInTheRow)/single(len); */
      vipldws2_B.scale = (real32_T)vipldws2_B.C2 / (real32_T)vipldws2_B.qY_g;
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
    if (vipldws2_B.scale > 0.8F) {
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
      vipldws2_B.colorAndTypeIdx[1] = 1;
    } else if ((lineColorIdx_idx_0 == 2) && (solidBrokenIdx_idx_0 == 2)) {
      /* '<S13>:1:165' elseif (lineColorIdx(lineIdx) == YELLOW_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
      /* '<S13>:1:166' colorAndTypeIdx(lineIdx) = YELLOW_SOLID; */
      vipldws2_B.colorAndTypeIdx[1] = 2;
    } else if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 1)) {
      /* '<S13>:1:167' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == BROKEN_MARKING) */
      /* '<S13>:1:168' colorAndTypeIdx(lineIdx) = WHITE_BROKEN; */
      vipldws2_B.colorAndTypeIdx[1] = 3;
    } else {
      if ((lineColorIdx_idx_0 == 1) && (solidBrokenIdx_idx_0 == 2)) {
        /* '<S13>:1:169' elseif (lineColorIdx(lineIdx) == WHITE_COLOR) && (solidBrokenIdx(lineIdx) == SOLID_MARKING) */
        /* '<S13>:1:170' colorAndTypeIdx(lineIdx) = WHITE_SOLID; */
        vipldws2_B.colorAndTypeIdx[1] = 4;
      }
    }
  } else {
    /* '<S13>:1:173' else */
    /* '<S13>:1:174' lineColorIdx(lineIdx) = INVALID_COLOR; */
    /* '<S13>:1:175' solidBrokenIdx(lineIdx) = INVALID_MARKING; */
    /* '<S13>:1:176' colorAndTypeIdx(lineIdx) = INVALID_COLOR_OR_TYPE; */
    vipldws2_B.colorAndTypeIdx[1] = 0;
  }

  /* End of MATLAB Function: '<S6>/DetectColorAndType1' */

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  vipldws2_B.Compare_d = (vipldws2_B.outMsg ==
    vipldws2_P.CompareToConstant2_const_h);

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (vipldws2_B.Compare_d) {
    vipldws2_B.Bias_h = vipldws2_P.Constant_Value_f;
  } else {
    vipldws2_B.Bias_h = vipldws2_P.Constant1_Value_b;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* Selector: '<S6>/Selector' */
  vipldws2_B.Bias_h = vipldws2_B.colorAndTypeIdx[vipldws2_B.Bias_h];

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  vipldws2_B.Compare_d = (vipldws2_B.Bias_h ==
    vipldws2_P.CompareToConstant_const_n);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  vipldws2_B.Switch_h = (vipldws2_B.Bias_h ==
    vipldws2_P.CompareToConstant3_const);

  /* Logic: '<S6>/Logical Operator4' */
  vipldws2_B.LogicalOperator4 = (vipldws2_B.Compare_d || vipldws2_B.Switch_h);

  /* DataTypeConversion: '<S8>/Data Type  Conversion' */
  vipldws2_B.Saturation_d = vipldws2_B.outMsg;

  /* Selector: '<S8>/Selector' incorporates:
   *  Constant: '<S8>/Constant'
   */
  vipldws2_B.Selector_h = vipldws2_P.Constant_Value_j[vipldws2_B.Saturation_d];

  /* Outputs for Triggered SubSystem: '<S6>/Sample and Hold' incorporates:
   *  TriggerPort: '<S15>/Trigger'
   */
  vipldws2_B.zcEvent = rt_I32ZCFcn(ANY_ZERO_CROSSING,
    &vipldws2_PrevZCX.SampleandHold_Trig_ZCE,
    (vipldws2_B.Selector_h));
  if (vipldws2_B.zcEvent != NO_ZCEVENT) {
    /* Inport: '<S15>/In' */
    vipldws2_B.In = vipldws2_B.LogicalOperator4;
    vipldws2_DW.SampleandHold_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S6>/Sample and Hold' */

  /* Logic: '<S6>/Logical Operator2' */
  vipldws2_B.LogicalOperator2_n = (vipldws2_B.LogicalOperator2_n &&
    vipldws2_B.In);

  /* Logic: '<S5>/Logical Operator2' */
  vipldws2_B.LogicalOperator2 = (vipldws2_B.Compare_ni &&
    vipldws2_B.LogicalOperator2_n);

  /* S-Function (sdspmultiportsel): '<S16>/Multiport Selector' */
  vipldws2_B.MultiportSelector_o1[0] = vipldws2_B.MatrixConcatenation5[0];
  vipldws2_B.MultiportSelector_o1[1] = vipldws2_B.MatrixConcatenation5[4];
  vipldws2_B.MultiportSelector_o2[0] = vipldws2_B.MatrixConcatenation5[2];
  vipldws2_B.MultiportSelector_o2[1] = vipldws2_B.MatrixConcatenation5[6];
  vipldws2_B.MultiportSelector_o3[0] = vipldws2_B.MatrixConcatenation5[1];
  vipldws2_B.MultiportSelector_o3[1] = vipldws2_B.MatrixConcatenation5[5];
  vipldws2_B.MultiportSelector_o4[0] = vipldws2_B.MatrixConcatenation5[3];

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  vipldws2_B.LogicalOperator7[0] = (vipldws2_B.MultiportSelector_o1[0] >=
    vipldws2_P.CompareToConstant10_const);

  /* RelationalOperator: '<S16>/Relational Operator' */
  vipldws2_B.LogicalOperator8[0] = (vipldws2_B.MultiportSelector_o1[0] !=
    vipldws2_B.MultiportSelector_o2[0]);

  /* RelationalOperator: '<S16>/Relational Operator1' */
  vipldws2_B.Compare_g[0] = (vipldws2_B.MultiportSelector_o3[0] !=
    vipldws2_B.MultiportSelector_o4[0]);

  /* Logic: '<S16>/Logical Operator8' */
  vipldws2_B.LogicalOperator8[0] = (vipldws2_B.LogicalOperator8[0] ||
    vipldws2_B.Compare_g[0]);

  /* Sum: '<S16>/Add' */
  vipldws2_B.Bias2[0] = vipldws2_B.MultiportSelector_o1[0] -
    vipldws2_B.MultiportSelector_o2[0];

  /* Abs: '<S16>/Abs' */
  if (vipldws2_B.Bias2[0] < 0) {
    vipldws2_B.Bias2[0] = -vipldws2_B.Bias2[0];
  }

  /* Sum: '<S16>/Add1' */
  vipldws2_B.Transpose2[0] = vipldws2_B.MultiportSelector_o3[0] -
    vipldws2_B.MultiportSelector_o4[0];

  /* Abs: '<S16>/Abs1' */
  if (vipldws2_B.Transpose2[0] < 0) {
    vipldws2_B.Transpose2[0] = -vipldws2_B.Transpose2[0];
  }

  /* Sum: '<S16>/Add2' */
  vipldws2_B.Bias2[0] += vipldws2_B.Transpose2[0];

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  vipldws2_B.Compare_g[0] = (vipldws2_B.Bias2[0] >=
    vipldws2_P.CompareToConstant1_const_o);

  /* Logic: '<S16>/Logical Operator7' */
  vipldws2_B.LogicalOperator7[0] = (vipldws2_B.LogicalOperator7[0] &&
    vipldws2_B.LogicalOperator8[0] && vipldws2_B.Compare_g[0]);

  /* S-Function (sdspmultiportsel): '<S16>/Multiport Selector' */
  vipldws2_B.MultiportSelector_o4[1] = vipldws2_B.MatrixConcatenation5[7];

  /* RelationalOperator: '<S19>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   */
  vipldws2_B.LogicalOperator7[1] = (vipldws2_B.MultiportSelector_o1[1] >=
    vipldws2_P.CompareToConstant10_const);

  /* RelationalOperator: '<S16>/Relational Operator' */
  vipldws2_B.LogicalOperator8[1] = (vipldws2_B.MultiportSelector_o1[1] !=
    vipldws2_B.MultiportSelector_o2[1]);

  /* RelationalOperator: '<S16>/Relational Operator1' */
  vipldws2_B.Compare_g[1] = (vipldws2_B.MultiportSelector_o3[1] !=
    vipldws2_B.MultiportSelector_o4[1]);

  /* Logic: '<S16>/Logical Operator8' */
  vipldws2_B.LogicalOperator8[1] = (vipldws2_B.LogicalOperator8[1] ||
    vipldws2_B.Compare_g[1]);

  /* Sum: '<S16>/Add' */
  vipldws2_B.Bias2[1] = vipldws2_B.MultiportSelector_o1[1] -
    vipldws2_B.MultiportSelector_o2[1];

  /* Abs: '<S16>/Abs' */
  if (vipldws2_B.Bias2[1] < 0) {
    vipldws2_B.Bias2[1] = -vipldws2_B.Bias2[1];
  }

  /* Sum: '<S16>/Add1' */
  vipldws2_B.Transpose2[1] = vipldws2_B.MultiportSelector_o3[1] -
    vipldws2_B.MultiportSelector_o4[1];

  /* Abs: '<S16>/Abs1' */
  if (vipldws2_B.Transpose2[1] < 0) {
    vipldws2_B.Transpose2[1] = -vipldws2_B.Transpose2[1];
  }

  /* Sum: '<S16>/Add2' */
  vipldws2_B.Bias2[1] += vipldws2_B.Transpose2[1];

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  vipldws2_B.Compare_g[1] = (vipldws2_B.Bias2[1] >=
    vipldws2_P.CompareToConstant1_const_o);

  /* Logic: '<S16>/Logical Operator7' */
  vipldws2_B.LogicalOperator7[1] = (vipldws2_B.LogicalOperator7[1] &&
    vipldws2_B.LogicalOperator8[1] && vipldws2_B.Compare_g[1]);

  /* S-Function (sdspmultiportsel): '<S16>/Multiport Selector1' */
  vipldws2_B.MultiportSelector1_o1 = vipldws2_B.LogicalOperator7[0];
  vipldws2_B.MultiportSelector1_o2 = vipldws2_B.LogicalOperator7[1];

  /* Logic: '<S16>/Logical Operator' */
  vipldws2_B.Switch_h = (vipldws2_B.MultiportSelector1_o1 &&
    vipldws2_B.MultiportSelector1_o2);

  /* Logic: '<S6>/Logical Operator' */
  vipldws2_B.LogicalOperator_b = (vipldws2_B.LogicalOperator_b &&
    vipldws2_B.RelationalOperator1);

  /* Logic: '<S6>/Logical Operator1' */
  vipldws2_B.LogicalOperator1 = (vipldws2_B.Switch_h &&
    vipldws2_B.LogicalOperator_b);

  /* MATLAB Function: '<S5>/Exclude 3rd Lane' */
  /*  Exclude third (left or right lane) if it is very close to the other lane  */
  /*  already detected and tracked by Kalman filter. */
  /* MATLAB Function 'Output/Exclude 3rd Lane': '<S66>:1' */
  /* '<S66>:1:6' [rH cW] = size(RefImg(:,:,1)); */
  /* '<S66>:1:7' out3rdLane = in3rdLane; */
  vipldws2_B.out3rdLane[0] = vipldws2_B.Switch1_b[0];
  vipldws2_B.out3rdLane[1] = vipldws2_B.Switch1_b[1];
  vipldws2_B.out3rdLane[2] = vipldws2_B.Switch1_b[2];
  vipldws2_B.out3rdLane[3] = vipldws2_B.Switch1_b[3];

  /* '<S66>:1:9' if (Show3rdLane && twoLanesFlag) */
  if (vipldws2_B.LogicalOperator2 && vipldws2_B.LogicalOperator1) {
    /* '<S66>:1:10' R1C1R2C2 = in3rdLane; */
    /* '<S66>:1:11' R1 = R1C1R2C2(1)+int32(1); */
    if (vipldws2_B.Switch1_b[0] > 2147483646) {
      vipldws2_B.planeWidth = MAX_int32_T;
    } else {
      vipldws2_B.planeWidth = vipldws2_B.Switch1_b[0] + 1;
    }

    /* '<S66>:1:12' C1 = R1C1R2C2(2)+int32(1); */
    if (vipldws2_B.Switch1_b[1] > 2147483646) {
      vipldws2_B.planeOffset = MAX_int32_T;
    } else {
      vipldws2_B.planeOffset = vipldws2_B.Switch1_b[1] + 1;
    }

    /* '<S66>:1:13' R2 = R1C1R2C2(3)+int32(1); */
    if (vipldws2_B.Switch1_b[2] > 2147483646) {
      vipldws2_B.qY_g = MAX_int32_T;
    } else {
      vipldws2_B.qY_g = vipldws2_B.Switch1_b[2] + 1;
    }

    vipldws2_B.plane = vipldws2_B.qY_g;

    /* '<S66>:1:14' C2 = R1C1R2C2(4)+int32(1); */
    if (vipldws2_B.Switch1_b[3] > 2147483646) {
      vipldws2_B.qY = MAX_int32_T;
    } else {
      vipldws2_B.qY = vipldws2_B.Switch1_b[3] + 1;
    }

    vipldws2_B.C2 = vipldws2_B.qY;

    /*  make sure R1 is the min(R1,R2) */
    /* '<S66>:1:16' if R1>R2 */
    if (vipldws2_B.planeWidth > vipldws2_B.qY_g) {
      /* '<S66>:1:17' TMP=R2; */
      /* '<S66>:1:18' R2=R1; */
      vipldws2_B.plane = vipldws2_B.planeWidth;

      /* '<S66>:1:19' R1=TMP; */
      vipldws2_B.planeWidth = vipldws2_B.qY_g;

      /* '<S66>:1:21' TMP=C2; */
      /* '<S66>:1:22' C2=C1; */
      vipldws2_B.C2 = vipldws2_B.planeOffset;

      /* '<S66>:1:23' C1=TMP; */
      vipldws2_B.planeOffset = vipldws2_B.qY;
    }

    /* '<S66>:1:26' for lineIdx =1:2 */
    for (vipldws2_B.indxI = 0; vipldws2_B.indxI < 2; vipldws2_B.indxI++) {
      /* '<S66>:1:28' r1c1r2c2 = mainTwoLanes(:,lineIdx); */
      /* '<S66>:1:29' r1 = r1c1r2c2(1)+int32(1); */
      if (vipldws2_B.MatrixConcatenation5[vipldws2_B.indxI << 2] > 2147483646) {
        vipldws2_B.r1 = MAX_int32_T;
      } else {
        vipldws2_B.r1 = vipldws2_B.MatrixConcatenation5[vipldws2_B.indxI << 2] +
          1;
      }

      /* '<S66>:1:30' c1 = r1c1r2c2(2)+int32(1); */
      if (vipldws2_B.MatrixConcatenation5[(vipldws2_B.indxI << 2) + 1] >
          2147483646) {
        vipldws2_B.c1 = MAX_int32_T;
      } else {
        vipldws2_B.c1 = vipldws2_B.MatrixConcatenation5[(vipldws2_B.indxI << 2)
          + 1] + 1;
      }

      /* '<S66>:1:31' r2 = r1c1r2c2(3)+int32(1); */
      if (vipldws2_B.MatrixConcatenation5[(vipldws2_B.indxI << 2) + 2] >
          2147483646) {
        vipldws2_B.qY_g = MAX_int32_T;
      } else {
        vipldws2_B.qY_g = vipldws2_B.MatrixConcatenation5[(vipldws2_B.indxI << 2)
          + 2] + 1;
      }

      vipldws2_B.r2 = vipldws2_B.qY_g;

      /* '<S66>:1:32' c2 = r1c1r2c2(4)+int32(1); */
      if (vipldws2_B.MatrixConcatenation5[(vipldws2_B.indxI << 2) + 3] >
          2147483646) {
        vipldws2_B.qY = MAX_int32_T;
      } else {
        vipldws2_B.qY = vipldws2_B.MatrixConcatenation5[(vipldws2_B.indxI << 2)
          + 3] + 1;
      }

      vipldws2_B.c2 = vipldws2_B.qY;

      /*  make sure r1 is the min(r1,r2) */
      /* '<S66>:1:35' if r1>r2 */
      if (vipldws2_B.r1 > vipldws2_B.qY_g) {
        /* '<S66>:1:36' tmp=r2; */
        /* '<S66>:1:37' r2=r1; */
        vipldws2_B.r2 = vipldws2_B.r1;

        /* '<S66>:1:38' r1=tmp; */
        vipldws2_B.r1 = vipldws2_B.qY_g;

        /* '<S66>:1:40' tmp=c2; */
        /* '<S66>:1:41' c2=c1; */
        vipldws2_B.c2 = vipldws2_B.c1;

        /* '<S66>:1:42' c1=tmp; */
        vipldws2_B.c1 = vipldws2_B.qY;
      }

      /* '<S66>:1:45' pointNotLine = (r1==r2) && (c1==c2); */
      /*  find if line is within image: (r1,c1)  and (r2,c2) must be within image */
      /* '<S66>:1:48' if ((r1>0 && r1 <= rH) && (c1>0 && c1 <= cW) && ... */
      /* '<S66>:1:49'         (r2>0 && r2 <= rH) && (c2>0 && c2 <= cW)) && ~pointNotLine */
      if ((vipldws2_B.r1 > 0) && (vipldws2_B.r1 <= 120) && (vipldws2_B.c1 > 0) &&
          (vipldws2_B.c1 <= 320) && (vipldws2_B.r2 > 0) && (vipldws2_B.r2 <= 120)
          && (vipldws2_B.c2 > 0) && (vipldws2_B.c2 <= 320) && (!((vipldws2_B.r1 ==
             vipldws2_B.r2) && (vipldws2_B.c1 == vipldws2_B.c2)))) {
        /* line_within_image = true; */
        /* '<S66>:1:51' if (abs(r1-R1)+ abs(c1-C1) + abs(r2-R2) +abs(c2-C2))< int32(20) */
        if (vipldws2_B.planeWidth < vipldws2_B.r1 - MAX_int32_T) {
          vipldws2_B.qY_g = MAX_int32_T;
        } else {
          vipldws2_B.qY_g = vipldws2_B.r1 - vipldws2_B.planeWidth;
        }

        if (vipldws2_B.planeOffset < vipldws2_B.c1 - MAX_int32_T) {
          vipldws2_B.qY = MAX_int32_T;
        } else {
          vipldws2_B.qY = vipldws2_B.c1 - vipldws2_B.planeOffset;
        }

        if (vipldws2_B.plane < vipldws2_B.r2 - MAX_int32_T) {
          vipldws2_B.c1 = MAX_int32_T;
        } else {
          vipldws2_B.c1 = vipldws2_B.r2 - vipldws2_B.plane;
        }

        if (vipldws2_B.C2 < vipldws2_B.c2 - MAX_int32_T) {
          vipldws2_B.i = MAX_int32_T;
        } else {
          vipldws2_B.i = vipldws2_B.c2 - vipldws2_B.C2;
        }

        if (vipldws2_B.qY_g < 0) {
          vipldws2_B.qY_g = -vipldws2_B.qY_g;
        }

        if (vipldws2_B.qY < 0) {
          vipldws2_B.qY = -vipldws2_B.qY;
        }

        if (vipldws2_B.c1 < 0) {
          vipldws2_B.c1 = -vipldws2_B.c1;
        }

        if (vipldws2_B.i < 0) {
          vipldws2_B.i = -vipldws2_B.i;
        }

        if ((vipldws2_B.qY_g < 0) && (vipldws2_B.qY < MIN_int32_T
             - vipldws2_B.qY_g)) {
          vipldws2_B.qY_g = MIN_int32_T;
        } else if ((vipldws2_B.qY_g > 0) && (vipldws2_B.qY > MAX_int32_T
                    - vipldws2_B.qY_g)) {
          vipldws2_B.qY_g = MAX_int32_T;
        } else {
          vipldws2_B.qY_g += vipldws2_B.qY;
        }

        if ((vipldws2_B.qY_g < 0) && (vipldws2_B.c1 < MIN_int32_T
             - vipldws2_B.qY_g)) {
          vipldws2_B.qY_g = MIN_int32_T;
        } else if ((vipldws2_B.qY_g > 0) && (vipldws2_B.c1 > MAX_int32_T
                    - vipldws2_B.qY_g)) {
          vipldws2_B.qY_g = MAX_int32_T;
        } else {
          vipldws2_B.qY_g += vipldws2_B.c1;
        }

        if ((vipldws2_B.qY_g < 0) && (vipldws2_B.i < MIN_int32_T
             - vipldws2_B.qY_g)) {
          vipldws2_B.qY_g = MIN_int32_T;
        } else if ((vipldws2_B.qY_g > 0) && (vipldws2_B.i > MAX_int32_T
                    - vipldws2_B.qY_g)) {
          vipldws2_B.qY_g = MAX_int32_T;
        } else {
          vipldws2_B.qY_g += vipldws2_B.i;
        }

        if (vipldws2_B.qY_g < 20) {
          /* '<S66>:1:52' out3rdLane = int32([-1000 -1000 -1000 -1000]'); */
          vipldws2_B.out3rdLane[0] = -1000;
          vipldws2_B.out3rdLane[1] = -1000;
          vipldws2_B.out3rdLane[2] = -1000;
          vipldws2_B.out3rdLane[3] = -1000;
        }
      } else {
        /* '<S66>:1:54' else */
        /*  line outside image */
        /*  go to nextLine */
      }
    }
  } else {
    /* '<S66>:1:59' else */
    /* '<S66>:1:60' out3rdLane = in3rdLane; */
  }

  /* End of MATLAB Function: '<S5>/Exclude 3rd Lane' */

  /* Bias: '<S5>/Bias3' */
  vipldws2_B.Bias3[0] = vipldws2_B.out3rdLane[0] + vipldws2_P.Bias3_Bias[0];
  vipldws2_B.Bias3[1] = vipldws2_B.out3rdLane[1] + vipldws2_P.Bias3_Bias[1];
  vipldws2_B.Bias3[2] = vipldws2_B.out3rdLane[2] + vipldws2_P.Bias3_Bias[2];
  vipldws2_B.Bias3[3] = vipldws2_B.out3rdLane[3] + vipldws2_P.Bias3_Bias[3];

  /* ManualSwitch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Draw Lines'
   *  Constant: '<Root>/Draw Polygon'
   */
  if (vipldws2_P.Switch_CurrentSetting == 1) {
    vipldws2_B.Switch_h = vipldws2_P.DrawLines_Value_j;
  } else {
    vipldws2_B.Switch_h = vipldws2_P.DrawPolygon_Value;
  }

  /* End of ManualSwitch: '<Root>/Switch' */

  /* Logic: '<Root>/Logical Operator' */
  vipldws2_B.LogicalOperator = (vipldws2_B.LogicalOperator1 &&
    vipldws2_B.Switch_h);

  /* Bias: '<S5>/Bias' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 8; vipldws2_B.i++) {
    vipldws2_B.Bias[vipldws2_B.i] = vipldws2_B.MatrixConcatenation5[vipldws2_B.i]
      + vipldws2_P.Bias_Bias_i[vipldws2_B.i];
  }

  /* End of Bias: '<S5>/Bias' */

  /* S-Function (sdspnsamp2): '<S5>/N-Sample Enable' incorporates:
   *  Constant: '<S2>/Constant'
   */
  /* DSP System Toolbox N-Sample Enable  (sdspnsamp2) - '<S5>/N-Sample Enable' */
  {
    {
      if (vipldws2_P.Constant_Value_g) {
        /* Reset iteration count. */
        vipldws2_DW.NSampleEnable_Counter = 0;
      }

      if (vipldws2_DW.NSampleEnable_Counter == vipldws2_P.NSampleEnable_N) {
        vipldws2_B.NSampleEnable = (boolean_T)(2 -
          vipldws2_P.NSampleEnable_ActiveLevel);
      } else {
        vipldws2_B.NSampleEnable = (boolean_T)
          (vipldws2_P.NSampleEnable_ActiveLevel - 1);
        (vipldws2_DW.NSampleEnable_Counter)++;
      }
    }
  }

  /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
   *  EnablePort: '<S67>/Enable'
   */
  if (vipldws2_B.NSampleEnable) {
    /* Bias: '<S67>/Bias' */
    vipldws2_B.Bias_h = (int8_T)(vipldws2_B.outMsg + vipldws2_P.Bias_Bias_d);

    /* Bias: '<S67>/Bias1' */
    vipldws2_B.Bias1_j[0] = (int8_T)(vipldws2_B.colorAndTypeIdx[0] +
      vipldws2_P.Bias1_Bias_e);
    vipldws2_B.Bias1_j[1] = (int8_T)(vipldws2_B.colorAndTypeIdx[1] +
      vipldws2_P.Bias1_Bias_e);

    /* Outputs for Enabled SubSystem: '<S67>/Draw  Polygon' incorporates:
     *  EnablePort: '<S68>/Enable'
     */
    if (vipldws2_B.LogicalOperator) {
      /* Selector: '<S71>/Selector1' */
      vipldws2_B.MatrixConcatenation6[0] = vipldws2_B.Bias[0];

      /* Selector: '<S71>/Selector4' */
      vipldws2_B.Selector7[0] = vipldws2_B.Bias[2];

      /* SignalConversion: '<S71>/ConcatBufferAtMatrix Concatenation6In2' */
      vipldws2_B.MatrixConcatenation6[2] = vipldws2_B.Selector7[0];

      /* Switch: '<S71>/Switch' incorporates:
       *  Constant: '<S71>/DSP Constant'
       */
      if (vipldws2_B.Selector7[0] >= vipldws2_P.Switch_Threshold) {
        vipldws2_B.MatrixConcatenation6[4] = vipldws2_B.Selector7[0];
      } else {
        vipldws2_B.MatrixConcatenation6[4] = vipldws2_P.DSPConstant_Value[0];
      }

      /* Selector: '<S71>/Selector1' */
      vipldws2_B.MatrixConcatenation6[1] = vipldws2_B.Bias[1];

      /* Selector: '<S71>/Selector4' */
      vipldws2_B.Selector7[1] = vipldws2_B.Bias[3];

      /* SignalConversion: '<S71>/ConcatBufferAtMatrix Concatenation6In2' */
      vipldws2_B.MatrixConcatenation6[3] = vipldws2_B.Selector7[1];

      /* Switch: '<S71>/Switch' incorporates:
       *  Constant: '<S71>/DSP Constant'
       */
      if (vipldws2_B.Selector7[0] >= vipldws2_P.Switch_Threshold) {
        vipldws2_B.MatrixConcatenation6[5] = vipldws2_B.Selector7[1];
      } else {
        vipldws2_B.MatrixConcatenation6[5] = vipldws2_P.DSPConstant_Value[1];
      }

      /* Selector: '<S71>/Selector' */
      vipldws2_B.Selector7[0] = vipldws2_B.Bias[6];

      /* Switch: '<S71>/Switch1' incorporates:
       *  Constant: '<S71>/DSP Constant2'
       */
      if (vipldws2_B.Selector7[0] >= vipldws2_P.Switch1_Threshold) {
        vipldws2_B.MatrixConcatenation6[6] = vipldws2_B.Selector7[0];
      } else {
        vipldws2_B.MatrixConcatenation6[6] = vipldws2_P.DSPConstant2_Value[0];
      }

      /* SignalConversion: '<S71>/ConcatBufferAtMatrix Concatenation6In5' */
      vipldws2_B.MatrixConcatenation6[8] = vipldws2_B.Selector7[0];

      /* Selector: '<S71>/Selector2' */
      vipldws2_B.MatrixConcatenation6[10] = vipldws2_B.Bias[4];

      /* Selector: '<S71>/Selector' */
      vipldws2_B.Selector7[1] = vipldws2_B.Bias[7];

      /* Switch: '<S71>/Switch1' incorporates:
       *  Constant: '<S71>/DSP Constant2'
       */
      if (vipldws2_B.Selector7[0] >= vipldws2_P.Switch1_Threshold) {
        vipldws2_B.MatrixConcatenation6[7] = vipldws2_B.Selector7[1];
      } else {
        vipldws2_B.MatrixConcatenation6[7] = vipldws2_P.DSPConstant2_Value[1];
      }

      /* SignalConversion: '<S71>/ConcatBufferAtMatrix Concatenation6In5' */
      vipldws2_B.MatrixConcatenation6[9] = vipldws2_B.Selector7[1];

      /* Selector: '<S71>/Selector2' */
      vipldws2_B.MatrixConcatenation6[11] = vipldws2_B.Bias[5];
      for (vipldws2_B.i = 0; vipldws2_B.i < 12; vipldws2_B.i++) {
        /* Selector: '<S68>/Selector2' */
        vipldws2_B.Selector2_h[vipldws2_B.i] =
          vipldws2_B.MatrixConcatenation6[tmp_1[vipldws2_B.i]];

        /* Math: '<S68>/Transpose1' */
        vipldws2_B.Transpose1_b[vipldws2_B.i] =
          vipldws2_B.Selector2_h[vipldws2_B.i];
      }

      /* S-Function (svipdrawshapes): '<S68>/DrawShapes' */
      /* Copy the image from input to output. */
      memcpy(&vipldws2_B.DrawShapes[0], &vipldws2_B.ImageDataTypeConversion[0],
             230400U * sizeof(real32_T));

      /* Calculate FillColor times Opacity. */
      vipldws2_DW.DrawShapes_DW_FillColorAdd[0] =
        vipldws2_P.DrawShapes_RTP_FILLCOLOR_o[0] *
        vipldws2_P.DrawShapes_RTP_OPACITY;
      vipldws2_DW.DrawShapes_DW_FillColorAdd[1] =
        vipldws2_P.DrawShapes_RTP_FILLCOLOR_o[1] *
        vipldws2_P.DrawShapes_RTP_OPACITY;
      vipldws2_DW.DrawShapes_DW_FillColorAdd[2] =
        vipldws2_P.DrawShapes_RTP_FILLCOLOR_o[2] *
        vipldws2_P.DrawShapes_RTP_OPACITY;

      /* Calculate One minus Opacity. */
      vipldws2_DW.DrawShapes_DW_OneMOpacity = 1.0F -
        vipldws2_P.DrawShapes_RTP_OPACITY;

      /* Update view port. */
      /* ProcessStep-start-1
       */
      /* ProcessStep-after poly points-1
       */
      /* Reset scanline states. */
      vipldws2_B.plane = 0;
      c_gotAlLeastOneYellowPixelInThe = true;
      while (c_gotAlLeastOneYellowPixelInThe) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        done = false;
        vipldws2_B.numEdge = 0;
        vipldws2_B.qY_g = vipldws2_B.plane;
        vipldws2_B.qY = vipldws2_B.plane;
        vipldws2_B.j = 0;
        while (vipldws2_B.j < 1) {
          /* start for loop
           */
          vipldws2_B.lastActiveEdgeIdxBdy = 11;
          vipldws2_B.indxI = 10;
          vipldws2_B.firstRowOut = 5;
          vipldws2_B.activeColBdy = 8;
          vipldws2_B.activeCol = 6;

          /* getLoc-3
           */
          vipldws2_B.i = vipldws2_B.Transpose1_b[8];
          while ((vipldws2_B.activeColBdy >= 0) && (vipldws2_B.Transpose1_b[10]
                  - 1 == vipldws2_B.i - 1)) {
            vipldws2_B.firstRowOut--;
            vipldws2_B.activeColBdy = (vipldws2_B.firstRowOut - 1) << 1;
            vipldws2_B.activeCol--;

            /* getLoc-3
             */
            vipldws2_B.i = vipldws2_B.Transpose1_b[vipldws2_B.activeColBdy];
          }

          if (vipldws2_B.activeColBdy < 0) {
            vipldws2_B.activeColBdy = 0;
          }

          /* getLoc-3
           */
          c_gotAlLeastOneYellowPixelInThe =
            (vipldws2_B.Transpose1_b[vipldws2_B.activeColBdy] - 1 >
             vipldws2_B.Transpose1_b[10] - 1);
          vipldws2_B.colOut = 1;
          vipldws2_B.activeColBdy = 0;
          prevEdgeIsVertical = false;

          /* getLoc-3
           */
          done = (vipldws2_B.Transpose1_b[10] - 1 == vipldws2_B.Transpose1_b[0]
                  - 1);
          vipldws2_B.i = 0;
          while (vipldws2_B.i < vipldws2_B.activeCol) {
            /* getLoc-3
             */
            if (vipldws2_B.Transpose1_b[vipldws2_B.indxI] - 1 !=
                vipldws2_B.Transpose1_b[vipldws2_B.activeColBdy] - 1) {
              /* getLoc-3
               */
              if (vipldws2_B.Transpose1_b[vipldws2_B.indxI] - 1 <
                  vipldws2_B.Transpose1_b[vipldws2_B.activeColBdy] - 1) {
                countTwice = false;
              } else {
                countTwice = true;
                vipldws2_B.firstRowOut = vipldws2_B.lastActiveEdgeIdxBdy;
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
                vipldws2_B.colOut = vipldws2_B.firstRowOut;
                vipldws2_B.firstRowOut = vipldws2_B.indxI;
                vipldws2_B.indxI = vipldws2_B.activeColBdy;
                vipldws2_B.activeColBdy = vipldws2_B.firstRowOut;
              }

              /* getLoc-3
               */
              /* Initialize a Bresenham line. */
              vipldws2_B.firstRow =
                vipldws2_B.Transpose1_b[vipldws2_B.activeColBdy] -
                vipldws2_B.Transpose1_b[vipldws2_B.indxI];
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] = 0;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] =
                vipldws2_B.Transpose1_b[vipldws2_B.lastActiveEdgeIdxBdy] - 1;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2] =
                vipldws2_B.Transpose1_b[vipldws2_B.indxI] - 1;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] =
                vipldws2_B.Transpose1_b[vipldws2_B.activeColBdy] - 1;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] = 0;
              if (vipldws2_B.Transpose1_b[vipldws2_B.colOut] - 1 >=
                  vipldws2_B.Transpose1_b[vipldws2_B.lastActiveEdgeIdxBdy] - 1)
              {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] =
                  vipldws2_B.Transpose1_b[vipldws2_B.colOut] -
                  vipldws2_B.Transpose1_b[vipldws2_B.lastActiveEdgeIdxBdy];
              } else {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] =
                  vipldws2_B.Transpose1_b[vipldws2_B.lastActiveEdgeIdxBdy] -
                  vipldws2_B.Transpose1_b[vipldws2_B.colOut];
              }

              while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] >= 0)
              {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6]++;
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] -=
                  vipldws2_B.firstRow;
              }

              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] - 1;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] +
                vipldws2_B.firstRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 4] =
                vipldws2_B.firstRow -
                (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7] << 1);
              if (vipldws2_B.Transpose1_b[vipldws2_B.lastActiveEdgeIdxBdy] - 1 >
                  vipldws2_B.Transpose1_b[vipldws2_B.colOut] - 1) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5] =
                  -vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] =
                  -vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6];
              }

              if ((!c_gotAlLeastOneYellowPixelInThe) && (!countTwice)) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2]++;
                if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] << 1) >
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 4]) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6];
                } else {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5];
                }
              } else {
                if (c_gotAlLeastOneYellowPixelInThe && countTwice) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3]--;
                }
              }

              c_gotAlLeastOneYellowPixelInThe = countTwice;
              if (!prevEdgeIsVertical) {
                /* Merge two Bresenham lines. */
                if ((vipldws2_B.qY_g != vipldws2_B.qY) &&
                    ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 5] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 6] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 7] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 8] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8]))) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] + 1
                      == vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2]) {
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] =
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3];
                    prevEdgeIsVertical = true;
                  } else {
                    if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] + 1
                        == vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2])
                    {
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 1] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2];
                      prevEdgeIsVertical = true;
                    }
                  }
                }

                if (!prevEdgeIsVertical) {
                  vipldws2_B.qY_g = vipldws2_B.qY;
                  vipldws2_B.numEdge++;
                }
              } else {
                vipldws2_B.qY_g = vipldws2_B.qY;
                vipldws2_B.numEdge++;
              }

              vipldws2_B.qY = vipldws2_B.qY_g + 9;
              if (!countTwice) {
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
                vipldws2_B.indxI = vipldws2_B.activeColBdy;
              }

              vipldws2_B.colOut = vipldws2_B.lastActiveEdgeIdxBdy + 2;
              vipldws2_B.activeColBdy = vipldws2_B.indxI + 2;
              prevEdgeIsVertical = false;
            } else {
              prevEdgeIsVertical = true;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
              vipldws2_B.indxI = vipldws2_B.activeColBdy;
              vipldws2_B.colOut += 2;
              vipldws2_B.activeColBdy += 2;
            }

            vipldws2_B.i++;
          }

          vipldws2_B.j = 1;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((vipldws2_B.plane != vipldws2_B.qY_g) &&
              ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 5] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 5]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 6] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 6]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 7] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 7]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 8] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 8]))) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3] + 1 ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2]) {
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3];
              done = true;
            } else {
              if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] + 1 ==
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2]) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 1] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 1];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2];
                done = true;
              }
            }
          }

          if (done) {
            vipldws2_B.numEdge--;
            vipldws2_B.qY -= 9;
          }
        }

        /* Set all other edges to invalid. */
        vipldws2_B.i = vipldws2_B.numEdge;
        while (vipldws2_B.i < 6) {
          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2] = 1;
          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] = 0;
          vipldws2_B.qY += 9;
          vipldws2_B.i++;
        }

        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws2_B.r1 = vipldws2_B.plane;
          vipldws2_B.r2 = vipldws2_B.plane + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.i = 1;
          while (vipldws2_B.i < vipldws2_B.numEdge) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 2] >
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_B.lastSeparator =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j] =
                  vipldws2_B.lastSeparator;
              }
            }

            vipldws2_B.r1 = vipldws2_B.r2;
            vipldws2_B.r2 += 9;
            vipldws2_B.i++;
          }
        }

        /* Find out the last column of the polygon. */
        vipldws2_B.planeOffset = vipldws2_B.plane + 3;
        vipldws2_B.qY_g = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3];
        vipldws2_B.i = 1;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          vipldws2_B.planeOffset += 9;
          if (vipldws2_B.qY_g <
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset]) {
            vipldws2_B.qY_g =
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset];
          }

          vipldws2_B.i++;
        }

        vipldws2_B.qY = vipldws2_B.qY_g;
        if (vipldws2_B.qY_g > 319) {
          vipldws2_B.qY = 319;
        }

        /* Find out the first column of the polygon. */
        vipldws2_B.planeOffset = vipldws2_B.plane + 2;
        vipldws2_B.qY_g = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2];
        vipldws2_B.i = 1;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          vipldws2_B.planeOffset += 9;
          if (vipldws2_B.qY_g >
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset]) {
            vipldws2_B.qY_g =
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset];
          }

          vipldws2_B.i++;
        }

        if (vipldws2_B.qY_g < 0) {
          vipldws2_B.qY_g = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        vipldws2_B.r1 = vipldws2_B.plane;
        vipldws2_B.r2 = vipldws2_B.plane;
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.plane;
        vipldws2_B.indxI = 0;
        vipldws2_B.planeOffset = 0;
        vipldws2_B.i = 0;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 3] >=
              vipldws2_B.qY_g) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <=
                vipldws2_B.qY_g) {
              while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <
                     vipldws2_B.qY_g) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]++;
                if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] << 1) >
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 4]) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 8];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 6];
                } else {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 7];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 5];
                }
              }

              vipldws2_B.lastActiveEdgeIdxBdy += 9;
              vipldws2_B.planeOffset++;
            }

            if (vipldws2_B.r2 != vipldws2_B.r1) {
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
              }
            }

            vipldws2_B.r1 += 9;
            vipldws2_B.indxI++;
          }

          vipldws2_B.r2 += 9;
          vipldws2_B.i++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws2_B.r1 = vipldws2_B.plane;
          vipldws2_B.r2 = vipldws2_B.plane + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.i = 1;
          while (vipldws2_B.i < vipldws2_B.planeOffset) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1] >
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_B.lastSeparator =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j] =
                  vipldws2_B.lastSeparator;
              }
            }

            vipldws2_B.r1 = vipldws2_B.r2;
            vipldws2_B.r2 += 9;
            vipldws2_B.i++;
          }
        }

        vipldws2_B.r1 = vipldws2_B.plane;
        vipldws2_B.activeColBdy = vipldws2_B.qY_g + 1;
        vipldws2_B.activeCol = 0;
        vipldws2_B.r2 = 0;
        vipldws2_B.lastSeparator = -1;
        c_gotAlLeastOneYellowPixelInThe = (0 <= vipldws2_B.qY);
        while (c_gotAlLeastOneYellowPixelInThe) {
          /* Get a string of pixels */
          countTwice = false;
          done = (vipldws2_B.r2 != 0);
          vipldws2_B.col = vipldws2_B.activeCol;
          if ((vipldws2_B.activeCol >= vipldws2_B.qY_g) && (vipldws2_B.activeCol
               <= vipldws2_B.qY)) {
            if (vipldws2_B.r1 < vipldws2_B.lastActiveEdgeIdxBdy) {
              vipldws2_B.i = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
              vipldws2_B.r1 += 9;
              if ((vipldws2_B.i == vipldws2_B.lastSeparator) && (vipldws2_B.r1 <
                   vipldws2_B.lastActiveEdgeIdxBdy)) {
                vipldws2_B.planeOffset =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
                c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.r1 <
                  vipldws2_B.lastActiveEdgeIdxBdy);
                while (c_gotAlLeastOneYellowPixelInThe && (vipldws2_B.i ==
                        vipldws2_B.planeOffset)) {
                  countTwice = true;
                  vipldws2_B.i = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1
                    + 1];
                  vipldws2_B.r1 += 9;
                  c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.r1 <
                    vipldws2_B.lastActiveEdgeIdxBdy);
                  if (c_gotAlLeastOneYellowPixelInThe) {
                    vipldws2_B.planeOffset =
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
                  }
                }

                if (!c_gotAlLeastOneYellowPixelInThe) {
                  countTwice = false;
                }
              }

              if (vipldws2_B.r2 != 0) {
                vipldws2_B.firstRow = vipldws2_B.lastSeparator;
                if (vipldws2_B.i <= 239) {
                  vipldws2_B.lastRow = vipldws2_B.i;
                  vipldws2_B.lastSeparator = vipldws2_B.i;
                } else {
                  vipldws2_B.lastRow = 239;
                  vipldws2_B.lastSeparator = 239;
                }
              } else {
                vipldws2_B.firstRow = vipldws2_B.lastSeparator + 1;
                if ((vipldws2_B.i > 0) && (vipldws2_B.i <= 239)) {
                  vipldws2_B.lastRow = vipldws2_B.i - 1;
                  vipldws2_B.lastSeparator = vipldws2_B.i;
                } else if (vipldws2_B.i <= 0) {
                  vipldws2_B.lastRow = -1;
                  vipldws2_B.lastSeparator = 0;
                } else {
                  vipldws2_B.lastRow = 239;
                  vipldws2_B.lastSeparator = 240;
                }
              }

              if (!countTwice) {
                vipldws2_B.r2 = !(vipldws2_B.r2 != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              vipldws2_B.firstRow = vipldws2_B.lastSeparator + 1;
              vipldws2_B.lastRow = 239;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              vipldws2_B.r1 = vipldws2_B.plane;
              vipldws2_B.r2 = vipldws2_B.plane;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.plane;
              vipldws2_B.numEdge = 0;
              vipldws2_B.planeOffset = 0;
              vipldws2_B.i = 0;
              while (vipldws2_B.i < vipldws2_B.indxI) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 3] >=
                    vipldws2_B.activeColBdy) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <=
                      vipldws2_B.activeColBdy) {
                    while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <
                           vipldws2_B.activeColBdy) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]++;
                      if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] << 1)
                          > vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 4])
                      {
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 8];
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 6];
                      } else {
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 7];
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 5];
                      }
                    }

                    vipldws2_B.lastActiveEdgeIdxBdy += 9;
                    vipldws2_B.planeOffset++;
                  }

                  if (vipldws2_B.r2 != vipldws2_B.r1) {
                    for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j];
                    }
                  }

                  vipldws2_B.r1 += 9;
                  vipldws2_B.numEdge++;
                }

                vipldws2_B.r2 += 9;
                vipldws2_B.i++;
              }

              vipldws2_B.indxI = vipldws2_B.numEdge;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (c_gotAlLeastOneYellowPixelInThe) {
                vipldws2_B.r1 = vipldws2_B.plane;
                vipldws2_B.r2 = vipldws2_B.plane + 9;
                c_gotAlLeastOneYellowPixelInThe = false;
                vipldws2_B.i = 1;
                while (vipldws2_B.i < vipldws2_B.planeOffset) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1] >
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1]) {
                    c_gotAlLeastOneYellowPixelInThe = true;
                    for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                      vipldws2_B.lastSeparator =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j] = vipldws2_B.lastSeparator;
                    }
                  }

                  vipldws2_B.r1 = vipldws2_B.r2;
                  vipldws2_B.r2 += 9;
                  vipldws2_B.i++;
                }
              }

              vipldws2_B.r1 = vipldws2_B.plane;
              vipldws2_B.activeColBdy++;
              vipldws2_B.r2 = 0;
              vipldws2_B.lastSeparator = -1;
              vipldws2_B.activeCol++;
            }
          } else {
            vipldws2_B.firstRow = 0;
            vipldws2_B.lastRow = 239;
            vipldws2_B.activeCol++;
          }

          if (vipldws2_B.firstRow < 0) {
            vipldws2_B.firstRow = 0;
          }

          if (vipldws2_B.lastRow < vipldws2_B.firstRow) {
            vipldws2_B.lastRow = vipldws2_B.firstRow - 1;
          }

          if (done) {
            vipldws2_B.j = vipldws2_B.col * 240 + vipldws2_B.firstRow;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.i = vipldws2_B.firstRow;
            while (vipldws2_B.i <= vipldws2_B.lastRow) {
              vipldws2_B.DrawShapes[vipldws2_B.col] *=
                vipldws2_DW.DrawShapes_DW_OneMOpacity;
              vipldws2_B.DrawShapes[vipldws2_B.col] +=
                vipldws2_DW.DrawShapes_DW_FillColorAdd[0];
              vipldws2_B.col++;
              vipldws2_B.i++;
            }

            vipldws2_B.j += 76800;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.i = vipldws2_B.firstRow;
            while (vipldws2_B.i <= vipldws2_B.lastRow) {
              vipldws2_B.DrawShapes[vipldws2_B.col] *=
                vipldws2_DW.DrawShapes_DW_OneMOpacity;
              vipldws2_B.DrawShapes[vipldws2_B.col] +=
                vipldws2_DW.DrawShapes_DW_FillColorAdd[1];
              vipldws2_B.col++;
              vipldws2_B.i++;
            }

            vipldws2_B.j += 76800;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.i = vipldws2_B.firstRow;
            while (vipldws2_B.i <= vipldws2_B.lastRow) {
              vipldws2_B.DrawShapes[vipldws2_B.col] *=
                vipldws2_DW.DrawShapes_DW_OneMOpacity;
              vipldws2_B.DrawShapes[vipldws2_B.col] +=
                vipldws2_DW.DrawShapes_DW_FillColorAdd[2];
              vipldws2_B.col++;
              vipldws2_B.i++;
            }
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.activeCol <=
            vipldws2_B.qY);
        }

        /* Move to the next polygon. */
        vipldws2_B.plane += 54;
        c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.plane < 54);
      }

      /* End of S-Function (svipdrawshapes): '<S68>/DrawShapes' */
      srUpdateBC(vipldws2_DW.DrawPolygon_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S67>/Draw  Polygon' */

    /* Selector: '<S69>/Selector1' */
    vipldws2_B.Transpose2[0] = vipldws2_B.Bias[0];

    /* Bias: '<S69>/Bias1' */
    vipldws2_B.Transpose2[0] += vipldws2_P.Bias1_Bias[0];

    /* Selector: '<S69>/Selector3' */
    vipldws2_B.Bias2[0] = vipldws2_B.Bias[4];

    /* Bias: '<S69>/Bias2' */
    vipldws2_B.Bias2[0] += vipldws2_P.Bias2_Bias[0];

    /* Selector: '<S69>/Selector1' */
    vipldws2_B.Transpose2[1] = vipldws2_B.Bias[1];

    /* Bias: '<S69>/Bias1' */
    vipldws2_B.Transpose2[1] += vipldws2_P.Bias1_Bias[1];

    /* Selector: '<S69>/Selector3' */
    vipldws2_B.Bias2[1] = vipldws2_B.Bias[5];

    /* Bias: '<S69>/Bias2' */
    vipldws2_B.Bias2[1] += vipldws2_P.Bias2_Bias[1];

    /* Switch: '<S67>/Switch' */
    if (vipldws2_B.LogicalOperator) {
      memcpy(&vipldws2_B.Switch2[0], &vipldws2_B.DrawShapes[0], 230400U * sizeof
             (real32_T));
    } else {
      memcpy(&vipldws2_B.Switch2[0], &vipldws2_B.ImageDataTypeConversion[0],
             230400U * sizeof(real32_T));
    }

    /* End of Switch: '<S67>/Switch' */

    /* Selector: '<S67>/Selector2' */
    for (vipldws2_B.i = 0; vipldws2_B.i < 2; vipldws2_B.i++) {
      vipldws2_B.Selector2_m[vipldws2_B.i << 2] = vipldws2_B.Bias[(vipldws2_B.i <<
        2) + 1];
      vipldws2_B.Selector2_m[1 + (vipldws2_B.i << 2)] =
        vipldws2_B.Bias[vipldws2_B.i << 2];
      vipldws2_B.Selector2_m[2 + (vipldws2_B.i << 2)] = vipldws2_B.Bias
        [(vipldws2_B.i << 2) + 3];
      vipldws2_B.Selector2_m[3 + (vipldws2_B.i << 2)] = vipldws2_B.Bias
        [(vipldws2_B.i << 2) + 2];
    }

    /* End of Selector: '<S67>/Selector2' */

    /* Math: '<S67>/Transpose1' */
    for (vipldws2_B.i = 0; vipldws2_B.i < 4; vipldws2_B.i++) {
      vipldws2_B.Transpose1_p[vipldws2_B.i << 1] =
        vipldws2_B.Selector2_m[vipldws2_B.i];
      vipldws2_B.Transpose1_p[1 + (vipldws2_B.i << 1)] =
        vipldws2_B.Selector2_m[vipldws2_B.i + 4];
    }

    /* End of Math: '<S67>/Transpose1' */

    /* S-Function (svipdrawshapes): '<S67>/DrawShapes' */
    if (vipldws2_P.DrawShapes_lineWidth_i == 1) {
      /* Compute output for unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws2_B.DrawShapes_m[0], &vipldws2_B.Switch2[0], 230400U *
             sizeof(real32_T));

      /* Update view port. */
      vipldws2_B.planeWidth = 0;
      for (vipldws2_B.plane = 0; vipldws2_B.plane < 2; vipldws2_B.plane++) {
        vipldws2_B.qY_g = vipldws2_B.Transpose1_p[vipldws2_B.plane + 2] - 1;
        vipldws2_B.qY = vipldws2_B.Transpose1_p[vipldws2_B.plane] - 1;
        if ((vipldws2_B.Transpose1_p[vipldws2_B.plane + 6] - 1 !=
             vipldws2_B.qY_g) || (vipldws2_B.Transpose1_p[4 + vipldws2_B.plane]
             - 1 != vipldws2_B.qY)) {
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.qY_g = (vipldws2_B.qY_g << 3) + 4;
          vipldws2_B.j = ((vipldws2_B.Transpose1_p[vipldws2_B.plane + 6] - 1) <<
                          3) + 4;
          vipldws2_B.qY = (vipldws2_B.qY << 3) + 4;
          vipldws2_B.numEdge = ((vipldws2_B.Transpose1_p[4 + vipldws2_B.plane] -
            1) << 3) + 4;

          /* Find the visible portion of a line. */
          countTwice = false;
          prevEdgeIsVertical = false;
          done = false;
          vipldws2_B.indxI = vipldws2_B.qY_g;
          vipldws2_B.c2 = vipldws2_B.qY;
          vipldws2_B.C2 = vipldws2_B.j;
          vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.numEdge;
          while (!done) {
            vipldws2_B.fromIdx = 0U;
            vipldws2_B.toIdx = 0U;

            /* Determine viewport violations. */
            if (vipldws2_B.indxI < 0) {
              vipldws2_B.fromIdx = 4U;
            } else {
              if (vipldws2_B.indxI > 1919) {
                vipldws2_B.fromIdx = 8U;
              }
            }

            if (vipldws2_B.C2 < 0) {
              vipldws2_B.toIdx = 4U;
            } else {
              if (vipldws2_B.C2 > 1919) {
                vipldws2_B.toIdx = 8U;
              }
            }

            if (vipldws2_B.c2 < 0) {
              vipldws2_B.fromIdx |= 1U;
            } else {
              if (vipldws2_B.c2 > 2559) {
                vipldws2_B.fromIdx |= 2U;
              }
            }

            if (vipldws2_B.lastActiveEdgeIdxBdy < 0) {
              vipldws2_B.toIdx |= 1U;
            } else {
              if (vipldws2_B.lastActiveEdgeIdxBdy > 2559) {
                vipldws2_B.toIdx |= 2U;
              }
            }

            if (!((vipldws2_B.fromIdx | vipldws2_B.toIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = true;
            } else if ((vipldws2_B.fromIdx & vipldws2_B.toIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = false;
            } else if (vipldws2_B.fromIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (countTwice) {
                vipldws2_B.indxI = vipldws2_B.qY_g;
                vipldws2_B.c2 = vipldws2_B.qY;
              }

              vipldws2_B.i = vipldws2_B.C2 - vipldws2_B.indxI;
              vipldws2_B.planeOffset = vipldws2_B.lastActiveEdgeIdxBdy -
                vipldws2_B.c2;
              if ((vipldws2_B.i > 1073741824) || (vipldws2_B.i < -1073741824) ||
                  ((vipldws2_B.planeOffset > 1073741824) ||
                   (vipldws2_B.planeOffset < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
                countTwice = true;
              } else if ((vipldws2_B.fromIdx & 4U) != 0U) {
                /* Violated RMin. */
                vipldws2_B.c1 = -vipldws2_B.indxI * vipldws2_B.planeOffset;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                           ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                  vipldws2_B.c2 += (div_s32_floor(vipldws2_B.c1 << 1,
                    vipldws2_B.i) + 1) >> 1;
                } else {
                  vipldws2_B.c2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                    vipldws2_B.i) + 1) >> 1;
                }

                vipldws2_B.indxI = 0;
                countTwice = true;
              } else if ((vipldws2_B.fromIdx & 8U) != 0U) {
                /* Violated RMax. */
                vipldws2_B.c1 = (1919 - vipldws2_B.indxI) *
                  vipldws2_B.planeOffset;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                           ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                  vipldws2_B.c2 += (div_s32_floor(vipldws2_B.c1 << 1,
                    vipldws2_B.i) + 1) >> 1;
                } else {
                  vipldws2_B.c2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                    vipldws2_B.i) + 1) >> 1;
                }

                vipldws2_B.indxI = 1919;
                countTwice = true;
              } else if ((vipldws2_B.fromIdx & 1U) != 0U) {
                /* Violated CMin. */
                vipldws2_B.c1 = -vipldws2_B.c2 * vipldws2_B.i;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                           || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset <
                             0))) {
                  vipldws2_B.indxI += (div_s32_floor(vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                } else {
                  vipldws2_B.indxI -= (div_s32_floor(-vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                }

                vipldws2_B.c2 = 0;
                countTwice = true;
              } else {
                /* Violated CMax. */
                vipldws2_B.c1 = (2559 - vipldws2_B.c2) * vipldws2_B.i;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                           || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset <
                             0))) {
                  vipldws2_B.indxI += (div_s32_floor(vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                } else {
                  vipldws2_B.indxI -= (div_s32_floor(-vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                }

                vipldws2_B.c2 = 2559;
                countTwice = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (prevEdgeIsVertical) {
                vipldws2_B.C2 = vipldws2_B.j;
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.numEdge;
              }

              vipldws2_B.i = vipldws2_B.C2 - vipldws2_B.indxI;
              vipldws2_B.planeOffset = vipldws2_B.lastActiveEdgeIdxBdy -
                vipldws2_B.c2;
              if ((vipldws2_B.i > 1073741824) || (vipldws2_B.i < -1073741824) ||
                  ((vipldws2_B.planeOffset > 1073741824) ||
                   (vipldws2_B.planeOffset < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
                prevEdgeIsVertical = true;
              } else if ((vipldws2_B.toIdx & 4U) != 0U) {
                /* Violated RMin. */
                vipldws2_B.c1 = -vipldws2_B.C2 * vipldws2_B.planeOffset;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                           ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                  vipldws2_B.lastActiveEdgeIdxBdy += (div_s32_floor
                    (vipldws2_B.c1 << 1, vipldws2_B.i) + 1) >> 1;
                } else {
                  vipldws2_B.lastActiveEdgeIdxBdy -= (div_s32_floor
                    (-vipldws2_B.c1 << 1, vipldws2_B.i) + 1) >> 1;
                }

                vipldws2_B.C2 = 0;
                prevEdgeIsVertical = true;
              } else if ((vipldws2_B.toIdx & 8U) != 0U) {
                /* Violated RMax. */
                vipldws2_B.c1 = (1919 - vipldws2_B.C2) * vipldws2_B.planeOffset;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                           ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                  vipldws2_B.lastActiveEdgeIdxBdy += (div_s32_floor
                    (vipldws2_B.c1 << 1, vipldws2_B.i) + 1) >> 1;
                } else {
                  vipldws2_B.lastActiveEdgeIdxBdy -= (div_s32_floor
                    (-vipldws2_B.c1 << 1, vipldws2_B.i) + 1) >> 1;
                }

                vipldws2_B.C2 = 1919;
                prevEdgeIsVertical = true;
              } else if ((vipldws2_B.toIdx & 1U) != 0U) {
                /* Violated CMin. */
                vipldws2_B.c1 = -vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.i;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                           || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset <
                             0))) {
                  vipldws2_B.C2 += (div_s32_floor(vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                } else {
                  vipldws2_B.C2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                }

                vipldws2_B.lastActiveEdgeIdxBdy = 0;
                prevEdgeIsVertical = true;
              } else {
                /* Violated CMax. */
                vipldws2_B.c1 = (2559 - vipldws2_B.lastActiveEdgeIdxBdy) *
                  vipldws2_B.i;
                if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
                {
                  /* Check for Inf or Nan. */
                  done = true;
                  c_gotAlLeastOneYellowPixelInThe = false;
                } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                           || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset <
                             0))) {
                  vipldws2_B.C2 += (div_s32_floor(vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                } else {
                  vipldws2_B.C2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                    vipldws2_B.planeOffset) + 1) >> 1;
                }

                vipldws2_B.lastActiveEdgeIdxBdy = 2559;
                prevEdgeIsVertical = true;
              }
            }
          }

          if (c_gotAlLeastOneYellowPixelInThe) {
            /* Initialize the Bresenham algorithm. */
            if (vipldws2_B.C2 >= vipldws2_B.indxI) {
              vipldws2_B.j = vipldws2_B.C2 - vipldws2_B.indxI;
            } else {
              vipldws2_B.j = vipldws2_B.indxI - vipldws2_B.C2;
            }

            if (vipldws2_B.lastActiveEdgeIdxBdy >= vipldws2_B.c2) {
              vipldws2_B.numEdge = vipldws2_B.lastActiveEdgeIdxBdy -
                vipldws2_B.c2;
            } else {
              vipldws2_B.numEdge = vipldws2_B.c2 -
                vipldws2_B.lastActiveEdgeIdxBdy;
            }

            if (vipldws2_B.j > vipldws2_B.numEdge) {
              vipldws2_B.r2 = 1;
              vipldws2_B.r1 = 240;
            } else {
              vipldws2_B.r2 = 240;
              vipldws2_B.r1 = 1;
              vipldws2_B.i = vipldws2_B.indxI;
              vipldws2_B.indxI = vipldws2_B.c2;
              vipldws2_B.c2 = vipldws2_B.i;
              vipldws2_B.i = vipldws2_B.C2;
              vipldws2_B.C2 = vipldws2_B.lastActiveEdgeIdxBdy;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.i;
            }

            if (vipldws2_B.indxI > vipldws2_B.C2) {
              vipldws2_B.i = vipldws2_B.indxI;
              vipldws2_B.indxI = vipldws2_B.C2;
              vipldws2_B.C2 = vipldws2_B.i;
              vipldws2_B.i = vipldws2_B.c2;
              vipldws2_B.c2 = vipldws2_B.lastActiveEdgeIdxBdy;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.i;
            }

            vipldws2_B.qY_g = vipldws2_B.C2 - vipldws2_B.indxI;
            if (vipldws2_B.c2 <= vipldws2_B.lastActiveEdgeIdxBdy) {
              vipldws2_B.qY = 1;
              vipldws2_B.lastActiveEdgeIdxBdy -= vipldws2_B.c2;
            } else {
              vipldws2_B.qY = -1;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.c2 -
                vipldws2_B.lastActiveEdgeIdxBdy;
            }

            vipldws2_B.activeColBdy = vipldws2_B.c2 - 4;
            vipldws2_B.activeCol = -((vipldws2_B.qY_g + 1) >> 1);
            if (vipldws2_B.r2 != 1) {
              vipldws2_B.colBoundary = 1919;
            } else {
              vipldws2_B.colBoundary = 2559;
            }

            vipldws2_B.c1 = vipldws2_B.indxI >> 3;
            vipldws2_B.j = ((vipldws2_B.c1 + 1) << 3) - vipldws2_B.indxI;
            vipldws2_B.firstRowOut = 320;
            vipldws2_B.lastRowOut = 0;
            memset(&vipldws2_DW.DrawShapes_DW_PixCount[0], 0, 320U * sizeof
                   (uint8_T));
            done = (vipldws2_B.indxI <= vipldws2_B.C2);
            while (done) {
              vipldws2_B.j--;
              vipldws2_B.numEdge = vipldws2_B.activeColBdy;

              /* Compute the next location using Bresenham algorithm. */
              /* Move to the next sub-pixel location. */
              vipldws2_B.activeCol += vipldws2_B.lastActiveEdgeIdxBdy;
              if (vipldws2_B.activeCol >= 0) {
                vipldws2_B.activeColBdy += vipldws2_B.qY;
                vipldws2_B.activeCol -= vipldws2_B.qY_g;
              }

              vipldws2_B.indxI++;
              done = (vipldws2_B.indxI <= vipldws2_B.C2);
              if (done) {
                vipldws2_B.col = vipldws2_B.numEdge + 7;
                if ((vipldws2_B.numEdge + 7 > 0) && (vipldws2_B.numEdge <
                     vipldws2_B.colBoundary)) {
                  if (vipldws2_B.numEdge < 0) {
                    vipldws2_B.numEdge = 0;
                  }

                  if (vipldws2_B.col > vipldws2_B.colBoundary) {
                    vipldws2_B.col = vipldws2_B.colBoundary;
                  }

                  vipldws2_B.planeOffset = vipldws2_B.numEdge >> 3;
                  vipldws2_B.i = vipldws2_B.col >> 3;
                  if (vipldws2_B.firstRowOut > vipldws2_B.planeOffset) {
                    vipldws2_B.firstRowOut = vipldws2_B.planeOffset;
                  }

                  if (vipldws2_B.lastRowOut < vipldws2_B.i) {
                    vipldws2_B.lastRowOut = vipldws2_B.i;
                  }

                  if (vipldws2_B.i > vipldws2_B.planeOffset) {
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                      (uint8_T)(((uint32_T)((vipldws2_B.planeOffset + 1) << 3) +
                                 vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset])
                                - vipldws2_B.numEdge);
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] = (uint8_T)
                      ((((uint32_T)
                         vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] +
                         vipldws2_B.col) - (vipldws2_B.i << 3)) + 1U);
                    vipldws2_B.numEdge = vipldws2_B.planeOffset + 1;
                    while (vipldws2_B.numEdge < vipldws2_B.i) {
                      vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] =
                        (uint8_T)
                        (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge]
                         + 8U);
                      vipldws2_B.numEdge++;
                    }
                  } else {
                    if (vipldws2_B.i == vipldws2_B.planeOffset) {
                      vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset]
                        = (uint8_T)((((uint32_T)
                                      vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset]
                                      + vipldws2_B.col) - vipldws2_B.numEdge) +
                                    1U);
                    }
                  }
                }
              }

              if ((vipldws2_B.j == 0) || (!done)) {
                while (vipldws2_B.firstRowOut <= vipldws2_B.lastRowOut) {
                  vipldws2_B.col = vipldws2_B.c1 * vipldws2_B.r2 +
                    vipldws2_B.firstRowOut * vipldws2_B.r1;
                  if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut]
                      == 64) {
                    vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                      vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeWidth]
                      - vipldws2_B.DrawShapes_m[vipldws2_B.col];
                  } else {
                    vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                      (vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeWidth]
                       - vipldws2_B.DrawShapes_m[vipldws2_B.col]) * (real32_T)
                      vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut]
                      / 64.0F;
                  }

                  vipldws2_B.col += 76800;
                  vipldws2_B.planeOffset = vipldws2_B.planeWidth + 2;
                  if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut]
                      == 64) {
                    vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                      vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                      - vipldws2_B.DrawShapes_m[vipldws2_B.col];
                  } else {
                    vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                      (vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                       - vipldws2_B.DrawShapes_m[vipldws2_B.col]) * (real32_T)
                      vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut]
                      / 64.0F;
                  }

                  vipldws2_B.col += 76800;
                  vipldws2_B.planeOffset += 2;
                  if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut]
                      == 64) {
                    vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                      vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                      - vipldws2_B.DrawShapes_m[vipldws2_B.col];
                  } else {
                    vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                      (vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                       - vipldws2_B.DrawShapes_m[vipldws2_B.col]) * (real32_T)
                      vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut]
                      / 64.0F;
                  }

                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] =
                    0U;
                  vipldws2_B.firstRowOut++;
                }

                vipldws2_B.j = 8;
                vipldws2_B.firstRowOut = 320;
                vipldws2_B.lastRowOut = 0;
                vipldws2_B.c1++;
              }
            }
          }
        }

        if (vipldws2_B.planeWidth < 3) {
          vipldws2_B.planeWidth++;
        } else {
          vipldws2_B.planeWidth = 0;
        }
      }
    } else {
      /* Compute output for non-unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws2_B.DrawShapes_m[0], &vipldws2_B.Switch2[0], 230400U *
             sizeof(real32_T));

      /* Update view port. */
      /* ProcessStep-start-1
       */
      if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
        /* convertLinePts2PolygonPts
         */
        vipldws2_B.numEdge = vipldws2_P.DrawShapes_lineWidth_i >> 1;

        /* getLineParams-1
         */
        /* getLineParams-main fcn
         */
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.Transpose1_p[2] -
          vipldws2_B.Transpose1_p[6];
        vipldws2_B.indxI = vipldws2_B.Transpose1_p[0] - vipldws2_B.Transpose1_p
          [4];
        if (vipldws2_B.indxI == 0) {
          vipldws2_B.scale = 0.0F;
          vipldws2_B.col = 1;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[0] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[0] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[2] - 1);
        } else if (vipldws2_B.lastActiveEdgeIdxBdy == 0) {
          vipldws2_B.col = 2;
          vipldws2_B.scale = 0.0F;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[2] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[2] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[0] - 1);
        } else {
          vipldws2_B.col = 0;
          vipldws2_B.scale = (real32_T)vipldws2_B.lastActiveEdgeIdxBdy /
            (real32_T)vipldws2_B.indxI;
          vipldws2_B.y2 = (real32_T)(vipldws2_B.Transpose1_p[2] - 1) - (real32_T)
            (vipldws2_B.Transpose1_p[0] - 1) * vipldws2_B.scale;
          vipldws2_B.acc4_idx_0 = (real32_T)vipldws2_B.numEdge / ((real32_T)
            vipldws2_B.indxI / (real32_T)sqrt((real32_T)
            (vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.lastActiveEdgeIdxBdy +
             vipldws2_B.indxI * vipldws2_B.indxI)));
          vipldws2_B.cnt = vipldws2_B.y2 + vipldws2_B.acc4_idx_0;
          vipldws2_B.y2 -= vipldws2_B.acc4_idx_0;
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[0] - 1) /
            vipldws2_B.scale + (real32_T)(vipldws2_B.Transpose1_p[2] - 1);
        }

        /* findPointOfIntersectionNormal-1
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.cnt;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.acc4_idx_0
                + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.cnt) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt += vipldws2_B.scale * vipldws2_B.acc1_idx_5;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[0] = vipldws2_B.lastActiveEdgeIdxBdy;
        vipldws2_DW.DrawShapes_DW_Points[2] = vipldws2_B.indxI;

        /* findPointOfIntersectionNormal-2
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.y2;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.y2;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.y2) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt = vipldws2_B.scale * vipldws2_B.acc1_idx_5 +
            vipldws2_B.y2;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.cnt +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[14] = vipldws2_B.activeCol;
        vipldws2_DW.DrawShapes_DW_Points[12] = vipldws2_B.activeColBdy;

        /* getLineParams-2
         */
        /* getLineParams-main fcn
         */
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.Transpose1_p[2] -
          vipldws2_B.Transpose1_p[6];
        vipldws2_B.indxI = vipldws2_B.Transpose1_p[0] - vipldws2_B.Transpose1_p
          [4];
        if (vipldws2_B.indxI == 0) {
          vipldws2_B.scale = 0.0F;
          vipldws2_B.col = 1;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[0] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[0] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[6] - 1);
        } else if (vipldws2_B.lastActiveEdgeIdxBdy == 0) {
          vipldws2_B.col = 2;
          vipldws2_B.scale = 0.0F;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[2] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[2] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[4] - 1);
        } else {
          vipldws2_B.col = 0;
          vipldws2_B.scale = (real32_T)vipldws2_B.lastActiveEdgeIdxBdy /
            (real32_T)vipldws2_B.indxI;
          vipldws2_B.y2 = (real32_T)(vipldws2_B.Transpose1_p[2] - 1) - (real32_T)
            (vipldws2_B.Transpose1_p[0] - 1) * vipldws2_B.scale;
          vipldws2_B.acc4_idx_0 = (real32_T)vipldws2_B.numEdge / ((real32_T)
            vipldws2_B.indxI / (real32_T)sqrt((real32_T)
            (vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.lastActiveEdgeIdxBdy +
             vipldws2_B.indxI * vipldws2_B.indxI)));
          vipldws2_B.cnt = vipldws2_B.y2 + vipldws2_B.acc4_idx_0;
          vipldws2_B.y2 -= vipldws2_B.acc4_idx_0;
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[4] - 1) /
            vipldws2_B.scale + (real32_T)(vipldws2_B.Transpose1_p[6] - 1);
        }

        /* findPointOfIntersectionNormal-3
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.cnt;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.acc4_idx_0
                + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.cnt) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt += vipldws2_B.scale * vipldws2_B.acc1_idx_5;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[4] = vipldws2_B.lastActiveEdgeIdxBdy;
        vipldws2_DW.DrawShapes_DW_Points[6] = vipldws2_B.indxI;

        /* findPointOfIntersectionNormal-4
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.y2;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.y2;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.y2) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt = vipldws2_B.scale * vipldws2_B.acc1_idx_5 +
            vipldws2_B.y2;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.cnt +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[10] = vipldws2_B.activeCol;
        vipldws2_DW.DrawShapes_DW_Points[8] = vipldws2_B.activeColBdy;
        vipldws2_B.numEdge = vipldws2_P.DrawShapes_lineWidth_i >> 1;

        /* getLineParams-1
         */
        /* getLineParams-main fcn
         */
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.Transpose1_p[3] -
          vipldws2_B.Transpose1_p[7];
        vipldws2_B.indxI = vipldws2_B.Transpose1_p[1] - vipldws2_B.Transpose1_p
          [5];
        if (vipldws2_B.indxI == 0) {
          vipldws2_B.scale = 0.0F;
          vipldws2_B.col = 1;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[1] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[1] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[3] - 1);
        } else if (vipldws2_B.lastActiveEdgeIdxBdy == 0) {
          vipldws2_B.col = 2;
          vipldws2_B.scale = 0.0F;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[3] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[3] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[1] - 1);
        } else {
          vipldws2_B.col = 0;
          vipldws2_B.scale = (real32_T)vipldws2_B.lastActiveEdgeIdxBdy /
            (real32_T)vipldws2_B.indxI;
          vipldws2_B.y2 = (real32_T)(vipldws2_B.Transpose1_p[3] - 1) - (real32_T)
            (vipldws2_B.Transpose1_p[1] - 1) * vipldws2_B.scale;
          vipldws2_B.acc4_idx_0 = (real32_T)vipldws2_B.numEdge / ((real32_T)
            vipldws2_B.indxI / (real32_T)sqrt((real32_T)
            (vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.lastActiveEdgeIdxBdy +
             vipldws2_B.indxI * vipldws2_B.indxI)));
          vipldws2_B.cnt = vipldws2_B.y2 + vipldws2_B.acc4_idx_0;
          vipldws2_B.y2 -= vipldws2_B.acc4_idx_0;
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[1] - 1) /
            vipldws2_B.scale + (real32_T)(vipldws2_B.Transpose1_p[3] - 1);
        }

        /* findPointOfIntersectionNormal-1
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.cnt;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.acc4_idx_0
                + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.cnt) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt += vipldws2_B.scale * vipldws2_B.acc1_idx_5;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[1] = vipldws2_B.lastActiveEdgeIdxBdy;
        vipldws2_DW.DrawShapes_DW_Points[3] = vipldws2_B.indxI;

        /* findPointOfIntersectionNormal-2
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.y2;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.y2;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.y2) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt = vipldws2_B.scale * vipldws2_B.acc1_idx_5 +
            vipldws2_B.y2;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.cnt +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[15] = vipldws2_B.activeCol;
        vipldws2_DW.DrawShapes_DW_Points[13] = vipldws2_B.activeColBdy;

        /* getLineParams-2
         */
        /* getLineParams-main fcn
         */
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.Transpose1_p[3] -
          vipldws2_B.Transpose1_p[7];
        vipldws2_B.indxI = vipldws2_B.Transpose1_p[1] - vipldws2_B.Transpose1_p
          [5];
        if (vipldws2_B.indxI == 0) {
          vipldws2_B.scale = 0.0F;
          vipldws2_B.col = 1;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[1] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[1] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[7] - 1);
        } else if (vipldws2_B.lastActiveEdgeIdxBdy == 0) {
          vipldws2_B.col = 2;
          vipldws2_B.scale = 0.0F;
          vipldws2_B.cnt = (real32_T)((vipldws2_B.Transpose1_p[3] -
            vipldws2_B.numEdge) - 1);
          vipldws2_B.y2 = (real32_T)((vipldws2_B.Transpose1_p[3] +
            vipldws2_B.numEdge) - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[5] - 1);
        } else {
          vipldws2_B.col = 0;
          vipldws2_B.scale = (real32_T)vipldws2_B.lastActiveEdgeIdxBdy /
            (real32_T)vipldws2_B.indxI;
          vipldws2_B.y2 = (real32_T)(vipldws2_B.Transpose1_p[3] - 1) - (real32_T)
            (vipldws2_B.Transpose1_p[1] - 1) * vipldws2_B.scale;
          vipldws2_B.acc4_idx_0 = (real32_T)vipldws2_B.numEdge / ((real32_T)
            vipldws2_B.indxI / (real32_T)sqrt((real32_T)
            (vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.lastActiveEdgeIdxBdy +
             vipldws2_B.indxI * vipldws2_B.indxI)));
          vipldws2_B.cnt = vipldws2_B.y2 + vipldws2_B.acc4_idx_0;
          vipldws2_B.y2 -= vipldws2_B.acc4_idx_0;
          vipldws2_B.acc4_idx_0 = (real32_T)(vipldws2_B.Transpose1_p[5] - 1) /
            vipldws2_B.scale + (real32_T)(vipldws2_B.Transpose1_p[7] - 1);
        }

        /* findPointOfIntersectionNormal-3
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.cnt;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.acc4_idx_0
                + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.cnt) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt += vipldws2_B.scale * vipldws2_B.acc1_idx_5;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[5] = vipldws2_B.lastActiveEdgeIdxBdy;
        vipldws2_DW.DrawShapes_DW_Points[7] = vipldws2_B.indxI;

        /* findPointOfIntersectionNormal-4
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.y2;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.y2;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.y2) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt = vipldws2_B.scale * vipldws2_B.acc1_idx_5 +
            vipldws2_B.y2;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.cnt +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[11] = vipldws2_B.activeCol;
        vipldws2_DW.DrawShapes_DW_Points[9] = vipldws2_B.activeColBdy;
      }

      /* ProcessStep-after poly points-1
       */
      vipldws2_B.c2 = 2;

      /* just before call for cgpolygon
       */
      if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
        /* just before call for cgpolygon-2
         */
        vipldws2_B.c2 = 4;
      }

      vipldws2_B.c1 = vipldws2_B.c2 << 1;
      memset(&vipldws2_DW.DrawShapes_DW_PixCount[0], 0, 240U * sizeof(uint8_T));

      /* Reset scanline states. */
      vipldws2_B.plane = 0;
      vipldws2_B.C2 = 0;
      vipldws2_B.planeWidth = 0;
      c_gotAlLeastOneYellowPixelInThe = true;
      while (c_gotAlLeastOneYellowPixelInThe) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        done = false;
        vipldws2_B.numEdge = 0;
        vipldws2_B.qY_g = vipldws2_B.plane;
        vipldws2_B.qY = vipldws2_B.plane;
        idxTmpArray[0U] = (int8_T)(vipldws2_B.c2 - 1);
        vipldws2_B.j = 0;
        while (vipldws2_B.j < 1) {
          /* start for loop
           */
          vipldws2_B.lastActiveEdgeIdxBdy = (((idxTmpArray[0] << 1) + 1) << 1) +
            vipldws2_B.C2;
          vipldws2_B.indxI = (idxTmpArray[0] << 2) + vipldws2_B.C2;
          vipldws2_B.firstRowOut = idxTmpArray[0];
          vipldws2_B.activeColBdy = ((idxTmpArray[0] - 1) << 2) + vipldws2_B.C2;
          vipldws2_B.activeCol = vipldws2_B.c2;
          if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
            /* getLoc-1
             */
            vipldws2_B.colBoundary =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];

            /* getLoc-1
             */
            vipldws2_B.lastRowOut =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws2_B.colBoundary = vipldws2_B.Transpose1_p[vipldws2_B.indxI];

            /* getLoc-2
             */
            vipldws2_B.lastRowOut =
              vipldws2_B.Transpose1_p[vipldws2_B.activeColBdy];
          }

          vipldws2_B.i = vipldws2_B.lastRowOut;
          while ((vipldws2_B.activeColBdy >= 0) && (vipldws2_B.colBoundary - 1 ==
                  vipldws2_B.i - 1)) {
            vipldws2_B.firstRowOut--;
            vipldws2_B.activeColBdy = ((vipldws2_B.firstRowOut - 1) << 2) +
              vipldws2_B.C2;
            vipldws2_B.activeCol--;
            if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
              /* getLoc-1
               */
              vipldws2_B.lastRowOut =
                vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];
            } else {
              /* getLoc-2
               */
              vipldws2_B.lastRowOut =
                vipldws2_B.Transpose1_p[vipldws2_B.activeColBdy];
            }

            vipldws2_B.i = vipldws2_B.lastRowOut;
          }

          if (vipldws2_B.activeColBdy < 0) {
            vipldws2_B.activeColBdy = 0;
          }

          if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
            /* getLoc-1
             */
            vipldws2_B.colBoundary =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];

            /* getLoc-1
             */
            vipldws2_B.lastRowOut =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws2_B.colBoundary = vipldws2_B.Transpose1_p[vipldws2_B.indxI];

            /* getLoc-2
             */
            vipldws2_B.lastRowOut =
              vipldws2_B.Transpose1_p[vipldws2_B.activeColBdy];
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.lastRowOut - 1 >
            vipldws2_B.colBoundary - 1);
          vipldws2_B.colOut = 2 + vipldws2_B.C2;
          vipldws2_B.activeColBdy = vipldws2_B.C2;
          prevEdgeIsVertical = false;
          if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
            /* getLoc-1
             */
            vipldws2_B.colBoundary =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.C2];

            /* getLoc-1
             */
            vipldws2_B.lastRowOut =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];
          } else {
            /* getLoc-2
             */
            vipldws2_B.colBoundary = vipldws2_B.Transpose1_p[vipldws2_B.C2];

            /* getLoc-2
             */
            vipldws2_B.lastRowOut = vipldws2_B.Transpose1_p[vipldws2_B.indxI];
          }

          done = (vipldws2_B.lastRowOut - 1 == vipldws2_B.colBoundary - 1);
          vipldws2_B.i = 0;
          while (vipldws2_B.i < vipldws2_B.activeCol) {
            if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
              /* getLoc-1
               */
              vipldws2_B.colBoundary =
                vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];

              /* getLoc-1
               */
              vipldws2_B.lastRowOut =
                vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];
            } else {
              /* getLoc-2
               */
              vipldws2_B.colBoundary =
                vipldws2_B.Transpose1_p[vipldws2_B.activeColBdy];

              /* getLoc-2
               */
              vipldws2_B.lastRowOut = vipldws2_B.Transpose1_p[vipldws2_B.indxI];
            }

            if (vipldws2_B.lastRowOut - 1 != vipldws2_B.colBoundary - 1) {
              if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
                /* getLoc-1
                 */
                vipldws2_B.colBoundary =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];
              } else {
                /* getLoc-2
                 */
                vipldws2_B.colBoundary =
                  vipldws2_B.Transpose1_p[vipldws2_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws2_B.lastRowOut = vipldws2_B.Transpose1_p[vipldws2_B.indxI];
              }

              if (vipldws2_B.lastRowOut - 1 < vipldws2_B.colBoundary - 1) {
                countTwice = false;
              } else {
                countTwice = true;
                vipldws2_B.firstRowOut = vipldws2_B.lastActiveEdgeIdxBdy;
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
                vipldws2_B.colOut = vipldws2_B.firstRowOut;
                vipldws2_B.firstRowOut = vipldws2_B.indxI;
                vipldws2_B.indxI = vipldws2_B.activeColBdy;
                vipldws2_B.activeColBdy = vipldws2_B.firstRowOut;
              }

              if (vipldws2_P.DrawShapes_lineWidth_i > 1) {
                /* getLoc-1
                 */
                vipldws2_B.colBoundary =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.colOut];

                /* getLoc-1
                 */
                vipldws2_B.lastRow =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];

                /* getLoc-1
                 */
                vipldws2_B.firstRowOut =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.lastActiveEdgeIdxBdy];
              } else {
                /* getLoc-2
                 */
                vipldws2_B.colBoundary =
                  vipldws2_B.Transpose1_p[vipldws2_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_B.Transpose1_p[vipldws2_B.colOut];

                /* getLoc-2
                 */
                vipldws2_B.lastRow = vipldws2_B.Transpose1_p[vipldws2_B.indxI];

                /* getLoc-2
                 */
                vipldws2_B.firstRowOut =
                  vipldws2_B.Transpose1_p[vipldws2_B.lastActiveEdgeIdxBdy];
              }

              /* Initialize a Bresenham line. */
              vipldws2_B.firstRowOut = ((vipldws2_B.firstRowOut - 1) << 3) + 4;
              vipldws2_B.lastRow = ((vipldws2_B.lastRow - 1) << 3) + 4;
              vipldws2_B.lastRowOut = ((vipldws2_B.lastRowOut - 1) << 3) + 4;
              vipldws2_B.colBoundary = ((vipldws2_B.colBoundary - 1) << 3) + 4;
              vipldws2_B.firstRow = vipldws2_B.colBoundary - vipldws2_B.lastRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] = 0;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] =
                vipldws2_B.firstRowOut;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2] =
                vipldws2_B.lastRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] =
                vipldws2_B.colBoundary;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] = 0;
              if (vipldws2_B.lastRowOut >= vipldws2_B.firstRowOut) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] =
                  vipldws2_B.lastRowOut - vipldws2_B.firstRowOut;
              } else {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] =
                  vipldws2_B.firstRowOut - vipldws2_B.lastRowOut;
              }

              while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] >= 0)
              {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6]++;
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] -=
                  vipldws2_B.firstRow;
              }

              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] - 1;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] +
                vipldws2_B.firstRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 4] =
                vipldws2_B.firstRow -
                (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7] << 1);
              if (vipldws2_B.firstRowOut > vipldws2_B.lastRowOut) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5] =
                  -vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] =
                  -vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6];
              }

              if ((!c_gotAlLeastOneYellowPixelInThe) && (!countTwice)) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2]++;
                if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] << 1) >
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 4]) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6];
                } else {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5];
                }
              } else {
                if (c_gotAlLeastOneYellowPixelInThe && countTwice) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3]--;
                }
              }

              c_gotAlLeastOneYellowPixelInThe = countTwice;
              if (!prevEdgeIsVertical) {
                /* Merge two Bresenham lines. */
                if ((vipldws2_B.qY_g != vipldws2_B.qY) &&
                    ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 5] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 6] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 7] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 8] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8]))) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] + 1
                      == vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2]) {
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] =
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3];
                    prevEdgeIsVertical = true;
                  } else {
                    if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] + 1
                        == vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2])
                    {
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 1] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2];
                      prevEdgeIsVertical = true;
                    }
                  }
                }

                if (!prevEdgeIsVertical) {
                  vipldws2_B.qY_g = vipldws2_B.qY;
                  vipldws2_B.numEdge++;
                }
              } else {
                vipldws2_B.qY_g = vipldws2_B.qY;
                vipldws2_B.numEdge++;
              }

              vipldws2_B.qY = vipldws2_B.qY_g + 9;
              if (!countTwice) {
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
                vipldws2_B.indxI = vipldws2_B.activeColBdy;
              }

              vipldws2_B.colOut = vipldws2_B.lastActiveEdgeIdxBdy + 4;
              vipldws2_B.activeColBdy = vipldws2_B.indxI + 4;
              prevEdgeIsVertical = false;
            } else {
              prevEdgeIsVertical = true;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
              vipldws2_B.indxI = vipldws2_B.activeColBdy;
              vipldws2_B.colOut += 4;
              vipldws2_B.activeColBdy += 4;
            }

            vipldws2_B.i++;
          }

          vipldws2_B.j = 1;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((vipldws2_B.plane != vipldws2_B.qY_g) &&
              ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 5] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 5]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 6] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 6]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 7] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 7]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 8] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 8]))) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3] + 1 ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2]) {
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3];
              done = true;
            } else {
              if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] + 1 ==
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2]) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 1] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 1];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2];
                done = true;
              }
            }
          }

          if (done) {
            vipldws2_B.numEdge--;
            vipldws2_B.qY -= 9;
          }
        }

        /* Set all other edges to invalid. */
        vipldws2_B.i = vipldws2_B.numEdge;
        while (vipldws2_B.i < vipldws2_B.c2) {
          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2] = 1;
          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] = 0;
          vipldws2_B.qY += 9;
          vipldws2_B.i++;
        }

        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws2_B.r1 = vipldws2_B.plane;
          vipldws2_B.r2 = vipldws2_B.plane + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.i = 1;
          while (vipldws2_B.i < vipldws2_B.numEdge) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 2] >
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_B.lastSeparator =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j] =
                  vipldws2_B.lastSeparator;
              }
            }

            vipldws2_B.r1 = vipldws2_B.r2;
            vipldws2_B.r2 += 9;
            vipldws2_B.i++;
          }
        }

        /* Find out the last column of the polygon. */
        vipldws2_B.planeOffset = vipldws2_B.plane + 3;
        vipldws2_B.qY_g = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3];
        vipldws2_B.i = 1;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          vipldws2_B.planeOffset += 9;
          if (vipldws2_B.qY_g <
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset]) {
            vipldws2_B.qY_g =
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset];
          }

          vipldws2_B.i++;
        }

        vipldws2_B.qY = vipldws2_B.qY_g;
        if (vipldws2_B.qY_g > 2559) {
          vipldws2_B.qY = 2559;
        }

        /* Find out the first column of the polygon. */
        vipldws2_B.planeOffset = vipldws2_B.plane + 2;
        vipldws2_B.qY_g = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2];
        vipldws2_B.i = 1;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          vipldws2_B.planeOffset += 9;
          if (vipldws2_B.qY_g >
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset]) {
            vipldws2_B.qY_g =
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset];
          }

          vipldws2_B.i++;
        }

        if (vipldws2_B.qY_g < 0) {
          vipldws2_B.qY_g = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        vipldws2_B.r1 = vipldws2_B.plane;
        vipldws2_B.r2 = vipldws2_B.plane;
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.plane;
        vipldws2_B.indxI = 0;
        vipldws2_B.planeOffset = 0;
        vipldws2_B.i = 0;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 3] >=
              vipldws2_B.qY_g) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <=
                vipldws2_B.qY_g) {
              while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <
                     vipldws2_B.qY_g) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]++;
                if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] << 1) >
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 4]) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 8];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 6];
                } else {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 7];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 5];
                }
              }

              vipldws2_B.lastActiveEdgeIdxBdy += 9;
              vipldws2_B.planeOffset++;
            }

            if (vipldws2_B.r2 != vipldws2_B.r1) {
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
              }
            }

            vipldws2_B.r1 += 9;
            vipldws2_B.indxI++;
          }

          vipldws2_B.r2 += 9;
          vipldws2_B.i++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws2_B.r1 = vipldws2_B.plane;
          vipldws2_B.r2 = vipldws2_B.plane + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.i = 1;
          while (vipldws2_B.i < vipldws2_B.planeOffset) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1] >
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_B.lastSeparator =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j] =
                  vipldws2_B.lastSeparator;
              }
            }

            vipldws2_B.r1 = vipldws2_B.r2;
            vipldws2_B.r2 += 9;
            vipldws2_B.i++;
          }
        }

        vipldws2_B.r1 = vipldws2_B.plane;
        vipldws2_B.activeColBdy = vipldws2_B.qY_g + 1;
        vipldws2_B.activeCol = 0;
        vipldws2_B.r2 = 0;
        vipldws2_B.lastSeparator = -1;
        vipldws2_B.colOut = vipldws2_B.qY_g >> 3;
        vipldws2_B.colBoundary = (vipldws2_B.colOut + 1) << 3;
        vipldws2_B.firstRowOut = 240;
        vipldws2_B.lastRowOut = 0;
        c_gotAlLeastOneYellowPixelInThe = (0 <= vipldws2_B.qY);
        while (c_gotAlLeastOneYellowPixelInThe) {
          /* Get a string of pixels */
          countTwice = false;
          done = (vipldws2_B.r2 != 0);
          vipldws2_B.col = vipldws2_B.activeCol;
          if ((vipldws2_B.activeCol >= vipldws2_B.qY_g) && (vipldws2_B.activeCol
               <= vipldws2_B.qY)) {
            if (vipldws2_B.r1 < vipldws2_B.lastActiveEdgeIdxBdy) {
              vipldws2_B.i = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
              vipldws2_B.r1 += 9;
              if ((vipldws2_B.i == vipldws2_B.lastSeparator) && (vipldws2_B.r1 <
                   vipldws2_B.lastActiveEdgeIdxBdy)) {
                vipldws2_B.planeOffset =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
                c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.r1 <
                  vipldws2_B.lastActiveEdgeIdxBdy);
                while (c_gotAlLeastOneYellowPixelInThe && (vipldws2_B.i ==
                        vipldws2_B.planeOffset)) {
                  countTwice = true;
                  vipldws2_B.i = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1
                    + 1];
                  vipldws2_B.r1 += 9;
                  c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.r1 <
                    vipldws2_B.lastActiveEdgeIdxBdy);
                  if (c_gotAlLeastOneYellowPixelInThe) {
                    vipldws2_B.planeOffset =
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
                  }
                }

                if (!c_gotAlLeastOneYellowPixelInThe) {
                  countTwice = false;
                }
              }

              if (vipldws2_B.r2 != 0) {
                vipldws2_B.firstRow = vipldws2_B.lastSeparator;
                if (vipldws2_B.i <= 1919) {
                  vipldws2_B.lastRow = vipldws2_B.i;
                  vipldws2_B.lastSeparator = vipldws2_B.i;
                } else {
                  vipldws2_B.lastRow = 1919;
                  vipldws2_B.lastSeparator = 1919;
                }
              } else {
                vipldws2_B.firstRow = vipldws2_B.lastSeparator + 1;
                if ((vipldws2_B.i > 0) && (vipldws2_B.i <= 1919)) {
                  vipldws2_B.lastRow = vipldws2_B.i - 1;
                  vipldws2_B.lastSeparator = vipldws2_B.i;
                } else if (vipldws2_B.i <= 0) {
                  vipldws2_B.lastRow = -1;
                  vipldws2_B.lastSeparator = 0;
                } else {
                  vipldws2_B.lastRow = 1919;
                  vipldws2_B.lastSeparator = 1920;
                }
              }

              if (!countTwice) {
                vipldws2_B.r2 = !(vipldws2_B.r2 != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              vipldws2_B.firstRow = vipldws2_B.lastSeparator + 1;
              vipldws2_B.lastRow = 1919;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              vipldws2_B.r1 = vipldws2_B.plane;
              vipldws2_B.r2 = vipldws2_B.plane;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.plane;
              vipldws2_B.numEdge = 0;
              vipldws2_B.planeOffset = 0;
              vipldws2_B.i = 0;
              while (vipldws2_B.i < vipldws2_B.indxI) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 3] >=
                    vipldws2_B.activeColBdy) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <=
                      vipldws2_B.activeColBdy) {
                    while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <
                           vipldws2_B.activeColBdy) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]++;
                      if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] << 1)
                          > vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 4])
                      {
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 8];
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 6];
                      } else {
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 7];
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 5];
                      }
                    }

                    vipldws2_B.lastActiveEdgeIdxBdy += 9;
                    vipldws2_B.planeOffset++;
                  }

                  if (vipldws2_B.r2 != vipldws2_B.r1) {
                    for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j];
                    }
                  }

                  vipldws2_B.r1 += 9;
                  vipldws2_B.numEdge++;
                }

                vipldws2_B.r2 += 9;
                vipldws2_B.i++;
              }

              vipldws2_B.indxI = vipldws2_B.numEdge;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (c_gotAlLeastOneYellowPixelInThe) {
                vipldws2_B.r1 = vipldws2_B.plane;
                vipldws2_B.r2 = vipldws2_B.plane + 9;
                c_gotAlLeastOneYellowPixelInThe = false;
                vipldws2_B.i = 1;
                while (vipldws2_B.i < vipldws2_B.planeOffset) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1] >
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1]) {
                    c_gotAlLeastOneYellowPixelInThe = true;
                    for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                      vipldws2_B.lastSeparator =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j] = vipldws2_B.lastSeparator;
                    }
                  }

                  vipldws2_B.r1 = vipldws2_B.r2;
                  vipldws2_B.r2 += 9;
                  vipldws2_B.i++;
                }
              }

              vipldws2_B.r1 = vipldws2_B.plane;
              vipldws2_B.activeColBdy++;
              vipldws2_B.r2 = 0;
              vipldws2_B.lastSeparator = -1;
              vipldws2_B.activeCol++;
            }
          } else {
            vipldws2_B.firstRow = 0;
            vipldws2_B.lastRow = 1919;
            vipldws2_B.activeCol++;
          }

          if (vipldws2_B.firstRow < 0) {
            vipldws2_B.firstRow = 0;
          }

          if (vipldws2_B.lastRow < vipldws2_B.firstRow) {
            vipldws2_B.lastRow = vipldws2_B.firstRow - 1;
          }

          if (done && ((vipldws2_B.lastRow > 0) && (vipldws2_B.firstRow < 1919)))
          {
            if (vipldws2_B.lastRow > 1919) {
              vipldws2_B.lastRow = 1919;
            }

            vipldws2_B.planeOffset = vipldws2_B.firstRow >> 3;
            vipldws2_B.i = vipldws2_B.lastRow >> 3;
            if (vipldws2_B.firstRowOut > vipldws2_B.planeOffset) {
              vipldws2_B.firstRowOut = vipldws2_B.planeOffset;
            }

            if (vipldws2_B.lastRowOut < vipldws2_B.i) {
              vipldws2_B.lastRowOut = vipldws2_B.i;
            }

            if (vipldws2_B.i > vipldws2_B.planeOffset) {
              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                (uint8_T)(((uint32_T)((vipldws2_B.planeOffset + 1) << 3) +
                           vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset])
                          - vipldws2_B.firstRow);
              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] = (uint8_T)
                ((((uint32_T)vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] +
                   vipldws2_B.lastRow) - (vipldws2_B.i << 3)) + 1U);
              vipldws2_B.numEdge = vipldws2_B.planeOffset + 1;
              while (vipldws2_B.numEdge < vipldws2_B.i) {
                vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] =
                  (uint8_T)
                  (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] + 8U);
                vipldws2_B.numEdge++;
              }
            } else {
              if (vipldws2_B.i == vipldws2_B.planeOffset) {
                vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                  (uint8_T)((((uint32_T)
                              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset]
                              + vipldws2_B.lastRow) - vipldws2_B.firstRow) + 1U);
              }
            }
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.activeCol <=
            vipldws2_B.qY);
          if (((vipldws2_B.colBoundary - 1 == vipldws2_B.col) ||
               (!c_gotAlLeastOneYellowPixelInThe)) && (vipldws2_B.lastRow >=
               1919)) {
            vipldws2_B.j = vipldws2_B.colOut * 240 + vipldws2_B.firstRowOut;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.numEdge = vipldws2_B.firstRowOut;
            while (vipldws2_B.numEdge <= vipldws2_B.lastRowOut) {
              if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] == 64)
              {
                vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                  vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeWidth] -
                  vipldws2_B.DrawShapes_m[vipldws2_B.col];
              } else {
                vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                  (vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeWidth]
                   - vipldws2_B.DrawShapes_m[vipldws2_B.col]) * (real32_T)
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] / 64.0F;
              }

              vipldws2_B.col++;
              vipldws2_B.numEdge++;
            }

            vipldws2_B.j += 76800;
            vipldws2_B.planeOffset = vipldws2_B.planeWidth + 2;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.numEdge = vipldws2_B.firstRowOut;
            while (vipldws2_B.numEdge <= vipldws2_B.lastRowOut) {
              if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] == 64)
              {
                vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                  vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                  - vipldws2_B.DrawShapes_m[vipldws2_B.col];
              } else {
                vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                  (vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                   - vipldws2_B.DrawShapes_m[vipldws2_B.col]) * (real32_T)
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] / 64.0F;
              }

              vipldws2_B.col++;
              vipldws2_B.numEdge++;
            }

            vipldws2_B.j += 76800;
            vipldws2_B.planeOffset += 2;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.numEdge = vipldws2_B.firstRowOut;
            while (vipldws2_B.numEdge <= vipldws2_B.lastRowOut) {
              if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] == 64)
              {
                vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                  vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                  - vipldws2_B.DrawShapes_m[vipldws2_B.col];
              } else {
                vipldws2_B.DrawShapes_m[vipldws2_B.col] +=
                  (vipldws2_P.DrawShapes_RTP_FILLCOLOR_f[vipldws2_B.planeOffset]
                   - vipldws2_B.DrawShapes_m[vipldws2_B.col]) * (real32_T)
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] / 64.0F;
              }

              vipldws2_B.col++;
              vipldws2_B.numEdge++;
            }

            while (vipldws2_B.firstRowOut <= vipldws2_B.lastRowOut) {
              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] = 0U;
              vipldws2_B.firstRowOut++;
            }

            vipldws2_B.colOut++;
            vipldws2_B.colBoundary += 8;
            vipldws2_B.firstRowOut = 240;
            vipldws2_B.lastRowOut = 0;
          }
        }

        if (vipldws2_B.planeWidth < 3) {
          vipldws2_B.planeWidth++;
        } else {
          vipldws2_B.planeWidth = 0;
        }

        /* Move to the next polygon. */
        vipldws2_B.plane += vipldws2_B.c2 * 9;
        if (vipldws2_B.C2 >= div_s32_floor(vipldws2_B.c1, vipldws2_B.c2) - 1) {
          vipldws2_B.C2 = 0;
        } else {
          vipldws2_B.C2++;
        }

        c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.plane < (vipldws2_B.c2 <<
          1) * 9);
      }
    }

    /* End of S-Function (svipdrawshapes): '<S67>/DrawShapes' */

    /* FromWorkspace: '<S70>/From Workspace' */
    {
      int_T currIndex = vipldws2_DW.FromWorkspace_IWORK.PrevIndex+1;
      real32_T *pDataValues = (real32_T *)
        vipldws2_DW.FromWorkspace_PWORK.DataPtr;
      if (currIndex >= 4) {
        currIndex = 0;
      }

      if (currIndex < 4) {
        pDataValues += currIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&vipldws2_B.Selector5[0])[elIdx] = *pDataValues;
            pDataValues += 4;
          }
        }
      } else {
        pDataValues += (3);

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&vipldws2_B.Selector5[0])[elIdx] = *pDataValues;
            pDataValues += 4;
          }
        }
      }

      vipldws2_DW.FromWorkspace_IWORK.PrevIndex = currIndex;
    }

    /* S-Function (sviptextrender): '<S67>/Insert Text' */
    /* put the pen at the beginning of the string */
    vipldws2_B.planeWidth = 1;

    /* copy input to output since Simulink isn't giving us in-place operation */
    memcpy(&vipldws2_B.InsertText[0], &vipldws2_B.DrawShapes_m[0], 230400U *
           sizeof(real32_T));
    done = false;
    while (vipldws2_B.planeWidth > 0) {
      c_gotAlLeastOneYellowPixelInThe = true;
      if (vipldws2_P.InsertText_TxtOpacity == 0.0F) {
        c_gotAlLeastOneYellowPixelInThe = false;
      }

      /* copy location to int32 container */
      vipldws2_B.planeOffset = vipldws2_P.InsertText_textLoc[0] - 1;

      /* update the color/intensity */
      vipldws2_DW.InsertText_colorVectorDW[0] = vipldws2_B.Selector5[0];

      /* Saturate color values */
      if (vipldws2_DW.InsertText_colorVectorDW[0] < 0.0F) {
        vipldws2_DW.InsertText_colorVectorDW[0] = 0.0F;
      } else {
        if (vipldws2_DW.InsertText_colorVectorDW[0] > 1.0F) {
          vipldws2_DW.InsertText_colorVectorDW[0] = 1.0F;
        }
      }

      vipldws2_DW.InsertText_colorVectorDW[1] = vipldws2_B.Selector5[1];

      /* Saturate color values */
      if (vipldws2_DW.InsertText_colorVectorDW[1] < 0.0F) {
        vipldws2_DW.InsertText_colorVectorDW[1] = 0.0F;
      } else {
        if (vipldws2_DW.InsertText_colorVectorDW[1] > 1.0F) {
          vipldws2_DW.InsertText_colorVectorDW[1] = 1.0F;
        }
      }

      vipldws2_DW.InsertText_colorVectorDW[2] = vipldws2_B.Selector5[2];

      /* Saturate color values */
      if (vipldws2_DW.InsertText_colorVectorDW[2] < 0.0F) {
        vipldws2_DW.InsertText_colorVectorDW[2] = 0.0F;
      } else {
        if (vipldws2_DW.InsertText_colorVectorDW[2] > 1.0F) {
          vipldws2_DW.InsertText_colorVectorDW[2] = 1.0F;
        }
      }

      /* copy selection to uint32 container */
      vipldws2_B.fromIdx = vipldws2_B.Bias_h - 1U;
      if (vipldws2_B.fromIdx >= 3U) {
        done = true;
        vipldws2_B.planeWidth = -1;
      } else {
        vipldws2_B.textIdx = (int32_T)
          vipldws2_ConstP.InsertText_stringRTP[vipldws2_B.fromIdx];
      }

      if (!done) {
        vipldws2_B.i = MWVIP_strlen
          (&vipldws2_DW.InsertText_StringDataDW[vipldws2_B.textIdx]);
        vipldws2_B.planeWidth = 0;
        if (c_gotAlLeastOneYellowPixelInThe) {
          /* put the pen at the beginning of the string */
          vipldws2_B.C2 = vipldws2_P.InsertText_textLoc[0] - 1;
          vipldws2_B.c2 = vipldws2_P.InsertText_textLoc[1];
          vipldws2_B.c1 = 0;
          while (vipldws2_B.c1 < vipldws2_B.i) {
            if (vipldws2_DW.InsertText_StringDataDW[vipldws2_B.textIdx +
                vipldws2_B.c1] == 10) {
              vipldws2_B.c2 += 23;
              vipldws2_B.C2 = vipldws2_B.planeOffset;
            } else {
              vipldws2_B.r2 =
                vipldws2_DW.InsertText_StringDataDW[vipldws2_B.textIdx +
                vipldws2_B.c1];
              vipldws2_B.r1 = (int32_T)
                vipldws2_ConstP.InsertText_GlyIndexes[vipldws2_B.r2];
              if (!((vipldws2_ConstP.InsertText_GlyWidths[vipldws2_B.r2] != 0) &&
                    (vipldws2_ConstP.InsertText_GlyHeights[vipldws2_B.r2] != 0) &&
                    (vipldws2_ConstP.InsertText_GlyXAdvances[vipldws2_B.r2] != 0)))
              {
                vipldws2_B.r2 = 32;
                vipldws2_B.r1 = 0;
              }

              vipldws2_B.scale = vipldws2_P.InsertText_TxtOpacity;
              MWVIP_DrawText_I_single_AA
                (&vipldws2_ConstP.InsertText_GlyData[vipldws2_B.r1],
                 vipldws2_B.C2, vipldws2_B.c2 + 18,
                 vipldws2_ConstP.InsertText_GlyLBearings[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyTBearings[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyWidths[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyHeights[vipldws2_B.r2], 320U,
                 240U, &vipldws2_B.InsertText[0],
                 &vipldws2_DW.InsertText_colorVectorDW[0], &vipldws2_B.scale,
                 false);
              MWVIP_DrawText_I_single_AA
                (&vipldws2_ConstP.InsertText_GlyData[vipldws2_B.r1],
                 vipldws2_B.C2, vipldws2_B.c2 + 18,
                 vipldws2_ConstP.InsertText_GlyLBearings[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyTBearings[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyWidths[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyHeights[vipldws2_B.r2], 320U,
                 240U, &vipldws2_B.InsertText[76800],
                 &vipldws2_DW.InsertText_colorVectorDW[1], &vipldws2_B.scale,
                 false);
              MWVIP_DrawText_I_single_AA
                (&vipldws2_ConstP.InsertText_GlyData[vipldws2_B.r1],
                 vipldws2_B.C2, vipldws2_B.c2 + 18,
                 vipldws2_ConstP.InsertText_GlyLBearings[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyTBearings[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyWidths[vipldws2_B.r2],
                 vipldws2_ConstP.InsertText_GlyHeights[vipldws2_B.r2], 320U,
                 240U, &vipldws2_B.InsertText[153600],
                 &vipldws2_DW.InsertText_colorVectorDW[2], &vipldws2_B.scale,
                 false);
              vipldws2_B.C2 +=
                vipldws2_ConstP.InsertText_GlyXAdvances[vipldws2_B.r2];
            }

            vipldws2_B.c1++;
          }
        }
      }
    }

    /* End of S-Function (sviptextrender): '<S67>/Insert Text' */

    /* Selector: '<S69>/Selector4' incorporates:
     *  Constant: '<S69>/Yellow1'
     */
    vipldws2_B.Selector5[0] = vipldws2_P.Yellow1_Value[(vipldws2_B.Bias1_j[0] -
      1) * 3];
    vipldws2_B.Selector5[1] = vipldws2_P.Yellow1_Value[(vipldws2_B.Bias1_j[0] -
      1) * 3 + 1];
    vipldws2_B.Selector5[2] = vipldws2_P.Yellow1_Value[(vipldws2_B.Bias1_j[0] -
      1) * 3 + 2];

    /* Selector: '<S69>/Selector6' */
    vipldws2_B.Selector7[0] = vipldws2_B.Transpose2[1];
    vipldws2_B.Selector7[1] = vipldws2_B.Transpose2[0];

    /* Math: '<S69>/Transpose1' */
    vipldws2_B.Transpose2[0] = vipldws2_B.Selector7[0];
    vipldws2_B.Transpose2[1] = vipldws2_B.Selector7[1];

    /* S-Function (sviptextrender): '<S69>/Insert Text: Left Lane' */
    /* put the pen at the beginning of the string */
    vipldws2_B.planeWidth = 1;

    /* copy input to output since Simulink isn't giving us in-place operation */
    memcpy(&vipldws2_B.InsertTextLeftLane[0], &vipldws2_B.InsertText[0], 230400U
           * sizeof(real32_T));
    done = false;
    while (vipldws2_B.planeWidth > 0) {
      c_gotAlLeastOneYellowPixelInThe = true;
      if (vipldws2_P.InsertTextLeftLane_TxtOpacity == 0.0F) {
        c_gotAlLeastOneYellowPixelInThe = false;
      }

      /* copy location to int32 container */
      vipldws2_B.planeOffset = vipldws2_B.Transpose2[0] - 1;

      /* update the color/intensity */
      vipldws2_DW.InsertTextLeftLane_colorVectorD[0] = vipldws2_B.Selector5[0];

      /* Saturate color values */
      if (vipldws2_DW.InsertTextLeftLane_colorVectorD[0] < 0.0F) {
        vipldws2_DW.InsertTextLeftLane_colorVectorD[0] = 0.0F;
      } else {
        if (vipldws2_DW.InsertTextLeftLane_colorVectorD[0] > 1.0F) {
          vipldws2_DW.InsertTextLeftLane_colorVectorD[0] = 1.0F;
        }
      }

      vipldws2_DW.InsertTextLeftLane_colorVectorD[1] = vipldws2_B.Selector5[1];

      /* Saturate color values */
      if (vipldws2_DW.InsertTextLeftLane_colorVectorD[1] < 0.0F) {
        vipldws2_DW.InsertTextLeftLane_colorVectorD[1] = 0.0F;
      } else {
        if (vipldws2_DW.InsertTextLeftLane_colorVectorD[1] > 1.0F) {
          vipldws2_DW.InsertTextLeftLane_colorVectorD[1] = 1.0F;
        }
      }

      vipldws2_DW.InsertTextLeftLane_colorVectorD[2] = vipldws2_B.Selector5[2];

      /* Saturate color values */
      if (vipldws2_DW.InsertTextLeftLane_colorVectorD[2] < 0.0F) {
        vipldws2_DW.InsertTextLeftLane_colorVectorD[2] = 0.0F;
      } else {
        if (vipldws2_DW.InsertTextLeftLane_colorVectorD[2] > 1.0F) {
          vipldws2_DW.InsertTextLeftLane_colorVectorD[2] = 1.0F;
        }
      }

      /* copy selection to uint32 container */
      vipldws2_B.fromIdx = vipldws2_B.Bias1_j[0] - 1U;
      if (vipldws2_B.fromIdx >= 5U) {
        done = true;
        vipldws2_B.planeWidth = -1;
      } else {
        vipldws2_B.textIdx_f = (int32_T)
          vipldws2_ConstP.pooled9[vipldws2_B.fromIdx];
      }

      if (!done) {
        vipldws2_B.i = MWVIP_strlen
          (&vipldws2_DW.InsertTextLeftLane_StringDataDW[vipldws2_B.textIdx_f]);
        vipldws2_B.planeWidth = 0;
        if (c_gotAlLeastOneYellowPixelInThe) {
          /* put the pen at the beginning of the string */
          vipldws2_B.C2 = vipldws2_B.Transpose2[0] - 1;
          vipldws2_B.c2 = vipldws2_B.Transpose2[1];
          vipldws2_B.c1 = 0;
          while (vipldws2_B.c1 < vipldws2_B.i) {
            if (vipldws2_DW.InsertTextLeftLane_StringDataDW[vipldws2_B.textIdx_f
                + vipldws2_B.c1] == 10) {
              vipldws2_B.c2 += 16;
              vipldws2_B.C2 = vipldws2_B.planeOffset;
            } else {
              vipldws2_B.r2 =
                vipldws2_DW.InsertTextLeftLane_StringDataDW[vipldws2_B.textIdx_f
                + vipldws2_B.c1];
              vipldws2_B.r1 = (int32_T)vipldws2_ConstP.pooled8[vipldws2_B.r2];
              if (!((vipldws2_ConstP.pooled11[vipldws2_B.r2] != 0) &&
                    (vipldws2_ConstP.pooled12[vipldws2_B.r2] != 0) &&
                    (vipldws2_ConstP.pooled13[vipldws2_B.r2] != 0))) {
                vipldws2_B.r2 = 32;
                vipldws2_B.r1 = 0;
              }

              vipldws2_B.scale = vipldws2_P.InsertTextLeftLane_TxtOpacity;
              MWVIP_DrawText_I_single_AA(&vipldws2_ConstP.pooled16[vipldws2_B.r1],
                vipldws2_B.C2, vipldws2_B.c2 + 12,
                vipldws2_ConstP.pooled2[vipldws2_B.r2],
                vipldws2_ConstP.pooled3[vipldws2_B.r2],
                vipldws2_ConstP.pooled11[vipldws2_B.r2],
                vipldws2_ConstP.pooled12[vipldws2_B.r2], 320U, 240U,
                &vipldws2_B.InsertTextLeftLane[0],
                &vipldws2_DW.InsertTextLeftLane_colorVectorD[0],
                &vipldws2_B.scale, false);
              MWVIP_DrawText_I_single_AA(&vipldws2_ConstP.pooled16[vipldws2_B.r1],
                vipldws2_B.C2, vipldws2_B.c2 + 12,
                vipldws2_ConstP.pooled2[vipldws2_B.r2],
                vipldws2_ConstP.pooled3[vipldws2_B.r2],
                vipldws2_ConstP.pooled11[vipldws2_B.r2],
                vipldws2_ConstP.pooled12[vipldws2_B.r2], 320U, 240U,
                &vipldws2_B.InsertTextLeftLane[76800],
                &vipldws2_DW.InsertTextLeftLane_colorVectorD[1],
                &vipldws2_B.scale, false);
              MWVIP_DrawText_I_single_AA(&vipldws2_ConstP.pooled16[vipldws2_B.r1],
                vipldws2_B.C2, vipldws2_B.c2 + 12,
                vipldws2_ConstP.pooled2[vipldws2_B.r2],
                vipldws2_ConstP.pooled3[vipldws2_B.r2],
                vipldws2_ConstP.pooled11[vipldws2_B.r2],
                vipldws2_ConstP.pooled12[vipldws2_B.r2], 320U, 240U,
                &vipldws2_B.InsertTextLeftLane[153600],
                &vipldws2_DW.InsertTextLeftLane_colorVectorD[2],
                &vipldws2_B.scale, false);
              vipldws2_B.C2 += vipldws2_ConstP.pooled13[vipldws2_B.r2];
            }

            vipldws2_B.c1++;
          }
        }
      }
    }

    /* End of S-Function (sviptextrender): '<S69>/Insert Text: Left Lane' */

    /* Selector: '<S69>/Selector5' incorporates:
     *  Constant: '<S69>/Yellow1'
     */
    vipldws2_B.Selector5[0] = vipldws2_P.Yellow1_Value[(vipldws2_B.Bias1_j[1] -
      1) * 3];
    vipldws2_B.Selector5[1] = vipldws2_P.Yellow1_Value[(vipldws2_B.Bias1_j[1] -
      1) * 3 + 1];
    vipldws2_B.Selector5[2] = vipldws2_P.Yellow1_Value[(vipldws2_B.Bias1_j[1] -
      1) * 3 + 2];

    /* Selector: '<S69>/Selector7' */
    vipldws2_B.Selector7[0] = vipldws2_B.Bias2[1];

    /* Math: '<S69>/Transpose2' */
    vipldws2_B.Transpose2[0] = vipldws2_B.Selector7[0];

    /* Selector: '<S69>/Selector7' */
    vipldws2_B.Selector7[1] = vipldws2_B.Bias2[0];

    /* Math: '<S69>/Transpose2' */
    vipldws2_B.Transpose2[1] = vipldws2_B.Selector7[1];

    /* S-Function (sviptextrender): '<S69>/Insert Text: Right Lane' */
    /* put the pen at the beginning of the string */
    vipldws2_B.planeWidth = 1;

    /* copy input to output since Simulink isn't giving us in-place operation */
    memcpy(&vipldws2_B.InsertTextRightLane[0], &vipldws2_B.InsertTextLeftLane[0],
           230400U * sizeof(real32_T));
    done = false;
    while (vipldws2_B.planeWidth > 0) {
      c_gotAlLeastOneYellowPixelInThe = true;
      if (vipldws2_P.InsertTextRightLane_TxtOpacity == 0.0F) {
        c_gotAlLeastOneYellowPixelInThe = false;
      }

      /* copy location to int32 container */
      vipldws2_B.planeOffset = vipldws2_B.Transpose2[0] - 1;

      /* update the color/intensity */
      vipldws2_DW.InsertTextRightLane_colorVector[0] = vipldws2_B.Selector5[0];

      /* Saturate color values */
      if (vipldws2_DW.InsertTextRightLane_colorVector[0] < 0.0F) {
        vipldws2_DW.InsertTextRightLane_colorVector[0] = 0.0F;
      } else {
        if (vipldws2_DW.InsertTextRightLane_colorVector[0] > 1.0F) {
          vipldws2_DW.InsertTextRightLane_colorVector[0] = 1.0F;
        }
      }

      vipldws2_DW.InsertTextRightLane_colorVector[1] = vipldws2_B.Selector5[1];

      /* Saturate color values */
      if (vipldws2_DW.InsertTextRightLane_colorVector[1] < 0.0F) {
        vipldws2_DW.InsertTextRightLane_colorVector[1] = 0.0F;
      } else {
        if (vipldws2_DW.InsertTextRightLane_colorVector[1] > 1.0F) {
          vipldws2_DW.InsertTextRightLane_colorVector[1] = 1.0F;
        }
      }

      vipldws2_DW.InsertTextRightLane_colorVector[2] = vipldws2_B.Selector5[2];

      /* Saturate color values */
      if (vipldws2_DW.InsertTextRightLane_colorVector[2] < 0.0F) {
        vipldws2_DW.InsertTextRightLane_colorVector[2] = 0.0F;
      } else {
        if (vipldws2_DW.InsertTextRightLane_colorVector[2] > 1.0F) {
          vipldws2_DW.InsertTextRightLane_colorVector[2] = 1.0F;
        }
      }

      /* copy selection to uint32 container */
      vipldws2_B.fromIdx = vipldws2_B.Bias1_j[1] - 1U;
      if (vipldws2_B.fromIdx >= 5U) {
        done = true;
        vipldws2_B.planeWidth = -1;
      } else {
        vipldws2_B.s40_iter = (int32_T)
          vipldws2_ConstP.pooled9[vipldws2_B.fromIdx];
      }

      if (!done) {
        vipldws2_B.i = MWVIP_strlen
          (&vipldws2_DW.InsertTextRightLane_StringDataD[vipldws2_B.s40_iter]);
        vipldws2_B.planeWidth = 0;
        if (c_gotAlLeastOneYellowPixelInThe) {
          /* put the pen at the beginning of the string */
          vipldws2_B.C2 = vipldws2_B.Transpose2[0] - 1;
          vipldws2_B.c2 = vipldws2_B.Transpose2[1];
          vipldws2_B.c1 = 0;
          while (vipldws2_B.c1 < vipldws2_B.i) {
            if (vipldws2_DW.InsertTextRightLane_StringDataD[vipldws2_B.s40_iter
                + vipldws2_B.c1] == 10) {
              vipldws2_B.c2 += 16;
              vipldws2_B.C2 = vipldws2_B.planeOffset;
            } else {
              vipldws2_B.r2 =
                vipldws2_DW.InsertTextRightLane_StringDataD[vipldws2_B.s40_iter
                + vipldws2_B.c1];
              vipldws2_B.r1 = (int32_T)vipldws2_ConstP.pooled8[vipldws2_B.r2];
              if (!((vipldws2_ConstP.pooled11[vipldws2_B.r2] != 0) &&
                    (vipldws2_ConstP.pooled12[vipldws2_B.r2] != 0) &&
                    (vipldws2_ConstP.pooled13[vipldws2_B.r2] != 0))) {
                vipldws2_B.r2 = 32;
                vipldws2_B.r1 = 0;
              }

              vipldws2_B.scale = vipldws2_P.InsertTextRightLane_TxtOpacity;
              MWVIP_DrawText_I_single_AA(&vipldws2_ConstP.pooled16[vipldws2_B.r1],
                vipldws2_B.C2, vipldws2_B.c2 + 12,
                vipldws2_ConstP.pooled2[vipldws2_B.r2],
                vipldws2_ConstP.pooled3[vipldws2_B.r2],
                vipldws2_ConstP.pooled11[vipldws2_B.r2],
                vipldws2_ConstP.pooled12[vipldws2_B.r2], 320U, 240U,
                &vipldws2_B.InsertTextRightLane[0],
                &vipldws2_DW.InsertTextRightLane_colorVector[0],
                &vipldws2_B.scale, false);
              MWVIP_DrawText_I_single_AA(&vipldws2_ConstP.pooled16[vipldws2_B.r1],
                vipldws2_B.C2, vipldws2_B.c2 + 12,
                vipldws2_ConstP.pooled2[vipldws2_B.r2],
                vipldws2_ConstP.pooled3[vipldws2_B.r2],
                vipldws2_ConstP.pooled11[vipldws2_B.r2],
                vipldws2_ConstP.pooled12[vipldws2_B.r2], 320U, 240U,
                &vipldws2_B.InsertTextRightLane[76800],
                &vipldws2_DW.InsertTextRightLane_colorVector[1],
                &vipldws2_B.scale, false);
              MWVIP_DrawText_I_single_AA(&vipldws2_ConstP.pooled16[vipldws2_B.r1],
                vipldws2_B.C2, vipldws2_B.c2 + 12,
                vipldws2_ConstP.pooled2[vipldws2_B.r2],
                vipldws2_ConstP.pooled3[vipldws2_B.r2],
                vipldws2_ConstP.pooled11[vipldws2_B.r2],
                vipldws2_ConstP.pooled12[vipldws2_B.r2], 320U, 240U,
                &vipldws2_B.InsertTextRightLane[153600],
                &vipldws2_DW.InsertTextRightLane_colorVector[2],
                &vipldws2_B.scale, false);
              vipldws2_B.C2 += vipldws2_ConstP.pooled13[vipldws2_B.r2];
            }

            vipldws2_B.c1++;
          }
        }
      }
    }

    /* End of S-Function (sviptextrender): '<S69>/Insert Text: Right Lane' */
    srUpdateBC(vipldws2_DW.Subsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S5>/Subsystem' */

  /* Switch: '<S5>/Switch' */
  if (vipldws2_B.NSampleEnable) {
    memcpy(&vipldws2_B.Switch[0], &vipldws2_B.InsertTextRightLane[0], 230400U *
           sizeof(real32_T));
  } else {
    memcpy(&vipldws2_B.Switch[0], &vipldws2_B.ImageDataTypeConversion[0],
           230400U * sizeof(real32_T));
  }

  /* End of Switch: '<S5>/Switch' */

  /* Outputs for Enabled SubSystem: '<S5>/Draw  3rd Line' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  if (vipldws2_B.LogicalOperator2) {
    /* SignalConversion: '<S65>/TmpSignal ConversionAtDrawShapesInport2' */
    vipldws2_B.TmpSignalConversionAtDrawShapes[0] = vipldws2_B.Bias3[1];
    vipldws2_B.TmpSignalConversionAtDrawShapes[1] = vipldws2_B.Bias3[0];
    vipldws2_B.TmpSignalConversionAtDrawShapes[2] = vipldws2_B.Bias3[3];
    vipldws2_B.TmpSignalConversionAtDrawShapes[3] = vipldws2_B.Bias3[2];

    /* S-Function (svipdrawshapes): '<S65>/DrawShapes' */
    if (vipldws2_P.DrawShapes_lineWidth == 1) {
      /* Compute output for unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws2_B.DrawShapes_l[0], &vipldws2_B.Switch[0], 230400U *
             sizeof(real32_T));

      /* Update view port. */
      vipldws2_B.qY_g = vipldws2_B.TmpSignalConversionAtDrawShapes[1] - 1;
      vipldws2_B.qY = vipldws2_B.TmpSignalConversionAtDrawShapes[0] - 1;
      if ((vipldws2_B.TmpSignalConversionAtDrawShapes[3] - 1 != vipldws2_B.qY_g)
          || (vipldws2_B.TmpSignalConversionAtDrawShapes[2] - 1 != vipldws2_B.qY))
      {
        c_gotAlLeastOneYellowPixelInThe = false;
        vipldws2_B.qY_g = (vipldws2_B.qY_g << 3) + 4;
        vipldws2_B.j = ((vipldws2_B.TmpSignalConversionAtDrawShapes[3] - 1) << 3)
          + 4;
        vipldws2_B.qY = (vipldws2_B.qY << 3) + 4;
        vipldws2_B.numEdge = ((vipldws2_B.TmpSignalConversionAtDrawShapes[2] - 1)
                              << 3) + 4;

        /* Find the visible portion of a line. */
        countTwice = false;
        prevEdgeIsVertical = false;
        done = false;
        vipldws2_B.indxI = vipldws2_B.qY_g;
        vipldws2_B.c2 = vipldws2_B.qY;
        vipldws2_B.C2 = vipldws2_B.j;
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.numEdge;
        while (!done) {
          vipldws2_B.fromIdx = 0U;
          vipldws2_B.toIdx = 0U;

          /* Determine viewport violations. */
          if (vipldws2_B.indxI < 0) {
            vipldws2_B.fromIdx = 4U;
          } else {
            if (vipldws2_B.indxI > 1919) {
              vipldws2_B.fromIdx = 8U;
            }
          }

          if (vipldws2_B.C2 < 0) {
            vipldws2_B.toIdx = 4U;
          } else {
            if (vipldws2_B.C2 > 1919) {
              vipldws2_B.toIdx = 8U;
            }
          }

          if (vipldws2_B.c2 < 0) {
            vipldws2_B.fromIdx |= 1U;
          } else {
            if (vipldws2_B.c2 > 2559) {
              vipldws2_B.fromIdx |= 2U;
            }
          }

          if (vipldws2_B.lastActiveEdgeIdxBdy < 0) {
            vipldws2_B.toIdx |= 1U;
          } else {
            if (vipldws2_B.lastActiveEdgeIdxBdy > 2559) {
              vipldws2_B.toIdx |= 2U;
            }
          }

          if (!((vipldws2_B.fromIdx | vipldws2_B.toIdx) != 0U)) {
            /* Line falls completely within bounds. */
            done = true;
            c_gotAlLeastOneYellowPixelInThe = true;
          } else if ((vipldws2_B.fromIdx & vipldws2_B.toIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            c_gotAlLeastOneYellowPixelInThe = false;
          } else if (vipldws2_B.fromIdx != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (countTwice) {
              vipldws2_B.indxI = vipldws2_B.qY_g;
              vipldws2_B.c2 = vipldws2_B.qY;
            }

            vipldws2_B.i = vipldws2_B.C2 - vipldws2_B.indxI;
            vipldws2_B.planeOffset = vipldws2_B.lastActiveEdgeIdxBdy -
              vipldws2_B.c2;
            if ((vipldws2_B.i > 1073741824) || (vipldws2_B.i < -1073741824) ||
                ((vipldws2_B.planeOffset > 1073741824) ||
                 (vipldws2_B.planeOffset < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = false;
              countTwice = true;
            } else if ((vipldws2_B.fromIdx & 4U) != 0U) {
              /* Violated RMin. */
              vipldws2_B.c1 = -vipldws2_B.indxI * vipldws2_B.planeOffset;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                         ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                vipldws2_B.c2 += (div_s32_floor(vipldws2_B.c1 << 1, vipldws2_B.i)
                                  + 1) >> 1;
              } else {
                vipldws2_B.c2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                  vipldws2_B.i) + 1) >> 1;
              }

              vipldws2_B.indxI = 0;
              countTwice = true;
            } else if ((vipldws2_B.fromIdx & 8U) != 0U) {
              /* Violated RMax. */
              vipldws2_B.c1 = (1919 - vipldws2_B.indxI) * vipldws2_B.planeOffset;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                         ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                vipldws2_B.c2 += (div_s32_floor(vipldws2_B.c1 << 1, vipldws2_B.i)
                                  + 1) >> 1;
              } else {
                vipldws2_B.c2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                  vipldws2_B.i) + 1) >> 1;
              }

              vipldws2_B.indxI = 1919;
              countTwice = true;
            } else if ((vipldws2_B.fromIdx & 1U) != 0U) {
              /* Violated CMin. */
              vipldws2_B.c1 = -vipldws2_B.c2 * vipldws2_B.i;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                         || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset < 0)))
              {
                vipldws2_B.indxI += (div_s32_floor(vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              } else {
                vipldws2_B.indxI -= (div_s32_floor(-vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              }

              vipldws2_B.c2 = 0;
              countTwice = true;
            } else {
              /* Violated CMax. */
              vipldws2_B.c1 = (2559 - vipldws2_B.c2) * vipldws2_B.i;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                         || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset < 0)))
              {
                vipldws2_B.indxI += (div_s32_floor(vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              } else {
                vipldws2_B.indxI -= (div_s32_floor(-vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              }

              vipldws2_B.c2 = 2559;
              countTwice = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (prevEdgeIsVertical) {
              vipldws2_B.C2 = vipldws2_B.j;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.numEdge;
            }

            vipldws2_B.i = vipldws2_B.C2 - vipldws2_B.indxI;
            vipldws2_B.planeOffset = vipldws2_B.lastActiveEdgeIdxBdy -
              vipldws2_B.c2;
            if ((vipldws2_B.i > 1073741824) || (vipldws2_B.i < -1073741824) ||
                ((vipldws2_B.planeOffset > 1073741824) ||
                 (vipldws2_B.planeOffset < -1073741824))) {
              /* Possible Inf or Nan. */
              done = true;
              c_gotAlLeastOneYellowPixelInThe = false;
              prevEdgeIsVertical = true;
            } else if ((vipldws2_B.toIdx & 4U) != 0U) {
              /* Violated RMin. */
              vipldws2_B.c1 = -vipldws2_B.C2 * vipldws2_B.planeOffset;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                         ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                vipldws2_B.lastActiveEdgeIdxBdy += (div_s32_floor(vipldws2_B.c1 <<
                  1, vipldws2_B.i) + 1) >> 1;
              } else {
                vipldws2_B.lastActiveEdgeIdxBdy -= (div_s32_floor(-vipldws2_B.c1
                  << 1, vipldws2_B.i) + 1) >> 1;
              }

              vipldws2_B.C2 = 0;
              prevEdgeIsVertical = true;
            } else if ((vipldws2_B.toIdx & 8U) != 0U) {
              /* Violated RMax. */
              vipldws2_B.c1 = (1919 - vipldws2_B.C2) * vipldws2_B.planeOffset;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.i >= 0)) ||
                         ((vipldws2_B.c1 < 0) && (vipldws2_B.i < 0))) {
                vipldws2_B.lastActiveEdgeIdxBdy += (div_s32_floor(vipldws2_B.c1 <<
                  1, vipldws2_B.i) + 1) >> 1;
              } else {
                vipldws2_B.lastActiveEdgeIdxBdy -= (div_s32_floor(-vipldws2_B.c1
                  << 1, vipldws2_B.i) + 1) >> 1;
              }

              vipldws2_B.C2 = 1919;
              prevEdgeIsVertical = true;
            } else if ((vipldws2_B.toIdx & 1U) != 0U) {
              /* Violated CMin. */
              vipldws2_B.c1 = -vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.i;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                         || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset < 0)))
              {
                vipldws2_B.C2 += (div_s32_floor(vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              } else {
                vipldws2_B.C2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              }

              vipldws2_B.lastActiveEdgeIdxBdy = 0;
              prevEdgeIsVertical = true;
            } else {
              /* Violated CMax. */
              vipldws2_B.c1 = (2559 - vipldws2_B.lastActiveEdgeIdxBdy) *
                vipldws2_B.i;
              if ((vipldws2_B.c1 > 1073741824) || (vipldws2_B.c1 < -1073741824))
              {
                /* Check for Inf or Nan. */
                done = true;
                c_gotAlLeastOneYellowPixelInThe = false;
              } else if (((vipldws2_B.c1 >= 0) && (vipldws2_B.planeOffset >= 0))
                         || ((vipldws2_B.c1 < 0) && (vipldws2_B.planeOffset < 0)))
              {
                vipldws2_B.C2 += (div_s32_floor(vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              } else {
                vipldws2_B.C2 -= (div_s32_floor(-vipldws2_B.c1 << 1,
                  vipldws2_B.planeOffset) + 1) >> 1;
              }

              vipldws2_B.lastActiveEdgeIdxBdy = 2559;
              prevEdgeIsVertical = true;
            }
          }
        }

        if (c_gotAlLeastOneYellowPixelInThe) {
          /* Initialize the Bresenham algorithm. */
          if (vipldws2_B.C2 >= vipldws2_B.indxI) {
            vipldws2_B.j = vipldws2_B.C2 - vipldws2_B.indxI;
          } else {
            vipldws2_B.j = vipldws2_B.indxI - vipldws2_B.C2;
          }

          if (vipldws2_B.lastActiveEdgeIdxBdy >= vipldws2_B.c2) {
            vipldws2_B.numEdge = vipldws2_B.lastActiveEdgeIdxBdy - vipldws2_B.c2;
          } else {
            vipldws2_B.numEdge = vipldws2_B.c2 - vipldws2_B.lastActiveEdgeIdxBdy;
          }

          if (vipldws2_B.j > vipldws2_B.numEdge) {
            vipldws2_B.r2 = 1;
            vipldws2_B.r1 = 240;
          } else {
            vipldws2_B.r2 = 240;
            vipldws2_B.r1 = 1;
            vipldws2_B.i = vipldws2_B.indxI;
            vipldws2_B.indxI = vipldws2_B.c2;
            vipldws2_B.c2 = vipldws2_B.i;
            vipldws2_B.i = vipldws2_B.C2;
            vipldws2_B.C2 = vipldws2_B.lastActiveEdgeIdxBdy;
            vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.i;
          }

          if (vipldws2_B.indxI > vipldws2_B.C2) {
            vipldws2_B.i = vipldws2_B.indxI;
            vipldws2_B.indxI = vipldws2_B.C2;
            vipldws2_B.C2 = vipldws2_B.i;
            vipldws2_B.i = vipldws2_B.c2;
            vipldws2_B.c2 = vipldws2_B.lastActiveEdgeIdxBdy;
            vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.i;
          }

          vipldws2_B.qY_g = vipldws2_B.C2 - vipldws2_B.indxI;
          if (vipldws2_B.c2 <= vipldws2_B.lastActiveEdgeIdxBdy) {
            vipldws2_B.qY = 1;
            vipldws2_B.lastActiveEdgeIdxBdy -= vipldws2_B.c2;
          } else {
            vipldws2_B.qY = -1;
            vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.c2 -
              vipldws2_B.lastActiveEdgeIdxBdy;
          }

          vipldws2_B.activeColBdy = vipldws2_B.c2 - 4;
          vipldws2_B.activeCol = -((vipldws2_B.qY_g + 1) >> 1);
          if (vipldws2_B.r2 != 1) {
            vipldws2_B.colBoundary = 1919;
          } else {
            vipldws2_B.colBoundary = 2559;
          }

          vipldws2_B.c1 = vipldws2_B.indxI >> 3;
          vipldws2_B.j = ((vipldws2_B.c1 + 1) << 3) - vipldws2_B.indxI;
          vipldws2_B.firstRowOut = 320;
          vipldws2_B.lastRowOut = 0;
          memset(&vipldws2_DW.DrawShapes_DW_PixCount[0], 0, 320U * sizeof
                 (uint8_T));
          done = (vipldws2_B.indxI <= vipldws2_B.C2);
          while (done) {
            vipldws2_B.j--;
            vipldws2_B.numEdge = vipldws2_B.activeColBdy;

            /* Compute the next location using Bresenham algorithm. */
            /* Move to the next sub-pixel location. */
            vipldws2_B.activeCol += vipldws2_B.lastActiveEdgeIdxBdy;
            if (vipldws2_B.activeCol >= 0) {
              vipldws2_B.activeColBdy += vipldws2_B.qY;
              vipldws2_B.activeCol -= vipldws2_B.qY_g;
            }

            vipldws2_B.indxI++;
            done = (vipldws2_B.indxI <= vipldws2_B.C2);
            if (done) {
              vipldws2_B.col = vipldws2_B.numEdge + 7;
              if ((vipldws2_B.numEdge + 7 > 0) && (vipldws2_B.numEdge <
                   vipldws2_B.colBoundary)) {
                if (vipldws2_B.numEdge < 0) {
                  vipldws2_B.numEdge = 0;
                }

                if (vipldws2_B.col > vipldws2_B.colBoundary) {
                  vipldws2_B.col = vipldws2_B.colBoundary;
                }

                vipldws2_B.planeOffset = vipldws2_B.numEdge >> 3;
                vipldws2_B.i = vipldws2_B.col >> 3;
                if (vipldws2_B.firstRowOut > vipldws2_B.planeOffset) {
                  vipldws2_B.firstRowOut = vipldws2_B.planeOffset;
                }

                if (vipldws2_B.lastRowOut < vipldws2_B.i) {
                  vipldws2_B.lastRowOut = vipldws2_B.i;
                }

                if (vipldws2_B.i > vipldws2_B.planeOffset) {
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                    (uint8_T)(((uint32_T)((vipldws2_B.planeOffset + 1) << 3) +
                               vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset])
                              - vipldws2_B.numEdge);
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] = (uint8_T)
                    ((((uint32_T)vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i]
                       + vipldws2_B.col) - (vipldws2_B.i << 3)) + 1U);
                  vipldws2_B.numEdge = vipldws2_B.planeOffset + 1;
                  while (vipldws2_B.numEdge < vipldws2_B.i) {
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] =
                      (uint8_T)
                      (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] +
                       8U);
                    vipldws2_B.numEdge++;
                  }
                } else {
                  if (vipldws2_B.i == vipldws2_B.planeOffset) {
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                      (uint8_T)((((uint32_T)
                                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset]
                                  + vipldws2_B.col) - vipldws2_B.numEdge) + 1U);
                  }
                }
              }
            }

            if ((vipldws2_B.j == 0) || (!done)) {
              while (vipldws2_B.firstRowOut <= vipldws2_B.lastRowOut) {
                vipldws2_B.col = vipldws2_B.c1 * vipldws2_B.r2 +
                  vipldws2_B.firstRowOut * vipldws2_B.r1;
                if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] ==
                    64) {
                  vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                    vipldws2_P.DrawShapes_RTP_FILLCOLOR[0] -
                    vipldws2_B.DrawShapes_l[vipldws2_B.col];
                } else {
                  vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                    (vipldws2_P.DrawShapes_RTP_FILLCOLOR[0] -
                     vipldws2_B.DrawShapes_l[vipldws2_B.col]) * (real32_T)
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] /
                    64.0F;
                }

                vipldws2_B.col += 76800;
                if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] ==
                    64) {
                  vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                    vipldws2_P.DrawShapes_RTP_FILLCOLOR[1] -
                    vipldws2_B.DrawShapes_l[vipldws2_B.col];
                } else {
                  vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                    (vipldws2_P.DrawShapes_RTP_FILLCOLOR[1] -
                     vipldws2_B.DrawShapes_l[vipldws2_B.col]) * (real32_T)
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] /
                    64.0F;
                }

                vipldws2_B.col += 76800;
                if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] ==
                    64) {
                  vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                    vipldws2_P.DrawShapes_RTP_FILLCOLOR[2] -
                    vipldws2_B.DrawShapes_l[vipldws2_B.col];
                } else {
                  vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                    (vipldws2_P.DrawShapes_RTP_FILLCOLOR[2] -
                     vipldws2_B.DrawShapes_l[vipldws2_B.col]) * (real32_T)
                    vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] /
                    64.0F;
                }

                vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] = 0U;
                vipldws2_B.firstRowOut++;
              }

              vipldws2_B.j = 8;
              vipldws2_B.firstRowOut = 320;
              vipldws2_B.lastRowOut = 0;
              vipldws2_B.c1++;
            }
          }
        }
      }
    } else {
      /* Compute output for non-unity line width
       */
      /* Copy the image from input to output. */
      memcpy(&vipldws2_B.DrawShapes_l[0], &vipldws2_B.Switch[0], 230400U *
             sizeof(real32_T));

      /* Update view port. */
      /* ProcessStep-start-1
       */
      if (vipldws2_P.DrawShapes_lineWidth > 1) {
        /* convertLinePts2PolygonPts
         */
        vipldws2_B.numEdge = vipldws2_P.DrawShapes_lineWidth >> 1;

        /* getLineParams-1
         */
        /* getLineParams-main fcn
         */
        vipldws2_B.lastActiveEdgeIdxBdy =
          vipldws2_B.TmpSignalConversionAtDrawShapes[1] -
          vipldws2_B.TmpSignalConversionAtDrawShapes[3];
        vipldws2_B.indxI = vipldws2_B.TmpSignalConversionAtDrawShapes[0] -
          vipldws2_B.TmpSignalConversionAtDrawShapes[2];
        if (vipldws2_B.indxI == 0) {
          vipldws2_B.scale = 0.0F;
          vipldws2_B.col = 1;
          vipldws2_B.cnt = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[0] - vipldws2_B.numEdge)
             - 1);
          vipldws2_B.y2 = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[0] + vipldws2_B.numEdge)
             - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[1] - 1);
        } else if (vipldws2_B.lastActiveEdgeIdxBdy == 0) {
          vipldws2_B.col = 2;
          vipldws2_B.scale = 0.0F;
          vipldws2_B.cnt = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[1] - vipldws2_B.numEdge)
             - 1);
          vipldws2_B.y2 = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[1] + vipldws2_B.numEdge)
             - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[0] - 1);
        } else {
          vipldws2_B.col = 0;
          vipldws2_B.scale = (real32_T)vipldws2_B.lastActiveEdgeIdxBdy /
            (real32_T)vipldws2_B.indxI;
          vipldws2_B.y2 = (real32_T)(vipldws2_B.TmpSignalConversionAtDrawShapes
            [1] - 1) - (real32_T)(vipldws2_B.TmpSignalConversionAtDrawShapes[0]
            - 1) * vipldws2_B.scale;
          vipldws2_B.acc4_idx_0 = (real32_T)vipldws2_B.numEdge / ((real32_T)
            vipldws2_B.indxI / (real32_T)sqrt((real32_T)
            (vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.lastActiveEdgeIdxBdy +
             vipldws2_B.indxI * vipldws2_B.indxI)));
          vipldws2_B.cnt = vipldws2_B.y2 + vipldws2_B.acc4_idx_0;
          vipldws2_B.y2 -= vipldws2_B.acc4_idx_0;
          vipldws2_B.acc4_idx_0 = (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[0] - 1) /
            vipldws2_B.scale + (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[1] - 1);
        }

        /* findPointOfIntersectionNormal-1
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.cnt;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.acc4_idx_0
                + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.cnt) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt += vipldws2_B.scale * vipldws2_B.acc1_idx_5;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[0] = vipldws2_B.lastActiveEdgeIdxBdy;
        vipldws2_DW.DrawShapes_DW_Points[1] = vipldws2_B.indxI;

        /* findPointOfIntersectionNormal-2
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.y2;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.y2;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.y2) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt = vipldws2_B.scale * vipldws2_B.acc1_idx_5 +
            vipldws2_B.y2;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.cnt +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[7] = vipldws2_B.activeCol;
        vipldws2_DW.DrawShapes_DW_Points[6] = vipldws2_B.activeColBdy;

        /* getLineParams-2
         */
        /* getLineParams-main fcn
         */
        vipldws2_B.lastActiveEdgeIdxBdy =
          vipldws2_B.TmpSignalConversionAtDrawShapes[1] -
          vipldws2_B.TmpSignalConversionAtDrawShapes[3];
        vipldws2_B.indxI = vipldws2_B.TmpSignalConversionAtDrawShapes[0] -
          vipldws2_B.TmpSignalConversionAtDrawShapes[2];
        if (vipldws2_B.indxI == 0) {
          vipldws2_B.scale = 0.0F;
          vipldws2_B.col = 1;
          vipldws2_B.cnt = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[0] - vipldws2_B.numEdge)
             - 1);
          vipldws2_B.y2 = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[0] + vipldws2_B.numEdge)
             - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[3] - 1);
        } else if (vipldws2_B.lastActiveEdgeIdxBdy == 0) {
          vipldws2_B.col = 2;
          vipldws2_B.scale = 0.0F;
          vipldws2_B.cnt = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[1] - vipldws2_B.numEdge)
             - 1);
          vipldws2_B.y2 = (real32_T)
            ((vipldws2_B.TmpSignalConversionAtDrawShapes[1] + vipldws2_B.numEdge)
             - 1);
          vipldws2_B.acc4_idx_0 = (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[2] - 1);
        } else {
          vipldws2_B.col = 0;
          vipldws2_B.scale = (real32_T)vipldws2_B.lastActiveEdgeIdxBdy /
            (real32_T)vipldws2_B.indxI;
          vipldws2_B.y2 = (real32_T)(vipldws2_B.TmpSignalConversionAtDrawShapes
            [1] - 1) - (real32_T)(vipldws2_B.TmpSignalConversionAtDrawShapes[0]
            - 1) * vipldws2_B.scale;
          vipldws2_B.acc4_idx_0 = (real32_T)vipldws2_B.numEdge / ((real32_T)
            vipldws2_B.indxI / (real32_T)sqrt((real32_T)
            (vipldws2_B.lastActiveEdgeIdxBdy * vipldws2_B.lastActiveEdgeIdxBdy +
             vipldws2_B.indxI * vipldws2_B.indxI)));
          vipldws2_B.cnt = vipldws2_B.y2 + vipldws2_B.acc4_idx_0;
          vipldws2_B.y2 -= vipldws2_B.acc4_idx_0;
          vipldws2_B.acc4_idx_0 = (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[2] - 1) /
            vipldws2_B.scale + (real32_T)
            (vipldws2_B.TmpSignalConversionAtDrawShapes[3] - 1);
        }

        /* findPointOfIntersectionNormal-3
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.cnt;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.acc4_idx_0
                + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc4_idx_0 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.cnt) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)(vipldws2_B.acc1_idx_5 *
                0.0F);
            }
          } else {
            vipldws2_B.lastActiveEdgeIdxBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt += vipldws2_B.scale * vipldws2_B.acc1_idx_5;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.indxI = (int32_T)(real32_T)floor(vipldws2_B.cnt + 0.5F);
            } else {
              vipldws2_B.indxI = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.indxI = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[2] = vipldws2_B.lastActiveEdgeIdxBdy;
        vipldws2_DW.DrawShapes_DW_Points[3] = vipldws2_B.indxI;

        /* findPointOfIntersectionNormal-4
         */
        /* findPointOfIntersectionNormal- main fcn
         */
        if (vipldws2_B.col == 1) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.y2;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.acc4_idx_0;
          }
        } else if (vipldws2_B.col == 2) {
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc4_idx_0);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc4_idx_0 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc4_idx_0 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc4_idx_0;
          }

          vipldws2_B.v = (real32_T)fabs(vipldws2_B.y2);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.y2 +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.y2 * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.y2;
          }
        } else {
          vipldws2_B.acc1_idx_5 = (vipldws2_B.acc4_idx_0 - vipldws2_B.y2) *
            vipldws2_B.scale / (vipldws2_B.scale * vipldws2_B.scale + 1.0F);
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.acc1_idx_5);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeColBdy = (int32_T)(real32_T)floor
                (vipldws2_B.acc1_idx_5 + 0.5F);
            } else {
              vipldws2_B.activeColBdy = (int32_T)(vipldws2_B.acc1_idx_5 * 0.0F);
            }
          } else {
            vipldws2_B.activeColBdy = (int32_T)vipldws2_B.acc1_idx_5;
          }

          vipldws2_B.cnt = vipldws2_B.scale * vipldws2_B.acc1_idx_5 +
            vipldws2_B.y2;
          vipldws2_B.v = (real32_T)fabs(vipldws2_B.cnt);
          if (vipldws2_B.v < 8.388608E+6F) {
            if (vipldws2_B.v >= 0.5F) {
              vipldws2_B.activeCol = (int32_T)(real32_T)floor(vipldws2_B.cnt +
                0.5F);
            } else {
              vipldws2_B.activeCol = (int32_T)(vipldws2_B.cnt * 0.0F);
            }
          } else {
            vipldws2_B.activeCol = (int32_T)vipldws2_B.cnt;
          }
        }

        vipldws2_DW.DrawShapes_DW_Points[5] = vipldws2_B.activeCol;
        vipldws2_DW.DrawShapes_DW_Points[4] = vipldws2_B.activeColBdy;
      }

      /* ProcessStep-after poly points-1
       */
      vipldws2_B.c2 = 2;

      /* just before call for cgpolygon
       */
      if (vipldws2_P.DrawShapes_lineWidth > 1) {
        /* just before call for cgpolygon-2
         */
        vipldws2_B.c2 = 4;
      }

      memset(&vipldws2_DW.DrawShapes_DW_PixCount[0], 0, 240U * sizeof(uint8_T));

      /* Reset scanline states. */
      vipldws2_B.plane = 0;
      vipldws2_B.C2 = 0;
      c_gotAlLeastOneYellowPixelInThe = true;
      while (c_gotAlLeastOneYellowPixelInThe) {
        /* Initialize the scanline. */
        /* Convert polygon vertices to boundaries. */
        done = false;
        vipldws2_B.numEdge = 0;
        vipldws2_B.qY_g = vipldws2_B.plane;
        vipldws2_B.qY = vipldws2_B.plane;
        idxTmpArray_0[0U] = (int8_T)(vipldws2_B.c2 - 1);
        vipldws2_B.j = 0;
        while (vipldws2_B.j < 1) {
          /* start for loop
           */
          vipldws2_B.lastActiveEdgeIdxBdy = ((idxTmpArray_0[0] << 1) +
            vipldws2_B.C2) + 1;
          vipldws2_B.indxI = (idxTmpArray_0[0] << 1) + vipldws2_B.C2;
          vipldws2_B.firstRowOut = idxTmpArray_0[0];
          vipldws2_B.activeColBdy = ((idxTmpArray_0[0] - 1) << 1) +
            vipldws2_B.C2;
          vipldws2_B.activeCol = vipldws2_B.c2;
          if (vipldws2_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            vipldws2_B.colBoundary =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];

            /* getLoc-1
             */
            vipldws2_B.lastRowOut =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws2_B.colBoundary =
              vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.indxI];

            /* getLoc-2
             */
            vipldws2_B.lastRowOut =
              vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.activeColBdy];
          }

          vipldws2_B.i = vipldws2_B.lastRowOut;
          while ((vipldws2_B.activeColBdy >= 0) && (vipldws2_B.colBoundary - 1 ==
                  vipldws2_B.i - 1)) {
            vipldws2_B.firstRowOut--;
            vipldws2_B.activeColBdy = ((vipldws2_B.firstRowOut - 1) << 1) +
              vipldws2_B.C2;
            vipldws2_B.activeCol--;
            if (vipldws2_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              vipldws2_B.lastRowOut =
                vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];
            } else {
              /* getLoc-2
               */
              vipldws2_B.lastRowOut =
                vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.activeColBdy];
            }

            vipldws2_B.i = vipldws2_B.lastRowOut;
          }

          if (vipldws2_B.activeColBdy < 0) {
            vipldws2_B.activeColBdy = 0;
          }

          if (vipldws2_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            vipldws2_B.colBoundary =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];

            /* getLoc-1
             */
            vipldws2_B.lastRowOut =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];
          } else {
            /* getLoc-2
             */
            vipldws2_B.colBoundary =
              vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.indxI];

            /* getLoc-2
             */
            vipldws2_B.lastRowOut =
              vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.activeColBdy];
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.lastRowOut - 1 >
            vipldws2_B.colBoundary - 1);
          vipldws2_B.colOut = vipldws2_B.C2 + 1;
          vipldws2_B.activeColBdy = vipldws2_B.C2;
          prevEdgeIsVertical = false;
          if (vipldws2_P.DrawShapes_lineWidth > 1) {
            /* getLoc-1
             */
            vipldws2_B.colBoundary =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.C2];

            /* getLoc-1
             */
            vipldws2_B.lastRowOut =
              vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];
          } else {
            /* getLoc-2
             */
            vipldws2_B.colBoundary =
              vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.C2];

            /* getLoc-2
             */
            vipldws2_B.lastRowOut =
              vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.indxI];
          }

          done = (vipldws2_B.lastRowOut - 1 == vipldws2_B.colBoundary - 1);
          vipldws2_B.i = 0;
          while (vipldws2_B.i < vipldws2_B.activeCol) {
            if (vipldws2_P.DrawShapes_lineWidth > 1) {
              /* getLoc-1
               */
              vipldws2_B.colBoundary =
                vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];

              /* getLoc-1
               */
              vipldws2_B.lastRowOut =
                vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];
            } else {
              /* getLoc-2
               */
              vipldws2_B.colBoundary =
                vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.activeColBdy];

              /* getLoc-2
               */
              vipldws2_B.lastRowOut =
                vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.indxI];
            }

            if (vipldws2_B.lastRowOut - 1 != vipldws2_B.colBoundary - 1) {
              if (vipldws2_P.DrawShapes_lineWidth > 1) {
                /* getLoc-1
                 */
                vipldws2_B.colBoundary =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];
              } else {
                /* getLoc-2
                 */
                vipldws2_B.colBoundary =
                  vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.indxI];
              }

              if (vipldws2_B.lastRowOut - 1 < vipldws2_B.colBoundary - 1) {
                countTwice = false;
              } else {
                countTwice = true;
                vipldws2_B.firstRowOut = vipldws2_B.lastActiveEdgeIdxBdy;
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
                vipldws2_B.colOut = vipldws2_B.firstRowOut;
                vipldws2_B.firstRowOut = vipldws2_B.indxI;
                vipldws2_B.indxI = vipldws2_B.activeColBdy;
                vipldws2_B.activeColBdy = vipldws2_B.firstRowOut;
              }

              if (vipldws2_P.DrawShapes_lineWidth > 1) {
                /* getLoc-1
                 */
                vipldws2_B.colBoundary =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.activeColBdy];

                /* getLoc-1
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.colOut];

                /* getLoc-1
                 */
                vipldws2_B.lastRow =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.indxI];

                /* getLoc-1
                 */
                vipldws2_B.firstRowOut =
                  vipldws2_DW.DrawShapes_DW_Points[vipldws2_B.lastActiveEdgeIdxBdy];
              } else {
                /* getLoc-2
                 */
                vipldws2_B.colBoundary =
                  vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.activeColBdy];

                /* getLoc-2
                 */
                vipldws2_B.lastRowOut =
                  vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.colOut];

                /* getLoc-2
                 */
                vipldws2_B.lastRow =
                  vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.indxI];

                /* getLoc-2
                 */
                vipldws2_B.firstRowOut =
                  vipldws2_B.TmpSignalConversionAtDrawShapes[vipldws2_B.lastActiveEdgeIdxBdy];
              }

              /* Initialize a Bresenham line. */
              vipldws2_B.firstRowOut = ((vipldws2_B.firstRowOut - 1) << 3) + 4;
              vipldws2_B.lastRow = ((vipldws2_B.lastRow - 1) << 3) + 4;
              vipldws2_B.lastRowOut = ((vipldws2_B.lastRowOut - 1) << 3) + 4;
              vipldws2_B.colBoundary = ((vipldws2_B.colBoundary - 1) << 3) + 4;
              vipldws2_B.firstRow = vipldws2_B.colBoundary - vipldws2_B.lastRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] = 0;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] =
                vipldws2_B.firstRowOut;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2] =
                vipldws2_B.lastRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] =
                vipldws2_B.colBoundary;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] = 0;
              if (vipldws2_B.lastRowOut >= vipldws2_B.firstRowOut) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] =
                  vipldws2_B.lastRowOut - vipldws2_B.firstRowOut;
              } else {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] =
                  vipldws2_B.firstRowOut - vipldws2_B.lastRowOut;
              }

              while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] >= 0)
              {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6]++;
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] -=
                  vipldws2_B.firstRow;
              }

              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] - 1;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8] +
                vipldws2_B.firstRow;
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 4] =
                vipldws2_B.firstRow -
                (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7] << 1);
              if (vipldws2_B.firstRowOut > vipldws2_B.lastRowOut) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5] =
                  -vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6] =
                  -vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6];
              }

              if ((!c_gotAlLeastOneYellowPixelInThe) && (!countTwice)) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2]++;
                if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] << 1) >
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 4]) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6];
                } else {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5];
                }
              } else {
                if (c_gotAlLeastOneYellowPixelInThe && countTwice) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3]--;
                }
              }

              c_gotAlLeastOneYellowPixelInThe = countTwice;
              if (!prevEdgeIsVertical) {
                /* Merge two Bresenham lines. */
                if ((vipldws2_B.qY_g != vipldws2_B.qY) &&
                    ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 5] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 5]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 6] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 6]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 7] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 7]) &&
                     (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 8] ==
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 8]))) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] + 1
                      == vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2]) {
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] =
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3];
                    prevEdgeIsVertical = true;
                  } else {
                    if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] + 1
                        == vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2])
                    {
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 1] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 1];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2];
                      prevEdgeIsVertical = true;
                    }
                  }
                }

                if (!prevEdgeIsVertical) {
                  vipldws2_B.qY_g = vipldws2_B.qY;
                  vipldws2_B.numEdge++;
                }
              } else {
                vipldws2_B.qY_g = vipldws2_B.qY;
                vipldws2_B.numEdge++;
              }

              vipldws2_B.qY = vipldws2_B.qY_g + 9;
              if (!countTwice) {
                vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
                vipldws2_B.indxI = vipldws2_B.activeColBdy;
              }

              vipldws2_B.colOut = vipldws2_B.lastActiveEdgeIdxBdy + 2;
              vipldws2_B.activeColBdy = vipldws2_B.indxI + 2;
              prevEdgeIsVertical = false;
            } else {
              prevEdgeIsVertical = true;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.colOut;
              vipldws2_B.indxI = vipldws2_B.activeColBdy;
              vipldws2_B.colOut += 2;
              vipldws2_B.activeColBdy += 2;
            }

            vipldws2_B.i++;
          }

          vipldws2_B.j = 1;
        }

        if (!done) {
          /* Merge two Bresenham lines. */
          if ((vipldws2_B.plane != vipldws2_B.qY_g) &&
              ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 5] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 5]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 6] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 6]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 7] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 7]) &&
               (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 8] ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 8]))) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3] + 1 ==
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2]) {
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3] =
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3];
              done = true;
            } else {
              if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 3] + 1 ==
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2]) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 1] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 1];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY_g + 2];
                done = true;
              }
            }
          }

          if (done) {
            vipldws2_B.numEdge--;
            vipldws2_B.qY -= 9;
          }
        }

        /* Set all other edges to invalid. */
        vipldws2_B.i = vipldws2_B.numEdge;
        while (vipldws2_B.i < vipldws2_B.c2) {
          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 2] = 1;
          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.qY + 3] = 0;
          vipldws2_B.qY += 9;
          vipldws2_B.i++;
        }

        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws2_B.r1 = vipldws2_B.plane;
          vipldws2_B.r2 = vipldws2_B.plane + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.i = 1;
          while (vipldws2_B.i < vipldws2_B.numEdge) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 2] >
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_B.lastSeparator =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j] =
                  vipldws2_B.lastSeparator;
              }
            }

            vipldws2_B.r1 = vipldws2_B.r2;
            vipldws2_B.r2 += 9;
            vipldws2_B.i++;
          }
        }

        /* Find out the last column of the polygon. */
        vipldws2_B.planeOffset = vipldws2_B.plane + 3;
        vipldws2_B.qY_g = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 3];
        vipldws2_B.i = 1;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          vipldws2_B.planeOffset += 9;
          if (vipldws2_B.qY_g <
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset]) {
            vipldws2_B.qY_g =
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset];
          }

          vipldws2_B.i++;
        }

        vipldws2_B.qY = vipldws2_B.qY_g;
        if (vipldws2_B.qY_g > 2559) {
          vipldws2_B.qY = 2559;
        }

        /* Find out the first column of the polygon. */
        vipldws2_B.planeOffset = vipldws2_B.plane + 2;
        vipldws2_B.qY_g = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.plane + 2];
        vipldws2_B.i = 1;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          vipldws2_B.planeOffset += 9;
          if (vipldws2_B.qY_g >
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset]) {
            vipldws2_B.qY_g =
              vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.planeOffset];
          }

          vipldws2_B.i++;
        }

        if (vipldws2_B.qY_g < 0) {
          vipldws2_B.qY_g = 0;
        }

        /* Move to the next column and find out boundaries of the polygon at this column. */
        vipldws2_B.r1 = vipldws2_B.plane;
        vipldws2_B.r2 = vipldws2_B.plane;
        vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.plane;
        vipldws2_B.indxI = 0;
        vipldws2_B.planeOffset = 0;
        vipldws2_B.i = 0;
        while (vipldws2_B.i < vipldws2_B.numEdge) {
          /* Find out the valid boundaries and bring them to the latest column. */
          if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 3] >=
              vipldws2_B.qY_g) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <=
                vipldws2_B.qY_g) {
              while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <
                     vipldws2_B.qY_g) {
                /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]++;
                if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] << 1) >
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 4]) {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 8];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 6];
                } else {
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 7];
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                    vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 5];
                }
              }

              vipldws2_B.lastActiveEdgeIdxBdy += 9;
              vipldws2_B.planeOffset++;
            }

            if (vipldws2_B.r2 != vipldws2_B.r1) {
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
              }
            }

            vipldws2_B.r1 += 9;
            vipldws2_B.indxI++;
          }

          vipldws2_B.r2 += 9;
          vipldws2_B.i++;
        }

        /* Sort the boundaries of the polygon according to row values. */
        /* Sort the boundaries of the polygon. */
        c_gotAlLeastOneYellowPixelInThe = true;
        while (c_gotAlLeastOneYellowPixelInThe) {
          vipldws2_B.r1 = vipldws2_B.plane;
          vipldws2_B.r2 = vipldws2_B.plane + 9;
          c_gotAlLeastOneYellowPixelInThe = false;
          vipldws2_B.i = 1;
          while (vipldws2_B.i < vipldws2_B.planeOffset) {
            if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1] >
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1]) {
              c_gotAlLeastOneYellowPixelInThe = true;
              for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                vipldws2_B.lastSeparator =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + vipldws2_B.j] =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j];
                vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + vipldws2_B.j] =
                  vipldws2_B.lastSeparator;
              }
            }

            vipldws2_B.r1 = vipldws2_B.r2;
            vipldws2_B.r2 += 9;
            vipldws2_B.i++;
          }
        }

        vipldws2_B.r1 = vipldws2_B.plane;
        vipldws2_B.activeColBdy = vipldws2_B.qY_g + 1;
        vipldws2_B.activeCol = 0;
        vipldws2_B.r2 = 0;
        vipldws2_B.lastSeparator = -1;
        vipldws2_B.colOut = vipldws2_B.qY_g >> 3;
        vipldws2_B.colBoundary = (vipldws2_B.colOut + 1) << 3;
        vipldws2_B.firstRowOut = 240;
        vipldws2_B.lastRowOut = 0;
        c_gotAlLeastOneYellowPixelInThe = (0 <= vipldws2_B.qY);
        while (c_gotAlLeastOneYellowPixelInThe) {
          /* Get a string of pixels */
          countTwice = false;
          done = (vipldws2_B.r2 != 0);
          vipldws2_B.col = vipldws2_B.activeCol;
          if ((vipldws2_B.activeCol >= vipldws2_B.qY_g) && (vipldws2_B.activeCol
               <= vipldws2_B.qY)) {
            if (vipldws2_B.r1 < vipldws2_B.lastActiveEdgeIdxBdy) {
              vipldws2_B.i = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
              vipldws2_B.r1 += 9;
              if ((vipldws2_B.i == vipldws2_B.lastSeparator) && (vipldws2_B.r1 <
                   vipldws2_B.lastActiveEdgeIdxBdy)) {
                vipldws2_B.planeOffset =
                  vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
                c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.r1 <
                  vipldws2_B.lastActiveEdgeIdxBdy);
                while (c_gotAlLeastOneYellowPixelInThe && (vipldws2_B.i ==
                        vipldws2_B.planeOffset)) {
                  countTwice = true;
                  vipldws2_B.i = vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1
                    + 1];
                  vipldws2_B.r1 += 9;
                  c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.r1 <
                    vipldws2_B.lastActiveEdgeIdxBdy);
                  if (c_gotAlLeastOneYellowPixelInThe) {
                    vipldws2_B.planeOffset =
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1];
                  }
                }

                if (!c_gotAlLeastOneYellowPixelInThe) {
                  countTwice = false;
                }
              }

              if (vipldws2_B.r2 != 0) {
                vipldws2_B.firstRow = vipldws2_B.lastSeparator;
                if (vipldws2_B.i <= 1919) {
                  vipldws2_B.lastRow = vipldws2_B.i;
                  vipldws2_B.lastSeparator = vipldws2_B.i;
                } else {
                  vipldws2_B.lastRow = 1919;
                  vipldws2_B.lastSeparator = 1919;
                }
              } else {
                vipldws2_B.firstRow = vipldws2_B.lastSeparator + 1;
                if ((vipldws2_B.i > 0) && (vipldws2_B.i <= 1919)) {
                  vipldws2_B.lastRow = vipldws2_B.i - 1;
                  vipldws2_B.lastSeparator = vipldws2_B.i;
                } else if (vipldws2_B.i <= 0) {
                  vipldws2_B.lastRow = -1;
                  vipldws2_B.lastSeparator = 0;
                } else {
                  vipldws2_B.lastRow = 1919;
                  vipldws2_B.lastSeparator = 1920;
                }
              }

              if (!countTwice) {
                vipldws2_B.r2 = !(vipldws2_B.r2 != 0);
              }
            } else {
              /* Reset states and move to the next column. */
              done = false;
              vipldws2_B.firstRow = vipldws2_B.lastSeparator + 1;
              vipldws2_B.lastRow = 1919;

              /* Move to the next column and find out boundaries of the polygon at this column. */
              vipldws2_B.r1 = vipldws2_B.plane;
              vipldws2_B.r2 = vipldws2_B.plane;
              vipldws2_B.lastActiveEdgeIdxBdy = vipldws2_B.plane;
              vipldws2_B.numEdge = 0;
              vipldws2_B.planeOffset = 0;
              vipldws2_B.i = 0;
              while (vipldws2_B.i < vipldws2_B.indxI) {
                /* Find out the valid boundaries and bring them to the latest column. */
                if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 3] >=
                    vipldws2_B.activeColBdy) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <=
                      vipldws2_B.activeColBdy) {
                    while (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2] <
                           vipldws2_B.activeColBdy) {
                      /* Use Bresenham algorithm to calculate the polygon boundaries at the next column */
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 2]++;
                      if ((vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] << 1)
                          > vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 4])
                      {
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 8];
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 6];
                      } else {
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 7];
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1] +=
                          vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 5];
                      }
                    }

                    vipldws2_B.lastActiveEdgeIdxBdy += 9;
                    vipldws2_B.planeOffset++;
                  }

                  if (vipldws2_B.r2 != vipldws2_B.r1) {
                    for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j];
                    }
                  }

                  vipldws2_B.r1 += 9;
                  vipldws2_B.numEdge++;
                }

                vipldws2_B.r2 += 9;
                vipldws2_B.i++;
              }

              vipldws2_B.indxI = vipldws2_B.numEdge;

              /* Sort the boundaries of the polygon according to row values. */
              /* Sort the boundaries of the polygon. */
              while (c_gotAlLeastOneYellowPixelInThe) {
                vipldws2_B.r1 = vipldws2_B.plane;
                vipldws2_B.r2 = vipldws2_B.plane + 9;
                c_gotAlLeastOneYellowPixelInThe = false;
                vipldws2_B.i = 1;
                while (vipldws2_B.i < vipldws2_B.planeOffset) {
                  if (vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 + 1] >
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 + 1]) {
                    c_gotAlLeastOneYellowPixelInThe = true;
                    for (vipldws2_B.j = 0; vipldws2_B.j < 9; vipldws2_B.j++) {
                      vipldws2_B.lastSeparator =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r1 +
                        vipldws2_B.j] =
                        vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j];
                      vipldws2_DW.DrawShapes_DW_Polygon[vipldws2_B.r2 +
                        vipldws2_B.j] = vipldws2_B.lastSeparator;
                    }
                  }

                  vipldws2_B.r1 = vipldws2_B.r2;
                  vipldws2_B.r2 += 9;
                  vipldws2_B.i++;
                }
              }

              vipldws2_B.r1 = vipldws2_B.plane;
              vipldws2_B.activeColBdy++;
              vipldws2_B.r2 = 0;
              vipldws2_B.lastSeparator = -1;
              vipldws2_B.activeCol++;
            }
          } else {
            vipldws2_B.firstRow = 0;
            vipldws2_B.lastRow = 1919;
            vipldws2_B.activeCol++;
          }

          if (vipldws2_B.firstRow < 0) {
            vipldws2_B.firstRow = 0;
          }

          if (vipldws2_B.lastRow < vipldws2_B.firstRow) {
            vipldws2_B.lastRow = vipldws2_B.firstRow - 1;
          }

          if (done && ((vipldws2_B.lastRow > 0) && (vipldws2_B.firstRow < 1919)))
          {
            if (vipldws2_B.lastRow > 1919) {
              vipldws2_B.lastRow = 1919;
            }

            vipldws2_B.planeOffset = vipldws2_B.firstRow >> 3;
            vipldws2_B.i = vipldws2_B.lastRow >> 3;
            if (vipldws2_B.firstRowOut > vipldws2_B.planeOffset) {
              vipldws2_B.firstRowOut = vipldws2_B.planeOffset;
            }

            if (vipldws2_B.lastRowOut < vipldws2_B.i) {
              vipldws2_B.lastRowOut = vipldws2_B.i;
            }

            if (vipldws2_B.i > vipldws2_B.planeOffset) {
              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                (uint8_T)(((uint32_T)((vipldws2_B.planeOffset + 1) << 3) +
                           vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset])
                          - vipldws2_B.firstRow);
              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] = (uint8_T)
                ((((uint32_T)vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.i] +
                   vipldws2_B.lastRow) - (vipldws2_B.i << 3)) + 1U);
              vipldws2_B.numEdge = vipldws2_B.planeOffset + 1;
              while (vipldws2_B.numEdge < vipldws2_B.i) {
                vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] =
                  (uint8_T)
                  (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] + 8U);
                vipldws2_B.numEdge++;
              }
            } else {
              if (vipldws2_B.i == vipldws2_B.planeOffset) {
                vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset] =
                  (uint8_T)((((uint32_T)
                              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.planeOffset]
                              + vipldws2_B.lastRow) - vipldws2_B.firstRow) + 1U);
              }
            }
          }

          c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.activeCol <=
            vipldws2_B.qY);
          if (((vipldws2_B.colBoundary - 1 == vipldws2_B.col) ||
               (!c_gotAlLeastOneYellowPixelInThe)) && (vipldws2_B.lastRow >=
               1919)) {
            vipldws2_B.j = vipldws2_B.colOut * 240 + vipldws2_B.firstRowOut;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.numEdge = vipldws2_B.firstRowOut;
            while (vipldws2_B.numEdge <= vipldws2_B.lastRowOut) {
              if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] == 64)
              {
                vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                  vipldws2_P.DrawShapes_RTP_FILLCOLOR[0] -
                  vipldws2_B.DrawShapes_l[vipldws2_B.col];
              } else {
                vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                  (vipldws2_P.DrawShapes_RTP_FILLCOLOR[0] -
                   vipldws2_B.DrawShapes_l[vipldws2_B.col]) * (real32_T)
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] / 64.0F;
              }

              vipldws2_B.col++;
              vipldws2_B.numEdge++;
            }

            vipldws2_B.j += 76800;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.numEdge = vipldws2_B.firstRowOut;
            while (vipldws2_B.numEdge <= vipldws2_B.lastRowOut) {
              if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] == 64)
              {
                vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                  vipldws2_P.DrawShapes_RTP_FILLCOLOR[1] -
                  vipldws2_B.DrawShapes_l[vipldws2_B.col];
              } else {
                vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                  (vipldws2_P.DrawShapes_RTP_FILLCOLOR[1] -
                   vipldws2_B.DrawShapes_l[vipldws2_B.col]) * (real32_T)
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] / 64.0F;
              }

              vipldws2_B.col++;
              vipldws2_B.numEdge++;
            }

            vipldws2_B.j += 76800;
            vipldws2_B.col = vipldws2_B.j;
            vipldws2_B.numEdge = vipldws2_B.firstRowOut;
            while (vipldws2_B.numEdge <= vipldws2_B.lastRowOut) {
              if (vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] == 64)
              {
                vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                  vipldws2_P.DrawShapes_RTP_FILLCOLOR[2] -
                  vipldws2_B.DrawShapes_l[vipldws2_B.col];
              } else {
                vipldws2_B.DrawShapes_l[vipldws2_B.col] +=
                  (vipldws2_P.DrawShapes_RTP_FILLCOLOR[2] -
                   vipldws2_B.DrawShapes_l[vipldws2_B.col]) * (real32_T)
                  vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.numEdge] / 64.0F;
              }

              vipldws2_B.col++;
              vipldws2_B.numEdge++;
            }

            while (vipldws2_B.firstRowOut <= vipldws2_B.lastRowOut) {
              vipldws2_DW.DrawShapes_DW_PixCount[vipldws2_B.firstRowOut] = 0U;
              vipldws2_B.firstRowOut++;
            }

            vipldws2_B.colOut++;
            vipldws2_B.colBoundary += 8;
            vipldws2_B.firstRowOut = 240;
            vipldws2_B.lastRowOut = 0;
          }
        }

        /* Move to the next polygon. */
        vipldws2_B.plane += vipldws2_B.c2 * 9;
        if (vipldws2_B.C2 >= div_s32_floor(vipldws2_B.c2, vipldws2_B.c2) - 1) {
          vipldws2_B.C2 = 0;
        } else {
          vipldws2_B.C2++;
        }

        c_gotAlLeastOneYellowPixelInThe = (vipldws2_B.plane < vipldws2_B.c2 * 9);
      }
    }

    /* End of S-Function (svipdrawshapes): '<S65>/DrawShapes' */
    srUpdateBC(vipldws2_DW.Draw3rdLine_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S5>/Draw  3rd Line' */

  /* Switch: '<S5>/Switch2' */
  if (vipldws2_B.LogicalOperator2) {
    memcpy(&vipldws2_B.Switch2[0], &vipldws2_B.DrawShapes_l[0], 230400U * sizeof
           (real32_T));
  } else {
    memcpy(&vipldws2_B.Switch2[0], &vipldws2_B.Switch[0], 230400U * sizeof
           (real32_T));
  }

  /* End of Switch: '<S5>/Switch2' */

  /* S-Function (svipscalenconvert): '<S5>/Image Data Type Conversion' */
  for (vipldws2_B.i = 0; vipldws2_B.i < 230400; vipldws2_B.i++) {
    vipldws2_B.scale = vipldws2_B.Switch2[vipldws2_B.i] * 255.0F + 0.5F;
    if (vipldws2_B.scale > 255.0F) {
      vipldws2_B.scale = 255.0F;
    }

    if (vipldws2_B.scale < 0.0F) {
      vipldws2_B.scale = 0.0F;
    }

    vipldws2_B.ImageDataTypeConversion_p[vipldws2_B.i] = (uint8_T)
      vipldws2_B.scale;
  }

  /* End of S-Function (svipscalenconvert): '<S5>/Image Data Type Conversion' */

  /* MinMax: '<S14>/MinMax' */
  if (vipldws2_B.Intersectionwithbottomimageboun <
      vipldws2_B.Intersectionwithbottomimagebo_g) {
    vipldws2_B.Saturation_d = vipldws2_B.Intersectionwithbottomimageboun;
  } else {
    vipldws2_B.Saturation_d = vipldws2_B.Intersectionwithbottomimagebo_g;
  }

  /* End of MinMax: '<S14>/MinMax' */

  /* Saturate: '<S14>/Saturation' */
  if (vipldws2_B.Saturation_d > vipldws2_P.Saturation_UpperSat_h) {
    vipldws2_B.Saturation_d = vipldws2_P.Saturation_UpperSat_h;
  } else {
    if (vipldws2_B.Saturation_d < vipldws2_P.Saturation_LowerSat_a) {
      vipldws2_B.Saturation_d = vipldws2_P.Saturation_LowerSat_a;
    }
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* DataTypeConversion: '<S14>/Data Type  Conversion' */
  vipldws2_B.Add = (real32_T)vipldws2_B.Saturation_d;

  /* DataTypeConversion: '<S14>/Data Type  Conversion1' */
  vipldws2_B.DataTypeConversion1 = (real32_T)
    vipldws2_B.Distancethresholdfordeparturewa;

  /* Sum: '<S14>/Add' */
  vipldws2_B.Add -= vipldws2_B.DataTypeConversion1;

  /* Product: '<S14>/Divide' */
  vipldws2_B.MatrixConcatenation2[0] = vipldws2_B.Add /
    vipldws2_B.DataTypeConversion1;

  /* Constant: '<S14>/min_safety' */
  vipldws2_B.MatrixConcatenation2[1] = vipldws2_P.min_safety_Value;
  for (vipldws2_B.i = 0; vipldws2_B.i < 20; vipldws2_B.i++) {
    /* RelationalOperator: '<S37>/Compare' incorporates:
     *  Constant: '<S37>/Constant'
     */
    vipldws2_B.Compare_m[vipldws2_B.i] = (vipldws2_B.Saturation_h[vipldws2_B.i] >=
      vipldws2_P.OnlyupdatethelineswhichKalmanfi);

    /* Switch: '<S38>/Reset' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S38>/Initial Condition'
     */
    if (vipldws2_P.Constant_Value_g) {
      vipldws2_B.Xnew_m[vipldws2_B.i] = vipldws2_P.UnitDelayResettable_vinit;
    } else {
      vipldws2_B.Xnew_m[vipldws2_B.i] = vipldws2_B.Saturation_h[vipldws2_B.i];
    }

    /* End of Switch: '<S38>/Reset' */
  }

  /* Outputs for Iterator SubSystem: '<S4>/Update' incorporates:
   *  ForIterator: '<S40>/For Iterator'
   */
  memcpy(&vipldws2_B.Assignment[0], &vipldws2_B.Assignment_a[0], 40U * sizeof
         (real32_T));
  vipldws2_B.s40_iter = 1;
  while (vipldws2_B.s40_iter <= vipldws2_P.ForIterator_IterationLimit_gd) {
    vipldws2_B.ForIterator = vipldws2_B.s40_iter;

    /* Selector: '<S40>/Selector' */
    vipldws2_B.Selector_b = vipldws2_B.Compare_m[vipldws2_B.ForIterator - 1];

    /* Switch: '<S40>/Switch1' */
    if (vipldws2_B.Selector_b) {
      /* Selector: '<S40>/Selector1' */
      vipldws2_B.Selector1[0] = vipldws2_B.Assignment_a[(vipldws2_B.ForIterator
        - 1) << 1];
      vipldws2_B.Switch1[0] = vipldws2_B.Selector1[0];

      /* Selector: '<S40>/Selector1' */
      vipldws2_B.Selector1[1] = vipldws2_B.Assignment_a[((vipldws2_B.ForIterator
        - 1) << 1) + 1];
      vipldws2_B.Switch1[1] = vipldws2_B.Selector1[1];
    } else {
      /* Selector: '<S40>/Selector2' */
      vipldws2_B.Selector2[0] = vipldws2_B.Assignment_i[(vipldws2_B.ForIterator
        - 1) << 1];
      vipldws2_B.Switch1[0] = vipldws2_B.Selector2[0];

      /* Selector: '<S40>/Selector2' */
      vipldws2_B.Selector2[1] = vipldws2_B.Assignment_i[((vipldws2_B.ForIterator
        - 1) << 1) + 1];
      vipldws2_B.Switch1[1] = vipldws2_B.Selector2[1];
    }

    /* End of Switch: '<S40>/Switch1' */

    /* Assignment: '<S40>/Assignment' */
    vipldws2_B.Assignment[(vipldws2_B.ForIterator - 1) << 1] =
      vipldws2_B.Switch1[0];
    vipldws2_B.Assignment[1 + ((vipldws2_B.ForIterator - 1) << 1)] =
      vipldws2_B.Switch1[1];
    vipldws2_B.s40_iter++;
  }

  /* End of Outputs for SubSystem: '<S4>/Update' */

  /* Update for UnitDelay: '<S39>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S39>/FixPt Constant'
   */
  vipldws2_DW.FixPtUnitDelay2_DSTATE = vipldws2_P.FixPtConstant_Value_e;
  for (vipldws2_B.i = 0; vipldws2_B.i < 40; vipldws2_B.i++) {
    /* Switch: '<S39>/Reset' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S39>/Initial Condition'
     */
    if (vipldws2_P.Constant_Value_g) {
      vipldws2_B.Xnew[vipldws2_B.i] =
        vipldws2_P.UnitDelayResettable1_vinit[vipldws2_B.i];
    } else {
      vipldws2_B.Xnew[vipldws2_B.i] = vipldws2_B.Assignment[vipldws2_B.i];
    }

    /* End of Switch: '<S39>/Reset' */

    /* Update for UnitDelay: '<S39>/FixPt Unit Delay1' */
    vipldws2_DW.FixPtUnitDelay1_DSTATE[vipldws2_B.i] =
      vipldws2_B.Xnew[vipldws2_B.i];
  }

  /* Update for UnitDelay: '<S38>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S38>/FixPt Constant'
   */
  vipldws2_DW.FixPtUnitDelay2_DSTATE_b = vipldws2_P.FixPtConstant_Value;

  /* Update for UnitDelay: '<S38>/FixPt Unit Delay1' */
  memcpy(&vipldws2_DW.FixPtUnitDelay1_DSTATE_d[0], &vipldws2_B.Xnew_m[0], 20U *
         sizeof(int32_T));

  /* Update for UnitDelay: '<S35>/En_Delay' */
  memcpy(&vipldws2_DW.En_Delay_DSTATE[0], &vipldws2_B.Saturation_h[0], 20U *
         sizeof(int32_T));

  /* Update for UnitDelay: '<S35>/Unit Delay2' */
  memcpy(&vipldws2_DW.UnitDelay2_DSTATE[0], &vipldws2_B.Assignment_o[0], 80U *
         sizeof(real32_T));

  /* Update for UnitDelay: '<S35>/Unit Delay3' */
  memcpy(&vipldws2_DW.UnitDelay3_DSTATE[0], &vipldws2_B.Assignment_io[0], 320U *
         sizeof(real32_T));

  /* Update for Delay: '<S17>/Delay' */
  vipldws2_DW.Delay_DSTATE = vipldws2_B.outMsg;

  /* Update for Delay: '<S17>/Delay1' */
  vipldws2_DW.Delay1_DSTATE_e = vipldws2_B.RawMessage;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    rtExtModeUpload(0, vipldws2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.033333333333333333s, 0.0s] */
    if ((rtmGetTFinal(vipldws2_M)!=-1) &&
        !((rtmGetTFinal(vipldws2_M)-vipldws2_M->Timing.taskTime0) >
          vipldws2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(vipldws2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(vipldws2_M)) {
      rtmSetErrorStatus(vipldws2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  vipldws2_M->Timing.taskTime0 =
    (++vipldws2_M->Timing.clockTick0) * vipldws2_M->Timing.stepSize0;
}

/* Model initialize function */
void vipldws2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)vipldws2_M, 0,
                sizeof(RT_MODEL_vipldws2_T));
  rtmSetTFinal(vipldws2_M, -1);
  vipldws2_M->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  vipldws2_M->Sizes.checksums[0] = (3383633471U);
  vipldws2_M->Sizes.checksums[1] = (3478459520U);
  vipldws2_M->Sizes.checksums[2] = (220928665U);
  vipldws2_M->Sizes.checksums[3] = (2149239437U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    vipldws2_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[12] = (sysRanDType *)&vipldws2_DW.SampleandHold_SubsysRanBC;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)&vipldws2_DW.Enablesignalgenerator_SubsysRan;
    systemRan[18] = (sysRanDType *)&vipldws2_DW.Core_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&vipldws2_DW.Options_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&vipldws2_DW.Options_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&vipldws2_DW.Options_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&vipldws2_DW.Options_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&vipldws2_DW.Options_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)&vipldws2_DW.Selectalinefromtherepositoryifi;
    systemRan[26] = (sysRanDType *)&vipldws2_DW.Differencebetweentwolines_Subsy;
    systemRan[27] = (sysRanDType *)&vipldws2_DW.Selectalinefromtherepositoryifi;
    systemRan[28] = (sysRanDType *)&vipldws2_DW.Selectalinefromtherepositoryifi;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = (sysRanDType *)&vipldws2_DW.Draw3rdLine_SubsysRanBC;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = (sysRanDType *)&vipldws2_DW.DrawPolygon_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&vipldws2_DW.Subsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(vipldws2_M->extModeInfo,
      &vipldws2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(vipldws2_M->extModeInfo, vipldws2_M->Sizes.checksums);
    rteiSetTPtr(vipldws2_M->extModeInfo, rtmGetTPtr(vipldws2_M));
  }

  /* block I/O */
  (void) memset(((void *) &vipldws2_B), 0,
                sizeof(B_vipldws2_T));

  {
    int32_T i;
    for (i = 0; i < 230400; i++) {
      vipldws2_B.ImageDataTypeConversion[i] = 0.0F;
    }

    for (i = 0; i < 76800; i++) {
      vipldws2_B.ColorSpaceConversion[i] = 0.0F;
    }

    for (i = 0; i < 38400; i++) {
      vipldws2_B.Clipimage[i] = 0.0F;
    }

    for (i = 0; i < 122940; i++) {
      vipldws2_B.HoughTransform_o1[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Init[i] = 0.0F;
    }

    for (i = 0; i < 80; i++) {
      vipldws2_B.UnitDelay2[i] = 0.0F;
    }

    for (i = 0; i < 320; i++) {
      vipldws2_B.UnitDelay3[i] = 0.0F;
    }

    for (i = 0; i < 115200; i++) {
      vipldws2_B.ColorSpaceConversion1[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.Switch[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Xnew[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.InsertTextRightLane[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.DrawShapes[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.DrawShapes_l[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Assignment[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Assignment_i[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws2_B.Selector2_n[i] = 0.0F;
    }

    for (i = 0; i < 320; i++) {
      vipldws2_B.Assignment_io[i] = 0.0F;
    }

    for (i = 0; i < 80; i++) {
      vipldws2_B.Assignment_o[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Assignment_p[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Assignment_a[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws2_B.P_prd_Reshape[i] = 0.0F;
    }

    for (i = 0; i < 38400; i++) {
      vipldws2_B.uDFIRFilter[i] = 0.0F;
    }

    for (i = 0; i < 38400; i++) {
      vipldws2_B.Saturation[i] = 0.0F;
    }

    for (i = 0; i < 231; i++) {
      vipldws2_B.selectrho5[i] = 0.0F;
    }

    for (i = 0; i < 40; i++) {
      vipldws2_B.Xold[i] = 0.0F;
    }

    for (i = 0; i < 122940; i++) {
      vipldws2_B.OverwriteValues[i] = 0.0F;
    }

    for (i = 0; i < 122940; i++) {
      vipldws2_B.OverwriteValues1[i] = 0.0F;
    }

    for (i = 0; i < 20; i++) {
      vipldws2_B.selectrho5_f[i] = 0.0F;
    }

    for (i = 0; i < 20; i++) {
      vipldws2_B.selectrho2[i] = 0.0F;
    }

    for (i = 0; i < 756; i++) {
      vipldws2_B.selectrho5_m[i] = 0.0F;
    }

    for (i = 0; i < 115200; i++) {
      vipldws2_B.Selector_a[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.DrawShapes_m[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.InsertText[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.InsertTextLeftLane[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws2_B.Switch_m[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws2_B.HP_prdt[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws2_B.y[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws2_B.MatrixScaling[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws2_B.BackwardSubstitution[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      vipldws2_B.KTrans[i] = 0.0F;
    }

    for (i = 0; i < 230400; i++) {
      vipldws2_B.Switch2[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws2_B.APAtQ[i] = 0.0F;
    }

    for (i = 0; i < 16; i++) {
      vipldws2_B.P_prdKHP_prd[i] = 0.0F;
    }

    vipldws2_B.Probe[0] = 0.0;
    vipldws2_B.Probe[1] = 0.0;
    vipldws2_B.Selector = 0.0;
    vipldws2_B.MatrixConcatenation3[0] = 0.0F;
    vipldws2_B.MatrixConcatenation3[1] = 0.0F;
    vipldws2_B.MatrixConcatenation3[2] = 0.0F;
    vipldws2_B.MatrixConcatenation3[3] = 0.0F;
    vipldws2_B.MatrixConcatenation2[0] = 0.0F;
    vipldws2_B.MatrixConcatenation2[1] = 0.0F;
    vipldws2_B.Selector1[0] = 0.0F;
    vipldws2_B.Selector1[1] = 0.0F;
    vipldws2_B.Selector2[0] = 0.0F;
    vipldws2_B.Selector2[1] = 0.0F;
    vipldws2_B.Selector2_f[0] = 0.0F;
    vipldws2_B.Selector2_f[1] = 0.0F;
    vipldws2_B.Selector1_k[0] = 0.0F;
    vipldws2_B.Selector1_k[1] = 0.0F;
    vipldws2_B.Selector_i[0] = 0.0F;
    vipldws2_B.Selector_i[1] = 0.0F;
    vipldws2_B.Selector1_c[0] = 0.0F;
    vipldws2_B.Selector1_c[1] = 0.0F;
    vipldws2_B.Selector1_c[2] = 0.0F;
    vipldws2_B.Selector1_c[3] = 0.0F;
    vipldws2_B.AX[0] = 0.0F;
    vipldws2_B.AX[1] = 0.0F;
    vipldws2_B.AX[2] = 0.0F;
    vipldws2_B.AX[3] = 0.0F;
    vipldws2_B.Z_est_Multiply[0] = 0.0F;
    vipldws2_B.Z_est_Multiply[1] = 0.0F;
    vipldws2_B.Z_prd_Multiply[0] = 0.0F;
    vipldws2_B.Z_prd_Multiply[1] = 0.0F;
    vipldws2_B.Selectorrho[0] = 0.0F;
    vipldws2_B.Selectorrho[1] = 0.0F;
    vipldws2_B.Selectortheta[0] = 0.0F;
    vipldws2_B.Selectortheta[1] = 0.0F;
    vipldws2_B.DataTypeConversion1 = 0.0F;
    vipldws2_B.Selectorrho_c = 0.0F;
    vipldws2_B.Selectortheta_i = 0.0F;
    vipldws2_B.Selectorrho_o = 0.0F;
    vipldws2_B.Selectortheta_g = 0.0F;
    vipldws2_B.Switch1[0] = 0.0F;
    vipldws2_B.Switch1[1] = 0.0F;
    vipldws2_B.Selector2_b[0] = 0.0F;
    vipldws2_B.Selector2_b[1] = 0.0F;
    vipldws2_B.Rho_2 = 0.0F;
    vipldws2_B.Switch_l[0] = 0.0F;
    vipldws2_B.Switch_l[1] = 0.0F;
    vipldws2_B.Switch_l[2] = 0.0F;
    vipldws2_B.Switch_l[3] = 0.0F;
    vipldws2_B.LDLFactorization[0] = 0.0F;
    vipldws2_B.LDLFactorization[1] = 0.0F;
    vipldws2_B.LDLFactorization[2] = 0.0F;
    vipldws2_B.LDLFactorization[3] = 0.0F;
    vipldws2_B.d[0] = 0.0F;
    vipldws2_B.d[1] = 0.0F;
    vipldws2_B.Add = 0.0F;
    vipldws2_B.Switch_j[0] = 0.0F;
    vipldws2_B.Switch_j[1] = 0.0F;
    vipldws2_B.HP_prdtHtR[0] = 0.0F;
    vipldws2_B.HP_prdtHtR[1] = 0.0F;
    vipldws2_B.HP_prdtHtR[2] = 0.0F;
    vipldws2_B.HP_prdtHtR[3] = 0.0F;
    vipldws2_B.X_prdKZHX_prd[0] = 0.0F;
    vipldws2_B.X_prdKZHX_prd[1] = 0.0F;
    vipldws2_B.X_prdKZHX_prd[2] = 0.0F;
    vipldws2_B.X_prdKZHX_prd[3] = 0.0F;
    vipldws2_B.Selector5[0] = 0.0F;
    vipldws2_B.Selector5[1] = 0.0F;
    vipldws2_B.Selector5[2] = 0.0F;
    vipldws2_B.ZHX_prd[0] = 0.0F;
    vipldws2_B.ZHX_prd[1] = 0.0F;
    vipldws2_B.Gain = 0.0F;
    vipldws2_B.HoughTransform_o2[0] = -1.57079637F;
    vipldws2_B.HoughTransform_o2[1] = -1.55334306F;
    vipldws2_B.HoughTransform_o2[2] = -1.53588974F;
    vipldws2_B.HoughTransform_o2[3] = -1.51843643F;
    vipldws2_B.HoughTransform_o2[4] = -1.50098312F;
    vipldws2_B.HoughTransform_o2[5] = -1.48352981F;
    vipldws2_B.HoughTransform_o2[6] = -1.46607661F;
    vipldws2_B.HoughTransform_o2[7] = -1.4486233F;
    vipldws2_B.HoughTransform_o2[8] = -1.43117F;
    vipldws2_B.HoughTransform_o2[9] = -1.41371667F;
    vipldws2_B.HoughTransform_o2[10] = -1.39626336F;
    vipldws2_B.HoughTransform_o2[11] = -1.37881017F;
    vipldws2_B.HoughTransform_o2[12] = -1.36135685F;
    vipldws2_B.HoughTransform_o2[13] = -1.34390354F;
    vipldws2_B.HoughTransform_o2[14] = -1.32645023F;
    vipldws2_B.HoughTransform_o2[15] = -1.30899692F;
    vipldws2_B.HoughTransform_o2[16] = -1.2915436F;
    vipldws2_B.HoughTransform_o2[17] = -1.27409041F;
    vipldws2_B.HoughTransform_o2[18] = -1.2566371F;
    vipldws2_B.HoughTransform_o2[19] = -1.23918378F;
    vipldws2_B.HoughTransform_o2[20] = -1.22173047F;
    vipldws2_B.HoughTransform_o2[21] = -1.20427716F;
    vipldws2_B.HoughTransform_o2[22] = -1.18682384F;
    vipldws2_B.HoughTransform_o2[23] = -1.16937065F;
    vipldws2_B.HoughTransform_o2[24] = -1.15191734F;
    vipldws2_B.HoughTransform_o2[25] = -1.13446403F;
    vipldws2_B.HoughTransform_o2[26] = -1.11701071F;
    vipldws2_B.HoughTransform_o2[27] = -1.0995574F;
    vipldws2_B.HoughTransform_o2[28] = -1.08210409F;
    vipldws2_B.HoughTransform_o2[29] = -1.06465089F;
    vipldws2_B.HoughTransform_o2[30] = -1.04719758F;
    vipldws2_B.HoughTransform_o2[31] = -1.02974427F;
    vipldws2_B.HoughTransform_o2[32] = -1.01229095F;
    vipldws2_B.HoughTransform_o2[33] = -0.994837701F;
    vipldws2_B.HoughTransform_o2[34] = -0.977384388F;
    vipldws2_B.HoughTransform_o2[35] = -0.959931076F;
    vipldws2_B.HoughTransform_o2[36] = -0.942477822F;
    vipldws2_B.HoughTransform_o2[37] = -0.925024509F;
    vipldws2_B.HoughTransform_o2[38] = -0.907571197F;
    vipldws2_B.HoughTransform_o2[39] = -0.890117943F;
    vipldws2_B.HoughTransform_o2[40] = -0.87266463F;
    vipldws2_B.HoughTransform_o2[41] = -0.855211318F;
    vipldws2_B.HoughTransform_o2[42] = -0.837758064F;
    vipldws2_B.HoughTransform_o2[43] = -0.820304751F;
    vipldws2_B.HoughTransform_o2[44] = -0.802851439F;
    vipldws2_B.HoughTransform_o2[45] = -0.785398185F;
    vipldws2_B.HoughTransform_o2[46] = -0.767944872F;
    vipldws2_B.HoughTransform_o2[47] = -0.75049156F;
    vipldws2_B.HoughTransform_o2[48] = -0.733038306F;
    vipldws2_B.HoughTransform_o2[49] = -0.715585F;
    vipldws2_B.HoughTransform_o2[50] = -0.69813168F;
    vipldws2_B.HoughTransform_o2[51] = -0.680678427F;
    vipldws2_B.HoughTransform_o2[52] = -0.663225114F;
    vipldws2_B.HoughTransform_o2[53] = -0.645771801F;
    vipldws2_B.HoughTransform_o2[54] = -0.628318548F;
    vipldws2_B.HoughTransform_o2[55] = -0.610865235F;
    vipldws2_B.HoughTransform_o2[56] = -0.593411922F;
    vipldws2_B.HoughTransform_o2[57] = -0.575958669F;
    vipldws2_B.HoughTransform_o2[58] = -0.558505356F;
    vipldws2_B.HoughTransform_o2[59] = -0.541052043F;
    vipldws2_B.HoughTransform_o2[60] = -0.52359879F;
    vipldws2_B.HoughTransform_o2[61] = -0.506145477F;
    vipldws2_B.HoughTransform_o2[62] = -0.488692194F;
    vipldws2_B.HoughTransform_o2[63] = -0.471238911F;
    vipldws2_B.HoughTransform_o2[64] = -0.453785598F;
    vipldws2_B.HoughTransform_o2[65] = -0.436332315F;
    vipldws2_B.HoughTransform_o2[66] = -0.418879032F;
    vipldws2_B.HoughTransform_o2[67] = -0.401425719F;
    vipldws2_B.HoughTransform_o2[68] = -0.383972436F;
    vipldws2_B.HoughTransform_o2[69] = -0.366519153F;
    vipldws2_B.HoughTransform_o2[70] = -0.34906584F;
    vipldws2_B.HoughTransform_o2[71] = -0.331612557F;
    vipldws2_B.HoughTransform_o2[72] = -0.314159274F;
    vipldws2_B.HoughTransform_o2[73] = -0.296705961F;
    vipldws2_B.HoughTransform_o2[74] = -0.279252678F;
    vipldws2_B.HoughTransform_o2[75] = -0.261799395F;
    vipldws2_B.HoughTransform_o2[76] = -0.244346097F;
    vipldws2_B.HoughTransform_o2[77] = -0.226892799F;
    vipldws2_B.HoughTransform_o2[78] = -0.209439516F;
    vipldws2_B.HoughTransform_o2[79] = -0.191986218F;
    vipldws2_B.HoughTransform_o2[80] = -0.17453292F;
    vipldws2_B.HoughTransform_o2[81] = -0.157079637F;
    vipldws2_B.HoughTransform_o2[82] = -0.139626339F;
    vipldws2_B.HoughTransform_o2[83] = -0.122173049F;
    vipldws2_B.HoughTransform_o2[84] = -0.104719758F;
    vipldws2_B.HoughTransform_o2[85] = -0.0872664601F;
    vipldws2_B.HoughTransform_o2[86] = -0.0698131695F;
    vipldws2_B.HoughTransform_o2[87] = -0.052359879F;
    vipldws2_B.HoughTransform_o2[88] = -0.0349065848F;
    vipldws2_B.HoughTransform_o2[89] = -0.0174532924F;
    vipldws2_B.HoughTransform_o2[90] = 0.0F;
    vipldws2_B.HoughTransform_o2[91] = 0.0174532924F;
    vipldws2_B.HoughTransform_o2[92] = 0.0349065848F;
    vipldws2_B.HoughTransform_o2[93] = 0.052359879F;
    vipldws2_B.HoughTransform_o2[94] = 0.0698131695F;
    vipldws2_B.HoughTransform_o2[95] = 0.0872664601F;
    vipldws2_B.HoughTransform_o2[96] = 0.104719758F;
    vipldws2_B.HoughTransform_o2[97] = 0.122173049F;
    vipldws2_B.HoughTransform_o2[98] = 0.139626339F;
    vipldws2_B.HoughTransform_o2[99] = 0.157079637F;
    vipldws2_B.HoughTransform_o2[100] = 0.17453292F;
    vipldws2_B.HoughTransform_o2[101] = 0.191986218F;
    vipldws2_B.HoughTransform_o2[102] = 0.209439516F;
    vipldws2_B.HoughTransform_o2[103] = 0.226892799F;
    vipldws2_B.HoughTransform_o2[104] = 0.244346097F;
    vipldws2_B.HoughTransform_o2[105] = 0.261799395F;
    vipldws2_B.HoughTransform_o2[106] = 0.279252678F;
    vipldws2_B.HoughTransform_o2[107] = 0.296705961F;
    vipldws2_B.HoughTransform_o2[108] = 0.314159274F;
    vipldws2_B.HoughTransform_o2[109] = 0.331612557F;
    vipldws2_B.HoughTransform_o2[110] = 0.34906584F;
    vipldws2_B.HoughTransform_o2[111] = 0.366519153F;
    vipldws2_B.HoughTransform_o2[112] = 0.383972436F;
    vipldws2_B.HoughTransform_o2[113] = 0.401425719F;
    vipldws2_B.HoughTransform_o2[114] = 0.418879032F;
    vipldws2_B.HoughTransform_o2[115] = 0.436332315F;
    vipldws2_B.HoughTransform_o2[116] = 0.453785598F;
    vipldws2_B.HoughTransform_o2[117] = 0.471238911F;
    vipldws2_B.HoughTransform_o2[118] = 0.488692194F;
    vipldws2_B.HoughTransform_o2[119] = 0.506145477F;
    vipldws2_B.HoughTransform_o2[120] = 0.52359879F;
    vipldws2_B.HoughTransform_o2[121] = 0.541052043F;
    vipldws2_B.HoughTransform_o2[122] = 0.558505356F;
    vipldws2_B.HoughTransform_o2[123] = 0.575958669F;
    vipldws2_B.HoughTransform_o2[124] = 0.593411922F;
    vipldws2_B.HoughTransform_o2[125] = 0.610865235F;
    vipldws2_B.HoughTransform_o2[126] = 0.628318548F;
    vipldws2_B.HoughTransform_o2[127] = 0.645771801F;
    vipldws2_B.HoughTransform_o2[128] = 0.663225114F;
    vipldws2_B.HoughTransform_o2[129] = 0.680678427F;
    vipldws2_B.HoughTransform_o2[130] = 0.69813168F;
    vipldws2_B.HoughTransform_o2[131] = 0.715585F;
    vipldws2_B.HoughTransform_o2[132] = 0.733038306F;
    vipldws2_B.HoughTransform_o2[133] = 0.75049156F;
    vipldws2_B.HoughTransform_o2[134] = 0.767944872F;
    vipldws2_B.HoughTransform_o2[135] = 0.785398185F;
    vipldws2_B.HoughTransform_o2[136] = 0.802851439F;
    vipldws2_B.HoughTransform_o2[137] = 0.820304751F;
    vipldws2_B.HoughTransform_o2[138] = 0.837758064F;
    vipldws2_B.HoughTransform_o2[139] = 0.855211318F;
    vipldws2_B.HoughTransform_o2[140] = 0.87266463F;
    vipldws2_B.HoughTransform_o2[141] = 0.890117943F;
    vipldws2_B.HoughTransform_o2[142] = 0.907571197F;
    vipldws2_B.HoughTransform_o2[143] = 0.925024509F;
    vipldws2_B.HoughTransform_o2[144] = 0.942477822F;
    vipldws2_B.HoughTransform_o2[145] = 0.959931076F;
    vipldws2_B.HoughTransform_o2[146] = 0.977384388F;
    vipldws2_B.HoughTransform_o2[147] = 0.994837701F;
    vipldws2_B.HoughTransform_o2[148] = 1.01229095F;
    vipldws2_B.HoughTransform_o2[149] = 1.02974427F;
    vipldws2_B.HoughTransform_o2[150] = 1.04719758F;
    vipldws2_B.HoughTransform_o2[151] = 1.06465089F;
    vipldws2_B.HoughTransform_o2[152] = 1.08210409F;
    vipldws2_B.HoughTransform_o2[153] = 1.0995574F;
    vipldws2_B.HoughTransform_o2[154] = 1.11701071F;
    vipldws2_B.HoughTransform_o2[155] = 1.13446403F;
    vipldws2_B.HoughTransform_o2[156] = 1.15191734F;
    vipldws2_B.HoughTransform_o2[157] = 1.16937065F;
    vipldws2_B.HoughTransform_o2[158] = 1.18682384F;
    vipldws2_B.HoughTransform_o2[159] = 1.20427716F;
    vipldws2_B.HoughTransform_o2[160] = 1.22173047F;
    vipldws2_B.HoughTransform_o2[161] = 1.23918378F;
    vipldws2_B.HoughTransform_o2[162] = 1.2566371F;
    vipldws2_B.HoughTransform_o2[163] = 1.27409041F;
    vipldws2_B.HoughTransform_o2[164] = 1.2915436F;
    vipldws2_B.HoughTransform_o2[165] = 1.30899692F;
    vipldws2_B.HoughTransform_o2[166] = 1.32645023F;
    vipldws2_B.HoughTransform_o2[167] = 1.34390354F;
    vipldws2_B.HoughTransform_o2[168] = 1.36135685F;
    vipldws2_B.HoughTransform_o2[169] = 1.37881017F;
    vipldws2_B.HoughTransform_o2[170] = 1.39626336F;
    vipldws2_B.HoughTransform_o2[171] = 1.41371667F;
    vipldws2_B.HoughTransform_o2[172] = 1.43117F;
    vipldws2_B.HoughTransform_o2[173] = 1.4486233F;
    vipldws2_B.HoughTransform_o2[174] = 1.46607661F;
    vipldws2_B.HoughTransform_o2[175] = 1.48352981F;
    vipldws2_B.HoughTransform_o2[176] = 1.50098312F;
    vipldws2_B.HoughTransform_o2[177] = 1.51843643F;
    vipldws2_B.HoughTransform_o2[178] = 1.53588974F;
    vipldws2_B.HoughTransform_o2[179] = 1.55334306F;
    vipldws2_B.HoughTransform_o3[0] = -341.0F;
    vipldws2_B.HoughTransform_o3[1] = -340.0F;
    vipldws2_B.HoughTransform_o3[2] = -339.0F;
    vipldws2_B.HoughTransform_o3[3] = -338.0F;
    vipldws2_B.HoughTransform_o3[4] = -337.0F;
    vipldws2_B.HoughTransform_o3[5] = -336.0F;
    vipldws2_B.HoughTransform_o3[6] = -335.0F;
    vipldws2_B.HoughTransform_o3[7] = -334.0F;
    vipldws2_B.HoughTransform_o3[8] = -333.0F;
    vipldws2_B.HoughTransform_o3[9] = -332.0F;
    vipldws2_B.HoughTransform_o3[10] = -331.0F;
    vipldws2_B.HoughTransform_o3[11] = -330.0F;
    vipldws2_B.HoughTransform_o3[12] = -329.0F;
    vipldws2_B.HoughTransform_o3[13] = -328.0F;
    vipldws2_B.HoughTransform_o3[14] = -327.0F;
    vipldws2_B.HoughTransform_o3[15] = -326.0F;
    vipldws2_B.HoughTransform_o3[16] = -325.0F;
    vipldws2_B.HoughTransform_o3[17] = -324.0F;
    vipldws2_B.HoughTransform_o3[18] = -323.0F;
    vipldws2_B.HoughTransform_o3[19] = -322.0F;
    vipldws2_B.HoughTransform_o3[20] = -321.0F;
    vipldws2_B.HoughTransform_o3[21] = -320.0F;
    vipldws2_B.HoughTransform_o3[22] = -319.0F;
    vipldws2_B.HoughTransform_o3[23] = -318.0F;
    vipldws2_B.HoughTransform_o3[24] = -317.0F;
    vipldws2_B.HoughTransform_o3[25] = -316.0F;
    vipldws2_B.HoughTransform_o3[26] = -315.0F;
    vipldws2_B.HoughTransform_o3[27] = -314.0F;
    vipldws2_B.HoughTransform_o3[28] = -313.0F;
    vipldws2_B.HoughTransform_o3[29] = -312.0F;
    vipldws2_B.HoughTransform_o3[30] = -311.0F;
    vipldws2_B.HoughTransform_o3[31] = -310.0F;
    vipldws2_B.HoughTransform_o3[32] = -309.0F;
    vipldws2_B.HoughTransform_o3[33] = -308.0F;
    vipldws2_B.HoughTransform_o3[34] = -307.0F;
    vipldws2_B.HoughTransform_o3[35] = -306.0F;
    vipldws2_B.HoughTransform_o3[36] = -305.0F;
    vipldws2_B.HoughTransform_o3[37] = -304.0F;
    vipldws2_B.HoughTransform_o3[38] = -303.0F;
    vipldws2_B.HoughTransform_o3[39] = -302.0F;
    vipldws2_B.HoughTransform_o3[40] = -301.0F;
    vipldws2_B.HoughTransform_o3[41] = -300.0F;
    vipldws2_B.HoughTransform_o3[42] = -299.0F;
    vipldws2_B.HoughTransform_o3[43] = -298.0F;
    vipldws2_B.HoughTransform_o3[44] = -297.0F;
    vipldws2_B.HoughTransform_o3[45] = -296.0F;
    vipldws2_B.HoughTransform_o3[46] = -295.0F;
    vipldws2_B.HoughTransform_o3[47] = -294.0F;
    vipldws2_B.HoughTransform_o3[48] = -293.0F;
    vipldws2_B.HoughTransform_o3[49] = -292.0F;
    vipldws2_B.HoughTransform_o3[50] = -291.0F;
    vipldws2_B.HoughTransform_o3[51] = -290.0F;
    vipldws2_B.HoughTransform_o3[52] = -289.0F;
    vipldws2_B.HoughTransform_o3[53] = -288.0F;
    vipldws2_B.HoughTransform_o3[54] = -287.0F;
    vipldws2_B.HoughTransform_o3[55] = -286.0F;
    vipldws2_B.HoughTransform_o3[56] = -285.0F;
    vipldws2_B.HoughTransform_o3[57] = -284.0F;
    vipldws2_B.HoughTransform_o3[58] = -283.0F;
    vipldws2_B.HoughTransform_o3[59] = -282.0F;
    vipldws2_B.HoughTransform_o3[60] = -281.0F;
    vipldws2_B.HoughTransform_o3[61] = -280.0F;
    vipldws2_B.HoughTransform_o3[62] = -279.0F;
    vipldws2_B.HoughTransform_o3[63] = -278.0F;
    vipldws2_B.HoughTransform_o3[64] = -277.0F;
    vipldws2_B.HoughTransform_o3[65] = -276.0F;
    vipldws2_B.HoughTransform_o3[66] = -275.0F;
    vipldws2_B.HoughTransform_o3[67] = -274.0F;
    vipldws2_B.HoughTransform_o3[68] = -273.0F;
    vipldws2_B.HoughTransform_o3[69] = -272.0F;
    vipldws2_B.HoughTransform_o3[70] = -271.0F;
    vipldws2_B.HoughTransform_o3[71] = -270.0F;
    vipldws2_B.HoughTransform_o3[72] = -269.0F;
    vipldws2_B.HoughTransform_o3[73] = -268.0F;
    vipldws2_B.HoughTransform_o3[74] = -267.0F;
    vipldws2_B.HoughTransform_o3[75] = -266.0F;
    vipldws2_B.HoughTransform_o3[76] = -265.0F;
    vipldws2_B.HoughTransform_o3[77] = -264.0F;
    vipldws2_B.HoughTransform_o3[78] = -263.0F;
    vipldws2_B.HoughTransform_o3[79] = -262.0F;
    vipldws2_B.HoughTransform_o3[80] = -261.0F;
    vipldws2_B.HoughTransform_o3[81] = -260.0F;
    vipldws2_B.HoughTransform_o3[82] = -259.0F;
    vipldws2_B.HoughTransform_o3[83] = -258.0F;
    vipldws2_B.HoughTransform_o3[84] = -257.0F;
    vipldws2_B.HoughTransform_o3[85] = -256.0F;
    vipldws2_B.HoughTransform_o3[86] = -255.0F;
    vipldws2_B.HoughTransform_o3[87] = -254.0F;
    vipldws2_B.HoughTransform_o3[88] = -253.0F;
    vipldws2_B.HoughTransform_o3[89] = -252.0F;
    vipldws2_B.HoughTransform_o3[90] = -251.0F;
    vipldws2_B.HoughTransform_o3[91] = -250.0F;
    vipldws2_B.HoughTransform_o3[92] = -249.0F;
    vipldws2_B.HoughTransform_o3[93] = -248.0F;
    vipldws2_B.HoughTransform_o3[94] = -247.0F;
    vipldws2_B.HoughTransform_o3[95] = -246.0F;
    vipldws2_B.HoughTransform_o3[96] = -245.0F;
    vipldws2_B.HoughTransform_o3[97] = -244.0F;
    vipldws2_B.HoughTransform_o3[98] = -243.0F;
    vipldws2_B.HoughTransform_o3[99] = -242.0F;
    vipldws2_B.HoughTransform_o3[100] = -241.0F;
    vipldws2_B.HoughTransform_o3[101] = -240.0F;
    vipldws2_B.HoughTransform_o3[102] = -239.0F;
    vipldws2_B.HoughTransform_o3[103] = -238.0F;
    vipldws2_B.HoughTransform_o3[104] = -237.0F;
    vipldws2_B.HoughTransform_o3[105] = -236.0F;
    vipldws2_B.HoughTransform_o3[106] = -235.0F;
    vipldws2_B.HoughTransform_o3[107] = -234.0F;
    vipldws2_B.HoughTransform_o3[108] = -233.0F;
    vipldws2_B.HoughTransform_o3[109] = -232.0F;
    vipldws2_B.HoughTransform_o3[110] = -231.0F;
    vipldws2_B.HoughTransform_o3[111] = -230.0F;
    vipldws2_B.HoughTransform_o3[112] = -229.0F;
    vipldws2_B.HoughTransform_o3[113] = -228.0F;
    vipldws2_B.HoughTransform_o3[114] = -227.0F;
    vipldws2_B.HoughTransform_o3[115] = -226.0F;
    vipldws2_B.HoughTransform_o3[116] = -225.0F;
    vipldws2_B.HoughTransform_o3[117] = -224.0F;
    vipldws2_B.HoughTransform_o3[118] = -223.0F;
    vipldws2_B.HoughTransform_o3[119] = -222.0F;
    vipldws2_B.HoughTransform_o3[120] = -221.0F;
    vipldws2_B.HoughTransform_o3[121] = -220.0F;
    vipldws2_B.HoughTransform_o3[122] = -219.0F;
    vipldws2_B.HoughTransform_o3[123] = -218.0F;
    vipldws2_B.HoughTransform_o3[124] = -217.0F;
    vipldws2_B.HoughTransform_o3[125] = -216.0F;
    vipldws2_B.HoughTransform_o3[126] = -215.0F;
    vipldws2_B.HoughTransform_o3[127] = -214.0F;
    vipldws2_B.HoughTransform_o3[128] = -213.0F;
    vipldws2_B.HoughTransform_o3[129] = -212.0F;
    vipldws2_B.HoughTransform_o3[130] = -211.0F;
    vipldws2_B.HoughTransform_o3[131] = -210.0F;
    vipldws2_B.HoughTransform_o3[132] = -209.0F;
    vipldws2_B.HoughTransform_o3[133] = -208.0F;
    vipldws2_B.HoughTransform_o3[134] = -207.0F;
    vipldws2_B.HoughTransform_o3[135] = -206.0F;
    vipldws2_B.HoughTransform_o3[136] = -205.0F;
    vipldws2_B.HoughTransform_o3[137] = -204.0F;
    vipldws2_B.HoughTransform_o3[138] = -203.0F;
    vipldws2_B.HoughTransform_o3[139] = -202.0F;
    vipldws2_B.HoughTransform_o3[140] = -201.0F;
    vipldws2_B.HoughTransform_o3[141] = -200.0F;
    vipldws2_B.HoughTransform_o3[142] = -199.0F;
    vipldws2_B.HoughTransform_o3[143] = -198.0F;
    vipldws2_B.HoughTransform_o3[144] = -197.0F;
    vipldws2_B.HoughTransform_o3[145] = -196.0F;
    vipldws2_B.HoughTransform_o3[146] = -195.0F;
    vipldws2_B.HoughTransform_o3[147] = -194.0F;
    vipldws2_B.HoughTransform_o3[148] = -193.0F;
    vipldws2_B.HoughTransform_o3[149] = -192.0F;
    vipldws2_B.HoughTransform_o3[150] = -191.0F;
    vipldws2_B.HoughTransform_o3[151] = -190.0F;
    vipldws2_B.HoughTransform_o3[152] = -189.0F;
    vipldws2_B.HoughTransform_o3[153] = -188.0F;
    vipldws2_B.HoughTransform_o3[154] = -187.0F;
    vipldws2_B.HoughTransform_o3[155] = -186.0F;
    vipldws2_B.HoughTransform_o3[156] = -185.0F;
    vipldws2_B.HoughTransform_o3[157] = -184.0F;
    vipldws2_B.HoughTransform_o3[158] = -183.0F;
    vipldws2_B.HoughTransform_o3[159] = -182.0F;
    vipldws2_B.HoughTransform_o3[160] = -181.0F;
    vipldws2_B.HoughTransform_o3[161] = -180.0F;
    vipldws2_B.HoughTransform_o3[162] = -179.0F;
    vipldws2_B.HoughTransform_o3[163] = -178.0F;
    vipldws2_B.HoughTransform_o3[164] = -177.0F;
    vipldws2_B.HoughTransform_o3[165] = -176.0F;
    vipldws2_B.HoughTransform_o3[166] = -175.0F;
    vipldws2_B.HoughTransform_o3[167] = -174.0F;
    vipldws2_B.HoughTransform_o3[168] = -173.0F;
    vipldws2_B.HoughTransform_o3[169] = -172.0F;
    vipldws2_B.HoughTransform_o3[170] = -171.0F;
    vipldws2_B.HoughTransform_o3[171] = -170.0F;
    vipldws2_B.HoughTransform_o3[172] = -169.0F;
    vipldws2_B.HoughTransform_o3[173] = -168.0F;
    vipldws2_B.HoughTransform_o3[174] = -167.0F;
    vipldws2_B.HoughTransform_o3[175] = -166.0F;
    vipldws2_B.HoughTransform_o3[176] = -165.0F;
    vipldws2_B.HoughTransform_o3[177] = -164.0F;
    vipldws2_B.HoughTransform_o3[178] = -163.0F;
    vipldws2_B.HoughTransform_o3[179] = -162.0F;
    vipldws2_B.HoughTransform_o3[180] = -161.0F;
    vipldws2_B.HoughTransform_o3[181] = -160.0F;
    vipldws2_B.HoughTransform_o3[182] = -159.0F;
    vipldws2_B.HoughTransform_o3[183] = -158.0F;
    vipldws2_B.HoughTransform_o3[184] = -157.0F;
    vipldws2_B.HoughTransform_o3[185] = -156.0F;
    vipldws2_B.HoughTransform_o3[186] = -155.0F;
    vipldws2_B.HoughTransform_o3[187] = -154.0F;
    vipldws2_B.HoughTransform_o3[188] = -153.0F;
    vipldws2_B.HoughTransform_o3[189] = -152.0F;
    vipldws2_B.HoughTransform_o3[190] = -151.0F;
    vipldws2_B.HoughTransform_o3[191] = -150.0F;
    vipldws2_B.HoughTransform_o3[192] = -149.0F;
    vipldws2_B.HoughTransform_o3[193] = -148.0F;
    vipldws2_B.HoughTransform_o3[194] = -147.0F;
    vipldws2_B.HoughTransform_o3[195] = -146.0F;
    vipldws2_B.HoughTransform_o3[196] = -145.0F;
    vipldws2_B.HoughTransform_o3[197] = -144.0F;
    vipldws2_B.HoughTransform_o3[198] = -143.0F;
    vipldws2_B.HoughTransform_o3[199] = -142.0F;
    vipldws2_B.HoughTransform_o3[200] = -141.0F;
    vipldws2_B.HoughTransform_o3[201] = -140.0F;
    vipldws2_B.HoughTransform_o3[202] = -139.0F;
    vipldws2_B.HoughTransform_o3[203] = -138.0F;
    vipldws2_B.HoughTransform_o3[204] = -137.0F;
    vipldws2_B.HoughTransform_o3[205] = -136.0F;
    vipldws2_B.HoughTransform_o3[206] = -135.0F;
    vipldws2_B.HoughTransform_o3[207] = -134.0F;
    vipldws2_B.HoughTransform_o3[208] = -133.0F;
    vipldws2_B.HoughTransform_o3[209] = -132.0F;
    vipldws2_B.HoughTransform_o3[210] = -131.0F;
    vipldws2_B.HoughTransform_o3[211] = -130.0F;
    vipldws2_B.HoughTransform_o3[212] = -129.0F;
    vipldws2_B.HoughTransform_o3[213] = -128.0F;
    vipldws2_B.HoughTransform_o3[214] = -127.0F;
    vipldws2_B.HoughTransform_o3[215] = -126.0F;
    vipldws2_B.HoughTransform_o3[216] = -125.0F;
    vipldws2_B.HoughTransform_o3[217] = -124.0F;
    vipldws2_B.HoughTransform_o3[218] = -123.0F;
    vipldws2_B.HoughTransform_o3[219] = -122.0F;
    vipldws2_B.HoughTransform_o3[220] = -121.0F;
    vipldws2_B.HoughTransform_o3[221] = -120.0F;
    vipldws2_B.HoughTransform_o3[222] = -119.0F;
    vipldws2_B.HoughTransform_o3[223] = -118.0F;
    vipldws2_B.HoughTransform_o3[224] = -117.0F;
    vipldws2_B.HoughTransform_o3[225] = -116.0F;
    vipldws2_B.HoughTransform_o3[226] = -115.0F;
    vipldws2_B.HoughTransform_o3[227] = -114.0F;
    vipldws2_B.HoughTransform_o3[228] = -113.0F;
    vipldws2_B.HoughTransform_o3[229] = -112.0F;
    vipldws2_B.HoughTransform_o3[230] = -111.0F;
    vipldws2_B.HoughTransform_o3[231] = -110.0F;
    vipldws2_B.HoughTransform_o3[232] = -109.0F;
    vipldws2_B.HoughTransform_o3[233] = -108.0F;
    vipldws2_B.HoughTransform_o3[234] = -107.0F;
    vipldws2_B.HoughTransform_o3[235] = -106.0F;
    vipldws2_B.HoughTransform_o3[236] = -105.0F;
    vipldws2_B.HoughTransform_o3[237] = -104.0F;
    vipldws2_B.HoughTransform_o3[238] = -103.0F;
    vipldws2_B.HoughTransform_o3[239] = -102.0F;
    vipldws2_B.HoughTransform_o3[240] = -101.0F;
    vipldws2_B.HoughTransform_o3[241] = -100.0F;
    vipldws2_B.HoughTransform_o3[242] = -99.0F;
    vipldws2_B.HoughTransform_o3[243] = -98.0F;
    vipldws2_B.HoughTransform_o3[244] = -97.0F;
    vipldws2_B.HoughTransform_o3[245] = -96.0F;
    vipldws2_B.HoughTransform_o3[246] = -95.0F;
    vipldws2_B.HoughTransform_o3[247] = -94.0F;
    vipldws2_B.HoughTransform_o3[248] = -93.0F;
    vipldws2_B.HoughTransform_o3[249] = -92.0F;
    vipldws2_B.HoughTransform_o3[250] = -91.0F;
    vipldws2_B.HoughTransform_o3[251] = -90.0F;
    vipldws2_B.HoughTransform_o3[252] = -89.0F;
    vipldws2_B.HoughTransform_o3[253] = -88.0F;
    vipldws2_B.HoughTransform_o3[254] = -87.0F;
    vipldws2_B.HoughTransform_o3[255] = -86.0F;
    vipldws2_B.HoughTransform_o3[256] = -85.0F;
    vipldws2_B.HoughTransform_o3[257] = -84.0F;
    vipldws2_B.HoughTransform_o3[258] = -83.0F;
    vipldws2_B.HoughTransform_o3[259] = -82.0F;
    vipldws2_B.HoughTransform_o3[260] = -81.0F;
    vipldws2_B.HoughTransform_o3[261] = -80.0F;
    vipldws2_B.HoughTransform_o3[262] = -79.0F;
    vipldws2_B.HoughTransform_o3[263] = -78.0F;
    vipldws2_B.HoughTransform_o3[264] = -77.0F;
    vipldws2_B.HoughTransform_o3[265] = -76.0F;
    vipldws2_B.HoughTransform_o3[266] = -75.0F;
    vipldws2_B.HoughTransform_o3[267] = -74.0F;
    vipldws2_B.HoughTransform_o3[268] = -73.0F;
    vipldws2_B.HoughTransform_o3[269] = -72.0F;
    vipldws2_B.HoughTransform_o3[270] = -71.0F;
    vipldws2_B.HoughTransform_o3[271] = -70.0F;
    vipldws2_B.HoughTransform_o3[272] = -69.0F;
    vipldws2_B.HoughTransform_o3[273] = -68.0F;
    vipldws2_B.HoughTransform_o3[274] = -67.0F;
    vipldws2_B.HoughTransform_o3[275] = -66.0F;
    vipldws2_B.HoughTransform_o3[276] = -65.0F;
    vipldws2_B.HoughTransform_o3[277] = -64.0F;
    vipldws2_B.HoughTransform_o3[278] = -63.0F;
    vipldws2_B.HoughTransform_o3[279] = -62.0F;
    vipldws2_B.HoughTransform_o3[280] = -61.0F;
    vipldws2_B.HoughTransform_o3[281] = -60.0F;
    vipldws2_B.HoughTransform_o3[282] = -59.0F;
    vipldws2_B.HoughTransform_o3[283] = -58.0F;
    vipldws2_B.HoughTransform_o3[284] = -57.0F;
    vipldws2_B.HoughTransform_o3[285] = -56.0F;
    vipldws2_B.HoughTransform_o3[286] = -55.0F;
    vipldws2_B.HoughTransform_o3[287] = -54.0F;
    vipldws2_B.HoughTransform_o3[288] = -53.0F;
    vipldws2_B.HoughTransform_o3[289] = -52.0F;
    vipldws2_B.HoughTransform_o3[290] = -51.0F;
    vipldws2_B.HoughTransform_o3[291] = -50.0F;
    vipldws2_B.HoughTransform_o3[292] = -49.0F;
    vipldws2_B.HoughTransform_o3[293] = -48.0F;
    vipldws2_B.HoughTransform_o3[294] = -47.0F;
    vipldws2_B.HoughTransform_o3[295] = -46.0F;
    vipldws2_B.HoughTransform_o3[296] = -45.0F;
    vipldws2_B.HoughTransform_o3[297] = -44.0F;
    vipldws2_B.HoughTransform_o3[298] = -43.0F;
    vipldws2_B.HoughTransform_o3[299] = -42.0F;
    vipldws2_B.HoughTransform_o3[300] = -41.0F;
    vipldws2_B.HoughTransform_o3[301] = -40.0F;
    vipldws2_B.HoughTransform_o3[302] = -39.0F;
    vipldws2_B.HoughTransform_o3[303] = -38.0F;
    vipldws2_B.HoughTransform_o3[304] = -37.0F;
    vipldws2_B.HoughTransform_o3[305] = -36.0F;
    vipldws2_B.HoughTransform_o3[306] = -35.0F;
    vipldws2_B.HoughTransform_o3[307] = -34.0F;
    vipldws2_B.HoughTransform_o3[308] = -33.0F;
    vipldws2_B.HoughTransform_o3[309] = -32.0F;
    vipldws2_B.HoughTransform_o3[310] = -31.0F;
    vipldws2_B.HoughTransform_o3[311] = -30.0F;
    vipldws2_B.HoughTransform_o3[312] = -29.0F;
    vipldws2_B.HoughTransform_o3[313] = -28.0F;
    vipldws2_B.HoughTransform_o3[314] = -27.0F;
    vipldws2_B.HoughTransform_o3[315] = -26.0F;
    vipldws2_B.HoughTransform_o3[316] = -25.0F;
    vipldws2_B.HoughTransform_o3[317] = -24.0F;
    vipldws2_B.HoughTransform_o3[318] = -23.0F;
    vipldws2_B.HoughTransform_o3[319] = -22.0F;
    vipldws2_B.HoughTransform_o3[320] = -21.0F;
    vipldws2_B.HoughTransform_o3[321] = -20.0F;
    vipldws2_B.HoughTransform_o3[322] = -19.0F;
    vipldws2_B.HoughTransform_o3[323] = -18.0F;
    vipldws2_B.HoughTransform_o3[324] = -17.0F;
    vipldws2_B.HoughTransform_o3[325] = -16.0F;
    vipldws2_B.HoughTransform_o3[326] = -15.0F;
    vipldws2_B.HoughTransform_o3[327] = -14.0F;
    vipldws2_B.HoughTransform_o3[328] = -13.0F;
    vipldws2_B.HoughTransform_o3[329] = -12.0F;
    vipldws2_B.HoughTransform_o3[330] = -11.0F;
    vipldws2_B.HoughTransform_o3[331] = -10.0F;
    vipldws2_B.HoughTransform_o3[332] = -9.0F;
    vipldws2_B.HoughTransform_o3[333] = -8.0F;
    vipldws2_B.HoughTransform_o3[334] = -7.0F;
    vipldws2_B.HoughTransform_o3[335] = -6.0F;
    vipldws2_B.HoughTransform_o3[336] = -5.0F;
    vipldws2_B.HoughTransform_o3[337] = -4.0F;
    vipldws2_B.HoughTransform_o3[338] = -3.0F;
    vipldws2_B.HoughTransform_o3[339] = -2.0F;
    vipldws2_B.HoughTransform_o3[340] = -1.0F;
    vipldws2_B.HoughTransform_o3[341] = 0.0F;
    vipldws2_B.HoughTransform_o3[342] = 1.0F;
    vipldws2_B.HoughTransform_o3[343] = 2.0F;
    vipldws2_B.HoughTransform_o3[344] = 3.0F;
    vipldws2_B.HoughTransform_o3[345] = 4.0F;
    vipldws2_B.HoughTransform_o3[346] = 5.0F;
    vipldws2_B.HoughTransform_o3[347] = 6.0F;
    vipldws2_B.HoughTransform_o3[348] = 7.0F;
    vipldws2_B.HoughTransform_o3[349] = 8.0F;
    vipldws2_B.HoughTransform_o3[350] = 9.0F;
    vipldws2_B.HoughTransform_o3[351] = 10.0F;
    vipldws2_B.HoughTransform_o3[352] = 11.0F;
    vipldws2_B.HoughTransform_o3[353] = 12.0F;
    vipldws2_B.HoughTransform_o3[354] = 13.0F;
    vipldws2_B.HoughTransform_o3[355] = 14.0F;
    vipldws2_B.HoughTransform_o3[356] = 15.0F;
    vipldws2_B.HoughTransform_o3[357] = 16.0F;
    vipldws2_B.HoughTransform_o3[358] = 17.0F;
    vipldws2_B.HoughTransform_o3[359] = 18.0F;
    vipldws2_B.HoughTransform_o3[360] = 19.0F;
    vipldws2_B.HoughTransform_o3[361] = 20.0F;
    vipldws2_B.HoughTransform_o3[362] = 21.0F;
    vipldws2_B.HoughTransform_o3[363] = 22.0F;
    vipldws2_B.HoughTransform_o3[364] = 23.0F;
    vipldws2_B.HoughTransform_o3[365] = 24.0F;
    vipldws2_B.HoughTransform_o3[366] = 25.0F;
    vipldws2_B.HoughTransform_o3[367] = 26.0F;
    vipldws2_B.HoughTransform_o3[368] = 27.0F;
    vipldws2_B.HoughTransform_o3[369] = 28.0F;
    vipldws2_B.HoughTransform_o3[370] = 29.0F;
    vipldws2_B.HoughTransform_o3[371] = 30.0F;
    vipldws2_B.HoughTransform_o3[372] = 31.0F;
    vipldws2_B.HoughTransform_o3[373] = 32.0F;
    vipldws2_B.HoughTransform_o3[374] = 33.0F;
    vipldws2_B.HoughTransform_o3[375] = 34.0F;
    vipldws2_B.HoughTransform_o3[376] = 35.0F;
    vipldws2_B.HoughTransform_o3[377] = 36.0F;
    vipldws2_B.HoughTransform_o3[378] = 37.0F;
    vipldws2_B.HoughTransform_o3[379] = 38.0F;
    vipldws2_B.HoughTransform_o3[380] = 39.0F;
    vipldws2_B.HoughTransform_o3[381] = 40.0F;
    vipldws2_B.HoughTransform_o3[382] = 41.0F;
    vipldws2_B.HoughTransform_o3[383] = 42.0F;
    vipldws2_B.HoughTransform_o3[384] = 43.0F;
    vipldws2_B.HoughTransform_o3[385] = 44.0F;
    vipldws2_B.HoughTransform_o3[386] = 45.0F;
    vipldws2_B.HoughTransform_o3[387] = 46.0F;
    vipldws2_B.HoughTransform_o3[388] = 47.0F;
    vipldws2_B.HoughTransform_o3[389] = 48.0F;
    vipldws2_B.HoughTransform_o3[390] = 49.0F;
    vipldws2_B.HoughTransform_o3[391] = 50.0F;
    vipldws2_B.HoughTransform_o3[392] = 51.0F;
    vipldws2_B.HoughTransform_o3[393] = 52.0F;
    vipldws2_B.HoughTransform_o3[394] = 53.0F;
    vipldws2_B.HoughTransform_o3[395] = 54.0F;
    vipldws2_B.HoughTransform_o3[396] = 55.0F;
    vipldws2_B.HoughTransform_o3[397] = 56.0F;
    vipldws2_B.HoughTransform_o3[398] = 57.0F;
    vipldws2_B.HoughTransform_o3[399] = 58.0F;
    vipldws2_B.HoughTransform_o3[400] = 59.0F;
    vipldws2_B.HoughTransform_o3[401] = 60.0F;
    vipldws2_B.HoughTransform_o3[402] = 61.0F;
    vipldws2_B.HoughTransform_o3[403] = 62.0F;
    vipldws2_B.HoughTransform_o3[404] = 63.0F;
    vipldws2_B.HoughTransform_o3[405] = 64.0F;
    vipldws2_B.HoughTransform_o3[406] = 65.0F;
    vipldws2_B.HoughTransform_o3[407] = 66.0F;
    vipldws2_B.HoughTransform_o3[408] = 67.0F;
    vipldws2_B.HoughTransform_o3[409] = 68.0F;
    vipldws2_B.HoughTransform_o3[410] = 69.0F;
    vipldws2_B.HoughTransform_o3[411] = 70.0F;
    vipldws2_B.HoughTransform_o3[412] = 71.0F;
    vipldws2_B.HoughTransform_o3[413] = 72.0F;
    vipldws2_B.HoughTransform_o3[414] = 73.0F;
    vipldws2_B.HoughTransform_o3[415] = 74.0F;
    vipldws2_B.HoughTransform_o3[416] = 75.0F;
    vipldws2_B.HoughTransform_o3[417] = 76.0F;
    vipldws2_B.HoughTransform_o3[418] = 77.0F;
    vipldws2_B.HoughTransform_o3[419] = 78.0F;
    vipldws2_B.HoughTransform_o3[420] = 79.0F;
    vipldws2_B.HoughTransform_o3[421] = 80.0F;
    vipldws2_B.HoughTransform_o3[422] = 81.0F;
    vipldws2_B.HoughTransform_o3[423] = 82.0F;
    vipldws2_B.HoughTransform_o3[424] = 83.0F;
    vipldws2_B.HoughTransform_o3[425] = 84.0F;
    vipldws2_B.HoughTransform_o3[426] = 85.0F;
    vipldws2_B.HoughTransform_o3[427] = 86.0F;
    vipldws2_B.HoughTransform_o3[428] = 87.0F;
    vipldws2_B.HoughTransform_o3[429] = 88.0F;
    vipldws2_B.HoughTransform_o3[430] = 89.0F;
    vipldws2_B.HoughTransform_o3[431] = 90.0F;
    vipldws2_B.HoughTransform_o3[432] = 91.0F;
    vipldws2_B.HoughTransform_o3[433] = 92.0F;
    vipldws2_B.HoughTransform_o3[434] = 93.0F;
    vipldws2_B.HoughTransform_o3[435] = 94.0F;
    vipldws2_B.HoughTransform_o3[436] = 95.0F;
    vipldws2_B.HoughTransform_o3[437] = 96.0F;
    vipldws2_B.HoughTransform_o3[438] = 97.0F;
    vipldws2_B.HoughTransform_o3[439] = 98.0F;
    vipldws2_B.HoughTransform_o3[440] = 99.0F;
    vipldws2_B.HoughTransform_o3[441] = 100.0F;
    vipldws2_B.HoughTransform_o3[442] = 101.0F;
    vipldws2_B.HoughTransform_o3[443] = 102.0F;
    vipldws2_B.HoughTransform_o3[444] = 103.0F;
    vipldws2_B.HoughTransform_o3[445] = 104.0F;
    vipldws2_B.HoughTransform_o3[446] = 105.0F;
    vipldws2_B.HoughTransform_o3[447] = 106.0F;
    vipldws2_B.HoughTransform_o3[448] = 107.0F;
    vipldws2_B.HoughTransform_o3[449] = 108.0F;
    vipldws2_B.HoughTransform_o3[450] = 109.0F;
    vipldws2_B.HoughTransform_o3[451] = 110.0F;
    vipldws2_B.HoughTransform_o3[452] = 111.0F;
    vipldws2_B.HoughTransform_o3[453] = 112.0F;
    vipldws2_B.HoughTransform_o3[454] = 113.0F;
    vipldws2_B.HoughTransform_o3[455] = 114.0F;
    vipldws2_B.HoughTransform_o3[456] = 115.0F;
    vipldws2_B.HoughTransform_o3[457] = 116.0F;
    vipldws2_B.HoughTransform_o3[458] = 117.0F;
    vipldws2_B.HoughTransform_o3[459] = 118.0F;
    vipldws2_B.HoughTransform_o3[460] = 119.0F;
    vipldws2_B.HoughTransform_o3[461] = 120.0F;
    vipldws2_B.HoughTransform_o3[462] = 121.0F;
    vipldws2_B.HoughTransform_o3[463] = 122.0F;
    vipldws2_B.HoughTransform_o3[464] = 123.0F;
    vipldws2_B.HoughTransform_o3[465] = 124.0F;
    vipldws2_B.HoughTransform_o3[466] = 125.0F;
    vipldws2_B.HoughTransform_o3[467] = 126.0F;
    vipldws2_B.HoughTransform_o3[468] = 127.0F;
    vipldws2_B.HoughTransform_o3[469] = 128.0F;
    vipldws2_B.HoughTransform_o3[470] = 129.0F;
    vipldws2_B.HoughTransform_o3[471] = 130.0F;
    vipldws2_B.HoughTransform_o3[472] = 131.0F;
    vipldws2_B.HoughTransform_o3[473] = 132.0F;
    vipldws2_B.HoughTransform_o3[474] = 133.0F;
    vipldws2_B.HoughTransform_o3[475] = 134.0F;
    vipldws2_B.HoughTransform_o3[476] = 135.0F;
    vipldws2_B.HoughTransform_o3[477] = 136.0F;
    vipldws2_B.HoughTransform_o3[478] = 137.0F;
    vipldws2_B.HoughTransform_o3[479] = 138.0F;
    vipldws2_B.HoughTransform_o3[480] = 139.0F;
    vipldws2_B.HoughTransform_o3[481] = 140.0F;
    vipldws2_B.HoughTransform_o3[482] = 141.0F;
    vipldws2_B.HoughTransform_o3[483] = 142.0F;
    vipldws2_B.HoughTransform_o3[484] = 143.0F;
    vipldws2_B.HoughTransform_o3[485] = 144.0F;
    vipldws2_B.HoughTransform_o3[486] = 145.0F;
    vipldws2_B.HoughTransform_o3[487] = 146.0F;
    vipldws2_B.HoughTransform_o3[488] = 147.0F;
    vipldws2_B.HoughTransform_o3[489] = 148.0F;
    vipldws2_B.HoughTransform_o3[490] = 149.0F;
    vipldws2_B.HoughTransform_o3[491] = 150.0F;
    vipldws2_B.HoughTransform_o3[492] = 151.0F;
    vipldws2_B.HoughTransform_o3[493] = 152.0F;
    vipldws2_B.HoughTransform_o3[494] = 153.0F;
    vipldws2_B.HoughTransform_o3[495] = 154.0F;
    vipldws2_B.HoughTransform_o3[496] = 155.0F;
    vipldws2_B.HoughTransform_o3[497] = 156.0F;
    vipldws2_B.HoughTransform_o3[498] = 157.0F;
    vipldws2_B.HoughTransform_o3[499] = 158.0F;
    vipldws2_B.HoughTransform_o3[500] = 159.0F;
    vipldws2_B.HoughTransform_o3[501] = 160.0F;
    vipldws2_B.HoughTransform_o3[502] = 161.0F;
    vipldws2_B.HoughTransform_o3[503] = 162.0F;
    vipldws2_B.HoughTransform_o3[504] = 163.0F;
    vipldws2_B.HoughTransform_o3[505] = 164.0F;
    vipldws2_B.HoughTransform_o3[506] = 165.0F;
    vipldws2_B.HoughTransform_o3[507] = 166.0F;
    vipldws2_B.HoughTransform_o3[508] = 167.0F;
    vipldws2_B.HoughTransform_o3[509] = 168.0F;
    vipldws2_B.HoughTransform_o3[510] = 169.0F;
    vipldws2_B.HoughTransform_o3[511] = 170.0F;
    vipldws2_B.HoughTransform_o3[512] = 171.0F;
    vipldws2_B.HoughTransform_o3[513] = 172.0F;
    vipldws2_B.HoughTransform_o3[514] = 173.0F;
    vipldws2_B.HoughTransform_o3[515] = 174.0F;
    vipldws2_B.HoughTransform_o3[516] = 175.0F;
    vipldws2_B.HoughTransform_o3[517] = 176.0F;
    vipldws2_B.HoughTransform_o3[518] = 177.0F;
    vipldws2_B.HoughTransform_o3[519] = 178.0F;
    vipldws2_B.HoughTransform_o3[520] = 179.0F;
    vipldws2_B.HoughTransform_o3[521] = 180.0F;
    vipldws2_B.HoughTransform_o3[522] = 181.0F;
    vipldws2_B.HoughTransform_o3[523] = 182.0F;
    vipldws2_B.HoughTransform_o3[524] = 183.0F;
    vipldws2_B.HoughTransform_o3[525] = 184.0F;
    vipldws2_B.HoughTransform_o3[526] = 185.0F;
    vipldws2_B.HoughTransform_o3[527] = 186.0F;
    vipldws2_B.HoughTransform_o3[528] = 187.0F;
    vipldws2_B.HoughTransform_o3[529] = 188.0F;
    vipldws2_B.HoughTransform_o3[530] = 189.0F;
    vipldws2_B.HoughTransform_o3[531] = 190.0F;
    vipldws2_B.HoughTransform_o3[532] = 191.0F;
    vipldws2_B.HoughTransform_o3[533] = 192.0F;
    vipldws2_B.HoughTransform_o3[534] = 193.0F;
    vipldws2_B.HoughTransform_o3[535] = 194.0F;
    vipldws2_B.HoughTransform_o3[536] = 195.0F;
    vipldws2_B.HoughTransform_o3[537] = 196.0F;
    vipldws2_B.HoughTransform_o3[538] = 197.0F;
    vipldws2_B.HoughTransform_o3[539] = 198.0F;
    vipldws2_B.HoughTransform_o3[540] = 199.0F;
    vipldws2_B.HoughTransform_o3[541] = 200.0F;
    vipldws2_B.HoughTransform_o3[542] = 201.0F;
    vipldws2_B.HoughTransform_o3[543] = 202.0F;
    vipldws2_B.HoughTransform_o3[544] = 203.0F;
    vipldws2_B.HoughTransform_o3[545] = 204.0F;
    vipldws2_B.HoughTransform_o3[546] = 205.0F;
    vipldws2_B.HoughTransform_o3[547] = 206.0F;
    vipldws2_B.HoughTransform_o3[548] = 207.0F;
    vipldws2_B.HoughTransform_o3[549] = 208.0F;
    vipldws2_B.HoughTransform_o3[550] = 209.0F;
    vipldws2_B.HoughTransform_o3[551] = 210.0F;
    vipldws2_B.HoughTransform_o3[552] = 211.0F;
    vipldws2_B.HoughTransform_o3[553] = 212.0F;
    vipldws2_B.HoughTransform_o3[554] = 213.0F;
    vipldws2_B.HoughTransform_o3[555] = 214.0F;
    vipldws2_B.HoughTransform_o3[556] = 215.0F;
    vipldws2_B.HoughTransform_o3[557] = 216.0F;
    vipldws2_B.HoughTransform_o3[558] = 217.0F;
    vipldws2_B.HoughTransform_o3[559] = 218.0F;
    vipldws2_B.HoughTransform_o3[560] = 219.0F;
    vipldws2_B.HoughTransform_o3[561] = 220.0F;
    vipldws2_B.HoughTransform_o3[562] = 221.0F;
    vipldws2_B.HoughTransform_o3[563] = 222.0F;
    vipldws2_B.HoughTransform_o3[564] = 223.0F;
    vipldws2_B.HoughTransform_o3[565] = 224.0F;
    vipldws2_B.HoughTransform_o3[566] = 225.0F;
    vipldws2_B.HoughTransform_o3[567] = 226.0F;
    vipldws2_B.HoughTransform_o3[568] = 227.0F;
    vipldws2_B.HoughTransform_o3[569] = 228.0F;
    vipldws2_B.HoughTransform_o3[570] = 229.0F;
    vipldws2_B.HoughTransform_o3[571] = 230.0F;
    vipldws2_B.HoughTransform_o3[572] = 231.0F;
    vipldws2_B.HoughTransform_o3[573] = 232.0F;
    vipldws2_B.HoughTransform_o3[574] = 233.0F;
    vipldws2_B.HoughTransform_o3[575] = 234.0F;
    vipldws2_B.HoughTransform_o3[576] = 235.0F;
    vipldws2_B.HoughTransform_o3[577] = 236.0F;
    vipldws2_B.HoughTransform_o3[578] = 237.0F;
    vipldws2_B.HoughTransform_o3[579] = 238.0F;
    vipldws2_B.HoughTransform_o3[580] = 239.0F;
    vipldws2_B.HoughTransform_o3[581] = 240.0F;
    vipldws2_B.HoughTransform_o3[582] = 241.0F;
    vipldws2_B.HoughTransform_o3[583] = 242.0F;
    vipldws2_B.HoughTransform_o3[584] = 243.0F;
    vipldws2_B.HoughTransform_o3[585] = 244.0F;
    vipldws2_B.HoughTransform_o3[586] = 245.0F;
    vipldws2_B.HoughTransform_o3[587] = 246.0F;
    vipldws2_B.HoughTransform_o3[588] = 247.0F;
    vipldws2_B.HoughTransform_o3[589] = 248.0F;
    vipldws2_B.HoughTransform_o3[590] = 249.0F;
    vipldws2_B.HoughTransform_o3[591] = 250.0F;
    vipldws2_B.HoughTransform_o3[592] = 251.0F;
    vipldws2_B.HoughTransform_o3[593] = 252.0F;
    vipldws2_B.HoughTransform_o3[594] = 253.0F;
    vipldws2_B.HoughTransform_o3[595] = 254.0F;
    vipldws2_B.HoughTransform_o3[596] = 255.0F;
    vipldws2_B.HoughTransform_o3[597] = 256.0F;
    vipldws2_B.HoughTransform_o3[598] = 257.0F;
    vipldws2_B.HoughTransform_o3[599] = 258.0F;
    vipldws2_B.HoughTransform_o3[600] = 259.0F;
    vipldws2_B.HoughTransform_o3[601] = 260.0F;
    vipldws2_B.HoughTransform_o3[602] = 261.0F;
    vipldws2_B.HoughTransform_o3[603] = 262.0F;
    vipldws2_B.HoughTransform_o3[604] = 263.0F;
    vipldws2_B.HoughTransform_o3[605] = 264.0F;
    vipldws2_B.HoughTransform_o3[606] = 265.0F;
    vipldws2_B.HoughTransform_o3[607] = 266.0F;
    vipldws2_B.HoughTransform_o3[608] = 267.0F;
    vipldws2_B.HoughTransform_o3[609] = 268.0F;
    vipldws2_B.HoughTransform_o3[610] = 269.0F;
    vipldws2_B.HoughTransform_o3[611] = 270.0F;
    vipldws2_B.HoughTransform_o3[612] = 271.0F;
    vipldws2_B.HoughTransform_o3[613] = 272.0F;
    vipldws2_B.HoughTransform_o3[614] = 273.0F;
    vipldws2_B.HoughTransform_o3[615] = 274.0F;
    vipldws2_B.HoughTransform_o3[616] = 275.0F;
    vipldws2_B.HoughTransform_o3[617] = 276.0F;
    vipldws2_B.HoughTransform_o3[618] = 277.0F;
    vipldws2_B.HoughTransform_o3[619] = 278.0F;
    vipldws2_B.HoughTransform_o3[620] = 279.0F;
    vipldws2_B.HoughTransform_o3[621] = 280.0F;
    vipldws2_B.HoughTransform_o3[622] = 281.0F;
    vipldws2_B.HoughTransform_o3[623] = 282.0F;
    vipldws2_B.HoughTransform_o3[624] = 283.0F;
    vipldws2_B.HoughTransform_o3[625] = 284.0F;
    vipldws2_B.HoughTransform_o3[626] = 285.0F;
    vipldws2_B.HoughTransform_o3[627] = 286.0F;
    vipldws2_B.HoughTransform_o3[628] = 287.0F;
    vipldws2_B.HoughTransform_o3[629] = 288.0F;
    vipldws2_B.HoughTransform_o3[630] = 289.0F;
    vipldws2_B.HoughTransform_o3[631] = 290.0F;
    vipldws2_B.HoughTransform_o3[632] = 291.0F;
    vipldws2_B.HoughTransform_o3[633] = 292.0F;
    vipldws2_B.HoughTransform_o3[634] = 293.0F;
    vipldws2_B.HoughTransform_o3[635] = 294.0F;
    vipldws2_B.HoughTransform_o3[636] = 295.0F;
    vipldws2_B.HoughTransform_o3[637] = 296.0F;
    vipldws2_B.HoughTransform_o3[638] = 297.0F;
    vipldws2_B.HoughTransform_o3[639] = 298.0F;
    vipldws2_B.HoughTransform_o3[640] = 299.0F;
    vipldws2_B.HoughTransform_o3[641] = 300.0F;
    vipldws2_B.HoughTransform_o3[642] = 301.0F;
    vipldws2_B.HoughTransform_o3[643] = 302.0F;
    vipldws2_B.HoughTransform_o3[644] = 303.0F;
    vipldws2_B.HoughTransform_o3[645] = 304.0F;
    vipldws2_B.HoughTransform_o3[646] = 305.0F;
    vipldws2_B.HoughTransform_o3[647] = 306.0F;
    vipldws2_B.HoughTransform_o3[648] = 307.0F;
    vipldws2_B.HoughTransform_o3[649] = 308.0F;
    vipldws2_B.HoughTransform_o3[650] = 309.0F;
    vipldws2_B.HoughTransform_o3[651] = 310.0F;
    vipldws2_B.HoughTransform_o3[652] = 311.0F;
    vipldws2_B.HoughTransform_o3[653] = 312.0F;
    vipldws2_B.HoughTransform_o3[654] = 313.0F;
    vipldws2_B.HoughTransform_o3[655] = 314.0F;
    vipldws2_B.HoughTransform_o3[656] = 315.0F;
    vipldws2_B.HoughTransform_o3[657] = 316.0F;
    vipldws2_B.HoughTransform_o3[658] = 317.0F;
    vipldws2_B.HoughTransform_o3[659] = 318.0F;
    vipldws2_B.HoughTransform_o3[660] = 319.0F;
    vipldws2_B.HoughTransform_o3[661] = 320.0F;
    vipldws2_B.HoughTransform_o3[662] = 321.0F;
    vipldws2_B.HoughTransform_o3[663] = 322.0F;
    vipldws2_B.HoughTransform_o3[664] = 323.0F;
    vipldws2_B.HoughTransform_o3[665] = 324.0F;
    vipldws2_B.HoughTransform_o3[666] = 325.0F;
    vipldws2_B.HoughTransform_o3[667] = 326.0F;
    vipldws2_B.HoughTransform_o3[668] = 327.0F;
    vipldws2_B.HoughTransform_o3[669] = 328.0F;
    vipldws2_B.HoughTransform_o3[670] = 329.0F;
    vipldws2_B.HoughTransform_o3[671] = 330.0F;
    vipldws2_B.HoughTransform_o3[672] = 331.0F;
    vipldws2_B.HoughTransform_o3[673] = 332.0F;
    vipldws2_B.HoughTransform_o3[674] = 333.0F;
    vipldws2_B.HoughTransform_o3[675] = 334.0F;
    vipldws2_B.HoughTransform_o3[676] = 335.0F;
    vipldws2_B.HoughTransform_o3[677] = 336.0F;
    vipldws2_B.HoughTransform_o3[678] = 337.0F;
    vipldws2_B.HoughTransform_o3[679] = 338.0F;
    vipldws2_B.HoughTransform_o3[680] = 339.0F;
    vipldws2_B.HoughTransform_o3[681] = 340.0F;
    vipldws2_B.HoughTransform_o3[682] = 341.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&vipldws2_DW, 0,
                sizeof(DW_vipldws2_T));
  vipldws2_DW.FrameRateDisplay_PrevTime = 0.0;
  vipldws2_DW.FrameRateDisplay_TotalTime = 0.0;
  vipldws2_DW.FrameRateDisplay_Count = 0.0;

  {
    int32_T i;
    for (i = 0; i < 40; i++) {
      vipldws2_DW.FixPtUnitDelay1_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 80; i++) {
      vipldws2_DW.UnitDelay2_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 320; i++) {
      vipldws2_DW.UnitDelay3_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 230400; i++) {
      vipldws2_DW.ColorSpaceConversion_DWORK1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 256; i++) {
      vipldws2_DW.Imagethresholding_P_DW[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 256; i++) {
      vipldws2_DW.Imagethresholding_MU_DW[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 231; i++) {
      vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWORKS[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 122940; i++) {
      vipldws2_DW.FindLocalMaxima_TEMP_IN_DWORKS[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 756; i++) {
      vipldws2_DW.FindLocalMaxima1_TEMP_IN_DWOR_e[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 115200; i++) {
      vipldws2_DW.ColorSpaceConversion1_DWORK1[i] = 0.0F;
    }
  }

  vipldws2_DW.InsertText_colorVectorDW[0] = 0.0F;
  vipldws2_DW.InsertText_colorVectorDW[1] = 0.0F;
  vipldws2_DW.InsertText_colorVectorDW[2] = 0.0F;
  vipldws2_DW.InsertTextLeftLane_colorVectorD[0] = 0.0F;
  vipldws2_DW.InsertTextLeftLane_colorVectorD[1] = 0.0F;
  vipldws2_DW.InsertTextLeftLane_colorVectorD[2] = 0.0F;
  vipldws2_DW.InsertTextRightLane_colorVector[0] = 0.0F;
  vipldws2_DW.InsertTextRightLane_colorVector[1] = 0.0F;
  vipldws2_DW.InsertTextRightLane_colorVector[2] = 0.0F;
  vipldws2_DW.DrawShapes_DW_FillColorAdd[0] = 0.0F;
  vipldws2_DW.DrawShapes_DW_FillColorAdd[1] = 0.0F;
  vipldws2_DW.DrawShapes_DW_FillColorAdd[2] = 0.0F;
  vipldws2_DW.DrawShapes_DW_OneMOpacity = 0.0F;
  vipldws2_DW.Add1_DWORK1 = 0.0F;
  vipldws2_DW.LDLFactorization_VMX[0] = 0.0F;
  vipldws2_DW.LDLFactorization_VMX[1] = 0.0F;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    vipldws2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
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
    MW_videoCaptureInit(vipldws2_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U,
                        240U, 2U, 2U, 1U, 0.033333333333333333);

    /* Start for Probe: '<S1>/Width of the image' */
    vipldws2_B.Widthoftheimage[0] = 120;
    vipldws2_B.Widthoftheimage[1] = 320;

    /* Start for Enabled SubSystem: '<S5>/Subsystem' */
    /* Start for Enabled SubSystem: '<S67>/Draw  Polygon' */
    /* Start for S-Function (svipdrawshapes): '<S68>/DrawShapes' */
    /* Calculate FillColor times Opacity. */
    vipldws2_DW.DrawShapes_DW_FillColorAdd[0] =
      vipldws2_P.DrawShapes_RTP_FILLCOLOR_o[0] *
      vipldws2_P.DrawShapes_RTP_OPACITY;
    vipldws2_DW.DrawShapes_DW_FillColorAdd[1] =
      vipldws2_P.DrawShapes_RTP_FILLCOLOR_o[1] *
      vipldws2_P.DrawShapes_RTP_OPACITY;
    vipldws2_DW.DrawShapes_DW_FillColorAdd[2] =
      vipldws2_P.DrawShapes_RTP_FILLCOLOR_o[2] *
      vipldws2_P.DrawShapes_RTP_OPACITY;

    /* Calculate One minus Opacity. */
    vipldws2_DW.DrawShapes_DW_OneMOpacity = 1.0F -
      vipldws2_P.DrawShapes_RTP_OPACITY;

    /* End of Start for SubSystem: '<S67>/Draw  Polygon' */

    /* Start for FromWorkspace: '<S70>/From Workspace' */
    {
      static real32_T pDataValues0[] = { 1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

      vipldws2_DW.FromWorkspace_PWORK.TimePtr = (void *) 0;
      vipldws2_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
      vipldws2_DW.FromWorkspace_IWORK.PrevIndex = -1;
    }

    /* Start for S-Function (sviptextrender): '<S67>/Insert Text' */
    memcpy(&vipldws2_DW.InsertText_StringDataDW[0],
           &vipldws2_ConstP.InsertText_StrArray[0], 74U * sizeof(uint8_T));
    for (i = 0; i < 53; i++) {
      /* Start for S-Function (sviptextrender): '<S69>/Insert Text: Left Lane' */
      vipldws2_DW.InsertTextLeftLane_StringDataDW[i] =
        vipldws2_ConstP.pooled15[i];

      /* Start for S-Function (sviptextrender): '<S69>/Insert Text: Right Lane' */
      vipldws2_DW.InsertTextRightLane_StringDataD[i] =
        vipldws2_ConstP.pooled15[i];
    }

    /* End of Start for SubSystem: '<S5>/Subsystem' */
    vipldws2_PrevZCX.SampleandHold_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S39>/FixPt Unit Delay2' */
    vipldws2_DW.FixPtUnitDelay2_DSTATE =
      vipldws2_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S39>/FixPt Unit Delay1' */
    memcpy(&vipldws2_DW.FixPtUnitDelay1_DSTATE[0],
           &vipldws2_P.UnitDelayResettable1_vinit[0], 40U * sizeof(real32_T));

    /* InitializeConditions for UnitDelay: '<S38>/FixPt Unit Delay2' */
    vipldws2_DW.FixPtUnitDelay2_DSTATE_b =
      vipldws2_P.FixPtUnitDelay2_InitialCondit_p;
    for (i = 0; i < 20; i++) {
      /* InitializeConditions for UnitDelay: '<S38>/FixPt Unit Delay1' */
      vipldws2_DW.FixPtUnitDelay1_DSTATE_d[i] =
        vipldws2_P.UnitDelayResettable_vinit;

      /* InitializeConditions for UnitDelay: '<S35>/En_Delay' */
      vipldws2_DW.En_Delay_DSTATE[i] = vipldws2_P.En_Delay_InitialCondition;
    }

    /* InitializeConditions for UnitDelay: '<S35>/Unit Delay2' */
    memcpy(&vipldws2_DW.UnitDelay2_DSTATE[0],
           &vipldws2_P.UnitDelay2_InitialCondition[0], 80U * sizeof(real32_T));

    /* InitializeConditions for UnitDelay: '<S35>/Unit Delay3' */
    memcpy(&vipldws2_DW.UnitDelay3_DSTATE[0],
           &vipldws2_P.UnitDelay3_InitialCondition[0], 320U * sizeof(real32_T));

    /* InitializeConditions for Delay: '<S17>/Delay' */
    vipldws2_DW.Delay_DSTATE = vipldws2_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S17>/Delay1' */
    vipldws2_DW.Delay1_DSTATE_e = vipldws2_P.Delay1_InitialCondition_p;

    /* InitializeConditions for S-Function (sdspcount2): '<S17>/Counter' */
    vipldws2_DW.Counter_Count = vipldws2_P.Counter_InitialCount;

    /* InitializeConditions for S-Function (sdspnsamp2): '<S5>/N-Sample Enable' incorporates:
     *  Constant: '<S2>/Constant'
     */

    /* DSP System Toolbox N-Sample Enable  (sdspnsamp2) - '<S5>/N-Sample Enable' */
    vipldws2_DW.NSampleEnable_Counter = (uint32_T) 0;

    /* SystemInitialize for Iterator SubSystem: '<S36>/Find the best  matches between the current  lines and those in the repository' */
    /* InitializeConditions for Delay: '<S54>/Delay1' */
    for (i = 0; i < 400; i++) {
      vipldws2_DW.Delay1_DSTATE[i] = vipldws2_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S54>/Delay1' */
    /* End of SystemInitialize for SubSystem: '<S36>/Find the best  matches between the current  lines and those in the repository' */

    /* SystemInitialize for Iterator SubSystem: '<S36>/Update the repository' */
    /* InitializeConditions for Delay: '<S55>/Delay1' */
    for (i = 0; i < 20; i++) {
      vipldws2_DW.Delay1_DSTATE_g[i] = vipldws2_P.Delay1_InitialCondition_n;
    }

    /* End of InitializeConditions for Delay: '<S55>/Delay1' */
    /* End of SystemInitialize for SubSystem: '<S36>/Update the repository' */

    /* SystemInitialize for Iterator SubSystem: '<S1>/Find the left and  right lanes from the depository' */
    /* InitializeConditions for UnitDelay: '<S24>/Min_left_dis' */
    vipldws2_DW.Min_left_dis_DSTATE = vipldws2_P.Min_left_dis_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_dis' */
    vipldws2_DW.Min_right_dis_DSTATE = vipldws2_P.Min_right_dis_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[0] =
      vipldws2_P.Min_left_pts_InitialCondition[0];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[0] =
      vipldws2_P.Min_right_pts_InitialCondition[0];

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[1] =
      vipldws2_P.Min_left_pts_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[1] =
      vipldws2_P.Min_right_pts_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[2] =
      vipldws2_P.Min_left_pts_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[2] =
      vipldws2_P.Min_right_pts_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<S24>/Min_left_pts' */
    vipldws2_DW.Min_left_pts_DSTATE[3] =
      vipldws2_P.Min_left_pts_InitialCondition[3];

    /* InitializeConditions for UnitDelay: '<S24>/Min_right_pts' */
    vipldws2_DW.Min_right_pts_DSTATE[3] =
      vipldws2_P.Min_right_pts_InitialCondition[3];

    /* End of SystemInitialize for SubSystem: '<S1>/Find the left and  right lanes from the depository' */

    /* SystemInitialize for Triggered SubSystem: '<S6>/Sample and Hold' */
    /* SystemInitialize for Outport: '<S15>/ ' */
    vipldws2_B.In = vipldws2_P._Y0;

    /* End of SystemInitialize for SubSystem: '<S6>/Sample and Hold' */
  }
}

/* Model terminate function */
void vipldws2_terminate(void)
{
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<S2>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(vipldws2_ConstP.V4L2VideoCapture_p1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
