#ifndef HDLIST_H
#define HDLIST_H

struct Node
{
	int num;
	char* pStr;
	Node* pnext;
};

//初始化
int init(Node** ppHeadNode, int size);

//插入尾部
int pushback(Node** ppHeadNode, int num, char* pData);

//删除尾部
int deleteback(Node** ppHeadNode);

//删除头部
int deletetop(Node** ppHeadNode);

//查找首个节点
Node* findFirst(Node* pHeadNode, char* pData);

//修改首个
int change(Node* pHeadNode, char* pOldValue, char* pNewValue);

//翻转
int rev(Node** ppHeadNode);

//插入某个节点之后
int insert(Node* pHeadNode, int num, char* pValue);

//删除某值
int remove(Node** ppHeadNode, char* pValue);

//获取最后节点
Node* getEndNode(Node** ppHeadNode);

//打印列表
int printList(Node* pHeadNode);


//插入排序
int insertSort(Node** ppHeadNode, Node* pNode);

//打印链表
int printList(Node* pHeadNode);


#endif //HDLIST_H


/*list code
time_t timet;
unsigned int rands = time(&timet);
srand(rands);


Node**  ppHeadNode = (Node**)malloc(sizeof(Node*));
Node**  ppHeadNode1 = (Node**)malloc(sizeof(Node*));
*ppHeadNode = nullptr;
*ppHeadNode1 = nullptr;


for (size_t i = 0; i < 26; i++)
{
char str[10] = { 0};
sprintf(str,"%c",rand()%26+97);
pushback(ppHeadNode, i+1, str);
}

printList(*ppHeadNode);


insertSort(ppHeadNode1, *ppHeadNode);
printList(*ppHeadNode1);

printf("\n");
rev(ppHeadNode1);
printList(*ppHeadNode1);*/

/*char* pStr = "55";
remove(ppHeadNode, pStr);
printList(*ppHeadNode);

Node* pNode = findFirst(*ppHeadNode, "54");
insert(pNode, 55,"55");
printList(*ppHeadNode);*/