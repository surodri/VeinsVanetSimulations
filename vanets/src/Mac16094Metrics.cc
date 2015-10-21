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

#define DBG_MAC EV
Define_Module(Mac16094Metrics); 

void Mac16094Metrics::initialize(int i){
    metrics= new Metrics();
    Mac1609_4::initialize(i);
}


void Mac16094Metrics::finish(){
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
        metrics->computeThroughput(statsReceivedPackets,simTime().dbl());
        sendUp(wsm);
    }
    else if (dest == LAddress::L2BROADCAST) {
        statsReceivedBroadcasts++;
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
  double throughput = metrics->computeThroughput(receivedPackets, currentSimulationTime);
  metrics->throughputMetric = throughput;

}

Mac16094Metrics::~Mac16094Metrics(){

}
