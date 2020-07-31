#pragma once
#include "Node.h"

void SerializeBinaryTree(Node*, int, int, std::string&);
int CountNodeValues(Node*, int);
int UniversalValueTree(Node*, int);
Node* SortBinaryTree(Node*);
int CountTreeDepth(Node* node, int depth = 0);