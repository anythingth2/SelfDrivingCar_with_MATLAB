#include "__cf_Region_of_Interest.h"
#ifndef RTW_HEADER_Region_of_Interest_cap_host_h_
#define RTW_HEADER_Region_of_Interest_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
Region_of_Interest_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void Region_of_Interest_host_InitializeDataMapInfo (
Region_of_Interest_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
