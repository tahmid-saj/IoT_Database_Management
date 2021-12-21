#include "nodeUpgradePQ.h"
#include <iostream>
#include <sstream>
#include <list>
#include <string>

using namespace std;

nodeUpgradePQ nodeUpgradePQList;

nodeUpgradePQ::nodeUpgradePQ() {

}

nodeUpgradePQ::~nodeUpgradePQ() {
	upgradePQList.clear();
}

void nodeUpgradePQ::enqueue(int priority, string task) {
	nodeOfPQ* tmpNode = new nodeOfPQ(priority, task);

	if ((*this).isEmpty()) {
		upgradePQList.push_back(*tmpNode);
	}
	else if (!(*this).isEmpty()) {

		list<nodeOfPQ>::iterator tmpIt;
		for (tmpIt = upgradePQList.begin(); tmpIt != upgradePQList.end(); tmpIt++) {
			if (tmpNode->upgradeTaskPriority <= tmpIt->upgradeTaskPriority) {

				upgradePQList.list::insert(tmpIt, *tmpNode);
				return;
			}
		}



		if (tmpIt == upgradePQList.end()) {
			upgradePQList.insert(tmpIt, *tmpNode);
		}
	}
}

string nodeUpgradePQ::dequeue() {
	return "";
}

string nodeUpgradePQ::front() {
	return "";
}

bool nodeUpgradePQ::isEmpty() {
	return upgradePQList.empty();
}