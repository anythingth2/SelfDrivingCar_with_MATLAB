function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Autothreshold */
	this.urlHashMap["testpi:16"] = "msg=rtwMsg_reducedBlock&block=testpi:16";
	/* <Root>/Color Space
 Conversion */
	this.urlHashMap["testpi:18"] = "testpi.c:224,233&testpi.h:107,144";
	/* <Root>/Constant */
	this.urlHashMap["testpi:28"] = "msg=rtwMsg_reducedBlock&block=testpi:28";
	/* <Root>/Constant1 */
	this.urlHashMap["testpi:29"] = "msg=rtwMsg_reducedBlock&block=testpi:29";
	/* <Root>/Edge Detection */
	this.urlHashMap["testpi:30"] = "testpi.c:234,396,498,660&testpi.h:112,117,118,119,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,150,155,160,165,170,175&testpi_data.c:23,28,33,38,43,48";
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["testpi:36"] = "testpi.h:120,121,122";
	/* <Root>/Hough Lines */
	this.urlHashMap["testpi:46"] = "msg=rtwMsg_reducedBlock&block=testpi:46";
	/* <Root>/Hough Transform */
	this.urlHashMap["testpi:47"] = "msg=rtwMsg_reducedBlock&block=testpi:47";
	/* <Root>/SDL Video Display */
	this.urlHashMap["testpi:12"] = "testpi.c:667";
	/* <Root>/Switch */
	this.urlHashMap["testpi:27"] = "msg=rtwMsg_reducedBlock&block=testpi:27";
	/* <Root>/V4L2 Video Capture */
	this.urlHashMap["testpi:13"] = "testpi.c:220,494&testpi.h:104,105,106,180&testpi_data.c:53";
	/* <S1>/Constant2 */
	this.urlHashMap["testpi:43"] = "testpi.c:399";
	/* <S1>/Divide */
	this.urlHashMap["testpi:44"] = "testpi.c:400";
	/* <S1>/Image Data Type
Conversion */
	this.urlHashMap["testpi:45"] = "testpi.c:398,409&testpi.h:108";
	/* <S2>/Level-2 MATLAB
S-Function */
	this.urlHashMap["testpi:12:10"] = "msg=rtwMsg_notTraceable&block=testpi:12:10";
	/* <S2>/MATLAB System */
	this.urlHashMap["testpi:12:11"] = "testpi.c:412,413,661&testpi.h:123,124";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "testpi"};
	this.sidHashMap["testpi"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "testpi:38"};
	this.sidHashMap["testpi:38"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "testpi:12"};
	this.sidHashMap["testpi:12"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/Autothreshold"] = {sid: "testpi:16"};
	this.sidHashMap["testpi:16"] = {rtwname: "<Root>/Autothreshold"};
	this.rtwnameHashMap["<Root>/Binary to RGB"] = {sid: "testpi:38"};
	this.sidHashMap["testpi:38"] = {rtwname: "<Root>/Binary to RGB"};
	this.rtwnameHashMap["<Root>/Color Space  Conversion"] = {sid: "testpi:18"};
	this.sidHashMap["testpi:18"] = {rtwname: "<Root>/Color Space  Conversion"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "testpi:28"};
	this.sidHashMap["testpi:28"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "testpi:29"};
	this.sidHashMap["testpi:29"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Edge Detection"] = {sid: "testpi:30"};
	this.sidHashMap["testpi:30"] = {rtwname: "<Root>/Edge Detection"};
	this.rtwnameHashMap["<Root>/Frame Rate Display"] = {sid: "testpi:36"};
	this.sidHashMap["testpi:36"] = {rtwname: "<Root>/Frame Rate Display"};
	this.rtwnameHashMap["<Root>/Hough Lines"] = {sid: "testpi:46"};
	this.sidHashMap["testpi:46"] = {rtwname: "<Root>/Hough Lines"};
	this.rtwnameHashMap["<Root>/Hough Transform"] = {sid: "testpi:47"};
	this.sidHashMap["testpi:47"] = {rtwname: "<Root>/Hough Transform"};
	this.rtwnameHashMap["<Root>/SDL Video Display"] = {sid: "testpi:12"};
	this.sidHashMap["testpi:12"] = {rtwname: "<Root>/SDL Video Display"};
	this.rtwnameHashMap["<Root>/Switch"] = {sid: "testpi:27"};
	this.sidHashMap["testpi:27"] = {rtwname: "<Root>/Switch"};
	this.rtwnameHashMap["<Root>/V4L2 Video Capture"] = {sid: "testpi:13"};
	this.sidHashMap["testpi:13"] = {rtwname: "<Root>/V4L2 Video Capture"};
	this.rtwnameHashMap["<S1>/I"] = {sid: "testpi:39"};
	this.sidHashMap["testpi:39"] = {rtwname: "<S1>/I"};
	this.rtwnameHashMap["<S1>/Constant2"] = {sid: "testpi:43"};
	this.sidHashMap["testpi:43"] = {rtwname: "<S1>/Constant2"};
	this.rtwnameHashMap["<S1>/Divide"] = {sid: "testpi:44"};
	this.sidHashMap["testpi:44"] = {rtwname: "<S1>/Divide"};
	this.rtwnameHashMap["<S1>/Image Data Type Conversion"] = {sid: "testpi:45"};
	this.sidHashMap["testpi:45"] = {rtwname: "<S1>/Image Data Type Conversion"};
	this.rtwnameHashMap["<S1>/R"] = {sid: "testpi:40"};
	this.sidHashMap["testpi:40"] = {rtwname: "<S1>/R"};
	this.rtwnameHashMap["<S1>/G"] = {sid: "testpi:41"};
	this.sidHashMap["testpi:41"] = {rtwname: "<S1>/G"};
	this.rtwnameHashMap["<S1>/B"] = {sid: "testpi:42"};
	this.sidHashMap["testpi:42"] = {rtwname: "<S1>/B"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "testpi:12:14"};
	this.sidHashMap["testpi:12:14"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/In2"] = {sid: "testpi:12:15"};
	this.sidHashMap["testpi:12:15"] = {rtwname: "<S2>/In2"};
	this.rtwnameHashMap["<S2>/In3"] = {sid: "testpi:12:16"};
	this.sidHashMap["testpi:12:16"] = {rtwname: "<S2>/In3"};
	this.rtwnameHashMap["<S2>/Level-2 MATLAB S-Function"] = {sid: "testpi:12:10"};
	this.sidHashMap["testpi:12:10"] = {rtwname: "<S2>/Level-2 MATLAB S-Function"};
	this.rtwnameHashMap["<S2>/MATLAB System"] = {sid: "testpi:12:11"};
	this.sidHashMap["testpi:12:11"] = {rtwname: "<S2>/MATLAB System"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
