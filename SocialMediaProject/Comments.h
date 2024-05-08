#ifndef COMMENTS_H
#define COMMENTS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Comments
{
private:
	int CommentID;
	int CommentPostID;
	int CommentUserID;
	string CommentContent;
public:
	Comments(int c = 0, int p = 0, int u = 0, string con = "");
	void readfileComments(ifstream& file);
	void DisplayComments();
	//SETTERS
	void setCommentID(int i);
	void setCommentPostID(int k);
	void setCommentUserID(int j);
	void setCommentContent(const string l);
	//GETTERS
	int getCommentID();
	int getCommentPostID();
	int getCommentUserID();
	string getCommentContent();
};












#endif 
