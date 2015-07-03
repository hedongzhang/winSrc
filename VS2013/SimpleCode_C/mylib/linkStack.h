#ifndef LINKSTACK_H
#define LINKSTACK_H

#include"hdlist.h"

struct LinkStack
{
	Node* pHeadNode;
	Node* topNode;
};

#define MAX_STR_SIZE 256

//��ʼ��LinkStack
int init(LinkStack* myLinkStack);

//ջ�Ƿ�Ϊ��
bool empty(LinkStack* myLinkStack);

//ѹ��ջ
int push(LinkStack* myLinkStack, char* value);

//����ջ
int pop(LinkStack* myLinkStack,char* value);

//��ȡջ��ֵ
int top(LinkStack* myLinkStack, char* value);

//�ӵ׵��ϴ�ӡջ����
void print(LinkStack* myLinkStack);

#endif //LINKSTACK_H