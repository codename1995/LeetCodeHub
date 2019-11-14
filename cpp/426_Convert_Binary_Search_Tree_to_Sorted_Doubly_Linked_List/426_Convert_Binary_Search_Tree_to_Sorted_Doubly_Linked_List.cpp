#include<iostream>
#include<cstring>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
*/
class Solution {
public:
	// 折腾了半天，自己代码巨长，官方题解不到15行
	Node* first = NULL;
	Node* last = NULL;

	void helper(Node* node) {
		if (node) {
			//left
			helper(node->left);
			//node
			if (last) {
				// link the previous node (last)
				// with the current one (node)
				last->right = node;
				node->left = last;
			}
			else {
				// keep the smallest node
				// to close DLL later on
				first = node;
			}
			last = node;
			//right
			helper(node->right);
		}
	}
	Node* treeToDoublyList(Node* root) {
		if (!root) return NULL;
		helper(root);
		// close DLL
		last->right = first;
		first->left = last;
		return first;
	}
};