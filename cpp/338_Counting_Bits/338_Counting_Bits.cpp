class Solution {
public:
	vector<int> countBits(int num) {
		if (num == 0) return vector<int>(1, 0);
		if (num == 1) return vector<int>{0, 1};
		vector<int> ans(num + 1, 0);
		ans[1] = 1;
		for (int i = 2; i != num + 1; i++) {
			if (i % 2 == 0)
				ans[i] = ans[i / 2];
			else
				ans[i] = ans[i - 1] + 1;
		}
		return ans;
	}
};