// Sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

void Swap(int* num1, int* num2);

void quickSort(int* array, int length, int start, int end);

int quickPartition(int* array, int length, int start, int end);

void mergeSort(int* array, int length);

void mergeSort(int* array, int* mergeBuffer, int length, int start, int end);

void merge(int *array, int* mergeBuffer, int leftStart, int leftEnd, int rightEnd);

int main()
{
	int testArray0[10] = { 5,7,6,9,0,4,1,3,2,8 };
	int testArray1[10] = { 5,7,6,9,0,4,1,3,2,8 };
	int testArray2[1] = {1};
	int * testArray3;
	
	quickSort(testArray0, 10, 0, 9);
	for (int i = 0; i < 10; i++) {
		std::cout << testArray0[i];
	}
	std::cout << " quick sort" << std::endl;
	
	mergeSort(testArray1, 10);
	for (int i = 0; i < 10; i++) {
		std::cout << testArray1[i];
	}
	std::cout << " merge sort" << std::endl;

    std::cout << "Hello World!\n";
}

void quickSort(int* array, int length, int start, int end) {
	if (array == nullptr) {
		return;
	}

	if (end <= start) {
		return;
	}

	int index = quickPartition(array, length, start, end);
	quickSort(array, length, start, index - 1);
	quickSort(array, length, index + 1, end);
}

int quickPartition(int* data, int length, int start, int end) {
	if (data==nullptr || length <= 0 ||start < 0|| end >= length) {
		throw new std::exception("Invalid Parameters");
	}

	int randomIndex = rand() % (end - start + 1) + start;
	Swap(&data[randomIndex], &data[end]);
	int small = start - 1;
	for (int i = start; i < end; i++) {
		if (data[i] < data[end]) {
			small++;
			if (data[small] != data[i]) {
				Swap(&data[small], &data[i]);
			}
			
		}
	}
	small++;
	Swap(&data[small], &data[end]);
	//std::cout << small << std::endl;
	return small;
}

void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void mergeSort(int* array, int length) {
	if (array == nullptr || length < 0) {
		return;
	}
	int * mergeBuffer = new int[length]();
	mergeSort(array, mergeBuffer, length, 0, length-1);
	delete[] mergeBuffer;
}

void mergeSort(int* array, int* mergeBuffer, int length, int start, int end) {
	
	
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(array, mergeBuffer, length, start, mid);
		mergeSort(array, mergeBuffer, length, mid + 1, end);
		merge(array, mergeBuffer, start, mid, end);
	}
}

void merge(int *array, int* mergeBuffer, int leftStart, int leftEnd, int rightEnd) {
	if (array == nullptr || leftStart < 0 || leftEnd < 0 || rightEnd < 0) {
		throw new std::exception("Invalid parameter input");
	}
	int rightStart = leftEnd + 1;
	int bufferIndex = leftStart;
	int i = leftStart;
	int j = rightStart;
	while (i <= leftEnd && j <= rightEnd) {
		if (array[i] < array[j]) {
			mergeBuffer[bufferIndex++] = array[i++];
		}
		else {
			mergeBuffer[bufferIndex++] = array[j++];
		}
	}
	while (i <= leftEnd) {
		mergeBuffer[bufferIndex++] = array[i++];
	}
	while (j <= rightEnd) {
		mergeBuffer[bufferIndex++] = array[j++];
	}
	
	for (int k = leftStart; k <= rightEnd; k++) {
		array[k] = mergeBuffer[k];
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
