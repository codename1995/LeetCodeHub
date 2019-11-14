class Solution {
public:
	int fib(int N) {
		vector<int> F{ 0,1 };
		for (int i = 2; i < N + 1; i++) {
			F.push_back(F[i - 1] + F[i - 2]);
		}
		return F[N];
	}
};