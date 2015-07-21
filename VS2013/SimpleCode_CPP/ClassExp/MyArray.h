#pragma once

#include<memory>

template<typename valueType=int, size_t size=10>
class  MyArray
{
public:
	//构造函数
	MyArray()
	{
		this->pValues = new valueType[size];
		this->count = size;
		std::cout << "构造数组！" << std::endl;
	};
	//析构函数
	virtual ~MyArray()
	{
		this->count = 0;
		delete[](this->pValues); 
		std::cout << "析构数组！" << std::endl;
	};
	//拷贝构造函数
	MyArray(const MyArray& other)
	{
		delete[](this->pValues);
		this->count = 0;
		this->pValues = new
	};
private:
	//数组指针
	valueType* pValues;
	//大小
	size_t count;
public:
	//重载下标
	virtual valueType& operator[](size_t currIndex)
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
	virtual operator valueType()
	{
		if (this->count != 0)
		{
			return (*this)[0];
		}
		else
		{
			std::cout <<"数组为空！" << std::endl;
			//return *((valueType*)MyArray<valueType, size_t>::);
		}
	};
	//打印
	virtual void print()
	{
		for (size_t i = 0; i < this->count; i++)
		{
			std::cout << (*this)[i] << std::endl;
		}
	};
};



