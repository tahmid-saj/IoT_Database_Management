#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataFiles
{
public:
	DataFiles();

	// Overloaded functions to get data files from default location
	void getWaterLevelFile();
	
	void getTemperatureFile();
	
	void getHumidityFile();

	void getNodeUpgradesFile();

	void getNodeWaterLevelsFile();

	void getNodeTemperaturesFile();

	void getNodeHumiditiesFile();

	// Overloaded functions to get data files from command line arguments
	void getWaterLevelFile(char *waterLevelFileLocation);

	void getTemperatureFile(char *temperatureFileLocation);

	void getHumidityFile(char *humidityFileLocation);

	void getNodeUpgradesFile(char *nodeUpgradeFileLocation);

	void getNodeWaterLevelsFile(char *nodeWaterLevelsFileLocation);

	void getNodeTemperaturesFile(char *nodeTemperaturesFileLocation);

	void getNodeHumiditiesFile(char *nodeHumiditiesFileLocation);

	// Functions to input into data file
	void inputWaterLevelFile(string inputDate, string inputTime, float inputMeasuredValue);

	void inputTemperatureFile(string inputDate, string inputTime, float inputMeasuredValue);

	void inputHumidityFile(string inputDate, string inputTime, float inputMeasuredValue);

	void inputNodeUpgradeTasksFile(int inputTaskPriority, string inputTask);

	char *waterLevelDataFileLocation, * temperatureDataFileLocation, * humidityDataFileLocation, * nodeUpgradeDataFileLocation,
		*nodeWaterLevelsDataFileLocation, *nodeTemperaturesDataFileLocation, *nodeHumiditiesDataFileLocation;

private:
	ifstream dataFileInput;
	ofstream dataFileOutput;
};

