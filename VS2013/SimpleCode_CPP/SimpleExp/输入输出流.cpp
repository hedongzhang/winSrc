#include<iostream>
#include<assert.h>
#include<string>
#include<iomanip>

using namespace std;


void mainIOS()
{
	//***ֱ��ʹ��iostream �ĺ���

	double i = 32.465453;
	cout << setprecision(10) << i << endl;;	//����С���㾫ȷ��10λ
	

	cout.width(20);		//�趨���
	cout.fill('#');			//�趨���
	cout << i;
	cout << endl;

	cout.width(20);		//�趨���
	cout.fill('#');			//�趨���
	cout.setf(cout.left);		//�����Ҷ���
	//cout.setf(cout.right,cout.left);		//����Ҷ��룬���������
	cout << i;
	cout << endl;


	//***ʹ��iomanip.hͷ�ļ�����

	cout << left << setw(20)<<setfill('*') << i << endl;
	cout << i;

	cout << endl;
	system("pause");
}