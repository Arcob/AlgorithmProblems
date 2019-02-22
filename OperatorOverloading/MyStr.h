#pragma once
class MyStr
{
public:
	MyStr(const char* _content);
	MyStr(const MyStr& _myStr);
	~MyStr();

	const MyStr operator+ (const MyStr& str) const;
	MyStr& operator= (const MyStr& str);
	bool operator== (const MyStr& str) const;

	void test (MyStr& str);
private:
	char * content;
	int length;
};

