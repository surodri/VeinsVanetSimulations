#ifndef __RESULTSUTILSTEST_H
#define __RESULTSUTILSTESTh_H

#include <../../../src/ResultsUtil.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ResultsUtilTest : public ResultsUtil{

	public:
		void testTotalAvgReturnsZeroWhenThroughputPpsIsZero(){
			vector<string> results;
			results.push_back("throughputPps: 0");
 			createTestFile("ZeroThroughput.sca", results);	
			
			double avgResult = ResultsUtil::totalAvg("ZeroThroughput.sca", "throughputPps:");  	
			cout<< "testTotalAvgReturnsZeroWhenThroughputPpsIsZero	throughputTotalAvg: " << avgResult<< endl;
		}

		void testTotalAvgIsNonzeroWhenOneOfTwoThroughputsIsZero(){
			vector<string> results;
			results.push_back("throughputPps: 0");
			results.push_back("throughputPps: 2.5");
			createTestFile("ZeroAndNonzeroThroughput.sca", results);
			double avgResult = ResultsUtil::totalAvg("ZeroAndNonzeroThroughput.sca", "throughputPps:");
			
			cout<< "testTotalAvgIsNonzeroWhenOneOfTwoThroughputsIsZero	throughputTotalAvg: " << avgResult<< endl;
		}

		void testTotalAvgPrintsErrorWhenTypeNotInFile(){
			vector<string> results;
			createTestFile("TypeNotInFile.sca", results);
		
			cerr<< "testTotalAvgPrintsErrorWhenTypeNotInFile	";
			double avgResult = ResultsUtil::totalAvg("TypeNotInFile.sca", "randomType:");
			cout<< "Getting Rid of warning for AVGRESULT" << avgResult << endl;

		}

		void createTestFile(const char* fileName, vector<string> & results){
			cout<<fileName<<endl;
			ofstream myFile(fileName);
			if(myFile.is_open())
			{
				
				for(unsigned int i=0; i< results.size(); i++){
					myFile<<results.at(i)<<endl;
				}
				myFile.close();			
			}else{
				wcerr<<"Cannot open the test file." <<endl;
			}
			
		}

		void getTotalAvgFromFileInActualResults(){
			string type = "throughputMbps";
			double avgResult = ResultsUtil::totalAvg("B_400Bytes_P_1000Bytes_Q_5-0.sca", type);
			cout<<type << "	TotalAvg: "<< avgResult << endl;

			type = "throughputMetricMac";
			avgResult = ResultsUtil::totalAvg("B_400Bytes_P_1000Bytes_Q_5-0.sca", type);
			cout << type << "	TotalAvg: "<< avgResult << endl;

			type = "throughputMetricMac:last";
			avgResult = ResultsUtil::totalAvg("B_400Bytes_P_1000Bytes_Q_5-0.sca", type);
			cout << type << "	TotalAvg: "<< avgResult << endl;
		}

		void getTotalAvgFromLowDensitySingleChSafetyQ5(){
			string type = "throughputMbps";
			double avgResult;// = ResultsUtil::totalAvg("SingleCH_Safety_B_400Bytes_P_1000Bytes_Q_5-0.sca", type);

			cout<< type << " TotalAvg: "<< avgResult << endl;
	
			type = "throughputMetricMac";
//			avgResult = ResultsUtil::totalAvg("SingleCH_Safety_B_400Bytes_P_1000Bytes_Q_5-0.sca", type);

			cout << type << " TotalAvg: " << avgResult << endl; 				
					
			type = "throughputMetricMac:last";
//			avgResult = ResultsUtil::totalAvg("SingleCH_Safety_B_400Bytes_P_1000Bytes_Q_5-0.sca", type);

			cout << type << " TotalAvg: " << avgResult << endl; 			
		}
		
			
		void getTotalAvgFromLowDensitySingleChSafetyQ2(){
			getThroughputTotalAvgsFromFile("SingleCH_Safety_B_400Bytes_P_1000Bytes_Q_2-0.sca");

		}
	
		void getTotalAvgFromLowDensitySingleChSafetyQ1(){
			getThroughputTotalAvgsFromFile("SingleCH_Safety_B_400Bytes_P_1000Bytes_Q_1-0.sca");
		}

		void getTotalAvgFromLowDensitySingleChSafetyQ100B100Bytes(){
			getThroughputTotalAvgsFromFile("SingleCH_Safety_B_100Bytes_Q_100-0.sca");
		}

		void getTotalAvgFromLowDensitySingleChSafetyQ2B100Bytes(){
			getThroughputTotalAvgsFromFile("SingleCH_Safety_B_100Bytes_Q_2-0.sca");
		}

		void getTotalAvgFromLowDensitySingleChSafetyQ1B100Bytes(){
			getThroughputTotalAvgsFromFile("SingleCH_Safety_B_100Bytes_Q_1-0.sca");
		}

		void getTotalAvgFromSlidesParamsB400BytesP1000BytesQ5(){
			getThroughputTotalAvgsFromFile("SlidesParams_B_400Bytes_P_1000Bytes_Q_5-0.sca");
}


		void getThroughputTotalAvgsFromFile(const char* fileName){
			string type = "throughputMbps";
			double avgResult = ResultsUtil::totalAvg(fileName, type);

			cout<< type << " TotalAvg: "<< avgResult << endl;
	
			type = "throughputMetricMac";
			avgResult = ResultsUtil::totalAvg(fileName, type);

			cout << type << " TotalAvg: " << avgResult << endl; 				
					
			type = "throughputMetricMac:last";
			avgResult = ResultsUtil::totalAvg(fileName, type);

			cout << type << " TotalAvg: " << avgResult << endl; 			}

};

#endif

