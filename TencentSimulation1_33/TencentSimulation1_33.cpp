// TencentSimulation1_33.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

const int MAX_N = 1000;
int visit[MAX_N+1];
int prime[MAX_N+1];

int main()
{	

	for (int i = 2; i <= MAX_N + 1; i++) {
		/*if (!prime[i]) {         //如果i是素数，让i的所有倍数都不是素数
			for (int j = i * i; j <= MAX_N; j += i) {
				prime[j] = 1;
			}
		}*/
		//std::cout << " i = " << i << std::endl;
		if (!visit[i]) {
			prime[0]++;
			prime[prime[0]] = i;      //纪录素数， 这个prime[0] 相当于 cnt，用来计数
		}
		for (int j = 1; j <= prime[0] && i*prime[j] <= MAX_N; j++) {
			//std::cout<<"  j = "<<j<<" prime["<<j<<"]"<<" = "<<prime[j]<<" i*prime[j] = "<<i*prime[j]<< std::endl;
			visit[i*prime[j]] = 1;
			if (i % prime[j] == 0) {
				std::cout << i << " " << prime[j] << std::endl;
				break;
			}
		}
	}
	for (int i = 1; i < prime[0]; i++) {
		if (prime[i]!=0) {
			std::cout << prime[i] << " ";
		}
		
	}
    std::cout << "Hello World!\n"; 
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
