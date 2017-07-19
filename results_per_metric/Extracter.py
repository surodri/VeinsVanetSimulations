import re
import csv
import os

class DataParser():
		
	def parseValue(self, fileNames, metric, headers):
		
		outputLines =  []
		outputLines.insert(0, headers)

		for fileName in fileNames:
			print(fileName)
			isFileEmpty = os.stat(fileName).st_size 
			if isFileEmpty<=0:
				print "Empty File"
			file = open(fileName, 'r')
			for index, line in enumerate(file):
				index = index + 1
				value = line.split(metric, 1)[1]
				value = value.strip()
				
				if fileName == 'DroppedPacketsInMac_B_100_Q_1.txt':
				   print fileName + value

				if isFileEmpty<=0 :
				   print("NONE")
				   value = "None"

				if index>=len(outputLines):
				
					outputLines.insert(index, [str(index), value])
				else:
					someVal = outputLines[index]
					outputLines[index].append(value)
	
		return outputLines		
	
	def printData(self, data):
		fileName = "data.csv"
		with open(fileName, 'wb') as file:
			writer = csv.writer(file)
			
			for dataByType in data: 
				for index, line in enumerate(dataByType):
					row = dataByType[index]
					writer.writerow(row)
					print( " ".join(row))
	
	def printDataSet(self, dataByType, fileName):	
		with open(fileName, 'wb') as file:
			writer = csv.writer(file)
			for index, line in enumerate(dataByType):
				row = dataByType[index]
				writer.writerow(row)
				print( " ".join(row))


dataParser = DataParser()


metrics = ['SentPackets', 'ReceivedUnicastPackets','DroppedPacketsInMac', 'RXTXLostPackets', 'SNIRLostPackets','TotalLostPackets','ReceivedBroadcasts', 'receivedFramesLowerMsg', 'receivedBitsLowerPackets', 'packetsNotForMe', 'receivedBits']
metricsParsed = []

fileName = "data.csv"

for index, metric in enumerate(metrics): 

	headersSentPackets = [metric, 'Q5', 'Q2', 'Q1', 'Q5', 'Q2', 'Q1']
  
	filesSentPackets = [metric + '_B_100_Q_5.txt', metric + '_B_100_Q_2.txt', metric + '_B_100_Q_1.txt']
#,  metric + '_B_100_Q_1_Bitrate_27.txt', metric + '_B_100_Q_2_Bitrate_27.txt',  metric + '_B_100_Q_5_Bitrate_27.txt']
	dataByMetric = dataParser.parseValue(filesSentPackets, metric, headersSentPackets)  
	metricsParsed.insert(index, dataByMetric)

dataParser.printData(metricsParsed)

filesDroppedPackets = ['DroppedPacketsInMac_B_100_Q_5.txt', 'DroppedPacketsInMac_B_100_Q_2.txt', 'DroppedPacketsInMac_B_100_Q_1.txt' ]
z
