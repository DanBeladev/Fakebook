#include "FansPage.h"
/*
This page contains all the methods that can be use for the "Fan page" object
*/

void FanPage::printPage()const
{
	/*print fans page name*/
	cout << this->pageName ;

}

void FanPage::printUsersThatLikedMe()const
{
	/*
	we didn't ask for doing this method in class
	but we built it anyway
	this function prints the names of users that liked the page 
	*/
	int i;
	cout << "Fans of " << this->pageName << ":\n ";
	for (i = 0; i < numOfUsersLikedMe; i++)
	{
		cout << "#" << i + 1 << ": " << this->usersLikedMe[i]->getName() << " \n";
	}
	cout << "---------------------------\n";
}

void FanPage::addStatus(Status* statusToAdd)
{
	/*adding status to statuses array in Fan Page and doing "my realloc" if needed*/
	int i;
	if (numOfStatuses == 0)
		posts = new Status*[statusesPSize];
	if (numOfStatuses == statusesPSize)
	{
		statusesPSize *= 2;
		posts = (Status**)myRealloc((void**)posts, statusesPSize, numOfStatuses);
		
	}

	posts[numOfStatuses] = statusToAdd;
	numOfStatuses++;
}

void FanPage::printStatuses()const
{
	/*
	printing all statuses of specific fan page
	*/
	int i;
	for (i = 0; i < numOfStatuses; i++)
	{
		cout << "#." << i + 1 << " ";
		posts[i]->show();
	}
	cout << "----------------------------\n";
}

void FanPage::addUser(User* userToAdd)
{
	/*
	adding user to users array of fan page
	*/
	if (numOfUsersLikedMe == 0)
		usersLikedMe = new User*[UsersLikedMePSize];
	if (numOfUsersLikedMe == UsersLikedMePSize)
	{
		UsersLikedMePSize *= 2;
		this->usersLikedMe = (User**)myRealloc((void**)usersLikedMe, UsersLikedMePSize, numOfUsersLikedMe);
	}

	usersLikedMe[numOfUsersLikedMe++] = userToAdd;
}

void FanPage:: setName(char* name) 
{
	/*define name to fans page*/
	this->pageName = new char[strlen(name) + 1];
	strcpy(this->pageName, name);
}

FanPage::~FanPage()
{/*dtor of fans page*/
	int i;
	delete[] this->pageName;
	if (numOfUsersLikedMe > 0)
	{
		delete[]usersLikedMe;
	}
	if (numOfStatuses > 0)
	{
		for (i = 0; i < numOfStatuses; i++)
		{
			delete this->posts[i];
			this->posts[i] = nullptr;
		}
		delete[] posts;
	}
}

char* FanPage::getFanPageName()const
{
	return this->pageName;
}
