#include<iostream>
#include<Windows.h>
#include"SetOfNumber.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	uint32_t temp[] = { 1,1,1,1,1,1,2,3 };
	SetOfNumber x{ 8,temp };

	x.show();
	cout << endl;

	x += 10;
	x.show();
	cout << endl;

	return 0;
}