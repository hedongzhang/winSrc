#include<iostream>
#include<assert.h>
#include<string>
#include<array>
#include<algorithm>

template <class T>
class Print
{
public:
	void operator()(T& t)
	{
		std::cout <<t<< std::endl;
	}
};

void main()
{
	Print<int> print;
	std::array<int, 6>arr = { 1, 2, 3, 4, 5, 6 };
	for_each(arr.begin(), arr.end(), print);

		system("pause");
}