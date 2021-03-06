// NeteaseBackPack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <math.h> 
#include<algorithm>

/*
21 1165911996
842104736 130059605 359419358 682646280 378385685 622124412 740110626 814007758 557557315 40153082 542984016 274340808 991565332 765434204 225621097 350652062 714078666 381520025 613885618 64141537 783016950*/

int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int*)b);
}

void dfs(long long capacityRemain, const std::vector<int>& snacks, int tempIndex, int & result) {
	if (capacityRemain < 0) {
		return;
	}

	if(tempIndex == snacks.size()){
		result++;
		return;
	}

	dfs(capacityRemain, snacks, tempIndex+1, result);
	dfs(capacityRemain - snacks[tempIndex], snacks, tempIndex+1, result);
	return;
}

int main()
{
	int snackNum;
	long long capacity;
	scanf_s("%d %d", &snackNum, &capacity);

	long long sum = 0;
	int * snacks = new int[snackNum];
	for (int i = 0; i < snackNum; i++) {
		scanf_s("%d", &snacks[i]);
		sum += snacks[i];
	}

	if (sum < capacity) {
		std::cout << (int)pow(2, snackNum) << std::endl;
		return 0;
	}

	std::vector<int> treatedSnacks;
	for (int i = 0; i < snackNum; i++) {
		if (snacks[i] < capacity) {
			treatedSnacks.push_back(snacks[i]);
		}
	}
	delete[] snacks;
	std::sort(treatedSnacks.begin(), treatedSnacks.end());
	//qsort(&treatedSnacks[0], treatedSnacks.size(), sizeof(int), cmp);
	/*int * resultArray = new int[capacity+1]();
	
	resultArray[0] = 1;
	for (int i = 1; i < capacity + 1; i++) {
		int index = 0;
		int tempNum = 0;
		while (i - treatedSnacks[index] > 0) {
			tempNum += resultArray[i - treatedSnacks[index]];
			index++;
		}
		resultArray[0] = tempNum;
	}*/
	int result = 0;
	dfs(capacity, treatedSnacks, 0, result);
	std::cout << result << std::endl;
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
