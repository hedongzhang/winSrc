#pragma once

template<typename T>
T add(T v1, T v2)
{
	if (v2 == 0)
	{
		return v1;
	}
	return add<T>(v1^v2, (v1&v2)<<1);
};