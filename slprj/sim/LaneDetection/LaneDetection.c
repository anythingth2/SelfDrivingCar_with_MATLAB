#include "__cf_LaneDetection.h"
#include "LaneDetection_capi.h"
#include "LaneDetection.h"
#include "LaneDetection_private.h"
#include "div_s32_floor.h"
#include "div_s32s64_floor.h"
#include "rt_sqrt_Us32En14_Ys16En7_Is32En14_f_pw.h"
int_T lgmcl3zswm [ 2 ] ; static RegMdlInfo rtMdlInfo_LaneDetection [ 51 ] = {
{ "l0tllqg3h2m" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"LaneDetection" } , { "cxtrrucx50" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "duu2pzoqsx" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"p2435mgk3k" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "omgz5xz0dl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "loh5fhjveq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"amothmzhxl" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "cypz1prack" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "fgxmmki454" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mn12vofnrq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "dyigtkkzhy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "oilz1v0r1v" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"e0dbcbnrpy" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "b3134h2vtq" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "mdqhnriry0" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"gdcvs4q13u" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "eefcu1kp0h" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "myza1tmjnx" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"ei51zoeub5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "LaneDetection" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, 0 , ( NULL ) } , { "eiamljoxof" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "csixeglpbl" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"pohpjw4nzvb" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "lgmcl3zswm" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , -
1 , ( void * ) "LaneDetection" } , { "o501xvk40da" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"oxbnh4j43of" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "mgczl4bvhy5" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "LaneDetection" } , { "pohpjw4nzv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "LaneDetection" } , {
"o501xvk40d" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"LaneDetection" } , { "csfix32_En31" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1
, ( void * ) "sfix32_En31" } , { "sfix32_En31" , MDL_INFO_ID_DATA_TYPE , 0 ,
- 1 , ( NULL ) } , { "csfix32_En8" , MDL_INFO_ID_CMPLX_DATA_TYPE , 0 , - 1 ,
( void * ) "sfix32_En8" } , { "sfix32_En8" , MDL_INFO_ID_DATA_TYPE , 0 , - 1
, ( NULL ) } , { "struct_ySQ4RIodpBjWyWISwhI9L" , MDL_INFO_ID_DATA_TYPE , 0 ,
- 1 , ( NULL ) } , { "struct_AEfjHdAdK9mYcaPLeyPKHG" , MDL_INFO_ID_DATA_TYPE
, 0 , - 1 , ( NULL ) } , { "struct_WLOnDAJlMFi5IZVHs48dt" ,
MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"struct_pkh41Wu1S5KReKZhn4FPzG" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL )
} , { "mr_LaneDetection_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_cacheDataToMxArrayWithOffset" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_extractBitFieldFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "LaneDetection" } , { "mr_LaneDetection_cacheDataAsMxArray"
, MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME , 0
, - 1 , ( void * ) "LaneDetection" } , { "mr_LaneDetection_SetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "LaneDetection" } , {
"mr_LaneDetection_GetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void *
) "LaneDetection" } , { "LaneDetection.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1
, ( NULL ) } , { "LaneDetection.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , (
void * ) "LaneDetection" } } ; at34mfr1ht at34mfr1htg = { 10.0 , 1 , 1024 ,
1.0 , 2.0 , 1U , 2U , 3U , 4U } ; void myza1tmjnx ( dyigtkkzhy * localDW ) {
int32_T nonZeroIdx ; localDW -> dadv2akfp4 = 134883 ; for ( nonZeroIdx = 0 ;
nonZeroIdx < 6 ; nonZeroIdx ++ ) { localDW -> djrywqscau [ nonZeroIdx ] =
o501xvk40da . fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [
nonZeroIdx ] ; if ( o501xvk40da . f3q14r5epo [ nonZeroIdx ] > 0 ) { localDW
-> mywyj3ifgs [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [ nonZeroIdx ] * 61 +
o501xvk40da . f3q14r5epo [ nonZeroIdx ] ; localDW -> d1q55gop1o [ nonZeroIdx
] = o501xvk40da . fyoacswgxa [ nonZeroIdx ] * 61 ; } else { localDW ->
mywyj3ifgs [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [ nonZeroIdx ] * 61 ;
localDW -> d1q55gop1o [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [ nonZeroIdx
] * 61 + o501xvk40da . f3q14r5epo [ nonZeroIdx ] ; } if ( o501xvk40da .
fyoacswgxa [ nonZeroIdx ] > 0 ) { localDW -> opprajci1l [ nonZeroIdx ] =
o501xvk40da . fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [
nonZeroIdx ] ; localDW -> ljymobalpk [ nonZeroIdx ] = o501xvk40da .
f3q14r5epo [ nonZeroIdx ] ; } else { localDW -> opprajci1l [ nonZeroIdx ] =
o501xvk40da . f3q14r5epo [ nonZeroIdx ] ; localDW -> ljymobalpk [ nonZeroIdx
] = o501xvk40da . fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [
nonZeroIdx ] ; } if ( ( o501xvk40da . f3q14r5epo [ nonZeroIdx ] < 0 ) && (
o501xvk40da . fyoacswgxa [ nonZeroIdx ] < 0 ) ) { localDW -> lsy3sbihvc [
nonZeroIdx ] = 0 ; localDW -> pt3k3gmetp [ nonZeroIdx ] = o501xvk40da .
fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [ nonZeroIdx ] ;
localDW -> peqr3kviw4 [ nonZeroIdx ] = o501xvk40da . f3q14r5epo [ nonZeroIdx
] ; localDW -> k2d4np15dl [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [
nonZeroIdx ] * 61 ; } if ( ( o501xvk40da . f3q14r5epo [ nonZeroIdx ] >= 0 )
&& ( o501xvk40da . fyoacswgxa [ nonZeroIdx ] < 0 ) ) { localDW -> peqr3kviw4
[ nonZeroIdx ] = 0 ; localDW -> k2d4np15dl [ nonZeroIdx ] = o501xvk40da .
fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [ nonZeroIdx ] ;
localDW -> lsy3sbihvc [ nonZeroIdx ] = o501xvk40da . f3q14r5epo [ nonZeroIdx
] ; localDW -> pt3k3gmetp [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [
nonZeroIdx ] * 61 ; } if ( ( o501xvk40da . f3q14r5epo [ nonZeroIdx ] < 0 ) &&
( o501xvk40da . fyoacswgxa [ nonZeroIdx ] >= 0 ) ) { localDW -> k2d4np15dl [
nonZeroIdx ] = 0 ; localDW -> peqr3kviw4 [ nonZeroIdx ] = o501xvk40da .
fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [ nonZeroIdx ] ;
localDW -> lsy3sbihvc [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [ nonZeroIdx
] * 61 ; localDW -> pt3k3gmetp [ nonZeroIdx ] = o501xvk40da . f3q14r5epo [
nonZeroIdx ] ; } if ( ( o501xvk40da . f3q14r5epo [ nonZeroIdx ] >= 0 ) && (
o501xvk40da . fyoacswgxa [ nonZeroIdx ] >= 0 ) ) { localDW -> pt3k3gmetp [
nonZeroIdx ] = 0 ; localDW -> lsy3sbihvc [ nonZeroIdx ] = o501xvk40da .
fyoacswgxa [ nonZeroIdx ] * 61 + o501xvk40da . f3q14r5epo [ nonZeroIdx ] ;
localDW -> peqr3kviw4 [ nonZeroIdx ] = o501xvk40da . fyoacswgxa [ nonZeroIdx
] * 61 ; localDW -> k2d4np15dl [ nonZeroIdx ] = o501xvk40da . f3q14r5epo [
nonZeroIdx ] ; } localDW -> fxerzqdnn4 [ nonZeroIdx ] = o501xvk40da .
bbulndrtcq [ nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; if
( o501xvk40da . grz3fajvk5 [ nonZeroIdx ] > 0 ) { localDW -> kj1gyk1zyf [
nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 + o501xvk40da .
grz3fajvk5 [ nonZeroIdx ] ; localDW -> a0d2h51hkg [ nonZeroIdx ] =
o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 ; } else { localDW -> kj1gyk1zyf
[ nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 ; localDW ->
a0d2h51hkg [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 +
o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; } if ( o501xvk40da . bbulndrtcq [
nonZeroIdx ] > 0 ) { localDW -> mxw2tseubc [ nonZeroIdx ] = o501xvk40da .
bbulndrtcq [ nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ;
localDW -> gtuh2kmbhr [ nonZeroIdx ] = o501xvk40da . grz3fajvk5 [ nonZeroIdx
] ; } else { localDW -> mxw2tseubc [ nonZeroIdx ] = o501xvk40da . grz3fajvk5
[ nonZeroIdx ] ; localDW -> gtuh2kmbhr [ nonZeroIdx ] = o501xvk40da .
bbulndrtcq [ nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; }
if ( ( o501xvk40da . grz3fajvk5 [ nonZeroIdx ] < 0 ) && ( o501xvk40da .
bbulndrtcq [ nonZeroIdx ] < 0 ) ) { localDW -> ezmqyj1gr1 [ nonZeroIdx ] = 0
; localDW -> grjqtyru3u [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [
nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; localDW ->
fub4i3nxul [ nonZeroIdx ] = o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; localDW
-> jdcxgsn5ce [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 ;
} if ( ( o501xvk40da . grz3fajvk5 [ nonZeroIdx ] >= 0 ) && ( o501xvk40da .
bbulndrtcq [ nonZeroIdx ] < 0 ) ) { localDW -> fub4i3nxul [ nonZeroIdx ] = 0
; localDW -> jdcxgsn5ce [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [
nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; localDW ->
ezmqyj1gr1 [ nonZeroIdx ] = o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; localDW
-> grjqtyru3u [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 ;
} if ( ( o501xvk40da . grz3fajvk5 [ nonZeroIdx ] < 0 ) && ( o501xvk40da .
bbulndrtcq [ nonZeroIdx ] >= 0 ) ) { localDW -> jdcxgsn5ce [ nonZeroIdx ] = 0
; localDW -> fub4i3nxul [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [
nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; localDW ->
ezmqyj1gr1 [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 ;
localDW -> grjqtyru3u [ nonZeroIdx ] = o501xvk40da . grz3fajvk5 [ nonZeroIdx
] ; } if ( ( o501xvk40da . grz3fajvk5 [ nonZeroIdx ] >= 0 ) && ( o501xvk40da
. bbulndrtcq [ nonZeroIdx ] >= 0 ) ) { localDW -> grjqtyru3u [ nonZeroIdx ] =
0 ; localDW -> ezmqyj1gr1 [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [
nonZeroIdx ] * 61 + o501xvk40da . grz3fajvk5 [ nonZeroIdx ] ; localDW ->
fub4i3nxul [ nonZeroIdx ] = o501xvk40da . bbulndrtcq [ nonZeroIdx ] * 61 ;
localDW -> jdcxgsn5ce [ nonZeroIdx ] = o501xvk40da . grz3fajvk5 [ nonZeroIdx
] ; } } } void LaneDetection ( const uint8_T fayizsozht [ 15921 ] , int32_T
dkvodhtl10 [ 20 ] , int32_T ipb214pkst [ 2 ] , real_T ht3xboriqh [ 5 ] ,
int32_T lpmddypkcn [ 2 ] , uint8_T lbljpp0upp [ 15921 ] , boolean_T
ioxyx4jnwk [ 15921 ] , oilz1v0r1v * localB , dyigtkkzhy * localDW ) {
boolean_T done ; int32_T imgRow ; int32_T m ; boolean_T b4 ; boolean_T b3 ;
boolean_T b2 ; int32_T accumOne ; int32_T accumTwo ; int32_T accumFour ;
int32_T accumThree ; int32_T acc2_idx_4 ; int32_T acc1_idx_3 ; int32_T
acc1_idx_0 ; int32_T acc1_idx_2 ; int32_T acc2_idx_2 ; int32_T acc2_idx_0 ;
int32_T acc2_idx_1 ; for ( localB -> dw40j5sber = 0 ; localB -> dw40j5sber <
259 ; localB -> dw40j5sber ++ ) { for ( imgRow = 0 ; imgRow < 59 ; imgRow ++
) { accumOne = 0 ; accumTwo = 0 ; localB -> autjwaia4y = ( ( localB ->
dw40j5sber + 1 ) * 61 + imgRow ) + 1 ; for ( m = 0 ; m < 6 ; m ++ ) {
accumOne += ( int32_T ) ( ( int64_T ) fayizsozht [ localB -> autjwaia4y +
localDW -> djrywqscau [ m ] ] * o501xvk40da . lltscohk4e [ m ] >> 23 ) ;
accumTwo += ( int32_T ) ( ( int64_T ) fayizsozht [ localB -> autjwaia4y +
localDW -> fxerzqdnn4 [ m ] ] * o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; }
localDW -> ephazqj5mq [ localB -> autjwaia4y ] = ( int32_T ) ( ( int64_T )
accumOne * accumOne >> 8 ) ; localDW -> cc40xb1fei [ localB -> autjwaia4y ] =
( int32_T ) ( ( int64_T ) accumTwo * accumTwo >> 8 ) ; } } for ( localB ->
dw40j5sber = 0 ; localB -> dw40j5sber < 259 ; localB -> dw40j5sber ++ ) {
accumOne = 0 ; accumTwo = 0 ; accumThree = 0 ; accumFour = 0 ; imgRow = (
localB -> dw40j5sber + 1 ) * 61 ; localB -> autjwaia4y = ( localB ->
dw40j5sber + 1 ) * 61 + 60 ; for ( m = 0 ; m < 6 ; m ++ ) { accumOne += (
int32_T ) ( ( int64_T ) fayizsozht [ imgRow + localDW -> kj1gyk1zyf [ m ] ] *
o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; accumTwo += ( int32_T ) ( ( int64_T
) fayizsozht [ localB -> autjwaia4y + localDW -> a0d2h51hkg [ m ] ] *
o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; accumThree += ( int32_T ) ( (
int64_T ) fayizsozht [ imgRow + localDW -> mywyj3ifgs [ m ] ] * o501xvk40da .
lltscohk4e [ m ] >> 23 ) ; accumFour += ( int32_T ) ( ( int64_T ) fayizsozht
[ localB -> autjwaia4y + localDW -> d1q55gop1o [ m ] ] * o501xvk40da .
lltscohk4e [ m ] >> 23 ) ; } localDW -> ephazqj5mq [ imgRow ] = ( int32_T ) (
( int64_T ) accumThree * accumThree >> 8 ) ; localDW -> cc40xb1fei [ imgRow ]
= ( int32_T ) ( ( int64_T ) accumOne * accumOne >> 8 ) ; localDW ->
ephazqj5mq [ localB -> autjwaia4y ] = ( int32_T ) ( ( int64_T ) accumFour *
accumFour >> 8 ) ; localDW -> cc40xb1fei [ localB -> autjwaia4y ] = ( int32_T
) ( ( int64_T ) accumTwo * accumTwo >> 8 ) ; } for ( imgRow = 0 ; imgRow < 59
; imgRow ++ ) { accumOne = 0 ; accumTwo = 0 ; accumThree = 0 ; accumFour = 0
; localB -> dw40j5sber = imgRow + 15861 ; for ( m = 0 ; m < 6 ; m ++ ) {
accumOne += ( int32_T ) ( ( int64_T ) fayizsozht [ ( imgRow + localDW ->
opprajci1l [ m ] ) + 1 ] * o501xvk40da . lltscohk4e [ m ] >> 23 ) ; accumTwo
+= ( int32_T ) ( ( int64_T ) fayizsozht [ localB -> dw40j5sber + localDW ->
ljymobalpk [ m ] ] * o501xvk40da . lltscohk4e [ m ] >> 23 ) ; accumThree += (
int32_T ) ( ( int64_T ) fayizsozht [ ( imgRow + localDW -> mxw2tseubc [ m ] )
+ 1 ] * o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; accumFour += ( int32_T ) ( (
int64_T ) fayizsozht [ localB -> dw40j5sber + localDW -> gtuh2kmbhr [ m ] ] *
o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; } localDW -> ephazqj5mq [ imgRow + 1
] = ( int32_T ) ( ( int64_T ) accumOne * accumOne >> 8 ) ; localDW ->
cc40xb1fei [ imgRow + 1 ] = ( int32_T ) ( ( int64_T ) accumThree * accumThree
>> 8 ) ; localDW -> ephazqj5mq [ localB -> dw40j5sber ] = ( int32_T ) ( (
int64_T ) accumTwo * accumTwo >> 8 ) ; localDW -> cc40xb1fei [ localB ->
dw40j5sber ] = ( int32_T ) ( ( int64_T ) accumFour * accumFour >> 8 ) ; }
accumOne = 0 ; accumTwo = 0 ; accumThree = 0 ; accumFour = 0 ; for ( m = 0 ;
m < 6 ; m ++ ) { accumOne += ( int32_T ) ( ( int64_T ) fayizsozht [ localDW
-> lsy3sbihvc [ m ] ] * o501xvk40da . lltscohk4e [ m ] >> 23 ) ; accumTwo +=
( int32_T ) ( ( int64_T ) fayizsozht [ localDW -> ezmqyj1gr1 [ m ] ] *
o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; accumThree += ( int32_T ) ( (
int64_T ) fayizsozht [ 60 + localDW -> peqr3kviw4 [ m ] ] * o501xvk40da .
lltscohk4e [ m ] >> 23 ) ; accumFour += ( int32_T ) ( ( int64_T ) fayizsozht
[ 60 + localDW -> fub4i3nxul [ m ] ] * o501xvk40da . n0vvzmoddm [ m ] >> 23 )
; } localDW -> ephazqj5mq [ 0 ] = ( int32_T ) ( ( int64_T ) accumOne *
accumOne >> 8 ) ; localDW -> cc40xb1fei [ 0 ] = ( int32_T ) ( ( int64_T )
accumTwo * accumTwo >> 8 ) ; localDW -> ephazqj5mq [ 60 ] = ( int32_T ) ( (
int64_T ) accumThree * accumThree >> 8 ) ; localDW -> cc40xb1fei [ 60 ] = (
int32_T ) ( ( int64_T ) accumFour * accumFour >> 8 ) ; accumOne = 0 ;
accumTwo = 0 ; accumThree = 0 ; accumFour = 0 ; for ( m = 0 ; m < 6 ; m ++ )
{ accumOne += ( int32_T ) ( ( int64_T ) fayizsozht [ 15860 + localDW ->
k2d4np15dl [ m ] ] * o501xvk40da . lltscohk4e [ m ] >> 23 ) ; accumTwo += (
int32_T ) ( ( int64_T ) fayizsozht [ 15860 + localDW -> jdcxgsn5ce [ m ] ] *
o501xvk40da . n0vvzmoddm [ m ] >> 23 ) ; accumThree += ( int32_T ) ( (
int64_T ) fayizsozht [ 15920 + localDW -> pt3k3gmetp [ m ] ] * o501xvk40da .
lltscohk4e [ m ] >> 23 ) ; accumFour += ( int32_T ) ( ( int64_T ) fayizsozht
[ 15920 + localDW -> grjqtyru3u [ m ] ] * o501xvk40da . n0vvzmoddm [ m ] >>
23 ) ; } localDW -> ephazqj5mq [ 15860 ] = ( int32_T ) ( ( int64_T ) accumOne
* accumOne >> 8 ) ; localDW -> cc40xb1fei [ 15860 ] = ( int32_T ) ( ( int64_T
) accumTwo * accumTwo >> 8 ) ; localDW -> ephazqj5mq [ 15920 ] = ( int32_T )
( ( int64_T ) accumThree * accumThree >> 8 ) ; localDW -> cc40xb1fei [ 15920
] = ( int32_T ) ( ( int64_T ) accumFour * accumFour >> 8 ) ; accumTwo = 0 ;
for ( m = 0 ; m < 15921 ; m ++ ) { localDW -> cdu44n1mcq [ m ] = localDW ->
ephazqj5mq [ m ] ; localDW -> cdu44n1mcq [ m ] += localDW -> cc40xb1fei [ m ]
; accumTwo += ( int32_T ) ( ( int64_T ) localDW -> cdu44n1mcq [ m ] * localDW
-> dadv2akfp4 >> 31 ) ; } accumOne = ( int32_T ) ( ( int64_T ) at34mfr1htg .
P_2 * accumTwo >> 8 ) ; for ( localB -> dw40j5sber = 0 ; localB -> dw40j5sber
< 261 ; localB -> dw40j5sber ++ ) { for ( imgRow = 0 ; imgRow < 61 ; imgRow
++ ) { m = localB -> dw40j5sber * 61 + imgRow ; done = true ; b2 = true ; b3
= true ; b4 = true ; if ( localB -> dw40j5sber != 0 ) { done = ( localDW ->
cdu44n1mcq [ m - 61 ] <= localDW -> cdu44n1mcq [ m ] ) ; } if ( localB ->
dw40j5sber != 260 ) { b2 = ( localDW -> cdu44n1mcq [ m ] > localDW ->
cdu44n1mcq [ m + 61 ] ) ; } if ( imgRow != 0 ) { b3 = ( localDW -> cdu44n1mcq
[ m - 1 ] <= localDW -> cdu44n1mcq [ m ] ) ; } if ( imgRow != 60 ) { b4 = (
localDW -> cdu44n1mcq [ m ] > localDW -> cdu44n1mcq [ m + 1 ] ) ; }
ioxyx4jnwk [ m ] = ( ( localDW -> cdu44n1mcq [ m ] > accumOne ) && ( ( (
localDW -> ephazqj5mq [ m ] >= localDW -> cc40xb1fei [ m ] ) && done && b2 )
|| ( ( localDW -> cc40xb1fei [ m ] >= localDW -> ephazqj5mq [ m ] ) && b3 &&
b4 ) ) ) ; } } MWVIP_Hough_D ( & ioxyx4jnwk [ 0 ] , & localB -> b3lj1ro54e [
0 ] , & o501xvk40da . mlslbus31o [ 0 ] , & o501xvk40da . kftxuk0mpk , 61 ,
261 , 535 , 91 ) ; accumOne = 0 ; done = false ; for ( m = 0 ; m < 96300 ; m
++ ) { localDW -> dsg35qf31k [ m ] = localB -> b3lj1ro54e [ m ] ; } for ( m =
0 ; m < 10 ; m ++ ) { localB -> gosar0sgre [ m ] = 0.0 ; } while ( ! done ) {
accumTwo = 0 ; localB -> ivcr4kb2di = localDW -> dsg35qf31k [ 0 ] ; for ( m =
0 ; m < 96300 ; m ++ ) { if ( localDW -> dsg35qf31k [ m ] > localB ->
ivcr4kb2di ) { accumTwo = m ; localB -> ivcr4kb2di = localDW -> dsg35qf31k [
m ] ; } } localB -> dw40j5sber = accumTwo % 535 ; m = accumTwo / 535 ; if (
localDW -> dsg35qf31k [ accumTwo ] >= at34mfr1htg . P_0 ) { localB ->
gosar0sgre [ accumOne ] = 1.0 + ( real_T ) m ; localB -> gosar0sgre [ 5U +
accumOne ] = 1 + localB -> dw40j5sber ; accumOne ++ ; if ( accumOne == 5 ) {
done = true ; } localB -> f1sw2ht4n2 = localB -> dw40j5sber - 2 ; accumTwo =
muIntScalarMax_sint32 ( localB -> f1sw2ht4n2 , 0 ) ; localB -> f1sw2ht4n2 =
localB -> dw40j5sber + 2 ; localB -> dw40j5sber = muIntScalarMin_sint32 (
localB -> f1sw2ht4n2 , 534 ) ; imgRow = m - 3 ; localB -> autjwaia4y = m + 3
; if ( ! ( ( imgRow < 0 ) || ( localB -> autjwaia4y > 179 ) ) ) { while (
imgRow <= localB -> autjwaia4y ) { accumThree = imgRow * 535 ; for ( m =
accumTwo ; m <= localB -> dw40j5sber ; m ++ ) { localDW -> dsg35qf31k [ m +
accumThree ] = 0.0 ; } imgRow ++ ; } } else { if ( imgRow < 0 ) { localB ->
iu2lveaurm = imgRow ; while ( localB -> iu2lveaurm <= localB -> autjwaia4y )
{ if ( localB -> iu2lveaurm < 0 ) { accumThree = ( localB -> iu2lveaurm + 180
) * 535 + 534 ; for ( m = accumTwo ; m <= localB -> dw40j5sber ; m ++ ) {
localDW -> dsg35qf31k [ accumThree - m ] = 0.0 ; } } else { accumThree =
localB -> iu2lveaurm * 535 ; for ( m = accumTwo ; m <= localB -> dw40j5sber ;
m ++ ) { localDW -> dsg35qf31k [ m + accumThree ] = 0.0 ; } } localB ->
iu2lveaurm ++ ; } } if ( localB -> autjwaia4y > 179 ) { localB -> iu2lveaurm
= imgRow ; while ( localB -> iu2lveaurm <= localB -> autjwaia4y ) { if (
localB -> iu2lveaurm > 179 ) { accumThree = ( localB -> iu2lveaurm - 180 ) *
535 + 534 ; for ( m = accumTwo ; m <= localB -> dw40j5sber ; m ++ ) { localDW
-> dsg35qf31k [ accumThree - m ] = 0.0 ; } } else { accumThree = localB ->
iu2lveaurm * 535 ; for ( m = accumTwo ; m <= localB -> dw40j5sber ; m ++ ) {
localDW -> dsg35qf31k [ m + accumThree ] = 0.0 ; } } localB -> iu2lveaurm ++
; } } } } else { done = true ; } } localDW -> dq3yf2kc54 = ( uint32_T )
accumOne ; localB -> caihcvukc4 = 5U ; localB -> hrm1rndox2 = ( uint32_T )
accumOne ; for ( m = 0 ; m < accumOne ; m ++ ) { localB -> gosar0sgre [
localB -> hrm1rndox2 ] = localB -> gosar0sgre [ localB -> caihcvukc4 ] ;
localB -> caihcvukc4 ++ ; localB -> hrm1rndox2 ++ ; } localDW -> oi5u3pitda [
0 ] = ( int32_T ) localDW -> dq3yf2kc54 ; localDW -> oi5u3pitda [ 1 ] = 2 ;
localDW -> asufhs1ugh [ 0 ] = localDW -> oi5u3pitda [ 0 ] ; localDW ->
asufhs1ugh [ 1 ] = 1 ; imgRow = localDW -> oi5u3pitda [ 0 ] ; localB ->
f1sw2ht4n2 = ( int32_T ) at34mfr1htg . P_3 ; for ( m = 0 ; m < imgRow ; m ++
) { localB -> n2vgaroq1m [ m ] = localB -> gosar0sgre [ ( localB ->
f1sw2ht4n2 - 1 ) * localDW -> oi5u3pitda [ 0 ] + m ] ; } imgRow = localDW ->
oi5u3pitda [ 0 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 <
imgRow ; localB -> f1sw2ht4n2 ++ ) { localB -> lysrq3xxtz [ localB ->
f1sw2ht4n2 ] = localB -> n2vgaroq1m [ localB -> f1sw2ht4n2 ] ; } localDW ->
fpfsjsly5b [ 0 ] = 1 ; localDW -> fpfsjsly5b [ 1 ] = localDW -> asufhs1ugh [
0 ] * localDW -> asufhs1ugh [ 1 ] ; imgRow = localDW -> asufhs1ugh [ 1 ] ;
for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ; localB ->
f1sw2ht4n2 ++ ) { localB -> autjwaia4y = localDW -> asufhs1ugh [ 0 ] ; for (
m = 0 ; m < localB -> autjwaia4y ; m ++ ) { localB -> br2yymckcz [ m +
localDW -> asufhs1ugh [ 0 ] * localB -> f1sw2ht4n2 ] = ( int32_T ) localB ->
lysrq3xxtz [ localDW -> asufhs1ugh [ 0 ] * localB -> f1sw2ht4n2 + m ] - 1 ; }
} imgRow = localDW -> asufhs1ugh [ 0 ] * localDW -> asufhs1ugh [ 1 ] ; for (
localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ; localB ->
f1sw2ht4n2 ++ ) { localB -> ldho0fd2nl [ localDW -> fpfsjsly5b [ 0 ] * localB
-> f1sw2ht4n2 ] = localB -> pzo3lxik1r [ localB -> br2yymckcz [ localB ->
f1sw2ht4n2 ] ] ; } localDW -> bhbvy4ifhi [ 0 ] = localDW -> oi5u3pitda [ 0 ]
; localDW -> bhbvy4ifhi [ 1 ] = 1 ; imgRow = localDW -> oi5u3pitda [ 0 ] ;
localB -> f1sw2ht4n2 = ( int32_T ) at34mfr1htg . P_4 ; for ( m = 0 ; m <
imgRow ; m ++ ) { localB -> n2vgaroq1m [ m ] = localB -> gosar0sgre [ (
localB -> f1sw2ht4n2 - 1 ) * localDW -> oi5u3pitda [ 0 ] + m ] ; } imgRow =
localDW -> oi5u3pitda [ 0 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB ->
f1sw2ht4n2 < imgRow ; localB -> f1sw2ht4n2 ++ ) { localB -> lysrq3xxtz [
localB -> f1sw2ht4n2 ] = localB -> n2vgaroq1m [ localB -> f1sw2ht4n2 ] ; }
localDW -> aoyjxzbpzc [ 0 ] = 1 ; localDW -> aoyjxzbpzc [ 1 ] = localDW ->
bhbvy4ifhi [ 0 ] * localDW -> bhbvy4ifhi [ 1 ] ; imgRow = localDW ->
bhbvy4ifhi [ 1 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 <
imgRow ; localB -> f1sw2ht4n2 ++ ) { localB -> autjwaia4y = localDW ->
bhbvy4ifhi [ 0 ] ; for ( m = 0 ; m < localB -> autjwaia4y ; m ++ ) { localB
-> br2yymckcz [ m + localDW -> bhbvy4ifhi [ 0 ] * localB -> f1sw2ht4n2 ] = (
int32_T ) localB -> lysrq3xxtz [ localDW -> bhbvy4ifhi [ 0 ] * localB ->
f1sw2ht4n2 + m ] - 1 ; } } imgRow = localDW -> bhbvy4ifhi [ 0 ] * localDW ->
bhbvy4ifhi [ 1 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 <
imgRow ; localB -> f1sw2ht4n2 ++ ) { localB -> dkhie0ooet [ localDW ->
aoyjxzbpzc [ 0 ] * localB -> f1sw2ht4n2 ] = localB -> mesknpbk5t [ localB ->
br2yymckcz [ localB -> f1sw2ht4n2 ] ] ; } ipb214pkst [ 1 ] = 4 ; ipb214pkst [
0 ] = localDW -> fpfsjsly5b [ 0 ] * localDW -> fpfsjsly5b [ 1 ] ; for ( m = 0
; m < localDW -> fpfsjsly5b [ 1 ] ; m ++ ) { accumTwo = 0 ; localB ->
ivcr4kb2di = ( localB -> dkhie0ooet [ m ] + 2.2204460492503131E-16 ) / (
muDoubleScalarCos ( localB -> ldho0fd2nl [ m ] ) + 2.2204460492503131E-16 ) ;
localB -> grmieipfa4 = muDoubleScalarFloor ( localB -> ivcr4kb2di + 0.5 ) ;
if ( ( localB -> grmieipfa4 >= 0.0 ) && ( localB -> grmieipfa4 <= 260.0 ) ) {
localB -> cqytuh4sir [ 0U ] = 0 ; if ( localB -> grmieipfa4 >= 0.5 ) { localB
-> cqytuh4sir [ 1U ] = ( int32_T ) muDoubleScalarFloor ( localB -> grmieipfa4
+ 0.5 ) ; } else { localB -> cqytuh4sir [ 1U ] = 0 ; } accumTwo = 1 ; }
localB -> bidf1d0hab = ( localB -> dkhie0ooet [ m ] + 2.2204460492503131E-16
) / ( muDoubleScalarSin ( localB -> ldho0fd2nl [ m ] ) +
2.2204460492503131E-16 ) ; localB -> grmieipfa4 = muDoubleScalarFloor (
localB -> bidf1d0hab + 0.5 ) ; if ( ( localB -> grmieipfa4 >= 0.0 ) && (
localB -> grmieipfa4 <= 60.0 ) ) { if ( localB -> grmieipfa4 >= 0.5 ) {
localB -> cqytuh4sir [ accumTwo << 1 ] = ( int32_T ) muDoubleScalarFloor (
localB -> grmieipfa4 + 0.5 ) ; } else { localB -> cqytuh4sir [ accumTwo << 1
] = 0 ; } localB -> cqytuh4sir [ 1 + ( accumTwo << 1 ) ] = 0 ; accumTwo ++ ;
} if ( accumTwo < 2 ) { localB -> grmieipfa4 = muDoubleScalarFloor ( ( localB
-> ivcr4kb2di - 260.0 ) * ( localB -> bidf1d0hab / localB -> ivcr4kb2di ) +
0.5 ) ; if ( ( localB -> grmieipfa4 >= 0.0 ) && ( localB -> grmieipfa4 <=
60.0 ) ) { if ( localB -> grmieipfa4 >= 0.5 ) { localB -> cqytuh4sir [
accumTwo << 1 ] = ( int32_T ) muDoubleScalarFloor ( localB -> grmieipfa4 +
0.5 ) ; } else { localB -> cqytuh4sir [ accumTwo << 1 ] = 0 ; } localB ->
cqytuh4sir [ 1 + ( accumTwo << 1 ) ] = 260 ; accumTwo ++ ; } } if ( accumTwo
< 2 ) { localB -> grmieipfa4 = muDoubleScalarFloor ( ( localB -> ivcr4kb2di -
localB -> ivcr4kb2di / localB -> bidf1d0hab * 60.0 ) + 0.5 ) ; if ( ( localB
-> grmieipfa4 >= 0.0 ) && ( localB -> grmieipfa4 <= 260.0 ) ) { localB ->
cqytuh4sir [ accumTwo << 1 ] = 60 ; if ( localB -> grmieipfa4 >= 0.5 ) {
localB -> cqytuh4sir [ 1 + ( accumTwo << 1 ) ] = ( int32_T )
muDoubleScalarFloor ( localB -> grmieipfa4 + 0.5 ) ; } else { localB ->
cqytuh4sir [ 1 + ( accumTwo << 1 ) ] = 0 ; } accumTwo ++ ; } } if ( accumTwo
< 2 ) { localB -> cqytuh4sir [ 0U ] = - 1 ; localB -> cqytuh4sir [ 1U ] = - 1
; localB -> cqytuh4sir [ 2U ] = - 1 ; localB -> cqytuh4sir [ 3U ] = - 1 ; }
dkvodhtl10 [ m ] = localB -> cqytuh4sir [ 1 ] + 1 ; dkvodhtl10 [ m + localDW
-> fpfsjsly5b [ 1 ] ] = localB -> cqytuh4sir [ 0 ] + 1 ; if ( localB ->
cqytuh4sir [ 3 ] > 2147483646 ) { dkvodhtl10 [ m + ( localDW -> fpfsjsly5b [
1 ] << 1 ) ] = MAX_int32_T ; } else { dkvodhtl10 [ m + ( localDW ->
fpfsjsly5b [ 1 ] << 1 ) ] = localB -> cqytuh4sir [ 3 ] + 1 ; } if ( localB ->
cqytuh4sir [ 2 ] > 2147483646 ) { dkvodhtl10 [ m + 3 * localDW -> fpfsjsly5b
[ 1 ] ] = MAX_int32_T ; } else { dkvodhtl10 [ m + 3 * localDW -> fpfsjsly5b [
1 ] ] = localB -> cqytuh4sir [ 2 ] + 1 ; } } if ( at34mfr1htg . P_1 == 1 ) {
accumTwo = 0 ; accumOne = 0 ; if ( ipb214pkst [ 1 ] > 1 ) { accumOne =
ipb214pkst [ 1 ] >> 1 ; done = ( accumOne << 1 == ipb214pkst [ 1 ] ) ;
accumTwo = ipb214pkst [ 0 ] ; } else { if ( ipb214pkst [ 1 ] == 1 ) {
accumOne = ipb214pkst [ 0 ] >> 1 ; done = ( accumOne << 1 == ipb214pkst [ 0 ]
) ; accumTwo = 1 ; } } memcpy ( & lbljpp0upp [ 0 ] , & fayizsozht [ 0 ] ,
15921U * sizeof ( uint8_T ) ) ; if ( done && ( accumTwo > 0 ) ) { localB ->
dw40j5sber = 0 ; while ( localB -> dw40j5sber < accumTwo ) { imgRow = 0 ;
localB -> autjwaia4y = 0 ; while ( localB -> autjwaia4y < accumOne - 1 ) {
localB -> f3exltnl3f = dkvodhtl10 [ ( ( imgRow * accumTwo << 1 ) + localB ->
dw40j5sber ) + accumTwo ] - 1 ; localB -> dsu3yzczbs = dkvodhtl10 [ ( imgRow
* accumTwo << 1 ) + localB -> dw40j5sber ] - 1 ; imgRow ++ ; acc1_idx_0 =
dkvodhtl10 [ ( ( imgRow * accumTwo << 1 ) + localB -> dw40j5sber ) + accumTwo
] - 1 ; acc1_idx_2 = dkvodhtl10 [ ( imgRow * accumTwo << 1 ) + localB ->
dw40j5sber ] - 1 ; if ( ( localB -> f3exltnl3f != acc1_idx_0 ) || ( localB ->
dsu3yzczbs != acc1_idx_2 ) ) { b2 = false ; b3 = false ; b4 = false ; done =
false ; accumFour = localB -> f3exltnl3f ; localB -> pdv5xeozmc = localB ->
dsu3yzczbs ; localB -> iu2lveaurm = acc1_idx_0 ; localB -> i4qkuytuty =
acc1_idx_2 ; while ( ! done ) { localB -> caihcvukc4 = 0U ; localB ->
hrm1rndox2 = 0U ; if ( accumFour < 0 ) { localB -> caihcvukc4 = 4U ; } else {
if ( accumFour > 60 ) { localB -> caihcvukc4 = 8U ; } } if ( localB ->
iu2lveaurm < 0 ) { localB -> hrm1rndox2 = 4U ; } else { if ( localB ->
iu2lveaurm > 60 ) { localB -> hrm1rndox2 = 8U ; } } if ( localB -> pdv5xeozmc
< 0 ) { localB -> caihcvukc4 |= 1U ; } else { if ( localB -> pdv5xeozmc > 260
) { localB -> caihcvukc4 |= 2U ; } } if ( localB -> i4qkuytuty < 0 ) { localB
-> hrm1rndox2 |= 1U ; } else { if ( localB -> i4qkuytuty > 260 ) { localB ->
hrm1rndox2 |= 2U ; } } if ( ! ( ( localB -> caihcvukc4 | localB -> hrm1rndox2
) != 0U ) ) { done = true ; b2 = true ; } else if ( ( localB -> caihcvukc4 &
localB -> hrm1rndox2 ) != 0U ) { done = true ; b2 = false ; } else if (
localB -> caihcvukc4 != 0U ) { if ( b3 ) { accumFour = localB -> f3exltnl3f ;
localB -> pdv5xeozmc = localB -> dsu3yzczbs ; } m = localB -> iu2lveaurm -
accumFour ; accumThree = localB -> i4qkuytuty - localB -> pdv5xeozmc ; if ( (
m > 1073741824 ) || ( m < - 1073741824 ) || ( ( accumThree > 1073741824 ) ||
( accumThree < - 1073741824 ) ) ) { done = true ; b2 = false ; b3 = true ; }
else if ( ( localB -> caihcvukc4 & 4U ) != 0U ) { localB -> cszf0mmuw5 = -
accumFour * accumThree ; if ( ( localB -> cszf0mmuw5 > 1073741824 ) || (
localB -> cszf0mmuw5 < - 1073741824 ) ) { done = true ; b2 = false ; } else
if ( ( ( localB -> cszf0mmuw5 >= 0 ) && ( m >= 0 ) ) || ( ( localB ->
cszf0mmuw5 < 0 ) && ( m < 0 ) ) ) { localB -> pdv5xeozmc += ( div_s32_floor (
localB -> cszf0mmuw5 << 1 , m ) + 1 ) >> 1 ; } else { localB -> pdv5xeozmc -=
( div_s32_floor ( - localB -> cszf0mmuw5 << 1 , m ) + 1 ) >> 1 ; } accumFour
= 0 ; b3 = true ; } else if ( ( localB -> caihcvukc4 & 8U ) != 0U ) { localB
-> cszf0mmuw5 = ( 60 - accumFour ) * accumThree ; if ( ( localB -> cszf0mmuw5
> 1073741824 ) || ( localB -> cszf0mmuw5 < - 1073741824 ) ) { done = true ;
b2 = false ; } else if ( ( ( localB -> cszf0mmuw5 >= 0 ) && ( m >= 0 ) ) || (
( localB -> cszf0mmuw5 < 0 ) && ( m < 0 ) ) ) { localB -> pdv5xeozmc += (
div_s32_floor ( localB -> cszf0mmuw5 << 1 , m ) + 1 ) >> 1 ; } else { localB
-> pdv5xeozmc -= ( div_s32_floor ( - localB -> cszf0mmuw5 << 1 , m ) + 1 ) >>
1 ; } accumFour = 60 ; b3 = true ; } else if ( ( localB -> caihcvukc4 & 1U )
!= 0U ) { localB -> cszf0mmuw5 = - localB -> pdv5xeozmc * m ; if ( ( localB
-> cszf0mmuw5 > 1073741824 ) || ( localB -> cszf0mmuw5 < - 1073741824 ) ) {
done = true ; b2 = false ; } else if ( ( ( localB -> cszf0mmuw5 >= 0 ) && (
accumThree >= 0 ) ) || ( ( localB -> cszf0mmuw5 < 0 ) && ( accumThree < 0 ) )
) { accumFour += ( div_s32_floor ( localB -> cszf0mmuw5 << 1 , accumThree ) +
1 ) >> 1 ; } else { accumFour -= ( div_s32_floor ( - localB -> cszf0mmuw5 <<
1 , accumThree ) + 1 ) >> 1 ; } localB -> pdv5xeozmc = 0 ; b3 = true ; } else
{ localB -> cszf0mmuw5 = ( 260 - localB -> pdv5xeozmc ) * m ; if ( ( localB
-> cszf0mmuw5 > 1073741824 ) || ( localB -> cszf0mmuw5 < - 1073741824 ) ) {
done = true ; b2 = false ; } else if ( ( ( localB -> cszf0mmuw5 >= 0 ) && (
accumThree >= 0 ) ) || ( ( localB -> cszf0mmuw5 < 0 ) && ( accumThree < 0 ) )
) { accumFour += ( div_s32_floor ( localB -> cszf0mmuw5 << 1 , accumThree ) +
1 ) >> 1 ; } else { accumFour -= ( div_s32_floor ( - localB -> cszf0mmuw5 <<
1 , accumThree ) + 1 ) >> 1 ; } localB -> pdv5xeozmc = 260 ; b3 = true ; } }
else { if ( b4 ) { localB -> iu2lveaurm = acc1_idx_0 ; localB -> i4qkuytuty =
acc1_idx_2 ; } m = localB -> iu2lveaurm - accumFour ; accumThree = localB ->
i4qkuytuty - localB -> pdv5xeozmc ; if ( ( m > 1073741824 ) || ( m < -
1073741824 ) || ( ( accumThree > 1073741824 ) || ( accumThree < - 1073741824
) ) ) { done = true ; b2 = false ; b4 = true ; } else if ( ( localB ->
hrm1rndox2 & 4U ) != 0U ) { localB -> cszf0mmuw5 = - localB -> iu2lveaurm *
accumThree ; if ( ( localB -> cszf0mmuw5 > 1073741824 ) || ( localB ->
cszf0mmuw5 < - 1073741824 ) ) { done = true ; b2 = false ; } else if ( ( (
localB -> cszf0mmuw5 >= 0 ) && ( m >= 0 ) ) || ( ( localB -> cszf0mmuw5 < 0 )
&& ( m < 0 ) ) ) { localB -> i4qkuytuty += ( div_s32_floor ( localB ->
cszf0mmuw5 << 1 , m ) + 1 ) >> 1 ; } else { localB -> i4qkuytuty -= (
div_s32_floor ( - localB -> cszf0mmuw5 << 1 , m ) + 1 ) >> 1 ; } localB ->
iu2lveaurm = 0 ; b4 = true ; } else if ( ( localB -> hrm1rndox2 & 8U ) != 0U
) { localB -> cszf0mmuw5 = ( 60 - localB -> iu2lveaurm ) * accumThree ; if (
( localB -> cszf0mmuw5 > 1073741824 ) || ( localB -> cszf0mmuw5 < -
1073741824 ) ) { done = true ; b2 = false ; } else if ( ( ( localB ->
cszf0mmuw5 >= 0 ) && ( m >= 0 ) ) || ( ( localB -> cszf0mmuw5 < 0 ) && ( m <
0 ) ) ) { localB -> i4qkuytuty += ( div_s32_floor ( localB -> cszf0mmuw5 << 1
, m ) + 1 ) >> 1 ; } else { localB -> i4qkuytuty -= ( div_s32_floor ( -
localB -> cszf0mmuw5 << 1 , m ) + 1 ) >> 1 ; } localB -> iu2lveaurm = 60 ; b4
= true ; } else if ( ( localB -> hrm1rndox2 & 1U ) != 0U ) { localB ->
cszf0mmuw5 = - localB -> i4qkuytuty * m ; if ( ( localB -> cszf0mmuw5 >
1073741824 ) || ( localB -> cszf0mmuw5 < - 1073741824 ) ) { done = true ; b2
= false ; } else if ( ( ( localB -> cszf0mmuw5 >= 0 ) && ( accumThree >= 0 )
) || ( ( localB -> cszf0mmuw5 < 0 ) && ( accumThree < 0 ) ) ) { localB ->
iu2lveaurm += ( div_s32_floor ( localB -> cszf0mmuw5 << 1 , accumThree ) + 1
) >> 1 ; } else { localB -> iu2lveaurm -= ( div_s32_floor ( - localB ->
cszf0mmuw5 << 1 , accumThree ) + 1 ) >> 1 ; } localB -> i4qkuytuty = 0 ; b4 =
true ; } else { localB -> cszf0mmuw5 = ( 260 - localB -> i4qkuytuty ) * m ;
if ( ( localB -> cszf0mmuw5 > 1073741824 ) || ( localB -> cszf0mmuw5 < -
1073741824 ) ) { done = true ; b2 = false ; } else if ( ( ( localB ->
cszf0mmuw5 >= 0 ) && ( accumThree >= 0 ) ) || ( ( localB -> cszf0mmuw5 < 0 )
&& ( accumThree < 0 ) ) ) { localB -> iu2lveaurm += ( div_s32_floor ( localB
-> cszf0mmuw5 << 1 , accumThree ) + 1 ) >> 1 ; } else { localB -> iu2lveaurm
-= ( div_s32_floor ( - localB -> cszf0mmuw5 << 1 , accumThree ) + 1 ) >> 1 ;
} localB -> i4qkuytuty = 260 ; b4 = true ; } } } if ( b2 ) { if ( localB ->
iu2lveaurm >= accumFour ) { acc1_idx_0 = localB -> iu2lveaurm - accumFour ; }
else { acc1_idx_0 = accumFour - localB -> iu2lveaurm ; } if ( localB ->
i4qkuytuty >= localB -> pdv5xeozmc ) { acc1_idx_2 = localB -> i4qkuytuty -
localB -> pdv5xeozmc ; } else { acc1_idx_2 = localB -> pdv5xeozmc - localB ->
i4qkuytuty ; } if ( acc1_idx_0 > acc1_idx_2 ) { m = 1 ; localB -> cszf0mmuw5
= 61 ; } else { m = 61 ; localB -> cszf0mmuw5 = 1 ; accumThree = accumFour ;
accumFour = localB -> pdv5xeozmc ; localB -> pdv5xeozmc = accumThree ;
accumThree = localB -> iu2lveaurm ; localB -> iu2lveaurm = localB ->
i4qkuytuty ; localB -> i4qkuytuty = accumThree ; } if ( accumFour > localB ->
iu2lveaurm ) { accumThree = accumFour ; accumFour = localB -> iu2lveaurm ;
localB -> iu2lveaurm = accumThree ; accumThree = localB -> pdv5xeozmc ;
localB -> pdv5xeozmc = localB -> i4qkuytuty ; localB -> i4qkuytuty =
accumThree ; } accumThree = localB -> iu2lveaurm - accumFour ; if ( localB ->
pdv5xeozmc <= localB -> i4qkuytuty ) { localB -> dsu3yzczbs = 1 ; localB ->
f3exltnl3f = localB -> i4qkuytuty - localB -> pdv5xeozmc ; } else { localB ->
dsu3yzczbs = - 1 ; localB -> f3exltnl3f = localB -> pdv5xeozmc - localB ->
i4qkuytuty ; } localB -> i4qkuytuty = - ( ( accumThree + 1 ) >> 1 ) ; localB
-> pdv5xeozmc = accumFour * m + localB -> pdv5xeozmc * localB -> cszf0mmuw5 ;
localB -> dsu3yzczbs = localB -> dsu3yzczbs * localB -> cszf0mmuw5 + m ; done
= ( accumFour <= localB -> iu2lveaurm ) ; while ( done ) { lbljpp0upp [
localB -> pdv5xeozmc ] = MAX_uint8_T ; localB -> i4qkuytuty += localB ->
f3exltnl3f ; if ( localB -> i4qkuytuty >= 0 ) { localB -> i4qkuytuty -=
accumThree ; localB -> pdv5xeozmc += localB -> dsu3yzczbs ; } else { localB
-> pdv5xeozmc += m ; } accumFour ++ ; done = ( accumFour <= localB ->
iu2lveaurm ) ; } } } localB -> autjwaia4y ++ ; } localB -> dw40j5sber ++ ; }
} } else { accumTwo = 0 ; accumOne = 0 ; if ( ipb214pkst [ 1 ] > 1 ) {
accumOne = ipb214pkst [ 1 ] >> 1 ; done = ( accumOne << 1 == ipb214pkst [ 1 ]
) ; accumTwo = ipb214pkst [ 0 ] ; } else { if ( ipb214pkst [ 1 ] == 1 ) {
accumOne = ipb214pkst [ 0 ] >> 1 ; done = ( accumOne << 1 == ipb214pkst [ 0 ]
) ; accumTwo = 1 ; } } memcpy ( & lbljpp0upp [ 0 ] , & fayizsozht [ 0 ] ,
15921U * sizeof ( uint8_T ) ) ; if ( done && ( accumTwo > 0 ) ) { if (
at34mfr1htg . P_1 > 1 ) { localB -> iu2lveaurm = 0 ; m = accumOne << 1 ;
imgRow = ( accumOne << 2 ) - 3 ; localB -> autjwaia4y = 0 ; while ( localB ->
autjwaia4y < accumTwo ) { accumThree = dkvodhtl10 [ localB -> autjwaia4y ] -
1 ; localB -> cszf0mmuw5 = dkvodhtl10 [ localB -> autjwaia4y + accumTwo ] - 1
; localB -> f3exltnl3f = dkvodhtl10 [ ( accumTwo << 1 ) + localB ->
autjwaia4y ] - 1 ; accumFour = dkvodhtl10 [ 3 * accumTwo + localB ->
autjwaia4y ] - 1 ; localB -> i4qkuytuty = at34mfr1htg . P_1 >> 1 ; localB ->
aplsq01g4t = localB -> cszf0mmuw5 - accumFour ; localB -> gdldy4anca =
accumThree - localB -> f3exltnl3f ; if ( localB -> gdldy4anca == 0 ) {
acc1_idx_0 = 0 ; localB -> pdv5xeozmc = 1 ; acc1_idx_2 = ( accumThree -
localB -> i4qkuytuty ) << 14 ; acc1_idx_3 = ( accumThree + localB ->
i4qkuytuty ) << 14 ; acc2_idx_4 = localB -> cszf0mmuw5 << 14 ; } else if (
localB -> aplsq01g4t == 0 ) { localB -> pdv5xeozmc = 2 ; acc1_idx_0 = 0 ;
acc1_idx_2 = ( localB -> cszf0mmuw5 - localB -> i4qkuytuty ) << 14 ;
acc1_idx_3 = ( localB -> cszf0mmuw5 + localB -> i4qkuytuty ) << 14 ;
acc2_idx_4 = accumThree << 14 ; } else { localB -> pdv5xeozmc = 0 ;
acc1_idx_0 = div_s32s64_floor ( ( int64_T ) ( localB -> aplsq01g4t << 14 ) <<
14 , localB -> gdldy4anca << 14 ) ; localB -> dw40j5sber = ( localB ->
cszf0mmuw5 << 14 ) - ( int32_T ) ( ( int64_T ) ( accumThree << 14 ) *
acc1_idx_0 >> 14 ) ; localB -> f1sw2ht4n2 = div_s32s64_floor ( ( int64_T ) (
localB -> i4qkuytuty << 14 ) << 14 , div_s32s64_floor ( ( int64_T ) ( localB
-> gdldy4anca << 14 ) << 14 , rt_sqrt_Us32En14_Ys16En7_Is32En14_f_pw ( (
localB -> aplsq01g4t * localB -> aplsq01g4t + localB -> gdldy4anca * localB
-> gdldy4anca ) << 14 ) << 7 ) ) ; acc1_idx_2 = localB -> dw40j5sber + localB
-> f1sw2ht4n2 ; acc1_idx_3 = localB -> dw40j5sber - localB -> f1sw2ht4n2 ;
acc2_idx_4 = div_s32s64_floor ( ( int64_T ) ( accumThree << 14 ) << 14 ,
acc1_idx_0 ) + ( localB -> cszf0mmuw5 << 14 ) ; } if ( localB -> pdv5xeozmc
== 1 ) { localB -> aplsq01g4t = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2
>> 14 ) ; localB -> gdldy4anca = ( ( acc2_idx_4 & 8192 ) != 0 ) + (
acc2_idx_4 >> 14 ) ; localB -> bpvfku0axv = ( ( acc1_idx_3 & 8192 ) != 0 ) +
( acc1_idx_3 >> 14 ) ; localB -> f1sw2ht4n2 = ( ( acc2_idx_4 & 8192 ) != 0 )
+ ( acc2_idx_4 >> 14 ) ; } else { if ( localB -> pdv5xeozmc == 2 ) { localB
-> aplsq01g4t = ( ( acc2_idx_4 & 8192 ) != 0 ) + ( acc2_idx_4 >> 14 ) ;
localB -> gdldy4anca = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2 >> 14 )
; } else { localB -> f1sw2ht4n2 = div_s32s64_floor ( ( int64_T ) ( int32_T )
( ( int64_T ) ( acc2_idx_4 - acc1_idx_2 ) * acc1_idx_0 >> 14 ) << 14 , (
int32_T ) ( ( int64_T ) acc1_idx_0 * acc1_idx_0 >> 14 ) + 16384 ) ; localB ->
aplsq01g4t = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB ->
f1sw2ht4n2 >> 14 ) ; localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T )
acc1_idx_0 * localB -> f1sw2ht4n2 >> 14 ) + acc1_idx_2 ; localB -> gdldy4anca
= ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ;
} if ( localB -> pdv5xeozmc == 2 ) { localB -> bpvfku0axv = ( ( acc2_idx_4 &
8192 ) != 0 ) + ( acc2_idx_4 >> 14 ) ; localB -> f1sw2ht4n2 = ( ( acc1_idx_3
& 8192 ) != 0 ) + ( acc1_idx_3 >> 14 ) ; } else { localB -> f1sw2ht4n2 =
div_s32s64_floor ( ( int64_T ) ( int32_T ) ( ( int64_T ) ( acc2_idx_4 -
acc1_idx_3 ) * acc1_idx_0 >> 14 ) << 14 , ( int32_T ) ( ( int64_T )
acc1_idx_0 * acc1_idx_0 >> 14 ) + 16384 ) ; localB -> bpvfku0axv = ( ( localB
-> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; localB ->
f1sw2ht4n2 = ( int32_T ) ( ( int64_T ) acc1_idx_0 * localB -> f1sw2ht4n2 >>
14 ) + acc1_idx_3 ; localB -> f1sw2ht4n2 = ( ( localB -> f1sw2ht4n2 & 8192 )
!= 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; } } localDW -> iocj4jvjgy [ localB
-> autjwaia4y ] = localB -> aplsq01g4t ; localDW -> iocj4jvjgy [ localB ->
autjwaia4y + accumTwo ] = localB -> gdldy4anca ; localB -> dsu3yzczbs = 3 ;
localDW -> iocj4jvjgy [ localB -> autjwaia4y + ( imgRow + 2 ) * accumTwo ] =
localB -> f1sw2ht4n2 ; localDW -> iocj4jvjgy [ localB -> autjwaia4y + (
imgRow + 1 ) * accumTwo ] = localB -> bpvfku0axv ; localB -> oqjwwtnwwt =
imgRow ; if ( m == 4 ) { localB -> aplsq01g4t = localB -> cszf0mmuw5 -
accumFour ; localB -> gdldy4anca = accumThree - localB -> f3exltnl3f ; if (
localB -> gdldy4anca == 0 ) { acc1_idx_0 = 0 ; localB -> pdv5xeozmc = 1 ;
acc1_idx_2 = ( accumThree - localB -> i4qkuytuty ) << 14 ; acc1_idx_3 = (
accumThree + localB -> i4qkuytuty ) << 14 ; acc2_idx_4 = accumFour << 14 ; }
else if ( localB -> aplsq01g4t == 0 ) { localB -> pdv5xeozmc = 2 ; acc1_idx_0
= 0 ; acc1_idx_2 = ( localB -> cszf0mmuw5 - localB -> i4qkuytuty ) << 14 ;
acc1_idx_3 = ( localB -> cszf0mmuw5 + localB -> i4qkuytuty ) << 14 ;
acc2_idx_4 = localB -> f3exltnl3f << 14 ; } else { localB -> pdv5xeozmc = 0 ;
acc1_idx_0 = div_s32s64_floor ( ( int64_T ) ( localB -> aplsq01g4t << 14 ) <<
14 , localB -> gdldy4anca << 14 ) ; localB -> dw40j5sber = ( localB ->
cszf0mmuw5 << 14 ) - ( int32_T ) ( ( int64_T ) ( accumThree << 14 ) *
acc1_idx_0 >> 14 ) ; localB -> f1sw2ht4n2 = div_s32s64_floor ( ( int64_T ) (
localB -> i4qkuytuty << 14 ) << 14 , div_s32s64_floor ( ( int64_T ) ( localB
-> gdldy4anca << 14 ) << 14 , rt_sqrt_Us32En14_Ys16En7_Is32En14_f_pw ( (
localB -> aplsq01g4t * localB -> aplsq01g4t + localB -> gdldy4anca * localB
-> gdldy4anca ) << 14 ) << 7 ) ) ; acc1_idx_2 = localB -> dw40j5sber + localB
-> f1sw2ht4n2 ; acc1_idx_3 = localB -> dw40j5sber - localB -> f1sw2ht4n2 ;
acc2_idx_4 = div_s32s64_floor ( ( int64_T ) ( localB -> f3exltnl3f << 14 ) <<
14 , acc1_idx_0 ) + ( accumFour << 14 ) ; } if ( localB -> pdv5xeozmc == 1 )
{ localB -> aplsq01g4t = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2 >> 14
) ; localB -> gdldy4anca = ( ( acc2_idx_4 & 8192 ) != 0 ) + ( acc2_idx_4 >>
14 ) ; localB -> bpvfku0axv = ( ( acc1_idx_3 & 8192 ) != 0 ) + ( acc1_idx_3
>> 14 ) ; localB -> f1sw2ht4n2 = ( ( acc2_idx_4 & 8192 ) != 0 ) + (
acc2_idx_4 >> 14 ) ; } else { if ( localB -> pdv5xeozmc == 2 ) { localB ->
aplsq01g4t = ( ( acc2_idx_4 & 8192 ) != 0 ) + ( acc2_idx_4 >> 14 ) ; localB
-> gdldy4anca = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2 >> 14 ) ; }
else { localB -> f1sw2ht4n2 = div_s32s64_floor ( ( int64_T ) ( int32_T ) ( (
int64_T ) ( acc2_idx_4 - acc1_idx_2 ) * acc1_idx_0 >> 14 ) << 14 , ( int32_T
) ( ( int64_T ) acc1_idx_0 * acc1_idx_0 >> 14 ) + 16384 ) ; localB ->
aplsq01g4t = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB ->
f1sw2ht4n2 >> 14 ) ; localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T )
acc1_idx_0 * localB -> f1sw2ht4n2 >> 14 ) + acc1_idx_2 ; localB -> gdldy4anca
= ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ;
} if ( localB -> pdv5xeozmc == 2 ) { localB -> bpvfku0axv = ( ( acc2_idx_4 &
8192 ) != 0 ) + ( acc2_idx_4 >> 14 ) ; localB -> f1sw2ht4n2 = ( ( acc1_idx_3
& 8192 ) != 0 ) + ( acc1_idx_3 >> 14 ) ; } else { localB -> f1sw2ht4n2 =
div_s32s64_floor ( ( int64_T ) ( int32_T ) ( ( int64_T ) ( acc2_idx_4 -
acc1_idx_3 ) * acc1_idx_0 >> 14 ) << 14 , ( int32_T ) ( ( int64_T )
acc1_idx_0 * acc1_idx_0 >> 14 ) + 16384 ) ; localB -> bpvfku0axv = ( ( localB
-> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; localB ->
f1sw2ht4n2 = ( int32_T ) ( ( int64_T ) acc1_idx_0 * localB -> f1sw2ht4n2 >>
14 ) + acc1_idx_3 ; localB -> f1sw2ht4n2 = ( ( localB -> f1sw2ht4n2 & 8192 )
!= 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; } } localDW -> iocj4jvjgy [ localB
-> autjwaia4y + ( accumTwo << 1 ) ] = localB -> aplsq01g4t ; localDW ->
iocj4jvjgy [ localB -> autjwaia4y + 3 * accumTwo ] = localB -> gdldy4anca ;
localDW -> iocj4jvjgy [ localB -> autjwaia4y + imgRow * accumTwo ] = localB
-> f1sw2ht4n2 ; localDW -> iocj4jvjgy [ localB -> autjwaia4y + ( imgRow - 1 )
* accumTwo ] = localB -> bpvfku0axv ; } else { localB -> dw40j5sber = 4 ;
while ( localB -> dw40j5sber < m ) { if ( localB -> dw40j5sber < m ) { localB
-> iu2lveaurm = localB -> dw40j5sber ; } else { localB -> iu2lveaurm = localB
-> dw40j5sber - m ; } localB -> eievh13zkr = dkvodhtl10 [ localB ->
iu2lveaurm * accumTwo + localB -> autjwaia4y ] - 1 ; localB -> mjnb4ff24c =
dkvodhtl10 [ ( localB -> iu2lveaurm + 1 ) * accumTwo + localB -> autjwaia4y ]
- 1 ; localB -> bpvfku0axv = 0 ; if ( m - 2 == localB -> dw40j5sber ) {
localB -> bpvfku0axv = 1 ; } localB -> aplsq01g4t = accumFour - localB ->
mjnb4ff24c ; localB -> gdldy4anca = localB -> f3exltnl3f - localB ->
eievh13zkr ; acc2_idx_4 = 0 ; if ( localB -> gdldy4anca == 0 ) { acc2_idx_0 =
0 ; localB -> iu2lveaurm = 1 ; acc2_idx_2 = ( localB -> f3exltnl3f - localB
-> i4qkuytuty ) << 14 ; acc2_idx_1 = ( localB -> f3exltnl3f + localB ->
i4qkuytuty ) << 14 ; if ( localB -> bpvfku0axv != 0 ) { acc2_idx_4 = localB
-> mjnb4ff24c << 14 ; } } else if ( localB -> aplsq01g4t == 0 ) { localB ->
iu2lveaurm = 2 ; acc2_idx_0 = 0 ; acc2_idx_2 = ( accumFour - localB ->
i4qkuytuty ) << 14 ; acc2_idx_1 = ( accumFour + localB -> i4qkuytuty ) << 14
; if ( localB -> bpvfku0axv != 0 ) { acc2_idx_4 = localB -> eievh13zkr << 14
; } } else { localB -> iu2lveaurm = 0 ; acc2_idx_0 = div_s32s64_floor ( (
int64_T ) ( localB -> aplsq01g4t << 14 ) << 14 , localB -> gdldy4anca << 14 )
; acc2_idx_1 = ( accumFour << 14 ) - ( int32_T ) ( ( int64_T ) ( localB ->
f3exltnl3f << 14 ) * acc2_idx_0 >> 14 ) ; localB -> f1sw2ht4n2 =
div_s32s64_floor ( ( int64_T ) ( localB -> i4qkuytuty << 14 ) << 14 ,
div_s32s64_floor ( ( int64_T ) ( localB -> gdldy4anca << 14 ) << 14 ,
rt_sqrt_Us32En14_Ys16En7_Is32En14_f_pw ( ( localB -> aplsq01g4t * localB ->
aplsq01g4t + localB -> gdldy4anca * localB -> gdldy4anca ) << 14 ) << 7 ) ) ;
acc2_idx_2 = acc2_idx_1 + localB -> f1sw2ht4n2 ; acc2_idx_1 -= localB ->
f1sw2ht4n2 ; if ( localB -> bpvfku0axv != 0 ) { acc2_idx_4 = div_s32s64_floor
( ( int64_T ) ( localB -> eievh13zkr << 14 ) << 14 , acc2_idx_0 ) + ( localB
-> mjnb4ff24c << 14 ) ; } } if ( localB -> pdv5xeozmc == 1 ) { localB ->
aplsq01g4t = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2 >> 14 ) ; localB
-> gdldy4anca = localB -> cszf0mmuw5 ; } else if ( localB -> pdv5xeozmc == 2
) { localB -> aplsq01g4t = accumThree ; localB -> gdldy4anca = ( ( acc1_idx_2
& 8192 ) != 0 ) + ( acc1_idx_2 >> 14 ) ; } else { localB -> aplsq01g4t = 0 ;
localB -> gdldy4anca = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2 >> 14 )
; } localB -> bpvfku0axv = ( localB -> f3exltnl3f - accumThree ) * ( localB
-> gdldy4anca - localB -> cszf0mmuw5 ) - ( localB -> aplsq01g4t - accumThree
) * ( accumFour - localB -> cszf0mmuw5 ) ; if ( localB -> iu2lveaurm == 1 ) {
localB -> f1sw2ht4n2 = ( ( acc2_idx_2 & 8192 ) != 0 ) + ( acc2_idx_2 >> 14 )
; localB -> k3ccqdz51e = localB -> cszf0mmuw5 ; } else if ( localB ->
iu2lveaurm == 2 ) { localB -> f1sw2ht4n2 = accumThree ; localB -> k3ccqdz51e
= ( ( acc2_idx_2 & 8192 ) != 0 ) + ( acc2_idx_2 >> 14 ) ; } else { localB ->
f1sw2ht4n2 = 0 ; localB -> k3ccqdz51e = ( ( acc2_idx_2 & 8192 ) != 0 ) + (
acc2_idx_2 >> 14 ) ; } localB -> erpgnv3z3v = ( localB -> eievh13zkr - localB
-> f3exltnl3f ) * ( localB -> k3ccqdz51e - accumFour ) - ( localB ->
f1sw2ht4n2 - localB -> f3exltnl3f ) * ( localB -> mjnb4ff24c - accumFour ) ;
if ( ( ( localB -> bpvfku0axv < 0 ) || ( ( ! ( localB -> bpvfku0axv > 0 ) )
&& ( ( localB -> f3exltnl3f - accumThree ) * ( localB -> f3exltnl3f -
accumThree ) + ( accumFour - localB -> cszf0mmuw5 ) * ( accumFour - localB ->
cszf0mmuw5 ) > ( localB -> aplsq01g4t - accumThree ) * ( localB -> aplsq01g4t
- accumThree ) + ( localB -> gdldy4anca - localB -> cszf0mmuw5 ) * ( localB
-> gdldy4anca - localB -> cszf0mmuw5 ) ) ) ) != ( ( localB -> erpgnv3z3v < 0
) || ( ( ! ( localB -> erpgnv3z3v > 0 ) ) && ( ( localB -> eievh13zkr -
localB -> f3exltnl3f ) * ( localB -> eievh13zkr - localB -> f3exltnl3f ) + (
localB -> mjnb4ff24c - accumFour ) * ( localB -> mjnb4ff24c - accumFour ) > (
localB -> f1sw2ht4n2 - localB -> f3exltnl3f ) * ( localB -> f1sw2ht4n2 -
localB -> f3exltnl3f ) + ( localB -> k3ccqdz51e - accumFour ) * ( localB ->
k3ccqdz51e - accumFour ) ) ) ) ) { accumThree = acc2_idx_2 ; acc2_idx_2 =
acc2_idx_1 ; acc2_idx_1 = accumThree ; } done = false ; if ( localB ->
pdv5xeozmc == 1 ) { done = true ; } b2 = false ; if ( localB -> iu2lveaurm ==
1 ) { b2 = true ; } if ( done && b2 ) { localB -> aplsq01g4t = ( ( acc1_idx_2
& 8192 ) != 0 ) + ( acc1_idx_2 >> 14 ) ; localB -> gdldy4anca = accumFour ; }
else if ( done ) { localB -> aplsq01g4t = ( ( acc1_idx_2 & 8192 ) != 0 ) + (
acc1_idx_2 >> 14 ) ; localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T ) (
localB -> aplsq01g4t << 14 ) * acc2_idx_0 >> 14 ) + acc2_idx_2 ; localB ->
gdldy4anca = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB ->
f1sw2ht4n2 >> 14 ) ; } else if ( b2 ) { localB -> aplsq01g4t = ( ( acc2_idx_2
& 8192 ) != 0 ) + ( acc2_idx_2 >> 14 ) ; localB -> f1sw2ht4n2 = ( int32_T ) (
( int64_T ) ( localB -> aplsq01g4t << 14 ) * acc1_idx_0 >> 14 ) + acc1_idx_2
; localB -> gdldy4anca = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB
-> f1sw2ht4n2 >> 14 ) ; } else { localB -> f1sw2ht4n2 = acc1_idx_0 -
acc2_idx_0 ; if ( localB -> f1sw2ht4n2 == 0 ) { localB -> aplsq01g4t = localB
-> f3exltnl3f ; localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T ) ( localB ->
f3exltnl3f << 14 ) * acc1_idx_0 >> 14 ) + acc1_idx_2 ; localB -> gdldy4anca =
( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; }
else { localB -> f1sw2ht4n2 = div_s32s64_floor ( ( int64_T ) ( acc2_idx_2 -
acc1_idx_2 ) << 14 , localB -> f1sw2ht4n2 ) ; localB -> aplsq01g4t = ( (
localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ;
localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T ) acc1_idx_0 * localB ->
f1sw2ht4n2 >> 14 ) + acc1_idx_2 ; localB -> gdldy4anca = ( ( localB ->
f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; } } done =
false ; if ( localB -> pdv5xeozmc == 1 ) { done = true ; } b2 = false ; if (
localB -> iu2lveaurm == 1 ) { b2 = true ; } if ( done && b2 ) { localB ->
bpvfku0axv = ( ( acc1_idx_3 & 8192 ) != 0 ) + ( acc1_idx_3 >> 14 ) ; localB
-> f1sw2ht4n2 = accumFour ; } else if ( done ) { localB -> bpvfku0axv = ( (
acc1_idx_3 & 8192 ) != 0 ) + ( acc1_idx_3 >> 14 ) ; localB -> f1sw2ht4n2 = (
int32_T ) ( ( int64_T ) ( localB -> bpvfku0axv << 14 ) * acc2_idx_0 >> 14 ) +
acc2_idx_1 ; localB -> f1sw2ht4n2 = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 )
+ ( localB -> f1sw2ht4n2 >> 14 ) ; } else if ( b2 ) { localB -> bpvfku0axv =
( ( acc2_idx_1 & 8192 ) != 0 ) + ( acc2_idx_1 >> 14 ) ; localB -> f1sw2ht4n2
= ( int32_T ) ( ( int64_T ) ( localB -> bpvfku0axv << 14 ) * acc1_idx_0 >> 14
) + acc1_idx_3 ; localB -> f1sw2ht4n2 = ( ( localB -> f1sw2ht4n2 & 8192 ) !=
0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; } else { localB -> f1sw2ht4n2 =
acc1_idx_0 - acc2_idx_0 ; if ( localB -> f1sw2ht4n2 == 0 ) { localB ->
bpvfku0axv = localB -> f3exltnl3f ; localB -> f1sw2ht4n2 = ( int32_T ) ( (
int64_T ) ( localB -> f3exltnl3f << 14 ) * acc1_idx_0 >> 14 ) + acc1_idx_3 ;
localB -> f1sw2ht4n2 = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB ->
f1sw2ht4n2 >> 14 ) ; } else { localB -> f1sw2ht4n2 = div_s32s64_floor ( (
int64_T ) ( acc2_idx_1 - acc1_idx_3 ) << 14 , localB -> f1sw2ht4n2 ) ; localB
-> bpvfku0axv = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB ->
f1sw2ht4n2 >> 14 ) ; localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T )
acc1_idx_0 * localB -> f1sw2ht4n2 >> 14 ) + acc1_idx_3 ; localB -> f1sw2ht4n2
= ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ;
} } localDW -> iocj4jvjgy [ localB -> autjwaia4y + ( localB -> dsu3yzczbs - 1
) * accumTwo ] = localB -> aplsq01g4t ; localDW -> iocj4jvjgy [ localB ->
autjwaia4y + localB -> dsu3yzczbs * accumTwo ] = localB -> gdldy4anca ;
localB -> dsu3yzczbs += 2 ; localDW -> iocj4jvjgy [ localB -> autjwaia4y +
localB -> oqjwwtnwwt * accumTwo ] = localB -> f1sw2ht4n2 ; localB ->
oqjwwtnwwt -= 2 ; localDW -> iocj4jvjgy [ localB -> autjwaia4y + ( localB ->
oqjwwtnwwt + 1 ) * accumTwo ] = localB -> bpvfku0axv ; accumThree = localB ->
f3exltnl3f ; localB -> cszf0mmuw5 = accumFour ; localB -> f3exltnl3f = localB
-> eievh13zkr ; accumFour = localB -> mjnb4ff24c ; acc1_idx_0 = acc2_idx_0 ;
acc1_idx_2 = acc2_idx_2 ; acc1_idx_3 = acc2_idx_1 ; localB -> pdv5xeozmc =
localB -> iu2lveaurm ; localB -> dw40j5sber += 2 ; } if ( localB ->
iu2lveaurm == 1 ) { localB -> aplsq01g4t = ( ( acc1_idx_2 & 8192 ) != 0 ) + (
acc1_idx_2 >> 14 ) ; localB -> gdldy4anca = ( ( acc2_idx_4 & 8192 ) != 0 ) +
( acc2_idx_4 >> 14 ) ; localB -> bpvfku0axv = ( ( acc1_idx_3 & 8192 ) != 0 )
+ ( acc1_idx_3 >> 14 ) ; localB -> f1sw2ht4n2 = ( ( acc2_idx_4 & 8192 ) != 0
) + ( acc2_idx_4 >> 14 ) ; } else { if ( localB -> iu2lveaurm == 2 ) { localB
-> aplsq01g4t = ( ( acc2_idx_4 & 8192 ) != 0 ) + ( acc2_idx_4 >> 14 ) ;
localB -> gdldy4anca = ( ( acc1_idx_2 & 8192 ) != 0 ) + ( acc1_idx_2 >> 14 )
; } else { localB -> f1sw2ht4n2 = div_s32s64_floor ( ( int64_T ) ( int32_T )
( ( int64_T ) ( acc2_idx_4 - acc1_idx_2 ) * acc1_idx_0 >> 14 ) << 14 , (
int32_T ) ( ( int64_T ) acc1_idx_0 * acc1_idx_0 >> 14 ) + 16384 ) ; localB ->
aplsq01g4t = ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB ->
f1sw2ht4n2 >> 14 ) ; localB -> f1sw2ht4n2 = ( int32_T ) ( ( int64_T )
acc1_idx_0 * localB -> f1sw2ht4n2 >> 14 ) + acc1_idx_2 ; localB -> gdldy4anca
= ( ( localB -> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ;
} if ( localB -> iu2lveaurm == 2 ) { localB -> bpvfku0axv = ( ( acc2_idx_4 &
8192 ) != 0 ) + ( acc2_idx_4 >> 14 ) ; localB -> f1sw2ht4n2 = ( ( acc1_idx_3
& 8192 ) != 0 ) + ( acc1_idx_3 >> 14 ) ; } else { localB -> f1sw2ht4n2 =
div_s32s64_floor ( ( int64_T ) ( int32_T ) ( ( int64_T ) ( acc2_idx_4 -
acc1_idx_3 ) * acc1_idx_0 >> 14 ) << 14 , ( int32_T ) ( ( int64_T )
acc1_idx_0 * acc1_idx_0 >> 14 ) + 16384 ) ; localB -> bpvfku0axv = ( ( localB
-> f1sw2ht4n2 & 8192 ) != 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; localB ->
f1sw2ht4n2 = ( int32_T ) ( ( int64_T ) acc1_idx_0 * localB -> f1sw2ht4n2 >>
14 ) + acc1_idx_3 ; localB -> f1sw2ht4n2 = ( ( localB -> f1sw2ht4n2 & 8192 )
!= 0 ) + ( localB -> f1sw2ht4n2 >> 14 ) ; } } localDW -> iocj4jvjgy [ localB
-> autjwaia4y + ( localB -> dsu3yzczbs - 1 ) * accumTwo ] = localB ->
aplsq01g4t ; localDW -> iocj4jvjgy [ localB -> autjwaia4y + localB ->
dsu3yzczbs * accumTwo ] = localB -> gdldy4anca ; localDW -> iocj4jvjgy [
localB -> autjwaia4y + localB -> oqjwwtnwwt * accumTwo ] = localB ->
f1sw2ht4n2 ; localDW -> iocj4jvjgy [ localB -> autjwaia4y + ( localB ->
oqjwwtnwwt - 1 ) * accumTwo ] = localB -> bpvfku0axv ; } localB -> autjwaia4y
++ ; } accumOne <<= 1 ; } imgRow = accumTwo * accumOne ; localB -> autjwaia4y
= 0 ; accumThree = 0 ; b2 = ( 0 < accumTwo * accumOne * 9 ) ; while ( b2 ) {
done = false ; localB -> cszf0mmuw5 = 0 ; localB -> i4qkuytuty = localB ->
autjwaia4y ; localB -> pdv5xeozmc = localB -> autjwaia4y ; localB ->
mjqwh0sluc [ 0U ] = accumOne - 1 ; localB -> dw40j5sber = 0 ; while ( localB
-> dw40j5sber < 1 ) { localB -> dsu3yzczbs = ( ( localB -> mjqwh0sluc [ 0 ]
<< 1 ) + 1 ) * accumTwo + accumThree ; localB -> oqjwwtnwwt = ( localB ->
mjqwh0sluc [ 0 ] << 1 ) * accumTwo + accumThree ; localB -> bpvfku0axv =
localB -> mjqwh0sluc [ 0 ] ; localB -> eievh13zkr = ( ( localB -> mjqwh0sluc
[ 0 ] - 1 ) << 1 ) * accumTwo + accumThree ; localB -> iu2lveaurm = accumOne
; if ( at34mfr1htg . P_1 > 1 ) { localB -> mjnb4ff24c = localDW -> iocj4jvjgy
[ localB -> oqjwwtnwwt ] ; localB -> aplsq01g4t = localDW -> iocj4jvjgy [
localB -> eievh13zkr ] ; } else { localB -> mjnb4ff24c = dkvodhtl10 [ localB
-> oqjwwtnwwt ] ; localB -> aplsq01g4t = dkvodhtl10 [ localB -> eievh13zkr ]
; } m = localB -> aplsq01g4t ; while ( ( localB -> eievh13zkr >= 0 ) && (
localB -> mjnb4ff24c - 1 == m - 1 ) ) { localB -> bpvfku0axv -- ; localB ->
eievh13zkr = ( ( localB -> bpvfku0axv - 1 ) << 1 ) * accumTwo + accumThree ;
localB -> iu2lveaurm -- ; if ( at34mfr1htg . P_1 > 1 ) { localB -> aplsq01g4t
= localDW -> iocj4jvjgy [ localB -> eievh13zkr ] ; } else { localB ->
aplsq01g4t = dkvodhtl10 [ localB -> eievh13zkr ] ; } m = localB -> aplsq01g4t
; } if ( localB -> eievh13zkr < 0 ) { localB -> eievh13zkr = 0 ; } if (
at34mfr1htg . P_1 > 1 ) { localB -> mjnb4ff24c = localDW -> iocj4jvjgy [
localB -> oqjwwtnwwt ] ; localB -> aplsq01g4t = localDW -> iocj4jvjgy [
localB -> eievh13zkr ] ; } else { localB -> mjnb4ff24c = dkvodhtl10 [ localB
-> oqjwwtnwwt ] ; localB -> aplsq01g4t = dkvodhtl10 [ localB -> eievh13zkr ]
; } b2 = ( localB -> aplsq01g4t - 1 > localB -> mjnb4ff24c - 1 ) ; localB ->
gdldy4anca = accumTwo + accumThree ; localB -> eievh13zkr = accumThree ; b4 =
false ; if ( at34mfr1htg . P_1 > 1 ) { localB -> mjnb4ff24c = localDW ->
iocj4jvjgy [ accumThree ] ; localB -> aplsq01g4t = localDW -> iocj4jvjgy [
localB -> oqjwwtnwwt ] ; } else { localB -> mjnb4ff24c = dkvodhtl10 [
accumThree ] ; localB -> aplsq01g4t = dkvodhtl10 [ localB -> oqjwwtnwwt ] ; }
done = ( localB -> aplsq01g4t - 1 == localB -> mjnb4ff24c - 1 ) ; for ( m = 0
; m < localB -> iu2lveaurm ; m ++ ) { if ( at34mfr1htg . P_1 > 1 ) { localB
-> mjnb4ff24c = localDW -> iocj4jvjgy [ localB -> eievh13zkr ] ; localB ->
aplsq01g4t = localDW -> iocj4jvjgy [ localB -> oqjwwtnwwt ] ; } else { localB
-> mjnb4ff24c = dkvodhtl10 [ localB -> eievh13zkr ] ; localB -> aplsq01g4t =
dkvodhtl10 [ localB -> oqjwwtnwwt ] ; } if ( localB -> aplsq01g4t - 1 !=
localB -> mjnb4ff24c - 1 ) { if ( at34mfr1htg . P_1 > 1 ) { localB ->
mjnb4ff24c = localDW -> iocj4jvjgy [ localB -> eievh13zkr ] ; localB ->
aplsq01g4t = localDW -> iocj4jvjgy [ localB -> oqjwwtnwwt ] ; } else { localB
-> mjnb4ff24c = dkvodhtl10 [ localB -> eievh13zkr ] ; localB -> aplsq01g4t =
dkvodhtl10 [ localB -> oqjwwtnwwt ] ; } if ( localB -> aplsq01g4t - 1 <
localB -> mjnb4ff24c - 1 ) { b3 = false ; } else { b3 = true ; localB ->
bpvfku0axv = localB -> dsu3yzczbs ; localB -> dsu3yzczbs = localB ->
gdldy4anca ; localB -> gdldy4anca = localB -> bpvfku0axv ; localB ->
bpvfku0axv = localB -> oqjwwtnwwt ; localB -> oqjwwtnwwt = localB ->
eievh13zkr ; localB -> eievh13zkr = localB -> bpvfku0axv ; } if ( at34mfr1htg
. P_1 > 1 ) { localB -> mjnb4ff24c = localDW -> iocj4jvjgy [ localB ->
eievh13zkr ] ; localB -> aplsq01g4t = localDW -> iocj4jvjgy [ localB ->
gdldy4anca ] ; localB -> bpvfku0axv = localDW -> iocj4jvjgy [ localB ->
oqjwwtnwwt ] ; localB -> f1sw2ht4n2 = localDW -> iocj4jvjgy [ localB ->
dsu3yzczbs ] ; } else { localB -> mjnb4ff24c = dkvodhtl10 [ localB ->
eievh13zkr ] ; localB -> aplsq01g4t = dkvodhtl10 [ localB -> gdldy4anca ] ;
localB -> bpvfku0axv = dkvodhtl10 [ localB -> oqjwwtnwwt ] ; localB ->
f1sw2ht4n2 = dkvodhtl10 [ localB -> dsu3yzczbs ] ; } localB -> k3ccqdz51e =
localB -> mjnb4ff24c - localB -> bpvfku0axv ; localDW -> gv5pvc5nnd [ localB
-> pdv5xeozmc ] = 0 ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 1 ] =
localB -> f1sw2ht4n2 - 1 ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 2 ]
= localB -> bpvfku0axv - 1 ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 3
] = localB -> mjnb4ff24c - 1 ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc +
6 ] = 0 ; if ( localB -> aplsq01g4t - 1 >= localB -> f1sw2ht4n2 - 1 ) {
localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 8 ] = localB -> aplsq01g4t -
localB -> f1sw2ht4n2 ; } else { localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc
+ 8 ] = localB -> f1sw2ht4n2 - localB -> aplsq01g4t ; } while ( localDW ->
gv5pvc5nnd [ localB -> pdv5xeozmc + 8 ] >= 0 ) { localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 6 ] ++ ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc
+ 8 ] -= localB -> k3ccqdz51e ; } localDW -> gv5pvc5nnd [ localB ->
pdv5xeozmc + 5 ] = localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 6 ] - 1 ;
localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 7 ] = localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 8 ] + localB -> k3ccqdz51e ; localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 4 ] = localB -> k3ccqdz51e - ( localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 7 ] << 1 ) ; if ( localB -> f1sw2ht4n2 - 1 > localB ->
aplsq01g4t - 1 ) { localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 5 ] = -
localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 5 ] ; localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 6 ] = - localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc +
6 ] ; } if ( ( ! b2 ) && ( ! b3 ) ) { localDW -> gv5pvc5nnd [ localB ->
pdv5xeozmc + 2 ] ++ ; if ( ( localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc ]
<< 1 ) > localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 4 ] ) { localDW ->
gv5pvc5nnd [ localB -> pdv5xeozmc ] += localDW -> gv5pvc5nnd [ localB ->
pdv5xeozmc + 8 ] ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 1 ] +=
localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 6 ] ; } else { localDW ->
gv5pvc5nnd [ localB -> pdv5xeozmc ] += localDW -> gv5pvc5nnd [ localB ->
pdv5xeozmc + 7 ] ; localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 1 ] +=
localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 5 ] ; } } else { if ( b2 && b3
) { localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 3 ] -- ; } } b2 = b3 ; if
( ! b4 ) { if ( ( localB -> i4qkuytuty != localB -> pdv5xeozmc ) && ( (
localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 5 ] == localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 5 ] ) && ( localDW -> gv5pvc5nnd [ localB ->
i4qkuytuty + 6 ] == localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 6 ] ) && (
localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 7 ] == localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 7 ] ) && ( localDW -> gv5pvc5nnd [ localB ->
i4qkuytuty + 8 ] == localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 8 ] ) ) )
{ if ( localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 3 ] + 1 == localDW ->
gv5pvc5nnd [ localB -> pdv5xeozmc + 2 ] ) { localDW -> gv5pvc5nnd [ localB ->
i4qkuytuty + 3 ] = localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 3 ] ; b4 =
true ; } else { if ( localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 3 ] + 1
== localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 2 ] ) { localDW ->
gv5pvc5nnd [ localB -> i4qkuytuty + 1 ] = localDW -> gv5pvc5nnd [ localB ->
pdv5xeozmc + 1 ] ; localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 2 ] =
localDW -> gv5pvc5nnd [ localB -> pdv5xeozmc + 2 ] ; b4 = true ; } } } if ( !
b4 ) { localB -> i4qkuytuty = localB -> pdv5xeozmc ; localB -> cszf0mmuw5 ++
; } } else { localB -> i4qkuytuty = localB -> pdv5xeozmc ; localB ->
cszf0mmuw5 ++ ; } localB -> pdv5xeozmc = localB -> i4qkuytuty + 9 ; if ( ! b3
) { localB -> dsu3yzczbs = localB -> gdldy4anca ; localB -> oqjwwtnwwt =
localB -> eievh13zkr ; } localB -> gdldy4anca = ( accumTwo << 1 ) + localB ->
dsu3yzczbs ; localB -> eievh13zkr = ( accumTwo << 1 ) + localB -> oqjwwtnwwt
; b4 = false ; } else { b4 = true ; localB -> dsu3yzczbs = localB ->
gdldy4anca ; localB -> oqjwwtnwwt = localB -> eievh13zkr ; localB ->
gdldy4anca += accumTwo << 1 ; localB -> eievh13zkr += accumTwo << 1 ; } }
localB -> dw40j5sber = 1 ; } if ( ! done ) { if ( ( localB -> autjwaia4y !=
localB -> i4qkuytuty ) && ( ( localDW -> gv5pvc5nnd [ localB -> autjwaia4y +
5 ] == localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 5 ] ) && ( localDW ->
gv5pvc5nnd [ localB -> autjwaia4y + 6 ] == localDW -> gv5pvc5nnd [ localB ->
i4qkuytuty + 6 ] ) && ( localDW -> gv5pvc5nnd [ localB -> autjwaia4y + 7 ] ==
localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 7 ] ) && ( localDW ->
gv5pvc5nnd [ localB -> autjwaia4y + 8 ] == localDW -> gv5pvc5nnd [ localB ->
i4qkuytuty + 8 ] ) ) ) { if ( localDW -> gv5pvc5nnd [ localB -> autjwaia4y +
3 ] + 1 == localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 2 ] ) { localDW ->
gv5pvc5nnd [ localB -> autjwaia4y + 3 ] = localDW -> gv5pvc5nnd [ localB ->
i4qkuytuty + 3 ] ; done = true ; } else { if ( localDW -> gv5pvc5nnd [ localB
-> i4qkuytuty + 3 ] + 1 == localDW -> gv5pvc5nnd [ localB -> autjwaia4y + 2 ]
) { localDW -> gv5pvc5nnd [ localB -> autjwaia4y + 1 ] = localDW ->
gv5pvc5nnd [ localB -> i4qkuytuty + 1 ] ; localDW -> gv5pvc5nnd [ localB ->
autjwaia4y + 2 ] = localDW -> gv5pvc5nnd [ localB -> i4qkuytuty + 2 ] ; done
= true ; } } } if ( done ) { localB -> cszf0mmuw5 -- ; localB -> pdv5xeozmc
-= 9 ; } } for ( m = localB -> cszf0mmuw5 ; m < accumOne ; m ++ ) { localDW
-> gv5pvc5nnd [ localB -> pdv5xeozmc + 2 ] = 1 ; localDW -> gv5pvc5nnd [
localB -> pdv5xeozmc + 3 ] = 0 ; localB -> pdv5xeozmc += 9 ; } b2 = true ;
while ( b2 ) { localB -> gdldy4anca = localB -> autjwaia4y ; localB ->
bpvfku0axv = localB -> autjwaia4y + 9 ; b2 = false ; for ( m = 1 ; m < localB
-> cszf0mmuw5 ; m ++ ) { if ( localDW -> gv5pvc5nnd [ localB -> gdldy4anca +
2 ] > localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 2 ] ) { b2 = true ; for
( localB -> iu2lveaurm = 0 ; localB -> iu2lveaurm < 9 ; localB -> iu2lveaurm
++ ) { localB -> f1sw2ht4n2 = localDW -> gv5pvc5nnd [ localB -> gdldy4anca +
localB -> iu2lveaurm ] ; localDW -> gv5pvc5nnd [ localB -> gdldy4anca +
localB -> iu2lveaurm ] = localDW -> gv5pvc5nnd [ localB -> bpvfku0axv +
localB -> iu2lveaurm ] ; localDW -> gv5pvc5nnd [ localB -> bpvfku0axv +
localB -> iu2lveaurm ] = localB -> f1sw2ht4n2 ; } } localB -> gdldy4anca =
localB -> bpvfku0axv ; localB -> bpvfku0axv += 9 ; } } localB -> iu2lveaurm =
localB -> autjwaia4y + 3 ; localB -> dw40j5sber = localDW -> gv5pvc5nnd [
localB -> autjwaia4y + 3 ] ; for ( m = 1 ; m < localB -> cszf0mmuw5 ; m ++ )
{ localB -> iu2lveaurm += 9 ; if ( localB -> dw40j5sber < localDW ->
gv5pvc5nnd [ localB -> iu2lveaurm ] ) { localB -> dw40j5sber = localDW ->
gv5pvc5nnd [ localB -> iu2lveaurm ] ; } } localB -> f3exltnl3f = localB ->
dw40j5sber ; if ( localB -> dw40j5sber > 260 ) { localB -> f3exltnl3f = 260 ;
} localB -> iu2lveaurm = localB -> autjwaia4y + 2 ; localB -> dw40j5sber =
localDW -> gv5pvc5nnd [ localB -> autjwaia4y + 2 ] ; for ( m = 1 ; m < localB
-> cszf0mmuw5 ; m ++ ) { localB -> iu2lveaurm += 9 ; if ( localB ->
dw40j5sber > localDW -> gv5pvc5nnd [ localB -> iu2lveaurm ] ) { localB ->
dw40j5sber = localDW -> gv5pvc5nnd [ localB -> iu2lveaurm ] ; } } if ( localB
-> dw40j5sber < 0 ) { localB -> dw40j5sber = 0 ; } localB -> gdldy4anca =
localB -> autjwaia4y ; localB -> bpvfku0axv = localB -> autjwaia4y ;
accumFour = localB -> autjwaia4y ; localB -> i4qkuytuty = 0 ; localB ->
aplsq01g4t = 0 ; for ( m = 0 ; m < localB -> cszf0mmuw5 ; m ++ ) { if (
localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 3 ] >= localB -> dw40j5sber )
{ if ( localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 2 ] <= localB ->
dw40j5sber ) { while ( localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 2 ] <
localB -> dw40j5sber ) { localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 2 ]
++ ; if ( ( localDW -> gv5pvc5nnd [ localB -> bpvfku0axv ] << 1 ) > localDW
-> gv5pvc5nnd [ localB -> bpvfku0axv + 4 ] ) { localDW -> gv5pvc5nnd [ localB
-> bpvfku0axv ] += localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 8 ] ;
localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 1 ] += localDW -> gv5pvc5nnd [
localB -> bpvfku0axv + 6 ] ; } else { localDW -> gv5pvc5nnd [ localB ->
bpvfku0axv ] += localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 7 ] ; localDW
-> gv5pvc5nnd [ localB -> bpvfku0axv + 1 ] += localDW -> gv5pvc5nnd [ localB
-> bpvfku0axv + 5 ] ; } } accumFour += 9 ; localB -> aplsq01g4t ++ ; } if (
localB -> bpvfku0axv != localB -> gdldy4anca ) { for ( localB -> iu2lveaurm =
0 ; localB -> iu2lveaurm < 9 ; localB -> iu2lveaurm ++ ) { localDW ->
gv5pvc5nnd [ localB -> gdldy4anca + localB -> iu2lveaurm ] = localDW ->
gv5pvc5nnd [ localB -> bpvfku0axv + localB -> iu2lveaurm ] ; } } localB ->
gdldy4anca += 9 ; localB -> i4qkuytuty ++ ; } localB -> bpvfku0axv += 9 ; }
b2 = true ; while ( b2 ) { localB -> gdldy4anca = localB -> autjwaia4y ;
localB -> bpvfku0axv = localB -> autjwaia4y + 9 ; b2 = false ; for ( m = 1 ;
m < localB -> aplsq01g4t ; m ++ ) { if ( localDW -> gv5pvc5nnd [ localB ->
gdldy4anca + 1 ] > localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 1 ] ) { b2
= true ; for ( localB -> iu2lveaurm = 0 ; localB -> iu2lveaurm < 9 ; localB
-> iu2lveaurm ++ ) { localB -> f1sw2ht4n2 = localDW -> gv5pvc5nnd [ localB ->
gdldy4anca + localB -> iu2lveaurm ] ; localDW -> gv5pvc5nnd [ localB ->
gdldy4anca + localB -> iu2lveaurm ] = localDW -> gv5pvc5nnd [ localB ->
bpvfku0axv + localB -> iu2lveaurm ] ; localDW -> gv5pvc5nnd [ localB ->
bpvfku0axv + localB -> iu2lveaurm ] = localB -> f1sw2ht4n2 ; } } localB ->
gdldy4anca = localB -> bpvfku0axv ; localB -> bpvfku0axv += 9 ; } } localB ->
aplsq01g4t = localB -> autjwaia4y ; localB -> pdv5xeozmc = localB ->
dw40j5sber + 1 ; localB -> dsu3yzczbs = 0 ; localB -> gdldy4anca = 0 ; localB
-> bpvfku0axv = - 1 ; b2 = ( 0 <= localB -> f3exltnl3f ) ; while ( b2 ) { b3
= false ; done = ( localB -> gdldy4anca != 0 ) ; localB -> mjnb4ff24c =
localB -> dsu3yzczbs ; if ( ( localB -> dsu3yzczbs >= localB -> dw40j5sber )
&& ( localB -> dsu3yzczbs <= localB -> f3exltnl3f ) ) { if ( localB ->
aplsq01g4t < accumFour ) { m = localDW -> gv5pvc5nnd [ localB -> aplsq01g4t +
1 ] ; localB -> aplsq01g4t += 9 ; if ( ( m == localB -> bpvfku0axv ) && (
localB -> aplsq01g4t < accumFour ) ) { localB -> cszf0mmuw5 = localDW ->
gv5pvc5nnd [ localB -> aplsq01g4t + 1 ] ; b2 = ( localB -> aplsq01g4t <
accumFour ) ; while ( b2 && ( m == localB -> cszf0mmuw5 ) ) { b3 = true ; m =
localDW -> gv5pvc5nnd [ localB -> aplsq01g4t + 1 ] ; localB -> aplsq01g4t +=
9 ; b2 = ( localB -> aplsq01g4t < accumFour ) ; if ( b2 ) { localB ->
cszf0mmuw5 = localDW -> gv5pvc5nnd [ localB -> aplsq01g4t + 1 ] ; } } if ( !
b2 ) { b3 = false ; } } if ( localB -> gdldy4anca != 0 ) { localB ->
oqjwwtnwwt = localB -> bpvfku0axv ; if ( m <= 60 ) { localB -> eievh13zkr = m
; localB -> bpvfku0axv = m ; } else { localB -> eievh13zkr = 60 ; localB ->
bpvfku0axv = 60 ; } } else { localB -> oqjwwtnwwt = localB -> bpvfku0axv + 1
; if ( ( m > 0 ) && ( m <= 60 ) ) { localB -> eievh13zkr = m - 1 ; localB ->
bpvfku0axv = m ; } else if ( m <= 0 ) { localB -> eievh13zkr = - 1 ; localB
-> bpvfku0axv = 0 ; } else { localB -> eievh13zkr = 60 ; localB -> bpvfku0axv
= 61 ; } } if ( ! b3 ) { localB -> gdldy4anca = ! ( localB -> gdldy4anca != 0
) ; } } else { done = false ; localB -> oqjwwtnwwt = localB -> bpvfku0axv + 1
; localB -> eievh13zkr = 60 ; localB -> gdldy4anca = localB -> autjwaia4y ;
localB -> bpvfku0axv = localB -> autjwaia4y ; accumFour = localB ->
autjwaia4y ; localB -> cszf0mmuw5 = 0 ; localB -> aplsq01g4t = 0 ; for ( m =
0 ; m < localB -> i4qkuytuty ; m ++ ) { if ( localDW -> gv5pvc5nnd [ localB
-> bpvfku0axv + 3 ] >= localB -> pdv5xeozmc ) { if ( localDW -> gv5pvc5nnd [
localB -> bpvfku0axv + 2 ] <= localB -> pdv5xeozmc ) { while ( localDW ->
gv5pvc5nnd [ localB -> bpvfku0axv + 2 ] < localB -> pdv5xeozmc ) { localDW ->
gv5pvc5nnd [ localB -> bpvfku0axv + 2 ] ++ ; if ( ( localDW -> gv5pvc5nnd [
localB -> bpvfku0axv ] << 1 ) > localDW -> gv5pvc5nnd [ localB -> bpvfku0axv
+ 4 ] ) { localDW -> gv5pvc5nnd [ localB -> bpvfku0axv ] += localDW ->
gv5pvc5nnd [ localB -> bpvfku0axv + 8 ] ; localDW -> gv5pvc5nnd [ localB ->
bpvfku0axv + 1 ] += localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 6 ] ; }
else { localDW -> gv5pvc5nnd [ localB -> bpvfku0axv ] += localDW ->
gv5pvc5nnd [ localB -> bpvfku0axv + 7 ] ; localDW -> gv5pvc5nnd [ localB ->
bpvfku0axv + 1 ] += localDW -> gv5pvc5nnd [ localB -> bpvfku0axv + 5 ] ; } }
accumFour += 9 ; localB -> aplsq01g4t ++ ; } if ( localB -> bpvfku0axv !=
localB -> gdldy4anca ) { for ( localB -> iu2lveaurm = 0 ; localB ->
iu2lveaurm < 9 ; localB -> iu2lveaurm ++ ) { localDW -> gv5pvc5nnd [ localB
-> gdldy4anca + localB -> iu2lveaurm ] = localDW -> gv5pvc5nnd [ localB ->
bpvfku0axv + localB -> iu2lveaurm ] ; } } localB -> gdldy4anca += 9 ; localB
-> cszf0mmuw5 ++ ; } localB -> bpvfku0axv += 9 ; } localB -> i4qkuytuty =
localB -> cszf0mmuw5 ; while ( b2 ) { localB -> gdldy4anca = localB ->
autjwaia4y ; localB -> bpvfku0axv = localB -> autjwaia4y + 9 ; b2 = false ;
for ( m = 1 ; m < localB -> aplsq01g4t ; m ++ ) { if ( localDW -> gv5pvc5nnd
[ localB -> gdldy4anca + 1 ] > localDW -> gv5pvc5nnd [ localB -> bpvfku0axv +
1 ] ) { b2 = true ; for ( localB -> iu2lveaurm = 0 ; localB -> iu2lveaurm < 9
; localB -> iu2lveaurm ++ ) { localB -> f1sw2ht4n2 = localDW -> gv5pvc5nnd [
localB -> gdldy4anca + localB -> iu2lveaurm ] ; localDW -> gv5pvc5nnd [
localB -> gdldy4anca + localB -> iu2lveaurm ] = localDW -> gv5pvc5nnd [
localB -> bpvfku0axv + localB -> iu2lveaurm ] ; localDW -> gv5pvc5nnd [
localB -> bpvfku0axv + localB -> iu2lveaurm ] = localB -> f1sw2ht4n2 ; } }
localB -> gdldy4anca = localB -> bpvfku0axv ; localB -> bpvfku0axv += 9 ; } }
localB -> aplsq01g4t = localB -> autjwaia4y ; localB -> pdv5xeozmc ++ ;
localB -> gdldy4anca = 0 ; localB -> bpvfku0axv = - 1 ; localB -> dsu3yzczbs
++ ; } } else { localB -> oqjwwtnwwt = 0 ; localB -> eievh13zkr = 60 ; localB
-> dsu3yzczbs ++ ; } if ( localB -> oqjwwtnwwt < 0 ) { localB -> oqjwwtnwwt =
0 ; } if ( localB -> eievh13zkr < localB -> oqjwwtnwwt ) { localB ->
eievh13zkr = localB -> oqjwwtnwwt - 1 ; } if ( done ) { localB -> mjnb4ff24c
= localB -> mjnb4ff24c * 61 + localB -> oqjwwtnwwt ; localB -> f1sw2ht4n2 = 1
; if ( at34mfr1htg . P_1 > 1 ) { localB -> f1sw2ht4n2 = 0 ; } localB ->
iu2lveaurm = localB -> mjnb4ff24c ; for ( m = localB -> oqjwwtnwwt ; m <=
localB -> eievh13zkr ; m ++ ) { if ( localB -> f1sw2ht4n2 != 0 ) { lbljpp0upp
[ localB -> iu2lveaurm ] = ( uint8_T ) ( ( ( int32_T ) ( ( uint32_T )
lbljpp0upp [ localB -> iu2lveaurm ] * lbljpp0upp [ 0 ] ) << 14 ) >> 14 ) ;
lbljpp0upp [ localB -> iu2lveaurm ] = ( uint8_T ) ( lbljpp0upp [ localB ->
iu2lveaurm ] + 255U ) ; } else { lbljpp0upp [ localB -> iu2lveaurm ] =
MAX_uint8_T ; } localB -> iu2lveaurm ++ ; } } b2 = ( localB -> dsu3yzczbs <=
localB -> f3exltnl3f ) ; } localB -> autjwaia4y += accumOne * 9 ; if (
accumThree >= div_s32_floor ( imgRow , accumOne ) - 1 ) { accumThree = 0 ; }
else { accumThree ++ ; } b2 = ( localB -> autjwaia4y < accumTwo * accumOne *
9 ) ; } } } localDW -> cphsgbzvky [ 0 ] = ipb214pkst [ 0 ] ; localDW ->
cphsgbzvky [ 1 ] = 1 ; imgRow = ipb214pkst [ 0 ] ; for ( localB -> f1sw2ht4n2
= 0 ; localB -> f1sw2ht4n2 < imgRow ; localB -> f1sw2ht4n2 ++ ) { localB ->
br2yymckcz [ localB -> f1sw2ht4n2 ] = dkvodhtl10 [ ( at34mfr1htg . P_5 - 1 )
* ipb214pkst [ 0 ] + localB -> f1sw2ht4n2 ] ; } imgRow = ipb214pkst [ 0 ] ;
for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ; localB ->
f1sw2ht4n2 ++ ) { localB -> gehxtlz2bv [ localB -> f1sw2ht4n2 ] = localB ->
br2yymckcz [ localB -> f1sw2ht4n2 ] ; } localDW -> oyjel415x0 [ 0 ] =
ipb214pkst [ 0 ] ; localDW -> oyjel415x0 [ 1 ] = 1 ; imgRow = ipb214pkst [ 0
] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ; localB
-> f1sw2ht4n2 ++ ) { localB -> br2yymckcz [ localB -> f1sw2ht4n2 ] =
dkvodhtl10 [ ( at34mfr1htg . P_7 - 1 ) * ipb214pkst [ 0 ] + localB ->
f1sw2ht4n2 ] ; } imgRow = ipb214pkst [ 0 ] ; for ( localB -> f1sw2ht4n2 = 0 ;
localB -> f1sw2ht4n2 < imgRow ; localB -> f1sw2ht4n2 ++ ) { localB ->
dkw5vs0mpk [ localB -> f1sw2ht4n2 ] = localB -> br2yymckcz [ localB ->
f1sw2ht4n2 ] ; } imgRow = localDW -> cphsgbzvky [ 0 ] * localDW -> cphsgbzvky
[ 1 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ;
localB -> f1sw2ht4n2 ++ ) { localB -> gehxtlz2bv [ localB -> f1sw2ht4n2 ] -=
localB -> dkw5vs0mpk [ localB -> f1sw2ht4n2 ] ; } localDW -> f3aef3z5gb [ 0 ]
= ipb214pkst [ 0 ] ; localDW -> f3aef3z5gb [ 1 ] = 1 ; imgRow = ipb214pkst [
0 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ; localB
-> f1sw2ht4n2 ++ ) { localB -> br2yymckcz [ localB -> f1sw2ht4n2 ] =
dkvodhtl10 [ ( at34mfr1htg . P_6 - 1 ) * ipb214pkst [ 0 ] + localB ->
f1sw2ht4n2 ] ; } imgRow = ipb214pkst [ 0 ] ; for ( localB -> f1sw2ht4n2 = 0 ;
localB -> f1sw2ht4n2 < imgRow ; localB -> f1sw2ht4n2 ++ ) { localB ->
dkw5vs0mpk [ localB -> f1sw2ht4n2 ] = localB -> br2yymckcz [ localB ->
f1sw2ht4n2 ] ; } localDW -> bpdlxsw4ck [ 0 ] = ipb214pkst [ 0 ] ; localDW ->
bpdlxsw4ck [ 1 ] = 1 ; imgRow = ipb214pkst [ 0 ] ; for ( localB -> f1sw2ht4n2
= 0 ; localB -> f1sw2ht4n2 < imgRow ; localB -> f1sw2ht4n2 ++ ) { localB ->
br2yymckcz [ localB -> f1sw2ht4n2 ] = dkvodhtl10 [ ( at34mfr1htg . P_8 - 1 )
* ipb214pkst [ 0 ] + localB -> f1sw2ht4n2 ] ; } imgRow = ipb214pkst [ 0 ] ;
for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 < imgRow ; localB ->
f1sw2ht4n2 ++ ) { localB -> k5x5wcew54 [ localB -> f1sw2ht4n2 ] = localB ->
br2yymckcz [ localB -> f1sw2ht4n2 ] ; } imgRow = localDW -> f3aef3z5gb [ 0 ]
* localDW -> f3aef3z5gb [ 1 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB ->
f1sw2ht4n2 < imgRow ; localB -> f1sw2ht4n2 ++ ) { localB -> dkw5vs0mpk [
localB -> f1sw2ht4n2 ] -= localB -> k5x5wcew54 [ localB -> f1sw2ht4n2 ] ; }
lpmddypkcn [ 0 ] = localDW -> cphsgbzvky [ 0 ] ; lpmddypkcn [ 1 ] = localDW
-> cphsgbzvky [ 1 ] ; imgRow = localDW -> f3aef3z5gb [ 0 ] * localDW ->
f3aef3z5gb [ 1 ] ; for ( localB -> f1sw2ht4n2 = 0 ; localB -> f1sw2ht4n2 <
imgRow ; localB -> f1sw2ht4n2 ++ ) { ht3xboriqh [ localB -> f1sw2ht4n2 ] = (
real_T ) localB -> dkw5vs0mpk [ localB -> f1sw2ht4n2 ] / ( real_T ) localB ->
gehxtlz2bv [ localB -> f1sw2ht4n2 ] ; } } void LaneDetectionTID1 ( void ) { }
void eefcu1kp0h ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , csixeglpbl * const dho20abj51 , oilz1v0r1v * localB ,
dyigtkkzhy * localDW , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) { rt_InitInfAndNaN ( sizeof ( real_T )
) ; ( void ) memset ( ( void * ) dho20abj51 , 0 , sizeof ( csixeglpbl ) ) ;
lgmcl3zswm [ 0 ] = mdlref_TID0 ; lgmcl3zswm [ 1 ] = mdlref_TID1 ; dho20abj51
-> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; { int32_T i ; for ( i = 0 ; i < 96300 ;
i ++ ) { localB -> b3lj1ro54e [ i ] = 0.0 ; } localB -> pzo3lxik1r [ 0 ] = -
1.5707963267948966 ; localB -> pzo3lxik1r [ 1 ] = - 1.5533430342749532 ;
localB -> pzo3lxik1r [ 2 ] = - 1.53588974175501 ; localB -> pzo3lxik1r [ 3 ]
= - 1.5184364492350666 ; localB -> pzo3lxik1r [ 4 ] = - 1.5009831567151235 ;
localB -> pzo3lxik1r [ 5 ] = - 1.4835298641951802 ; localB -> pzo3lxik1r [ 6
] = - 1.4660765716752369 ; localB -> pzo3lxik1r [ 7 ] = - 1.4486232791552935
; localB -> pzo3lxik1r [ 8 ] = - 1.4311699866353502 ; localB -> pzo3lxik1r [
9 ] = - 1.4137166941154069 ; localB -> pzo3lxik1r [ 10 ] = -
1.3962634015954636 ; localB -> pzo3lxik1r [ 11 ] = - 1.3788101090755203 ;
localB -> pzo3lxik1r [ 12 ] = - 1.3613568165555769 ; localB -> pzo3lxik1r [
13 ] = - 1.3439035240356338 ; localB -> pzo3lxik1r [ 14 ] = -
1.3264502315156905 ; localB -> pzo3lxik1r [ 15 ] = - 1.3089969389957472 ;
localB -> pzo3lxik1r [ 16 ] = - 1.2915436464758039 ; localB -> pzo3lxik1r [
17 ] = - 1.2740903539558606 ; localB -> pzo3lxik1r [ 18 ] = -
1.2566370614359172 ; localB -> pzo3lxik1r [ 19 ] = - 1.2391837689159739 ;
localB -> pzo3lxik1r [ 20 ] = - 1.2217304763960306 ; localB -> pzo3lxik1r [
21 ] = - 1.2042771838760873 ; localB -> pzo3lxik1r [ 22 ] = -
1.1868238913561442 ; localB -> pzo3lxik1r [ 23 ] = - 1.1693705988362009 ;
localB -> pzo3lxik1r [ 24 ] = - 1.1519173063162575 ; localB -> pzo3lxik1r [
25 ] = - 1.1344640137963142 ; localB -> pzo3lxik1r [ 26 ] = -
1.1170107212763709 ; localB -> pzo3lxik1r [ 27 ] = - 1.0995574287564276 ;
localB -> pzo3lxik1r [ 28 ] = - 1.0821041362364843 ; localB -> pzo3lxik1r [
29 ] = - 1.064650843716541 ; localB -> pzo3lxik1r [ 30 ] = -
1.0471975511965976 ; localB -> pzo3lxik1r [ 31 ] = - 1.0297442586766545 ;
localB -> pzo3lxik1r [ 32 ] = - 1.0122909661567112 ; localB -> pzo3lxik1r [
33 ] = - 0.99483767363676789 ; localB -> pzo3lxik1r [ 34 ] = -
0.97738438111682457 ; localB -> pzo3lxik1r [ 35 ] = - 0.95993108859688125 ;
localB -> pzo3lxik1r [ 36 ] = - 0.94247779607693793 ; localB -> pzo3lxik1r [
37 ] = - 0.92502450355699462 ; localB -> pzo3lxik1r [ 38 ] = -
0.90757121103705141 ; localB -> pzo3lxik1r [ 39 ] = - 0.89011791851710809 ;
localB -> pzo3lxik1r [ 40 ] = - 0.87266462599716477 ; localB -> pzo3lxik1r [
41 ] = - 0.85521133347722145 ; localB -> pzo3lxik1r [ 42 ] = -
0.83775804095727824 ; localB -> pzo3lxik1r [ 43 ] = - 0.82030474843733492 ;
localB -> pzo3lxik1r [ 44 ] = - 0.8028514559173916 ; localB -> pzo3lxik1r [
45 ] = - 0.78539816339744828 ; localB -> pzo3lxik1r [ 46 ] = -
0.767944870877505 ; localB -> pzo3lxik1r [ 47 ] = - 0.75049157835756175 ;
localB -> pzo3lxik1r [ 48 ] = - 0.73303828583761843 ; localB -> pzo3lxik1r [
49 ] = - 0.71558499331767511 ; localB -> pzo3lxik1r [ 50 ] = -
0.69813170079773179 ; localB -> pzo3lxik1r [ 51 ] = - 0.68067840827778847 ;
localB -> pzo3lxik1r [ 52 ] = - 0.66322511575784526 ; localB -> pzo3lxik1r [
53 ] = - 0.64577182323790194 ; localB -> pzo3lxik1r [ 54 ] = -
0.62831853071795862 ; localB -> pzo3lxik1r [ 55 ] = - 0.6108652381980153 ;
localB -> pzo3lxik1r [ 56 ] = - 0.59341194567807209 ; localB -> pzo3lxik1r [
57 ] = - 0.57595865315812877 ; localB -> pzo3lxik1r [ 58 ] = -
0.55850536063818546 ; localB -> pzo3lxik1r [ 59 ] = - 0.54105206811824214 ;
localB -> pzo3lxik1r [ 60 ] = - 0.52359877559829882 ; localB -> pzo3lxik1r [
61 ] = - 0.50614548307835561 ; localB -> pzo3lxik1r [ 62 ] = -
0.48869219055841229 ; localB -> pzo3lxik1r [ 63 ] = - 0.47123889803846897 ;
localB -> pzo3lxik1r [ 64 ] = - 0.4537856055185257 ; localB -> pzo3lxik1r [
65 ] = - 0.43633231299858238 ; localB -> pzo3lxik1r [ 66 ] = -
0.41887902047863912 ; localB -> pzo3lxik1r [ 67 ] = - 0.4014257279586958 ;
localB -> pzo3lxik1r [ 68 ] = - 0.38397243543875248 ; localB -> pzo3lxik1r [
69 ] = - 0.36651914291880922 ; localB -> pzo3lxik1r [ 70 ] = -
0.3490658503988659 ; localB -> pzo3lxik1r [ 71 ] = - 0.33161255787892263 ;
localB -> pzo3lxik1r [ 72 ] = - 0.31415926535897931 ; localB -> pzo3lxik1r [
73 ] = - 0.29670597283903605 ; localB -> pzo3lxik1r [ 74 ] = -
0.27925268031909273 ; localB -> pzo3lxik1r [ 75 ] = - 0.26179938779914941 ;
localB -> pzo3lxik1r [ 76 ] = - 0.24434609527920614 ; localB -> pzo3lxik1r [
77 ] = - 0.22689280275926285 ; localB -> pzo3lxik1r [ 78 ] = -
0.20943951023931956 ; localB -> pzo3lxik1r [ 79 ] = - 0.19198621771937624 ;
localB -> pzo3lxik1r [ 80 ] = - 0.17453292519943295 ; localB -> pzo3lxik1r [
81 ] = - 0.15707963267948966 ; localB -> pzo3lxik1r [ 82 ] = -
0.13962634015954636 ; localB -> pzo3lxik1r [ 83 ] = - 0.12217304763960307 ;
localB -> pzo3lxik1r [ 84 ] = - 0.10471975511965978 ; localB -> pzo3lxik1r [
85 ] = - 0.087266462599716474 ; localB -> pzo3lxik1r [ 86 ] = -
0.069813170079773182 ; localB -> pzo3lxik1r [ 87 ] = - 0.05235987755982989 ;
localB -> pzo3lxik1r [ 88 ] = - 0.034906585039886591 ; localB -> pzo3lxik1r [
89 ] = - 0.017453292519943295 ; localB -> pzo3lxik1r [ 90 ] = 0.0 ; localB ->
pzo3lxik1r [ 91 ] = 0.017453292519943295 ; localB -> pzo3lxik1r [ 92 ] =
0.034906585039886591 ; localB -> pzo3lxik1r [ 93 ] = 0.05235987755982989 ;
localB -> pzo3lxik1r [ 94 ] = 0.069813170079773182 ; localB -> pzo3lxik1r [
95 ] = 0.087266462599716474 ; localB -> pzo3lxik1r [ 96 ] =
0.10471975511965978 ; localB -> pzo3lxik1r [ 97 ] = 0.12217304763960307 ;
localB -> pzo3lxik1r [ 98 ] = 0.13962634015954636 ; localB -> pzo3lxik1r [ 99
] = 0.15707963267948966 ; localB -> pzo3lxik1r [ 100 ] = 0.17453292519943295
; localB -> pzo3lxik1r [ 101 ] = 0.19198621771937624 ; localB -> pzo3lxik1r [
102 ] = 0.20943951023931956 ; localB -> pzo3lxik1r [ 103 ] =
0.22689280275926285 ; localB -> pzo3lxik1r [ 104 ] = 0.24434609527920614 ;
localB -> pzo3lxik1r [ 105 ] = 0.26179938779914941 ; localB -> pzo3lxik1r [
106 ] = 0.27925268031909273 ; localB -> pzo3lxik1r [ 107 ] =
0.29670597283903605 ; localB -> pzo3lxik1r [ 108 ] = 0.31415926535897931 ;
localB -> pzo3lxik1r [ 109 ] = 0.33161255787892263 ; localB -> pzo3lxik1r [
110 ] = 0.3490658503988659 ; localB -> pzo3lxik1r [ 111 ] =
0.36651914291880922 ; localB -> pzo3lxik1r [ 112 ] = 0.38397243543875248 ;
localB -> pzo3lxik1r [ 113 ] = 0.4014257279586958 ; localB -> pzo3lxik1r [
114 ] = 0.41887902047863912 ; localB -> pzo3lxik1r [ 115 ] =
0.43633231299858238 ; localB -> pzo3lxik1r [ 116 ] = 0.4537856055185257 ;
localB -> pzo3lxik1r [ 117 ] = 0.47123889803846897 ; localB -> pzo3lxik1r [
118 ] = 0.48869219055841229 ; localB -> pzo3lxik1r [ 119 ] =
0.50614548307835561 ; localB -> pzo3lxik1r [ 120 ] = 0.52359877559829882 ;
localB -> pzo3lxik1r [ 121 ] = 0.54105206811824214 ; localB -> pzo3lxik1r [
122 ] = 0.55850536063818546 ; localB -> pzo3lxik1r [ 123 ] =
0.57595865315812877 ; localB -> pzo3lxik1r [ 124 ] = 0.59341194567807209 ;
localB -> pzo3lxik1r [ 125 ] = 0.6108652381980153 ; localB -> pzo3lxik1r [
126 ] = 0.62831853071795862 ; localB -> pzo3lxik1r [ 127 ] =
0.64577182323790194 ; localB -> pzo3lxik1r [ 128 ] = 0.66322511575784526 ;
localB -> pzo3lxik1r [ 129 ] = 0.68067840827778847 ; localB -> pzo3lxik1r [
130 ] = 0.69813170079773179 ; localB -> pzo3lxik1r [ 131 ] =
0.71558499331767511 ; localB -> pzo3lxik1r [ 132 ] = 0.73303828583761843 ;
localB -> pzo3lxik1r [ 133 ] = 0.75049157835756175 ; localB -> pzo3lxik1r [
134 ] = 0.767944870877505 ; localB -> pzo3lxik1r [ 135 ] =
0.78539816339744828 ; localB -> pzo3lxik1r [ 136 ] = 0.8028514559173916 ;
localB -> pzo3lxik1r [ 137 ] = 0.82030474843733492 ; localB -> pzo3lxik1r [
138 ] = 0.83775804095727824 ; localB -> pzo3lxik1r [ 139 ] =
0.85521133347722145 ; localB -> pzo3lxik1r [ 140 ] = 0.87266462599716477 ;
localB -> pzo3lxik1r [ 141 ] = 0.89011791851710809 ; localB -> pzo3lxik1r [
142 ] = 0.90757121103705141 ; localB -> pzo3lxik1r [ 143 ] =
0.92502450355699462 ; localB -> pzo3lxik1r [ 144 ] = 0.94247779607693793 ;
localB -> pzo3lxik1r [ 145 ] = 0.95993108859688125 ; localB -> pzo3lxik1r [
146 ] = 0.97738438111682457 ; localB -> pzo3lxik1r [ 147 ] =
0.99483767363676789 ; localB -> pzo3lxik1r [ 148 ] = 1.0122909661567112 ;
localB -> pzo3lxik1r [ 149 ] = 1.0297442586766545 ; localB -> pzo3lxik1r [
150 ] = 1.0471975511965976 ; localB -> pzo3lxik1r [ 151 ] = 1.064650843716541
; localB -> pzo3lxik1r [ 152 ] = 1.0821041362364843 ; localB -> pzo3lxik1r [
153 ] = 1.0995574287564276 ; localB -> pzo3lxik1r [ 154 ] =
1.1170107212763709 ; localB -> pzo3lxik1r [ 155 ] = 1.1344640137963142 ;
localB -> pzo3lxik1r [ 156 ] = 1.1519173063162575 ; localB -> pzo3lxik1r [
157 ] = 1.1693705988362009 ; localB -> pzo3lxik1r [ 158 ] =
1.1868238913561442 ; localB -> pzo3lxik1r [ 159 ] = 1.2042771838760873 ;
localB -> pzo3lxik1r [ 160 ] = 1.2217304763960306 ; localB -> pzo3lxik1r [
161 ] = 1.2391837689159739 ; localB -> pzo3lxik1r [ 162 ] =
1.2566370614359172 ; localB -> pzo3lxik1r [ 163 ] = 1.2740903539558606 ;
localB -> pzo3lxik1r [ 164 ] = 1.2915436464758039 ; localB -> pzo3lxik1r [
165 ] = 1.3089969389957472 ; localB -> pzo3lxik1r [ 166 ] =
1.3264502315156905 ; localB -> pzo3lxik1r [ 167 ] = 1.3439035240356338 ;
localB -> pzo3lxik1r [ 168 ] = 1.3613568165555769 ; localB -> pzo3lxik1r [
169 ] = 1.3788101090755203 ; localB -> pzo3lxik1r [ 170 ] =
1.3962634015954636 ; localB -> pzo3lxik1r [ 171 ] = 1.4137166941154069 ;
localB -> pzo3lxik1r [ 172 ] = 1.4311699866353502 ; localB -> pzo3lxik1r [
173 ] = 1.4486232791552935 ; localB -> pzo3lxik1r [ 174 ] =
1.4660765716752369 ; localB -> pzo3lxik1r [ 175 ] = 1.4835298641951802 ;
localB -> pzo3lxik1r [ 176 ] = 1.5009831567151235 ; localB -> pzo3lxik1r [
177 ] = 1.5184364492350666 ; localB -> pzo3lxik1r [ 178 ] = 1.53588974175501
; localB -> pzo3lxik1r [ 179 ] = 1.5533430342749532 ; localB -> mesknpbk5t [
0 ] = - 267.0 ; localB -> mesknpbk5t [ 1 ] = - 266.0 ; localB -> mesknpbk5t [
2 ] = - 265.0 ; localB -> mesknpbk5t [ 3 ] = - 264.0 ; localB -> mesknpbk5t [
4 ] = - 263.0 ; localB -> mesknpbk5t [ 5 ] = - 262.0 ; localB -> mesknpbk5t [
6 ] = - 261.0 ; localB -> mesknpbk5t [ 7 ] = - 260.0 ; localB -> mesknpbk5t [
8 ] = - 259.0 ; localB -> mesknpbk5t [ 9 ] = - 258.0 ; localB -> mesknpbk5t [
10 ] = - 257.0 ; localB -> mesknpbk5t [ 11 ] = - 256.0 ; localB -> mesknpbk5t
[ 12 ] = - 255.0 ; localB -> mesknpbk5t [ 13 ] = - 254.0 ; localB ->
mesknpbk5t [ 14 ] = - 253.0 ; localB -> mesknpbk5t [ 15 ] = - 252.0 ; localB
-> mesknpbk5t [ 16 ] = - 251.0 ; localB -> mesknpbk5t [ 17 ] = - 250.0 ;
localB -> mesknpbk5t [ 18 ] = - 249.0 ; localB -> mesknpbk5t [ 19 ] = - 248.0
; localB -> mesknpbk5t [ 20 ] = - 247.0 ; localB -> mesknpbk5t [ 21 ] = -
246.0 ; localB -> mesknpbk5t [ 22 ] = - 245.0 ; localB -> mesknpbk5t [ 23 ] =
- 244.0 ; localB -> mesknpbk5t [ 24 ] = - 243.0 ; localB -> mesknpbk5t [ 25 ]
= - 242.0 ; localB -> mesknpbk5t [ 26 ] = - 241.0 ; localB -> mesknpbk5t [ 27
] = - 240.0 ; localB -> mesknpbk5t [ 28 ] = - 239.0 ; localB -> mesknpbk5t [
29 ] = - 238.0 ; localB -> mesknpbk5t [ 30 ] = - 237.0 ; localB -> mesknpbk5t
[ 31 ] = - 236.0 ; localB -> mesknpbk5t [ 32 ] = - 235.0 ; localB ->
mesknpbk5t [ 33 ] = - 234.0 ; localB -> mesknpbk5t [ 34 ] = - 233.0 ; localB
-> mesknpbk5t [ 35 ] = - 232.0 ; localB -> mesknpbk5t [ 36 ] = - 231.0 ;
localB -> mesknpbk5t [ 37 ] = - 230.0 ; localB -> mesknpbk5t [ 38 ] = - 229.0
; localB -> mesknpbk5t [ 39 ] = - 228.0 ; localB -> mesknpbk5t [ 40 ] = -
227.0 ; localB -> mesknpbk5t [ 41 ] = - 226.0 ; localB -> mesknpbk5t [ 42 ] =
- 225.0 ; localB -> mesknpbk5t [ 43 ] = - 224.0 ; localB -> mesknpbk5t [ 44 ]
= - 223.0 ; localB -> mesknpbk5t [ 45 ] = - 222.0 ; localB -> mesknpbk5t [ 46
] = - 221.0 ; localB -> mesknpbk5t [ 47 ] = - 220.0 ; localB -> mesknpbk5t [
48 ] = - 219.0 ; localB -> mesknpbk5t [ 49 ] = - 218.0 ; localB -> mesknpbk5t
[ 50 ] = - 217.0 ; localB -> mesknpbk5t [ 51 ] = - 216.0 ; localB ->
mesknpbk5t [ 52 ] = - 215.0 ; localB -> mesknpbk5t [ 53 ] = - 214.0 ; localB
-> mesknpbk5t [ 54 ] = - 213.0 ; localB -> mesknpbk5t [ 55 ] = - 212.0 ;
localB -> mesknpbk5t [ 56 ] = - 211.0 ; localB -> mesknpbk5t [ 57 ] = - 210.0
; localB -> mesknpbk5t [ 58 ] = - 209.0 ; localB -> mesknpbk5t [ 59 ] = -
208.0 ; localB -> mesknpbk5t [ 60 ] = - 207.0 ; localB -> mesknpbk5t [ 61 ] =
- 206.0 ; localB -> mesknpbk5t [ 62 ] = - 205.0 ; localB -> mesknpbk5t [ 63 ]
= - 204.0 ; localB -> mesknpbk5t [ 64 ] = - 203.0 ; localB -> mesknpbk5t [ 65
] = - 202.0 ; localB -> mesknpbk5t [ 66 ] = - 201.0 ; localB -> mesknpbk5t [
67 ] = - 200.0 ; localB -> mesknpbk5t [ 68 ] = - 199.0 ; localB -> mesknpbk5t
[ 69 ] = - 198.0 ; localB -> mesknpbk5t [ 70 ] = - 197.0 ; localB ->
mesknpbk5t [ 71 ] = - 196.0 ; localB -> mesknpbk5t [ 72 ] = - 195.0 ; localB
-> mesknpbk5t [ 73 ] = - 194.0 ; localB -> mesknpbk5t [ 74 ] = - 193.0 ;
localB -> mesknpbk5t [ 75 ] = - 192.0 ; localB -> mesknpbk5t [ 76 ] = - 191.0
; localB -> mesknpbk5t [ 77 ] = - 190.0 ; localB -> mesknpbk5t [ 78 ] = -
189.0 ; localB -> mesknpbk5t [ 79 ] = - 188.0 ; localB -> mesknpbk5t [ 80 ] =
- 187.0 ; localB -> mesknpbk5t [ 81 ] = - 186.0 ; localB -> mesknpbk5t [ 82 ]
= - 185.0 ; localB -> mesknpbk5t [ 83 ] = - 184.0 ; localB -> mesknpbk5t [ 84
] = - 183.0 ; localB -> mesknpbk5t [ 85 ] = - 182.0 ; localB -> mesknpbk5t [
86 ] = - 181.0 ; localB -> mesknpbk5t [ 87 ] = - 180.0 ; localB -> mesknpbk5t
[ 88 ] = - 179.0 ; localB -> mesknpbk5t [ 89 ] = - 178.0 ; localB ->
mesknpbk5t [ 90 ] = - 177.0 ; localB -> mesknpbk5t [ 91 ] = - 176.0 ; localB
-> mesknpbk5t [ 92 ] = - 175.0 ; localB -> mesknpbk5t [ 93 ] = - 174.0 ;
localB -> mesknpbk5t [ 94 ] = - 173.0 ; localB -> mesknpbk5t [ 95 ] = - 172.0
; localB -> mesknpbk5t [ 96 ] = - 171.0 ; localB -> mesknpbk5t [ 97 ] = -
170.0 ; localB -> mesknpbk5t [ 98 ] = - 169.0 ; localB -> mesknpbk5t [ 99 ] =
- 168.0 ; localB -> mesknpbk5t [ 100 ] = - 167.0 ; localB -> mesknpbk5t [ 101
] = - 166.0 ; localB -> mesknpbk5t [ 102 ] = - 165.0 ; localB -> mesknpbk5t [
103 ] = - 164.0 ; localB -> mesknpbk5t [ 104 ] = - 163.0 ; localB ->
mesknpbk5t [ 105 ] = - 162.0 ; localB -> mesknpbk5t [ 106 ] = - 161.0 ;
localB -> mesknpbk5t [ 107 ] = - 160.0 ; localB -> mesknpbk5t [ 108 ] = -
159.0 ; localB -> mesknpbk5t [ 109 ] = - 158.0 ; localB -> mesknpbk5t [ 110 ]
= - 157.0 ; localB -> mesknpbk5t [ 111 ] = - 156.0 ; localB -> mesknpbk5t [
112 ] = - 155.0 ; localB -> mesknpbk5t [ 113 ] = - 154.0 ; localB ->
mesknpbk5t [ 114 ] = - 153.0 ; localB -> mesknpbk5t [ 115 ] = - 152.0 ;
localB -> mesknpbk5t [ 116 ] = - 151.0 ; localB -> mesknpbk5t [ 117 ] = -
150.0 ; localB -> mesknpbk5t [ 118 ] = - 149.0 ; localB -> mesknpbk5t [ 119 ]
= - 148.0 ; localB -> mesknpbk5t [ 120 ] = - 147.0 ; localB -> mesknpbk5t [
121 ] = - 146.0 ; localB -> mesknpbk5t [ 122 ] = - 145.0 ; localB ->
mesknpbk5t [ 123 ] = - 144.0 ; localB -> mesknpbk5t [ 124 ] = - 143.0 ;
localB -> mesknpbk5t [ 125 ] = - 142.0 ; localB -> mesknpbk5t [ 126 ] = -
141.0 ; localB -> mesknpbk5t [ 127 ] = - 140.0 ; localB -> mesknpbk5t [ 128 ]
= - 139.0 ; localB -> mesknpbk5t [ 129 ] = - 138.0 ; localB -> mesknpbk5t [
130 ] = - 137.0 ; localB -> mesknpbk5t [ 131 ] = - 136.0 ; localB ->
mesknpbk5t [ 132 ] = - 135.0 ; localB -> mesknpbk5t [ 133 ] = - 134.0 ;
localB -> mesknpbk5t [ 134 ] = - 133.0 ; localB -> mesknpbk5t [ 135 ] = -
132.0 ; localB -> mesknpbk5t [ 136 ] = - 131.0 ; localB -> mesknpbk5t [ 137 ]
= - 130.0 ; localB -> mesknpbk5t [ 138 ] = - 129.0 ; localB -> mesknpbk5t [
139 ] = - 128.0 ; localB -> mesknpbk5t [ 140 ] = - 127.0 ; localB ->
mesknpbk5t [ 141 ] = - 126.0 ; localB -> mesknpbk5t [ 142 ] = - 125.0 ;
localB -> mesknpbk5t [ 143 ] = - 124.0 ; localB -> mesknpbk5t [ 144 ] = -
123.0 ; localB -> mesknpbk5t [ 145 ] = - 122.0 ; localB -> mesknpbk5t [ 146 ]
= - 121.0 ; localB -> mesknpbk5t [ 147 ] = - 120.0 ; localB -> mesknpbk5t [
148 ] = - 119.0 ; localB -> mesknpbk5t [ 149 ] = - 118.0 ; localB ->
mesknpbk5t [ 150 ] = - 117.0 ; localB -> mesknpbk5t [ 151 ] = - 116.0 ;
localB -> mesknpbk5t [ 152 ] = - 115.0 ; localB -> mesknpbk5t [ 153 ] = -
114.0 ; localB -> mesknpbk5t [ 154 ] = - 113.0 ; localB -> mesknpbk5t [ 155 ]
= - 112.0 ; localB -> mesknpbk5t [ 156 ] = - 111.0 ; localB -> mesknpbk5t [
157 ] = - 110.0 ; localB -> mesknpbk5t [ 158 ] = - 109.0 ; localB ->
mesknpbk5t [ 159 ] = - 108.0 ; localB -> mesknpbk5t [ 160 ] = - 107.0 ;
localB -> mesknpbk5t [ 161 ] = - 106.0 ; localB -> mesknpbk5t [ 162 ] = -
105.0 ; localB -> mesknpbk5t [ 163 ] = - 104.0 ; localB -> mesknpbk5t [ 164 ]
= - 103.0 ; localB -> mesknpbk5t [ 165 ] = - 102.0 ; localB -> mesknpbk5t [
166 ] = - 101.0 ; localB -> mesknpbk5t [ 167 ] = - 100.0 ; localB ->
mesknpbk5t [ 168 ] = - 99.0 ; localB -> mesknpbk5t [ 169 ] = - 98.0 ; localB
-> mesknpbk5t [ 170 ] = - 97.0 ; localB -> mesknpbk5t [ 171 ] = - 96.0 ;
localB -> mesknpbk5t [ 172 ] = - 95.0 ; localB -> mesknpbk5t [ 173 ] = - 94.0
; localB -> mesknpbk5t [ 174 ] = - 93.0 ; localB -> mesknpbk5t [ 175 ] = -
92.0 ; localB -> mesknpbk5t [ 176 ] = - 91.0 ; localB -> mesknpbk5t [ 177 ] =
- 90.0 ; localB -> mesknpbk5t [ 178 ] = - 89.0 ; localB -> mesknpbk5t [ 179 ]
= - 88.0 ; localB -> mesknpbk5t [ 180 ] = - 87.0 ; localB -> mesknpbk5t [ 181
] = - 86.0 ; localB -> mesknpbk5t [ 182 ] = - 85.0 ; localB -> mesknpbk5t [
183 ] = - 84.0 ; localB -> mesknpbk5t [ 184 ] = - 83.0 ; localB -> mesknpbk5t
[ 185 ] = - 82.0 ; localB -> mesknpbk5t [ 186 ] = - 81.0 ; localB ->
mesknpbk5t [ 187 ] = - 80.0 ; localB -> mesknpbk5t [ 188 ] = - 79.0 ; localB
-> mesknpbk5t [ 189 ] = - 78.0 ; localB -> mesknpbk5t [ 190 ] = - 77.0 ;
localB -> mesknpbk5t [ 191 ] = - 76.0 ; localB -> mesknpbk5t [ 192 ] = - 75.0
; localB -> mesknpbk5t [ 193 ] = - 74.0 ; localB -> mesknpbk5t [ 194 ] = -
73.0 ; localB -> mesknpbk5t [ 195 ] = - 72.0 ; localB -> mesknpbk5t [ 196 ] =
- 71.0 ; localB -> mesknpbk5t [ 197 ] = - 70.0 ; localB -> mesknpbk5t [ 198 ]
= - 69.0 ; localB -> mesknpbk5t [ 199 ] = - 68.0 ; localB -> mesknpbk5t [ 200
] = - 67.0 ; localB -> mesknpbk5t [ 201 ] = - 66.0 ; localB -> mesknpbk5t [
202 ] = - 65.0 ; localB -> mesknpbk5t [ 203 ] = - 64.0 ; localB -> mesknpbk5t
[ 204 ] = - 63.0 ; localB -> mesknpbk5t [ 205 ] = - 62.0 ; localB ->
mesknpbk5t [ 206 ] = - 61.0 ; localB -> mesknpbk5t [ 207 ] = - 60.0 ; localB
-> mesknpbk5t [ 208 ] = - 59.0 ; localB -> mesknpbk5t [ 209 ] = - 58.0 ;
localB -> mesknpbk5t [ 210 ] = - 57.0 ; localB -> mesknpbk5t [ 211 ] = - 56.0
; localB -> mesknpbk5t [ 212 ] = - 55.0 ; localB -> mesknpbk5t [ 213 ] = -
54.0 ; localB -> mesknpbk5t [ 214 ] = - 53.0 ; localB -> mesknpbk5t [ 215 ] =
- 52.0 ; localB -> mesknpbk5t [ 216 ] = - 51.0 ; localB -> mesknpbk5t [ 217 ]
= - 50.0 ; localB -> mesknpbk5t [ 218 ] = - 49.0 ; localB -> mesknpbk5t [ 219
] = - 48.0 ; localB -> mesknpbk5t [ 220 ] = - 47.0 ; localB -> mesknpbk5t [
221 ] = - 46.0 ; localB -> mesknpbk5t [ 222 ] = - 45.0 ; localB -> mesknpbk5t
[ 223 ] = - 44.0 ; localB -> mesknpbk5t [ 224 ] = - 43.0 ; localB ->
mesknpbk5t [ 225 ] = - 42.0 ; localB -> mesknpbk5t [ 226 ] = - 41.0 ; localB
-> mesknpbk5t [ 227 ] = - 40.0 ; localB -> mesknpbk5t [ 228 ] = - 39.0 ;
localB -> mesknpbk5t [ 229 ] = - 38.0 ; localB -> mesknpbk5t [ 230 ] = - 37.0
; localB -> mesknpbk5t [ 231 ] = - 36.0 ; localB -> mesknpbk5t [ 232 ] = -
35.0 ; localB -> mesknpbk5t [ 233 ] = - 34.0 ; localB -> mesknpbk5t [ 234 ] =
- 33.0 ; localB -> mesknpbk5t [ 235 ] = - 32.0 ; localB -> mesknpbk5t [ 236 ]
= - 31.0 ; localB -> mesknpbk5t [ 237 ] = - 30.0 ; localB -> mesknpbk5t [ 238
] = - 29.0 ; localB -> mesknpbk5t [ 239 ] = - 28.0 ; localB -> mesknpbk5t [
240 ] = - 27.0 ; localB -> mesknpbk5t [ 241 ] = - 26.0 ; localB -> mesknpbk5t
[ 242 ] = - 25.0 ; localB -> mesknpbk5t [ 243 ] = - 24.0 ; localB ->
mesknpbk5t [ 244 ] = - 23.0 ; localB -> mesknpbk5t [ 245 ] = - 22.0 ; localB
-> mesknpbk5t [ 246 ] = - 21.0 ; localB -> mesknpbk5t [ 247 ] = - 20.0 ;
localB -> mesknpbk5t [ 248 ] = - 19.0 ; localB -> mesknpbk5t [ 249 ] = - 18.0
; localB -> mesknpbk5t [ 250 ] = - 17.0 ; localB -> mesknpbk5t [ 251 ] = -
16.0 ; localB -> mesknpbk5t [ 252 ] = - 15.0 ; localB -> mesknpbk5t [ 253 ] =
- 14.0 ; localB -> mesknpbk5t [ 254 ] = - 13.0 ; localB -> mesknpbk5t [ 255 ]
= - 12.0 ; localB -> mesknpbk5t [ 256 ] = - 11.0 ; localB -> mesknpbk5t [ 257
] = - 10.0 ; localB -> mesknpbk5t [ 258 ] = - 9.0 ; localB -> mesknpbk5t [
259 ] = - 8.0 ; localB -> mesknpbk5t [ 260 ] = - 7.0 ; localB -> mesknpbk5t [
261 ] = - 6.0 ; localB -> mesknpbk5t [ 262 ] = - 5.0 ; localB -> mesknpbk5t [
263 ] = - 4.0 ; localB -> mesknpbk5t [ 264 ] = - 3.0 ; localB -> mesknpbk5t [
265 ] = - 2.0 ; localB -> mesknpbk5t [ 266 ] = - 1.0 ; localB -> mesknpbk5t [
267 ] = 0.0 ; localB -> mesknpbk5t [ 268 ] = 1.0 ; localB -> mesknpbk5t [ 269
] = 2.0 ; localB -> mesknpbk5t [ 270 ] = 3.0 ; localB -> mesknpbk5t [ 271 ] =
4.0 ; localB -> mesknpbk5t [ 272 ] = 5.0 ; localB -> mesknpbk5t [ 273 ] = 6.0
; localB -> mesknpbk5t [ 274 ] = 7.0 ; localB -> mesknpbk5t [ 275 ] = 8.0 ;
localB -> mesknpbk5t [ 276 ] = 9.0 ; localB -> mesknpbk5t [ 277 ] = 10.0 ;
localB -> mesknpbk5t [ 278 ] = 11.0 ; localB -> mesknpbk5t [ 279 ] = 12.0 ;
localB -> mesknpbk5t [ 280 ] = 13.0 ; localB -> mesknpbk5t [ 281 ] = 14.0 ;
localB -> mesknpbk5t [ 282 ] = 15.0 ; localB -> mesknpbk5t [ 283 ] = 16.0 ;
localB -> mesknpbk5t [ 284 ] = 17.0 ; localB -> mesknpbk5t [ 285 ] = 18.0 ;
localB -> mesknpbk5t [ 286 ] = 19.0 ; localB -> mesknpbk5t [ 287 ] = 20.0 ;
localB -> mesknpbk5t [ 288 ] = 21.0 ; localB -> mesknpbk5t [ 289 ] = 22.0 ;
localB -> mesknpbk5t [ 290 ] = 23.0 ; localB -> mesknpbk5t [ 291 ] = 24.0 ;
localB -> mesknpbk5t [ 292 ] = 25.0 ; localB -> mesknpbk5t [ 293 ] = 26.0 ;
localB -> mesknpbk5t [ 294 ] = 27.0 ; localB -> mesknpbk5t [ 295 ] = 28.0 ;
localB -> mesknpbk5t [ 296 ] = 29.0 ; localB -> mesknpbk5t [ 297 ] = 30.0 ;
localB -> mesknpbk5t [ 298 ] = 31.0 ; localB -> mesknpbk5t [ 299 ] = 32.0 ;
localB -> mesknpbk5t [ 300 ] = 33.0 ; localB -> mesknpbk5t [ 301 ] = 34.0 ;
localB -> mesknpbk5t [ 302 ] = 35.0 ; localB -> mesknpbk5t [ 303 ] = 36.0 ;
localB -> mesknpbk5t [ 304 ] = 37.0 ; localB -> mesknpbk5t [ 305 ] = 38.0 ;
localB -> mesknpbk5t [ 306 ] = 39.0 ; localB -> mesknpbk5t [ 307 ] = 40.0 ;
localB -> mesknpbk5t [ 308 ] = 41.0 ; localB -> mesknpbk5t [ 309 ] = 42.0 ;
localB -> mesknpbk5t [ 310 ] = 43.0 ; localB -> mesknpbk5t [ 311 ] = 44.0 ;
localB -> mesknpbk5t [ 312 ] = 45.0 ; localB -> mesknpbk5t [ 313 ] = 46.0 ;
localB -> mesknpbk5t [ 314 ] = 47.0 ; localB -> mesknpbk5t [ 315 ] = 48.0 ;
localB -> mesknpbk5t [ 316 ] = 49.0 ; localB -> mesknpbk5t [ 317 ] = 50.0 ;
localB -> mesknpbk5t [ 318 ] = 51.0 ; localB -> mesknpbk5t [ 319 ] = 52.0 ;
localB -> mesknpbk5t [ 320 ] = 53.0 ; localB -> mesknpbk5t [ 321 ] = 54.0 ;
localB -> mesknpbk5t [ 322 ] = 55.0 ; localB -> mesknpbk5t [ 323 ] = 56.0 ;
localB -> mesknpbk5t [ 324 ] = 57.0 ; localB -> mesknpbk5t [ 325 ] = 58.0 ;
localB -> mesknpbk5t [ 326 ] = 59.0 ; localB -> mesknpbk5t [ 327 ] = 60.0 ;
localB -> mesknpbk5t [ 328 ] = 61.0 ; localB -> mesknpbk5t [ 329 ] = 62.0 ;
localB -> mesknpbk5t [ 330 ] = 63.0 ; localB -> mesknpbk5t [ 331 ] = 64.0 ;
localB -> mesknpbk5t [ 332 ] = 65.0 ; localB -> mesknpbk5t [ 333 ] = 66.0 ;
localB -> mesknpbk5t [ 334 ] = 67.0 ; localB -> mesknpbk5t [ 335 ] = 68.0 ;
localB -> mesknpbk5t [ 336 ] = 69.0 ; localB -> mesknpbk5t [ 337 ] = 70.0 ;
localB -> mesknpbk5t [ 338 ] = 71.0 ; localB -> mesknpbk5t [ 339 ] = 72.0 ;
localB -> mesknpbk5t [ 340 ] = 73.0 ; localB -> mesknpbk5t [ 341 ] = 74.0 ;
localB -> mesknpbk5t [ 342 ] = 75.0 ; localB -> mesknpbk5t [ 343 ] = 76.0 ;
localB -> mesknpbk5t [ 344 ] = 77.0 ; localB -> mesknpbk5t [ 345 ] = 78.0 ;
localB -> mesknpbk5t [ 346 ] = 79.0 ; localB -> mesknpbk5t [ 347 ] = 80.0 ;
localB -> mesknpbk5t [ 348 ] = 81.0 ; localB -> mesknpbk5t [ 349 ] = 82.0 ;
localB -> mesknpbk5t [ 350 ] = 83.0 ; localB -> mesknpbk5t [ 351 ] = 84.0 ;
localB -> mesknpbk5t [ 352 ] = 85.0 ; localB -> mesknpbk5t [ 353 ] = 86.0 ;
localB -> mesknpbk5t [ 354 ] = 87.0 ; localB -> mesknpbk5t [ 355 ] = 88.0 ;
localB -> mesknpbk5t [ 356 ] = 89.0 ; localB -> mesknpbk5t [ 357 ] = 90.0 ;
localB -> mesknpbk5t [ 358 ] = 91.0 ; localB -> mesknpbk5t [ 359 ] = 92.0 ;
localB -> mesknpbk5t [ 360 ] = 93.0 ; localB -> mesknpbk5t [ 361 ] = 94.0 ;
localB -> mesknpbk5t [ 362 ] = 95.0 ; localB -> mesknpbk5t [ 363 ] = 96.0 ;
localB -> mesknpbk5t [ 364 ] = 97.0 ; localB -> mesknpbk5t [ 365 ] = 98.0 ;
localB -> mesknpbk5t [ 366 ] = 99.0 ; localB -> mesknpbk5t [ 367 ] = 100.0 ;
localB -> mesknpbk5t [ 368 ] = 101.0 ; localB -> mesknpbk5t [ 369 ] = 102.0 ;
localB -> mesknpbk5t [ 370 ] = 103.0 ; localB -> mesknpbk5t [ 371 ] = 104.0 ;
localB -> mesknpbk5t [ 372 ] = 105.0 ; localB -> mesknpbk5t [ 373 ] = 106.0 ;
localB -> mesknpbk5t [ 374 ] = 107.0 ; localB -> mesknpbk5t [ 375 ] = 108.0 ;
localB -> mesknpbk5t [ 376 ] = 109.0 ; localB -> mesknpbk5t [ 377 ] = 110.0 ;
localB -> mesknpbk5t [ 378 ] = 111.0 ; localB -> mesknpbk5t [ 379 ] = 112.0 ;
localB -> mesknpbk5t [ 380 ] = 113.0 ; localB -> mesknpbk5t [ 381 ] = 114.0 ;
localB -> mesknpbk5t [ 382 ] = 115.0 ; localB -> mesknpbk5t [ 383 ] = 116.0 ;
localB -> mesknpbk5t [ 384 ] = 117.0 ; localB -> mesknpbk5t [ 385 ] = 118.0 ;
localB -> mesknpbk5t [ 386 ] = 119.0 ; localB -> mesknpbk5t [ 387 ] = 120.0 ;
localB -> mesknpbk5t [ 388 ] = 121.0 ; localB -> mesknpbk5t [ 389 ] = 122.0 ;
localB -> mesknpbk5t [ 390 ] = 123.0 ; localB -> mesknpbk5t [ 391 ] = 124.0 ;
localB -> mesknpbk5t [ 392 ] = 125.0 ; localB -> mesknpbk5t [ 393 ] = 126.0 ;
localB -> mesknpbk5t [ 394 ] = 127.0 ; localB -> mesknpbk5t [ 395 ] = 128.0 ;
localB -> mesknpbk5t [ 396 ] = 129.0 ; localB -> mesknpbk5t [ 397 ] = 130.0 ;
localB -> mesknpbk5t [ 398 ] = 131.0 ; localB -> mesknpbk5t [ 399 ] = 132.0 ;
localB -> mesknpbk5t [ 400 ] = 133.0 ; localB -> mesknpbk5t [ 401 ] = 134.0 ;
localB -> mesknpbk5t [ 402 ] = 135.0 ; localB -> mesknpbk5t [ 403 ] = 136.0 ;
localB -> mesknpbk5t [ 404 ] = 137.0 ; localB -> mesknpbk5t [ 405 ] = 138.0 ;
localB -> mesknpbk5t [ 406 ] = 139.0 ; localB -> mesknpbk5t [ 407 ] = 140.0 ;
localB -> mesknpbk5t [ 408 ] = 141.0 ; localB -> mesknpbk5t [ 409 ] = 142.0 ;
localB -> mesknpbk5t [ 410 ] = 143.0 ; localB -> mesknpbk5t [ 411 ] = 144.0 ;
localB -> mesknpbk5t [ 412 ] = 145.0 ; localB -> mesknpbk5t [ 413 ] = 146.0 ;
localB -> mesknpbk5t [ 414 ] = 147.0 ; localB -> mesknpbk5t [ 415 ] = 148.0 ;
localB -> mesknpbk5t [ 416 ] = 149.0 ; localB -> mesknpbk5t [ 417 ] = 150.0 ;
localB -> mesknpbk5t [ 418 ] = 151.0 ; localB -> mesknpbk5t [ 419 ] = 152.0 ;
localB -> mesknpbk5t [ 420 ] = 153.0 ; localB -> mesknpbk5t [ 421 ] = 154.0 ;
localB -> mesknpbk5t [ 422 ] = 155.0 ; localB -> mesknpbk5t [ 423 ] = 156.0 ;
localB -> mesknpbk5t [ 424 ] = 157.0 ; localB -> mesknpbk5t [ 425 ] = 158.0 ;
localB -> mesknpbk5t [ 426 ] = 159.0 ; localB -> mesknpbk5t [ 427 ] = 160.0 ;
localB -> mesknpbk5t [ 428 ] = 161.0 ; localB -> mesknpbk5t [ 429 ] = 162.0 ;
localB -> mesknpbk5t [ 430 ] = 163.0 ; localB -> mesknpbk5t [ 431 ] = 164.0 ;
localB -> mesknpbk5t [ 432 ] = 165.0 ; localB -> mesknpbk5t [ 433 ] = 166.0 ;
localB -> mesknpbk5t [ 434 ] = 167.0 ; localB -> mesknpbk5t [ 435 ] = 168.0 ;
localB -> mesknpbk5t [ 436 ] = 169.0 ; localB -> mesknpbk5t [ 437 ] = 170.0 ;
localB -> mesknpbk5t [ 438 ] = 171.0 ; localB -> mesknpbk5t [ 439 ] = 172.0 ;
localB -> mesknpbk5t [ 440 ] = 173.0 ; localB -> mesknpbk5t [ 441 ] = 174.0 ;
localB -> mesknpbk5t [ 442 ] = 175.0 ; localB -> mesknpbk5t [ 443 ] = 176.0 ;
localB -> mesknpbk5t [ 444 ] = 177.0 ; localB -> mesknpbk5t [ 445 ] = 178.0 ;
localB -> mesknpbk5t [ 446 ] = 179.0 ; localB -> mesknpbk5t [ 447 ] = 180.0 ;
localB -> mesknpbk5t [ 448 ] = 181.0 ; localB -> mesknpbk5t [ 449 ] = 182.0 ;
localB -> mesknpbk5t [ 450 ] = 183.0 ; localB -> mesknpbk5t [ 451 ] = 184.0 ;
localB -> mesknpbk5t [ 452 ] = 185.0 ; localB -> mesknpbk5t [ 453 ] = 186.0 ;
localB -> mesknpbk5t [ 454 ] = 187.0 ; localB -> mesknpbk5t [ 455 ] = 188.0 ;
localB -> mesknpbk5t [ 456 ] = 189.0 ; localB -> mesknpbk5t [ 457 ] = 190.0 ;
localB -> mesknpbk5t [ 458 ] = 191.0 ; localB -> mesknpbk5t [ 459 ] = 192.0 ;
localB -> mesknpbk5t [ 460 ] = 193.0 ; localB -> mesknpbk5t [ 461 ] = 194.0 ;
localB -> mesknpbk5t [ 462 ] = 195.0 ; localB -> mesknpbk5t [ 463 ] = 196.0 ;
localB -> mesknpbk5t [ 464 ] = 197.0 ; localB -> mesknpbk5t [ 465 ] = 198.0 ;
localB -> mesknpbk5t [ 466 ] = 199.0 ; localB -> mesknpbk5t [ 467 ] = 200.0 ;
localB -> mesknpbk5t [ 468 ] = 201.0 ; localB -> mesknpbk5t [ 469 ] = 202.0 ;
localB -> mesknpbk5t [ 470 ] = 203.0 ; localB -> mesknpbk5t [ 471 ] = 204.0 ;
localB -> mesknpbk5t [ 472 ] = 205.0 ; localB -> mesknpbk5t [ 473 ] = 206.0 ;
localB -> mesknpbk5t [ 474 ] = 207.0 ; localB -> mesknpbk5t [ 475 ] = 208.0 ;
localB -> mesknpbk5t [ 476 ] = 209.0 ; localB -> mesknpbk5t [ 477 ] = 210.0 ;
localB -> mesknpbk5t [ 478 ] = 211.0 ; localB -> mesknpbk5t [ 479 ] = 212.0 ;
localB -> mesknpbk5t [ 480 ] = 213.0 ; localB -> mesknpbk5t [ 481 ] = 214.0 ;
localB -> mesknpbk5t [ 482 ] = 215.0 ; localB -> mesknpbk5t [ 483 ] = 216.0 ;
localB -> mesknpbk5t [ 484 ] = 217.0 ; localB -> mesknpbk5t [ 485 ] = 218.0 ;
localB -> mesknpbk5t [ 486 ] = 219.0 ; localB -> mesknpbk5t [ 487 ] = 220.0 ;
localB -> mesknpbk5t [ 488 ] = 221.0 ; localB -> mesknpbk5t [ 489 ] = 222.0 ;
localB -> mesknpbk5t [ 490 ] = 223.0 ; localB -> mesknpbk5t [ 491 ] = 224.0 ;
localB -> mesknpbk5t [ 492 ] = 225.0 ; localB -> mesknpbk5t [ 493 ] = 226.0 ;
localB -> mesknpbk5t [ 494 ] = 227.0 ; localB -> mesknpbk5t [ 495 ] = 228.0 ;
localB -> mesknpbk5t [ 496 ] = 229.0 ; localB -> mesknpbk5t [ 497 ] = 230.0 ;
localB -> mesknpbk5t [ 498 ] = 231.0 ; localB -> mesknpbk5t [ 499 ] = 232.0 ;
localB -> mesknpbk5t [ 500 ] = 233.0 ; localB -> mesknpbk5t [ 501 ] = 234.0 ;
localB -> mesknpbk5t [ 502 ] = 235.0 ; localB -> mesknpbk5t [ 503 ] = 236.0 ;
localB -> mesknpbk5t [ 504 ] = 237.0 ; localB -> mesknpbk5t [ 505 ] = 238.0 ;
localB -> mesknpbk5t [ 506 ] = 239.0 ; localB -> mesknpbk5t [ 507 ] = 240.0 ;
localB -> mesknpbk5t [ 508 ] = 241.0 ; localB -> mesknpbk5t [ 509 ] = 242.0 ;
localB -> mesknpbk5t [ 510 ] = 243.0 ; localB -> mesknpbk5t [ 511 ] = 244.0 ;
localB -> mesknpbk5t [ 512 ] = 245.0 ; localB -> mesknpbk5t [ 513 ] = 246.0 ;
localB -> mesknpbk5t [ 514 ] = 247.0 ; localB -> mesknpbk5t [ 515 ] = 248.0 ;
localB -> mesknpbk5t [ 516 ] = 249.0 ; localB -> mesknpbk5t [ 517 ] = 250.0 ;
localB -> mesknpbk5t [ 518 ] = 251.0 ; localB -> mesknpbk5t [ 519 ] = 252.0 ;
localB -> mesknpbk5t [ 520 ] = 253.0 ; localB -> mesknpbk5t [ 521 ] = 254.0 ;
localB -> mesknpbk5t [ 522 ] = 255.0 ; localB -> mesknpbk5t [ 523 ] = 256.0 ;
localB -> mesknpbk5t [ 524 ] = 257.0 ; localB -> mesknpbk5t [ 525 ] = 258.0 ;
localB -> mesknpbk5t [ 526 ] = 259.0 ; localB -> mesknpbk5t [ 527 ] = 260.0 ;
localB -> mesknpbk5t [ 528 ] = 261.0 ; localB -> mesknpbk5t [ 529 ] = 262.0 ;
localB -> mesknpbk5t [ 530 ] = 263.0 ; localB -> mesknpbk5t [ 531 ] = 264.0 ;
localB -> mesknpbk5t [ 532 ] = 265.0 ; localB -> mesknpbk5t [ 533 ] = 266.0 ;
localB -> mesknpbk5t [ 534 ] = 267.0 ; } ( void ) memset ( ( void * ) localDW
, 0 , sizeof ( dyigtkkzhy ) ) ; { int32_T i ; for ( i = 0 ; i < 96300 ; i ++
) { localDW -> dsg35qf31k [ i ] = 0.0 ; } }
LaneDetection_InitializeDataMapInfo ( dho20abj51 , localDW , sysRanPtr ,
contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && ( rt_ChildPath != ( NULL
) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI , rt_ChildMMIIdx , & (
dho20abj51 -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath ( dho20abj51 ->
DataMapInfo . mmi , rt_ChildPath ) ; rtwCAPI_MMISetContStateStartIndex (
dho20abj51 -> DataMapInfo . mmi , rt_CSTATEIdx ) ; } } void
mr_LaneDetection_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T * modelName
, int_T * retVal ) { * retVal = 0 ; * retVal = 0 ; ssRegModelRefMdlInfo (
mdlRefSfcnS , modelName , rtMdlInfo_LaneDetection , 51 ) ; * retVal = 1 ; }
static void mr_LaneDetection_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_LaneDetection_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_LaneDetection_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_LaneDetection_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_LaneDetection_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_LaneDetection_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( double )
bitVal ) ) ; } static uint_T mr_LaneDetection_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_LaneDetection_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_LaneDetection_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_LaneDetection_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_LaneDetection_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_LaneDetection_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_LaneDetection_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_LaneDetection_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_LaneDetection_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_LaneDetection_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_LaneDetection_GetDWork ( const
l0tllqg3h2m * mdlrefDW ) { static const char * dwFieldNames [ 3 ] = { "rtb" ,
"rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 ,
3 , dwFieldNames ) ; mr_LaneDetection_cacheDataAsMxArray ( ssDW , 0 , 0 , & (
mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb ) ) ; { static const char *
dwFieldNames [ 35 ] = { "mdlrefDW->rtdw.dsg35qf31k" ,
"mdlrefDW->rtdw.ephazqj5mq" , "mdlrefDW->rtdw.cc40xb1fei" ,
"mdlrefDW->rtdw.cdu44n1mcq" , "mdlrefDW->rtdw.gv5pvc5nnd" ,
"mdlrefDW->rtdw.iocj4jvjgy" , "mdlrefDW->rtdw.djrywqscau" ,
"mdlrefDW->rtdw.fxerzqdnn4" , "mdlrefDW->rtdw.mywyj3ifgs" ,
"mdlrefDW->rtdw.d1q55gop1o" , "mdlrefDW->rtdw.opprajci1l" ,
"mdlrefDW->rtdw.ljymobalpk" , "mdlrefDW->rtdw.kj1gyk1zyf" ,
"mdlrefDW->rtdw.a0d2h51hkg" , "mdlrefDW->rtdw.mxw2tseubc" ,
"mdlrefDW->rtdw.gtuh2kmbhr" , "mdlrefDW->rtdw.lsy3sbihvc" ,
"mdlrefDW->rtdw.peqr3kviw4" , "mdlrefDW->rtdw.k2d4np15dl" ,
"mdlrefDW->rtdw.pt3k3gmetp" , "mdlrefDW->rtdw.ezmqyj1gr1" ,
"mdlrefDW->rtdw.fub4i3nxul" , "mdlrefDW->rtdw.jdcxgsn5ce" ,
"mdlrefDW->rtdw.grjqtyru3u" , "mdlrefDW->rtdw.oi5u3pitda" ,
"mdlrefDW->rtdw.asufhs1ugh" , "mdlrefDW->rtdw.fpfsjsly5b" ,
"mdlrefDW->rtdw.bhbvy4ifhi" , "mdlrefDW->rtdw.aoyjxzbpzc" ,
"mdlrefDW->rtdw.cphsgbzvky" , "mdlrefDW->rtdw.oyjel415x0" ,
"mdlrefDW->rtdw.f3aef3z5gb" , "mdlrefDW->rtdw.bpdlxsw4ck" ,
"mdlrefDW->rtdw.dq3yf2kc54" , "mdlrefDW->rtdw.dadv2akfp4" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 35 , dwFieldNames ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 0 , & ( mdlrefDW -> rtdw
. dsg35qf31k ) , sizeof ( mdlrefDW -> rtdw . dsg35qf31k ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 1 , & ( mdlrefDW -> rtdw
. ephazqj5mq ) , sizeof ( mdlrefDW -> rtdw . ephazqj5mq ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 2 , & ( mdlrefDW -> rtdw
. cc40xb1fei ) , sizeof ( mdlrefDW -> rtdw . cc40xb1fei ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 3 , & ( mdlrefDW -> rtdw
. cdu44n1mcq ) , sizeof ( mdlrefDW -> rtdw . cdu44n1mcq ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 4 , & ( mdlrefDW -> rtdw
. gv5pvc5nnd ) , sizeof ( mdlrefDW -> rtdw . gv5pvc5nnd ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 5 , & ( mdlrefDW -> rtdw
. iocj4jvjgy ) , sizeof ( mdlrefDW -> rtdw . iocj4jvjgy ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 6 , & ( mdlrefDW -> rtdw
. djrywqscau ) , sizeof ( mdlrefDW -> rtdw . djrywqscau ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 7 , & ( mdlrefDW -> rtdw
. fxerzqdnn4 ) , sizeof ( mdlrefDW -> rtdw . fxerzqdnn4 ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 8 , & ( mdlrefDW -> rtdw
. mywyj3ifgs ) , sizeof ( mdlrefDW -> rtdw . mywyj3ifgs ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 9 , & ( mdlrefDW -> rtdw
. d1q55gop1o ) , sizeof ( mdlrefDW -> rtdw . d1q55gop1o ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 10 , & ( mdlrefDW ->
rtdw . opprajci1l ) , sizeof ( mdlrefDW -> rtdw . opprajci1l ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 11 , & ( mdlrefDW ->
rtdw . ljymobalpk ) , sizeof ( mdlrefDW -> rtdw . ljymobalpk ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 12 , & ( mdlrefDW ->
rtdw . kj1gyk1zyf ) , sizeof ( mdlrefDW -> rtdw . kj1gyk1zyf ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 13 , & ( mdlrefDW ->
rtdw . a0d2h51hkg ) , sizeof ( mdlrefDW -> rtdw . a0d2h51hkg ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 14 , & ( mdlrefDW ->
rtdw . mxw2tseubc ) , sizeof ( mdlrefDW -> rtdw . mxw2tseubc ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 15 , & ( mdlrefDW ->
rtdw . gtuh2kmbhr ) , sizeof ( mdlrefDW -> rtdw . gtuh2kmbhr ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 16 , & ( mdlrefDW ->
rtdw . lsy3sbihvc ) , sizeof ( mdlrefDW -> rtdw . lsy3sbihvc ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 17 , & ( mdlrefDW ->
rtdw . peqr3kviw4 ) , sizeof ( mdlrefDW -> rtdw . peqr3kviw4 ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 18 , & ( mdlrefDW ->
rtdw . k2d4np15dl ) , sizeof ( mdlrefDW -> rtdw . k2d4np15dl ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 19 , & ( mdlrefDW ->
rtdw . pt3k3gmetp ) , sizeof ( mdlrefDW -> rtdw . pt3k3gmetp ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 20 , & ( mdlrefDW ->
rtdw . ezmqyj1gr1 ) , sizeof ( mdlrefDW -> rtdw . ezmqyj1gr1 ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 21 , & ( mdlrefDW ->
rtdw . fub4i3nxul ) , sizeof ( mdlrefDW -> rtdw . fub4i3nxul ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 22 , & ( mdlrefDW ->
rtdw . jdcxgsn5ce ) , sizeof ( mdlrefDW -> rtdw . jdcxgsn5ce ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 23 , & ( mdlrefDW ->
rtdw . grjqtyru3u ) , sizeof ( mdlrefDW -> rtdw . grjqtyru3u ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 24 , & ( mdlrefDW ->
rtdw . oi5u3pitda ) , sizeof ( mdlrefDW -> rtdw . oi5u3pitda ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 25 , & ( mdlrefDW ->
rtdw . asufhs1ugh ) , sizeof ( mdlrefDW -> rtdw . asufhs1ugh ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 26 , & ( mdlrefDW ->
rtdw . fpfsjsly5b ) , sizeof ( mdlrefDW -> rtdw . fpfsjsly5b ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 27 , & ( mdlrefDW ->
rtdw . bhbvy4ifhi ) , sizeof ( mdlrefDW -> rtdw . bhbvy4ifhi ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 28 , & ( mdlrefDW ->
rtdw . aoyjxzbpzc ) , sizeof ( mdlrefDW -> rtdw . aoyjxzbpzc ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 29 , & ( mdlrefDW ->
rtdw . cphsgbzvky ) , sizeof ( mdlrefDW -> rtdw . cphsgbzvky ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 30 , & ( mdlrefDW ->
rtdw . oyjel415x0 ) , sizeof ( mdlrefDW -> rtdw . oyjel415x0 ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 31 , & ( mdlrefDW ->
rtdw . f3aef3z5gb ) , sizeof ( mdlrefDW -> rtdw . f3aef3z5gb ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 32 , & ( mdlrefDW ->
rtdw . bpdlxsw4ck ) , sizeof ( mdlrefDW -> rtdw . bpdlxsw4ck ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 33 , & ( mdlrefDW ->
rtdw . dq3yf2kc54 ) , sizeof ( mdlrefDW -> rtdw . dq3yf2kc54 ) ) ;
mr_LaneDetection_cacheDataAsMxArray ( rtdwData , 0 , 34 , & ( mdlrefDW ->
rtdw . dadv2akfp4 ) , sizeof ( mdlrefDW -> rtdw . dadv2akfp4 ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_LaneDetection_SetDWork ( l0tllqg3h2m * mdlrefDW , const mxArray * ssDW ) {
mr_LaneDetection_restoreDataFromMxArray ( & ( mdlrefDW -> rtb ) , ssDW , 0 ,
0 , sizeof ( mdlrefDW -> rtb ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_LaneDetection_restoreDataFromMxArray
( & ( mdlrefDW -> rtdw . dsg35qf31k ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW
-> rtdw . dsg35qf31k ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . ephazqj5mq ) , rtdwData , 0 , 1 , sizeof ( mdlrefDW ->
rtdw . ephazqj5mq ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . cc40xb1fei ) , rtdwData , 0 , 2 , sizeof ( mdlrefDW ->
rtdw . cc40xb1fei ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . cdu44n1mcq ) , rtdwData , 0 , 3 , sizeof ( mdlrefDW ->
rtdw . cdu44n1mcq ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . gv5pvc5nnd ) , rtdwData , 0 , 4 , sizeof ( mdlrefDW ->
rtdw . gv5pvc5nnd ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . iocj4jvjgy ) , rtdwData , 0 , 5 , sizeof ( mdlrefDW ->
rtdw . iocj4jvjgy ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . djrywqscau ) , rtdwData , 0 , 6 , sizeof ( mdlrefDW ->
rtdw . djrywqscau ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . fxerzqdnn4 ) , rtdwData , 0 , 7 , sizeof ( mdlrefDW ->
rtdw . fxerzqdnn4 ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . mywyj3ifgs ) , rtdwData , 0 , 8 , sizeof ( mdlrefDW ->
rtdw . mywyj3ifgs ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . d1q55gop1o ) , rtdwData , 0 , 9 , sizeof ( mdlrefDW ->
rtdw . d1q55gop1o ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . opprajci1l ) , rtdwData , 0 , 10 , sizeof ( mdlrefDW ->
rtdw . opprajci1l ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . ljymobalpk ) , rtdwData , 0 , 11 , sizeof ( mdlrefDW ->
rtdw . ljymobalpk ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . kj1gyk1zyf ) , rtdwData , 0 , 12 , sizeof ( mdlrefDW ->
rtdw . kj1gyk1zyf ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . a0d2h51hkg ) , rtdwData , 0 , 13 , sizeof ( mdlrefDW ->
rtdw . a0d2h51hkg ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . mxw2tseubc ) , rtdwData , 0 , 14 , sizeof ( mdlrefDW ->
rtdw . mxw2tseubc ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . gtuh2kmbhr ) , rtdwData , 0 , 15 , sizeof ( mdlrefDW ->
rtdw . gtuh2kmbhr ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . lsy3sbihvc ) , rtdwData , 0 , 16 , sizeof ( mdlrefDW ->
rtdw . lsy3sbihvc ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . peqr3kviw4 ) , rtdwData , 0 , 17 , sizeof ( mdlrefDW ->
rtdw . peqr3kviw4 ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . k2d4np15dl ) , rtdwData , 0 , 18 , sizeof ( mdlrefDW ->
rtdw . k2d4np15dl ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . pt3k3gmetp ) , rtdwData , 0 , 19 , sizeof ( mdlrefDW ->
rtdw . pt3k3gmetp ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . ezmqyj1gr1 ) , rtdwData , 0 , 20 , sizeof ( mdlrefDW ->
rtdw . ezmqyj1gr1 ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . fub4i3nxul ) , rtdwData , 0 , 21 , sizeof ( mdlrefDW ->
rtdw . fub4i3nxul ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . jdcxgsn5ce ) , rtdwData , 0 , 22 , sizeof ( mdlrefDW ->
rtdw . jdcxgsn5ce ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . grjqtyru3u ) , rtdwData , 0 , 23 , sizeof ( mdlrefDW ->
rtdw . grjqtyru3u ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . oi5u3pitda ) , rtdwData , 0 , 24 , sizeof ( mdlrefDW ->
rtdw . oi5u3pitda ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . asufhs1ugh ) , rtdwData , 0 , 25 , sizeof ( mdlrefDW ->
rtdw . asufhs1ugh ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . fpfsjsly5b ) , rtdwData , 0 , 26 , sizeof ( mdlrefDW ->
rtdw . fpfsjsly5b ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . bhbvy4ifhi ) , rtdwData , 0 , 27 , sizeof ( mdlrefDW ->
rtdw . bhbvy4ifhi ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . aoyjxzbpzc ) , rtdwData , 0 , 28 , sizeof ( mdlrefDW ->
rtdw . aoyjxzbpzc ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . cphsgbzvky ) , rtdwData , 0 , 29 , sizeof ( mdlrefDW ->
rtdw . cphsgbzvky ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . oyjel415x0 ) , rtdwData , 0 , 30 , sizeof ( mdlrefDW ->
rtdw . oyjel415x0 ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . f3aef3z5gb ) , rtdwData , 0 , 31 , sizeof ( mdlrefDW ->
rtdw . f3aef3z5gb ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . bpdlxsw4ck ) , rtdwData , 0 , 32 , sizeof ( mdlrefDW ->
rtdw . bpdlxsw4ck ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . dq3yf2kc54 ) , rtdwData , 0 , 33 , sizeof ( mdlrefDW ->
rtdw . dq3yf2kc54 ) ) ; mr_LaneDetection_restoreDataFromMxArray ( & (
mdlrefDW -> rtdw . dadv2akfp4 ) , rtdwData , 0 , 34 , sizeof ( mdlrefDW ->
rtdw . dadv2akfp4 ) ) ; } } void mr_LaneDetection_RegisterSimStateChecksum (
SimStruct * S ) { const uint32_T chksum [ 4 ] = { 4016238724U , 725399851U ,
2757904227U , 683318713U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"LaneDetection" , & chksum [ 0 ] ) ; } mxArray *
mr_LaneDetection_GetSimStateDisallowedBlocks ( ) { return NULL ; }
