// TurnMultiTimes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	int turnTime;
	std::cin >> turnTime;
	std::string str;
	std::cin >> str;

	int leftNum = 0;
	int rightNum = 0;

	for (int i = 0; i < turnTime; i++) {
		if (str[i] == 'L') {
			leftNum++;
		}
		else if (str[i] == 'R') {
			rightNum++;
		}
	}

	bool isRight = rightNum > leftNum ? true : false;
	
	int remain = isRight ? (rightNum - leftNum) : (leftNum - rightNum);

	remain = remain % 4;

	char result;
	if (isRight) {
		switch (remain)
		{
		case 0:
			result = 'N';
			break;
		case 1:
			result = 'E';
			break;
		case 2:
			result = 'S';
			break;
		case 3:
			result = 'W';
			break;
		default:
			break;
		}
	}
	else {
		switch (remain)
		{
		case 0:
			result = 'N';
			break;
		case 1:
			result = 'W';
			break;
		case 2:
			result = 'S';
			break;
		case 3:
			result = 'E';
			break;
		default:
			break;
		}
	}

	std::cout << result << std::endl;

	return 0;
}
