#pragma once
#include<iostream>

using namespace std;

class SetOfNumber
{
	uint32_t* arr;
	uint32_t sszz;
	void clear() {
		delete[]arr;
		arr = nullptr;
	}
public:

	SetOfNumber(unsigned int size, uint32_t* arr);

	SetOfNumber() : SetOfNumber(0, nullptr) {}

	SetOfNumber(const SetOfNumber& obj) : arr{ new uint32_t[obj.sszz] }, sszz{ obj.sszz } {
		for (size_t i = 0; i < obj.sszz; i++) {
			arr[i] = obj.arr[i];
		}
	}
	~SetOfNumber() {
		clear();
	}

	uint32_t has(uint32_t value, uint32_t limit = -1) const;		//наличие элемента во множестве

	void show() const {
		for (size_t i = 0; i < sszz; i++) {
			cout << arr[i] << " ";
		}
	}

	SetOfNumber& operator+=(const SetOfNumber& set);			//добавление множества к другому множеству
	const SetOfNumber operator+(const SetOfNumber& set) const;		//	

	SetOfNumber& operator++();							//инкремент к каждому числу множества
	const SetOfNumber operator++(int);						//инкремент к каждому числу множества
	SetOfNumber& operator--();
	const SetOfNumber operator--(int);

	SetOfNumber& operator-=(uint32_t value);				//вычетание из множества другого множества
	const SetOfNumber operator-(uint32_t value) const;		//удаление элемента из множества - элемент

	SetOfNumber& operator+=(uint32_t value);			//добавление множества к другому множеству
	friend const SetOfNumber operator+(const SetOfNumber& set, uint32_t value);		//добавление элемента множество + элемент (без привязки к классу)
	friend const SetOfNumber operator+(uint32_t value, const SetOfNumber& set);		//добавление элемента элемент +множество (без привязки к классу)

	friend ostream& operator<< (ostream& out, const SetOfNumber& set);
	friend istream& operator>> (istream& out, SetOfNumber& set);

	SetOfNumber& operator= (const SetOfNumber& name);
};

