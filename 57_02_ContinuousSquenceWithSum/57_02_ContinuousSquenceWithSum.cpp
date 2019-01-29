// 57_02_ContinuousSquenceWithSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <cstdio>

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
	if (sum < 3) {
		return;
	}

	int slowPtr = 1;
	int fastPtr = 2;
	int tempSum = 3;

	while (slowPtr <= (sum >> 1) && fastPtr < sum && slowPtr < fastPtr) {
		if (tempSum == sum) {
			PrintContinuousSequence(slowPtr, fastPtr);
			tempSum -= slowPtr;
			slowPtr++;
			fastPtr++;
			tempSum += fastPtr;
		}
		else if (tempSum > sum) {
			tempSum -= slowPtr;
			slowPtr++;
		}
		else {
			fastPtr++;
			tempSum += fastPtr;
		}
	}
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d ", i);

	printf("\n");
}

// ====================测试代码====================
void Test(const char* testName, int sum)
{
	if (testName != nullptr)
		printf("%s for %d begins: \n", testName, sum);

	FindContinuousSequence(sum);
}

int main(int argc, char* argv[])
{
	Test("test1", 1);
	Test("test2", 3);
	Test("test3", 4);
	Test("test4", 9);
	Test("test5", 15);
	Test("test6", 100);

	return 0;
}
