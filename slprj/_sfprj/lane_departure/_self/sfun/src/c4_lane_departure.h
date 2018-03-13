#ifndef __c4_lane_departure_h__
#define __c4_lane_departure_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_lane_departureInstanceStruct
#define typedef_SFc4_lane_departureInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c4_dataWrittenToVector[1];
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_fEmlrtCtx;
  int32_T *c4_sfEvent;
  uint8_T *c4_is_active_c4_lane_departure;
  uint8_T *c4_is_c4_lane_departure;
  real_T *c4_numberLane;
} SFc4_lane_departureInstanceStruct;

#endif                                 /*typedef_SFc4_lane_departureInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_lane_departure_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_lane_departure_get_check_sum(mxArray *plhs[]);
extern void c4_lane_departure_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
