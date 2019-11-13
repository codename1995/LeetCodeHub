#include<cstring>
#include<iostream>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		// Efficient Solution (Recommend)
		int cnt = 0;
		while (n != 0)
		{
			cnt++;
			n = n & (n - 1); // 这一步将n的二进制表示的所有1中最低的那个翻转成0，其他所有位不变
			// ..010100
			// ..010011
			// &______
			// ..010000
		}
		return cnt;
		// Brute-force
		/*
		int cnt = 0;
		while (n != 0)
		{
			cnt += n & 1;
			n = n >> 1;
		}
		return cnt;
		*/
	}
};