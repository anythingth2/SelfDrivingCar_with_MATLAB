function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Color Space
 Conversion */
	this.urlHashMap["lane_departure:29"] = "lane_departure.c:341,348&lane_departure.h:207";
	/* <Root>/Constant */
	this.urlHashMap["lane_departure:23"] = "msg=rtwMsg_reducedBlock&block=lane_departure:23";
	/* <Root>/Constant1 */
	this.urlHashMap["lane_departure:31"] = "msg=rtwMsg_reducedBlock&block=lane_departure:31";
	/* <Root>/Constant2 */
	this.urlHashMap["lane_departure:72"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:72";
	/* <Root>/Constant3 */
	this.urlHashMap["lane_departure:73"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:73";
	/* <Root>/Draw Shapes */
	this.urlHashMap["lane_departure:75"] = "lane_departure.c:1377,1732&lane_departure.h:138";
	/* <Root>/Edge Detection */
	this.urlHashMap["lane_departure:30"] = "lane_departure.c:940,1100,2505,2667&lane_departure.h:145,168,169,170,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,206,223,228,233,238,243,248&lane_departure_data.c:62,67,72,77,82,87";
	/* <Root>/Erosion */
	this.urlHashMap["lane_departure:91"] = "lane_departure.c:350,938,2395,2503&lane_departure.h:141,171,172,173,174,179,180,181";
	/* <Root>/Find Local Maxima */
	this.urlHashMap["lane_departure:64"] = "lane_departure.c:1107,1210&lane_departure.h:146,178,200";
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["lane_departure:92"] = "lane_departure.h:175,176,177";
	/* <Root>/Hough Lines */
	this.urlHashMap["lane_departure:65"] = "lane_departure.c:1283,1375&lane_departure.h:147,205";
	/* <Root>/Hough Transform */
	this.urlHashMap["lane_departure:63"] = "lane_departure.c:1102&lane_departure.h:136,143,144,213,218&lane_departure_data.c:23,57";
	/* <Root>/Selector */
	this.urlHashMap["lane_departure:66"] = "lane_departure.c:1212,1225&lane_departure.h:150,201";
	/* <Root>/Selector1 */
	this.urlHashMap["lane_departure:67"] = "lane_departure.c:1227,1245&lane_departure.h:148,202";
	/* <Root>/Selector2 */
	this.urlHashMap["lane_departure:68"] = "lane_departure.c:1247,1261&lane_departure.h:203";
	/* <Root>/Selector5 */
	this.urlHashMap["lane_departure:71"] = "lane_departure.c:1263,1281&lane_departure.h:149,204";
	/* <Root>/Video Viewer */
	this.urlHashMap["lane_departure:76"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:76";
	/* <S1>/From Multimedia File */
	this.urlHashMap["lane_departure:1"] = "msg=rtwMsg_reducedBlock&block=lane_departure:1";
	/* <S1>/MATLAB Function */
	this.urlHashMap["lane_departure:107"] = "lane_departure.c:247,322,340&lane_departure.h:91,139";
	/* <S1>/Matrix
Concatenate */
	this.urlHashMap["lane_departure:94"] = "lane_departure.h:137";
	/* <S1>/V4L2 Video Capture */
	this.urlHashMap["lane_departure:93"] = "lane_departure.c:317,2391&lane_departure.h:253&lane_departure_data.c:92";
	/* <S2>:1 */
	this.urlHashMap["lane_departure:107:1"] = "lane_departure.c:323";
	/* <S2>:1:2 */
	this.urlHashMap["lane_departure:107:1:2"] = "lane_departure.c:324";
	/* <S2>:1:3 */
	this.urlHashMap["lane_departure:107:1:3"] = "lane_departure.c:328";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "lane_departure"};
	this.sidHashMap["lane_departure"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "lane_departure:96"};
	this.sidHashMap["lane_departure:96"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "lane_departure:107"};
	this.sidHashMap["lane_departure:107"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/Color Space  Conversion"] = {sid: "lane_departure:29"};
	this.sidHashMap["lane_departure:29"] = {rtwname: "<Root>/Color Space  Conversion"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "lane_departure:23"};
	this.sidHashMap["lane_departure:23"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Constant1"] = {sid: "lane_departure:31"};
	this.sidHashMap["lane_departure:31"] = {rtwname: "<Root>/Constant1"};
	this.rtwnameHashMap["<Root>/Constant2"] = {sid: "lane_departure:72"};
	this.sidHashMap["lane_departure:72"] = {rtwname: "<Root>/Constant2"};
	this.rtwnameHashMap["<Root>/Constant3"] = {sid: "lane_departure:73"};
	this.sidHashMap["lane_departure:73"] = {rtwname: "<Root>/Constant3"};
	this.rtwnameHashMap["<Root>/Draw Shapes"] = {sid: "lane_departure:75"};
	this.sidHashMap["lane_departure:75"] = {rtwname: "<Root>/Draw Shapes"};
	this.rtwnameHashMap["<Root>/Edge Detection"] = {sid: "lane_departure:30"};
	this.sidHashMap["lane_departure:30"] = {rtwname: "<Root>/Edge Detection"};
	this.rtwnameHashMap["<Root>/Erosion"] = {sid: "lane_departure:91"};
	this.sidHashMap["lane_departure:91"] = {rtwname: "<Root>/Erosion"};
	this.rtwnameHashMap["<Root>/Find Local Maxima"] = {sid: "lane_departure:64"};
	this.sidHashMap["lane_departure:64"] = {rtwname: "<Root>/Find Local Maxima"};
	this.rtwnameHashMap["<Root>/Frame Rate Display"] = {sid: "lane_departure:92"};
	this.sidHashMap["lane_departure:92"] = {rtwname: "<Root>/Frame Rate Display"};
	this.rtwnameHashMap["<Root>/Hough Lines"] = {sid: "lane_departure:65"};
	this.sidHashMap["lane_departure:65"] = {rtwname: "<Root>/Hough Lines"};
	this.rtwnameHashMap["<Root>/Hough Transform"] = {sid: "lane_departure:63"};
	this.sidHashMap["lane_departure:63"] = {rtwname: "<Root>/Hough Transform"};
	this.rtwnameHashMap["<Root>/Input "] = {sid: "lane_departure:96"};
	this.sidHashMap["lane_departure:96"] = {rtwname: "<Root>/Input "};
	this.rtwnameHashMap["<Root>/Selector"] = {sid: "lane_departure:66"};
	this.sidHashMap["lane_departure:66"] = {rtwname: "<Root>/Selector"};
	this.rtwnameHashMap["<Root>/Selector1"] = {sid: "lane_departure:67"};
	this.sidHashMap["lane_departure:67"] = {rtwname: "<Root>/Selector1"};
	this.rtwnameHashMap["<Root>/Selector2"] = {sid: "lane_departure:68"};
	this.sidHashMap["lane_departure:68"] = {rtwname: "<Root>/Selector2"};
	this.rtwnameHashMap["<Root>/Selector5"] = {sid: "lane_departure:71"};
	this.sidHashMap["lane_departure:71"] = {rtwname: "<Root>/Selector5"};
	this.rtwnameHashMap["<Root>/Video Viewer"] = {sid: "lane_departure:76"};
	this.sidHashMap["lane_departure:76"] = {rtwname: "<Root>/Video Viewer"};
	this.rtwnameHashMap["<S1>/From Multimedia File"] = {sid: "lane_departure:1"};
	this.sidHashMap["lane_departure:1"] = {rtwname: "<S1>/From Multimedia File"};
	this.rtwnameHashMap["<S1>/MATLAB Function"] = {sid: "lane_departure:107"};
	this.sidHashMap["lane_departure:107"] = {rtwname: "<S1>/MATLAB Function"};
	this.rtwnameHashMap["<S1>/Matrix Concatenate"] = {sid: "lane_departure:94"};
	this.sidHashMap["lane_departure:94"] = {rtwname: "<S1>/Matrix Concatenate"};
	this.rtwnameHashMap["<S1>/V4L2 Video Capture"] = {sid: "lane_departure:93"};
	this.sidHashMap["lane_departure:93"] = {rtwname: "<S1>/V4L2 Video Capture"};
	this.rtwnameHashMap["<S1>/Image"] = {sid: "lane_departure:98"};
	this.sidHashMap["lane_departure:98"] = {rtwname: "<S1>/Image"};
	this.rtwnameHashMap["<S2>:1"] = {sid: "lane_departure:107:1"};
	this.sidHashMap["lane_departure:107:1"] = {rtwname: "<S2>:1"};
	this.rtwnameHashMap["<S2>:1:2"] = {sid: "lane_departure:107:1:2"};
	this.sidHashMap["lane_departure:107:1:2"] = {rtwname: "<S2>:1:2"};
	this.rtwnameHashMap["<S2>:1:3"] = {sid: "lane_departure:107:1:3"};
	this.sidHashMap["lane_departure:107:1:3"] = {rtwname: "<S2>:1:3"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
