
#include <omnetpp.h>

#include<TestMetrics.h>
#include <INETDefs.h>



namespace MetricsTests {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{

long currentNumBits = 9;
cPacket *pkt = new cPacket();
cMessage *message = pkt; // Valid   cPacket is a descendant of cMessage
cPacket *packet = dynamic_cast<cPacket*>(message);
packet->setBitLength(1);

TestMetrics* metrics = new TestMetrics();
long numberOfBits = metrics->testUpdateNumBits(currentNumBits, packet);

ev << numberOfBits ;
std::cout<<"numberOfBits: "<<numberOfBits<<std::endl;

delete pkt;
delete metrics;


}

}; //namespace
