#include<cstring>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	bool isValid(vector<int> v, int l, int r)
	{
		// LC解法2：T:O(n), S:O(1) 解法1基础上进一步缩小空间复杂度，直接在队列上操作
		// 参考：https://blog.csdn.net/qq508618087/article/details/50929129
		int k = -1, m = INT_MIN;
		for (int i = 0; i <= v.size() - 1; i++)
		{
			if (v[i] < m) return false;
			while (k >= 0 && v[i] > v[k])
			{
				m = v[k--];
			}
			v[++k] = v[i];
		}
		return true;

		// LC解法1：T:O(n), S:O(n) 利用栈模拟
		//int m = INT_MIN;
		//stack<int> s;
		//for (int i = 0; i <= v.size() - 1; i++)
		//{
		//	if (v[i] < m) return false;
		//	while (!s.empty() && v[i] > s.top())
		//	{
		//		m = s.top();
		//		s.pop();
		//	}
		//	s.push(v[i]);
		//}
		//return true;



		// 以下是剑指offer的思路，虽然合理，但LC上超时了。LC上给了一个很长的单路子树，使得前两个循环的时间复杂度暴涨。
		// 1.首元素显然是根节点
		// 2.以此为锚，遍历之后的元素，在第一个大于根节点的元素之前的是左子树，之后（含）则是右子树
		// 3.继续遍历，若存在小于根节点的则直接返回false，（右子树必小于根节点）
		// 4.递归左右子树
		//if (l >= r) return true;

		//int root = v[l];
		//int i = l + 1;
		//for (; i <= r; i++)
		//{
		//	if (v[i] > root) break;
		//}

		//// root left subtree is invalid
		//if (!isValid(v, l + 1, i - 1)) return false;

		//// root right subtree is invalid
		//for (int j = i; j <= r; j++)
		//{
		//	if (v[j] < root) return false;
		//}
		//if (!isValid(v, i, r)) return false;
		//	
		//return true;

	}
	bool verifyPreorder(vector<int>& preorder) {
		if (preorder.size() == 0) return true;
		return isValid(preorder, 0, preorder.size() - 1);

	}
};