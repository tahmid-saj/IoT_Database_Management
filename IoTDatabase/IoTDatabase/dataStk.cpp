#include "dataStk.h"
#include "dataDLL.h"

#include <iostream>
#include <string>
#include <vector>

dataStk::dataStk() {

}

void dataStk::clear() {
	dataDLLStk.clear();
}

bool dataStk::isEmpty() const {
	return dataDLLStk.empty();
}

dataDLLNode& dataStk::topNode() {
	return dataDLLStk.back();
}

dataDLLNode dataStk::pop() {
	dataDLLNode tmpNode = dataDLLStk.front();
	dataDLLStk.pop_front();
	return tmpNode;
}

void dataStk::push(const dataDLLNode& node) {
	dataDLLStk.push_back(node);
}
