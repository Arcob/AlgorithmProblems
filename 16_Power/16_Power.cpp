// 16_Power.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (base == 0 && exponent == 0) {
		g_InvalidInput = false;
		return 1;
	}

	if (base == 0 && exponent < 0) { //0的0次方无意义，0的负数次方会导致求0的倒数也就是除0出错
		g_InvalidInput = true;
		return 0;
	}

	if (base == 0) {
		return 0;
	}

	if (exponent == 0) {
		return 1;
	}

	bool exponentUnderZero = false;
	int unsignedExponent = exponent;
	if (exponent < 0) {
		exponentUnderZero = true;
		unsignedExponent = -exponent;
	}

	double result = PowerWithUnsignedExponent(base, unsignedExponent);
	
	if (exponentUnderZero) {
		result = 1.0 / result;
	}

	return result;
	
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	if (exponent == 0) {
		return 1;
	}
	else if (exponent == 1) {
		return base;
	}
	
	double temp = PowerWithUnsignedExponent(base, exponent / 2);
	double quadTemp = temp * temp;
	
	if (exponent & 1 == 1) {
		return quadTemp * base;
	}
	else {
		return quadTemp;
	}
	
}

bool equal(double num1, double num2) {
	if ((num1 - num2) < 0.0000001 && (num1 - num2) > -0.0000001) {
		return true;
	}
	else {
		return false;
	}
}


// ====================测试代码====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << std::endl;
}

int main(int argc, char* argv[])
{
	// 底数、指数都为正数
	Test("Test1", 2, 3, 8, false);

	// 底数为负数、指数为正数
	Test("Test2", -2, 3, -8, false);

	// 指数为负数
	Test("Test3", 2, -3, 0.125, false);

	// 指数为0
	Test("Test4", 2, 0, 1, false);

	// 底数、指数都为0
	Test("Test5", 0, 0, 1, false);

	// 底数为0、指数为正数
	Test("Test6", 0, 4, 0, false);

	// 底数为0、指数为负数
	Test("Test7", 0, -4, 0, true);

	return 0;
}
