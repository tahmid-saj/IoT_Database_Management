#pragma once

#include <iostream>
#include <string>

using namespace std;

class dataBSTNode {
public:
	float nodeRecentMeasuredValue;
	string nodeNumber;
	dataBSTNode* leftNode;
	dataBSTNode* rightNode;
};


class dataBST {
public:
	// BST
	dataBST();

	// ~BST
	~dataBST();

	// insert
	void insertNode(float measuredValue, string number);

	// remove
	void removeNode(float measuredValue, string number);

	// display
	void displayBST();

	// search
	void searchNode(float measuredValue, string number);

private:
	dataBSTNode* rootNode;

	// makeEmpty
	dataBSTNode* clearBST(dataBSTNode* bstRoot);

	// insert
	dataBSTNode* insertNode(float measuredValue, dataBSTNode* bstRoot, string number);

	// findMin
	dataBSTNode* findMinNode(dataBSTNode* bstRoot);

	// findMax
	dataBSTNode* findMaxNode(dataBSTNode* bstRoot);

	// remove
	dataBSTNode* removeNode(float measuredValue, dataBSTNode* bstRoot, string number);

	// inorder
	void inorder(dataBSTNode* bstRoot);

	// find
	dataBSTNode* findNode(dataBSTNode* bstRoot, float measuredValue, string number);
};
