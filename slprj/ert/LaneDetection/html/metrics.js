function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["LaneDetection"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\LaneDetection\\LaneDetection.c",
	stack: 64,
	stackTotal: 100};
	 this.metricsArray.fcn["LaneDetection_Start"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\LaneDetection\\LaneDetection.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["LaneDetection_initialize"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\LaneDetection\\LaneDetection.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["MWVIP_Hough_D"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\vision\\visionrt\\export\\include\\visionrt\\viphough_rt.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["cos"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["div_nde_s32_floor"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\_sharedutils\\div_nde_s32_floor.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memcpy"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["mul_s32_loSR"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\_sharedutils\\mul_s32_loSR.c",
	stack: 8,
	stackTotal: 36};
	 this.metricsArray.fcn["mul_ssu32_loSR"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\_sharedutils\\mul_ssu32_loSR.c",
	stack: 8,
	stackTotal: 36};
	 this.metricsArray.fcn["mul_wide_s32"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\_sharedutils\\mul_wide_s32.c",
	stack: 28,
	stackTotal: 28};
	 this.metricsArray.fcn["mul_wide_su32"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\_sharedutils\\mul_wide_su32.c",
	stack: 28,
	stackTotal: 28};
	 this.metricsArray.fcn["sin"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="LaneDetection_metrics.html">Global Memory: 0(bytes) Maximum Stack: 64(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
