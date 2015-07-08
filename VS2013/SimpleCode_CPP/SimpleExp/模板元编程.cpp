#include<iostream>

using namespace std;

template<int N>
struct data
{
	enum { res = data<N-1>::res+data<N-2>::res };
};

template <>
struct data<1>
{
	enum { res = 1 };
};
template <>
struct data <2>
{
	enum { res = 1 };
};

int met(int i)
{
	if (i == 1 || i == 2)
	{
		return 1;
	}
	else
	{
		return met(i - 1) + met(i - 2);;
	}
}

void main()
{
	cout << data<40>::res << endl;
	cout<<met(40)<<endl;
	system("pause");
}