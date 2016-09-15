
#include <omnetpp.h>

#include <../../../src/Metrics.h>
#include <TestMetrics2.h>
#include <INETDefs.h>



namespace Metrics_Throughput {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{
std::string outputDescription = "Throughput: ";

long bitLength = 10;
long currentNumPackets = 2;
int currentSimulationTime = 0;
cPacket *pkt = new cPacket();
cMessage *message = pkt; //Valid cPacket descendant of cMessage

cPacket *packet = dynamic_cast<cPacket*>(message);
packet ->setBitLength(bitLength);


TestMetrics2 *metrics = new TestMetrics2();
double throughput = metrics->testComputeThroughput(currentNumPackets, currentSimulationTime);

ev << outputDescription << throughput;
std::cout<<"Actual: "<<std::endl;

delete pkt;
delete metrics;


}

}; //namespace
