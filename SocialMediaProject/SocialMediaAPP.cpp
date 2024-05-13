//#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "ProfilePage.h" 
#include "Posts.h"
#include "Pages.h"
#include "Comments.h"
#include "SocialApp.h"
#include "FriendList.h"
#include "Likes.h"
using namespace std;

void RunApp()
{
    //////////////////////////////////////////// DATA INPUT /////////////////////////////////////
    const int numAccounts = 10;

    // For email/user input
    ifstream infile("email.txt");
    if (!infile.is_open())
    {
        cerr << "Error opening file (email.txt)!" << endl;
        exit(1);
    }

    User* info[numAccounts];
    for (int i = 0; i < numAccounts; i++)
    {
        info[i] = new User;
        info[i]->readfileU(infile);
    }
    infile.close();

    // For ProfilePage input
    ifstream infile1("ProfilePage.txt");
    if (!infile1.is_open())
    {
        cerr << "Error opening file (Profile.txt)!" << endl;
        exit(1);
    }

    ProfilePage* info1[numAccounts];
    for (int i = 0; i < numAccounts; i++)
    {
        info1[i] = new ProfilePage;
        info1[i]->readfilePP(infile1);
    }
    infile1.close();
    // For Posts
    ifstream infile2("Posts.txt");
    if (!infile2.is_open())
    {
        cerr << "Error opening file (Posts.txt)!" << endl;
        exit(1);
    }
    ifstream infilePosts("Size.txt"); // this is due to storing size for next restart and make new posts
    if (!infilePosts.is_open())
    {
        cerr << "Error opening file (Size.txt)!" << endl;
        exit(1);
    }
    int numOfPosts;
    infilePosts >> numOfPosts;
    Posts** info2 = new Posts * [numOfPosts];
    for (int i = 0; i < numOfPosts; i++)
    {
        info2[i] = new Posts;
        info2[i]->readfilePosts(infile2);
    }
    infile2.close();

    //pages
    const int numPages = 3;
    ifstream infilePages("Pages.txt");
    if (!infilePages.is_open())
    {
        cerr << "Error opening file (Pages.txt)!" << endl;
        exit(1);
    }

    Pages* info3[numPages];
    for (int i = 0; i < numPages; i++)
    {
        info3[i] = new Pages;
        info3[i]->readfilePages(infilePages);
    }
    infilePages.close();
    // comments
    int numComments;
    infilePosts >> numComments;
    ifstream infileComments("Comments.txt");
    if (!infileComments.is_open())
    {
        cerr << "Error opening file (Comments.txt)!" << endl;
        exit(1);
    }
    Comments** info4 = new Comments * [numComments];
    for (int i = 0; i < numComments; i++)
    {
        info4[i] = new Comments;
        info4[i]->readfileComments(infileComments);
    }
    infileComments.close();
    // friedlist
    ifstream infileFlist("FriendList.txt");
    if (!infileFlist.is_open())
    {
        cerr << "Error opening file (FriendList.txt)!" << endl;
        exit(1);
    }
    FriendList* info5[numAccounts];
    for (int i = 0;i < numAccounts;i++)
    {
        info5[i] = new FriendList;
        info5[i]->readfileFL(infileFlist);
    }
    infileFlist.close();
    //likes
    Likes** postLikes = new Likes * [numOfPosts];
    for (int i = 0; i < numOfPosts; i++)
    {
        postLikes[i] = new Likes(info2[i]->getPostID());
    }

    system("color 7c");

    ////////////////////////////////////// BOOT PAGE ////////////////////////////////////////////
    cout << "\t\t\t\t\t        FAST SOCIAL MEDIA APP " << endl;
    for (int i = 0;i < 1000000000;i++);

    /////////////////////////////////////////////////LOGIN PAGE////////////////////////////////////////////
    string mainEmail, mainPassword;
    bool loggedIn = false;

    cout << "\t\t\t\t****************************************************" << endl;
    cout << "\t\t\t\t                      LOGIN                             " << endl;
    cout << "\t\t\t\t****************************************************" << endl;
    int mainUserID = 0;
    do {
        cout << "Enter Email: ";
        cin >> mainEmail;
        cout << "Enter Password: ";
        cin >> mainPassword;

        loggedIn = false;

        for (int i = 0; i < numAccounts; i++)
        {
            if (info[i]->getEmail() == mainEmail && info[i]->getPassword() == mainPassword)
            {
                system("color 7a");
                cout << endl;
                cout << "\t\t\t\t\t\tLogged in successfully!" << endl;
                cout << "\t\t\t\t****************************************************" << endl;
                cout << "\t\t\t\t\t\t   Welcome User " << endl;
                cout << "\t\t\t\t****************************************************" << endl;
                cout << "\t\t\t\t\t        **( " << info[i]->getFname() << " " << info[i]->getLname() << " )** " << endl;
                cout << endl;
                cout << endl;
                loggedIn = true;
                mainUserID = i;
                break;
            }
        }

        if (!loggedIn) {
            cout << "Invalid credentials. Please try again." << endl;
        }

    } while (!loggedIn);

    //////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i = 0;i < 1000000000;i++);
    system("cls");
    
    bool logout = false;
    while (logout == false) // to continue asking user
    {
        system("color 7d");
        cout << "\t\t\t\t****************************************************" << endl;
        cout << "\t\t\t\t\t        FAST SOCIAL MEDIA APP " << endl;
        cout << "\t\t\t\t****************************************************" << endl;
        cout << "\t\t\t\t****************************************************" << endl;
        cout << "\t\t\t\t\t        **( " << info[mainUserID]->getFname() << " " << info[mainUserID]->getLname() << " )** " << endl;
        cout << endl;
        cout << endl;
        int Commands = 0;
        cout << " PRESS to do the following things " << endl;
        cout << "1 -> PASSWORD CHANGE" << endl;
        cout << "2-> NAME CHANGE" << endl;
        cout << "3-> PROFILE PAGE" << endl;
        cout << "4-> HOME PAGE" << endl;
        cout << "5-> PAGES" << endl;
        cout << "6-> COMMENTS" << endl;
        cout << "7-> FRIENDLIST " << endl;
        cout << "8-> MEMORY POST" << endl;
        cout << "9-> TO LIKE POST" << endl;
        cout << "10-> LOGOUT" << endl;
        cin >> Commands;
        bool Greater = false;
        while (Greater == false)
        {
            system("color 70");
            if (Commands <= 0 || Commands > 10)
            {
                cout << " Enter again :";
                cin >> Commands;
            }
            else if (Commands > 0 || Commands <= 10)
            {
                Greater = true;
            }
        }
        //////////////////////////////////////PASSWORD CHANGE/////////////////////////////////////////////
        if (Commands == 1)
        {
            system("color 90");
            system("cls");
            string AgreePAScha;
            cout << "Do You want to change password if then Type [YES] else any other " << endl;
            cin >> AgreePAScha;
            if (AgreePAScha == "YES" || AgreePAScha == "yes")
            {
                string passwordchange;
                cout << "Enter new Password " << endl;
                cin >> passwordchange;
                cout << " Password Changed !!!!!!! " << endl;
                info[mainUserID]->setPassword(passwordchange);
            }
            for (int i = 0;i < 1000000000;i++);

        }
        ////////////////////////////////////////NAME CHANGE/////////////////////////////////////////////
        if (Commands == 2)
        {
            system("color 20");
            system("cls");
            string AgreeNAMEcha;
            cout << "Do You want to change USER NAME if then Type [YES] else any other " << endl;
            cin >> AgreeNAMEcha;
            if (AgreeNAMEcha == "YES" || AgreeNAMEcha == "yes")
            {
                string fNAMEchange;
                cout << "Enter new FIRST NAME " << endl;
                cin >> fNAMEchange;
                string lNAMEchange;
                cout << "Enter new LAST NAME " << endl;
                cin >> lNAMEchange;
                cout << " NAME Changed !!!!!!! " << endl;
                info[mainUserID]->setFname(fNAMEchange);
                info[mainUserID]->setLname(lNAMEchange);
            }
            for (int i = 0;i < 1000000000;i++);

        }
        /////////////////////////////////////////// Profile Page ////////////////////////////////////////////////
        if (Commands == 3)
        {
            system("color 30");
            system("cls");
            cout << endl << endl;
            cout << "\t\t\t\t****************************************************" << endl;
            cout << "\t\t\t\t\t\t    **(PROFILE PAGE)**" << endl;
            cout << "\t\t\t\t\t               " << info[mainUserID]->getFname() << " " << info[mainUserID]->getLname() << endl;
            cout << " PERSONAL DETAILS : " << endl;
            info1[mainUserID]->DisplayP(); // displaying personal details
            cout << endl << endl;
            for (int i = 0;i < numOfPosts;i++)
            {
                if (info2[i]->getuserPostID() == info[mainUserID]->getId())
                {
                    info2[i]->DisplayPosts();
                }

            }
            for (int i = 0;i < 1000000000;i++);

        }
        ////////////////////////////////////////////HOME PAGE ///////////////////////////////////////////////////
        if (Commands == 4)
        {
            system("color 40");
            system("cls");
            string AgreeHome;
            cout << "Do you want to Visit HomePage? Type [YES] to visit, or any other key to cancel." << endl;
            cin >> AgreeHome;
            if (AgreeHome == "YES" || AgreeHome == "yes")
            {
                cout << "\t\t\t\t****************************************************" << endl;
                cout << "\t\t\t\t\t\t         HOME PAGE " << endl;
                for (int i = 0;i < numOfPosts;i++)
                {
                    for (int j = 0;j < numAccounts;j++)
                    {
                        if (info2[i]->getuserPostID() == info[j]->getId())
                        {
                            cout << "USER NAME : " << info[j]->getFname() << " " << info[j]->getLname() << endl;
                            info2[i]->DisplayPosts();
                            cout << "ID to delete Post and Comment ((" << i + 1 << "))" << endl;
                            cout << "\t\t\t\t****************************************************" << endl;
                            cout << endl;
                        }
                    }
                }
                for (int i = 0;i < 1000000000;i++);

            }
            ///////////////////////?????????????????????????????? delete post??????????????????????????????????////////////////////
            string AgreeDelPost;
            cout << " Do you want to delete post " << endl;
            cin >> AgreeDelPost;
            if (AgreeDelPost == "YES" || AgreeDelPost == "yes")
            {
                int pdelID;
                cout << "Enter the ID of post you want to enter from (1 to " << numOfPosts << " )" << endl;
                cin >> pdelID;
                bool postdelid = false;
                while (postdelid == false)
                {
                    if (pdelID <= 0 || pdelID > numOfPosts)
                    {
                        cout << " Invalid Post ID! Enter again " << endl;
                        cin >> pdelID;
                    }
                    else if (pdelID > 0 || pdelID < numOfPosts)
                    {
                        postdelid = true;
                    }
                }
                if (pdelID > 0 || pdelID < numOfPosts)
                {
                    int postIndexToDelete = pdelID - 1;

                    // Swap the post to be deleted with the last post in the array
                    if (postIndexToDelete != numOfPosts - 1)
                    {
                        // Move the last post to the position of the post to be deleted
                        swap(info2[postIndexToDelete], info2[numOfPosts - 1]);
                    }

                    // Delete the post at the end
                    delete info2[numOfPosts - 1];
                    numOfPosts--; // Decrease the count of posts

                    cout << "Post with ID " << pdelID << " has been successfully deleted." << endl;
                }
                ///////////////////////////////////////////////////// create new post//////////////////////////////////
                string AgreePost;
                cout << "Do you want to post? Type [YES] to post, or any other key to cancel." << endl;
                cin >> AgreePost;

                if (AgreePost == "YES" || AgreePost == "yes")
                {
                    // Increase the number of posts
                    numOfPosts += 1;

                    // Create a new array to hold the updated posts
                    Posts** newInfo2 = new Posts * [numOfPosts];

                    // Copy existing posts to the new array
                    for (int i = 0; i < numOfPosts - 1; i++)
                    {
                        newInfo2[i] = info2[i];
                    }

                    // Allocate memory for the new post
                    newInfo2[numOfPosts - 1] = new Posts;

                    // Set properties of the new post
                    int postidplus = numOfPosts + 1;
                    newInfo2[numOfPosts - 1]->SetPostID(postidplus);
                    int temp = info[mainUserID]->getId();
                    newInfo2[numOfPosts - 1]->SetuserPostID(temp);

                    string content;
                    cout << "Enter content: ";
                    cin.ignore();
                    getline(cin, content);
                    newInfo2[numOfPosts - 1]->SetcontentPost(content);
                    newInfo2[numOfPosts - 1]->SetTimePost("3:30 PM");

                    // Free the memory of the old info2 array (including posts)
                    delete[] info2;

                    // Point info2 to the new array
                    info2 = newInfo2;
                }
            }
            for (int i = 0;i < 1000000000;i++);

        }
        //////////////////////////////////////////// PAGES //////////////////////////////////////////////////////
        if (Commands == 5)
        {
            system("color 90");
            system("cls");
            string showPage;
            cout << "\t\t\t\t****************************************************" << endl;
            cout << endl;
            cout << endl;
            cout << "Do you want to Visit PAGES? Type [YES] to visit, or any other key to cancel." << endl;
            cin >> showPage;
            if (showPage == "YES" || showPage == "yes")
            { // problem in main pages loop error
                bool pagefound = false;
                int mainPageID = 0;
                cout << "\t\t\t\t****************************************************" << endl;
                for (int i = 0;i < numPages;i++)
                {
                    if (info[mainUserID]->getId() == info3[i]->getUserPageID1() || info[mainUserID]->getId() == info3[i]->getUserPageID2() || info[mainUserID]->getId() == info3[i]->getUserPageID3())
                    {
                        mainPageID = i;
                        cout << "\t\t\t\t\t\t     PAGE ID : " << info3[i]->getpageID() << endl << endl;
                        cout << "\t\t\t\t\t\t      PAGE NAME " << endl;
                        cout << "\t\t\t\t\t\t   *|(" << info3[i]->getPageName() << ")|*" << endl << endl;
                        cout << "LIKES ON PAGE <{ " << info3[i]->getpagefollowers() << " }>" << endl;
                        cout << " Location : " << info3[i]->getPagelocation() << endl;
                        cout << "Page Description is :" << endl;
                        cout << info3[i]->getPagedescription() << endl;
                        cout << "{(Followers)} " << endl << endl;;
                        for (int j = 0;j < numAccounts;j++)
                        {
                            if (info[j]->getId() == info3[i]->getUserPageID1() || info[j]->getId() == info3[i]->getUserPageID2() || info[j]->getId() == info3[i]->getUserPageID3())
                            {
                                cout << info[j]->getFname() << " " << info[j]->getLname() << endl;
                            }
                        }
                        cout << endl << endl;
                        pagefound = true;
                    }
                }
                if (pagefound == false)
                {
                    cout << " USER " << info[mainUserID]->getFname() << " " << info[mainUserID]->getLname() << " doesnot follow any page " << endl;
                }
                for (int i = 0;i < numOfPosts;i++)
                {

                    if (info3[mainPageID]->getpostPageID1() == info2[i]->getPostID() || info3[mainPageID]->getpostPageID2() == info2[i]->getPostID() || info3[mainPageID]->getpostPageID3() == info2[i]->getPostID())
                    {
                        info2[i]->DisplayPosts();
                    }
                }
            }
            for (int i = 0;i < 1000000000;i++);

        }
        ////////////////////////////////////////COMMENTS//////////////////////////////////////////////////////
        if (Commands == 6)
        {
            system("color 80");
            system("cls");
            string AgreeComments;
            cout << "Do you want to watch Comments on Posts ? Type [YES] to visit, or any other key to cancel." << endl;
            cin >> AgreeComments;
            if (AgreeComments == "YES" || AgreeComments == "yes")
            {
                int i = 0;
                cout << "Enter the ID of post you want to see Comments from 1 to " << numOfPosts << endl;
                cin >> i;
                bool postid = false;
                while (postid == false)
                {
                    if (i <= 0 || i > numOfPosts)
                    {
                        cout << " Invalid Post ID! Enter again " << endl;
                        cin >> i;
                    }
                    else if (i > 0 || i < numOfPosts)
                    {
                        postid = true;
                    }
                }
                if (i > 0 || i < numOfPosts)
                {
                    for (int j = 0;j < numAccounts;j++)
                    {
                        if (info[j]->getId() == info2[i - 1]->getuserPostID())
                        {
                            cout << info[j]->getFname() << " " << info[j]->getLname() << endl;
                        }
                    }
                    info2[i - 1]->DisplayPosts();
                    cout << " ((((COMMENTS))))" << endl;
                    for (int j = 0;j < numComments;j++)
                    {
                        if (info4[j]->getCommentPostID() == info2[i - 1]->getPostID())
                        {
                            for (int k = 0;k < numAccounts;k++)
                            {
                                if (info4[j]->getCommentUserID() == info[k]->getId())
                                {
                                    cout << info[k]->getFname() << " " << info[k]->getLname() << endl;
                                    info4[j]->DisplayComments();
                                }
                            }
                        }
                    }
                }

            }
            string Agreecomment_Add;
            cout << "Do you want to do Comments on Posts ? Type [YES] to visit, or any other key to cancel." << endl;
            cin >> Agreecomment_Add;
            if (Agreecomment_Add == "YES" || Agreecomment_Add == "yes")
            {
                // Increase the number of comments
                numComments += 1;

                // Create a new array to hold the updated comments
                Comments** newInfo4 = new Comments * [numComments];

                // Copy existing comments to the new array
                for (int i = 0; i < numComments - 1; i++)
                {
                    newInfo4[i] = info4[i];
                }

                // Allocate memory for the new comment
                newInfo4[numComments - 1] = new Comments;
                // to get post ID
                int pID;
                cout << "Enter the ID of post you want to enter from (1 to " << numOfPosts + 1 << " )" << endl;
                cin >> pID;
                bool postcommentid = false;
                while (postcommentid == false)
                {
                    if (pID <= 0 || pID > numOfPosts + 1)
                    {
                        cout << " Invalid Post ID! Enter again " << endl;
                        cin >> pID;
                    }
                    else if (pID > 0 || pID < numOfPosts + 1)
                    {
                        postcommentid = true;
                    }
                }
                int CommentonPost = info2[pID - 1]->getPostID();

                // Set properties of the new comment
                newInfo4[numComments - 1]->setCommentID(numComments);
                newInfo4[numComments - 1]->setCommentPostID(CommentonPost);
                int tempcomments = info[mainUserID]->getId();
                newInfo4[numComments - 1]->setCommentUserID(tempcomments);

                string contentc;
                cout << "Enter content: ";
                cin.ignore();
                getline(cin, contentc);
                newInfo4[numComments - 1]->setCommentContent(contentc);

                // Free the memory of the old info4 array (including comments)
                delete[] info4;

                // Point info4 to the new array
                info4 = newInfo4;
            }
            for (int i = 0;i < 1000000000;i++);

        }
        /////////////////////////////////////logout////////////////////////////////////////////////////////
        if (Commands == 10)
        {
            system("color 8c");
            cout << "\t\t\t\t****************************************************" << endl;
            cout << "\t\t\t\t\t\t       LOGGING OUT " << endl;
            cout << "\t\t\t\t****************************************************" << endl;

            logout = true;
            break;
        }
        //////////////////////////////////Friend list/////////////////////////////////////////////////
        if (Commands == 7)
        {
            system("cls");
            string AgreeList;
            cout << "Do you want to view FriendList ? Type [YES] to visit, or any other key to cancel." << endl;
            cin >> AgreeList;
            if (AgreeList == "YES" || AgreeList == "yes")
            {
                int FLuserID = 0;
                for (int i = 0;i < numAccounts;i++)
                {
                    if (info[mainUserID]->getId() == info5[i]->getuserId())
                    {
                        FLuserID = i;
                        break;
                    }
                }
                int F1 = info5[FLuserID]->getfrienduserId1();
                int F2 = info5[FLuserID]->getfrienduserId2();
                int F3 = info5[FLuserID]->getfrienduserId3();
                for (int i = 0;i < numAccounts;i++)
                {
                    if (info[i]->getId() == F1 || info[i]->getId() == F2 || info[i]->getId() == F3)
                    {
                        cout << info[i]->getFname() << " " << info[i]->getLname() << endl;
                        cout << info[i]->getId() << endl << endl;
                    }
                }

                string AgreeListPP;
                cout << "Do you want to view Pofile of Friend ? Type [YES] to visit, or any other key to cancel." << endl;
                cin >> AgreeListPP;
                if (AgreeListPP == "YES" || AgreeListPP == "yes")
                {
                    int getID;
                    cout << "Enter the ID of the friend you want to visit: " << endl;
                    cin >> getID;

                    bool IDfound = false;
                    while (!IDfound)
                    {
                        if (getID == F1 || getID == F2 || getID == F3)
                        {
                            IDfound = true; // ID is valid, exit the loop
                        }
                        else
                        {
                            cout << "Invalid ID. Please enter a valid friend ID: ";
                            cin >> getID;
                        }
                    }
                    cout << endl;
                    for (int i = 0;i < numAccounts;i++)
                    {
                        if (info[i]->getId() == getID)
                        {
                            info1[i]->DisplayP();
                        }
                    }
                }
            }
            for (int i = 0;i < 1000000000;i++);

        }
        ///////////////////////////////////////////////memory off //////////////////////////////////////
        if (Commands == 8)
        {
            system("color 90");
            system("cls");
            string Agree_memory;
            cout << "Do you want to add Memory ? Type [YES] to visit, or any other key to cancel." << endl;
            cin >> Agree_memory;
            if (Agree_memory == "YES" || Agree_memory == "yes")
            {
                int pMID;
                cout << "Enter post ID you want to share as memory from (1 to " << numOfPosts << " )" << endl;
                cin >> pMID;
                bool postMid = false;
                while (postMid == false)
                {
                    if (pMID <= 0 || pMID > numOfPosts)
                    {
                        cout << " Invalid Post ID! Enter again " << endl;
                        cin >> pMID;
                    }
                    else if (pMID > 0 || pMID < numOfPosts)
                    {
                        postMid = true;
                    }
                }
                if (pMID > 0 || pMID < numOfPosts)
                {
                    if (info[mainUserID]->getId() == info2[pMID - 1]->getuserPostID())
                    {
                        cout << endl << endl;
                        cout << "POST SHARED AS MEMORY " << endl << endl;
                        info2[pMID - 1]->DisplayPosts();
                    }
                    else
                    {
                        cout << "The post doesnot belong to you " << endl;
                    }
                }
            }
            for (int i = 0;i < 1000000000;i++);

        }
        if (Commands == 9)
        {
            system("color 20");
            system("cls");
            int postIndex;
            cout << "Enter the ID of the post you want to interact with (1 to " << numOfPosts << "): " << endl;
            cin >> postIndex;

            if (postIndex >= 1 && postIndex <= numOfPosts) 
            {
                int actualPostIndex = postIndex - 1;

                // Check if the user wants to like the post
                string agreeLike;
                cout << "Do you want to like this post? Type [YES] to like, or any other key to skip: " << endl;;
                cin >> agreeLike;

                if (agreeLike == "YES" || agreeLike == "yes") 
                {
                    // Add like to the post
                    postLikes[actualPostIndex]->addLike(info[mainUserID]->getId());
                }


                string showLikes;
                cout << "Do you want to see who liked this post? Type [YES] to view likes: " << endl;
                cin >> showLikes;

                if (showLikes == "YES" || showLikes == "yes") 
                {
                    postLikes[actualPostIndex]->displayLikes();
                }
            }
            else 
            {
                cout << "Invalid post ID. Please try again." << endl;
            }
            for (int i = 0;i < 1000000000;i++);

        }





        //////////////////////////////////////////// OUTPUT DATA ////////////////////////////////////////////////
        //changing password
        ofstream outputFile("email.txt");
        if (!outputFile.is_open())
        {
            cerr << "Error opening output file!(email.txt)" << endl;
            exit(1);
        }

        for (int i = 0; i < numAccounts; i++)
        {
            info[i]->outputFileU(outputFile);
        }
        outputFile.close();
        //making posts
        ofstream outputFile1("Posts.txt");
        if (!outputFile1.is_open())
        {
            cerr << "Error opening output file (posts.txt)!" << endl;
            exit(1);
        }

        for (int i = 0; i < numOfPosts; i++)
        {
            info2[i]->outputfilePost(outputFile1);
        }
        outputFile1.close();
        // making comments
        ofstream outputFile2("Comments.txt");
        if (!outputFile2.is_open())
        {
            cerr << "Error opening output file (Comments.txt)!" << endl;
            exit(1);
        }

        for (int i = 0; i < numComments; i++)
        {
            info4[i]->outputfilecomments(outputFile2);
        }
        outputFile2.close();
        // storing size of posts and comments
        ofstream outputFilePosts("Size.txt");
        if (!outputFilePosts.is_open())
        {
            cerr << "Error opening output file (size.txt)!" << endl;
            exit(1);
        }
        else
        {
            outputFilePosts << numOfPosts << " " << numComments << " ";
        }

    } //while loop end
    ///////////////////////////////////////////// CLEAN UP ////////////////////////////////////////////////

    for (int i = 0; i < numAccounts; i++)
    {
        delete info[i];  // email.txt
        delete info1[i]; // profilepage.txt
        delete info5[i]; // friendlist
    }
    for (int i = 0; i < numPages; i++)
    {
        delete info3[i];  // pages.txt

    }
    // posts.txt de allocation
    for (int i = 0; i < numOfPosts; i++)
    {
        delete info2[i];
    }
    delete[] info2;
    info2 = nullptr;
    // comments.txt
    for (int i = 0; i < numComments; i++)
    {
        delete info4[i];  // comments.txt
    }
    //likes deallocation
    for (int i = 0; i < numOfPosts; i++)
    {
        delete postLikes[i];
    }
    delete[] postLikes;




}