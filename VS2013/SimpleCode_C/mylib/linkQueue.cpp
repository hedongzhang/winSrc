#define  _CRT_SECURE_NO_WARNINGS
#include"linkQueue.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

//初始化LinkQueue
int init(LinkQueue* myLinkQueue)
{
	if (myLinkQueue != nullptr)
	{
		while (myLinkQueue->pHeadNode != nullptr)
		{
			char temp[MAX_STR_SIZE] = { 0 };
			pop(myLinkQueue, temp);
		}
		myLinkQueue->topNode = nullptr;
		return 1;
	}
	else
	{
		return 0;
	}
}

//队列是否为空
bool empty(LinkQueue* myLinkQueue)
{
	if (myLinkQueue != nullptr)
	{
		if (myLinkQueue->topNode != nullptr)
		{
			return 0;
		}
	}
	return 1;
}

//压入队列
int push(LinkQueue* myLinkQueue, char* value, int layer)
{
	if (myLinkQueue != nullptr && value != nullptr)
	{
		if (myLinkQueue->pHeadNode == nullptr)
		{
			pushback(&myLinkQueue->pHeadNode, layer, value);
			myLinkQueue->topNode = myLinkQueue->pHeadNode;
		}
		else
		{
			Node* pCurrNode = myLinkQueue->pHeadNode;
			if (pCurrNode->num < layer)
			{
				Node* pNewNode = (Node*)malloc(sizeof(Node));
				pNewNode->num = layer;
				char* pStr = (char*)malloc(sizeof(char)*(strlen(value) + 1));
				strcpy(pStr, value);
				pNewNode->pStr = pStr;
				pNewNode->pnext = myLinkQueue->pHeadNode;
				myLinkQueue->pHeadNode = pNewNode;

				return 1;
			}
			while (pCurrNode->pnext!=nullptr)
			{
				if (pCurrNode->pnext->num<layer)
				{
					break;
				}
				pCurrNode = pCurrNode->pnext;
			}
			insert(pCurrNode, layer, value);
			if (pCurrNode->pnext->pnext==nullptr)
			{
				myLinkQueue->topNode = pCurrNode->pnext;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

//弹出队列
int pop(LinkQueue* myLinkQueue, char* value)
{
	if (myLinkQueue != nullptr && value != nullptr)
	{
		if (myLinkQueue->topNode != nullptr)
		{
			strcpy(value, myLinkQueue->pHeadNode->pStr);
			if (myLinkQueue->topNode == myLinkQueue->pHeadNode)
			{
				myLinkQueue->topNode = nullptr;
			}
			deletetop(&myLinkQueue->pHeadNode);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

//获取队列尾值
int end(LinkQueue* myLinkQueue, char* value)
{
	if (myLinkQueue != nullptr && value != nullptr)
	{
		if (myLinkQueue->topNode != nullptr)
		{
			strcpy(value, getEndNode(&myLinkQueue->pHeadNode)->pStr);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

//从底到上打印队列数据
void print(LinkQueue* myLinkQueue)
{
	if (myLinkQueue != nullptr)
	{
		if (myLinkQueue->topNode != nullptr)
		{
			Node* pNode = myLinkQueue->pHeadNode;
			while (pNode != nullptr)
			{
				printf("%d->:%s\n", pNode->num, pNode->pStr);
				pNode = pNode->pnext;
			}
		}
	}
}