#include "__cf_Region_of_Interest.h"
#ifndef RTW_HEADER_Region_of_Interest_h_
#define RTW_HEADER_Region_of_Interest_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef Region_of_Interest_COMMON_INCLUDES_
#define Region_of_Interest_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "Region_of_Interest_types.h"
#include "multiword_types.h"
#include "rt_nonfinite.h"
struct fvh4b3gton { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; } ; typedef struct { havv0zhfkq rtm ; } ddfq4cerlym ; extern
void oodkrbf2of ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , havv0zhfkq *
const e5tz0canl4 , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_Region_of_Interest_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray *
mr_Region_of_Interest_GetDWork ( const ddfq4cerlym * mdlrefDW ) ; extern void
mr_Region_of_Interest_SetDWork ( ddfq4cerlym * mdlrefDW , const mxArray *
ssDW ) ; extern void mr_Region_of_Interest_RegisterSimStateChecksum (
SimStruct * S ) ; extern mxArray *
mr_Region_of_Interest_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Region_of_Interest_GetCAPIStaticMap ( void )
; extern void Region_of_Interest ( const uint8_T c3rzf0cfx4 [ 76800 ] , const
real_T lz0zmltrhm [ 261 ] , const real_T nlup1hx5nn [ 61 ] , uint8_T
l315esvsqa [ 15921 ] ) ;
#endif
