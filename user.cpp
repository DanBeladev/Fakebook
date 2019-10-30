#include "user.h"

User::~User()
{

	int i;
	delete[] this->name;
	if (numOfFriends > 0)
	{
		delete[]friends;
	}
	if (numOfPages > 0)
	{
		delete[]pages;
	}
	if (numOfStatuses > 0)
	{
		for (i = 0; i < numOfStatuses; i++)
		{
			delete this->posts[i];
		}
		delete[] posts;
	}

}

void User::printLastTenStatusesOfFriends()
{
	int i;
	for (i = 0; i < numOfFriendsPosts; i++)
	{
		
		cout << "#." << i + 1<<" ";
		lastTenFriendsPosts[i]->show();

	}
	cout << "----------------------------\n";
}

char* User::getName() const
{
	return name;
}

void User::printUser() const
{
	/*printing user details including birth date*/
	cout << "name: " << this->name << endl << "birth date: ";
	this->birthDate.showDate();
}

void User::printUserWithoutBitrhDate() const
{/*printing user details not including birth date*/
	cout << this->name;
}

void User::setName(char* name)
{/*define user name*/
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void User::setBirthDate(Date& date)
{
	birthDate = date;
}

void User::addFriend(User* friendToAdd)
{
/*
 func that adding new user to user's list of member in facebook
 */
	if (numOfFriends == 0)
		friends = new User*[friendsPSize];
	if (numOfFriends == friendsPSize)
	{
		friendsPSize *= 2;
		friends = (User**)myRealloc((void**)friends, friendsPSize, numOfFriends);
	}

	friends[numOfFriends] = friendToAdd;
	numOfFriends++;

}

void User::printFriends() const
{
	/*format of printing and showing friends of member in face book*/
	int i;
	cout << "friends of " << this->name << ":\n";
	for (i = 0; i < numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": " << this->friends[i]->name << " \n";
	}
	cout << "---------------------------\n";
}

void User::addStatus(Status* statusToAdd)
{/*adding status to the status list (arr) of user*/
	if (numOfStatuses == 0)
		posts = new Status*[statusesPSize];
	if (numOfStatuses == statusesPSize)
	{
		statusesPSize *= 2;
		this->posts = (Status**)myRealloc((void**)this->posts, statusesPSize, numOfStatuses);
	}

	posts[numOfStatuses++] = statusToAdd;
}

void User::printStatuses() const
{/*Prints a user's statuses in order */
	int i;
	for (i = 0; i < numOfStatuses; i++)
	{
		cout <<"#."<< i + 1;
		posts[i]->show(); 
	
	}
	cout << "----------------------------\n";
}

void User::updateLastTenFriendsPosts(Status* status)
{
	/*
	This function updates the array of the last 10 friends statuses and uses it after adding a status
	of member on Facebook.
	This function updates all the arrays of his friends.
	*/
	if (numOfFriendsPosts <= ARR_SIZE_OF_LAST_FRIENDS_POSTS-1)
		lastTenFriendsPosts[numOfFriendsPosts++] = status;
	else
	{
		shiftLeft(lastTenFriendsPosts);
		lastTenFriendsPosts[numOfFriendsPosts - 1] = status;
	}
}

void User::updateStatusInAllFriends(Status* status)
{/*
 The more specific function that updates each member's array
 */
	int i;
	for (i = 0; i < numOfFriends; i++)
	{
		friends[i]->updateLastTenFriendsPosts(status);
	}
}

void User::addFansPage(FanPage* pageToAdd)
{	/*
	This function adds a new page to the list of pages that a friend likes
	*/
	if (numOfPages == 0)
		pages = new FanPage*[pagesPsize];
	if (numOfPages == pagesPsize)
	{
		pagesPsize *= 2;
		this->pages = (FanPage**)realloc(this->pages, sizeof(FanPage*)*pagesPsize);
	}

	pages[numOfPages++] = pageToAdd;
}

void User::updateLastTenPostsAfterAddingFriend(User* newFriend)
{
	/*
	This function updates the last 10 statuses array of a particular member AFTER adding a new member,
	which probably does have potential statuses to enter into the array.
	*/

	//If the new member has no statuses at all, there is nothing to change in the array and we return
	if (newFriend->numOfStatuses == 0)
		return;
	Status* temp[ARR_SIZE_OF_LAST_FRIENDS_POSTS];
	int i, j,lSizeTemp=0;

	//for getting the index of the last statuses in arrays
	int indexInLastTenPosts = this->numOfFriendsPosts - 1;
	int indexNumOfNewFriendArrPosts = newFriend->numOfStatuses - 1;

	//This loop is performed as long as the statuses in the arrays are not finished or up to 10 iterations
	for (i = ARR_SIZE_OF_LAST_FRIENDS_POSTS-1; i >= 0 && indexNumOfNewFriendArrPosts >= 0 && indexInLastTenPosts >= 0; i--)
	{//using comparing func of dates
		if (compareTwoDatesOfStatuses(*newFriend->posts[indexNumOfNewFriendArrPosts], *this->lastTenFriendsPosts[indexInLastTenPosts]) == 1)
		{
			temp[i] = newFriend->posts[indexNumOfNewFriendArrPosts];
			indexNumOfNewFriendArrPosts--;
		}
		else
		{
			temp[i] = this->lastTenFriendsPosts[indexInLastTenPosts];
			indexInLastTenPosts--;
		}
		lSizeTemp++;
	}
	//if temp is not full i would check the rest of two arrays
	if (lSizeTemp < ARR_SIZE_OF_LAST_FRIENDS_POSTS)
	{
		if (indexNumOfNewFriendArrPosts == -1)
		{
			for (j = i; j >= 0 && indexInLastTenPosts >= 0; j--)
			{
				temp[j] = this->lastTenFriendsPosts[indexInLastTenPosts];
				indexInLastTenPosts--;
				lSizeTemp++;
			}
		}
		if (indexInLastTenPosts == -1)
		{
			for (j = i; j >= 0 && indexNumOfNewFriendArrPosts >= 0; j--)
			{
				temp[j] = newFriend->posts[indexNumOfNewFriendArrPosts];
				indexNumOfNewFriendArrPosts--;
				lSizeTemp++;
			}

		}
	}
	/*
	If my temp array is not filled with 10 statuses I will move my array to
	the beginning(index 0) so that it is organized for the following statuses that will enter
	*/
	if (lSizeTemp < ARR_SIZE_OF_LAST_FRIENDS_POSTS)
	{
		shiftLeft(temp, lSizeTemp);
	}
	copyNewLastTenPostsArr(this->lastTenFriendsPosts, temp, lSizeTemp);
	numOfFriendsPosts = lSizeTemp;
}