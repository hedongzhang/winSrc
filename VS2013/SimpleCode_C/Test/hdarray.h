#ifndef HDARRAY_H
#define HDARRAY_H

struct strdata
{
	char **pData;
	int length;
};

//初始化
int init(struct  strdata* data);
//重新初始化
int reinit(struct  strdata* data);

//增加一个数据
int add(struct  strdata* data, char* addvalue);
//增加一个数组
int addobject(struct  strdata* data, char*dataobj[], int num);

//查找某个值,返回第一个位置索引
int findfirst(struct  strdata* data, char* value);
//查找某个值,返回第所有个位置索引--返回内存需要由使用者释放
int* find(struct  strdata* data, char* value);
//删除数组中第一个给定值
int removefirst(struct  strdata* data, char* value);
//删除数组中所有给定值
int remov(struct  strdata* data, char* value);

//修改某值
int change(struct  strdata* data, char* oldvalue, char* newvalue);

//插入某位置值
int insert(struct  strdata* data, int index, char* newvalue);

//打印字符串数组
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
