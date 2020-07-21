// TreeOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include<string>
#include "Node.h"
#include <vector>
#include <sstream>
#include<iterator>
#include <algorithm>
#include <cmath>

using namespace std;

// This function was written using an example on this page: http://www.cplusplus.com/articles/2wA0RXSz/
// It works starting from C++11
vector<string> SplitStringToVector(const string& inputString, const char& delimiter)
{
	string stringBuffer{ "" };
	vector<string> result;

	for (auto n : inputString)
	{
		if (n != delimiter) stringBuffer += n; else
			if (n == delimiter && stringBuffer != "") { result.push_back(stringBuffer); stringBuffer = ""; }
	}
	if (stringBuffer != "") result.push_back(stringBuffer);

	return result;
}

/****                    SAMPLE IMAGE OUTPUT                       ****/
//								  1
//                              2   3
//                                4   7
//                                      7
//                                    7   7
void SimplePrintTree(vector<string> serializedTree, int treeDepth) {
	
	// Put the input vector to a 2 dimensional array
	cout << "SimplePrintTree:" << "\r\n\r\n";
	int printSpan = pow(2, treeDepth);
	int** consolePicture = new int * [serializedTree.size()];
	int offset = printSpan / 2;
	for (int i = 0; i < serializedTree.size(); i++) {
		consolePicture[i] = new int[printSpan];
		// Fill a row with NULL values
		for (int j = 0; j < printSpan; j++)
			consolePicture[i][j] = NULL;
		vector<string> splittedElement = SplitStringToVector(serializedTree[i], ',');
		int rows;
		istringstream(splittedElement[2]) >> rows;
		int cols;
		istringstream(splittedElement[1]) >> cols;
		int value;
		istringstream(splittedElement[3]) >> value;
		consolePicture[rows][(printSpan / 2) + cols] = value;
	}

	// Print the array
	for (int i = 0; i < serializedTree.size(); i++) {
		for (int j = 0; j < printSpan; j++) {
			if(consolePicture[i][j] != NULL)
				cout << consolePicture[i][j] << " ";
			else
				cout << "  ";
		}
		cout << "\r\n";
	}

	delete[] consolePicture;

}

void PrintTree(vector<string> serializedTree, int treeDepth) {

	// Put the input vector to a 2 dimensional array
	cout << "PrintTree:" << "\r\n\r\n";
	int printSpan = pow(2, treeDepth);
	string** consolePicture = new string* [treeDepth*2];
	for (int i = 0; i < treeDepth * 2; i++) {
		consolePicture[i] = new string[printSpan];
		for (int j = 0; j < printSpan; j++)
			consolePicture[i][j] = " ";
	}
		
	for (int i = 0; i < serializedTree.size(); i++) {
		
		// Fill a row with NULL values
		//for (int j = 0; j < printSpan; j++)
		//	consolePicture[i][j] = " ";
		vector<string> splittedElement = SplitStringToVector(serializedTree[i], ',');
		int rows;
		istringstream(splittedElement[2]) >> rows;
		int cols;
		istringstream(splittedElement[1]) >> cols;

		consolePicture[rows*2][(printSpan / 2) + cols] = splittedElement[3];
		if (rows > 0)
			if(splittedElement[0] == "r")
				consolePicture[rows * 2-1][(printSpan / 2) + cols] = "\\";
			else
				consolePicture[rows * 2-1][(printSpan / 2) + cols] = "/";
	}

	// Print the array
	for (int i = 0; i < treeDepth * 2; i++) {
		for (int j = 0; j < printSpan; j++) {
			cout << consolePicture[i][j];
		}
		cout << "\r\n";
	}

	//delete[] consolePicture;

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




void PlotTree(Node* nodeToPlot, int level, int treeDepth, list<string> img) {
	// Plan:
	// Tree serialization with an information, which node comes from which parent, which level
	// Reading from the string instructions how to plot the tree
	if (nodeToPlot != NULL) {
		int imgWidth = treeDepth ^ 2;
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

	string serializedTree = "l,";
	SerializeBinaryTree(&root, 0, 0, serializedTree);
	vector<string> splittedString = SplitStringToVector(serializedTree, ';');
	SimplePrintTree(splittedString, 5);
	PrintTree(splittedString, 5);

	std::cout << "Tree serialization: " << serializedTree << "\n";
	std::cout << "Nodes' sum: " << CountNodeValues(&root, 0) << "\n";
	std::cout << "Universal Value Trees: " << UniversalValueTree(&root, 0) << "\n";

}


