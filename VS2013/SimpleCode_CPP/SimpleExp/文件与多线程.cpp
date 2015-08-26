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
			cout << "线程：" << threadNum <<"="<< *arrayData[i] << endl;
		}
	}
}


void mainWJYDXC()
{
	ifstream ifstre;
	ofstream ofstre;
	ifstre.open(R"(E:\重要文件\资料\视频资料\2014传智播客C++第三期更新完毕\文档\out.txt)");
	//ofstre.open(R"(E:\重要文件\资料\视频资料\2014传智播客C++第三期更新完毕\文档\1.txt)");
	if (ifstre)
	{
		cout << "打开文件成功！" << endl;

		
		while (!ifstre.eof() && arrCount<100000)
		{
			string* pStr=new string;
			getline(ifstre, *pStr);
			
			arrayData[arrCount] = pStr;
			arrCount++;
			//cout << arrayData[arrCount] << endl;;
			//ofstre<< str<< endl;
			
		}
		cout << "读取："<<arrCount << "条"<<endl;;
		if (!ifstre.eof())
		{
			cout << "文件未读完！" << endl;
		}

		ifstre.close();
		//ofstre.close();
	}
	else
	{
		cout << "打开文件失败！" << endl;
	}



	while (1)
	{
		string strTemp;
		cout << "请输入关键字！" << endl;
		cin >> strTemp;

		int threadCount = 1;
		cout << "请输线程数！" << endl;
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
				cout << "线程：" << 1 << "=" << *arrayData[i] << endl;
			}
		}*/

		
	}
	





	system("pause");
}