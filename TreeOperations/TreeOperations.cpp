#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "Visualization.h"
#include "Operations.h"

using namespace std;


int main()
{
	std::cout << "Init tree\n";
	// Build a binary tree
	Node A = Node(2);
	Node C = Node(4);
	Node F = Node(7);
	Node G = Node(-1);
	Node E = Node(7, &F, &G);
	Node D = Node(7, NULL, &E);
	Node B = Node(3, &C, &D);
	Node root = Node(1, &A, &B);

	

	PrintTreeFactory(root, 5);
	std::cout << "Nodes' sum: " << CountNodeValues(&root, 0) << "\n";
	std::cout << "Universal Value Trees: " << UniversalValueTree(&root, 0) << "\n";
	std::cout << "Print the sorted tree: \n\r";
	Node* sortedTree = SortBinaryTree(&root);
	PrintTreeFactory(*sortedTree, 9);

}


