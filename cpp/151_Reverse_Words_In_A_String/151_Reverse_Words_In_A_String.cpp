#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	// @Iris_bupt
	// https://leetcode-cn.com/problems/reverse-words-in-a-string/solution/c-si-xing-dai-ma-ji-qi-you-hua-by-pris_bupt/
	string reverseWords(string s) {
		// Solution 3: In-place and not use stringstream.
		// reverse the whole string, then reverse every world.
		// 4 ms, 98.7%
		reverse(s.begin(), s.end());

		// find the first and last valid character
		int beg = 0, endd = s.size() - 1;
		while (s[beg] == ' ') ++beg;
		while (s[endd] == ' ') --endd;
		if (beg > endd) return "";

		// reverse every world
		int r = beg;
		int l = beg;
		while (r <= endd)
		{
			while (s[r] != ' ' && r <= endd) ++r;	// r指向第一个空格或s.end()+1
			reverse(s.begin() + l, s.begin() + r);	// reverse(b, e) 前闭后开
			while (r<=endd && s[r] == ' ') r++;	//退出循环时r指向第一个有效字符或s.end()+1,前者会继续运行，后者会退出外层循环
			l = r;
		}

		// eliminate additional space
		int tail = beg;
		for (int i = beg; i <= endd; ++i)
		{
			if (i >= 1 && s[i] == ' ' && s[i - 1] == ' ') continue;
			s[tail++] = s[i];
		}
		return s.substr(beg, tail - beg);



		// Solution 2: use stringstream, but didn't use string.insert() to save time;
		// save in order, but output in reversed order.
		// 4 ms, 98.7%
		//string res, s2;
		//stringstream ss(s);
		//vector<string> tmp;
		//while (ss >> s2) tmp.push_back(s2);
		//for (int i = tmp.size() - 1; i != -1; --i)
		//	res += tmp[i] + " ";

		//return res.size() ? string(res.begin(), res.end() - 1) : "";


		// Solution 1: use stringstream
		// 28 ms, 18.4%
		//string res, s2;
		//stringstream ss(s);
		//while (ss >> s2) res.insert(0, s2 + " ");
		//return res.size() ? string(res.begin(), res.end() - 1) : "";

	}
};

void main()
{
	Solution solu;

	string case1{ "the sky is blue" };
	string EA1{ "blue is sky the" };
	cout << (solu.reverseWords(case1) == EA1) << endl;
}
