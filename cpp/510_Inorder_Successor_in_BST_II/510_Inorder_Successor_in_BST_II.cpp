/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // 按照穷举好的逻辑,写清楚即可
        if (node->right){
            node = node->right;
            while (node->left) node = node->left;
        }
        else{
            while (node->parent && (node->parent->right == node)) node=node->parent;
            node = node->parent;
        }
        return node;
    }
};