function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Draw Shapes */
	this.urlHashMap["LaneDetection:2"] = "LaneDetection.c:763,1110";
	/* <Root>/Edge Detection */
	this.urlHashMap["LaneDetection:3"] = "LaneDetection.c:103,106,109,112,115,118,126,288,317,482&LaneDetection.h:49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,76,77,78,83";
	/* <S1>/Constant2 */
	this.urlHashMap["LaneDetection:7"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:7";
	/* <S1>/Constant3 */
	this.urlHashMap["LaneDetection:8"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:8";
	/* <S1>/Find Local Maxima */
	this.urlHashMap["LaneDetection:9"] = "LaneDetection.c:489,590&LaneDetection.h:40,41,67,85";
	/* <S1>/Hough Lines */
	this.urlHashMap["LaneDetection:10"] = "LaneDetection.c:666,761";
	/* <S1>/Hough Transform */
	this.urlHashMap["LaneDetection:11"] = "LaneDetection.c:97,100,484&LaneDetection.h:37,38,39";
	/* <S1>/Selector */
	this.urlHashMap["LaneDetection:12"] = "LaneDetection.c:592,605&LaneDetection.h:44,68";
	/* <S1>/Selector1 */
	this.urlHashMap["LaneDetection:13"] = "LaneDetection.c:607,626&LaneDetection.h:69";
	/* <S1>/Selector2 */
	this.urlHashMap["LaneDetection:14"] = "LaneDetection.c:628,642&LaneDetection.h:70";
	/* <S1>/Selector5 */
	this.urlHashMap["LaneDetection:15"] = "LaneDetection.c:644,664&LaneDetection.h:71";
	/* <S2>/Constant */
	this.urlHashMap["LaneDetection:19"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:19";
	/* <S2>/Constant1 */
	this.urlHashMap["LaneDetection:20"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:20";
	/* <S2>/Constant2 */
	this.urlHashMap["LaneDetection:21"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:21";
	/* <S2>/Constant3 */
	this.urlHashMap["LaneDetection:22"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:22";
	/* <S2>/Constant4 */
	this.urlHashMap["LaneDetection:38"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:38";
	/* <S2>/Constant5 */
	this.urlHashMap["LaneDetection:40"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:40";
	/* <S2>/Divide */
	this.urlHashMap["LaneDetection:23"] = "LaneDetection.c:1206,1215";
	/* <S2>/Product */
	this.urlHashMap["LaneDetection:37"] = "LaneDetection.c:1190,1196&LaneDetection.h:42";
	/* <S2>/Product1 */
	this.urlHashMap["LaneDetection:39"] = "LaneDetection.c:1166,1172";
	/* <S2>/Selector */
	this.urlHashMap["LaneDetection:24"] = "LaneDetection.c:1112,1125&LaneDetection.h:72,80";
	/* <S2>/Selector2 */
	this.urlHashMap["LaneDetection:25"] = "LaneDetection.c:1151,1164&LaneDetection.h:74";
	/* <S2>/Selector3 */
	this.urlHashMap["LaneDetection:26"] = "LaneDetection.c:1127,1141&LaneDetection.h:73,79";
	/* <S2>/Selector4 */
	this.urlHashMap["LaneDetection:27"] = "LaneDetection.c:1174,1188&LaneDetection.h:75";
	/* <S2>/Subtract */
	this.urlHashMap["LaneDetection:28"] = "LaneDetection.c:1143,1149";
	/* <S2>/Subtract1 */
	this.urlHashMap["LaneDetection:29"] = "LaneDetection.c:1198,1204&LaneDetection.h:43";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "LaneDetection"};
	this.sidHashMap["LaneDetection"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "LaneDetection:4"};
	this.sidHashMap["LaneDetection:4"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "LaneDetection:17"};
	this.sidHashMap["LaneDetection:17"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<Root>/I"] = {sid: "LaneDetection:1"};
	this.sidHashMap["LaneDetection:1"] = {rtwname: "<Root>/I"};
	this.rtwnameHashMap["<Root>/Draw Shapes"] = {sid: "LaneDetection:2"};
	this.sidHashMap["LaneDetection:2"] = {rtwname: "<Root>/Draw Shapes"};
	this.rtwnameHashMap["<Root>/Edge Detection"] = {sid: "LaneDetection:3"};
	this.sidHashMap["LaneDetection:3"] = {rtwname: "<Root>/Edge Detection"};
	this.rtwnameHashMap["<Root>/Find Line"] = {sid: "LaneDetection:4"};
	this.sidHashMap["LaneDetection:4"] = {rtwname: "<Root>/Find Line"};
	this.rtwnameHashMap["<Root>/Find Slope"] = {sid: "LaneDetection:17"};
	this.sidHashMap["LaneDetection:17"] = {rtwname: "<Root>/Find Slope"};
	this.rtwnameHashMap["<Root>/Points"] = {sid: "LaneDetection:31"};
	this.sidHashMap["LaneDetection:31"] = {rtwname: "<Root>/Points"};
	this.rtwnameHashMap["<Root>/Slope"] = {sid: "LaneDetection:32"};
	this.sidHashMap["LaneDetection:32"] = {rtwname: "<Root>/Slope"};
	this.rtwnameHashMap["<Root>/LineImage"] = {sid: "LaneDetection:33"};
	this.sidHashMap["LaneDetection:33"] = {rtwname: "<Root>/LineImage"};
	this.rtwnameHashMap["<Root>/Edge"] = {sid: "LaneDetection:34"};
	this.sidHashMap["LaneDetection:34"] = {rtwname: "<Root>/Edge"};
	this.rtwnameHashMap["<S1>/BW"] = {sid: "LaneDetection:5"};
	this.sidHashMap["LaneDetection:5"] = {rtwname: "<S1>/BW"};
	this.rtwnameHashMap["<S1>/Edge"] = {sid: "LaneDetection:6"};
	this.sidHashMap["LaneDetection:6"] = {rtwname: "<S1>/Edge"};
	this.rtwnameHashMap["<S1>/Constant2"] = {sid: "LaneDetection:7"};
	this.sidHashMap["LaneDetection:7"] = {rtwname: "<S1>/Constant2"};
	this.rtwnameHashMap["<S1>/Constant3"] = {sid: "LaneDetection:8"};
	this.sidHashMap["LaneDetection:8"] = {rtwname: "<S1>/Constant3"};
	this.rtwnameHashMap["<S1>/Find Local Maxima"] = {sid: "LaneDetection:9"};
	this.sidHashMap["LaneDetection:9"] = {rtwname: "<S1>/Find Local Maxima"};
	this.rtwnameHashMap["<S1>/Hough Lines"] = {sid: "LaneDetection:10"};
	this.sidHashMap["LaneDetection:10"] = {rtwname: "<S1>/Hough Lines"};
	this.rtwnameHashMap["<S1>/Hough Transform"] = {sid: "LaneDetection:11"};
	this.sidHashMap["LaneDetection:11"] = {rtwname: "<S1>/Hough Transform"};
	this.rtwnameHashMap["<S1>/Selector"] = {sid: "LaneDetection:12"};
	this.sidHashMap["LaneDetection:12"] = {rtwname: "<S1>/Selector"};
	this.rtwnameHashMap["<S1>/Selector1"] = {sid: "LaneDetection:13"};
	this.sidHashMap["LaneDetection:13"] = {rtwname: "<S1>/Selector1"};
	this.rtwnameHashMap["<S1>/Selector2"] = {sid: "LaneDetection:14"};
	this.sidHashMap["LaneDetection:14"] = {rtwname: "<S1>/Selector2"};
	this.rtwnameHashMap["<S1>/Selector5"] = {sid: "LaneDetection:15"};
	this.sidHashMap["LaneDetection:15"] = {rtwname: "<S1>/Selector5"};
	this.rtwnameHashMap["<S1>/Pts"] = {sid: "LaneDetection:16"};
	this.sidHashMap["LaneDetection:16"] = {rtwname: "<S1>/Pts"};
	this.rtwnameHashMap["<S2>/Pts"] = {sid: "LaneDetection:18"};
	this.sidHashMap["LaneDetection:18"] = {rtwname: "<S2>/Pts"};
	this.rtwnameHashMap["<S2>/Constant"] = {sid: "LaneDetection:19"};
	this.sidHashMap["LaneDetection:19"] = {rtwname: "<S2>/Constant"};
	this.rtwnameHashMap["<S2>/Constant1"] = {sid: "LaneDetection:20"};
	this.sidHashMap["LaneDetection:20"] = {rtwname: "<S2>/Constant1"};
	this.rtwnameHashMap["<S2>/Constant2"] = {sid: "LaneDetection:21"};
	this.sidHashMap["LaneDetection:21"] = {rtwname: "<S2>/Constant2"};
	this.rtwnameHashMap["<S2>/Constant3"] = {sid: "LaneDetection:22"};
	this.sidHashMap["LaneDetection:22"] = {rtwname: "<S2>/Constant3"};
	this.rtwnameHashMap["<S2>/Constant4"] = {sid: "LaneDetection:38"};
	this.sidHashMap["LaneDetection:38"] = {rtwname: "<S2>/Constant4"};
	this.rtwnameHashMap["<S2>/Constant5"] = {sid: "LaneDetection:40"};
	this.sidHashMap["LaneDetection:40"] = {rtwname: "<S2>/Constant5"};
	this.rtwnameHashMap["<S2>/Divide"] = {sid: "LaneDetection:23"};
	this.sidHashMap["LaneDetection:23"] = {rtwname: "<S2>/Divide"};
	this.rtwnameHashMap["<S2>/Product"] = {sid: "LaneDetection:37"};
	this.sidHashMap["LaneDetection:37"] = {rtwname: "<S2>/Product"};
	this.rtwnameHashMap["<S2>/Product1"] = {sid: "LaneDetection:39"};
	this.sidHashMap["LaneDetection:39"] = {rtwname: "<S2>/Product1"};
	this.rtwnameHashMap["<S2>/Selector"] = {sid: "LaneDetection:24"};
	this.sidHashMap["LaneDetection:24"] = {rtwname: "<S2>/Selector"};
	this.rtwnameHashMap["<S2>/Selector2"] = {sid: "LaneDetection:25"};
	this.sidHashMap["LaneDetection:25"] = {rtwname: "<S2>/Selector2"};
	this.rtwnameHashMap["<S2>/Selector3"] = {sid: "LaneDetection:26"};
	this.sidHashMap["LaneDetection:26"] = {rtwname: "<S2>/Selector3"};
	this.rtwnameHashMap["<S2>/Selector4"] = {sid: "LaneDetection:27"};
	this.sidHashMap["LaneDetection:27"] = {rtwname: "<S2>/Selector4"};
	this.rtwnameHashMap["<S2>/Subtract"] = {sid: "LaneDetection:28"};
	this.sidHashMap["LaneDetection:28"] = {rtwname: "<S2>/Subtract"};
	this.rtwnameHashMap["<S2>/Subtract1"] = {sid: "LaneDetection:29"};
	this.sidHashMap["LaneDetection:29"] = {rtwname: "<S2>/Subtract1"};
	this.rtwnameHashMap["<S2>/Slope"] = {sid: "LaneDetection:30"};
	this.sidHashMap["LaneDetection:30"] = {rtwname: "<S2>/Slope"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
