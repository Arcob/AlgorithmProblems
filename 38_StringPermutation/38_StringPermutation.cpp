// 38_StringPermutation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include "pch.h"
#include <iostream>
#include <cstdio>

void swap(char * a, char* b);

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
	if (pStr == nullptr)
		return;

	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	}
	else {
		char * tempPtr = pBegin;
		while (*tempPtr != '\0') {
			swap(pBegin, tempPtr);
			Permutation(pStr, pBegin + 1);
			swap(pBegin, tempPtr);
			tempPtr++;
		}
	}
}

void swap(char * a, char* b) {
	char temp = *b;
	*b = *a;
	*a = temp;
}

// ====================测试代码====================
void Test(char* pStr)
{
	if (pStr == nullptr)
		printf("Test for nullptr begins:\n");
	else
		printf("Test for %s begins:\n", pStr);

	Permutation(pStr);

	printf("\n");
}

int main(int argc, char* argv[])
{
	Test(nullptr);

	char string1[] = "";
	Test(string1);

	char string2[] = "a";
	Test(string2);

	char string3[] = "ab";
	Test(string3);

	char string4[] = "abc";
	Test(string4);

	return 0;
}