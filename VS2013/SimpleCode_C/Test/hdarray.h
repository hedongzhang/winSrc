#ifndef HDARRAY_H
#define HDARRAY_H

struct strdata
{
	char **pData;
	int length;
};

//��ʼ��
int init(struct  strdata* data);
//���³�ʼ��
int reinit(struct  strdata* data);

//����һ������
int add(struct  strdata* data, char* addvalue);
//����һ������
int addobject(struct  strdata* data, char*dataobj[], int num);

//����ĳ��ֵ,���ص�һ��λ������
int findfirst(struct  strdata* data, char* value);
//����ĳ��ֵ,���ص����и�λ������--�����ڴ���Ҫ��ʹ�����ͷ�
int* find(struct  strdata* data, char* value);
//ɾ�������е�һ������ֵ
int removefirst(struct  strdata* data, char* value);
//ɾ�����������и���ֵ
int remov(struct  strdata* data, char* value);

//�޸�ĳֵ
int change(struct  strdata* data, char* oldvalue, char* newvalue);

//����ĳλ��ֵ
int insert(struct  strdata* data, int index, char* newvalue);

//��ӡ�ַ�������
void print(struct  strdata* data);


#endif    //HDARRAY_H



/*array code
struct strdata  strayyay = { 0 };
init(&strayyay);
add(&strayyay, "1345");
char* arr[6] = { "345", "btb", "66rw", "9s5", "btb", "l0jybh" };
addobject(&strayyay, arr, 6);
print(&strayyay);

printf("\n");
remov(&strayyay, "btb");
print(&strayyay);

char* pstr = (char*)malloc(10 * sizeof(char));
strcpy(pstr, "123445");
change(&strayyay, "btb", pstr);
printf("\n");
print(&strayyay);

insert(&strayyay, 3,"qqq");
printf("\n");
print(&strayyay);

insert(&strayyay, 7, "vrsbytnuytrbvgbthnrybgrv");
printf("\n");
print(&strayyay);*/
