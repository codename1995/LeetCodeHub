/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <cstdio>
#include <vector>

using namespace std;

void BuildProductionArray(const vector<double>& input, vector<double>& output)
{
	// 将《剑指offer》提供的整个代码拷过来，删掉这个函数下的内容，自己重新打一遍
	vector<double> C, D;
	if (input.size() > 0 || output.size() == input.size())
	{
		C.push_back(1);
		for (int i = 0; i < input.size()-1; ++i)
		{
			C.push_back(C.back() * input[i]);
		}

		D.push_back(1);
		for (int i = input.size() - 1; i > 0; --i)
		{
			D.push_back(D.back() * input[i]);
		}

		for (int i = 0; i < input.size(); ++i)
		{
			output[i] = C[i] * D[input.size() - 1 - i];
		}
	}

	
}

//================= Test Code =================
static bool EqualArrays(const vector<double>& input, const vector<double>& output)
{
	int length1 = input.size();
	int length2 = output.size();

	if (length1 != length2)
		return false;

	for (int i = 0; i < length1; ++i)
	{
		if (abs(input[i] - output[i]) > 0.0000001)
			return false;
	}

	return true;
}

void test(const vector<double>& input, vector<double>& output, const vector<double>& expected)
{
	//printf("%s Begins: ", testName);

	BuildProductionArray(input, output);
	if (EqualArrays(output, expected))
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

static void test1()
{
	// 输入数组中没有0
	vector<double> input= { 1, 2, 3, 4, 5 };
	vector<double> output= { 0, 0, 0, 0, 0 };
	vector<double> expected = { 120, 60, 40, 30, 24 };

	test(input, output, expected);
}

static void test2()
{
	// 输入数组中有一个0
	vector<double> input= { 1, 2, 0, 4, 5 };
	vector<double> output= { 0, 0, 0, 0, 0 };
	vector<double> expected = { 0, 0, 40, 0, 0 };

	test(input, output, expected);
}

static void test3()
{
	// 输入数组中有两个0
	vector<double> input= { 1, 2, 0, 4, 0 };
	vector<double> output= { 0, 0, 0, 0, 0 };
	vector<double> expected = { 0, 0, 0, 0, 0 };

	test(input, output, expected);
}

static void test4()
{
	// 输入数组中有正、负数
	vector<double> input= { 1, -2, 3, -4, 5 };
	vector<double> output= { 0, 0, 0, 0, 0 };
	vector<double> expected = { 120, -60, 40, -30, 24 };

	test(input, output, expected);
}

static void test5()
{
	// 输入输入中只有两个数字
	vector<double> input= { 1, -2 };
	vector<double> output = { 0, 0 };
	vector<double> expected = { -2, 1 };

	test(input, output, expected);
}

int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
