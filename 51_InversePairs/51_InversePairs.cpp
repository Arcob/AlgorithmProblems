// 51_InversePairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

#include "pch.h"
#include <iostream>
#include <cstdio>

int InversePairsCore(int* data, int* copy, int start, int end);

int merge(int* data, int* copy, int leftStart, int leftEnd, int rightEnd);

void swap(int * a, int* b);

int InversePairs(int* data, int length)
{
	if (data == nullptr || length <= 0) {
		return 0;
	}

	int * copy = new int[length]();


	int result = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;
	return result;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (data == nullptr || copy == nullptr || start < 0 || end <= start) {
		return 0;
	}
	if (start == end - 1) {
		if (data[start] > data[end]) {
			int temp = data[start];
			data[start] = data[end];
			data[end] = temp;
			//std::cout << data[start] << " " << data[end] << std::endl;
			return 1;
		}
		return 0;
	}
	int mid = (start + end) / 2;
	int result = InversePairsCore(data, copy, start, mid) + InversePairsCore(data, copy, mid + 1, end);
	//std::cout << result << std::endl;
	int leftPtr = start;
	int rightPtr = mid + 1;
	int copyPtr = start;
	while (leftPtr < mid + 1 && rightPtr < end + 1) {
		if (data[leftPtr] > data[rightPtr]) {
			copy[copyPtr] = data[rightPtr];
			result += mid - leftPtr + 1;
			copyPtr++;
			rightPtr++;
		}
		else {
			copy[copyPtr] = data[leftPtr];
			//result += end - rightPtr + 1;
			copyPtr++;
			leftPtr++;
		}
	}
	while (leftPtr < mid + 1) {
		copy[copyPtr] = data[leftPtr];
		copyPtr++;
		leftPtr++;
	}
	while (rightPtr < end + 1) {
		copy[copyPtr] = data[rightPtr];
		copyPtr++;
		rightPtr++;
	}

	for (int i = start; i <= end; i++) {
		data[i] = copy[i];
	}
	
	return result;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result = InversePairs(data, length);
	if (result == expected)
		printf("Passed.\n");
	else
		//std::cout << "correct is: " << expected << " as now is: " << result << std::endl;
		printf("Failed.\n");
}

void Test1()
{
	int data[] = { 1, 2, 3, 4, 7, 6, 5 };
	int expected = 3;

	Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
	int data[] = { 6, 5, 4, 3, 2, 1 };
	int expected = 15;

	Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
	int data[] = { 1, 2, 3, 4, 5, 6 };
	int expected = 0;

	Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
	int data[] = { 1 };
	int expected = 0;

	Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
	int data[] = { 1, 2 };
	int expected = 0;

	Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
	int data[] = { 2, 1 };
	int expected = 1;

	Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
	int data[] = { 1, 2, 1, 2, 1 };
	int expected = 3;

	Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
	int expected = 0;

	Test("Test8", nullptr, 0, expected);
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

	return 0;
}
