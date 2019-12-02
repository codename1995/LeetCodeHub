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
	bool hasPathSum(TreeNode* root, int sum) {
		// recusive
		if (!root) return false;
		if (!root->left && !root->right && sum == root->val) return true;
		return (root->left && hasPathSum(root->left, sum - root->val))
			|| (root->right && hasPathSum(root->right, sum - root->val));
	}
};