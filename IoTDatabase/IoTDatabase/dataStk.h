#pragma once
#include "dataDLL.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

class dataStk
{
public:
	friend class dataDLL;

	dataStk();

	// Clear the stack
	void clear();

	// Check if the stack is empty
	bool isEmpty() const;

	// Return the top node of the stack
	dataDLLNode& topNode();

	// Pop the top node of the stack
	dataDLLNode pop();

	// Push a node into the stack
	void push(const dataDLLNode& node);

private:
	list<dataDLLNode> dataDLLStk;
};

