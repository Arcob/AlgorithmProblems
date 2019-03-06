// NewTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "TestClass.h"

#define MAX(a,b) ((a)>(b)?(a):(b))

template <typename T>
inline int max(const T& a, const T& b){
	return a > b ? a : b;
}

int timer = 0;
enum etest {
	eparam1,
	eparam2,
	eparam3 = 10,
	eparam4,
	eparam5 = 'a',
	eparam6
}epr;

struct A {
	char a;
	int b;
	short c;
};

struct B {
	short c;
	char a;
	int b;
};

int f(int n) {
	timer++;
	if (n <= 3) return 1;
	else return f(n - 2) + f(n - 6) + 1;
}

int main()
{
	/*const int N = 10;
	const int M = 2;
	int* a = new int[N];
	for (int i = 0; i < N; ++i)
		a[i] = (0 == i % 2) ? (i + 2) : (i + 0);
	//int(*b)[N / M] = (int(*)[N / M])a;
	int(*b)[N / M] = (int(*)[N / M])a;
	std::cout << sizeof(b) << std::endl;

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N / M; ++j)
			printf("%d", b[i][j]);
	*/
	int i = 3;
	std::cout << MAX(3, 2) << std::endl;
	std::cout << MAX(3, 8) << std::endl;
	std::cout << max(3, 8) << std::endl;
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
