#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>

typedef void(*pmet)();

char jiamiChar(char minChar,char key)
{
	/*if (minChar!=key && minChar != 0)
	{*/
		minChar^=key;
	//}
	return minChar;
}

char* jiamiStr(char* password,char* mingwen)
{
	char* pMiWen =(char*) calloc( sizeof(char),1024);
	strncpy(pMiWen, mingwen, 1024);
	int lenpass = strlen(password);
	int lenmiwen = strlen(mingwen);

	if (lenmiwen%lenpass==0)
	{
		int count = lenmiwen / lenpass;
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < lenpass; j++)
			{
				int index = i*lenpass + j;
				if (mingwen[index] != password[j])
				{
					pMiWen[index] = mingwen[index] ^ password[j];
				}
			}
		}
	}
	else
	{
		int count = lenmiwen / lenpass;
		int endCount = lenmiwen % lenpass;
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < lenpass; j++)
			{
				int index = i*lenpass + j;
				if (mingwen[index] != password[j])
				{
					pMiWen[index] = mingwen[index] ^ password[j];
				}
			}
		}
		for (size_t i = 0; i < endCount; i++)
		{
			int index = count*lenpass + i;
			if (mingwen[index] != password[i])
			{
				pMiWen[index] = mingwen[index] ^ password[i];
			}
		}
	}
	return pMiWen;
}

char jiemiStr(char password, char* miwen)
{
	return password;
}


int jiaMiFile(char* srcFile,char* objFile,char* key)
{
	FILE* pReadFile = fopen(srcFile, "rb");
	FILE* pWriteFile = fopen(objFile, "wb");

	if (pReadFile&&pWriteFile)
	{
		printf("打开文件成功！\n");

		int keyLen = strlen(key);
		int currIndex = 0;

		while (1)
		{
			char minWen = fgetc(pReadFile);
			if (feof(pReadFile))
			{
				break;
			}
			//printf("明文：%d\n", minWen);
			char miWen = jiamiChar(minWen, key[currIndex%keyLen]);
			//printf("密文：%d\n", miWen);
			fputc(miWen, pWriteFile);
			currIndex++;
		}
		fclose(pWriteFile);
		fclose(pReadFile);
		printf("加密成功！\n");
		return 1;
	}
	else
	{
		printf("打开文件失败！\n");
		printf("加密失败！\n");
		return 0;
	}
}

int jieMiFile(char* srcFile, char* objFile, char* key)
{
	FILE* pReadFile = fopen(srcFile, "rb");
	FILE* pWriteFile = fopen(objFile, "wb");

	if (pReadFile&&pWriteFile)
	{
		printf("打开文件成功！\n");

		int keyLen = strlen(key);
		int currIndex = 0;

		while (1)
		{
			char minWen = fgetc(pReadFile);
			if (feof(pReadFile))
			{
				break;
			}
			//printf("明文：%c\n", minWen);
			char miWen = jiamiChar(minWen, key[currIndex%keyLen]);
			//printf("密文：%c\n", miWen);
			fputc(miWen, pWriteFile);
			currIndex++;
		}
		fclose(pWriteFile);
		fclose(pReadFile);
		printf("解密成功！\n");
		return 1;
	}
	else
	{
		printf("打开文件失败！\n");
		printf("解密失败！\n");
		return 0;
	}
}

int main6()
{
	char key[256] = { 0 };
	printf("请输入加密密码：");
	scanf("%s", key);
	while (strcmp(key,"-1")!=0)
	{
		jiaMiFile("C:\\Users\\HDZhang\\Desktop\\TextDiff.exe", "C:\\Users\\HDZhang\\Desktop\\miwen.txt", key);

		printf("请输入解密密码：");
		scanf("%s", key);
		jiaMiFile("C:\\Users\\HDZhang\\Desktop\\miwen.txt", "C:\\Users\\HDZhang\\Desktop\\out.txt", key);

		printf("请输入加密密码：");
		scanf("%s", key);
	}
	
	system("pause");
	return 0;
}