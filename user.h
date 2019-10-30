#ifndef USER_H
#define USER_H
#include "Statuses.h"

class FanPage;

class User
{
private:
	int numOfFriends,friendsPSize;
	int numOfStatuses, statusesPSize;
	int numOfFriendsPosts;
	int numOfPages,pagesPsize;
	char* name;
	Date birthDate;
	User** friends;
	Status** posts;
	FanPage** pages;
	Status* lastTenFriendsPosts[ARR_SIZE_OF_LAST_FRIENDS_POSTS];
	User(const User& other) = default;
public:
	User() : numOfFriends(0), numOfFriendsPosts(0), numOfPages(0), numOfStatuses(0),
			friendsPSize(1), statusesPSize(1), pagesPsize(1){}
	~User();
	char* getName() const;
	void printLastTenStatusesOfFriends();
	void printUser() const;
	void printUserWithoutBitrhDate() const;
	void printFriends() const;
	void setName(char* name);
	void setBirthDate(Date& date);
	void addFriend(User* friendToAdd);
	void addStatus(Status* statusToAdd);
	void addFansPage(FanPage* pageToAdd);
	void updateLastTenPostsAfterAddingFriend(User * newFriend);
	void printStatuses() const;
	void updateLastTenFriendsPosts(Status* status);
	void updateStatusInAllFriends(Status* status);
};


#endif // !USER_H

