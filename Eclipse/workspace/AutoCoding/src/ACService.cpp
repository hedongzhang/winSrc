/*
 * ACService.cpp
 *
 *  Created on: 2015��5��5��
 *      Author: HDZhang
 */

#include"ACService.h"
#include"ACManager.h"
#include"ACCodeManager.h"
#include"ACSQLManager.h"
#include"ACConfManager.h"
#include<fstream>
#include<sstream>

using namespace n_acmanager;

ACService::ACService(map<string,string>& baseMessage):m_KeyValue(baseMessage)
{
	inputFields.clear();
	outputFields.clear();
	//m_KeyValue.clear();

	cout<<endl<<"=====��ʼ��������=====<"<<this->m_KeyValue.find("@SERVICE_NAME@")->second<<">"<<endl;

	if(init()!=RETURN_SUCCESS)
	{
		cout<<"=====ACService��ʼ��ʧ��=====<"<<this->baseMess.name<<">"<<endl;
	}
}

ACService::~ACService()
{
}


/**********��ʼ������**********
	 *
	 */
int ACService::init()
{
	//��ȡ���������Ϣ
	this->baseMess.name=this->m_KeyValue.find("@SERVICE_NAME@")->second;
	this->baseMess.sql=this->m_KeyValue.find("@SQL@")->second;
	this->baseMess.class_id=this->m_KeyValue.find("@CLASS_ID@")->second;
	this->baseMess.group_id=this->m_KeyValue.find("@GROUP_ID@")->second;
	this->baseMess.input_node=this->m_KeyValue.find("@INPUT_NODE@")->second;
	this->baseMess.output_node=this->m_KeyValue.find("@OUTPUT_NODE@")->second;
	this->baseMess.libName=this->m_KeyValue.find("@LIB_NAME@")->second;
	//this->baseMess.type=this->m_KeyValue.find("@SERVICE_TYPE@")->second;

	//��ʼ����������������Ϣ
	if(initOtherMessage()!=n_acmanager::RETURN_SUCCESS)
	{
		return n_acmanager::RETURN_FAILED;
	}

	//������������ֶ���Ϣ
	if(this->m_KeyValue.find("@FIELDS@")!=m_KeyValue.end())
	{
		string fieldFilePath=this->m_KeyValue.find("@FIELDS@")->second;
		if(readFieldsFile(fieldFilePath)!=n_acmanager::RETURN_SUCCESS)
		{
			return n_acmanager::RETURN_FAILED;
		}
	}
	else
	{
		if(initInputFields()==n_acmanager::RETURN_FAILED || initOutputFields()==n_acmanager::RETURN_FAILED)
		{
			cout<<"=====����sql��ʼ����������ֶ�ʧ�ܣ�====="<<endl;
			return n_acmanager::RETURN_FAILED;
		}
	}

	//���������ļ�
	ACConfManager acConfManager(*this);
	//����sql�ű�
	ACSQLManager acSQLManager(*this);

	//��ӡ������Ϣ
	//printService();
	ACCodeManager acCodeManager(*this);
	//ACCodeManager acCodeManager("");

	return n_acmanager::RETURN_SUCCESS;
}

int ACService::initOtherMessage()
{
	if(creatClassName(this->otherMess.className)!=n_acmanager::RETURN_SUCCESS)
		return RETURN_FAILED;
	if(creatServiceType()!=n_acmanager::RETURN_SUCCESS)
		return RETURN_FAILED;
	return RETURN_SUCCESS;
}

int ACService::creatClassName(string& className)
{
	if(this->baseMess.name=="")
	{
		cout<<"������Ϊ�գ�����������ʧ�ܣ�"<<endl;
		return n_acmanager::RETURN_FAILED;
	}

	string serviceName=this->baseMess.name;
	toupper(serviceName[0]);
	string::size_type pos = 1;
	while (pos < serviceName.length())
	{
		if (serviceName[pos] == '_') {
			serviceName.erase(pos, 1);
			serviceName[pos] = toupper(serviceName[pos]);
		} else {
			serviceName[pos] = tolower(serviceName[pos]);
		}
		pos++;
	}
	className = "DCCrm";
	className += serviceName;

	//cout << "����������" + className << endl;
	return n_acmanager::RETURN_SUCCESS;
}
int ACService::creatServiceType()
{
	if(m_KeyValue.find("@SERVICE_TYPE@")!=m_KeyValue.end())
	{
		this->otherMess.type=this->m_KeyValue.find("@SERVICE_TYPE@")->second;
		return RETURN_SUCCESS;
	}
	else
	{
		string::size_type currIndex=0;
		while(  baseMess.sql[currIndex]==' ' || baseMess.sql[currIndex]=='\t' || \
				baseMess.sql[currIndex]=='\v' || baseMess.sql[currIndex]=='\n' || \
				baseMess.sql[currIndex]=='\r' )
			currIndex++;

		if(	this->baseMess.sql[currIndex]=='s' || this->baseMess.sql[currIndex]=='S' )
		{
			this->otherMess.type=ACServiceTypeSelect;
		}
		else if( this->baseMess.sql[currIndex]=='u' || this->baseMess.sql[currIndex]=='U' )
		{
			this->otherMess.type=ACServiceTypeUpdate;
		}
		else if( this->baseMess.sql[currIndex]=='d' || this->baseMess.sql[currIndex]=='D' )
		{
			this->otherMess.type=ACServiceTypeDelete;
		}
		else if( this->baseMess.sql[currIndex]=='i' || this->baseMess.sql[currIndex]=='I' )
		{
			this->otherMess.type=ACServiceTypeInsert;
		}
		else if( this->baseMess.sql[currIndex]=='b' || this->baseMess.sql[currIndex]=='B' )
		{
			this->otherMess.type=ACServiceTypeCombo;
		}
		else
		{
			return n_acmanager::RETURN_FAILED;
		}
		return n_acmanager::RETURN_SUCCESS;
	}
}

/*����sql��ʼ�������ֶ�
 * ��ȡÿ��[:]֮ǰֱ���ո����Ϊ�����ֶ����ƣ��Զ�ת��Ϊ��д��
 * exp:
 * 		latn_id = :LATN_ID
   	   	and a.acc_nbr = :ACC_NBR
        �����������
   exp:
   	   	to_char(a.record_time, 'yyyy-mm-dd hh:mi:ss') data ,
 */
int ACService::initInputFields()
{
	cout<<endl<<"=====����sql��ʼ�������ֶ�====="<<endl;
	if(this->baseMess.sql=="")
	{
		cout<<"����sqlΪ�գ��޷����������ֶ�!"<<endl;
		return n_acmanager::RETURN_FAILED;
	}
	string sql=this->baseMess.sql;
	string::size_type currPos = 0;
	string::size_type fieldPos = 0;
	while (currPos < sql.length())
	{
		if(fieldPos==0 && sql[currPos]==':')
		{
			fieldPos=currPos+1;
		}
		else if(fieldPos!=0 && sql[currPos]==':')
		{
			fieldPos=0;
		}
		else if( fieldPos!=0 && sql[currPos]==' ')
		{
			for(string::size_type i=fieldPos;i<currPos;i++)
			{
				sql[i]=toupper(sql[i]);
			}

			Field field;
			field.type=FieldType::STRING;
			field.name=sql.substr(fieldPos,currPos-fieldPos);
			field.size=64;
			this->inputFields.push_back(field);
			fieldPos=0;
		}

		currPos++;
	}
	this->numInputBindParam=this->inputFields.size();

	return n_acmanager::RETURN_SUCCESS;
}

/*����sql��ʼ������ֶ�
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
int ACService::initOutputFields()
{
	cout<<endl<<"=====����sql��ʼ������ֶ�====="<<endl;
	if(this->baseMess.sql=="")
	{
		cout<<"=====����sqlΪ�գ��޷���������ֶ�!====="<<endl;
		return n_acmanager::RETURN_FAILED;
	}
	string sql=this->baseMess.sql;

	string::size_type currIndex=0;
	while(  baseMess.sql[currIndex]==' ' || baseMess.sql[currIndex]=='\t' || \
			baseMess.sql[currIndex]=='\v' || baseMess.sql[currIndex]=='\n' || \
			baseMess.sql[currIndex]=='\r' )
		currIndex++;

	if(sql[currIndex]!='s' && sql[currIndex]!='S')
	{
		//cout<<"=====����select��䣬������ֶΣ�====="<<endl;
		return n_acmanager::RETURN_SUCCESS;
	}




	string::size_type currPos = 0;
	while(currPos!=sql.size())
	{
		if(sql[currPos]==',' && sql[currPos-1]==' ')
		{
			string::size_type size=2;
			while(sql[currPos-size]!=' ')
			{
				size++;
			}

			Field field;
			field.name=sql.substr(currPos-size+1,size-2);

			for(string::size_type i=0;i<field.name.size();i++)
			{
				field.name[i]=toupper(field.name[i]);
			}
			sql.substr(currPos-size+1,size-2);
			field.size=64;
			field.type=FieldType::STRING;
			this->outputFields.push_back(field);
		}
		currPos++;
	}
	this->numOutputBindParam=this->outputFields.size();

	return n_acmanager::RETURN_SUCCESS;

}

/**********���ļ���ȡ��������ֶ�**********
 *
 */
int ACService::readFieldsFile(string path)
{
	cout<<endl<<"=====��ʼ��ȡ�ֶ������ļ�====="<<endl;
	ifstream ifstre;
	ifstre.open(path);
	if(ifstre.is_open())
	{
		string currFieldType="";
		string currLineValue="";
		this->numInputBindParam=0;
		this->numOutputBindParam=0;
		while(!ifstre.eof())
		{
			getline(ifstre,currLineValue);

			if(currLineValue[0]=='@')
			{
				istringstream istringstre(currLineValue);
				istringstre>>currFieldType;
				if(currFieldType=="@INPUT_BIND_FIELD@")
					istringstre>>this->numInputBindParam;
				else if(currFieldType=="@OUTPUT_BIND_FIELD@")
					istringstre>>this->numOutputBindParam;
			}
			else if(currFieldType.empty() || currLineValue.empty() || currLineValue[0]=='#')
			{
				continue;
			}
			else if(currFieldType=="@INPUT_BIND_FIELD@")
			{
				for(string::size_type currIndex=0;currIndex<currLineValue.length();currIndex++)
					currLineValue[currIndex]=toupper(currLineValue[currIndex]);

				istringstream istringstre(currLineValue);

				Field field;
				field.size=0;
				istringstre>>field.name;

				string temp;
				istringstre>>temp;
				if(temp!="")
				{
					if(temp=="$")
					{
						field.isNihil=true;
					}
					else if(temp=="%")
					{
						field.needAssembly=true;
					}
					else
					{

						istringstream istringstreTemp(temp);
						istringstreTemp>>field.size;
						istringstre>>temp;
						if(temp!="")
						{
							if(temp=="$")
							{
								field.isNihil=true;
							}
							else if(temp=="%")
							{
								field.needAssembly=true;
							}
						}
					}
				}

				if(field.size==0)
					field.size=64;
				field.type=FieldType::STRING;
				this->inputFields.push_back(field);

			}
			else if(currFieldType=="@OUTPUT_BIND_FIELD@")
			{
				for(string::size_type currIndex=0;currIndex<currLineValue.length();currIndex++)
					currLineValue[currIndex]=toupper(currLineValue[currIndex]);

				istringstream istringstre(currLineValue);

				Field field;
				field.size=0;
				istringstre>>field.name;
				istringstre>>field.size;
				if(field.size==0)
					field.size=64;
				field.type=FieldType::STRING;
				this->outputFields.push_back(field);
			}
		}
		/*if(this->numInputBindParam==0)
			this->numInputBindParam=this->inputFields.size();
		if(this->numOutputBindParam==0)
			this->numOutputBindParam=this->outputFields.size();*/
		cout<<"======��ȡ�ֶ��������====="<<endl<<endl;
		ifstre.close();
	}
	else
	{
		cout<<"=====��ȡ�ֶ������ļ��쳣====="<<endl<<endl;
		ifstre.close();
		return RETURN_FAILED;
	}
	return n_acmanager::RETURN_SUCCESS;
}


//��ӡ������Ϣ
int ACService::printService()
{
	cout<<"================��ӡ����================"<<endl;
	cout<<"������Ϣ��"<<endl<<"{"<<endl;
	cout<<"	��������"<<this->baseMess.name<<endl;
	cout<<"	class_id��"<<this->baseMess.class_id<<endl;
	cout<<"	group_id��"<<this->baseMess.group_id<<endl;
	cout<<"	��νڵ㣺"<<this->baseMess.input_node<<endl;
	cout<<"	���νڵ㣺"<<this->baseMess.output_node<<endl;
	cout<<"	������"<<this->baseMess.libName<<endl;
	cout<<"	SQL��"<<this->baseMess.sql<<endl;
	cout<<"}"<<endl;
	cout<<"������Ϣ��"<<endl<<"{"<<endl;
	cout<<"	����������"<<this->otherMess.className<<endl;
	cout<<"	���ɷ������ͣ�"<<this->otherMess.type<<endl;
	cout<<"}"<<endl<<endl;



	cout<<"�����ֶΣ�"<<this->inputFields.size()<<"����"<<endl;
	cout<<"����";
	for(int i=0;i<68;i++)
	{
		cout<<" ";
	}
	cout<<"����            ��С            ��ֵ"<<endl;
	for(Field field:this->inputFields)
	{
		int spaceNum=32-field.name.length();
		cout<<field.name;
		for(int i=0;i<spaceNum;i++)
		{
			cout<<" ";
		}
		cout<<field.type<<"      "<<field.size<<"      "<<field.isNihil<<endl;
	}
	cout<<endl<<"����ֶΣ�"<<this->outputFields.size()<<"����"<<endl;
	cout<<"����";
	for(int i=0;i<68;i++)
	{
		cout<<" ";
	}
	cout<<"����            ��С            ��ֵ"<<endl;
	for(Field field:this->outputFields)
	{
		int spaceNum=32-field.name.length();
		cout<<field.name;
		for(int i=0;i<spaceNum;i++)
		{
			cout<<" ";
		}
		cout<<field.type<<"      "<<field.size<<"      "<<field.isNihil<<endl;
	}
	cout<<"======================================="<<endl;
	return n_acmanager::RETURN_SUCCESS;
}

ACService::BaseMess& ACService::getBaseMessage()
{
	return this->baseMess;
}

ACService::OtherMess& ACService::getOtherMessage()
{
	return this->otherMess;
}

//������������ֶ�
int ACService::setInputField(vector<Field>& field)
{
	this->inputFields=field;
	return n_acmanager::RETURN_SUCCESS;
}
vector<Field>& ACService::getInputField()
{
	return this->inputFields;
}
int ACService::setOutputField(vector<Field>& field)
{
	this->outputFields=field;
	return n_acmanager::RETURN_SUCCESS;
}
vector<Field>& ACService::getOutputField()
{
	return this->outputFields;
}

//��ȡSQL�󶨲�������
int ACService::getNumInoutBindParam()
{
	return this->numInputBindParam;
}
//��ȡSQL���ز�������
int ACService::getNumOutputBindParam()
{
	return this->numOutputBindParam;
}
