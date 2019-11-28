#include<vector>
#include<algorithm>
#include<queue>
#include<random>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	vector<int> nums;
	int partition(int l, int r, int pivot_ix) {
		int pivot = nums[pivot_ix];
		// 1. move piovt to end
		swap(nums[pivot_ix], nums[r]);

		// 2. move all smaller elements to the left
		int store_index = l;
		for (int i = l; i < r; i++)
		{
			if (nums[i] < pivot)		// 升序，改为  >  则是降序
			{
				swap(nums[i], nums[store_index]);
				store_index++;
			}
		}

		// 3. move pivot to its final place
		swap(nums[store_index], nums[r]);
		return store_index;
	}
	int select(int l, int r, int k_smallest)
	{
		// Returns the k-th largest element of list within left..right
		if (l == r) return nums[l];

		int pivot_ix = l + (r - l) / 2;

		pivot_ix = partition(l, r, pivot_ix);

		if (k_smallest == pivot_ix)
			return nums[k_smallest];
		else if (k_smallest < pivot_ix)
			return select(l, pivot_ix - 1, k_smallest);
		else
			return select(pivot_ix + 1, r, k_smallest);
	}
	int findKthLargest(vector<int>& arr, int k) {
		// Solution 3: One solution for big data
		// T: O(n*logk) S: O(k)
		// 逐一读取元素，维护一个大小为k的最小堆/最小优先队列
		//priority_queue<int, deque<int>, greater<int> > pq; //greater<int> 表示升序，最小优先出队
		//for (auto n : nums)
		//{
		//	if (pq.size() < k)
		//		pq.push(n);
		//	else if (n > pq.top())
		//	{
		//		pq.pop();
		//		pq.push(n);
		//	}
		//}
		//return pq.top();

		// Solution 2: Use function Partition()
		// T: O(n), but it is too difficulty to program all these codes. Besides, 
		// the 'nums' will be changed.
		// 用Partition函数来调整数组，直到右数第k个数确定
		// algorithm adapted from offical solution
		nums = arr;
		return select(0, nums.size() - 1, nums.size() - k);

		// Solution 1: library  XD
		// T: O(nlogn)
		//sort(nums.begin(), nums.end());
		//return nums[nums.size() - k];
	}
};

void main()
{
	vector<int> v{ 7,6,5,4,3,2,1 };
	int k = 2;

	Solution solu;
	int res = solu.findKthLargest(v, k);

	if (res != 6)
		cout << 'WA' << endl;
	
	int i;
}