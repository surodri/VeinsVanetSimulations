package vanets.src;

import org.car2x.veins.modules.mac.ieee80211p.Mac1609_4; 

simple Mac16094Metrics extends Mac1609_4
{
    parameters:
        @signal[throughputSignalMac](type=double);
        @statistic[throughputMetricMac](title="throughputMetricMac"; source="throughputSignalMac"; record=last,count,sum, mean, vector?);
        //@statistic[throughputMbps](title="throughputMbps"; source 
	    @class(Mac16094Metrics); 
}