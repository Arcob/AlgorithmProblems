// 49_UglyNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。


#include "pch.h"
#include <iostream>
#include <cstdio>

// ====================算法1的代码====================
bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;

	return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
	if (index <= 0)
		return 0;

	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		++number;

		if (IsUgly(number))
			++uglyFound;
	}

	return number;
}

// ====================算法2的代码====================
int Min(int number1, int number2, int number3);

int GetUglyNumber_Solution2(int index)
{
	if (index <= 0) {
		return 0;
	}

	int* uglyNumbers = new int[index];
	uglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int * pMultiply2 = uglyNumbers;
	int * pMultiply3 = uglyNumbers;
	int * pMultiply5 = uglyNumbers;

	while (nextUglyIndex < index) {
		int next = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		uglyNumbers[nextUglyIndex] = next;

		while (*pMultiply2 * 2 <= next) {
			pMultiply2++;;
		}

		while (*pMultiply3 * 3 <= next) {
			pMultiply3++;;
		}

		while (*pMultiply5 * 5 <= next) {
			pMultiply5++;;
		}

		nextUglyIndex++;
	}

	int ugly = uglyNumbers[nextUglyIndex - 1];
	delete[] uglyNumbers;
	return ugly;

	return 0;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;

	return min;
}

// ====================测试代码====================
void Test(int index, int expected)
{
	if (GetUglyNumber_Solution1(index) == expected)
		printf("solution1 passed\n");
	else
		printf("solution1 failed\n");

	if (GetUglyNumber_Solution2(index) == expected)
		printf("solution2 passed\n");
	else
		printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
	/*int * testPtr = new int[10];
	std::cout << testPtr << std::endl;
	std::cout << reinterpret_cast<int>(testPtr) << std::endl;
	int * testPtr2 = testPtr+1;
	std::cout << testPtr2 << std::endl;
	std::cout << reinterpret_cast<int>(testPtr2) << std::endl;
	std::cout << reinterpret_cast<int>(testPtr) << std::endl;*/

	Test(1, 1);

	Test(2, 2);
	Test(3, 3);
	Test(4, 4);
	Test(5, 5);
	Test(6, 6);
	Test(7, 8);
	Test(8, 9);
	Test(9, 10);
	Test(10, 12);
	Test(11, 15);

	Test(1500, 859963392);

	Test(0, 0);

	return 0;
}