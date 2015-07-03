#ifndef LINKSTACK_H
#define LINKSTACK_H

#include"hdlist.h"

struct LinkStack
{
	Node* pHeadNode;
	Node* topNode;
};

#define MAX_STR_SIZE 256

//初始化LinkStack
int init(LinkStack* myLinkStack);

//栈是否为空
bool empty(LinkStack* myLinkStack);

//压入栈
int push(LinkStack* myLinkStack, char* value);

//弹出栈
int pop(LinkStack* myLinkStack,char* value);

//获取栈顶值
int top(LinkStack* myLinkStack, char* value);

//从底到上打印栈数据
void print(LinkStack* myLinkStack);

#endif //LINKSTACK_H