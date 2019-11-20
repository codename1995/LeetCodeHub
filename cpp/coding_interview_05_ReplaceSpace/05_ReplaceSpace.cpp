#include<cstring>
#include<iostream>

using namespace std;

// ��Ҫ�Լ�ȷ����Ч�ַ������ȣ�length��ʾstr����󳤶�
void ReplaceBlank(char str[], const int length)
{
	if (str == nullptr || length <= 0)
		return;

	int cnt = 0, oriLength = 0;
	for (int i = 0; i < length && str[i]!='\0'; i++) {
		++oriLength;
		if (str[i] == ' ')
			++cnt;
	}


	const int new_length = oriLength + 2 * cnt;
	char* str1 = str + oriLength;
	char* str2 = str + new_length;
	while (str1 < str2) {
		if (*str1 == ' ')
		{
			*str2 = '0';
			*(--str2) = '2';
			*(--str2) = '%';
		}
		else
		{
			*str2 = *str1;
		}
		--str1;
		--str2;
	}
}

//class Solution {
//public:
//    void replaceSpace(char *str,int length) {
//        if(str == nullptr) return;
//        int cntSpace = 0, oriLength = 0;
//        for (int i=0;str[i]!='\0';i++){
//            oriLength++;
//            if (str[i] == ' ') cntSpace++;
//        }
//        
//        int newLength = oriLength + cntSpace * 2;
//        if (newLength+1>length) return;
//        char* str1 = str + oriLength;
//        char* str2 = str + newLength;
//        while (str1 < str2)
//        {
//            if (*str1==' '){
//                *str2-- = '0';
//                *str2-- = '2';
//                *str2-- = '%';
//            }
//            else{
//                *str2-- = *str1;
//            }
//            str1--;
//        }
//    }
//};
/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <cstdio>
#include <cstring>

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
//void ReplaceBlank(char str[], int length)
//{
//	if (str == nullptr && length <= 0)
//		return;
//
//	/*originalLength Ϊ�ַ���str��ʵ�ʳ���*/
//	int originalLength = 0;
//	int numberOfBlank = 0;
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		++originalLength;
//
//		if (str[i] == ' ')
//			++numberOfBlank;
//
//		++i;
//	}
//
//	/*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
//	int newLength = originalLength + numberOfBlank * 2;
//	if (newLength > length)
//		return;
//
//	int indexOfOriginal = originalLength;
//	int indexOfNew = newLength;
//	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
//	{
//		if (str[indexOfOriginal] == ' ')
//		{
//			str[indexOfNew--] = '0';
//			str[indexOfNew--] = '2';
//			str[indexOfNew--] = '%';
//		}
//		else
//		{
//			str[indexOfNew--] = str[indexOfOriginal];
//		}
//
//		--indexOfOriginal;
//	}
//}

// ====================���Դ���====================
void Test(const char* testName, char str[], int length, const char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();

	return 0;
}

