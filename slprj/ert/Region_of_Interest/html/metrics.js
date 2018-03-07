function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.fcn["Region_of_Interest"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\Region_of_Interest\\Region_of_Interest.c",
	stack: 8,
	stackTotal: 8};
	 this.metricsArray.fcn["Region_of_Interest_initialize"] = {file: "C:\\Users\\ChiChaChai\\Documents\\AMAS-2017\\SelfDrivingCar_with_MATLAB\\slprj\\ert\\Region_of_Interest\\Region_of_Interest.c",
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
	 this.codeMetricsSummary = '<a href="Region_of_Interest_metrics.html">Global Memory: 0(bytes) Maximum Stack: 8(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
