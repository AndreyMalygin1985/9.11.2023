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

	uint32_t has(uint32_t value, uint32_t limit = -1) const;		//������� �������� �� ���������

	void show() const
	{
		for (size_t i = 0; i < sszz; i++)
		{
			cout << arr[i] << " ";
		}
	}
	
	SetOfNumber& operator+=(uint32_t value);			//���������� ��������� � ������� ���������
	SetOfNumber& operator+=(const SetOfNumber& set);	//���������� ��������� � ������� ���������
	SetOfNumber& operator+(const SetOfNumber& set);	//
	
	SetOfNumber& operator-=(uint32_t value);			//��������� ��������� � ������� ���������

	SetOfNumber& increment();
	SetOfNumber& operator++();							//��������� � ������� ����� ���������
	SetOfNumber& operator++(int);						//��������� � ������� ����� ���������


	static const SetOfNumber add(const SetOfNumber& set, uint32_t value);		//��������� + ��������
	
	friend const SetOfNumber operator+(const SetOfNumber& set, uint32_t value);		//���������� �������� ��������� + ������� (��� �������� � ������)
	friend const SetOfNumber operator+(uint32_t value, const SetOfNumber& set);		//���������� �������� ������� +��������� (��� �������� � ������)

};

