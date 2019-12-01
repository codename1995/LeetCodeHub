
class Solution {
public:
	int hammingDistance(int x, int y) {
		int flag = 1 << 30;
		int cnt = 0;
		x ^= y;
		while (flag >= 1) {
			cnt += flag & x ? 1 : 0;
			flag = flag >> 1;
		}
		return cnt;
	}
};