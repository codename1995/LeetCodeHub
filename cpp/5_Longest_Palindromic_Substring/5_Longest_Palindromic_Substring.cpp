#include<string>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	string ss;
	int len;
	int max_len;
	int max_l, max_r;


	void isPalindromeEven(int l, int r) {
		while (l > -1 && r < len) {
			if (ss[l] == ss[r]) {
				if (r - l + 1 > max_len) {
					max_len = r - l + 1;
					max_l = l;
					max_r = r;
				}
				--l;
				++r;
			}
			else break;
		}
	}
	void isPalindromeOdd(int i) {
		int l = i - 1, r = i + 1;
		while (l > -1 && r < len) {
			if (ss[l] == ss[r]) {
				if (r - l + 1 > max_len) {
					max_len = r - l + 1;
					max_l = l;
					max_r = r;
				}
				--l;
				++r;
			}
			else break;
		}
	}
	string longestPalindrome(string s) {
		if (s.size() == 0) return s;
		ss = s;
		len = s.size();
		max_len = 1;
		max_l = 0;
		max_r = -1;
		for (int i = 0; i < ss.size(); ++i) {
			isPalindromeOdd(i);
			isPalindromeEven(i, i + 1);
		}
		return s.substr(max_l, max_len);
	}
};

void main()
{
	Solution solu;

	string case1 = "babaddtattarrattatddetartrateedredividerb";
	cout << (solu.longestPalindrome(case1) == "b") << endl;
}