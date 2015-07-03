#define  _CRT_SECURE_NO_WARNINGS

#include"linkStack.h"
#include<string.h>
#include<stdio.h>

//��ʼ��LinkStack
int init(LinkStack* myLinkStack)
{
	if (myLinkStack != nullptr)
	{
		while (myLinkStack->pHeadNode != nullptr)
		{
			char temp[MAX_STR_SIZE] = {0};
			pop(myLinkStack, temp);
		} 
		myLinkStack->topNode = nullptr;
		return 1;
	}
	else
	{
		return 0;
	}
}

//ջ�Ƿ�Ϊ��
bool empty(LinkStack* myLinkStack)
{
	if (myLinkStack != nullptr)
	{
		if (myLinkStack->topNode != nullptr)
		{
			return 0;
		}
	}
	return 1;
}

//ѹ��ջ
int push(LinkStack* myLinkStack, char* value)
{
	if (myLinkStack != nullptr && value!=nullptr)
	{
		if (myLinkStack->pHeadNode==nullptr)
		{
			pushback(&myLinkStack->pHeadNode, 1, value);
			myLinkStack->topNode = myLinkStack->pHeadNode;
		}
		else
		{
			pushback(&myLinkStack->topNode, myLinkStack->topNode->num+1, value);
			myLinkStack->topNode = myLinkStack->topNode->pnext;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

//����ջ
int pop(LinkStack* myLinkStack, char* value)
{
	if (myLinkStack != nullptr && value != nullptr)
	{
		if (myLinkStack->topNode!=nullptr)
		{
			strcpy(value,getEndNode(&myLinkStack->pHeadNode)->pStr);
			deleteback(&myLinkStack->pHeadNode);
			myLinkStack->topNode = getEndNode(&myLinkStack->pHeadNode);
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

//��ȡջ��ֵ
int top(LinkStack* myLinkStack, char* value)
{
	if (myLinkStack != nullptr && value != nullptr)
	{
		if (myLinkStack->topNode != nullptr)
		{
			strcpy(value, getEndNode(&myLinkStack->pHeadNode)->pStr);
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

//�ӵ׵��ϴ�ӡջ����
void print(LinkStack* myLinkStack)
{
	if (myLinkStack != nullptr)
	{
		if (myLinkStack->topNode!=nullptr)
		{
			Node* pNode = myLinkStack->pHeadNode;
			while (pNode!=nullptr)
			{
				printf("%d->:%s\n", pNode->num, pNode->pStr);
				pNode = pNode->pnext;
			}
		}
	}
}