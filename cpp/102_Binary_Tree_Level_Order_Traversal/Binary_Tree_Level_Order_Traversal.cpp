#include<vector>
#include<iostream>
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
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}
		queue<TreeNode*> Q;
		TreeNode* p;
		Q.push(root);
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
			ans.push_back(nums);
		}
		return ans;
	}
};
