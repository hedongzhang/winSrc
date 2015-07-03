/*
 * ACCodeManager.h
 *
 *  Created on: 2015年5月14日
 *      Author: HDZhang
 */

#ifndef INC_ACCODEMANAGER_H_
#define INC_ACCODEMANAGER_H_

#include"ACService.h"

using namespace std;

class ACCodeManager
{
public:
	ACCodeManager(ACService service);

	int init();

	int start();

	int creatHeadFile();

	int creatSrcFile();

	string creatInputFields();

	string creatOutputFields();

	string creatGetInputParam();

	string creatBusinessProcess();

	string creatSetOutputParam();

private:
	ACService service;
	string coreClassName;		//用于替换关键字
	string upperClassName;		//用于替换头文件预定义宏关键字

	string headInputPath;		//头文件输入路径
	string headOutputPath;		//头文件输出路径

	string srcInputPath;		//源文件输入路径
	string srcOutputPath;		//源文件输出路径


	const string paramTmplString="\n"
			"\t\tif(pTuxBuffer->GetValue(\"@FIELD_NAME@\",st@CORE_CLASS_NAME@In.@FIELD_NAME@)<0)\n"
			"\t\t{\n"
				"\t\t\tCRM_LOG((LC_DEBUG,\"get parameter[@FIELD_NAME@]  failed\"));\n"
				"\t\t\treturn -1;\n"
			"\t\t}\n"
			"\t\tCRM_LOG((LC_DEBUG,\"get parameter[@FIELD_NAME@]  is %s\",st@CORE_CLASS_NAME@In.@FIELD_NAME@));\n\n";

	const string paramTmplLong="\n"
			"\t\tif(pTuxBuffer->GetValue(\"@FIELD_NAME@\",(char*)&st@CORE_CLASS_NAME@In.@FIELD_NAME@)<0)\n"
			"\t\t{\n"
				"\t\t\tCRM_LOG((LC_DEBUG,\"get parameter[@FIELD_NAME@]  failed\"));\n"
				"\t\t\treturn -1;\n"
			"\t\t}\n"
			"\t\tCRM_LOG((LC_DEBUG,\"get parameter[@FIELD_NAME@]  is %ld\",st@CORE_CLASS_NAME@In.@FIELD_NAME@));\n\n";

	const string inputTempHead="\
	pTuxBufferAll->RsOpen();\n\
	\n\
	while(pTuxBufferAll->RsFetchRow())\n\
	{\n\
		DCTuxBuffer *pTuxBuffer = NULL;\n\
		int ret = pTuxBufferAll->RsGetNestedCol(\"@NODE_NAME@\",(DCBuffer**)&pTuxBuffer);\n\
		if (ret == 0)\n\
		{\n\
			continue;\n\
		}\n\
		\n\
		if (ret < 0)\n\
		{\n\
			CRM_LOG((LC_ERROR,\"get parameter[@NODE_NAME@] failed\"));\n\
			this->SetErrorMsg(CRM_ERROR_SERVICE_GETINPUT_FAILED,\"get parameter[@NODE_NAME@] failed\");\n\
			return CRM_ERROR_SERVICE_GETINPUT_FAILED;\n\
		}\n";

	const string outParamTmplLong1="\n\
	pTuxBuffer->SetValue(\"@FIELD_NAME@\", (char*)&iter->@FIELD_NAME@);\n\
	CRM_LOG((LC_DEBUG,\"get output param @FIELD_NAME@[%ld]\",iter->@FIELD_NAME@));\n";

	const string outParamTmplString1="\n\
	pTuxBuffer->SetValue(\"@FIELD_NAME@\", iter->@FIELD_NAME@);\n\
	CRM_LOG((LC_DEBUG,\"get output param @FIELD_NAME@[%s]\",iter->@FIELD_NAME@));\n";

	const string outputTempHead="\n\
	char Fml32Tag[32] = \"@NODE_NAME@\";\n\
\n\
	DCTuxBuffer *pOutBuffer = (DCTuxBuffer *)pTuxBuffer->CreateNesteBuffer(Fml32Tag,l_@CORE_CLASS_NAME@Out.size()*sizeof(ST@CORE_CLASS_NAME@Out),SEND_BUF);\n\
	if (pOutBuffer == NULL)\n\
	{\n\
		CRM_LOG((LC_ERROR,\"create nested buffer [%s] failed\",Fml32Tag));\n\
		this->SetErrorMsg(CRM_ERROR_BUFPTR_ISNULL,\"create nested buffer [%s] failed\",Fml32Tag);\n\
		return -1;\n\
	}\n\
\n\
	list<ST@CORE_CLASS_NAME@Out>::iterator iter;\n\
	pOutBuffer->RsOpen();\n\
	for (iter=l_@CORE_CLASS_NAME@Out.begin(); iter!=l_@CORE_CLASS_NAME@Out.end(); iter++)\n\
	{\n\
		pOutBuffer->RsAddRow();\n";

	const string outParamTmplLong2="\n\
		pOutBuffer->RsSetCol(\"@FIELD_NAME@\",(char*)&iter->@FIELD_NAME@,sizeof(long));\n\
		CRM_LOG((LC_DEBUG,\"get output param @FIELD_NAME@[%ld]\",iter->@FIELD_NAME@));\n";

	const string outParamTmplString2="\n\
		pOutBuffer->RsSetCol(\"@FIELD_NAME@\", iter->@FIELD_NAME@);\n\
		CRM_LOG((LC_DEBUG,\"get output param @FIELD_NAME@[%s]\",iter->@FIELD_NAME@));\n";

	const string outputTempEnd="\n\
		pOutBuffer->RsSaveRow();\n\
	}\n\
	pTuxBuffer->SetfValue(Fml32Tag,pOutBuffer);\n";


	const string bissnessProcessHead="\n\
	int nErrorCode = 0;\n\
	int class_id = @SERVICE_NAME@_DEF;\n\
\n\
	list<ST@CORE_CLASS_NAME@In>::iterator iter=l_@CORE_CLASS_NAME@In.begin();\n\
	for(;iter!=l_@CORE_CLASS_NAME@In.end();iter++)\n\
	{\n\
		long nLATN_ID=@LATN_ID@;\n\
\n\
		string extraSQL=\"\";\n\
\n\
		DCCrmDBAgent dbAgent;\n\
		if (InitDBAgent(&dbAgent, class_id, true, nLATN_ID, nLATN_ID,extraSQL) < 0) {\n\
			return -1;\n\
		}\n\
\n\
		if ((nErrorCode = dbAgent.BindParam((void*)&(*iter))) < 0) {\n\
			CRM_LOG((LC_ERROR,\"Bind SQL[%ld] failed %s\", class_id, dbAgent.GetErrorMsg()));\n\
			this->SetErrorMsg(nErrorCode, \"Bind SQL[%ld] failed \", class_id);\n\
			return -1;\n\
		}\n";


	const string bissnessProcessEnd1="\n\
\n\
		DCDataSet *pDataSet = dbAgent.Open();\n\
		if (NULL == pDataSet) {\n\
			CRM_LOG((LC_ERROR,\"Execute SQL[%ld] failed %s\", class_id, dbAgent.GetErrorMsg()));\n\
			this->SetErrorMsg(CRM_ERROR_EXE_SQl_FAILED, \"Execute SQL[%ld] failed \", class_id);\n\
			return -1;\n\
		}\n\
\n\
		int row = 0;\n\
		ST@CORE_CLASS_NAME@Out offersOut[DEF_PAGE_SIZE] = {0};\n\
\n\
		while ((row = pDataSet->GetRows((void*) offersOut, DEF_PAGE_SIZE)) > 0) {\n\
			l_@CORE_CLASS_NAME@Out.insert(l_@CORE_CLASS_NAME@Out.end(),\n\
					offersOut, offersOut + row);\n\
			m_nRowTotal += row;\n\
		}\n\
\n\
		if (row < 0) {\n\
			CRM_LOG((LC_ERROR,\"Get dataset failed for sql [%ld]\",class_id));\n\
			this->SetErrorMsg(CRM_ERROR_DATASET_FAILED, \"Get dataset failed for sql [%ld]\", class_id);\n\
			return -1;\n\
		}\n\
\n\
		m_nRowTotal = dbAgent.GetTotalCount();\n\
	}";


	const string bissnessProcessEnd2="\n\
		if (!dbAgent.Execute())\n\
		{\n\
			CRM_LOG((LC_ERROR,\"execute sql failed for group user list query\"));\n\
			SetErrorMsg(nErrorCode,\"execute sql[%ld] failed\",class_id);\n\
			return CRM_ERROR_EXE_SQl_FAILED;\n\
		}\n\
	}";

};



#endif /* INC_ACCODEMANAGER_H_ */