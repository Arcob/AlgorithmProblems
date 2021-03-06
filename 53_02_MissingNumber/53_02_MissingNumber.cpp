﻿// 53_02_MissingNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <cstdio>

int GetMissingNumber(const int* numbers, int length)
{
	
	if (numbers == nullptr || length <= 0) {
		return -1;
	}

	int start = 0;
	int end = length - 1;
	
	while (start <= end) {//二分时多移动1的index，在start大于end时跳出循环以防止死循环
		int mid = (start + end) / 2;
		if (numbers[mid] == mid) {
			start = mid+1;
		}
		else {
			if (mid == 0 || numbers[mid - 1] == mid - 1) {
				return mid;
			}
			end = mid-1;
		}
	}

	if (start == length)
		return length;

	// 无效的输入，比如数组不是按要求排序的，
	// 或者有数字不在0到n-1范围之内
	return -1;
}

// ====================测试代码====================
void Test(const char* testName, int numbers[], int length, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result = GetMissingNumber(numbers, length);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 缺失的是第一个数字0
void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5 };
	int expected = 0;
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2()
{
	int numbers[] = { 0, 1, 2, 3, 4 };
	int expected = 5;
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test3()
{
	int numbers[] = { 0, 1, 2, 4, 5 };
	int expected = 3;
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
	int numbers[] = { 1 };
	int expected = 0;
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
	int numbers[] = { 0 };
	int expected = 1;
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test6()
{
	int expected = -1;
	Test("Test6", nullptr, 0, expected);
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
