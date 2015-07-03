#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>

void met(int num, ...)
{
	va_list v;
	va_start(v, num);
	for (size_t i = 0; i < num; i++)
	{
		int data = va_arg(v, int);
		printf("%d\n", data);
	}
	va_end(v);

}