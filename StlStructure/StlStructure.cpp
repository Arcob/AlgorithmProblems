// StlStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

void testHeap();

void printVector();

struct S3
{
};

const int returnConstInt();

int main()
{
	/*int test1[] = { 1,2,3,4,5,6};
	int * test2 = new int[6]();
	const int i = returnConstInt();
	const int length = 1;
	int test[length];
	int k = sizeof(int);
	std::cout << sizeof(S3) << " " << returnConstInt() << " " << sizeof(&i) << std::endl;
	testHeap();*/

	const char str1[] = "abc";
	const char str2[] = "abc";
	std::cout << (str1 == str2) << std::endl;

	const char *str7 = "abc";
	const char *str8 = "abc";
	std::cout << (str7 == str8) << std::endl;

    std::cout << "Hello World!\n"; 
}

const int const returnConstInt(){
	return 4;
}

void testHeap() {

}

void printVector() {

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
