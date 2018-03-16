function TraceInfoFlag() {
    this.traceFlag = new Array();
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["test.c:34"]=1;
    this.lineTraceFlag["test.c:35"]=1;
    this.lineTraceFlag["test.c:36"]=1;
    this.lineTraceFlag["test.c:121"]=1;
    this.lineTraceFlag["test.c:122"]=1;
    this.lineTraceFlag["test.c:129"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
