// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h>

int main()
{
	int time = 0;
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
	std::cout << "Time interval of >> is: " << end3 - start3 - emptyInterval << std::endl;
	system("pause");
}

//看不懂留到之后看的：
//17， 19， 20, 29, 51, 55_02, 59_2
//再写一次的
//36, 37, 38, 41, 43
//set map一系列东西,哈希表,最大堆
