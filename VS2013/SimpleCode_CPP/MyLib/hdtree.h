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

//打印树
//1、先序	2、中序	3、后序	4、层次	5、树状
template<class T>
void print(hdtree_node<T>* p_hdtree_node, int type);

//默认构建树
template<class T>
void insert(hdtree_node<T>** pp_hdtree_node, T value[], int length);
template<class T>
void insert(hdtree_node<T>** pp_hdtree_node, T value);

//二叉排序树
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

//递归

//先序遍历
template<class T>
void printF(hdtree_node<T>* p_hdtree_node);
//中序遍历
template<class T>
void printM(hdtree_node<T>* p_hdtree_node);
//后序遍历
template<class T>
void printB(hdtree_node<T>* p_hdtree_node);
//层次遍历
template<class T>
void printL(hdtree_node<T>* p_hdtree_node);
//默认遍历
template<class T>
void printD(hdtree_node<T>* p_hdtree_node, int layer = 0);

//非递归

//先序遍历
template<class T>
void print_stack_F(hdtree_node<T>* p_hdtree_node);

//中序遍历
template<class T>
void print_stack_M(hdtree_node<T>* p_hdtree_node);

#endif
