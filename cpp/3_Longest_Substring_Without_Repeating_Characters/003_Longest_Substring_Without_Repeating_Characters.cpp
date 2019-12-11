#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	// 思路不难，竟然调了1个小时， 唉
	// 双指针+滑动窗+哈希表
	// 双指针，l和r分别表示当前子串的首尾元素位置
	// 用一个哈希表来存，当前子串中是否存在字符s[i]
	// 用滑动窗来更新，若不存在该字符，则r++，若存在该字符，则l++直到删去该字符
	int lengthOfLongestSubstring(string s) {
		int cnt[128] = { 0 };
		int l = 0, r = 0;
		int max_length = 0;
		for (; r < s.size(); r++) {
			if (cnt[s[r]] == 0)
			{
				cnt[s[r]]++;
				max_length = max(max_length, r + 1 - l);
			}
			else
			{
				while (cnt[s[r]] > 0) {
					cnt[s[l]]--;
					l++;
				}
				cnt[s[r]]++; // while 循环后，cnt[s[r]]==0，但此时应包含s[r]，故再cnt[s[r]]++
			}
		}
		return max_length;
	}
};

void main()
{
	string case1("bbbbb");

	Solution solu;
	int res = solu.lengthOfLongestSubstring(case1);
	cout << res << endl;
}