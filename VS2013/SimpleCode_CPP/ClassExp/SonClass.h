#pragma once

#include "ClassTemp.h"
class SonClass :
	public ClassTemp
{
public:
	SonClass();
	~SonClass();
	void setValue(int value) override;
	void setPP(int value);
	void pp()
	{
		cout << this->sonValue << endl;
	}
	int sonValue = 0;
	int *temp;
};

