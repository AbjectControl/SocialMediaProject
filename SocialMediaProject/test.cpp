//#include <iostream>
//#include <fstream>
//#include <string>
//#include "User.h"
//#include "ProfilePage.h" 
//#include "Posts.h"
//#include "Pages.h"
//using namespace std;
//
//int main()
//{
//    //////////////////////////////////////////// DATA INPUT /////////////////////////////////////
//    const int numAccounts = 10;
//
//    // For email/user input
//    ifstream infile("email.txt");
//    if (!infile.is_open())
//    {
//        cout << "Error opening file (email.txt)!" << endl;
//        return 1;
//    }
//
//    User* info[numAccounts];
//    for (int i = 0; i < numAccounts; i++)
//    {
//        info[i] = new User;
//        info[i]->readfileU(infile);
//    }
//    infile.close();
//
//    // For ProfilePage input
//    ifstream infile1("ProfilePage.txt");
//    if (!infile1.is_open())
//    {
//        cout << "Error opening file (Profile.txt)!" << endl;
//        return 1;
//    }
//
//    ProfilePage* info1[numAccounts];
//    for (int i = 0; i < numAccounts; i++)
//    {
//        info1[i] = new ProfilePage;
//        info1[i]->readfilePP(infile1);
//    }
//    infile1.close();
//    // For Posts
//    ifstream infile2("Posts.txt");
//    if (!infile2.is_open())
//    {
//        cout << "Error opening file (Posts.txt)!" << endl;
//        return 1;
//    }
//    ifstream infilePosts("Size.txt"); // this is due to storing size for next restart and make new posts
//    if (!infilePosts.is_open())
//    {
//        cout << "Error opening file (Size.txt)!" << endl;
//        return 1;
//    }
//    int numOfPosts;
//    infilePosts >> numOfPosts;
//    Posts** info2 = new Posts * [numOfPosts];
//    for (int i = 0; i < numOfPosts; i++)
//    {
//        info2[i] = new Posts;
//        info2[i]->readfilePosts(infile2);
//    }
//    infile2.close();
//
//    //pages
//    const int numPages = 3;
//    ifstream infilePages("Pages.txt");
//    if (!infilePages.is_open())
//    {
//        cout << "Error opening file (Pages.txt)!" << endl;
//        return 1;
//    }
//
//    Pages* info3[numPages];
//    for (int i = 0; i < numPages; i++)
//    {
//        info3[i] = new Pages;
//        info3[i]->readfilePages(infilePages);
//    }
//    infilePages.close();
//
//    ////////////////////////////////////// BOOT PAGE ////////////////////////////////////////////
//    cout << "\t\t\t\t\t\t   WELCOME USER " << endl;
//    for (int i = 0;i < 1000000000;i++);
//
//    /////////////////////////////////////////////////LOGIN PAGE////////////////////////////////////////////
//    string mainEmail, mainPassword;
//    bool loggedIn = false;
//
//    cout << "\t\t\t\t****************************************************" << endl;
//    cout << "\t\t\t\t                      LOGIN                             " << endl;
//    cout << "\t\t\t\t****************************************************" << endl;
//    int mainUserID = 0;
//    do {
//        cout << "Enter Email: ";
//        cin >> mainEmail;
//        cout << "Enter Password: ";
//        cin >> mainPassword;
//
//        loggedIn = false;
//
//        for (int i = 0; i < numAccounts; i++)
//        {
//            if (info[i]->getEmail() == mainEmail && info[i]->getPassword() == mainPassword)
//            {
//                cout << endl;
//                cout << "\t\t\t\t\t\tLogged in successfully!" << endl;
//                cout << "\t\t\t\t****************************************************" << endl;
//                cout << "\t\t\t\t\t\t   Welcome User " << endl;
//                cout << "\t\t\t\t****************************************************" << endl;
//                cout << "\t\t\t\t\t      **( " << info[i]->getFname() << " " << info[i]->getLname() << " )** " << endl;
//                cout << endl;
//                cout << endl;
//                loggedIn = true;
//                mainUserID = i;
//                break;
//            }
//        }
//
//        if (!loggedIn) {
//            cout << "Invalid credentials. Please try again." << endl;
//        }
//
//    } while (!loggedIn);
//
//    ////////////////////////////////////////PASSWORD CHANGE/////////////////////////////////////////////
//    string AgreePAScha;
//    cout << "Do You want to change password if then Type [YES] else any other " << endl;
//    cin >> AgreePAScha;
//    if (AgreePAScha == "YES" || AgreePAScha == "yes")
//    {
//        string passwordchange;
//        cout << "Enter new Password " << endl;
//        cin >> passwordchange;
//        cout << " Password Changed !!!!!!! " << endl;
//        info[mainUserID]->setPassword(passwordchange);
//    }
//    ////////////////////////////////////////NAME CHANGE/////////////////////////////////////////////
//    string AgreeNAMEcha;
//    cout << "Do You want to change USER NAME if then Type [YES] else any other " << endl;
//    cin >> AgreeNAMEcha;
//    if (AgreeNAMEcha == "YES" || AgreeNAMEcha == "yes")
//    {
//        string fNAMEchange;
//        cout << "Enter new FIRST NAME " << endl;
//        cin >> fNAMEchange;
//        string lNAMEchange;
//        cout << "Enter new LAST NAME " << endl;
//        cin >> lNAMEchange;
//        cout << " NAME Changed !!!!!!! " << endl;
//        info[mainUserID]->setFname(fNAMEchange);
//        info[mainUserID]->setLname(lNAMEchange);
//    }
//
//    /////////////////////////////////////////// Profile Page ////////////////////////////////////////////////
//    cout << endl << endl;
//    cout << "\t\t\t\t****************************************************" << endl;
//    cout << "\t\t\t\t\t\t    **(PROFILE PAGE)**" << endl;
//    cout << "\t\t\t\t\t               " << info[mainUserID]->getFname() << " " << info[mainUserID]->getLname() << endl;
//    cout << " PERSONAL DETAILS : " << endl;
//    info1[mainUserID]->DisplayP(); // displaying personal details
//    cout << endl << endl;
//    for (int i = 0;i < numOfPosts;i++)
//    {
//        if (info2[i]->getuserPostID() == info[mainUserID]->getId())
//        {
//            info2[i]->DisplayPosts();
//        }
//
//    }
//    ////////////////////////////////////////////HOME PAGE ///////////////////////////////////////////////////
//    string AgreeHome;
//    cout << "Do you want to Visit HomePage? Type [YES] to visit, or any other key to cancel." << endl;
//    cin >> AgreeHome;
//    if (AgreeHome == "YES" || AgreeHome == "yes")
//    {
//        cout << "\t\t\t\t****************************************************" << endl;
//        cout << "\t\t\t\t\t\t         HOME PAGE " << endl;
//        for (int i = 0;i < numOfPosts;i++)
//        {
//            for (int j = 0;j < numAccounts;j++)
//            {
//                if (info2[i]->getuserPostID() == info[j]->getId())
//                {
//                    cout << "USER NAME : " << info[j]->getFname() << " " << info[j]->getLname() << endl;
//                    info2[i]->DisplayPosts();
//                    cout << "\t\t\t\t****************************************************" << endl;
//                    cout << endl;
//                }
//            }
//        }
//    }
//    // create new post
//    string AgreePost;
//    cout << "Do you want to post? Type [YES] to post, or any other key to cancel." << endl;
//    cin >> AgreePost;
//
//    if (AgreePost == "YES" || AgreePost == "yes")
//    {
//        // Increase the number of posts
//        numOfPosts += 1;
//
//        // Create a new array to hold the updated posts
//        Posts** newInfo2 = new Posts * [numOfPosts];
//
//        // Copy existing posts to the new array
//        for (int i = 0; i < numOfPosts - 1; i++)
//        {
//            newInfo2[i] = info2[i];
//        }
//
//        // Allocate memory for the new post
//        newInfo2[numOfPosts - 1] = new Posts;
//
//        // Set properties of the new post
//        newInfo2[numOfPosts - 1]->SetPostID(numOfPosts);
//        int temp = info[mainUserID]->getId();
//        newInfo2[numOfPosts - 1]->SetuserPostID(temp);
//
//        string content;
//        cout << "Enter content: ";
//        cin.ignore();
//        getline(cin, content);
//        newInfo2[numOfPosts - 1]->SetcontentPost(content);
//        newInfo2[numOfPosts - 1]->SetTimePost("3:30 PM");
//
//        // Free the memory of the old info2 array (including posts)
//        delete[] info2;
//
//        // Point info2 to the new array
//        info2 = newInfo2;
//    }
//    //////////////////////////////////////////// PAGES //////////////////////////////////////////////////////
//
//    string showPage;
//    cout << "\t\t\t\t****************************************************" << endl;
//    cout << endl;
//    cout << endl;
//    cout << "Do you want to Visit PAGES? Type [YES] to visit, or any other key to cancel." << endl;
//    cin >> showPage;
//    if (showPage == "YES" || showPage == "yes")
//    { // problem in main pages loop error
//        bool pagefound = false;
//        cout << "\t\t\t\t****************************************************" << endl;
//        for (int i = 0;i < numPages;i++)
//        {
//            if (info[mainUserID]->getId() == info3[i]->getUserPageID1() || info[mainUserID]->getId() == info3[i]->getUserPageID2() || info[mainUserID]->getId() == info3[i]->getUserPageID3())
//            {
//                cout << "\t\t\t\t\t\t     PAGE ID : " << info3[i]->getpageID() << endl << endl;
//                cout << "\t\t\t\t\t\t      PAGE NAME " << endl;
//                cout << "\t\t\t\t\t\t   *|(" << info3[i]->getPageName() << ")|*" << endl << endl;
//                cout << "LIKES ON PAGE <{ " << info3[i]->getpagefollowers() << " }>" << endl;
//                cout << " Location : " << info3[i]->getPagelocation() << endl;
//                cout << "Page Description is :" << endl;
//                cout << info3[i]->getPagedescription() << endl;
//                cout << "{(Followers)} " << endl << endl;;
//                for (int j = 0;j < numAccounts;j++)
//                {
//                    if (info[j]->getId() == info3[i]->getUserPageID1() || info[j]->getId() == info3[i]->getUserPageID2() || info[j]->getId() == info3[i]->getUserPageID3())
//                    {
//                        cout << info[j]->getFname() << " " << info[j]->getLname() << endl;
//                    }
//                }
//                cout << endl << endl;
//                pagefound = true;
//            }
//        }
//        // Assume info, info2, info3 are arrays of appropriate objects
//
//// Iterate over posts
//        for (int j = 0; j < numOfPosts; j++) {
//            int postID = info2[j]->getPostID();
//            int userPostID = info2[j]->getuserPostID();
//
//            // Check if the post is associated with any of the specific pages
//            for (int i = 0; i < numPages; i++) {
//                if (postID == info3[i]->getpostPageID1() ||
//                    postID == info3[i]->getpostPageID2() ||
//                    postID == info3[i]->getpostPageID3()) {
//
//                    // Check if the user who posted this is a follower of the page
//                    for (int k = 0; k < numAccounts; k++) {
//                        if (userPostID == info[k]->getId()) {
//                            // Display user's name and post content
//                            cout << "USER NAME : " << info[k]->getFname() << " " << info[k]->getLname() << endl;
//                            info2[j]->DisplayPosts();
//                            cout << "\t\t\t\t****************************************************" << endl;
//                            cout << endl;
//                            break; // No need to check further users for this post
//                        }
//                    }
//                }
//            }
//        }
//
//        if (pagefound == false)
//        {
//            cout << " USER " << info[mainUserID]->getFname() << " " << info[mainUserID]->getLname() << " doesnot follow any page " << endl;
//        }
//    }
//
//
//
//
//
//
//
//
//
//
//
//    //////////////////////////////////////////// OUTPUT DATA ////////////////////////////////////////////////
//    //changing password
//    ofstream outputFile("email.txt");
//    if (!outputFile.is_open())
//    {
//        cout << "Error opening output file!(email.txt)" << endl;
//        return 1;
//    }
//
//    for (int i = 0; i < numAccounts; i++)
//    {
//        info[i]->outputFileU(outputFile);
//    }
//    outputFile.close();
//    //making posts
//    ofstream outputFile1("Posts.txt");
//    if (!outputFile1.is_open())
//    {
//        cout << "Error opening output file (posts.txt)!" << endl;
//        return 1;
//    }
//
//    for (int i = 0; i < numOfPosts; i++)
//    {
//        info2[i]->outputfilePost(outputFile1);
//    }
//    outputFile.close();
//    // storing size of posts
//    ofstream outputFilePosts("Size.txt");
//    if (!outputFilePosts.is_open())
//    {
//        cout << "Error opening output file (size.txt)!" << endl;
//        return 1;
//    }
//    else
//    {
//        outputFilePosts << numOfPosts << " ";
//    }
//
//    ///////////////////////////////////////////// CLEAN UP ////////////////////////////////////////////////
//
//    for (int i = 0; i < numAccounts; i++)
//    {
//        delete info[i];  // email.txt
//        delete info1[i]; // profilepage.txt
//    }
//    for (int i = 0; i < numPages; i++)
//    {
//        delete info3[i];  // pages.txt
//
//    }
//    // posts.txt de allocation
//    for (int i = 0; i < numOfPosts; i++)
//    {
//        delete info2[i];
//    }
//    delete[] info2;
//    info2 = nullptr;
//
//
//
//
//
//    return 0;
//}