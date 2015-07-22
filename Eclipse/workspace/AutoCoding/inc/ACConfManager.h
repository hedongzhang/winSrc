/*
 * ACConfManager.h
 *
 *  Created on: 2015��5��4��
 *      Author: HDZhang
 */

#ifndef INC_ACCONFMANAGER_H_
#define INC_ACCONFMANAGER_H_

#include<vector>
#include<map>
#include<set>
#include"ACManager.h"
#include"ACService.h"
/*
 * ��Ҫ���ܣ���������ļ������ɹ���
 *
 *
 */

class ACConfManager
{
public:
	//�������ļ�·����ʼ����
	ACConfManager(ACService& service);
	//��ȡCrmdemFml32�ļ�
	int readCrmdemFml32();
	//��ȡMetadataIn�ļ�
	int readMetadataIn();
	/* ���������ļ�
	 *
	 */
	int complateConfig(ACService& service);

	//����crmdem.fml32�ļ�������δд����ֶ�д��
	int parseCrmdemFml32(ACService& service);
	//д��CrmdemFml32�ļ�
	int writeCrmdemFml32(Field& Field);
	//����metadata.in�ļ���������������д��
	int parseMetadataIn(ACService& service);
	//д��metadata.in�ļ�
	int writeMetadataIn(string serverTemp,string serviceName);

private:
	string crmdemFileName;
	string metadataFileName;
	map<string,Field> m_allFileMess;
	set<string> s_services;
	int maxFieldNum;


	const string serviceTemp="\nservice=@SERVICE@\n"
						"export=y\n"
						"servicetype=atom\n"
						"inbuf=FML32\n"
						"outbuf=FML32\n"
						"tuxservice=@SERVICE@\n";

	const string nodeTemp="\tparam=@NODE@\n"
					 "\ttype=fml32\n"
					 "\taccess=@ACCESS@\n"
					 "\tsize=@SIZE@\n"
					 "\trequiredcount=0\n"
					 "\tcount=0\n"
					 "\t(\n"
					 "@FIELDS@\n"
					 "\t)\n\n";

	const string fieldTemp1="\tparam=@PARAM@\n"
					 "\ttype=@TYPE@\n"
					 "\taccess=@ACCESS@\n"
					 "\tsize=@SIZE@\n"
					 "\trequiredcount=1\n"
					 "\tcount=1\n\n";

	const string fieldTemp2="\t\tparam=@PARAM@\n"
						 "\t\ttype=@TYPE@\n"
						 "\t\taccess=@ACCESS@\n"
						 "\t\tsize=@SIZE@\n"
						 "\t\trequiredcount=1\n"
						 "\t\tcount=1\n\n";

};



#endif /* INC_ACCONFMANAGER_H_ */
