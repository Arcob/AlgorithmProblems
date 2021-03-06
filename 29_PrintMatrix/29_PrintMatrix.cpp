// 29_PrintMatrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

//之后重写
#include "pch.h"
#include <iostream>
#include <cstdio>

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNumber(int number);

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == nullptr || columns <= 0 || rows <= 0) {
		return;
	}

	int start = 0;
	while (columns > start * 2 && rows > start * 2) {
		PrintMatrixInCircle(numbers, columns, rows, start);

		++start;
	}
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i <= endX; i++) {
		int number = numbers[start][i];
		printNumber(number);
	}
	if (start < endY) {
		for (int j = start + 1; j <= endY; j++) {
			int number = numbers[j][endX];
			printNumber(number);
		}
	}
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; i--) {
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	if (start < endX && start < endY - 1)
	{
		for (int j = endY - 1; j >= start + 1; j--) {
			int number = numbers[j][start];
			printNumber(number);
		}
	}
}

void printNumber(int number)
{
	printf("%d\t", number);
}

// ====================测试代码====================
void Test(int columns, int rows)
{
	printf("Test Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}

int main(int argc, char* argv[])
{
	/*
	1
	*/
	Test(1, 1);

	/*
	1    2
	3    4
	*/
	Test(2, 2);

	/*
	1    2    3    4
	5    6    7    8
	9    10   11   12
	13   14   15   16
	*/
	Test(4, 4);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14   15
	16   17   18   19   20
	21   22   23   24   25
	*/
	Test(5, 5);

	/*
	1
	2
	3
	4
	5
	*/
	Test(1, 5);

	/*
	1    2
	3    4
	5    6
	7    8
	9    10
	*/
	Test(2, 5);

	/*
	1    2    3
	4    5    6
	7    8    9
	10   11   12
	13   14   15
	*/
	Test(3, 5);

	/*
	1    2    3    4
	5    6    7    8
	9    10   11   12
	13   14   15   16
	17   18   19   20
	*/
	Test(4, 5);

	/*
	1    2    3    4    5
	*/
	Test(5, 1);

	/*
	1    2    3    4    5
	6    7    8    9    10
	*/
	Test(5, 2);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14    15
	*/
	Test(5, 3);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14   15
	16   17   18   19   20
	*/
	Test(5, 4);

	return 0;
}