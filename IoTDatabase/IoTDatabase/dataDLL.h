#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class dataDLLNode {
public:
	friend class dataStk;
	friend void performMathOperation(string operation);
	dataDLLNode() {
		dataMeasuredValue = 0.0f;
		next = nullptr;
		prev = nullptr;
	}

	dataDLLNode(string date, string time, float measuredValue, dataDLLNode* n = nullptr, dataDLLNode* p = nullptr) {
		dataDate = date;
		dataTime = time;
		dataMeasuredValue = measuredValue;

		next = n;
		prev = p;
	}

	string dataDate;
	string dataTime;
	float dataMeasuredValue;

	dataDLLNode* next;
	dataDLLNode* prev;
};

class dataDLL
{
public:
	dataDLL();
	~dataDLL();

	// Data structure operations

	// Insert a node to the head
	void insertToHead(string date, string time, float measuredValue);

	// Insert a node to the tail
	void insertToTail(string date, string time, float measuredValue);

	// Check if empty
	bool isEmpty();

	// Check if in the DLL
	float isInList(string date, string time);

	// Math operations

	// Calculating average measure over period of time
	float calcAvgMeasure(string begDate, string begTime, string endDate, string endTime);

	// Calculating maximum measure over a period of time
	float calcMaxMeasure(string begDate, string begTime, string endDate, string endTime);

	// Calculating minimum measure over a period of time
	float calcMinMeasure(string begDate, string begTime, string endDate, string endTime);

	// Calculating percent error between a data and an entered value representing the actual measured value
	float calcPercentErr(string sensorDataDate, string sensorDataTime, float actualMeasuredValue);

	// Calculating the voltage calibration of a data set of the water levels using linear regression calculation 
	// (only available for water level data)
	void calcVoltCalibration();

	// Print the initial DLL
	ostream& printInitialList(ostringstream &os, string date, string time, float measuredValue);

	// Show the reverse DLL using the stack operations
	void getReverseDLL(string dataMeasurementType);

	// dataDLLType will be the type of data: water level, temperature or humidity
	string dataDLLType;

private:
	dataDLLNode* head;
	dataDLLNode* tail;
};

// Nonmember functions

istream& readParameterFile(istream& is, string dataMeasurementType);

// Insert a node anywhere (will insert data to the file as well)
void insertNode(ostream& os, string date, string time, float measuredValue);

// Search a node
void searchNodeValue(string date, string time, string dataMeasurementType);

void performMathOperation(string operation);