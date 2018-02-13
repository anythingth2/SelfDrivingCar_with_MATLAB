function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Draw Shapes */
	this.urlHashMap["lane_departure:75"] = "lane_departure.c:1257,1590&lane_departure.h:117";
	/* <Root>/Edge Detection */
	this.urlHashMap["lane_departure:30"] = "lane_departure.c:825,982,2774,2936&lane_departure.h:118,137,138,139,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,177,193,198,203,208,213,218&lane_departure_data.c:62,67,72,77,82,87";
	/* <Root>/Erosion */
	this.urlHashMap["lane_departure:91"] = "lane_departure.c:236,823,2664,2772&lane_departure.h:110,140,141,142,143,150,151,152";
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["lane_departure:92"] = "lane_departure.h:144,145,146";
	/* <Root>/SDL Video Display */
	this.urlHashMap["lane_departure:143"] = "lane_departure.c:2943";
	/* <Root>/Video Viewer1 */
	this.urlHashMap["lane_departure:140"] = "msg=rtwMsg_notTraceable&block=lane_departure:140";
	/* <S1>/MATLAB Function */
	this.urlHashMap["lane_departure:107"] = "msg=&block=lane_departure:107";
	/* <S1>/V4L2 Video Capture */
	this.urlHashMap["lane_departure:93"] = "lane_departure.c:232,2660&lane_departure.h:114,115,116,223&lane_departure_data.c:92";
	/* <S2>/Constant2 */
	this.urlHashMap["lane_departure:72"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:72";
	/* <S2>/Constant3 */
	this.urlHashMap["lane_departure:73"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:73";
	/* <S2>/Find Local Maxima */
	this.urlHashMap["lane_departure:64"] = "lane_departure.c:989,1090&lane_departure.h:119,147,171";
	/* <S2>/Hough Lines */
	this.urlHashMap["lane_departure:65"] = "lane_departure.c:1165,1255&lane_departure.h:113,176";
	/* <S2>/Hough Transform */
	this.urlHashMap["lane_departure:63"] = "lane_departure.c:984&lane_departure.h:107,111,112,183,188&lane_departure_data.c:23,57";
	/* <S2>/Selector */
	this.urlHashMap["lane_departure:66"] = "lane_departure.c:1092,1105&lane_departure.h:122,172";
	/* <S2>/Selector1 */
	this.urlHashMap["lane_departure:67"] = "lane_departure.c:1107,1126&lane_departure.h:120,173";
	/* <S2>/Selector2 */
	this.urlHashMap["lane_departure:68"] = "lane_departure.c:1128,1142&lane_departure.h:174";
	/* <S2>/Selector5 */
	this.urlHashMap["lane_departure:71"] = "lane_departure.c:1144,1163&lane_departure.h:121,175";
	/* <S3>/Image Data Type
Conversion */
	this.urlHashMap["lane_departure:139"] = "msg=rtwMsg_notTraceable&block=lane_departure:139";
	/* <S3>/Logical
Operator */
	this.urlHashMap["lane_departure:137"] = "msg=rtwMsg_notTraceable&block=lane_departure:137";
	/* <S3>/mask */
	this.urlHashMap["lane_departure:134"] = "msg=rtwMsg_notTraceable&block=lane_departure:134";
	/* <S4>/In1 */
	this.urlHashMap["lane_departure:143:14"] = "msg=&block=lane_departure:143:14";
	/* <S4>/In2 */
	this.urlHashMap["lane_departure:143:15"] = "msg=&block=lane_departure:143:15";
	/* <S4>/In3 */
	this.urlHashMap["lane_departure:143:16"] = "msg=&block=lane_departure:143:16";
	/* <S4>/Level-2 MATLAB
S-Function */
	this.urlHashMap["lane_departure:143:10"] = "msg=&block=lane_departure:143:10";
	/* <S4>/MATLAB System */
	this.urlHashMap["lane_departure:143:11"] = "lane_departure.c:1591,1592,2937&lane_departure.h:148,149";
	/* <S5>:1 */
	this.urlHashMap["lane_departure:107:1"] = "msg=&block=lane_departure:107:1";
	/* <S6>:1 */
	this.urlHashMap["lane_departure:134:1"] = "msg=rtwMsg_notTraceable&block=lane_departure:134:1";
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
	this.rtwnameHashMap["<S2>"] = {sid: "lane_departure:111"};
	this.sidHashMap["lane_departure:111"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "lane_departure:115"};
	this.sidHashMap["lane_departure:115"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "lane_departure:143"};
	this.sidHashMap["lane_departure:143"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "lane_departure:107"};
	this.sidHashMap["lane_departure:107"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "lane_departure:134"};
	this.sidHashMap["lane_departure:134"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<Root>/Draw Shapes"] = {sid: "lane_departure:75"};
	this.sidHashMap["lane_departure:75"] = {rtwname: "<Root>/Draw Shapes"};
	this.rtwnameHashMap["<Root>/Edge Detection"] = {sid: "lane_departure:30"};
	this.sidHashMap["lane_departure:30"] = {rtwname: "<Root>/Edge Detection"};
	this.rtwnameHashMap["<Root>/Erosion"] = {sid: "lane_departure:91"};
	this.sidHashMap["lane_departure:91"] = {rtwname: "<Root>/Erosion"};
	this.rtwnameHashMap["<Root>/Frame Rate Display"] = {sid: "lane_departure:92"};
	this.sidHashMap["lane_departure:92"] = {rtwname: "<Root>/Frame Rate Display"};
	this.rtwnameHashMap["<Root>/Input "] = {sid: "lane_departure:96"};
	this.sidHashMap["lane_departure:96"] = {rtwname: "<Root>/Input "};
	this.rtwnameHashMap["<Root>/Lane Departure"] = {sid: "lane_departure:111"};
	this.sidHashMap["lane_departure:111"] = {rtwname: "<Root>/Lane Departure"};
	this.rtwnameHashMap["<Root>/ROI"] = {sid: "lane_departure:115"};
	this.sidHashMap["lane_departure:115"] = {rtwname: "<Root>/ROI"};
	this.rtwnameHashMap["<Root>/SDL Video Display"] = {sid: "lane_departure:143"};
	this.sidHashMap["lane_departure:143"] = {rtwname: "<Root>/SDL Video Display"};
	this.rtwnameHashMap["<Root>/Video Viewer1"] = {sid: "lane_departure:140"};
	this.sidHashMap["lane_departure:140"] = {rtwname: "<Root>/Video Viewer1"};
	this.rtwnameHashMap["<S1>/MATLAB Function"] = {sid: "lane_departure:107"};
	this.sidHashMap["lane_departure:107"] = {rtwname: "<S1>/MATLAB Function"};
	this.rtwnameHashMap["<S1>/Terminator"] = {sid: "lane_departure:141"};
	this.sidHashMap["lane_departure:141"] = {rtwname: "<S1>/Terminator"};
	this.rtwnameHashMap["<S1>/Terminator1"] = {sid: "lane_departure:142"};
	this.sidHashMap["lane_departure:142"] = {rtwname: "<S1>/Terminator1"};
	this.rtwnameHashMap["<S1>/V4L2 Video Capture"] = {sid: "lane_departure:93"};
	this.sidHashMap["lane_departure:93"] = {rtwname: "<S1>/V4L2 Video Capture"};
	this.rtwnameHashMap["<S1>/Image"] = {sid: "lane_departure:98"};
	this.sidHashMap["lane_departure:98"] = {rtwname: "<S1>/Image"};
	this.rtwnameHashMap["<S2>/BW"] = {sid: "lane_departure:112"};
	this.sidHashMap["lane_departure:112"] = {rtwname: "<S2>/BW"};
	this.rtwnameHashMap["<S2>/Edge"] = {sid: "lane_departure:113"};
	this.sidHashMap["lane_departure:113"] = {rtwname: "<S2>/Edge"};
	this.rtwnameHashMap["<S2>/Constant2"] = {sid: "lane_departure:72"};
	this.sidHashMap["lane_departure:72"] = {rtwname: "<S2>/Constant2"};
	this.rtwnameHashMap["<S2>/Constant3"] = {sid: "lane_departure:73"};
	this.sidHashMap["lane_departure:73"] = {rtwname: "<S2>/Constant3"};
	this.rtwnameHashMap["<S2>/Find Local Maxima"] = {sid: "lane_departure:64"};
	this.sidHashMap["lane_departure:64"] = {rtwname: "<S2>/Find Local Maxima"};
	this.rtwnameHashMap["<S2>/Hough Lines"] = {sid: "lane_departure:65"};
	this.sidHashMap["lane_departure:65"] = {rtwname: "<S2>/Hough Lines"};
	this.rtwnameHashMap["<S2>/Hough Transform"] = {sid: "lane_departure:63"};
	this.sidHashMap["lane_departure:63"] = {rtwname: "<S2>/Hough Transform"};
	this.rtwnameHashMap["<S2>/Selector"] = {sid: "lane_departure:66"};
	this.sidHashMap["lane_departure:66"] = {rtwname: "<S2>/Selector"};
	this.rtwnameHashMap["<S2>/Selector1"] = {sid: "lane_departure:67"};
	this.sidHashMap["lane_departure:67"] = {rtwname: "<S2>/Selector1"};
	this.rtwnameHashMap["<S2>/Selector2"] = {sid: "lane_departure:68"};
	this.sidHashMap["lane_departure:68"] = {rtwname: "<S2>/Selector2"};
	this.rtwnameHashMap["<S2>/Selector5"] = {sid: "lane_departure:71"};
	this.sidHashMap["lane_departure:71"] = {rtwname: "<S2>/Selector5"};
	this.rtwnameHashMap["<S2>/Pts"] = {sid: "lane_departure:114"};
	this.sidHashMap["lane_departure:114"] = {rtwname: "<S2>/Pts"};
	this.rtwnameHashMap["<S3>/Image"] = {sid: "lane_departure:116"};
	this.sidHashMap["lane_departure:116"] = {rtwname: "<S3>/Image"};
	this.rtwnameHashMap["<S3>/Image Data Type Conversion"] = {sid: "lane_departure:139"};
	this.sidHashMap["lane_departure:139"] = {rtwname: "<S3>/Image Data Type Conversion"};
	this.rtwnameHashMap["<S3>/Logical Operator"] = {sid: "lane_departure:137"};
	this.sidHashMap["lane_departure:137"] = {rtwname: "<S3>/Logical Operator"};
	this.rtwnameHashMap["<S3>/mask"] = {sid: "lane_departure:134"};
	this.sidHashMap["lane_departure:134"] = {rtwname: "<S3>/mask"};
	this.rtwnameHashMap["<S3>/MaskedImage "] = {sid: "lane_departure:138"};
	this.sidHashMap["lane_departure:138"] = {rtwname: "<S3>/MaskedImage "};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "lane_departure:143:14"};
	this.sidHashMap["lane_departure:143:14"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/In2"] = {sid: "lane_departure:143:15"};
	this.sidHashMap["lane_departure:143:15"] = {rtwname: "<S4>/In2"};
	this.rtwnameHashMap["<S4>/In3"] = {sid: "lane_departure:143:16"};
	this.sidHashMap["lane_departure:143:16"] = {rtwname: "<S4>/In3"};
	this.rtwnameHashMap["<S4>/Level-2 MATLAB S-Function"] = {sid: "lane_departure:143:10"};
	this.sidHashMap["lane_departure:143:10"] = {rtwname: "<S4>/Level-2 MATLAB S-Function"};
	this.rtwnameHashMap["<S4>/MATLAB System"] = {sid: "lane_departure:143:11"};
	this.sidHashMap["lane_departure:143:11"] = {rtwname: "<S4>/MATLAB System"};
	this.rtwnameHashMap["<S5>:1"] = {sid: "lane_departure:107:1"};
	this.sidHashMap["lane_departure:107:1"] = {rtwname: "<S5>:1"};
	this.rtwnameHashMap["<S6>:1"] = {sid: "lane_departure:134:1"};
	this.sidHashMap["lane_departure:134:1"] = {rtwname: "<S6>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
