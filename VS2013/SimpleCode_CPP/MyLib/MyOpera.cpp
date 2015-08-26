#include "MyOpera.h"
#include<iostream>

using namespace std;

int mainMO()
{	
	while (true)
	{
		int i;
		int j ;
		cin >> i >> j;
		int z = add<int>(i, j);
		cout << z << endl;

		system("pause");
	}
	
	return 1;
}
