#include<iostream>
#include"Date.h"
using namespace std;


int main()
{
	Date date1(15, 9, 2023);
	date1.PrintDate();
	Date date2(21, 4, 1989);
	date2.PrintDate();
	cout << endl;
	Date test1 = ++date1;
	test1.PrintDate();
	cout << endl;

	Date test2 = date1++;
	test2.PrintDate();
	date1.PrintDate();
	cout << endl;

	Date test3 = --date1;
	test3.PrintDate();
	cout << endl;

	Date test4 = date1--;
	test4.PrintDate();
	date1.PrintDate();
	cout << endl;

	date1 = date1 + 10;
	date1.PrintDate();
	cout << endl;

	date1 = date1 - 10;
	date1.PrintDate();
	cout << endl;

	int test5 = date1 - date2;
	cout << test5 << endl << endl;
	date1 += 30;
	date1.PrintDate();
	date1 -= 15;
	date1.PrintDate();

	if (date1 < date2) {
		cout << "date1 < date2" << endl;
	}
	else {
		cout << "date1 > date2" << endl;
	}

	if (date1 > date2) {
		cout << "date1 > date2" << endl;
	}
	else {
		cout << "date1 < date2" << endl;
	}

	if (date1 <= date2) {
		cout << "date1 <= date2" << endl;
	}
	else {
		cout << "date1 >= date2" << endl;
	}

	if (date1 >= date2) {
		cout << "date1 >= date2" << endl;
	}
	else {
		cout << "date1 <= date2" << endl;
	}

	if (date1 == date2) {
		cout << "date1 == date2" << endl;
	}
	else {
		cout << "date1 != date2" << endl;
	}



}