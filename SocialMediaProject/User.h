#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User
{
private:
    string email;
    string password;
    int Id;
    string Fname;
    string Lname;

public:
    User(string e = "", string p = "", int i = 0,string f="",string l="");
    void readfileU(ifstream& file);
    void outputFileU(ofstream& file);
    void DisplayU();

    // Setters
    void setEmail(const string& e);
    void setPassword(const string& p);
    void setID(int i);
    void setFname(const string& f);
    void setLname(const string& l);

    // Getters
    string getEmail() const;
    string getPassword() const;
    int getId();
    string getFname() const;
    string getLname() const;

};

#endif 
#pragma once
