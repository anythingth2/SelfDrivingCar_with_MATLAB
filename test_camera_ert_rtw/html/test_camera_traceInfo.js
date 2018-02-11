function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Matrix
Concatenate */
	this.urlHashMap["test_camera:7"] = "test_camera.h:75";
	/* <Root>/V4L2 Video Capture */
	this.urlHashMap["test_camera:2"] = "test_camera.c:30,115,123&test_camera.h:81&test_camera_data.c:22";
	/* <Root>/Video Viewer */
	this.urlHashMap["test_camera:3"] = "msg=&block=test_camera:3";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "test_camera"};
	this.sidHashMap["test_camera"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Matrix Concatenate"] = {sid: "test_camera:7"};
	this.sidHashMap["test_camera:7"] = {rtwname: "<Root>/Matrix Concatenate"};
	this.rtwnameHashMap["<Root>/V4L2 Video Capture"] = {sid: "test_camera:2"};
	this.sidHashMap["test_camera:2"] = {rtwname: "<Root>/V4L2 Video Capture"};
	this.rtwnameHashMap["<Root>/Video Viewer"] = {sid: "test_camera:3"};
	this.sidHashMap["test_camera:3"] = {rtwname: "<Root>/Video Viewer"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
