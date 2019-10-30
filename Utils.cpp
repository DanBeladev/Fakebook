#include "Utils.h"
/*
A file was writed for general functions
*/

int Date::getDay()const
{
	return day;
}

int Date::getMonth()const
{
	return month;
}

int Date::getYear()const
{
	return year;
}

int Clock::getHours()const
{
	return this->hour;
}

int Clock::getMinutes()const
{
	return this->minutes;
}

bool Date::setMonth(int month)
{
	if (month>12 || month < 1)
	{
		cout << "your month dosen't exsit please enter valid month: " << endl;
		return false;
	}
	else
	{
		this->month = month;
		return true;
	}
}

bool Date::setYear(int year)
{
	if (year>2019 || year < 1900)
	{
		cout << "your year has to be between the years 1900-2019, please enter valid year:  " << endl;
		return false;
	}
	else
	{
		this->year = year;
		return true;
	}
}

bool Date::setDay(int day)
{
	if (day>30 || day < 1)
	{
		cout << "your day dosen't exsit please enter valid day: " << endl;
		return false;
	}
	else
	{
		this->day = day;
		return true;
	}
	
	
}

void Date::showDate()const
{
	cout << (day < 10 ? "0" : "") << day << "/" << (month < 10 ? "0":"")<< month << "/" << year;
}

void Clock::showTime()const
{
	cout << (hour < 10 ? "0" : "")
		<< hour << ":"
		<< (minutes < 10 ? "0" : "")
		<< minutes;

}

void printMenu()
{
	/*A function that prints the menu to the user*/
	cout << "1.Add user\n2.Add fan page\n3.Add status to user/fan page\n4.Show all statuses of user/fan page\n5.Connect between two users\n";
	cout << "6.Add user to fan page\n7.Show all useres and fans pages\n8.Show all friends of chosen user or likers of chosen fan page\n9.show recent 10 friend's posts of specific user\n0.exit\nfor printing again this menu press 'p'\n";
	cout << "----------------------------------------------------------\n";
}

void* myRealloc(void** arr, int pSize, int lSize)
{
	/* A new realloc function that we built to expand existing memory*/
	int i;
	void** tmp = new void*[lSize];
	for (i = 0; i < lSize; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = new void*[pSize];
	for (i = 0; i < lSize; i++)
	{
		arr[i] = tmp[i];
	}
	delete[]tmp;
	return arr;
}




