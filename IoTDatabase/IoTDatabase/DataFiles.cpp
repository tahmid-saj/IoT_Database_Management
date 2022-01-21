#include "DataFiles.h"
#include "dataDLL.h"
#include "nodeUpgradeQ.h"
#include "nodeUpgradePQ.h"
#include "dataBST.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Can use enums for the vector below in the future:
vector<string> dataMeasurementTypes = {"Water Level", "Temperature", "Humidity"};

dataBST bstNodeWaterLevels, bstNodeTemperatures, bstNodeHumidities;

DataFiles::DataFiles() = default;

// Overloaded functions to get data files from default location
void DataFiles::getWaterLevelFile() {
	dataFileInput.open("Data Files/WaterLevels.txt");
	waterLevelDataFileLocation = (char*)"Data Files/WaterLevels.txt";

	string dateHeader, timeHeader, measuredValueHeader;

	dataFileInput >> dateHeader >> timeHeader >> measuredValueHeader;
	cout << dateHeader << "\t" << timeHeader << "\t" << measuredValueHeader << endl;

	cout << "Water level list:" << endl;
	
	while (!dataFileInput.eof()) {
		readParameterFile(dataFileInput, ::dataMeasurementTypes[0]);
	}

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getTemperatureFile() {
	dataFileInput.open("Data Files/Temperatures.txt");
	temperatureDataFileLocation = (char*)"Data Files/Temperatures.txt";

	string dateHeader, timeHeader, measuredValueHeader;

	dataFileInput >> dateHeader >> timeHeader >> measuredValueHeader;
	cout << dateHeader << "\t" << timeHeader << "\t" << measuredValueHeader << endl;

	cout << "Temperature list:" << endl;

	while (!dataFileInput.eof()) {
		readParameterFile(dataFileInput, ::dataMeasurementTypes[1]);
	}

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getHumidityFile() {
	dataFileInput.open("Data Files/Humidities.txt");
	humidityDataFileLocation = (char*)"Data Files/Humidities.txt";

	string dateHeader, timeHeader, measuredValueHeader;

	dataFileInput >> dateHeader >> timeHeader >> measuredValueHeader;
	cout << dateHeader << "\t" << timeHeader << "\t" << measuredValueHeader << endl;

	cout << "Humidity list:" << endl;

	while (!dataFileInput.eof()) {
		readParameterFile(dataFileInput, ::dataMeasurementTypes[2]);
	}

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getNodeUpgradesFile() {
	dataFileInput.open("Data Files/NodeUpgradeTasks.txt");
	nodeUpgradeDataFileLocation = (char*)"Data Files/NodeUpgradeTasks.txt";

	string priorityHeader, taskHeader;

	cout << "Node upgrade tasks (without piority):" << endl;
	dataFileInput >> priorityHeader >> taskHeader;
	cout << taskHeader << endl;

	while (!dataFileInput.eof()) {
		readUpgradeTaskFileQ(dataFileInput);
	}

	cout << endl;

	cout << "Node upgrade tasks (with priority):" << endl;
	cout << priorityHeader << "\t" << taskHeader << endl;

	dataFileInput.seekg(0, ios::beg);

	dataFileInput.ignore(numeric_limits<streamsize>::max(), '\n');

	while (!dataFileInput.eof()) {
		readUpgradeTaskFilePQ(dataFileInput);
	}

	ostringstream osTaskUpgradesPQ;
	printInitialPQ(osTaskUpgradesPQ);

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getNodeWaterLevelsFile() {
	dataFileInput.open("Data Files/NodeWaterLevels.txt");
	nodeWaterLevelsDataFileLocation = (char*)"Data Files/NodeWaterLevels.txt";

	string nodeNumberHeader, measuredValueHeader;

	dataFileInput >> nodeNumberHeader >> measuredValueHeader;
	cout << nodeNumberHeader << "\t\t" << measuredValueHeader << endl;

	cout << "Node numbers and recently measured water levels:" << endl;

	while (!dataFileInput.eof()) {
		float measuredValue;
		string nodeNumber;

		dataFileInput >> nodeNumber; 
		dataFileInput >> measuredValue;

		::bstNodeWaterLevels.insertNode(measuredValue, nodeNumber);
	}

	::bstNodeWaterLevels.displayBST();
	dataFileInput.close();
}

void DataFiles::getNodeTemperaturesFile() {
	dataFileInput.open("Data Files/NodeTemperatures.txt");
	nodeTemperaturesDataFileLocation = (char*)"Data Files/NodeTemperatures.txt";

	string nodeNumberHeader, measuredValueHeader;

	dataFileInput >> nodeNumberHeader >> measuredValueHeader;
	cout << nodeNumberHeader << "\t\t" << measuredValueHeader << endl;

	cout << "Node numbers and recently measured temperatures:" << endl;

	while (!dataFileInput.eof()) {
		float measuredValue;
		string nodeNumber;

		dataFileInput >> nodeNumber;
		dataFileInput >> measuredValue;

		::bstNodeTemperatures.insertNode(measuredValue, nodeNumber);
	}

	::bstNodeTemperatures.displayBST();
	dataFileInput.close();
}

void DataFiles::getNodeHumiditiesFile() {
	dataFileInput.open("Data Files/NodeHumidities.txt");
	nodeHumiditiesDataFileLocation = (char*)"Data Files/NodeHumidities.txt";

	string nodeNumberHeader, measuredValueHeader;

	dataFileInput >> nodeNumberHeader >> measuredValueHeader;
	cout << nodeNumberHeader << "\t\t" << measuredValueHeader << endl;

	cout << "Node numbers and recently measured water levels:" << endl;

	while (!dataFileInput.eof()) {
		float measuredValue;
		string nodeNumber;

		dataFileInput >> nodeNumber;
		dataFileInput >> measuredValue;

		::bstNodeHumidities.insertNode(measuredValue, nodeNumber);
	}

	::bstNodeHumidities.displayBST();
	dataFileInput.close();
}

// Overloaded functions to get data files from command line arguments
void DataFiles::getWaterLevelFile(char *waterLevelFileLocation) {
	dataFileInput.open(waterLevelFileLocation);

	waterLevelDataFileLocation = waterLevelFileLocation;

	string dateHeader, timeHeader, measuredValueHeader;

	dataFileInput >> dateHeader >> timeHeader >> measuredValueHeader;
	cout << dateHeader << "\t" << timeHeader << "\t" << measuredValueHeader << endl;

	cout << "Water level list:" << endl;

	while (!dataFileInput.eof()) {
		readParameterFile(dataFileInput, ::dataMeasurementTypes[0]);
	}

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getTemperatureFile(char *temperatureFileLocation) {
	dataFileInput.open(temperatureFileLocation);

	temperatureDataFileLocation = temperatureFileLocation;

	string dateHeader, timeHeader, measuredValueHeader;

	dataFileInput >> dateHeader >> timeHeader >> measuredValueHeader;
	cout << dateHeader << "\t" << timeHeader << "\t" << measuredValueHeader << endl;

	cout << "Temperature list:" << endl;

	while (!dataFileInput.eof()) {
		readParameterFile(dataFileInput, ::dataMeasurementTypes[1]);
	}

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getHumidityFile(char *humidityFileLocation) {
	dataFileInput.open(humidityFileLocation);

	humidityDataFileLocation = humidityFileLocation;

	string dateHeader, timeHeader, measuredValueHeader;

	dataFileInput >> dateHeader >> timeHeader >> measuredValueHeader;
	cout << dateHeader << "\t" << timeHeader << "\t" << measuredValueHeader << endl;

	cout << "Humidity list:" << endl;

	while (!dataFileInput.eof()) {
		readParameterFile(dataFileInput, ::dataMeasurementTypes[2]);
	}

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getNodeUpgradesFile(char *nodeUpgradeFileLocation) {
	dataFileInput.open(nodeUpgradeFileLocation);

	nodeUpgradeDataFileLocation = nodeUpgradeFileLocation;

	string priorityHeader, taskHeader;

	cout << "Node upgrade tasks (without piority):" << endl;
	dataFileInput >> priorityHeader >> taskHeader;
	cout << taskHeader << endl;

	while (!dataFileInput.eof()) {
		readUpgradeTaskFileQ(dataFileInput);
	}

	cout << endl;

	cout << "Node upgrade tasks (with priority):" << endl;
	cout << priorityHeader << "\t" << taskHeader << endl;

	dataFileInput.seekg(0, ios::beg);

	dataFileInput.ignore(numeric_limits<streamsize>::max(), '\n');

	while (!dataFileInput.eof()) {
		readUpgradeTaskFilePQ(dataFileInput);
	}

	ostringstream osTaskUpgradesPQ;
	printInitialPQ(osTaskUpgradesPQ);

	cout << endl;
	dataFileInput.close();
}

void DataFiles::getNodeWaterLevelsFile(char* nodeWaterLevelsFileLocation) {
	dataFileInput.open(nodeWaterLevelsFileLocation);

	nodeWaterLevelsDataFileLocation = nodeWaterLevelsFileLocation;

	string nodeNumberHeader, measuredValueHeader;

	dataFileInput >> nodeNumberHeader >> measuredValueHeader;
	cout << nodeNumberHeader << "\t\t" << measuredValueHeader << endl;

	cout << "Node numbers and recently measured water levels:" << endl;

	while (!dataFileInput.eof()) {
		float measuredValue;
		string nodeNumber;

		dataFileInput >> nodeNumber;
		dataFileInput >> measuredValue;

		::bstNodeWaterLevels.insertNode(measuredValue, nodeNumber);
	}

	::bstNodeWaterLevels.displayBST();
	dataFileInput.close();
}

void DataFiles::getNodeTemperaturesFile(char* nodeTemperaturesFileLocation) {
	dataFileInput.open(nodeTemperaturesFileLocation);

	nodeTemperaturesDataFileLocation = nodeTemperaturesFileLocation;

	string nodeNumberHeader, measuredValueHeader;

	dataFileInput >> nodeNumberHeader >> measuredValueHeader;
	cout << nodeNumberHeader << "\t\t" << measuredValueHeader << endl;

	cout << "Node numbers and recently measured temperatures:" << endl;

	while (!dataFileInput.eof()) {
		float measuredValue;
		string nodeNumber;

		dataFileInput >> nodeNumber;
		dataFileInput >> measuredValue;

		::bstNodeTemperatures.insertNode(measuredValue, nodeNumber);
	}

	::bstNodeTemperatures.displayBST();
	dataFileInput.close();
}

void DataFiles::getNodeHumiditiesFile(char* nodeHumiditiesFileLocation) {
	dataFileInput.open(nodeHumiditiesFileLocation);

	nodeHumiditiesDataFileLocation = nodeHumiditiesFileLocation;

	string nodeNumberHeader, measuredValueHeader;

	dataFileInput >> nodeNumberHeader >> measuredValueHeader;
	cout << nodeNumberHeader << "\t\t" << measuredValueHeader << endl;

	cout << "Node numbers and recently measured water levels:" << endl;

	while (!dataFileInput.eof()) {
		float measuredValue;
		string nodeNumber;

		dataFileInput >> nodeNumber;
		dataFileInput >> measuredValue;

		::bstNodeHumidities.insertNode(measuredValue, nodeNumber);
	}

	::bstNodeHumidities.displayBST();
	dataFileInput.close();
}

// Functions to input into data file
void DataFiles::inputWaterLevelFile(string inputDate, string inputTime, float inputMeasuredValue) {
	dataFileOutput.open(waterLevelDataFileLocation, fstream::app);

	cout << "Inserting " << inputDate << " " << inputTime << " " << inputMeasuredValue << endl;
	insertNode(dataFileOutput, inputDate, inputTime, inputMeasuredValue);

	dataFileOutput.close();
}

void DataFiles::inputTemperatureFile(string inputDate, string inputTime, float inputMeasuredValue) {
	dataFileOutput.open(temperatureDataFileLocation, fstream::app);

	cout << "Inserting " << inputDate << " " << inputTime << " " << inputMeasuredValue << endl;
	insertNode(dataFileOutput, inputDate, inputTime, inputMeasuredValue);

	dataFileOutput.close();
}

void DataFiles::inputHumidityFile(string inputDate, string inputTime, float inputMeasuredValue) {
	dataFileOutput.open(humidityDataFileLocation, fstream::app);

	cout << "Inserting " << inputDate << " " << inputTime << " " << inputMeasuredValue << endl;
	insertNode(dataFileOutput, inputDate, inputTime, inputMeasuredValue);

	dataFileOutput.close();
}

void DataFiles::inputNodeUpgradeTasksFile(int inputTaskPriority, string inputTask) {
	dataFileOutput.open(nodeUpgradeDataFileLocation, fstream::app);

	cout << "Inserting " << inputTaskPriority << " " << inputTask << endl;
	dataFileOutput << "\n" << inputTaskPriority << " " << inputTask;

	dataFileOutput.close();
}