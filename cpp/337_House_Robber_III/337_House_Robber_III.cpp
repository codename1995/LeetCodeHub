#include<cstring>
#include<iostream>
#include<vector>
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
	vector<int> dp(TreeNode* curr) {
		// 返回两个值，第一个值表示不选这个节点，第二个值表示选择这个节点
		if (!curr) return { 0, 0 };

		vector<int> l = dp(curr->left);
		vector<int> r = dp(curr->right);

		return { max(l[0], l[1]) + max(r[0], r[1]), curr->val + l[0] + r[0] };
	}
	int rob(TreeNode* root) {
		// 帮助理解树状DP：https://leetcode-cn.com/problems/house-robber-iii/solution/jian-dan-gao-xiao-de-shu-zhuang-dpzi-di-xiang-shan/
		// 更简洁的Python代码：https://leetcode-cn.com/problems/house-robber-iii/solution/shu-xing-dp-by-enda-2/
		vector<int> res = dp(root);
		return max(res[0], res[1]);
	}
};
