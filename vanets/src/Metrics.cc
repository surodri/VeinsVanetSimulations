#include "Metrics.h"

Define_Module(Metrics);

simsignal_t Metrics::throughputSignal = registerSignal("throughput");

void Metrics::initialize(){
    numberOfBits = 0;

    WATCH(numberOfBits);
    WATCH(throughputSignal);

}

void Metrics::handleMessage(cMessage *msg)
{
     cPacket *packet = PK(msg);
     numberOfBits = updateNumberOfBits(numberOfBits, packet);
     long throughput = numberOfBits/simTime();
     emit(throughputSignal,throughput);
}

long Metrics::updateNumberOfBits(long numberOfBits, cPacket* packet){
     return numberOfBits += packet->getBitLength();
}

void Metrics::finish(){
    recordScalar("numberOfBits", numberOfBits);
}
