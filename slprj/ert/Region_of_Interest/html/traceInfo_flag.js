function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["Region_of_Interest.c:45c31"]=1;
    this.traceFlag["Region_of_Interest.c:46c26"]=1;
    this.traceFlag["Region_of_Interest.c:47c25"]=1;
    this.traceFlag["Region_of_Interest.c:47c30"]=1;
    this.traceFlag["Region_of_Interest.c:47c75"]=1;
    this.traceFlag["Region_of_Interest.c:47c80"]=1;
    this.traceFlag["Region_of_Interest.c:48c13"]=1;
    this.traceFlag["Region_of_Interest.c:48c38"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["Region_of_Interest.c:45"]=1;
    this.lineTraceFlag["Region_of_Interest.c:46"]=1;
    this.lineTraceFlag["Region_of_Interest.c:47"]=1;
    this.lineTraceFlag["Region_of_Interest.c:48"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
