#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int maxArcCnt;
	vector<int> dfs(TreeNode* root) {
		// return {nocrossMaxArch, corssMaxArch}
		if (!root) return vector<int>{0, 0};
		if (root && !root->left & !root->right) return vector<int>{1, 1};
		int maxDepth, corssMaxArch;

		vector<int> vl, vr;
		vl = dfs(root->left);
		vr = dfs(root->right);
		maxDepth = max(vl[0], vr[0]) + 1;
		corssMaxArch = vl[0] + vr[0];
		maxArcCnt = max(maxArcCnt, corssMaxArch);
		return vector<int>{maxDepth, corssMaxArch};

	}
	int diameterOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		maxArcCnt = 0;
		dfs(root);
		return maxArcCnt;
	}
};