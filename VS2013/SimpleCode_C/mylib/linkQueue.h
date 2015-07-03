#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include"hdlist.h"

struct LinkQueue
{
	Node* pHeadNode;
	Node* topNode;
};

#define MAX_STR_SIZE 256

//��ʼ��LinkQueue
int init(LinkQueue* myLinkQueue);

//�����Ƿ�Ϊ��
bool empty(LinkQueue* myLinkQueue);

//���(���һ������Ϊ���ȼ�)
int push(LinkQueue* myLinkQueue, char* value,int layer=0);

//����
int pop(LinkQueue* myLinkQueue, char* value);

//��ȡ��βֵ
int end(LinkQueue* myLinkQueue, char* value);

//�Ӷ�ͷ����β��ӡ��������
void print(LinkQueue* myLinkQueue);


#endif //LINKQUEUE_H