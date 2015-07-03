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
////////我的实现
int WINAPI MessageBoxMy(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType)
{
	printf("===你的程序已被我劫持!===\n");
	return 1;
}

int systemMy(const char * _Command)
{
	if (strcmp(_Command, "tasklist")==0)
	{
		printf("\n******不允许执行：tasklist！******\n");
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
	MessageBoxA(0,"创建进程已被劫持","360",0);
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
	MessageBoxA(0, "创建进程已被劫持", "360", 0);
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

	DetourRestoreAfterWith();		//恢复原来状态
	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourAttach((void**)&pSystem, systemMy);			//劫持函数
	DetourTransactionCommit();

	printf("%p\t\n", pSystem);
	printf("%p\t\n", system);
	system("dir");

	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourDetach((void**)&pSystem, systemMy);			//撤销拦截函数
	DetourTransactionCommit();				//拦截生效

	printf("%p\t\n", pSystem);
	printf("%p\t\n", system);
	system("dir");
	getchar();
}

_declspec(dllexport)void go()
{
	MessageBoxA(0, "注入成功！", "提示！", 0);

	DetourRestoreAfterWith();		//恢复原来状态
	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourAttach((void**)&pCreateProcessWMy, CreateProcessWMy);			//劫持函数
	DetourTransactionCommit();				//拦截生效

	DetourRestoreAfterWith();		//恢复原来状态
	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourAttach((void**)&pCreateProcessAMy, CreateProcessAMy);			//劫持函数
	DetourTransactionCommit();				//拦截生效

	Sleep(60000);
	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourDetach((void**)&pCreateProcessWMy, CreateProcessWMy);			//撤销拦截函数
	DetourTransactionCommit();				//拦截生效

	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourDetach((void**)&pCreateProcessAMy, CreateProcessAMy);			//撤销拦截函数
	DetourTransactionCommit();				//拦截生效
}
//劫持
void hook(PVOID OldMethod, PVOID nowMethod)
{
	DetourRestoreAfterWith();		//恢复原来状态
	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourAttach((void**)&OldMethod, nowMethod);			//劫持函数
	DetourTransactionCommit();				//拦截生效
}

//取消劫持
void unhook(PVOID OldMethod, PVOID nowMethod)
{
	DetourTransactionBegin();			//开始拦截
	DetourUpdateThread(GetCurrentThread());			//刷新当前线程

	DetourDetach((void**)&OldMethod, nowMethod);			//撤销拦截函数
	DetourTransactionCommit();				//拦截生效
}