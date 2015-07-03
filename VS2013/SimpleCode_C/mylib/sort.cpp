#include"sort.h"


void quickPriSort(int data[], int start, int end, int* pCurrIndex)
{
	*pCurrIndex = start;
	int value = data[*pCurrIndex];

	while (start <= end)
	{
		while (start <= end)
		{
			if (data[start] > value)
			{
				break;
			}
			start++;
		}
		while (start <= end)
		{
			if (data[end] <= value)
			{
				break;
			}
			end--;
		}
		if (start < end)
		{
			data[end] ^= data[start];
			data[start] ^= data[end];
			data[end] ^= data[start];
			end--;
			start++;
		}
	}
	if (end >*pCurrIndex)
	{
		data[end] ^= data[*pCurrIndex];
		data[*pCurrIndex] ^= data[end];
		data[end] ^= data[*pCurrIndex];
		*pCurrIndex = end;
	}
}

void qkSort(int data[], int start, int end)
{
	int currIndex = start;
	if (start<end)
	{
		quickPriSort(data, start, end, &currIndex);
		qkSort(data, start, currIndex - 1);
		qkSort(data, currIndex + 1, end);
	}
}
