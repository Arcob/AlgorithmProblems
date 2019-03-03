// TencentSimulation2_31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

void test(const char* name, const char* in, int expected);

int returnIndex(const char* in);

int main()
{
	test("Test 1", "a", 0);
	test("Test 2", "aaa", 2);
	test("Test 3", "b", 2);
	test("Test 4", "baca", 16331);
    std::cout << "Hello World!\n"; 
}

int returnIndex(const char* in) {
	if (in == nullptr) {
		return 0;
	}
	int length = 0;
	while (in[length] != '\0') {
		length++;
	}
	int index = 0;
	for (int i = 0; i < length; i++, index++) {
		int n = in[i] - 'a';
		for (int j = 0; j < 4 - i; j++)
			index += n * pow(25, j);
	}
	std::cout << index - 1 << std::endl;
	std::cout << 25 * 25 * 25+ + 625 + 25 * 2 << std::endl;
	return index - 1;
}

void test(const char* name, const char* in, int expected) {
	std::cout << name <<((returnIndex(in) == expected) ? (" passed") : (" failed")) << std::endl;
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
