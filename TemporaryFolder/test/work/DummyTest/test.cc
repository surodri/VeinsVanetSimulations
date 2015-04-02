
#include <omnetpp.h>



namespace DummyTest {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{
cMessage msg;
msg.setSchedulingPriority(456);
ev << "SchedulingPriority: " << msg.getSchedulingPriority() << endl;


}

}; //namespace
