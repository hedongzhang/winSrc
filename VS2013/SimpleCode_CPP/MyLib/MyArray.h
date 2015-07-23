#pragma once
#include<memory>

template<typename valueType, size_t size>
class  MyArray
{
public:
	//���캯��
	MyArray();
	//��������
	~MyArray();
	//�������캯��
	MyArray(const MyArray& other);
private:
	//����ָ��
	valueType* pValues;
	//��С
	size_t count;
public:
	//�����±�
	valueType& operator[](size_t currIndex);
	//��������ת��
	operator valueType();
	//��ӡ
	void print();
};





