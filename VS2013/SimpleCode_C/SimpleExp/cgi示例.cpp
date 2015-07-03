#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct stru
{
	char c1;
	short s1;
	int i1;
	char str[7];
}st = { 'A', 1, 1, "AAAA" };;

struct stru1
{
	char c1;
	int i1;
	short s1;
	char str[7];
}st1 = {'A',1,1,"AAAA"};

void main5()
{	
	printf("Content-type:text/html\n\n");
	printf("<html>");
	printf("<body>");

	char str[256] = { 0 };
	char key[256] = { 0 };
	char cmd[256] = { 0 };

	gets(str);
	printf("\n%s\n\n", str);

	 char* pStart=strstr(str, "doc=")+4;
	 int count = 0;
	 while (*pStart != '&')
	 {
		 key[count] = *pStart++;
		 count++;
	 }
	 sprintf(cmd,"%s>1.txt", key);
	 system(cmd);

	 FILE* pFile = fopen("./1.txt","r");
	 while (!feof(pFile))
	 {
		 char strtemp[256] = { 0 };
		 fgets(strtemp, 256, pFile);
	      printf("%s<br>\n", strtemp);
	 }
	 fclose(pFile);

	printf("</body>");
	printf("</html>");

}