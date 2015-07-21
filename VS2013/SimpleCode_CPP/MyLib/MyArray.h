#pragma once
#include<memory>

template<typename valueType, size_t size>
class  MyArray
{
public:
	//构造函数
	MyArray();
	//析构函数
	~MyArray();
	//拷贝构造函数
	MyArray(const MyArray& other);
private:
	//数组指针
	valueType* pValues;
	//大小
	size_t count;
public:
	//重载下标
	valueType& operator[](size_t currIndex);
	//重载类型转换
	operator valueType();
	//打印
	void print();
};





