#include<string>
#include<cstring>
#include<iostream>
#include<sstream>

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
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

class Codec {
public:
	// @Gremist
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