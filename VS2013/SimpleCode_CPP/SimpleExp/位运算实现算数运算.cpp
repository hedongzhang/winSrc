#pragma once
#include<iostream>

//λ����ʵ�ּ�
template<typename T>
T add(T v1, T v2)
{
	if (v2 == 0)
	{
		return v1;
	}
	return add<T>(v1^v2, (v1&v2) << 1);			//���������^���Ǽӷ������������λ��&����������һλ�ǽ�λ���
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
