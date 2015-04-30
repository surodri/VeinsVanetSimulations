//Reference to Andres Vargas class sink.h in inet 

#ifndef __INET_INET_METRICS_H
#define __INET_INET_METRICS_H

#include <INETDefs.h>

/**
 * A module that just deletes every packet it receives, and collects
 * basic statistics (packet count, bit count, packet rate, bit rate).
 */
class INET_API Metrics : public cSimpleModule
{
public:
    virtual ~Metrics(){}

  protected:
    long numberOfBits;
    static simsignal_t throughputSignal;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual long updateNumberOfBits(long numberOfBits, cPacket* packet);
  // virtual void initialize(){
  //     numberOfBits = 0;

  //     WATCH(numberOfBits);

  // }

  // virtual void handleMessage(cMessage *msg)
  // {

  //     cPacket *packet = PK(msg);
  //     numberOfBits = updateNumberOfBits(numberOfBits, packet);
  // }

  // virtual long updateNumberOfBits(long numberOfBits, cPacket* packet){
  //     return numberOfBits += packet->getBitLength();
  // }

  // virtual void finish(){
  //     recordScalar("numberOfBits", numberOfBits);
  // }
};

#endif /* INET_INET_METRICS_H_ */


