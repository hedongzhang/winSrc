#pragma once

#include "MyArray.h"
#include<memory>

//���캯��
template<typename valueType, size_t size>
MyArray<valueType, size>::MyArray()
{
	this->pValues = new valueType[size];
	this->count = size;
	std::cout << "�������飡" << std::endl;
};
//��������
template<typename valueType, size_t size>
MyArray<valueType, size>::~MyArray()
{
	this->count = 0;
	delete[](this->pValues);
	std::cout << "�������飡" << std::endl;
};
//�������캯��
template<typename valueType, size_t size>
MyArray<valueType, size>::MyArray(const MyArray& other)
{
	delete[](this->pValues);
	this->count = 0;
	this->pValues = new
};
//�����±�
template<typename valueType, size_t size>
valueType& MyArray<valueType, size>::operator[](size_t currIndex)
{
	if (currIndex < this->count)
	{
		return *(this->pValues + currIndex);
	}
	else
	{
		std::cout << "�������Խ�磡" << std::endl;
		//return *((valueType*)MyArray<valueType, size_t>::);
	}
};
//��������ת��
template<typename valueType, size_t size>
MyArray<valueType, size>::operator valueType()
{
	if (this->count != 0)
	{
		return (*this)[0];
	}
	else
	{
		std::cout << "����Ϊ�գ�" << std::endl;
		//return *((valueType*)MyArray<valueType, size_t>::);
	}
};
//��ӡ
template<typename valueType, size_t size>
void MyArray<valueType, size>::print()
{
	for (size_t i = 0; i < this->count; i++)
	{
		std::cout << (*this)[i] << std::endl;
	}
};

