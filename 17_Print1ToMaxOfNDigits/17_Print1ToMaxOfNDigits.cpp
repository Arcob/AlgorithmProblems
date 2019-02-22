// 17_Print1ToMaxOfNDigits.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <cstdio>

void PrintNumber(char* number);
bool Increment(char* number);
void Swap(char* a, char* b);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

//不会 之后看

// ====================方法一====================
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	number[n] = '\0';
	Print1ToMaxOfNDigitsRecursively(number, n, -1);

	delete[] number;
	
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void swap(char* a, char* b) {
	char temp = *a;
	*b = *a;
	*a = temp;
}

// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	int index = 0;
	while (number[index] == 0) {
		index++;
	}
	
	while (number[index] != '\0') {
		printf("%c", number[index]);
		index++;
	}

	printf("\t");
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits(n);

	printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);

	return 0;
}
