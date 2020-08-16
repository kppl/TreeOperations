#pragma once

class Node
{
	public: 
		int value;
		Node* left, *right;
		bool IsUnival = false;

		Node() {
			value = -9999;
			left = nullptr;
			right = nullptr;
		}

		Node(int val) {
			value = val;
		}

		Node(int val, Node* l, Node* r) {
			value = val;
			left = l;
			right = r;
		}

};

