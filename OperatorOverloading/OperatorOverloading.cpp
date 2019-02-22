// OperatorOverloading.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "MyStr.h"

void test(const char* name, bool equal, bool expected);
void test(const char* name, MyStr equal, char* expected);

int main()
{
	MyStr myStr1 = MyStr("test1");
	MyStr myStr2 = MyStr("test2");
	MyStr myStrSame1 = MyStr("test1");
	MyStr myStrEmpty = MyStr("");
	MyStr myStrAdd = MyStr("test1test2");
	char* testStr = new char[6];
	strcpy_s(testStr, 6, "test1");
	MyStr myStr3 = MyStr(testStr);

	test("test1", myStr1 == myStr2, false);
	test("test2", myStr1 == myStrSame1, true);
	test("test3", myStr1 == myStr1, true);
	test("test4", myStr1 == myStr3, true);
	test("test5", myStr2 == myStr3, false);
	//std::cout << (myStr1 + myStr2) << std::endl;
	test("test6", (myStr1 + myStr2 + myStrEmpty) == myStrAdd, true);
	test("test7", (myStr1 + myStr2) == myStr1, false);
	MyStr myStrTest1 = MyStr("none");
	MyStr myStrTest2 = MyStr("none");
	myStrTest1 = myStr1;
	(myStrTest2 = myStr2) = myStr1;
	test("test8", myStrTest1 == myStr1, true);
	test("test9", myStrTest2 == myStr1, true);
	test("test10", myStrTest2 == myStr2, false);
	system("pause");
}

void test(const char* name, bool equal, bool expected) {
	if (equal == expected) {
		std::cout << name << " passed" << std::endl;
	}
	else {
		std::cout << name << " failed" << std::endl;
	}
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
