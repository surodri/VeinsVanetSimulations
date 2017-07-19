
#include <omnetpp.h>

#include <PhyLayer80211p.h>


namespace FooCrap {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{
PhyLayer80211p* phy = new PhyLayer80211p();
Decider80211p* decider = new Decider80211p(phy , 0.0, 0.0, true, 0.0, -1, false, false);

enum Decider80211p::PACKET_OK_RESULT packetOkResult = decider-> packetOk(0.0, 0.0, 0, 0.0);
ev << packetOkResult ;

}

}; //namespace
