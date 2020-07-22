#include <iostream>
#include <list>
#include<string>
#include "Node.h"
#include "Visualization.h"
#include <vector>
#include <sstream>
#include<iterator>
#include <algorithm>
#include <cmath>

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
	}
	else if ((startNode->left != NULL && startNode->right != NULL) && (startNode->left->value == startNode->right->value) && startNode->right->value == startNode->value) {
		result++;
		startNode->IsUnival = true;
	}
	else if ((startNode->left != NULL && startNode->right == NULL) && (startNode->left->value == startNode->value)) {
		result++;
		startNode->IsUnival = true;
	}
	else if ((startNode->right != NULL && startNode->left == NULL) && (startNode->right->value == startNode->value)) {
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

	string serializedTree = "l,";
	SerializeBinaryTree(&root, 0, 0, serializedTree);
	vector<string> splittedString = SplitStringToVector(serializedTree, ';');
	SimplePrintTree(splittedString, 5);
	PrintTree(splittedString, 5);

	std::cout << "Tree serialization: " << serializedTree << "\n";
	std::cout << "Nodes' sum: " << CountNodeValues(&root, 0) << "\n";
	std::cout << "Universal Value Trees: " << UniversalValueTree(&root, 0) << "\n";

}


