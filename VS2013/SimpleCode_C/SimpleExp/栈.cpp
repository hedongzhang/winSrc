#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

//二分法查找
int serch()
{
	const int size = 11;
	int objValue=5;

	time_t time1;
	unsigned int num = time(&time1);
	srand(num);

	int date[size];
	for (size_t i = 0; i < size; i++)
	{
		date[i] = rand() % size;
		printf("%d\n", date[i]);
	}

	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size-1-i; j++)
		{
			if (date[j]>date[j + 1])
			{
				date[j] = date[j + 1] + date[j];
				date[j + 1] = date[j] - date[j + 1];
				date[j] = date[j] - date[j + 1];
			}
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		printf("%d->%d\n", i,date[i]);
	}

	size_t head = 0, tail = size - 1;
	while (head< tail)
	{
		size_t midd = (head + tail) / 2;
		 if (date[midd] == objValue)
		{
			printf("找到了，在%d\n", midd);
			return 1;
		}
		else if (date[midd] < objValue)
		{
			head = midd+1;
		}
		else
		{
			tail = midd-1;
		}
	}
	printf("没找到!\n");
	return 0;
}

//12345 54321
int metho(int num, int metho1)
{
	int newNum = metho1;

	/*do
	{
		newNum *= 10;
		newNum += num % 10;
		num /= 10;
	} while (num > 0);*/

	/*while (num > 0)
	{
		newNum *= 10;
		newNum += num % 10;
		num /= 10;
	}*/

	/*for (size_t i = num; i >0; i/=10)
	{
		newNum *= 10;
		newNum += i % 10;
	}*/

	//L1:
	//{
	//	newNum *= 10;
	//	newNum += num % 10;
	//	num /= 10;
	//}
	//if (num > 0)
	//{
	//	goto L1;
	//}

	newNum *= 10;
	if (num < 10)
	{
		return newNum+num;
	}
	else
	{
		newNum += num % 10;
		return metho(num / 10, newNum);
	}

	return newNum;
}

int ten2two(int i)
{
	if (i==0)
	{
		return i;
	}
	else
	{
		return i % 2 + 10 * ten2two(i / 2);
	}
}

int two2ten(int i)
{
	if (i == 0)
	{
		return i;
	}
	else
	{
		return i % 10 + 2 * two2ten(i / 10);
	}
}

struct MyStack
{
	int top;
	int stack[100];
}myStack{ -1, { 0 } };

int setEmpty()
{
	myStack.top = -1;
	return 0;
}

bool isEmpty()
{
	if (myStack.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int push(int i)
{
	if (myStack.top >= 100)
	{
		return 0;
	}
	else
	{
		myStack.stack[++myStack.top] = i;
	}
	return 1;
}

int pop()
{
	if (myStack.top == -1)
	{
		return 0;
	}
	else
	{
		return myStack.stack[myStack.top--];
	}
}


void main1()
{
	//int num_10;
	//scanf("%d", &num_10);

	/*for (int i = 0; i <= 100; i++)
	{
		int num_10 = i;
		while (num_10>0)
		{
			if (!push(num_10 % 2))
			{
				return;
			}
			num_10 /= 2;
		}

		while (!isEmpty())
		{
			printf("%d", pop());
		}
		printf("\n");
	}*/
	
	int value = 0;
	char numStr[10] = { 0 };
	scanf("%s", numStr);

	int size = 0;
	while (numStr[size]!='\0')
	{
		if (numStr[size] > '9' || numStr[size] < '0' )
		{
			return;
		}
		size++;
	}

	for (size_t i = 0; i < 234; i++)
	{
		int temp = numStr[i] - 48;
		for (size_t j = 1; j < size-i; j++)
		{
			temp *= 10;
		}
		value += temp;
	}


	printf("%d\n", value);
	//printf("%d\n", num/100000);
	system("pause");
}

