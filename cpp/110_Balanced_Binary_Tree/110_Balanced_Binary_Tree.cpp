#include<cstring>
#include<iostream>
#include<algorithm>


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
	int helper(TreeNode* root) {
		// if root is balanced, return depth of root
		// otherwise, return -1
		if (!root) return 0;
		int l_depth = helper(root->left);
		int r_depth = helper(root->right);
		if (l_depth != -1 && r_depth != -1 && abs(l_depth - r_depth) <= 1) return 1 + max(l_depth, r_depth);
		return -1;
	}
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
	bool isBalanced(TreeNode* root) {
		// Solution 2: Bottom-up
		return helper(root) != -1;



		// Solution 1: Recusively
		//if (!root) return true;
		//return (abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 &&
		//	isBalanced(root->left) &&
		//	isBalanced(root->right));
	}
};