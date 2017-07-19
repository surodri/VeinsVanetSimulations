package vanets.src;

import org.car2x.veins.base.modules.*;
import org.car2x.veins.modules.nic.Nic80211p;

module CarWithMetrics
{
    parameters:
        string nicType = default("Nic80211pMetrics");
        string applType;
        string veinsmobilityType;
    gates:
        input veinsradioIn;
        
	submodules:    
        
        appl: <applType> like org.car2x.veins.base.modules.IBaseApplLayer {
        	parameters:
        	@display("p=60,50");
        }
         	       
        nic: <nicType> like org.car2x.veins.modules.nic.INic80211p {
             parameters:
                  @display("p=60, 50");
        }
         	       
        veinsmobility: <veinsmobilityType> like org.car2x.veins.base.modules.IMobility {
            parameters:
                @display("p=130, 172;i=block/cogwheel");
        }
     
     connections:
         nic.upperLayerOut --> appl.lowerLayerIn;
         nic.upperLayerIn <-- appl.lowerLayerOut;
         nic.upperControlOut --> appl.lowerControlIn;
         nic.upperControlIn <-- appl.lowerControlOut; 
         
         veinsradioIn --> nic.radioIn;         
}
