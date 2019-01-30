// 65_AddTwoNumbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。


#include "pch.h"
#include <iostream>
#include <cstdio>

;
int Add(int num1, int num2)
{
	int sum, carry;
	do 
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}
	while (carry != 0);

	return sum;
}

// ====================测试代码====================
void Test(int num1, int num2, int expected)
{
	int result = Add(num1, num2);
	if (result == expected)
		printf("%d + %d is %d. Passed\n", num1, num2, result);
	else
		printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

int main(int argc, char* argv[])
{
	Test(1, 2, 3);
	Test(111, 899, 1010);

	Test(-1, 2, 1);
	Test(1, -2, -1);

	Test(3, 0, 3);
	Test(0, -4, -4);

	Test(-2, -8, -10);

	return 0;
}
