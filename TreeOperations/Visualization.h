#pragma once
#include <vector>;

std::vector<std::string> SplitStringToVector(const std::string&, const char& delimiter);
void SimplePrintTree(std::vector<std::string>, int);
void PrintTree(std::vector<std::string>, int);
void PrintTreeFactory(Node& root, int treeDepth, int mode = 0);