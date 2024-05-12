#include "Likes.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


#include <iostream>
#include <string>

using namespace std;

Likes::~Likes() 
{
   delete[] likedByUsers;
}

bool Likes::hasLiked(int userID) const 
{
        for (int i = 0; i < size; i++) 
        {
            if (likedByUsers[i] == userID) 
            {
                return true;
            }
        }
        return false;
}

    void Likes::addLike(int userID) 
    {
        if (!hasLiked(userID)) 
        {
            // Allocate new memory for likedByUsers
            int* newLikedByUsers = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newLikedByUsers[i] = likedByUsers[i];
            }
            newLikedByUsers[size] = userID;

            // Free old memory
            delete[] likedByUsers;

            // Update pointer and size
            likedByUsers = newLikedByUsers;
            size++;

            cout << "You liked the post!" << endl;
        }
        else 
        {
            cout << "You've already liked this post." << endl;
        }
    }

    void Likes::displayLikes() const 
    {
        if (size > 0) 
        {
            cout << "Users who liked this post (Post ID: " << postID << "):" << endl;
            for (int i = 0; i < size; i++) 
            {
                cout << "User ID: " << likedByUsers[i] << endl;
                // You can display user names here based on their ID from your User array
            }
        }
        else 
        {
            cout << "No one has liked this post yet." << endl;
        }
    }

