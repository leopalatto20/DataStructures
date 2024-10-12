#pragma once
#include <iostream>

using namespace std;

template <typename T>
class DLinkedNode {
public:
	DLinkedNode* next;
	DLinkedNode* prev;
	T info;
	DLinkedNode(T info) : next(nullptr), prev(nullptr), info(info) {
	}
};
