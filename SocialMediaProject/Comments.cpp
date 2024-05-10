#include"Comments.h"


Comments::Comments(int c, int p, int u, string con)
{
	CommentID=c;
	CommentPostID=p;
	CommentUserID=u;
	CommentContent=con;
}
void Comments::readfileComments(ifstream& file)
{
	string tempCommentID;
	if (getline(file, tempCommentID))
	{
		CommentID = stoi(tempCommentID);
	}
	string tempCommentPostID;
	if (getline(file, tempCommentPostID))
	{
		CommentPostID = stoi(tempCommentPostID);
	}
	string tempCommentUserID;
	if (getline(file, tempCommentUserID))
	{
		CommentUserID = stoi(tempCommentUserID);
	}
	getline(file, CommentContent);
}
void Comments::outputfilecomments(ofstream& file)
{
	file << CommentID << endl;
	file << CommentPostID << endl;
	file << CommentUserID << endl;
	file << CommentContent << endl;
}
void Comments::DisplayComments()
{
	cout << "COMMENT ID : " << CommentID << endl;
	//cout << "COMMENT POST ID : " << CommentPostID << endl;
	//cout << "COMMENT USER ID : " << CommentUserID << endl;
	cout << "<^*[COMMENT CONTENT]*^> : " << endl;
	cout << CommentContent << endl;
	cout << endl;
}
//SETTERS
void Comments::setCommentID(int i)
{
	CommentID = i;
}
void Comments::setCommentPostID(int k)
{
	CommentPostID=k;
}
void Comments::setCommentUserID(int j)
{
	CommentUserID = j;
}
void Comments::setCommentContent(const string l)
{
	CommentContent = l;
}
//GETTERS
int Comments::getCommentID()
{
	return CommentID;
}
int Comments::getCommentPostID()
{
	return CommentPostID;
}
int Comments::getCommentUserID()
{
	return CommentUserID;
}
string Comments::getCommentContent()
{
	return CommentContent;
}














