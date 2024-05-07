#ifndef PAGES_H
#define PAGES_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pages
{
private:
	int pageID;
	string PageName;
	string PageFdate;
	int pageFollowers;
	int UserPageID1;
	int UserPageID2;
	int UserPageID3;
	string Pagelocation;
	string Pagedescription;
	int postPageID1;
	int postPageID2;
	int postPageID3;

public:
	Pages(int p = 0, string n = "", string date = "",int pa=0 ,int u1 = 0, int u2 = 0, int u3 = 0, string l = "", string des = "", int p1 = 0, int p2 = 0, int p3 = 0);
	void readfilePages(ifstream &file);

	//SETTERS
	void setpageID(int p);
	void setPageName(const string& n);
	void setPageFdate(const string& d);
	void setUserPageID1(int y);
	void setUserPageID2(int e);
	void setUserPageID3(int g);
	void setPagelocation(const string& k);
	void setPagedescription(const string& u);
	void setpostPageID1(int f);
	void setpostPageID2(int d);
	void setpostPageID3(int y);

    //GETTERS
	int getpageID();
	string getPageName();
	string getPageFdate();
	int getUserPageID1();
	int getUserPageID2();
	int getUserPageID3();
	string getPagelocation();
	string getPagedescription();
	int getpostPageID1();
	int getpostPageID2();
	int getpostPageID3();
};









#endif