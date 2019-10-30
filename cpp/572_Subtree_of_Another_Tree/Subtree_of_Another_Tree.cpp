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
	bool sameTree(TreeNode* a, TreeNode* b)
	{
		if (!a && !b) return true;
		if ((!a && b) || (a && !b)) return false; // a ^ b, if == 1, return false
		if (a->val != b->val) return false;
		return sameTree(a->left, b->left) && sameTree(a->right, b->right);
		// 以下是参考@Marvin 的题解进行简化
		// 实际尝试中发现简化后代码确实更清晰易懂，但是执行时间始终更长，不明白为什么
		//if (!a && !b) return true;
		//if (!a or !b) return false;
		//return (a->val == b->val) && sameTree(a->left, b->left) && sameTree(a->right, b->right);
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s) return false;
		return (sameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
	}
};