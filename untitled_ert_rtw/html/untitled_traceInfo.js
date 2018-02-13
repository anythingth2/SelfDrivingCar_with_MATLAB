function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/SDL Video Display */
	this.urlHashMap["untitled:2"] = "untitled.c:146,164";
	/* <Root>/V4L2 Video Capture */
	this.urlHashMap["untitled:1"] = "untitled.c:33,136,152&untitled.h:76,77,78,93&untitled_data.c:22";
	/* <S1>/Level-2 MATLAB
S-Function */
	this.urlHashMap["untitled:2:10"] = "msg=rtwMsg_notTraceable&block=untitled:2:10";
	/* <S1>/MATLAB System */
	this.urlHashMap["untitled:2:11"] = "untitled.c:39,47,48,140,155,156,163&untitled.h:86,87";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled"};
	this.sidHashMap["untitled"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "untitled:2"};
	this.sidHashMap["untitled:2"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/SDL Video Display"] = {sid: "untitled:2"};
	this.sidHashMap["untitled:2"] = {rtwname: "<Root>/SDL Video Display"};
	this.rtwnameHashMap["<Root>/V4L2 Video Capture"] = {sid: "untitled:1"};
	this.sidHashMap["untitled:1"] = {rtwname: "<Root>/V4L2 Video Capture"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "untitled:2:14"};
	this.sidHashMap["untitled:2:14"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/In2"] = {sid: "untitled:2:15"};
	this.sidHashMap["untitled:2:15"] = {rtwname: "<S1>/In2"};
	this.rtwnameHashMap["<S1>/In3"] = {sid: "untitled:2:16"};
	this.sidHashMap["untitled:2:16"] = {rtwname: "<S1>/In3"};
	this.rtwnameHashMap["<S1>/Level-2 MATLAB S-Function"] = {sid: "untitled:2:10"};
	this.sidHashMap["untitled:2:10"] = {rtwname: "<S1>/Level-2 MATLAB S-Function"};
	this.rtwnameHashMap["<S1>/MATLAB System"] = {sid: "untitled:2:11"};
	this.sidHashMap["untitled:2:11"] = {rtwname: "<S1>/MATLAB System"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
