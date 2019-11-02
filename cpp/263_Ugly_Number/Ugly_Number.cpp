
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) return false;
		while (num > 0)
		{
			int t = num;
			if (num % 2 == 0) num = num / 2;
			if (num % 3 == 0) num = num / 3;
			if (num % 5 == 0) num = num / 5;
			if (num == 1) return true;
			if (num == t) return false;
		}
		return false;
	}
};