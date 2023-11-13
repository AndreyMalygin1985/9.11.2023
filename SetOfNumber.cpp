#include "SetOfNumber.h"

SetOfNumber::SetOfNumber(unsigned int size, uint32_t* arr) : arr{ new uint32_t[size] }, sszz{ size }
{
	int index{ 0 };
	for (size_t i = 0; i < sszz; i++)
	{
		if (has(arr[i] , index) == -1)
		{
			this->arr[index] = arr[i];
			index++;
		}
	}

	uint32_t* temp = new uint32_t[index];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temp;
	sszz = index;
}

uint32_t SetOfNumber::has(uint32_t value, uint32_t limit) const
{
	uint32_t c_sszz = limit == -1 ? this->sszz : limit;
	for (uint32_t i = 0; i < c_sszz; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

SetOfNumber& SetOfNumber::operator+=(uint32_t value)
{
	if (has(value) != -1)
	{
		return *this;
	}
	uint32_t* temp = new uint32_t[sszz + 1];
	for (size_t i = 0; i < sszz; i++)
	{
		temp[i] = arr[i];
	}
	temp[sszz] = value;
	delete[] arr;
	arr = temp;
	sszz++;
	return *this;
}

SetOfNumber& SetOfNumber::operator+=(const SetOfNumber& set)
{
	for (size_t i = 0; i < set.sszz; i++)
	{
		if (!this->has(set.arr[i]) == -1)
		{
			*this += set.arr[i];
		}
	}
	return *this;
}

SetOfNumber& SetOfNumber::operator+(const SetOfNumber& set)
{
	*this += set;
	return *this;
}

SetOfNumber& SetOfNumber::operator-=(uint32_t value)
{
	uint32_t index = has(value);
	if (has(value) == -1)
	{
		return *this;
	}

	uint32_t* temp = new uint32_t[sszz - 1];
	for (uint32_t i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	if (index != sszz-1) {
		for (uint32_t i = index + 1; i < sszz; i++)
		{
			temp[i-1] = arr[i];
		}
	}
	delete[] arr;
	arr = temp;
	sszz--;
	return *this;
}

SetOfNumber& SetOfNumber::operator++()
{
	return this->increment();
}

SetOfNumber& SetOfNumber::operator++(int)
{
	return this->increment();
}

SetOfNumber& SetOfNumber::increment()
{
	for (size_t i = 0; i < sszz; i++)
	{
		arr[i]++;
	}
	return *this;
}

const SetOfNumber SetOfNumber::add(const SetOfNumber& set, uint32_t value)		//множество + значение
{
	{
		if (set.has(value) == -1)
		{
			uint32_t* temp = new uint32_t[set.sszz + 1];
			for (size_t i = 0; i < set.sszz; i++)
			{
				temp[i] = set.arr[i];
			}
			temp[set.sszz] = value;
			return SetOfNumber(set.sszz + 1, temp);
		}
		return set;
	}
	return SetOfNumber();
}

const SetOfNumber operator+(const SetOfNumber& set, uint32_t value)
{
	return SetOfNumber::add(set, value);
}

const SetOfNumber operator+(uint32_t value, const SetOfNumber& set)
{
	return SetOfNumber::add(set, value);
}

