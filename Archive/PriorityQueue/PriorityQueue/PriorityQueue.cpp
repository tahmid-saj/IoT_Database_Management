#include <iostream>
#include "nodeUpgradePQ.h"


int main()
{
    
    nodeUpgradePQ nodeUpgradePQList;

    nodeUpgradePQList.enqueue(5, "1");
    nodeUpgradePQList.enqueue(6, "2");
    nodeUpgradePQList.enqueue(3, "3");
    nodeUpgradePQList.enqueue(4, "4");
    nodeUpgradePQList.enqueue(1, "5");
    nodeUpgradePQList.enqueue(1, "6");
    nodeUpgradePQList.enqueue(1, "7");
    nodeUpgradePQList.enqueue(9, "8");
    nodeUpgradePQList.enqueue(10, "9");
    
    
    for (list<nodeOfPQ>::iterator tmpIt = nodeUpgradePQList.upgradePQList.begin(); tmpIt != nodeUpgradePQList.upgradePQList.end(); tmpIt++) {
        cout << tmpIt->upgradeTaskPriority << "\t\t\t\t" << "-" << tmpIt->upgradeTask << "\n";
    }

    return 0;
}