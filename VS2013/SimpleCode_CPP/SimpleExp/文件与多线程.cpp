#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<thread>

using namespace std;

//#define DATA_arrCount 13000000
#define DATA_arrCount 100000
#define DATA_SIZE 130

string* arrayData[DATA_arrCount];
int arrCount = 0;

void search(int start, int end, string strTemp,int threadNum)
{
	for (size_t i = start; i < end; i++)
	{
		if (arrayData[i]->find(strTemp) != string::npos)
		{
			cout << "�̣߳�" << threadNum <<"="<< *arrayData[i] << endl;
		}
	}
}


void mainWJYDXC()
{
	ifstream ifstre;
	ofstream ofstre;
	ifstre.open(R"(E:\��Ҫ�ļ�\����\��Ƶ����\2014���ǲ���C++�����ڸ������\�ĵ�\out.txt)");
	//ofstre.open(R"(E:\��Ҫ�ļ�\����\��Ƶ����\2014���ǲ���C++�����ڸ������\�ĵ�\1.txt)");
	if (ifstre)
	{
		cout << "���ļ��ɹ���" << endl;

		
		while (!ifstre.eof() && arrCount<100000)
		{
			string* pStr=new string;
			getline(ifstre, *pStr);
			
			arrayData[arrCount] = pStr;
			arrCount++;
			//cout << arrayData[arrCount] << endl;;
			//ofstre<< str<< endl;
			
		}
		cout << "��ȡ��"<<arrCount << "��"<<endl;;
		if (!ifstre.eof())
		{
			cout << "�ļ�δ���꣡" << endl;
		}

		ifstre.close();
		//ofstre.close();
	}
	else
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
	}



	while (1)
	{
		string strTemp;
		cout << "������ؼ��֣�" << endl;
		cin >> strTemp;

		int threadCount = 1;
		cout << "�����߳�����" << endl;
		cin >> threadCount;

		vector<thread>  vecThreads;

		int temp = arrCount / threadCount;

		for (int i = 0; i < threadCount;i++)
		{
			thread thread1(search, i*temp, i*temp + temp, strTemp,i+1);
			//vecThreads.push_back(thread1);
			thread1.detach();
		}

		/*for (size_t i = 0; i < 10000; i++)
		{
			if (arrayData[i]->find(strTemp) != string::npos)
			{
				cout << "�̣߳�" << 1 << "=" << *arrayData[i] << endl;
			}
		}*/

		
	}
	





	system("pause");
}