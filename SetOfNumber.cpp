#include "SetOfNumber.h"

bool SetOfNumber::has(uint32_t value, uint32_t limit) const
{
	int32_t c_sszz = limit == -1 ? this->sszz : limit;
	for (size_t i = 0; i < c_sszz; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
    return false;
}