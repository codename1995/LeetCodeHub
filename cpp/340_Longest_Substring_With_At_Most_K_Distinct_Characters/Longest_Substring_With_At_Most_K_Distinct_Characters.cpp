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
	// 用滑动窗来更新，若不存在该字符，则r++，若存在该字符，则l++直到删去该字符
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (k <= 0 || s.size() == 0) return 0;
		//int k = 2;
		int cnt[128] = { 0 };
		int cnt_DistinctCharacters = 0;
		int l = 0, r = 0;
		int max_length = 0;
		for (; r < s.size(); r++) {
			if (cnt_DistinctCharacters < k || cnt_DistinctCharacters == k && cnt[s[r]] >= 1)
			//if (cnt[s[r]] < k && cnt_DistinctCharacters<=k)
			{
				if (cnt[s[r]] == 0) cnt_DistinctCharacters++; // 当前子串中没有该字符，需新增

				cnt[s[r]]++;
				max_length = max(max_length, r + 1 - l);
			}
			else
			{
				while (cnt_DistinctCharacters>=k){ // 缩短子串，直到子串中的unique字符个数比k少1个
					if (--cnt[s[l]] == 0) {
						cnt_DistinctCharacters--;
					}
					l++;
				}
				// while 循环后，补上s[r]的相关信息（哈希表+1，unique字符个数+1）
				cnt[s[r]]++;
				cnt_DistinctCharacters++;
			}
			//for (int i = l; i != r; i++)
			//	cout << s[i];
			//cout << endl;
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
