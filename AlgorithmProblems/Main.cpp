#include <iostream>
#include "Solution.h"

int main()
{
	Solution::test();
	int key = 1;
	std::string hehe = "helloworld";
	std::cout << &key << " " << &hehe << std::endl;
	system("pause");
}