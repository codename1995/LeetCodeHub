#include<vector>
#include<queue>

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
	int pathSum2(TreeNode* root, int sum) {
		int cnt = 0;
		if (root && root->val == sum) ++cnt;
		if (root && root->left) {
			cnt += pathSum2(root->left, sum - root->val);
		}
		if (root && root->right) {
			cnt += pathSum2(root->right, sum - root->val);
		}
		return cnt;
	}
	int pathSum(TreeNode* root, int sum) {
		int cnt = 0;
		if (!root) return cnt;
		queue<TreeNode*> root_queue;
		root_queue.push(root);
		while (!root_queue.empty()) {
			TreeNode* r = root_queue.front();
			root_queue.pop();
			if (r->left) root_queue.push(r->left);
			if (r->right) root_queue.push(r->right);

			cnt += pathSum2(r, sum);
		}
		return cnt;
	}
};
