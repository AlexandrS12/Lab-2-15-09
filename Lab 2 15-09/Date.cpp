#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()//defolt
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}
//setters
void Date::setDay(int d)
{
	if (d >= 1 && d <= 31) day = d;
}
void Date::setMonth(int m)
{
	if(m>=1 && m<=12) month = m;
}
void Date::setYear(int y)
{
	if (y>=0) year = y;
}
//getters
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
//Print
void Date::PrintDate()
{
	cout << "Day: " << day << " Month: " << month << " Year: " << year << endl;
}
// ++ and --
Date Date::operator++()
{
	day++;
	if (day > 31) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);

	if (day > 28 && month == 2) 
	{
		day = 28;
	}
	else if (day < 31) 
	{
		++day;
	}
	else if (day > 31) 
	{
		day = 1;
		++month;
	}
	else if (day > 31 && month == 12) 
	{
		year = month = 1;
		++year;
	}

	return temp;
}

Date Date::operator--()
{
	day--;
	if (day < 1) {
		month--;
		if (month < 1) {
			month = 12;
			year--;
		}
		day = 31; 
	}
	return *this;
}

Date Date::operator--(int)
{
	Date temp(*this);

	if (day > 28 && month == 2) 
	{
		day = 28;
	}
	else if (day < 31) 
	{
		--day;
	}
	else if (day > 31) 
	{
		day = 1;
		++month;
	}
	else if (day > 31 && month == 12)
	{
		year = month = 1;
		++year;
	}

	return temp;
}


//..
Date Date::operator+(int day) const //data + amount days
{
	Date rez(*this);

	for (int i = 0; i < day; i++) {
		if (rez.day < 28 || (rez.day == 28 && rez.month != 2)) 
		{
			++rez.day;
		}
		else if (rez.month < 12) 
		{
			rez.day = 1;
			++rez.month;
		}
		else 
		{
			rez.day = 1;
			rez.month = 1;
			++rez.year;
		}
	}

	return rez;
}
Date Date::operator-(int day) const//data - amount days
{
	Date rez(*this);

	for (int i = 0; i < day; i++) 
	{
		if (rez.day < 28 || (rez.day == 28 && rez.month != 2)) 
		{
			--rez.day;
		}
		else if (rez.month < 12)
		{
			rez.day = 31;
			--rez.month;
		}
		else 
		{
			rez.day = 31;
			rez.month = 12;
			--rez.year;
		}
	}

	return rez;


	return Date();
}
int Date::operator-(Date& x) const
{
	int date1 = year * 365 + month * 30 + day;
	int date2 = x.year * 365 + x.month * 30 + x.day;

	if (date1 < date2) 
	{
		int temp = date1;
		date1 = date2;
		date2 = temp;
	}

	return date1 - date2;
}
//.....
Date& Date::operator+=(int d)
{
	for (int i = 0; i < d; i++) 
	{
		if (day < 28 || (day == 28 && month != 2)) 
		{
			day++;
		}
		else if (month < 12)
		{
			day = 1;
			month++;
		}
		else 
		{
			day = 1;
			month = 1;
			year++;
		}
	}
	return *this;
}

Date& Date::operator-=(int d)
{
	for (int i = 0; i < d; i++) 
	{
		if (day > 1)
		{
			day--;
		}
		else 
		{
			if (month > 1) 
			{
				month--;
				if (month == 2) 
				{
					day = 28;
				}
				else 
				{
					day = 31;
				}
			}
			else
			{
				year--;
				month = 12;
				day = 31;
			}
		}
	}
	return *this;
}
//.....
bool Date::operator<(Date c)
{
	if (year < c.year) 
	{
		return true;
	}
	else
	{
		if (month < c.month) 
		{
			return true;
		}
		else 
		{
			if (day < c.day)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}

bool Date::operator>(Date c)
{
	if (year > c.year) 
	{
		return true;
	}
	else 
	{
		if (month > c.month)
		{
			return true;
		}
		else 
		{
			if (day > c.day) 
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}

bool Date::operator<=(Date c)
{
	if (year <= c.year) 
	{
		return true;
	}
	else 
	{
		if (month <= c.month)
		{
			return true;
		}
		else {
			if (day <= c.day)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
	}
}

bool Date::operator>=(Date c)
{
	if (year >= c.year) 
	{
		return true;
	}
	else 
	{
		if (month >= c.month) 
		{
			return true;
		}
		else {
			if (day >= c.day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::operator==(Date c)
{
	if (day == c.day && month == c.month && year == c.year) {
		return true;
	}
	return false;

}

bool Date::operator!=(Date c)
{
	if (day != c.day && month != c.month && year != c.year) {
		return true;
	}
	return false;

}