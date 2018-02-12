function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/BOTTOM VIEW
 */
	this.urlHashMap["lane_departure:27"] = "msg=rtwMsg_notTraceable&block=lane_departure:27";
	/* <Root>/Color Space
 Conversion */
	this.urlHashMap["lane_departure:29"] = "lane_departure.c:306,315&lane_departure.h:157";
	/* <Root>/Constant */
	this.urlHashMap["lane_departure:23"] = "msg=rtwMsg_reducedBlock&block=lane_departure:23";
	/* <Root>/Constant1 */
	this.urlHashMap["lane_departure:31"] = "msg=rtwMsg_reducedBlock&block=lane_departure:31";
	/* <Root>/Constant2 */
	this.urlHashMap["lane_departure:72"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:72";
	/* <Root>/Constant3 */
	this.urlHashMap["lane_departure:73"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:73";
	/* <Root>/Draw Shapes */
	this.urlHashMap["lane_departure:75"] = "lane_departure.c:1330,1673&lane_departure.h:93";
	/* <Root>/Edge Detection */
	this.urlHashMap["lane_departure:30"] = "lane_departure.c:895,1051,2445,2607&lane_departure.h:98,118,119,120,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,156,173,178,183,188,193,198&lane_departure_data.c:62,67,72,77,82,87";
	/* <Root>/Erosion */
	this.urlHashMap["lane_departure:91"] = "lane_departure.c:317,893,2335,2443&lane_departure.h:94,121,122,123,124,129,130,131";
	/* <Root>/Find Local Maxima */
	this.urlHashMap["lane_departure:64"] = "lane_departure.c:1058,1163&lane_departure.h:99,128,150";
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["lane_departure:92"] = "lane_departure.h:125,126,127";
	/* <Root>/Hough Lines */
	this.urlHashMap["lane_departure:65"] = "lane_departure.c:1236,1328&lane_departure.h:100,155";
	/* <Root>/Hough Transform */
	this.urlHashMap["lane_departure:63"] = "lane_departure.c:1053&lane_departure.h:91,96,97,163,168&lane_departure_data.c:23,57";
	/* <Root>/Selector */
	this.urlHashMap["lane_departure:66"] = "lane_departure.c:1165,1178&lane_departure.h:103,151";
	/* <Root>/Selector1 */
	this.urlHashMap["lane_departure:67"] = "lane_departure.c:1180,1198&lane_departure.h:101,152";
	/* <Root>/Selector2 */
	this.urlHashMap["lane_departure:68"] = "lane_departure.c:1200,1214&lane_departure.h:153";
	/* <Root>/Selector5 */
	this.urlHashMap["lane_departure:71"] = "lane_departure.c:1216,1234&lane_departure.h:102,154";
	/* <Root>/Video Viewer */
	this.urlHashMap["lane_departure:76"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:76";
	/* <Root>/Video Viewer1 */
	this.urlHashMap["lane_departure:83"] = "msg=rtwMsg_notTraceable&block=lane_departure:83";
	/* <Root>/Video Viewer2 */
	this.urlHashMap["lane_departure:84"] = "msg=rtwMsg_notTraceable&block=lane_departure:84";
	/* <Root>/roi
 */
	this.urlHashMap["lane_departure:17"] = "msg=rtwMsg_notTraceable&block=lane_departure:17";
	/* <S1>/From Multimedia File */
	this.urlHashMap["lane_departure:1"] = "msg=rtwMsg_reducedBlock&block=lane_departure:1";
	/* <S1>/Matrix
Concatenate */
	this.urlHashMap["lane_departure:94"] = "lane_departure.h:92";
	/* <S1>/V4L2 Video Capture */
	this.urlHashMap["lane_departure:93"] = "lane_departure.c:301,2331&lane_departure.h:203&lane_departure_data.c:92";
	/* <S2>:1 */
	this.urlHashMap["lane_departure:17:1"] = "msg=rtwMsg_notTraceable&block=lane_departure:17:1";
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
	this.rtwnameHashMap["<S2>"] = {sid: "lane_departure:17"};
	this.sidHashMap["lane_departure:17"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/BOTTOM VIEW "] = {sid: "lane_departure:27"};
	this.sidHashMap["lane_departure:27"] = {rtwname: "<Root>/BOTTOM VIEW "};
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
	this.rtwnameHashMap["<Root>/Video Viewer1"] = {sid: "lane_departure:83"};
	this.sidHashMap["lane_departure:83"] = {rtwname: "<Root>/Video Viewer1"};
	this.rtwnameHashMap["<Root>/Video Viewer2"] = {sid: "lane_departure:84"};
	this.sidHashMap["lane_departure:84"] = {rtwname: "<Root>/Video Viewer2"};
	this.rtwnameHashMap["<Root>/roi "] = {sid: "lane_departure:17"};
	this.sidHashMap["lane_departure:17"] = {rtwname: "<Root>/roi "};
	this.rtwnameHashMap["<S1>/From Multimedia File"] = {sid: "lane_departure:1"};
	this.sidHashMap["lane_departure:1"] = {rtwname: "<S1>/From Multimedia File"};
	this.rtwnameHashMap["<S1>/Matrix Concatenate"] = {sid: "lane_departure:94"};
	this.sidHashMap["lane_departure:94"] = {rtwname: "<S1>/Matrix Concatenate"};
	this.rtwnameHashMap["<S1>/V4L2 Video Capture"] = {sid: "lane_departure:93"};
	this.sidHashMap["lane_departure:93"] = {rtwname: "<S1>/V4L2 Video Capture"};
	this.rtwnameHashMap["<S1>/Image"] = {sid: "lane_departure:98"};
	this.sidHashMap["lane_departure:98"] = {rtwname: "<S1>/Image"};
	this.rtwnameHashMap["<S2>:1"] = {sid: "lane_departure:17:1"};
	this.sidHashMap["lane_departure:17:1"] = {rtwname: "<S2>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
