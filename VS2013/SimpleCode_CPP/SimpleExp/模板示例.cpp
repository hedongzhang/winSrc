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


void main()
{
	while (true)
	{
		int value[10] = { 1, 4, 6, 8, 23, 64, 1, 0, 42 };
		char value1[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		cout << max(value, 10)<<endl;
		cout << max(value1, 10) << endl;
		system("pause");
	}
}