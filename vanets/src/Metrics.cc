#include "Metrics.h"

Define_Module(Metrics);

simsignal_t Metrics::throughputSignal = registerSignal("throughput");

void Metrics::initialize(){
    packetsDeliveredToMetrics = 0;

    WATCH(packetsDeliveredToMetrics);
    WATCH(throughputSignal);

}

int Metrics::computeThroughput(int currentPacketsReceived,simtime_t currentSimulationTime) {

    long result = 0;
    simtime_t testSimTime;
    getSimTime(testSimTime);

    std::cout<< "Simulation Time: "<<currentSimulationTime<<std::endl;
    std::cout<< "TestNowTime:"<<testSimTime<<std::endl;

    if (currentSimulationTime!=0){
        result = currentPacketsReceived/currentSimulationTime;
    }
    return result;
}

void Metrics::handleMessage(cMessage *msg)
{
     cPacket *packet = PK(msg);
     packetsDeliveredToMetrics = updateNumberOfPacketsReceived(packetsDeliveredToMetrics);

     int throughput = computeThroughput(packetsDeliveredToMetrics,simTime()+delta);
     emit(throughputSignal,throughput);
}

long Metrics::updateNumberOfPacketsReceived(long packetsDeliveredToMetrics){
     return packetsDeliveredToMetrics = packetsDeliveredToMetrics +1;
}

void Metrics::finish(){
    recordScalar("packetsDeliveredToMetrics", packetsDeliveredToMetrics);
}
