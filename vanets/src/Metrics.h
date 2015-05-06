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
    virtual long computeThroughput(long numberOfBits, simtime_t currentSimulationTime);
};

#endif /* INET_INET_METRICS_H_ */


