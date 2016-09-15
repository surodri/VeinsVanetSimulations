
#include <omnetpp.h>

#include<TestMetrics.h>
#include <INETDefs.h>




namespace Metrics_PacketsDeliveredToMetrics {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{

long currentNumPackets = 5;
std::string outputDescription = "packetsDelivered: ";


TestMetrics* metrics = new TestMetrics();
long packetsDelivered = metrics->testUpdateNumberOfPacketsReceived(currentNumPackets);

std::cout<<"Actual: "<<std::endl;
ev <<outputDescription << packetsDelivered ;

delete metrics;


}

}; //namespace
