// 50_01_FirstNotRepeatingChar.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>

/*char FirstNotRepeatingChar(const char* pString)
{
	if (pString == nullptr) {
		return '\0';
	}

	int * timeArray = new int[256];
	int * firstIndexInString = new int[256];
	for (int i = 0; i < 256; i++) {
		timeArray[i] = 0;
		firstIndexInString[i] = -1;
	}

	int index = 0;
	while (pString[index] != '\0') {
		timeArray[pString[index]] += 1;
		firstIndexInString[pString[index]] = index;
		index++;
	}

	int earliestTime = INT_MAX;
	char result = '\0';
	for (int i = 0; i < 256; i++) {
		if (timeArray[i] == 1) {
			if (firstIndexInString[i] < earliestTime) {
				earliestTime = firstIndexInString[i];
				result = static_cast<char>(i);
			}
		}
	}

	return result;
}*/

char FirstNotRepeatingChar(const char* pString)
{
	if (pString == nullptr)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i < tableSize; ++i)
		hashTable[i] = 0;

	const char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)] ++;

	pHashKey = pString;
	//不用存顺序
	while (*pHashKey != '\0')//按字符串顺序从前往后找即可保证找到的一定是第一个
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;
		
		pHashKey++;
	}

	return '\0';
}

// ====================测试代码====================
void Test(const char* pString, char expected)
{
	if (FirstNotRepeatingChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	// 常规输入测试，存在只出现一次的字符
	Test("google", 'l');

	// 常规输入测试，不存在只出现一次的字符
	Test("aabccdbd", '\0');

	// 常规输入测试，所有字符都只出现一次
	Test("bacdefg", 'b');

	// 鲁棒性测试，输入nullptr
	Test(nullptr, '\0');

	return 0;
}