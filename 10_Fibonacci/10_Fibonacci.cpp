// 10_Fibonacci.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

long long Fibonacci_Solution(unsigned int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	long long result[] = { 0,1 };
	unsigned int index = 1;
	long long temp = 0;
	while (index < n) {
		temp = result[0] + result[1];
		result[0] = result[1];
		result[1] = temp;
		index++;
	}
	return temp;
}

// ====================测试代码====================
void Test(int n, int expected)
{
	if (Fibonacci_Solution(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);
}

int main(int argc, char* argv[])
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	Test(40, 102334155);

	return 0;
}