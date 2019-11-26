#include<queue>
#include<cstring>
#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		// 1. 递归（推荐）
		if (!root) return root;
		TreeNode* tmp;
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);

		return root;

		// 2. 循环，亦可
		//if (!root) return root;
		//queue<TreeNode*> q;
		//q.push(root);
		//while (!q.empty()) {
		//	TreeNode* r = q.front();
		//	q.pop();

		//	TreeNode* tmp = r->left;
		//	r->left = r->right;
		//	r->right = tmp;

		//	if (r->left) q.push(r->left);
		//	if (r->right) q.push(r->right);
		//}
		//return root;
	}
};