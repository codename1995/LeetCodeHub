#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int l = 0, r = A.size();
		if (r <= 1) return A;
		int tmp = 0;
		while (l < r) {
			if (A[l] % 2 != 0) //LeetCode 上要求偶数在前，故此处判断条件为是奇数
			{
				tmp = A[l];
				A[l] = A[--r];
				A[r] = tmp;
			}
			else
			{
				l++;
			}
		}
		return A;
	}
};
// ====================测试代码====================
// Following code adapted from https://github.com/zhedahht/CodingInterviewChinese2/
void PrintArray(vector<int> numbers, int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(const char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	Solution solu;
	vector<int> nums;
	for (int i = 0; i < length; ++i) {
		nums.push_back(numbers[i]);
	}


	printf("Test for solution 1:\n");
	PrintArray(nums, length);
	solu.sortArrayByParity(nums);
	PrintArray(nums, length);

	//printf("test for solution 2:\n");
	//printarray(copy, length);
	//reorderoddeven_2(copy, length);
	//printarray(copy, length);

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}

