#ifndef POSTS_H
#define POSTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Posts
{
private:
	int postID;
	int userPostID;
	string contentPost;
	string timePost;
public:
	Posts(int p=0, int u = 0, string c = "", string t = "");
	void readfilePosts(ifstream& file);
	void outputfilePost(ofstream& file);
	void DisplayPosts();
	//void DisplayPosts2();

	//SETTERS
	void SetPostID(int& i);
	void SetuserPostID(int& p);
	void SetcontentPost(const string& c);
	void SetTimePost(const string& t);

	//GETTERS
	int getPostID();
	int getuserPostID();
	string getcontentPost();
	string getTimePost();
};




























#endif

