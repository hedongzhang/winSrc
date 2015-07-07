#include<iostream>
#include<functional>


//using  std::function;

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


/*函数包装器
	设置执行关卡
	实现泛型函数
	实现内嵌函数
*/
template<typename F,typename D>
D run(F func, D data)
{
	return func(data);
}
int funcTemp(int data)
{
	return data *= data;
}


template<typename T>
void swap(T& data1, T& data2)
{
	T temp = data1;
	data1 = data2;
	data2 = temp;
}

//可变参数模板
void argsMet()
{
}
template<typename T,typename... Args>
void argsMet(T t,Args... args)
{
	std::cout << t << std::endl;
	argsMet(args...);
}


void mainMB()
{
		/*int value[10] = { 1, 4, 6, 8, 23, 64, 1, 0, 42 };
		char value1[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		cout << max(value, 10)<<endl;
		cout << max(value1, 10) << endl;

		cout << mul(12, 'A')<<endl;*/

		/*function<int(int)> funcTemp1 = [](int data){ return data *= data; };

		cout<<run(funcTemp1, 3)<<endl;*/

		/*char d1 = 'a';
		char d2 = 't';
		std::cout << d1 << std::endl << d2 <<std:: endl;

		swap(d1, d2);
		std::cout << d1 << std::endl << d2 << std::endl;*/

	int i = 10;
	char c = 'A';
	argsMet(i,c);

		system("pause");
}