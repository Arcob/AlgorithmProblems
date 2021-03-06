// VirtualTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <hash_set>
#include <unordered_set>

class Base {
public:
	virtual void foo();
private:
	int temp;
	void bar() {

	}
};

class Derived : public Base{
public:
	virtual void foo();
};

void Base::foo() {
	std::cout << "Base foo" << std::endl;
}

void Derived::foo() {
	//temp++;
	std::cout << "Derived foo" << std::endl;
}

constexpr int max(int a, int b) {
	return a > b ? a : b;
}

constexpr int getSum(int a, int b) {
	return max(a,b);
}

//测private函数继承问题
int main()
{
	long long a;
	switch (a)
	{
	case 1:
		break;
	default:
		break;
	}
	std::hash_set<int> a;
	std::unordered_set<int> a;
	/*constexpr int length = 10;
	int hehe[getSum(2, 3)] = {10};
	std::cout << sizeof(hehe) << std::endl;
	std::cout << hehe[0] << std::endl;*/
	Base* base1 = new Base();
	Base* base2 = new Base();
	Base* derived1 = new Derived();
	Derived* derived2 = new Derived();

	typedef void(*Func)(void);

	long long* pvptr1 = (long long*)base1;
	long long* vptr1 = (long long*)*pvptr1;
	std::cout << "Base1 vptr is: " << vptr1 << " and value is: " << vptr1[0] << std::endl;
	Func func1 = (Func)vptr1[0];
	func1();
	
	long long* pvptr2 = (long long*)base2;
	long long* vptr2 = (long long*)*pvptr2;
	std::cout << "Base2 vptr is: " << vptr2 << " and value is: " << vptr2[0] << std::endl;
	Func func2 = (Func)vptr2[0];
	func2();

	long long* pvptr3 = (long long*)derived1;
	long long* vptr3 = (long long*)*pvptr3;
	std::cout << "Derived1 vptr is: " << vptr3 << " and value is: " << vptr3[0] << std::endl;
	Func func3 = (Func)vptr3[0];
	func3();

	long long* pvptr4 = (long long*)derived2;
	long long* vptr4 = (long long*)*pvptr4;
	std::cout << "Derived2 vptr is: " << vptr4 << " and value is: " << vptr4[0] << std::endl;
	Func func4 = (Func)vptr4[0];
	func4();

	delete base1;
	delete base2;
	delete derived1;
	delete derived2;


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
