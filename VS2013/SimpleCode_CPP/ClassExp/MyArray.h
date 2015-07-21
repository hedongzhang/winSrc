#pragma once

#include<memory>

template<typename valueType=int, size_t size=10>
class  MyArray
{
public:
	//���캯��
	MyArray()
	{
		this->pValues = new valueType[size];
		this->count = size;
		std::cout << "�������飡" << std::endl;
	};
	//��������
	virtual ~MyArray()
	{
		this->count = 0;
		delete[](this->pValues); 
		std::cout << "�������飡" << std::endl;
	};
	//�������캯��
	MyArray(const MyArray& other)
	{
		delete[](this->pValues);
		this->count = 0;
		this->pValues = new
	};
private:
	//����ָ��
	valueType* pValues;
	//��С
	size_t count;
public:
	//�����±�
	virtual valueType& operator[](size_t currIndex)
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
	virtual operator valueType()
	{
		if (this->count != 0)
		{
			return (*this)[0];
		}
		else
		{
			std::cout <<"����Ϊ�գ�" << std::endl;
			//return *((valueType*)MyArray<valueType, size_t>::);
		}
	};
	//��ӡ
	virtual void print()
	{
		for (size_t i = 0; i < this->count; i++)
		{
			std::cout << (*this)[i] << std::endl;
		}
	};
};



