#pragma once
#include <iostream>
#include <list>
#include <string>

using namespace std;

class nodeOfPQ {
public:
	nodeOfPQ() {
		upgradeTaskPriority = 11;
	}

	nodeOfPQ(int priority, string task) {
		upgradeTaskPriority = priority;
		upgradeTask = task;

	}

	int upgradeTaskPriority;
	string upgradeTask;
};

class nodeUpgradePQ
{
public:
	nodeUpgradePQ();
	~nodeUpgradePQ();

	// Insert a node
	void enqueue(int priority, string task);

	// Delete a node
	string dequeue();

	// Return the front node
	string front();

	// Check if priority queue is empty
	bool isEmpty();

	// Print the priority queue
	//ostream& printInitialPQ(ostringstream& os, int priority, string task);

	list<nodeOfPQ> upgradePQList;
};