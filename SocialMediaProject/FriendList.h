#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class FriendList
{
private:
	int UserId;
	int frienduserId1;
	int frienduserId2;
	int frienduserId3;
	
public:
	FriendList(int u=0, int u1=0, int u2=0, int u3=0);
	void readfileFL(ifstream& file);

	void setUserId(int d);
	void setfrienduserId1(int f);
	void setfrienduserId2(int e);
	void setfrienduserId3(int g);

	int getuserId();
	int getfrienduserId1();
	int getfrienduserId2();
	int getfrienduserId3();

};













#endif 

