#define  _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>

int openQQ(char* path)
{
	ShellExecuteA(0, "open", path, 0, 0, 0);
	return 1;
}

int closeQQ()
{
	system("taskkill /f /im QQ.exe");
	return 1;
}

int setQQPos(char* className, char* title,int x,int y)
{
	HWND win;
	win = FindWindow(className, title);
	if (win == NULL)
	{
		printf("QQÃ»¿ªÆô£¡");
		return 0;
	}
	else
	{
		//printf("ÒÆ¶¯QQ£¡");
		SetWindowPos(win, NULL, x, y, 300, 400, 1);
	}
	return 1;
}

int moveQQ(char* className, char* title)
{
	setQQPos(className, title, 0, 0);

	int x = 0, y = 0;
	int xSymbol = 5, ySymbol = 5;

	while (1)
	{
		x += xSymbol;
		y += ySymbol;
		if (setQQPos(className, title, x, y) == 0)
		{
			return -1;
		}
		
		if (x <= 0 || x >= 1366)
		{
			xSymbol = -xSymbol;
		}
		if (y <= 0 || y >= 768)
		{
			ySymbol = -ySymbol;
		}
		Sleep(10);
	}
	return 0;
}

void main()
{
	Sleep(1000);
	moveQQ("TXGuiFoundation", "QQ");

	system("pause");
}

