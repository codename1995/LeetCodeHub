class Solution {
public:
	int hammingWeight(uint32_t n) {
		// Efficient Solution (Recommend)
		int cnt = 0;
		while (n != 0)
		{
			cnt++;
			n = n & (n - 1);
		}
		return cnt;
	}
};