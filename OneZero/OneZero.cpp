// OneZero.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

enum Status {
	kInvalid = 0,
	kValid = 1
};

bool g_Normal_Status = kInvalid;
bool g_Dp_Status = kValid;

int oneZeroNormal(int* array, int length);

int oneZeroDP(int* array, int length);

void test(const char* testName, int* array, int length);

int oneZeroNormal(int* array, int length) {
	g_Normal_Status = kInvalid;
	if (array == nullptr || length < 0) {
		g_Normal_Status = false;
		return 0;
	}

	int index = 0;
	int zeroNum = 0;
	int result = 0;
	while (index < length) {
		if (array[index] == 0) {
			zeroNum++;
		}
		else if (array[index] == 1) {
			if (zeroNum == 0 && index != 0) {
				return 0;
			}
			result += (zeroNum - 1) / 2;
			zeroNum = 0;
		}
		else {
			return 0;
		}
		index++;
	}
	result += (zeroNum - 1) / 2;
	g_Normal_Status = kValid;
	return result;
}


int oneZeroDP(int* array, int length) {
	g_Dp_Status = kInvalid;
	if (array == nullptr || length < 0) {
		g_Dp_Status = false;
		return 0;
	}

	int* result = new int[length];

	result[0] = 0;

	return 0;
}

int main()
{
	int* array1 = new int[10] {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	test("test1", array1, 10);
	//std::cout << -1 / 2 << std::endl;
	return 0;
}

void test(const char* testName, int* array, int length) {
	int tempNormal = oneZeroNormal(array, length);
	int tempDp = oneZeroDP(array, length);

	if (!g_Normal_Status || !g_Dp_Status) {
		std::cout << "invalid input" << std::endl;
	}
	else {
		std::cout << testName << ": normal is: " << tempNormal << " and dp is: " << tempDp << std::endl;
	}
	
}

