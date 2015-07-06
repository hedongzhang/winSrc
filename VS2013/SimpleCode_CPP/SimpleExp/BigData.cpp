#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
using namespace std;

#define MAX_SIZE 20

struct BigNum
{
private:
	char data[MAX_SIZE];
	char* pDataEnd;
	int size;
public:
	BigNum(const char* pData)
	{
		for (size_t i = 0; i < MAX_SIZE; i++)
		{
			data[i] = '\0';
		}

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
		if (this->size < MAX_SIZE)
		{
			*(this->pDataEnd) = jinwei + '0';
		}
		else
		{
			--(this->pDataEnd);
			this->size--;
		}
	}

	void mul(BigNum& otherNum)
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

	void printf()
	{
		char* pCurr = this->pDataEnd;
		while (pCurr != this->data - 1)
		{
			cout << *pCurr--;
		}
		cout << endl;
	}
};



void mainBD()
{
	char mod = 0;
	cout << "请选择模式：加：+、乘：*、退出：0\n";
	cin >> mod;
	cout << endl;
	while (mod != '0')
	{
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
		else if (mod == '*')
		{
			bigNum1.mul(bigNum2);
			cout << "相乘";
		}
		cout << "结果是：";
		bigNum1.printf();
		cout << endl;


		cout << "请选择模式：加：+、乘：*、退出：0";
		cin >> mod;
		cout << endl;
	}

	system("pause");
}