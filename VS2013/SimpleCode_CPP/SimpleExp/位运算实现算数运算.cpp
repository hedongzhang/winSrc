#pragma once
#include<iostream>

//位运算实现加
template<typename T>
T add(T v1, T v2)
{
	if (v2 == 0)
	{
		return v1;
	}
	return add<T>(v1^v2, (v1&v2) << 1);			//两个数异或（^）是加法结果，两个数位（&）与再左移一位是进位结果
};



using namespace std;

int mainSSYS()
{
	while (true)
	{
		int i;
		int j;
		cin >> i >> j;
		int z = add<int>(i, j);
		cout << z << endl;

		system("pause");
	}

	return 1;
}
