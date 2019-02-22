#include "pch.h"
#include "MyStr.h"
#include <string>
#include <iostream>


MyStr::MyStr(const char* _content)
{
	length = strlen(_content);
	content = new char[length + 1];
	strcpy_s(content, length+1, _content);
}


MyStr::MyStr(const MyStr& _myStr)
{
	length = _myStr.length;
	content = new char[length + 1];
	strcpy_s(content, length + 1, _myStr.content);
}

MyStr::~MyStr() {
	delete[] content;
}

const MyStr MyStr::operator+ (const MyStr& str) const{
	int resultLength = length + str.length + 1;
	char* temp = new char[resultLength];
	strcpy_s(temp, resultLength, content);
	strcat_s(temp, resultLength, str.content);
	MyStr result = MyStr(temp);
	delete[] temp;
	return result;
}

MyStr& MyStr::operator= (const MyStr& str) {
	if (this != &str) {
		MyStr temp = MyStr(str);

		char * tempContent = content;
		content = temp.content;
		temp.content = tempContent;

		length = temp.length;
	}
	return *this;
}

bool MyStr::operator== (const MyStr& str) const{
	//std::cout << str.length << " " << length << std::endl;
	//std::cout << str.content << " " << content << std::endl;
	//std::cout << strcmp(content, str.content) << std::endl;
	if (str.length == length && strcmp(content, str.content)==0) {
		return true;
	}
	return false;
}

void MyStr::test(MyStr& str) {
	str.length = 1;
}
