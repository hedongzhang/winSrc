#include<iostream>
#include<boost/array.hpp>

using namespace std;


void main123()
{
	boost::array<int, 6> arr = {1,2,3,4,5,6};
	boost::array<int, 6>::iterator iter = arr.begin();

	while (iter!=arr.end())
	{
		cout << *iter << endl;
		iter++;
	}

	system("pause");
}