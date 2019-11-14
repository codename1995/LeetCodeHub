class Solution {
public:
	int integerBreak(int n) {
		// greedy based on proof
		if (n <= 3) return n - 1;
		int prod = 1;
		while (n >= 5) {
			prod *= 3;
			n -= 3;
		}
		prod *= n;
		//if (n==4) prod*=4;
		//else if (n==3) prod*=3;
		//else if (n==2) prod*=2;
		return prod;
	}
};