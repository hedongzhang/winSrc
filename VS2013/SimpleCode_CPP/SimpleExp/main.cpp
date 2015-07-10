#include<iostream>
#include<assert.h>

using namespace std;

int main()
{
	
	cout << __FILE__ << endl;
	cout << __LINE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __FUNCTION__ << endl;

	int i = 10;
	//static_assert( (1 > 5),"err");

	system("pause");
}