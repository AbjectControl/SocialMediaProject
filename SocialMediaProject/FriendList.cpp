#include <iostream>
#include <fstream>
#include <string>
#include "FriendList.h"

using namespace std;

FriendList::FriendList(int u,int u1, int u2, int u3)
{
	UserId=u;
    frienduserId1=u1;
	frienduserId2=u2;
	frienduserId3=u3;
}
void FriendList::readfileFL(ifstream& file)
{
	file >> UserId;
	file >> frienduserId1;
	file >> frienduserId2;
	file >> frienduserId3;
}

void FriendList::setUserId(int d)
{
	UserId = d;
}
void FriendList::setfrienduserId1(int e)
{
	frienduserId1 = e;
}
void FriendList::setfrienduserId2(int f)
{
	frienduserId2 = f; 
}
void FriendList::setfrienduserId3(int g)
{
	frienduserId3 = g; 
}

int FriendList::getuserId()
{
	return UserId;
}
int FriendList::getfrienduserId1()
{
	return frienduserId1;
}
int FriendList::getfrienduserId2() 
{
	return frienduserId2; 
}
int FriendList::getfrienduserId3() 
{
	return frienduserId3; 
}
