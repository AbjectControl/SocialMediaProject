#include "User.h"

User::User(string e, string p, int i, string f, string l)
{
    email = e;
    password = p;
    Id = i;
    Fname = f;
    Lname = l;

}

void User::readfileU(ifstream& file)
{
    file >> email;
    file >> password;
    file >> Id;
    file >> Fname;
    file >> Lname;
}

void User::outputFileU(ofstream& file)
{
    file << email << " " << password << " " << Id <<" "<<Fname<<" "<<Lname<< endl;
}

void User::DisplayU()
{
    cout << "Email: " << email << endl;
    cout << "Password: " << password << endl;
}
//SETTERS
void User::setEmail(const string& e)
{
    email = e;
}

void User::setPassword(const string& p)
{
    password = p;
}

void User::setID(int i)
{
    Id = i;
}
void User::setFname(const string& f)
{
    Fname = f;
}
void User::setLname(const string& l)
{
    Lname = l;
}
//GETTERS
string User::getEmail() const
{
    return email;
}

string User::getPassword() const
{
    return password;
}

int User::getId()
{
    return Id;
}
string User::getFname() const
{
    return Fname;
}
string User::getLname() const
{
    return Lname;
}