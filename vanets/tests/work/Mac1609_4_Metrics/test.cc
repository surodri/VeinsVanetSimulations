
#include <omnetpp.h>

#include <Mac16094MetricsTest.h>
#include <../../../src/Metrics.h>



namespace Mac1609_4_Metrics {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{

Metrics *metrics = new Metrics();
Mac16094MetricsTest *macMetrics = new Mac16094MetricsTest();
double simulationTime = 0;
double currentPacketsReceived = 0;

//when simulation time is zero get zero
simulationTime = 0;
currentPacketsReceived = 0;
macMetrics->testComputeThroughputPacketsPerSecond(metrics, currentPacketsReceived, simulationTime);

//when currentPackets is zero
currentPacketsReceived = 0;
simulationTime =5;
macMetrics->testComputeThroughputPacketsPerSecond(metrics, currentPacketsReceived, simulationTime);

currentPacketsReceived = 5;
simulationTime = 10;
macMetrics->testComputeThroughputPacketsPerSecond(metrics, currentPacketsReceived, simulationTime);

cPacket *pkt = new cPacket();
cMessage *message = pkt; //Valid cPacket descendant of cMessage
macMetrics->testHandleLowerMsgCallsThroughputWhenReceivingBroadcast(message);

//when currentMgbis is zero
double currentMgbits = 0;
cPacket *packet = dynamic_cast<cPacket*>(message);
packet->setBitLength(1);
simulationTime = 10;
macMetrics->testThroughputMegabitsPerSecond(metrics, 1, currentMgbits, simulationTime);

//when currentMbgits is not zero
currentMgbits = 2;
packet->setBitLength(4000000);
simulationTime = 10;
macMetrics->testThroughputMegabitsPerSecond(metrics, 4000000, currentMgbits, simulationTime);

//when packetLength is zero
currentMgbits = 2;
packet->setBitLength(0);
simulationTime = 10;
macMetrics->testThroughputMegabitsPerSecond(metrics, 0, currentMgbits, simulationTime);

//when currentMgbits is a really big digit number
currentMgbits = 2000000000000000000000000000;
packet->setBitLength(2000000000000000000);
simulationTime = 10;
macMetrics->testThroughputMegabitsPerSecond(metrics, 2000000000000000000, currentMgbits, simulationTime);

macMetrics->testGetAvgThroughput("B_400Bytes_P_1000Bytes_Q_5-0.sca");


}

}; //namespace
