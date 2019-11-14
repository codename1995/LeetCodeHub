#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	// 本题的本质是要设计一个排序规则：对于两个数m,n，要比较m@n和n@m哪个大，其中@表示连接。
	
	// 解决思路是将m@n与n@m转换成字符串，然后直接用strcmp来比较。
	// 面试时，可能还需要证明这一作用于两个数的方法对于数组nums也有效。
	// 证明的思路：1. 自反性；2. 对称性；3. 传递性

	// Tips: 这题Python代码只有三行，非常简单
	// C++实现的难点在于sort()函数怎么用
	// 需要用一个名字是啥我都不知道的方法  [](typename a, typename b) { return xxx; } );

	// @isaac7
	// https://leetcode.com/problems/largest-number/discuss/53157/A-simple-C%2B%2B-solution
	string largestNumber(vector<int>& nums) {
		vector<string> arr;
		for (auto i : nums)
			arr.push_back(to_string(i));
		sort(arr.begin(), arr.end(), [](string& s1, string& s2) {return s1 + s2 > s2 + s1; });
		string res;
		for (auto s : arr)
			res += s; // 对于字符串的append操作 s += x 比 s = s + x 快得多
		while (res[0] == '0' && res.length() > 1)
			res.erase(0, 1); // 应付 Case [0,0]
		return res;
	}
};