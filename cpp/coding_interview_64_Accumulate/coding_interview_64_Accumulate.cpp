#include<iostream>


using namespace std;

// 作者给了四种解法，我感觉真要我想，只能手写出第一种
// 另外在知乎上看到一种解法觉得还不错，也写在这里

class Solution1
{
private:
	static unsigned int sum;
	static unsigned int n;
public:
	Solution1() { ++n; sum += n; }

	static void reset() { n = 0; sum = 0; }
	static unsigned int GetSum() { return sum; }
};

unsigned int Solution1::sum = 0;
unsigned int Solution1::n = 0;

unsigned int Sum_Solution1(unsigned int n)
{
	Solution1::reset();

	Solution1* a = new Solution1[n];
	delete[]a;
	a = nullptr;

	return Solution1::GetSum();
}

class Solution5 {
	// https://zhuanlan.zhihu.com/p/41514000
public:
	int Sum_Solution5(int n) {
		int sum = n;
		bool t = (n > 0) && (sum += Sum_Solution5(n - 1)) > 0;
		return sum;
	}
};

void main()
{
	Solution5 s5;
	int n = s5.Sum_Solution5(5);
	cout << n << endl;
}
