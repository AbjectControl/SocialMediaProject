#ifndef LIKES_H
#define LIKES_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Likes 
{
private:
    int postID;
    int* likedByUsers;
    int size;
public:
    Likes(int postID) : postID(postID), likedByUsers(nullptr), size(0) {}
    ~Likes();

    bool hasLiked(int userID) const;
    void addLike(int userID);
    void displayLikes() const;
};













#endif 
