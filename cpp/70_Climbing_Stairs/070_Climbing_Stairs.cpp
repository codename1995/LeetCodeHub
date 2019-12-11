



class Solution {
public:
	int climbStairs(int n) {
		int cur = 1, prv = 1, prvv = 1;
		for (int i = 2; i <= n; ++i) {
			cur = prv + prvv;
			prvv = prv;
			prv = cur;
		}
		return cur;
	}
};