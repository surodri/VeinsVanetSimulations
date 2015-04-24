#include "Metrics.h"
void Metrics::initialize(){
    numberOfBits = 0;

    WATCH(numberOfBits);

}

void Metrics::handleMessage(cMessage *msg)
{
     cPacket *packet = PK(msg);
     numberOfBits = updateNumberOfBits(numberOfBits, packet);
}

long Metrics::updateNumberOfBits(long numberOfBits, cPacket* packet){
     return numberOfBits += packet->getBitLength();
}

void Metrics::finish(){
    recordScalar("numberOfBits", numberOfBits);
}
