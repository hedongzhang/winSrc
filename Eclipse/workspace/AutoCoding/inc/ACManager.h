/*
 * ACManager.h
 *
 *  Created on: 2015��5��5��
 *      Author: HDZhang
 */

#ifndef INC_ACMANAGER_H_
#define INC_ACMANAGER_H_

#include<iostream>
#include<map>
#include<ctime>

using namespace std;

namespace n_acmanager
{
	class ACManager
	{
	private:
		//ϵͳ�����ļ�·��
		string configFile;

		/* �����������ֵ
		 * ���� AUTOR
		 * ������·�� RESULT_PATH
		 * ʱ�� TIME
		 */
		map<string,string> m_baseMessage;

		/* ������������Ϣ
		 * ������ SERVICE_NAME
		 * �������� SERVICE_TYPE
		 * ���� LIB_NAME
		 * SQL SQL_CONTEXT
		 * GROUP_ID
		 * CLASS_ID
		 * �ڵ��� INPUT_NODE OUTPUT_NODE
		 * ͷ�ļ�ģ�� HEAD_TEMPLATE_TYPE
		 * Դ�ļ�ģ�� SOURC_TEMPLATE_TYPE
		 */
		map<string,map<string,string> > m_keyMap;

		/*����ģ��ӳ��
		 *
		 */
		map<string,string> m_codeTemplateMap;

	public:
		ACManager(string configFile="./conf/config.ini");
		virtual ~ACManager();

		/**********������ʼ��**********
		 * ��ȡ�����ļ������������ļ�����ؼ�����ֵ������ؼ���ӳ���ģ��
		 * @�ַ�------ģ������
		 * һ���ַ�----ģ��·��
		 * #�ַ�------ע��
		 */
		int init();

		/**********��ӡ��ȡ�Ļ�����Ϣ**********
		 *
		 */
		void showBaseMessage();

		/**********�Զ����ɷ���**********
		 *
		 */
		int creatServices();


		//��ȡ������Ϣ
		int readConfig();
		//����·����ȡ�ؼ���ģ������
		int readKeyTemplate(string path);
		//����·����ȡ����ģ������
		int readCodeTemplate(string path);

		//��ȡ�ؼ�ֵ
		int getBaseMessage(const string keyName,string codeTemplate);
		//���ùؼ�ֵ
		int setBaseMessage(const string keyName,string codeTemplate);
		//��ȡ�ض��Ĺؼ���ӳ��
		int getKeyMap(const string keyName,map<string,string>& keyMap);
		//��ȡ�ض�����ģ��ӳ��
		int getCodeTemplateMap(const string keyName,string& codeTemplate);
		//����ؼ���ӳ��
		int setKeyMap(const string keyName,map<string,string> keyMap);
		//�������ģ��ӳ��
		int setCodeTemplateMap(const string keyName,string codeTemplate);
	};



	//����ֵ
	const int RETURN_FAILED=0;
	const int RETURN_SUCCESS=1;

	//�滻�ַ���
	string replaceString(string srcString ,string keyString ,string valueString);
	//longת��Ϊstring
	string longToString(long longVaiue);
	//��ȡ��ǰ����
	string getNowDate();
}



#endif /* INC_ACMANAGER_H_ */
