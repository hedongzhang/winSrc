#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<deque>
#include"LinkQueue.h"
#include"linkQueue.h"
#include"sort.h"

#pragma comment(lib, "mylib.lib")

int main()
{
	int data[7] = {2,7,9,4,7,6,1};
	qkSort(data, 0, 6);

	for (size_t i = 0; i < 7; i++)
	{
		printf("%d\n", data[i]);
	}
	
	system("pause");
}