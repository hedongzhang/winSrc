#include"myString.h"


char*  myStrstr(char* pSrcStr, const char* pObjStr)
{
	if (pSrcStr != nullptr && pObjStr != nullptr)
	{
		char* currPo = pSrcStr;
		while (currPo != '\0')
		{
			int index = 0;
			while (*(pObjStr + index) != '\0' && *(currPo + index) != '\0')
			{
				if (*(pObjStr + index) != *(currPo + index))
				{
					break;
				}
				index++;
			}
			if (*(pObjStr + index) == '\0')
			{
				return currPo;
			}
			currPo++;
		}
		return nullptr;
	}
}