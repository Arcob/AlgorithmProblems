// 57_01_TwoNumbersWithSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

#include "pch.h"
#include <iostream>
#include <cstdio>

bool numExist(int data[], int length, int num);

/*bool FindNumbersWithSum(int data[], int length, int sum,
	int* num1, int* num2)
{
	if (data == nullptr || length <= 0) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (numExist(data, length, sum - data[i])) {
			*num1 = data[i];
			*num2 = sum - data[i];
			return true;
		}
	}

	return false;
}*/
;
bool FindNumbersWithSum(int data[], int length, int sum,
	int* num1, int* num2)
{
	if (data == nullptr || length <= 0 || num1 == nullptr || num2 == nullptr) {
		return false;
	}

	int slowPtr = 0;
	int fastPtr = length - 1;

	while (slowPtr < fastPtr) {
		int tempSum = data[slowPtr] + data[fastPtr];
		if (tempSum == sum) {
			*num1 = data[slowPtr];
			*num2 = data[fastPtr];
			return true;
		}
		else if (tempSum < sum) {
			slowPtr++;
		}
		else {
			fastPtr--;
		}
	}

	return false;
}

bool numExist(int data[], int length, int num) {
	if (data == nullptr || length <= 0) {
		return false;
	}

	int start = 0;
	int end = length - 1;
	while (start <= end) {
		int mid = (start + end) >> 1;
		if (data[mid] == num) {
			return true;
		}

		if (data[mid] < num) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return false;
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int sum, bool expectedReturn)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int num1, num2;
	int result = FindNumbersWithSum(data, length, sum, &num1, &num2);
	if (result == expectedReturn)
	{
		if (result)
		{
			if (num1 + num2 == sum)
				printf("Passed. \n");
			else
				printf("FAILED. \n");
		}
		else
			printf("Passed. \n");
	}
	else
		printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
	int data[] = { 1, 2, 4, 7, 11, 15 };
	Test("Test1", data, sizeof(data) / sizeof(int), 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test2", data, sizeof(data) / sizeof(int), 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
	int data[] = { 1, 2, 4, 7, 11, 16 };
	Test("Test3", data, sizeof(data) / sizeof(int), 10, false);
}

// 鲁棒性测试
void Test4()
{
	Test("Test4", nullptr, 0, 0, false);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}