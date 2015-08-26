#ifndef hdtree_node_H
#define hdtree_node_H

template<class T>
struct hdtree_node
{
	hdtree_node(T value);

	T data;
	hdtree_node* left_node;
	hdtree_node* right_node;
};

//��ӡ��
//1������	2������	3������	4�����	5����״
template<class T>
void print(hdtree_node<T>* p_hdtree_node, int type);

//Ĭ�Ϲ�����
template<class T>
void insert(hdtree_node<T>** pp_hdtree_node, T value[], int length);
template<class T>
void insert(hdtree_node<T>** pp_hdtree_node, T value);

//����������
template<class T>
int insert_sort(hdtree_node<T>** pp_hdtree_node, T value[], int length);
template<class T>
int insert_sort(hdtree_node<T>** pp_hdtree_node, T value);
template<class T>
hdtree_node<T>* find_sort(hdtree_node<T>* p_hdtree_node, T value);
template<class T>
int delete_sort(hdtree_node<T>** pp_hdtree_node, T value);
template<class T>
int delete_sort_atom(hdtree_node<T>** pp_hdtree_node);

//�ݹ�

//�������
template<class T>
void printF(hdtree_node<T>* p_hdtree_node);
//�������
template<class T>
void printM(hdtree_node<T>* p_hdtree_node);
//�������
template<class T>
void printB(hdtree_node<T>* p_hdtree_node);
//��α���
template<class T>
void printL(hdtree_node<T>* p_hdtree_node);
//Ĭ�ϱ���
template<class T>
void printD(hdtree_node<T>* p_hdtree_node, int layer = 0);

//�ǵݹ�

//�������
template<class T>
void print_stack_F(hdtree_node<T>* p_hdtree_node);

//�������
template<class T>
void print_stack_M(hdtree_node<T>* p_hdtree_node);

#endif
