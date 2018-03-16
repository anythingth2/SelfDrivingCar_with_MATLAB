function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Draw Shapes */
	this.urlHashMap["LaneDetection:2"] = "LaneDetection.c:854,1202";
	/* <Root>/Edge Detection */
	this.urlHashMap["LaneDetection:3"] = "LaneDetection.c:111,114,117,120,123,126,182,344,391,562&LaneDetection.h:93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,121,122,123,130";
	/* <Root>/ROI_Tracking */
	this.urlHashMap["LaneDetection:41"] = "LaneDetection.c:376,389&LaneDetection.h:135";
	/* <Root>/ROI_X */
	this.urlHashMap["LaneDetection:42"] = "LaneDetection.c:102,377";
	/* <Root>/ROI_X_2 */
	this.urlHashMap["LaneDetection:94"] = "msg=&block=LaneDetection:94";
	/* <Root>/ROI_Y */
	this.urlHashMap["LaneDetection:43"] = "LaneDetection.c:99,378";
	/* <Root>/ROI_Y_2 */
	this.urlHashMap["LaneDetection:95"] = "msg=&block=LaneDetection:95";
	/* <Root>/Tracking_ROI */
	this.urlHashMap["LaneDetection:44"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:44";
	/* <Root>/LeftLaneTwoPts */
	this.urlHashMap["LaneDetection:101"] = "msg=&block=LaneDetection:101";
	/* <S1>/Constant2 */
	this.urlHashMap["LaneDetection:7"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:7";
	/* <S1>/Constant3 */
	this.urlHashMap["LaneDetection:8"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:8";
	/* <S1>/Find Local Maxima */
	this.urlHashMap["LaneDetection:9"] = "LaneDetection.c:569,673&LaneDetection.h:81,83,111,132";
	/* <S1>/Hough Lines */
	this.urlHashMap["LaneDetection:10"] = "LaneDetection.c:754,852";
	/* <S1>/Hough Transform */
	this.urlHashMap["LaneDetection:11"] = "LaneDetection.c:105,108,564&LaneDetection.h:78,79,80";
	/* <S1>/Selector */
	this.urlHashMap["LaneDetection:12"] = "LaneDetection.c:675,688&LaneDetection.h:86,112";
	/* <S1>/Selector1 */
	this.urlHashMap["LaneDetection:13"] = "LaneDetection.c:690,712&LaneDetection.h:113";
	/* <S1>/Selector2 */
	this.urlHashMap["LaneDetection:14"] = "LaneDetection.c:714,728&LaneDetection.h:114";
	/* <S1>/Selector5 */
	this.urlHashMap["LaneDetection:15"] = "LaneDetection.c:730,752&LaneDetection.h:115";
	/* <S1>/TwoPoints2Vector */
	this.urlHashMap["LaneDetection:48"] = "LaneDetection.c:1204,1247&LaneDetection.h:120,124";
	/* <S2>/TwoPoints */
	this.urlHashMap["LaneDetection:99"] = "msg=&block=LaneDetection:99";
	/* <S2>/Find Line Similarity with Support Line */
	this.urlHashMap["LaneDetection:46"] = "LaneDetection.c:1249,1272&LaneDetection.h:129";
	/* <S2>/Find Nearest Line */
	this.urlHashMap["LaneDetection:56"] = "LaneDetection.c:1274,1317";
	/* <S2>/Selector */
	this.urlHashMap["LaneDetection:100"] = "LaneDetection.c:1316,1332";
	/* <S2>/TwoPoint */
	this.urlHashMap["LaneDetection:96"] = "msg=&block=LaneDetection:96";
	/* <S3>/Constant */
	this.urlHashMap["LaneDetection:19"] = "msg=rtwMsg_notTraceable&block=LaneDetection:19";
	/* <S3>/Constant1 */
	this.urlHashMap["LaneDetection:20"] = "msg=rtwMsg_notTraceable&block=LaneDetection:20";
	/* <S3>/Constant2 */
	this.urlHashMap["LaneDetection:21"] = "msg=rtwMsg_notTraceable&block=LaneDetection:21";
	/* <S3>/Constant3 */
	this.urlHashMap["LaneDetection:22"] = "msg=rtwMsg_notTraceable&block=LaneDetection:22";
	/* <S3>/Constant4 */
	this.urlHashMap["LaneDetection:38"] = "msg=rtwMsg_notTraceable&block=LaneDetection:38";
	/* <S3>/Constant5 */
	this.urlHashMap["LaneDetection:40"] = "msg=rtwMsg_notTraceable&block=LaneDetection:40";
	/* <S3>/Divide */
	this.urlHashMap["LaneDetection:23"] = "LaneDetection.c:1429,1438";
	/* <S3>/Product */
	this.urlHashMap["LaneDetection:37"] = "LaneDetection.c:1413,1419&LaneDetection.h:84";
	/* <S3>/Product1 */
	this.urlHashMap["LaneDetection:39"] = "LaneDetection.c:1389,1395";
	/* <S3>/Selector */
	this.urlHashMap["LaneDetection:24"] = "LaneDetection.c:1334,1347&LaneDetection.h:116,126";
	/* <S3>/Selector2 */
	this.urlHashMap["LaneDetection:25"] = "LaneDetection.c:1373,1387&LaneDetection.h:118";
	/* <S3>/Selector3 */
	this.urlHashMap["LaneDetection:26"] = "LaneDetection.c:1349,1363&LaneDetection.h:117,125";
	/* <S3>/Selector4 */
	this.urlHashMap["LaneDetection:27"] = "LaneDetection.c:1397,1411&LaneDetection.h:119";
	/* <S3>/Subtract */
	this.urlHashMap["LaneDetection:28"] = "LaneDetection.c:1365,1371";
	/* <S3>/Subtract1 */
	this.urlHashMap["LaneDetection:29"] = "LaneDetection.c:1421,1427&LaneDetection.h:85";
	/* <S4>/BaseVector */
	this.urlHashMap["LaneDetection:66"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:66";
	/* <S4>/Constant */
	this.urlHashMap["LaneDetection:82"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:82";
	/* <S4>/Constant1 */
	this.urlHashMap["LaneDetection:84"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:84";
	/* <S4>/Divide */
	this.urlHashMap["LaneDetection:71"] = "LaneDetection.c:1440";
	/* <S4>/Dot Product */
	this.urlHashMap["LaneDetection:67"] = "LaneDetection.c:1441";
	/* <S4>/Math
Function */
	this.urlHashMap["LaneDetection:81"] = "LaneDetection.c:1442";
	/* <S4>/Math
Function1 */
	this.urlHashMap["LaneDetection:83"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:83";
	/* <S4>/Product */
	this.urlHashMap["LaneDetection:70"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:70";
	/* <S4>/Sqrt */
	this.urlHashMap["LaneDetection:90"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:90";
	/* <S4>/Sqrt1 */
	this.urlHashMap["LaneDetection:91"] = "LaneDetection.c:1443";
	/* <S4>/Sum of
Elements */
	this.urlHashMap["LaneDetection:88"] = "LaneDetection.c:1444";
	/* <S4>/Sum of
Elements1 */
	this.urlHashMap["LaneDetection:89"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=LaneDetection:89";
	/* <S4>/Trigonometric
Function */
	this.urlHashMap["LaneDetection:73"] = "LaneDetection.c:1450,1461";
	/* <S5>:1 */
	this.urlHashMap["LaneDetection:48:1"] = "LaneDetection.c:1205";
	/* <S5>:1:2 */
	this.urlHashMap["LaneDetection:48:1:2"] = "LaneDetection.c:1206";
	/* <S6>:1 */
	this.urlHashMap["LaneDetection:46:1"] = "LaneDetection.c:1250";
	/* <S6>:1:2 */
	this.urlHashMap["LaneDetection:46:1:2"] = "LaneDetection.c:1251";
	/* <S6>:1:3 */
	this.urlHashMap["LaneDetection:46:1:3"] = "LaneDetection.c:1252";
	/* <S6>:1:5 */
	this.urlHashMap["LaneDetection:46:1:5"] = "LaneDetection.c:1253";
	/* <S6>:1:7 */
	this.urlHashMap["LaneDetection:46:1:7"] = "LaneDetection.c:1261";
	/* <S6>:1:8 */
	this.urlHashMap["LaneDetection:46:1:8"] = "LaneDetection.c:1263";
	/* <S7>:1 */
	this.urlHashMap["LaneDetection:56:1"] = "LaneDetection.c:1275";
	/* <S7>:1:2 */
	this.urlHashMap["LaneDetection:56:1:2"] = "LaneDetection.c:1276";
	/* <S7>:1:3 */
	this.urlHashMap["LaneDetection:56:1:3"] = "LaneDetection.c:1281,1282";
	/* <S7>:1:4 */
	this.urlHashMap["LaneDetection:56:1:4"] = "LaneDetection.c:1283";
	/* <S7>:1:5 */
	this.urlHashMap["LaneDetection:56:1:5"] = "LaneDetection.c:1286";
	/* <S7>:1:6 */
	this.urlHashMap["LaneDetection:56:1:6"] = "LaneDetection.c:1288";
	/* <S7>:1:7 */
	this.urlHashMap["LaneDetection:56:1:7"] = "LaneDetection.c:1291";
	/* <S7>:1:9 */
	this.urlHashMap["LaneDetection:56:1:9"] = "LaneDetection.c:1295";
	/* <S7>:1:10 */
	this.urlHashMap["LaneDetection:56:1:10"] = "LaneDetection.c:1299";
	/* <S7>:1:11 */
	this.urlHashMap["LaneDetection:56:1:11"] = "LaneDetection.c:1301";
	/* <S7>:1:12 */
	this.urlHashMap["LaneDetection:56:1:12"] = "LaneDetection.c:1304";
	/* <S7>:1:15 */
	this.urlHashMap["LaneDetection:56:1:15"] = "LaneDetection.c:1310";
	/* <S7>:1:16 */
	this.urlHashMap["LaneDetection:56:1:16"] = "LaneDetection.c:1311";
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
	this.rtwnameHashMap["<S2>"] = {sid: "LaneDetection:59"};
	this.sidHashMap["LaneDetection:59"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "LaneDetection:17"};
	this.sidHashMap["LaneDetection:17"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "LaneDetection:63"};
	this.sidHashMap["LaneDetection:63"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "LaneDetection:48"};
	this.sidHashMap["LaneDetection:48"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<S6>"] = {sid: "LaneDetection:46"};
	this.sidHashMap["LaneDetection:46"] = {rtwname: "<S6>"};
	this.rtwnameHashMap["<S7>"] = {sid: "LaneDetection:56"};
	this.sidHashMap["LaneDetection:56"] = {rtwname: "<S7>"};
	this.rtwnameHashMap["<Root>/I"] = {sid: "LaneDetection:1"};
	this.sidHashMap["LaneDetection:1"] = {rtwname: "<Root>/I"};
	this.rtwnameHashMap["<Root>/SupportLeftLineVector"] = {sid: "LaneDetection:52"};
	this.sidHashMap["LaneDetection:52"] = {rtwname: "<Root>/SupportLeftLineVector"};
	this.rtwnameHashMap["<Root>/Draw Shapes"] = {sid: "LaneDetection:2"};
	this.sidHashMap["LaneDetection:2"] = {rtwname: "<Root>/Draw Shapes"};
	this.rtwnameHashMap["<Root>/Edge Detection"] = {sid: "LaneDetection:3"};
	this.sidHashMap["LaneDetection:3"] = {rtwname: "<Root>/Edge Detection"};
	this.rtwnameHashMap["<Root>/Find Line"] = {sid: "LaneDetection:4"};
	this.sidHashMap["LaneDetection:4"] = {rtwname: "<Root>/Find Line"};
	this.rtwnameHashMap["<Root>/Find Nearest Support Line"] = {sid: "LaneDetection:59"};
	this.sidHashMap["LaneDetection:59"] = {rtwname: "<Root>/Find Nearest Support Line"};
	this.rtwnameHashMap["<Root>/Find Slope"] = {sid: "LaneDetection:17"};
	this.sidHashMap["LaneDetection:17"] = {rtwname: "<Root>/Find Slope"};
	this.rtwnameHashMap["<Root>/ROI_Tracking"] = {sid: "LaneDetection:41"};
	this.sidHashMap["LaneDetection:41"] = {rtwname: "<Root>/ROI_Tracking"};
	this.rtwnameHashMap["<Root>/ROI_X"] = {sid: "LaneDetection:42"};
	this.sidHashMap["LaneDetection:42"] = {rtwname: "<Root>/ROI_X"};
	this.rtwnameHashMap["<Root>/ROI_X_2"] = {sid: "LaneDetection:94"};
	this.sidHashMap["LaneDetection:94"] = {rtwname: "<Root>/ROI_X_2"};
	this.rtwnameHashMap["<Root>/ROI_Y"] = {sid: "LaneDetection:43"};
	this.sidHashMap["LaneDetection:43"] = {rtwname: "<Root>/ROI_Y"};
	this.rtwnameHashMap["<Root>/ROI_Y_2"] = {sid: "LaneDetection:95"};
	this.sidHashMap["LaneDetection:95"] = {rtwname: "<Root>/ROI_Y_2"};
	this.rtwnameHashMap["<Root>/Tracking_ROI"] = {sid: "LaneDetection:44"};
	this.sidHashMap["LaneDetection:44"] = {rtwname: "<Root>/Tracking_ROI"};
	this.rtwnameHashMap["<Root>/Vector2Angle"] = {sid: "LaneDetection:63"};
	this.sidHashMap["LaneDetection:63"] = {rtwname: "<Root>/Vector2Angle"};
	this.rtwnameHashMap["<Root>/TwoPoints"] = {sid: "LaneDetection:31"};
	this.sidHashMap["LaneDetection:31"] = {rtwname: "<Root>/TwoPoints"};
	this.rtwnameHashMap["<Root>/Slope"] = {sid: "LaneDetection:32"};
	this.sidHashMap["LaneDetection:32"] = {rtwname: "<Root>/Slope"};
	this.rtwnameHashMap["<Root>/LineImage"] = {sid: "LaneDetection:33"};
	this.sidHashMap["LaneDetection:33"] = {rtwname: "<Root>/LineImage"};
	this.rtwnameHashMap["<Root>/Edge"] = {sid: "LaneDetection:34"};
	this.sidHashMap["LaneDetection:34"] = {rtwname: "<Root>/Edge"};
	this.rtwnameHashMap["<Root>/Angle"] = {sid: "LaneDetection:92"};
	this.sidHashMap["LaneDetection:92"] = {rtwname: "<Root>/Angle"};
	this.rtwnameHashMap["<Root>/LeftLaneTwoPts"] = {sid: "LaneDetection:101"};
	this.sidHashMap["LaneDetection:101"] = {rtwname: "<Root>/LeftLaneTwoPts"};
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
	this.rtwnameHashMap["<S1>/TwoPoints2Vector"] = {sid: "LaneDetection:48"};
	this.sidHashMap["LaneDetection:48"] = {rtwname: "<S1>/TwoPoints2Vector"};
	this.rtwnameHashMap["<S1>/TwoPts"] = {sid: "LaneDetection:16"};
	this.sidHashMap["LaneDetection:16"] = {rtwname: "<S1>/TwoPts"};
	this.rtwnameHashMap["<S1>/LineVectors"] = {sid: "LaneDetection:49"};
	this.sidHashMap["LaneDetection:49"] = {rtwname: "<S1>/LineVectors"};
	this.rtwnameHashMap["<S2>/LineVectors"] = {sid: "LaneDetection:60"};
	this.sidHashMap["LaneDetection:60"] = {rtwname: "<S2>/LineVectors"};
	this.rtwnameHashMap["<S2>/SupportLine"] = {sid: "LaneDetection:61"};
	this.sidHashMap["LaneDetection:61"] = {rtwname: "<S2>/SupportLine"};
	this.rtwnameHashMap["<S2>/TwoPoints"] = {sid: "LaneDetection:99"};
	this.sidHashMap["LaneDetection:99"] = {rtwname: "<S2>/TwoPoints"};
	this.rtwnameHashMap["<S2>/Find Line Similarity with Support Line"] = {sid: "LaneDetection:46"};
	this.sidHashMap["LaneDetection:46"] = {rtwname: "<S2>/Find Line Similarity with Support Line"};
	this.rtwnameHashMap["<S2>/Find Nearest Line"] = {sid: "LaneDetection:56"};
	this.sidHashMap["LaneDetection:56"] = {rtwname: "<S2>/Find Nearest Line"};
	this.rtwnameHashMap["<S2>/Selector"] = {sid: "LaneDetection:100"};
	this.sidHashMap["LaneDetection:100"] = {rtwname: "<S2>/Selector"};
	this.rtwnameHashMap["<S2>/NearestVector"] = {sid: "LaneDetection:62"};
	this.sidHashMap["LaneDetection:62"] = {rtwname: "<S2>/NearestVector"};
	this.rtwnameHashMap["<S2>/TwoPoint"] = {sid: "LaneDetection:96"};
	this.sidHashMap["LaneDetection:96"] = {rtwname: "<S2>/TwoPoint"};
	this.rtwnameHashMap["<S3>/Pts"] = {sid: "LaneDetection:18"};
	this.sidHashMap["LaneDetection:18"] = {rtwname: "<S3>/Pts"};
	this.rtwnameHashMap["<S3>/Constant"] = {sid: "LaneDetection:19"};
	this.sidHashMap["LaneDetection:19"] = {rtwname: "<S3>/Constant"};
	this.rtwnameHashMap["<S3>/Constant1"] = {sid: "LaneDetection:20"};
	this.sidHashMap["LaneDetection:20"] = {rtwname: "<S3>/Constant1"};
	this.rtwnameHashMap["<S3>/Constant2"] = {sid: "LaneDetection:21"};
	this.sidHashMap["LaneDetection:21"] = {rtwname: "<S3>/Constant2"};
	this.rtwnameHashMap["<S3>/Constant3"] = {sid: "LaneDetection:22"};
	this.sidHashMap["LaneDetection:22"] = {rtwname: "<S3>/Constant3"};
	this.rtwnameHashMap["<S3>/Constant4"] = {sid: "LaneDetection:38"};
	this.sidHashMap["LaneDetection:38"] = {rtwname: "<S3>/Constant4"};
	this.rtwnameHashMap["<S3>/Constant5"] = {sid: "LaneDetection:40"};
	this.sidHashMap["LaneDetection:40"] = {rtwname: "<S3>/Constant5"};
	this.rtwnameHashMap["<S3>/Divide"] = {sid: "LaneDetection:23"};
	this.sidHashMap["LaneDetection:23"] = {rtwname: "<S3>/Divide"};
	this.rtwnameHashMap["<S3>/Product"] = {sid: "LaneDetection:37"};
	this.sidHashMap["LaneDetection:37"] = {rtwname: "<S3>/Product"};
	this.rtwnameHashMap["<S3>/Product1"] = {sid: "LaneDetection:39"};
	this.sidHashMap["LaneDetection:39"] = {rtwname: "<S3>/Product1"};
	this.rtwnameHashMap["<S3>/Selector"] = {sid: "LaneDetection:24"};
	this.sidHashMap["LaneDetection:24"] = {rtwname: "<S3>/Selector"};
	this.rtwnameHashMap["<S3>/Selector2"] = {sid: "LaneDetection:25"};
	this.sidHashMap["LaneDetection:25"] = {rtwname: "<S3>/Selector2"};
	this.rtwnameHashMap["<S3>/Selector3"] = {sid: "LaneDetection:26"};
	this.sidHashMap["LaneDetection:26"] = {rtwname: "<S3>/Selector3"};
	this.rtwnameHashMap["<S3>/Selector4"] = {sid: "LaneDetection:27"};
	this.sidHashMap["LaneDetection:27"] = {rtwname: "<S3>/Selector4"};
	this.rtwnameHashMap["<S3>/Subtract"] = {sid: "LaneDetection:28"};
	this.sidHashMap["LaneDetection:28"] = {rtwname: "<S3>/Subtract"};
	this.rtwnameHashMap["<S3>/Subtract1"] = {sid: "LaneDetection:29"};
	this.sidHashMap["LaneDetection:29"] = {rtwname: "<S3>/Subtract1"};
	this.rtwnameHashMap["<S3>/Slope"] = {sid: "LaneDetection:30"};
	this.sidHashMap["LaneDetection:30"] = {rtwname: "<S3>/Slope"};
	this.rtwnameHashMap["<S4>/Vector"] = {sid: "LaneDetection:64"};
	this.sidHashMap["LaneDetection:64"] = {rtwname: "<S4>/Vector"};
	this.rtwnameHashMap["<S4>/BaseVector"] = {sid: "LaneDetection:66"};
	this.sidHashMap["LaneDetection:66"] = {rtwname: "<S4>/BaseVector"};
	this.rtwnameHashMap["<S4>/Constant"] = {sid: "LaneDetection:82"};
	this.sidHashMap["LaneDetection:82"] = {rtwname: "<S4>/Constant"};
	this.rtwnameHashMap["<S4>/Constant1"] = {sid: "LaneDetection:84"};
	this.sidHashMap["LaneDetection:84"] = {rtwname: "<S4>/Constant1"};
	this.rtwnameHashMap["<S4>/Divide"] = {sid: "LaneDetection:71"};
	this.sidHashMap["LaneDetection:71"] = {rtwname: "<S4>/Divide"};
	this.rtwnameHashMap["<S4>/Dot Product"] = {sid: "LaneDetection:67"};
	this.sidHashMap["LaneDetection:67"] = {rtwname: "<S4>/Dot Product"};
	this.rtwnameHashMap["<S4>/Math Function"] = {sid: "LaneDetection:81"};
	this.sidHashMap["LaneDetection:81"] = {rtwname: "<S4>/Math Function"};
	this.rtwnameHashMap["<S4>/Math Function1"] = {sid: "LaneDetection:83"};
	this.sidHashMap["LaneDetection:83"] = {rtwname: "<S4>/Math Function1"};
	this.rtwnameHashMap["<S4>/Product"] = {sid: "LaneDetection:70"};
	this.sidHashMap["LaneDetection:70"] = {rtwname: "<S4>/Product"};
	this.rtwnameHashMap["<S4>/Sqrt"] = {sid: "LaneDetection:90"};
	this.sidHashMap["LaneDetection:90"] = {rtwname: "<S4>/Sqrt"};
	this.rtwnameHashMap["<S4>/Sqrt1"] = {sid: "LaneDetection:91"};
	this.sidHashMap["LaneDetection:91"] = {rtwname: "<S4>/Sqrt1"};
	this.rtwnameHashMap["<S4>/Sum of Elements"] = {sid: "LaneDetection:88"};
	this.sidHashMap["LaneDetection:88"] = {rtwname: "<S4>/Sum of Elements"};
	this.rtwnameHashMap["<S4>/Sum of Elements1"] = {sid: "LaneDetection:89"};
	this.sidHashMap["LaneDetection:89"] = {rtwname: "<S4>/Sum of Elements1"};
	this.rtwnameHashMap["<S4>/Trigonometric Function"] = {sid: "LaneDetection:73"};
	this.sidHashMap["LaneDetection:73"] = {rtwname: "<S4>/Trigonometric Function"};
	this.rtwnameHashMap["<S4>/Angle"] = {sid: "LaneDetection:65"};
	this.sidHashMap["LaneDetection:65"] = {rtwname: "<S4>/Angle"};
	this.rtwnameHashMap["<S5>:1"] = {sid: "LaneDetection:48:1"};
	this.sidHashMap["LaneDetection:48:1"] = {rtwname: "<S5>:1"};
	this.rtwnameHashMap["<S5>:1:2"] = {sid: "LaneDetection:48:1:2"};
	this.sidHashMap["LaneDetection:48:1:2"] = {rtwname: "<S5>:1:2"};
	this.rtwnameHashMap["<S6>:1"] = {sid: "LaneDetection:46:1"};
	this.sidHashMap["LaneDetection:46:1"] = {rtwname: "<S6>:1"};
	this.rtwnameHashMap["<S6>:1:2"] = {sid: "LaneDetection:46:1:2"};
	this.sidHashMap["LaneDetection:46:1:2"] = {rtwname: "<S6>:1:2"};
	this.rtwnameHashMap["<S6>:1:3"] = {sid: "LaneDetection:46:1:3"};
	this.sidHashMap["LaneDetection:46:1:3"] = {rtwname: "<S6>:1:3"};
	this.rtwnameHashMap["<S6>:1:5"] = {sid: "LaneDetection:46:1:5"};
	this.sidHashMap["LaneDetection:46:1:5"] = {rtwname: "<S6>:1:5"};
	this.rtwnameHashMap["<S6>:1:7"] = {sid: "LaneDetection:46:1:7"};
	this.sidHashMap["LaneDetection:46:1:7"] = {rtwname: "<S6>:1:7"};
	this.rtwnameHashMap["<S6>:1:8"] = {sid: "LaneDetection:46:1:8"};
	this.sidHashMap["LaneDetection:46:1:8"] = {rtwname: "<S6>:1:8"};
	this.rtwnameHashMap["<S7>:1"] = {sid: "LaneDetection:56:1"};
	this.sidHashMap["LaneDetection:56:1"] = {rtwname: "<S7>:1"};
	this.rtwnameHashMap["<S7>:1:2"] = {sid: "LaneDetection:56:1:2"};
	this.sidHashMap["LaneDetection:56:1:2"] = {rtwname: "<S7>:1:2"};
	this.rtwnameHashMap["<S7>:1:3"] = {sid: "LaneDetection:56:1:3"};
	this.sidHashMap["LaneDetection:56:1:3"] = {rtwname: "<S7>:1:3"};
	this.rtwnameHashMap["<S7>:1:4"] = {sid: "LaneDetection:56:1:4"};
	this.sidHashMap["LaneDetection:56:1:4"] = {rtwname: "<S7>:1:4"};
	this.rtwnameHashMap["<S7>:1:5"] = {sid: "LaneDetection:56:1:5"};
	this.sidHashMap["LaneDetection:56:1:5"] = {rtwname: "<S7>:1:5"};
	this.rtwnameHashMap["<S7>:1:6"] = {sid: "LaneDetection:56:1:6"};
	this.sidHashMap["LaneDetection:56:1:6"] = {rtwname: "<S7>:1:6"};
	this.rtwnameHashMap["<S7>:1:7"] = {sid: "LaneDetection:56:1:7"};
	this.sidHashMap["LaneDetection:56:1:7"] = {rtwname: "<S7>:1:7"};
	this.rtwnameHashMap["<S7>:1:9"] = {sid: "LaneDetection:56:1:9"};
	this.sidHashMap["LaneDetection:56:1:9"] = {rtwname: "<S7>:1:9"};
	this.rtwnameHashMap["<S7>:1:10"] = {sid: "LaneDetection:56:1:10"};
	this.sidHashMap["LaneDetection:56:1:10"] = {rtwname: "<S7>:1:10"};
	this.rtwnameHashMap["<S7>:1:11"] = {sid: "LaneDetection:56:1:11"};
	this.sidHashMap["LaneDetection:56:1:11"] = {rtwname: "<S7>:1:11"};
	this.rtwnameHashMap["<S7>:1:12"] = {sid: "LaneDetection:56:1:12"};
	this.sidHashMap["LaneDetection:56:1:12"] = {rtwname: "<S7>:1:12"};
	this.rtwnameHashMap["<S7>:1:15"] = {sid: "LaneDetection:56:1:15"};
	this.sidHashMap["LaneDetection:56:1:15"] = {rtwname: "<S7>:1:15"};
	this.rtwnameHashMap["<S7>:1:16"] = {sid: "LaneDetection:56:1:16"};
	this.sidHashMap["LaneDetection:56:1:16"] = {rtwname: "<S7>:1:16"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
