#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>
#include<time.h>

static int now = 0;
static int isSearched = 0;

struct SearchStru
{
	int* startAddr;
	int num;
	int* endAddr;
	int* objAddr;
	int no;
};

void search(void* pVoid)
{
	SearchStru* pSearchStru = (SearchStru*)pVoid;
	int* currValue = (*pSearchStru).startAddr;
	printf("第%d个线程开始查找%d--！\n", (*pSearchStru).no,(*pSearchStru).num );

	while (currValue++ != (*pSearchStru).endAddr)
	{
		if (isSearched == 1)
		{
			//printf("已找到%d--结束第%d个线程！\n", (*pSearchStru).num, (*pSearchStru).no);
			//_endthread();
		}
		if (*currValue == (*pSearchStru).num)
		{
			printf("查找到%d--第%d个线程！\n", (*pSearchStru).num, (*pSearchStru).no);
			(*pSearchStru).objAddr = currValue;
			isSearched = 1;
			_endthread();
		}
	}
	printf("没查找到%d--第%d个线程结束！\n", (*pSearchStru).num, (*pSearchStru).no);
}


void myTime(void* pValue)
{
	while (1)
	{
		Sleep(1000);
		char comm[20] = { 0 };
		char* pComm = comm;
		sprintf(pComm, "title 执行时间为：%d秒", ++now);
		system(pComm);
	}
}

void main3()
{
	time_t timet;
	unsigned int timenum = (unsigned int)time(&timet);
	srand(timenum);
	HANDLE hdl1 = (void*)_beginthread(myTime, 0, NULL);

	int date[1000];
	for (size_t i = 0; i < 1000; i++)
	{
		date[i] = rand()%1000;
	}

	SearchStru earchStru[10] = {0};
	for (size_t i = 0; i < 10; i++)
	{
		earchStru[i].startAddr = date + 100 * i;
		earchStru[i].endAddr = date + 100 * i + 100;
		earchStru[i].num = 348;
		earchStru[i].no = i;
		earchStru[i].objAddr = NULL;

		HANDLE hdl2 = (void*)_beginthread(search, 0,& earchStru[i]);
		//Sleep(10);
	}
	//printf("%d\t%d\n",a,a++);
	system("pause");
}
