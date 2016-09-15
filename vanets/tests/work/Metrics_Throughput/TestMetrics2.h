#ifndef __TESTMETRICS2_H
#define __TESTMETRICSTh2_H

#include <../../../src/Metrics.h>

class TestMetrics2 : public Metrics
{
	public:
			double testComputeThroughput(double numberOfBits, double simulationTime){				
				return Metrics::computeThroughput(numberOfBits, simulationTime);
			};

};
#endif

