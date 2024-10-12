#pragma once
#include <iostream>

using namespace std;

template <typename T>
class BinaryNode {
public:
	T info;
	BinaryNode* left;
	BinaryNode* right;
	BinaryNode(T info) : info(info), left(nullptr), right(nullptr) {
	}
};
