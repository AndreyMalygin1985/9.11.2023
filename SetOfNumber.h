#pragma once
#include<iostream>

using namespace std;

class SetOfNumber
{
	uint32_t* arr;
	uint32_t sszz;
public:

	SetOfNumber(unsigned int size, uint32_t* arr);

	SetOfNumber() : SetOfNumber(0, nullptr) {}

	SetOfNumber(const SetOfNumber& obj) : arr{ new uint32_t[obj.sszz] }, sszz{ obj.sszz } {
		for (size_t i = 0; i < obj.sszz; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	~SetOfNumber()
	{
		delete[] arr;
	}

	bool has(uint32_t value, uint32_t limit = -1) const;

	void show() const
	{
		for (size_t i = 0; i < sszz; i++)
		{
			cout << arr[i] << " ";
		}
	}

	//void increase(uint32_t sszz)
	//{
	//	uint32_t* temp = new uint32_t[sszz];
	//	for (size_t i = 0; i < sszz; i++)
	//	{
	//		temp[i] = this->arr[i];
	//	}
	//	delete[] this->arr;
	//	this->arr = temp;
	//}

	static const SetOfNumber add(const SetOfNumber& set, uint32_t value);	//множество + значение

	friend const SetOfNumber operator+(const SetOfNumber& set, uint32_t value);

	friend const SetOfNumber operator+(uint32_t value, const SetOfNumber& set);

	friend void operator+=(SetOfNumber& set, uint32_t value);
	
};

