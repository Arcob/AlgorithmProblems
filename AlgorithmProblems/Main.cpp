#include <iostream>
#include "AllProblems.h"

void duplicate() {
	int numbers0[] = { 2,3,1,0,2,5,3 };//���ظ���ȷ����
	int length0 = sizeof(numbers0) / sizeof(int);

	int numbers1[] = { 2,3,1,0,4,5,6 };//���ظ���ȷ����
	int length1 = sizeof(numbers1) / sizeof(int);

	int numbers2[] = { 2,3,1,0,9,5,3 };//���ַ�Χ��������
	int length2 = sizeof(numbers2) / sizeof(int);

	int* numbers3 = nullptr;//�����ָ��
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
