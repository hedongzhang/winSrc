#include<iostream>
#include<locale>

using namespace std;

void mainLXZH()
{
	int i = static_cast<int>(1.1);

	const int* cpi = &i;
	int* pi = const_cast<int*>(cpi);
	*pi = 2;
	cout << i << endl;

	char* pc = reinterpret_cast<char*>(pi);
	for (size_t j = 0; j < 4; j++)
	{
		printf("%c\t%d\t%p\n", *(pc+j), *(pc+j), pc+j);
	}

	
	system("pause");
}