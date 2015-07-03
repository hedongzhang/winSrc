#ifndef HDLIST_H
#define HDLIST_H

struct Node
{
	int num;
	char* pStr;
	Node* pnext;
};

//��ʼ��
int init(Node** ppHeadNode, int size);

//����β��
int pushback(Node** ppHeadNode, int num, char* pData);

//ɾ��β��
int deleteback(Node** ppHeadNode);

//ɾ��ͷ��
int deletetop(Node** ppHeadNode);

//�����׸��ڵ�
Node* findFirst(Node* pHeadNode, char* pData);

//�޸��׸�
int change(Node* pHeadNode, char* pOldValue, char* pNewValue);

//��ת
int rev(Node** ppHeadNode);

//����ĳ���ڵ�֮��
int insert(Node* pHeadNode, int num, char* pValue);

//ɾ��ĳֵ
int remove(Node** ppHeadNode, char* pValue);

//��ȡ���ڵ�
Node* getEndNode(Node** ppHeadNode);

//��ӡ�б�
int printList(Node* pHeadNode);


//��������
int insertSort(Node** ppHeadNode, Node* pNode);

//��ӡ����
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