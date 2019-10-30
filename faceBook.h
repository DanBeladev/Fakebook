#ifndef FACEBOOK_H
#define FACEBOOK_H

#include "user.h"
#include "FansPage.h"

/*this object is the main object that manage the all users and fans pages were created*/
class FaceBook
{
private:
	int numOfUseres,UserPSize;
	 int numOfPages,fanPagePsize;
	User** users;
	FanPage** pages;
	FaceBook(const FaceBook& other) = default;
public:
	FaceBook() ;
	~FaceBook();
	void addUser(char* name,Date& date);
	void addFansPage(char* pageName);
	void printUsers() const;
	void printFansPages()const;
	void connectBetween2Users( User* user1,  User* user2);
	void connectBetweenUserToFanPage( User* user1,  FanPage* fanPage1);
	void addStatusToUser(User* user,  Status* status);
	void addStatusToPage(FanPage* page,  Status* status);
	void printStatusesOfSpecificUser( User* user)const;
	int getNumOfUsers() const { return numOfUseres; }
	User* getUser(char* nameToSearch) const;
	FanPage* getFanPage(char* nameToSearch)const;
};


#endif // !_FACEBOOK

