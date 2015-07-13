#include<string>
#include <iostream>
#include<memory>

using namespace std;

class parent;
class children;

typedef shared_ptr<parent> parent_ptr;
typedef shared_ptr<children> children_ptr;

class parent
{
public:
	~parent() { std::cout << "destroying parent\n"; }

public:
	children_ptr children;
};

class children
{
public:
	~children() { std::cout << "destroying children\n"; }

public:
	parent_ptr parent;
};


void test()
{
	//parent_ptr father(new parent());
	shared_ptr<parent> father(new parent());
	shared_ptr<parent> temp = make_shared<parent>();
	unique_ptr<parent>  father1();
	shared_ptr<children> son(new children);

	father->children = son;
	son->parent = father;
}

void mainZNZZ()
{
	std::cout << "begin test...\n";
	test();
	std::cout << "end test.\n";

	system("pause");
}