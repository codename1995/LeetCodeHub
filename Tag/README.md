# Abstract
A summary for problems with different tag. Best viewed in VS Code with Markdown Perview Enhanced.

[TOC]

# Math
TBC
# Data Structure
## Tree
### Binary Search Tree
#### Inorder
```C++
// Print the INORDER of a BST in a vector

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> inorder(TreeNode* root){
    vector<int> nums;

    if (!root) return nums;

    stack<TreeNode*> s;
    while (!s.epmty() || root!=nullptr)
    {
        if (root!=nullptr)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            TreeNode* top = s.top();
            s.pop();
            nums.push_back(top->val);
            root=top->right;
        }
    }
    return nums;
}

```
# Sort
## Classical Sort Algorithms
### MERGE-SORT
#### Pseudo-code
```Python
# Adapted from "Introduction to Algorithms"
def Merge_Sort(A, l, r):
    if (l<r):
        m = (l+r)//2
        Merge_Sort(A,l,m)
        Merge_Sort(A,m+1,r)
        Merge(A, l, m, r)
def Merge(A, l, m, r):
    # Procedure:
    # 1. Copy the left and right part of array A to two new array
    # 2. Merge two array to A one by one.
    L = A[l..m]
    L.append(float("INF"))
    R = A[m+1..r]
    R.append(float("INF"))
    i = j = 1
    for k = l to r:
        if L[i] <= R[j]:
            A[k] = L[i++]
        else
            A[k] = R[j++]
```
#### Problems
H 493 [Reverse Pairs](https://leetcode-cn.com/problems/reverse-pairs/)
# Method
## DP

## Hash Table

### Alphabet Hash Table
Here is a typical application for "saving time by space".
Use a simple alphabet hash table so that we can check whether a character exist in string s
or the first/last position of the character in string s.
#### Template

```C++
/* Alphabet Hash Table Template
 *@method 
 *@for 
 *@param
    string s;                // The string
 *@return 
    none
*/

int cnt[26] = {0}; // Initialize the INT array in C++ is very important. Otherwise, the value will be unknown.
// if not only a character but maybe a symbol like '#', '$' , ...
// we can use cnt[256] to cover ASCII
for (auto c : s){
    cnt[c - 'a']++;
}
for (int i=0;i!=s.size();i++){
    if (cnt[s[i] - 'a'])
        balabala...
}
```

#### Problems
387 [First Unique Character in A String](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)  
1218 [Longest Arithemetic Subsequence of Given Difference ](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/) (A Special Hast Table) 

## Sliding windows
#### Template

```C++
/* Sliding Windows Template
 *@method 
 *@for 
 *@param
    string s;                // The string
 *@return 
    int max_length;          // max substring length
*/

int l = 0, r = 0;
for (;r<s.size();r++){
    if (condition1)         // extand substring
        r++
    else if (condition2)    // shorten substring
        l++
}
```
#### Problems
3 [Longest Substring without Repeating Characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)  
340 [Longest Substring with At Most two Distinct Characters](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/) 


