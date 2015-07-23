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
	//���캯��
	BigNum(const char* pData);
	BigNum(int intValue);
	//�������캯��
	BigNum(const BigNum& other);

	BigNum& operator=(BigNum& other);

	//��ʼ�����������㣩
	void init(int type);
	//��ȡ������λ��
	int getSize();

public:
	//�Ƚϴ�С
	int cmp(BigNum& otherNum);
	bool operator >(BigNum& otherNum);

	//���
	void add(BigNum& otherNum);
	BigNum operator++();
	//���
	void sub(BigNum& otherNum);
	BigNum operator--();
	//���
	void mul(BigNum& otherNum);
	void mulBase(char*  pData, char* pStartPos, char* currChar);

	//���
	void div(BigNum& otherNum);

	//�׳�
	static BigNum factorial(BigNum startNum, BigNum countNum);

	void print();
};



