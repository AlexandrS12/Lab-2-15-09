#pragma once
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d, int m, int y);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void PrintDate();
    //.....
    Date operator++(); // ++a
    Date operator++(int); // a++
    Date operator--(); // --a
    Date operator--(int); //a--
	//......
	Date operator+(int) const;// +10
	Date operator-(int) const;// - 10
	int operator-(Date& x) const;// data - data
	//......
	Date& operator+=(int);// += data
	Date& operator-=(int);// -=data
	//......
	bool operator<(Date c);
	bool operator>(Date c);
	bool operator<=(Date c);
	bool operator>=(Date c);
	bool operator==(Date c);
	bool operator!=(Date c);


};

