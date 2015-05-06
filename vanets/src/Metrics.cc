#include "Metrics.h"

Define_Module(Metrics);

simsignal_t Metrics::throughputSignal = registerSignal("throughput");

void Metrics::initialize(){
    numberOfBits = 0;

    WATCH(numberOfBits);
    WATCH(throughputSignal);

}

long Metrics::computeThroughput(long currentNumberOfBits,simtime_t currentSimulationTime) {

    long result = 0;
    std::cout<< "Simulation Time: "<<currentSimulationTime<<std::endl;
    if (currentSimulationTime!=0){
        result = currentNumberOfBits/currentSimulationTime;
    }
    return result;
}

void Metrics::handleMessage(cMessage *msg)
{
     cPacket *packet = PK(msg);
     numberOfBits = updateNumberOfBits(numberOfBits, packet);

     long throughput = computeThroughput(numberOfBits,simTime());
     emit(throughputSignal,throughput);
}

long Metrics::updateNumberOfBits(long numberOfBits, cPacket* packet){
     return numberOfBits += packet->getBitLength();
}

void Metrics::finish(){
    recordScalar("numberOfBits", numberOfBits);
}
