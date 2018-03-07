#include "__cf_LaneDetection.h"
#ifndef RTW_HEADER_LaneDetection_h_
#define RTW_HEADER_LaneDetection_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef LaneDetection_COMMON_INCLUDES_
#define LaneDetection_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "math.h"
#include "viphough_rt.h"
#endif
#include "LaneDetection_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
typedef struct { real_T b3lj1ro54e [ 96300 ] ; real_T pzo3lxik1r [ 180 ] ;
real_T mesknpbk5t [ 535 ] ; real_T gosar0sgre [ 10 ] ; real_T ldho0fd2nl [ 5
] ; real_T dkhie0ooet [ 5 ] ; real_T lysrq3xxtz [ 5 ] ; real_T n2vgaroq1m [ 5
] ; int32_T k5x5wcew54 [ 5 ] ; int32_T dkw5vs0mpk [ 5 ] ; int32_T gehxtlz2bv
[ 5 ] ; int32_T br2yymckcz [ 5 ] ; int32_T cqytuh4sir [ 4 ] ; real_T
grmieipfa4 ; real_T bidf1d0hab ; real_T ivcr4kb2di ; int32_T mjqwh0sluc [ 2 ]
; int32_T mjnb4ff24c ; int32_T oqjwwtnwwt ; int32_T eievh13zkr ; int32_T
dsu3yzczbs ; int32_T iu2lveaurm ; int32_T erpgnv3z3v ; int32_T pdv5xeozmc ;
int32_T i4qkuytuty ; int32_T cszf0mmuw5 ; int32_T f3exltnl3f ; int32_T
k3ccqdz51e ; int32_T bpvfku0axv ; int32_T gdldy4anca ; int32_T aplsq01g4t ;
int32_T f1sw2ht4n2 ; int32_T autjwaia4y ; int32_T dw40j5sber ; uint32_T
hrm1rndox2 ; uint32_T caihcvukc4 ; } oilz1v0r1v ; typedef struct { real_T
dsg35qf31k [ 96300 ] ; int32_T ephazqj5mq [ 15921 ] ; int32_T cc40xb1fei [
15921 ] ; int32_T cdu44n1mcq [ 15921 ] ; int32_T gv5pvc5nnd [ 180 ] ; int32_T
iocj4jvjgy [ 40 ] ; int32_T djrywqscau [ 6 ] ; int32_T fxerzqdnn4 [ 6 ] ;
int32_T mywyj3ifgs [ 6 ] ; int32_T d1q55gop1o [ 6 ] ; int32_T opprajci1l [ 6
] ; int32_T ljymobalpk [ 6 ] ; int32_T kj1gyk1zyf [ 6 ] ; int32_T a0d2h51hkg
[ 6 ] ; int32_T mxw2tseubc [ 6 ] ; int32_T gtuh2kmbhr [ 6 ] ; int32_T
lsy3sbihvc [ 6 ] ; int32_T peqr3kviw4 [ 6 ] ; int32_T k2d4np15dl [ 6 ] ;
int32_T pt3k3gmetp [ 6 ] ; int32_T ezmqyj1gr1 [ 6 ] ; int32_T fub4i3nxul [ 6
] ; int32_T jdcxgsn5ce [ 6 ] ; int32_T grjqtyru3u [ 6 ] ; int32_T oi5u3pitda
[ 2 ] ; int32_T asufhs1ugh [ 2 ] ; int32_T fpfsjsly5b [ 2 ] ; int32_T
bhbvy4ifhi [ 2 ] ; int32_T aoyjxzbpzc [ 2 ] ; int32_T cphsgbzvky [ 2 ] ;
int32_T oyjel415x0 [ 2 ] ; int32_T f3aef3z5gb [ 2 ] ; int32_T bpdlxsw4ck [ 2
] ; uint32_T dq3yf2kc54 ; int32_T dadv2akfp4 ; } dyigtkkzhy ; struct
at34mfr1ht_ { real_T P_0 ; int32_T P_1 ; int32_T P_2 ; real_T P_3 ; real_T
P_4 ; uint8_T P_5 ; uint8_T P_6 ; uint8_T P_7 ; uint8_T P_8 ; } ; struct
eiamljoxof { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; sysRanDType * systemRan [ 2 ] ; int_T systemTid [ 2 ] ;
} DataMapInfo ; } ; typedef struct { oilz1v0r1v rtb ; dyigtkkzhy rtdw ;
csixeglpbl rtm ; } l0tllqg3h2m ; extern void eefcu1kp0h ( SimStruct *
_mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , csixeglpbl * const
dho20abj51 , oilz1v0r1v * localB , dyigtkkzhy * localDW , void * sysRanPtr ,
int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_LaneDetection_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName
, int_T * retVal ) ; extern mxArray * mr_LaneDetection_GetDWork ( const
l0tllqg3h2m * mdlrefDW ) ; extern void mr_LaneDetection_SetDWork (
l0tllqg3h2m * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_LaneDetection_RegisterSimStateChecksum ( SimStruct * S ) ; extern mxArray
* mr_LaneDetection_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * LaneDetection_GetCAPIStaticMap ( void ) ;
extern void myza1tmjnx ( dyigtkkzhy * localDW ) ; extern void LaneDetection (
const uint8_T fayizsozht [ 15921 ] , int32_T dkvodhtl10 [ 20 ] , int32_T
ipb214pkst [ 2 ] , real_T ht3xboriqh [ 5 ] , int32_T lpmddypkcn [ 2 ] ,
uint8_T lbljpp0upp [ 15921 ] , boolean_T ioxyx4jnwk [ 15921 ] , oilz1v0r1v *
localB , dyigtkkzhy * localDW ) ; extern void LaneDetectionTID1 ( void ) ;
#endif
