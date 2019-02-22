// 44_DigitsInSequence.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include "pch.h"
#include <iostream>
#include <algorithm>

using namespace std;

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int getTotalnumberOfDigits(int num);
int PowerBase10(unsigned int n);

int digitAtIndex(int index)
{
	if (index < 0) {
		return -1;
	}

	/*if (index <= 9) {
		return index;
	}*/
	
	int curNumberOfDigits = 0;
	int indexRemain = index;
	int lastIndexRemain = indexRemain;

	while (indexRemain >= 0) {
		curNumberOfDigits++;
		lastIndexRemain = indexRemain;
		indexRemain -= getTotalnumberOfDigits(curNumberOfDigits);
		
	}
	//curNumberOfDigits此时表明数字是几位数
	//lastIndexRemain此时表明还剩下几位数字
	int numberNum = 0;
	while (lastIndexRemain >= curNumberOfDigits) {
		lastIndexRemain -= curNumberOfDigits;
		numberNum++;
	}
	lastIndexRemain = curNumberOfDigits - lastIndexRemain;
	//lastIndexRemain此时表明该数是数字的第几位
	int number = PowerBase10(curNumberOfDigits - 1);
	if (curNumberOfDigits == 1) { //如果是个位数是从0开始而不是从1
		number = 0;
	}
	number += numberNum;
	while (lastIndexRemain > 1) {
		number /= 10;
		lastIndexRemain -= 1;
	}
	
	return number % 10;
}

int getTotalnumberOfDigits(int num) {
	if (num <= 0) {
		return 0;
	}if (num == 1) {
		return 10;
	}
	return num * PowerBase10(num - 1) * 9;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
		result *= 10;

	return result;
}

int countOfIntegers(int digits)
{
	
	return 0;
}

int digitAtIndex(int index, int digits)
{
	
	return 0;
}

int beginNumber(int digits)
{
	if (digits == 1)
		return 0;

	return (int)std::pow(10, digits - 1);
}

// ====================测试代码====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if (digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}


int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
	return 0;
}