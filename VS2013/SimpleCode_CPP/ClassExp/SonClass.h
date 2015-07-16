#pragma once

#include "ClassTemp.h"
class SonClass :
	public ClassTemp
{
public:
	SonClass();
	~SonClass();

	void setValue(int value) override;
};

