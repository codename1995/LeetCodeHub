#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		// 2. KMP


		// 1. 基础字符串匹配，O(mn)，超时
		if (needle.size() == 0) return 0;
		bool flag = true;
		for (int i = 0; i < haystack.size(); ++i) {
			flag = true;
			int j = 0;
			for (; j < needle.size(); ++j) {
				if ((i + j) < haystack.size() && needle[j] != haystack[i + j]) {
					flag = false;
					break;
				}
			}
			if (i + j <= haystack.size() && flag) return i;
			flag = false;
		}
		return -1;
	}
};