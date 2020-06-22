#pragma once

class Node
{
	public: 
		int value;
		Node* left, *right;
		bool IsUnival = false;

		Node(int val) {
			value = val;
		}

		Node(int val, Node* l, Node* r) {
			value = val;
			left = l;
			right = r;
		}
};

