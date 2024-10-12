#pragma once
#include <iostream>
#include "DLinkedNode.h"

using namespace std;

template <typename T>
class DLinkedList {
private:
	DLinkedNode<T>* head;
public:
	DLinkedList() : head(nullptr) {
	}

	~DLinkedList() {
		deleteList();
	}

	void deleteList() {
		DLinkedNode<T>* current = head;
		while(current) {
			DLinkedNode<T>* tmp = current->next;
			delete current;
			current = tmp;
		}
		head = nullptr;
	}

	bool insertData(T data) {
		DLinkedNode<T>* newNode = new(nothrow) DLinkedNode<T>(data);
			if(!newNode)
				return false;
		if(!head) {
			head = newNode;
			return true;
		}
		DLinkedNode<T>* current = head;
		while(current->next) {
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
		return true;
	}

	bool insertDataStart(T dato) {
		DLinkedNode<T>* newNode = new(nothrow) DLinkedNode<T>(dato);
		if(!newNode)
			return false;
		if(!head) {
			head = newNode;
			return true;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return true;
	}

	bool deleteNode(T dato) {
		if(!head)
			return false;
		DLinkedNode<T>* current = head;
		while(current && current->info != dato) {
			current = current->next;
		}
		if(!current)
			return false;
		if(current == head)
			return deleteHead();
		current->prev->next = current->next;
		delete current;
		return true;
	}

	bool deleteHead() {
		if(!head)
			return false;
		DLinkedNode<T>* tmp = head;
		head = head->next;
		delete tmp;
		return true;
	}

	void printList() {
		DLinkedNode<T>* current = head;
		while(current) {
			cout << current->info << " " << endl;
			current = current->next;
		}
	}
};

