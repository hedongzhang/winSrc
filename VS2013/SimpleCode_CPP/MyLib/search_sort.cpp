#include<iostream>

using namespace std;
//����������Ա
void swap(int data[], int first, int end)
{
	if (first != end)
	{
		data[first] ^= data[end];
		data[end] ^= data[first];
		data[first] ^= data[end];
	}
}

//�۰����
int search(int data[],int first,int end,int key)
{
	if (first >= end)
	{
		return -1;
	}
	else
	{
		//int curr = (first + end) / 2;
		int curr = first + (end - first)*(key - data[first]) / (data[end] - data[first]);
		if (data[curr] == key)
		{
			return curr;
		}
		else if (data[curr]>key)
		{
			return search(data, first, curr-1, key);
		}
		else
		{
			return search(data, curr + 1, end, key);
		}
	}
}

//ð������
void bubble_sort(int data[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j > 0;j --)
		{
			if (data[j]<data[j-1])
			{
				swap(data, j, j - 1);
			}
		}
	}
}

//ѡ������
void select_sort(int data[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		int min_index =i;
		for (int curr_index = i; curr_index < size; curr_index++)
		{
			if (data[curr_index] < data[min_index])
			{
				min_index = curr_index;
			}
		}
		if (min_index!=i)
		{
			swap(data,min_index, i);
		}
	}
}

//��������
void insert_sort(int data[], int size)
{
	//ѭ��ÿ��Ԫ��
	for (size_t i = 1; i < size; i++)
	{
		//���ö��ֲ��ң��ҵ�ǰ�����������е�һ������iԪ�ص�λ��curr
		int first = 0,end=i-1;
		while (first<=end)
		{
			int curr = (first + end) / 2;
			if (data[curr]>data[i] && data[curr-1]<data[i])
			{
				//����i��Ԫ�ز��뵽�ҵ���currλ��
				for (size_t k = i; k >curr; k--)
				{
					swap(data, k, k - 1);
				}
				break;
			}
			else if (data[curr] > data[i])
			{
				end = curr - 1;
			}
			else
			{
				first = curr + 1;
			}
		}

		//һ��ѭ������ǰ�����������е�һ������iԪ�ص�λ��
		/*for (size_t j = 0; j < i; j++)
		{
			if (data[j]>data[i])
			{
				for (size_t k = i; k >j; k--)
				{
					swap(data, k, k - 1);
				}
				break;
			}
		}*/
	}
}

//ϣ������
void shell_sort(int data[], int size)
{
	for(int step = size/2 ; step > 0; step /= 2)
	{
		for (int curr_group_start = 0; curr_group_start < step; curr_group_start++)
		{
			int curr_group_index = curr_group_start+step;
			while (curr_group_index<size)
			{
				int curr_index_temp = curr_group_index;
				while (curr_index_temp>0)
				{
					if (data[curr_index_temp] < data[curr_index_temp - step])
					{
						swap(data, curr_index_temp, curr_index_temp - step);
					}
					curr_index_temp -= step;
				}
				curr_group_index += step;
			}
		}
	}
}

//�鲢����
void m_sort(int data_first[], int first, int middle, int last, int data_temp[]);
void merge_sort(int data[], int first,int last, int data_temp[])
{
	if (first<last)
	{
		int middle = (first + last) / 2;
		merge_sort(data, first, middle, data_temp);
		merge_sort(data, middle+1,last, data_temp);
		//m_sort(data, middle-first+1,data+middle-first+1,last-middle,data_temp);
		m_sort(data, first, middle,last, data_temp);
	}
}
void m_sort(int data_first[], int first,int middle,int last, int data_temp[])
{
	int index_first = first;
	int index_second = middle+1;
	int index_temp = 0;

	while (index_first<=middle && index_second<=last)
	{
		if (data_first[index_first]<data_first[index_second])
		{
			data_temp[index_temp++] = data_first[index_first++];
		}
		else
		{
			data_temp[index_temp++] = data_first[index_second++];
		}
	}
	while (index_first<=middle)
	{
		data_temp[index_temp++] = data_first[index_first++];
	}
	while (index_second<=last)
	{
		data_temp[index_temp++] = data_first[index_second++];
	}

	for (size_t i = 0; i < index_temp; i++)
	{
		data_first[first+i] = data_temp[i];
	}
}
//void m_sort(int data_first[], int size_first, int data_second[], int size_second,int data_temp[])
//{
//	int index_first = 0, index_second = 0, index_temp = 0;
//	while (index_first<size_first && index_second<size_second)
//	{
//		if (data_first[index_first]<data_second[index_second])
//		{
//			data_temp[index_temp++] = data_first[index_first++];
//		}
//		else
//		{
//			data_temp[index_temp++] = data_second[index_second++];
//		}
//	}
//	while (index_first<size_first)
//	{
//		data_temp[index_temp++] = data_first[index_first++];
//	}
//	while (index_second<size_second)
//	{
//		data_temp[index_temp++] = data_second[index_second++];
//	}
//}

//��������
int q_sort(int data[], int first, int end);
void quick_sort(int data[], int first,int end)
{
	if (first<end)
	{
		int curr_pos=q_sort(data, first, end);
		quick_sort(data, first, curr_pos-1);
		quick_sort(data, curr_pos+1,end);
	}
}
int q_sort(int data[], int first, int end)
{
	int curr_num = data[first];
	while (first<end)
	{
		while (first<end && curr_num <= data[end])
		{
			end--;
		}
		swap(data,first,end);
		while (first<end && curr_num >= data[first])
		{
			first++;
		}
		swap(data, first, end);
	}
	return first;
}

//������г�Ա
void print(int data[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << data[i]<<"\t";
	}
	cout << endl;
}

int mainPX()
{
	int data[10] = { 23, 90, 4, 555, 10, 1, 56, 3, 123, 7 };
	print(data, 10);

	bubble_sort(data, 10);
	print(data, 10);

	/*shell_sort(data, 10);
	print(data, 10);*/

	//int data_new[10] = { 0 };
	//merge_sort(data, 0, 9, data_new);
	//print(data_new, 10);


	//quick_sort(data, 0, 9);
	//insert_sort(data, 10);
	//print(data, 10);

	

	system("pause");
	return 0;
}