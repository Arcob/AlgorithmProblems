// 42_GreatestSumOfSubarrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include "pch.h"
#include <iostream>
#include <cstdio>
;
bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	g_InvalidInput = false;
	if (pData == nullptr || nLength <= 0) {
		g_InvalidInput = true;
		return 0;
	}

	int tempSum = 0;
	int max = INT_MIN; //解决所有数都是负数造成的问题,max不能为0
	for (int i = 0; i < nLength; i++) {
		tempSum += pData[i];
		if (tempSum > max) {
			max = tempSum;
		}
		if (tempSum < 0) {
			tempSum = 0;
		}
	}

	return max;
}

// ====================测试代码====================
void Test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
	Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}