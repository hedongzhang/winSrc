#include "BigNum.h"
#include<string>

//构造函数
BigNum::BigNum(const char* pData) :pDataEnd(nullptr), size(0)
{
	//init(0);

	if ((*pData) == '\0')
	{
		return;
	}
	const char* pOtherDataEnd = pData;
	while (*(pOtherDataEnd + 1) != '\0')
	{
		pOtherDataEnd++;
	}

	int index = 0;
	for (; index < MAX_SIZE - 1; index++)
	{
		if (pOtherDataEnd == pData - 1)
		{
			break;
		}
		else if ((*pOtherDataEnd)<'0' || (*pOtherDataEnd)>'9')
		{
			break;
		}
		else
		{
			data[index] = (*pOtherDataEnd);
		}
		pOtherDataEnd--;
	}
	this->pDataEnd = data + index - 1;
	this->size = index;
}
BigNum::BigNum(int intValue) :pDataEnd(nullptr), size(0)
{
	if (intValue == 0)
	{
		init(1);
		return;
	}
	init(0);
	while (intValue>0 && this->size<MAX_SIZE)
	{
		data[this->size] = intValue % 10 + '0';
		intValue /= 10;
		(this->size)++;
	}
	this->pDataEnd = this->data + size - 1;
}
//拷贝构造函数
BigNum::BigNum(const BigNum& other)
{
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->pDataEnd = this->data + size - 1;
}

BigNum& BigNum::operator=(BigNum& other)
{
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->pDataEnd = this->data + size - 1;
	return *this;
}

//初始化（数据置零）
void BigNum::init(int type)
{
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		data[i] = '\0';
	}
	if (type == 0)
	{
		data[0] = '\0';
		this->size = 0;
		this->pDataEnd = this->data;
	}
	else
	{
		data[0] = '0';
		this->size = 1;
		this->pDataEnd = this->data;
	}
}
//获取大数的位数
int BigNum::getSize()
{
	return this->size;
}

//比较大小
int BigNum::cmp(BigNum& otherNum)
{
	if (this->size>otherNum.size)
	{
		return 1;
	}
	else if (this->size<otherNum.size)
	{
		return -1;
	}
	else
	{
		char* myCurrPtr = this->pDataEnd;
		char* otherCurrPtr = otherNum.pDataEnd;

		while ((myCurrPtr + 1) != this->data && (otherCurrPtr + 1) != otherNum.data)
		{
			if ((*myCurrPtr) > (*otherCurrPtr))
			{
				return 1;
			}
			else if ((*myCurrPtr) < (*otherCurrPtr))
			{
				return -1;
			}
			else
			{
				myCurrPtr--;
				otherCurrPtr--;
			}
		}
		return 0;
	}
}
bool BigNum::operator >(BigNum& otherNum)
{
	if (this->cmp(otherNum) > 0)
	{
		return true;
	}
	return false;
}

//相加
void BigNum::add(BigNum& otherNum)
{
	char* pOtherDataEnd = otherNum.data;
	this->pDataEnd = this->data;

	int jinwei = 0;
	this->size = 1;
	while ((*pOtherDataEnd) != '\0' || (*(this->pDataEnd)) != '\0')
	{
		int tempValue = 0;
		if ((*pOtherDataEnd) != '\0')
		{
			tempValue += *pOtherDataEnd - '0';
		}
		if ((*(this->pDataEnd)) != '\0')
		{
			tempValue += *(this->pDataEnd) - '0';
		}
		tempValue += jinwei;
		jinwei = tempValue / 10;
		*(this->pDataEnd) = tempValue % 10 + '0';

		pOtherDataEnd++;
		(this->pDataEnd)++;
		this->size++;
	}
	if (this->size < MAX_SIZE && jinwei != 0)
	{
		*(this->pDataEnd) = jinwei + '0';
	}
	else
	{
		--(this->pDataEnd);
		this->size--;
	}
}
BigNum BigNum::operator++()
{
	BigNum tempNum(1);
	this->add(tempNum);
	return *this;
}
//相减
void BigNum::sub(BigNum& otherNum)
{
	if (this->cmp(otherNum) <= 0)
	{
		this->init(1);
	}
	else
	{
		int jiewei = 0;		//借位
		char* pMyCurrPtr = this->data;
		char* pOtherCurrPtr = otherNum.data;
		while (pMyCurrPtr != this->pDataEnd + 1)
		{
			if (*pOtherCurrPtr != '\0')
			{
				jiewei += *pOtherCurrPtr;
			}
			else
			{
				jiewei += '0';
			}

			if ((*pMyCurrPtr) >= jiewei)
			{
				*pMyCurrPtr = *pMyCurrPtr - jiewei + '0';
				jiewei = 0;
			}
			else
			{
				*pMyCurrPtr = 10 + *pMyCurrPtr - jiewei + '0';
				jiewei = 1;
			}

			pMyCurrPtr++;
			pOtherCurrPtr++;
		}
		while (*this->pDataEnd == '0' && this->pDataEnd>this->data)
		{
			*(this->pDataEnd) = '\0';
			this->pDataEnd--;
			this->size--;
		}
	}
}
BigNum BigNum::operator--()
{
	BigNum tempNum(1);
	this->sub(tempNum);
	return *this;
}
//相乘
void BigNum::mul(BigNum& otherNum)
{
	BigNum tempNum(0);
	if (otherNum > tempNum)
	{
		char* pCurrChar = otherNum.data;
		char tempData[MAX_SIZE + MAX_SIZE] = { 0 };
		char* pTempData = tempData;

		while (*pCurrChar != '\0')
		{
			mulBase(this->data, pTempData++, pCurrChar++);
		}
		//memset(this->data, 0, sizeof(this->data));
		strncpy(this->data, tempData, MAX_SIZE - 1);
		this->size = 0;
		while (this->data[this->size] != '\0')
		{
			this->size++;
		}
		this->pDataEnd = this->data + size - 1;
	}
	else
	{
		init(1);
	}
}
void BigNum::mulBase(char*  pData, char* pStartPos, char* currChar)
{
	int currValue = *currChar - '0';

	int jinwei = 0;
	while (*pData != '\0')
	{
		int tempValue = currValue*(*pData - '0') + jinwei;
		if (*pStartPos != '\0')
		{
			tempValue += *pStartPos - '0';
		}
		jinwei = tempValue / 10;
		*pStartPos++ = tempValue % 10 + '0';
		pData++;
	}
	while (jinwei != 0)
	{
		if (*pStartPos != '\0')
		{
			int tempValue = *pStartPos - '0' + jinwei;
			jinwei = tempValue / 10;
			*pStartPos = tempValue % 10;
		}
		else
		{
			*pStartPos = jinwei + '0';
			jinwei = 0;
		}
	}

}

//相除
void BigNum::div(BigNum& otherNum)
{
	if (this->cmp(otherNum)<0)
	{
		*this = BigNum(0);
	}
	else if (this->cmp(otherNum) == 0)
	{
		*this = BigNum(1);
	}
	else
	{
		BigNum resultNum(1);
		this->sub(otherNum);
		while (this->cmp(otherNum) >= 0)
		{
			this->sub(otherNum);
			++resultNum;
		}
		*this = resultNum;
	}

}

//阶乘
BigNum BigNum::factorial(BigNum startNum, BigNum countNum)
	{
		BigNum tempNum(0);
		BigNum tempMulNum(1);
		while (countNum>tempNum)
		{
			tempMulNum.mul(startNum);
			--startNum;
			--countNum;
			//temp.print();
		}
		//bigNum1.print();
		return tempMulNum;
	}

void BigNum::print()
{
	char* pCurrPtr = this->pDataEnd;
	while (pCurrPtr != this->data - 1)
	{
		cout << *pCurrPtr--;
	}
	cout << endl;
}




void mainBN()
{
	char mod = 0;

	while (mod != '0')
	{
		cout << "请选择模式======<<  加：+、减：-、乘：*、除：/、阶乘：！、退出：0 >>======\n\n";
		cin >> mod;
		if (mod == '0')
		{
			break;
		}
		cout << endl;

		string value1;
		string value2;
		cout << "输入第一个数：";
		cin >> value1;
		cout << "输入第二个数：";
		cin >> value2;

		BigNum bigNum1(value1.c_str());
		BigNum bigNum2(value2.c_str());

		if (mod == '+')
		{
			bigNum1.add(bigNum2);
			cout << "相加";
		}
		else if (mod == '-')
		{
			bigNum1.sub(bigNum2);
			cout << "相减";
		}
		else if (mod == '*')
		{
			bigNum1.mul(bigNum2);
			cout << "相乘";
		}
		else if (mod == '/')
		{
			bigNum1.div(bigNum2);
			cout << "相除";
		}
		else if (mod == '!')
		{
			bigNum1 = BigNum::factorial(bigNum1, bigNum2);
			cout << "阶乘";
		}
		else
		{
			continue;
		}

		cout << "结果是：" << endl;
		bigNum1.print();
		cout << "位数是：";
		cout << bigNum1.getSize();
		cout << endl;
	}


	/*//大数阶乘
	BigNum bigNum1 = BigNum::factorial(1000);
	bigNum1.print();
	cout << bigNum1.getSize() << endl;*/

	system("pause");
}