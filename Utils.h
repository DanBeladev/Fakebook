#ifndef UTILS_H
#define UTILS_H
#include <iostream>

#define MAX 100
const int ARR_SIZE_OF_LAST_FRIENDS_POSTS = 10;
using namespace std;
class Clock
{
	int hour, minutes;
public:
	Clock() = default;
	Clock(int hour, int minutes) :hour(hour), minutes(minutes) {};

	void showTime() const;
	int getHours() const;
	int getMinutes() const;
};

class Date
{
private:
	int day, month, year;
public:
	Date() = default;
	Date(int day, int month, int year) : day(day), month(month), year(year) {};
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool setDay(int day);
	bool setMonth(int month);
	bool setYear(int year);
	void showDate() const;

};

void printMenu();
void* myRealloc(void** arr, int pSize, int lSize);



#endif // !USER_H

