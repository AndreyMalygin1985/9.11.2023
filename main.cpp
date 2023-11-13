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
	cout << "\t|x += 10|" << endl;
	x.show();
	cout << endl;


	SetOfNumber y = x + 12;
	++y;
	cout << "\t|++y|" << endl;

	y.show();
	cout << endl;

	y++;
	cout << "\t|y++|" << endl;
	y.show();
	cout << endl;

	x += y;
	cout << "\t|x += y|" << endl;
	x.show();
	cout << endl;

	uint32_t temp2[] = { 100,200,400 };
	SetOfNumber z{ 3,temp2 };

	SetOfNumber zxy = z + x + y;
	cout <<"\t|zxy|" << endl;
	zxy.show();
	cout << endl;


	return 0;
}