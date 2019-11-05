#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		// 题目中并没有说s一定有效
		// 因此要考虑到一些异常case，如"0", "01", "100","227","27"
		// （对应返回值分别为0，0，0，2，1）
		if (s[0] == '0') return 0;
		int prv2 = 0, prv1 = 1, cur = 1; // prv2, prv1表示dp[i-2]和dp[i-1]
		for (int i = 1; i <= s.size(); i++)
		{
			prv2 = prv1;
			prv1 = cur;
			if (s[i] == '0')
			{
				if (s[i - 1] == '1' || s[i - 1] == '2') cur = prv2;
				else return 0;
			}
			else
			{
				if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6') //11-19,21-26
					cur = prv2 + prv1;
				else cur = prv1; //1-9
			}
		}
		return cur;
	}
};