// 60_DicesProbability.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <math.h>

int g_maxValue = 6;

// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
	if (number < 1)
		return;

	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;

	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i)
	{
		double ratio = (double)pProbabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int* pProbabilities)
{
	for (int i = 1; i <= g_maxValue; ++i)
		Probability(number, number, i, pProbabilities);
}

void Probability(int original, int current, int sum,
	int* pProbabilities)
{
	if (current == 1)
	{
		pProbabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

// ====================方法二====================
void PrintProbability_Solution2(int number)
{
	if (number < 1)
		return;

	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1]();
	pProbabilities[1] = new int[g_maxValue * number + 1]();



	int * curBuffer = pProbabilities[0];
	int * lastBuffer = pProbabilities[1];

	for (int i = 1; i <= g_maxValue; i++) {
		lastBuffer[i] = 1;
	}
	
	for (int i = 2; i <= number; i++) {
		for (int j = i; j <= g_maxValue * i; j++) {
			for (int k = 1; k <= 6; k++) {
				curBuffer[j] += (j - k > 0) ? lastBuffer[j - k] : 0;
			}
		}
		int* temp = curBuffer;
		curBuffer = lastBuffer;
		lastBuffer = temp;
	}
	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i)
	{
		double ratio = (double)lastBuffer[i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];

	return;
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	printf("Test for solution1\n");
	PrintProbability_Solution1(n);

	printf("Test for solution2\n");
	PrintProbability_Solution2(n);

	printf("\n");
}

int main(int argc, char* argv[])
{
	Test(1);
	Test(2);
	Test(3);
	Test(4);

	Test(11);

	Test(0);

	return 0;
}
