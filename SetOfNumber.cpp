﻿#include "SetOfNumber.h"

SetOfNumber::SetOfNumber(unsigned int size, uint32_t* arr) : arr{ new uint32_t[size] }, sszz{ size } {
	int index = 0;

	for (size_t i = 0; i < sszz; i++) {
		if (has(arr[i], index) == -1) {
			this->arr[index] = arr[i];
			index++;
		}
	}

	uint32_t* temp = new uint32_t[index];
	for (size_t i = 0; i < index; i++) {
		temp[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temp;
	sszz = index;
}

uint32_t SetOfNumber::has(uint32_t value, uint32_t limit) const {
	uint32_t c_sszz = limit == -1 ? this->sszz : limit;

	for (uint32_t i = 0; i < c_sszz; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}

SetOfNumber& SetOfNumber::operator+=(const SetOfNumber& set) {
	for (size_t i = 0; i < set.sszz; i++) {
		if (this->has(set.arr[i]) == -1) {
			*this += set.arr[i];
		}
	}
	return *this;
}

const SetOfNumber SetOfNumber::operator+(const SetOfNumber& set) const {
	SetOfNumber temp = *this;
	temp += set;
	return temp;
}

SetOfNumber& SetOfNumber::operator++() {
	for (size_t i = 0; i < sszz; i++) {
		arr[i]++;
	}
	return *this;
}

const SetOfNumber SetOfNumber::operator++(int) {
	SetOfNumber set{ *this };
	this->operator++();
	return set;
}

SetOfNumber& SetOfNumber::operator--() {
	for (size_t i = 0; i < sszz; i++) {
		arr[i]--;
	}
	return *this;
}

const SetOfNumber SetOfNumber::operator--(int) {
	SetOfNumber set{ *this };
	this->operator--();
	return set;
}

SetOfNumber& SetOfNumber::operator-=(uint32_t value) {
	uint32_t index = has(value);
	if (index == -1) {
		return *this;
	}

	uint32_t* temp = new uint32_t[sszz - 1];
	for (uint32_t i = 0; i < index; i++) {
		temp[i] = arr[i];
	}
	if (index != sszz - 1) {
		for (uint32_t i = index + 1; i < sszz; i++) {
			temp[i - 1] = arr[i];
		}
	}
	delete[] arr;
	arr = temp;
	sszz--;
	return *this;
}

const SetOfNumber SetOfNumber::operator-(uint32_t value) const {
	SetOfNumber temp = *this;
	temp -= value;
	return temp;
}

SetOfNumber& SetOfNumber::operator+=(uint32_t value) {
	if (has(value) != -1) {
		return *this;
	}

	uint32_t* temp = new uint32_t[sszz + 1];
	for (size_t i = 0; i < sszz; i++) {
		temp[i] = arr[i];
	}
	temp[sszz] = value;
	delete[] arr;
	arr = temp;
	sszz++;
	return *this;
}

const SetOfNumber operator+(const SetOfNumber& set, uint32_t value) {
	if (set.has(value) == -1) {
		SetOfNumber temp(set);
		temp += value;
		return temp;
	}
	return set;
}

const SetOfNumber operator+(uint32_t value, const SetOfNumber& set) {
	return set + value;
}


ostream& operator<<(ostream& out, const SetOfNumber& set) {
	out << "{";
	for (size_t i = 0; i < set.sszz; i++) {
		out << " " << set.arr[i];
	}
	out << " }";
	return out;
}

istream& operator>>(istream& out, SetOfNumber& set) {
	cout << "Укажите размер множества" << endl;
	out >> set.sszz;
	out.ignore(1);

	delete[]set.arr;
	set.arr = new uint32_t[set.sszz];
	for (size_t i = 0; i < set.sszz; i++) {
		cout << "Укажите значение индекса " << i << ": ";
		out >> set.sszz;
		out.ignore(1);
	}
	return out;
}

SetOfNumber& SetOfNumber::operator=(const SetOfNumber& name) {
	if (this == &name) {
		return *this;
	}
	clear();

	arr = new uint32_t[name.sszz];
	for (uint32_t i = 0; i < name.sszz; i++) {
		arr[i] = name.arr[i];
	}
	sszz = name.sszz;
	return *this;
}