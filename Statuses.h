#ifndef STATUSES_H
#define STATUSES_H
#include "Utils.h"
#include <ctime>
#include <time.h>

class Status
{
public:
	enum typeStatus { PICTURE, VIDEO, TEXT };

	Status(typeStatus type, char* bodyStatus);
	~Status();
	void show()const;
	friend int compareTwoDatesOfStatuses(const Status& s1, const Status& s2);
	Date getDate() const;
	Clock getTime() const;
private:
	Status(const Status& other) = default;
	Date date;
	Clock time;
	typeStatus type;
	char* bodyStatus;
};


void shiftLeft(Status** st,int lSize= ARR_SIZE_OF_LAST_FRIENDS_POSTS-1);
void copyNewLastTenPostsArr(Status** dst, Status** src, int lSizeNewArr);

#endif
