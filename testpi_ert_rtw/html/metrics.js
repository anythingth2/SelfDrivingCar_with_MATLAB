function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtB"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	size: 691200};
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	size: 998872};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	size: 57};
	 this.metricsArray.var["testpi.c:rtBTransTable"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi_dt.h",
	size: 8};
	 this.metricsArray.var["testpi.c:rtBTransitions"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi_dt.h",
	size: 112};
	 this.metricsArray.var["testpi.c:rtDataTypeNames"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi_dt.h",
	size: 68};
	 this.metricsArray.var["testpi.c:rtDataTypeSizes"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi_dt.h",
	size: 68};
	 this.metricsArray.fcn["MW_videoCaptureInit"] = {file: "C:\\ProgramData\\MATLAB\\SupportPackages\\R2017a\\toolbox\\realtime\\targets\\linux\\blocks\\sfcn\\include\\v4l2_capture.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["MW_videoCaptureOutput"] = {file: "C:\\ProgramData\\MATLAB\\SupportPackages\\R2017a\\toolbox\\realtime\\targets\\linux\\blocks\\sfcn\\include\\v4l2_capture.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memcpy"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["mul_s32_loSR"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	stack: 8,
	stackTotal: 36};
	 this.metricsArray.fcn["mul_ssu32_loSR"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	stack: 8,
	stackTotal: 36};
	 this.metricsArray.fcn["mul_wide_s32"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	stack: 28,
	stackTotal: 28};
	 this.metricsArray.fcn["mul_wide_su32"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	stack: 28,
	stackTotal: 28};
	 this.metricsArray.fcn["rtExtModeUpload"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\rtw\\c\\src\\ext_mode\\common\\ext_work.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtExtModeUploadCheckTrigger"] = {file: "C:\\Program Files\\MATLAB\\R2017a\\rtw\\c\\src\\ext_mode\\common\\ext_work.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["testpi_initialize"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["testpi_step"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS 2017\\SelfDrivingCar_with_MATLAB\\testpi_ert_rtw\\testpi.c",
	stack: 48,
	stackTotal: 84};
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
	 this.codeMetricsSummary = '<a href="testpi_metrics.html">Global Memory: 1690385(bytes) Maximum Stack: 48(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
