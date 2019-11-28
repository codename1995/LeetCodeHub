#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		// 1~9  1 * 9			1区间，区间内每个number有1个digit，共有9个number
		// 10~99  2 * 90		2区间
		// 100~999  3 * 900		3区间
		// ...					k区间，区间内每个number有k个digit，共有9*(10^k-1)个number
		// 因此，第一步，通过逐步相减(即while循环)，得到区间号k的值
		// 第二步，在该区间内，确定n对应的那个整数

		// 优化后代码
		int k = 1;
		while (n > k * 9 * pow(10, k - 1))
		{
			n -= k * 9 * pow(10, k - 1);
			k++;
		}
		// 退出循环时，n表示在当前区间内的第n个digit。
		// k表示当前是k区间，此时，每个number有k个digit。
		// 因此，0~k-1 digit对应第一个number，以此类推。
		// 所以，可以用 (n-1)/k 表示此时应该用该区间的第几个number，
		// 并且，该number的实际值为 (n - 1) / k + pow(10, k - 1)
		int the_integer = (n - 1) / k + pow(10, k - 1);
		string s = to_string(the_integer);
		if (n % k == 0) return s.back() - '0';
		return s[n % k - 1] - '0';
	}
};

void main()
{
	Solution solu;
	solu.findNthDigit(101);
}