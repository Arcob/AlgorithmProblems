// CowFindJob.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>

struct Work {
	int difficulty;
	int pay;
}works[100001];

struct Student {
	int ability;
	int id;
	int pay;
}students[100001];

int workCmp(const void* a, const void* b) {
	return ((Work*)a)->difficulty > ((Work*)b)->difficulty;
}

int studentCmpWithAbility(const void* a, const void* b) {
	return ((Student*)a)->ability > ((Student*)b)->ability;
}

int studentCmpWithId(const void* a, const void* b) {
	return ((Student*)a)->id > ((Student*)b)->id;
}

int workNumN, studentNumM;
int main()
{
	std::cin >> workNumN >> studentNumM;
	for (int i = 0; i < workNumN; i++)
	{
		scanf_s("%d %d", &works[i].difficulty, &works[i].pay);
	}
	std::qsort(works, workNumN, sizeof(Work),workCmp);

	for (int i = 0; i < studentNumM; i++)
	{
		scanf_s("%d", &students[i].ability);
		students[i].id = i;
	}
	std::qsort(students, studentNumM, sizeof(Student), studentCmpWithAbility);

	int pWork = 0;
	int tempPay = 0;
	for (int i = 0; i < studentNumM; i++) {
		while (pWork<workNumN && students[i].ability >= works[pWork].difficulty) {
			tempPay = std::max(works[pWork].pay,tempPay);
			pWork++;
		}
		students[i].pay = tempPay;
	}
	//std::qsort(students, studentNumM, sizeof(Student), studentCmpWithId);

	for (int i = 0; i < studentNumM; i++) {
		printf("%d\n", students[i].pay);
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
