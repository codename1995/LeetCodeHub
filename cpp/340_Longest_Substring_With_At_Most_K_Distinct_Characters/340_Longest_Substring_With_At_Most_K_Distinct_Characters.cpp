#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	// 相比前置的第3题
	// 1. 多了一个至多包含k个字符的限制
	// 2. 字符串包含ASCII表

	// 做了对应的改动
	// 新增cnt_DistinctCharacters用于统计当前子串中unique后字符个数
	// 将cnt扩展为128位，以适应ASCII表的长度

	// 双指针+滑动窗+哈希表
	// 双指针，l和r分别表示当前子串的首尾元素位置
	// 用一个哈希表来存，当前子串中是否存在字符s[i]
	// 用滑动窗来更新，若当前不同字符数(char_cnt)未超过k，则r++，若存在该字符，则l++直到删去该字符
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (k <= 0 || s.size() == 0) return 0;
		//int k = 2;
		vector<int> cnt(256, 0);
		int char_cnt = 0; // 当前不同字符数
		int l = 0, r = 0;
		int max_length = 0;
		for (; r < s.size() && l < s.size(); ++r) {
			if (++cnt[s[r]] == 1) ++char_cnt;
			if (char_cnt > k) {
				while (char_cnt > k) {
					if (--cnt[s[l++]] == 0) --char_cnt;
				}
			}
			else
			{
				max_length = max(max_length, r - l + 1);
			}
		}
		return max_length;
	}

};


void main()
{
	vector<string> in;
	vector<int> k;
	vector<int> expected_ans;

	in.push_back("bbbbbac");
	k.push_back(2);
	expected_ans.push_back(6);

	in.push_back("eceba");
	k.push_back(2);
	expected_ans.push_back(3);

	in.push_back("a@b$5!a8alskj234jasdf*()@$&%&#FJAvjjdaurNNMa8ASDF-0321jf?>{}L:fh");
	k.push_back(10);
	expected_ans.push_back(14);

	Solution solu;
	for (int i = 0; i != in.size(); i++)
	{
		int res = solu.lengthOfLongestSubstringKDistinct(in[i], k[i]);
		cout << (res == expected_ans[i]) << endl;
	}
}
