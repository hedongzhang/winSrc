#include<iostream>
#include<stack>
#include<queue>
#include"hdtree.h"

using namespace std;

template<class T>
hdtree_node<T>::hdtree_node(T value) :data(value)
{
	this->right_node = nullptr;
	this->left_node = nullptr;
}

template<class T>
void print(hdtree_node<T>* p_hdtree_node, int type)
{
	switch (type)
	{
	case 1:
		printF<T>(p_hdtree_node);
		break;
	case 2:
		printM<T>(p_hdtree_node);
		break;
	case 3:
		printB<T>(p_hdtree_node);
		break;
	case 4:
		printL<T>(p_hdtree_node);
		break;
	default:
		printD<T>(p_hdtree_node);
		break;
	}
}


template<class T>
void printF(hdtree_node<T>* p_hdtree_node)
{
	if (p_hdtree_node != nullptr)
	{
		cout << p_hdtree_node->data << endl;
		printF(p_hdtree_node->left_node);
		printF(p_hdtree_node->right_node);
	}
}

template<class T>
void printM(hdtree_node<T>* p_hdtree_node)
{
	if (p_hdtree_node != nullptr)
	{
		printM(p_hdtree_node->left_node);
		cout << p_hdtree_node->data << endl;
		printM(p_hdtree_node->right_node);
	}
}

template<class T>
void printB(hdtree_node<T>* p_hdtree_node)
{
	if (p_hdtree_node != nullptr)
	{
		printB(p_hdtree_node->left_node);
		printB(p_hdtree_node->right_node);
		cout << p_hdtree_node->data << endl;
	}
}

//层次遍历
template<class T>
void printL(hdtree_node<T>* p_hdtree_node)
{
	if (p_hdtree_node != nullptr)
	{
		queue<hdtree_node<T>*> queue_data;
		queue_data.push(p_hdtree_node);
		while (!queue_data.empty())
		{
			hdtree_node<T>* p_temp=queue_data.front();
			queue_data.pop();
			cout << p_temp->data<<endl;
			if (p_temp->left_node != nullptr)
			{
				queue_data.push(p_temp->left_node);
			}
			if (p_temp->right_node != nullptr)
			{
				queue_data.push(p_temp->right_node);
			}
		}
	}
	
}
//默认遍历
template<class T>
void printD(hdtree_node<T>* p_hdtree_node, int layer)
{
	if (p_hdtree_node != nullptr)
	{
		printD(p_hdtree_node->left_node, layer + 1);
		for (size_t i = 0; i < layer; i++)
		{
			cout << "  ";
		}
		cout << p_hdtree_node->data<<endl;
		printD(p_hdtree_node->right_node, layer + 1);
	}
}
//非递归

//先序遍历
template<class T>
void print_stack_F(hdtree_node<T>* p_hdtree_node)
{
	stack<hdtree_node<T>*> data_stack;
	if (p_hdtree_node != nullptr)
	{
		data_stack.push(p_hdtree_node);
		while (!data_stack.empty())
		{
			p_hdtree_node = data_stack.top();
			cout << p_hdtree_node->data << endl;
			data_stack.pop();
			if (p_hdtree_node->right_node!=nullptr)
			data_stack.push(p_hdtree_node->right_node);
			if (p_hdtree_node->left_node != nullptr)
			data_stack.push(p_hdtree_node->left_node);
		}
	}
}

//中序遍历
template<class T>
void print_stack_M(hdtree_node<T>* p_hdtree_node)
{
	stack<hdtree_node<T>*> data_stack;
	while (p_hdtree_node != nullptr || !data_stack.empty())
	{
		while (p_hdtree_node != nullptr)
		{
			data_stack.push(p_hdtree_node);
			p_hdtree_node = p_hdtree_node->left_node;
		}
		if (!data_stack.empty())
		{
			p_hdtree_node = data_stack.top();
			cout << p_hdtree_node->data << endl;
			data_stack.pop();
			p_hdtree_node = p_hdtree_node->right_node;
		}
	}
}


//默认构建树
template<class T>
void insert(hdtree_node<T>** pp_hdtree_node, T value[], int length)
{
	for (size_t i = 0; i < length; i++)
	{
		insert(pp_hdtree_node, value[i]);
	}
}
template<class T>
void insert(hdtree_node<T>** pp_hdtree_node, T value)
{
	/*if (*pp_hdtree_node == nullptr)
	{
		*pp_hdtree_node = new hdtree_node<T>(value);
	}
	else
	{
		if ()
		insert_sort(&((*pp_hdtree_node)->left_node), value);
		insert_sort(&((*pp_hdtree_node)->right_node), value);
	}*/
}


//二叉排序树
template<class T>
int insert_sort(hdtree_node<T>** pp_hdtree_node, T value[], int length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (insert_sort(pp_hdtree_node, value[i]) < 0)
		{
			return -1;
		}
	}
	return 1;
}
template<class T>
int insert_sort(hdtree_node<T>** pp_hdtree_node, T value)
{
	if (*pp_hdtree_node == nullptr)
	{
		*pp_hdtree_node = new hdtree_node<T>(value);
		return 1;
	}
	else
	{
		if ((*pp_hdtree_node)->data > value)
		{
			return insert_sort(&((*pp_hdtree_node)->left_node), value);
		}
		else if ((*pp_hdtree_node)->data < value)
		{
			return insert_sort(&((*pp_hdtree_node)->right_node), value);
		}
		else
		{
			return -1;
		}
	}
}
template<class T>
hdtree_node<T>* find_sort(hdtree_node<T>* p_hdtree_node, T value)
{
	if (p_hdtree_node == nullptr)
	{
		return nullptr;
	}
	else
	{
		if (p_hdtree_node->data == value)
		{
			return p_hdtree_node;
		}
		else if (p_hdtree_node->data > value)
		{
			return find_sort(p_hdtree_node->left_node, value);
		}
		else if (p_hdtree_node->data < value)
		{
			return find_sort(p_hdtree_node->right_node, value);
		}
	}
}
template<class T>
int delete_sort(hdtree_node<T>** pp_hdtree_node, T value)
{
	if (*pp_hdtree_node == nullptr)
	{
		return 1;
	}
	else
	{
		if ((*pp_hdtree_node)->data == value)
		{
			return delete_sort_atom(pp_hdtree_node);
		}
		else if ((*pp_hdtree_node)->data > value)
		{
			return delete_sort(&(*pp_hdtree_node)->left_node, value);
		}
		else if ((*pp_hdtree_node)->data < value)
		{
			return delete_sort(&(*pp_hdtree_node)->right_node, value);
		}
	}
}
template<class T>
int delete_sort_atom(hdtree_node<T>** pp_hdtree_node)
{
	if ((*pp_hdtree_node)->left_node == nullptr && (*pp_hdtree_node)->right_node == nullptr)
	{
		delete *pp_hdtree_node;
		*pp_hdtree_node = nullptr;
	}
	else if ((*pp_hdtree_node)->left_node == nullptr)
	{
		*pp_hdtree_node = (*pp_hdtree_node)->right_node;
	}
	else if ((*pp_hdtree_node)->right_node == nullptr)
	{
		*pp_hdtree_node = (*pp_hdtree_node)->left_node;
	}
	else
	{
		hdtree_node<T>** pp_node = &(*pp_hdtree_node)->right_node;
		while ((*pp_node)->left_node != nullptr)
		{
			pp_node = &(*pp_node)->left_node;
		}
		(*pp_hdtree_node)->data = (*pp_node)->data;
		*pp_node = (*pp_node)->right_node;
	}
	return 0;
}

int mainTREE()
{
	int data[17] = { 5, 2,1,4,3, 19, 6, 8, 7, 30,25,35,21,27,23,22,24 };
	hdtree_node<int>* p_tree = nullptr;
	insert_sort(&p_tree, data, 17);

	print<int>(p_tree, 4);
	print<int>(p_tree, 5);
	cout << endl;

	

	delete_sort(&p_tree, 5);

	print<int>(p_tree, 5);


	system("pause");
	return 0;
}



//hdtree_node<int> tree1(1);
//hdtree_node<int> tree2(2);
//hdtree_node<int> tree3(3);
//hdtree_node<int> tree4(4);
//hdtree_node<int> tree5(5);
//hdtree_node<int> tree6(6);
//hdtree_node<int> tree7(7);
//
//tree1.left_node = &tree2;
//tree1.right_node = &tree3;
//tree2.left_node = &tree4;
//tree2.right_node = &tree5;
//tree3.left_node = &tree6;
//tree3.right_node = &tree7;
//
//print<int>(&tree1, 1);
//cout << endl;
//print<int>(&tree1, 2);
//cout << endl;
//print<int>(&tree1, 3);
//cout << endl;
//print<int>(&tree1, 4);
//cout << endl;
//print<int>(&tree1, 5);
//
//hdtree_node<int>* p_node = find_sort<int>(p_tree, 9);
//if (p_node != nullptr)
//{
//	print<int>(p_node, 5);
//}