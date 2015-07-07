#include<locale>
#include<iostream>

using namespace std;

void mainBDH()
{
	setlocale(LC_ALL, "chs");

	wchar_t wc = L'ºÍ';
	wcout << wc << endl;
	system("pause");
}