function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Display */
	this.urlHashMap["lane_departure:440"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:440";
	/* <Root>/Display2 */
	this.urlHashMap["lane_departure:540"] = "msg=&block=lane_departure:540";
	/* <Root>/Display4 */
	this.urlHashMap["lane_departure:526"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:526";
	/* <Root>/DummySupporLefttLine */
	this.urlHashMap["lane_departure:524"] = "lane_departure.c:169,264&lane_departure.h:181&lane_departure_data.c:23";
	/* <Root>/Edge Image */
	this.urlHashMap["lane_departure:432"] = "msg=rtwMsg_notTraceable&block=lane_departure:432";
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["lane_departure:92"] = "lane_departure.h:159,160,161";
	/* <Root>/Input
 */
	this.urlHashMap["lane_departure:96"] = "lane_departure.h:149";
	/* <Root>/Lane Image */
	this.urlHashMap["lane_departure:431"] = "msg=rtwMsg_notTraceable&block=lane_departure:431";
	/* <Root>/LaneDetection */
	this.urlHashMap["lane_departure:429"] = "lane_departure.c:168,255,263&lane_departure.h:143,144,145,150,153,154,166,167,168,169";
	/* <Root>/Scope */
	this.urlHashMap["lane_departure:527"] = "lane_departure.h:164";
	/* <Root>/Angle */
	this.urlHashMap["lane_departure:525"] = "lane_departure.c:179&lane_departure.h:174";
	/* <Root>/Brightness */
	this.urlHashMap["lane_departure:538"] = "lane_departure.c:135&lane_departure.h:175";
	/* <S1>/From Multimedia File */
	this.urlHashMap["lane_departure:186"] = "msg=rtwMsg_notTraceable&block=lane_departure:186";
	/* <S1>/Input */
	this.urlHashMap["lane_departure:258"] = "msg=rtwMsg_notTraceable&block=lane_departure:258";
	/* <S1>/MATLAB Function */
	this.urlHashMap["lane_departure:107"] = "lane_departure.c:110,125&lane_departure.h:98,151&phlnjecbbimokfkf_imrotate.c:14";
	/* <S1>/MATLAB Function1 */
	this.urlHashMap["lane_departure:260"] = "msg=rtwMsg_notTraceable&block=lane_departure:260";
	/* <S1>/Stop Simulation */
	this.urlHashMap["lane_departure:507"] = "msg=rtwMsg_notTraceable&block=lane_departure:507";
	/* <S1>/V4L2 Video Capture */
	this.urlHashMap["lane_departure:93"] = "lane_departure.c:46,106,259&lane_departure.h:146,147,148";
	/* <S2>:1 */
	this.urlHashMap["lane_departure:107:1"] = "lane_departure.c:111";
	/* <S2>:1:2 */
	this.urlHashMap["lane_departure:107:1:2"] = "lane_departure.c:112";
	/* <S2>:1:3 */
	this.urlHashMap["lane_departure:107:1:3"] = "lane_departure.c:116";
	/* <S3>:1 */
	this.urlHashMap["lane_departure:260:1"] = "msg=rtwMsg_notTraceable&block=lane_departure:260:1";
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
	this.rtwnameHashMap["<S3>"] = {sid: "lane_departure:260"};
	this.sidHashMap["lane_departure:260"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "lane_departure:440"};
	this.sidHashMap["lane_departure:440"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Display2"] = {sid: "lane_departure:540"};
	this.sidHashMap["lane_departure:540"] = {rtwname: "<Root>/Display2"};
	this.rtwnameHashMap["<Root>/Display4"] = {sid: "lane_departure:526"};
	this.sidHashMap["lane_departure:526"] = {rtwname: "<Root>/Display4"};
	this.rtwnameHashMap["<Root>/DummySupporLefttLine"] = {sid: "lane_departure:524"};
	this.sidHashMap["lane_departure:524"] = {rtwname: "<Root>/DummySupporLefttLine"};
	this.rtwnameHashMap["<Root>/Edge Image"] = {sid: "lane_departure:432"};
	this.sidHashMap["lane_departure:432"] = {rtwname: "<Root>/Edge Image"};
	this.rtwnameHashMap["<Root>/Frame Rate Display"] = {sid: "lane_departure:92"};
	this.sidHashMap["lane_departure:92"] = {rtwname: "<Root>/Frame Rate Display"};
	this.rtwnameHashMap["<Root>/Input "] = {sid: "lane_departure:96"};
	this.sidHashMap["lane_departure:96"] = {rtwname: "<Root>/Input "};
	this.rtwnameHashMap["<Root>/Lane Image"] = {sid: "lane_departure:431"};
	this.sidHashMap["lane_departure:431"] = {rtwname: "<Root>/Lane Image"};
	this.rtwnameHashMap["<Root>/LaneDetection"] = {sid: "lane_departure:429"};
	this.sidHashMap["lane_departure:429"] = {rtwname: "<Root>/LaneDetection"};
	this.rtwnameHashMap["<Root>/Scope"] = {sid: "lane_departure:527"};
	this.sidHashMap["lane_departure:527"] = {rtwname: "<Root>/Scope"};
	this.rtwnameHashMap["<Root>/Angle"] = {sid: "lane_departure:525"};
	this.sidHashMap["lane_departure:525"] = {rtwname: "<Root>/Angle"};
	this.rtwnameHashMap["<Root>/Brightness"] = {sid: "lane_departure:538"};
	this.sidHashMap["lane_departure:538"] = {rtwname: "<Root>/Brightness"};
	this.rtwnameHashMap["<S1>/From Multimedia File"] = {sid: "lane_departure:186"};
	this.sidHashMap["lane_departure:186"] = {rtwname: "<S1>/From Multimedia File"};
	this.rtwnameHashMap["<S1>/Input"] = {sid: "lane_departure:258"};
	this.sidHashMap["lane_departure:258"] = {rtwname: "<S1>/Input"};
	this.rtwnameHashMap["<S1>/MATLAB Function"] = {sid: "lane_departure:107"};
	this.sidHashMap["lane_departure:107"] = {rtwname: "<S1>/MATLAB Function"};
	this.rtwnameHashMap["<S1>/MATLAB Function1"] = {sid: "lane_departure:260"};
	this.sidHashMap["lane_departure:260"] = {rtwname: "<S1>/MATLAB Function1"};
	this.rtwnameHashMap["<S1>/Stop Simulation"] = {sid: "lane_departure:507"};
	this.sidHashMap["lane_departure:507"] = {rtwname: "<S1>/Stop Simulation"};
	this.rtwnameHashMap["<S1>/Terminator"] = {sid: "lane_departure:141"};
	this.sidHashMap["lane_departure:141"] = {rtwname: "<S1>/Terminator"};
	this.rtwnameHashMap["<S1>/Terminator1"] = {sid: "lane_departure:142"};
	this.sidHashMap["lane_departure:142"] = {rtwname: "<S1>/Terminator1"};
	this.rtwnameHashMap["<S1>/Terminator2"] = {sid: "lane_departure:187"};
	this.sidHashMap["lane_departure:187"] = {rtwname: "<S1>/Terminator2"};
	this.rtwnameHashMap["<S1>/Terminator3"] = {sid: "lane_departure:188"};
	this.sidHashMap["lane_departure:188"] = {rtwname: "<S1>/Terminator3"};
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
	this.rtwnameHashMap["<S3>:1"] = {sid: "lane_departure:260:1"};
	this.sidHashMap["lane_departure:260:1"] = {rtwname: "<S3>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
