/*
 * File: rt_i32zcfcn.h
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

#ifndef RTW_HEADER_rt_i32zcfcn_h_
#define RTW_HEADER_rt_i32zcfcn_h_
#include "rtwtypes.h"
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

extern ZCEventType rt_I32ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, int32_T
  currValue);

#endif                                 /* RTW_HEADER_rt_i32zcfcn_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
