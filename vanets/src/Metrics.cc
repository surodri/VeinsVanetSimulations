#include "Metrics.h"

Define_Module(Metrics);

void Metrics::initialize(){

    currentSimulationTime = 0;
    packetsDeliveredToMetrics = 0;
    throughputMetric = 0;
    throughputSignal = registerSignal("throughputSignal");

    cMessage *timerMessage = new cPacket();
    timerMessage->setName("timer");

    cMessage *dataMessage = new cPacket();
    dataMessage->setName("data");

    scheduleAt(simTime(),timerMessage);
    scheduleAt(simTime(),dataMessage);
    WATCH(packetsDeliveredToMetrics);
    WATCH(throughputMetric);

}

double Metrics::computeThroughput(double currentPacketsReceived,double currentSimulationTime) {

    double result = 0;

    if (currentSimulationTime>0){

        result = currentPacketsReceived/currentSimulationTime;
    }
    return result;
}

simtime_t Metrics::getCurrentTime(){
    return currentSimulationTime;
}

double Metrics::getThroughputMetric(){
    return throughputMetric;
}

double Metrics::getThroughputSignal(){
    return throughputSignal;
}
void Metrics::handleMessage(cMessage *msg)
{
     if(msg->isSelfMessage()){
         currentSimulationTime = simTime();
         scheduleAt(simTime()+1,msg);
     }

     if(msg->isName("data")){
         packetsDeliveredToMetrics = updateNumberOfPacketsReceived(packetsDeliveredToMetrics);
         double currentSimulationTimeDouble = currentSimulationTime.dbl();

         throughputMetric = computeThroughput(packetsDeliveredToMetrics, currentSimulationTimeDouble);

         emit(throughputSignal,throughputMetric);
     }


}

double Metrics::updateNumberOfPacketsReceived(double packetsDeliveredToMetrics){
     return packetsDeliveredToMetrics = packetsDeliveredToMetrics +1;
}

void Metrics::finish(){
    recordScalar("packetsDeliveredToMetrics", packetsDeliveredToMetrics);
    recordScalar("throughputMetric", throughputMetric);
}
