// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <cstdio>
#include <iostream>

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
		return;
	
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; i++) {
		resultExclusiveOR ^= data[i];
	}

	unsigned int digit = FindFirstBitIs1(resultExclusiveOR);

	int * slowPtr = data;
	int * fastPtr = data + length - 1;
	//把digit位为1的放在前面，把digit位为0的放在后面
	while (slowPtr < fastPtr) {
		while (IsBit1(*slowPtr, digit) == 1) {
			slowPtr++;
		}
		while (IsBit1(*fastPtr, digit) == 0) {
			fastPtr--;
		}

		if (slowPtr > fastPtr) {
			break;
		}

		int temp = *slowPtr;
		*slowPtr = *fastPtr;
		*fastPtr = temp;
	}

	int * slowPtr2 = data;
	int * fastPtr2 = data + length - 1;

	*num1 = 0;
	while (slowPtr2 <= fastPtr) {
		*num1 ^= *slowPtr2;
		slowPtr2++;
	}

	*num2 = 0;
	while (fastPtr2 >= slowPtr) {
		*num2 ^= *fastPtr2;
		fastPtr2--;
	}

}

// 找到num从右边数起第一个是1的位
unsigned int FindFirstBitIs1(int num)
{
	unsigned int result = 0;
	while (num != 0) {
		if ((num & 1) == 1) {
			return result;
		}
		num = num >> 1;
		result++;
	}

	return -1;
}

// 判断数字num的第indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

// ====================测试代码====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result1, result2;
	FindNumsAppearOnce(data, length, &result1, &result2);

	if ((expected1 == result1 && expected2 == result2) ||
		(expected2 == result1 && expected1 == result2))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

void Test1()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
	int data[] = { 4, 6 };
	Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
	int data[] = { 4, 6, 1, 1, 1, 1 };
	Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}