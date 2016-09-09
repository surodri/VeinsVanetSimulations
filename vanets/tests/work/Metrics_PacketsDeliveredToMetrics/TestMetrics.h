#ifndef __TESTMETRICS_H
#define __TESTMETRICS_H

#include <../../../src/Metrics.h>

class TestMetrics : public Metrics
{
	public:
		long testUpdateNumberOfPacketsReceived(long packetsDeliveredToMetrics){
			return Metrics::updateNumberOfPacketsReceived(packetsDeliveredToMetrics);
		};
};
#endif

