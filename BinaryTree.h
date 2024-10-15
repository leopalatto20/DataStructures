#pragma once
#include "BinaryNode.h"
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
private:
	BinaryNode<T>* root;

	void recursiveDeleteTree(BinaryNode<T>*& node) {
		if(!node)
			return;
		recursiveDeleteTree(node->left);
		recursiveDeleteTree(node->right);
		delete node;
		node = nullptr;
	}

	bool recursiveInsert(BinaryNode<T>*& node, T info) {
		if(!node) {
			node = new(nothrow) BinaryNode<T>(info);
			if(!node)
				return false;
			return true;
		}
		if(info < node->info) {
			return recursiveInsert(node->left, info);
		}
		return recursiveInsert(node->right, info);
	}

	void recursiveDisplay(BinaryNode<T>* node) {
		if(!node)
			return;
		recursiveDisplay(node->left);
		cout << node->info << endl;
		recursiveDisplay(node->right);
	}

	T* recursiveSearch(BinaryNode<T>* node, T info) {
		if(!node)
			return nullptr;
		if(node->info == info) {
			return &node->info;
		}
		if(info < node->info)
			return recursiveSearch(node->left, info);
		return recursiveSearch(node->right, info);
	}

	T* recursiveSearchInOrder(BinaryNode<T>* node, int numToSearch, int& counter) {
		if(!node)
			return nullptr;
		T* result = recursiveSearchInOrder(node->left, numToSearch, counter);
		if(result)
			return result;

		if(counter == numToSearch)
			return &node->info;
		counter++;

		return recursiveSearchInOrder(node->right, numToSearch, counter);
	}

public:
	BinaryTree() : root(nullptr) {
	}

	~BinaryTree() {
		deleteTree();
	}

	void deleteTree() {
		recursiveDeleteTree(root);
		root = nullptr;
	}

	bool insert(T info) {
		return recursiveInsert(root, info);
	}

	void displayTree() {
		recursiveDisplay(root);
	}

	T* binarySearch(T info) {
		return(recursiveSearch(root, info));
	}

	T* searchInOrder(int numToSearch) {
		int counter(0);
		return(recursiveSearchInOrder(root, numToSearch, counter));
	}
};
