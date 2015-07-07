#include<iostream>
#include<locale>
#include<array>
#include<vector>
#include<tuple>

using namespace std;

void main()
{
	int i = 12;
	char c = 'C';
	string str = "qefr";
	tuple<int, char, string> myTuple(i,c,str);

	std::get<0>(myTuple);

	system("pause");
}