#include <iostream>
#include <list>
#include<string>
#include "Node.h"
#include "Operations.h"
#include <vector>
#include <sstream>
#include<iterator>
#include <algorithm>
#include <cmath>
#include "Operations.h"

using namespace std;




// The function SplitStringToVector was written using an example on the following page: http://www.cplusplus.com/articles/2wA0RXSz/
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
	int** consolePicture = new int* [serializedTree.size()];
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
			if (consolePicture[i][j] != NULL)
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
	string** consolePicture = new string * [treeDepth * 2];
	for (int i = 0; i < treeDepth * 2; i++) {
		consolePicture[i] = new string[printSpan];
		for (int j = 0; j < printSpan; j++)
			consolePicture[i][j] = " ";
	}

	for (int i = 0; i < serializedTree.size(); i++) {
		vector<string> splittedElement = SplitStringToVector(serializedTree[i], ',');
		int rows;
		istringstream(splittedElement[2]) >> rows;
		int cols;
		istringstream(splittedElement[1]) >> cols;

		consolePicture[rows * 2][(printSpan / 2) + cols] = splittedElement[3];
		if (rows > 0)
			if (splittedElement[0] == "r")
				consolePicture[rows * 2 - 1][(printSpan / 2) + cols] = "\\";
			else
				consolePicture[rows * 2 - 1][(printSpan / 2) + cols] = "/";
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

void PrintTreeFactory(Node& root, int mode = 0) {
	int treeDepth = CountTreeDepth(&root);
	string serializedTree = "l,";
	SerializeBinaryTree(&root, 0, 0, serializedTree);
	vector<string> splittedString = SplitStringToVector(serializedTree, ';');
	switch (mode) {
	case 0:
		PrintTree(splittedString, treeDepth);
		break;
	case 1:
		SimplePrintTree(splittedString, treeDepth);
	}

}

