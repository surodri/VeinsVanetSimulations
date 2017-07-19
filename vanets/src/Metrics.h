//Reference to Andres Vargas class sink.h in inet 

#ifndef __INET_INET_METRICS_H
#define __INET_INET_METRICS_H


#include <omnetpp.h>
#include <FindModule.h>
/**
 * A module that just deletes every packet it receives, and collects
 * basic statistics (packet count, bit count, packet rate, bit rate).
 */
class  Metrics : public cSimpleModule
{
public:
    virtual ~Metrics(){}
    double throughputMetric;

  protected:
    simtime_t currentSimulationTime;
    double packetsDeliveredToMetrics;

    simsignal_t throughputSignal;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();
    virtual double updateNumberOfPacketsReceived(double packetsDeliveredToMetrics);
    virtual simtime_t getCurrentTime();
  public:
    virtual double computeThroughput(double packetsDeliveredToMetrics, double currentSimulationTime);
    double getThroughputMetric();
    double getThroughputSignal();
};

#endif /* INET_INET_METRICS_H_ */


