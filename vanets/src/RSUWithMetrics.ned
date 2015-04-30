package vanets.src; 

import org.car2x.veins.base.modules.*;
import org.car2x.veins.modules.nic.Nic80211p;



network RSUWithMetrics 
{
    parameters:
        string nicType = default("Nic80211p");
    	string applType; 
    gates:
        input veinsradioInDirect @directIn;
        
 	submodules:
 	    
 	    
 	    metrics:Metrics{
 	        parameters:
 	            	@display("p=169,124");
 	    }
 	   
		appl: <applType> like org.car2x.veins.base.modules.IBaseApplLayer {
		    parameters:
		        @display("p=60,50");
		}
		 	   
 	    nic: <nicType> like org.car2x.veins.modules.nic.INic80211p {
 	        parameters:
 	            @display("p=6-,50");
 	    }
 	    
 	    mobility: BaseMobility {
 	        parameters:
 	            @display("p=130,172;i=block/cogwheel");
 	    }
 	    
 	    
 	connections allowunconnected:
		veinsradioInDirect --> { @display("m=s"); } --> nic.radioIn;
		nic.upperLayerOut --> metrics.in++;
		
		
}