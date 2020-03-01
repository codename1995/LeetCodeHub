# Abstract
A summary for problems with different tag. Best viewed in VS Code with Markdown Perview Enhanced.

[TOC]

# Math
TBC
# Data Structure
## Tree
### BFS&DFS
#### Depth-First Search
Solution 1: DFS with queue / iterative DFS
Here give an example for LC437 Path Sum 
```C++ {.line-numbers}
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
	// int pathSum2(TreeNode* root, int sum) {
	// 	int cnt = 0;
	// 	if (root && root->val == sum) ++cnt;
	// 	if (root && root->left) {
	// 		cnt += pathSum2(root->left, sum - root->val);
	// 	}
	// 	if (root && root->right) {
	// 		cnt += pathSum2(root->right, sum - root->val);
	// 	}
	// 	return cnt;
	// }
	int pathSum(TreeNode* root, int sum) {
        //YOU CAN INITIAL SOMETHING HERE //
		//int cnt = 0;
		if (!root) return cnt;
		queue<TreeNode*> root_queue;
		root_queue.push(root);
		while (!root_queue.empty()) {
			TreeNode* r = root_queue.front();
			root_queue.pop();
			if (r->left) root_queue.push(r->left);
			if (r->right) root_queue.push(r->right);

            //YOU CAN DO SOMETHING HERE //
			//cnt += pathSum2(r, sum);
		}
		return cnt;
	}
};
```
### Binary Search Tree
#### Inorder
```C++ {.line-numbers}
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
```Python {.line-numbers}
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
### QUICK-SORT
#### Pseudo-code
```cpp
    int partition(vector<int> &nums, int l, int r, int pivot_ix){
        int pivot = nums[pivot_ix];
        swap(nums[r], nums[pivot_ix]);

        int pos = l;
        for (int i=l;i<=r;++i){
            if (nums[i]>pivot){
                swap(nums[i], nums[pos++]);
            }
        }

        swap(nums[pos], nums[r]);
        return pos;
    }
    void QUICK-SORT-CORE(vector<int> &array, int l, int r){
        if (l>=r) return; 

        int pivot_ix = randomRange(l,r); // 在[l,r]范围内随机产生一个数
        int pos = partition(nums, l, r, pivot_ix);
        QUICK-SORT-CORE(nums,l,pos-1);
        QUICK-SORT-CORE(nums,pos+1,r);
    }
    vector<int> QUICK-SORT(vector<int> &array){
        if (array.size()>1)
            QUICK-SORT-CORE(array, 0, array.size()-1);
        return array;
    }
```

#### Problem
E 169 [Majority Element](https://leetcode-cn.com/problems/majority-element/submissions/) It could be solved by quick-sort-like algorithm.
M 215 [Kth Largest Element in an array](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)
# Method
## DP

## Hash Table

### Alphabet Hash Table
Here is a typical application for "saving time by space".
Use a simple alphabet hash table so that we can check whether a character exist in string s
or the first/last position of the character in string s.
#### Template

```C++ {.line-numbers}
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

```C++ {.line-numbers}
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


