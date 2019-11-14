#include<vector>
#include<iostream>
#include<cstring>
#include<queue>

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		// 仅仅在102的基础上微调，添加了 一个标志位 l2r
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}
		queue<TreeNode*> Q;
		TreeNode* p;
		Q.push(root);
		bool l2r = true; // flag_left_to_right
		while (!Q.empty()) {
			int n = Q.size();
			vector<int> nums;
			for (int i = 0; i != n; i++) {
				p = Q.front();
				nums.push_back(p->val);
				Q.pop();
				if (p->left) Q.push(p->left);
				if (p->right) Q.push(p->right);
			}
			if (!l2r)
				reverse(nums.begin(), nums.end());
			ans.push_back(nums);
			l2r = !l2r;
		}
		return ans;
	}
};