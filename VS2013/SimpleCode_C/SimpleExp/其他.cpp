#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<locale>
#include<stdarg.h>
#include<time.h>
#include<iostream>

using namespace std;

//������
#define SWAP(a,b) (a)^=(b) ; (b)^=(a); (a)^=(b);

//�����
void zuheshu(int* data, int size, int num, int* que, int currNum)
{
	if (currNum == num)
	{
		printf("\n");
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		size_t j = 0;
		for (; j < currNum; j++)
		{
			if (i == que[j])
			{
				break;
			}
		}
		if (j == currNum)
		{
			que[currNum] = i;
			printf("%d->", i);
			zuheshu(data, size, num, que, currNum + 1);
		}
	}
}

//�ڴ�СΪ�̶��ķ����ϴ�һ�����ߵ����һ��Ĳ���
int mun = 0;
void zou(int x, int y, int size)
{
	int n = size - 1;
	if (x == n && y == n)
	{
		mun++;
		return;
	}
	if (x < n)
	{
		zou(x + 1, y, size);
	}
	if (y < n)
	{
		zou(x, y + 1, size);
	}
}

//�ݹ����
double sum(double count)
{
	if (count < 1)
	{
		return 0;
	}
	else
	{
		double temp = 0.5 / count;
		return  temp + sum(count - 1);
	}
}

//��ʱ
int main()
{
	time_t startTime;
	time_t endTime;
	time(&startTime);

	time(&endTime);
	printf("��ʱ��%fs\n", difftime(endTime, startTime));
	system("pause");
}
