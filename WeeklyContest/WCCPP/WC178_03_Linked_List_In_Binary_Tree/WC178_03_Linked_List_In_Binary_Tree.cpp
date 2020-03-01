#include<vector>
#include<string>
#include<queue>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	bool check(TreeNode* root, vector<int>& v, int idx1) {
		if (idx1 == v.size()) return true;
		if (!root || root->val != v[idx1]) return false;
		if (check(root->left, v, idx1 + 1) || check(root->right, v, idx1 + 1)) {
			return true;
		}
		return false;
	}
	bool isSubPath(ListNode* head, TreeNode* root) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		queue<TreeNode*> root_queue;
		root_queue.push(root);
		while (!root_queue.empty()) {
			TreeNode* r = root_queue.front();
			if (check(r, v, 0)) return true;
			root_queue.pop();
			if (r->left) root_queue.push(r->left);
			if (r->right) root_queue.push(r->right);
		}
		return false;
	}
};