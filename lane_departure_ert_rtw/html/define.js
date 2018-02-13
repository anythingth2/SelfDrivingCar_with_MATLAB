function CodeDefine() { 
this.def = new Array();
this.def["runModel"] = {file: "ert_main_c.html",line:31,type:"var"};
this.def["stopSem"] = {file: "ert_main_c.html",line:32,type:"var"};
this.def["baserateTaskSem"] = {file: "ert_main_c.html",line:33,type:"var"};
this.def["schedulerThread"] = {file: "ert_main_c.html",line:34,type:"var"};
this.def["baseRateThread"] = {file: "ert_main_c.html",line:35,type:"var"};
this.def["threadJoinStatus"] = {file: "ert_main_c.html",line:36,type:"var"};
this.def["terminatingmodel"] = {file: "ert_main_c.html",line:37,type:"var"};
this.def["baseRateTask"] = {file: "ert_main_c.html",line:38,type:"fcn"};
this.def["exitFcn"] = {file: "ert_main_c.html",line:80,type:"fcn"};
this.def["terminateTask"] = {file: "ert_main_c.html",line:86,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:102,type:"fcn"};
this.def["rtB"] = {file: "lane_departure_c.html",line:79,type:"var"};
this.def["rtDW"] = {file: "lane_departure_c.html",line:82,type:"var"};
this.def["rtM_"] = {file: "lane_departure_c.html",line:85,type:"var"};
this.def["rtM"] = {file: "lane_departure_c.html",line:86,type:"var"};
this.def["mul_wide_s32"] = {file: "lane_departure_c.html",line:94,type:"fcn"};
this.def["mul_s32_loSR"] = {file: "lane_departure_c.html",line:140,type:"fcn"};
this.def["mul_wide_su32"] = {file: "lane_departure_c.html",line:149,type:"fcn"};
this.def["mul_ssu32_loSR"] = {file: "lane_departure_c.html",line:194,type:"fcn"};
this.def["div_nde_s32_floor"] = {file: "lane_departure_c.html",line:203,type:"fcn"};
this.def["lane_departure_step"] = {file: "lane_departure_c.html",line:210,type:"fcn"};
this.def["lane_departure_initialize"] = {file: "lane_departure_c.html",line:1630,type:"fcn"};
this.def["RT_MODEL"] = {file: "lane_departure_h.html",line:82,type:"type"};
this.def["codertarget_linux_blocks_SDLVid"] = {file: "lane_departure_h.html",line:90,type:"type"};
this.def["struct_T"] = {file: "lane_departure_h.html",line:101,type:"type"};
this.def["B"] = {file: "lane_departure_h.html",line:133,type:"type"};
this.def["DW"] = {file: "lane_departure_h.html",line:178,type:"type"};
this.def["ConstP"] = {file: "lane_departure_h.html",line:226,type:"type"};
this.def["rtConstP"] = {file: "lane_departure_data_c.html",line:21,type:"var"};
this.def["chunk_T"] = {file: "multiword_types_h.html",line:25,type:"type"};
this.def["uchunk_T"] = {file: "multiword_types_h.html",line:26,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:88,type:"type"};
this.def["rtDataTypeSizes"] = {file: "lane_departure_dt_h.html",line:21,type:"var"};
this.def["rtDataTypeNames"] = {file: "lane_departure_dt_h.html",line:45,type:"var"};
this.def["rtBTransitions"] = {file: "lane_departure_dt_h.html",line:69,type:"var"};
this.def["rtBTransTable"] = {file: "lane_departure_dt_h.html",line:91,type:"var"};
this.def["MWVIP_Hough_D"] = {file: "hough_d_rt_c.html",line:8,type:"fcn"};
this.def["MWVIP_Hough_R"] = {file: "hough_r_rt_c.html",line:8,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["lane_departure_c.html"] = "../lane_departure.c";
	this.html2Root["lane_departure_c.html"] = "lane_departure_c.html";
	this.html2SrcPath["lane_departure_h.html"] = "../lane_departure.h";
	this.html2Root["lane_departure_h.html"] = "lane_departure_h.html";
	this.html2SrcPath["lane_departure_data_c.html"] = "../lane_departure_data.c";
	this.html2Root["lane_departure_data_c.html"] = "lane_departure_data_c.html";
	this.html2SrcPath["multiword_types_h.html"] = "../multiword_types.h";
	this.html2Root["multiword_types_h.html"] = "multiword_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["lane_departure_dt_h.html"] = "../lane_departure_dt.h";
	this.html2Root["lane_departure_dt_h.html"] = "lane_departure_dt_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["hough_d_rt_c.html"] = "../../../../../../../Program Files/MATLAB/R2017a/toolbox/vision/visionrt/viphough/hough_d_rt.c";
	this.html2Root["hough_d_rt_c.html"] = "hough_d_rt_c.html";
	this.html2SrcPath["hough_r_rt_c.html"] = "../../../../../../../Program Files/MATLAB/R2017a/toolbox/vision/visionrt/viphough/hough_r_rt.c";
	this.html2Root["hough_r_rt_c.html"] = "hough_r_rt_c.html";
	this.html2SrcPath["viphough_rt_h.html"] = "../../../../../../../Program Files/MATLAB/R2017a/toolbox/vision/visionrt/export/include/visionrt/viphough_rt.h";
	this.html2Root["viphough_rt_h.html"] = "viphough_rt_h.html";
	this.html2SrcPath["MW_custom_RTOS_header_h.html"] = "../MW_custom_RTOS_header.h";
	this.html2Root["MW_custom_RTOS_header_h.html"] = "MW_custom_RTOS_header_h.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","lane_departure_c.html","lane_departure_h.html","lane_departure_data_c.html","multiword_types_h.html","rtwtypes_h.html","lane_departure_dt_h.html","rtmodel_h.html","hough_d_rt_c.html","hough_r_rt_c.html","viphough_rt_h.html","MW_custom_RTOS_header_h.html","MW_target_hardware_resources_h.html"];
