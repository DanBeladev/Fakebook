#include "mainFunctions.h"
/*
This page contains auxiliary functions for managing and navigating the main menu
*/

Status::typeStatus getTypeStatus()
{
	/*
	get from user the type of status he wants to upload
	*/
	char statusType;
	cout << "choose status type:\n1.picture\n2.video\n3.text" << endl;
	cin >> statusType;
	switch (statusType)
	{
	case '1':
		return Status::PICTURE;
	case '2':
		return Status::VIDEO;

	case '3':
		return Status::TEXT;

	default:
		cout << "ERROR! please insert valid input" << endl;
		break;
	}
}

void chooseOption(char c, FaceBook& mainFace)
{
	/*
	navigation function
	*/
	char name[MAX];
	char str[MAX];
	switch (c)
	{
	case '1':
		addUserToFaceBook(mainFace,name);
		break;
	case '2':
		addFansPageToFaceBook(mainFace,name);
		break;
	case '3':
		addStatusToUserOrToFansPage(mainFace,name,str);
		break;
	case '4':
		showStatusesOfUserOrFansPage(mainFace,name,str);
		break;
	case '5':
		implyFriendRequest(mainFace,name,str);
		break;
	case '6':
		addUserToFanPage(mainFace, name, str);
		break;
	case '7':
		showAllUsersAndFansPages(mainFace);
		break;
	case '8':
		showFriendsOfUserOrFriendsOfFansPage(mainFace,name);
		break;
	case '9':
		showLastPostsOfFriendsUser(mainFace, name);
		break;
	case 'p':
		printMenu();
		break;

	default:
		break;
	}
}

void getFanPageName(char* str)
{
	cout << "\nenter fan page name:";
	cin.getline(str, MAX);
}

void getStatus(char* str)
{
	cout << "enter status to add:\n"; 
	cin.ignore();
	cin.getline(str, MAX);
}

void getTwoNames(char* name1, char* name2)
{
	cout << "\nenter first friend name:";
	cin.ignore();
	cin.getline(name1, MAX);
	cout << "enter second friend name:";
	cin.getline(name2, MAX);
}

void getName(char* name)
{
	cout << "enter name:";
	cin.ignore();
	cin.getline(name, MAX);
}

void addUserToFaceBook(FaceBook& mainFace,char* name)
{
	/*
	Adding a new user to the system by entering details of name and date of birth
	*/
	Date date;
	int tmp = 0;
	getName(name);
	cout << "enter birth date:\n";
	cout << "day:";
	do
	{
		cin >> tmp;
		
	} while (date.setDay(tmp) == false);
	
	cout << "month:";
	do
	{
		cin >> tmp;
	} while (cin.fail() || date.setMonth(tmp) == false);

	cout << "year: ";
	do
	{
		cin >> tmp;
	} while (cin.fail() || date.setYear(tmp) == false);


	mainFace.addUser(name, date);
}

void addFansPageToFaceBook(FaceBook& mainFace,char* name)
{
	/*
	Adding a new fans page to the system(faceBook) by entering page name
	*/
	FanPage fanPage;
	getName(name);
	
	mainFace.addFansPage(name);
}

void addStatusToUserOrToFansPage(FaceBook& mainFace, char* name,char* str)
{
	/*
	A function that manages the process of adding a status to a user or fan page
	*/
	int i;
	char coice,statusType;
	Status::typeStatus type;
	User* us;
	FanPage* fp;
	cout << "for adding status to user press 1\nfor adding status to fan page press 2"<<endl;
	cin >> coice;
	if (coice == '1')
	{
		mainFace.printUsers();
		getName(name);
		us = mainFace.getUser(name);
		if (!us)
			return;
		
		type = getTypeStatus();
		getStatus(str);
		Status* statusToAdd = new Status(type, str);
		mainFace.addStatusToUser(us, statusToAdd);
	}
	else if (coice == '2')
	{
		cout << "the fans pages are:";
		mainFace.printFansPages();
		cin.ignore();
		getFanPageName(name);
		fp = mainFace.getFanPage(name);
		if (!fp)
			return;
		type = getTypeStatus();
		getStatus(str);
		Status* statusToAdd = new Status(type, str);
		mainFace.addStatusToPage(fp, statusToAdd);
	}
	else
	{
		cout << "ERROR! NOT VALID INPUT" << endl;
	}
}

void showStatusesOfUserOrFansPage(FaceBook& mainFace,char* name,char* str)
{
	/*
	A function that manages the process of viewing a user's statuses or a fan page
	*/
	int i;
	User* us;
	FanPage* fp;
	char coice;
	cout << "for showing statuses of user press 1\nfor showing statuses of fan page press 2" << endl;
	cin >> coice;
	switch (coice)
	{
	case '1':
		mainFace.printUsers();
		getName(name);
		us = mainFace.getUser(name);
		if(!us)
			return;
		us->printStatuses();
		break;
	case'2':
		mainFace.printFansPages();
		cin.ignore();
		getFanPageName(str);
		fp = mainFace.getFanPage(str);
		if (!fp)
			return;
		fp->printStatuses();
	default:
		break;
	}

}

void implyFriendRequest(FaceBook& mainFace,char* name1,char* name2)
{
	/*
	A function that implements the process of adding a user to a user
	*/
	User* us1, *us2;
	mainFace.printUsers();
	getTwoNames(name1, name2);
	us1=mainFace.getUser(name1);
	if (!us1)
		return;
	us2= mainFace.getUser(name2);
	if (!us2)
		return;
	mainFace.connectBetween2Users(us1, us2);

}

void addUserToFanPage(FaceBook& mainFace,char* name,char* pageName)
{
	/*
	A function that implements the process of adding a member to a fan page
	*/
	User* us;
	FanPage* fp;
	cout << "the users are:";
	mainFace.printUsers();
	getName(name);
	us = mainFace.getUser(name);
	if (!us)
		return;
	cout << "the pages are:";
	mainFace.printFansPages();
	getFanPageName(pageName);
	fp = mainFace.getFanPage(pageName);
	if (!fp)
		return;
	
	mainFace.connectBetweenUserToFanPage(us, fp);

}

void showAllUsersAndFansPages(FaceBook& mainFace)
{
	/*printing the users*/
	mainFace.printUsers();
	mainFace.printFansPages();
}

void showFriendsOfUserOrFriendsOfFansPage(FaceBook& mainFace,char* name)
{
	/*
	Prints the relevant users at user request
	*/
	char coice;
	cout << "for showing friends of user press 1\nfor showing likers of fans page press 2" << endl;
	cin >> coice;
	User* us;
	FanPage * fp;
	switch (coice)
	{
	case '1':

		mainFace.printUsers();
		getName(name);
		us = mainFace.getUser(name);
		if (!us)
			return;
		us->printFriends();
		break;
	case'2':
		mainFace.printFansPages();
		cin.ignore();
		getFanPageName(name);
		fp = mainFace.getFanPage(name);
		if (!fp)
			return;
		fp->printUsersThatLikedMe();
	default:
		break;
	}
}

void showLastPostsOfFriendsUser(FaceBook & mainFace, char * name)
{
	/*
	A function that prints the 10 most recent statuses of a user's friends
	*/
	User* us;
	cout << "the users are:";
	mainFace.printUsers();
	getName(name);
	us = mainFace.getUser(name);
	if(us)
		us->printLastTenStatusesOfFriends();
}


