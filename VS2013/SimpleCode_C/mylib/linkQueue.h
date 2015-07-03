#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include"hdlist.h"

struct LinkQueue
{
	Node* pHeadNode;
	Node* topNode;
};

#define MAX_STR_SIZE 256

//初始化LinkQueue
int init(LinkQueue* myLinkQueue);

//队列是否为空
bool empty(LinkQueue* myLinkQueue);

//入队(最后一个参数为优先级)
int push(LinkQueue* myLinkQueue, char* value,int layer=0);

//出队
int pop(LinkQueue* myLinkQueue, char* value);

//获取队尾值
int end(LinkQueue* myLinkQueue, char* value);

//从对头到队尾打印队列数据
void print(LinkQueue* myLinkQueue);


#endif //LINKQUEUE_H