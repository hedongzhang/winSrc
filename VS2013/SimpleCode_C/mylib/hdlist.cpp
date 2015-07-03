#define _CRT_SECURE_NO_WARNINGS

#include"hdlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//初始化
int init(Node** ppHeadNode, int size)
{
	if (ppHeadNode != nullptr)
	{
		/*starAddr = (char*)malloc(size*sizeof(char));
		currAddr = starAddr;
		endAddr = starAddr+size;*/
	}
	return 0;
}

//插入尾部
int pushback(Node** ppHeadNode, int num, char* pData)
{
	if (ppHeadNode != nullptr && pData!=nullptr)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->num = num;
		char* pStr = (char*)malloc(sizeof(char)*(strlen(pData)+1));
		strcpy(pStr, pData);
		pNewNode->pStr = pStr;
		pNewNode->pnext = nullptr;

		if (*ppHeadNode == nullptr)
		{
			*ppHeadNode = pNewNode;
		}
		else
		{
			Node* pNodeTemp = (*ppHeadNode);
			while (pNodeTemp->pnext!=nullptr)
			{
				pNodeTemp = pNodeTemp->pnext;
			}
			pNodeTemp->pnext = pNewNode;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

//删除尾部
int deleteback(Node** ppHeadNode)
{
	if (ppHeadNode != nullptr)
	{
		if (*ppHeadNode != nullptr)
		{
			Node* pNode = *ppHeadNode;
			if (pNode->pnext==nullptr)
			{
				free(pNode->pStr);
				free(pNode);
				*ppHeadNode = nullptr;
				return 1;
			}
			while (pNode->pnext->pnext!=nullptr)
			{
				pNode = pNode->pnext;
			}
			free(pNode->pnext->pStr);
			free(pNode->pnext);
			pNode->pnext = nullptr;
			return 1;
		}
	}
		return 0;
}

//删除头部
int deletetop(Node** ppHeadNode)
{
	if (ppHeadNode != nullptr)
	{
		if (*ppHeadNode != nullptr)
		{
			Node* pNode = *ppHeadNode;
			*ppHeadNode = pNode->pnext;
			free(pNode->pStr);
			free(pNode);
			return 1;
		}
	}
	return 0;
}

//查找首个
Node* findFirst(Node* pHeadNode, char* pData)
{
	if (pHeadNode!=nullptr && pData!=nullptr)
	{
		Node* currNode = pHeadNode;
		while (currNode!=nullptr)
		{
			if (strcmp(currNode->pStr,pData)==0)
			{
				return currNode;
			}
			currNode = currNode->pnext;
		}
	}
	return nullptr;
}

//修改首个
int change(Node* pHeadNode, char* pOldValue, char* pNewValue)
{
	if (pHeadNode != nullptr && pOldValue!=nullptr && pNewValue!=nullptr)
	{
		Node* pNode = findFirst(pHeadNode, pOldValue);
		free(pNode->pStr);
		pNode->pStr = (char*)malloc(sizeof(char)*(strlen(pNewValue) + 1));
		strcpy(pNode->pStr, pNewValue);
		return 1;
	}
	return 0;
}

//翻转
int rev(Node** ppHeadNode)
{
	if (ppHeadNode != nullptr && *ppHeadNode != nullptr)
	{
		Node* pCurrOldNode = *ppHeadNode;
		Node* pCurrNewNode = nullptr;

		while (pCurrOldNode)
		{
			Node* pTempNode = pCurrOldNode->pnext;
			pCurrOldNode->pnext = pCurrNewNode;
			pCurrNewNode = pCurrOldNode;
			pCurrOldNode = pTempNode;
		}
		*ppHeadNode = pCurrNewNode;
		return 1;
	}
	return 0;
}

//插入
int insert(Node* pHeadNode, int num, char* pValue)
{
	if (pHeadNode != nullptr && pValue!=nullptr)
	{
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		pNewNode->num = num;
		char* pStr = (char*)malloc(sizeof(char)*(strlen(pValue) + 1));
		strcpy(pStr, pValue);
		pNewNode->pStr = pStr;
		pNewNode->pnext = pHeadNode->pnext;
		pHeadNode->pnext = pNewNode;
		return 1;
	}
	return 0;
}
//删除某值
int remove(Node** ppHeadNode, char* pValue)
{
	if (ppHeadNode != nullptr && *ppHeadNode != nullptr && pValue != nullptr)
	{
		Node* pTempNode = *ppHeadNode;
		if ( strcmp(pTempNode->pStr,pValue)==0)
		{
			*ppHeadNode = pTempNode->pnext;
			return 1;
		}
		while (pTempNode->pnext)
		{
			if (strcmp(pTempNode->pnext->pStr, pValue) == 0)
			{
				pTempNode->pnext = pTempNode->pnext->pnext;
				return 1;
			}
			pTempNode = pTempNode->pnext;
		}
	}
	return 0;
}

//获取最后节点
Node* getEndNode(Node** ppHeadNode)
{
	if (ppHeadNode != nullptr && *ppHeadNode != nullptr)
	{
		Node* pNode = *ppHeadNode;
		while (pNode->pnext!=nullptr)
		{
			pNode = pNode->pnext;
		}
		return pNode;
	}
	return nullptr;
}

//插入排序
int insertSort(Node** ppHeadNode, Node* pNode)
{
	if (ppHeadNode != nullptr)
	{
		if (pNode != nullptr)
		{
			Node* pNewNode = (Node*)malloc(sizeof(Node));
			pNewNode->num = pNode->num;
			char* pStr = (char*)malloc(sizeof(char)*(strlen(pNode->pStr) + 1));
			strcpy(pStr, pNode->pStr);
			pNewNode->pStr = pStr;
			pNewNode->pnext = nullptr;


			if (*ppHeadNode == nullptr)
			{
				*ppHeadNode = pNewNode;
				return insertSort(ppHeadNode, pNode->pnext);
			}
			else
			{
				Node* pCurrNode = *ppHeadNode;
				if (strcmp(pCurrNode->pStr, pNode->pStr) > 0)
				{
					pNewNode->pnext = pCurrNode;
					*ppHeadNode = pNewNode;
					return insertSort(ppHeadNode, pNode->pnext);
				}
				while (pCurrNode->pnext)
				{
					if (strcmp(pCurrNode->pnext->pStr, pNode->pStr) > 0)
					{
						pNewNode->pnext = pCurrNode->pnext;
						pCurrNode->pnext = pNewNode;
						return insertSort(ppHeadNode, pNode->pnext);
					}
					pCurrNode = pCurrNode->pnext;
				}
				pCurrNode->pnext = pNewNode;
				return insertSort(ppHeadNode, pNode->pnext);
			}
			return 1;
		}
		return 0;
	}
	return 0;
}

int printList(Node* pHeadNode)
{
	if (pHeadNode!=nullptr)
	{
		Node* pNode = pHeadNode;
		while (pNode != nullptr)
		{
			printf("%d : %s\n", pNode->num, pNode->pStr);
			pNode = pNode->pnext;
		}
		return 1;
	}
	else
	{
		return 0;
	}
	
}