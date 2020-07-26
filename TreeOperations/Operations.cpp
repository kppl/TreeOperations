#include <iostream>
#include <sstream>
#include "Node.h"

using namespace std;

// This function goes over each binary tree node and extract all information to a string.
void SerializeBinaryTree(Node* nodeToPlot, int posHorizontal, int posVertical, string& serializedTree) {

	serializedTree += to_string(posHorizontal) + "," + to_string(posVertical) + "," + to_string(nodeToPlot->value) + ";";
	posVertical++;

	if (nodeToPlot->left) {
		serializedTree += "l,";
		SerializeBinaryTree(nodeToPlot->left, posHorizontal - 1, posVertical, serializedTree);
	}

	if (nodeToPlot->right) {
		serializedTree += "r,";
		SerializeBinaryTree(nodeToPlot->right, posHorizontal + 1, posVertical, serializedTree);
	}
}

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

Node* SortBinaryTree(Node* root) {
	return NULL;
}
