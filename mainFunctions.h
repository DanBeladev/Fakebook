#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include "faceBook.h"

void chooseOption(char c,FaceBook& mainFace);
void getStatus(char * str);
void addUserToFaceBook(FaceBook& mainFace, char* name);
void addFansPageToFaceBook(FaceBook& mainFace, char* name);
void addStatusToUserOrToFansPage(FaceBook & mainFace, char * name, char * str);
void showStatusesOfUserOrFansPage(FaceBook& mainFace, char* name, char* str);
void implyFriendRequest(FaceBook& mainFace, char* name1, char* name2);
void addUserToFanPage(FaceBook& mainFace, char* name,char*pageName);
void showAllUsersAndFansPages(FaceBook& mainFace);
void showFriendsOfUserOrFriendsOfFansPage(FaceBook& mainFace, char* name);
void showLastPostsOfFriendsUser(FaceBook& mainFace, char* name);


Status::typeStatus getTypeStatus();
#endif // !MAINFUNCTIONS_H
