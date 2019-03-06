// IpStringToInt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

enum Status
{
	kInvalid = 0,
	kValid = 1
};

bool g_nStatus = kInvalid;

long long IpStrToLong(const char* string) {
	g_nStatus = kInvalid;

	if (string == nullptr || *string == '\0') {
		return 0;
	}
	bool canBeDot = false;

	const char* pTemp = string;
	int dotNum = 0;
	long long result = 0;
	long tempResult = 0;

	while (*pTemp != '\0') {
		if (canBeDot && *pTemp == '.') {
			canBeDot = false;
			if (tempResult > 255) {
				return 0;
			}
			tempResult = 0;
			pTemp++;
			dotNum++;
			continue;
		}

		if (*pTemp >= '0' && *pTemp <= '9') {
			if (tempResult == 0 && *pTemp == '0' && *(pTemp+1)!='.' && *(pTemp + 1) != '\0') {
				return 0;
			}
			result *= 10;
			result += *pTemp - '0';
			tempResult *= 10;
			tempResult += *pTemp - '0';
			canBeDot = true;
			pTemp++;
		}else {
			return 0;
		}

		
	}
	if (dotNum != 3) {
		return 0;
	}
	g_nStatus = kValid;
	return result;

}

void Test(const char* string)
{
	long long result = IpStrToLong(string);
	if (result == 0 && g_nStatus == kInvalid)
		printf("the input %s is invalid.\n", string);
	else
		printf("number for %s is: %lld.\n", string, result);
}

int main()
{
	std::cout << "sizeof(long long) is: " << sizeof(long long) << std::endl;
	std::cout << "sizeof(long) is: " << sizeof(long) << std::endl;
	std::cout << "sizeof(int) is: " << sizeof(int) << std::endl;
	Test(nullptr);//nullptr

	Test("");//空字符串

	Test("192.168.0.103");//正确

	Test("10.0.0.1");//正确

	Test("127.0.0.1");//正确

	Test("731.0.0.1");//某一位超过255

	Test("127..0.1");//连点

	Test("127.0.122.0.1");//点数超过3个

	Test("255.255.255.255");//超过int最大值（用longlong）

	Test("2222.255.255.255");//某一位超过三位

	Test("192.068.0.103");//某一段开头是0

	Test("192.168.0.0");//结尾是单独的0

	Test("0.0.0.0");//全是0

	Test("12345");//没有点

	Test("+");//无关字符串

	return 0;
}