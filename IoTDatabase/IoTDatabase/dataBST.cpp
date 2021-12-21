#include "dataBST.h"

#include <iostream>
#include <string>

using namespace std;

// Public functions

dataBST::dataBST() {
	rootNode = NULL;
}

dataBST::~dataBST() {
	rootNode = clearBST(rootNode);
}

void dataBST::insertNode(float measuredValue, string number) {
	rootNode = insertNode(measuredValue, rootNode, number);
}

void dataBST::removeNode(float measuredValue, string number) {
	rootNode = removeNode(measuredValue, rootNode, number);
}

void dataBST::displayBST() {
	inorder(rootNode);
	cout << endl;
}

void dataBST::searchNode(float measuredValue, string number) {
	rootNode = findNode(rootNode, measuredValue, number);
}

// Private functions

dataBSTNode* dataBST::clearBST(dataBSTNode* bstRoot) {
	if (bstRoot == NULL) {
		return NULL;
	}
	else {
		clearBST(bstRoot->leftNode);
		clearBST(bstRoot->rightNode);
		delete bstRoot;
	}

	return NULL;
}

dataBSTNode* dataBST::insertNode(float measuredValue, dataBSTNode* bstRoot, string number) {
	if (bstRoot == NULL) {
		bstRoot = new dataBSTNode;
		bstRoot->nodeRecentMeasuredValue = measuredValue;
		bstRoot->nodeNumber = number;

		bstRoot->leftNode = bstRoot->rightNode = NULL;
	}
	else if (measuredValue <= bstRoot->nodeRecentMeasuredValue) {
		bstRoot->leftNode = insertNode(measuredValue, bstRoot->leftNode, number);
	}
	else if (measuredValue > bstRoot->nodeRecentMeasuredValue) {
		bstRoot->rightNode = insertNode(measuredValue, bstRoot->rightNode, number);
	}

	return bstRoot;
}

dataBSTNode* dataBST::findMinNode(dataBSTNode* bstRoot) {
	if (bstRoot == NULL) {
		return NULL;
	}
	else if (bstRoot->leftNode == NULL) {
		return bstRoot;
	}
	else {
		return findMinNode(bstRoot->leftNode);
	}
}

dataBSTNode* dataBST::findMaxNode(dataBSTNode* bstRoot) {
	if (bstRoot == NULL) {
		return NULL;
	}
	else if (bstRoot->rightNode == NULL) {
		return bstRoot;
	}
	else {
		return findMaxNode(bstRoot->rightNode);
	}
}

dataBSTNode* dataBST::removeNode(float measuredValue, dataBSTNode* bstRoot, string number) {
	dataBSTNode* temp;

	if (bstRoot == NULL) {
		return NULL;
	}
	else if (measuredValue <= bstRoot->nodeRecentMeasuredValue) {
		bstRoot->leftNode = removeNode(measuredValue, bstRoot->leftNode, number);
	}
	else if (measuredValue > bstRoot->nodeRecentMeasuredValue) {
		bstRoot->rightNode = removeNode(measuredValue, bstRoot->rightNode, number);
	}
	else if (bstRoot->leftNode && bstRoot->rightNode) {
		temp = findMinNode(bstRoot->rightNode);
		bstRoot->nodeRecentMeasuredValue = temp->nodeRecentMeasuredValue;
		bstRoot->nodeNumber = temp->nodeNumber;

		bstRoot->rightNode = removeNode(bstRoot->nodeRecentMeasuredValue, bstRoot->rightNode, bstRoot->nodeNumber);
	}
	else {
		temp = bstRoot;

		if (bstRoot->leftNode == NULL)
			bstRoot = bstRoot->rightNode;
		else if (bstRoot->rightNode == NULL)
			bstRoot = bstRoot->leftNode;
		delete temp;
	}

	return bstRoot;
}

void dataBST::inorder(dataBSTNode* bstRoot) {
	if (bstRoot == NULL) {
		return;
	}

	inorder(bstRoot->leftNode);
	cout << bstRoot->nodeNumber << "\t\t\t\t" << bstRoot->nodeRecentMeasuredValue << endl;
	inorder(bstRoot->rightNode);
}

dataBSTNode* dataBST::findNode(dataBSTNode* bstRoot, float measuredValue, string number) {
	if (bstRoot == NULL) {
		return NULL;
	}
	else if (measuredValue <= bstRoot->nodeRecentMeasuredValue) {
		return findNode(bstRoot->leftNode, measuredValue, number);
	}
	else if (measuredValue > bstRoot->nodeRecentMeasuredValue) {
		return findNode(bstRoot->rightNode, measuredValue, number);
	}

	return bstRoot;
}