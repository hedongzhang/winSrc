#pragma once

#include "MyArray.h"
#include<memory>

//构造函数
template<typename valueType, size_t size>
MyArray<valueType, size>::MyArray()
{
	this->pValues = new valueType[size];
	this->count = size;
	std::cout << "构造数组！" << std::endl;
};
//析构函数
template<typename valueType, size_t size>
MyArray<valueType, size>::~MyArray()
{
	this->count = 0;
	delete[](this->pValues);
	std::cout << "析构数组！" << std::endl;
};
//拷贝构造函数
template<typename valueType, size_t size>
MyArray<valueType, size>::MyArray(const MyArray& other)
{
	delete[](this->pValues);
	this->count = 0;
	this->pValues = new
};
//重载下标
template<typename valueType, size_t size>
valueType& MyArray<valueType, size>::operator[](size_t currIndex)
{
	if (currIndex < this->count)
	{
		return *(this->pValues + currIndex);
	}
	else
	{
		std::cout << "数组访问越界！" << std::endl;
		//return *((valueType*)MyArray<valueType, size_t>::);
	}
};
//重载类型转换
template<typename valueType, size_t size>
MyArray<valueType, size>::operator valueType()
{
	if (this->count != 0)
	{
		return (*this)[0];
	}
	else
	{
		std::cout << "数组为空！" << std::endl;
		//return *((valueType*)MyArray<valueType, size_t>::);
	}
};
//打印
template<typename valueType, size_t size>
void MyArray<valueType, size>::print()
{
	for (size_t i = 0; i < this->count; i++)
	{
		std::cout << (*this)[i] << std::endl;
	}
};

