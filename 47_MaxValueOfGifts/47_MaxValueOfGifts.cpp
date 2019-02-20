// 47_MaxValueOfGifts.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

#include "pch.h"
#include <algorithm>
#include <iostream>
;
int getMaxValue_solution1(const int* values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0) {
		return 0;
	}

	int** maxValues = new int*[rows];
	for (int i = 0; i < rows; ++i)
		maxValues[i] = new int[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int left = 0;
			int up = 0;

			if (i > 0)
				up = maxValues[i - 1][j];

			if (j > 0)
				left = maxValues[i][j - 1];

			maxValues[i][j] = std::max(left, up) + values[i * cols + j];
		}
	}

	int maxValue = maxValues[rows - 1][cols - 1];

	for (int i = 0; i < rows; ++i)
		delete[] maxValues[i];
	delete[] maxValues;

	return maxValue;
}

int getMaxValue_solution2(const int* values, int rows, int cols)
{
	if (values == nullptr || rows <= 0 || cols <= 0) {
		return 0;
	}

	int * cache = new int[cols]();
	int * result = new int[cols]();
	int colIndex = 0;
	
	while (colIndex < rows) {
		result[0] = cache[0] + values[colIndex * cols];
		for (int i = 1; i < cols; i++) {
			result[i] = std::max(cache[i]+ values[colIndex * cols + i], result[i - 1] + values[colIndex * cols + i]);
		}
		colIndex++;
		int * temp = cache;
		cache = result;
		result = temp;
		//cache = result;
		for (int i = 0; i < cols; i++) {
			//std::cout << result[i] << std::endl;
			result[i] = 0;
		}
	}
	//std::cout << cache[cols - 1] << std::endl;
	return cache[cols-1];
}

// ====================测试代码====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
	if (getMaxValue_solution1(values, rows, cols) == expected)
		std::cout << testName << ": solution1 passed." << std::endl;
	else
		std::cout << testName << ": solution1 FAILED." << std::endl;

	if (getMaxValue_solution2(values, rows, cols) == expected)
		std::cout << testName << ": solution2 passed." << std::endl;
	else
		std::cout << testName << ": solution2 FAILED." << std::endl;
}

void test1()
{
	// 三行三列
	int values[][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	int expected = 29;
	test("test1", (const int*)values, 3, 3, expected);
}

void test2()
{
	//四行四列
	int values[][4] = {
		{ 1, 10, 3, 8 },
		{ 12, 2, 9, 6 },
		{ 5, 7, 4, 11 },
		{ 3, 7, 16, 5 }
	};
	int expected = 53;
	test("test2", (const int*)values, 4, 4, expected);
}

void test3()
{
	// 一行四列
	int values[][4] = {
		{ 1, 10, 3, 8 }
	};
	int expected = 22;
	test("test3", (const int*)values, 1, 4, expected);
}

void test4()
{
	int values[4][1] = {
		{ 1 },
		{ 12 },
		{ 5 },
		{ 3 }
	};
	int expected = 21;
	test("test4", (const int*)values, 4, 1, expected);
}

void test5()
{
	// 一行一列
	int values[][1] = {
		{ 3 }
	};
	int expected = 3;
	test("test5", (const int*)values, 1, 1, expected);
}

void test6()
{
	// 空指针
	int expected = 0;
	test("test6", nullptr, 0, 0, expected);
}

int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}
