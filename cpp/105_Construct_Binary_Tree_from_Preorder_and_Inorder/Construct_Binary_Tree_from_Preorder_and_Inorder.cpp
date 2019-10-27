#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
//#include "..\Utilities\BianryTree.h"
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
class Solution {
public:
    vector<int> _preorder;
    vector<int> _inorder;
    TreeNode* buildTreeHelper(int pl, int pr, int inl, int inr){
        if (inl<=inr && pl<=pr){
            int root_val = _preorder[pl];
            int k = inl; //存放根节点在中序序列中的位置
            for (int i=inl;i!=inr+2;i++){ // 寻找root_val在inorder中的位置
               if (_inorder[i] == root_val) {
                   k = i;
                   break;
                   }
            }
            TreeNode* root = new TreeNode(root_val);
            //int left_sub_len = k-inl;//左子树结点数
            root->left = buildTreeHelper(pl+1,  pl+k-inl, inl, k-1);
            root->right = buildTreeHelper(pl+k-inl+1, pr, k+1,inr);
            return root;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty()){
            return NULL;
        }
        _preorder = preorder;
        _inorder = inorder;
        return buildTreeHelper(0, preorder.size()-1, 0, inorder.size()-1);
    }
};