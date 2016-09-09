
#include <omnetpp.h>



namespace NetworkSimulation_Parameters {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{
std::cout<<"WHAT UP " <<std::endl;


}

}; //namespace
