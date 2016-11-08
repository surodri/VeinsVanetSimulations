#!/bin/sh

declare -a arr=("SentPackets" 
		"ReceivedUnicastPackets"
		"ReceivedBroadcasts"
		"SNIRLostPackets"
		"RXTXLostPackets"
		"TotalLostPackets"
		"DroppedPacketsInMac"
		"receivedFramesLowerMsg"
		"receivedBitsLowerPackets"
		"receivedBits"
		"packetsNotForMe")

declare -a sizes=("5") 

for metric in "${arr[@]}"
do
	echo "$metric" 
	echo "${metric}" 
	for queueSize in "${sizes}"
	do
		grep -r "$metric" SingleCH_Safety_B_100Bytes_Q_"$queueSize"-0.sca > ../../../results_per_metric/"$metric"_B_100_Q_"$queueSize".txt
		#grep -r "$metric" SingleCH_Safety_B_100Bytes_Q_"$queueSize"-0_27Mbitrate.sca > ../../../results_per_metric/"$metric"_B_100_Q_"$queueSize"_Bitrate_27.txt
	done
done

ls ../../../results_per_metric/ 
