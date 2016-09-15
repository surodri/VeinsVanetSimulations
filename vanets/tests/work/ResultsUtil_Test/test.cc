
#include <omnetpp.h>

#include <ResultsUtilTest.h>



namespace ResultsUtil_Test {



class Test : public cSimpleModule
{
    public:
        Test() : cSimpleModule(32768) {}
        virtual void activity();
};

Define_Module(Test);

void Test::activity()
{

cout<< "WHHAT LKDSJFLSKDJFL:S?"<<endl;
ResultsUtilTest* resultsUtilTest = new ResultsUtilTest();

resultsUtilTest -> testTotalAvgReturnsZeroWhenThroughputPpsIsZero();

resultsUtilTest -> testTotalAvgIsNonzeroWhenOneOfTwoThroughputsIsZero();

resultsUtilTest -> testTotalAvgPrintsErrorWhenTypeNotInFile();

resultsUtilTest -> getTotalAvgFromFileInActualResults();

resultsUtilTest -> getTotalAvgFromLowDensitySingleChSafetyQ5();

resultsUtilTest -> getTotalAvgFromLowDensitySingleChSafetyQ2();

resultsUtilTest -> getTotalAvgFromLowDensitySingleChSafetyQ1();

resultsUtilTest -> getTotalAvgFromLowDensitySingleChSafetyQ100B100Bytes();

//resultsUtilTest -> getTotalAvgFromLowDensitySingleChSafetyQ2B100Bytes();

resultsUtilTest -> getTotalAvgFromLowDensitySingleChSafetyQ1B100Bytes();

resultsUtilTest -> getTotalAvgFromSlidesParamsB400BytesP1000BytesQ5();


}

}; //namespace
