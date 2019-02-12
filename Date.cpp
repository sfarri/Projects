#include "Date.hpp"

Date::Date(int Month, int Day, int Year)
{
	month = Month;
	day = Day;
	year = Year;
}

void Date::setDay(int d)
{
	if (d < 1 && d > 31)
		cout << "The day is invalid" << endl;
	else
	day = d;
	
}

void Date::setMonth(int m)
{
	if (m < 1 && m > 12)
		cout << "The month is invalid" << endl;
	else
	month = m;
	
}

void Date::setYear(int y)
{
	if (y < 1900 && y > 2050)
		cout << "The year is invalid" << endl;
	else
		year = y;
}

void Date::showDate1()
{
	cout << month << " /" << day << " /" << year << endl;
}

void Date::showDate2()
{
	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	cout << monthName[month - 1] << "  " << day << "  " << year << endl;
}

void Date::showDate3()
{
	string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	cout << day << "  " << monthName[month - 1] << "  " << year << endl;
}