#include<string>
#include<cstring>
#include<iostream>
#include<sstream>
#include"TreeNode_LC.h"

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
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

class Codec {
public:
	// @Gremist
	// 写在讨论区里，没有单独的链接
	// 采用了C++ STL 的 stringstream ，通过std::in和std::out能够自动地根据空格切分输入输出流
	string serialize(TreeNode* root) {
		if (!root) return "#";
		return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
	}

	TreeNode* deserialize(string data) {
		istringstream in(data);
		return helper(in);
	}

	TreeNode* helper(istringstream& in) {
		string val;
		in >> val;
		if (val == "#") return nullptr;
		auto root = new TreeNode(stoi(val));
		root->left = helper(in);
		root->right = helper(in);
		return root;
	}
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

 // ============= Module Test ==============

bool sameTree(TreeNode* a, TreeNode* b)
{
	if (!a && !b) return true;
	if (!a || !b) return false;
	return (a->val == b->val) &&
		sameTree(a->left, b->left) &&
		sameTree(a->right, b->right);
}

void main()
{
	// ===== Test Case =====
	TreeNode* root = new TreeNode(1);
	//root->left = new TreeNode(2);
	//root->left->right = new TreeNode(35);
	//root->right = new TreeNode(3);
	//root->right->left = new TreeNode(4);
	//root->right->right = new TreeNode(5);

	TreeNode* p = new TreeNode(-1);
	root->right = p;
	//for (int i=0; i <= 1000; i++)
	for (int i = 1000; i >= 0; i--)
	{
		TreeNode* p2 = new TreeNode(i);
		p->right = p2;
		p = p2;
	}



	Codec codec;
	string s;
	s = codec.serialize(root);
	TreeNode* decodedTree = codec.deserialize(s);
	if (sameTree(root, decodedTree))
		cout << "Right" << endl;
	else
		cout << "Wrong" << endl;

}