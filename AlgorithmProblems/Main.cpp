#include <iostream>
#include "AllProblems.h"

void duplicate() {
	int numbers0[] = { 2,3,1,0,2,5,3 };//有重复正确用例
	int length0 = sizeof(numbers0) / sizeof(int);

	int numbers1[] = { 2,3,1,0,4,5,6 };//无重复正确用例
	int length1 = sizeof(numbers1) / sizeof(int);

	int numbers2[] = { 2,3,1,0,9,5,3 };//数字范围超出长度
	int length2 = sizeof(numbers2) / sizeof(int);

	int* numbers3 = nullptr;//传入空指针
	int length3 = 7;

	int *duplication = &numbers0[2];
	bool result = Duplicate::duplicate(numbers3, length3, duplication);
	std::cout << result << " " << *duplication << std::endl;
}

int main()
{
	duplicate();
	system("pause");
}
