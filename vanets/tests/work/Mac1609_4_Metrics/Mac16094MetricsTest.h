#ifndef __MAC16094METRICSTEST_H
#define __MAC16094METRICSTESTh_H

using namespace std;
#include <../../../src/Mac16094Metrics.h>
#include <fstream>
#include <iomanip>


class Mac16094MetricsTest : public Mac16094Metrics{
	
   public:
	void testComputeThroughputPacketsPerSecond(Metrics* metrics, double packetsReceived, double currentTime){
		cout<<setiosflags(ios::fixed)<<setprecision(16);	
		Mac16094Metrics::computeThroughput(metrics, packetsReceived, currentTime);
		
		double result = Mac16094Metrics::getThroughputMetricMac();
		cout<<"throughputPps: "<<result<<endl;
		
	}

	void testThroughputMegabitsPerSecond(Metrics* metrics, double messageBits, double mgbitsReceived, double currentTime){
		cout<<setiosflags(ios::fixed)<<setprecision(16);
		Mac16094Metrics::computeThroughputMbps(metrics, messageBits, mgbitsReceived, currentTime);
	    double throughputResult = Mac16094Metrics::getThroughputMbps();
		cout<<"throughputMbps: "<<throughputResult<<endl;
	}
	
	void testHandleLowerMsgCallsThroughputWhenReceivingBroadcast(cMessage* message){
		Mac16094Metrics::statsReceivedBroadcasts = 5;
		//Mac16094Metrics::handleLowerMsg(message);
		
		//double throughputResult = testGetThroughputMetric();
		//cout<<"throughputPps:"<<throughputResult<<endl;		
	}
	
	double testGetThroughputSignal(){
		return Mac16094Metrics::metrics->getThroughputSignal();
	}

	void testGetAvgThroughput(string fileName){
	
		const char *fileNameConstChar = fileName.c_str();
		ifstream configFile (fileNameConstChar);
		if(configFile.is_open()){
			string word;
			for(string word; getline(configFile, word, ' ');){
			   if (word == "throghputMetricMac"){
				stringstream stream(word);
				string numString = " ";
				stream >> numString;
				cout<< numString <<endl;
				}
			}
		}
	}
};
#endif

