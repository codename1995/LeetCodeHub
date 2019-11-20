#include <iostream>
#include<cstring>

using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr) {};
	CMyString(const CMyString& str) {};
	~CMyString(void) {};

private:
	char* m_pData;
};

// 默写区域
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str) {
		CMyString strTemp(str);

		char* tmpData = str.m_pData;
		strTemp.m_pData = tmpData;
		m_pData = strTemp.m_pData;
	}
	return *this;
}





// 初级程序员写法
CMyString& CMyString::operator =(const CMyString& str)
{
	if (this == &str)
		return *this;

	delete[]m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

// 高级程序员写法
//CMyString& CMyString::operator =(const CMyString& str)
//{
//	if (this != &str)
//	{
//		CMyString strTemp(str); // 创建一个临时的CMyString
//
//		// 交换strTemp与this的m_pData
//		char* pTemp = strTemp.m_pData; // 创建一个临时的m_pData，在if语句块之外会自动析构
//		strTemp.m_pData = m_pData;
//		m_pData = pTemp;
//	}
//
//	return *this;
//}