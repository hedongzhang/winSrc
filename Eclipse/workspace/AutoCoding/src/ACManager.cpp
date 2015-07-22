/*
 * ACManager.cpp
 *
 *  Created on: 2015��5��5��
 *      Author: HDZhang
 */

#include "ACManager.h"
#include "ACService.h"
#include<fstream>
#include<memory.h>
#include<sstream>
#include<ctime>
#include<time.h>

using namespace n_acmanager;

ACManager::ACManager(string configFile):configFile(configFile)
{
	if(init()==RETURN_FAILED)
	{
		cout<<"=====ACManager��ʼ��ʧ��====="<<endl;
	}
	else
	{
		creatServices();
	}
}

ACManager::~ACManager() {
	// TODO Auto-generated destructor stub
}

int ACManager::getBaseMessage(const string keyName,string codeTemplate)
{
    map<string,string>::iterator ite_baseMessage= m_baseMessage.find(keyName);
    if(ite_baseMessage!=m_baseMessage.end())
    {
        codeTemplate=ite_baseMessage->second;
        return RETURN_SUCCESS;
    }
    else
    {
        return RETURN_FAILED;
    }
}

int ACManager::setBaseMessage(const string keyName,string codeTemplate)
{
    m_baseMessage.insert(map<string,string>::value_type(keyName,codeTemplate));
	return RETURN_SUCCESS;
}

int ACManager::getKeyMap(const string keyName,map<string,string>& keyMap)
{
    map<string,map<string,string> >::iterator valueIter=ACManager::m_keyMap.find(keyName);
    if(valueIter!=ACManager::m_keyMap.end())
    {
        keyMap=valueIter->second;
        return RETURN_SUCCESS;
    }
    else
    {
        return RETURN_FAILED;
    }
}

int ACManager::getCodeTemplateMap(const string keyName,string& codeTemplate)
{
    map<string,string>::iterator codeTemplateIter= ACManager::m_codeTemplateMap.find(keyName);
    if(codeTemplateIter!=ACManager::m_codeTemplateMap.end())
    {
        codeTemplate=codeTemplateIter->second;
        return RETURN_SUCCESS;
    }
    else
    {
        return RETURN_FAILED;
    }
}

int ACManager::setKeyMap(const string keyName,map<string,string> keyMap)
{
    ACManager::m_keyMap.insert(map<string,map<string,string> >::value_type(keyName,keyMap));
    return RETURN_SUCCESS;
}

int ACManager::setCodeTemplateMap(const string keyName,string codeTemplate)
{
    ACManager::m_codeTemplateMap.insert(map<string,string>::value_type(keyName,codeTemplate));
    return RETURN_SUCCESS;
}


/**********������ʼ��**********
 * ��ȡ�����ļ������������ļ�����ؼ�����ֵ������ؼ���ӳ���ģ��
 * @�ַ�------ģ������
 * һ���ַ�----ģ��·��
 * #�ַ�------ע��
 */
int ACManager::init()
{
	cout<<"=====��ʼ��ʼ��====="<<endl;

	//��ȡ������Ϣ
	if(readConfig()==RETURN_FAILED)
	{
		cout<<"=====��ȡ������Ϣʧ��====="<<endl;
		return RETURN_FAILED;
	}

	cout<<"======��ʼ�����======"<<endl<<endl;
	return RETURN_SUCCESS;
}


/**********��ӡ��ȡ�Ļ�����Ϣ**********
 *
 */
void ACManager::showBaseMessage()
{
	cout<< endl << "=====��ȡֵ�б�=====" << endl;
	for (map<string, string>::iterator ite = m_baseMessage.begin();
			ite != m_baseMessage.end(); ite++) {
		cout << ite->first << ":" << ite->second << endl;
	}

	cout << "=====��ȡģ���б�=====" << endl;
	for (map<string,map<string,string> >::iterator ite = ACManager::m_keyMap.begin();ite != ACManager::m_keyMap.end(); ite++)
	{
		cout << ite->first << endl<< "{"<< endl;
		for (map<string,string>::iterator ite1 = ite->second.begin();ite1 != ite->second.end(); ite1++)
		{
			cout <<"  "<< ite1->first << ":" << ite1->second << endl;
		}
		cout <<"}"<< endl;
	}
	for (map<string,string>::iterator ite = ACManager::m_codeTemplateMap.begin();ite != ACManager::m_codeTemplateMap.end(); ite++)
	{
		cout <<"  "<< ite->first << ":" << ite->second << endl;
	}
	cout << "===================" << endl;

}


//��ȡ������Ϣ
int ACManager::readConfig()
{
	cout<<"=====��ȡ����====="<<endl;
	ifstream ifstre;
	ifstre.open(this->configFile.c_str());
	if(ifstre.is_open())
	{
		string currentTemplateName("");
		string currentTemplateValue("");

		while(!ifstre.eof())
		{
			char fileContextChar[200];
			memset(fileContextChar,0,sizeof(fileContextChar));
			ifstre.getline(fileContextChar,2000);
			if(fileContextChar[0]=='@')
			{
				string templateName(fileContextChar);

				if(templateName.compare("@ServiceTemplate")==0 || templateName.compare("@CodeTemplate")==0)
				{
					if(!currentTemplateName.empty())
					{
						int returnCode=RETURN_SUCCESS;
						if(currentTemplateName.compare("@ServiceTemplate")==0)
						{
							//��ȡ·���µĹؼ���ӳ���ļ�
							returnCode=readKeyTemplate(currentTemplateValue);
						}
						else if(currentTemplateName.compare("@CodeTemplate")==0)
						{
							//��ȡ·���µĴ���ģ�岢��ģ���ļ���ӳ��
							returnCode=readCodeTemplate(currentTemplateValue);
						}
						else
						{
							m_baseMessage.insert(map<string,string>::value_type(currentTemplateName,currentTemplateValue));
						}
						if(returnCode==RETURN_FAILED)
						{
							cout<<"=====��ȡ�ؼ���ӳ���ļ������ģ�������ļ�����===="<<endl;
							ifstre.close();
							return RETURN_FAILED;
						}
					}
				}
				else if(currentTemplateName!=templateName)
				{
					if(!currentTemplateName.empty())
					{
						int returnCode=RETURN_SUCCESS;
						if(currentTemplateName.compare("@ServiceTemplate")==0)
						{
							//��ȡ·���µĹؼ���ӳ���ļ�
							returnCode=readKeyTemplate(currentTemplateValue);
						}
						else if(currentTemplateName.compare("@CodeTemplate")==0)
						{
							//��ȡ·���µĴ���ģ�岢��ģ���ļ���ӳ��
							returnCode=readCodeTemplate(currentTemplateValue);
						}
						else
						{
							m_baseMessage.insert(map<string,string>::value_type(currentTemplateName,currentTemplateValue));
						}
						if(returnCode==RETURN_FAILED)
						{
							cout<<"=====��ȡ�ؼ���ӳ���ļ������ģ�������ļ�����====="<<endl;
							ifstre.close();
							return RETURN_FAILED;
						}
					}
				}
				currentTemplateName=templateName;
				currentTemplateValue="";
				//�����������˳�
				if(currentTemplateName.compare("@")==0)
				{
					break;
				}
				continue;
			}
			else if(fileContextChar[0]=='#')
			{
				//ע��
				continue;
			}
			else
			{
				currentTemplateValue+=string(fileContextChar);
			}
		}

		//cout<<fileContext;
		ifstre.close();
	}
	else
	{
		cout<<"=====�������ļ��쳣====="<<endl;
		ifstre.close();
		return RETURN_FAILED;
	}

	showBaseMessage();
	cout<<"=====���ö�ȡ����====="<<endl<<endl;
	return RETURN_SUCCESS;
}
//����·����ȡ�ؼ���ģ������
int ACManager::readKeyTemplate(string path)
{
    string keyTemplateName=path.substr(path.find_last_of('/')+1);
    if(!keyTemplateName.empty())
    {
        ifstream ifstre;
        ifstre.open(path.c_str());
        if(ifstre.is_open())
        {
            map<string,string> keyTemplate;
            string keyContext;
            string templateContext;
            while(!ifstre.eof())
            {
            	string currLine;
            	getline(ifstre,currLine);

            	if(currLine[0]=='#' || currLine.empty())
            	{
            		continue;
            	}

            	if(keyContext=="")
            	{
            		keyContext=currLine;
            	}
            	else
            	{
            		if(currLine[0]!='@')
            		{
            			if(keyContext=="@SQL@")
            				currLine=currLine+"\n";
						templateContext+=currLine;
            		}
            		else
            		{
            			keyTemplate.insert(pair<string,string>(keyContext,templateContext));
            			keyContext=currLine;
            			templateContext="";
            		}
            	}
            }
            keyTemplate.insert(pair<string,string>(keyContext,templateContext));

            ifstre.close();
            return ACManager::setKeyMap(keyTemplateName,keyTemplate);
        }
        return RETURN_FAILED;
    }
    return RETURN_SUCCESS;
}
//����·����ȡ����ģ������
int ACManager::readCodeTemplate(string path)
{
    string keyTemplateName=path.substr(path.find_last_of('/')+1);
    if(!keyTemplateName.empty())
    {
        return ACManager::setCodeTemplateMap(keyTemplateName,path);
    }
    return RETURN_SUCCESS;
}


/**********�Զ����ɷ���**********
 *
 */
int ACManager::creatServices()
{
	for (map<string,map<string,string> >::iterator ite = ACManager::m_keyMap.begin();ite != ACManager::m_keyMap.end(); ite++)
	{
		if(ite->second.find("@AUTOR@")==ite->second.end())
		{
			if(this->m_baseMessage.find("@AUTOR")!=this->m_baseMessage.end())
			{
				ite->second.insert(pair<string,string>("@AUTOR@",this->m_baseMessage.find("@AUTOR")->second));
			}
			else
			{
				ite->second.insert(pair<string,string>("@AUTOR@","DEFAULT"));
			}
		}
		if(ite->second.find("@RESULT_PATH@")==ite->second.end())
		{
			if(this->m_baseMessage.find("@RESULT_PATH")!=this->m_baseMessage.end())
			{
				ite->second.insert(pair<string,string>("@RESULT_PATH@",this->m_baseMessage.find("@RESULT_PATH")->second));
			}
			else
			{
				ite->second.insert(pair<string,string>("@RESULT_PATH@","./result/"));
			}
		}

		if(ite->second.find("@DATE@")==ite->second.end())
		{
			if(this->m_baseMessage.find("@TIME")!=this->m_baseMessage.end())
			{
				ite->second.insert(pair<string,string>("@DATE@",this->m_baseMessage.find("@TIME")->second));
			}
			else
			{
				ite->second.insert(pair<string,string>("@DATE@",n_acmanager::getNowDate()));
			}
		}

		ACService service(ite->second);
		service.printService();
	}
	return RETURN_SUCCESS;

}


//�滻�ַ�������
string n_acmanager::replaceString(string srcString ,string keyString ,string valueString)
{
	string::size_type currIndex=srcString.find(keyString);
	while(currIndex!=string::npos)
	{
		srcString.replace(currIndex,keyString.size(),valueString);
		currIndex=srcString.find(keyString,currIndex+valueString.size());
	}
	return srcString;
}

//����longת���ַ�������
string n_acmanager::longToString(long longVaiue)
{
	ostringstream ostringstre;
	ostringstre<<longVaiue;
	ostringstre.flush();
	return ostringstre.str();
}

string n_acmanager::getNowDate()
{
	time_t nowTime;
	nowTime=time(NULL);
	tm* current_time = localtime(&nowTime);

	string dataString="";
	dataString+=n_acmanager::longToString(current_time->tm_year+1900)+"��";
	dataString+=n_acmanager::longToString(current_time->tm_mon+1)+"��";
	dataString+=n_acmanager::longToString(current_time->tm_mday)+"��";

	return dataString;
}
