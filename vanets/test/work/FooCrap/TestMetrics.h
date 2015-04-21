#ifndef __TESTMETRICS_H
#define __TESTMETRICS_H

#include <../../../src/Metrics.h>

class TestMetrics : public Metrics
{
	public:
		long testUpdateNumBits(long numberOfBits, cPacket* packet){
			return Metrics::updateNumberOfBits(numberOfBits, packet);
		};
};
#endif


