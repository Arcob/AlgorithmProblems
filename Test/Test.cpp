// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h>

int add(int a, int b) {
	return a + b;
}

template <typename T> std::string testDouble(T);
template <> std::string testDouble(double);

template <typename T> std::string testDouble(T) {
	return "not double";
}

template <> std::string testDouble(double) {
	return "double";
}

template <typename T>
T foo(T temp) {
	return temp + 1;
}

template <>
int foo<int>(int temp) {
	return temp + 3;
}

int foo(int temp) {
	return temp + 2;
}



int main()
{
	std::cout << foo('0') << std::endl;
	
	/*int time = 0;
	time_t start1 = clock();
	while (time < 1000000000) {
		time++;
	}
    //std::cout << "Hello World!\n";
	time_t end1 = clock();
	time = 0;
	int emptyInterval = end1 - start1;
	std::cout << "Empty time interval is: " << emptyInterval << std::endl;

	int test = 141341;
	int temp;
	time_t start2 = clock();
	while (time < 1000000000) {
		temp = test / 2;
		time++;
	}
	time_t end2 = clock();
	time = 0;
	std::cout << "Time interval of / is: " << end2 - start2 - emptyInterval << std::endl;

	time_t start3 = clock();
	while (time < 1000000000) {
		temp = test >> 1;
		time++;
	}
	time_t end3 = clock();
	time = 0;
	std::cout << "Time interval of >> is: " << end3 - start3 - emptyInterval << std::endl;*/

	/*typedef int(*PFtypedef)(int, int);
	using PFusing = int(*)(int, int);
	using D = double;
	int(*pf)(int, int);
	pf = &add;
	PFtypedef add;
	PFusing add;
	D a = 1.0;
	system("pause");*/
}



//看不懂留到之后看的：
//17， 19， 20, 29,45, 46, 51, 55_02, 59_2 62 64
//再写一次的
//12,13,36, 37, 38, 41, 43, 67
//set map一系列东西,哈希表,最大堆,全排列 快排归并排序手写,bfs dfs
//虚函数 录视频
//https://blog.csdn.net/qq_26105397/article/details/80585613
