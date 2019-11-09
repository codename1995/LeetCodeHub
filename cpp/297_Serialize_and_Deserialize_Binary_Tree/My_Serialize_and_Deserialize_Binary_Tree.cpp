#include<string>
#include<cstring>
#include<iostream>
#include<queue>
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
class Codec2 {
public:
	// 第47个case没通过。要注意不能用string类型的一个位来表示值，因为值是int型，可能超过一个字符的范围。
	// Case 48是一个仅有右子树的有1000个节点的case，很容易超内存
	// Case 48实在通不过，存了一个思路更加简单的代码

	void printString(string s)
	{
		for (int i = 0; i <= s.size() - 1; i++) {
			cout << s[i];
		}
		cout << endl;
	}
	//string int2str(int n)
	//{
	//	string s;
	//	while (n >= 0)
	//	{
	//		s.push_back(n % 200 + '$' + 1); // ASCII: #-35,$-36
	//		n = n/200;
	//	}
	//	return s;
	//}
	//int str2int(string s)
	//{
	//	int n = 0;
	//	for (int i = s.size()-1; i>-1; i--)
	//	{
	//		n = n * 200 + s[i] - '$' - 1;
	//	}
	//	return n;
	//}
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string s;
		s = serialize(root, s);
		return s;
	}
	string serialize(TreeNode* root, string s) {
		if (!root)
		{
			s.push_back('#');
			s.push_back(',');
			return s;
		}
		else
		{
			
			s += to_string(root->val); 
			s.push_back(',');
			s = serialize(root->left, s);
			s = serialize(root->right, s);
		}
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* helper(int* i, string* _data)
	{
		int j = *i;
		while (j <= (*_data).size() - 1 && (*_data)[j] != ',')
			++j;

		if (*i > (*_data).size() - 1 || ((j-*i) == 1 && (*_data)[*i] == '#'))
		{
			*i = ++j;
			//delete *root;
			return NULL;
		}
		TreeNode* root = new TreeNode(stoi((*_data).substr(*i, j - *i)));
		*i = ++j;

		root->left = helper(i, _data);
		root->right = helper(i, _data);

		return root;
	}
	TreeNode* deserialize(string data) {
		if (data.size() == 0 || data[0] == '#') return NULL;


		TreeNode* root = new TreeNode(-1);
		int i = 0;
		root = helper(&i, &data);

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

 // ============= Module Test ==============

bool sameTree2(TreeNode* a, TreeNode* b)
{
	if (!a && !b) return true;
	if (!a || !b) return false;
	return (a->val == b->val) &&
		sameTree2(a->left, b->left) &&
		sameTree2(a->right, b->right);
}

void main_2()
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
	for(int i=1000;i>=0;i--)
	{
		TreeNode* p2 = new TreeNode(i);
		p->right = p2;
		p = p2;
	}



	Codec2 codec;
	string s;
	s = codec.serialize(root);
	codec.printString(s);
	TreeNode* decodedTree = codec.deserialize(s);
	if (sameTree2(root, decodedTree))
		cout << "Right" << endl;
	else
		cout << "Wrong" << endl;

}