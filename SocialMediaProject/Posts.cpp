#include"Posts.h"

Posts::Posts(int p, int u, string c, string t)
{
	postID = p;
	userPostID = u;
	contentPost = c;
	timePost = t;
}
void Posts::readfilePosts(ifstream& file)
{
	string tempPostID;
	if (getline(file, tempPostID))
	{
		postID = stoi(tempPostID);
	}
	string tempUserPostID;
	if (getline(file, tempUserPostID))
	{
		userPostID = stoi(tempUserPostID);
	}
	//getline(file, userPostID);
	getline(file, contentPost);
	getline(file, timePost);
}
void Posts::outputfilePost(ofstream& file)
{
	file << postID << endl;
	file << userPostID << endl;
	file << contentPost << endl;
	file << timePost << endl;
}
void Posts::DisplayPosts()
{
	cout << "Post ID : " << postID << endl;
	//cout << "User ID :" << userPostID << endl;
	cout << "**********^^(CONTENT)^^**********" <<"<( "<<timePost<<" )>" << endl;
	cout << endl;
	cout << contentPost << endl;
	cout << endl;

}
//SETTERS
void Posts::SetPostID(int& i)
{
	postID = i;
}
void Posts::SetuserPostID(int& p)
{
	userPostID = p;
}
void Posts::SetcontentPost(const string& c)
{
	contentPost = c;
}
void Posts::SetTimePost(const string& t)
{
	timePost = t;
}

//GETTERS
int Posts::getPostID()
{
	return postID;
}
int Posts::getuserPostID()
{
	return userPostID;
}
string Posts::getcontentPost()
{
	return contentPost;
}
string Posts::getTimePost()
{
	return timePost;
}