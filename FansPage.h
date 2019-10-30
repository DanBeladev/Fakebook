#ifndef FANSPAGE
#define FANSPAGE
#include "user.h"

class FanPage
{
private:
	char* pageName;
	User** usersLikedMe;
	Status** posts;
	int numOfUsersLikedMe,UsersLikedMePSize;
	int numOfStatuses,statusesPSize;
	FanPage(const FanPage& other) = default;

public:

	FanPage() : numOfUsersLikedMe(0), numOfStatuses(0), UsersLikedMePSize(1), statusesPSize(1){}
	~FanPage();
	char* getFanPageName() const;
	void printPage() const;
	void printUsersThatLikedMe()const;
	void addStatus(Status* statusToAdd);
	void printStatuses()const;
	void addUser(User* userToAdd);
	void setName(char* name);
};
#endif // !FANSPAGE

