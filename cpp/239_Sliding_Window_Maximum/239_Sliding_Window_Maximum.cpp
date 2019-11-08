#include<vector>
#include<iostream>
#include<deque>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// Use a deque to store the max element for sliding windows, specifically
		// 1. Visit element in "nums" one by one, and add them in to deque's back
		// 2. 
		// ... emm, hard to instruct. Let's draw a picture
		// nums:	3	2	4	2	3	6	// input array
		// deque:	3	2				// snapshoot 1: just visited "3"
		// deque:	3	2	4			// snapshoot 2: max length of deque is equal to "k"
		// deque:	4					// snapshoot 3: Amazing! A largest num "4" push out all number in front of it
		// deque:	4	2				// snapshoot 4: 2 is not strong enough to push out "4", but when 4 has to leave, "2" might be the largest one
		// deque:	4	3				// snapshoot 5: where is "2" ?? a new element will compare with deque.back() to ensure deque in descending order
		// deque:	6					// snapshoot 6: push out again.
		// Well, an issue was ignored to make the instruction easy-to-understand, i.e. how could we know an element shoube be removed because it out of windows?
		// The answer is that deque is not only a deque, but also a hash table. We store index in it instead of value.
		// 
		// PS: I didn't use dp. I just upload my code twice, and defeat 43% -> 88%. It may caused by too fewer case (just 18).

		vector<int> res;
		if (nums.size() == 0) return res;
		deque<int> dq;
		for (int i = 0; i < nums.size(); ++i)
		{
			while (!dq.empty() && nums[i] > nums[dq.back()])
				dq.pop_back();
			dq.push_back(i);
			while (nums[i] > nums[dq.front()] || (i - dq.front() + 1) > k)
				dq.pop_front();
			if (i >= k - 1) res.push_back(nums[dq.front()]);
		}
		return res;
	}
};

void main()
{
	Solution solu;
	vector<int> case1{ 1,3,1,2,0,5 };
	vector<int> EA{ 3,3,2,5 };
	cout << (solu.maxSlidingWindow(case1, 3) == EA) << endl;

}