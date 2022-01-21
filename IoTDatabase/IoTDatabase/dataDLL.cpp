#include "dataDLL.h"
#include "dataStk.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>

#define S 100

using namespace std;

dataDLL genList, waterLevelDataList, temperatureDataList, humidityDataList;

dataStk waterLevelDataStk, temperatureDataStk, humidityDataStk;

dataDLL::dataDLL() {
	head = nullptr;
	tail = nullptr;
}

dataDLL::~dataDLL() {
	for (dataDLLNode* node; !isEmpty(); ) {
		node = head->next;
		delete head;
		head = node;
	}
}

// Data structure operations

void dataDLL::insertToHead(string date, string time, float measuredValue) {
	head = new dataDLLNode(date, time, measuredValue, head);

	if (tail == nullptr) {
		tail = head;
	}
}

void dataDLL::insertToTail(string date, string time, float measuredValue) {
	if (tail != nullptr) {
		tail = new dataDLLNode(date, time, measuredValue, nullptr, tail);
		tail->prev->next = tail;
	}
	else {
		head = tail = new dataDLLNode(date, time, measuredValue);
	}
}

bool dataDLL::isEmpty() {
	return head == nullptr;
}

float dataDLL::isInList(string date, string time) {
	// Check if any node with the string values date and time is in the linked list

	for (dataDLLNode* searchNode = this->head; searchNode != nullptr; searchNode = searchNode->next) {
		if (searchNode->dataDate == date && searchNode->dataTime == time) {
			cout << "\nThe measured value is: " << searchNode->dataMeasuredValue << endl;
			return searchNode->dataMeasuredValue;
		}
	}

	return -1;
}

// Math operations

float dataDLL::calcAvgMeasure(string begDate, string begTime, string endDate, string endTime) {
	float sumMeasure = 0.0, avgMeasure = 0.0;
	cout << "The measured values for the beginning and end date, times are: " << endl;

	if (isInList(begDate, begTime) != -1 && isInList(endDate, endTime) != -1) {
		int countValues = 0;
		
		for (dataDLLNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
			if (tmp->dataDate == endDate && tmp->dataTime == endTime) {
				countValues++;
				sumMeasure += tmp->dataMeasuredValue;
				continue;
			}

			if (countValues > 0 && (tmp->dataDate != begDate || tmp->dataTime != begTime)) {
				countValues++;
				sumMeasure += tmp->dataMeasuredValue;
				continue;
			}

			if (countValues > 0 && tmp->dataDate == begDate && tmp->dataTime == begTime) {
				countValues++;
				sumMeasure += tmp->dataMeasuredValue;
				avgMeasure = sumMeasure / countValues;
				return avgMeasure;
			}
		}
	}
	
	return avgMeasure;
}

float dataDLL::calcMaxMeasure(string begDate, string begTime, string endDate, string endTime) {
	float maxMeasure = 0.0f;
	cout << "The measured values for the beginning and end dates, times are: " << endl;

	if (isInList(begDate, begTime) != -1 && isInList(endDate, endTime) != -1) {
		bool afterEnd = false;

		for (dataDLLNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
			if (tmp->dataDate == endDate && tmp->dataTime == endTime) {
				afterEnd = true;
			}

			if (afterEnd && (tmp->dataDate != begDate || tmp->dataTime != begTime) && 
				((tmp->dataMeasuredValue) > maxMeasure)) {
				maxMeasure = tmp->dataMeasuredValue;
				continue;
			}

			if (afterEnd && tmp->dataDate == begDate && tmp->dataTime == begTime) {
				if (tmp->dataMeasuredValue > maxMeasure) {
					maxMeasure = tmp->dataMeasuredValue;
				}

				break;
			}
			
		}
	}

	return maxMeasure;
}

float dataDLL::calcMinMeasure(string begDate, string begTime, string endDate, string endTime) {
	float minMeasure = 0.0f;
	cout << "The measured values for the beginning and end dates, times are: " << endl;

	if (isInList(begDate, begTime) != -1 && isInList(endDate, endTime) != -1) {
		bool afterEnd = false;

		for (dataDLLNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
			if (tmp->dataDate == endDate && tmp->dataTime == endTime) {
				afterEnd = true;
				minMeasure = tmp->dataMeasuredValue;
			}

			if (afterEnd && (tmp->dataDate != begDate || tmp->dataTime != begTime) &&
				((tmp->dataMeasuredValue) < minMeasure)) {
				minMeasure = tmp->dataMeasuredValue;
				continue;
			}

			if (afterEnd && tmp->dataDate == begDate && tmp->dataTime == begTime) {
				if (tmp->dataMeasuredValue < minMeasure) {
					minMeasure = tmp->dataMeasuredValue;
				}

				break;
			}

		}
	}

	return minMeasure;
}

float dataDLL::calcPercentErr(string sensorDataDate, string sensorDataTime, float actualMeasuredValue) {
	float percentErr = 0.0;

	cout << "The measured values for the beginning and end dates, times are: " << endl;

	if (isInList(sensorDataDate, sensorDataTime) != -1) {

		for (dataDLLNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
			if (tmp->dataDate == sensorDataDate && tmp->dataTime == sensorDataTime) {
				percentErr = (abs(tmp->dataMeasuredValue - actualMeasuredValue) / abs(actualMeasuredValue)) * 100;
				break;
			}
		}
	}

	return percentErr;
}

void dataDLL::calcVoltCalibration() {
	int n, i;
	float x[S], y[S], sumX = 0, sumX2 = 0, sumY = 0, sumXY = 0, a, b;

	// Input x, y
	cout << "How many data points? [x is the calibration, y is the water level]";
	cin >> n;

	cout << "Enter data points:" << endl;

	for (i = 1; i <= n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
		cout << "y[" << i << "] = ";
		cin >> y[i];
	}

	// Calculating sum
	for (i = 1; i <= n; i++)
	{
		sumX = sumX + x[i];
		sumX2 = sumX2 + x[i] * x[i];

		sumY = sumY + y[i];
		sumXY = sumXY + x[i] * y[i];
	}

	// Calculating a and b
	b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
	a = (sumY - b * sumX) / n;

	// Displaying value of a and b
	cout << "Calculated value of a is " << a << "and b is " << b << endl;
	cout << "Equation of best fit is: y = " << a << " + " << b << "x";
}

// Printing the list using list object
ostream& dataDLL::printInitialList(ostringstream &os, string date, string time, float measuredValue) {
	os << date << "\t\t" << time << "\t\t\t\t" << measuredValue << "\n";
	cout << os.str();

	return os;
}

void dataDLL::getReverseDLL(string dataMeasurementType) {
	int DLLSize = 0;

	for (dataDLLNode *tmpNode = head; tmpNode != nullptr; tmpNode = tmpNode->next) {
		dataDLLNode *pushingNode = new dataDLLNode(tmpNode->dataDate, tmpNode->dataTime, tmpNode->dataMeasuredValue);

		if (dataMeasurementType == std::string("Water Level")) {
			::waterLevelDataStk.push(*pushingNode);
			DLLSize++;
		}
		else if (dataMeasurementType == std::string("Temperature")) {
			::temperatureDataStk.push(*pushingNode);
			DLLSize++;
		}
		else if (dataMeasurementType == std::string("Humidity")) {
			::humidityDataStk.push(*pushingNode);
			DLLSize++;
		}
	}

	cout << "\nReverse list:" << endl;

	for (int i = 1; i <= DLLSize; i++) {
		if (dataMeasurementType == std::string("Water Level")) {
			dataDLLNode popedNode = ::waterLevelDataStk.pop();
			cout << popedNode.dataDate << "\t\t" << popedNode.dataTime << "\t\t\t\t" << popedNode.dataMeasuredValue << endl;
		}
		else if (dataMeasurementType == std::string("Temperature")) {
			dataDLLNode popedNode = ::temperatureDataStk.pop();
			cout << popedNode.dataDate << "\t\t" << popedNode.dataTime << "\t\t\t\t" << popedNode.dataMeasuredValue << endl;
		}
		else if (dataMeasurementType == std::string("Humidity")) {
			dataDLLNode popedNode = ::humidityDataStk.pop();
			cout << popedNode.dataDate << "\t\t" << popedNode.dataTime << "\t\t\t\t" << popedNode.dataMeasuredValue << endl;
		}
	}
}

// Nonmember functions

istream& readParameterFile(istream& is, string dataMeasurementType) {

	// Initialize the list by using the insertToHead function

	if (dataMeasurementType == std::string("Water Level")) {
		::waterLevelDataList.dataDLLType = dataMeasurementType;

		string rowDateValue, rowTimeValue;
		float rowMeasuredValueFloat;

		is >> rowDateValue >> rowTimeValue;
		is >> rowMeasuredValueFloat;
		
		::waterLevelDataList.insertToHead(rowDateValue, rowTimeValue, rowMeasuredValueFloat);

		ostringstream osWaterLevelList;
		::waterLevelDataList.printInitialList(osWaterLevelList, rowDateValue, rowTimeValue, rowMeasuredValueFloat);

		// Reversing water level DLL
		if (is.eof() && ::waterLevelDataStk.isEmpty()) {
			::waterLevelDataList.getReverseDLL(dataMeasurementType);
		}

		return is;
	}
	
	if (dataMeasurementType == std::string("Temperature")) {
		::temperatureDataList.dataDLLType = dataMeasurementType;

		string rowDateValue, rowTimeValue;
		float rowMeasuredValueFloat;

		is >> rowDateValue >> rowTimeValue;
		is >> rowMeasuredValueFloat;

		::temperatureDataList.insertToHead(rowDateValue, rowTimeValue, rowMeasuredValueFloat);

		ostringstream osTemperatureList;
		::temperatureDataList.printInitialList(osTemperatureList, rowDateValue, rowTimeValue, rowMeasuredValueFloat);

		// Reversing water level DLL
		if (is.eof() && ::temperatureDataStk.isEmpty()) {
			::temperatureDataList.getReverseDLL(dataMeasurementType);
		}

		return is;
	}

	if (dataMeasurementType == std::string("Humidity")) {
		::humidityDataList.dataDLLType = dataMeasurementType;

		string rowDateValue, rowTimeValue;
		float rowMeasuredValueFloat;

		is >> rowDateValue >> rowTimeValue;
		is >> rowMeasuredValueFloat;

		::humidityDataList.insertToHead(rowDateValue, rowTimeValue, rowMeasuredValueFloat);

		ostringstream osHumidityList;
		::humidityDataList.printInitialList(osHumidityList, rowDateValue, rowTimeValue, rowMeasuredValueFloat);

		// Reversing water level DLL
		if (is.eof() && ::humidityDataStk.isEmpty()) {
			::humidityDataList.getReverseDLL(dataMeasurementType);
		}

		return is;
	}

	return is;
}

void insertNode(ostream& os, string date, string time, float measuredValue) {
	// When inserting a node, the values from the node should be added to the data file as well
	// This will call another function in the DataFiles class to insert the data in the data file
	
	os << "\n" << date << " " << time << " " << measuredValue;
}

void searchNodeValue(string date, string time, string dataMeasurementType) {
	dataDLL* tmpDataDLL = &(::genList);

	if (dataMeasurementType == std::string("water-level")) {
		tmpDataDLL = &(::waterLevelDataList);
	}
	else if (dataMeasurementType == std::string("temperature")) {
		tmpDataDLL = &(::temperatureDataList);
	}
	else if (dataMeasurementType == std::string("humidity")) {
		tmpDataDLL = &(::humidityDataList);
	}

	if (tmpDataDLL->isInList(date, time) == -1) {
		cout << "\nThere is no value with this date and time." << endl;
	}
}

void performMathOperation(string operation) {
	string bDate, bTime, eDate, eTime;

	if (operation == std::string("Avg")) {
		cout << "\nEnter the beginning [date] and [time], and ending [date] and [time]: ";
		cin >> bDate >> bTime >> eDate >> eTime;

		cout << ::waterLevelDataList.calcAvgMeasure(bDate, bTime, eDate, eTime) << endl;
	}
	else if (operation == std::string("Max")) {
		cout << "\nEnter the beginning [date] and [time], and ending [date] and [time]: ";
		cin >> bDate >> bTime >> eDate >> eTime;

		cout << ::waterLevelDataList.calcMaxMeasure(bDate, bTime, eDate, eTime) << endl;
	}
	else if (operation == std::string("Min")) {
		cout << "\nEnter the beginning [date] and [time], and ending [date] and [time]: ";
		cin >> bDate >> bTime >> eDate >> eTime;

		cout << ::waterLevelDataList.calcMinMeasure(bDate, bTime, eDate, eTime) << endl;
	}
	else if (operation == std::string("Err")) {
		cout << "\nEnter the [date], [time] and [actual measured value] you would like to compare with: ";
		string sensorDate, sensorTime;
		float actualValue;

		cin >> sensorDate >> sensorTime >> actualValue;
		cout << ::waterLevelDataList.calcPercentErr(sensorDate, sensorTime, actualValue) << endl;
	}
	else if (operation == std::string("Calibration")) {
		::waterLevelDataList.calcVoltCalibration();
	}
}