#include<windows.h>
#include<stdio.h>
#include"detours.h"

#pragma comment(lib,"detours.lib")

/////////
static int(WINAPI* pMessBox)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) = MessageBoxA;

static int(*pSystem)(const char * _Command) = system;

static BOOL (WINAPI* pCreateProcessWMy)(
	LPCWSTR lpApplicationName,
	LPWSTR lpCommandLine,
	LPSECURITY_ATTRIBUTES lpProcessAttributes,
	LPSECURITY_ATTRIBUTES lpThreadAttributes,
	BOOL bInheritHandles,
	DWORD dwCreationFlags,
	LPVOID lpEnvironment,
	LPCWSTR lpCurrentDirectory,
	LPSTARTUPINFOW lpStartupInfo,
	LPPROCESS_INFORMATION lpProcessInformation
	) = CreateProcessW;

static BOOL(WINAPI* pCreateProcessAMy)(
	 LPCSTR lpApplicationName,
	 LPSTR lpCommandLine,
	 LPSECURITY_ATTRIBUTES lpProcessAttributes,
	 LPSECURITY_ATTRIBUTES lpThreadAttributes,
	 BOOL bInheritHandles,
	 DWORD dwCreationFlags,
	 LPVOID lpEnvironment,
	 LPCSTR lpCurrentDirectory,
	 LPSTARTUPINFOA lpStartupInfo,
	 LPPROCESS_INFORMATION lpProcessInformation
	) = CreateProcessA;
////////�ҵ�ʵ��
int WINAPI MessageBoxMy(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType)
{
	printf("===��ĳ����ѱ��ҽٳ�!===\n");
	return 1;
}

int systemMy(const char * _Command)
{
	if (strcmp(_Command, "tasklist")==0)
	{
		printf("\n******������ִ�У�tasklist��******\n");
		return 0;
	}
	else
	{
		pSystem(_Command);
		return 1;
	}
}

BOOL WINAPI CreateProcessWMy(LPCWSTR lpApplicationName,LPWSTR lpCommandLine,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,BOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation)
{
	MessageBoxA(0,"���������ѱ��ٳ�","360",0);
	if (lpApplicationName != NULL)
	{
		if (strcmp(lpApplicationName, "360tray.exe") == 0)
		{
			pCreateProcessWMy(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
			return 1;
		}
	}
	return 0;
}

BOOL WINAPI CreateProcessAMy(LPCSTR lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	MessageBoxA(0, "���������ѱ��ٳ�", "360", 0);
	if (lpApplicationName != NULL)
	{
		if (strcmp(lpApplicationName, "360tray.exe") == 0)
		{
			pCreateProcessAMy(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
			return 1;
		}
	}
	return 0;
}
/////////
void main1()
{
	printf("%p\t\n", pSystem);
	printf("%p\t\n", system);
	system("dir");

	DetourRestoreAfterWith();		//�ָ�ԭ��״̬
	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourAttach((void**)&pSystem, systemMy);			//�ٳֺ���
	DetourTransactionCommit();

	printf("%p\t\n", pSystem);
	printf("%p\t\n", system);
	system("dir");

	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourDetach((void**)&pSystem, systemMy);			//�������غ���
	DetourTransactionCommit();				//������Ч

	printf("%p\t\n", pSystem);
	printf("%p\t\n", system);
	system("dir");
	getchar();
}

_declspec(dllexport)void go()
{
	MessageBoxA(0, "ע��ɹ���", "��ʾ��", 0);

	DetourRestoreAfterWith();		//�ָ�ԭ��״̬
	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourAttach((void**)&pCreateProcessWMy, CreateProcessWMy);			//�ٳֺ���
	DetourTransactionCommit();				//������Ч

	DetourRestoreAfterWith();		//�ָ�ԭ��״̬
	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourAttach((void**)&pCreateProcessAMy, CreateProcessAMy);			//�ٳֺ���
	DetourTransactionCommit();				//������Ч

	Sleep(60000);
	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourDetach((void**)&pCreateProcessWMy, CreateProcessWMy);			//�������غ���
	DetourTransactionCommit();				//������Ч

	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourDetach((void**)&pCreateProcessAMy, CreateProcessAMy);			//�������غ���
	DetourTransactionCommit();				//������Ч
}
//�ٳ�
void hook(PVOID OldMethod, PVOID nowMethod)
{
	DetourRestoreAfterWith();		//�ָ�ԭ��״̬
	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourAttach((void**)&OldMethod, nowMethod);			//�ٳֺ���
	DetourTransactionCommit();				//������Ч
}

//ȡ���ٳ�
void unhook(PVOID OldMethod, PVOID nowMethod)
{
	DetourTransactionBegin();			//��ʼ����
	DetourUpdateThread(GetCurrentThread());			//ˢ�µ�ǰ�߳�

	DetourDetach((void**)&OldMethod, nowMethod);			//�������غ���
	DetourTransactionCommit();				//������Ч
}