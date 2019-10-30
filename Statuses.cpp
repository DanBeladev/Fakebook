#include "Statuses.h"
/*
This page contains all the methods that can be use for the "Status" object
*/


Status::Status(typeStatus type, char* bodyStatus) : type(type)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	int hour = now->tm_hour;
	int min = now->tm_min;
	Date tmpDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	Clock tmpClock(hour, min);

	time = tmpClock;
	date = tmpDate;

	this->bodyStatus = new char[strlen(bodyStatus) + 1];
	strcpy(this->bodyStatus, bodyStatus);

}

Status::~Status()
{
	
	delete[] this->bodyStatus;
}

void Status::show()const
{
	cout <<"''"<< bodyStatus <<"''"<< endl << "posted at date: ";
	date.showDate();
	cout << " at time: ";
	time.showTime();
	switch (type)
	{
	case Status::PICTURE:
		cout << " PICTURE type" << endl;
		break;
	case Status::VIDEO:
		cout << " VIDEO type" << endl;
		break;
	case Status::TEXT:
		cout << " TEXT type" << endl;
		break;
	default:
		break;
	}
	
}

Date Status::getDate() const
{
	return this->date;
}

Clock Status::getTime() const
{
	return this->time;
}

int compareTwoDatesOfStatuses(const Status & s1, const Status & s2)
{
	/*
	A function that recieves two statuses objects and returns 1 if the first date is more recent and -1 for the second
	and 0 if they equal dates.
	*/
	if (s1.getDate().getYear() > s2.getDate().getYear())
		return 1;
	if (s2.getDate().getYear() > s1.getDate().getYear())
		return -1;
	if (s1.getDate().getMonth() > s2.getDate().getMonth())
		return 1;
	if (s2.getDate().getMonth() > s1.getDate().getMonth())
		return -1;
	if (s1.getDate().getDay() > s2.getDate().getDay())
		return 1;
	if (s2.getDate().getDay() > s1.getDate().getDay())
		return -1;
	if (s1.getTime().getHours() > s2.getTime().getHours())
		return 1;
	if (s2.getTime().getHours() > s1.getTime().getHours())
		return -1;
	if (s1.getTime().getMinutes() > s2.getTime().getMinutes())
		return 1;
	if (s2.getTime().getMinutes() > s1.getTime().getMinutes())
			return -1;
	
		return 0;
		
}

void shiftLeft(Status** st,int lSize)
{	/*
	this function manage the "lastTenFriendsPosts" by shifting the newers statuses to the starting point in array
	(to index 0)
	*/

	int i;
	for (i = 0; i < lSize; i++)
	{
		st[i] = st[ARR_SIZE_OF_LAST_FRIENDS_POSTS - lSize + i];
	}
}

void copyNewLastTenPostsArr(Status ** dst, Status ** src, int lSizeNewArr)
{
	/*
	after adding friend we have to update the "lastTenFriendsPosts"
	so we use at temp array and after the proccesing of merging we copy the temp array to the "lastTenFriendsPosts"
	of User
	*/
	int i;
	for (i = 0; i < lSizeNewArr; i++)
	{
		dst[i] = src[i];
	}
}
