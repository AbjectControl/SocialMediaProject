//#include <iostream>
//#include <fstream>
//#include <string>
//#include "raylib.h"
//#include "User.h"
//#include "ProfilePage.h"
//#include "Posts.h"
//using namespace std;
//
//// Function to render a text input box and return the entered text
//string DrawTextInputBox(int posX, int posY, int width, int height, const char* defaultText)
//{
//    const int textSize = 20;
//    const int padding = 5;
//
//    char buffer[256] = ""; // Buffer to store user input
//
//    bool textBoxActive = false;
//    Rectangle textBoxRect = { posX, posY, width, height };
//
//    while (!WindowShouldClose())
//    {
//        // Begin drawing
//        BeginDrawing();
//        ClearBackground(RAYWHITE);
//
//        // Draw text box outline
//        DrawRectangleLinesEx(textBoxRect, 2, BLACK);
//
//        // Draw text inside the text box
//        if (textBoxActive)
//        {
//            DrawText(buffer, posX + padding, posY + padding, textSize, BLACK);
//        }
//        else
//        {
//            DrawText(defaultText, posX + padding, posY + padding, textSize, GRAY);
//        }
//
//        // Check for mouse input to activate text box
//        if (CheckCollisionPointRec(GetMousePosition(), textBoxRect))
//        {
//            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//            {
//                textBoxActive = true;
//            }
//        }
//        else
//        {
//            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//            {
//                textBoxActive = false;
//            }
//        }
//
//        // Check for keyboard input when text box is active
//        if (textBoxActive)
//        {
//            int key = GetKeyPressed();
//
//            if (key != KEY_NULL)
//            {
//                // Append character to buffer if it's a valid text input
//                if ((key >= 32) && (key <= 125) && (strlen(buffer) < sizeof(buffer) - 1))
//                {
//                    int len = strlen(buffer);
//                    buffer[len] = static_cast<char>(key);
//                    buffer[len + 1] = '\0';
//                }
//                else if (key == KEY_BACKSPACE)
//                {
//                    // Remove last character from buffer on backspace
//                    int len = strlen(buffer);
//                    if (len > 0)
//                    {
//                        buffer[len - 1] = '\0';
//                    }
//                }
//            }
//        }
//
//        // End drawing
//        EndDrawing();
//    }
//
//    return string(buffer);
//}
//
//int main()
//{
//    const int numAccounts = 10;
//    int numOfPosts = 0;
//    int screenWidth = 800;
//    int screenHeight = 600;
//
//    // Initialize window and raylib
//    InitWindow(screenWidth, screenHeight, "Social Media App");
//
//    // Load data from files
//    ifstream infile("email.txt");
//    ifstream infile1("ProfilePage.txt");
//    ifstream infile2("Posts.txt");
//    ifstream infilePosts("Size.txt");
//
//    if (!infile.is_open() || !infile1.is_open() || !infile2.is_open() || !infilePosts.is_open())
//    {
//        cout << "Error opening file!" << endl;
//        return 1;
//    }
//
//    // Load user data
//    User* info[numAccounts];
//    for (int i = 0; i < numAccounts; i++)
//    {
//        info[i] = new User;
//        info[i]->readfileU(infile);
//    }
//    infile.close();
//
//    // Load profile data
//    ProfilePage* info1[numAccounts];
//    for (int i = 0; i < numAccounts; i++)
//    {
//        info1[i] = new ProfilePage;
//        info1[i]->readfilePP(infile1);
//    }
//    infile1.close();
//
//    // Load posts data and post count
//    infilePosts >> numOfPosts;
//    Posts** info2 = new Posts * [numOfPosts];
//    for (int i = 0; i < numOfPosts; i++)
//    {
//        info2[i] = new Posts;
//        info2[i]->readfilePosts(infile2);
//    }
//    infile2.close();
//    infilePosts.close();
//
//    // Main game loop
//    while (!WindowShouldClose())
//    {
//        const int screenWidth = 800;
//        const int screenHeight = 600;
//
//        InitWindow(screenWidth, screenHeight, "Login Form");
//
//        const int textFieldWidth = 300;
//        const int textFieldHeight = 40;
//        const int buttonWidth = 120;
//        const int buttonHeight = 40;
//
//        string userEmail = "";
//        string userPassword = "";
//
//        bool loggedIn = false;
//        bool showLoginError = false;
//
//        // Main game loop
//        while (!WindowShouldClose())
//        {
//            // Update
//            userEmail = GetText("Enter Email:", userEmail, textFieldWidth);
//            userPassword = GetText("Enter Password:", userPassword, textFieldWidth);
//
//            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//            {
//                int buttonX = (screenWidth - buttonWidth) / 2;
//                int buttonY = screenHeight / 2 + 50;
//
//                // Check login button click
//                if (CheckCollisionPointRec(GetMousePosition(), { buttonX, buttonY, buttonWidth, buttonHeight }))
//                {
//                    // Hardcoded login credentials (for demonstration purposes)
//                    string correctEmail = "user@example.com";
//                    string correctPassword = "password123";
//
//                    if (userEmail == correctEmail && userPassword == correctPassword)
//                    {
//                        loggedIn = true;
//                        showLoginError = false;
//                    }
//                    else
//                    {
//                        loggedIn = false;
//                        showLoginError = true;
//                    }
//                }
//            }
//
//            // Draw
//            BeginDrawing();
//            ClearBackground(RAYWHITE);
//
//            if (!loggedIn)
//            {
//                DrawText("Login Form", screenWidth / 2 - 80, 50, 20, BLACK);
//
//                int emailFieldY = screenHeight / 2 - 50;
//                DrawText("Email:", screenWidth / 2 - textFieldWidth / 2, emailFieldY - 30, 20, BLACK);
//                DrawRectangle(screenWidth / 2 - textFieldWidth / 2, emailFieldY, textFieldWidth, textFieldHeight, LIGHTGRAY);
//                DrawText(userEmail.c_str(), screenWidth / 2 - textFieldWidth / 2 + 5, emailFieldY + 10, 20, BLACK);
//
//                int passwordFieldY = emailFieldY + 70;
//                DrawText("Password:", screenWidth / 2 - textFieldWidth / 2, passwordFieldY - 30, 20, BLACK);
//                DrawRectangle(screenWidth / 2 - textFieldWidth / 2, passwordFieldY, textFieldWidth, textFieldHeight, LIGHTGRAY);
//                DrawText(userPassword.c_str(), screenWidth / 2 - textFieldWidth / 2 + 5, passwordFieldY + 10, 20, BLACK);
//
//                int buttonX = (screenWidth - buttonWidth) / 2;
//                int buttonY = screenHeight / 2 + 50;
//                DrawRectangle(buttonX, buttonY, buttonWidth, buttonHeight, BLUE);
//                DrawText("Login", buttonX + 20, buttonY + 10, 20, WHITE);
//
//                if (showLoginError)
//                {
//                    DrawText("Invalid credentials. Please try again.", screenWidth / 2 - 160, screenHeight / 2 + 100, 20, RED);
//                }
//            }
//            else
//            {
//                DrawText("Logged in successfully!", screenWidth / 2 - 120, screenHeight / 2, 20, GREEN);
//            }
//            // Display posts
//            for (int i = 0; i < numOfPosts; i++)
//            {
//                if (info2[i]->getuserPostID() == info[0]->getId()) // Assuming info[0] is the logged-in user
//                {
//                    DrawText(info2[i]->getcontentPost().c_str(), 100, 200 + i * 50, 20, BLACK);
//                }
//            }
//
//            // Check for new post creation
//            if (IsKeyPressed(KEY_P))
//            {
//                // Create new post
//                numOfPosts++;
//
//                string content = DrawTextInputBox(100, 500, 600, 30, "Enter new post content...");
//
//                info2[numOfPosts - 1] = new Posts;
//                info2[numOfPosts - 1]->SetPostID(numOfPosts);
//                int temp = 0;
//                temp = info[0]->getId();
//                info2[numOfPosts - 1]->SetuserPostID(temp); // Assuming info[0] is the logged-in user
//                info2[numOfPosts - 1]->SetcontentPost(content);
//                info2[numOfPosts - 1]->SetTimePost("3:30 PM");
//            }
//        }
//
//        // End drawing
//        EndDrawing();
//    }
//
//    // Clean up resources
//    for (int i = 0; i < numAccounts; i++)
//    {
//        delete info[i];
//        delete info1[i];
//    }
//
//    for (int i = 0; i < numOfPosts; i++)
//    {
//        delete info2[i];
//    }
//    delete[] info2;
//
//    CloseWindow();
//
//    return 0;
//}
