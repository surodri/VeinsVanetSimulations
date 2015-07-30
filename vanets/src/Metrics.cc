#include "Metrics.h"

Define_Module(Metrics);

void Metrics::initialize(){

    currentSimulationTime = 0;
    packetsDeliveredToMetrics = 0;
    throughputSignal = 0;


    cMessage *timerMessage = new cPacket();
    timerMessage->setName("timer");

    scheduleAt(simTime(),timerMessage);
    WATCH(packetsDeliveredToMetrics);
    WATCH(throughputSignal);

}

float Metrics::computeThroughput(float currentPacketsReceived,simtime_t currentSimulationTime) {

    float result = 0;
    simtime_t testSimTime=simTime();

    std::cout<< "Simulation Time: "<<currentSimulationTime<<std::endl;
    std::cout<< "TestNowTime:"<<testSimTime<<std::endl;

    if (currentSimulationTime>0){
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

     }
     throughputSignal = computeThroughput(packetsDeliveredToMetrics, currentSimulationTime);
     std::cout<<"Current Throughput:"<<throughputSignal<<std::endl;
     //emit(throughputSignal,throughput);
}

float Metrics::updateNumberOfPacketsReceived(float packetsDeliveredToMetrics){
     return packetsDeliveredToMetrics = packetsDeliveredToMetrics +1;
}

void Metrics::finish(){
    recordScalar("packetsDeliveredToMetrics", packetsDeliveredToMetrics);
    recordScalar("throughputSignal", throughputSignal);
}
