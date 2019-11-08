#include<vector>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
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
	int kthSmallest(TreeNode* root, int k) {
		// inorder vist the BST and break when find k-th node
		stack<TreeNode*> s;
		int cnt = 0;
		while (!s.empty() || root!=nullptr)
		{
			if (root != nullptr)
			{
				s.push(root);
				root = root->left;
			}
			else
			{
				TreeNode* top = s.top();
				s.pop();
				if (++cnt == k) return top->val;
				root = top->right;
			}
		}
		return 0; // Since the description say that k is valid, this "return" will no be executed.

	}
	// Copy iteratively inorder here
	vector<int> inorder(TreeNode* root)
	{
		vector<int> nums;
		if (!root) return nums;

		stack<TreeNode*> s;

		while (!s.empty() || root != nullptr)
		{
			if (root != nullptr)
			{
				s.push(root);
				root = root->left;
			}
			else
			{
				TreeNode* top = s.top();
				s.pop();
				nums.push_back(top->val);
				s.push(top->right);
			}
		}
		return nums;
	}
};