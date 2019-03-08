// ClassSpaceTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

class Parent
{
public:
	int b = 1;
	char a = 0;
	
};

class Child :public Parent
{
public:
	int c = 1;
	int foo() {
		b++;
		//a++;
		return b;
	}
};

class GrandChild : private Child {
public :
	int z;
	using Parent::b;
	int foo() {

		Parent::b++;
		//a++;
		return b;
	}
};

struct BE
{
	
	long long test2;
	//int b;
	int a;
	virtual void foo();
	
	
	//short number;
	//char a;
	//char b;
	
	
	
	/*union UBffer
	{
		char buffer[13];
		double number;
	}bu;*/
	//char buffer[7];
}bc;

void BE::foo() {

}

int main()
{
	Child b;
	Parent a;
	GrandChild c;
	
	std::cout << "bc.sizeof = " << sizeof(bc) << std::endl;
	//std::cout << b.foo() << std::endl;
	std::cout << "a.sizeof = " << sizeof(a) << std::endl;
	std::cout << "b.sizeof = " << sizeof(b) << std::endl;
	std::cout << "c.sizeof = " << sizeof(c) << std::endl;

	system("pause");
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
