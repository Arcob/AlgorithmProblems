﻿// 59_02_QueueWithMax.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题59（二）：队列的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <deque>
#include <exception>

template<typename T> class QueueWithMax
{
public:
	QueueWithMax() : currentIndex(0)
	{
	}

	void push_back(T number)
	{
		while (!maximums.empty() && maximums.back().number <= number) {
			maximums.pop_back();
		}
		InternalData tempData = { number, currentIndex };
		data.push_back(tempData);
		maximums.push_back(tempData);
		currentIndex++;
	}

	void pop_front()
	{
		if (maximums.empty()) {
			throw new std::exception("empty maximums");
		}

		if (maximums.front().index == data.front().index) {
			maximums.pop_front();
		}
		data.pop_front();
	}

	T max() const
	{
		if (maximums.empty()) {
			throw new std::exception("empty maximums");
		}

		return maximums.front().number;
	}

private:
	struct InternalData
	{
		T number;
		int index;
	};

	std::deque<InternalData> data;
	std::deque<InternalData> maximums;
	int currentIndex;
};

// ====================测试代码====================
void Test(const char* testName, const QueueWithMax<int>& queue, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (queue.max() == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	QueueWithMax<int> queue;
	// {2}
	queue.push_back(2);
	Test("Test1", queue, 2);

	// {2, 3}
	queue.push_back(3);
	Test("Test2", queue, 3);

	// {2, 3, 4}
	queue.push_back(4);
	Test("Test3", queue, 4);

	// {2, 3, 4, 2}
	queue.push_back(2);
	Test("Test4", queue, 4);

	// {3, 4, 2}
	queue.pop_front();
	Test("Test5", queue, 4);

	// {4, 2}
	queue.pop_front();
	Test("Test6", queue, 4);

	// {2}
	queue.pop_front();
	Test("Test7", queue, 2);

	// {2, 6}
	queue.push_back(6);
	Test("Test8", queue, 6);

	// {2, 6, 2}
	queue.push_back(2);
	Test("Test9", queue, 6);

	// {2, 6, 2, 5}
	queue.push_back(5);
	Test("Test9", queue, 6);

	// {6, 2, 5}
	queue.pop_front();
	Test("Test10", queue, 6);

	// {2, 5}
	queue.pop_front();
	Test("Test11", queue, 5);

	// {5}
	queue.pop_front();
	Test("Test12", queue, 5);

	// {5, 1}
	queue.push_back(1);
	Test("Test13", queue, 5);

	return 0;
}