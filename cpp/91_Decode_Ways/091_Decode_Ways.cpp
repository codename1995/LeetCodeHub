#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		// 本题最关键的是理清s[i]与s[i-1]构成的几种关系应该如何操作
		// 这一步骤看了代码之后会非常清楚，难的是如何思考出来

		// 暂时没想到很好的推理方法。总之，按这种方法走
		// s[i] == 0 ?
		// Y------------- s[i-1] == {1,2} 则 dp[i]=dp[i-2]，否则直接返回0
		// N------------- s[i-1]s[i]是否在11与26之间（除了20）
		//				  Y--------- dp[i] = dp[i-1]+ dp[i-2]
		//				  N--------- dp[i] = dp[i-1]

		if (s[0] == '0') return 0;
		int prv2 = 1, prv1 = 1, cur; // prv2, prv1表示dp[i-2]和dp[i-1]
		for (int i = 1; i < s.size(); i++) // string结尾有结束符；size算到结束符前一位
		{
			if (s[i] == '0') // 10,20
			{
				if (s[i - 1] == '1' || s[i - 1] == '2') cur = prv2;
				else return 0;
			}
			else
			{
				if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6') // 11-19,21-26
					cur = prv2 + prv1;
				else cur = prv1; // 1-9
			}
			prv2 = prv1;
			prv1 = cur;
		}
		return cur;
	}
};


void main()
{
	Solution solu;

	string case1{ "112" };
	cout << case1[3] << endl;
	cout << (solu.numDecodings(case1) == 3) << endl;
}