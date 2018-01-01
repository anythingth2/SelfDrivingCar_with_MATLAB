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
this.def["rtB"] = {file: "testpi_c.html",line:79,type:"var"};
this.def["rtDW"] = {file: "testpi_c.html",line:82,type:"var"};
this.def["rtM_"] = {file: "testpi_c.html",line:85,type:"var"};
this.def["rtM"] = {file: "testpi_c.html",line:86,type:"var"};
this.def["mul_wide_s32"] = {file: "testpi_c.html",line:93,type:"fcn"};
this.def["mul_s32_loSR"] = {file: "testpi_c.html",line:139,type:"fcn"};
this.def["mul_wide_su32"] = {file: "testpi_c.html",line:148,type:"fcn"};
this.def["mul_ssu32_loSR"] = {file: "testpi_c.html",line:193,type:"fcn"};
this.def["testpi_step"] = {file: "testpi_c.html",line:203,type:"fcn"};
this.def["testpi_initialize"] = {file: "testpi_c.html",line:451,type:"fcn"};
this.def["RT_MODEL"] = {file: "testpi_h.html",line:79,type:"type"};
this.def["codertarget_linux_blocks_SDLVid"] = {file: "testpi_h.html",line:87,type:"type"};
this.def["struct_T"] = {file: "testpi_h.html",line:98,type:"type"};
this.def["B"] = {file: "testpi_h.html",line:113,type:"type"};
this.def["DW"] = {file: "testpi_h.html",line:145,type:"type"};
this.def["ConstP"] = {file: "testpi_h.html",line:183,type:"type"};
this.def["rtConstP"] = {file: "testpi_data_c.html",line:21,type:"var"};
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
this.def["rtDataTypeSizes"] = {file: "testpi_dt_h.html",line:21,type:"var"};
this.def["rtDataTypeNames"] = {file: "testpi_dt_h.html",line:42,type:"var"};
this.def["rtBTransitions"] = {file: "testpi_dt_h.html",line:63,type:"var"};
this.def["rtBTransTable"] = {file: "testpi_dt_h.html",line:81,type:"var"};
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
	this.html2SrcPath["testpi_c.html"] = "../testpi.c";
	this.html2Root["testpi_c.html"] = "testpi_c.html";
	this.html2SrcPath["testpi_h.html"] = "../testpi.h";
	this.html2Root["testpi_h.html"] = "testpi_h.html";
	this.html2SrcPath["testpi_data_c.html"] = "../testpi_data.c";
	this.html2Root["testpi_data_c.html"] = "testpi_data_c.html";
	this.html2SrcPath["multiword_types_h.html"] = "../multiword_types.h";
	this.html2Root["multiword_types_h.html"] = "multiword_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["testpi_dt_h.html"] = "../testpi_dt.h";
	this.html2Root["testpi_dt_h.html"] = "testpi_dt_h.html";
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
"ert_main_c.html","testpi_c.html","testpi_h.html","testpi_data_c.html","multiword_types_h.html","rtwtypes_h.html","rtmodel_h.html","testpi_dt_h.html","MW_custom_RTOS_header_h.html","MW_target_hardware_resources_h.html"];
