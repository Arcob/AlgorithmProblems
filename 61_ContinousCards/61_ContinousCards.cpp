﻿// 61_ContinousCards.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int* numbers, int length)
{
	if (numbers == nullptr || length < 1)
		return false;

	qsort(numbers, length, sizeof(int), Compare);
	
	int numOfZero = 0;
	int numOfInterval = 0;

	for (int i = 0; i < length; i++) {
		if (numbers[i] == 0) {
			numOfZero++;
		}
		else if (i+1<length && numbers[i] == numbers[i + 1]) { //处理对子，如果对子存在则一定不是顺子
			return false;
		}
	}

	int startIndex = 0;

	while (numbers[startIndex] == 0) {
		startIndex++;
		if (startIndex >= length) {
			return true;
		}
	}
	//std::cout << numbers[length - 1] << " bb " << numbers[startIndex] << std::endl;
	numOfInterval = (numbers[length - 1] - numbers[startIndex])-(length-1 - startIndex);
	//std::cout << numOfZero << " aa " << numOfInterval << std::endl;

	return (numOfInterval <= numOfZero) ? true: false;
}

int Compare(const void *arg1, const void *arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}

// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (IsContinuous(numbers, length) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	int numbers[] = { 1, 3, 2, 5, 4 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
	int numbers[] = { 1, 3, 2, 6, 4 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
	int numbers[] = { 0, 3, 2, 6, 4 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
	int numbers[] = { 0, 3, 1, 6, 4 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
	int numbers[] = { 1, 3, 0, 5, 0 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
	int numbers[] = { 1, 3, 0, 7, 0 };
	Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
	int numbers[] = { 1, 0, 0, 5, 0 };
	Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
	int numbers[] = { 1, 0, 0, 7, 0 };
	Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
	int numbers[] = { 3, 0, 0, 0, 0 };
	Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
	int numbers[] = { 0, 0, 0, 0, 0 };
	Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
	int numbers[] = { 1, 0, 0, 1, 0 };
	Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
	Test("Test12", nullptr, 0, false);
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
	Test10();
	Test11();
	Test12();

	return 0;
}
