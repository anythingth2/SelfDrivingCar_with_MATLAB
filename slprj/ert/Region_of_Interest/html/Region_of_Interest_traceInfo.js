function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Selector1 */
	this.urlHashMap["Region_of_Interest:4"] = "Region_of_Interest.c:44,52";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Region_of_Interest"};
	this.sidHashMap["Region_of_Interest"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Image"] = {sid: "Region_of_Interest:1"};
	this.sidHashMap["Region_of_Interest:1"] = {rtwname: "<Root>/Image"};
	this.rtwnameHashMap["<Root>/ROI_X"] = {sid: "Region_of_Interest:2"};
	this.sidHashMap["Region_of_Interest:2"] = {rtwname: "<Root>/ROI_X"};
	this.rtwnameHashMap["<Root>/ROI_Y"] = {sid: "Region_of_Interest:3"};
	this.sidHashMap["Region_of_Interest:3"] = {rtwname: "<Root>/ROI_Y"};
	this.rtwnameHashMap["<Root>/Selector1"] = {sid: "Region_of_Interest:4"};
	this.sidHashMap["Region_of_Interest:4"] = {rtwname: "<Root>/Selector1"};
	this.rtwnameHashMap["<Root>/MaskedImage "] = {sid: "Region_of_Interest:5"};
	this.sidHashMap["Region_of_Interest:5"] = {rtwname: "<Root>/MaskedImage "};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
