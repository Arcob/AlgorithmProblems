﻿// 56_02_NumberAppearingOnce.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <exception>
;
int FindNumberAppearingOnce(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0) {
		throw new std::exception("Invalid Input");
	}

	int * buffer = new int[32];
	for (int i = 0; i < 32; i++) {
		buffer[i] = 0;
	}
	for (int i = 0; i < length; i++) {
		int tempNumber = numbers[i];
		for (int j = 0; j < 32; j++) {
			buffer[j] += (tempNumber & 1);
			tempNumber = tempNumber >> 1;
		}
	}

	int result = 0;
	int mask = 1;
	for (int i = 0; i < 32; i++) {
		if (buffer[i] % 3 != 0) {
			result = result | mask;
		}
		mask = mask << 1;
	}

	return result;
}

// ====================测试代码====================
void Test(const char* testName, int numbers[], int length, int expected)
{
	int result = FindNumberAppearingOnce(numbers, length);
	if (result == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
}

// 所有数字都是正数，唯一的数字是最小的
void Test1()
{
	int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
	int expected = 3;
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字的大小位于中间
void Test2()
{
	int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
	int expected = 4;
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字是最大的
void Test3()
{
	int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
	int expected = 7;
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 唯一的数字是负数
void Test4()
{
	int numbers[] = { -10, 214, 214, 214 };
	int expected = -10;
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 除了唯一的数字，其他数字都是负数
void Test5()
{
	int numbers[] = { -209, 3467, -209, -209 };
	int expected = 3467;
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 重复的数字有正数也有负数
void Test6()
{
	int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
	int expected = 1023;
	Test("Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是负数
void Test7()
{
	int numbers[] = { -1024, -1024, -1024, -1023 };
	int expected = -1023;
	Test("Test7", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 唯一的数字是0
void Test8()
{
	int numbers[] = { -23, 0, 214, -23, 214, -23, 214 };
	int expected = 0;
	Test("Test8", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 除了唯一的数字，其他数字都是0
void Test9()
{
	int numbers[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
	int expected = 3467;
	Test("Test9", numbers, sizeof(numbers) / sizeof(int), expected);
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