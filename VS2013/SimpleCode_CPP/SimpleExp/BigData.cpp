#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

#define MAX_SIZE 50000000

class BigNum
{
private:
	char data[MAX_SIZE];
	char* pDataEnd;
	int size;

public:
	//���캯��
	BigNum(const char* pData) :pDataEnd(nullptr), size(0)
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
	BigNum(int intValue) :pDataEnd(nullptr), size(0)
	{
		if (intValue == 0)
		{
			init(1);
			return;
		}
		init(0);
		while (intValue>0 && this->size<MAX_SIZE)
		{
			data[this->size] = intValue % 10+'0';
			intValue /= 10;
			(this->size)++;
		}
		this->pDataEnd = this->data+size-1;
	}
	//�������캯��
	BigNum(const BigNum& other)
	{
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			this->data[i] = other.data[i];
		}
		this->size = other.size;
		this->pDataEnd = this->data + size-1;
	}

	BigNum& operator=(BigNum& other)
	{
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			this->data[i] = other.data[i];
		}
		this->size = other.size;
		this->pDataEnd = this->data + size - 1;
		return *this;
	}

	//��ʼ�����������㣩
	void init(int type)
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
	//��ȡ������λ��
	int getSize()
	{
		return this->size;
	}

public:
	//�Ƚϴ�С
	int cmp(BigNum& otherNum)
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

			while ( (myCurrPtr + 1) != this->data && (otherCurrPtr+1)!=otherNum.data)
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
	bool operator >(BigNum& otherNum)
	{
		if (this->cmp(otherNum) > 0)
		{
			return true;
		}
		return false;
	}
	
	//���
	void add(BigNum& otherNum)
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
		if (this->size < MAX_SIZE && jinwei!=0)
		{
			*(this->pDataEnd) = jinwei + '0';
		}
		else
		{
			--(this->pDataEnd);
			this->size--;
		}
	}
	//���
	void sub(BigNum& otherNum)
	{
		if (this->cmp(otherNum) <= 0)
		{
			this->init(1);
		}
		else
		{
			int jiewei = 0;		//��λ
			char* pMyCurrPtr = this->data;
			char* pOtherCurrPtr = otherNum.data;
			while (pMyCurrPtr!=this->pDataEnd+1)
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
	BigNum operator--()
	{
		BigNum tempNum(1);
		this->sub(tempNum);
		return *this;
	}
	//���
	void mul(BigNum& otherNum)
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
	void mulBase(char*  pData, char* pStartPos, char* currChar)
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

	//���
	void div(BigNum& otherNum)
	{
		if (this->size < otherNum.size)
		{
			init(1);
		}
		else
		{

		}
			
	}

	//�׳�
	static BigNum factorial(BigNum startNum, BigNum countNum)
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

	void print()
	{
		char* pCurrPtr = this->pDataEnd;
		while (pCurrPtr != this->data - 1)
		{
			cout << *pCurrPtr--;
		}
		cout << endl;
	}
};



void main()
{
	char mod = 0;
	
	while (mod != '0')
	{
		cout << "��ѡ��ģʽ======<<  �ӣ�+������-���ˣ�*������/���׳ˣ������˳���0 >>======\n\n";
		cin >> mod;
		cout << endl;

		string value1;
		string value2;
		cout << "�����һ������";
		cin >> value1;
		cout << "����ڶ�������";
		cin >> value2;

		BigNum bigNum1(value1.c_str());
		BigNum bigNum2(value2.c_str());

		if (mod == '+')
		{
			bigNum1.add(bigNum2);
			cout << "���";
		}
		else if (mod == '-')
		{
			bigNum1.sub(bigNum2);
			cout << "���";
		}
		else if (mod == '*')
		{
			bigNum1.mul(bigNum2);
			cout << "���";
		}
		else if (mod == '/')
		{
			bigNum1.div(bigNum2);
			cout << "���";
		}
		else if(mod == '!')
		{
			bigNum1 = BigNum::factorial(bigNum1, bigNum2);
			cout << "�׳�";
		}
		else
		{
			continue;
		}
		
		cout << "����ǣ�"<<endl;
		bigNum1.print();
		cout << "λ���ǣ�";
		cout << bigNum1.getSize();
		cout << endl;
	}

	
	/*//�����׳�
	BigNum bigNum1 = BigNum::factorial(1000);
	bigNum1.print();
	cout << bigNum1.getSize() << endl;*/

	system("pause");
}