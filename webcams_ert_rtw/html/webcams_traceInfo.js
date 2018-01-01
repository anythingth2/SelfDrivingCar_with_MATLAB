function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Color Space
 Conversion */
	this.urlHashMap["webcams:4"] = "webcams.c:113,127&webcams.h:55,68";
	/* <Root>/Constant */
	this.urlHashMap["webcams:13"] = "webcams.c:130&webcams.h:107&webcams_data.c:22";
	/* <Root>/Edge Detection */
	this.urlHashMap["webcams:5"] = "webcams.c:129&webcams.h:56,62,63,64,84,89&webcams_data.c:483,488";
	/* <Root>/From Multimedia File */
	this.urlHashMap["webcams:1"] = "webcams.c:45,56,160,188,190,200,211&webcams.h:53,65,66,67";
	/* <Root>/Resize */
	this.urlHashMap["webcams:15"] = "webcams.c:58,111&webcams.h:54,61,74,79,94,99&webcams_data.c:30,194,493,590";
	/* <Root>/Video Viewer */
	this.urlHashMap["webcams:2"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=webcams:2";
	/* <Root>/Video Viewer1 */
	this.urlHashMap["webcams:16"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=webcams:16";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "webcams"};
	this.sidHashMap["webcams"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Color Space  Conversion"] = {sid: "webcams:4"};
	this.sidHashMap["webcams:4"] = {rtwname: "<Root>/Color Space  Conversion"};
	this.rtwnameHashMap["<Root>/Constant"] = {sid: "webcams:13"};
	this.sidHashMap["webcams:13"] = {rtwname: "<Root>/Constant"};
	this.rtwnameHashMap["<Root>/Edge Detection"] = {sid: "webcams:5"};
	this.sidHashMap["webcams:5"] = {rtwname: "<Root>/Edge Detection"};
	this.rtwnameHashMap["<Root>/From Multimedia File"] = {sid: "webcams:1"};
	this.sidHashMap["webcams:1"] = {rtwname: "<Root>/From Multimedia File"};
	this.rtwnameHashMap["<Root>/Resize"] = {sid: "webcams:15"};
	this.sidHashMap["webcams:15"] = {rtwname: "<Root>/Resize"};
	this.rtwnameHashMap["<Root>/Video Viewer"] = {sid: "webcams:2"};
	this.sidHashMap["webcams:2"] = {rtwname: "<Root>/Video Viewer"};
	this.rtwnameHashMap["<Root>/Video Viewer1"] = {sid: "webcams:16"};
	this.sidHashMap["webcams:16"] = {rtwname: "<Root>/Video Viewer1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
