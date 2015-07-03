#include<Windows.h>
_declspec(dllexport)void go()
{
	MessageBoxA(0, "注入成功！", "提示！", 0);

	int* pNum = (int*)0x1D8B17A8;
	while (1)
	{
		Sleep(100);
		*pNum += 10;
	}
}