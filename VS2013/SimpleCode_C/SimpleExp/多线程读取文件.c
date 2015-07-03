#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include"hdlist.h"
#include<process.h>

#pragma comment(lib, "mylib.lib")

struct ThreadMes
{
	int startPos;
	int endPos;
	char* key;
	int num;
};

#define DATA_NUM 13180807

char** ppStr = (char**)malloc(sizeof(char*) * DATA_NUM);
ThreadMes pThreadMes[100] = { 0 };
int resultCount = 0;


void find(void * pThreadMes)
{
	ThreadMes* pCurrMes = (ThreadMes*)pThreadMes;
	int currPos = pCurrMes->startPos;
	while (currPos != pCurrMes->endPos)
	{
		if (strstr(ppStr[currPos], pCurrMes->key) != NULL)
		{
			printf("第%d个线程： 【%s】\n", pCurrMes->num, ppStr[currPos]);
			resultCount++;
		}
		currPos++;
	}
}

void beginThread(int num, char* key)
{
	int size = DATA_NUM / num;
	int currIndex = 0;
	int currThreadNum = 0;
	while (currIndex + size<DATA_NUM)
	{
		pThreadMes[currThreadNum].key = key;
		pThreadMes[currThreadNum].startPos = currIndex;
		pThreadMes[currThreadNum].endPos = currIndex + size;
		pThreadMes[currThreadNum].num = currThreadNum + 1;
		currIndex += size;
		_beginthread(find, 0, (void*)(pThreadMes + currThreadNum));
		currThreadNum++;
	}
	pThreadMes[currThreadNum].key = key;
	pThreadMes[currThreadNum].startPos = currIndex;
	pThreadMes[currThreadNum].endPos = DATA_NUM;
	pThreadMes[currThreadNum].num = currThreadNum + 1;
	currIndex += size;
	_beginthread(find, 0, (void*)(pThreadMes + currThreadNum));
}

void main1()
{
	time_t timet;
	unsigned int startTime = time(&timet);

	char* path = "E:\\BaiduYunDownload\\2014传智播客C++第三期更新完毕\\0726\\code\\dangdangwang.txt";
	char* pathGet = "C:\\Users\\HDZhang\\Desktop\\dangdangwang.txt";
	FILE* pFile = fopen(path, "r");
	FILE* pGetFile = fopen(pathGet, "w");


	if (pFile && pGetFile)
	{
		printf("打开文件成功!\n");
		fseek(pFile, 0, SEEK_END);
		int size = ftell(pFile);
		printf("大小： \t%d:B\t%.2f:K\t%.2f:M\t%.2f:G\n", size, size / 1024.0, size / 1024.0 / 1024.0, size / 1024.0 / 1024.0 / 1024.0);
		rewind(pFile);

		int count = 0;
		while (!feof(pFile))
		{
			char buff[275] = { 0 };
			fgets(buff, 275, pFile);
			ppStr[count] = (char*)malloc(sizeof(char)*(strlen(buff) + 1));
			strcpy(ppStr[count++], buff);
		}
		printf("\n载入完成！		总共： %d条\n", count);
		printf("用时： %d秒\n", (time(&timet) - startTime));
	}
	else
	{
		printf("打开文件失败！");
	}
	fclose(pFile);
	fclose(pGetFile);

	char key[64] = { 0 };
	int threadNum = 1;
	printf("\n请输入关键字：");
	scanf("%s", key);
	printf("\n线程数：");
	scanf("%d", &threadNum);
	while (strcmp(key, "-1") != 0)
	{
		//DATA_NUM

		beginThread(threadNum, key);

		printf("\n请输入关键字：");
		scanf("%s", key);
		printf("\n线程数：");
		scanf("%d", &threadNum);
	}



	system("pause");
}


//time_t timet;
//unsigned int startTime = time(&timet);
//
//struct strDef
//{
//	char value[110];
//};
//strDef* ppStr = (strDef*)malloc(sizeof(strDef) * MAX_SIZE);
//
//int count = 0;
//
//char* path = "E:\\BaiduYunDownload\\2014传智播客C++第三期更新完毕\\0726\\code\\dangdangwang.txt";
//char* pathGet = "C:\\Users\\HDZhang\\Desktop\\dangdangwang.txt";
//FILE* pFile = fopen(path, "r");
//FILE* pGetFile = fopen(pathGet, "w");
//if (pFile && pGetFile)
//{
//	printf("打开文件成功!\n");
//	fseek(pFile, 0, SEEK_END);
//	int size = ftell(pFile);
//	fprintf(pGetFile, "大小： \t%d:B\t%.2f:K\t%.2f:M\t%.2f:G\n", size, size / 1024.0, size / 1024.0 / 1024.0, size / 1024.0 / 1024.0 / 1024.0);
//	printf("大小： \t%d:B\t%.2f:K\t%.2f:M\t%.2f:G\n", size, size / 1024.0, size / 1024.0 / 1024.0, size / 1024.0 / 1024.0 / 1024.0);
//	rewind(pFile);
//
//
//	while (!feof(pFile))
//	{
//		if (count < MAX_SIZE)
//		{
//			fgets(ppStr[count++].value, 128, pFile);
//		}
//		else
//		{
//			printf("\n数据溢出！\n", count);
//			system("pause");
//			return;
//		}
//		/*if (strstr(buff, "陈玲") != NULL)
//		{
//		printf("\n%s\n", buff);
//		pushback(ppHeadNode, count, buff);
//		}*/
//	}
//	fprintf(pGetFile, "\n总共： %d条\n", count);
//	printf("\n总共： %d条\n", count);
//	printf("用时： %d秒\n", (time(&timet) - startTime));
//}
//else
//{
//	printf("打开文件失败！");
//}
//fclose(pFile);
//
//
//char buff1[64] = { 0 };
//char buff2[64] = { 0 };
//printf("\n输入关键字：");
//scanf("%s%s", buff1, buff2);
//
//while (strcmp(buff1, "-1") != 0)
//{
//	startTime = time(&timet);
//
//	int size1 = 0;
//	for (size_t i = 0; i < count; i++)
//	{
//		if (strstr(ppStr[i++].value, buff1) != NULL && strstr(ppStr[i - 1].value, buff2) != NULL)
//		{
//			fprintf(pGetFile, "%s\n", ppStr[i - 1].value);
//			printf("%s\n", ppStr[i - 1].value);
//			size1++;
//		}
//	}
//	printf("查找用时:%d秒\n", time(&timet) - startTime);
//	printf("找到:%d条\n", size1);
//
//	printf("\n输入关键字：");
//	scanf("%s%s", buff1, buff2);
//}
//fflush(pGetFile);
//fclose(pGetFile);