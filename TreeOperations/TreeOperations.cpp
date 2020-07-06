// TreeOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include<string>
#include "Node.h"

using namespace std;


int CountNodeValues(Node* startNode, int initValue)
{
	int result = initValue + startNode->value;

	if (startNode->left)
		result = CountNodeValues(startNode->left, result);
	if (startNode->right)
		result = CountNodeValues(startNode->right, result);

	return result;
}

int UniversalValueTree(Node* startNode, int initValue) {
	int result = initValue;

	// check children
	if (startNode->left == NULL && startNode->right == NULL) {
		result++;
		startNode->IsUnival = true;
	} else if ((startNode->left != NULL && startNode->right != NULL) && (startNode->left->value == startNode->right->value) && startNode->right->value == startNode->value) {
		result++;
		startNode->IsUnival = true;
	} else if ((startNode->left != NULL && startNode->right == NULL) && (startNode->left->value == startNode->value)) {
		result++;
		startNode->IsUnival = true;
	} else if ((startNode->right != NULL && startNode->left == NULL) && (startNode->right->value == startNode->value)) {
		result++;
		startNode->IsUnival = true;
	}
	
	if (startNode->left) {
		// check subtrees
		if (startNode->left->IsUnival)
			result++;
		// go deeper
		result = UniversalValueTree(startNode->left, result);
	}		
	if (startNode->right) {
		// check subtrees
		if (startNode->right->IsUnival)
			result++;
		// go deeper
		result = UniversalValueTree(startNode->right, result);
	}
		

	return result;
}

void SerializeBinaryTree(Node* nodeToPlot, int level, string& serializedTree) {

	serializedTree += to_string(nodeToPlot->value);
	level++;

	if (nodeToPlot->left) {
		for(int i=0; i<=level; i++)
			serializedTree += "l";
		SerializeBinaryTree(nodeToPlot->left, level, serializedTree);
	}
	else {
		for (int i = 0; i <= level; i++)
			serializedTree += "l";
		serializedTree += "_";
	}
	
	if (nodeToPlot->right) {
		for (int i = 0; i <= level; i++)
			serializedTree += "r";
		SerializeBinaryTree(nodeToPlot->right, level, serializedTree);
	}
	else {
		for (int i = 0; i <= level; i++)
			serializedTree += "r";
		serializedTree += "_";
	}

	cout << serializedTree << "\r\n";
}

void PlotTree(Node* nodeToPlot, int level, int treeDepth, list<string> img) {
	// Plan:
	// Tree serialization with an information, which node comes from which parent, which level
	// Reading from the string instructions how to plot the tree
	if (nodeToPlot != NULL) {
		int imgWidth = treeDepth^2;
		for (int i = 0; i < imgWidth / 2; i++) {

		}
	}
		
}

int main()
{
	std::cout << "Init tree\n";
	// Build a binary tree
	Node A = Node(2);
	Node C = Node(4);
	Node F = Node(7);
	Node G = Node(7);
	Node E = Node(7, &F, &G);
	Node D = Node(7, NULL, &E);
	Node B = Node(3, &C, &D);
	Node root = Node(1, &A, &B);

	string serializedTree;
	SerializeBinaryTree(&root, 0, serializedTree);
	std::cout << "Tree serialization: " << serializedTree << "\n";
	std::cout << "Nodes' sum: " << CountNodeValues(&root, 0) << "\n";
	std::cout << "Universal Value Trees: " << UniversalValueTree(&root, 0) << "\n";

}


