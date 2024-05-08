#include"Pages.h"

Pages::Pages(int p, string n, string date,int pa, int u1, int u2, int u3, string l, string des, int p1, int p2, int p3)
{
    pageID=p;
	PageName=n;
	PageFdate=date;
	pageFollowers = pa;
	UserPageID1=u1;
	UserPageID2=u2;
	UserPageID3=u3;
	Pagelocation=l;
	Pagedescription=des;
	postPageID1=p1;
	postPageID2=p2;
	postPageID3=p3;

}
void Pages::readfilePages(ifstream& file)
{
	string tempPageID;
	if (getline(file, tempPageID))
	{
		pageID = stoi(tempPageID);
	}
	getline(file, PageName);
	getline(file, PageFdate);
	string tempPagefollowers;
	if (getline(file, tempPagefollowers))
	{
		pageFollowers = stoi(tempPagefollowers);
	}
	string tempuserPageID1;
	if (getline(file, tempuserPageID1))
	{
		UserPageID1 = stoi(tempuserPageID1);
	}
	string tempuserPageID2;
	if (getline(file, tempuserPageID2))
	{
		UserPageID2 = stoi(tempuserPageID2);
	}
	string tempuserPageID3;
	if (getline(file, tempuserPageID2))
	{
		UserPageID3 = stoi(tempuserPageID2);
	}
	getline(file, Pagelocation);
	getline(file, Pagedescription);
	string temppostPageID1;
	if (getline(file, temppostPageID1))
	{
		postPageID1 = stoi(temppostPageID1);
	}
	string temppostPageID2;
	if (getline(file, temppostPageID2))
	{
		postPageID2 = stoi(temppostPageID2);
	}
	string temppostPageID3;
	if (getline(file, temppostPageID3))
	{
		postPageID3 = stoi(temppostPageID3);
	}
}

//SETTERS
void Pages::setpageID(int p)
{
	pageID = p;
}
void Pages::setPageName(const string& n)
{
	PageName = n;
}
void Pages::setPageFdate(const string& d)
{
	PageFdate = d;
}
void Pages::setpageFollowers(int f)
{
	pageFollowers = f;
}
void Pages::setUserPageID1(int y)
{
	UserPageID1 = y;
}
void Pages::setUserPageID2(int e)
{
	UserPageID2 = e;
}
void Pages::setUserPageID3(int g)
{
	UserPageID3 = g;
}
void Pages::setPagelocation(const string& k)
{
	Pagelocation = k;
}
void Pages::setPagedescription(const string& u)
{
	Pagedescription = u;
}
void Pages::setpostPageID1(int f)
{
	postPageID1 = f;
}
void Pages::setpostPageID2(int d)
{
	postPageID2 = d;
}
void Pages::setpostPageID3(int y)
{
	postPageID3 = y;
}

//GETTERS
int Pages::getpageID()
{
	return pageID;
}
string Pages::getPageName()
{
	return PageName;
}
string Pages::getPageFdate()
{
	return PageFdate;
}
int Pages::getpagefollowers()
{
	return pageFollowers;
}
int Pages::getUserPageID1()
{
	return UserPageID1;
}
int Pages::getUserPageID2()
{
	return UserPageID2;
}
int Pages::getUserPageID3()
{
	return UserPageID3;
}
string Pages::getPagelocation()
{
	return Pagelocation;
}
string Pages::getPagedescription()
{
	return Pagedescription;
}
int Pages::getpostPageID1()
{
	return postPageID1;
}
int Pages::getpostPageID2()
{
	return postPageID2;
}
int Pages::getpostPageID3()
{
	return postPageID3;
}