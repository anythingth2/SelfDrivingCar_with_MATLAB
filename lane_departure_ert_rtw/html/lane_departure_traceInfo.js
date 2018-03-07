function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["lane_departure:92"] = "lane_departure.h:160,161,162";
	/* <Root>/LaneDetection */
	this.urlHashMap["lane_departure:429"] = "lane_departure.c:160,236,248&lane_departure.h:143,147,149,150,164,165,166";
	/* <Root>/ROI */
	this.urlHashMap["lane_departure:430"] = "lane_departure.c:153,240&lane_departure.h:146,163";
	/* <Root>/ROI_X */
	this.urlHashMap["lane_departure:180"] = "lane_departure.c:154&lane_departure.h:172&lane_departure_data.c:23";
	/* <Root>/ROI_Y */
	this.urlHashMap["lane_departure:181"] = "lane_departure.c:155&lane_departure.h:175&lane_departure_data.c:50";
	/* <Root>/Video Viewer */
	this.urlHashMap["lane_departure:308"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:308";
	/* <Root>/Video Viewer1 */
	this.urlHashMap["lane_departure:431"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:431";
	/* <Root>/Video Viewer2 */
	this.urlHashMap["lane_departure:432"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:432";
	/* <S1>/From Multimedia File */
	this.urlHashMap["lane_departure:186"] = "msg=rtwMsg_notTraceable&block=lane_departure:186";
	/* <S1>/MATLAB Function */
	this.urlHashMap["lane_departure:107"] = "lane_departure.c:85,137,152&lane_departure.h:96,148";
	/* <S1>/MATLAB Function1 */
	this.urlHashMap["lane_departure:260"] = "msg=rtwMsg_notTraceable&block=lane_departure:260";
	/* <S1>/V4L2 Video Capture */
	this.urlHashMap["lane_departure:93"] = "lane_departure.c:42,133,244&lane_departure.h:141,144,145";
	/* <S1>/Video Viewer */
	this.urlHashMap["lane_departure:258"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=lane_departure:258";
	/* <S2>:1 */
	this.urlHashMap["lane_departure:107:1"] = "lane_departure.c:138";
	/* <S2>:1:2 */
	this.urlHashMap["lane_departure:107:1:2"] = "lane_departure.c:139";
	/* <S2>:1:3 */
	this.urlHashMap["lane_departure:107:1:3"] = "lane_departure.c:143";
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
	this.rtwnameHashMap["<Root>/Frame Rate Display"] = {sid: "lane_departure:92"};
	this.sidHashMap["lane_departure:92"] = {rtwname: "<Root>/Frame Rate Display"};
	this.rtwnameHashMap["<Root>/Input "] = {sid: "lane_departure:96"};
	this.sidHashMap["lane_departure:96"] = {rtwname: "<Root>/Input "};
	this.rtwnameHashMap["<Root>/LaneDetection"] = {sid: "lane_departure:429"};
	this.sidHashMap["lane_departure:429"] = {rtwname: "<Root>/LaneDetection"};
	this.rtwnameHashMap["<Root>/ROI"] = {sid: "lane_departure:430"};
	this.sidHashMap["lane_departure:430"] = {rtwname: "<Root>/ROI"};
	this.rtwnameHashMap["<Root>/ROI_X"] = {sid: "lane_departure:180"};
	this.sidHashMap["lane_departure:180"] = {rtwname: "<Root>/ROI_X"};
	this.rtwnameHashMap["<Root>/ROI_Y"] = {sid: "lane_departure:181"};
	this.sidHashMap["lane_departure:181"] = {rtwname: "<Root>/ROI_Y"};
	this.rtwnameHashMap["<Root>/Video Viewer"] = {sid: "lane_departure:308"};
	this.sidHashMap["lane_departure:308"] = {rtwname: "<Root>/Video Viewer"};
	this.rtwnameHashMap["<Root>/Video Viewer1"] = {sid: "lane_departure:431"};
	this.sidHashMap["lane_departure:431"] = {rtwname: "<Root>/Video Viewer1"};
	this.rtwnameHashMap["<Root>/Video Viewer2"] = {sid: "lane_departure:432"};
	this.sidHashMap["lane_departure:432"] = {rtwname: "<Root>/Video Viewer2"};
	this.rtwnameHashMap["<S1>/From Multimedia File"] = {sid: "lane_departure:186"};
	this.sidHashMap["lane_departure:186"] = {rtwname: "<S1>/From Multimedia File"};
	this.rtwnameHashMap["<S1>/MATLAB Function"] = {sid: "lane_departure:107"};
	this.sidHashMap["lane_departure:107"] = {rtwname: "<S1>/MATLAB Function"};
	this.rtwnameHashMap["<S1>/MATLAB Function1"] = {sid: "lane_departure:260"};
	this.sidHashMap["lane_departure:260"] = {rtwname: "<S1>/MATLAB Function1"};
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
	this.rtwnameHashMap["<S1>/Video Viewer"] = {sid: "lane_departure:258"};
	this.sidHashMap["lane_departure:258"] = {rtwname: "<S1>/Video Viewer"};
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
