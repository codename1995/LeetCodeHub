#include<vector>
#include<queue>
#include<deque>
#include<cstring>
#include<iostream>

using namespace std;

// Solution 3: Multiset + 双指针
// T: O(logn) 在LC测试中，约180ms，（对比方法2约300ms）


// Solution 2: 维护两个堆
// T: O(5*logn) + O(1) = O(logn)
// 1. 一个最小堆，用于存放较大的数据；一个最大堆，用于存放较小的数据
// 2. 加入数据时 较小->较大--判断->较小 走一遍，即可维护两个堆，且使中位数位于较小或较小和较大的顶端
// 3.弹出时，若两个堆的元素个数一样，取平均；否则，取最大堆（较小）的顶
class MedianFinder {
	priority_queue<int, deque<int>, less<int> > lo; //最大优先队列，存较小数
	priority_queue<int, deque<int>, greater<int> > hi; // 最小优先队列，存较大数

public:
	void addNum(int num) {
		lo.push(num);                                    // Add to max heap

		hi.push(lo.top());                               // balancing step
		lo.pop();

		if (lo.size() < hi.size()) {                     // maintain size property
			lo.push(hi.top());
			hi.pop();
		}
	}

	double findMedian() {
		if (hi.size() == lo.size())
		{
			double a = hi.top(), b = lo.top();
			return (a + b) * 0.5;
		}
		else
			return double(lo.top());

	}
};

// Solution 1: 插入排序
// 需利用 vector 的函数insert()和lower_bound()
//作者：LeetCode
//链接：https ://leetcode-cn.com/problems/find-median-from-data-stream/solution/shu-ju-liu-de-zhong-wei-shu-by-leetcode/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class MedianFinder1 {
	vector<int> store; // resize-able container

public:
	// Adds a number into the data structure.
	void addNum(int num)
	{
		if (store.empty())
			store.push_back(num);
		else
			store.insert(lower_bound(store.begin(), store.end(), num), num);     // binary search and insertion combined
	}

	// Returns the median of current data stream
	double findMedian()
	{
		int n = store.size();
		return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
	}
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */