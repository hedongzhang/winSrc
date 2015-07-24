#define  _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
#include<string>
using namespace std;

#define MAX_SIZE 10000

class BigNum
{
private:
	char data[MAX_SIZE];
	char* pDataEnd;
	int size;

public:
	//构造函数
	BigNum(const char* pData);
	BigNum(int intValue);
	//拷贝构造函数
	BigNum(const BigNum& other);

	BigNum& operator=(BigNum& other);

	//初始化（数据置零）
	void init(int type);
	//获取大数的位数
	int getSize();

public:
	//比较大小
	int cmp(BigNum& otherNum);
	bool operator >(BigNum& otherNum);

	//相加
	void add(BigNum& otherNum);
	BigNum operator++();
	//相减
	void sub(BigNum& otherNum);
	BigNum operator--();
	//相乘
	void mul(BigNum& otherNum);
	void mulBase(char*  pData, char* pStartPos, char* currChar);

	//相除
	void div(BigNum& otherNum);

	//阶乘
	static BigNum factorial(BigNum startNum, BigNum countNum);

	void print();
};



