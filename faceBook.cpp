#include "faceBook.h"
/*
Realization of all functions that manage the object "Facebook"
*/

FaceBook::FaceBook() :numOfUseres(0), numOfPages(0), UserPSize(1), fanPagePsize(1) 
{
	users = new User*[UserPSize];
	pages = new FanPage*[fanPagePsize];
}

FaceBook::~FaceBook()
{
	int i;
	if (numOfUseres > 0)
	{
		for (i = 0; i < numOfUseres; i++)
		{
			if(this->users[i]!=nullptr)
				delete this-> users[i];
		}
	}
	delete[] users;
	if (numOfPages > 0)
	{
		for (i = 0; i < numOfPages; i++)
		{
			delete this->pages[i];
		}
	}
	delete[]pages;
}

User* FaceBook::getUser(char* nameToSearch)const
{
	/*finding user by name else returnung Null*/
	int i;
	for (i = 0; i < numOfUseres; i++)
	{
		if (strcmp(this->users[i]->getName(), nameToSearch) == 0)
			return this->users[i];
	}
	cout << "the name doesn't exist\n";
	return nullptr;
}

FanPage* FaceBook::getFanPage(char* nameToSearch)const
/*finding fans page by name else returnung Null*/
{
	int i;
	for (i = 0; i < numOfPages; i++)
	{
		if (strcmp(this->pages[i]->getFanPageName(), nameToSearch) == 0)
			return this->pages[i];
	}
	cout << "the fans page name doesn't exist\n";
	return nullptr;
}

void FaceBook::addUser(char* name, Date& date)
{
	/*adding user to FaceBook and use(if needed) "my realloc" function we built*/
	User* UserToAdd = new User;
	UserToAdd->setName(name);
	UserToAdd->setBirthDate(date);
	if (UserPSize == numOfUseres)
	{
		UserPSize *= 2;
		users = (User**)myRealloc((void**)users, UserPSize,numOfUseres);
	}
	users[numOfUseres++] = UserToAdd;
}

void FaceBook::printUsers()const
{
	int i;
	cout << "The users are:\n";
	for (i = 0; i < numOfUseres; i++)
	{
		cout << "user #" << i + 1 << ": "<< users[i]->getName()<<endl;
	}
	cout << "---------------------------\n";
	/*int i;
	cout << "friends of " << this->name << ":\n";
	for (i = 0; i < numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": " << this->friends[i]->name << " \n";
	}
	cout << "---------------------------\n";*/
}

void FaceBook::connectBetween2Users(User* user1, User* user2)
{
	/*imply the friend request*/
	user1->addFriend(user2);
	user1->updateLastTenPostsAfterAddingFriend(user2);
	user2->addFriend(user1);
	user2->updateLastTenPostsAfterAddingFriend(user1);
}

void FaceBook::connectBetweenUserToFanPage(User* user1, FanPage* fanPage1)
{/* fan page1 adding to users array the wanted user and 
 user1 adding to fan pages array the wanted fan page*/
	user1->addFansPage(fanPage1);
	fanPage1->addUser(user1);
}

void FaceBook::addStatusToUser(User* user, Status* status)
{/*adding status to posts array in user*/
	user->addStatus(status);
	user->updateStatusInAllFriends(status);
}

void FaceBook::addStatusToPage(FanPage* page, Status* status)
{/*adding status to posts array in fan page*/
	page->addStatus(status);
}

void FaceBook::printStatusesOfSpecificUser(User* user)const
{
	user->printStatuses();
}

void FaceBook::addFansPage(char* pageName)
{/*adding fans page to FaceBook's fans pages array and use(if needed) "my realloc" function we built*/
	FanPage* pageToAdd = new FanPage;
	pageToAdd->setName(pageName);

	if (fanPagePsize == numOfPages)
	{
		fanPagePsize *= 2;
		pages = (FanPage**)myRealloc((void**)pages, fanPagePsize,numOfPages);
	}
	pages[numOfPages++] = pageToAdd;
}

void FaceBook::printFansPages()const
{
	/*print the all fun pages in face book*/
	int i;
	cout << "The fans pages are:\n";
	for (i = 0; i < numOfPages; i++)
	{
		cout << "fans page #" << i + 1 << ": " << pages[i]->getFanPageName() << endl;
	}
	cout << "---------------------------\n";
	
}
