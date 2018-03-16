function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Frame Rate
Display */
	this.urlHashMap["test:28"] = "test.h:82,83,84";
	/* <Root>/Terminator */
	this.urlHashMap["test:6"] = "msg=&block=test:6";
	/* <Root>/Terminator1 */
	this.urlHashMap["test:7"] = "msg=&block=test:7";
	/* <Root>/V4L2 Video Capture */
	this.urlHashMap["test:1"] = "test.c:33,120,128&test.h:75,76,77,90&test_data.c:22";
	/* <Root>/Video Viewer7 */
	this.urlHashMap["test:27"] = "msg=&block=test:27";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "test"};
	this.sidHashMap["test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Frame Rate Display"] = {sid: "test:28"};
	this.sidHashMap["test:28"] = {rtwname: "<Root>/Frame Rate Display"};
	this.rtwnameHashMap["<Root>/Terminator"] = {sid: "test:6"};
	this.sidHashMap["test:6"] = {rtwname: "<Root>/Terminator"};
	this.rtwnameHashMap["<Root>/Terminator1"] = {sid: "test:7"};
	this.sidHashMap["test:7"] = {rtwname: "<Root>/Terminator1"};
	this.rtwnameHashMap["<Root>/V4L2 Video Capture"] = {sid: "test:1"};
	this.sidHashMap["test:1"] = {rtwname: "<Root>/V4L2 Video Capture"};
	this.rtwnameHashMap["<Root>/Video Viewer7"] = {sid: "test:27"};
	this.sidHashMap["test:27"] = {rtwname: "<Root>/Video Viewer7"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
