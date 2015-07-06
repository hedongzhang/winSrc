#include<iostream>

using namespace std;

template<typename T> T max(T data[], const int n)
{
	T maxValue(data[0]);
	for (size_t i = 1; i < n; i++)
	{
		if (maxValue < data[i])
		{
			maxValue = data[i];
		}
	}
	return maxValue;
}


template<class T1, class T2>
auto mul(T1 data1, T2 data2)->decltype(data1* data2)
{
	return data1* data2;
}


void mainMBSL()
{
	while (true)
	{
		int value[10] = { 1, 4, 6, 8, 23, 64, 1, 0, 42 };
		char value1[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		cout << max(value, 10)<<endl;
		cout << max(value1, 10) << endl;

		cout << mul(12, 'A')<<endl;

		system("pause");
	}
}