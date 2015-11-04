//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <Mac16094Metrics.h>
#include <../../../veins/src/veins/modules/phy/DeciderResult80211.h>
#include <../../../veins/src/veins/base/phyLayer/PhyToMacControlInfo.h>
using namespace std;
#define DBG_MAC EV
Define_Module(Mac16094Metrics); 

void Mac16094Metrics::initialize(int i){
    cout<<setiosflags(ios::fixed)<<setprecision(10);

    metrics= new Metrics();
    statsReceivedPackets = 0;
    statsMbpsReceived = 0;
    throughputMetricMac = 0;
    throughputMbps = 0;

    throughputSignalMac = registerSignal("throughputSignalMac");

    Mac1609_4::initialize(i);

    WATCH(throughputMetricMac);
    WATCH(throughputMbps);
}


void Mac16094Metrics::finish(){

    recordScalar("throughputMetricMac", throughputMetricMac);
    recordScalar("throughputMbps", throughputMbps);
    Mac1609_4::finish();
}

void Mac16094Metrics::handleLowerMsg(cMessage* message){
    Mac80211Pkt* macPkt = static_cast<Mac80211Pkt*>(message);
    ASSERT(macPkt);

    WaveShortMessage*  wsm =  dynamic_cast<WaveShortMessage*>(macPkt->decapsulate());

    //pass information about received frame to the upper layers
    DeciderResult80211 *macRes = dynamic_cast<DeciderResult80211 *>(PhyToMacControlInfo::getDeciderResult(message));
    ASSERT(macRes);
    DeciderResult80211 *res = new DeciderResult80211(*macRes);
    wsm->setControlInfo(new PhyToMacControlInfo(res));

    long dest = macPkt->getDestAddr();

    DBG_MAC << "Received frame name= " << macPkt->getName()
            << ", myState=" << " src=" << macPkt->getSrcAddr()
            << " dst=" << macPkt->getDestAddr() << " myAddr="
            << myMacAddress << std::endl;

    if (macPkt->getDestAddr() == myMacAddress) {
        DBG_MAC << "Received a data packet addressed to me." << std::endl;
        statsReceivedPackets++;

        double statsReceivedPacketsDbl = (double) statsReceivedPackets;
        double time = simTime().dbl();
        std::cout<<"statsReceivedPacketDbl"<< statsReceivedPacketsDbl<<endl;
        std::cout<<"time"<< time<<endl;
        computeThroughput(metrics, statsReceivedPacketsDbl,time);

        sendUp(wsm);
    }
    else if (dest == LAddress::L2BROADCAST) {

        cout<<setiosflags(ios::fixed)<<setprecision(16);

        statsReceivedBroadcasts++;
        double statsReceivedBroadcastsDbl = (double) statsReceivedBroadcasts;
        double time = simTime().dbl();

        std::cout<<"statsReceivedBroadcastsDbl"<< statsReceivedBroadcastsDbl<<endl;
        std::cout<<"time"<< time;

        double messageBits = (double)wsm->getBitLength();
        cout<<messageBits<<endl;

        computeThroughput(metrics, statsReceivedBroadcastsDbl,time);
        computeThroughputMbps(metrics, messageBits, statsMbpsReceived, time);

        sendUp(wsm);
    }
    else {
        DBG_MAC << "Packet not for me, deleting..." << std::endl;
        delete wsm;
    }
    delete macPkt;
}

void Mac16094Metrics::handleUpperMsg(cMessage* message){
    Mac1609_4::handleUpperMsg(message);
}

void Mac16094Metrics::handleSelfMsg(cMessage* message){
    Mac1609_4::handleSelfMsg(message);
}

void Mac16094Metrics::handleLowerControl(cMessage* message){
    Mac1609_4::handleLowerControl(message);
}

void Mac16094Metrics::handleUpperControl(cMessage* message){
    Mac1609_4::handleUpperControl(message);
}


void Mac16094Metrics::computeThroughput(Metrics* metrics, double receivedPackets, double currentSimulationTime){
  throughputMetricMac = metrics->computeThroughput(receivedPackets, currentSimulationTime);
  emit(throughputSignalMac, throughputMetricMac);
  metrics->throughputMetric = throughputMetricMac;
}

void Mac16094Metrics::computeThroughputMbps(Metrics* metrics, double messageBits, double currentMbs, double currentTime){
  cout<<setiosflags(ios::fixed)<<setprecision(16);

  double messageMbs = (messageBits)/1000000;

  cout<<"messageMbs: "<< messageMbs << endl;
  cout<<"currentMbs: "<< currentMbs << endl;
  cout<<"temp: "<< currentMbs + messageMbs << endl;

  statsMbpsReceived = currentMbs + messageMbs;

  cout<<"statsMbpsReceived: "<<statsMbpsReceived <<endl;

  throughputMbps = metrics->computeThroughput(statsMbpsReceived, currentTime);

  cout<<"statsMbpsReceived: "<< throughputMbps<<endl;
}

double Mac16094Metrics::getThroughputMbps(){
    return throughputMbps;
}

double Mac16094Metrics::getThroughputMetricMac(){
    return throughputMetricMac;
}

Mac16094Metrics::~Mac16094Metrics(){

}
