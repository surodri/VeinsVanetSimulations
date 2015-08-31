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
    simtime_t testSimTime=simTime();

    std::cout<< "Test Time double: "<<testSimTime.dbl()<<std::endl;
    std::cout<< "Simulation Time: "<<currentSimulationTime<<std::endl;
    std::cout<< "Test Time simetime_t type:"<<testSimTime<<std::endl;

    if (currentSimulationTime>0){
        std::cout<<"currentPacketsReceived type: "<<typeid(currentPacketsReceived).name()<<'\n';
        std::cout<<"currentSimulationTime type: "<<typeid(currentSimulationTime).name()<<'\n';
        result = currentPacketsReceived/currentSimulationTime;
    }
    return result;
}

simtime_t Metrics::getCurrentTime(){
    return currentSimulationTime;
}

void Metrics::handleMessage(cMessage *msg)
{
     if(msg->isSelfMessage()){
         currentSimulationTime = simTime();
         scheduleAt(simTime()+1,msg);
     }
     std::cout<<msg<<" "<<currentSimulationTime<<std::endl;

     if(msg->isName("data")){
         packetsDeliveredToMetrics = updateNumberOfPacketsReceived(packetsDeliveredToMetrics);
         double currentSimulationTimeDouble = currentSimulationTime.dbl();
         throughputMetric = computeThroughput(packetsDeliveredToMetrics, currentSimulationTimeDouble);
         std::cout<<"Current Throughput:"<<throughputMetric<<std::endl;
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
