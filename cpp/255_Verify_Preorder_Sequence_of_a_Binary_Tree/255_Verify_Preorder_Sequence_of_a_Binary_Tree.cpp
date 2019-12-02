#include<cstring>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	bool isValid(vector<int> v, int l, int r)
	{
		// LC解法2：T:O(n), S:O(1) 解法1基础上进一步缩小空间复杂度，直接在队列上模拟栈操作
		// 参考：https://blog.csdn.net/qq508618087/article/details/50929129
		//int pos = -1, minn = INT_MIN;
		//for (int i = 0; i <= v.size() - 1; i++)
		//{
		//	if (v[i] < minn) return false;
		//	while (pos >= 0 && v[i] > v[pos])
		//	{
		//		minn = v[pos--];
		//	}
		//	v[++pos] = v[i];
		//}
		//return true;

		// LC解法1：T:O(n), S:O(n) 利用栈
		// 若队列的值逐渐减小，则一直在沿左子树向下，将值入栈
		// 一旦队列的值变大，说明遇到了右子树，此时需不断出栈，直到找到其根结点
		// 根节点的判断依据是，若v[i]为右子树结点，v[k]为根，则v[k]<v[i]且v[k-1]>v[i]
		// 将v[k]的值存于变量m
		// 若v[i]之后有值小于m，则该前序序列不合格
		int m = INT_MIN;
		stack<int> s;
		for (int i = 0; i <= v.size() - 1; i++)
		{
			if (v[i] < m) return false;
			while (!s.empty() && v[i] > s.top())
			{
				m = s.top();
				s.pop();	// 不停出栈，直到v[k]<v[i]且v[k-1]>v[i]，令m=v[k]
			}
			s.push(v[i]); // 将右子树顶点作为根 入栈
		}
		return true;



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