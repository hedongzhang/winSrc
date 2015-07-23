/*
 * ACService.h
 *
 *  Created on: 2015��5��5��
 *      Author: HDZhang
 */

#ifndef ACSERVICE_H_
#define ACSERVICE_H_

#include<iostream>
#include<vector>
#include<map>


using namespace std;

//�ֶ�����
enum FieldType
{
	STRING,
	LONG,
	FML32,
};
//�ֶ�
struct Field
{
public:
	string name;
	FieldType type;
	long size;
	bool isNihil;
	bool needAssembly;

	Field()
	{
		name="";
		type=FieldType::STRING;
		size=64;
		isNihil=false;
		needAssembly=false;
	}
};

//��������
const string ACServiceTypeSelect="ATOM_SERVICE_TYPE_SELECT";
const string ACServiceTypeUpdate="ATOM_SERVICE_TYPE_UPDATE";
const string ACServiceTypeInsert="ATOM_SERVICE_TYPE_INSERT";
const string ACServiceTypeDelete="ATOM_SERVICE_TYPE_DELETE";
const string ACServiceTypeCombo="ATOM_SERVICE_TYPE_COMBO";


//����
class ACService
{

public:
	//������������Ϣ
	struct BaseMess
	{
		string name;          //������
		string class_id;	  //class_id
		string group_id;      //��ID
		string input_node;    //��νڵ�
		string output_node;   //���νڵ�
		string libName;       //����
		string sql;           //sql
	};

	//�������������Ϣ
	struct OtherMess
	{
		string type;          //��������
		string className;    //������
	};

	/***********���캯��**********
	 *
	 */
	ACService(map<string,string>& baseMessage);
	virtual ~ACService();

	/**********��ʼ������**********
	 *
	 */
	int init();

	//���ݻ�����Ϣ��ʼ�������Ϣ
	int initOtherMessage();
	//��������
	int creatClassName(string& className);
	//���ɷ�������
	int creatServiceType();

	/**********����sql��ʼ�������ֶ�**********
	 * ��ȡÿ��[:]֮ǰֱ���ո����Ϊ�����ֶ�����
	 * exp:
	 * 		latn_id = :LATN_ID
	   	   	and a.acc_nbr = :ACC_NBR
	        �����������
	   exp:
	   	   	to_char(a.record_time, 'yyyy-mm-dd hh:mi:ss') data ,
	 */
	int initInputFields();
	/**********����sql��ʼ������ֶ�**********
	 * ��ȡÿ��[,]�Ϳո�֮ǰֱ������һ���ո�Ϊֹ����Ϊ����ֶ����ƣ��Զ�ת��Ϊ��д��
	 * exp:
	 *		select a.latn_id latn_id ,
	 *		a.acc_nbr acc_nbr ,
	 * �����������
	 * exp:
	 * 	   	to_char(a.record_time, 'yyyy-mm-dd hh:mi:ss') data
	 * 	   	a.pdf_path pdf_path,\
	 * 	   	[,]֮ǰ�޿ո�
	 */
	int initOutputFields();

	/**********���ļ���ȡ��������ֶ�**********
	 *
	 */
	int readFieldsFile(string path);



	//��ӡ������Ϣ
	int printService();

	//���ʻ�����Ϣ
	BaseMess& getBaseMessage();
	OtherMess& getOtherMessage();
	//������������ֶ�
	int setInputField(vector<Field>& field);
	vector<Field>& getInputField();
	int setOutputField(vector<Field>& field);
	vector<Field>& getOutputField();

	//��ȡSQL�󶨲�������
	int getNumInoutBindParam();
	//��ȡSQL���ز�������
	int getNumOutputBindParam();
	map<string,string> m_KeyValue;    //�򵥹ؼ���ֵ�滻
private:
	BaseMess baseMess;    //������Ϣ
	OtherMess otherMess;  //������Ϣ

	vector<Field> inputFields;   //�����ֶ�
	vector<Field> outputFields;  //����ֶ�

	int numInputBindParam;  //SQL�󶨲�������
	int numOutputBindParam;  //SQL���ز�������
};



#endif /* ACSERVICE_H_ */
