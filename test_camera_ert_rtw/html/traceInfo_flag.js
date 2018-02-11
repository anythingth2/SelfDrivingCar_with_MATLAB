function TraceInfoFlag() {
    this.traceFlag = new Array();
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["test_camera.c:31"]=1;
    this.lineTraceFlag["test_camera.c:32"]=1;
    this.lineTraceFlag["test_camera.c:33"]=1;
    this.lineTraceFlag["test_camera.c:34"]=1;
    this.lineTraceFlag["test_camera.c:116"]=1;
    this.lineTraceFlag["test_camera.c:117"]=1;
    this.lineTraceFlag["test_camera.c:124"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
