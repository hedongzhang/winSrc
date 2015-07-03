#define _CRT_SECURE_NO_WARNINGS
#include"hdarray.h"
#include<malloc.h>
#include<string.h>
#include<stdio.h>


int init(struct  strdata* data)
{
	if (data != nullptr)
	{
		data->length = 0;
		data->pData = nullptr;
		return 1;
	}
	else
	{
		return 0;
	}
};

int reinit(struct  strdata* data)
{
	if (data != nullptr)
	{
		while (data->length != 0)
		{
			free(data->pData[data->length--]);
		}
		free(data->pData);
		data->pData = nullptr;
		data->length = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

int add(struct  strdata* data, char* addvalue)
{
	if (data != nullptr && addvalue != nullptr)
	{
		char* pTemp = (char*)calloc(strlen(addvalue) + 1, sizeof(char));
		strcpy(pTemp, addvalue);

		if (data->pData == nullptr)
		{
			data->pData = (char**)malloc(sizeof(char*));
			*(data->pData) = pTemp;
			data->length++;
		}
		else
		{
			data->pData = (char**)realloc(data->pData, sizeof(char*)*(data->length + 1));
			if (data->pData != nullptr)
			{
				data->pData[++(data->length)] = pTemp;
			}
			else
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int addobject(struct  strdata* data, char*dataobj[], int num)
{
	if (data != nullptr && dataobj != nullptr)
	{
		data->pData = (char**)realloc(data->pData, sizeof(char*)*(data->length + num));
		if (data->pData == nullptr)
		{
			return -1;
		}
		for (size_t i = 0; i < num; i++)
		{
			char* pTemp = (char*)calloc(strlen(dataobj[i]) + 1, sizeof(char));
			strcpy(pTemp, dataobj[i]);
			data->pData[(data->length)++] = pTemp;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

//查找某个值,返回第一个位置索引
int findfirst(struct  strdata* data, char* value)
{
	if (data != nullptr && data->length!=0)
	{
		for (size_t currIndex = 0; currIndex < data->length; currIndex++)
		{
			if (strcmp(*(data->pData + currIndex),value)==0)
			{
				return currIndex;
			}
		}
	}
	return -1;
}
//查找某个值,返回第所有个位置索引--返回内存需要由使用者释放
int* find(struct  strdata* data, char* value,int* num)
{
	if (data != nullptr && data->length != 0)
	{
		*num = 0;
		int* pIndexs = nullptr;
		for (size_t currIndex = 0; currIndex < data->length; currIndex++)
		{
			if (strcmp(*(data->pData + currIndex), value) == 0)
			{
				(*num)++;
				if ((*num) == 1)
				{
					pIndexs = (int*)calloc((*num), sizeof(int));
				}
				else
				{
					pIndexs = (int*)realloc(pIndexs, (*num)*sizeof(int));
				}
				pIndexs[(*num)-1] = currIndex;
			}
		}
		return pIndexs;
	}
	return nullptr;
}
//删除数组中第一个给定值
int removefirst(struct  strdata* data, char* value)
{
	int index = findfirst(data, value);
	free(*(data->pData + index));
	if (index!=0)
	{
		for (size_t i = index; i < data->length-1; i++)
		{
			*(data->pData + i) = *(data->pData + i + 1);
		}
		data->length--;
	}
	return 0;
}
//删除数组中所有给定值
int remov(struct  strdata* data, char* value)
{
	int num = 0;
	int* pIndexs = find(data, value, &num);
	for (size_t i = 0; i < num; i++)
	{
		/*int index = pIndexs[i];
		for (size_t i = index; i < data->length - 1; i++)
		{
			*(data->pData + i) = *(data->pData + i + 1);
		}
		data->length--;*/
		removefirst(data,value);
	}
	free(pIndexs);
	return 1;
}

//修改某值
int change(struct  strdata* data, char* oldvalue, char* newvalue)
{
	if (data != nullptr && oldvalue != nullptr && newvalue != nullptr)
	{
		size_t index = findfirst(data, oldvalue);
		while (index != -1)
		{
			free(data->pData[index]);
			data->pData[index] = newvalue;
			index = findfirst(data, oldvalue);
		}
		return 1;
	}
	return 0;
}

//插入某位置值
int insert(struct  strdata* data, int index, char* newvalue)
{
	if (data == nullptr || newvalue == nullptr)
	{
		return 0;
	}
	if (index < data->length)
	{
		int size = ++data->length;
		data->pData = (char**)realloc(data->pData, sizeof(char*)*size);
		int currIndex = data->length - 1;
		while (currIndex>index)
		{
			data->pData[currIndex] = data->pData[currIndex - 1];
			currIndex--;
		}
		data->pData[index] = newvalue;
		return 1;
	}
	else if (index == data->length)
	{
		add(data, newvalue);
		return 1;
	}
	else
	{
		return 0;
	}
}

void print(struct  strdata* data)
{
	if (data != nullptr && data->length != 0)
	{
		for (size_t currIndex = 0; currIndex < data->length; currIndex++)
		{
			printf("%s\n", *(data->pData + currIndex));
		}
	}
	else
	{
		return;
	}
	{

	};
}
