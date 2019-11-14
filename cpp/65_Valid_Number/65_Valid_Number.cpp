#include<string>

using namespace std;

class Solution {
public:
	int i; // idx of string
	bool scanInteger(string s) {
		bool isNumber = false;
		if (s[i] == '+' || s[i] == '-')
			i++;
		
		return scanUnsignedInteger(s);
	}
	bool scanUnsignedInteger(string s){
		bool isNumber = false;
		for (; i <= s.size() - 1; i++) {
			if (s[i] <= '9' && s[i] >= '0')
			{
				isNumber = true;
			}
			else break;
		}
		return isNumber;
	}
	bool isNumber(string s) {
		// if s is a number, it must be A[.[B]][e|EC] or .B[e|EC]
		// where A and C are signed int, B is unsigned int
		if (empty(s))
			return false;

		// check space
		i = 0;
		while (s[i] == ' ') i++;

		bool numeric = scanInteger(s);

		if (i!=s.size() && s[i] == '.')
		{
			// 3种情况：
			// 1. 无整数部分，如.123
			// 2. 无小数部分，如123
			// 3. 整数+小数，如123.123
			i++;
			numeric = scanUnsignedInteger(s) || numeric;
		}

		if (i != s.size() && s[i] == 'e' || s[i] == 'E')
		{
			i++;
			if (i != s.size() && s[i] == '+') i++;
			numeric = numeric && scanInteger(s);
		}

		while (i != s.size() && s[i] == ' ') i++;
		return (numeric && i == s.size());

	}
};

// ====================测试代码====================
// Following code adapted from https://github.com/zhedahht/CodingInterviewChinese2/
void Test(const char* testName, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	string s = str;
	Solution solu;
	if (solu.isNumber(str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
	Test("Test1", "100", true);
	Test("Test2", "123.45e+6", true);
	Test("Test3", "+500", true);
	Test("Test4", "5e2", true);
	Test("Test5", "3.1416", true);
	Test("Test6", "600.", true);
	Test("Test7", "-.123", true);
	Test("Test8", "-1E-16", true);
	Test("Test9", "1.79769313486232E+308", true);

	printf("\n\n");

	Test("Test10", "12e", false);
	Test("Test11", "1a3.14", false);
	Test("Test12", "1+23", false);
	Test("Test13", "1.2.3", false);
	Test("Test14", "+-5", false);
	Test("Test15", "12e+5.4", false);
	Test("Test16", ".", false);
	Test("Test17", ".e1", false);
	Test("Test18", "e1", false);
	Test("Test19", "+.", false);
	Test("Test20", "", false);

	return 0;
}
