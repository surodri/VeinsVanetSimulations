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
    simtime_t currentSimulationTime;
    float packetsDeliveredToMetrics;
    float throughputSignal;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual float updateNumberOfPacketsReceived(float packetsDeliveredToMetrics);
    virtual simtime_t getCurrentTime();
    virtual float computeThroughput(float packetsDeliveredToMetrics, simtime_t currentSimulationTime);
};

#endif /* INET_INET_METRICS_H_ */


