#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>

//int×ª×Ö·û´®
void inttostr(int curnum,char** str )
{
	if (curnum!= 0)
	{
		inttostr(curnum / 10,str);
		**str = curnum % 10 + 48;
		(*str)++;
	}
}
//double×ª×Ö·û´®
void doutostr(double currnum,char* str)
{
	//a = 10;
	if (currnum == 0)
	{
		*str = '\0';
	}
	else if (currnum>0)
	{
		int currInt = 10 * currnum;
		*str = currInt + 48;
		doutostr(currnum * 10 - currInt, str + 1);
	}
}

//×Ö·û´®×ªdouble
double strtodouble(char* str)
{
	if (str == NULL || *str > '9' || *str < '0')
	{
		return 0;
	}
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return  0.1*( ( strtodouble(str+1) ) + (*str-48));
	}
}
//×Ö·û´®×ªint
int strtoint(char* str,int currValue)
{
	if (str == NULL)
	{
		return 0;
	} 
	if (*str == '\0' || *str > '9' || *str < '0')
	{
		return currValue;
	}
	else
	{
		return strtoint(str + 1, currValue * 10 + (*str - 48));
	}
}
//×Ö·û´®×ªdouble
double stringtodouble(char* numStr)
{
	if (numStr == NULL)
	{
		return 0;
	}

	double returnValue=0;
	char* start = numStr;
	char* point = numStr;
	bool isFushu = false;

	if (*point == '-')
	{
		isFushu = true;
		start++;
	}
	while (*point != '\0' && *point != '.')
	{
		point++;
	}
	if (*point == '.')
	{
		*point = '\0';
		returnValue = strtoint(start, 0) + strtodouble(point + 1);
	}
	else
	{
		returnValue = strtoint(start, 0);
	}
	if (isFushu)
	{
		returnValue = -returnValue;
	}
	return returnValue;
}

void main2()
{
	while (1)
	{
		double value = 0;
		char numStr[20] = {"0."};
		scanf("%lf", &value);

		char* temp = numStr;
		//doutostr(value, temp+2);
		//value = stringtodouble((char*)numStr);
		
		printf("%s\n", numStr);

		system("pause");
	}
}
