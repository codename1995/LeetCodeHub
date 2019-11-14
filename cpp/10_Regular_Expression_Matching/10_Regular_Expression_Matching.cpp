#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
	void printMatrix(vector<vector<bool>> v) {
		int nr = v.size();
		int nc = v[0].size();
		cout << "  ";
		for (int j = 0; j < nc; j++)
			cout << j;
		cout << endl;
		for (int i = 0; i < nr; i++) {
			cout << i << " ";
			for (int j = 0; j < nc; j++) cout << v[i][j];
			cout << endl;
		}
		cout << endl;
	}
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		// dp[i][j] denotes s[i:] match p[j:]

		dp.back().back() = true;
		for (int i = s.size(); i != -1; --i) {
			for (int j = p.size() - 1; j != -1; --j) {
				printMatrix(dp);
				bool first_match = i<s.size() && (s[i] == p[j] || p[j] == '.');
				if (j+1<p.size() && p[j + 1] == '*')
					dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
				else
					dp[i][j] = first_match && dp[i + 1][j + 1];
			}
		}
		return dp[0][0];

	}
};

// ====================Test Module====================
void PrintArray(vector<int> numbers, int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

// Following code adapted from https://github.com/zhedahht/CodingInterviewChinese2/
void Test(const char* testName, const char* str, const char* pattern, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);
	
	string s = str;
	string p = pattern;
	Solution solu;
	if (solu.isMatch(s, p) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Test("Test01", "", "", true);
	Test("Test02", "", ".*", true);
	Test("Test03", "", ".", false);
	Test("Test04", "", "c*", true);
	Test("Test05", "a", ".*", true);
	Test("Test06", "a", "a.", false);
	Test("Test07", "a", "", false);
	Test("Test08", "a", ".", true);
	Test("Test09", "a", "ab*", true);
	Test("Test10", "a", "ab*a", false);
	Test("Test11", "aa", "aa", true);
	Test("Test12", "aa", "a*", true);
	Test("Test13", "aa", ".*", true);
	Test("Test14", "aa", ".", false);
	Test("Test15", "ab", ".*", true);
	Test("Test16", "ab", ".*", true);
	Test("Test17", "aaa", "aa*", true);
	Test("Test18", "aaa", "aa.a", false);
	Test("Test19", "aaa", "a.a", true);
	Test("Test20", "aaa", ".a", false);
	Test("Test21", "aaa", "a*a", true);
	Test("Test22", "aaa", "ab*a", false);
	Test("Test23", "aaa", "ab*ac*a", true);
	Test("Test24", "aaa", "ab*a*c*a", true);
	Test("Test25", "aaa", ".*", true);
	Test("Test26", "aab", "c*a*b", true);
	Test("Test27", "aaca", "ab*a*c*a", true);
	Test("Test28", "aaba", "ab*a*c*a", false);
	Test("Test29", "bbbba", ".*a*a", true);
	Test("Test30", "bcbbabab", ".*a*a", false);
	Test("Test31", "mississippi", "mis*is*p*.", true);

	return 0;
}